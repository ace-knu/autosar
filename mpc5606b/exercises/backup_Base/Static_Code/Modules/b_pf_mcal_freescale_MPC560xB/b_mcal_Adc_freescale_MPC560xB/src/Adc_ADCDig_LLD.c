/**
*   @file    Adc_ADCDig_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - low level driver source file.
*   @details This is the low level driver source file,mainly implemented for the ADCDig hardware IP.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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
* @section Adc_ADCDig_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include". This violation is not fixed since the inclusion of MemMap.h is as per Autosar
* requirement.
*
* @section Adc_ADCDig_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
*
* @section Adc_ADCDig_LLD_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.3, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller.
* The address calculated as an unsigned int is passed to  a macro for initializing the
* pointer with that address (ex: see REG_WRITE32 macro).
*
* @section Adc_ADCDig_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section Adc_ADCDig_LLD_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This is used for the Speed optimization of the memory access.
*
* @section Adc_ADCDig_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 14.2, Expected void type, assignment, increment or decrement.
* This is used to read an unused value from an register.
*
* @section Adc_ADCDig_LLD_c_REF_7
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 characters signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_ADCDig_LLD_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the code complexity.
*
* @section Adc_ADCDig_LLD_c_REF_9
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware ofsset of the controller. The address calculated as
* an unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_ADCDig_LLD_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is to be used by LLD layer.
*
* @section Adc_ADCDig_LLD_c_REF_11
* Violates MISRA 2004 Required Rule 10.1, cast from integer type to different type or
* a wider integer type
* This is used for the Speed optimization of the memory access.
*
* @section Adc_ADCDig_LLD_c_REF_12
* Violates MISRA 2004 Required Rule 1.2, place reliance on undefined or unspecified behaviour
* This is used for the code complexity.
*
* @section Adc_ADCDig_LLD_c_REF_13
* Violates MISRA 2004 Required Rule 12.4, contain side effects of right-hand operand of a logical
* && or ||. This is used for the code complexity.
*
* @section Adc_ADCDig_LLD_c_REF_14
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not
* be permitted
*
* @section Adc_ADCDig_LLD_c_REF_15
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
* @section Adc_ADCDig_LLD_c_REF_16
* Violates MISRA 2004 Required Rule 14.10, if else-if constructs not terminated by else
* Unrequired else conditions are omitted for code complexity and optimization.
*
* @section Adc_ADCDig_LLD_c_REF_17
* Violates MISRA 2004 Required Rule 14.6, multiple break statements in a loop, but are necessary
* to exit from the loop when Triggerflag is true.
*
* @section Adc_ADCDig_LLD_c_REF_18
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Adc_ADCDig_LLD.c
*/
#include "Adc.h"
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "Reg_eSys_ADCDig.h"
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "Adc_ADCDig_LLD_CfgEx.h"
#include "SchM_Adc.h"
#include "Adc_ADCDig_LLD.h"
#include "Dma_LLD.h"
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "Mcal.h"

#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "Dem.h"
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
 #ifdef IPV_ADCDIG
  /* if Leopard or Pictus512_256_1M or Leopard cut2/cut3 or Komodo 2M or Panther */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file */
    #include "Adc_CTU2_LLD.h" /* CTUV2 related functionality */
  #elif (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file */
    #include "Adc_BCTU_LLD.h" /* BCTU related functionality */
  #else
    #include "Adc_CTU_LLD.h" /* CTU-lite related functionality */
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
  /* If Fado */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
      #include "Siu_Adc_LLD.h"
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
 #endif /* IPV_ADCDIG */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Adc_ADCDig_LLD.c
*/
#define ADC_AR_VENDOR_ID_DIG_LLD_C                 (43)
/*
* @violates @ref Adc_ADCDig_LLD_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C     (4)
/*
* @violates @ref Adc_ADCDig_LLD_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C     (0)
/*
* @violates @ref Adc_ADCDig_LLD_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C  (3)
#define ADC_SW_MAJOR_VERSION_DIG_LLD_C             (1)
#define ADC_SW_MINOR_VERSION_DIG_LLD_C             (0)
#define ADC_SW_PATCH_VERSION_DIG_LLD_C             (1)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Adc header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_DIG_LLD_C != ADC_VENDOR_ID)
    #error "Adc_ADCDig_LLD.c and Adc.h have different vendor ids"
#endif

/* Check if source file and Adc header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != ADC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Adc.h are different"
#endif

/* Check if source file and Adc header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_DIG_LLD_C != ADC_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_DIG_LLD_C != ADC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_ADCDig_LLD.c and Adc.h are different"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_DIG_LLD_C != ADC_REG_VENDOR_ID)
    #error "Adc_ADCDig_LLD.c and Reg_eSys_ADCDig.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != ADC_REG_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != ADC_REG_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != ADC_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Reg_eSys_ADCDig.h are different"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != ADC_REG_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_DIG_LLD_C != ADC_REG_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_DIG_LLD_C != ADC_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_ADCDig_LLD.c and Reg_eSys_ADCDig.h are different"
#endif

/* Check if source file and ADCDig_LLD_CfgEx header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_DIG_LLD_C != ADC_LLD_CFGEX_VENDOR_ID)
    #error "Adc_ADCDig_LLD.c and ADCDig_LLD_CfgEx.h have different vendor ids"
#endif

/* Check if source file and ADCDig_LLD_CfgEx header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != ADC_LLD_CFGEX_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != ADC_LLD_CFGEX_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != ADC_LLD_CFGEX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and ADCDig_LLD_CfgEx.h are different"
#endif

/* Check if source file and ADCDig_LLD_CfgEx header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != ADC_LLD_CFGEX_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_DIG_LLD_C != ADC_LLD_CFGEX_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_DIG_LLD_C != ADC_LLD_CFGEX_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_ADCDig_LLD.c and ADCDig_LLD_CfgEx.h are different"
#endif

/* Check if source file and ADCDig_LLD header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_DIG_LLD_C != ADC_VENDOR_ID_DIG_LLD)
    #error "Adc_ADCDig_LLD.c and ADCDig_LLD.h have different vendor ids"
#endif

/* Check if source file and ADCDig_LLD header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD) || \
     (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD) || \
     (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and ADCDig_LLD.h are different"
#endif

/* Check if source file and ADCDig_LLD header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != ADC_SW_MAJOR_VERSION_DIG_LLD) || \
     (ADC_SW_MINOR_VERSION_DIG_LLD_C != ADC_SW_MINOR_VERSION_DIG_LLD) || \
     (ADC_SW_PATCH_VERSION_DIG_LLD_C != ADC_SW_PATCH_VERSION_DIG_LLD))
    #error "Software Version Numbers of Adc_ADCDig_LLD.c and ADCDig_LLD.h are different"
#endif

/* Check if source file and DMA header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_DIG_LLD_C != DMA_VENDOR_ID)
    #error "Adc_ADCDig_LLD.c and Dma_LLD.h have different vendor ids"
#endif

/* Check if source file and DMA header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != DMA_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != DMA_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != DMA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Dma_LLD.h are different"
#endif

/* Check if source file and DMA header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != DMA_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_DIG_LLD_C != DMA_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_DIG_LLD_C != DMA_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_Irq.c and Dma_LLD.h are different"
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
 #ifdef IPV_ADCDIG
 /* if Leopard or Pictus512_256_1M or Leopard cut2/cut3 or Komodo 2M or Panther */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
  #if (ADC_ENABLE_CTUV2 == STD_ON)
   /* Check if source file and DMA header file are from the same vendor */
   #if (ADC_AR_VENDOR_ID_DIG_LLD_C != CTU2_VENDOR_ID)
    #error "Adc_ADCDig_LLD.c and Adc_CTU2_LLD.h have different vendor ids"
   #endif
   /* Check if source file and DMA header file are of the same Autosar version */
   #if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != CTU2_AR_RELEASE_MAJOR_VERSION) || \
        (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != CTU2_AR_RELEASE_MINOR_VERSION) || \
        (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != CTU2_AR_RELEASE_REVISION_VERSION))
       #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Adc_CTU2_LLD.h are different"
   #endif
   /* Check if source file and DMA header file are of the same Software version */
   #if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != CTU2_SW_MAJOR_VERSION) || \
        (ADC_SW_MINOR_VERSION_DIG_LLD_C != CTU2_SW_MINOR_VERSION) || \
        (ADC_SW_PATCH_VERSION_DIG_LLD_C != CTU2_SW_PATCH_VERSION))
       #error "Software Version Numbers of Adc_ADCDig_LLD.c and Adc_CTU2_LLD.h are different"
   #endif
  #endif /* (ADC_ENABLE_CTUV2 == STD_ON) */
 /* If Rainier cut 1.0 */
 #elif (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  #if (ADC_ENABLE_BCTU == STD_ON)
   #if (ADC_AR_VENDOR_ID_DIG_LLD_C != BCTU_VENDOR_ID)
    #error "Adc_ADCDig_LLD.c and Adc_BCTU_LLD.h have different vendor ids"
   #endif
   /* Check if source file and DMA header file are of the same Autosar version */
   #if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != BCTU_AR_RELEASE_MAJOR_VERSION) || \
        (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != BCTU_AR_RELEASE_MINOR_VERSION) || \
        (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != BCTU_AR_RELEASE_REVISION_VERSION))
       #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Adc_CTU2_LLD.h are different"
   #endif
   /* Check if source file and DMA header file are of the same Software version */
   #if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != BCTU_SW_MAJOR_VERSION) || \
        (ADC_SW_MINOR_VERSION_DIG_LLD_C != BCTU_SW_MINOR_VERSION) || \
        (ADC_SW_PATCH_VERSION_DIG_LLD_C != BCTU_SW_PATCH_VERSION))
       #error "Software Version Numbers of Adc_ADCDig_LLD.c and Adc_BCTU_LLD.h are different"
   #endif
  #endif /* (ADC_ENABLE_BCTU == STD_ON) */
 #else /* Bolero or Fado */
  /* Check if source file and DMA header file are from the same vendor */
  #if (ADC_AR_VENDOR_ID_DIG_LLD_C != CTU_VENDOR_ID)
   #error "Adc_ADCDig_LLD.c and Adc_CTU_LLD.h have different vendor ids"
  #endif
  /* Check if source file and DMA header file are of the same Autosar version */
  #if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != CTU_AR_RELEASE_MAJOR_VERSION) || \
       (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != CTU_AR_RELEASE_MINOR_VERSION) || \
       (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD_C != CTU_AR_RELEASE_REVISION_VERSION))
      #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Adc_CTU_LLD.h are different"
  #endif
  /* Check if source file and DMA header file are of the same Software version */
  #if ((ADC_SW_MAJOR_VERSION_DIG_LLD_C != CTU_SW_MAJOR_VERSION) || \
       (ADC_SW_MINOR_VERSION_DIG_LLD_C != CTU_SW_MINOR_VERSION) || \
       (ADC_SW_PATCH_VERSION_DIG_LLD_C != CTU_SW_PATCH_VERSION))
      #error "Software Version Numbers of Adc_ADCDig_LLD.c and Adc_CTU_LLD.h are different"
  #endif
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
 #endif /* IPV_ADCDIG */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
 /* Check if source file and Dem header file are of the same version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != DEM_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Dem.h are different"
 #endif
#endif
 /* Check if source file and DET header file are of the same version */
 #if (ADC_DEV_ERROR_DETECT == STD_ON)
    #if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD_C != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD.c and Det.h are different"
    #endif
 #endif
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

/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef IPV_ADCDIG
/* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2/cut3 or Pictus 1M or Komodo 2M or Panther or Rainier or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  /* if !Pictus1M */
  #ifndef IPV_ADCDIG_31301_PICTUS1M
      #ifdef ADC_WDG_SUPPORTED
