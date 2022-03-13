/**
*   @file    eMIOS_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @implements DGPT07700
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS200
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
* @section eMios_Irq_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include" MemMap.h included after each section define in order to set the current memory section
*
* @section eMios_Irq_c_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section eMios_Irq_c_3
* Violates MISRA 2004 Required Rule 11.1, Conversion shall not be performed between a pointer to a function
* and any type other than an integral type
*
* @section eMios_Irq_c_4
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability.
*
* @section eMios_Irq_c_5
* Violates MISRA 2004 Required Rule 20.2, This violation is not fixed since we have not used any
* Standard library macros.
*
*@section eMios_Irq_c_6
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
* @section eMios_Irq_c_7
* Violates MISRA 2004 Required Rule 17.4, This violation is due to the use of pointer arithmetic,
* which is used for the speed optimization, the indexing of the pointer is taken care and hence the
* unintended memory location will not be accessed.
*
* @section eMios_Irq_c_8
* Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator: '||'
* This violation  is not fixed since  the functions execution is not mandatory, both left hand and
* right hand side of logical operator && are checking some status values
*/


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
/*
* @violates @ref eMios_Irq_c_2 Precautions shall be taken in order to prevent the contents of a
*            header file being included twice. 
*/
#include "Std_Types.h"
#include "modules.h"
/*
* @violates @ref eMios_Irq_c_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_eSys.h"
#include "Reg_eSys_eMIOS.h"
#include "Reg_eSys_eMIOS_CfgEx.h"


#if (USE_GPT_MODULE==STD_ON)
#include "Gpt.h"
#include "Gpt_LLD.h"
#endif

#if (USE_PWM_MODULE==STD_ON)
#include "Pwm.h"
#include "Pwm_eMIOS_LLD.h"
#endif

#if (USE_ICU_MODULE==STD_ON)
#include "Icu_LLD.h"
#include "Icu_eMIOS_LLD.h"
#endif


/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/**
* @brief   eMIOS Module Id, The define value is 100 for GPT, 121 for PWM and 122 for ICU
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
#define EMIOS_COMMON_MODULE_ID                121

/**
* @brief   Source file version information
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
#define EMIOS_IRQ_C_VENDOR_ID                      43
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
/*
* @violates @ref eMios_Irq_c_6 This is required as per autosar Requirement, 
*/
#define EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
/*
* @violates @ref eMios_Irq_c_6 This is required as per autosar Requirement, 
*/
#define EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
/*
* @violates @ref eMios_Irq_c_6 This is required as per autosar Requirement, 
*/
#define EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION    3
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
#define EMIOS_IRQ_C_SW_MAJOR_VERSION               1
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
#define EMIOS_IRQ_C_SW_MINOR_VERSION               0
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
#define EMIOS_IRQ_C_SW_PATCH_VERSION               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and header file are of the same Autosar version */
#if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != MODULES_AR_RELEASE_MINOR_VERSION_H))
    #error "AutoSar Version Numbers of eMIOS_Irq.c and modules.h are different"
#endif
#endif


/* Check if source file and Reg_eSys_eMIOS.h are of the same vendor */
#if (EMIOS_IRQ_C_VENDOR_ID != REG_ESYS_EMIOS_H_VENDOR_ID)
    #error "eMIOS_Irq.c and Reg_eSys_eMIOS.h have different vendor ids"
#endif

/* Check if source file and header file are of the same Autosar version */
#if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_MINOR_VERSION) || \
        (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMIOS_Irq.c and Reg_eSys_eMIOS.h are different"
#endif


/* Check if source file and header file are of the same Software version */
#if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_H_SW_MAJOR_VERSION)  || \
        (EMIOS_IRQ_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_H_SW_MINOR_VERSION)  || \
        (EMIOS_IRQ_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMIOS_Irq.c and Reg_eSys_eMIOS.h are different"
#endif


/* Check if source file and Reg_eSys_EMIOS_CfgEx.h are of the same vendor */
#if (EMIOS_IRQ_C_VENDOR_ID != REG_ESYS_EMIOS_CFGEX_H_VENDOR_ID)
    #error "eMIOS_Irq.c and Reg_eSys_EMIOS_CfgEx.h have different vendor ids"
#endif


/* Check if source file and header file are of the same Autosar version */
#if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION !=  \
                                              REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
        (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION !=  \
                                              REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMIOS_Irq.c and Reg_eSys_EMIOS_CfgEx.h are different"
#endif


/* Check if source file and header file are of the same Software version */
#if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MAJOR_VERSION)  || \
        (EMIOS_IRQ_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MINOR_VERSION)  || \
        (EMIOS_IRQ_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMIOS_Irq.c and Reg_eSys_EMIOS_CfgEx.h are different"
#endif


#if (USE_PWM_MODULE==STD_ON)

    #if (EMIOS_IRQ_C_VENDOR_ID != PWM_VENDOR_ID)
        #error "eMIOS_Irq.c and Pwm.h have different vendor ids"
    #endif
/* Check if source file and Gpt header file are of the same Autosar version */
    #if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of eMIOS_Irq.c and Pwm.h are different"
    #endif
    /* Check if source file and GPT header file are of the same Software version */
    #if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
            (EMIOS_IRQ_C_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
            (EMIOS_IRQ_C_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION) )
        #error "Software Version Numbers of eMIOS_Irq.c and Pwm.h are different"
    #endif

    #if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION !=  \
                                                     PWM_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of eMIOS_Irq.c and Pwm_eMIOS_LLD.h are different"
    #endif
    /* Check if source file and header file are of the same Software version */
    #if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != PWM_EMIOS_LLD_H_SW_MAJOR_VERSION)  || \
            (EMIOS_IRQ_C_SW_MINOR_VERSION != PWM_EMIOS_LLD_H_SW_MINOR_VERSION)  || \
            (EMIOS_IRQ_C_SW_PATCH_VERSION != PWM_EMIOS_LLD_H_SW_PATCH_VERSION))
        #error "Software Version Numbers of eMIOS_Irq.c and Pwm_eMIOS_LLD.h are different"
    #endif

#endif

#if (USE_ICU_MODULE==STD_ON)

    #if (EMIOS_IRQ_C_VENDOR_ID != ICU_VENDOR_ID)
        #error "eMIOS_Irq.c and ICU.h have different vendor ids"
    #endif
/* Check if source file and Gpt header file are of the same Autosar version */
    #if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of eMIOS_Irq.c and ICU.h are different"
    #endif
    /* Check if source file and GPT header file are of the same Software version */
    #if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION) || \
            (EMIOS_IRQ_C_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION) || \
            (EMIOS_IRQ_C_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION) )
        #error "Software Version Numbers of eMIOS_Irq.c and ICU.h are different"
    #endif

    #if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
            (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION !=  \
                                                     ICU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of eMIOS_Irq.c and ICU_eMIOS_LLD.h are different"
    #endif
    /* Check if source file and header file are of the same Software version */
    #if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != ICU_EMIOS_LLD_H_SW_MAJOR_VERSION)  || \
            (EMIOS_IRQ_C_SW_MINOR_VERSION != ICU_EMIOS_LLD_H_SW_MINOR_VERSION)  || \
            (EMIOS_IRQ_C_SW_PATCH_VERSION != ICU_EMIOS_LLD_H_SW_PATCH_VERSION))
        #error "Software Version Numbers of eMIOS_Irq.c and ICU_eMIOS_LLD.h are different"
    #endif

#endif

#if (USE_GPT_MODULE==STD_ON)
#if (EMIOS_IRQ_C_VENDOR_ID != GPT_VENDOR_ID)
    #error "eMIOS_Irq.c and Gpt.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMIOS_Irq.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION) || \
     (EMIOS_IRQ_C_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION) || \
     (EMIOS_IRQ_C_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION) )
    #error "Software Version Numbers of eMIOS_Irq.c and Gpt.h are different"
#endif

#if (EMIOS_IRQ_C_VENDOR_ID != GPT_LLD_VENDOR_ID)
    #error "eMIOS_Irq.c and Gpt_LLD.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((EMIOS_IRQ_C_AR_RELEASE_MAJOR_VERSION != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_IRQ_C_AR_RELEASE_MINOR_VERSION != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_IRQ_C_AR_RELEASE_REVISION_VERSION != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMIOS_Irq.c and Gpt_LLD.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((EMIOS_IRQ_C_SW_MAJOR_VERSION != GPT_LLD_SW_MAJOR_VERSION) || \
     (EMIOS_IRQ_C_SW_MINOR_VERSION != GPT_LLD_SW_MINOR_VERSION) || \
     (EMIOS_IRQ_C_SW_PATCH_VERSION != GPT_LLD_SW_PATCH_VERSION) )
    #error "Software Version Numbers of eMIOS_Irq.c and Gpt_LLD.h are different"
#endif
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

/*==================================================================================================
*                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
/*
* @brief EMIOS_0 common ISR declarations
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_0_CH_1_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_2_CH_3_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_4_CH_5_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_6_CH_7_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_8_CH_9_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_10_CH_11_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_12_CH_13_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_14_CH_15_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_16_CH_17_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_18_CH_19_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_20_CH_21_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_22_CH_23_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_24_CH_25_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_26_CH_27_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_28_CH_29_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_30_CH_31_ISR);

/*
* @brief EMIOS_1 common ISR declarations
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_0_CH_1_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_2_CH_3_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_4_CH_5_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_6_CH_7_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_8_CH_9_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_10_CH_11_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_12_CH_13_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_14_CH_15_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_16_CH_17_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_18_CH_19_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_20_CH_21_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_22_CH_23_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_24_CH_25_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_26_CH_27_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_28_CH_29_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_30_CH_31_ISR);

/*
* @brief EMIOS_2 common ISR declarations
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_0_CH_1_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_2_CH_3_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_4_CH_5_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_6_CH_7_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_8_CH_9_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_10_CH_11_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_12_CH_13_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_14_CH_15_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_16_CH_17_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_18_CH_19_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_20_CH_21_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_22_CH_23_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_24_CH_25_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_26_CH_27_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_28_CH_29_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_30_CH_31_ISR);


/*
* @brief EMIOS_0 independent ISR declarations
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_0_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_1_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_2_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_3_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_4_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_5_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_6_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_7_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_8_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_9_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_10_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_11_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_12_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_13_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_14_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_15_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_16_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_17_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_18_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_19_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_20_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_21_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_22_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_23_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_24_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_25_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_26_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_27_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_28_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_29_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_30_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_31_ISR);

/*
* @brief EMIOS_1 independent ISR declarations
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_0_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_1_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_2_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_3_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_4_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_5_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_6_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_7_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_8_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_9_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_10_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_11_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_12_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_13_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_14_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_15_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_16_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_17_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_18_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_19_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_20_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_21_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_22_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_23_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_24_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_25_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_26_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_27_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_28_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_29_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_30_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_31_ISR);

/*
* @brief EMIOS_2 independent ISR declarations
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_0_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_1_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_2_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_3_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_4_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_5_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_6_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_7_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_8_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_9_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_10_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_11_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_12_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_13_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_14_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_15_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_16_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_17_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_18_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_19_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_20_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_21_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_22_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_23_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_24_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_25_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_26_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_27_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_28_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_29_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_30_ISR);
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_31_ISR);

#if (USE_ICU_MODULE==STD_ON)
    #if (ICU_DMA_SUPPORTED == STD_ON)
    #if (defined ICU_EMIOS_DmaCh0_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch0);
    #endif
    #if (defined ICU_EMIOS_DmaCh1_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch1);
    #endif
    #if (defined ICU_EMIOS_DmaCh2_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch2);
    #endif
    #if (defined ICU_EMIOS_DmaCh3_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch3);
    #endif
    #if (defined ICU_EMIOS_DmaCh4_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch4);
    #endif
    #if (defined ICU_EMIOS_DmaCh5_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch5);
    #endif
    #if (defined ICU_EMIOS_DmaCh6_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch6);
    #endif
    #if (defined ICU_EMIOS_DmaCh7_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch7);
    #endif
    #if (defined ICU_EMIOS_DmaCh8_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch8);
    #endif
    #if (defined ICU_EMIOS_DmaCh9_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch9);
    #endif
    #if (defined ICU_EMIOS_DmaCh10_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch10);
    #endif
    #if (defined ICU_EMIOS_DmaCh11_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch11);
    #endif
    #if (defined ICU_EMIOS_DmaCh12_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch12);
    #endif
    #if (defined ICU_EMIOS_DmaCh13_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch13);
    #endif
    #if (defined ICU_EMIOS_DmaCh14_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch14);
    #endif
    #if (defined ICU_EMIOS_DmaCh15_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch15);
    #endif
    #if (defined ICU_EMIOS_DmaCh16_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch16);
    #endif
    #if (defined ICU_EMIOS_DmaCh17_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch17);
    #endif
    #if (defined ICU_EMIOS_DmaCh18_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch18);
    #endif
    #if (defined ICU_EMIOS_DmaCh19_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch19);
    #endif
    #if (defined ICU_EMIOS_DmaCh20_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch20);
    #endif
    #if (defined ICU_EMIOS_DmaCh21_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch21);
    #endif
    #if (defined ICU_EMIOS_DmaCh22_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch22);
    #endif
    #if (defined ICU_EMIOS_DmaCh23_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch23);
    #endif
    #if (defined ICU_EMIOS_DmaCh24_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch24);
    #endif
    #if (defined ICU_EMIOS_DmaCh25_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch25);
    #endif
    #if (defined ICU_EMIOS_DmaCh26_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch26);
    #endif
    #if (defined ICU_EMIOS_DmaCh27_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch27);
    #endif
    #if (defined ICU_EMIOS_DmaCh28_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch28);
    #endif
    #if (defined ICU_EMIOS_DmaCh29_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch29);
    #endif
    #if (defined ICU_EMIOS_DmaCh30_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch30);
    #endif
    #if (defined ICU_EMIOS_DmaCh31_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch31);
    #endif
    #if (defined ICU_EMIOS_DmaCh32_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch32);
    #endif
    #if (defined ICU_EMIOS_DmaCh33_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch33);
    #endif
    #if (defined ICU_EMIOS_DmaCh34_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch34);
    #endif
    #if (defined ICU_EMIOS_DmaCh35_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch35);
    #endif
    #if (defined ICU_EMIOS_DmaCh36_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch36);
    #endif
    #if (defined ICU_EMIOS_DmaCh37_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch37);
    #endif
    #if (defined ICU_EMIOS_DmaCh38_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch38);
    #endif
    #if (defined ICU_EMIOS_DmaCh39_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch39);
    #endif
    #if (defined ICU_EMIOS_DmaCh40_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch40);
    #endif
    #if (defined ICU_EMIOS_DmaCh41_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch41);
    #endif
    #if (defined ICU_EMIOS_DmaCh42_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch42);
    #endif
    #if (defined ICU_EMIOS_DmaCh43_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch43);
    #endif
    #if (defined ICU_EMIOS_DmaCh44_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch44);
    #endif
    #if (defined ICU_EMIOS_DmaCh45_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch45);
    #endif
    #if (defined ICU_EMIOS_DmaCh46_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch46);
    #endif
    #if (defined ICU_EMIOS_DmaCh47_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch47);
    #endif
    #if (defined ICU_EMIOS_DmaCh48_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch48);
    #endif
    #if (defined ICU_EMIOS_DmaCh49_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch49);
    #endif
    #if (defined ICU_EMIOS_DmaCh50_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch50);
    #endif
    #if (defined ICU_EMIOS_DmaCh51_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch51);
    #endif
    #if (defined ICU_EMIOS_DmaCh52_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch52);
    #endif
    #if (defined ICU_EMIOS_DmaCh53_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch53);
    #endif
    #if (defined ICU_EMIOS_DmaCh54_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch54);
    #endif
    #if (defined ICU_EMIOS_DmaCh55_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch55);
    #endif
    #if (defined ICU_EMIOS_DmaCh56_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch56);
    #endif
    #if (defined ICU_EMIOS_DmaCh57_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch57);
    #endif
    #if (defined ICU_EMIOS_DmaCh58_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch58);
    #endif
    #if (defined ICU_EMIOS_DmaCh59_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch59);
    #endif
    #if (defined ICU_EMIOS_DmaCh60_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch60);
    #endif
    #if (defined ICU_EMIOS_DmaCh61_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch61);
    #endif
    #if (defined ICU_EMIOS_DmaCh62_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch62);
    #endif
    #if (defined ICU_EMIOS_DmaCh63_ISR_USED)
        /* MISRA-C:2004 8.2 VIOLATION: Refer to REF 6 above */
        ISR(Icu_EMIOS_Dma_Ch63);
    #endif
    #endif
#endif


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if ((USE_GPT_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==100))
#define GPT_START_SEC_CODE
    /*
    * @violates @ref eMios_Irq_c_1 only preprocessor statements and comments before "#include" 
    */
    /*
    * @violates @ref eMios_Irq_c_2 Precautions shall be taken in order to prevent the contents of a
    *            header file being included twice.
    */
    #include "MemMap.h"
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==121))
    #define PWM_START_SEC_CODE
    /*
    * @violates @ref eMios_Irq_c_1 only preprocessor statements and comments before "#include" 
    */    
    /*
    * @violates @ref eMios_Irq_c_2 Precautions shall be taken in order to prevent the contents of a
    *            header file being included twice.
    */
    #include "MemMap.h"
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON) && \
      (EMIOS_COMMON_MODULE_ID==122))
    #define ICU_START_SEC_CODE
    /*
    * @violates @ref eMios_Irq_c_1 only preprocessor statements and comments before "#include" 
    */    
    /*
    * @violates @ref eMios_Irq_c_2 Precautions shall be taken in order to prevent the contents of a
    *            header file being included twice.
    */
    #include "MemMap.h"
#endif


#if ( ((USE_GPT_MODULE==STD_ON)  && (EMIOS_COMMON_MODULE_ID==100)) || \
      ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON)  && (EMIOS_COMMON_MODULE_ID==121)) || \
      ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON) && \
       (EMIOS_COMMON_MODULE_ID==122)) )

#ifdef EMIOS_COMMON_ISR_HANDLER
  #if  (EMIOS_COMMON_ISR_HANDLER == STD_ON)


/*==================================================================================================*/
/*                    COMMON EMIOS CHANNELS INTERRUPT SERVICE ROUTINES DEFINITION                   */
/*==================================================================================================*/



/*********************************** EMIOS 0 common interrupts START ******************************/


/*
* @brief EMIOS module:0 channels:0,1 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_0
*/
#if  ((defined GPT_EMIOS_0_CH_0_ISR_USED) && (defined PWM_EMIOS_0_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined PWM_EMIOS_0_CH_0_ISR_USED) && (defined ICU_EMIOS_0_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined ICU_EMIOS_0_CH_0_ISR_USED) && (defined GPT_EMIOS_0_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_0"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_1
*/
#if  ((defined GPT_EMIOS_0_CH_1_ISR_USED) && (defined PWM_EMIOS_0_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined PWM_EMIOS_0_CH_1_ISR_USED) && (defined ICU_EMIOS_0_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined ICU_EMIOS_0_CH_1_ISR_USED) && (defined GPT_EMIOS_0_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if ( (defined GPT_EMIOS_0_CH_0_ISR_USED) || (defined GPT_EMIOS_0_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_0_ISR_USED) || (defined PWM_EMIOS_0_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_0_ISR_USED) || (defined ICU_EMIOS_0_CH_1_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 0 and 1 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 0 and 1
* @note   This will be defined only if eMIOS channels 0 or 1 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_0_CH_1_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_0_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_0_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_0_ISR_USED) )

    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_0 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 0)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_0 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 0)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_0_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_0);
                #endif

                #if(defined PWM_EMIOS_0_CH_0_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_0);
                #endif

                #if(defined ICU_EMIOS_0_CH_0_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_0);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_1_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_1_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_1_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_1 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 1)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_1 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 1)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_1_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_1);
                #endif

                #if(defined PWM_EMIOS_0_CH_1_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_1);
                #endif

                #if(defined ICU_EMIOS_0_CH_1_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_1);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:2,3 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_2
*/
#if  ((defined GPT_EMIOS_0_CH_2_ISR_USED) && (defined PWM_EMIOS_0_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined PWM_EMIOS_0_CH_2_ISR_USED) && (defined ICU_EMIOS_0_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined ICU_EMIOS_0_CH_2_ISR_USED) && (defined GPT_EMIOS_0_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_2"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_3
*/
#if  ((defined GPT_EMIOS_0_CH_3_ISR_USED) && (defined PWM_EMIOS_0_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined PWM_EMIOS_0_CH_3_ISR_USED) && (defined ICU_EMIOS_0_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined ICU_EMIOS_0_CH_3_ISR_USED) && (defined GPT_EMIOS_0_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if ( (defined GPT_EMIOS_0_CH_2_ISR_USED) || (defined GPT_EMIOS_0_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_2_ISR_USED) || (defined PWM_EMIOS_0_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_2_ISR_USED) || (defined ICU_EMIOS_0_CH_3_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 2 and 3 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 2 and 3
*
* @note   This will be defined only if eMIOS channels 2 or 3 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_2_CH_3_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_2_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_2_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_2_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 2)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_2 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */    
        if ( ( REG_READ32(EMIOS_CSR(0, 2)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_2_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_2);
                #endif

                #if(defined PWM_EMIOS_0_CH_2_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_2);
                #endif

                #if(defined ICU_EMIOS_0_CH_2_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_2);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_3_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_3_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_3_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_3 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 3)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_3 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 3)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_3_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_3);
                #endif

                #if(defined PWM_EMIOS_0_CH_3_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_3);
                #endif

                #if(defined ICU_EMIOS_0_CH_3_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_3);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
  /* @violates @ref eMios_Irq_c_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:4,5 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_4
*/
#if  ((defined GPT_EMIOS_0_CH_4_ISR_USED) && (defined PWM_EMIOS_0_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined PWM_EMIOS_0_CH_4_ISR_USED) && (defined ICU_EMIOS_0_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined ICU_EMIOS_0_CH_4_ISR_USED) && (defined GPT_EMIOS_0_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_4"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_5
*/
#if  ((defined GPT_EMIOS_0_CH_5_ISR_USED) && (defined PWM_EMIOS_0_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined PWM_EMIOS_0_CH_5_ISR_USED) && (defined ICU_EMIOS_0_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined ICU_EMIOS_0_CH_5_ISR_USED) && (defined GPT_EMIOS_0_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if ( (defined GPT_EMIOS_0_CH_4_ISR_USED) || (defined GPT_EMIOS_0_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_4_ISR_USED) || (defined PWM_EMIOS_0_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_4_ISR_USED) || (defined ICU_EMIOS_0_CH_5_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 4 and 5 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 4 and 5
*
* @note   This will be defined only if eMIOS channels 4 or 5 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_4_CH_5_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_4_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_4_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_4_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_4 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 4)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_4 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 4)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_4_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_4);
                #endif

                #if(defined PWM_EMIOS_0_CH_4_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_4);
                #endif

                #if(defined ICU_EMIOS_0_CH_4_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_4);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_5_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_5_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_5_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_5 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 5)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_5 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 5)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_5_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_5);
                #endif

                #if(defined PWM_EMIOS_0_CH_5_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_5);
                #endif

                #if(defined ICU_EMIOS_0_CH_5_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_5);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:6,7 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_6