/**
* @brief          Channel descriptions for the WDG interrupts
* @details        Channel descriptions structure for the WDG interrupts.
* @violates @ref Adc_ADCDig_LLD_c_REF_10 internal linkage or external linkage
*/
VAR(uint8, ADC_VAR) ADC_LLD_WdgChannelDescRegIndex[ADC_MAX_HW_UNITS][ADC_MAX_CHANNEL_PER_HW_UNIT];
VAR(uint32, ADC_VAR) ADC_LLD_WdgChannelDescMask[ADC_MAX_HW_UNITS][ADC_MAX_CHANNEL_PER_HW_UNIT];
      #endif
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
 #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
               (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
               (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
               (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* #ifdef IPV_ADCDIG */

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          MHT groups array.
* @details        This array is used to handle the MHT groups in an efficient manner
*                 through the driver code.
*/
VAR(Adc_LLD_MhtChannelGroupType, ADC_VAR) Adc_LLD_MhtChannelGroup[ADC_MAX_HW_UNITS][ADC_MAX_GROUPS_PER_HW_UNIT];
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */


#if (ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON)
/**
* @brief          Set once register array.
* @details        This array is used to handle the set once register feature.
* @violates @ref Adc_ADCDig_LLD_c_REF_10 internal linkage or external linkage
* @violates @ref Adc_ADCDig_LLD_c_REF_18 Objects shall be defined at block scope
*/
VAR(uint8, ADC_VAR) Adc_LLD_OnceRegistersSet[ADC_MAX_HW_UNITS];
#endif /* ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON */

#ifdef ADC_DMA_SUPPORTED
#if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
/**
* @brief          Internal buffer used by DMA to transfer blocks with gaps
*/
VAR(Adc_ValueGroupType, ADC_VAR) DmaInternalResultBuffer[ADC_MAX_HW_UNITS][ADC_MAXIMUM_HW_CHANNELS];
#endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
#endif /* ADC_DMA_SUPPORTED */

/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_c_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          This function return the greater channel index assigned to a group.
* @details        Return the greater channel index assigned to a group.
*
* @param[in]      Group           The group number.
*
* @return         Adc_ChannelType Max Channel index assigned to a group.
*
* @pre            Driver must be initialized.
*/
STATIC FUNC(Adc_ChannelType, ADC_CODE) Adc_MaxChannelIdAssignedToGroup
(
  CONST(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_READ_GROUP_API == STD_ON) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
/* @violates @ref Adc_ADCDig_LLD_c_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          This function return the greater channel index assigned to a group.
* @details        Return the greater channel index assigned to a group.
*
* @param[in]      Group           The group number.
*
* @return         Adc_ChannelType Max Channel index assigned to a group.
*
* @pre            Driver must be initialized.
*/
STATIC FUNC(Adc_ChannelType, ADC_CODE) Adc_MaxChannelIdAssignedToGroup
(
  CONST(Adc_GroupType, AUTOMATIC) Group
)
{
  VAR(Adc_ChannelType, AUTOMATIC) ch=(Adc_ChannelType)0U;
  VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
  VAR(Adc_ChannelType, AUTOMATIC) MaxChIndex;
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  MaxChIndex = Adc_Cfg_Ptr->Groups[Group].Assignment[ch];

  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  for(ch=(Adc_ChannelType)1U;ch<Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; ch++)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChIndex = Adc_Cfg_Ptr->Groups[Group].Assignment[ch];
    if (ChIndex > MaxChIndex)
    {
        MaxChIndex = ChIndex;
    }
  }
  return MaxChIndex;
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Checks if conversion values are in the configured range.
* @details        Return true if conversion values are in the configured range, otherwise false.
*
* @param[in]      value       Adc conversion value.
*                 unit        Adc Hardware unit.
*                 index       Adc channel index assigned to a group.
*
* @return         boolean     Conversion value in range flag.
* @retval         TRUE        if conversion values are in the configured range.
* @retval         FALSE       if conversion values are not in the configured range.
*
* @pre            Driver must be initialized.
*/
FUNC(boolean, ADC_CODE) ADCDig_LLD_CheckConversionValuesInRange
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
(
  VAR(uint16, AUTOMATIC) value,
  VAR(Adc_HwUnitType, AUTOMATIC) unit,
  VAR(Adc_ChannelType, AUTOMATIC) index
)
{
  VAR(boolean, AUTOMATIC) ValInRange = (boolean)FALSE;

  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  switch (Adc_Cfg_Ptr->Channels[unit][index].ChannelRange)
  {
    /* Complete range - independent from channel limit settings. */
    case (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS:
        ValInRange = (boolean)TRUE;
    break;
    /* Range between low limit and high limit - high limit value included. */
    case (Adc_ChannelRangeSelectType)ADC_RANGE_BETWEEN:
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if ((value > Adc_Cfg_Ptr->Channels[unit][index].ChannelLowLimit) && (value <= Adc_Cfg_Ptr->Channels[unit][index].ChannelHighLimit))
      {
        ValInRange = (boolean)TRUE;
      }
      else
      {
        ValInRange = (boolean)FALSE;
      }
    break;
    /* Range above high limit or below low limit - low limit value included. */
    case (Adc_ChannelRangeSelectType)ADC_RANGE_NOT_BETWEEN:
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if ((value > Adc_Cfg_Ptr->Channels[unit][index].ChannelHighLimit) || (value <= Adc_Cfg_Ptr->Channels[unit][index].ChannelLowLimit))
      {
        ValInRange = (boolean)TRUE;
      }
      else
      {
        ValInRange = (boolean)FALSE;
      }
    break;
    /* Range below high limit -high limit value included. */
    case (Adc_ChannelRangeSelectType)ADC_RANGE_NOT_OVER_HIGH:
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if (value <= Adc_Cfg_Ptr->Channels[unit][index].ChannelHighLimit)
      {
        ValInRange = (boolean)TRUE;
      }
      else
      {
        ValInRange = (boolean)FALSE;
      }
    break;
    /* Range above low limit. */
    case (Adc_ChannelRangeSelectType)ADC_RANGE_NOT_UNDER_LOW:
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if (value > Adc_Cfg_Ptr->Channels[unit][index].ChannelLowLimit)
      {
        ValInRange = (boolean)TRUE;
      }
      else
      {
        ValInRange = (boolean)FALSE;
      }
    break;
    /* Range above high limit. */
    case (Adc_ChannelRangeSelectType)ADC_RANGE_OVER_HIGH:
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if (value > Adc_Cfg_Ptr->Channels[unit][index].ChannelHighLimit)
      {
        ValInRange = (boolean)TRUE;
      }
      else
      {
        ValInRange = (boolean)FALSE;
      }
    break;
    /* Range below low limit - low limit value included. */
    case (Adc_ChannelRangeSelectType)ADC_RANGE_UNDER_LOW:
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if (value <= Adc_Cfg_Ptr->Channels[unit][index].ChannelLowLimit)
      {
        ValInRange = (boolean)TRUE;
      }
      else
      {
        ValInRange = (boolean)FALSE;
      }
    break;
    /* Unexpected value */
    default:
    /* Catastrophic Errors Recovery (CER) */
      Cer_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_ADCDIG_LLD_READGROUP_ID,
                      (uint8)ADC_CER_LIMIT_RANGE_TYPE);
  }
  return (boolean)ValInRange;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
* @brief          This function initializes the ADC hardware module, and the ADC driver.
* @details        This function initializes the ADC hardware module, and the ADC driver.
*
* @param[in]      CfgPtr      Configuration data pointer.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_Init
(
  P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) CfgPtr
)
{
  VAR(Adc_HwUnitType, AUTOMATIC) unit=(Adc_HwUnitType)0; /* Hardware unit index */
  VAR(Adc_HwUnitType, AUTOMATIC) HwIndex=(Adc_HwUnitType)0; /* Hardware index in the structure*/
  VAR(uint16, AUTOMATIC) queue_index = (uint16)0; /* Queue index */
  VAR(Adc_GroupType,AUTOMATIC)Group = (Adc_GroupType)0; /* Group Index */
  P2CONST(Adc_LLD_HWUnitConfiguration, AUTOMATIC, ADC_APPL_CONST) ConfigPtr = NULL_PTR;
  VAR(uint32, AUTOMATIC) Timeout;
#ifdef ADC_WDG_SUPPORTED
  VAR(uint8, AUTOMATIC) ch = 0U;
  VAR(uint32, AUTOMATIC) wtimrValue = (uint32)0; /* watchdog timer temp variable */
#endif /* ADC_WDG_SUPPORTED */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
  VAR(Adc_GroupType, AUTOMATIC) GroupIndex = (Adc_GroupType)0; /* Enable/Disable channel Group Index */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

  /* ADC056*/
  ConfigPtr = CfgPtr->ADC;
  
#if (ADC_DEINIT_API == STD_ON)  
  /*PR-MCAL-3337*/
   ADCDig_LLD_DeInit();
#endif
  /* Initialize Group Status structures to beginning values */
  for(Group=0U; Group<CfgPtr->GroupCount; Group++)  /* GroupCount = total number of groups */
  {
    /* ADC307*/
    ADC_GroupStatus[Group].Conversion = ADC_IDLE;
    /* this group was not converted yet */
    ADC_GroupStatus[Group].AlreadyConverted = ADC_NOT_YET_CONVERTED;
  #ifdef ADC_DMA_SUPPORTED
    #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
    ADC_GroupStatus[Group].Adc_Dma_Continuous = (Adc_Dma_ContinuousType)STD_OFF;
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (((uint32)(Adc_Cfg_Ptr->Groups[Group].LastCh) -
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         (uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh >> (uint32)(2))) ==
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ((uint32)(Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount)-(uint32)1)
       )
    {
      ADC_GroupStatus[Group].Adc_Dma_Continuous = (Adc_Dma_ContinuousType)STD_ON;
    }
    #endif /* #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
  #endif /* ADC_DMA_SUPPORTED */
    ADC_GroupStatus[Group].ResultIndex = 0U;
  #if (ADC_HW_TRIGGER_API == STD_ON)
    ADC_GroupStatus[Group].HwTriggering = ADC_HWTRIGGER_DISABLED;
  #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
  /* ADC077 */
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    ADC_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
 #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    GroupIndex = (Adc_GroupType)Adc_Cfg_Ptr->Groups[Group].EnableChDisableChGroupIndex;
    if(GroupIndex != ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      Adc_NCMRx_Mask[GroupIndex].Adc_NCMR0 = Adc_Cfg_Ptr->Groups[Group].Adc_PrecisionChannel;
      /* !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      Adc_NCMRx_Mask[GroupIndex].Adc_NCMR1 = Adc_Cfg_Ptr->Groups[Group].Adc_ExtendedChannel;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      Adc_NCMRx_Mask[GroupIndex].Adc_NCMR2 = Adc_Cfg_Ptr->Groups[Group].Adc_ExternalChannel;
      #else
      Adc_NCMRx_Mask[GroupIndex].Adc_NCMR1 = (uint32)ADC_NCMR_RESET_VALUE;
      Adc_NCMRx_Mask[GroupIndex].Adc_NCMR2 = (uint32)ADC_NCMR_RESET_VALUE;
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
                (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
    }
  #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
  }
  
  /* For Bolero 3M only */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
#if (ADC_DUAL_CLOCK_MODE == STD_ON )
   Adc_ClockMode = ADC_NORMAL;
#endif
#endif
  
  #if (ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON)
    /* Initialize the global set once register to 0*/
    for(unit=0U; unit<ADC_MAX_HW_UNITS; unit++)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      Adc_LLD_OnceRegistersSet[unit] = 0U;
    }
  #endif /* (ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON) */
    /* Initialize Unit Status structures */
  for(unit = (Adc_HwUnitType)0; unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; unit++)
  {
    /* Mark the HW unit as IDLE */
    ADC_UnitStatus[unit].Status = ADC_IDLE; /* Status of the HW unit */
    ADC_UnitStatus[unit].QueueIndex = 0U;   /* Filled slots in the queue */
    /* Mark all the queue slots as "empty" */
    for(queue_index = 0U; queue_index<(uint16)Adc_Cfg_Ptr->Misc.ADC_QUEUE_MAX_DEPTH; queue_index++)
    {
      ADC_UnitStatus[unit].Queue[queue_index] = 0U;
    }

    /* SW Injected queue initialization */
    ADC_UnitStatus[unit].SwInjQueue[0] =0U;
    ADC_UnitStatus[unit].SwInjQueueIndex = 0U;   /* Filled slots in the sw injected queue */

  #if (ADC_HW_TRIGGER_API == STD_ON)
    ADC_UnitStatus[unit].HwQueue[0] =0U;
    /* Filled slots in the Hw queue */
    ADC_UnitStatus[unit].HwQueueIndex   = 0U;
   #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    /* by default consider all groups regular groups */
    ADC_UnitStatus[unit].HwQueueGroupType = ADC_REGULAR_GROUP_TYPE;
   #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
  #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    ADC_UnitStatus[unit].InjConvOngoin = (boolean)FALSE;

    if(ADC_HW_UNITS(unit) == (uint8)STD_ON)
    {
      for(HwIndex = 0U; HwIndex < (Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); HwIndex++)
      {
        /* Get the index of hardware unit in structure which will match with the hardware unit ID*/
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(ConfigPtr[HwIndex].AdcHardwareUnitId == unit)
        {
          break;
        }
      }
  #if (ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(Adc_LLD_OnceRegistersSet[unit] == 0U) /* necessary once set registers not set yet */
    {
    /* if !Pictus512_256 */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
     #if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON)
      /* set once presampling for every ADC HW unit using setting of the first group belonging to the unit */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      REG_WRITE32(ADC_PSR0_REG(unit), (ConfigPtr[HwIndex].Adc_PrecisionPsr));
      /* if !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      REG_WRITE32(ADC_PSR1_REG(unit), (ConfigPtr[HwIndex].Adc_ExtendedPsr));
      /* !Rainier and ! Calypso */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
      if (unit == (Adc_HwUnitType)ADC_UNIT_0)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        REG_WRITE32(ADC_PSR2_REG(ADC_UNIT_0), (ConfigPtr[HwIndex].Adc_ExternalPsr));
      }
      #else
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        REG_WRITE32(ADC_PSR2_REG(unit), (ConfigPtr[HwIndex].Adc_ExternalPsr));
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
                (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) */
     #endif /* ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
#if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_ON)
  #ifdef ADC_WDG_SUPPORTED
    #ifdef IPV_ADCDIG
    /* if Bolero 1.5M or Leopard or Bolero 3M (Bolero 256k-128k) or Leopard cut2 or Pictus1M or
          Komodo 2M or Leopard2M or Panther or Rainier or Calypso */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
      #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
      /* Enable the Watchdog only on configured channels */
      /* @violates @ref ADCDig_LLD_c_REF_5 expected another indexing **/
      /* @violates @ref ADCDig_LLD_c_REF_6 expected conversion between pointers to a functions **/
      REG_WRITE32(ADC_CWENR0_REG(unit), (ConfigPtr[HwIndex].Adc_Wer0));
      /* if !Leopard && !Leopard cut2 && !Komodo 2M && !Leopard2M */
        #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
            (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
        /* @violates @ref ADCDig_LLD_c_REF_5 expected another indexing **/
        /* @violates @ref ADCDig_LLD_c_REF_6 expected conversion between pointers to a functions **/
        REG_WRITE32(ADC_CWENR1_REG(unit), (ConfigPtr[HwIndex].Adc_Wer1));
        #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
        if (unit == (Adc_HwUnitType)ADC_UNIT_0) /* ADCUnit0 */
        {
            /* @violates @ref ADCDig_LLD_c_REF_5 expected another indexing **/
            /* @violates @ref ADCDig_LLD_c_REF_6 expected conversion between pointers to a functions **/
            REG_WRITE32(ADC_CWENR2_REG(unit), (ConfigPtr[HwIndex].Adc_Wer2));
        }
        #else
        /* @violates @ref ADCDig_LLD_c_REF_5 expected another indexing **/
        /* @violates @ref ADCDig_LLD_c_REF_6 expected conversion between pointers to a functions **/
        REG_WRITE32(ADC_CWENR2_REG(unit), (ConfigPtr[HwIndex].Adc_Wer2));
        #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)*/
        #endif /* if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
                     (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
      #endif /* IPV_ADCDIG_31301_PICTUS1M */
    #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
   #endif /* ifdef IPV_ADCDIG */
  #endif /* ifdef ADC_WDG_SUPPORTED */
#endif /* #if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_ON) */
    #if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON)
     /*If !Spectrum*/
      /*  Program Convertion Time*/
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      REG_WRITE32(ADC_CTR0_REG(unit),ConfigPtr[HwIndex].ConvTime);
      #ifdef IPV_ADCDIG
      /* if !Pictus512_256 */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
        #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
            (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            REG_WRITE32(ADC_CTR1_REG(unit),ConfigPtr[HwIndex].ConvTime);
        #else /* Leopard cut2 or Pictus 1M or Komodo 2M or Leopard2M or Panther or Rainier */
          #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            REG_WRITE32(ADC_CTR1_REG(unit),ConfigPtr[HwIndex].ConvTime1);
          #endif /* IPV_ADCDIG_31301_PICTUS1M */
        #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
                  (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
        #ifdef IPV_ADCDIG
            /* if Bolero 3M (Bolero 256K) or Bolero 1.5M or Rainier */
            #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
                (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
              #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
                if (unit == (Adc_HwUnitType)ADC_UNIT_3)
              #else
                if (unit == (Adc_HwUnitType)ADC_UNIT_0)
              #endif
                {
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                  REG_WRITE32(ADC_CTR2_REG(unit),ConfigPtr[HwIndex].ConvTime);
                }
            #else /* !Bolero 3M and !Bolero 1.5M */
             /* if !Leopard and !Leopard cut2 and !Pictus1M and !Komodo 2M and !Leopard2M and !Panther */
             #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
                 (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_WRITE32(ADC_CTR2_REG(unit),ConfigPtr[HwIndex].ConvTime);
             #endif /* if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
            #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
        #endif /* ifdef IPV_ADCDIG */
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
    #endif /* IPV_ADCDIG*/
    #endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_ON */
     Adc_LLD_OnceRegistersSet[unit] = 1U; /* set marker -- once registers already set */
       }
   #endif /* (if ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON) */


      /* enter into power-down mode */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
      REG_WRITE32(ADC_MCR_REG(unit),ADC_POWER_DOWN_EN);
      /* load the timeout counter */
      Timeout = ADC_TIMEOUT_COUNTER;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
      while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_STATUS) != ADC_POWERDOWN_STATUS)&&
            (Timeout > (uint32)0U))
      {
          Timeout--;
      }
      /* If the ADC hardware is not entered in power down state, report the production error */
      if ( Timeout == (uint32)0U )
      {
          /* Report production error and return from function. */
          #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
          if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
          {
             Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
          }
          #endif
          /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
          return;
      }
      /* Write the configured power down exit delay value into PDEDR register */
    #ifdef IPV_ADCDIG
      /* if Bolero 3M */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
       if (unit == (Adc_HwUnitType)ADC_UNIT_0)
       {
         /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
         REG_WRITE32(ADC_PDEDR_REG(unit),ConfigPtr[HwIndex].AdcPwrDownDelay);
       }
      #else /* !Bolero 3M */
       /*
       * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
       * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
       */
       REG_WRITE32(ADC_PDEDR_REG(unit),ConfigPtr[HwIndex].AdcPwrDownDelay);
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    #endif /* IPV_ADCDIG */

      /* comes out from PowerDown */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_POWER_DOWN);
      /* load the timeout counter */
      Timeout = ADC_TIMEOUT_COUNTER;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
      while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_STATUS) != ADC_IDLE_OFFSET_STATUS)&&
            (Timeout > (uint32)0U))
      {
          Timeout--;
      }
      /* If the ADC hardware is not entered in idle state, report the production error */
      if ( Timeout == (uint32)0U )
      {
          /* Report production error and return from function. */
          #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
          if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
          {
             Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
          }
          #endif
          /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
          return;
      }

      /* Write the configured mux delay value into DSDR register */
      /* if !Leopard && !Pictus512_256 && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
     /* if Bolero 3M or Bolero 1.5M */
     #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
         (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
       #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
       if (unit == (Adc_HwUnitType)ADC_UNIT_0)
       #else
       if (unit == (Adc_HwUnitType)ADC_UNIT_3)
       #endif
      {
        #if (ADC_MUX_DELAY_SUPPORT == STD_ON)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
        REG_WRITE32(ADC_DSDR_REG(unit),ConfigPtr[HwIndex].AdcMuxDelay);
        #else
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          REG_WRITE32(ADC_DSDR_REG(unit),0x00000000UL);
        #endif
      }
     #else /* !Bolero 3M and !Bolero1.5M */
        #if (ADC_MUX_DELAY_SUPPORT == STD_ON)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      REG_WRITE32(ADC_DSDR_REG(unit),ConfigPtr[HwIndex].AdcMuxDelay);
        #else
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          REG_WRITE32(ADC_DSDR_REG(unit),0x00000000UL);
        #endif
     #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
             (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
      /*ClkPrescaler, Auto Clock Off , Offset Refresh, Right align and overwrite */
      /*
       * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
       * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
       */
      REG_BIT_SET32(ADC_MCR_REG(unit),ConfigPtr[HwIndex].AdcMainConfig);

    /* if Leopard cut2/cut3 or Komodo 2M */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01)
     /* if !Pictus1M */
     #ifndef IPV_ADCDIG_31301_PICTUS1M
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_SET32(ADC_IMR_REG(unit), ADC_ISR_REF_RANGE_EN);
     #endif /* IPV_ADCDIG_31301_PICTUS1M */
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */

    /* Enable WatchDog Threshold Interrupt*/
    #ifdef ADC_WDG_SUPPORTED
     /* !Fado and !Pictus512_256 */
     #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
      /* if Bolero 3M */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
       if (unit == (Adc_HwUnitType)ADC_UNIT_0)
       {
         #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
           wtimrValue = ADC_WTH0_LOW_ISR_EN | ADC_WTH1_LOW_ISR_EN | ADC_WTH2_LOW_ISR_EN |
                        ADC_WTH3_LOW_ISR_EN | ADC_WTH4_LOW_ISR_EN | ADC_WTH5_LOW_ISR_EN |
                        ADC_WTH0_HIGH_ISR_EN | ADC_WTH1_HIGH_ISR_EN | ADC_WTH2_HIGH_ISR_EN |
                        ADC_WTH3_HIGH_ISR_EN | ADC_WTH4_HIGH_ISR_EN | ADC_WTH5_HIGH_ISR_EN;
         #else /* Bolero 256k-128k */
           wtimrValue = ADC_WTH0_LOW_ISR_EN | ADC_WTH1_LOW_ISR_EN | ADC_WTH2_LOW_ISR_EN |
                        ADC_WTH0_HIGH_ISR_EN | ADC_WTH1_HIGH_ISR_EN | ADC_WTH2_HIGH_ISR_EN;
         #endif /* IPV_ADCDIG_31201_BOLERO256K */
       }
       if (unit == (Adc_HwUnitType)ADC_UNIT_1)
       {
         wtimrValue = ADC_WTH0_LOW_ISR_EN | ADC_WTH1_LOW_ISR_EN | ADC_WTH2_LOW_ISR_EN |
                    ADC_WTH0_HIGH_ISR_EN | ADC_WTH1_HIGH_ISR_EN | ADC_WTH2_HIGH_ISR_EN;
       }
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
      /* if Leopard or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther or Rainier */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
       /* if !Pictus1M */
       #ifndef IPV_ADCDIG_31301_PICTUS1M
        wtimrValue = ADC_WTH0_LOW_ISR_EN | ADC_WTH1_LOW_ISR_EN | ADC_WTH2_LOW_ISR_EN |
                     ADC_WTH3_LOW_ISR_EN | ADC_WTH4_LOW_ISR_EN | ADC_WTH5_LOW_ISR_EN |
                     ADC_WTH6_LOW_ISR_EN | ADC_WTH7_LOW_ISR_EN | ADC_WTH8_LOW_ISR_EN |
                     ADC_WTH9_LOW_ISR_EN | ADC_WTH10_LOW_ISR_EN | ADC_WTH11_LOW_ISR_EN |
                     ADC_WTH12_LOW_ISR_EN | ADC_WTH13_LOW_ISR_EN | ADC_WTH14_LOW_ISR_EN |
                     ADC_WTH15_LOW_ISR_EN | ADC_WTH0_HIGH_ISR_EN | ADC_WTH1_HIGH_ISR_EN |
                     ADC_WTH2_HIGH_ISR_EN | ADC_WTH3_HIGH_ISR_EN | ADC_WTH4_HIGH_ISR_EN |
                     ADC_WTH5_HIGH_ISR_EN | ADC_WTH6_HIGH_ISR_EN | ADC_WTH7_HIGH_ISR_EN |
                     ADC_WTH8_HIGH_ISR_EN | ADC_WTH9_HIGH_ISR_EN | ADC_WTH10_HIGH_ISR_EN |
                     ADC_WTH11_HIGH_ISR_EN | ADC_WTH12_HIGH_ISR_EN | ADC_WTH13_HIGH_ISR_EN |
                     ADC_WTH14_HIGH_ISR_EN | ADC_WTH15_HIGH_ISR_EN;
       #else /* Pictus1M */
        wtimrValue = ADC_WTH0_LOW_ISR_EN | ADC_WTH1_LOW_ISR_EN | ADC_WTH2_LOW_ISR_EN |
                     ADC_WTH3_LOW_ISR_EN | ADC_WTH0_HIGH_ISR_EN | ADC_WTH1_HIGH_ISR_EN |
                     ADC_WTH2_HIGH_ISR_EN | ADC_WTH3_HIGH_ISR_EN;
       #endif /* IPV_ADCDIG_31301_PICTUS1M */
      #else
        #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
           wtimrValue = ADC_WTH0_LOW_ISR_EN | ADC_WTH1_LOW_ISR_EN | ADC_WTH2_LOW_ISR_EN |
                        ADC_WTH3_LOW_ISR_EN | ADC_WTH4_LOW_ISR_EN | ADC_WTH5_LOW_ISR_EN |
                        ADC_WTH0_HIGH_ISR_EN | ADC_WTH1_HIGH_ISR_EN | ADC_WTH2_HIGH_ISR_EN |
                        ADC_WTH3_HIGH_ISR_EN | ADC_WTH4_HIGH_ISR_EN | ADC_WTH5_HIGH_ISR_EN;
        #endif /* IPV_ADCDIG_31201_BOLERO256K */
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
     #else /* Fado or Pictus512_256 */
      wtimrValue = ADC_WTH0_LOW_ISR_EN | ADC_WTH1_LOW_ISR_EN | ADC_WTH2_LOW_ISR_EN |
                   ADC_WTH3_LOW_ISR_EN | ADC_WTH0_HIGH_ISR_EN | ADC_WTH1_HIGH_ISR_EN |
                   ADC_WTH2_HIGH_ISR_EN | ADC_WTH3_HIGH_ISR_EN;
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)&&(IPV_ADCDIG != IPV_ADCDIG_00_01_06_01*/
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
     REG_BIT_SET32(ADC_WTIMR_REG(unit), wtimrValue);
    #endif /* ADC_WDG_SUPPORTED */
      /* presampling related configurations/initializations */
      {
    #ifdef IPV_ADCDIG
     /* if !Pictus512_256 */
     #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) && (!defined(IPV_ADCDIG_31301_PICTUS1M)) && \
          (!defined(IPV_ADCDIG_31301_KOMODO2M))
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      VAR(uint32, AUTOMATIC) pscrVal = (uint32) ( ((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal0)<< (uint32)1) | \
                                                  (uint32)Adc_Cfg_Ptr->ADC[HwIndex].PreConv );
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      pscrVal |= (uint32) ( ((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal1)<< (uint32)3));
      #elif (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) /* Rainier of Calypso */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      VAR(uint32, AUTOMATIC) pscrVal = (uint32)(((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal0)<<(uint32)1)|
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                                                 (uint32)Adc_Cfg_Ptr->ADC[HwIndex].PreConv);
      #else
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      VAR(uint32, AUTOMATIC) pscrVal = (uint32)(((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal)<<(uint32)1)|
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                                                 (uint32)Adc_Cfg_Ptr->ADC[HwIndex].PreConv);
      #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) && (!defined(IPV_ADCDIG_31301_PICTUS1M)) && \
          (!defined(IPV_ADCDIG_31301_KOMODO2M)) */
     /* if !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther && !Rainier && !Calypso */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
        pscrVal |= ((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal)<< (uint32)3); /* int. extended chs */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
        pscrVal |= ((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal)<< (uint32)5); /* external channels */
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) &&
                (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
      /* Rainier or Calypso */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
        pscrVal |= ((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal1)<< (uint32)3); /* int. extended chs */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
        pscrVal |= ((uint32)(Adc_Cfg_Ptr->ADC[HwIndex].PreVal2)<< (uint32)5); /* external channels */
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||(IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
                
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(ADC_PSCR_REG(unit), pscrVal);
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
    #endif /* IPV_ADCDIG */
      }
    /* if Bolero or Fado  */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01)
        /* activate the CTU control mode in ADC HW unit */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_MCR_REG(unit), ADC_CTU_ENABLED);
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) */
    }
  }

#ifdef ADC_WDG_SUPPORTED
  for(ch=(Adc_ChannelType)0U;ch<(Adc_ChannelType)(Adc_Cfg_Ptr->Misc.ADC_CHANNELS[0]); ch++)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues !=ADC_UNUSED_THRESHOLD)
    {
    /* if Bolero 512K or Fado or Pictus512_256 or Pictus1M  */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || defined(IPV_ADCDIG_31301_PICTUS1M)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      REG_WRITE32(ADC_TRCx_REG(ADC_UNIT_0, Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg), \
                                           Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThCtrl);
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || defined(IPV_ADCDIG_31301_PICTUS1M) */
    #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if((Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg <= ADC_THRESHOLD_REG_3))
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_THRHLRx_REG(ADC_UNIT_0, Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg),
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
      }
    #else /* Bolero 256k-128k */
        /* @violates @ref ADCDig_LLD_c_REF_5 expected another indexing **/
       if((Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg <= ADC_THRESHOLD_REG_2))
        {
          REG_WRITE32(ADC_THRHLRx_REG(ADC_UNIT_0, Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg),
                      /* @violates @ref ADCDig_LLD_c_REF_6 expected conversion between pointers to a functions **/
                      /* @violates @ref ADCDig_LLD_c_REF_5 expected another indexing **/
                      Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
        }
    #endif /* IPV_ADCDIG_31201_BOLERO256K */
      else
      {
      /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther or Calypso */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
          (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
        #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
        /* if !Pictus1M */
        #ifndef IPV_ADCDIG_31301_PICTUS1M
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_4)
          {
            /*
            * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
            * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            */
            REG_WRITE32(ADC_THRHLR4_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
          }
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_5)
          {
            /*
            * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
            */
            REG_WRITE32(ADC_THRHLR5_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
          }
          else
          {
          /* if Leopard or Leopard cut2/cut3 or Komodo 2M or Panther */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_6)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR6_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_7)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR7_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_8)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR8_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_9)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR9_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_10)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR10_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_11)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR11_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_12)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR12_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_13)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR13_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_14)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR14_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThReg == ADC_THRESHOLD_REG_15)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR15_REG(ADC_UNIT_0),Adc_Cfg_Ptr->Channels[ADC_UNIT_0][ch].ThValues);
            }
            else
            {
            /* never here: Misra check. */
            }
          #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */
          }
        #endif /* IPV_ADCDIG_31301_PICTUS1M */
        #endif /* IPV_ADCDIG_31201_BOLERO256K */
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
      }
    }
  }
#endif /* ADC_WDG_SUPPORTED */

#ifdef IPV_ADCDIG
 /*if Bolero 1.5M or Leopard or Bolero 3M or Pictus512_256 or Leopard cut2/cut3 or Pictus 1M or 
      Komodo 2M or Panther or Rainier or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* if !Pictus1M */
  #ifndef IPV_ADCDIG_31301_PICTUS1M
    #ifdef ADC_WDG_SUPPORTED
    for(ch=(Adc_ChannelType)0U;ch <(Adc_ChannelType)(Adc_Cfg_Ptr->Misc.ADC_CHANNELS[1]); ch++)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues !=ADC_UNUSED_THRESHOLD)
      {
      /* if Pictus512_256  */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        REG_WRITE32(ADC_TRCx_REG(ADC_UNIT_1, Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg), \
                                             Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThCtrl);
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01)*/
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg <= ADC_THRESHOLD_REG_3))
        {
            /*
            * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
            */
            REG_WRITE32(ADC_THRHLRx_REG(ADC_UNIT_1, Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
        }
        else
        {
        /* if Leopard or Leopard cut2/cut3 or Komodo 2M or Panther or Calypso */
        #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_4)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR4_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_5)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR5_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* If !Calypso */
         #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_6)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR6_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_7)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR7_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_8)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR8_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_9)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR9_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_10)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR10_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_11)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR11_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_12)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR12_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_13)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR13_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_14)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR14_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThReg == ADC_THRESHOLD_REG_15)
         {
           /*
           * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
           * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
           */
           REG_WRITE32(ADC_THRHLR15_REG(ADC_UNIT_1), Adc_Cfg_Ptr->Channels[ADC_UNIT_1][ch].ThValues);
         }
         #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
         else
         {
           /* never here: Misra check. */
         }
        #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
        }
      }
    }
    /* if Komodo 2M or Panther or Rainier */
    #if defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
    for(ch=(Adc_ChannelType)0U;ch <(Adc_ChannelType)(Adc_Cfg_Ptr->Misc.ADC_CHANNELS[2]); ch++)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues !=ADC_UNUSED_THRESHOLD)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg <= ADC_THRESHOLD_REG_3))
        {
            /*
            * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
            */
            REG_WRITE32(ADC_THRHLRx_REG(ADC_UNIT_2, Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
        }
        else
        {
            /* if !Rainier */
            #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_4)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR4_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_5)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR5_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_6)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR6_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_7)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR7_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_8)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR8_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_9)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR9_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_10)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR10_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_11)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR11_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_12)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR12_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_13)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR13_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_14)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR14_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThReg == ADC_THRESHOLD_REG_15)
            {
              /*
              * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
              * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
              */
              REG_WRITE32(ADC_THRHLR15_REG(ADC_UNIT_2), Adc_Cfg_Ptr->Channels[ADC_UNIT_2][ch].ThValues);
            }
            else
            {
              /* never here: Misra check. */
            }
            #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) */
        }
      }
    }
    for(ch=(Adc_ChannelType)0U;ch <(Adc_ChannelType)(Adc_Cfg_Ptr->Misc.ADC_CHANNELS[3]); ch++)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues !=ADC_UNUSED_THRESHOLD)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg <= ADC_THRESHOLD_REG_3))
        {
            /*
            * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
            */
            REG_WRITE32(ADC_THRHLRx_REG(ADC_UNIT_3, Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        else
        {
        /* if !Rainier */
        #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_4)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR4_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_5)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR5_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_6)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR6_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_7)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR7_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_8)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR8_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_9)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR9_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_10)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR10_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_11)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR11_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_12)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR12_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_13)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR13_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_14)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR14_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if(Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThReg == ADC_THRESHOLD_REG_15)
        {
          /*
          * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
          * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
          */
          REG_WRITE32(ADC_THRHLR15_REG(ADC_UNIT_3), Adc_Cfg_Ptr->Channels[ADC_UNIT_3][ch].ThValues);
        }
        else
        {
          /* never here: Misra check. */
        }
        #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) */
        }
      }
    }
    #endif /* defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
    #endif /* #ifdef ADC_WDG_SUPPORTED */
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
  #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */

  /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2/cut3 or Pictus 1M or Komodo 2M or Panther 
        or Rainier or Calypso */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
   /* if !Pictus1M */
   #ifndef IPV_ADCDIG_31301_PICTUS1M
    #ifdef ADC_WDG_SUPPORTED
    for(unit = (Adc_HwUnitType)0; unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; unit++)
    {
     for(ch=(Adc_ChannelType)0U;ch <(Adc_ChannelType)(Adc_Cfg_Ptr->Misc.ADC_CHANNELS[unit]); ch++)
     {
      /* update the CWSEL register only for the enabled channels */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if(Adc_Cfg_Ptr->Channels[unit][ch].ThValues != ADC_UNUSED_THRESHOLD)
      {
        /* program the CWSEL register (channel watchdog select register) */
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        * @violates @ref Adc_ADCDig_LLD_c_REF_12 place reliance on undefined or unspecified behavior
        * @violates @ref Adc_ADCDig_LLD_c_REF_13 contain side effects of right-hand operand
        * @violates @ref Adc_ADCDig_LLD_c_REF_16 if else-if constructs not terminated by else
        */
        ADC_SET_THRESHOLDS(unit, (uint32)Adc_Cfg_Ptr->Channels[unit][ch].ThReg, (Adc_ChannelType)Adc_Cfg_Ptr->Channels[unit][ch].ChId);
      }
      /* initialize channel descriptions for the WDG ISR */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      ADC_LLD_WdgChannelDescRegIndex[unit][ch]=(uint8)CfgPtr->Channels[unit][ch].ChId/(uint8)32;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      ADC_LLD_WdgChannelDescMask[unit][ch]=((uint32)1<<(uint32)(CfgPtr->Channels[unit][ch].ChId%(uint32)32));
     }
    }
    #endif /* ADC_WDG_SUPPORTED */
   #endif /* IPV_ADCDIG_31301_PICTUS1M */
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

 /* If there are MHT then setup the relation between the physical channels and groups  */
 #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
   for(unit = (Adc_HwUnitType)0; unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; unit++)
   {
    VAR(Adc_GroupType, AUTOMATIC) gr = (Adc_GroupType)0;
    VAR(uint8, AUTOMATIC) ChIndex = (uint8)0;
    VAR(uint8, AUTOMATIC) posGr = (uint8)0;
    for(gr=(Adc_GroupType)0U;gr <  (CfgPtr->Misc.ADC_GROUPS[unit]); gr++)
    {
     /* CfgPtr->Groups[gr].Assignment[0] - logical index to use in Adc_Channels_Cfg vector...) */
     /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
     ChIndex = CfgPtr->Groups[gr].Assignment[0];
     /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
     if (CfgPtr->Groups[gr].IsMHTGroup == ADC_MHT_GROUP_TYPE)
     {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      Adc_LLD_MhtChannelGroup[unit][posGr].chId=(Adc_ChannelType)CfgPtr->Channels[unit][ChIndex].ChId;
      Adc_LLD_MhtChannelGroup[unit][posGr].grId=(Adc_GroupType)gr;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      Adc_LLD_MhtChannelGroup[unit][posGr].register_index=(uint8)CfgPtr->Channels[unit][ChIndex].ChId/(uint8)32;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      Adc_LLD_MhtChannelGroup[unit][posGr].mask=((uint32)1<<(uint32)(CfgPtr->Channels[unit][ChIndex].ChId%(uint32)32));
      posGr++;
     }
    }
   }
 #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

/* Leopard and Pictus CTU related initializations */
/* if Leopard or Pictus512_256 or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
  #if (ADC_ENABLE_CTUV2 == STD_ON)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_11 cast from integer type to a other type or a wider integer type */
    if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_CTUV2 == (uint8)STD_ON)
    {
        CTUV2_LLD_Init (CfgPtr->CTUCfgPtr); /* Initialize the CTUV2 hardware */
        CTUV2_LLD_SetupDMA(); /* Also setup the DMA Transfer Descriptors */
    }
  #endif /* (ADC_ENABLE_CTUV2 == STD_ON) */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */

/* Rainier BCTU related initializations */
/* if Rainier or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  #if (ADC_ENABLE_BCTU == STD_ON)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_11 cast from integer type to a other type or a wider integer type */
    if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_BCTU == (uint8)STD_ON)
    {
        BCTU_LLD_Init(CfgPtr->BCTUCfgPtr); /* Initialize the BCTU hardware */
        BCTU_LLD_SetupDMA();  /* Also setup the DMA Transfer Descriptors */
    }
  #endif /* (ADC_ENABLE_BCTU == STD_ON) */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG */
}

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          This function deinitializes the ADC driver, and the ADC hardware.
* @details        This function deinitializes the ADC driver, and ensures that the ADC hardware
*                 will be in the power on after reset state.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_DeInit(void)
{
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(uint8,AUTOMATIC) group_index = (uint8)0;
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    VAR(Adc_HwUnitType, AUTOMATIC) unit=(Adc_HwUnitType)0; /* Hardware unit index */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
  VAR(Adc_GroupType, AUTOMATIC) GroupIndex = (Adc_GroupType)0; /* Enable/Disable channel Group Index */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

    /* enter critical region to avoid ISRs during register reset */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();
    for(;unit<(Adc_HwUnitType)ADC_MAX_HW_UNITS;unit++)
    {  /* ADC111-- ADC110*/
        if(ADC_HW_UNITS(unit) == (uint8)STD_ON)
        {
        #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
            /* Enter ADC unit to power down mode */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_BIT_SET32(ADC_MCR_REG(unit), ADC_POWER_DOWN);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_MCR_REG(unit), ADC_MCR_RESET_VALUE);
        #else
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_MCR_REG(unit), ADC_MCR_RESET_VALUE);
        #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_IMR_REG(unit), ADC_IMR_RESET_VALUE);
        #ifdef IPV_ADCDIG
         /* !Pictus512_256 */
         #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
          /* if !Pictus1M */
          #ifndef IPV_ADCDIG_31301_PICTUS1M
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_CIMR0_REG(unit), ADC_CIMR_RESET_VALUE);
           /* if !Leopard && !Leopard cut2/cut3 && !Komodo 2M && !Panther */
           #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
               (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_CIMR1_REG(unit), ADC_CIMR_RESET_VALUE);
            /* if Bolero 3M or Bolero 1.5M */
            #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
             if (unit == (Adc_HwUnitType)ADC_UNIT_0)
             {
               /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
               REG_WRITE32(ADC_CIMR2_REG(unit), ADC_CIMR_RESET_VALUE);
             }
            #else /* !Bolero 3M and !Bolero1.5M */
             /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
             REG_WRITE32(ADC_CIMR2_REG(unit), ADC_CIMR_RESET_VALUE);
            #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                      (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
           #endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
                         (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) */
          #endif /* IPV_ADCDIG_31301_PICTUS1M */
         #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
        #endif /* IPV_ADCDIG */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_WTISR_REG(unit), ADC_WTISR_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_WTIMR_REG(unit), ADC_WTIMR_RESET_VALUE);
        #ifdef ADC_DMA_SUPPORTED
        if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA)
        {
            /* Disable DMA interrupt */
            Dma_disable_interrupt((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[unit]);
        }
        #endif /* ifdef ADC_DMA_SUPPORTED */
        #ifdef IPV_ADCDIG
         /* if Bolero 1.5M or Leopard or Fado or Bolero 3M or
               Pictus512_256 or Leopard cut2/cut3 or Pictus1M or Komodo 2M  or Panther or Rainier or Calypso */
         #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
             (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
             (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
             (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
             (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
                REG_WRITE32(ADC_DMAE_REG(unit), ADC_DMAE_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
                REG_WRITE32(ADC_DMAR0_REG(unit), ADC_DMAR_RESET_VALUE);
              /* if !Leopard && Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
              #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
                  (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
               /* if !Pictus512_256 */
               #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_DMAR1_REG(unit), ADC_DMAR_RESET_VALUE);
                /* if Bolero 3M or Bolero 1.5M */
                #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
                if (unit == (Adc_HwUnitType)ADC_UNIT_0)
                {
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                  REG_WRITE32(ADC_DMAR2_REG(unit), ADC_DMAR_RESET_VALUE);
                }
                #else /* !Bolero 3M and !Bolero 1.5M */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_DMAR2_REG(unit), ADC_DMAR_RESET_VALUE);
                #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                          (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
               #endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
              #endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
                            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) */
         #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                   (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                   (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || 
                   (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
                   (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
        #endif /* IPV_ADCDIG */

        /* if Bolero 512K or Fado or Pictus512_256 or Pictus1M or Komodo 2M */
        #if (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || defined(IPV_ADCDIG_31301_PICTUS1M)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_TRC0_REG(unit), ADC_TRC0_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_TRC1_REG(unit), ADC_TRC1_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_TRC2_REG(unit), ADC_TRC2_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_TRC3_REG(unit), ADC_TRC3_RESET_VALUE);
        #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
                  defined(IPV_ADCDIG_31301_PICTUS1M) */

        #ifdef ADC_WDG_SUPPORTED
          /* If Calypso */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR0_REG(unit), ADC_THRHLR_RESET_VALUE(unit));
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR1_REG(unit), ADC_THRHLR_RESET_VALUE(unit));
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR2_REG(unit), ADC_THRHLR_RESET_VALUE(unit));
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR3_REG(unit), ADC_THRHLR_RESET_VALUE(unit));
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR4_REG(unit), ADC_THRHLR_RESET_VALUE(unit));
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR5_REG(unit), ADC_THRHLR_RESET_VALUE(unit));
          #else
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR0_REG(unit), ADC_THRHLR0_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR1_REG(unit), ADC_THRHLR1_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_THRHLR2_REG(unit), ADC_THRHLR2_RESET_VALUE);
            /* For Hardware unit 0 */
            #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
            if(unit == (Adc_HwUnitType)ADC_UNIT_0)
            {
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR3_REG(unit), ADC_THRHLR3_RESET_VALUE);
            }
            #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
          /* if Pictus512_256 or Leopard or Leopard cut2 or Pictus 1M or Komodo 2M or Panther or Rainier */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
            /* if !Pictus1M */
            #ifndef IPV_ADCDIG_31301_PICTUS1M
            if(unit == (Adc_HwUnitType)ADC_UNIT_1)
            {
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR3_REG(unit), ADC_THRHLR3_RESET_VALUE);
            }
            #endif /* IPV_ADCDIG_31301_PICTUS1M */
            /* if Komodo 2M or Panther or Rainier */
            #if defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
                (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
            if(unit == (Adc_HwUnitType)ADC_UNIT_2)
            {
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR3_REG(unit), ADC_THRHLR3_RESET_VALUE);
            }
            if(unit == (Adc_HwUnitType)ADC_UNIT_3)
            {
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR3_REG(unit), ADC_THRHLR3_RESET_VALUE);
            }
            #endif /* defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                      (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) */
          #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) */
          /* if Pictus512_256 or Leopard or Leopard cut2 or Pictus 1M or Komodo 2M */
          /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2 or Pictus 1M or Komodo 2M or Panther or Calypso */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||\
              (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||\
              (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
            /* if !Pictus1M */
            #ifndef IPV_ADCDIG_31301_PICTUS1M
             #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
             /* Bolero 1.5M or Bolero 3M */
             #if ((IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01))
              if(unit == (Adc_HwUnitType)ADC_UNIT_0)
              {
               /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
               REG_WRITE32(ADC_THRHLR4_REG(unit), ADC_THRHLR4_RESET_VALUE);
               /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
               REG_WRITE32(ADC_THRHLR5_REG(unit), ADC_THRHLR5_RESET_VALUE);
              }
             #else
               /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
               REG_WRITE32(ADC_THRHLR4_REG(unit), ADC_THRHLR4_RESET_VALUE);
               /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
               REG_WRITE32(ADC_THRHLR5_REG(unit), ADC_THRHLR5_RESET_VALUE);
             #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)) */
             #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
            #endif /* IPV_ADCDIG_31301_PICTUS1M */
          #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
          /* if Leopard or Leopard cut2/cut3 or Pictus 1M or Komodo 2M or Panther */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||\
              (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
            /* if !Pictus1M */
            #ifndef IPV_ADCDIG_31301_PICTUS1M
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR6_REG(unit), ADC_THRHLR6_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR7_REG(unit), ADC_THRHLR7_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR8_REG(unit), ADC_THRHLR8_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR9_REG(unit), ADC_THRHLR9_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR10_REG(unit), ADC_THRHLR10_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR11_REG(unit), ADC_THRHLR11_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR12_REG(unit), ADC_THRHLR12_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR13_REG(unit), ADC_THRHLR13_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR14_REG(unit), ADC_THRHLR14_RESET_VALUE);
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_THRHLR15_REG(unit), ADC_THRHLR15_RESET_VALUE);
            #endif /* IPV_ADCDIG_31301_PICTUS1M */
          #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
          #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
        #endif /* ADC_WDG_SUPPORTED */

        #ifdef IPV_ADCDIG
          /* if !Pictus512_256 */
          #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            ADC_CLEAN_CHANNEL_PENDING_REGS(unit);
          #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
        #endif /* IPV_ADCDIG */
        /* if !Pictus512_256 */
        #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_PSCR_REG(unit), 0x0UL);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(ADC_PSR0_REG(unit), 0x0UL);
           /* if !Leopard && !Leopard cut2 && !Pictus1M && !Komodo 2M && !Panther */
           #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&\
               (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_PSR1_REG(unit), 0x0UL);
            /* if Bolero 3M or Bolero 1.5M */
            #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
            if (unit == (Adc_HwUnitType)ADC_UNIT_0)
            {
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_WRITE32(ADC_PSR2_REG(unit), 0x0UL);
            }
            #else /* !Bolero 3M and !Bolero 1.5M */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_PSR2_REG(unit), 0x0UL);
            #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
           #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                     (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
        #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_CTR0_REG(unit), ADC_CTR0_RESET_VALUE);

        #ifdef IPV_ADCDIG
         /* if !Pictus512_256 */
         #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
          /* if !Pictus1M */
          #ifndef IPV_ADCDIG_31301_PICTUS1M
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_CTR1_REG(unit), ADC_CTR1_RESET_VALUE);
          #endif /* IPV_ADCDIG_31301_PICTUS1M */
          /* if Bolero 3M or Bolero 1.5M or Rainier */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
            #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
            if (unit == (Adc_HwUnitType)ADC_UNIT_3)
            #else
            if (unit == (Adc_HwUnitType)ADC_UNIT_0)
            #endif
            {
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_WRITE32(ADC_CTR2_REG(unit), ADC_CTR2_RESET_VALUE);
            }
          #else /* !Bolero 3M and !Bolero1.5M */
          /* if !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
            #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&\
                (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_WRITE32(ADC_CTR2_REG(unit), ADC_CTR2_RESET_VALUE);
            #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                      (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                      (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
          #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
         #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
        #endif /* IPV_ADCDIG */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_NCMR0_REG(unit), ADC_NCMR_RESET_VALUE);
        #ifdef IPV_ADCDIG
        /* if !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
         #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
             (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_NCMR1_REG(unit), ADC_NCMR_RESET_VALUE);
            /* if Bolero 3M or Bolero 1.5M */
            #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
            if (unit == (Adc_HwUnitType)ADC_UNIT_0)
            {
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_WRITE32(ADC_NCMR2_REG(unit), ADC_NCMR_RESET_VALUE);
            }
            #else /* !Bolero 3M and !Bolero 1.5M */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_NCMR2_REG(unit), ADC_NCMR_RESET_VALUE);
            #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
         #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                   (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
        #endif /* IPV_ADCDIG */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_JCMR0_REG(unit), ADC_JCMR_RESET_VALUE);
        #ifdef IPV_ADCDIG
         /* if !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
         #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
         (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_JCMR1_REG(unit), ADC_JCMR_RESET_VALUE);
            /* if Bolero 3M or Bolero 1.5M */
            #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
            if (unit == (Adc_HwUnitType)ADC_UNIT_0)
            {
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_WRITE32(ADC_JCMR2_REG(unit), ADC_JCMR_RESET_VALUE);
            }
            #else /* !Bolero 3M and !Bolero 1.5M */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_JCMR2_REG(unit), ADC_JCMR_RESET_VALUE);
            #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
          #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                    (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
        #endif /* IPV_ADCDIG*/

        #if (ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_LLD_OnceRegistersSet[unit] = 0U;
        #endif /* ADC_SET_ONCE_REGISTERS_SUPPORTED == STD_ON */

        #ifdef ADC_WDG_SUPPORTED
         #ifdef IPV_ADCDIG
         /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2/cut3 or Pictus1M or Komodo 2M 
            or Panther or Rainier or Calypso */
            #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
                (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
                (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
                (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
                /* if !Pictus1M */
                #ifndef IPV_ADCDIG_31301_PICTUS1M
                    /* watchdog registers */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                    REG_WRITE32(ADC_CWENR0_REG(unit), ADC_CWENR_RESET_VALUE);
                    /* if !Leopard && !Leopard cut2/cut3 && !Komodo 2M && !Panther */
                    #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
                        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
                        (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                    REG_WRITE32(ADC_CWENR1_REG(unit), ADC_CWENR_RESET_VALUE);
                    /* if Bolero 3M or Bolero 1.5M */
                     #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
                         (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
                     if (unit == (Adc_HwUnitType)ADC_UNIT_0)
                     {
                       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                       REG_WRITE32(ADC_CWENR2_REG(unit), ADC_CWENR_RESET_VALUE);
                     }
                     #else /* !Bolero 3M and !Bolero 1.5M */
                       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                       REG_WRITE32(ADC_CWENR2_REG(unit), ADC_CWENR_RESET_VALUE);
                     #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                               (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
                    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                              (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                              (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                    REG_WRITE32(ADC_CWSEL0_REG(unit), ADC_CWSEL_RESET_VALUE);
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                    REG_WRITE32(ADC_CWSEL1_REG(unit), ADC_CWSEL_RESET_VALUE);
                    /* if !Leopard && !Leopard cut2/cut3 && !Komodo 2M && !Panther*/
                    #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
                        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
                        (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                      REG_WRITE32(ADC_CWSEL4_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* Bolero 1.5M or Bolero 3M */
                     #if ((IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
                          (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01))
                     if (unit == (Adc_HwUnitType)ADC_UNIT_0)
                     {
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL5_REG(unit), ADC_CWSEL_RESET_VALUE);
                        #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL6_REG(unit), ADC_CWSEL_RESET_VALUE);
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL7_REG(unit), ADC_CWSEL_RESET_VALUE);
                        #endif /* IPV_ADCDIG_31201_BOLERO256K */
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL8_REG(unit), ADC_CWSEL_RESET_VALUE);
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL9_REG(unit), ADC_CWSEL_RESET_VALUE);
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL10_REG(unit), ADC_CWSEL_RESET_VALUE);
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL11_REG(unit), ADC_CWSEL_RESET_VALUE);
                     }
                     /* Bolero 3M */
                     #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
                     if (unit == (Adc_HwUnitType)ADC_UNIT_1)
                     {
                        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                        REG_WRITE32(ADC_CWSEL5_REG(unit), ADC_CWSEL_RESET_VALUE);
                     }
                     #endif
                     #else /* !Bolero 1.5M  && !Bolero 3M */
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL5_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL6_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL7_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL8_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL9_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL10_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL11_REG(unit), ADC_CWSEL_RESET_VALUE);
                     /* Rainier or Calypso */
                     #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
                     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                     REG_WRITE32(ADC_CWSEL2_REG(unit), ADC_CWSEL_RESET_VALUE);
                     #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
                     #endif /* ((IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
                                (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)) */
                    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                              (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                              (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
                #endif /* IPV_ADCDIG_31301_PICTUS1M */
                #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                              (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
                              (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
                              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
            #endif /* #ifdef IPV_ADCDIG */
        #endif /* #ifdef ADC_WDG_SUPPORTED */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_PDEDR_REG(unit), ADC_PDEDR_RESET_VALUE);
            ADC_UnitStatus[unit].InjConvOngoin = (boolean)FALSE;
        }
    }

#if (ADC_HW_TRIGGER_API == STD_ON)
    #ifdef IPV_ADCDIG
        /* if Bolero or Fado */
        #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
            /* calling with false, it actually resets the TRGIEN flag of the CTU_CSR register */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            CTU_LLD_Init_FALSE();
            /* clear the interrupt flag */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            CTU_LLD_ClearTRGI();
            /* reset all CTU_EVTCFGRx registers */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            CTU_LLD_ResetEvtCfgRegs();
         /* if Fado */
         #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
            /* No division for the counter clock */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            CTU_LLD_ResetPrescalerBits()
            /* reset all CTU_SVRx registers */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            CTU_LLD_ResetSvrRegs()
         #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
            for(;unit<(Adc_HwUnitType)ADC_MAX_HW_UNITS;unit++)
            {  /* ADC111-- ADC110*/
              if(ADC_HW_UNITS(unit) == (uint8)STD_ON)
              {
                /* de-activate the CTU control mode in ADC HW unit */
                /* @violates @ref ADCDig_LLD_c_REF_3 cast from unsigned long to pointer */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CTU_ENABLED);
              }
            }
        #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

        /* CTUv2 on Leopard or Pictus512_256 or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther */
        #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
            #if (ADC_ENABLE_CTUV2 == STD_ON)
                if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_CTUV2 == (uint8)STD_ON)
                {
                    CTUV2_LLD_DeInit();
                }
            #endif /* (ADC_ENABLE_CTUV2 == STD_ON) */
        #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
                  (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */

        /* Rainier or Calypso */
        #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
            #if (ADC_ENABLE_BCTU == STD_ON)
                if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_BCTU == (uint8)STD_ON)
                {
                    BCTU_LLD_DeInit();
                }
            #endif /* (ADC_ENABLE_BCTU == STD_ON) */
        #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
    #endif /* IPV_ADCDIG */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    for(group_index=(uint8)0U;group_index<(uint8)ADC_MAX_GROUPS;group_index++)
    {
       /* ADC 111*/
        ADC_GroupStatus[group_index].Notification = ADC_NOTIFICATION_DISABLED;
        #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        GroupIndex = (Adc_GroupType)Adc_Cfg_Ptr->Groups[group_index].EnableChDisableChGroupIndex;
        if(GroupIndex != ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX)
        {
          Adc_NCMRx_Mask[GroupIndex].Adc_NCMR0 = (uint32)ADC_NCMR_RESET_VALUE;
          Adc_NCMRx_Mask[GroupIndex].Adc_NCMR1 = (uint32)ADC_NCMR_RESET_VALUE;
          Adc_NCMRx_Mask[GroupIndex].Adc_NCMR2 = (uint32)ADC_NCMR_RESET_VALUE;
        }
        #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    }
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

     /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
    
}
#endif /* #if (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief          This function starts the group conversion.
* @details        This function starts the group conversion.
*
* @param[in]      Group       The group of which conversion will be started.
* @param[in]      unit        The hardware unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_StartGroupConversion
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
  /* Priority of the requested Group */
  VAR(Adc_GroupPriorityType, AUTOMATIC) gPri = (Adc_GroupPriorityType)0;
  /* Temporary index in the Queue */
  VAR(Adc_QueueIndexType, AUTOMATIC) p = (Adc_QueueIndexType)0;
  /* Position of the new Group in the Queue */
  VAR(Adc_QueueIndexType, AUTOMATIC) pos = 0U;
  VAR(uint32, AUTOMATIC) Timeout;
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
#if (ADC_ENABLE_QUEUING == STD_ON)
  /* First available slot in the Queue */
  VAR(Adc_QueueIndexType, AUTOMATIC) qPtr = (Adc_QueueIndexType)0;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0016)
  VAR(boolean, AUTOMATIC) ConversionOnGoing = (boolean)FALSE;
#endif
  /* enter critical region to work on queue, DMA, ADC registers */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_07();
  /* Mark the Group as BUSY when the Group goes to the Queue or gets started */
  ADC_GroupStatus[Group].Conversion = ADC_BUSY;

/* if Bolero 1.5M or Bolero 512K or Leopard cut2/cut3 (Pictus 1M) or Fado or Pictus 512k_256k or
      Komodo 2M  or Bolero 3M (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* In this case injected conversion is ongoing */
  #if (STD_ON==ADC_HW_TRIGGER_API)
  /* SW Injected conversions should be entertained only if there are no other
     HW or CTU injected chains enabled, otherwise the SW Injected may be aborted
     (MSR.JABORT will be set) and no interrupt will be issued */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
  if (((ADC_UnitStatus[unit].SwInjQueueIndex != (Adc_QueueIndexType)0)&&(Adc_Cfg_Ptr->Groups[Group].type != (Adc_GroupConvType)ADC_CONV_TYPE_NORMAL)) || \
      ((Adc_Cfg_Ptr->Groups[Group].type == (Adc_GroupConvType)ADC_CONV_TYPE_INJECTED) && \
       (ADC_UnitStatus[unit].HwQueueIndex != (Adc_QueueIndexType)0)))
  #else
  if ((ADC_UnitStatus[unit].SwInjQueueIndex != (Adc_QueueIndexType)0) &&
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      (Adc_Cfg_Ptr->Groups[Group].type != (Adc_GroupConvType)ADC_CONV_TYPE_NORMAL))
  #endif /* #if (STD_ON==ADC_HW_TRIGGER_API) */
  {
    /* Return the Group status as IDLE */
    ADC_GroupStatus[Group].Conversion = ADC_IDLE;
    /* error occured, exit critical section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();
    /* (ADC346, ADC426)*/
    #if (ADC_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError((uint16)ADC_MODULE_ID,
                      (uint8)0U,
                      (uint8)ADC_STARTGROUPCONVERSION_ID,
                      (uint8)ADC_E_BUSY);
    #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return;
  }
  /* Injected conversion mode */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  if (Adc_Cfg_Ptr->Groups[Group].type == (Adc_GroupConvType)ADC_CONV_TYPE_INJECTED)
  {
    /* Place the Group in the SW Inj Queue */
    ADC_UnitStatus[unit].SwInjQueue[0] = Group;
    /* Increase the Queue Index */
    ADC_UnitStatus[unit].SwInjQueueIndex++;
#if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_OFF)
 #ifdef ADC_WDG_SUPPORTED
  #ifdef IPV_ADCDIG
   /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2/cut3 or Pictus1M or Komodo 2M 
      or Panther or Rainier or Calypso */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* if !Pictus1M */
    #ifndef IPV_ADCDIG_31301_PICTUS1M
    /* Enable the Watchdog only on configured channels */
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    */
    REG_WRITE32(ADC_CWENR0_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer0));
    /* if !Leopard && !Leopard cut2/cut3 && !Komodo 2M && !Panther */
     #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
         (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
     /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
     REG_WRITE32(ADC_CWENR1_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer1));
     #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
     if (unit == (Adc_HwUnitType)ADC_UNIT_0) /* ADCUnit0 */
     {
       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
       REG_WRITE32(ADC_CWENR2_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer2));
     }
     #else
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
       REG_WRITE32(ADC_CWENR2_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer2));
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)*/
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
               (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
    #endif /* IPV_ADCDIG_31301_PICTUS1M */
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
  #endif /* IPV_ADCDIG */
 #endif /* ADC_WDG_SUPPORTED */
#endif /* #if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_OFF) */
   ADCDig_LLD_StartInjectedConversion((Adc_HwUnitType)unit);
  /* exit critical region */
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();
  }
  else
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
  {

#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) /* ADC311 -- ADC340 -- ADC332 -- ADC417*/
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  gPri = ADC_GroupPriority(Group);
  qPtr = ADC_UnitStatus[unit].QueueIndex;

  if (qPtr > (Adc_QueueIndexType)0U)
  {
#if (STD_ON==ADC_HW_TRIGGER_API)
    if (((ADC_UnitStatus[unit].SwInjQueueIndex != (Adc_QueueIndexType)0)||(ADC_UnitStatus[unit].HwQueueIndex != (Adc_QueueIndexType)0))&& 
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_13 contain side effects of right-hand operand */
    (((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING))
#else
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_13 contain side effects of right-hand operand */
    if (((ADC_UnitStatus[unit].SwInjQueueIndex != (Adc_QueueIndexType)0))&&(((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING))
#endif         
    {
        /*An Injected  HW/SW conversion is ongoing and a normal conversion is suspended */
        /*At the end of the injected conversion, the normal conversion will be resumed  */  
        /*so don't update the Group in position 0 in ADC_UnitStatus[unit].Queue         */
        pos=(Adc_QueueIndexType)1;
    }  
    /* Queue is NOT Empty */
    /* Find the right place in Queue */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    while((pos < qPtr) && (ADC_GroupPriority(ADC_GroupInQueue(unit, pos)) >= gPri))
    {
      pos++;
    }

    if(pos==0U)
    {
    #ifdef ADC_DMA_SUPPORTED
      if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_DMAR0_REG(unit),ADC_DMAR_RESET_VALUE);

       /* if !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
        #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_DMAR1_REG(unit),ADC_DMAR_RESET_VALUE);

        #ifdef IPV_ADCDIG
        /* if Bolero 3M or Bolero 1.5M */
         #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
         if(unit==(Adc_HwUnitType)ADC_UNIT_0)
         {
           if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
           {
             /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
             REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
           }
         }
         #else /* !Bolero 3M and !Bolero 1.5M */
         /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
         REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
        #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
        #endif /* IPV_ADCDIG */
        #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
                  (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                  (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                  (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_DMAE_REG(unit), ADC_DMAE_RESET_VALUE);

        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          /* reset DMA channel interrupt flag (IRQ ACK) */
          if(unit==(Adc_HwUnitType)ADC_UNIT_0)
          {
            /* Disable DMA interrupt */
            Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
          }
        } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == STD_ON) */

        #ifdef IPV_ADCDIG
        /*if Bolero 1.5M or Leopard or Bolero 3M or Pictus512_256 or Leopard cut2/cut3 or Pictus1M 
        or Komodo 2M or Panther or Rainier or Calypso */
         #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
             (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
             (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
             (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
          /* if !Pictus1M */
          #ifndef IPV_ADCDIG_31301_PICTUS1M
          #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
          if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
          {
            if(unit==(Adc_HwUnitType)ADC_UNIT_1)
            {
              /* Disable DMA interrupt */
              Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
            }
          }
          /* if Komodo 2M or Panther or Rainier */
          #if defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
          if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == (uint8)STD_ON)
          {
            if(unit==(Adc_HwUnitType)ADC_UNIT_2)
            {
              /* Disable DMA interrupt */
              Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[2]);
            }
          }
          if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
          {
            if(unit==(Adc_HwUnitType)ADC_UNIT_3)
            {
              /* Disable DMA interrupt */
              Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[3]);
            }
          }
          #endif /* defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
          #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
          #endif /* IPV_ADCDIG_31301_PICTUS1M */
         #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                   (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
                   (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                   (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
        #endif /* IPV_ADCDIG */

      } /* if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA) */
      #endif /* ADC_DMA_SUPPORTED  */

      /* Stop the current conversion group because the highest priority group occurs */
      /* The following code stop the conversion and abort the current group conversion,
      is important to abort the current, othewise, another interrupt occurs after the stop */
      /* load the timeout counter */
      Timeout = ADC_TIMEOUT_COUNTER;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING)&&
            (Timeout > (uint32)0U))
      {
        #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0014)
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          ADC_SWITCH_TO_ONE_SHOT_MODE(unit);
        #else
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          REG_BIT_SET32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
        #endif

        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_NORMAL_CONV_STOP);
        Timeout--;
      }

      /* Clear the ABORT_CHAIN bit if set, otherwise the next chain will be ABORTED
         without any End of Chain Interrupt */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_3 cast from unsigned int to pointer. */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      if (REG_READ32(ADC_MCR_REG(unit)) & ADC_ABORT_CHAIN)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_3 cast from unsigned int to pointer. */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
      }

      /* If the ongoing conversion is not aborted, report the production error */
      if ( Timeout == (uint32)0U )
      {
          /* Report production error and return from function. */
          #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
          if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
          {
             Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
          }
          #endif
          /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
          return;
      }
      else /* ENGR00127057 */
      {
          VAR(Adc_ChannelType, AUTOMATIC) ch_temp;
          VAR(Adc_ChannelType, AUTOMATIC) ChIndex_temp;
          /* clear VALID bit from ADC result registers for all channels assigned to the group when
             conversion is aborted*/
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          for(ch_temp=(Adc_ChannelType)0U;ch_temp<Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount;ch_temp++)
          {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            ChIndex_temp = Adc_Cfg_Ptr->Groups[Group].Assignment[ch_temp];
            /*
            * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
            */
            REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex_temp].ChId));
          }
      }
      #ifdef ADC_DMA_SUPPORTED
      if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_INTERRUPT)
      #endif /* ADC_DMA_SUPPORTED */
      {
        /* Disable Interrupt Mask*/
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_NORM_CONV_MASK);
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);
      }
    }

    /* Make space for the new Group */
    if(qPtr > pos)
    {
      for(p = qPtr; p > pos; p--)
      {
        ADC_UnitStatus[unit].Queue[p] = ((Adc_GroupType)ADC_UnitStatus[unit].Queue[p-(Adc_QueueIndexType)1U]);
      }
    }

    /* Place the Group in the Queue */
    ADC_UnitStatus[unit].Queue[pos] = Group;
    /* Increase the Queue Index */
    ADC_UnitStatus[unit].QueueIndex++;
  }