*/
#if  ((defined GPT_EMIOS_0_CH_6_ISR_USED) && (defined PWM_EMIOS_0_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined PWM_EMIOS_0_CH_6_ISR_USED) && (defined ICU_EMIOS_0_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined ICU_EMIOS_0_CH_6_ISR_USED) && (defined GPT_EMIOS_0_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_6"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_7
*/
#if  ((defined GPT_EMIOS_0_CH_7_ISR_USED) && (defined PWM_EMIOS_0_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined PWM_EMIOS_0_CH_7_ISR_USED) && (defined ICU_EMIOS_0_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined ICU_EMIOS_0_CH_7_ISR_USED) && (defined GPT_EMIOS_0_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if ( (defined GPT_EMIOS_0_CH_6_ISR_USED) || (defined GPT_EMIOS_0_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_6_ISR_USED) || (defined PWM_EMIOS_0_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_6_ISR_USED) || (defined ICU_EMIOS_0_CH_7_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 6 and 7 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 6 and 7
*
* @note   This will be defined only if eMIOS channels 6 or 7 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_6_CH_7_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_6_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_6_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_6_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_6 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 6)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_6 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 6)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_6_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_6);
                #endif

                #if(defined PWM_EMIOS_0_CH_6_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_6);
                #endif

                #if(defined ICU_EMIOS_0_CH_6_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_6);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_7_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_7_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_7_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_7 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 7)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_7 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 7)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_7_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_7);
                #endif

                #if(defined PWM_EMIOS_0_CH_7_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_7);
                #endif

                #if(defined ICU_EMIOS_0_CH_7_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_7);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:8,9 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_8
*/
#if  ((defined GPT_EMIOS_0_CH_8_ISR_USED) && (defined PWM_EMIOS_0_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined PWM_EMIOS_0_CH_8_ISR_USED) && (defined ICU_EMIOS_0_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined ICU_EMIOS_0_CH_8_ISR_USED) && (defined GPT_EMIOS_0_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_8"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_9
*/
#if  ((defined GPT_EMIOS_0_CH_9_ISR_USED) && (defined PWM_EMIOS_0_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined PWM_EMIOS_0_CH_9_ISR_USED) && (defined ICU_EMIOS_0_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined ICU_EMIOS_0_CH_9_ISR_USED) && (defined GPT_EMIOS_0_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if ( (defined GPT_EMIOS_0_CH_8_ISR_USED) || (defined GPT_EMIOS_0_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_8_ISR_USED) || (defined PWM_EMIOS_0_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_8_ISR_USED) || (defined ICU_EMIOS_0_CH_9_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 8 and 9 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 8 and 9
* @note   This will be defined only if eMIOS channels 8 or 9 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_8_CH_9_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_8_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_8_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_8_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_8 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 8)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_8 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 8)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_8_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_8);
                #endif

                #if(defined PWM_EMIOS_0_CH_8_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_8);
                #endif

                #if(defined ICU_EMIOS_0_CH_8_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_8);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_9_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_9_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_9_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_9 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 9)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_9 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 9)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_9_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_9);
                #endif

                #if(defined PWM_EMIOS_0_CH_9_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_9);
                #endif

                #if(defined ICU_EMIOS_0_CH_9_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_9);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
   /* @violates @ref eMios_Irq_c_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:10,11 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_10
*/
#if  ((defined GPT_EMIOS_0_CH_10_ISR_USED) && (defined PWM_EMIOS_0_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined PWM_EMIOS_0_CH_10_ISR_USED) && (defined ICU_EMIOS_0_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined ICU_EMIOS_0_CH_10_ISR_USED) && (defined GPT_EMIOS_0_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_10"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_11
*/
#if  ((defined GPT_EMIOS_0_CH_11_ISR_USED) && (defined PWM_EMIOS_0_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined PWM_EMIOS_0_CH_11_ISR_USED) && (defined ICU_EMIOS_0_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined ICU_EMIOS_0_CH_11_ISR_USED) && (defined GPT_EMIOS_0_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if ( (defined GPT_EMIOS_0_CH_10_ISR_USED) || (defined GPT_EMIOS_0_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_10_ISR_USED) || (defined PWM_EMIOS_0_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_10_ISR_USED) || (defined ICU_EMIOS_0_CH_11_ISR_USED) )

/*================================================================================================*/
/**
* @brief    Interrupt handler for eMIOS channels : 10 and 11 for eMIOS_0 module
* @details  Process the interrupt of eMIOS channels 10 and 11
*
*@note      This will be defined only if eMIOS channels 10 or 11 are configured in GPT, ICU or
*           PWM mode
*/
/*================================================================================================*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_10_CH_11_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_10_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_10_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_10_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_10 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 10)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_10 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 10)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_10_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_10);
                #endif

                #if(defined PWM_EMIOS_0_CH_10_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_10);
                #endif

                #if(defined ICU_EMIOS_0_CH_10_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_10);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_11_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_11_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_11_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_11 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 11)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_11 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 11)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_11_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_11);
                #endif

                #if(defined PWM_EMIOS_0_CH_11_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_11);
                #endif

                #if(defined ICU_EMIOS_0_CH_11_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_11);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:12,13 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_12
*/
#if  ((defined GPT_EMIOS_0_CH_12_ISR_USED) && (defined PWM_EMIOS_0_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined PWM_EMIOS_0_CH_12_ISR_USED) && (defined ICU_EMIOS_0_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined ICU_EMIOS_0_CH_12_ISR_USED) && (defined GPT_EMIOS_0_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_12"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_13
*/
#if  ((defined GPT_EMIOS_0_CH_13_ISR_USED) && (defined PWM_EMIOS_0_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined PWM_EMIOS_0_CH_13_ISR_USED) && (defined ICU_EMIOS_0_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined ICU_EMIOS_0_CH_13_ISR_USED) && (defined GPT_EMIOS_0_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if ( (defined GPT_EMIOS_0_CH_12_ISR_USED) || (defined GPT_EMIOS_0_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_12_ISR_USED) || (defined PWM_EMIOS_0_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_12_ISR_USED) || (defined ICU_EMIOS_0_CH_13_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 12 and 13 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 12 and 13
*
* @note     This will be defined only if eMIOS channels 12 or 13 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_12_CH_13_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_12_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_12_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_12_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_12 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 12)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_12 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 12)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_12_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_12);
                #endif

                #if(defined PWM_EMIOS_0_CH_12_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_12);
                #endif

                #if(defined ICU_EMIOS_0_CH_12_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_12);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_13_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_13_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_13_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_13 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 13)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_13 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 13)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_13_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_13);
                #endif

                #if(defined PWM_EMIOS_0_CH_13_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_13);
                #endif

                #if(defined ICU_EMIOS_0_CH_13_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_13);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:14,15 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_14
*/
#if  ((defined GPT_EMIOS_0_CH_14_ISR_USED) && (defined PWM_EMIOS_0_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined PWM_EMIOS_0_CH_14_ISR_USED) && (defined ICU_EMIOS_0_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined ICU_EMIOS_0_CH_14_ISR_USED) && (defined GPT_EMIOS_0_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_14"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_15
*/
#if  ((defined GPT_EMIOS_0_CH_15_ISR_USED) && (defined PWM_EMIOS_0_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined PWM_EMIOS_0_CH_15_ISR_USED) && (defined ICU_EMIOS_0_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined ICU_EMIOS_0_CH_15_ISR_USED) && (defined GPT_EMIOS_0_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if ( (defined GPT_EMIOS_0_CH_14_ISR_USED) || (defined GPT_EMIOS_0_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_14_ISR_USED) || (defined PWM_EMIOS_0_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_14_ISR_USED) || (defined ICU_EMIOS_0_CH_15_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 14 and 15 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 14 and 15
*
* @note     This will be defined only if eMIOS channels 14 or 15 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_14_CH_15_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_14_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_14_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_14_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_14 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 14)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_14 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 14)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_14_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_14);
                #endif

                #if(defined PWM_EMIOS_0_CH_14_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_14);
                #endif

                #if(defined ICU_EMIOS_0_CH_14_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_14);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_15_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_15_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_15_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_15 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 15)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_15 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 15)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_15_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_15);
                #endif

                #if(defined PWM_EMIOS_0_CH_15_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_15);
                #endif

                #if(defined ICU_EMIOS_0_CH_15_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_15);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:16,17 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_16
*/
#if  ((defined GPT_EMIOS_0_CH_16_ISR_USED) && (defined PWM_EMIOS_0_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined PWM_EMIOS_0_CH_16_ISR_USED) && (defined ICU_EMIOS_0_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined ICU_EMIOS_0_CH_16_ISR_USED) && (defined GPT_EMIOS_0_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_16"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_17
*/
#if  ((defined GPT_EMIOS_0_CH_17_ISR_USED) && (defined PWM_EMIOS_0_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined PWM_EMIOS_0_CH_17_ISR_USED) && (defined ICU_EMIOS_0_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined ICU_EMIOS_0_CH_17_ISR_USED) && (defined GPT_EMIOS_0_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if ( (defined GPT_EMIOS_0_CH_16_ISR_USED) || (defined GPT_EMIOS_0_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_16_ISR_USED) || (defined PWM_EMIOS_0_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_16_ISR_USED) || (defined ICU_EMIOS_0_CH_17_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 16 and 17 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 16 and 17

* @note     This will be defined only if eMIOS channels 16 or 17 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_16_CH_17_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_16_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_16_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_16_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_16 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 16)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_16 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 16)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_16_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_16);
                #endif

                #if(defined PWM_EMIOS_0_CH_16_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_16);
                #endif

                #if(defined ICU_EMIOS_0_CH_16_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_16);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_17_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_17_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_17_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_17 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 17)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
       ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_17 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 17)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_17_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_17);
                #endif

                #if(defined PWM_EMIOS_0_CH_17_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_17);
                #endif

                #if(defined ICU_EMIOS_0_CH_17_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_17);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:18,19 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_18
*/
#if  ((defined GPT_EMIOS_0_CH_18_ISR_USED) && (defined PWM_EMIOS_0_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined PWM_EMIOS_0_CH_18_ISR_USED) && (defined ICU_EMIOS_0_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined ICU_EMIOS_0_CH_18_ISR_USED) && (defined GPT_EMIOS_0_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_18"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_19
*/
#if  ((defined GPT_EMIOS_0_CH_19_ISR_USED) && (defined PWM_EMIOS_0_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined PWM_EMIOS_0_CH_19_ISR_USED) && (defined ICU_EMIOS_0_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined ICU_EMIOS_0_CH_19_ISR_USED) && (defined GPT_EMIOS_0_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if ( (defined GPT_EMIOS_0_CH_18_ISR_USED) || (defined GPT_EMIOS_0_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_18_ISR_USED) || (defined PWM_EMIOS_0_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_18_ISR_USED) || (defined ICU_EMIOS_0_CH_19_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 18 and 19 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 18 and 19
*
* @note   This will be defined only if eMIOS channels 18 or 19 are configured in GPT, ICU or PWM
*            mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_18_CH_19_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_18_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_18_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_18_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_18 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 18)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_18 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 18)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_18_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_18);
                #endif

                #if(defined PWM_EMIOS_0_CH_18_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_18);
                #endif

                #if(defined ICU_EMIOS_0_CH_18_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_18);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_19_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_19_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_19_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_19 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 19)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_19 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 19)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_19_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_19);
                #endif

                #if(defined PWM_EMIOS_0_CH_19_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_19);
                #endif

                #if(defined ICU_EMIOS_0_CH_19_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_19);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:20,21 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_20
*/
#if  ((defined GPT_EMIOS_0_CH_20_ISR_USED) && (defined PWM_EMIOS_0_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined PWM_EMIOS_0_CH_20_ISR_USED) && (defined ICU_EMIOS_0_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined ICU_EMIOS_0_CH_20_ISR_USED) && (defined GPT_EMIOS_0_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_20"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_21
*/
#if  ((defined GPT_EMIOS_0_CH_21_ISR_USED) && (defined PWM_EMIOS_0_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined PWM_EMIOS_0_CH_21_ISR_USED) && (defined ICU_EMIOS_0_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined ICU_EMIOS_0_CH_21_ISR_USED) && (defined GPT_EMIOS_0_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if ( (defined GPT_EMIOS_0_CH_20_ISR_USED) || (defined GPT_EMIOS_0_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_20_ISR_USED) || (defined PWM_EMIOS_0_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_20_ISR_USED) || (defined ICU_EMIOS_0_CH_21_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 20 and 21 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 20 and 21
*
* @note   This will be defined only if eMIOS channels 20 or 21 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_20_CH_21_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_20_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_20_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_20_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_20 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 20)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_20 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 20)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_20_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_20);
                #endif

                #if(defined PWM_EMIOS_0_CH_20_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_20);
                #endif

                #if(defined ICU_EMIOS_0_CH_20_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_20);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_21_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_21_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_21_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_21 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 21)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_21 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 21)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_21_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_21);
                #endif

                #if(defined PWM_EMIOS_0_CH_21_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_21);
                #endif

                #if(defined ICU_EMIOS_0_CH_21_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_21);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:22,23 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_22
*/
#if  ((defined GPT_EMIOS_0_CH_22_ISR_USED) && (defined PWM_EMIOS_0_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined PWM_EMIOS_0_CH_22_ISR_USED) && (defined ICU_EMIOS_0_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined ICU_EMIOS_0_CH_22_ISR_USED) && (defined GPT_EMIOS_0_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_22"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_23
*/
#if  ((defined GPT_EMIOS_0_CH_23_ISR_USED) && (defined PWM_EMIOS_0_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined PWM_EMIOS_0_CH_23_ISR_USED) && (defined ICU_EMIOS_0_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined ICU_EMIOS_0_CH_23_ISR_USED) && (defined GPT_EMIOS_0_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if ( (defined GPT_EMIOS_0_CH_22_ISR_USED) || (defined GPT_EMIOS_0_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_22_ISR_USED) || (defined PWM_EMIOS_0_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_22_ISR_USED) || (defined ICU_EMIOS_0_CH_23_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 22 and 23 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 22 and 23
*
* @note   This will be defined only if eMIOS channels 22 or 23 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_22_CH_23_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_22_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_22_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_22_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_22 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 22)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_22 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 22)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_22_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_22);
                #endif

                #if(defined PWM_EMIOS_0_CH_22_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_22);
                #endif

                #if(defined ICU_EMIOS_0_CH_22_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_22);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_23_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_23_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_23_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_23 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 23)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_23 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 23)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_23_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_23);
                #endif

                #if(defined PWM_EMIOS_0_CH_23_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_23);
                #endif

                #if(defined ICU_EMIOS_0_CH_23_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_23);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:24,25 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_24
*/
#if  ((defined GPT_EMIOS_0_CH_24_ISR_USED) && (defined PWM_EMIOS_0_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined PWM_EMIOS_0_CH_24_ISR_USED) && (defined ICU_EMIOS_0_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined ICU_EMIOS_0_CH_24_ISR_USED) && (defined GPT_EMIOS_0_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_24"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_25
*/
#if  ((defined GPT_EMIOS_0_CH_25_ISR_USED) && (defined PWM_EMIOS_0_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined PWM_EMIOS_0_CH_25_ISR_USED) && (defined ICU_EMIOS_0_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined ICU_EMIOS_0_CH_25_ISR_USED) && (defined GPT_EMIOS_0_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if ( (defined GPT_EMIOS_0_CH_24_ISR_USED) || (defined GPT_EMIOS_0_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_24_ISR_USED) || (defined PWM_EMIOS_0_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_24_ISR_USED) || (defined ICU_EMIOS_0_CH_25_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 24 and 25 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 24 and 25
*
* @note   This will be defined only if eMIOS channels 24 or 25 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_24_CH_25_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_24_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_24_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_24_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_24 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 24)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_24 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 24)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_24_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_24);
                #endif

                #if(defined PWM_EMIOS_0_CH_24_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_24);
                #endif

                #if(defined ICU_EMIOS_0_CH_24_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_24);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_25_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_25_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_25_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_25 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 25)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_25 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 25)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_25_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_25);
                #endif

                #if(defined PWM_EMIOS_0_CH_25_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_25);
                #endif

                #if(defined ICU_EMIOS_0_CH_25_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_25);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:26,27 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_26
*/
#if  ((defined GPT_EMIOS_0_CH_26_ISR_USED) && (defined PWM_EMIOS_0_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined PWM_EMIOS_0_CH_26_ISR_USED) && (defined ICU_EMIOS_0_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined ICU_EMIOS_0_CH_26_ISR_USED) && (defined GPT_EMIOS_0_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_26"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_27
*/
#if  ((defined GPT_EMIOS_0_CH_27_ISR_USED) && (defined PWM_EMIOS_0_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined PWM_EMIOS_0_CH_27_ISR_USED) && (defined ICU_EMIOS_0_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined ICU_EMIOS_0_CH_27_ISR_USED) && (defined GPT_EMIOS_0_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if ( (defined GPT_EMIOS_0_CH_26_ISR_USED) || (defined GPT_EMIOS_0_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_26_ISR_USED) || (defined PWM_EMIOS_0_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_26_ISR_USED) || (defined ICU_EMIOS_0_CH_27_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 26 and 27 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 26 and 27
*
* @note   This will be defined only if eMIOS channels 26 or 27 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_26_CH_27_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_26_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_26_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_26_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_26 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 26)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_26 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 26)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_26_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_26);
                #endif

                #if(defined PWM_EMIOS_0_CH_26_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_26);
                #endif

                #if(defined ICU_EMIOS_0_CH_26_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_26);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_27_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_27_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_27_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_27 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 27)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_27 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 27)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_27_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_27);
                #endif

                #if(defined PWM_EMIOS_0_CH_27_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_27);
                #endif

                #if(defined ICU_EMIOS_0_CH_27_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_27);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:28,29 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_28
*/
#if  ((defined GPT_EMIOS_0_CH_28_ISR_USED) && (defined PWM_EMIOS_0_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined PWM_EMIOS_0_CH_28_ISR_USED) && (defined ICU_EMIOS_0_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined ICU_EMIOS_0_CH_28_ISR_USED) && (defined GPT_EMIOS_0_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_28"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_29
*/
#if  ((defined GPT_EMIOS_0_CH_29_ISR_USED) && (defined PWM_EMIOS_0_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined PWM_EMIOS_0_CH_29_ISR_USED) && (defined ICU_EMIOS_0_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined ICU_EMIOS_0_CH_29_ISR_USED) && (defined GPT_EMIOS_0_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if ( (defined GPT_EMIOS_0_CH_28_ISR_USED) || (defined GPT_EMIOS_0_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_28_ISR_USED) || (defined PWM_EMIOS_0_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_28_ISR_USED) || (defined ICU_EMIOS_0_CH_29_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 28 and 29 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 28 and 29
*
* @note   This will be defined only if eMIOS channels 28 or 29 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_28_CH_29_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_28_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_28_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_28_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_28 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 28)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_28 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 28)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_28_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_28);
                #endif

                #if(defined PWM_EMIOS_0_CH_28_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_28);
                #endif

                #if(defined ICU_EMIOS_0_CH_28_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_28);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_29_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_29_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_29_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_29 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 29)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_29 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 29)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_29_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_29);
                #endif

                #if(defined PWM_EMIOS_0_CH_29_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_29);
                #endif

                #if(defined ICU_EMIOS_0_CH_29_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_29);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:30,31 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_30
*/
#if  ((defined GPT_EMIOS_0_CH_30_ISR_USED) && (defined PWM_EMIOS_0_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined PWM_EMIOS_0_CH_30_ISR_USED) && (defined ICU_EMIOS_0_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined ICU_EMIOS_0_CH_30_ISR_USED) && (defined GPT_EMIOS_0_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_30"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_31
*/
#if  ((defined GPT_EMIOS_0_CH_31_ISR_USED) && (defined PWM_EMIOS_0_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined PWM_EMIOS_0_CH_31_ISR_USED) && (defined ICU_EMIOS_0_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined ICU_EMIOS_0_CH_31_ISR_USED) && (defined GPT_EMIOS_0_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if ( (defined GPT_EMIOS_0_CH_30_ISR_USED) || (defined GPT_EMIOS_0_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_30_ISR_USED) || (defined PWM_EMIOS_0_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_30_ISR_USED) || (defined ICU_EMIOS_0_CH_31_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 30 and 31 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channels 30 and 31
*
* @note   This will be defined only if eMIOS channels 30 or 31 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_30_CH_31_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_30_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_30_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_30_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_30 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 30)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_30 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */        
        if ( ( REG_READ32(EMIOS_CSR(0, 30)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_30_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_30);
                #endif

                #if(defined PWM_EMIOS_0_CH_30_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_30);
                #endif

                #if(defined ICU_EMIOS_0_CH_30_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_30);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_31_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_31_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_31_ISR_USED) )

    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_31 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(0, 31)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_31 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(0, 31)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_0_CH_31_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_31);
                #endif

                #if(defined PWM_EMIOS_0_CH_31_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_31);
                #endif

                #if(defined ICU_EMIOS_0_CH_31_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_31);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 0 common interrupts END ********************************/



/*********************************** EMIOS 1 common interrupts START ******************************/


/*
* @brief EMIOS module:1 channels:0,1 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_0
*/
#if  ((defined GPT_EMIOS_1_CH_0_ISR_USED) && (defined PWM_EMIOS_1_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined PWM_EMIOS_1_CH_0_ISR_USED) && (defined ICU_EMIOS_1_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined ICU_EMIOS_1_CH_0_ISR_USED) && (defined GPT_EMIOS_1_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_0"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_1
*/
#if  ((defined GPT_EMIOS_1_CH_1_ISR_USED) && (defined PWM_EMIOS_1_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined PWM_EMIOS_1_CH_1_ISR_USED) && (defined ICU_EMIOS_1_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined ICU_EMIOS_1_CH_1_ISR_USED) && (defined GPT_EMIOS_1_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if ( (defined GPT_EMIOS_1_CH_0_ISR_USED) || (defined GPT_EMIOS_1_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_0_ISR_USED) || (defined PWM_EMIOS_1_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_0_ISR_USED) || (defined ICU_EMIOS_1_CH_1_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 0 and 1 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 0 and 1
*
* @note   This will be defined only if eMIOS channels 0 or 1 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_0_CH_1_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_0_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_0_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_0_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_0 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 0)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_0 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 0)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_0_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_0);
                #endif

                #if(defined PWM_EMIOS_1_CH_0_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_0);
                #endif

                #if(defined ICU_EMIOS_1_CH_0_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_0);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_1_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_1_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_1_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_1 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 1)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_1 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 1)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_1_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_1);
                #endif

                #if(defined PWM_EMIOS_1_CH_1_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_1);
                #endif

                #if(defined ICU_EMIOS_1_CH_1_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_1);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:2,3 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_2