#else /* ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE */
 #if (ADC_ENABLE_QUEUING == STD_ON) /* ADC333*/
  qPtr = ADC_UnitStatus[unit].QueueIndex;
  if (qPtr > (Adc_QueueIndexType)0U)
  {
    /* Place the Group in the Queue */
    ADC_UnitStatus[unit].Queue[qPtr] = Group;
    /* Increase the Queue Index */
    ADC_UnitStatus[unit].QueueIndex++;
  }
 #else /* ADC_ENABLE_QUEUING == STD_OFF*/
  /* In this case all the StartConversion should be rejected by DET */
 #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
#endif /* ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE */

#if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_OFF)
#ifdef ADC_WDG_SUPPORTED
 #ifdef IPV_ADCDIG
 /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther 
    or Rainier or Calypso */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
   /* if !Pictus1M */
   #ifndef IPV_ADCDIG_31301_PICTUS1M
    /* Enable the Watchdog only on configured channels */
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    */
    REG_WRITE32(ADC_CWENR0_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer0));
    /* if !Leopard && !Leopard cut2/cut3 && !Komodo 2M && !Panther */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
     REG_WRITE32(ADC_CWENR1_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer1));
     #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
     if (unit == (Adc_HwUnitType)ADC_UNIT_0) /* ADCUnit0 */
     {
       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
       REG_WRITE32(ADC_CWENR2_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer2));
     }
     #else
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
     /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
     REG_WRITE32(ADC_CWENR2_REG(unit), (Adc_Cfg_Ptr->Groups[Group].Adc_Wer2));
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
   #endif /* IPV_ADCDIG_31301_PICTUS1M */
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01 */
 #endif /* IPV_ADCDIG */
#endif /* ADC_WDG_SUPPORTED */
#endif /* (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_OFF) */

#if (ADC_ENABLE_QUEUING == STD_ON)
  if((ADC_UnitStatus[unit].Queue[0] == Group)||
     (ADC_UnitStatus[unit].QueueIndex == (Adc_QueueIndexType)0))
  { /* No_priorities OR Queue_is_empty */
    /* Indicate a new group was added to the queue */
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    if (ADC_UnitStatus[unit].QueueIndex == (Adc_QueueIndexType)0)
    {
      /* Place the Group in the Queue */
      ADC_UnitStatus[unit].Queue[0] = Group;
      ADC_UnitStatus[unit].QueueIndex++;
    }


#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0016)
/* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
/* @violates @ref Adc_ADCDig_LLD_c_REF_11 cast from integer type to a other type */
    ConversionOnGoing=(((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING);
#endif
    /* ADC will not be running - no ISR can occur now */
    /* ADC061*/
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0016)
    if (ConversionOnGoing== (boolean) FALSE )
    {
#endif
    ADCDig_LLD_StartNormalConversion((Adc_HwUnitType)unit);
#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0016)
   }
#endif
#if (ADC_ENABLE_QUEUING == STD_ON)
  }
  else
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();
  }
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
  }
}

/**
* @brief          This function stops the group conversion.
* @details        This function stops the group conversion.
*
* @param[in]      Group       The group of which conversion will be started.
* @param[in]      unit        The hardware unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_StopGroupConversion
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
    VAR(uint32, AUTOMATIC) Timeout;
#if (ADC_ENABLE_QUEUING == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) queueIndex = (Adc_QueueIndexType)0;
    VAR(Adc_QueueIndexType, AUTOMATIC) removedPos = (Adc_QueueIndexType)0;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

  /* enter critical region to protect against queue changes from ISRs */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();

  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  if((((Adc_Cfg_Ptr->Groups[Group].mode) == ADC_CONV_MODE_ONESHOT)||
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      ((Adc_Cfg_Ptr->Groups[Group].AccessMode ==ADC_ACCESS_MODE_STREAMING)&&
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
       (Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)))&&
       (ADC_GroupStatus[Group].Conversion == ADC_STREAM_COMPLETED))
  { /*Stream Completed*/
    /* group is stopped, change its status to IDLE  ADC360 -- ADC221*/
    ADC_GroupStatus[Group].Conversion = ADC_IDLE;
    ADC_UnitStatus[unit].Status = ADC_IDLE;
    /* FD reset number of samples completed */
    ADC_GroupStatus[Group].ResultIndex = 0U;
  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* disable group notification (ADC155) */
    ADC_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
  }
  else
  {
  #if (ADC_ENABLE_QUEUING == STD_ON)
    /* Find the Group in the Queue */
    removedPos= ADC_UnitStatus[unit].QueueIndex;  /* initialize with something invalid */

    /* Hotfix for ENGR00133492 */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(Adc_Cfg_Ptr->Groups[Group].AdcWithoutInterrupt  == (uint8)STD_OFF)
    {   /* Last valid Group in the Queue */
        queueIndex = ADC_UnitStatus[unit].QueueIndex - (Adc_QueueIndexType)1U;
    }
    else
    {
      if (ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType)0)
      {   /* Last valid Group in the Queue */
          queueIndex = ADC_UnitStatus[unit].QueueIndex - (Adc_QueueIndexType)1U;
      }
      else /* mans that Adc_ReadGroup was called */
      {   /* Last valid Group in the Queue */
          queueIndex = ADC_UnitStatus[unit].QueueIndex;
      }
    }

    while (queueIndex < (Adc_QueueIndexType)Adc_QueueIndexType_MAXIMUM)
    {
      if ( Group == ADC_UnitStatus[unit].Queue[queueIndex] )
      { /* The group is found in the Queue */
        /* store the position of the group to be removed */
        removedPos= queueIndex;
        /* ADC072: Stop the conversion of all channels belonging to this group */
        if(queueIndex == (Adc_QueueIndexType)0U)/*In this case the group might be under conversion*/
  #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
        {
          /* Interrupt disable to protect code section  */
        #ifdef ADC_DMA_SUPPORTED
          if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_INTERRUPT)
        #endif /* ADC_DMA_SUPPORTED */
          {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_NORM_CONV_MASK);
          }
          #ifdef ADC_DMA_SUPPORTED
          else /* is dma driven: Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA */
          {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_DMAE_REG(unit), ADC_DMAE_RESET_VALUE);
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_DMAR0_REG(unit),ADC_DMAR_RESET_VALUE);
            /* !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
            #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&\
                (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_DMAR1_REG(unit),ADC_DMAR_RESET_VALUE);
            #ifdef IPV_ADCDIG
             /* if Bolero 3M or Bolero 1.5M */
             #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
             if(unit==(Adc_HwUnitType)ADC_UNIT_0)
             {
              if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
              {
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
              }
             }
             #else /* !Bolero 3M and !Bolero 1.5M */
             /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
             REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
             #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                       (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
            #endif /* #ifdef IPV_ADCDIG */
            #endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
                          (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                          (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */

            if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
            {
              /* reset DMA channel interrupt flag (IRQ ACK) */
              if(unit==(Adc_HwUnitType)ADC_UNIT_0)
              {
                /* Disable DMA interrupt */
                Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
              }
            } /* #if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == STD_ON) */

            #ifdef IPV_ADCDIG
            /* if Bolero 1.5M or Leopard or Bolero 3M or Pictus512_256 or Leopard cut2/cut3 or 
            Pictus1M or Komodo 2M or Pantehr or Rainier or Calypso */
             #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
                 (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
                 (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
                 (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
              /* if !Pictus1M */
              #ifndef IPV_ADCDIG_31301_PICTUS1M
              #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
              if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
              {
                if(unit==(Adc_HwUnitType)ADC_UNIT_1)
                {
                  /* Disable DMA interrupt */
                  Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
                }
              }
              /* if Komodo 2M or Panther or Rainier */
              #if defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
              if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == (uint8)STD_ON)
              {
                if(unit==(Adc_HwUnitType)ADC_UNIT_2)
                {
                  /* Disable DMA interrupt */
                  Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[2]);
                }
              }
              if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
              {
                if(unit==(Adc_HwUnitType)ADC_UNIT_3)
                {
                  /* Disable DMA interrupt */
                  Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[3]);
                }
              }
              #endif  /* defined(IPV_ADCDIG_31301_KOMODO2M) || 
                        (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                        (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
              #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
              #endif /* IPV_ADCDIG_31301_PICTUS1M */
             #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                           (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
                           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
            #endif /* #ifdef IPV_ADCDIG */

          } /* if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA) */
          #endif /* ADC_DMA_SUPPORTED */

          /* Stop the current conversion group because the highest priority group occurs */
          /* The following code stop the conversion and abort the current group conversion,
          is important to abort the current, othewise, another interrupt occurs after the stop */
          /* load the timeout counter */
          Timeout = ADC_TIMEOUT_COUNTER;
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          if(Adc_Cfg_Ptr->Groups[Group].AdcWithoutInterrupt  == (uint8)STD_ON)
          {
          #if (ADC_BYPASS_CONSISTENCY_LOOP == STD_OFF)
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING)&&
                (Timeout > (uint32)0U))
          #endif /* (ADC_BYPASS_CONSISTENCY_LOOP == STD_OFF) */
            {
              #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0014)
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                ADC_SWITCH_TO_ONE_SHOT_MODE(unit);
              #else
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_BIT_SET32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
              #endif

              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_NORMAL_CONV_STOP);
            #if (ADC_BYPASS_CONSISTENCY_LOOP == STD_OFF)
              Timeout--;
            #endif /* (ADC_BYPASS_CONSISTENCY_LOOP == STD_OFF) */
            }

            /* Clear the ABORT_CHAIN bit if set, otherwise the next chain will be ABORTED
               without any End of Chain Interrupt */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_3 cast from unsigned int to pointer. */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            if (REG_READ32(ADC_MCR_REG(unit)) & ADC_ABORT_CHAIN)
            {
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer. */
              REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
            }
          }
          else
          {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING)&&
                (Timeout > (uint32)0U))
            {
              #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0014)
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                ADC_SWITCH_TO_ONE_SHOT_MODE(unit);
              #else
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_BIT_SET32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
              #endif

              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_NORMAL_CONV_STOP);
              Timeout--;
            }

            /* Clear the ABORT_CHAIN bit if set, otherwise the next chain will be ABORTED
               without any End of Chain Interrupt */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_3 cast from unsigned int to pointer. */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            if (REG_READ32(ADC_MCR_REG(unit)) & ADC_ABORT_CHAIN)
            {
              /* @violates @ref Adc_ADCDig_LLD_c_REF_3 cast from unsigned int to pointer. */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
            }
          }
          /* If the ongoing conversion is not aborted, report the production error */
          if ( Timeout == (uint32)0U )
          {
              /* Report production error and return from function. */
              #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
              if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
              {
                 Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
              }
              #endif
              /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
              return;
          }
          else /* ENGR00127057 */
          {
              VAR(Adc_ChannelType, AUTOMATIC) ch_temp;
              VAR(Adc_ChannelType, AUTOMATIC) ChIndex_temp;
              /* clear VALID bit from ADC result registers for all channels assigned to the group
                 when conversion is aborted */
              for(ch_temp=(Adc_ChannelType)0U;
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                  ch_temp <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount;
                  ch_temp++)
              {
                /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                ChIndex_temp = Adc_Cfg_Ptr->Groups[Group].Assignment[ch_temp];
                /*
                * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
                */
                REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex_temp].ChId));
              }
          }
          #ifdef ADC_DMA_SUPPORTED
          if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_INTERRUPT)
          #endif /* ADC_DMA_SUPPORTED */
          {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);
          }
          ADC_UnitStatus[unit].Status = ADC_IDLE;
        }
#if (ADC_ENABLE_QUEUING == STD_ON)
        /* remove group from Queue */
        /* ADC385--ADC386--ADC437--ADC438**/
        ADCDig_RemoveFromQueue(unit, queueIndex);
      }
      queueIndex--;
    }/* End od While */
#endif
    /* FD reset number of samples completed */
    ADC_GroupStatus[Group].ResultIndex = 0U;
    /* group is stopped, change its status to IDLE  ADC360 -- ADC221*/
    ADC_GroupStatus[Group].Conversion = ADC_IDLE;
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* disable group notification (ADC155) */
    ADC_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
    #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

#if (ADC_ENABLE_QUEUING == STD_ON)
    /* Start the next qroup in the Queue (if any) */
    if((removedPos == (Adc_QueueIndexType)0U)&&
       (ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType)0U))
    {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
        /* ADC not running - no ISR can occur now */

        /* Structures and pointers will be initialized when the next Group starts */
        ADCDig_LLD_StartNormalConversion((Adc_HwUnitType)unit);
    }
    else
    {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
    }
#else
        /* no element will be present in the queue */
        ADC_UnitStatus[unit].QueueIndex= (Adc_QueueIndexType)0;

        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
  }
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          This function reads the converted data for the requested group.
* @details        Reads the converted data for the requested group.
*
* @param[in]      Group           The group number.
* @param[in]      DataPtr         Pointer to a buffer which will be filled by the
*                                 conversion results.
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successfull read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*
*/
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_ReadGroup
(
  CONST(Adc_GroupType, AUTOMATIC) Group,
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
)
{
  VAR(Std_ReturnType, AUTOMATIC) AdcDig_ReadGroupRet = (Std_ReturnType)E_OK;
  /* Pointer to AdcGroup */
  P2CONST(Adc_LLD_GroupConfiguration, AUTOMATIC, ADC_APPL_CONST) GroupPtr=NULL_PTR;
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  GroupPtr = &(Adc_Cfg_Ptr->Groups[Group]);
  /* If the group is configured for without interrupts*/
  if(GroupPtr->AdcWithoutInterrupt  == (uint8)STD_ON)
  {
    VAR(uint32, AUTOMATIC) Adc_CDR_value;
    VAR(Adc_ChannelType, AUTOMATIC) ch;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
    VAR(Adc_ChannelType, AUTOMATIC) MaxChIndex;
    VAR(Adc_HwUnitType, AUTOMATIC) unit;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    VAR(boolean, AUTOMATIC) flag = (boolean)TRUE; /*  flag to set if ADC results are in the range selected */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

    /* Enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();

    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    unit = ADC_GroupUnit(Group);

    MaxChIndex = Adc_MaxChannelIdAssignedToGroup(Group);
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][MaxChIndex].ChId));
    if((Adc_CDR_value & ADC_VALID_DATA_MASK) == (uint32)0)
    {   /* data of the greater ADC channel are not measured yet -> VALID flag not set yet */
        AdcDig_ReadGroupRet = (Std_ReturnType)E_NOT_OK;
    }

    if(AdcDig_ReadGroupRet == (Std_ReturnType)E_NOT_OK)
    {
    #if (ADC_HW_TRIGGER_API == STD_ON)
    /* if we are in hw triggered mode, and a group has more than one channel, than
    for the rest of the channels start an injected conversion. */

        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(Adc_Cfg_Ptr->Groups[Group].TriggerSource == ADC_TRIGG_SRC_HW)
        {
          /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
              Komodo 2M or Bolero 3M (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
             /* if !Fado */
            #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
              /*64 => PIT2, 65 => PIT6, 66 => DMA for Bolero 256K there is only PIT2 */
            #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
            /* if Fado */
            #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
              /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
                71 => PIT2 */
            #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0])<=(Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
          #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
                    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
            {
                /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                ChIndex = Adc_Cfg_Ptr->Groups[Group].Assignment[0];
                if (MaxChIndex != ChIndex)
                {
                    /*
                    * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
                    */
                    Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
                    if ((Adc_CDR_value & ADC_VALID_DATA_MASK) != (uint32)0)
                    {
                        /*
                        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
                        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer
                        */
                        REG_BIT_SET32(ADC_MCR_REG(unit), ADC_INJ_START_CONV_EN);
                    }
                }
            }
        }
    #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
        /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
        return(AdcDig_ReadGroupRet);
    }

    /* copy result direct from ADC result registers to output data array */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for(ch=(Adc_ChannelType)0U;ch <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; ch++)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      ChIndex = Adc_Cfg_Ptr->Groups[Group].Assignment[ch];
      /*
      * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
      * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
      */
      Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck == (boolean)TRUE)
      {
        flag = (boolean)ADCDig_LLD_CheckConversionValuesInRange((uint16)Adc_CDR_value, unit, ChIndex);
        if (flag == (boolean)TRUE)
        {
          /* ADC446 */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          *(DataPtr + (ch)) = (uint16)Adc_CDR_value;
        }
        else
        {
          /* ADC448, ADC449, ADC450 */
          AdcDig_ReadGroupRet = (Std_ReturnType)E_NOT_OK;
        }
      }
      else /* (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck = (boolean)FALSE) */
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        *(DataPtr + (ch)) = (uint16)Adc_CDR_value;
      }
#else
     /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      *(DataPtr + (ch)) = (uint16)Adc_CDR_value;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    }

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* (flag = (boolean)FALSE) => conversion values are not in the configured range */
    if (flag == (boolean)FALSE)
    {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_ONESHOT)
        {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if(Adc_Cfg_Ptr->Groups[Group].TriggerSource == ADC_TRIGG_SRC_SW)
            {
                /* ADC449 */
                ADC_GroupStatus[Group].Conversion = ADC_BUSY;
            }
            else
            {
                /* ADC450 */
                ADC_GroupStatus[Group].Conversion = ADC_IDLE;
            }
        }
        else
        {
            /* ADC448 */
            ADC_GroupStatus[Group].Conversion = ADC_BUSY;
        }
    } /* ADC447: (flag = (boolean)TRUE) => conversion values are in the configured range */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    else if(Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_ONESHOT)
    {
        ADC_GroupStatus[Group].Conversion = ADC_IDLE;
    }
    else
    {
        ADC_GroupStatus[Group].Conversion = ADC_BUSY;
    }
#else
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_ONESHOT)
    {
        ADC_GroupStatus[Group].Conversion = ADC_IDLE;
    }
    else
    {
        ADC_GroupStatus[Group].Conversion = ADC_BUSY;
    }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

    /* at least once the group was converted */
    ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

    /* NOTE: Streaming groups are NOT allowed without interrupts in configuration */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((Adc_Cfg_Ptr->Groups[Group].mode ==  ADC_CONV_MODE_ONESHOT) && \
        (Adc_Cfg_Ptr->Groups[Group].TriggerSource == ADC_TRIGG_SRC_SW))
    {
      ADC_GroupStatus[Group].Conversion = ADC_IDLE;
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if (Adc_Cfg_Ptr->Groups[Group].type == (Adc_GroupConvType)ADC_CONV_TYPE_NORMAL)
      {
        /* Hotfix for ENGR00133492 */
        if (ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType)0)
        {
          /* no element will be present in the queue */
          ADC_UnitStatus[unit].QueueIndex--;
        }
      }
      else /* SW INJECTED */
      {
        if (ADC_UnitStatus[unit].SwInjQueueIndex > (Adc_QueueIndexType)0)
        {
          /* no more element for SW injected conversions */
          ADC_UnitStatus[unit].SwInjQueueIndex--;
        }
      }
    }
    else
    {
      ADC_GroupStatus[Group].Conversion = ADC_BUSY;
    }

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
  }
  else
  {
    VAR(uint8, AUTOMATIC) count = (uint8)0;
    VAR(Adc_ChannelType, AUTOMATIC)ChCount = (Adc_ChannelType)0;
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) ResultPtr = NULL_PTR;
    VAR(uint32, AUTOMATIC) DestOffset = (uint32)0;
    VAR(Adc_StreamNumSampleType, AUTOMATIC) ResultIndex = (Adc_StreamNumSampleType)0;

#if (STD_ON == ADC_DIRECT_DMA_RES_BUFFER_COPY)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_11 cast from integer type to a other type */
    ChCount = (uint16)((uint32)((uint32)(Adc_Cfg_Ptr->Groups[Group].LastCh) - \
                       (uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh >> (uint32)(2))) + (uint32)(1));
#else
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
     * @violates @ref Adc_ADCDig_LLD_c_REF_11 cast from integer type to a other type or a wider integer type */
    ChCount = (uint16)(Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount);