*/
#if  ((defined GPT_EMIOS_1_CH_2_ISR_USED) && (defined PWM_EMIOS_1_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined PWM_EMIOS_1_CH_2_ISR_USED) && (defined ICU_EMIOS_1_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined ICU_EMIOS_1_CH_2_ISR_USED) && (defined GPT_EMIOS_1_CH_2_ISR_USED))
#error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_2"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_3
*/
#if  ((defined GPT_EMIOS_1_CH_3_ISR_USED) && (defined PWM_EMIOS_1_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined PWM_EMIOS_1_CH_3_ISR_USED) && (defined ICU_EMIOS_1_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined ICU_EMIOS_1_CH_3_ISR_USED) && (defined GPT_EMIOS_1_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if ( (defined GPT_EMIOS_1_CH_2_ISR_USED) || (defined GPT_EMIOS_1_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_2_ISR_USED) || (defined PWM_EMIOS_1_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_2_ISR_USED) || (defined ICU_EMIOS_1_CH_3_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 2 and 3 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 2 and 3
*
* @note   This will be defined only if eMIOS channels 2 or 3 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_2_CH_3_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_2_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_2_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_2_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 2)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_2 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 2)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_2_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_2);
                #endif

                #if(defined PWM_EMIOS_1_CH_2_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_2);
                #endif

                #if(defined ICU_EMIOS_1_CH_2_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_2);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_3_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_3_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_3_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_3 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 3)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_3 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 3)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_3_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_3);
                #endif

                #if(defined PWM_EMIOS_1_CH_3_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_3);
                #endif

                #if(defined ICU_EMIOS_1_CH_3_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_3);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:4,5 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_4
*/
#if  ((defined GPT_EMIOS_1_CH_4_ISR_USED) && (defined PWM_EMIOS_1_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined PWM_EMIOS_1_CH_4_ISR_USED) && (defined ICU_EMIOS_1_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined ICU_EMIOS_1_CH_4_ISR_USED) && (defined GPT_EMIOS_1_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_4"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_5
*/
#if  ((defined GPT_EMIOS_1_CH_5_ISR_USED) && (defined PWM_EMIOS_1_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined PWM_EMIOS_1_CH_5_ISR_USED) && (defined ICU_EMIOS_1_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined ICU_EMIOS_1_CH_5_ISR_USED) && (defined GPT_EMIOS_1_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if ( (defined GPT_EMIOS_1_CH_4_ISR_USED) || (defined GPT_EMIOS_1_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_4_ISR_USED) || (defined PWM_EMIOS_1_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_4_ISR_USED) || (defined ICU_EMIOS_1_CH_5_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 4 and 5 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 4 and 5
* @note   This will be defined only if eMIOS channels 4 or 5 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_4_CH_5_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_4_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_4_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_4_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_4 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 4)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_4 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 4)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_4_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_4);
                #endif

                #if(defined PWM_EMIOS_1_CH_4_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_4);
                #endif

                #if(defined ICU_EMIOS_1_CH_4_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_4);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_5_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_5_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_5_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_5 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 5)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_5 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 5)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_5_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_5);
                #endif

                #if(defined PWM_EMIOS_1_CH_5_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_5);
                #endif

                #if(defined ICU_EMIOS_1_CH_5_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_5);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:6,7 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_6
*/
#if  ((defined GPT_EMIOS_1_CH_6_ISR_USED) && (defined PWM_EMIOS_1_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined PWM_EMIOS_1_CH_6_ISR_USED) && (defined ICU_EMIOS_1_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined ICU_EMIOS_1_CH_6_ISR_USED) && (defined GPT_EMIOS_1_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_6"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_7
*/
#if  ((defined GPT_EMIOS_1_CH_7_ISR_USED) && (defined PWM_EMIOS_1_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined PWM_EMIOS_1_CH_7_ISR_USED) && (defined ICU_EMIOS_1_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined ICU_EMIOS_1_CH_7_ISR_USED) && (defined GPT_EMIOS_1_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if ( (defined GPT_EMIOS_1_CH_6_ISR_USED) || (defined GPT_EMIOS_1_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_6_ISR_USED) || (defined PWM_EMIOS_1_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_6_ISR_USED) || (defined ICU_EMIOS_1_CH_7_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 6 and 7 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 6 and 7
*
* @note   This will be defined only if eMIOS channels 6 or 7 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_6_CH_7_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_6_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_6_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_6_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_6 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 6)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_6 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 6)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_6_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_6);
                #endif

                #if(defined PWM_EMIOS_1_CH_6_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_6);
                #endif

                #if(defined ICU_EMIOS_1_CH_6_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_6);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_7_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_7_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_7_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_7 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 7)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_7 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 7)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_7_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_7);
                #endif

                #if(defined PWM_EMIOS_1_CH_7_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_7);
                #endif

                #if(defined ICU_EMIOS_1_CH_7_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_7);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:8,9 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_8
*/
#if  ((defined GPT_EMIOS_1_CH_8_ISR_USED) && (defined PWM_EMIOS_1_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined PWM_EMIOS_1_CH_8_ISR_USED) && (defined ICU_EMIOS_1_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined ICU_EMIOS_1_CH_8_ISR_USED) && (defined GPT_EMIOS_1_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_8"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_9
*/
#if  ((defined GPT_EMIOS_1_CH_9_ISR_USED) && (defined PWM_EMIOS_1_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined PWM_EMIOS_1_CH_9_ISR_USED) && (defined ICU_EMIOS_1_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined ICU_EMIOS_1_CH_9_ISR_USED) && (defined GPT_EMIOS_1_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if ( (defined GPT_EMIOS_1_CH_8_ISR_USED) || (defined GPT_EMIOS_1_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_8_ISR_USED) || (defined PWM_EMIOS_1_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_8_ISR_USED) || (defined ICU_EMIOS_1_CH_9_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 8 and 9 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 8 and 9
*
* @note   This will be defined only if eMIOS channels 8 or 9 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_8_CH_9_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_8_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_8_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_8_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_8 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 8)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_8 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 8)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_8_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_8);
                #endif

                #if(defined PWM_EMIOS_1_CH_8_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_8);
                #endif

                #if(defined ICU_EMIOS_1_CH_8_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_8);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_9_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_9_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_9_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_9 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 9)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_9 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 9)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_9_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_9);
                #endif

                #if(defined PWM_EMIOS_1_CH_9_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_9);
                #endif

                #if(defined ICU_EMIOS_1_CH_9_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_9);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:10,11 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_10
*/
#if  ((defined GPT_EMIOS_1_CH_10_ISR_USED) && (defined PWM_EMIOS_1_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined PWM_EMIOS_1_CH_10_ISR_USED) && (defined ICU_EMIOS_1_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined ICU_EMIOS_1_CH_10_ISR_USED) && (defined GPT_EMIOS_1_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_10"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_11
*/
#if  ((defined GPT_EMIOS_1_CH_11_ISR_USED) && (defined PWM_EMIOS_1_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined PWM_EMIOS_1_CH_11_ISR_USED) && (defined ICU_EMIOS_1_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined ICU_EMIOS_1_CH_11_ISR_USED) && (defined GPT_EMIOS_1_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if ( (defined GPT_EMIOS_1_CH_10_ISR_USED) || (defined GPT_EMIOS_1_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_10_ISR_USED) || (defined PWM_EMIOS_1_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_10_ISR_USED) || (defined ICU_EMIOS_1_CH_11_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 10 and 11 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 10 and 11
*
* @note     This will be defined only if eMIOS channels 10 or 11 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_10_CH_11_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_10_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_10_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_10_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_10 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 10)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_10 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 10)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_10_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_10);
                #endif

                #if(defined PWM_EMIOS_1_CH_10_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_10);
                #endif

                #if(defined ICU_EMIOS_1_CH_10_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_10);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_11_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_11_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_11_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_11 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 11)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_11 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 11)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_11_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_11);
                #endif

                #if(defined PWM_EMIOS_1_CH_11_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_11);
                #endif

                #if(defined ICU_EMIOS_1_CH_11_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_11);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:12,13 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_12
*/
#if  ((defined GPT_EMIOS_1_CH_12_ISR_USED) && (defined PWM_EMIOS_1_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined PWM_EMIOS_1_CH_12_ISR_USED) && (defined ICU_EMIOS_1_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined ICU_EMIOS_1_CH_12_ISR_USED) && (defined GPT_EMIOS_1_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_12"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_13
*/
#if  ((defined GPT_EMIOS_1_CH_13_ISR_USED) && (defined PWM_EMIOS_1_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined PWM_EMIOS_1_CH_13_ISR_USED) && (defined ICU_EMIOS_1_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined ICU_EMIOS_1_CH_13_ISR_USED) && (defined GPT_EMIOS_1_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if ( (defined GPT_EMIOS_1_CH_12_ISR_USED) || (defined GPT_EMIOS_1_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_12_ISR_USED) || (defined PWM_EMIOS_1_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_12_ISR_USED) || (defined ICU_EMIOS_1_CH_13_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 12 and 13 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 12 and 13
*
* @note   This will be defined only if eMIOS channels 12 or 13 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_12_CH_13_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_12_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_12_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_12_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_12 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 12)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_12 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 12)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_12_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_12);
                #endif

                #if(defined PWM_EMIOS_1_CH_12_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_12);
                #endif

                #if(defined ICU_EMIOS_1_CH_12_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_12);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_13_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_13_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_13_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_13 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 13)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_13 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 13)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_13_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_13);
                #endif

                #if(defined PWM_EMIOS_1_CH_13_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_13);
                #endif

                #if(defined ICU_EMIOS_1_CH_13_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_13);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:14,15 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_14
*/
#if  ((defined GPT_EMIOS_1_CH_14_ISR_USED) && (defined PWM_EMIOS_1_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined PWM_EMIOS_1_CH_14_ISR_USED) && (defined ICU_EMIOS_1_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined ICU_EMIOS_1_CH_14_ISR_USED) && (defined GPT_EMIOS_1_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_14"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_15
*/
#if  ((defined GPT_EMIOS_1_CH_15_ISR_USED) && (defined PWM_EMIOS_1_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined PWM_EMIOS_1_CH_15_ISR_USED) && (defined ICU_EMIOS_1_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined ICU_EMIOS_1_CH_15_ISR_USED) && (defined GPT_EMIOS_1_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if ( (defined GPT_EMIOS_1_CH_14_ISR_USED) || (defined GPT_EMIOS_1_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_14_ISR_USED) || (defined PWM_EMIOS_1_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_14_ISR_USED) || (defined ICU_EMIOS_1_CH_15_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 14 and 15 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 14 and 15
*
* @note   This will be defined only if eMIOS channels 14 or 15 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_14_CH_15_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_14_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_14_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_14_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_14 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 14)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_14 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 14)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_14_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_14);
                #endif

                #if(defined PWM_EMIOS_1_CH_14_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_14);
                #endif

                #if(defined ICU_EMIOS_1_CH_14_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_14);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_15_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_15_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_15_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_15 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 15)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_15 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 15)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_15_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_15);
                #endif

                #if(defined PWM_EMIOS_1_CH_15_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_15);
                #endif

                #if(defined ICU_EMIOS_1_CH_15_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_15);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:16,17 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_16
*/
#if  ((defined GPT_EMIOS_1_CH_16_ISR_USED) && (defined PWM_EMIOS_1_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined PWM_EMIOS_1_CH_16_ISR_USED) && (defined ICU_EMIOS_1_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined ICU_EMIOS_1_CH_16_ISR_USED) && (defined GPT_EMIOS_1_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_16"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_17
*/
#if  ((defined GPT_EMIOS_1_CH_17_ISR_USED) && (defined PWM_EMIOS_1_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined PWM_EMIOS_1_CH_17_ISR_USED) && (defined ICU_EMIOS_1_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined ICU_EMIOS_1_CH_17_ISR_USED) && (defined GPT_EMIOS_1_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if ( (defined GPT_EMIOS_1_CH_16_ISR_USED) || (defined GPT_EMIOS_1_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_16_ISR_USED) || (defined PWM_EMIOS_1_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_16_ISR_USED) || (defined ICU_EMIOS_1_CH_17_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 16 and 17 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 16 and 17
*
* @note   This will be defined only if eMIOS channels 16 or 17 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_16_CH_17_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_16_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_16_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_16_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_16 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 16)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_16 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 16)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_16_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_16);
                #endif

                #if(defined PWM_EMIOS_1_CH_16_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_16);
                #endif

                #if(defined ICU_EMIOS_1_CH_16_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_16);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_17_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_17_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_17_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_17 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 17)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_17 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 17)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_17_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_17);
                #endif

                #if(defined PWM_EMIOS_1_CH_17_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_17);
                #endif

                #if(defined ICU_EMIOS_1_CH_17_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_17);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
   /* @violates @ref eMios_Irq_c_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:18,19 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_18
*/
#if  ((defined GPT_EMIOS_1_CH_18_ISR_USED) && (defined PWM_EMIOS_1_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined PWM_EMIOS_1_CH_18_ISR_USED) && (defined ICU_EMIOS_1_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined ICU_EMIOS_1_CH_18_ISR_USED) && (defined GPT_EMIOS_1_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_18"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_19
*/
#if  ((defined GPT_EMIOS_1_CH_19_ISR_USED) && (defined PWM_EMIOS_1_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined PWM_EMIOS_1_CH_19_ISR_USED) && (defined ICU_EMIOS_1_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined ICU_EMIOS_1_CH_19_ISR_USED) && (defined GPT_EMIOS_1_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if ( (defined GPT_EMIOS_1_CH_18_ISR_USED) || (defined GPT_EMIOS_1_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_18_ISR_USED) || (defined PWM_EMIOS_1_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_18_ISR_USED) || (defined ICU_EMIOS_1_CH_19_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 18 and 19 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 18 and 19
*
* @note   This will be defined only if eMIOS channels 18 or 19 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_18_CH_19_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_18_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_18_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_18_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_18 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 18)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_18 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 18)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_18_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_18);
                #endif

                #if(defined PWM_EMIOS_1_CH_18_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_18);
                #endif

                #if(defined ICU_EMIOS_1_CH_18_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_18);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_19_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_19_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_19_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_19 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 19)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_19 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 19)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_19_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_19);
                #endif

                #if(defined PWM_EMIOS_1_CH_19_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_19);
                #endif

                #if(defined ICU_EMIOS_1_CH_19_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_19);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:20,21 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_20
*/
#if  ((defined GPT_EMIOS_1_CH_20_ISR_USED) && (defined PWM_EMIOS_1_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined PWM_EMIOS_1_CH_20_ISR_USED) && (defined ICU_EMIOS_1_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined ICU_EMIOS_1_CH_20_ISR_USED) && (defined GPT_EMIOS_1_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_20"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_21
*/
#if  ((defined GPT_EMIOS_1_CH_21_ISR_USED) && (defined PWM_EMIOS_1_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined PWM_EMIOS_1_CH_21_ISR_USED) && (defined ICU_EMIOS_1_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined ICU_EMIOS_1_CH_21_ISR_USED) && (defined GPT_EMIOS_1_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if ( (defined GPT_EMIOS_1_CH_20_ISR_USED) || (defined GPT_EMIOS_1_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_20_ISR_USED) || (defined PWM_EMIOS_1_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_20_ISR_USED) || (defined ICU_EMIOS_1_CH_21_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 20 and 21 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 20 and 21
*
* @note   This will be defined only if eMIOS channels 20 or 21 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_20_CH_21_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_20_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_20_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_20_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_20 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 20)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_20 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 20)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_20_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_20);
                #endif

                #if(defined PWM_EMIOS_1_CH_20_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_20);
                #endif

                #if(defined ICU_EMIOS_1_CH_20_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_20);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_21_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_21_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_21_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_21 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 21)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_21 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 21)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_21_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_21);
                #endif

                #if(defined PWM_EMIOS_1_CH_21_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_21);
                #endif

                #if(defined ICU_EMIOS_1_CH_21_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_21);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:22,23 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_22
*/
#if  ((defined GPT_EMIOS_1_CH_22_ISR_USED) && (defined PWM_EMIOS_1_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined PWM_EMIOS_1_CH_22_ISR_USED) && (defined ICU_EMIOS_1_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined ICU_EMIOS_1_CH_22_ISR_USED) && (defined GPT_EMIOS_1_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_22"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_23
*/
#if  ((defined GPT_EMIOS_1_CH_23_ISR_USED) && (defined PWM_EMIOS_1_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined PWM_EMIOS_1_CH_23_ISR_USED) && (defined ICU_EMIOS_1_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined ICU_EMIOS_1_CH_23_ISR_USED) && (defined GPT_EMIOS_1_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if ( (defined GPT_EMIOS_1_CH_22_ISR_USED) || (defined GPT_EMIOS_1_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_22_ISR_USED) || (defined PWM_EMIOS_1_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_22_ISR_USED) || (defined ICU_EMIOS_1_CH_23_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 22 and 23 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 22 and 23
*
* @note   This will be defined only if eMIOS channels 22 or 23 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/  
ISR(EMIOS_1_CH_22_CH_23_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_22_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_22_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_22_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_22 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 22)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_22 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 22)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_22_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_22);
                #endif

                #if(defined PWM_EMIOS_1_CH_22_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_22);
                #endif

                #if(defined ICU_EMIOS_1_CH_22_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_22);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_23_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_23_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_23_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_23 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 23)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_23 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 23)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_23_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_23);
                #endif

                #if(defined PWM_EMIOS_1_CH_23_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_23);
                #endif

                #if(defined ICU_EMIOS_1_CH_23_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_23);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:24,25 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_24
*/
#if  ((defined GPT_EMIOS_1_CH_24_ISR_USED) && (defined PWM_EMIOS_1_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined PWM_EMIOS_1_CH_24_ISR_USED) && (defined ICU_EMIOS_1_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined ICU_EMIOS_1_CH_24_ISR_USED) && (defined GPT_EMIOS_1_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_24"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_25
*/
#if  ((defined GPT_EMIOS_1_CH_25_ISR_USED) && (defined PWM_EMIOS_1_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined PWM_EMIOS_1_CH_25_ISR_USED) && (defined ICU_EMIOS_1_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined ICU_EMIOS_1_CH_25_ISR_USED) && (defined GPT_EMIOS_1_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if ( (defined GPT_EMIOS_1_CH_24_ISR_USED) || (defined GPT_EMIOS_1_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_24_ISR_USED) || (defined PWM_EMIOS_1_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_24_ISR_USED) || (defined ICU_EMIOS_1_CH_25_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 24 and 25 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 24 and 25
*
* @note   This will be defined only if eMIOS channels 24 or 25 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/  
ISR(EMIOS_1_CH_24_CH_25_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_24_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_24_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_24_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_24 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 24)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_24 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 24)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_24_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_24);
                #endif

                #if(defined PWM_EMIOS_1_CH_24_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_24);
                #endif

                #if(defined ICU_EMIOS_1_CH_24_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_24);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_25_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_25_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_25_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_25 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 25)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_25 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 25)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_25_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_25);
                #endif

                #if(defined PWM_EMIOS_1_CH_25_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_25);
                #endif

                #if(defined ICU_EMIOS_1_CH_25_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_25);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:26,27 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_26
*/
#if  ((defined GPT_EMIOS_1_CH_26_ISR_USED) && (defined PWM_EMIOS_1_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined PWM_EMIOS_1_CH_26_ISR_USED) && (defined ICU_EMIOS_1_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined ICU_EMIOS_1_CH_26_ISR_USED) && (defined GPT_EMIOS_1_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_26"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_27
*/
#if  ((defined GPT_EMIOS_1_CH_27_ISR_USED) && (defined PWM_EMIOS_1_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined PWM_EMIOS_1_CH_27_ISR_USED) && (defined ICU_EMIOS_1_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined ICU_EMIOS_1_CH_27_ISR_USED) && (defined GPT_EMIOS_1_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if ( (defined GPT_EMIOS_1_CH_26_ISR_USED) || (defined GPT_EMIOS_1_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_26_ISR_USED) || (defined PWM_EMIOS_1_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_26_ISR_USED) || (defined ICU_EMIOS_1_CH_27_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 26 and 27 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 26 and 27
*
* @note   This will be defined only if eMIOS channels 26 or 27 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_26_CH_27_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_26_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_26_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_26_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_26 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 26)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_26 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 26)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_26_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_26);
                #endif

                #if(defined PWM_EMIOS_1_CH_26_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_26);
                #endif

                #if(defined ICU_EMIOS_1_CH_26_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_26);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_27_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_27_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_27_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_27 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 27)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_27 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 27)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_27_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_27);
                #endif

                #if(defined PWM_EMIOS_1_CH_27_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_27);
                #endif

                #if(defined ICU_EMIOS_1_CH_27_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_27);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:28,29 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_28
*/
#if  ((defined GPT_EMIOS_1_CH_28_ISR_USED) && (defined PWM_EMIOS_1_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined PWM_EMIOS_1_CH_28_ISR_USED) && (defined ICU_EMIOS_1_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined ICU_EMIOS_1_CH_28_ISR_USED) && (defined GPT_EMIOS_1_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_28"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_29
*/
#if  ((defined GPT_EMIOS_1_CH_29_ISR_USED) && (defined PWM_EMIOS_1_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined PWM_EMIOS_1_CH_29_ISR_USED) && (defined ICU_EMIOS_1_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined ICU_EMIOS_1_CH_29_ISR_USED) && (defined GPT_EMIOS_1_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if ( (defined GPT_EMIOS_1_CH_28_ISR_USED) || (defined GPT_EMIOS_1_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_28_ISR_USED) || (defined PWM_EMIOS_1_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_28_ISR_USED) || (defined ICU_EMIOS_1_CH_29_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 28 and 29 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 28 and 29
*
* @note   This will be defined only if eMIOS channels 28 or 29 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_28_CH_29_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_28_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_28_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_28_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_28 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 28)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_28 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 28)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_28_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_28);
                #endif

                #if(defined PWM_EMIOS_1_CH_28_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_28);
                #endif

                #if(defined ICU_EMIOS_1_CH_28_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_28);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_29_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_29_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_29_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_29 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 29)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_29 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 29)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_29_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_29);
                #endif

                #if(defined PWM_EMIOS_1_CH_29_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_29);
                #endif

                #if(defined ICU_EMIOS_1_CH_29_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_29);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:30,31 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_30
*/
#if  ((defined GPT_EMIOS_1_CH_30_ISR_USED) && (defined PWM_EMIOS_1_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined PWM_EMIOS_1_CH_30_ISR_USED) && (defined ICU_EMIOS_1_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined ICU_EMIOS_1_CH_30_ISR_USED) && (defined GPT_EMIOS_1_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

/*
* @brief resource conflict check for EMIOS_1_CH_31
*/
#if  ((defined GPT_EMIOS_1_CH_31_ISR_USED) && (defined PWM_EMIOS_1_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined PWM_EMIOS_1_CH_31_ISR_USED) && (defined ICU_EMIOS_1_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined ICU_EMIOS_1_CH_31_ISR_USED) && (defined GPT_EMIOS_1_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if ( (defined GPT_EMIOS_1_CH_30_ISR_USED) || (defined GPT_EMIOS_1_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_30_ISR_USED) || (defined PWM_EMIOS_1_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_30_ISR_USED) || (defined ICU_EMIOS_1_CH_31_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 30 and 31 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channels 30 and 31
*
* @note   This will be defined only if eMIOS channels 30 or 31 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_30_CH_31_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_30_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_30_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_30_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_30 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 30)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_30 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 30)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_30_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_30);
                #endif

                #if(defined PWM_EMIOS_1_CH_30_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_30);
                #endif

                #if(defined ICU_EMIOS_1_CH_30_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_30);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_31_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_31_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_31_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_31 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(1, 31)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_31 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(1, 31)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_1_CH_31_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_31);
                #endif

                #if(defined PWM_EMIOS_1_CH_31_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_31);
                #endif

                #if(defined ICU_EMIOS_1_CH_31_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_31);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 1 common interrupts END ********************************/


/********************************** EMIOS 2 common interrupts START ********************************/
/*
* @brief EMIOS module:2 channels:0,1 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_0
*/
#if  ((defined GPT_EMIOS_2_CH_0_ISR_USED) && (defined PWM_EMIOS_2_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined PWM_EMIOS_2_CH_0_ISR_USED) && (defined ICU_EMIOS_2_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined ICU_EMIOS_2_CH_0_ISR_USED) && (defined GPT_EMIOS_2_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_0"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_1
*/
#if  ((defined GPT_EMIOS_2_CH_1_ISR_USED) && (defined PWM_EMIOS_2_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined PWM_EMIOS_2_CH_1_ISR_USED) && (defined ICU_EMIOS_2_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined ICU_EMIOS_2_CH_1_ISR_USED) && (defined GPT_EMIOS_2_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if ( (defined GPT_EMIOS_2_CH_0_ISR_USED) || (defined GPT_EMIOS_2_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_0_ISR_USED) || (defined PWM_EMIOS_2_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_0_ISR_USED) || (defined ICU_EMIOS_2_CH_1_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 0 and 1 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 0 and 1
* @note   This will be defined only if eMIOS channels 0 or 1 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_0_CH_1_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_0_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_0_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_0_ISR_USED) )

    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 0)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_2 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 0)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_0_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_0);
                #endif

                #if(defined PWM_EMIOS_2_CH_0_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_0);
                #endif

                #if(defined ICU_EMIOS_2_CH_0_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_0);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_1_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_1_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_1_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_1 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 1)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_1 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 1)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_1_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_1);
                #endif

                #if(defined PWM_EMIOS_2_CH_1_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_1);
                #endif

                #if(defined ICU_EMIOS_2_CH_1_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_1);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:2,3 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_2
*/
#if  ((defined GPT_EMIOS_2_CH_2_ISR_USED) && (defined PWM_EMIOS_2_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined PWM_EMIOS_2_CH_2_ISR_USED) && (defined ICU_EMIOS_2_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined ICU_EMIOS_2_CH_2_ISR_USED) && (defined GPT_EMIOS_2_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_2"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_3
*/
#if  ((defined GPT_EMIOS_2_CH_3_ISR_USED) && (defined PWM_EMIOS_2_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined PWM_EMIOS_2_CH_3_ISR_USED) && (defined ICU_EMIOS_2_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined ICU_EMIOS_2_CH_3_ISR_USED) && (defined GPT_EMIOS_2_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if ( (defined GPT_EMIOS_2_CH_2_ISR_USED) || (defined GPT_EMIOS_2_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_2_ISR_USED) || (defined PWM_EMIOS_2_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_2_ISR_USED) || (defined ICU_EMIOS_2_CH_3_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 2 and 3 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 2 and 3
*
* @note   This will be defined only if eMIOS channels 2 or 3 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_2_CH_3_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_2_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_2_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_2_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 2)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_2 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */    
        if ( ( REG_READ32(EMIOS_CSR(2, 2)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_2_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_2);
                #endif

                #if(defined PWM_EMIOS_2_CH_2_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_2);
                #endif

                #if(defined ICU_EMIOS_2_CH_2_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_2);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_3_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_3_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_3_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_3 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 3)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_3 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 3)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_3_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_3);
                #endif

                #if(defined PWM_EMIOS_2_CH_3_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_3);
                #endif

                #if(defined ICU_EMIOS_2_CH_3_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_3);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
  /* @violates @ref eMios_Irq_c_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:4,5 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_4
*/
#if  ((defined GPT_EMIOS_2_CH_4_ISR_USED) && (defined PWM_EMIOS_2_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined PWM_EMIOS_2_CH_4_ISR_USED) && (defined ICU_EMIOS_2_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined ICU_EMIOS_2_CH_4_ISR_USED) && (defined GPT_EMIOS_2_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_4"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_5
*/
#if  ((defined GPT_EMIOS_2_CH_5_ISR_USED) && (defined PWM_EMIOS_2_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined PWM_EMIOS_2_CH_5_ISR_USED) && (defined ICU_EMIOS_2_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined ICU_EMIOS_2_CH_5_ISR_USED) && (defined GPT_EMIOS_2_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if ( (defined GPT_EMIOS_2_CH_4_ISR_USED) || (defined GPT_EMIOS_2_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_4_ISR_USED) || (defined PWM_EMIOS_2_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_4_ISR_USED) || (defined ICU_EMIOS_2_CH_5_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 4 and 5 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 4 and 5
*
* @note   This will be defined only if eMIOS channels 4 or 5 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_4_CH_5_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_4_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_4_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_4_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_4 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 4)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_4 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 4)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_4_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_4);
                #endif

                #if(defined PWM_EMIOS_2_CH_4_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_4);
                #endif

                #if(defined ICU_EMIOS_2_CH_4_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_4);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_5_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_5_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_5_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_5 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 5)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_5 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 5)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_5_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_5);
                #endif

                #if(defined PWM_EMIOS_2_CH_5_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_5);
                #endif

                #if(defined ICU_EMIOS_2_CH_5_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_5);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:6,7 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_6
*/
#if  ((defined GPT_EMIOS_2_CH_6_ISR_USED) && (defined PWM_EMIOS_2_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined PWM_EMIOS_2_CH_6_ISR_USED) && (defined ICU_EMIOS_2_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined ICU_EMIOS_2_CH_6_ISR_USED) && (defined GPT_EMIOS_2_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_6"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_7
*/
#if  ((defined GPT_EMIOS_2_CH_7_ISR_USED) && (defined PWM_EMIOS_2_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined PWM_EMIOS_2_CH_7_ISR_USED) && (defined ICU_EMIOS_2_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined ICU_EMIOS_2_CH_7_ISR_USED) && (defined GPT_EMIOS_2_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if ( (defined GPT_EMIOS_2_CH_6_ISR_USED) || (defined GPT_EMIOS_2_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_6_ISR_USED) || (defined PWM_EMIOS_2_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_6_ISR_USED) || (defined ICU_EMIOS_2_CH_7_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 6 and 7 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 6 and 7
*
* @note   This will be defined only if eMIOS channels 6 or 7 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_6_CH_7_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_6_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_6_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_6_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_6 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 6)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_6 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 6)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_6_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_6);
                #endif

                #if(defined PWM_EMIOS_2_CH_6_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_6);
                #endif

                #if(defined ICU_EMIOS_2_CH_6_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_6);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_7_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_7_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_7_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_7 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 7)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_7 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 7)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_7_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_7);
                #endif

                #if(defined PWM_EMIOS_2_CH_7_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_7);
                #endif

                #if(defined ICU_EMIOS_2_CH_7_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_7);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:8,9 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_8
*/
#if  ((defined GPT_EMIOS_2_CH_8_ISR_USED) && (defined PWM_EMIOS_2_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined PWM_EMIOS_2_CH_8_ISR_USED) && (defined ICU_EMIOS_2_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined ICU_EMIOS_2_CH_8_ISR_USED) && (defined GPT_EMIOS_2_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_8"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_9
*/
#if  ((defined GPT_EMIOS_2_CH_9_ISR_USED) && (defined PWM_EMIOS_2_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined PWM_EMIOS_2_CH_9_ISR_USED) && (defined ICU_EMIOS_2_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined ICU_EMIOS_2_CH_9_ISR_USED) && (defined GPT_EMIOS_2_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if ( (defined GPT_EMIOS_2_CH_8_ISR_USED) || (defined GPT_EMIOS_2_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_8_ISR_USED) || (defined PWM_EMIOS_2_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_8_ISR_USED) || (defined ICU_EMIOS_2_CH_9_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 8 and 9 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 8 and 9
* @note   This will be defined only if eMIOS channels 8 or 9 are configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_8_CH_9_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_8_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_8_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_8_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_8 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 8)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_8 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 8)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_8_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_8);
                #endif

                #if(defined PWM_EMIOS_2_CH_8_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_8);
                #endif

                #if(defined ICU_EMIOS_2_CH_8_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_8);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_9_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_9_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_9_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_9 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 9)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_9 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 9)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_9_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_9);
                #endif

                #if(defined PWM_EMIOS_2_CH_9_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_9);
                #endif

                #if(defined ICU_EMIOS_2_CH_9_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_9);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
   /* @violates @ref eMios_Irq_c_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:10,11 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_10
*/
#if  ((defined GPT_EMIOS_2_CH_10_ISR_USED) && (defined PWM_EMIOS_2_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined PWM_EMIOS_2_CH_10_ISR_USED) && (defined ICU_EMIOS_2_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined ICU_EMIOS_2_CH_10_ISR_USED) && (defined GPT_EMIOS_2_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_10"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_11
*/
#if  ((defined GPT_EMIOS_2_CH_11_ISR_USED) && (defined PWM_EMIOS_2_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined PWM_EMIOS_2_CH_11_ISR_USED) && (defined ICU_EMIOS_2_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined ICU_EMIOS_2_CH_11_ISR_USED) && (defined GPT_EMIOS_2_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if ( (defined GPT_EMIOS_2_CH_10_ISR_USED) || (defined GPT_EMIOS_2_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_10_ISR_USED) || (defined PWM_EMIOS_2_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_10_ISR_USED) || (defined ICU_EMIOS_2_CH_11_ISR_USED) )

/*================================================================================================*/
/**
* @brief    Interrupt handler for eMIOS channels : 10 and 11 for eMIOS_2 module
* @details  Process the interrupt of eMIOS channels 10 and 11
*
*@note      This will be defined only if eMIOS channels 10 or 11 are configured in GPT, ICU or
*           PWM mode
*/
/*================================================================================================*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_10_CH_11_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_10_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_10_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_10_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_10 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 10)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_10 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 10)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_10_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_10);
                #endif

                #if(defined PWM_EMIOS_2_CH_10_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_10);
                #endif

                #if(defined ICU_EMIOS_2_CH_10_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_10);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_11_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_11_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_11_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_11 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 11)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_11 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 11)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_11_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_11);
                #endif

                #if(defined PWM_EMIOS_2_CH_11_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_11);
                #endif

                #if(defined ICU_EMIOS_2_CH_11_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_11);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:12,13 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_12
*/
#if  ((defined GPT_EMIOS_2_CH_12_ISR_USED) && (defined PWM_EMIOS_2_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined PWM_EMIOS_2_CH_12_ISR_USED) && (defined ICU_EMIOS_2_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined ICU_EMIOS_2_CH_12_ISR_USED) && (defined GPT_EMIOS_2_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_12"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_13
*/
#if  ((defined GPT_EMIOS_2_CH_13_ISR_USED) && (defined PWM_EMIOS_2_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined PWM_EMIOS_2_CH_13_ISR_USED) && (defined ICU_EMIOS_2_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined ICU_EMIOS_2_CH_13_ISR_USED) && (defined GPT_EMIOS_2_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if ( (defined GPT_EMIOS_2_CH_12_ISR_USED) || (defined GPT_EMIOS_2_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_12_ISR_USED) || (defined PWM_EMIOS_2_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_12_ISR_USED) || (defined ICU_EMIOS_2_CH_13_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 12 and 13 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 12 and 13
*
* @note     This will be defined only if eMIOS channels 12 or 13 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_12_CH_13_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_12_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_12_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_12_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_12 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 12)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_12 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 12)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_12_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_12);
                #endif

                #if(defined PWM_EMIOS_2_CH_12_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_12);
                #endif

                #if(defined ICU_EMIOS_2_CH_12_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_12);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_13_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_13_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_13_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_13 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 13)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_13 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 13)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_13_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_13);
                #endif

                #if(defined PWM_EMIOS_2_CH_13_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_13);
                #endif

                #if(defined ICU_EMIOS_2_CH_13_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_13);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:14,15 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_14
*/
#if  ((defined GPT_EMIOS_2_CH_14_ISR_USED) && (defined PWM_EMIOS_2_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined PWM_EMIOS_2_CH_14_ISR_USED) && (defined ICU_EMIOS_2_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined ICU_EMIOS_2_CH_14_ISR_USED) && (defined GPT_EMIOS_2_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_14"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_15
*/
#if  ((defined GPT_EMIOS_2_CH_15_ISR_USED) && (defined PWM_EMIOS_2_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined PWM_EMIOS_2_CH_15_ISR_USED) && (defined ICU_EMIOS_2_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined ICU_EMIOS_2_CH_15_ISR_USED) && (defined GPT_EMIOS_2_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if ( (defined GPT_EMIOS_2_CH_14_ISR_USED) || (defined GPT_EMIOS_2_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_14_ISR_USED) || (defined PWM_EMIOS_2_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_14_ISR_USED) || (defined ICU_EMIOS_2_CH_15_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 14 and 15 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 14 and 15
*
* @note     This will be defined only if eMIOS channels 14 or 15 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_14_CH_15_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_14_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_14_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_14_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_14 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 14)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_14 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 14)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_14_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_14);
                #endif

                #if(defined PWM_EMIOS_2_CH_14_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_14);
                #endif

                #if(defined ICU_EMIOS_2_CH_14_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_14);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_15_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_15_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_15_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_15 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 15)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_15 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 15)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_15_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_15);
                #endif

                #if(defined PWM_EMIOS_2_CH_15_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_15);
                #endif

                #if(defined ICU_EMIOS_2_CH_15_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_15);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:16,17 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_16
*/
#if  ((defined GPT_EMIOS_2_CH_16_ISR_USED) && (defined PWM_EMIOS_2_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined PWM_EMIOS_2_CH_16_ISR_USED) && (defined ICU_EMIOS_2_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined ICU_EMIOS_2_CH_16_ISR_USED) && (defined GPT_EMIOS_2_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_16"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_17
*/
#if  ((defined GPT_EMIOS_2_CH_17_ISR_USED) && (defined PWM_EMIOS_2_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined PWM_EMIOS_2_CH_17_ISR_USED) && (defined ICU_EMIOS_2_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined ICU_EMIOS_2_CH_17_ISR_USED) && (defined GPT_EMIOS_2_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if ( (defined GPT_EMIOS_2_CH_16_ISR_USED) || (defined GPT_EMIOS_2_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_16_ISR_USED) || (defined PWM_EMIOS_2_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_16_ISR_USED) || (defined ICU_EMIOS_2_CH_17_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 16 and 17 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 16 and 17

* @note     This will be defined only if eMIOS channels 16 or 17 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_16_CH_17_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_16_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_16_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_16_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_16 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 16)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_16 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 16)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_16_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_16);
                #endif

                #if(defined PWM_EMIOS_2_CH_16_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_16);
                #endif

                #if(defined ICU_EMIOS_2_CH_16_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_16);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_17_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_17_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_17_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_17 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 17)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
       ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_17 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 17)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_17_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_17);
                #endif

                #if(defined PWM_EMIOS_2_CH_17_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_17);
                #endif

                #if(defined ICU_EMIOS_2_CH_17_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_17);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:18,19 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_18
*/
#if  ((defined GPT_EMIOS_2_CH_18_ISR_USED) && (defined PWM_EMIOS_2_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined PWM_EMIOS_2_CH_18_ISR_USED) && (defined ICU_EMIOS_2_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined ICU_EMIOS_2_CH_18_ISR_USED) && (defined GPT_EMIOS_2_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_18"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_19
*/
#if  ((defined GPT_EMIOS_2_CH_19_ISR_USED) && (defined PWM_EMIOS_2_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined PWM_EMIOS_2_CH_19_ISR_USED) && (defined ICU_EMIOS_2_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined ICU_EMIOS_2_CH_19_ISR_USED) && (defined GPT_EMIOS_2_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if ( (defined GPT_EMIOS_2_CH_18_ISR_USED) || (defined GPT_EMIOS_2_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_18_ISR_USED) || (defined PWM_EMIOS_2_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_18_ISR_USED) || (defined ICU_EMIOS_2_CH_19_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 18 and 19 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 18 and 19
*
* @note   This will be defined only if eMIOS channels 18 or 19 are configured in GPT, ICU or PWM
*            mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_18_CH_19_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_18_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_18_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_18_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_18 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 18)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_18 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 18)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_18_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_18);
                #endif

                #if(defined PWM_EMIOS_2_CH_18_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_18);
                #endif

                #if(defined ICU_EMIOS_2_CH_18_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_18);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_19_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_19_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_19_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_19 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 19)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_19 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 19)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_19_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_19);
                #endif

                #if(defined PWM_EMIOS_2_CH_19_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_19);
                #endif

                #if(defined ICU_EMIOS_2_CH_19_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_19);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:20,21 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_20
*/
#if  ((defined GPT_EMIOS_2_CH_20_ISR_USED) && (defined PWM_EMIOS_2_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined PWM_EMIOS_2_CH_20_ISR_USED) && (defined ICU_EMIOS_2_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined ICU_EMIOS_2_CH_20_ISR_USED) && (defined GPT_EMIOS_2_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_20"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_21
*/
#if  ((defined GPT_EMIOS_2_CH_21_ISR_USED) && (defined PWM_EMIOS_2_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined PWM_EMIOS_2_CH_21_ISR_USED) && (defined ICU_EMIOS_2_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined ICU_EMIOS_2_CH_21_ISR_USED) && (defined GPT_EMIOS_2_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if ( (defined GPT_EMIOS_2_CH_20_ISR_USED) || (defined GPT_EMIOS_2_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_20_ISR_USED) || (defined PWM_EMIOS_2_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_20_ISR_USED) || (defined ICU_EMIOS_2_CH_21_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 20 and 21 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 20 and 21
*
* @note   This will be defined only if eMIOS channels 20 or 21 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_20_CH_21_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_20_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_20_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_20_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_20 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 20)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_20 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 20)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_20_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_20);
                #endif

                #if(defined PWM_EMIOS_2_CH_20_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_20);
                #endif

                #if(defined ICU_EMIOS_2_CH_20_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_20);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_21_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_21_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_21_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_21 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 21)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_21 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 21)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_21_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_21);
                #endif

                #if(defined PWM_EMIOS_2_CH_21_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_21);
                #endif

                #if(defined ICU_EMIOS_2_CH_21_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_21);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:22,23 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_22
*/
#if  ((defined GPT_EMIOS_2_CH_22_ISR_USED) && (defined PWM_EMIOS_2_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined PWM_EMIOS_2_CH_22_ISR_USED) && (defined ICU_EMIOS_2_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined ICU_EMIOS_2_CH_22_ISR_USED) && (defined GPT_EMIOS_2_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_22"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_23
*/
#if  ((defined GPT_EMIOS_2_CH_23_ISR_USED) && (defined PWM_EMIOS_2_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined PWM_EMIOS_2_CH_23_ISR_USED) && (defined ICU_EMIOS_2_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined ICU_EMIOS_2_CH_23_ISR_USED) && (defined GPT_EMIOS_2_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if ( (defined GPT_EMIOS_2_CH_22_ISR_USED) || (defined GPT_EMIOS_2_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_22_ISR_USED) || (defined PWM_EMIOS_2_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_22_ISR_USED) || (defined ICU_EMIOS_2_CH_23_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 22 and 23 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 22 and 23
*
* @note   This will be defined only if eMIOS channels 22 or 23 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_22_CH_23_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_22_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_22_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_22_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_22 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 22)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_22 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 22)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_22_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_22);
                #endif

                #if(defined PWM_EMIOS_2_CH_22_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_22);
                #endif

                #if(defined ICU_EMIOS_2_CH_22_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_22);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_23_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_23_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_23_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_23 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 23)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_23 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 23)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_23_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_23);
                #endif

                #if(defined PWM_EMIOS_2_CH_23_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_23);
                #endif

                #if(defined ICU_EMIOS_2_CH_23_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_23);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:24,25 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_24