#endif
    /* Enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();
    if (ADC_GroupStatus[Group].Conversion == ADC_BUSY)
    {
      AdcDig_ReadGroupRet = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
      /* ADC140 Disable Interrupt Mask*/
      /* get index of last completed sample */
      if (ADC_GroupStatus[Group].ResultIndex == (Adc_StreamNumSampleType)0)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ResultIndex = Adc_Cfg_Ptr->Groups[Group].NumSamples - (Adc_StreamNumSampleType)1;
      }
      else
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ResultIndex = ADC_GroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1;
      }

      /*
      * @violates @ref Adc_ADCDig_LLD_c_REF_5 Cast from pointer to pointer.
      * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
      */
      ResultPtr=(Adc_ValueGroupType *)(Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group]+ResultIndex);
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      DestOffset = Adc_Cfg_Ptr->Groups[Group].NumSamples;

      /* ADC075 copy results of last conversion from streaming buffer to internal buffer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      for(count = 0U; count < (uint8)ChCount; count++)
      {
        /* ADC113-- ADC122 -- ADC383 */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        DataPtr[count] = (*ResultPtr);
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ResultPtr += DestOffset;
      }

      /* The following code has been added to respect the State Diagram of Streaming Access Mode */
      if (ADC_GroupStatus[Group].Conversion == ADC_COMPLETED)
      {
        ADC_GroupStatus[Group].ResultIndex = 0U;

        /* ADC331 -- ADC222*/
        ADC_GroupStatus[Group].Conversion = ADC_BUSY;
      }
      else
      {
        /* Compliance with State Diagram */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (Adc_Cfg_Ptr->Groups[Group].TriggerSource  == ADC_TRIGG_SRC_SW)
        {
          if (ADC_GroupStatus[Group].Conversion == ADC_STREAM_COMPLETED)
          {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if((Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_ONESHOT)||
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              ((Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_CONTINUOUS)&&
               /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
               (Adc_Cfg_Ptr->Groups[Group].AccessMode ==ADC_ACCESS_MODE_STREAMING)&&
               /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
               (Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)))
            {
              /* ADC330 - ADC221 */
              ADC_GroupStatus[Group].Conversion = ADC_IDLE;
            }
            else
            { /* Continuous*/
              /* ADC329 -- ADC222 */
              ADC_GroupStatus[Group].Conversion = ADC_BUSY;
            }
          }
        }
        #if (ADC_HW_TRIGGER_API == STD_ON)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        else if (Adc_Cfg_Ptr->Groups[Group].TriggerSource  == ADC_TRIGG_SRC_HW)
        { /* Hw Trigger*/
          if (ADC_GroupStatus[Group].Conversion == ADC_STREAM_COMPLETED)
          {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if((Adc_Cfg_Ptr->Groups[Group].AccessMode ==ADC_ACCESS_MODE_STREAMING)&&
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              (Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR))
            {
              /* ADC330 - ADC221*/
              ADC_GroupStatus[Group].Conversion = ADC_IDLE;
            }
            else
            { /* Simple One-shot mode, in other words in single access mode*/
              /* ADC329 -- ADC222*/
              ADC_GroupStatus[Group].Conversion = ADC_BUSY;
            }
          }
        }
        else
        {
             /* Catastrophic Errors Recovery (CER) */
             Cer_ReportError((uint16)ADC_MODULE_ID,
                             (uint8)0U,
                             (uint8)ADC_ADCDIG_LLD_READGROUP_ID,
                             (uint8)ADC_CER_TRIG_SRC_TYPE);
        }
        #endif /* (ADC_HW_TRIGGER_API == STD_ON) */
      }
    }
    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
  }/* if(GroupPtr->AdcWithoutInterrupt  == STD_ON) */
  return(AdcDig_ReadGroupRet);
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          This function enables the hardware triggers for the specified group.
* @details        This function enables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      unit            The hardware unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_EnableHardwareTrigger
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
/* if Bolero or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
  VAR(uint32, AUTOMATIC) Timeout;
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
/* if Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
  VAR(uint16, AUTOMATIC) Ext_trigger_src;
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
  P2CONST(Adc_LLD_GroupConfiguration, AUTOMATIC, ADC_APPL_CONST) GroupPtr; /* Pointer to AdcGroup */
/* if Bolero or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
  VAR(uint8, AUTOMATIC) phChannel = (uint8)0;
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  VAR(uint32, AUTOMATIC) mcr_clear_val = (uint32)0;
  VAR(uint32, AUTOMATIC) mcr_set_val = ADC_INJ_EXT_TRIGGER_EN;

/* if Leopard or Pictus512_256 or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther */
#if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
 #if (ADC_ENABLE_CTUV2 == STD_ON)
  if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_CTUV2 == (uint8)STD_ON)
  {
    /* activate the CTU control mode in ADC */
    if (CTUV2_LLD_IsSingleMode() == (boolean)TRUE)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_SET32(ADC_MCR_REG(unit), ADC_CTU_ENABLED);
    }
    else
    {
    #ifndef IPV_ADCDIG_31301_KOMODO2M
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_MCR_REG(ADC_UNIT_0), ADC_CTU_ENABLED);
      #if (ADC_MAX_HW_UNITS > 1U) /* this check should be already covered by configuration */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_MCR_REG(ADC_UNIT_1), ADC_CTU_ENABLED);
      #endif /* #if (ADC_MAX_HW_UNITS > 1U) */
    #else
      if(unit <= (Adc_HwUnitType)ADC_UNIT_1)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_MCR_REG(ADC_UNIT_0), ADC_CTU_ENABLED);
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_MCR_REG(ADC_UNIT_1), ADC_CTU_ENABLED);
      }
      else
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_MCR_REG(ADC_UNIT_2), ADC_CTU_ENABLED);
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_MCR_REG(ADC_UNIT_3), ADC_CTU_ENABLED);
      }
    #endif /* #ifndef IPV_ADCDIG_31301_KOMODO2M */
    }
    CTUV2_LLD_StartCTU();
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return; /* return, due to the fact that we are under CTU control mode.  */
  }
 #endif /* (ADC_ENABLE_CTUV2 == STD_ON) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */

/* if Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
 #if (ADC_ENABLE_BCTU == STD_ON)
  if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_BCTU == (uint8)STD_ON)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_BIT_SET32(ADC_MCR_REG(unit), ADC_CTU_ENABLED);
    BCTU_LLD_StartCTU();
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return; /* return, due to the fact that we are under CTU control mode.  */
  }
 #endif /* (ADC_ENABLE_BCTU == STD_ON) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

  /* Enter critical section */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10();

  GroupPtr = Adc_Cfg_Ptr->Groups;

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    /* if the queue is empty than simply copy into the groups in queue type the first group type */
    if (ADC_UnitStatus[unit].HwQueueIndex == (Adc_QueueIndexType)0)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      ADC_UnitStatus[unit].HwQueueGroupType = GroupPtr[Group].IsMHTGroup;
    }
    else
    {
      /* the queue is not empty, check the type of the group that will be (or not) en-queued */
      if ( /* different group type or more than one regular group not allowed */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          (ADC_UnitStatus[unit].HwQueueGroupType != GroupPtr[Group].IsMHTGroup) ||
          (ADC_UnitStatus[unit].HwQueueGroupType == (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE)
         )
      { /* the hw queue contains some other kind of group */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10();
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLEHARDWARETRIGGER_ID,
                        (uint8)ADC_E_BUSY);
        #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
        return;
      }
    }
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

    ADC_UnitStatus[unit].HwQueue[ADC_UnitStatus[unit].HwQueueIndex] = Group;
    ADC_UnitStatus[unit].HwQueueIndex++;
    
     /* Mark the HW unit as BUSY */
    ADC_UnitStatus[unit].Status = ADC_BUSY; /* Status of the HW unit */
    
    /* Mark the Group as BUSY when the Group goes to the Queue or gets started */
    /* ADC222 */
    ADC_GroupStatus[Group].Conversion = ADC_BUSY;
    /* if HW trigger is enabled for a group, its HW trigger status becoms ENABLED */
    ADC_GroupStatus[Group].HwTriggering = ADC_HWTRIGGER_ENABLED;
    /* ADC432 */
    /* Put the conversion results from Results Buffer Base Address */
    ADC_GroupStatus[Group].ResultIndex    = 0U;

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /*  Program Convertion Time*/
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    */
    REG_WRITE32(ADC_CTR0_REG(unit), GroupPtr[Group].ConvTime);
 #ifdef IPV_ADCDIG
  /* if !Pictus512_256 */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
    /* if !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther and !Rainier */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr[Group].ConvTime);
    #else /* Leopard cut2 or Pictus1M or Komodo 2M */
     /* if !Pictus1M */
     #ifndef IPV_ADCDIG_31301_PICTUS1M
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr[Group].ConvTime1);
     #endif /* IPV_ADCDIG_31301_PICTUS1M */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
     /* if Bolero 3M or Bolero 1.5M or Rainier */
     #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
         (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
     #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
     if(unit==(Adc_HwUnitType)ADC_UNIT_3)
     {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
     #else
     if(unit==(Adc_HwUnitType)ADC_UNIT_0)
     {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
     #endif
      {
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR2_REG(unit), GroupPtr[Group].ConvTime);
      }
     }
     #else /* !Bolero 3M and !Bolero 1.5M */
      /* if !Leopard && !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther*/
      #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
       REG_WRITE32(ADC_CTR2_REG(unit), GroupPtr[Group].ConvTime);
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
     #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
 #endif /* IPV_ADCDIG*/
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */

 /* Program the mask registers */
 #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    /* Even if we are in no-interrupts mode, these registers should be programmed for the hardware
    triggered groups that has more than one channel - the rest of the channels will be injected
    into the conversion when the first one completed. */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    REG_RMW32(ADC_JCMR0_REG(unit), 0x00UL, GroupPtr[Group].Adc_PrecisionChannel);
  #ifdef IPV_ADCDIG
    /* !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      REG_RMW32(ADC_JCMR1_REG(unit), 0x00UL, GroupPtr[Group].Adc_ExtendedChannel);
      /* if Bolero 3M or Bolero 1.5M */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
      if(unit==(Adc_HwUnitType)ADC_UNIT_0)
      {
        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          REG_RMW32(ADC_JCMR2_REG(unit), 0x00UL, GroupPtr[Group].Adc_ExternalChannel);
        }
      }
      #else /* !Bolero 3M and !Bolero 1.5M */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_RMW32(ADC_JCMR2_REG(unit), 0x00UL, GroupPtr[Group].Adc_ExternalChannel);
      #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
  #endif /* IPV_ADCDIG*/
 #else
    /* Program the mask registers */
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    */
    REG_WRITE32(ADC_JCMR0_REG(unit), GroupPtr[Group].Adc_PrecisionChannel);
  #ifdef IPV_ADCDIG
    /* !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
      REG_WRITE32(ADC_JCMR1_REG(unit), GroupPtr[Group].Adc_ExtendedChannel);
      /* if Bolero 3M or Bolero 1.5M */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
      if(unit==(Adc_HwUnitType)ADC_UNIT_0)
      {
        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
          REG_WRITE32(ADC_JCMR2_REG(unit), GroupPtr[Group].Adc_ExternalChannel);
        }
      }
      #else /* !Bolero 3M and !Bolero 1.5M */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
      REG_WRITE32(ADC_JCMR2_REG(unit), GroupPtr[Group].Adc_ExternalChannel);
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
   #endif /* IPV_ADCDIG*/
 #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

    /* Clear Interrupt status flag and CTU interrupt flag */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV | ADC_ISR_END_CHANNEL_CTU_CONV_CLEAN);

/* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
       Komodo 2M or Bolero 3M (Bolero 256k-128k) or Leopard2M  or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
        /* if !Fado */
        #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
           /*64 => PIT2, 65 => PIT6, 66 => DMA for Bolero 256K there is only PIT2 */
        #endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
        /* if Fado */
        #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
         /* If the configured trigger source is EXT_TRIG_10/EXT_TRIG_11/EXT_TRIG_12/EXT_TRIG_13/PIT2
         67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
         71 => PIT2 */
        if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0]) >= (Adc_HwTriggerTimerType)ADC_EXT_TRIG_PE10)
        {
            Ext_trigger_src = (Adc_Cfg_Ptr->Groups[Group].HwResource[0]-(uint16)ADC_EXT_TRIG_PE10);
            SIU_ADC_LLM_Enable_Ext_Trigger(Ext_trigger_src)
        }
        #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
   if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0]) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
  {
  /* if Bolero or Fado */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)

    /* Enable CTU interrupt */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
    if (GroupPtr[Group].AdcWithoutInterrupt == (uint8)STD_OFF)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_SET32(ADC_IMR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV_EN);
    }
    /* Init CTU */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    CTU_LLD_Init_TRUE();
    /* Enable CTU in ADC MCR register is done into init function */
    /*mcr_set_val |= ADC_CTU_ENABLED;*/

  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_BIT_SET32(ADC_MCR_REG(unit), mcr_set_val);
  }

  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  if(GroupPtr[Group].AdcWithoutInterrupt == (uint8)STD_OFF)
  {
    #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
     #ifdef IPV_ADCDIG
      /* !Pictus512_256 */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
       #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
       REG_RMW32(ADC_CIMR0_REG(unit), 0x00UL, (GroupPtr[Group].Adc_PrecisionChannel));
       #endif /* IPV_ADCDIG_31301_PICTUS1M */
       /* !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
       #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
           (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
       REG_RMW32(ADC_CIMR1_REG(unit), 0x00UL, (GroupPtr[Group].Adc_ExtendedChannel));
       /* Bolero 3M or Bolero 1.5M */
        #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
        if(unit==(Adc_HwUnitType)ADC_UNIT_0)
        {
         if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
         {
           /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
           /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
           REG_RMW32(ADC_CIMR2_REG(unit), 0x00UL, (GroupPtr[Group].Adc_ExternalChannel));
         }
        }
        #else /* !Bolero 3M and !Bolero1.5M */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_RMW32(ADC_CIMR2_REG(unit), 0x00UL, (GroupPtr[Group].Adc_ExternalChannel));
        #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
       #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                 (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
     #endif /* IPV_ADCDIG */
    #else
     #ifdef IPV_ADCDIG
      /* !Pictus512_256 */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
       #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
       /*
       * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
       * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
       */
        REG_WRITE32(ADC_CIMR0_REG(unit), (GroupPtr[Group].Adc_PrecisionChannel));
       #endif /* IPV_ADCDIG_31301_PICTUS1M */
      /* !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
      REG_WRITE32(ADC_CIMR1_REG(unit), (GroupPtr[Group].Adc_ExtendedChannel));
       /* Bolero 3M or Bolero 1.5M */
       #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
       if(unit==(Adc_HwUnitType)ADC_UNIT_0)
       {
        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
          REG_WRITE32(ADC_CIMR2_REG(unit), (GroupPtr[Group].Adc_ExternalChannel));
        }
       }
       #else /* !Bolero 3M and !Bolero 1.5M */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
       REG_WRITE32(ADC_CIMR2_REG(unit), (GroupPtr[Group].Adc_ExternalChannel));
       #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
                (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
     #endif /* IPV_ADCDIG */
    #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
  }

  /* Bolero or Fado */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
  /* Adc physical channel for the CTU triggered */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
  phChannel = Adc_Cfg_Ptr->Channels[unit][GroupPtr[Group].Assignment[0]].ChId;
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

  /* CTU-Lite On Bolero 512K and Fado, this code is added to map the adc channel to ctu channel
     as per Ref. manual */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
  if ((phChannel >= ADC_ST_EXTENDED_CH) && (phChannel <= ADC_MAX_EXTENDED_CH))
  {
    phChannel = (phChannel - (uint8)(ADC_MAX_PRICISION_COUNT));
  }
  else if ((phChannel >= ADC_ST_EXTERNAL_CH) && (phChannel <= ADC_ED_EXTERNAL_CH))
  {
    phChannel = (phChannel - (uint8)(ADC_ST_EXTENDED_CH));
  }
  else
  {
    /* do nothing */
  }
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

 /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
       Komodo 2M or Bolero 3M or or Bolero 256k or Leopard2M or Panther or Rainier or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
   /* if !Fado */
   #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
     /*64 => PIT2, 65 => PIT6, 66 => DMA for Bolero 256K there is only PIT2 */
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
   /* if Fado */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
     /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
       71 => PIT2 */
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
   if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0]) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
  {
  /* Configure the CTU_EVTCFGRx registers */
  /* CTU-Lite On Bolero and Fado*/
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) /* Bolero */
  #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
  CTU_LLD_SetEvtCfgReg( \
      (uint8)GroupPtr[Group].HwResource[0], /* TriggerSource */ \
      (boolean)TRUE, /* TriggerMask */ \
      (boolean)FALSE, /* ClearFlag */ \
      (uint8)unit, /* AdcHwUnitSelector */ \
      (uint8)(phChannel) \
  /* @violates @ref Adc_ADCDig_LLD_c_REF_14 Boolean operations whose results are invariant shall not be permitted */
  );
  #else /* Bolero 256k-128k */
  VAR(uint8, AUTOMATIC) unit_1 = (uint8)unit + (uint8)1;
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
    CTU_LLD_SetEvtCfgReg(
        (uint8)GroupPtr[Group].HwResource[0], /* TriggerSource */
        (boolean)TRUE, /* TriggerMask */
        (boolean)FALSE, /* ClearFlag */
        (uint8)unit_1, /* AdcHwUnitSelector */
        (uint8)(phChannel)
    );
  #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
  #else /* Fado */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetPrescalerValue((uint8)GroupPtr[Group].PrescConfig)
  if ( GroupPtr[Group].DelayIndex != NO_DELAY )
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    CTU_LLD_SetCounterStartValue((uint8)GroupPtr[Group].DelayIndex,
                                (uint32)GroupPtr[Group].CounterStartValue)
  }
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetEvtCfgReg(
      (uint8)GroupPtr[Group].HwResource[0], /* TriggerSource */
      (boolean)TRUE, /* TriggerMask */
      (boolean)FALSE, /* ClearFlag */
      (uint8)GroupPtr[Group].CounterGroup, /* Counter Group */
      (uint8)GroupPtr[Group].DelayIndex, /* Delay Index */
      (uint8)(phChannel)
  );
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  }

#ifdef ADC_DMA_SUPPORTED
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
      /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
       Komodo 2M or Bolero 3M or or Bolero 256k or Leopard2M or Panther */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA) && \
       (Adc_Cfg_Ptr->Groups[Group].HwResource[0] > (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS))
  #else
    if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA)
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
            (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
    {
      {
        /* If the group is configured for with interrupts*/
        if(GroupPtr->AdcWithoutInterrupt == (uint8)STD_OFF)
        {
         /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
         REG_BIT_SET32(ADC_DMAE_REG(unit), ADC_DMA_GLOBAL_EN);
         ADCDig_StartDMAOperation(unit);
        }
      }
    }
    else
#endif /* ADC_DMA_SUPPORTED */
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if(GroupPtr[Group].AdcWithoutInterrupt == (uint8)STD_OFF)
      {
        /* Enable Interrupt*/
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_EN);
      }
    }
  /* Select the Edge*/
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  if(GroupPtr[Group].TriggerEdge == ADC_HW_TRIG_RISING_EDGE)
  {
    mcr_set_val = ADC_INJ_TRIGGER_EDGE;
  }
  else
  {
    mcr_clear_val = ADC_INJ_TRIGGER_EDGE;
  }
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_BIT_SET32(ADC_MCR_REG(unit), mcr_set_val);
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_BIT_CLEAR32(ADC_MCR_REG(unit), mcr_clear_val);
  /* Bolero or Fado */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
    /* load the timeout counter */
    Timeout = ADC_TIMEOUT_COUNTER;
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_CTU_CONV_ONGOING) != ADC_CTU_CONV_FINISH)&&
         (Timeout > (uint32)0U))
   {
      Timeout--;
   }
    /* If the ADC hardware is not entered in power down state, report the production error */
    if ( Timeout == (uint32)0U )
    {
     /* Report production error and return from function. */
     #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
     if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
     {
        Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
     }
     #endif
     /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
     return;
    }
  /* if !Bolero 3M (Bolero 256k-128k) and !Bolero 512K and !Bolero 1.5M */
  #if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                            (IPV_CTU != IPV_CTU_00_00_03_01) && \
                            (IPV_CTU != IPV_CTU_00_00_08_02))
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   REG_BIT_SET32(CTU_CSR, 0x40U);
  #endif /* if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                                      (IPV_CTU != IPV_CTU_00_00_03_01) && \
                                      (IPV_CTU != IPV_CTU_00_00_08_02)) */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   REG_RMW32(ADC_ISR_REG(unit), (ADC_ISR_END_CHAIN_NORM_CONV|ADC_ISR_END_CHANNEL_NORM_CONV),
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            (ADC_ISR_END_CHAIN_INJ_CONV|ADC_ISR_END_CHANNEL_INJ_CONV|ADC_ISR_END_CHANNEL_CTU_CONV));
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

 /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
       Komodo 2M or Bolero 3M or (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
   /* if !Fado */
   #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
     /*64 => PIT2, 65 => PIT6, 66 => DMA for Bolero 256K there is only PIT2 */
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
   /* if Fado */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
     /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
       71 => PIT2 */
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
   if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0]) > (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
   {
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
     REG_BIT_SET32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
   }
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

  /* Exit critical section */
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10();
}

/**
* @brief          This function disables the hardware triggers for the specified group.
* @details        This function disables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      unit            The hardware unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_DisableHardwareTrigger
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
/* if Leopard or Pictus512_256 or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther */
#if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
  #if (ADC_ENABLE_CTUV2 == STD_ON)
  if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_CTUV2 == (uint8)STD_ON)
  {
    /* activate the CTU control mode in ADC */
    if (CTUV2_LLD_IsSingleMode() == (boolean)TRUE)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CTU_ENABLED);
    }
    else
    {
    #ifndef IPV_ADCDIG_31301_KOMODO2M
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(ADC_UNIT_0), ADC_CTU_ENABLED);
      #if (ADC_MAX_HW_UNITS > 1U) /* this check should be already covered by configuration */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(ADC_UNIT_1), ADC_CTU_ENABLED);
      #endif /* #if (ADC_MAX_HW_UNITS > 1U) */
    #else
      if(unit <= (Adc_HwUnitType)ADC_UNIT_1)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(ADC_UNIT_0), ADC_CTU_ENABLED);
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(ADC_UNIT_1), ADC_CTU_ENABLED);
      }
      else
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(ADC_UNIT_2), ADC_CTU_ENABLED);
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(ADC_UNIT_3), ADC_CTU_ENABLED);
      }
    #endif
    }
    CTUV2_LLD_StopCTU();
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return; /* return, due to the fact that we are under CTU control mode.  */
  }
  #endif /* (ADC_ENABLE_CTUV2 == STD_ON) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)*/
          