*/
#if  ((defined GPT_EMIOS_2_CH_24_ISR_USED) && (defined PWM_EMIOS_2_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined PWM_EMIOS_2_CH_24_ISR_USED) && (defined ICU_EMIOS_2_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined ICU_EMIOS_2_CH_24_ISR_USED) && (defined GPT_EMIOS_2_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_24"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_25
*/
#if  ((defined GPT_EMIOS_2_CH_25_ISR_USED) && (defined PWM_EMIOS_2_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined PWM_EMIOS_2_CH_25_ISR_USED) && (defined ICU_EMIOS_2_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined ICU_EMIOS_2_CH_25_ISR_USED) && (defined GPT_EMIOS_2_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if ( (defined GPT_EMIOS_2_CH_24_ISR_USED) || (defined GPT_EMIOS_2_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_24_ISR_USED) || (defined PWM_EMIOS_2_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_24_ISR_USED) || (defined ICU_EMIOS_2_CH_25_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 24 and 25 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 24 and 25
*
* @note   This will be defined only if eMIOS channels 24 or 25 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_24_CH_25_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_24_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_24_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_24_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_24 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 24)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_24 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 24)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_24_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_24);
                #endif

                #if(defined PWM_EMIOS_2_CH_24_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_24);
                #endif

                #if(defined ICU_EMIOS_2_CH_24_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_24);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_25_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_25_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_25_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_25 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 25)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_25 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 25)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_25_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_25);
                #endif

                #if(defined PWM_EMIOS_2_CH_25_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_25);
                #endif

                #if(defined ICU_EMIOS_2_CH_25_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_25);
                #endif
        }
    }
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:26,27 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_26
*/
#if  ((defined GPT_EMIOS_2_CH_26_ISR_USED) && (defined PWM_EMIOS_2_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined PWM_EMIOS_2_CH_26_ISR_USED) && (defined ICU_EMIOS_2_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined ICU_EMIOS_2_CH_26_ISR_USED) && (defined GPT_EMIOS_2_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_26"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_27
*/
#if  ((defined GPT_EMIOS_2_CH_27_ISR_USED) && (defined PWM_EMIOS_2_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined PWM_EMIOS_2_CH_27_ISR_USED) && (defined ICU_EMIOS_2_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined ICU_EMIOS_2_CH_27_ISR_USED) && (defined GPT_EMIOS_2_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if ( (defined GPT_EMIOS_2_CH_26_ISR_USED) || (defined GPT_EMIOS_2_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_26_ISR_USED) || (defined PWM_EMIOS_2_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_26_ISR_USED) || (defined ICU_EMIOS_2_CH_27_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 26 and 27 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 26 and 27
*
* @note   This will be defined only if eMIOS channels 26 or 27 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_26_CH_27_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_26_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_26_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_26_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_26 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 26)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_26 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 26)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_26_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_26);
                #endif

                #if(defined PWM_EMIOS_2_CH_26_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_26);
                #endif

                #if(defined ICU_EMIOS_2_CH_26_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_26);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_27_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_27_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_27_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_27 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 27)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_27 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 27)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_27_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_27);
                #endif

                #if(defined PWM_EMIOS_2_CH_27_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_27);
                #endif

                #if(defined ICU_EMIOS_2_CH_27_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_27);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:28,29 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_28
*/
#if  ((defined GPT_EMIOS_2_CH_28_ISR_USED) && (defined PWM_EMIOS_2_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined PWM_EMIOS_2_CH_28_ISR_USED) && (defined ICU_EMIOS_2_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined ICU_EMIOS_2_CH_28_ISR_USED) && (defined GPT_EMIOS_2_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_28"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_29
*/
#if  ((defined GPT_EMIOS_2_CH_29_ISR_USED) && (defined PWM_EMIOS_2_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined PWM_EMIOS_2_CH_29_ISR_USED) && (defined ICU_EMIOS_2_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined ICU_EMIOS_2_CH_29_ISR_USED) && (defined GPT_EMIOS_2_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if ( (defined GPT_EMIOS_2_CH_28_ISR_USED) || (defined GPT_EMIOS_2_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_28_ISR_USED) || (defined PWM_EMIOS_2_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_28_ISR_USED) || (defined ICU_EMIOS_2_CH_29_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 28 and 29 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 28 and 29
*
* @note   This will be defined only if eMIOS channels 28 or 29 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_28_CH_29_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_28_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_28_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_28_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_28 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 28)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_28 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 28)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_28_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_28);
                #endif

                #if(defined PWM_EMIOS_2_CH_28_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_28);
                #endif

                #if(defined ICU_EMIOS_2_CH_28_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_28);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_29_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_29_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_29_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_29 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 29)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_29 */        
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 29)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_29_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_29);
                #endif

                #if(defined PWM_EMIOS_2_CH_29_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_29);
                #endif

                #if(defined ICU_EMIOS_2_CH_29_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_29);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:30,31 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_30
*/
#if  ((defined GPT_EMIOS_2_CH_30_ISR_USED) && (defined PWM_EMIOS_2_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined PWM_EMIOS_2_CH_30_ISR_USED) && (defined ICU_EMIOS_2_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined ICU_EMIOS_2_CH_30_ISR_USED) && (defined GPT_EMIOS_2_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_30"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_31
*/
#if  ((defined GPT_EMIOS_2_CH_31_ISR_USED) && (defined PWM_EMIOS_2_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined PWM_EMIOS_2_CH_31_ISR_USED) && (defined ICU_EMIOS_2_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined ICU_EMIOS_2_CH_31_ISR_USED) && (defined GPT_EMIOS_2_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if ( (defined GPT_EMIOS_2_CH_30_ISR_USED) || (defined GPT_EMIOS_2_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_30_ISR_USED) || (defined PWM_EMIOS_2_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_30_ISR_USED) || (defined ICU_EMIOS_2_CH_31_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channels : 30 and 31 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channels 30 and 31
*
* @note   This will be defined only if eMIOS channels 30 or 31 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_30_CH_31_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_30_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_30_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_30_ISR_USED) )


    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_30 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 30)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_30 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */        
        if ( ( REG_READ32(EMIOS_CSR(2, 30)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_30_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_30);
                #endif

                #if(defined PWM_EMIOS_2_CH_30_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_30);
                #endif

                #if(defined ICU_EMIOS_2_CH_30_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_30);
                #endif
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_31_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_31_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_31_ISR_USED) )

    /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_31 */
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    if ( (REG_READ32(EMIOS_CCR(2, 31)) & (CCR_DMA_MASK | CCR_FEN_MASK)) ==
         ((CCR_DMA_ASSIGN_INT << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE << CCR_FEN_SHIFT ))) {

        /* Check if match event occured on EMIOS_31 */
        /*
        * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
        */
        if ( ( REG_READ32(EMIOS_CSR(2, 31)) & CSR_FLAG_MASK) != 0U ) {

                #if(defined GPT_EMIOS_2_CH_31_ISR_USED)
                        Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_31);
                #endif

                #if(defined PWM_EMIOS_2_CH_31_ISR_USED)
                        Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_31);
                #endif

                #if(defined ICU_EMIOS_2_CH_31_ISR_USED)
                        Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_31);
                #endif
        }
    }
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif

/*********************************** EMIOS 2 common interrupts END ********************************/

#else  /* EMIOS_COMMON_ISR_HANDLER == STD_OFF */




/*================================================================================================*/
/*                     CHANNEL INDEPENDENT EMIOS INTERRUPT SERVICE ROUTINES DEFINITION            */
/*================================================================================================*/



/*********************************** EMIOS 0 independent interrupts START *************************/


/*
* @brief EMIOS module:0 channel:0 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_0
*/
#if  ((defined GPT_EMIOS_0_CH_0_ISR_USED) && (defined PWM_EMIOS_0_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined PWM_EMIOS_0_CH_0_ISR_USED) && (defined ICU_EMIOS_0_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined ICU_EMIOS_0_CH_0_ISR_USED) && (defined GPT_EMIOS_0_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_0"
#endif


#if ( (defined GPT_EMIOS_0_CH_0_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_0_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_0_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 0 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 0
*
* @note   This will be defined only if eMIOS channel 0 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_0_ISR)
{

    #if(defined GPT_EMIOS_0_CH_0_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_0);
    #endif

    #if(defined PWM_EMIOS_0_CH_0_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_0);
    #endif

    #if(defined ICU_EMIOS_0_CH_0_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_0);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:1 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_1
*/
#if  ((defined GPT_EMIOS_0_CH_1_ISR_USED) && (defined PWM_EMIOS_0_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined PWM_EMIOS_0_CH_1_ISR_USED) && (defined ICU_EMIOS_0_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined ICU_EMIOS_0_CH_1_ISR_USED) && (defined GPT_EMIOS_0_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_1"
#endif


#if ( (defined GPT_EMIOS_0_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_1_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 1 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 1
*
* @note   This will be defined only if eMIOS channel 1 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_1_ISR)
{

    #if(defined GPT_EMIOS_0_CH_1_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_1);
    #endif

    #if(defined PWM_EMIOS_0_CH_1_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_1);
    #endif

    #if(defined ICU_EMIOS_0_CH_1_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_1);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:2 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_2
*/
#if  ((defined GPT_EMIOS_0_CH_2_ISR_USED) && (defined PWM_EMIOS_0_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined PWM_EMIOS_0_CH_2_ISR_USED) && (defined ICU_EMIOS_0_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined ICU_EMIOS_0_CH_2_ISR_USED) && (defined GPT_EMIOS_0_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_2"
#endif


#if ( (defined GPT_EMIOS_0_CH_2_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_2_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_2_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 2 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 2
*
* @note   This will be defined only if eMIOS channel 2 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_2_ISR)
{

    #if(defined GPT_EMIOS_0_CH_2_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_2);
    #endif

    #if(defined PWM_EMIOS_0_CH_2_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_2);
    #endif

    #if(defined ICU_EMIOS_0_CH_2_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_2);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:3 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_3
*/
#if  ((defined GPT_EMIOS_0_CH_3_ISR_USED) && (defined PWM_EMIOS_0_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined PWM_EMIOS_0_CH_3_ISR_USED) && (defined ICU_EMIOS_0_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined ICU_EMIOS_0_CH_3_ISR_USED) && (defined GPT_EMIOS_0_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_3"
#endif


#if ( (defined GPT_EMIOS_0_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_3_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 3 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 3
*
* @note   This will be defined only if eMIOS channel 3 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_3_ISR)
{

    #if(defined GPT_EMIOS_0_CH_3_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_3);
    #endif

    #if(defined PWM_EMIOS_0_CH_3_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_3);
    #endif

    #if(defined ICU_EMIOS_0_CH_3_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_3);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:4 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_4
*/
#if  ((defined GPT_EMIOS_0_CH_4_ISR_USED) && (defined PWM_EMIOS_0_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined PWM_EMIOS_0_CH_4_ISR_USED) && (defined ICU_EMIOS_0_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined ICU_EMIOS_0_CH_4_ISR_USED) && (defined GPT_EMIOS_0_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_4"
#endif


#if ( (defined GPT_EMIOS_0_CH_4_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_4_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_4_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 4 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 4
*
* @note   This will be defined only if eMIOS channel 4 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_4_ISR)
{

    #if(defined GPT_EMIOS_0_CH_4_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_4);
    #endif

    #if(defined PWM_EMIOS_0_CH_4_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_4);
    #endif

    #if(defined ICU_EMIOS_0_CH_4_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_4);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:5 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_5
*/
#if  ((defined GPT_EMIOS_0_CH_5_ISR_USED) && (defined PWM_EMIOS_0_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined PWM_EMIOS_0_CH_5_ISR_USED) && (defined ICU_EMIOS_0_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined ICU_EMIOS_0_CH_5_ISR_USED) && (defined GPT_EMIOS_0_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_5"
#endif


#if ( (defined GPT_EMIOS_0_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_5_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 5 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 5
*
* @note   This will be defined only if eMIOS channel 5 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_5_ISR)
{

    #if(defined GPT_EMIOS_0_CH_5_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_5);
    #endif

    #if(defined PWM_EMIOS_0_CH_5_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_5);
    #endif

    #if(defined ICU_EMIOS_0_CH_5_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_5);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:6 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_6
*/
#if  ((defined GPT_EMIOS_0_CH_6_ISR_USED) && (defined PWM_EMIOS_0_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined PWM_EMIOS_0_CH_6_ISR_USED) && (defined ICU_EMIOS_0_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined ICU_EMIOS_0_CH_6_ISR_USED) && (defined GPT_EMIOS_0_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_6"
#endif


#if ( (defined GPT_EMIOS_0_CH_6_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_6_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_6_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 6 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 6
*
* @note   This will be defined only if eMIOS channel 6 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_6_ISR)
{

    #if(defined GPT_EMIOS_0_CH_6_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_6);
    #endif

    #if(defined PWM_EMIOS_0_CH_6_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_6);
    #endif

    #if(defined ICU_EMIOS_0_CH_6_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_6);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:7 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_7
*/
#if  ((defined GPT_EMIOS_0_CH_7_ISR_USED) && (defined PWM_EMIOS_0_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined PWM_EMIOS_0_CH_7_ISR_USED) && (defined ICU_EMIOS_0_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined ICU_EMIOS_0_CH_7_ISR_USED) && (defined GPT_EMIOS_0_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_7"
#endif


#if ( (defined GPT_EMIOS_0_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_7_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 7 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 7
*
* @note   This will be defined only if eMIOS channel 7 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_7_ISR)
{

    #if(defined GPT_EMIOS_0_CH_7_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_7);
    #endif

    #if(defined PWM_EMIOS_0_CH_7_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_7);
    #endif

    #if(defined ICU_EMIOS_0_CH_7_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_7);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:8 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_8
*/

#if  ((defined GPT_EMIOS_0_CH_8_ISR_USED) && (defined PWM_EMIOS_0_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined PWM_EMIOS_0_CH_8_ISR_USED) && (defined ICU_EMIOS_0_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined ICU_EMIOS_0_CH_8_ISR_USED) && (defined GPT_EMIOS_0_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_8"
#endif


#if ( (defined GPT_EMIOS_0_CH_8_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_8_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_8_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 8 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 8
*
* @note   This will be defined only if eMIOS channel 8 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_8_ISR)
{

    #if(defined GPT_EMIOS_0_CH_8_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_8);
    #endif

    #if(defined PWM_EMIOS_0_CH_8_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_8);
    #endif

    #if(defined ICU_EMIOS_0_CH_8_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_8);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:9 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_9
*/
#if  ((defined GPT_EMIOS_0_CH_9_ISR_USED) && (defined PWM_EMIOS_0_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined PWM_EMIOS_0_CH_9_ISR_USED) && (defined ICU_EMIOS_0_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined ICU_EMIOS_0_CH_9_ISR_USED) && (defined GPT_EMIOS_0_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_9"
#endif


#if ( (defined GPT_EMIOS_0_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_9_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 9 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 9
*
* @note   This will be defined only if eMIOS channel 9 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_9_ISR)
{

    #if(defined GPT_EMIOS_0_CH_9_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_9);
    #endif

    #if(defined PWM_EMIOS_0_CH_9_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_9);
    #endif

    #if(defined ICU_EMIOS_0_CH_9_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_9);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:10 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_10
*/
#if  ((defined GPT_EMIOS_0_CH_10_ISR_USED) && (defined PWM_EMIOS_0_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined PWM_EMIOS_0_CH_10_ISR_USED) && (defined ICU_EMIOS_0_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined ICU_EMIOS_0_CH_10_ISR_USED) && (defined GPT_EMIOS_0_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_10"
#endif


#if ( (defined GPT_EMIOS_0_CH_10_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_10_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_10_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 10 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 10
*
* @note   This will be defined only if eMIOS channel 10 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_10_ISR)
{

    #if(defined GPT_EMIOS_0_CH_10_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_10);
    #endif

    #if(defined PWM_EMIOS_0_CH_10_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_10);
    #endif

    #if(defined ICU_EMIOS_0_CH_10_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_10);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:11 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_11
*/
#if  ((defined GPT_EMIOS_0_CH_11_ISR_USED) && (defined PWM_EMIOS_0_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined PWM_EMIOS_0_CH_11_ISR_USED) && (defined ICU_EMIOS_0_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined ICU_EMIOS_0_CH_11_ISR_USED) && (defined GPT_EMIOS_0_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_11"
#endif


#if ( (defined GPT_EMIOS_0_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_11_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 11 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 11
*
* @note   This will be defined only if eMIOS channel 11 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_11_ISR)
{

    #if(defined GPT_EMIOS_0_CH_11_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_11);
    #endif

    #if(defined PWM_EMIOS_0_CH_11_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_11);
    #endif

    #if(defined ICU_EMIOS_0_CH_11_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_11);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:12 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_12
*/
#if  ((defined GPT_EMIOS_0_CH_12_ISR_USED) && (defined PWM_EMIOS_0_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined PWM_EMIOS_0_CH_12_ISR_USED) && (defined ICU_EMIOS_0_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined ICU_EMIOS_0_CH_12_ISR_USED) && (defined GPT_EMIOS_0_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_12"
#endif


#if ( (defined GPT_EMIOS_0_CH_12_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_12_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_12_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 12 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 12
*
* @note   This will be defined only if eMIOS channel 12 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_12_ISR)
{

    #if(defined GPT_EMIOS_0_CH_12_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_12);
    #endif

    #if(defined PWM_EMIOS_0_CH_12_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_12);
    #endif

    #if(defined ICU_EMIOS_0_CH_12_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_12);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:13 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_13
*/
#if  ((defined GPT_EMIOS_0_CH_13_ISR_USED) && (defined PWM_EMIOS_0_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined PWM_EMIOS_0_CH_13_ISR_USED) && (defined ICU_EMIOS_0_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined ICU_EMIOS_0_CH_13_ISR_USED) && (defined GPT_EMIOS_0_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_13"
#endif


#if ( (defined GPT_EMIOS_0_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_13_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 13 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 13
*
* @note   This will be defined only if eMIOS channel 13 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_13_ISR)
{

    #if(defined GPT_EMIOS_0_CH_13_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_13);
    #endif

    #if(defined PWM_EMIOS_0_CH_13_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_13);
    #endif

    #if(defined ICU_EMIOS_0_CH_13_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_13);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:14 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_14
*/
#if  ((defined GPT_EMIOS_0_CH_14_ISR_USED) && (defined PWM_EMIOS_0_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined PWM_EMIOS_0_CH_14_ISR_USED) && (defined ICU_EMIOS_0_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined ICU_EMIOS_0_CH_14_ISR_USED) && (defined GPT_EMIOS_0_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_14"
#endif


#if ( (defined GPT_EMIOS_0_CH_14_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_14_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_14_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 14 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 14
*
* @note   This will be defined only if eMIOS channel 14 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_14_ISR)
{

    #if(defined GPT_EMIOS_0_CH_14_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_14);
    #endif

    #if(defined PWM_EMIOS_0_CH_14_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_14);
    #endif

    #if(defined ICU_EMIOS_0_CH_14_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_14);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:15 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_15
*/
#if  ((defined GPT_EMIOS_0_CH_15_ISR_USED) && (defined PWM_EMIOS_0_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined PWM_EMIOS_0_CH_15_ISR_USED) && (defined ICU_EMIOS_0_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined ICU_EMIOS_0_CH_15_ISR_USED) && (defined GPT_EMIOS_0_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_15"
#endif


#if ( (defined GPT_EMIOS_0_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_15_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 15 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 15
*
* @note   This will be defined only if eMIOS channel 15 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_15_ISR)
{

    #if(defined GPT_EMIOS_0_CH_15_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_15);
    #endif

    #if(defined PWM_EMIOS_0_CH_15_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_15);
    #endif

    #if(defined ICU_EMIOS_0_CH_15_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_15);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:16 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_16
*/
#if  ((defined GPT_EMIOS_0_CH_16_ISR_USED) && (defined PWM_EMIOS_0_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined PWM_EMIOS_0_CH_16_ISR_USED) && (defined ICU_EMIOS_0_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined ICU_EMIOS_0_CH_16_ISR_USED) && (defined GPT_EMIOS_0_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_16"
#endif


#if ( (defined GPT_EMIOS_0_CH_16_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_16_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_16_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 16 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 16
*
* @note   This will be defined only if eMIOS channel 16 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_16_ISR)
{

    #if(defined GPT_EMIOS_0_CH_16_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_16);
    #endif

    #if(defined PWM_EMIOS_0_CH_16_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_16);
    #endif

    #if(defined ICU_EMIOS_0_CH_16_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_16);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:17 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_17
*/
#if  ((defined GPT_EMIOS_0_CH_17_ISR_USED) && (defined PWM_EMIOS_0_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined PWM_EMIOS_0_CH_17_ISR_USED) && (defined ICU_EMIOS_0_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined ICU_EMIOS_0_CH_17_ISR_USED) && (defined GPT_EMIOS_0_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_17"
#endif


#if ( (defined GPT_EMIOS_0_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_17_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 17 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 17
*
* @note   This will be defined only if eMIOS channel 17 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_17_ISR)
{

    #if(defined GPT_EMIOS_0_CH_17_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_17);
    #endif

    #if(defined PWM_EMIOS_0_CH_17_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_17);
    #endif

    #if(defined ICU_EMIOS_0_CH_17_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_17);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:18 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_18
*/
#if  ((defined GPT_EMIOS_0_CH_18_ISR_USED) && (defined PWM_EMIOS_0_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined PWM_EMIOS_0_CH_18_ISR_USED) && (defined ICU_EMIOS_0_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined ICU_EMIOS_0_CH_18_ISR_USED) && (defined GPT_EMIOS_0_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_18"
#endif


#if ( (defined GPT_EMIOS_0_CH_18_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_18_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_18_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 18 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 18
*
* @note   This will be defined only if eMIOS channel 18 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_18_ISR)
{

    #if(defined GPT_EMIOS_0_CH_18_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_18);
    #endif

    #if(defined PWM_EMIOS_0_CH_18_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_18);
    #endif

    #if(defined ICU_EMIOS_0_CH_18_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_18);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:19 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_19
*/
#if  ((defined GPT_EMIOS_0_CH_19_ISR_USED) && (defined PWM_EMIOS_0_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined PWM_EMIOS_0_CH_19_ISR_USED) && (defined ICU_EMIOS_0_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined ICU_EMIOS_0_CH_19_ISR_USED) && (defined GPT_EMIOS_0_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_19"
#endif


#if ( (defined GPT_EMIOS_0_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_19_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 19 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 19
*
* @note   This will be defined only if eMIOS channel 19 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_19_ISR)
{

    #if(defined GPT_EMIOS_0_CH_19_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_19);
    #endif

    #if(defined PWM_EMIOS_0_CH_19_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_19);
    #endif

    #if(defined ICU_EMIOS_0_CH_19_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_19);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */    
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:20 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_20
*/
#if  ((defined GPT_EMIOS_0_CH_20_ISR_USED) && (defined PWM_EMIOS_0_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined PWM_EMIOS_0_CH_20_ISR_USED) && (defined ICU_EMIOS_0_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined ICU_EMIOS_0_CH_20_ISR_USED) && (defined GPT_EMIOS_0_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_20"
#endif


#if ( (defined GPT_EMIOS_0_CH_20_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_20_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_20_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 20 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 20
*
* @note   This will be defined only if eMIOS channel 20 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_20_ISR)
{

    #if(defined GPT_EMIOS_0_CH_20_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_20);
    #endif

    #if(defined PWM_EMIOS_0_CH_20_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_20);
    #endif

    #if(defined ICU_EMIOS_0_CH_20_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_20);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:21 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_21
*/
#if  ((defined GPT_EMIOS_0_CH_21_ISR_USED) && (defined PWM_EMIOS_0_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined PWM_EMIOS_0_CH_21_ISR_USED) && (defined ICU_EMIOS_0_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined ICU_EMIOS_0_CH_21_ISR_USED) && (defined GPT_EMIOS_0_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_21"
#endif


#if ( (defined GPT_EMIOS_0_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_21_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 21 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 21
*
* @note   This will be defined only if eMIOS channel 21 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_21_ISR)
{

    #if(defined GPT_EMIOS_0_CH_21_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_21);
    #endif

    #if(defined PWM_EMIOS_0_CH_21_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_21);
    #endif

    #if(defined ICU_EMIOS_0_CH_21_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_21);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:22 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_22
*/
#if  ((defined GPT_EMIOS_0_CH_22_ISR_USED) && (defined PWM_EMIOS_0_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined PWM_EMIOS_0_CH_22_ISR_USED) && (defined ICU_EMIOS_0_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined ICU_EMIOS_0_CH_22_ISR_USED) && (defined GPT_EMIOS_0_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_22"
#endif


#if ( (defined GPT_EMIOS_0_CH_22_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_22_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_22_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 22 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 22
*
* @note   This will be defined only if eMIOS channel 22 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_22_ISR)
{

    #if(defined GPT_EMIOS_0_CH_22_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_22);
    #endif

    #if(defined PWM_EMIOS_0_CH_22_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_22);
    #endif

    #if(defined ICU_EMIOS_0_CH_22_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_22);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:23 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_23
*/
#if  ((defined GPT_EMIOS_0_CH_23_ISR_USED) && (defined PWM_EMIOS_0_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined PWM_EMIOS_0_CH_23_ISR_USED) && (defined ICU_EMIOS_0_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined ICU_EMIOS_0_CH_23_ISR_USED) && (defined GPT_EMIOS_0_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_23"
#endif


#if ( (defined GPT_EMIOS_0_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_23_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 23 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 23
*
* @note   This will be defined only if eMIOS channel 23 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_23_ISR)
{

    #if(defined GPT_EMIOS_0_CH_23_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_23);
    #endif

    #if(defined PWM_EMIOS_0_CH_23_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_23);
    #endif

    #if(defined ICU_EMIOS_0_CH_23_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_23);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:24 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_24
*/
#if  ((defined GPT_EMIOS_0_CH_24_ISR_USED) && (defined PWM_EMIOS_0_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined PWM_EMIOS_0_CH_24_ISR_USED) && (defined ICU_EMIOS_0_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined ICU_EMIOS_0_CH_24_ISR_USED) && (defined GPT_EMIOS_0_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_24"
#endif


#if ( (defined GPT_EMIOS_0_CH_24_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_24_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_24_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 24 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 24
*
* @note   This will be defined only if eMIOS channel 24 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_24_ISR)
{

    #if(defined GPT_EMIOS_0_CH_24_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_24);
    #endif

    #if(defined PWM_EMIOS_0_CH_24_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_24);
    #endif

    #if(defined ICU_EMIOS_0_CH_24_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_24);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:25 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_25
*/
#if  ((defined GPT_EMIOS_0_CH_25_ISR_USED) && (defined PWM_EMIOS_0_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined PWM_EMIOS_0_CH_25_ISR_USED) && (defined ICU_EMIOS_0_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined ICU_EMIOS_0_CH_25_ISR_USED) && (defined GPT_EMIOS_0_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_25"
#endif


#if ( (defined GPT_EMIOS_0_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_25_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 25 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 25
*
* @note   This will be defined only if eMIOS channel 25 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_25_ISR)
{

    #if(defined GPT_EMIOS_0_CH_25_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_25);
    #endif

    #if(defined PWM_EMIOS_0_CH_25_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_25);
    #endif

    #if(defined ICU_EMIOS_0_CH_25_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_25);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:26 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_26
*/
#if  ((defined GPT_EMIOS_0_CH_26_ISR_USED) && (defined PWM_EMIOS_0_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined PWM_EMIOS_0_CH_26_ISR_USED) && (defined ICU_EMIOS_0_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined ICU_EMIOS_0_CH_26_ISR_USED) && (defined GPT_EMIOS_0_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_26"
#endif


#if ( (defined GPT_EMIOS_0_CH_26_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_26_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_26_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 26 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 26
*
* @note   This will be defined only if eMIOS channel 26 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_0_CH_26_ISR)
{

    #if(defined GPT_EMIOS_0_CH_26_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_26);
    #endif

    #if(defined PWM_EMIOS_0_CH_26_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_26);
    #endif

    #if(defined ICU_EMIOS_0_CH_26_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_26);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:27 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_27
*/
#if  ((defined GPT_EMIOS_0_CH_27_ISR_USED) && (defined PWM_EMIOS_0_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined PWM_EMIOS_0_CH_27_ISR_USED) && (defined ICU_EMIOS_0_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined ICU_EMIOS_0_CH_27_ISR_USED) && (defined GPT_EMIOS_0_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_27"
#endif


#if ( (defined GPT_EMIOS_0_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_27_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 27 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 27
*
* @note   This will be defined only if eMIOS channel 27 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_0_CH_27_ISR)
{

    #if(defined GPT_EMIOS_0_CH_27_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_27);
    #endif

    #if(defined PWM_EMIOS_0_CH_27_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_27);
    #endif

    #if(defined ICU_EMIOS_0_CH_27_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_27);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:28 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_28
*/
#if  ((defined GPT_EMIOS_0_CH_28_ISR_USED) && (defined PWM_EMIOS_0_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined PWM_EMIOS_0_CH_28_ISR_USED) && (defined ICU_EMIOS_0_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined ICU_EMIOS_0_CH_28_ISR_USED) && (defined GPT_EMIOS_0_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_28"
#endif


#if ( (defined GPT_EMIOS_0_CH_28_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_28_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_28_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 28 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 28
*
* @note   This will be defined only if eMIOS channel 28 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_0_CH_28_ISR)
{

    #if(defined GPT_EMIOS_0_CH_28_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_28);
    #endif

    #if(defined PWM_EMIOS_0_CH_28_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_28);
    #endif

    #if(defined ICU_EMIOS_0_CH_28_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_28);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:29 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_29
*/
#if  ((defined GPT_EMIOS_0_CH_29_ISR_USED) && (defined PWM_EMIOS_0_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined PWM_EMIOS_0_CH_29_ISR_USED) && (defined ICU_EMIOS_0_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined ICU_EMIOS_0_CH_29_ISR_USED) && (defined GPT_EMIOS_0_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_29"
#endif


#if ( (defined GPT_EMIOS_0_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_29_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 29 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 29
*
* @note   This will be defined only if eMIOS channel 29 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_0_CH_29_ISR)
{

    #if(defined GPT_EMIOS_0_CH_29_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_29);
    #endif

    #if(defined PWM_EMIOS_0_CH_29_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_29);
    #endif

    #if(defined ICU_EMIOS_0_CH_29_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_29);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:30 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_30
*/
#if  ((defined GPT_EMIOS_0_CH_30_ISR_USED) && (defined PWM_EMIOS_0_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined PWM_EMIOS_0_CH_30_ISR_USED) && (defined ICU_EMIOS_0_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined ICU_EMIOS_0_CH_30_ISR_USED) && (defined GPT_EMIOS_0_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_30"
#endif


#if ( (defined GPT_EMIOS_0_CH_30_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_30_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_30_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 30 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 30
*
* @note   This will be defined only if eMIOS channel 30 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_30_ISR)
{

    #if(defined GPT_EMIOS_0_CH_30_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_30);
    #endif

    #if(defined PWM_EMIOS_0_CH_30_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_30);
    #endif

    #if(defined ICU_EMIOS_0_CH_30_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_30);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:31 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_31
*/
#if  ((defined GPT_EMIOS_0_CH_31_ISR_USED) && (defined PWM_EMIOS_0_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined PWM_EMIOS_0_CH_31_ISR_USED) && (defined ICU_EMIOS_0_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined ICU_EMIOS_0_CH_31_ISR_USED) && (defined GPT_EMIOS_0_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_31"
#endif


#if ( (defined GPT_EMIOS_0_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_31_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 31 for eMIOS_0 module
* @details   Process the interrupt of eMIOS channel 31
*
* @note   This will be defined only if eMIOS channel 31 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_0_CH_31_ISR)
{

    #if(defined GPT_EMIOS_0_CH_31_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_31);
    #endif

    #if(defined PWM_EMIOS_0_CH_31_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_31);
    #endif

    #if(defined ICU_EMIOS_0_CH_31_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_0_CH_31);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 0 independent interrupts END ***************************/



/*********************************** EMIOS 1 independent interrupts START *************************/


/*
* @brief EMIOS module:1 channel:0 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_0
*/
#if  ((defined GPT_EMIOS_1_CH_0_ISR_USED) && (defined PWM_EMIOS_1_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined PWM_EMIOS_1_CH_0_ISR_USED) && (defined ICU_EMIOS_1_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined ICU_EMIOS_1_CH_0_ISR_USED) && (defined GPT_EMIOS_1_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_0"
#endif


#if ( (defined GPT_EMIOS_1_CH_0_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_0_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_0_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 0 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 0
*
* @note   This will be defined only if eMIOS channel 0 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_0_ISR)
{

    #if(defined GPT_EMIOS_1_CH_0_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_0);
    #endif

    #if(defined PWM_EMIOS_1_CH_0_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_0);
    #endif

    #if(defined ICU_EMIOS_1_CH_0_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_0);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:1 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_1
*/
#if  ((defined GPT_EMIOS_1_CH_1_ISR_USED) && (defined PWM_EMIOS_1_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined PWM_EMIOS_1_CH_1_ISR_USED) && (defined ICU_EMIOS_1_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined ICU_EMIOS_1_CH_1_ISR_USED) && (defined GPT_EMIOS_1_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_1"
#endif


#if ( (defined GPT_EMIOS_1_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_1_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 1 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 1
*
* @note   This will be defined only if eMIOS channel 1 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_1_ISR)
{

    #if(defined GPT_EMIOS_1_CH_1_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_1);
    #endif

    #if(defined PWM_EMIOS_1_CH_1_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_1);
    #endif

    #if(defined ICU_EMIOS_1_CH_1_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_1);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:2 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_2
*/
#if  ((defined GPT_EMIOS_1_CH_2_ISR_USED) && (defined PWM_EMIOS_1_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined PWM_EMIOS_1_CH_2_ISR_USED) && (defined ICU_EMIOS_1_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined ICU_EMIOS_1_CH_2_ISR_USED) && (defined GPT_EMIOS_1_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_2"
#endif


#if ( (defined GPT_EMIOS_1_CH_2_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_2_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_2_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 2 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 2
*
* @note   This will be defined only if eMIOS channel 2 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_2_ISR)
{

    #if(defined GPT_EMIOS_1_CH_2_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_2);
    #endif

    #if(defined PWM_EMIOS_1_CH_2_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_2);
    #endif

    #if(defined ICU_EMIOS_1_CH_2_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_2);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:3 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_3
*/
#if  ((defined GPT_EMIOS_1_CH_3_ISR_USED) && (defined PWM_EMIOS_1_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined PWM_EMIOS_1_CH_3_ISR_USED) && (defined ICU_EMIOS_1_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined ICU_EMIOS_1_CH_3_ISR_USED) && (defined GPT_EMIOS_1_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_3"
#endif


#if ( (defined GPT_EMIOS_1_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_3_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 3 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 3
*
* @note   This will be defined only if eMIOS channel 3 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_3_ISR)
{

    #if(defined GPT_EMIOS_1_CH_3_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_3);
    #endif

    #if(defined PWM_EMIOS_1_CH_3_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_3);
    #endif

    #if(defined ICU_EMIOS_1_CH_3_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_3);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:4 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_4
*/
#if  ((defined GPT_EMIOS_1_CH_4_ISR_USED) && (defined PWM_EMIOS_1_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined PWM_EMIOS_1_CH_4_ISR_USED) && (defined ICU_EMIOS_1_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined ICU_EMIOS_1_CH_4_ISR_USED) && (defined GPT_EMIOS_1_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_4"
#endif


#if ( (defined GPT_EMIOS_1_CH_4_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_4_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_4_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 4 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 4
*
* @note   This will be defined only if eMIOS channel 4 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_4_ISR)
{

    #if(defined GPT_EMIOS_1_CH_4_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_4);
    #endif

    #if(defined PWM_EMIOS_1_CH_4_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_4);
    #endif

    #if(defined ICU_EMIOS_1_CH_4_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_4);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:5 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_5
*/
#if  ((defined GPT_EMIOS_1_CH_5_ISR_USED) && (defined PWM_EMIOS_1_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined PWM_EMIOS_1_CH_5_ISR_USED) && (defined ICU_EMIOS_1_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined ICU_EMIOS_1_CH_5_ISR_USED) && (defined GPT_EMIOS_1_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_5"
#endif


#if ( (defined GPT_EMIOS_1_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_5_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 5 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 5
*
* @note   This will be defined only if eMIOS channel 5 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_5_ISR)
{

    #if(defined GPT_EMIOS_1_CH_5_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_5);
    #endif

    #if(defined PWM_EMIOS_1_CH_5_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_5);
    #endif

    #if(defined ICU_EMIOS_1_CH_5_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_5);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:6 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_6
*/
#if  ((defined GPT_EMIOS_1_CH_6_ISR_USED) && (defined PWM_EMIOS_1_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined PWM_EMIOS_1_CH_6_ISR_USED) && (defined ICU_EMIOS_1_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined ICU_EMIOS_1_CH_6_ISR_USED) && (defined GPT_EMIOS_1_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_6"
#endif


#if ( (defined GPT_EMIOS_1_CH_6_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_6_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_6_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 6 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 6
*
* @note   This will be defined only if eMIOS channel 6 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_6_ISR)
{

    #if(defined GPT_EMIOS_1_CH_6_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_6);
    #endif

    #if(defined PWM_EMIOS_1_CH_6_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_6);
    #endif

    #if(defined ICU_EMIOS_1_CH_6_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_6);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:7 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_7
*/
#if  ((defined GPT_EMIOS_1_CH_7_ISR_USED) && (defined PWM_EMIOS_1_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined PWM_EMIOS_1_CH_7_ISR_USED) && (defined ICU_EMIOS_1_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined ICU_EMIOS_1_CH_7_ISR_USED) && (defined GPT_EMIOS_1_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_7"
#endif


#if ( (defined GPT_EMIOS_1_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_7_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 7 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 7
*
* @note   This will be defined only if eMIOS channel 7 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_7_ISR)
{

    #if(defined GPT_EMIOS_1_CH_7_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_7);
    #endif

    #if(defined PWM_EMIOS_1_CH_7_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_7);
    #endif

    #if(defined ICU_EMIOS_1_CH_7_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_7);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:8 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_8
*/
#if  ((defined GPT_EMIOS_1_CH_8_ISR_USED) && (defined PWM_EMIOS_1_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined PWM_EMIOS_1_CH_8_ISR_USED) && (defined ICU_EMIOS_1_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined ICU_EMIOS_1_CH_8_ISR_USED) && (defined GPT_EMIOS_1_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_8"
#endif


#if ( (defined GPT_EMIOS_1_CH_8_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_8_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_8_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 8 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 8
*
* @note   This will be defined only if eMIOS channel 8 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_8_ISR)
{

    #if(defined GPT_EMIOS_1_CH_8_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_8);
    #endif

    #if(defined PWM_EMIOS_1_CH_8_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_8);
    #endif

    #if(defined ICU_EMIOS_1_CH_8_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_8);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:9 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_9
*/
#if  ((defined GPT_EMIOS_1_CH_9_ISR_USED) && (defined PWM_EMIOS_1_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined PWM_EMIOS_1_CH_9_ISR_USED) && (defined ICU_EMIOS_1_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined ICU_EMIOS_1_CH_9_ISR_USED) && (defined GPT_EMIOS_1_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_9"
#endif


#if ( (defined GPT_EMIOS_1_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_9_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 9 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 9
*
* @note   This will be defined only if eMIOS channel 9 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_9_ISR)
{

    #if(defined GPT_EMIOS_1_CH_9_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_9);
    #endif

    #if(defined PWM_EMIOS_1_CH_9_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_9);
    #endif

    #if(defined ICU_EMIOS_1_CH_9_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_9);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:10 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_10
*/
#if  ((defined GPT_EMIOS_1_CH_10_ISR_USED) && (defined PWM_EMIOS_1_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined PWM_EMIOS_1_CH_10_ISR_USED) && (defined ICU_EMIOS_1_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined ICU_EMIOS_1_CH_10_ISR_USED) && (defined GPT_EMIOS_1_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_10"
#endif


#if ( (defined GPT_EMIOS_1_CH_10_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_10_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_10_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 10 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 10
*
* @note      This will be defined only if eMIOS channel 10 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_10_ISR)
{

    #if(defined GPT_EMIOS_1_CH_10_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_10);
    #endif

    #if(defined PWM_EMIOS_1_CH_10_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_10);
    #endif

    #if(defined ICU_EMIOS_1_CH_10_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_10);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:11 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_11
*/
#if  ((defined GPT_EMIOS_1_CH_11_ISR_USED) && (defined PWM_EMIOS_1_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined PWM_EMIOS_1_CH_11_ISR_USED) && (defined ICU_EMIOS_1_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined ICU_EMIOS_1_CH_11_ISR_USED) && (defined GPT_EMIOS_1_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_11"
#endif


#if ( (defined GPT_EMIOS_1_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_11_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 11 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 11
*
* @note   This will be defined only if eMIOS channel 11 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_11_ISR)
{

    #if(defined GPT_EMIOS_1_CH_11_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_11);
    #endif

    #if(defined PWM_EMIOS_1_CH_11_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_11);
    #endif

    #if(defined ICU_EMIOS_1_CH_11_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_11);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:12 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_12
*/
#if  ((defined GPT_EMIOS_1_CH_12_ISR_USED) && (defined PWM_EMIOS_1_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined PWM_EMIOS_1_CH_12_ISR_USED) && (defined ICU_EMIOS_1_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined ICU_EMIOS_1_CH_12_ISR_USED) && (defined GPT_EMIOS_1_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_12"
#endif


#if ( (defined GPT_EMIOS_1_CH_12_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_12_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_12_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 12 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 12
*
* @note   This will be defined only if eMIOS channel 12 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_12_ISR)
{

    #if(defined GPT_EMIOS_1_CH_12_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_12);
    #endif

    #if(defined PWM_EMIOS_1_CH_12_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_12);
    #endif

    #if(defined ICU_EMIOS_1_CH_12_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_12);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:13 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_13
*/
#if  ((defined GPT_EMIOS_1_CH_13_ISR_USED) && (defined PWM_EMIOS_1_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined PWM_EMIOS_1_CH_13_ISR_USED) && (defined ICU_EMIOS_1_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined ICU_EMIOS_1_CH_13_ISR_USED) && (defined GPT_EMIOS_1_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_13"
#endif


#if ( (defined GPT_EMIOS_1_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_13_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 13 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 13
*
* @note   This will be defined only if eMIOS channel 13 is configured in GPT, ICU or PWM mode
*/
/*================================================================================================*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_13_ISR)
{

    #if(defined GPT_EMIOS_1_CH_13_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_13);
    #endif

    #if(defined PWM_EMIOS_1_CH_13_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_13);
    #endif

    #if(defined ICU_EMIOS_1_CH_13_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_13);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:14 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_14
*/
#if  ((defined GPT_EMIOS_1_CH_14_ISR_USED) && (defined PWM_EMIOS_1_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined PWM_EMIOS_1_CH_14_ISR_USED) && (defined ICU_EMIOS_1_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined ICU_EMIOS_1_CH_14_ISR_USED) && (defined GPT_EMIOS_1_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_14"
#endif


#if ( (defined GPT_EMIOS_1_CH_14_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_14_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_14_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 14 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 14
*
* @note   This will be defined only if eMIOS channel 14 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_14_ISR)
{

    #if(defined GPT_EMIOS_1_CH_14_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_14);
    #endif

    #if(defined PWM_EMIOS_1_CH_14_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_14);
    #endif

    #if(defined ICU_EMIOS_1_CH_14_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_14);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:15 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_15
*/
#if  ((defined GPT_EMIOS_1_CH_15_ISR_USED) && (defined PWM_EMIOS_1_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined PWM_EMIOS_1_CH_15_ISR_USED) && (defined ICU_EMIOS_1_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined ICU_EMIOS_1_CH_15_ISR_USED) && (defined GPT_EMIOS_1_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_15"
#endif


#if ( (defined GPT_EMIOS_1_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_15_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 15 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 15
*
* @note   This will be defined only if eMIOS channel 15 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_15_ISR)
{

    #if(defined GPT_EMIOS_1_CH_15_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_15);
    #endif

    #if(defined PWM_EMIOS_1_CH_15_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_15);
    #endif

    #if(defined ICU_EMIOS_1_CH_15_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_15);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:16 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_16
*/
#if  ((defined GPT_EMIOS_1_CH_16_ISR_USED) && (defined PWM_EMIOS_1_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined PWM_EMIOS_1_CH_16_ISR_USED) && (defined ICU_EMIOS_1_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined ICU_EMIOS_1_CH_16_ISR_USED) && (defined GPT_EMIOS_1_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_16"
#endif


#if ( (defined GPT_EMIOS_1_CH_16_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_16_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_16_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 16 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 16
*
* @note   This will be defined only if eMIOS channel 16 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_16_ISR)
{

    #if(defined GPT_EMIOS_1_CH_16_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_16);
    #endif

    #if(defined PWM_EMIOS_1_CH_16_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_16);
    #endif

    #if(defined ICU_EMIOS_1_CH_16_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_16);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:17 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_17
*/
#if  ((defined GPT_EMIOS_1_CH_17_ISR_USED) && (defined PWM_EMIOS_1_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined PWM_EMIOS_1_CH_17_ISR_USED) && (defined ICU_EMIOS_1_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined ICU_EMIOS_1_CH_17_ISR_USED) && (defined GPT_EMIOS_1_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_17"
#endif


#if ( (defined GPT_EMIOS_1_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_17_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 17 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 17
*
* @note   This will be defined only if eMIOS channel 17 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_17_ISR)
{

    #if(defined GPT_EMIOS_1_CH_17_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_17);
    #endif

    #if(defined PWM_EMIOS_1_CH_17_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_17);
    #endif

    #if(defined ICU_EMIOS_1_CH_17_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_17);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:18 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_18
*/
#if  ((defined GPT_EMIOS_1_CH_18_ISR_USED) && (defined PWM_EMIOS_1_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined PWM_EMIOS_1_CH_18_ISR_USED) && (defined ICU_EMIOS_1_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined ICU_EMIOS_1_CH_18_ISR_USED) && (defined GPT_EMIOS_1_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_18"
#endif


#if ( (defined GPT_EMIOS_1_CH_18_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_18_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_18_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 18 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 18
*
* @note   This will be defined only if eMIOS channel 18 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_18_ISR)
{

    #if(defined GPT_EMIOS_1_CH_18_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_18);
    #endif

    #if(defined PWM_EMIOS_1_CH_18_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_18);
    #endif

    #if(defined ICU_EMIOS_1_CH_18_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_18);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:19 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_19
*/
#if  ((defined GPT_EMIOS_1_CH_19_ISR_USED) && (defined PWM_EMIOS_1_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined PWM_EMIOS_1_CH_19_ISR_USED) && (defined ICU_EMIOS_1_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined ICU_EMIOS_1_CH_19_ISR_USED) && (defined GPT_EMIOS_1_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_19"
#endif


#if ( (defined GPT_EMIOS_1_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_19_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 19 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 19
*
* @note   This will be defined only if eMIOS channel 19 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_19_ISR)
{

    #if(defined GPT_EMIOS_1_CH_19_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_19);
    #endif

    #if(defined PWM_EMIOS_1_CH_19_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_19);
    #endif

    #if(defined ICU_EMIOS_1_CH_19_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_19);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:20 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_20
*/
#if  ((defined GPT_EMIOS_1_CH_20_ISR_USED) && (defined PWM_EMIOS_1_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined PWM_EMIOS_1_CH_20_ISR_USED) && (defined ICU_EMIOS_1_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined ICU_EMIOS_1_CH_20_ISR_USED) && (defined GPT_EMIOS_1_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_20"
#endif


#if ( (defined GPT_EMIOS_1_CH_20_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_20_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_20_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 20 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 20
*
* @note   This will be defined only if eMIOS channel 20 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_20_ISR)
{

    #if(defined GPT_EMIOS_1_CH_20_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_20);
    #endif

    #if(defined PWM_EMIOS_1_CH_20_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_20);
    #endif

    #if(defined ICU_EMIOS_1_CH_20_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_20);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:21 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_21
*/
#if  ((defined GPT_EMIOS_1_CH_21_ISR_USED) && (defined PWM_EMIOS_1_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined PWM_EMIOS_1_CH_21_ISR_USED) && (defined ICU_EMIOS_1_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined ICU_EMIOS_1_CH_21_ISR_USED) && (defined GPT_EMIOS_1_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_21"
#endif


#if ( (defined GPT_EMIOS_1_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_21_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 21 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 21
*
* @note   This will be defined only if eMIOS channel 21 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_21_ISR)
{

    #if(defined GPT_EMIOS_1_CH_21_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_21);
    #endif

    #if(defined PWM_EMIOS_1_CH_21_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_21);
    #endif

    #if(defined ICU_EMIOS_1_CH_21_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_21);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/**
    @brief EMIOS module:1 channel:22 independent interrupt handler
*/

/**
    @brief resource conflict check for EMIOS_1_CH_22
*/
#if  ((defined GPT_EMIOS_1_CH_22_ISR_USED) && (defined PWM_EMIOS_1_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined PWM_EMIOS_1_CH_22_ISR_USED) && (defined ICU_EMIOS_1_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined ICU_EMIOS_1_CH_22_ISR_USED) && (defined GPT_EMIOS_1_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_22"
#endif


#if ( (defined GPT_EMIOS_1_CH_22_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_22_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_22_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 22 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 22
*
* @note   This will be defined only if eMIOS channel 22 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_22_ISR)
{

    #if(defined GPT_EMIOS_1_CH_22_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_22);
    #endif

    #if(defined PWM_EMIOS_1_CH_22_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_22);
    #endif

    #if(defined ICU_EMIOS_1_CH_22_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_22);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:23 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_23
*/
#if  ((defined GPT_EMIOS_1_CH_23_ISR_USED) && (defined PWM_EMIOS_1_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined PWM_EMIOS_1_CH_23_ISR_USED) && (defined ICU_EMIOS_1_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined ICU_EMIOS_1_CH_23_ISR_USED) && (defined GPT_EMIOS_1_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_23"
#endif


#if ( (defined GPT_EMIOS_1_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_23_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 23 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 23
*
* @note   This will be defined only if eMIOS channel 23 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_23_ISR)
{

    #if(defined GPT_EMIOS_1_CH_23_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_23);
    #endif

    #if(defined PWM_EMIOS_1_CH_23_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_23);
    #endif

    #if(defined ICU_EMIOS_1_CH_23_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_23);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:24 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_24
*/
#if  ((defined GPT_EMIOS_1_CH_24_ISR_USED) && (defined PWM_EMIOS_1_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined PWM_EMIOS_1_CH_24_ISR_USED) && (defined ICU_EMIOS_1_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined ICU_EMIOS_1_CH_24_ISR_USED) && (defined GPT_EMIOS_1_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_24"
#endif


#if ( (defined GPT_EMIOS_1_CH_24_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_24_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_24_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 24 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 24
*
* @note   This will be defined only if eMIOS channel 24 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_24_ISR)
{

    #if(defined GPT_EMIOS_1_CH_24_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_24);
    #endif

    #if(defined PWM_EMIOS_1_CH_24_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_24);
    #endif

    #if(defined ICU_EMIOS_1_CH_24_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_24);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:25 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_25
*/
#if  ((defined GPT_EMIOS_1_CH_25_ISR_USED) && (defined PWM_EMIOS_1_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined PWM_EMIOS_1_CH_25_ISR_USED) && (defined ICU_EMIOS_1_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined ICU_EMIOS_1_CH_25_ISR_USED) && (defined GPT_EMIOS_1_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_25"
#endif


#if ( (defined GPT_EMIOS_1_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_25_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 25 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 25
*
* @note   This will be defined only if eMIOS channel 25 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_25_ISR)
{

    #if(defined GPT_EMIOS_1_CH_25_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_25);
    #endif

    #if(defined PWM_EMIOS_1_CH_25_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_25);
    #endif

    #if(defined ICU_EMIOS_1_CH_25_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_25);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:26 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_26
*/
#if  ((defined GPT_EMIOS_1_CH_26_ISR_USED) && (defined PWM_EMIOS_1_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined PWM_EMIOS_1_CH_26_ISR_USED) && (defined ICU_EMIOS_1_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined ICU_EMIOS_1_CH_26_ISR_USED) && (defined GPT_EMIOS_1_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_26"
#endif


#if ( (defined GPT_EMIOS_1_CH_26_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_26_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_26_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 26 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 26
*
* @note   This will be defined only if eMIOS channel 26 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_26_ISR)
{

    #if(defined GPT_EMIOS_1_CH_26_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_26);
    #endif

    #if(defined PWM_EMIOS_1_CH_26_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_26);
    #endif

    #if(defined ICU_EMIOS_1_CH_26_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_26);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:27 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_27
*/
#if  ((defined GPT_EMIOS_1_CH_27_ISR_USED) && (defined PWM_EMIOS_1_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined PWM_EMIOS_1_CH_27_ISR_USED) && (defined ICU_EMIOS_1_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined ICU_EMIOS_1_CH_27_ISR_USED) && (defined GPT_EMIOS_1_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_27"
#endif


#if ( (defined GPT_EMIOS_1_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_27_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 27 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 27
*
* @note   This will be defined only if eMIOS channel 27 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_27_ISR)
{

    #if(defined GPT_EMIOS_1_CH_27_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_27);
    #endif

    #if(defined PWM_EMIOS_1_CH_27_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_27);
    #endif

    #if(defined ICU_EMIOS_1_CH_27_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_27);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:28 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_28
*/
#if  ((defined GPT_EMIOS_1_CH_28_ISR_USED) && (defined PWM_EMIOS_1_CH_28_ISR_USED))
#error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined PWM_EMIOS_1_CH_28_ISR_USED) && (defined ICU_EMIOS_1_CH_28_ISR_USED))
#error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined ICU_EMIOS_1_CH_28_ISR_USED) && (defined GPT_EMIOS_1_CH_28_ISR_USED))
#error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_28"
#endif


#if ( (defined GPT_EMIOS_1_CH_28_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_28_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_28_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 28 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 28
*
* @note   This will be defined only if eMIOS channel 28 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_28_ISR)
{

    #if(defined GPT_EMIOS_1_CH_28_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_28);
    #endif

    #if(defined PWM_EMIOS_1_CH_28_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_28);
    #endif

    #if(defined ICU_EMIOS_1_CH_28_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_28);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:29 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_29
*/
#if  ((defined GPT_EMIOS_1_CH_29_ISR_USED) && (defined PWM_EMIOS_1_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined PWM_EMIOS_1_CH_29_ISR_USED) && (defined ICU_EMIOS_1_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined ICU_EMIOS_1_CH_29_ISR_USED) && (defined GPT_EMIOS_1_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_29"
#endif


#if ( (defined GPT_EMIOS_1_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_29_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 29 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 29
*
* @note   This will be defined only if eMIOS channel 29 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_29_ISR)
{

    #if(defined GPT_EMIOS_1_CH_29_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_29);
    #endif

    #if(defined PWM_EMIOS_1_CH_29_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_29);
    #endif

    #if(defined ICU_EMIOS_1_CH_29_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_29);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:30 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_30
*/
#if  ((defined GPT_EMIOS_1_CH_30_ISR_USED) && (defined PWM_EMIOS_1_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined PWM_EMIOS_1_CH_30_ISR_USED) && (defined ICU_EMIOS_1_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined ICU_EMIOS_1_CH_30_ISR_USED) && (defined GPT_EMIOS_1_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_30"
#endif


#if ( (defined GPT_EMIOS_1_CH_30_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_30_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_30_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 30 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 30
*
* @note   This will be defined only if eMIOS channel 30 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_30_ISR)
{

    #if(defined GPT_EMIOS_1_CH_30_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_30);
    #endif

    #if(defined PWM_EMIOS_1_CH_30_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_30);
    #endif

    #if(defined ICU_EMIOS_1_CH_30_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_30);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:31 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_31
*/
#if  ((defined GPT_EMIOS_1_CH_31_ISR_USED) && (defined PWM_EMIOS_1_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined PWM_EMIOS_1_CH_31_ISR_USED) && (defined ICU_EMIOS_1_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined ICU_EMIOS_1_CH_31_ISR_USED) && (defined GPT_EMIOS_1_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_31"
#endif


#if ( (defined GPT_EMIOS_1_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_31_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 31 for eMIOS_1 module
* @details   Process the interrupt of eMIOS channel 31
*
* @note   This will be defined only if eMIOS channel 31 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_1_CH_31_ISR)
{

    #if(defined GPT_EMIOS_1_CH_31_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_31);
    #endif

    #if(defined PWM_EMIOS_1_CH_31_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_31);
    #endif

    #if(defined ICU_EMIOS_1_CH_31_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_1_CH_31);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 1 independent interrupts END ***************************/

/********************************** EMIOS 2 independent interrupts START **************************/

/*
* @brief EMIOS module:2 channel:0 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_0
*/
#if  ((defined GPT_EMIOS_2_CH_0_ISR_USED) && (defined PWM_EMIOS_2_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined PWM_EMIOS_2_CH_0_ISR_USED) && (defined ICU_EMIOS_2_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined ICU_EMIOS_2_CH_0_ISR_USED) && (defined GPT_EMIOS_2_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_0"
#endif


#if ( (defined GPT_EMIOS_2_CH_0_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_0_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_0_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 0 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 0
*
* @note   This will be defined only if eMIOS channel 0 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_0_ISR)
{

    #if(defined GPT_EMIOS_2_CH_0_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_0);
    #endif

    #if(defined PWM_EMIOS_2_CH_0_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_0);
    #endif

    #if(defined ICU_EMIOS_2_CH_0_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_0);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:1 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_1
*/
#if  ((defined GPT_EMIOS_2_CH_1_ISR_USED) && (defined PWM_EMIOS_2_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined PWM_EMIOS_2_CH_1_ISR_USED) && (defined ICU_EMIOS_2_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined ICU_EMIOS_2_CH_1_ISR_USED) && (defined GPT_EMIOS_2_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_1"
#endif


#if ( (defined GPT_EMIOS_2_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_1_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 1 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 1
*
* @note   This will be defined only if eMIOS channel 1 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_1_ISR)
{

    #if(defined GPT_EMIOS_2_CH_1_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_1);
    #endif

    #if(defined PWM_EMIOS_2_CH_1_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_1);
    #endif

    #if(defined ICU_EMIOS_2_CH_1_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_1);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:2 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_2
*/
#if  ((defined GPT_EMIOS_2_CH_2_ISR_USED) && (defined PWM_EMIOS_2_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined PWM_EMIOS_2_CH_2_ISR_USED) && (defined ICU_EMIOS_2_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined ICU_EMIOS_2_CH_2_ISR_USED) && (defined GPT_EMIOS_2_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_2"
#endif


#if ( (defined GPT_EMIOS_2_CH_2_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_2_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_2_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 2 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 2
*
* @note   This will be defined only if eMIOS channel 2 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_2_ISR)
{

    #if(defined GPT_EMIOS_2_CH_2_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_2);
    #endif

    #if(defined PWM_EMIOS_2_CH_2_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_2);
    #endif

    #if(defined ICU_EMIOS_2_CH_2_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_2);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:3 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_3
*/
#if  ((defined GPT_EMIOS_2_CH_3_ISR_USED) && (defined PWM_EMIOS_2_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined PWM_EMIOS_2_CH_3_ISR_USED) && (defined ICU_EMIOS_2_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined ICU_EMIOS_2_CH_3_ISR_USED) && (defined GPT_EMIOS_2_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_3"
#endif


#if ( (defined GPT_EMIOS_2_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_3_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 3 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 3
*
* @note   This will be defined only if eMIOS channel 3 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_3_ISR)
{

    #if(defined GPT_EMIOS_2_CH_3_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_3);
    #endif

    #if(defined PWM_EMIOS_2_CH_3_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_3);
    #endif

    #if(defined ICU_EMIOS_2_CH_3_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_3);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:4 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_4
*/
#if  ((defined GPT_EMIOS_2_CH_4_ISR_USED) && (defined PWM_EMIOS_2_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined PWM_EMIOS_2_CH_4_ISR_USED) && (defined ICU_EMIOS_2_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined ICU_EMIOS_2_CH_4_ISR_USED) && (defined GPT_EMIOS_2_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_4"
#endif


#if ( (defined GPT_EMIOS_2_CH_4_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_4_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_4_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 4 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 4
*
* @note   This will be defined only if eMIOS channel 4 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_4_ISR)
{

    #if(defined GPT_EMIOS_2_CH_4_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_4);
    #endif

    #if(defined PWM_EMIOS_2_CH_4_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_4);
    #endif

    #if(defined ICU_EMIOS_2_CH_4_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_4);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:5 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_5
*/
#if  ((defined GPT_EMIOS_2_CH_5_ISR_USED) && (defined PWM_EMIOS_2_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined PWM_EMIOS_2_CH_5_ISR_USED) && (defined ICU_EMIOS_2_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined ICU_EMIOS_2_CH_5_ISR_USED) && (defined GPT_EMIOS_2_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_5"
#endif


#if ( (defined GPT_EMIOS_2_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_5_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 5 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 5
*
* @note   This will be defined only if eMIOS channel 5 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_5_ISR)
{

    #if(defined GPT_EMIOS_2_CH_5_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_5);
    #endif

    #if(defined PWM_EMIOS_2_CH_5_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_5);
    #endif

    #if(defined ICU_EMIOS_2_CH_5_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_5);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:6 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_6
*/
#if  ((defined GPT_EMIOS_2_CH_6_ISR_USED) && (defined PWM_EMIOS_2_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined PWM_EMIOS_2_CH_6_ISR_USED) && (defined ICU_EMIOS_2_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined ICU_EMIOS_2_CH_6_ISR_USED) && (defined GPT_EMIOS_2_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_6"
#endif


#if ( (defined GPT_EMIOS_2_CH_6_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_6_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_6_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 6 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 6
*
* @note   This will be defined only if eMIOS channel 6 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_6_ISR)
{

    #if(defined GPT_EMIOS_2_CH_6_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_6);
    #endif

    #if(defined PWM_EMIOS_2_CH_6_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_6);
    #endif

    #if(defined ICU_EMIOS_2_CH_6_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_6);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:7 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_7
*/
#if  ((defined GPT_EMIOS_2_CH_7_ISR_USED) && (defined PWM_EMIOS_2_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined PWM_EMIOS_2_CH_7_ISR_USED) && (defined ICU_EMIOS_2_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined ICU_EMIOS_2_CH_7_ISR_USED) && (defined GPT_EMIOS_2_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_7"
#endif


#if ( (defined GPT_EMIOS_2_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_7_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 7 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 7
*
* @note   This will be defined only if eMIOS channel 7 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_7_ISR)
{

    #if(defined GPT_EMIOS_2_CH_7_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_7);
    #endif

    #if(defined PWM_EMIOS_2_CH_7_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_7);
    #endif

    #if(defined ICU_EMIOS_2_CH_7_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_7);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:8 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_8
*/

#if  ((defined GPT_EMIOS_2_CH_8_ISR_USED) && (defined PWM_EMIOS_2_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined PWM_EMIOS_2_CH_8_ISR_USED) && (defined ICU_EMIOS_2_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined ICU_EMIOS_2_CH_8_ISR_USED) && (defined GPT_EMIOS_2_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_8"
#endif


#if ( (defined GPT_EMIOS_2_CH_8_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_8_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_8_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 8 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 8
*
* @note   This will be defined only if eMIOS channel 8 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_8_ISR)
{

    #if(defined GPT_EMIOS_2_CH_8_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_8);
    #endif

    #if(defined PWM_EMIOS_2_CH_8_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_8);
    #endif

    #if(defined ICU_EMIOS_2_CH_8_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_8);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:9 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_9
*/
#if  ((defined GPT_EMIOS_2_CH_9_ISR_USED) && (defined PWM_EMIOS_2_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined PWM_EMIOS_2_CH_9_ISR_USED) && (defined ICU_EMIOS_2_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined ICU_EMIOS_2_CH_9_ISR_USED) && (defined GPT_EMIOS_2_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_9"
#endif


#if ( (defined GPT_EMIOS_2_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_9_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 9 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 9
*
* @note   This will be defined only if eMIOS channel 9 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_9_ISR)
{

    #if(defined GPT_EMIOS_2_CH_9_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_9);
    #endif

    #if(defined PWM_EMIOS_2_CH_9_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_9);
    #endif

    #if(defined ICU_EMIOS_2_CH_9_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_9);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:10 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_10
*/
#if  ((defined GPT_EMIOS_2_CH_10_ISR_USED) && (defined PWM_EMIOS_2_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined PWM_EMIOS_2_CH_10_ISR_USED) && (defined ICU_EMIOS_2_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined ICU_EMIOS_2_CH_10_ISR_USED) && (defined GPT_EMIOS_2_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_10"
#endif


#if ( (defined GPT_EMIOS_2_CH_10_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_10_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_10_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 10 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 10
*
* @note   This will be defined only if eMIOS channel 10 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_10_ISR)
{

    #if(defined GPT_EMIOS_2_CH_10_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_10);
    #endif

    #if(defined PWM_EMIOS_2_CH_10_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_10);
    #endif

    #if(defined ICU_EMIOS_2_CH_10_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_10);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:11 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_11
*/
#if  ((defined GPT_EMIOS_2_CH_11_ISR_USED) && (defined PWM_EMIOS_2_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined PWM_EMIOS_2_CH_11_ISR_USED) && (defined ICU_EMIOS_2_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined ICU_EMIOS_2_CH_11_ISR_USED) && (defined GPT_EMIOS_2_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_11"
#endif


#if ( (defined GPT_EMIOS_2_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_11_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 11 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 11
*
* @note   This will be defined only if eMIOS channel 11 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_11_ISR)
{

    #if(defined GPT_EMIOS_2_CH_11_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_11);
    #endif

    #if(defined PWM_EMIOS_2_CH_11_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_11);
    #endif

    #if(defined ICU_EMIOS_2_CH_11_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_11);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:12 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_12
*/
#if  ((defined GPT_EMIOS_2_CH_12_ISR_USED) && (defined PWM_EMIOS_2_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined PWM_EMIOS_2_CH_12_ISR_USED) && (defined ICU_EMIOS_2_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined ICU_EMIOS_2_CH_12_ISR_USED) && (defined GPT_EMIOS_2_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_12"
#endif


#if ( (defined GPT_EMIOS_2_CH_12_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_12_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_12_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 12 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 12
*
* @note   This will be defined only if eMIOS channel 12 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_12_ISR)
{

    #if(defined GPT_EMIOS_2_CH_12_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_12);
    #endif

    #if(defined PWM_EMIOS_2_CH_12_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_12);
    #endif

    #if(defined ICU_EMIOS_2_CH_12_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_12);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:13 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_13
*/
#if  ((defined GPT_EMIOS_2_CH_13_ISR_USED) && (defined PWM_EMIOS_2_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined PWM_EMIOS_2_CH_13_ISR_USED) && (defined ICU_EMIOS_2_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined ICU_EMIOS_2_CH_13_ISR_USED) && (defined GPT_EMIOS_2_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_13"
#endif


#if ( (defined GPT_EMIOS_2_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_13_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 13 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 13
*
* @note   This will be defined only if eMIOS channel 13 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_13_ISR)
{

    #if(defined GPT_EMIOS_2_CH_13_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_13);
    #endif

    #if(defined PWM_EMIOS_2_CH_13_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_13);
    #endif

    #if(defined ICU_EMIOS_2_CH_13_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_13);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:14 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_14
*/
#if  ((defined GPT_EMIOS_2_CH_14_ISR_USED) && (defined PWM_EMIOS_2_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined PWM_EMIOS_2_CH_14_ISR_USED) && (defined ICU_EMIOS_2_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined ICU_EMIOS_2_CH_14_ISR_USED) && (defined GPT_EMIOS_2_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_14"
#endif


#if ( (defined GPT_EMIOS_2_CH_14_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_14_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_14_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 14 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 14
*
* @note   This will be defined only if eMIOS channel 14 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_14_ISR)
{

    #if(defined GPT_EMIOS_2_CH_14_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_14);
    #endif

    #if(defined PWM_EMIOS_2_CH_14_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_14);
    #endif

    #if(defined ICU_EMIOS_2_CH_14_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_14);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:15 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_15
*/
#if  ((defined GPT_EMIOS_2_CH_15_ISR_USED) && (defined PWM_EMIOS_2_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined PWM_EMIOS_2_CH_15_ISR_USED) && (defined ICU_EMIOS_2_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined ICU_EMIOS_2_CH_15_ISR_USED) && (defined GPT_EMIOS_2_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_15"
#endif


#if ( (defined GPT_EMIOS_2_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_15_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 15 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 15
*
* @note   This will be defined only if eMIOS channel 15 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_15_ISR)
{

    #if(defined GPT_EMIOS_2_CH_15_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_15);
    #endif

    #if(defined PWM_EMIOS_2_CH_15_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_15);
    #endif

    #if(defined ICU_EMIOS_2_CH_15_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_15);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:16 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_16
*/
#if  ((defined GPT_EMIOS_2_CH_16_ISR_USED) && (defined PWM_EMIOS_2_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined PWM_EMIOS_2_CH_16_ISR_USED) && (defined ICU_EMIOS_2_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined ICU_EMIOS_2_CH_16_ISR_USED) && (defined GPT_EMIOS_2_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_16"
#endif


#if ( (defined GPT_EMIOS_2_CH_16_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_16_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_16_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 16 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 16
*
* @note   This will be defined only if eMIOS channel 16 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_16_ISR)
{

    #if(defined GPT_EMIOS_2_CH_16_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_16);
    #endif

    #if(defined PWM_EMIOS_2_CH_16_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_16);
    #endif

    #if(defined ICU_EMIOS_2_CH_16_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_16);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:17 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_17
*/
#if  ((defined GPT_EMIOS_2_CH_17_ISR_USED) && (defined PWM_EMIOS_2_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined PWM_EMIOS_2_CH_17_ISR_USED) && (defined ICU_EMIOS_2_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined ICU_EMIOS_2_CH_17_ISR_USED) && (defined GPT_EMIOS_2_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_17"
#endif


#if ( (defined GPT_EMIOS_2_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_17_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 17 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 17
*
* @note   This will be defined only if eMIOS channel 17 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_17_ISR)
{

    #if(defined GPT_EMIOS_2_CH_17_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_17);
    #endif

    #if(defined PWM_EMIOS_2_CH_17_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_17);
    #endif

    #if(defined ICU_EMIOS_2_CH_17_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_17);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:18 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_18
*/
#if  ((defined GPT_EMIOS_2_CH_18_ISR_USED) && (defined PWM_EMIOS_2_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined PWM_EMIOS_2_CH_18_ISR_USED) && (defined ICU_EMIOS_2_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined ICU_EMIOS_2_CH_18_ISR_USED) && (defined GPT_EMIOS_2_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_18"
#endif


#if ( (defined GPT_EMIOS_2_CH_18_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_18_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_18_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 18 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 18
*
* @note   This will be defined only if eMIOS channel 18 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_18_ISR)
{

    #if(defined GPT_EMIOS_2_CH_18_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_18);
    #endif

    #if(defined PWM_EMIOS_2_CH_18_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_18);
    #endif

    #if(defined ICU_EMIOS_2_CH_18_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_18);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:19 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_19
*/
#if  ((defined GPT_EMIOS_2_CH_19_ISR_USED) && (defined PWM_EMIOS_2_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined PWM_EMIOS_2_CH_19_ISR_USED) && (defined ICU_EMIOS_2_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined ICU_EMIOS_2_CH_19_ISR_USED) && (defined GPT_EMIOS_2_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_19"
#endif


#if ( (defined GPT_EMIOS_2_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_19_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 19 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 19
*
* @note   This will be defined only if eMIOS channel 19 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_19_ISR)
{

    #if(defined GPT_EMIOS_2_CH_19_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_19);
    #endif

    #if(defined PWM_EMIOS_2_CH_19_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_19);
    #endif

    #if(defined ICU_EMIOS_2_CH_19_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_19);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */    
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:20 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_20
*/
#if  ((defined GPT_EMIOS_2_CH_20_ISR_USED) && (defined PWM_EMIOS_2_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined PWM_EMIOS_2_CH_20_ISR_USED) && (defined ICU_EMIOS_2_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined ICU_EMIOS_2_CH_20_ISR_USED) && (defined GPT_EMIOS_2_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_20"
#endif


#if ( (defined GPT_EMIOS_2_CH_20_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_20_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_20_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 20 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 20
*
* @note   This will be defined only if eMIOS channel 20 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_20_ISR)
{

    #if(defined GPT_EMIOS_2_CH_20_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_20);
    #endif

    #if(defined PWM_EMIOS_2_CH_20_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_20);
    #endif

    #if(defined ICU_EMIOS_2_CH_20_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_20);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:21 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_21
*/
#if  ((defined GPT_EMIOS_2_CH_21_ISR_USED) && (defined PWM_EMIOS_2_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined PWM_EMIOS_2_CH_21_ISR_USED) && (defined ICU_EMIOS_2_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined ICU_EMIOS_2_CH_21_ISR_USED) && (defined GPT_EMIOS_2_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_21"
#endif


#if ( (defined GPT_EMIOS_2_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_21_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 21 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 21
*
* @note   This will be defined only if eMIOS channel 21 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_21_ISR)
{

    #if(defined GPT_EMIOS_2_CH_21_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_21);
    #endif

    #if(defined PWM_EMIOS_2_CH_21_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_21);
    #endif

    #if(defined ICU_EMIOS_2_CH_21_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_21);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:22 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_22
*/
#if  ((defined GPT_EMIOS_2_CH_22_ISR_USED) && (defined PWM_EMIOS_2_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined PWM_EMIOS_2_CH_22_ISR_USED) && (defined ICU_EMIOS_2_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined ICU_EMIOS_2_CH_22_ISR_USED) && (defined GPT_EMIOS_2_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_22"
#endif


#if ( (defined GPT_EMIOS_2_CH_22_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_22_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_22_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 22 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 22
*
* @note   This will be defined only if eMIOS channel 22 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_22_ISR)
{

    #if(defined GPT_EMIOS_2_CH_22_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_22);
    #endif

    #if(defined PWM_EMIOS_2_CH_22_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_22);
    #endif

    #if(defined ICU_EMIOS_2_CH_22_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_22);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:23 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_23
*/
#if  ((defined GPT_EMIOS_2_CH_23_ISR_USED) && (defined PWM_EMIOS_2_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined PWM_EMIOS_2_CH_23_ISR_USED) && (defined ICU_EMIOS_2_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined ICU_EMIOS_2_CH_23_ISR_USED) && (defined GPT_EMIOS_2_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_23"
#endif


#if ( (defined GPT_EMIOS_2_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_23_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 23 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 23
*
* @note   This will be defined only if eMIOS channel 23 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_23_ISR)
{

    #if(defined GPT_EMIOS_2_CH_23_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_23);
    #endif

    #if(defined PWM_EMIOS_2_CH_23_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_23);
    #endif

    #if(defined ICU_EMIOS_2_CH_23_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_23);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:24 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_24
*/
#if  ((defined GPT_EMIOS_2_CH_24_ISR_USED) && (defined PWM_EMIOS_2_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined PWM_EMIOS_2_CH_24_ISR_USED) && (defined ICU_EMIOS_2_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined ICU_EMIOS_2_CH_24_ISR_USED) && (defined GPT_EMIOS_2_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_24"
#endif


#if ( (defined GPT_EMIOS_2_CH_24_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_24_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_24_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 24 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 24
*
* @note   This will be defined only if eMIOS channel 24 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_24_ISR)
{

    #if(defined GPT_EMIOS_2_CH_24_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_24);
    #endif

    #if(defined PWM_EMIOS_2_CH_24_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_24);
    #endif

    #if(defined ICU_EMIOS_2_CH_24_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_24);
    #endif

    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:25 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_25
*/
#if  ((defined GPT_EMIOS_2_CH_25_ISR_USED) && (defined PWM_EMIOS_2_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined PWM_EMIOS_2_CH_25_ISR_USED) && (defined ICU_EMIOS_2_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined ICU_EMIOS_2_CH_25_ISR_USED) && (defined GPT_EMIOS_2_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_25"
#endif


#if ( (defined GPT_EMIOS_2_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_25_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 25 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 25
*
* @note   This will be defined only if eMIOS channel 25 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_25_ISR)
{

    #if(defined GPT_EMIOS_2_CH_25_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_25);
    #endif

    #if(defined PWM_EMIOS_2_CH_25_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_25);
    #endif

    #if(defined ICU_EMIOS_2_CH_25_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_25);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:26 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_26
*/
#if  ((defined GPT_EMIOS_2_CH_26_ISR_USED) && (defined PWM_EMIOS_2_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined PWM_EMIOS_2_CH_26_ISR_USED) && (defined ICU_EMIOS_2_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined ICU_EMIOS_2_CH_26_ISR_USED) && (defined GPT_EMIOS_2_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_26"
#endif


#if ( (defined GPT_EMIOS_2_CH_26_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_26_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_26_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 26 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 26
*
* @note   This will be defined only if eMIOS channel 26 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_2_CH_26_ISR)
{

    #if(defined GPT_EMIOS_2_CH_26_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_26);
    #endif

    #if(defined PWM_EMIOS_2_CH_26_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_26);
    #endif

    #if(defined ICU_EMIOS_2_CH_26_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_26);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:27 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_27
*/
#if  ((defined GPT_EMIOS_2_CH_27_ISR_USED) && (defined PWM_EMIOS_2_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined PWM_EMIOS_2_CH_27_ISR_USED) && (defined ICU_EMIOS_2_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined ICU_EMIOS_2_CH_27_ISR_USED) && (defined GPT_EMIOS_2_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_27"
#endif


#if ( (defined GPT_EMIOS_2_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_27_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 27 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 27
*
* @note   This will be defined only if eMIOS channel 27 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_2_CH_27_ISR)
{

    #if(defined GPT_EMIOS_2_CH_27_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_27);
    #endif

    #if(defined PWM_EMIOS_2_CH_27_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_27);
    #endif

    #if(defined ICU_EMIOS_2_CH_27_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_27);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:28 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_28
*/
#if  ((defined GPT_EMIOS_2_CH_28_ISR_USED) && (defined PWM_EMIOS_2_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined PWM_EMIOS_2_CH_28_ISR_USED) && (defined ICU_EMIOS_2_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined ICU_EMIOS_2_CH_28_ISR_USED) && (defined GPT_EMIOS_2_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_28"
#endif


#if ( (defined GPT_EMIOS_2_CH_28_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_28_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_28_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 28 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 28
*
* @note   This will be defined only if eMIOS channel 28 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_2_CH_28_ISR)
{

    #if(defined GPT_EMIOS_2_CH_28_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_28);
    #endif

    #if(defined PWM_EMIOS_2_CH_28_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_28);
    #endif

    #if(defined ICU_EMIOS_2_CH_28_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_28);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:29 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_29
*/
#if  ((defined GPT_EMIOS_2_CH_29_ISR_USED) && (defined PWM_EMIOS_2_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined PWM_EMIOS_2_CH_29_ISR_USED) && (defined ICU_EMIOS_2_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined ICU_EMIOS_2_CH_29_ISR_USED) && (defined GPT_EMIOS_2_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_29"
#endif


#if ( (defined GPT_EMIOS_2_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_29_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 29 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 29
*
* @note   This will be defined only if eMIOS channel 29 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/ 
ISR(EMIOS_2_CH_29_ISR)
{

    #if(defined GPT_EMIOS_2_CH_29_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_29);
    #endif

    #if(defined PWM_EMIOS_2_CH_29_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_29);
    #endif

    #if(defined ICU_EMIOS_2_CH_29_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_29);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:30 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_30
*/
#if  ((defined GPT_EMIOS_2_CH_30_ISR_USED) && (defined PWM_EMIOS_2_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined PWM_EMIOS_2_CH_30_ISR_USED) && (defined ICU_EMIOS_2_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined ICU_EMIOS_2_CH_30_ISR_USED) && (defined GPT_EMIOS_2_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_30"
#endif


#if ( (defined GPT_EMIOS_2_CH_30_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_30_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_30_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 30 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 30
*
* @note   This will be defined only if eMIOS channel 30 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_30_ISR)
{

    #if(defined GPT_EMIOS_2_CH_30_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_30);
    #endif

    #if(defined PWM_EMIOS_2_CH_30_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_30);
    #endif

    #if(defined ICU_EMIOS_2_CH_30_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_30);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:31 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_31
*/
#if  ((defined GPT_EMIOS_2_CH_31_ISR_USED) && (defined PWM_EMIOS_2_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined PWM_EMIOS_2_CH_31_ISR_USED) && (defined ICU_EMIOS_2_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined ICU_EMIOS_2_CH_31_ISR_USED) && (defined GPT_EMIOS_2_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_31"
#endif


#if ( (defined GPT_EMIOS_2_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_31_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMIOS channel : 31 for eMIOS_2 module
* @details   Process the interrupt of eMIOS channel 31
*
* @note   This will be defined only if eMIOS channel 31 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Irq_c_5 This is not a standard library macro, 
*/
ISR(EMIOS_2_CH_31_ISR)
{

    #if(defined GPT_EMIOS_2_CH_31_ISR_USED)
         Gpt_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_31);
    #endif

    #if(defined PWM_EMIOS_2_CH_31_ISR_USED)
         Pwm_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_31);
    #endif

    #if(defined ICU_EMIOS_2_CH_31_ISR_USED)
         Icu_eMIOS_LLD_ProcessInterrupt(EMIOS_2_CH_31);
    #endif
    
    /*
    * @violates @ref eMios_Irq_c_3 Cast from unsigned long to pointer 
    */
    EXIT_INTERRUPT();
}
#endif