/* if Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  #if (ADC_ENABLE_BCTU == STD_ON)
  if (Adc_Cfg_Ptr->Misc.ADC_ACTIVE_BCTU == (uint8)STD_ON)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CTU_ENABLED);
    BCTU_LLD_StopCTU();
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return; /* return, due to the fact that we are under CTU control mode.  */
  }
  #endif /* (ADC_ENABLE_BCTU == STD_ON) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
          

  /* Enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11();

  #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
  /* [ADC157] if HW trigger is disabled for a group, its HW trigger status becoms DISABLED */
  ADC_GroupStatus[Group].Notification = ADC_NOTIFICATION_DISABLED;
  #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

  ADC_GroupStatus[Group].HwTriggering = ADC_HWTRIGGER_DISABLED;

 /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
       Komodo 2M or Bolero 3M or (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* if !Fado */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
     /*64 => PIT2, 65 => PIT6, 66 => DMA for Bolero 256K there is only PIT2 */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
    /* if Fado */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
     /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
       71 => PIT2 */
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0]) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
  {
/* CTU-Lite On Bolero or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
   /* Bolero */
  /* set the group associated CTU_EVTCFGRx register to 0 */
  #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
  CTU_LLD_SetEvtCfgReg( \
      (uint8)((uint32)(Adc_Cfg_Ptr->Groups[Group].HwResource[0])), /*trigger src reg displacement*/ \
      (boolean)FALSE, /* trigger mask */ \
      (boolean)FALSE, /* Clear Flag */ \
      (uint8)unit, /* hw unit selector */ \
      (uint8)0 /* ADC channel ID */ \
  /* @violates @ref Adc_ADCDig_LLD_c_REF_14 Boolean operations whose results are invariant shall not be permitted */
  );
  #else /* Bolero 256k-128k */
  VAR(uint8, AUTOMATIC) unit_1 = (uint8)unit + (uint8)1;
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 pointer arithmetic other than array indexing used */
    CTU_LLD_SetEvtCfgReg(
      (uint8)((uint32)(Adc_Cfg_Ptr->Groups[Group].HwResource[0])), /*trigger src reg displacement*/
      (boolean)FALSE, /* trigger mask */
      (boolean)FALSE, /* Clear Flag */
      (uint8)unit_1, /* hw unit selector */
      (uint8)0 /* ADC channel ID */
    );
  #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
  #else /* Fado */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetEvtCfgReg(
      (uint8)((uint32)(Adc_Cfg_Ptr->Groups[Group].HwResource[0])), /*trigger src reg displacement*/
      (boolean)FALSE, /* trigger mask */
      (boolean)FALSE, /* Clear Flag */
      (uint8)COUNTER_0, /* Counter Group */
      (uint8)NO_DELAY, /* Delay Index */
      (uint8)0 /* ADC channel ID */
  );
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_OFF)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_Init_FALSE(); /* disable the TRGIEN field in the CTU_CSR register */
  #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_OFF) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  }

  if(ADC_UnitStatus[unit].HwQueueIndex > 0U)
  {
    /* ADC429 */
    ADC_UnitStatus[unit].HwQueueIndex--;
  }

  #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    if (ADC_UnitStatus[unit].HwQueueIndex == (Adc_QueueIndexType)0)
    {
     /* if Bolero 1.5M or Bolero 512K or Bolero 3M (Bolero 256k-128k) */
     #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)||(IPV_ADCDIG == IPV_ADCDIG_00_01_08_01)||\
         (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
      /*64 => PIT2, 65 => PIT6 for Bolero 256K there is only PIT2*/
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if((Adc_Cfg_Ptr->Groups[Group].HwResource[0])<=(Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
     #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
               (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
      {
      /* Bolero or Fado */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
          (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
        /* Stop CTU - no other HW triggered groups in queue */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        CTU_LLD_Init_FALSE(); /* disable the TRGIEN field in the CTU_CSR register */
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
      }
  #endif

#ifdef ADC_DMA_SUPPORTED
  /* Disable DMA */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
      /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
       Komodo 2M or Bolero 3M or or Bolero 256k or Leopard2M or Panther or Rainier or Calypso */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA) && \
       (Adc_Cfg_Ptr->Groups[Group].HwResource[0] > (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS))
  #else
    if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA)
  #endif   
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_DMAE_REG(unit), ADC_DMAE_RESET_VALUE);
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_DMAR0_REG(unit),ADC_DMAR_RESET_VALUE);
      /* !Pictus512_256 && !Leopard && !Leopard cut2 && !Pictus1M && !Komodo 2M && !Leopard2M
         && !Panther */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&\
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_DMAR1_REG(unit),ADC_DMAR_RESET_VALUE);
      #ifdef IPV_ADCDIG
       /* if Bolero 3M (Bolero 256k-128k) or Bolero 1.5M or Spectrum*/
       #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
       if(unit==(Adc_HwUnitType)ADC_UNIT_0)
       {
        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
        }
       }
       #else /* !Bolero 3M and !Bolero 1.5M */
       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
       #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
      #endif /* ifdef IPV_ADCDIG */
      #endif /* if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
                   (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */

      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
      {
        /* reset DMA channel interrupt flag (IRQ ACK) */
        if(unit==(Adc_HwUnitType)ADC_UNIT_0)
        {
          /* Disable DMA interrupt */
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
        }
      } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == STD_ON) */

    #ifdef IPV_ADCDIG
    /*if Bolero 1.5M or Leopard or Bolero 3M or Pictus512_256 or Leopard cut2 or Pictus1M or
         Komodo 2M or Leopard2M or Panther or Rainier or Calypso */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
     #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
     #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
      {
        if(unit==(Adc_HwUnitType)ADC_UNIT_1)
        {
          /* Disable DMA interrupt */
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
        }
      } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == STD_ON) */
      /* if Komodo 2M or Panther or Rainier */
      #if defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == (uint8)STD_ON)
      {
        if(unit==(Adc_HwUnitType)ADC_UNIT_2)
        {
          /* Disable DMA interrupt */
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[2]);
        }
      } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == STD_ON) */
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
      {
        if(unit==(Adc_HwUnitType)ADC_UNIT_3)
        {
          /* Disable DMA interrupt */
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[3]);
        }
      } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == STD_ON) */
      #endif /* defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
      #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
     #endif /* IPV_ADCDIG_31301_PICTUS1M */
    #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                 (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
                 (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
                 (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
    #endif /* ifdef IPV_ADCDIG */
    }
#endif /* ADC_DMA_SUPPORTED */
   /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
         Komodo 2M or Bolero 3M or (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
       /* if !Fado */
       #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
         /*64 => PIT2, 65 => PIT6, 66 => DMA for Bolero 256K there is only PIT2 */
       #endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
       /* if Fado */
       #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
         /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
           71 => PIT2 */
       #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0])<=(Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV_CLEAN);
      /* Disabling the HW triggering sources. ADC116 */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* Disable CTU in ADC MCR register is done into deinit funtion */
      /*REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CTU_ENABLED | ADC_INJ_EXT_TRIGGER_EN);*/
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
    }
    /* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
          Komodo 2M or Bolero 3M or (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    else
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
    }
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
  #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
      /* reset the queue group status to regular ones... */
      ADC_UnitStatus[unit].HwQueueGroupType = (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE;
    }
  #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

  /* ADC361*/
  ADC_GroupStatus[Group].Conversion = ADC_IDLE;
  
  /* Mark the HW unit as IDLE  if a normal conversion  is not in suspended state*/
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  if(((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)!=ADC_NORMAL_CONV_ONGOING)
  {
    ADC_UnitStatus[unit].Status = ADC_IDLE; /* Status of the HW unit */
  }  

  /* Disable Interrupt Status */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_RMW32(ADC_ISR_REG(unit), (ADC_ISR_END_CHAIN_NORM_CONV|ADC_ISR_END_CHANNEL_NORM_CONV),
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
           (ADC_ISR_END_CHAIN_INJ_CONV|ADC_ISR_END_CHANNEL_INJ_CONV|ADC_ISR_END_CHANNEL_CTU_CONV));
  /* Disable Interrupt Mask*/
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_MASK);
  /* Exit critical region */
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11();
}

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/**
* @brief          This function enables the hardware trigger for the specified group.
* @details        Non autosar API to enable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_EnableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
/* if Bolero or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
    VAR(uint32, AUTOMATIC) Timeout;
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
    /* Pointer to AdcGroup */
    P2CONST(Adc_LLD_GroupConfiguration, AUTOMATIC, ADC_APPL_CONST) GroupPtr;
    /* if Bolero or Fado */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
    VAR(uint8, AUTOMATIC) phChannel = (uint8)0;
      #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
        VAR(uint16, AUTOMATIC) Ext_trigger_src;
      #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    VAR(uint32, AUTOMATIC) mcr_clear_val = (uint32)0;
    VAR(uint32, AUTOMATIC) mcr_set_val = ADC_INJ_EXT_TRIGGER_EN;
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) unit = ADC_GroupUnit(Group);
    #ifdef IPV_ADCDIG
      /* if !Pictus512_256 and !Leopard and !Leopard cut2 and !Pictus1M and !Komodo 2M and !Panther */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      VAR(boolean, AUTOMATIC) Triggerflag = (boolean)FALSE;
      VAR(uint8, AUTOMATIC) trigCount;
      VAR(uint32, AUTOMATIC) temp_var;
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
                (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
    #endif /* IPV_ADCDIG*/

    /* Enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21();

#ifdef IPV_ADCDIG
  /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)

    for (trigCount=(uint8) 0U;
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
         trigCount<(uint8)(Adc_Cfg_Ptr->Groups[Group].AssignedTriggerCount);
         trigCount++)
    {
        /* check if the trigger source is configured for the called group */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (TriggerSource == ADC_GroupTriggerSource(Group, trigCount))
        {
            if ((TriggerSource) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
            {
                /* Check if this trigger source is already enabled for the group
                if it is already enabled report DET */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                temp_var = CTU_LLD_ReadEvtCfgRegs(TriggerSource);
                if (temp_var != (CTU_EVTCFGR_TM))
                {
                    Triggerflag = (boolean)TRUE;
                    break;
                }
            }
            else /* Trigger source is other than CTU */
            {
                Triggerflag = (boolean)TRUE;
                /* @violates @ref Adc_ADCDig_LLD_c_REF_17 multiple break statements in a loop */
                break;
            }
        }
    }
    if(Triggerflag == (boolean)FALSE)
    {
        /* Error: non-configured or configured Trigger Source which is already enabled is called
           for the group */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21();
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENABLECTUTRIGGER_ID,
                        (uint8)ADC_E_PARAM_TRIGGER);
        #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
        return;
    }
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */

    GroupPtr = Adc_Cfg_Ptr->Groups;

    ADC_UnitStatus[unit].HwQueue[ADC_UnitStatus[unit].HwQueueIndex] = Group;
    ADC_UnitStatus[unit].HwQueueIndex++;

    /* Mark the Group as BUSY when the Group goes to the Queue or gets started */
    /* ADC222*/
    ADC_GroupStatus[Group].Conversion = ADC_BUSY;

    /* if HW trigger is enabled for a group, its HW trigger status becoms ENABLED */
    ADC_GroupStatus[Group].HwTriggering = ADC_HWTRIGGER_ENABLED;

    /* ADC432 */
    /* Put the conversion results from Results Buffer Base Address */
    ADC_GroupStatus[Group].ResultIndex    = 0U;

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /*  Program Convertion Time*/
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    */
    REG_WRITE32(ADC_CTR0_REG(unit), GroupPtr[Group].ConvTime);
 #ifdef IPV_ADCDIG
  /* if !Pictus512_256 */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
    /* if !Leopard cut2/cut3 and !Pictus 1M and !Komodo 2M and !Panther and !Rainier */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr[Group].ConvTime);
    #else /* Leopard cut2 or Pictus 1M or Komodo 2M */
     /* if !Pictus1M */
     #ifndef IPV_ADCDIG_31301_PICTUS1M
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr[Group].ConvTime1);
     #endif /* IPV_ADCDIG_31301_PICTUS1M */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && 
              (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */

    /* if Bolero 3M */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
     if(unit==(Adc_HwUnitType)ADC_UNIT_0)
     {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
      {
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR2_REG(unit), GroupPtr[Group].ConvTime);
      }
     }
    #else /* !Bolero 3M */
     /* if !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
     #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
         (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
      if (unit == (Adc_HwUnitType)ADC_UNIT_0)
      {
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR2_REG(unit), GroupPtr[Group].ConvTime);
      }
      #else
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        */
        REG_WRITE32(ADC_CTR2_REG(unit), GroupPtr[Group].ConvTime);
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
               (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
 #endif /* IPV_ADCDIG*/
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */

    /* Clear Interrupt status flag and CTU interrupt flag */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV | ADC_ISR_END_CHANNEL_CTU_CONV_CLEAN);

 /* if Bolero 1.5M or Bolero 512K or Bolero3M or Fado */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
       /* if !Fado */
       #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
         /*64 => PIT2, 65 => PIT6 for Bolero 256K there is only PIT2*/
       #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
       /* if Fado */
       #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
         /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
           71 => PIT2 */
       #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
   if ((TriggerSource) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  {
  /* if Bolero or Fado */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
    /* Init CTU */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    CTU_LLD_Init_TRUE();
    /* Enable CTU in ADC MCR register is done into init function */
    /*mcr_set_val |= ADC_CTU_ENABLED;*/
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

    /* Enable the CTU trigger*/
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_BIT_SET32(ADC_MCR_REG(unit), mcr_set_val);
  }
  /* if Bolero or Fado */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
  /* Adc physical channel for the CTU triggered */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  phChannel = Adc_Cfg_Ptr->Channels[unit][GroupPtr[Group].Assignment[0]].ChId;
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

  /* CTU-Lite On Bolero 512K and Fado, this code is added to map the adc channel to ctu channel
     as per Ref. manual */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
  if ((phChannel >= ADC_ST_EXTENDED_CH) && (phChannel <= ADC_MAX_EXTENDED_CH))
  {
    phChannel = (phChannel - (uint8)(ADC_MAX_PRICISION_COUNT));
  }
  else if ((phChannel >= ADC_ST_EXTERNAL_CH) && (phChannel <= ADC_ED_EXTERNAL_CH))
  {
    phChannel = (phChannel - (uint8)(ADC_ST_EXTENDED_CH));
  }
  else
  {
    /* do nothing */
  }
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

 /* if Bolero 1.5M or Bolero 512K or Bolero 3M or Fado */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
      /* if !Fado */
      #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
        /*64 => PIT2, 65 => PIT6 for Bolero 256K there is only PIT2*/
      #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
      /* if Fado */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
        /* If the configured trigger source is EXT_TRIG_10/EXT_TRIG_11/EXT_TRIG_12/EXT_TRIG_13/PIT2
        67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
        71 => PIT2 */
        if ((TriggerSource) >= (Adc_HwTriggerTimerType)ADC_EXT_TRIG_PE10)
        {
            Ext_trigger_src = (TriggerSource-(uint16)ADC_EXT_TRIG_PE10);
            SIU_ADC_LLM_Enable_Ext_Trigger(Ext_trigger_src)
        }
      #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
   if ((TriggerSource) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
  {
  /* Configure the CTU_EVTCFGRx registers */
  /* CTU-Lite On Bolero and Fado*/
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) /* Bolero */
  #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetEvtCfgReg(
      (uint8)TriggerSource, /* TriggerSource */
      (boolean)TRUE, /* TriggerMask */
      (boolean)FALSE, /* ClearFlag */
      (uint8)unit, /* AdcHwUnitSelector */
      (uint8)(phChannel)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_14 Boolean operations whose results are invariant shall not be permitted */
  );
  #else /* Bolero 256k-128k */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  VAR(uint8, AUTOMATIC) unit_1 = (uint8)unit + (uint8)1;
    CTU_LLD_SetEvtCfgReg(
      (uint8)TriggerSource, /* TriggerSource */
      (boolean)TRUE, /* TriggerMask */
      (boolean)FALSE, /* ClearFlag */
      (uint8)unit_1, /* AdcHwUnitSelector */
      (uint8)(phChannel)
    );
  #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
#else /* Fado */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetPrescalerValue((uint8)GroupPtr[Group].PrescConfig)
  if ( GroupPtr[Group].DelayIndex != NO_DELAY )
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    CTU_LLD_SetCounterStartValue((uint8)GroupPtr[Group].DelayIndex,
                                 (uint32)GroupPtr[Group].CounterStartValue)
  }
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetEvtCfgReg(
      (uint8)TriggerSource, /* TriggerSource */
      (boolean)TRUE, /* TriggerMask */
      (boolean)FALSE, /* ClearFlag */
      (uint8)GroupPtr[Group].CounterGroup, /* Counter Group */
      (uint8)GroupPtr[Group].DelayIndex, /* Delay Index */
      (uint8)(phChannel)
  );
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  }
  /* Select the Edge*/
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  if(GroupPtr[Group].TriggerEdge == ADC_HW_TRIG_RISING_EDGE)
  {
    mcr_set_val = ADC_INJ_TRIGGER_EDGE;
  }
  else
  {
    mcr_clear_val = ADC_INJ_TRIGGER_EDGE;
  }

  /* Configure trigger edge for the group */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_BIT_SET32(ADC_MCR_REG(unit), mcr_set_val);
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_BIT_CLEAR32(ADC_MCR_REG(unit), mcr_clear_val);
/* if Bolero or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
   /* load the timeout counter */
   Timeout = ADC_TIMEOUT_COUNTER;

   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_CTU_CONV_ONGOING) != ADC_CTU_CONV_FINISH)&&
         (Timeout > (uint32)0U))
   {
      Timeout--;
   }
   /* If the ADC hardware is not entered in power down state, report the production error */
   if ( Timeout == (uint32)0U )
   {
     /* Report production error and return from function. */
     #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
     if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
     {
        Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
     }
     #endif
     /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
     return;
   }
   /* if !Bolero 3M (Bolero 256k-128k) and !Bolero 512K and !Bolero 1.5M */
   #if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                            (IPV_CTU != IPV_CTU_00_00_03_01) && \
                            (IPV_CTU != IPV_CTU_00_00_08_02))
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   REG_BIT_SET32(CTU_CSR, 0x40U);
   #endif /* if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                                        (IPV_CTU != IPV_CTU_00_00_03_01) && \
                                        (IPV_CTU != IPV_CTU_00_00_08_02)) */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   REG_RMW32(ADC_ISR_REG(unit), (ADC_ISR_END_CHAIN_NORM_CONV|ADC_ISR_END_CHANNEL_NORM_CONV),
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            (ADC_ISR_END_CHAIN_INJ_CONV|ADC_ISR_END_CHANNEL_INJ_CONV|ADC_ISR_END_CHANNEL_CTU_CONV));
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/* if Bolero 1.5M or Bolero 512K or Bolero 3M or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
   /*64 => PIT2, 65 => PIT6 for Bolero 256K there is only PIT2*/
   if ((TriggerSource) > (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
   {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_SET32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
   }
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

  /* Exit critical section */
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21();
}

/**
* @brief          This function disables the hardware trigger for the specified group.
* @details        Non autosar API to disable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be disabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
*
* @return         void
*
*/
FUNC(void, ADC_CODE) ADCDig_LLD_DisableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  VAR(Adc_HwUnitType, AUTOMATIC) unit = ADC_GroupUnit(Group);
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    VAR(boolean, AUTOMATIC) Triggerflag = (boolean)FALSE;
    VAR(uint8, AUTOMATIC) count;
    VAR(uint32, AUTOMATIC) temp_var;
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG*/

  /* Enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_22();

#ifdef IPV_ADCDIG
  /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther  */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  for (count=(uint8) 0U; count<(uint8)(Adc_Cfg_Ptr->Groups[Group].AssignedTriggerCount); count++)
  {
      /* check that the trigger source is configured for the called group */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if (TriggerSource == ADC_GroupTriggerSource(Group, count))
      {
          if ((TriggerSource) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
          {
              /* check that the trigger source is enabled for the called group */
              /* @note Violates MISRA 2004 Advisory Rule 11.3, cast from unsigned long to pointer:
                  See @ref REF 3 */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              temp_var = CTU_LLD_ReadEvtCfgRegs(TriggerSource);
              if (temp_var == CTU_EVTCFGR_TM)
              {
                  Triggerflag = (boolean)TRUE;
                  break;
              }
          }
          else /* Trigger source is other than CTU */
          {
              Triggerflag = (boolean)TRUE;
              /* @violates @ref Adc_ADCDig_LLD_c_REF_17 multiple break statements in a loop */
              break;
          }
      }
  }
  if (Triggerflag == (boolean)FALSE)
  {
        /* Error: non-configured or configured Trigger Source which is already enabled is called
           for the group */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_22();
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DISABLECTUTRIGGER_ID,
                        (uint8)ADC_E_PARAM_TRIGGER);
        #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
        return;
  }
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG*/

  ADC_GroupStatus[Group].HwTriggering = ADC_HWTRIGGER_DISABLED;

/* if Bolero 1.5M or Bolero 512K or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
    /* if !Fado */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
     /*64 => PIT2, 65 => PIT6 for Bolero 256K there is only PIT2*/
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
    /* if Fado */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
     /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
       71 => PIT2 */
    #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
  if ((TriggerSource) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  {
/* CTU-Lite On Bolero or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) /* Bolero */
  /* set the group associated CTU_EVTCFGRx register to 0 */
  #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetEvtCfgReg(
      (uint8)((uint32)TriggerSource), /* trigger source register displacement */
      (boolean)FALSE, /* trigger mask */
      (boolean)FALSE, /* Clear Flag */
      (uint8)unit, /* hw unit selector */
      (uint8)0 /* ADC channel ID */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_14 Boolean operations whose results are invariant shall not be permitted */
  );
  #else /* Bolero 256k-128k */
  VAR(uint8, AUTOMATIC) unit_1 = (uint8)unit + (uint8)1;
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    CTU_LLD_SetEvtCfgReg(
      (uint8)((uint32)TriggerSource), /* trigger source register displacement */
      (boolean)FALSE, /* trigger mask */
      (boolean)FALSE, /* Clear Flag */
      (uint8)unit_1, /* hw unit selector */
      (uint8)0 /* ADC channel ID */
    );
  #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
  #else /* Fado */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_SetEvtCfgReg(
      (uint8)((uint32)(TriggerSource)), /* trigger source register displacement */
      (boolean)FALSE, /* trigger mask */
      (boolean)FALSE, /* Clear Flag */
      (uint8)COUNTER_0, /* Counter Group */
      (uint8)NO_DELAY, /* Delay Index */
      (uint8)0 /* ADC channel ID */
  );
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

  /* disable the TRGIEN field in the CTU_CSR register */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  CTU_LLD_Init_FALSE();
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  }
  if(ADC_UnitStatus[unit].HwQueueIndex > 0U)
  {
    ADC_UnitStatus[unit].HwQueueIndex--;   /* ADC429 */
  }

/* if Bolero 1.5M or Bolero 512K or Bolero 3M or Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
    /* if !Fado */
       #if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01)
         /*64 => PIT2, 65 => PIT6 for Bolero 256K there is only PIT2*/
       #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) */
       /* if Fado */
       #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
         /*67 => EXT_TRIG_PE10, 68 => EXT_TRIG_PE11, 69 => EXT_TRIG_PE12, 70 => EXT_TRIG_PE13,
           71 => PIT2 */
       #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
    if ((TriggerSource) <= (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    {
      /* Clear interrupt mask register*/
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV_CLEAN);
      /* Disabling the HW triggering sources. ADC116 */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      /* Disable CTU in ADC MCR register is done into deinit funtion */
      /*REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CTU_ENABLED | ADC_INJ_EXT_TRIGGER_EN);*/
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
    }
    /* if Bolero 1.5M or Bolero 512K or Fado */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
    else
    {
      /* Disable external trigger */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
    }
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

  /* ADC361 */
  ADC_GroupStatus[Group].Conversion = ADC_IDLE;

  /* Disable Interrupt Status */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_RMW32(ADC_ISR_REG(unit), (ADC_ISR_END_CHAIN_NORM_CONV|ADC_ISR_END_CHANNEL_NORM_CONV),
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
           (ADC_ISR_END_CHAIN_INJ_CONV|ADC_ISR_END_CHANNEL_INJ_CONV|ADC_ISR_END_CHANNEL_CTU_CONV));

  /* Disable Interrupt Mask*/
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_MASK);

  /* Exit critical region */
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_22();
}

/**
* @brief          This function reads the data from the ADC channel hardware data register.
* @details        This non Autosar API is used to copy the data from the ADC channel
*                 hardware data register to the ADC group result buffer.
*
* @param[in]      Group           The group for which the data will be read.
* @param[in]      DataPtr         Pointer to a buffer which will be filled by the
*                                 conversion results.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successfull read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*
*/
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_HwResultReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
)
{
    VAR(uint32, AUTOMATIC) Adc_CDR_value;
    VAR(Std_ReturnType, AUTOMATIC) Adc_ReadGroupRet = (Std_ReturnType)E_OK;
    /* Unit on which the requested group conversion data is available */
    VAR(Adc_HwUnitType, AUTOMATIC) unit;
    VAR(Adc_ChannelType, AUTOMATIC) AdcChIndex;

    /* Get the unit to which the group belongs to */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    unit = ADC_GroupUnit(Group);
    /* Get the GroupChannelIndex of first channel */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    AdcChIndex = Adc_Cfg_Ptr->Groups[Group].Assignment[0];
    /* Global Interrupt disable to protect code section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23();
#ifdef IPV_ADCDIG
    /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M  and !Komodo 2M and 
          !Panther and !Rainier and !Calypso */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
      /* if !Bolero 3M (Bolero 256k-128k) and !Bolero 512K and !Bolero 1.5M */
      #if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                            (IPV_CTU != IPV_CTU_00_00_03_01) && \
                            (IPV_CTU != IPV_CTU_00_00_08_02))
    /* Check the CTU status flag and clear it if set */
    if ((REG_READ32(CTU_CSR) & CTU_CSR_TRGI) == CTU_CSR_TRGI)
    {
        /* Clear CTU status flag */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_BIT_SET32(CTU_CSR, CTU_CSR_TRGI);
    }
      #endif /* if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                                          (IPV_CTU != IPV_CTU_00_00_03_01) && \
                                          (IPV_CTU != IPV_CTU_00_00_08_02)) */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG*/

    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][AdcChIndex].ChId));

    if((Adc_CDR_value & ADC_VALID_DATA_MASK) == (uint32)0)
    {   /* data are not measured yet -> VALID flag not set yet */
        Adc_ReadGroupRet = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        *(DataPtr) = (uint16)Adc_CDR_value;
    }
    /* Global Interrupt enable to protect code section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23();

    return(Adc_ReadGroupRet);
}

#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/**
* @brief          This function returns the first empty position in the result buffer.
* @details        This function returns the first empty position in the result buffer.
*
* @param[in]      Group           The group number.
* @param[in]      PtrToSamplePtr  Pointer to the result buffer start address.
*
* @return         Adc_StreamNumSampleType  Number of samples from the result buffer.
* @retval         >= 0;
*
*/
FUNC(Adc_StreamNumSampleType, ADC_CODE) ADCDig_LLD_GetStreamLastPointer
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr
)
{
  VAR(Adc_StreamNumSampleType, AUTOMATIC) NumberOfResults = (Adc_StreamNumSampleType)0U;
  VAR(Adc_StreamNumSampleType, AUTOMATIC) ResultIndex = (Adc_StreamNumSampleType)0;

  *PtrToSamplePtr = (Adc_ValueGroupType *)NULL_PTR;

  /* Enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12();

  if ((ADC_GroupStatus[Group].Conversion == ADC_COMPLETED)||
      (ADC_GroupStatus[Group].Conversion == ADC_STREAM_COMPLETED))
  {

    if (ADC_GroupStatus[Group].ResultIndex == (Adc_StreamNumSampleType)0U)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      ResultIndex = Adc_Cfg_Ptr->Groups[Group].NumSamples - (Adc_StreamNumSampleType)1U;
      /* ADC387 Note*/
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      NumberOfResults = Adc_Cfg_Ptr->Groups[Group].NumSamples;
    }
    else
    {
      ResultIndex = ADC_GroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1U;
      NumberOfResults = ADC_GroupStatus[Group].ResultIndex;
    }


    /* The following code has been added to respect the State Diagram of Streaming Access Mode */
    if (ADC_GroupStatus[Group].Conversion == ADC_COMPLETED)
    {
      ADC_GroupStatus[Group].ResultIndex = 0U;

      /* ADC328 -- ADC222*/
      ADC_GroupStatus[Group].Conversion = ADC_BUSY;
    }

    /* ADC214 -- ADC418 -- ADC382*/
    /* @violates @ref Adc_ADCDig_LLD_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    *PtrToSamplePtr=(Adc_ValueGroupType *)(Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group]+ResultIndex);

    /* Compliance with State Diagram */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (Adc_Cfg_Ptr->Groups[Group].TriggerSource  == ADC_TRIGG_SRC_SW)
    {
      if (ADC_GroupStatus[Group].Conversion == ADC_STREAM_COMPLETED)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_ONESHOT)||
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          ((Adc_Cfg_Ptr->Groups[Group].mode == ADC_CONV_MODE_CONTINUOUS)&&
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          (Adc_Cfg_Ptr->Groups[Group].AccessMode ==ADC_ACCESS_MODE_STREAMING)&&
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          (Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)))
        {
          /* ADC327 -- ADC221*/
          ADC_GroupStatus[Group].Conversion = ADC_IDLE;
        }
        else
        { /* Continuous*/
          /* ADC326 -- ADC222*/
          ADC_GroupStatus[Group].Conversion = ADC_BUSY;
        }
      }
      else if(ADC_GroupStatus[Group].Conversion == ADC_COMPLETED)
      {
        /* ADC328 */
      }else
      {
      /* do nothig for misra */
      }
    }
#if (ADC_HW_TRIGGER_API == STD_ON)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (Adc_Cfg_Ptr->Groups[Group].TriggerSource  == ADC_TRIGG_SRC_HW)
    { /* Hw Trigger*/
      if (ADC_GroupStatus[Group].Conversion == ADC_STREAM_COMPLETED)
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((Adc_Cfg_Ptr->Groups[Group].AccessMode ==ADC_ACCESS_MODE_STREAMING)&&
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          (Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR))
        {
          /* ADC327 - ADC221*/
          ADC_GroupStatus[Group].Conversion = ADC_IDLE;
        }
        else
        { /* Simple One-shot mode, in other words in single access mode*/
          /* ADC326 -- ADC222*/
          ADC_GroupStatus[Group].Conversion = ADC_BUSY;
        }
      }
      else if(ADC_GroupStatus[Group].Conversion == ADC_COMPLETED)
      {
        /* ADC328*/
      }else
      {
      /* do nothig for misra */
      }
    }
    else
    {
         /* Catastrophic Errors Recovery (CER) */
         Cer_ReportError((uint16)ADC_MODULE_ID,
                         (uint8)0U,
                         (uint8)ADC_ADCDIG_LLD_GETSTREAMLASTPOINTER_ID,
                         (uint8)ADC_CER_TRIG_SRC_TYPE);
    }
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
  }

  /* Exit critical region */
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12();

  /* ADC387 -- ADC382*/
  return(NumberOfResults);
}

/**
* @brief          This function starts the conversion on the specified hardware unit.
* @details        This function starts the conversion on the specified hardware unit.
*                 This function should be called with the ADC unit on standby (no ADC interruptions
*                 allowed because its code is not protected by critical regions) - no conversions must
*                 be running.
*
* @param[in]      unit            the used hw unit.
*
* @return         void
*
*/
/*
* @violates @ref Adc_ADCDig_LLD_c_REF_10 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) ADCDig_LLD_StartNormalConversion
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
(
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
  P2CONST(Adc_LLD_GroupConfiguration, AUTOMATIC, ADC_APPL_CONST) GroupPtr; /* Pointer to AdcGroup */
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0; /* Active group in the Queue */
#if ((STD_ON == ADC_MUX_DELAY_SUPPORT) && (STD_ON == ADC_MUX_DELAY_SUPPORT_PER_GROUP))
  VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = (Adc_HwUnitType)0; /* HW index */
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
  VAR(Adc_GroupType, AUTOMATIC) Adc_IndividualGroupId = 0x00U;
#endif

  if (ADC_UnitStatus[unit].QueueIndex == (Adc_QueueIndexType)0)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return;
  }

  /* Get the Group ID of the current active group */
  /* Load the first group in the queue (ADC_UnitStatus[unit].Queue[0])*/
  Group=ADC_UnitStatus[unit].Queue[0];

  /* ADC435_Conf */
  /* Put the conversion results from Results Buffer Base Address */
  ADC_GroupStatus[Group].ResultIndex = 0U;

  /*Mark the Unit as BUSY */
  ADC_UnitStatus[unit].Status=ADC_BUSY;

  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  GroupPtr = &(Adc_Cfg_Ptr->Groups[Group]);

  #if ((STD_ON == ADC_MUX_DELAY_SUPPORT) && (STD_ON == ADC_MUX_DELAY_SUPPORT_PER_GROUP))
    /* Write the configured mux delay value into DSDR register */
    /* Get the HW index */
    for(HwIndex = 0U; HwIndex < (Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); HwIndex++)
    {
        /* Get the index of hardware unit in structure which will match with the hardware unit ID*/
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(Adc_Cfg_Ptr->ADC[HwIndex].AdcHardwareUnitId == unit)
        {
            break;
        }
    }
    /* if !Leopard && !Pictus512_256 && !Leopard cut2 && !Pictus1M && !Komodo 2M && !Leopard2M && 
          !Panther */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* if Bolero 3M (Bolero 256k-128k) or Bolero 1.5M or Rainier */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
        #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
        if (unit == (Adc_HwUnitType)ADC_UNIT_0)
        #else
        if (unit == (Adc_HwUnitType)ADC_UNIT_3)
        #endif
        { /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          if (Adc_Cfg_Ptr->Groups[Group].AdcMuxDelayNeeded == (uint8)STD_ON)
          {
           #if (STD_ON == ADC_DUAL_CLOCK_MODE)
            #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
            if (ADC_NORMAL == Adc_ClockMode)
            {
            #else
              if ((REG_READ32(ADC_MCR_REG(unit)) & ADC_CLOCK_PRESCALER_DIV1) != ADC_CLOCK_PRESCALER_DIV1)
              {
            #endif
            #endif
                /* Write DSDR with AdcMuxDelay value of the group */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
                REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcMuxDelay);
            #if (STD_ON == ADC_DUAL_CLOCK_MODE)
              }
              else /* ADC runs on low power system frequency */
              {
                /* Write DSDR with AdcAltMuxDelay value of the group */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
                REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcAltMuxDelay);
              }
            #endif
          }
          else
          {
            /* Write DSDR with value of ZERO */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
            REG_WRITE32(ADC_DSDR_REG(unit),(uint32)0x00UL);
          }
        }
      #else /* !Bolero 3M and !Bolero1.5M */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (Adc_Cfg_Ptr->Groups[Group].AdcMuxDelayNeeded == (uint8)STD_ON)
        {
          #if (STD_ON == ADC_DUAL_CLOCK_MODE)
            if ((REG_READ32(ADC_MCR_REG(unit)) & ADC_CLOCK_PRESCALER_DIV1) != ADC_CLOCK_PRESCALER_DIV1)
            {
          #endif
              /* Write DSDR with AdcMuxDelay value of the group */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
              REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcMuxDelay);
          #if (STD_ON == ADC_DUAL_CLOCK_MODE)
            }
            else /* ADC runs on low power system frequency */
            {
              /* Write DSDR with AdcAltMuxDelay value of the group */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
              REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcAltMuxDelay);
            }
          #endif
        }
        else
        {
          /* Write DSDR with value of ZERO */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
          REG_WRITE32(ADC_DSDR_REG(unit),(uint32)0x00UL);
        }
      #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
  #endif

/* if !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
  #if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF)
    /* presampling related configurations/initializations */
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer
    */
    REG_WRITE32(ADC_PSR0_REG(unit), (GroupPtr->Adc_PrecisionPsr));
   /* if !Leopard && !Leopard cut2/cut3 && !Pictus1M  && !Komodo 2M  and !Panther */
   #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
       (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_PSR1_REG(unit), (GroupPtr->Adc_ExtendedPsr));
    /* !Rainier and !Calypso */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
    if (unit == (Adc_HwUnitType)ADC_UNIT_0)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_PSR2_REG(ADC_UNIT_0), (GroupPtr->Adc_ExternalPsr));
    }
    #else
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_PSR2_REG(unit), (GroupPtr->Adc_ExternalPsr));
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01)
             (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
 #endif /* ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /*  Program Convertion Time*/
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer
    */
    REG_WRITE32(ADC_CTR0_REG(unit),GroupPtr->ConvTime);
 #ifdef IPV_ADCDIG
  /* if !Pictus512_256 */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
    /* if !Leopard cut2/cut3 and !Pictus 1M and !Komodo 2M and !Panther and !Rainier */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr->ConvTime);
    #else /* Leopard cut2 or Pictus 1M or Komodo 2M */
     /* if !Pictus1M */
     #ifndef IPV_ADCDIG_31301_PICTUS1M
        /*
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
        * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer
        */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr->ConvTime1);
     #endif /* IPV_ADCDIG_31301_PICTUS1M */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
              (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
    /*if Bolero 3M or Bolero 1.5M or Rainier */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
     #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
     if(unit==(Adc_HwUnitType)ADC_UNIT_3)
     {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
    #else
    if(unit==(Adc_HwUnitType)ADC_UNIT_0)
     {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
      {
       /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
       REG_WRITE32(ADC_CTR2_REG(unit),GroupPtr->ConvTime);
      }
     }
    #else /* !Bolero 3M and !Bolero 1.5M and !Rainier */
     /* if !Leopard && !Leopard cut2/cut3  && !Pictus1M  && !Komodo 2M & !Panther */
     #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
         (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_CTR2_REG(unit),GroupPtr->ConvTime);
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01)
               (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
 #endif /* IPV_ADCDIG*/
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */


/* If the Individual group channel enable capability is ON*/
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  Adc_IndividualGroupId = (Adc_GroupType)Adc_Cfg_Ptr->Groups[Group].EnableChDisableChGroupIndex;
  if(Adc_IndividualGroupId != ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX)
  {
  /* Program the Normal Conversion Mask register */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_WRITE32(ADC_NCMR0_REG(unit), Adc_NCMRx_Mask[Adc_IndividualGroupId].Adc_NCMR0);
#ifdef IPV_ADCDIG
  /* if !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M  && !Komodo 2M && !Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_WRITE32(ADC_NCMR1_REG(unit), Adc_NCMRx_Mask[Adc_IndividualGroupId].Adc_NCMR1);
   /* if Bolero 3M or Bolero 1.5M */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
   if(unit==(Adc_HwUnitType)ADC_UNIT_0)
   {
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
    {
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
     REG_WRITE32(ADC_NCMR2_REG(unit), Adc_NCMRx_Mask[Adc_IndividualGroupId].Adc_NCMR2);
    }
   }
   #else /* !Bolero 3M and !Bolero 1.5M */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   REG_WRITE32(ADC_NCMR2_REG(unit), Adc_NCMRx_Mask[Adc_IndividualGroupId].Adc_NCMR2);
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)*/
#endif /* IPV_ADCDIG */
  }
  else
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
  {
  /* Program the Normal Conversion Mask register */
  /*
  * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
  * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer
  */
  REG_WRITE32(ADC_NCMR0_REG(unit), GroupPtr->Adc_PrecisionChannel);
#ifdef IPV_ADCDIG
  /* if !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M  && !Komodo 2M && Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_WRITE32(ADC_NCMR1_REG(unit), GroupPtr->Adc_ExtendedChannel);
   /* if Bolero 3M or Bolero 1.5M */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
   if(unit==(Adc_HwUnitType)ADC_UNIT_0)
   {
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
    {
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
     REG_WRITE32(ADC_NCMR2_REG(unit), GroupPtr->Adc_ExternalChannel);
    }
   }
   #else /* !Bolero 3M and !Bolero 1.5M */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   REG_WRITE32(ADC_NCMR2_REG(unit), GroupPtr->Adc_ExternalChannel);
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */
  }
  /* Program the Mode */
  if(GroupPtr->mode==ADC_CONV_MODE_ONESHOT)
  {
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer
    */
    REG_BIT_CLEAR32(ADC_MCR_REG(unit),ADC_CONVERSION_MODE);
  }
  else
  {
    /*
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer
    * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer
    */
    REG_BIT_SET32(ADC_MCR_REG(unit),ADC_CONVERSION_MODE);
  }

#ifdef ADC_DMA_SUPPORTED
  if (Adc_Cfg_Ptr->Misc.ADC_DMA_INTERRUPT_SOFTWARE == ADC_DMA)
  {
    /* If the group is configured for with interrupts*/
    if(GroupPtr->AdcWithoutInterrupt == (uint8)STD_OFF)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_BIT_SET32(ADC_DMAE_REG(unit), ADC_DMA_GLOBAL_EN);
      ADCDig_StartDMAOperation(unit);
    }
  }
  else
#endif /* ADC_DMA_SUPPORTED */
  {
    /* Clear Interrupt status flag*/
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
    REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);

    /* If the group is configured for with interrupts*/
    if(GroupPtr->AdcWithoutInterrupt == (uint8)STD_OFF)
    {
      /* Enable Interrupt*/
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
      REG_BIT_SET32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_NORM_CONV_EN);
    }
  }

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  /* Clear the channels status, so we get the updated status for the next round of conversion */

  /* if !Pictus512_256 */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
    /* if !Pictus1M */
    #ifndef IPV_ADCDIG_31301_PICTUS1M
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_CEOCFR0_REG(unit), ((uint32)(GroupPtr->Adc_PrecisionChannel)));
    #endif /* !IPV_ADCDIG_31301_PICTUS1M */
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

  /* if !Pictus512_256 && !Leopard && !Leopard cut2 && !Pictus1M  && !Komodo 2M &&
        !Leopard2M && !Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)

    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_CEOCFR1_REG(unit), ((uint32)(GroupPtr->Adc_ExtendedChannel)));

    /* if Bolero 3M or Bolero 1.5M */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
      if ((unit) == (Adc_HwUnitType)0)
      {
        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          REG_WRITE32(ADC_CEOCFR2_REG(unit), ((uint32)(GroupPtr->Adc_ExternalChannel)));
        }
      }
    #else /* !Bolero 3M and !Bolero 1.5M */
      REG_WRITE32(ADC_CEOCFR2_REG(unit), ((uint32)(GroupPtr->Adc_ExternalChannel)));
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */

  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */

#endif /* (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015) */

  /* Start Normal Convertion */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
  REG_BIT_SET32(ADC_MCR_REG(unit), ADC_NORMAL_START_CONV_EN);
}

#ifdef ADC_DMA_SUPPORTED
/**
* @brief          This function programs the DMA transfers involved in the ADC conversion process.
* @details        This function should be called with the ADC unit on standby (no ADC interruptions
*                 allowed because its code is not protected by critical regions) - no conversions must
*                 be running.
*
* @param[in]      unit            the used hw unit.
*
* @return         void
*
* @pre ADC unit is not running anything.
*
* @violates @ref Adc_ADCDig_LLD_c_REF_10 internal linkage or external linkage
*/
FUNC(void, ADC_CODE) ADCDig_StartDMAOperation
(
  VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  VAR(Adc_ChannelType, AUTOMATIC)ChCount = (Adc_ChannelType)0;
  VAR(Adc_ChannelType, AUTOMATIC)phChannel = (Adc_ChannelType)0;

  if ((ADC_UnitStatus[Unit].QueueIndex == (Adc_QueueIndexType)0)
      #if (STD_ON == ADC_HW_TRIGGER_API)
      && (ADC_UnitStatus[Unit].HwQueueIndex == (Adc_QueueIndexType)0)
      #endif  /* (STD_ON == ADC_HW_TRIGGER_API) */
     )
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return;
  }

  /* @violates @ref Adc_ADCDig_LLD_c_REF_11 cast from integer type to a other type */
  if (ADC_UnitStatus[Unit].QueueIndex > 0)
  {
    Group=ADC_UnitStatus[Unit].Queue[0];
  }
  #if (STD_ON == ADC_HW_TRIGGER_API)
  else
  {
    Group=ADC_UnitStatus[Unit].HwQueue[0];
  }
  #endif /* (STD_ON == ADC_HW_TRIGGER_API) */

#if (STD_ON == ADC_DIRECT_DMA_RES_BUFFER_COPY)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_11 cast from integer type to a other type */
  ChCount = (uint16)((uint32)((uint32)(Adc_Cfg_Ptr->Groups[Group].LastCh) - \
                     (uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh >> (uint32)(2))) + (uint32)(1));
#else
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  ChCount = (Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount);
#endif /* (STD_ON == ADC_DIRECT_DMA_RES_BUFFER_COPY) */

  if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
  {
    if(Unit==(Adc_HwUnitType)ADC_UNIT_0)
    {
      /* Disable DMA interrupt */
      Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
    }
  } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == STD_ON) */

#ifdef IPV_ADCDIG
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* if Bolero 1.5M or Leopard or Bolero 3M or Pictus512_256 or Leopard cut2/cut3
     or Pictus1M or Komodo 2M or Panther or Rainier or Calypso */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
   /* if !Pictus1M */
   #ifndef IPV_ADCDIG_31301_PICTUS1M
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
    {
      if(Unit==(Adc_HwUnitType)ADC_UNIT_1)
      {
        /* Disable DMA interrupt */
        Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
      }
    }
    /* if Komopo 2M or Panther or Rainier */
    #if defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == (uint8)STD_ON)
    {
      if(Unit==(Adc_HwUnitType)ADC_UNIT_2)
      {
        /* Disable DMA interrupt */
        Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[2]);
      }
    }
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
    {
      if(Unit==(Adc_HwUnitType)ADC_UNIT_3)
      {
        /* Disable DMA interrupt */
        Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[3]);
      }
    }
    #endif /* defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
   #endif /* IPV_ADCDIG_31301_PICTUS1M */
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG_31201_BOLERO256K */
#endif /* IPV_ADCDIG */

  /* Enable the last channel of the chain to transfer data in DMA mode */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  phChannel = (Adc_ChannelType)Adc_Cfg_Ptr->Groups[Group].LastCh;

  if (phChannel < ADC_ST_EXTENDED_CH)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_DMAR0_REG(Unit), ((uint32)1<<(uint32)phChannel));
  }