/*********************************** EMIOS 2 independent interrupts END ***************************/


#endif  /* EMIOS_COMMON_ISR_HANDLER == STD_ON */

#if (USE_ICU_MODULE==STD_ON)
#if (ICU_DMA_SUPPORTED == STD_ON)
#if (defined ICU_EMIOS_DmaCh0_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch0)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_0];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_0) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_0)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh1_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch1)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_1];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_1) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_1)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh2_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch2)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_2];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_2) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_2)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh3_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch3)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_3];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_3) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_3)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh4_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch4)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_4];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_4) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_4)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh5_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch5)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_5];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_5) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_5)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh6_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch6)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_6];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_6) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_6)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh7_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch7)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_7];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_7) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_7)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh8_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch8)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_8];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_8) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_8)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh9_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch9)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_9];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_9) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_9)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh10_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch10)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_10];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_10) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_10)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh11_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch11)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_11];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_11) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_11)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh12_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch12)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_12];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_12) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_12)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh13_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch13)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_13];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_13) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_13)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh14_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch14)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_14];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_14) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_14)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh15_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch15)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_15];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_15) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_15)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh16_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch16)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_16];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_16) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_16)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh17_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch17)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_17];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_17) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_17)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh18_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch18)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_18];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_18) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_18)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh19_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch19)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_19];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_19) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_19)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh20_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch0
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
     ISR(Icu_EMIOS_Dma_Ch20)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_20];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_20) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_20)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh21_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch1
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch21)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_21];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_21) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_21)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh22_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch2
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch22)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_22];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_22) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_22)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh23_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch3
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch23)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_23];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_23) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_23)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#if (defined ICU_EMIOS_DmaCh24_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch4
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch24)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_24];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_24) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_24)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh25_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch5
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch25)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_25];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_25) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_25)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh26_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch26)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_26];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_26) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_26)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh27_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch27)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_27];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_27) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_27)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh28_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch28)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_28];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_28) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_28)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh29_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch29)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_29];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_29) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_29)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh30_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch30)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_30];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_30) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_30)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh31_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch31)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_31];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_31) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
            (((REG_READ32(DMA_INTL(0))) & ((uint32)1U << ICU_EMIOS_DMA_CH_31)) != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh32_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch32)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_32];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_32) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_32 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh33_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch33)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_33];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_33) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_33 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh34_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch34)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_34];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_34) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_34 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh35_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch6
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch35)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_35];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_35) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_35 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh36_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch7
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch36)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_36];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_36) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
         (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_36 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh37_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch8
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch37)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_37];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_37) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_37 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh38_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch9
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch38)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_38];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_38) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_38 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh39_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch10
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch39)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_39];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_39) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_39 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh40_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch11
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch40)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_40];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_40) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_40 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh41_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch12
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch41)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_41];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_41) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
         (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_41 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh42_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch13
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch42)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_42];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_42) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
         (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_42 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh43_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch43)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_43];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_43) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
         (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_43 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh44_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch44)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_44];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_44) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_44 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh45_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch45)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_45];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_45) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_45 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh46_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch46)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_46];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_46) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_46 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh47_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch47)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_47];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_47) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_47 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh48_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch48)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_48];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_48) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
       (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_48 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh49_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch49)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_49];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_49) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
         (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_49 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh50_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch50)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_50];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_50) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
         (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_50 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh51_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch51)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_51];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_51) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_51 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh52_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch52)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_52];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_52) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_52 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh53_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch53)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_53];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_53) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_53 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh54_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch54)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_54];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_54) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_54 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh55_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch55)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_55];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_55) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_55 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh56_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch56)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_56];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_56) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_56 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh57_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch57)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_57];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_57) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_57 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh58_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch58)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_58];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_58) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_58 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh59_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch59)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_59];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_59) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_59 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh60_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch60)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_60];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_60) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_60 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh61_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch61)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_61];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_61) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_61 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh62_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch62)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_62];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_62) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_62 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif

#if (defined ICU_EMIOS_DmaCh63_ISR_USED)
/**********************************************************************
* Function Name: Icu_EMIOS_Dma_Ch14
* Service ID: n/a
* Sync/Asyn: n/a
* Re-Entrancy: Reentrant
* Parameters (in): channel - hardware channel number
* Parameters (out): None
* Return Value: None
* Description: ICU Interrupt Service Routine Generated by Configuration Tool
**********************************************************************/
    /* MISRA-C:2004 8.1,8.2 VIOLATION: Refer to REF 5,6 above */
    /* MISRA-C:2004 16.8 VIOLATION: Refer to REF 7 above */
    ISR(Icu_EMIOS_Dma_Ch63)
    {
/*
* @violates @ref eMios_Irq_c_7 Array indexing shall be the only allowed form of pointer
* arithmetic.
*/
        CONST(uint8, ICU_CONST) hwChannel = Icu_Cfg_Ptr->Icu_DMAHWMap[ICU_EMIOS_DMA_CH_63];
        CONST(uint8, ICU_CONST) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
        CONST(uint8, ICU_CONST) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        if ((((REG_READ32(EMIOS_CCR(mIdx, chIdx))) & ( CCR_DMA_MASK | CCR_FEN_MASK )) ==
             ((CCR_DMA_ASSIGN_DMA << CCR_DMA_SHIFT ) | (CCR_FEN_ENABLE << CCR_FEN_SHIFT))) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
             ((DMA_TCD_SR(ICU_EMIOS_DMA_CH_63) & (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)) != 0U ) &&
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        (((REG_READ32(DMA_INTH(0))) & ((uint32)1U << (ICU_EMIOS_DMA_CH_63 - ICU_EMIOS_DMA_CH_32))) \
                                                                                             != 0U )
/*
* @violates @ref eMios_Irq_c_8 side effects on right hand of logical operator: '||'.
 */
           )
        {
            /* Call Common Interrupt Routine */
            Icu_eMIOS_LLD_ProcessInterrupt(hwChannel);
        }
/* @violates @ref eMios_Irq_c_3 cast from unsigned long to pointer */
        EXIT_INTERRUPT();
    }
#endif
#endif /* #if (ICU_DMA_PRESENT == STD_ON) */
#endif /* DMA interrupts for ICU module */
#else

#error "Unknown EMIOS interrupt handler type, EMIOS_COMMON_ISR_HANDLER is undefined";

#endif /* #ifdef EMIOS_COMMON_ISR_HANDLER */


#endif /* module check */


#if ((USE_GPT_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==100))

#define GPT_STOP_SEC_CODE
/*
* @violates @ref eMios_Irq_c_1 only preprocessor statements and comments before
*            "#include"  
*/
/*
* @violates @ref eMios_Irq_c_2 Precautions shall be taken in order to prevent the contents of a
*            header file being included twice.
*/
#include "MemMap.h"
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==121))
#define PWM_STOP_SEC_CODE
/*
* @violates @ref eMios_Irq_c_1 only preprocessor statements and comments before
*            "#include"  
*/
/*
* @violates @ref eMios_Irq_c_2 Precautions shall be taken in order to prevent the contents of a
*            header file being included twice.
*/
#include "MemMap.h"
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON) && \
     (EMIOS_COMMON_MODULE_ID==122))
#define ICU_STOP_SEC_CODE

/*
* @violates @ref eMios_Irq_c_1 only preprocessor statements and comments before
*            "#include"  
*/
/*
* @violates @ref eMios_Irq_c_2 Precautions shall be taken in order to prevent the contents of a
*            header file being included twice.
*/
#include "MemMap.h"
#endif


#ifdef __cplusplus
}
#endif
/** @} */