/* if !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
  else if ((phChannel >= ADC_ST_EXTENDED_CH) && (phChannel <= ADC_ED_EXTENDED_CH))
  {
    phChannel = (phChannel - (ADC_ST_EXTENDED_CH));
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_DMAR1_REG(Unit), ((uint32)1<<(uint32)phChannel));
  }
  else if ((phChannel >= ADC_ST_EXTERNAL_CH) && (phChannel <= ADC_ED_EXTERNAL_CH))
  {
   /* if Bolero 3M or Bolero 256k-128k or Bolero 1.5M */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
   if(Unit==(Adc_HwUnitType)ADC_UNIT_0)
   {
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
    {
      phChannel = (phChannel - (ADC_ST_EXTERNAL_CH));
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_DMAR2_REG(Unit), ((uint32)1<<(uint32)phChannel));
    }
   }
   #else /* !Bolero 3M and !Bolero 1.5M */
    phChannel = (phChannel - (ADC_ST_EXTERNAL_CH));
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_DMAR2_REG(Unit), ((uint32)1<<(uint32)phChannel));
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
  }
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
  else
  {
    /* invalid channel */
  }

  /* update result address of ch 0 and destination offset to support format of streaming buffer */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group]+ADC_GroupStatus[Group].ResultIndex;

  if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
  {
    if(Unit == (Adc_HwUnitType)ADC_UNIT_0)
    {
    #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
      if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_ON)
    #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
      {
        /* There are no gaps into the group channels list, so it can be transferred without any
        problems directly to the user configured buffer. */
        Dma_configure_channel(
        /* dma_channel */
        (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0],
        /* src_addr */
        (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
        /* src_transfer_size */
        DMA_DATA_TRANSFER_16_BIT,
        /* dest_transfer_size */
        DMA_DATA_TRANSFER_16_BIT,
        /* src_next_offset */
        (uint16)4,
        /* n_bytes_to_transfer */
        (uint16)((uint16)ChCount << (uint16)1),
        /* src_last_adj */
        (uint32)0,
        /* dest_addr */
        (uint32)(pResult),
        /* current_iteration_count */
        (uint16)1,
        /* dest_next_offset */
        (uint16)(Adc_Cfg_Ptr->Groups[Group].NumSamples << (uint16)1),
        /* dest_last_adj */
        (uint32)0,
        /* begin_iteration_count */
        (uint16)1,
        /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
        (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
      } /* if (ADC_GroupStatus[Group].Adc_Dma_Continuous == STD_ON) */
    #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
      else
      if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_OFF)
      {
        /* There are gaps into the group channel list. In this case DMA will transfer all channels
           between the start channel and end channel into the intermediate buffer
           DmaInternalResultBuffer, and in the DMA ISR will be filtered out the unnecessary data. */
        Dma_configure_channel(
        /* dma_channel */
        (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0],
        /* src_addr */
        (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
        /* src_transfer_size */
        DMA_DATA_TRANSFER_16_BIT,
        /* dest_transfer_size */
        DMA_DATA_TRANSFER_16_BIT,
        /* src_next_offset */
        (uint16)4,
        /* n_bytes_to_transfer */
        (uint16)((uint16)((Adc_Cfg_Ptr->Groups[Group].LastCh+(uint16)1)<<(uint16)1)-
                 ((uint16)(Adc_Cfg_Ptr->Groups[Group].FirstCh)>>(uint16)1)),
        /* src_last_adj */
        (uint32)0,
        /* dest_addr */
        (uint32)(DmaInternalResultBuffer[Unit]),
        /* current_iteration_count */
        (uint16)1,
        /* dest_next_offset */
        (uint16)2, /* next data to xfer is the next channel data into the internal buffer */
        /* dest_last_adj */
        (uint32)0,
        /* begin_iteration_count */
        (uint16)1,
        /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
        (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
      }
      else {
        /* do nothing for misra */
      }
    #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
      /* Start the DMA channel0 */
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      Dma_start_channel((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
    } /* end if(Unit == (Adc_HwUnitType)ADC_UNIT_0) */
  } /* #if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == STD_ON) */

#ifdef IPV_ADCDIG
 #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
 /* if Bolero 1.5M or Leopard or Bolero 3M or Pictus512_256 or Leopard cut2/cut3
    or Pictus1M or Komodo 2M or Panther or Rainier or Calypso */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
   /* if !Pictus1M */
   #ifndef IPV_ADCDIG_31301_PICTUS1M
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
    {
      if(Unit==(Adc_HwUnitType)ADC_UNIT_1)
      {
      #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
        if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_ON)
      #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
        {
          /* There are no gaps into the group channels list, so it can be transferred without any
             problems directly to the user configured buffer. */
          Dma_configure_channel(
          /* dma_channel */
          (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1],
          /* src_addr */
          (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
          /* src_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* dest_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* src_next_offset */
          (uint16)4,
          /* n_bytes_to_transfer */
          (uint16)((uint16)ChCount << (uint16)1),
          /* src_last_adj */
          (uint32)0,
          /* dest_addr */
          (uint32)(pResult),
          /* current_iteration_count */
          (uint16)1,
          /* dest_next_offset */
          (uint16)(Adc_Cfg_Ptr->Groups[Group].NumSamples << (uint16)1),
          /* dest_last_adj */
          (uint32)0,
          /* begin_iteration_count */
          (uint16)1,
          /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
          (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
        } /* if (ADC_GroupStatus[Group].Adc_Dma_Continuous == STD_ON) */
      #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
        else
        if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_OFF)
        {
          /* There are gaps into the group channel list. In this case DMA will transfer all channels
             between the start channel and end channel into the intermediate buffer
             DmaInternalResultBuffer, and in the DMA ISR will be filtered out the unnecessary data.*/
          Dma_configure_channel(
          /* dma_channel */
          (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1],
          /* src_addr */
          (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
          /* src_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* dest_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* src_next_offset */
          (uint16)4,
          /* n_bytes_to_transfer */
          (uint16)((uint16)((Adc_Cfg_Ptr->Groups[Group].LastCh+(uint16)1)<<(uint16)1)-
                   ((uint16)(Adc_Cfg_Ptr->Groups[Group].FirstCh)>>(uint16)1)),
          /* src_last_adj */
          (uint32)0,
          /* dest_addr */
          (uint32)(DmaInternalResultBuffer[Unit]),
          /* current_iteration_count */
          (uint16)1,
          /* dest_next_offset */
          (uint16)2, /* next data to xfer is the next channel data into the internal buffer */
          /* dest_last_adj */
          (uint32)0,
          /* begin_iteration_count */
          (uint16)1,
          /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
          (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
        }
        else {
          /* do nothing for misra */
        }
      #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
        /* Start the DMA channel1 */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        Dma_start_channel( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
      }
    } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == STD_ON) */
   #endif /* IPV_ADCDIG_31301_PICTUS1M */
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
            (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
 #endif /* IPV_ADCDIG_31201_BOLERO256K */
#endif /* IPV_ADCDIG */

/* if Komodo 2M or Panther or Rainier */
#if defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == (uint8)STD_ON)
    {
      if(Unit==(Adc_HwUnitType)ADC_UNIT_2)
      {
      #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
        if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_ON)
      #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
        {
          /* There are no gaps into the group channels list, so it can be transferred without any
             problems directly to the user configured buffer. */
          Dma_configure_channel(
          /* dma_channel */
          (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[2],
          /* src_addr */
          (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
          /* src_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* dest_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* src_next_offset */
          (uint16)4,
          /* n_bytes_to_transfer */
          (uint16)((uint16)ChCount << (uint16)1),
          /* src_last_adj */
          (uint32)0,
          /* dest_addr */
          (uint32)(pResult),
          /* current_iteration_count */
          (uint16)1,
          /* dest_next_offset */
          (uint16)(Adc_Cfg_Ptr->Groups[Group].NumSamples << (uint16)1),
          /* dest_last_adj */
          (uint32)0,
          /* begin_iteration_count */
          (uint16)1,
          /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
          (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
        } /* if (ADC_GroupStatus[Group].Adc_Dma_Continuous == STD_ON) */
      #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
        else
        if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_OFF)
        {
         /* There are gaps into the group channel list. In this case DMA will transfer all channels
            between the start channel and end channel into the intermediate buffer
            DmaInternalResultBuffer, and in the DMA ISR will be filtered out the unnecessary data.*/
          Dma_configure_channel(
          /* dma_channel */
          (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[2],
          /* src_addr */
          (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
          /* src_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* dest_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* src_next_offset */
          (uint16)4,
          /* n_bytes_to_transfer */
          (uint16)((uint16)((Adc_Cfg_Ptr->Groups[Group].LastCh+(uint16)1)<<(uint16)1)-
                   ((uint16)(Adc_Cfg_Ptr->Groups[Group].FirstCh)>>(uint16)1)),
          /* src_last_adj */
          (uint32)0,
          /* dest_addr */
          (uint32)(DmaInternalResultBuffer[Unit]),
          /* current_iteration_count */
          (uint16)1,
          /* dest_next_offset */
          (uint16)2, /* next data to xfer is the next channel data into the internal buffer */
          /* dest_last_adj */
          (uint32)0,
          /* begin_iteration_count */
          (uint16)1,
          /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
          (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
        }
        else {
          /* do nothing for misra */
        }
      #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
        /* Start the DMA channel2 */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        Dma_start_channel( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[2]);
      }
    } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == STD_ON) */
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
    {
      if(Unit==(Adc_HwUnitType)ADC_UNIT_3)
      {
      #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
        if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_ON)
      #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
        {
          /* There are no gaps into the group channels list, so it can be transferred without any
             problems directly to the user configured buffer. */
          Dma_configure_channel(
          /* dma_channel */
          (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[3],
          /* src_addr */
          (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
          /* src_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* dest_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* src_next_offset */
          (uint16)4,
          /* n_bytes_to_transfer */
          (uint16)((uint16)ChCount << (uint16)1),
          /* src_last_adj */
          (uint32)0,
          /* dest_addr */
          (uint32)(pResult),
          /* current_iteration_count */
          (uint16)1,
          /* dest_next_offset */
          (uint16)(Adc_Cfg_Ptr->Groups[Group].NumSamples << (uint16)1),
          /* dest_last_adj */
          (uint32)0,
          /* begin_iteration_count */
          (uint16)1,
          /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
          (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
        } /* if (ADC_GroupStatus[Group].Adc_Dma_Continuous == STD_ON) */
      #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
        else
        if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_OFF)
        {
         /* There are gaps into the group channel list. In this case DMA will transfer all channels
            between the start channel and end channel into the intermediate buffer
            DmaInternalResultBuffer, and in the DMA ISR will be filtered out the unnecessary data.*/
          Dma_configure_channel(
          /* dma_channel */
          (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[3],
          /* src_addr */
          (uint32)(ADC_ADDRESS(Unit)+ADC_CH_DATA_REG_OFFSET+(uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)),
          /* src_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* dest_transfer_size */
          DMA_DATA_TRANSFER_16_BIT,
          /* src_next_offset */
          (uint16)4,
          /* n_bytes_to_transfer */
          (uint16)((uint16)((Adc_Cfg_Ptr->Groups[Group].LastCh+(uint16)1)<<(uint16)1)-
                   ((uint16)(Adc_Cfg_Ptr->Groups[Group].FirstCh)>>(uint16)1)),
          /* src_last_adj */
          (uint32)0,
          /* dest_addr */
          (uint32)(DmaInternalResultBuffer[Unit]),
          /* current_iteration_count */
          (uint16)1,
          /* dest_next_offset */
          (uint16)2, /* next data to xfer is the next channel data into the internal buffer */
          /* dest_last_adj */
          (uint32)0,
          /* begin_iteration_count */
          (uint16)1,
          /*
         * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
         * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
         */
          (uint8)(DMA_TCD_DISABLE_REQ | DMA_TCD_INT_HALF));
        }
        else {
          /* do nothing for misra */
        }
      #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
        /* Start the DMA channel3 */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        Dma_start_channel( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[3]);
      }
    } /* if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[2] == STD_ON) */
#endif /* defined(IPV_ADCDIG_31301_KOMODO2M) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
}
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_ENABLE_QUEUING == STD_ON)
/**
* @brief          This function implements the dequeue operation on the internal ADC queue.
* @details        This function implements the dequeue operation on the internal ADC queue.
*
* @param[in]      unit            The used hw unit.
* @param[in]      cur_queue_index The current queue index.
*
* @return         void
*
* @pre This function must be called from a critical region. It is not protecting itself against interruptions.
*
*/
FUNC(void, ADC_CODE) ADCDig_RemoveFromQueue
(
  CONST(Adc_HwUnitType, AUTOMATIC) unit,
  CONST(Adc_QueueIndexType, AUTOMATIC) cur_queue_index
)
{
    Adc_QueueIndexType position_index = (Adc_QueueIndexType)0;
    Adc_QueueIndexType current_index= ADC_UnitStatus[unit].QueueIndex;

    if( (Adc_QueueIndexType)current_index <= (Adc_QueueIndexType)1U)
    {
        /* zero or one element present in the queue */
        ADC_UnitStatus[unit].QueueIndex= (Adc_QueueIndexType)0;
    }
    else
    {
        /* more than one element in the queue */
        /* move all elements after the one to remove (from cur_queue_index position) one place
           to the left */
        for(position_index=(Adc_QueueIndexType)cur_queue_index+(Adc_QueueIndexType)1U;
            position_index<(Adc_QueueIndexType)current_index;
            position_index++)
        {
            ADC_UnitStatus[unit].Queue[position_index-(Adc_QueueIndexType)1U]=
            (Adc_GroupType)ADC_UnitStatus[unit].Queue[position_index];
        }
        ADC_UnitStatus[unit].QueueIndex--;
    }
}
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

/* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
      Komodo 2M or Bolero 3M (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
/**
* @brief          This function starts the injected conversion on the specified hardware unit.
* @details        This function starts the injected conversion on the specified hardware unit.
*                 This function should be called with the ADC unit on idle or busy.
*
* @param[in]      unit            The used hw unit.
*
* @return         void
*
*/
/*
* @violates @ref Adc_ADCDig_LLD_c_REF_10 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) ADCDig_LLD_StartInjectedConversion
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
(
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
  P2CONST(Adc_LLD_GroupConfiguration, AUTOMATIC, ADC_APPL_CONST) GroupPtr; /* Pointer to AdcGroup */
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0; /* Active group in the Queue */

  if (ADC_UnitStatus[unit].SwInjQueueIndex == (Adc_QueueIndexType)0)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
    return;
  }

  /* Get the Group ID of the current active group */
  /* Load the first group in the queue (ADC_UnitStatus[unit].Queue[0])*/
  Group=ADC_UnitStatus[unit].SwInjQueue[0];

  /* ADC435_Conf */
  /* Put the conversion results from Results Buffer Base Address */
  ADC_GroupStatus[Group].ResultIndex = 0U;

  /*Mark the Unit as BUSY */
  ADC_UnitStatus[unit].Status=ADC_BUSY;

  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  GroupPtr = &(Adc_Cfg_Ptr->Groups[Group]);

  /* if !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 #if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF)
    /* presampling related configurations/initializations */
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
    REG_WRITE32(ADC_PSR0_REG(unit), (GroupPtr->Adc_PrecisionPsr));
    /* if !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_PSR1_REG(unit), (GroupPtr->Adc_ExtendedPsr));
    /* !Rainier and !Calypso */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
    if (unit == (Adc_HwUnitType)ADC_UNIT_0)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_PSR2_REG(ADC_UNIT_0), (GroupPtr->Adc_ExternalPsr));
    }
    #else
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
    REG_WRITE32(ADC_PSR2_REG(unit), (GroupPtr->Adc_ExternalPsr));
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01)
             (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
 #endif /* #if ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF */
#endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    /*  Program Convertion Time*/
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
    REG_WRITE32(ADC_CTR0_REG(unit),GroupPtr->ConvTime);
 #ifdef IPV_ADCDIG
  /* if !Pictus512_256 */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
    /* if !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther and ! Rainier */
    #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
        (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr->ConvTime);
    #else /* Leopard cut2 or Pictus1M or Komodo 2M or Rainier */
     /* if !Pictus1M */
     #ifndef IPV_ADCDIG_31301_PICTUS1M
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(ADC_CTR1_REG(unit),GroupPtr->ConvTime1);
     #endif /* IPV_ADCDIG_31301_PICTUS1M */
    #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) 
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */

    /* if Bolero 3M and Bolero 1.5M or Rainier */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
    #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
    if(unit==(Adc_HwUnitType)ADC_UNIT_3)
    {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[3] == (uint8)STD_ON)
    #else
    if(unit==(Adc_HwUnitType)ADC_UNIT_0)
    {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
    #endif
      {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
        REG_WRITE32(ADC_CTR2_REG(unit),GroupPtr->ConvTime);
      }
    }
    #else /* !Bolero 3M and !Bolero 1.5M */
     /* if !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
     #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
         (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
      REG_WRITE32(ADC_CTR2_REG(unit),GroupPtr->ConvTime);
     #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01)
               (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
    #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
 #endif /* IPV_ADCDIG */
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */

  /* Program the Injected Conversion Mask register */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
  REG_WRITE32(ADC_JCMR0_REG(unit), GroupPtr->Adc_PrecisionChannel);
#ifdef IPV_ADCDIG
  /* if !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
  REG_WRITE32(ADC_JCMR1_REG(unit), GroupPtr->Adc_ExtendedChannel);
  /* if Bolero 3M or Bolero 1.5M */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
   if(unit==(Adc_HwUnitType)ADC_UNIT_0)
   {
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
    {
     /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
     REG_WRITE32(ADC_JCMR2_REG(unit), GroupPtr->Adc_ExternalChannel);
    }
   }
   #else /* !Bolero 3M and !Bolero 1.5M */
   /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
   REG_WRITE32(ADC_JCMR2_REG(unit), GroupPtr->Adc_ExternalChannel);
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */

  /* Clear Interrupt status flag*/
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
  REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_CLEAN);

  /* If the group is configured for with interrupts*/
  if(GroupPtr->AdcWithoutInterrupt == (uint8)STD_OFF)
  {
    /* Enable Interrupt*/
    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
    REG_BIT_SET32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_EN);
  }

  /* Start Injected Convertion */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
  REG_BIT_SET32(ADC_MCR_REG(unit), ADC_INJ_START_CONV_EN);
}
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

#if (ADC_SET_MODE_API == STD_ON)
/**
* @brief          This function sets the PWDN bit while going in power down mode or clears it
*                 upon exit from power down mode.
* @details        Set power down/ normal mode.
*
* @param[in]      SetMode         ADC_NORMAL_MODE,ADC_POWER_DOWN_MODE.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successfull set mode.
* @retval         E_NOT_OK        In case of unsuccessfull set mode.
*
*/
FUNC (Std_ReturnType, ADC_CODE) ADCDig_LLD_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) SetMode
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) unit=(Adc_HwUnitType)0; /* Hardware unit index */
    VAR(uint32, AUTOMATIC) Timeout;
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_NOT_OK;

    if(SetMode == ADC_POWER_DOWN_MODE)
    {
        for (unit = (uint8)0U; unit < (Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); unit++)
        {
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            if (((REG_READ32(ADC_MSR_REG(unit)))&ADC_CTU_CONV_ONGOING) != ADC_CTU_CONV_FINISH)
            {
              /* Report production error and return from function. */
              #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
              if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
              {
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
              }
              #endif
              TempReturn = (Std_ReturnType)E_NOT_OK;
              /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
              return (TempReturn);
            }
            /* enter into power-down mode */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_BIT_SET32(ADC_MCR_REG(unit),ADC_POWER_DOWN);

            /* load the timeout counter */
            Timeout = ADC_TIMEOUT_COUNTER;

            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_STATUS) != ADC_POWERDOWN_STATUS)&&
                  (Timeout > (uint32)0U))
            {
                Timeout--;
            }
            /* If the ADC HW is not entered in power down state, report the production error */
            if ( Timeout == (uint32)0U )
            {
                /* Report production error and return from function. */
                #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
                {
                   Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                #endif

                TempReturn = (Std_ReturnType)E_NOT_OK;
                /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
                return (TempReturn);
            }
            else
            {
                TempReturn = (Std_ReturnType)E_OK;
            }
        }
    }
    else
    {
        for (unit = (uint8)0U; unit < (Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); unit++)
        {
            /* Exit from PowerDown mode */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
            REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_POWER_DOWN);

            /* load the timeout counter */
            Timeout = ADC_TIMEOUT_COUNTER;

            /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
            while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_STATUS) != ADC_IDLE_OFFSET_STATUS)&&
                 (Timeout > (uint32)0U))
            {
               Timeout--;
            }
            /* If the ADC hardware is not entered in idle state, report the production error */
            if ( Timeout == (uint32)0U )
            {
                /* Report production error and return from function.  */
                #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
                {
                   Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                #endif

                TempReturn = (Std_ReturnType)E_NOT_OK;
                /* @violates @ref Adc_ADCDig_LLD_c_REF_4 Return statement before end of function. */
                return (TempReturn);
            }
            else
            {
                TempReturn = (Std_ReturnType)E_OK;
            }
        }
    }
    return (TempReturn);
}
#endif /* (ADC_SET_MODE_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          This function sets the Prescaler value only when ADC is in power down mode.
* @details        Set prescaler clock divider only in power down mode.
*
* @param[in]      ClockMode       ADC_NORMAL, ADC_ALTERNATE.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successfull set mode.
* @retval         E_NOT_OK        In case of unsuccessfull set mode.
*
*/
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_SetClockMode
(
   VAR(Adc_NonASR_DualClockModeType, AUTOMATIC) ClockMode
)
{
   VAR(Adc_HwUnitType, AUTOMATIC) unit=(Adc_HwUnitType)0; /* Hardware unit index */
   VAR(Adc_HwUnitType, AUTOMATIC) HwIndex=(Adc_HwUnitType)0; /* Index of hardware unit */
   VAR(Std_ReturnType, AUTOMATIC) AdcDig_SetClockModeRet=(Std_ReturnType)E_OK;

   /* Bolero 3M Only */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
   Adc_ClockMode = ClockMode;
  #endif
   for (unit = (Adc_HwUnitType)0; unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; unit++)
   {
    if(ADC_HW_UNITS(unit) == (uint8)STD_ON)
    {
        /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
        if (((REG_READ32(ADC_MSR_REG(unit)))&ADC_STATUS) == ADC_POWERDOWN_STATUS)
        {
           /* Get index of hardware unit */
           for(HwIndex = 0U; HwIndex < (Adc_HwUnitType)(Adc_Cfg_Ptr->Misc.ADC_MAX_HWCFG); HwIndex++)
           {
               /* Get the index of hardware unit in structure which will match with the hardware unit ID*/
               /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
               if(Adc_Cfg_Ptr->ADC[HwIndex].AdcHardwareUnitId == unit)
               {
               break;
               }
           }
           if (ClockMode == (Adc_NonASR_DualClockModeType)ADC_NORMAL)
           {
              #ifdef IPV_ADCDIG
            #if (STD_ON == ADC_MUX_DELAY_SUPPORT)
              /* Write the configured mux delay value into DSDR register */
              /* if !Leopard && !Pictus512_256 && !Leopard cut2 && !Pictus1M && !Komodo 2M && !Leopard2M && 
                    !Panther */
              #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
                  (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
                /* if Bolero 3M (Bolero 256k-128k) or Bolero 1.5M or Rainier */
                #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
                    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
                  #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
                  if (unit == (Adc_HwUnitType)ADC_UNIT_0)
                  #else
                  if (unit == (Adc_HwUnitType)ADC_UNIT_3)
                  #endif
                  {
                    /* Write DSDR with AdcMuxDelay value of the group */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
                    REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcMuxDelay);
                  }
                #else /* !Bolero 3M and !Bolero1.5M */
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
                  REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcMuxDelay);
                #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
              #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
                        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
            #endif

                /* Write the configured power down exit delay value into PDEDR register */
                /* if Bolero 3M */
                #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
                  if (unit == (Adc_HwUnitType)ADC_UNIT_0)
                  {
                    /*
                     * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                     * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
                     */
                    REG_WRITE32(ADC_PDEDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcPwrDownDelay);
                  }
                #else /* !Bolero 3M */
                  /*
                   * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                   * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
                   */
                  REG_WRITE32(ADC_PDEDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcPwrDownDelay);
                #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

              #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
                #ifdef IPV_ADCDIG_31201_BOLERO256K
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_BIT_CLEAR32(ADC_MCR_REG(unit), (uint32)ADC_CLOCK_PRESCALER_DIV1);
                #endif /* ifdef IPV_ADCDIG_31201_BOLERO256K */
              #else
                /* !Bolero3M */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_BIT_CLEAR32(ADC_MCR_REG(unit), (uint32)ADC_CLOCK_PRESCALER_DIV1);
              #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
              #endif /* ifdef IPV_ADCDIG */

              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              REG_WRITE32(ADC_CTR0_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeNormal));
              #ifdef IPV_ADCDIG
              /* if !Pictus512_256 */
              #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
               /* if !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther and !Rainier */
               #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
                   (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                REG_WRITE32(ADC_CTR1_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeNormal));
               #else
                #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                 REG_WRITE32(ADC_CTR1_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeNormal1));
                #endif /* IPV_ADCDIG_31301_PICTUS1M */
               #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
               /* if Bolero 3M or Bolero 1.5M or Rainier */
               #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
                   (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
               #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
               if (unit == (Adc_HwUnitType)ADC_UNIT_3)
               #else
               if (unit == (Adc_HwUnitType)ADC_UNIT_0)
               #endif
               {
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                 REG_WRITE32(ADC_CTR2_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeNormal));
               }
               #else /* !Bolero 3M and !Bolero 1.5M */
                /* if !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther*/
                #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
                    (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                  REG_WRITE32(ADC_CTR2_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeNormal));
                #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
                          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) */
               #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                         (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
              #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
              #endif /* IPV_ADCDIG */
           }
           else
           {
              #ifdef IPV_ADCDIG
            #if (STD_ON == ADC_MUX_DELAY_SUPPORT)
              /* Write the configured mux delay value into DSDR register */
              /* if !Leopard && !Pictus512_256 && !Leopard cut2 && !Pictus1M && !Komodo 2M && !Leopard2M && 
                    !Panther */
              #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
                  (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
                /* if Bolero 3M (Bolero 256k-128k) or Bolero 1.5M or Rainier */
                #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
                    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
                  #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
                  if (unit == (Adc_HwUnitType)ADC_UNIT_0)
                  #else
                  if (unit == (Adc_HwUnitType)ADC_UNIT_3)
                  #endif
                  {
                    /* Write DSDR with AdcAltMuxDelay value of the group */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
                    REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcAltMuxDelay);
                  }
                #else /* !Bolero 3M and !Bolero1.5M */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                    /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer. */
                  REG_WRITE32(ADC_DSDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcAltMuxDelay);
                #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
              #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
                        (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
            #endif

                /* Write the configured power down exit delay value into PDEDR register */
                /* if Bolero 3M */
                #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
                  if (unit == (Adc_HwUnitType)ADC_UNIT_0)
                  {
                    /*
                     * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                     * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
                     */
                    REG_WRITE32(ADC_PDEDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcAltPwrDownDelay);
                  }
                #else /* !Bolero 3M */
                  /*
                   * @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                   * @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer.
                   */
                  REG_WRITE32(ADC_PDEDR_REG(unit),Adc_Cfg_Ptr->ADC[HwIndex].AdcAltPwrDownDelay);
                #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

              #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
                #ifdef IPV_ADCDIG_31201_BOLERO256K
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_BIT_SET32(ADC_MCR_REG(unit), (uint32)ADC_CLOCK_PRESCALER_DIV1);
                #endif /* ifdef IPV_ADCDIG_31201_BOLERO256K */
              #else
                /* !Bolero3M */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                REG_BIT_SET32(ADC_MCR_REG(unit), (uint32)ADC_CLOCK_PRESCALER_DIV1);
              #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
              #endif /* ifdef IPV_ADCDIG */

              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              REG_WRITE32(ADC_CTR0_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeAlternate));
              #ifdef IPV_ADCDIG
              /* if !Pictus512_256 */
              #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
               /* if !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther and !Rainier */
               #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
                   (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
                /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                REG_WRITE32(ADC_CTR1_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeAlternate));
               #else
                #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned int to pointer */
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                 REG_WRITE32(ADC_CTR1_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeAlternate1));
                #endif /* IPV_ADCDIG_31301_PICTUS1M */
               #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
               /* if Bolero 3M or Bolero 1.5M */
               #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || \
                   (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
               #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
               if (unit == (Adc_HwUnitType)ADC_UNIT_3)
               #else
               if (unit == (Adc_HwUnitType)ADC_UNIT_0)
               #endif
               {
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                 /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                 REG_WRITE32(ADC_CTR2_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeAlternate));
               }
               #else /* !Bolero 3M and !Bolero 1.5M */
                /* if !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther*/
                #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
                    (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
                  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                  REG_WRITE32(ADC_CTR2_REG(unit),(uint32)(Adc_Cfg_Ptr->ADC[HwIndex].ConvTimeAlternate));
                #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
                          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) */
               #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
                         (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
              #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
              #endif /* IPV_ADCDIG */
           }
        }
        else
        {
           AdcDig_SetClockModeRet = (Std_ReturnType)E_NOT_OK;
           break;
        }
    }
   }
   return AdcDig_SetClockModeRet;
}
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          Get the injected conversions status.
* @details        This function checks if an injected conversion (HW/SW) is ongoing
*
* @param[in]      unit            ADC Unit id.
*
* @return         Adc_StatusType  Status of the ADC HW unit.
* @retval         ADC_IDLE:       SW/HW Injection or Hardware Trigger group are idle.
* @retval         ADC_BUSY:       SW/HW Injection or Hardware Trigger is inprogress.
*
*/
FUNC(Adc_StatusType, ADC_CODE) ADCDig_LLD_GetInjectedConversionStatus
/* @violates @ref Adc_ADCDig_LLD_c_REF_15 Identifier exceeds 31 characters */
(
  VAR(Adc_HwUnitType, AUTOMATIC) unit
)
{
/* if !Pictus 512k 256k 1M && !Leopard cut2/cut3 && !Komodo 2M */
#if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01)
    VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) */
    VAR(Adc_StatusType, AUTOMATIC) tempReturn = (Adc_StatusType)ADC_IDLE;

/* if !Pictus 512k 256k 1M && !Leopard cut2/cut3 && !Komodo 2M */
#if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01)
    Group=(ADC_UnitStatus[unit].HwQueue[0]);
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((Adc_Cfg_Ptr->Groups[Group].HwResource[0])<=(Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
    {
      /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
      if ((Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount)>(Adc_ChannelType)1U)
      {
        tempReturn = (Adc_StatusType)ADC_BUSY;
      }
      else
      {
        tempReturn = (Adc_StatusType)ADC_IDLE;
      }
    }
    else
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) */
    {
      (void)unit;
      tempReturn = (Adc_StatusType)ADC_BUSY;
    }
    return (tempReturn);
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* ADC_GET_INJECTED_CONVERSION_STATUS_API */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
 * @brief   Function to reconfigure High and Low thresholds for a given group.
 * @details This Non Autosar API is used to reconfigure High and Low thresholds for a given group.
 *
 * @param[in]  GroupId          Index of group
 * @param[in]  LowValue         Low threshold value for channels in the group
 * @param[in]  HighValue        High threshold value for channels in the group
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successfull Configure Threshold.
 * @retval         E_NOT_OK        In case of unsuccessfull ConfigureThreshold.
 */
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_ConfigureThreshold
(
  VAR(Adc_GroupType, AUTOMATIC) GroupId,
  VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
  VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
)
{
  VAR(Std_ReturnType, AUTOMATIC) Adc_ConThdRet = (Std_ReturnType)E_NOT_OK;
  VAR(Adc_HwUnitType, AUTOMATIC) unit = (Adc_HwUnitType)0;
  VAR(Adc_ChannelType, AUTOMATIC) ChCount = (Adc_ChannelType)0;
  VAR(Adc_ChannelType, AUTOMATIC) ch = (Adc_ChannelType)0;
  VAR(uint32, AUTOMATIC) ThValue = ADC_LOW_TH0_VALUE(LowValue) | ADC_HIGH_TH0_VALUE(HighValue);

  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  unit = ADC_GroupUnit(GroupId);

  /* Check the channels in the group one by one, set the threshold values if threshold is enabled */
  /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
  for(ChCount=(Adc_ChannelType)0U;ChCount <Adc_Cfg_Ptr->Groups[GroupId].AssignedChannelCount; ChCount++)
  {
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ch = Adc_Cfg_Ptr->Groups[GroupId].Assignment[ChCount];
    /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(Adc_Cfg_Ptr->Channels[unit][ch].ThValues != ADC_UNUSED_THRESHOLD)
    {
      {
      #ifdef IPV_ADCDIG
        #ifdef IPV_ADCDIG_31201_BOLERO256K /* Bolero 256k-128k */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((Adc_Cfg_Ptr->Channels[unit][ch].ThReg <= ADC_THRESHOLD_REG_2))
        {
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          REG_WRITE32(ADC_THRHLRx_REG(unit, Adc_Cfg_Ptr->Channels[unit][ch].ThReg), ThValue);
          Adc_ConThdRet = (Std_ReturnType)E_OK;
        }
        #else /* !Bolero 256k-128k */
        /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((Adc_Cfg_Ptr->Channels[unit][ch].ThReg <= ADC_THRESHOLD_REG_3))
        {
          /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_3 cast from unsigned int to pointer. */
          /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
          REG_WRITE32(ADC_THRHLRx_REG(unit, Adc_Cfg_Ptr->Channels[unit][ch].ThReg), ThValue);
          Adc_ConThdRet = (Std_ReturnType)E_OK;
        }
        else
        {
          /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2 or Pictus1M or Komodo 2M or Leopard2M or Calypso */
          #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
            #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
            /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if(Adc_Cfg_Ptr->Channels[unit][ch].ThReg >= ADC_THRESHOLD_REG_4)
            {
              /* @violates @ref Adc_ADCDig_LLD_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_3 cast from unsigned int to pointer. */
              /* @violates @ref Adc_ADCDig_LLD_c_REF_9 cast from unsigned long to pointer */
              REG_WRITE32(ADC_THRHLR_4_5x_REG(unit,((uint32)Adc_Cfg_Ptr->Channels[unit][ch].ThReg - (uint32)ADC_THRESHOLD_REG_4)), \
                ThValue);

              Adc_ConThdRet = (Std_ReturnType)E_OK;
            }
            #endif /* ifndef IPV_ADCDIG_31301_PICTUS1M */
          #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
              (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */
        }
        #endif /* ifdef IPV_ADCDIG_31201_BOLERO256K */
      #endif /* ifdef IPV_ADCDIG */
      }
    }
  }

  return Adc_ConThdRet;
}
#endif /* if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_ADCDig_LLD_c_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_ADCDig_LLD_c_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
