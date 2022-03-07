/**
*   @file    Adc_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Interrupt Low Level Driver source file.
*   @details  Autosar Adc Interrupt Low Level Driver source file.
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
* @section Adc_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
* 
* @section Adc_Irq_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.3, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller.
* The address calculated as an unsigned int is passed to  a macro for initializing the
* pointer with that address (ex: see REG_WRITE32 macro).
*
* @section Adc_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
* 
* @section Adc_Irq_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This is used for the Speed optimization of the memory access.
* 
* @section Adc_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 14.2, Expected void type, assignment, increment or decrement.
* This is used to read an unused value from an register.
*
* @section Adc_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer 
* arithmetic but used due to the code complexity.
*
* @section Adc_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware ofsset of the controller. The address calculated as
* an unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_Irq_c_REF_9
* Violates MISRA 2004 Required Rule 12.4, contain side effects of right-hand operand of a logical
* && or ||. This is used for the code complexity.
*
* @section Adc_Irq_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is to be used by LLD layer.
*
* @section Adc_Irq_c_REF_11
* Violates MISRA 2004 Required Rule 10.1, Cast from integer type to different type or a wider integer type
* This is used for the Speed optimization of the memory access.
*
* @section Adc_Irq_c_REF_12
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
* @section Adc_Irq_c_REF_13
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section Adc_Irq_c_REF_14
* Violates MISRA 2004 Required Rule 14.10, All if ... else if constructs shall be terminated with
* an else clause. This violation is due to pre-compilation macro conditions.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @implements     DADC00007 */
#include "Adc.h"
#include "Adc_LLD.h"
#include "Dma_LLD.h"
#include "Adc_CTU_LLD.h"
/* @violates @ref Adc_Irq_c_REF_2 Repeated include file */
#include "Mcal.h"
#include "SchM_Adc.h"
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* @violates @ref Adc_Irq_c_REF_2 Repeated include file */
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DADC04005 */
#define ADC_IRQ_C_AR_VENDOR_ID                 (43)
/* @violates @ref Adc_Irq_c_REF_12 Identifier exceeds 31 characters */
#define ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION     (4)
/* @violates @ref Adc_Irq_c_REF_12 Identifier exceeds 31 characters */
#define ADC_IRQ_C_AR_RELEASE_MINOR_VERSION     (0)
/* @violates @ref Adc_Irq_c_REF_12 Identifier exceeds 31 characters */
#define ADC_IRQ_C_AR_RELEASE_REVISION_VERSION  (3)
#define ADC_IRQ_C_SW_MAJOR_VERSION             (1)
#define ADC_IRQ_C_SW_MINOR_VERSION             (0)
#define ADC_IRQ_C_SW_PATCH_VERSION             (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06007 */
/* Check if source file and ADC header file are from the same vendor */
#if (ADC_IRQ_C_AR_VENDOR_ID != ADC_VENDOR_ID)
    #error "Adc_Irq.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_Irq.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_IRQ_C_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION) || \
     (ADC_IRQ_C_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION) || \
     (ADC_IRQ_C_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
  #error "Software Version Numbers of Adc_Irq.c and Adc.h are different"
#endif

/* Check if source file and ADC LLD header file are from the same vendor */
#if (ADC_IRQ_C_AR_VENDOR_ID != ADC_LLD_H_VENDOR_ID)
    #error "Adc_Irq.c and Adc_LLD.h have different vendor ids"
#endif

/* Check if source file and ADC LLD header file are of the same Autosar version */
#if ((ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION != ADC_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_MINOR_VERSION != ADC_LLD_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_REVISION_VERSION != ADC_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_Irq.c and Adc_LLD.h are different"
#endif

/* Check if source file and ADC LLD header file are of the same Software version */
#if ((ADC_IRQ_C_SW_MAJOR_VERSION != ADC_LLD_H_SW_MAJOR_VERSION) || \
     (ADC_IRQ_C_SW_MINOR_VERSION != ADC_LLD_H_SW_MINOR_VERSION) || \
     (ADC_IRQ_C_SW_PATCH_VERSION != ADC_LLD_H_SW_PATCH_VERSION))
  #error "Software Version Numbers of Adc_Irq.c and Adc_LLD.h are different"
#endif

/* Check if source file and DMA header file are from the same vendor */
#if (ADC_IRQ_C_AR_VENDOR_ID != DMA_VENDOR_ID)
    #error "Adc_Irq.c and Dma_LLD.h have different vendor ids"
#endif

/* Check if source file and DMA header file are of the same Autosar version */
#if ((ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION != DMA_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_MINOR_VERSION != DMA_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_REVISION_VERSION != DMA_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Adc_Irq.c and Dma_LLD.h are different"
#endif

/* Check if source file and DMA header file are of the same Software version */
#if ((ADC_IRQ_C_SW_MAJOR_VERSION != DMA_SW_MAJOR_VERSION) || \
     (ADC_IRQ_C_SW_MINOR_VERSION != DMA_SW_MINOR_VERSION) || \
     (ADC_IRQ_C_SW_PATCH_VERSION != DMA_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_Irq.c and Dma_LLD.h are different"
#endif

#if (ADC_IRQ_C_AR_VENDOR_ID != CTU_VENDOR_ID)
    #error "Adc_Irq.c and Adc_CTU_LLD.h have different vendor ids"
#endif

/* Check if source file and CTUV2 header file are of the same Autosar version */
#if ((ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION != CTU_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_MINOR_VERSION != CTU_AR_RELEASE_MINOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_REVISION_VERSION != CTU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_Irq.c and Adc_CTU_LLD.h are different"
#endif

/* Check if source file and CTU header file are of the same Software version */
#if ((ADC_IRQ_C_SW_MAJOR_VERSION != CTU_SW_MAJOR_VERSION) || \
     (ADC_IRQ_C_SW_MINOR_VERSION != CTU_SW_MINOR_VERSION) || \
     (ADC_IRQ_C_SW_PATCH_VERSION != CTU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_Irq.c and Adc_CTU_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
 /* Check if source file and Dem header file are of the same version */
 #if ((ADC_IRQ_C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IRQ_C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Adc_Irq.c and Dem.h are different"
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
/* @violates @ref Adc_Irq_c_REF_2 Repeated include file MemMap.h */
/* @violates @ref Adc_Irq_c_REF_12 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Adc_Irq_c_REF_2 Repeated include file */
#include "MemMap.h"

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
/**
 * @brief   Global Flag to check if continuous group needs to be restarted in Adc_EndNormalConv()
 */
/* @violates @ref Adc_Irq_c_REF_10 Declaration and definition of objects or function */
VAR(uint32, ADC_VAR) Adc_ErrataApplied = (uint32)0;
#endif /* (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015) */

/*
* @violates @ref Adc_Irq_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Irq_c_REF_2 Repeated include file MemMap.h
*/
/* @violates @ref Adc_Irq_c_REF_12 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Adc_Irq_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Irq_c_REF_2 Repeated include file */
#include "MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* @violates @ref Adc_Irq_c_REF_12 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Adc_Irq_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
/* @violates @ref Adc_Irq_c_REF_1 only preprocessor statements and comments before "#include" */
#include "MemMap.h"

/* @violates @ref Adc_Irq_c_REF_12 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Adc_Irq_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
/* @violates @ref Adc_Irq_c_REF_1 only preprocessor statements and comments before "#include" */
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
/*
* @violates @ref Adc_Irq_c_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
/* @violates @ref Adc_Irq_c_REF_1 only preprocessor statements and comments before "#include" */
#include "MemMap.h"

STATIC INLINE void Adc_EndNormalConv(Adc_HwUnitType unit);

#if (ADC_HW_TRIGGER_API == STD_ON)
STATIC INLINE void Adc_EndInjectedConv(Adc_HwUnitType unit);
STATIC INLINE void Adc_EndCTUConv(Adc_HwUnitType unit);
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
STATIC INLINE void Adc_EndMultipleCTUConv(Adc_HwUnitType unit);
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

STATIC INLINE void Adc_EndSwInjectedConv(Adc_HwUnitType unit);

#ifdef ADC_DMA_SUPPORTED
STATIC INLINE void Adc_DMAEndNormalConv(Adc_HwUnitType unit, Adc_GroupType Group);
STATIC INLINE void Adc_DMAEndInjectedConv(Adc_HwUnitType unit, Adc_GroupType Group);
STATIC INLINE void Adc_DMAEndGroupConversion(Adc_HwUnitType unit);
ISR(Adc_DMAEndGroupConvUnit0);
  #ifdef IPV_ADCDIG
    /* If Bolero 1.5M */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) 
    ISR(Adc_DMAEndGroupConvUnit1);
    #endif
  #endif
#endif /* ADC_DMA_SUPPORTED */

STATIC INLINE void Adc_EndGroupConversion(Adc_HwUnitType unit);

#ifdef ADC_WDG_SUPPORTED
STATIC INLINE void Adc_WDGThresholdHandler(Adc_HwUnitType unit);
#ifdef IPV_ADCDIG
  /* if Bolero 1.5M or Bolero 256k */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
  STATIC void Adc_EndWDGInterrupt(Adc_HwUnitType unit);
  #endif /*#if(IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
#endif /* #ifdef IPV_ADCDIG */
ISR(Adc_WatchDogThresholdUnit0);
  #ifdef IPV_ADCDIG
    /* if Bolero 1.5M */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
    ISR(Adc_WatchDogThresholdUnit1);
    #endif
  #endif
#endif /* ADC_WDG_SUPPORTED */

ISR(Adc_EndGroupConvUnit0);
#ifdef IPV_ADCDIG
  /* if Bolero 1.5M */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
  ISR(Adc_EndGroupConvUnit1);
  #endif
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief          This function handles the normal conversion ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04006.
*
*/
STATIC INLINE void Adc_EndNormalConv(Adc_HwUnitType unit)
{
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  VAR(Adc_ChannelType, AUTOMATIC) ch = (Adc_ChannelType)0;
  VAR(Adc_ChannelType, AUTOMATIC) ChIndex = (Adc_ChannelType)0;
  VAR(volatile uint32, AUTOMATIC) Timeout;
  /* Streaming num samples should be at least 1U */
  VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = (Adc_StreamNumSampleType)1U;
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    VAR(uint8, AUTOMATIC) callNotification = (uint8)0;
#endif /* STD_ON==ADC_GRP_NOTIF_CAPABILITY */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
 /* flag to set if ADC results are in the range selected */
  VAR(boolean,AUTOMATIC) flag = (boolean)TRUE;
  VAR(uint32, AUTOMATIC) Adc_CDR_value;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  VAR(uint32, AUTOMATIC) Adc_Ncmrx_Value[3] = {0x0U, 0x0U, 0x0U};
  VAR(uint32, AUTOMATIC) Adc_Ceocfrx_Value[3] = {0x0U, 0x0U, 0x0U};
  VAR(uint32, AUTOMATIC) Adc_MsrValue = 0x0UL;
  VAR(uint32, AUTOMATIC) Adc_McrValue = 0x0UL;
#endif

  /* enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14();

  Group=(ADC_UnitStatus[unit].Queue[0]);
#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)

  /* Check for spurious interrupt for errata */

  /* Clear the interrupt before checking NSTART */
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);

  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  Adc_MsrValue = (uint32)(REG_READ32(ADC_MSR_REG(unit)));
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  Adc_McrValue = (uint32)(REG_READ32(ADC_MCR_REG(unit)));

  if ((Adc_MsrValue & ADC_NORMAL_CONV_STATUS) == ADC_NORMAL_CONV_ONGOING)
  {
    if ((Adc_McrValue & ADC_CONVERSION_MODE) == ADC_ONE_SHOT_MODE)
    {
      /* Errata Addendum case: This is a spurious interrupt */

      /* Exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
      /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
      return;
    }
  }

  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  Adc_Ncmrx_Value[0] = REG_READ32(ADC_NCMR0_REG(unit));
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  Adc_Ceocfrx_Value[0] = REG_READ32(ADC_CEOCFR0_REG(unit));
  Adc_Ncmrx_Value[0] = ((Adc_Ncmrx_Value[0]) ^ (Adc_Ceocfrx_Value[0] & Adc_Ncmrx_Value[0]));

  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  Adc_Ncmrx_Value[1] = REG_READ32(ADC_NCMR1_REG(unit));
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  Adc_Ceocfrx_Value[1] = REG_READ32(ADC_CEOCFR1_REG(unit));
  Adc_Ncmrx_Value[1] = ((Adc_Ncmrx_Value[1]) ^ (Adc_Ceocfrx_Value[1] & Adc_Ncmrx_Value[1]));

  /* @violates @ref Adc_Irq_c_REF_11 cast from integer type to a other type or a wider integer type */
  if (ADC_UNIT_0 == unit)
  {
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    Adc_Ncmrx_Value[2] = REG_READ32(ADC_NCMR2_REG(unit));
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    Adc_Ceocfrx_Value[2] = REG_READ32(ADC_CEOCFR2_REG(unit));
    Adc_Ncmrx_Value[2] = ((Adc_Ncmrx_Value[2]) ^ (Adc_Ceocfrx_Value[2] & Adc_Ncmrx_Value[2]));
  }

  /* Check the CEOCFRx registers to know the channels for which the conversion were completed */
  /* @violates @ref Adc_Irq_c_REF_11 cast from integer type to a other type or a wider integer type */
  if( (Adc_Ncmrx_Value[0] != 0) || (Adc_Ncmrx_Value[1] != 0) || (Adc_Ncmrx_Value[2] != 0) )
  {
    /* The conversion is not completed for all channels in the group */
    Adc_ErrataApplied = (uint32)1;

    /* stop any ongoing continuous conversion */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    if (((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING)
    {
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_NORMAL_CONV_STOP);
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_NCMR0_REG(unit), 0x00000000UL);
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_NCMR1_REG(unit), 0x00000000UL);
      /* @violates @ref Adc_Irq_c_REF_11 cast from integer type to a other type or a wider integer type */
      if (ADC_UNIT_0 == unit)
      {
        /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
        REG_WRITE32(ADC_NCMR2_REG(unit), 0x00000000UL);
      }

      Timeout = ADC_TIMEOUT_COUNTER;
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING)&&
          /* @violates @ref Adc_Irq_c_REF_9 contain side effects of right-hand operand */
          (Timeout > (uint32)0U))
      {
        Timeout--;
      }
      if (Timeout == (uint32)0U)
      {
        /* Report production error */
        #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
          if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
          {
            Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
          }
        #endif
      }
    }

    /* Clear the pending interrupts */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);

    /* Clear any pending channel flags (CEOCFRx) */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    ADC_CLEAN_CHANNEL_PENDING_REGS(unit);

    /* Load NCMRx once again with pending channels */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_NCMR0_REG(unit), Adc_Ncmrx_Value[0]);
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_NCMR1_REG(unit), Adc_Ncmrx_Value[1]);
    /* @violates @ref Adc_Irq_c_REF_11 cast from integer type to a other type or a wider integer type */
    if (ADC_UNIT_0 == unit)
    {
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_NCMR2_REG(unit), Adc_Ncmrx_Value[2]);
    }

    /* and start a one-shot conversion for these pending channels */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_BIT_CLEAR32(ADC_MCR_REG(unit),ADC_CONVERSION_MODE);
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_BIT_SET32(ADC_MCR_REG(unit), ADC_NORMAL_START_CONV_EN);

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
    /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
    return;
  }

  /* Clear the channels status, so we get the updated status for the next round of conversion */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  REG_WRITE32(ADC_CEOCFR0_REG(unit), ((uint32)(Adc_Cfg_Ptr->Groups[Group].Adc_PrecisionChannel)));
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  REG_WRITE32(ADC_CEOCFR1_REG(unit), ((uint32)(Adc_Cfg_Ptr->Groups[Group].Adc_ExtendedChannel)));
  /* @violates @ref Adc_Irq_c_REF_11 cast from integer type to a other type or a wider integer type */
  if (ADC_UNIT_0 == unit)
  {
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    REG_WRITE32(ADC_CEOCFR2_REG(unit), ((uint32)(Adc_Cfg_Ptr->Groups[Group].Adc_ExternalChannel)));
  }

#endif /* (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015) */

  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  pResult = (Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] + ADC_GroupStatus[Group].ResultIndex);
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  GroupSamples = (Adc_Cfg_Ptr->Groups[Group].NumSamples);
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  for(ch=(Adc_ChannelType)0U;ch <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; ch++)
  {
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    ChIndex = Adc_GroupChannelIndex(Group,ch);
    
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck == (boolean)TRUE)
    {
        flag = (boolean)ADCDig_LLD_CheckConversionValuesInRange((uint16)Adc_CDR_value, unit, ChIndex);
        if (flag == (boolean)TRUE)
        {
          /* ADC446 */
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          *(pResult+(ch*(GroupSamples)))=(uint16)Adc_CDR_value;
        }
        else /* ADC448, ADC449, ADC450*/
        {
          ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          if (Adc_Cfg_Ptr->Groups[Group].mode ==  ADC_CONV_MODE_ONESHOT)
          {
            /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
            REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_NORM_CONV_MASK);
          #if (ADC_ENABLE_QUEUING == STD_ON)
            ADCDig_RemoveFromQueue(unit,(uint8)0);
            if (ADC_UnitStatus[unit].QueueIndex>(Adc_QueueIndexType)0U)
            {
              Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
            }
          #else
            /* no element will be present in the queue */
            ADC_UnitStatus[unit].QueueIndex= (Adc_QueueIndexType)0;
          #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
          }

          /* ADC078 */
          /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
          REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
          /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
          return;
        }
    }
    else /* (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck = (boolean)FALSE) */
    {
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        *(pResult+(ch*(GroupSamples)))=(uint16)Adc_CDR_value;
    }
#else
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    /* @violates @ref Adc_Irq_c_REF_8 pointer arithmetic other than array indexing used */
    *(pResult+(ch*(GroupSamples)))=(uint16)REG_READ32(ADC_CH_DATA_REG(unit,Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  }

  /* increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
  ADC_GroupStatus[Group].ResultIndex++;
   /* at least once the group was converted */
  ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
  /* ADC447 */
  if(ADC_GroupStatus[Group].Conversion == ADC_BUSY)
  {
    /* ADC224 */
    ADC_GroupStatus[Group].Conversion = ADC_COMPLETED;
  }

  if (ADC_GroupStatus[Group].ResultIndex >= GroupSamples) /* if all samples completed, wrap to 0 */
  {
    /* ADC325 */
    ADC_GroupStatus[Group].Conversion=ADC_STREAM_COMPLETED;
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if((Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)&& \
       (Adc_Cfg_Ptr->Groups[Group].AccessMode==ADC_ACCESS_MODE_STREAMING))
    {
      /* ADC078 */
      /* the following code stop the conversion and abort the current group conversion,
         is important to abort the current, othewise, another interrupt occurs after the stop */
      Timeout = ADC_TIMEOUT_COUNTER;
      /* @violates @ref Adc_Irq_c_REF_9 contain side effects of right-hand operand */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING)&& \
            (Timeout > (uint32)0U))
      {
        #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0014)
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
          ADC_SWITCH_TO_ONE_SHOT_MODE(unit);
        #else
          /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
          REG_BIT_SET32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
        #endif
        /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
        /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_NORMAL_CONV_STOP);
        Timeout--;
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
          
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
          #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
            Adc_ErrataApplied = (uint32)0;
          #endif
          /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
          return;
      }
      else /* ENGR00127057 */
      {
          VAR(Adc_ChannelType, AUTOMATIC) ch_temp;
          VAR(Adc_ChannelType, AUTOMATIC) ChIndex_temp;
          /* clear VALID bit from ADC result registers for all channels assigned to the group
             when conversion is aborted*/
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          for(ch_temp=(Adc_ChannelType)0U; \
              ch_temp <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; \
              ch_temp++)
          {
            /* @violates @ref Adc_Irq_c_REF_5 expected another indexing */
            /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            ChIndex_temp = Adc_Cfg_Ptr->Groups[Group].Assignment[ch_temp];
            /* @violates @ref Adc_Irq_c_REF_6 Expected void type, assignment, increment or decrement. */
            /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
            /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex_temp].ChId));
          }
      }
      /* ADC078 */
      /* Disable Interrupt Mask */
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_NORM_CONV_MASK);
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);
      ADC_UnitStatus[unit].Status=ADC_IDLE;
#if (ADC_ENABLE_QUEUING == STD_ON)
      ADCDig_RemoveFromQueue(unit,(uint8)0U);

      if (ADC_UnitStatus[unit].QueueIndex> (Adc_QueueIndexType)0U)
      {
        Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
      }
#else
        /* no element will be present in the queue */
        ADC_UnitStatus[unit].QueueIndex= (Adc_QueueIndexType)0;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
      /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&& \
          (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
        /* ADC078 -- ADC104 -- ADC085*/
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        Adc_Cfg_Ptr->Groups[Group].Notification();
      }
      else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
      }
      #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
        Adc_ErrataApplied = (uint32)0;
      #endif
      /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
      return;
    }
    ADC_GroupStatus[Group].ResultIndex = 0U;
  }

  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if (Adc_Cfg_Ptr->Groups[Group].mode ==  ADC_CONV_MODE_ONESHOT)
  {
    /* ADC325 */
    ADC_GroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;
    ADC_UnitStatus[unit].Status = ADC_COMPLETED;
    /* call notification function */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /* ADC083 -- ADC416 -- ADC080-- ADC060*/
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&& \
        (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
    {
      /* ADC078 -- ADC104 -- ADC085*/
      callNotification = (uint8)1;
    }
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */

    /* Disable Interrupt Mask*/
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_NORM_CONV_MASK);
#if (ADC_ENABLE_QUEUING == STD_ON)
    ADCDig_RemoveFromQueue(unit,(uint8)0);

    if (ADC_UnitStatus[unit].QueueIndex>(Adc_QueueIndexType)0U)
    {
      Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
    }
#else

     /* no element will be present in the queue */
     ADC_UnitStatus[unit].QueueIndex= (Adc_QueueIndexType)0;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
  }
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  else if (Adc_Cfg_Ptr->Groups[Group].mode ==  ADC_CONV_MODE_CONTINUOUS)
  {
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&& \
        (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
    {
      /* ADC078 -- ADC104 -- ADC085*/
      callNotification = (uint8)1;
    }
    #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    
    #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
    /* If the continuous group was stopped in the Errata Workaround, resume it */
    if ((uint32)1 == Adc_ErrataApplied)
    {
      /* Note: Adc_LLD_StartNormalConversion also sets ADC_GroupStatus[Group].ResultIndex = 0,
      but this is not what we want */
      GroupSamples = ADC_GroupStatus[Group].ResultIndex;
      Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
      ADC_GroupStatus[Group].ResultIndex = GroupSamples;
    }
    #endif /* if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015) */

  }
  else
  {
        /* Catastrophic Errors Recovery (CER) */
        Cer_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_ENDNORMALCONV_ID,
                        (uint8)ADC_CER_MODE_TYPE_INT);
  }

  /* ADC078 */
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_NORM_CLEAN);

  /* exit critical region */
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
  /* ADC083 -- ADC416 -- ADC080-- ADC060*/
  if (callNotification == (uint8)1)
  {
    /* call group notification */
    /* ADC078 -- ADC104 -- ADC085*/
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    Adc_Cfg_Ptr->Groups[Group].Notification();
  }
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  Adc_ErrataApplied = (uint32)0;
#endif
}

/**
* @brief          This function handles the injected conversion ending.
* @details        When a SW injected conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04007.
*
*/
STATIC INLINE void Adc_EndSwInjectedConv(Adc_HwUnitType unit)
{
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  VAR(Adc_ChannelType, AUTOMATIC) ch = (Adc_ChannelType)0;
  VAR(Adc_ChannelType, AUTOMATIC) ChIndex = (Adc_ChannelType)0;
  /* Streaming num samples should be at least 1U */
  VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = (Adc_StreamNumSampleType)1U;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* flag to set if ADC results are in the range selected */
  VAR(boolean,AUTOMATIC) flag = (boolean)TRUE;
  VAR(uint32, AUTOMATIC) Adc_CDR_value;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

  /* enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24();

  Group=(ADC_UnitStatus[unit].SwInjQueue[0]);
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] + ADC_GroupStatus[Group].ResultIndex;
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  GroupSamples = (Adc_Cfg_Ptr->Groups[Group].NumSamples);
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  for(ch=(Adc_ChannelType)0U;ch <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; ch++)
  {
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    ChIndex = Adc_GroupChannelIndex(Group,ch);
    
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
/* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit,Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck == (boolean)TRUE)
    {
        flag = (boolean)ADCDig_LLD_CheckConversionValuesInRange((uint16)Adc_CDR_value, unit, ChIndex);
        if (flag == (boolean)TRUE)
        {
          /* ADC446 */
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          *(pResult+(ch*(GroupSamples)))=(uint16)Adc_CDR_value;
        }
        else /* ADC448, ADC449, ADC450*/
        {
          /* at least once the group was converted */
          ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
          ADC_GroupStatus[Group].ResultIndex = 0U;
          /* no element will be present in the sw inj queue */
          ADC_UnitStatus[unit].SwInjQueueIndex= (Adc_QueueIndexType)0;
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24();
          /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
          return;
        }
    }
    else /* (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck = (boolean)FALSE) */
    {
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        *(pResult+(ch*(GroupSamples)))=(uint16)Adc_CDR_value;
    }
#else
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    /* @violates @ref Adc_Irq_c_REF_8 pointer arithmetic other than array indexing used */
    *(pResult+(ch*(GroupSamples)))=(uint16)REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  }

  /* at least once the group was converted */
  ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

  /* ADC325, ADC447 */
  ADC_GroupStatus[Group].Conversion=ADC_STREAM_COMPLETED;

  ADC_GroupStatus[Group].ResultIndex = 0U;

  ADC_UnitStatus[unit].Status=ADC_COMPLETED;

  /* no element will be present in the sw inj queue */
  ADC_UnitStatus[unit].SwInjQueueIndex= (Adc_QueueIndexType)0;

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
  /* ADC083 -- ADC416 -- ADC080 -- ADC060 */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&& \
      (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24();
    /* ADC078 -- ADC104 -- ADC085 */
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    Adc_Cfg_Ptr->Groups[Group].Notification();
  }
  else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24();
  }
}

#if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__)
/**
* @brief          This function handles the injected conversion ending.
* @details        When a HW injected conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04008.
*
*/
STATIC INLINE void Adc_EndInjectedConv(Adc_HwUnitType unit)
{
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  VAR(Adc_ChannelType, AUTOMATIC) ch = (Adc_ChannelType)0;
  VAR(Adc_ChannelType, AUTOMATIC) ChIndex = (Adc_ChannelType)0;
  /* Streaming num samples should be at least 1U */
  VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = (Adc_StreamNumSampleType)1U;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* flag to set if ADC results are in the range selected */
  VAR(boolean,AUTOMATIC) flag = (boolean)TRUE;
  VAR(uint32, AUTOMATIC) Adc_CDR_value;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  VAR(uint32,ADC_VAR)Adc_NormalInterrupted = REG_READ32(ADC_MSR_REG(unit)) & ADC_NORMAL_CONV_STATUS;
#endif
  /* enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15();

  Group=(ADC_UnitStatus[unit].HwQueue[0]);
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] + ADC_GroupStatus[Group].ResultIndex;
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  GroupSamples = (Adc_Cfg_Ptr->Groups[Group].NumSamples);
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  for(ch=(Adc_ChannelType)0U;ch <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; ch++)
  {
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    ChIndex = Adc_GroupChannelIndex(Group,ch);

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit,Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck == (boolean)TRUE)
    {
        flag = (boolean)ADCDig_LLD_CheckConversionValuesInRange((uint16)Adc_CDR_value, unit, ChIndex);
        if (flag == (boolean)TRUE)
        {
          /* ADC446 */
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          *(pResult+(ch*(GroupSamples)))=(uint16)Adc_CDR_value;
        }
        else /* ADC448, ADC449, ADC450*/
        {
          /* at least once the group was converted */
          ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
          /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
          return;
        }
    }
    else /* (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck = (boolean)FALSE) */
    {
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        *(pResult+(ch*(GroupSamples)))=(uint16)Adc_CDR_value;
    }
#else
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    /* @violates @ref Adc_Irq_c_REF_8 pointer arithmetic other than array indexing used */
    *(pResult+(ch*(GroupSamples)))=(uint16)REG_READ32(ADC_CH_DATA_REG(unit,Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId));
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  }

  /* increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
  ADC_GroupStatus[Group].ResultIndex++;
  /* at least once the group was converted */
  ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
  /* ADC447 */
  if(ADC_GroupStatus[Group].Conversion ==ADC_BUSY)
  {
    /* ADC224*/
    ADC_GroupStatus[Group].Conversion=ADC_COMPLETED;
  }

  if (ADC_GroupStatus[Group].ResultIndex >= GroupSamples) /* if all samples completed, wrap to 0 */
  {
    /* ADC325 */
    ADC_GroupStatus[Group].Conversion = ADC_STREAM_COMPLETED;
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if((Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)&& \
       (Adc_Cfg_Ptr->Groups[Group].AccessMode == ADC_ACCESS_MODE_STREAMING))
    {
      /* Stop Conversion */
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
      ADC_UnitStatus[unit].Status=ADC_IDLE;
      /* ADC078 */
      /* Disable Interrupt Mask*/
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_MASK);
      /* ADC429 */
      ADC_GroupsInHwQueue(unit) = (Adc_QueueIndexType)0;

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
      /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&& \
          (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
        /* ADC078 -- ADC104 -- ADC085*/
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        Adc_Cfg_Ptr->Groups[Group].Notification();
      }
      else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
      }
      /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
      return;
    }
    ADC_GroupStatus[Group].ResultIndex = 0U;
  }

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  if ((uint32)0 == Adc_NormalInterrupted)
  {
#endif
    /* if any conversion is in queue */
    if ((ADC_UnitStatus[unit].InjConvOngoin == (boolean)TRUE) ||
        (ADC_UnitStatus[unit].QueueIndex>(Adc_QueueIndexType)0U))
    {
      ADC_UnitStatus[unit].InjConvOngoin = (boolean)FALSE;
      Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
    }
#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  }
#endif

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
  /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&& \
      (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
    /* ADC078 -- ADC104 -- ADC085*/
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    Adc_Cfg_Ptr->Groups[Group].Notification();
  }
  else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
  }
}

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          This function handles the end of a CTU conversion in the case
*                 of multiple hardware trigger.
* @details        When a CTU onversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04009.
*
*/
STATIC INLINE void Adc_EndMultipleCTUConv(Adc_HwUnitType unit)
{
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  volatile uint32 chanIntReg[3] = {(uint32)0,(uint32)0,(uint32)0};
  uint32 chanIntMask[3] = {(uint32)0,(uint32)0,(uint32)0};
  VAR(Adc_GroupType, AUTOMATIC) gr;
  /* Streaming num samples should be at least 1U */
  VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = (Adc_StreamNumSampleType)1U;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  VAR(Adc_ChannelType, AUTOMATIC) ch = (Adc_ChannelType)0;
  /* flag to set if ADC results are in the range selected */
  VAR(boolean,AUTOMATIC) flag = (boolean)TRUE;
  VAR(uint32, AUTOMATIC) Adc_CDR_value;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  
  /* enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();
/* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  chanIntReg[0] = REG_READ32(ADC_CEOCFR0_REG(unit));
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  chanIntReg[1] = REG_READ32(ADC_CEOCFR1_REG(unit));
  /* Bolero 1.5M */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
  if(unit==(Adc_HwUnitType)ADC_UNIT_0)
  {
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    chanIntReg[2] = REG_READ32(ADC_CEOCFR2_REG(unit));
  }
  #else /* Bolero 512K or Bolero 256K */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  chanIntReg[2] = REG_READ32(ADC_CEOCFR2_REG(unit));
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */

  for(gr=(Adc_GroupType)0U;gr<(Adc_GroupType)(Adc_Cfg_Ptr->Misc.ADC_HW_QUEUE_MAX_DEPTH[unit]);gr++)
  {
    VAR(uint32, AUTOMATIC) channelTemp;
    VAR(uint32, AUTOMATIC) mask;
    VAR(uint8, AUTOMATIC) register_index;

    channelTemp = Adc_LLD_MhtChannelGroup[unit][gr].chId;
    Group = Adc_LLD_MhtChannelGroup[unit][gr].grId;
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    GroupSamples = (Adc_Cfg_Ptr->Groups[Group].NumSamples);
    mask = Adc_LLD_MhtChannelGroup[unit][gr].mask;
    register_index = Adc_LLD_MhtChannelGroup[unit][gr].register_index;

    /* check if the current channel is triggered or not... */
    if( (chanIntReg[register_index] & ((uint32)(mask))) == ((uint32)(mask)))
    {
      chanIntMask[register_index] |= mask;
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      pResult=Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group]+ADC_GroupStatus[Group].ResultIndex;

      /* Clear the CTU interrupt flag */
      CTU_LLD_ClearTRGI();

      /* Clear CTU Interrupt status flag */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      if((REG_READ32(ADC_ISR_REG(unit))&ADC_ISR_END_CHANNEL_CTU_CONV)==ADC_ISR_END_CHANNEL_CTU_CONV)
      {
        /* Clear Interrupt status flag */
        /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
        REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV);
      }

      /* if we are here, there are only one channel in the group */
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      ch = Adc_Cfg_Ptr->Groups[Group].Assignment[0];
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit,channelTemp));
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      if (Adc_Cfg_Ptr->Channels[unit][ch].ChannelLimitCheck == (boolean)TRUE)
      {
        flag = (boolean)ADCDig_LLD_CheckConversionValuesInRange((uint16)Adc_CDR_value, unit, ch);
        if (flag == (boolean)TRUE)
        {
            /* ADC446 */
            *(pResult) = (uint16)Adc_CDR_value;
        }
        else /* ADC448, ADC449, ADC450*/
        {
            /* at least once the group was converted */
            ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
            /* exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
            /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
      }
      else /* (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck = (boolean)FALSE) */
      {
          *(pResult) = (uint16)Adc_CDR_value;
      }
#else
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      *(pResult) = (uint16)REG_READ32(ADC_CH_DATA_REG(unit,channelTemp));
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

      /*increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed*/
      ADC_GroupStatus[Group].ResultIndex++;

      /* at least once the group was converted */
      ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
      
      if(ADC_GroupStatus[Group].Conversion ==ADC_BUSY)
      {
        /* ADC224*/
        ADC_GroupStatus[Group].Conversion=ADC_COMPLETED;
      }

    if (ADC_GroupStatus[Group].ResultIndex >= GroupSamples) /* if all samples completed, wrap to 0*/
    {

      /* ADC325*/
      ADC_GroupStatus[Group].Conversion=ADC_STREAM_COMPLETED;
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      if( (Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR) &&
       /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          (Adc_Cfg_Ptr->Groups[Group].AccessMode == ADC_ACCESS_MODE_STREAMING) )
      {
        /* ADC429*/
        ADC_UnitStatus[unit].HwQueueIndex--;

        if (ADC_UnitStatus[unit].HwQueueIndex == (Adc_QueueIndexType)0)
        {
          /* Stop Conversion */
          /* Disable CTU in ADC MCR register is done into deinit funtion */
          /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
          /* REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CTU_ENABLED); */

          ADC_UnitStatus[unit].Status=ADC_IDLE;

          /* Disable Interrupt Mask*/
          /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
          REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV_EN);
        }

    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
        if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
        {
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
          /* ADC078 -- ADC104 -- ADC085*/
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          Adc_Cfg_Ptr->Groups[Group].Notification();
          /* enter critical region */
          SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();
        }
        else
    #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
        {
           /* Do nothing for Misra */

        }
      }
      else
      {
        ADC_GroupStatus[Group].ResultIndex = 0U;
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
        if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
        {
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
          /* ADC078 -- ADC104 -- ADC085*/
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          Adc_Cfg_Ptr->Groups[Group].Notification();
            /* enter critical region */
         SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();

        }
        else
    #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
        {
             /* Do nothing for misra */
        }
      }
    }
    else
    {
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
        if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
        {
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
          /* ADC078 -- ADC104 -- ADC085*/
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          Adc_Cfg_Ptr->Groups[Group].Notification();
          /* enter critical region */
         SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();
        }
        else
    #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
        {
          /* Do nothing for Misra */
        }
    }
    }
  }

   /* exit critical region */
   SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
          
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  REG_WRITE32(ADC_CEOCFR0_REG(unit),chanIntMask[0]);
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  REG_WRITE32(ADC_CEOCFR1_REG(unit),chanIntMask[1]);
 /* Bolero 1.5M */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
  if(unit==(Adc_HwUnitType)ADC_UNIT_0)
  {
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_CEOCFR2_REG(unit),chanIntMask[2]);
  }
 #else /* Bolero 512K or Bolero 256K */
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  REG_WRITE32(ADC_CEOCFR2_REG(unit),chanIntMask[2]);
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
}
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

/**
* @brief          This function handles the end of a CTU conversion.
* @details        When a CTU onversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04010.
*
*/
STATIC INLINE void Adc_EndCTUConv(Adc_HwUnitType unit)
{
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  VAR(Adc_ChannelType, AUTOMATIC) ch = (Adc_ChannelType)0;
  /* Streaming num samples should be at least 1U */
  VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = (Adc_StreamNumSampleType)1U;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* flag to set if ADC results are in the range selected */
  VAR(boolean,AUTOMATIC) flag = (boolean)TRUE;
  VAR(uint32, AUTOMATIC) Adc_CDR_value;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  VAR(uint32,ADC_VAR)Adc_NormalInterrupted = REG_READ32(ADC_MSR_REG(unit)) & ADC_NORMAL_CONV_STATUS;
#endif

  /* enter critical region */
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();

  Group=(ADC_UnitStatus[unit].HwQueue[0]);
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] + ADC_GroupStatus[Group].ResultIndex;
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  GroupSamples = (Adc_Cfg_Ptr->Groups[Group].NumSamples);

  /* Clear the CTU interrupt flag */
  CTU_LLD_ClearTRGI();

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  REG_WRITE32(ADC_CEOCFR0_REG(unit), ((uint32)(Adc_Cfg_Ptr->Groups[Group].Adc_PrecisionChannel)));
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  REG_WRITE32(ADC_CEOCFR1_REG(unit), ((uint32)(Adc_Cfg_Ptr->Groups[Group].Adc_ExtendedChannel)));
  if ((unit) == (Adc_HwUnitType)0)
  {
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    REG_WRITE32(ADC_CEOCFR2_REG(unit), ((uint32)(Adc_Cfg_Ptr->Groups[Group].Adc_ExternalChannel)));
  }
#else
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  ADC_CLEAN_CHANNEL_PENDING_REGS(unit);
#endif

  /* Clear CTU Interrupt status flag */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  if ((REG_READ32(ADC_ISR_REG(unit)) & ADC_ISR_END_CHANNEL_CTU_CONV)==ADC_ISR_END_CHANNEL_CTU_CONV)
  {
    /* Clear Interrupt status flag */
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV);
  }

  /* Start software injected Conversion for the rest of the channels */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if ((Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount) > (Adc_ChannelType) 1U)
  {
    ADC_UnitStatus[unit].InjConvOngoin = (boolean)TRUE;

    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_BIT_SET32(ADC_IMR_REG(unit), ADC_ISR_END_CHANNEL_INJ_CONV_EN);

    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_BIT_SET32(ADC_MCR_REG(unit), ADC_INJ_START_CONV_EN);

    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();

    /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
    return;
  }

  /* if we are here, there are only one channel in the group */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  ch = Adc_Cfg_Ptr->Groups[Group].Assignment[0];
  
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  Adc_CDR_value = REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ch].ChId));
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if (Adc_Cfg_Ptr->Channels[unit][ch].ChannelLimitCheck == (boolean)TRUE)
  {
    flag = (boolean)ADCDig_LLD_CheckConversionValuesInRange((uint16)Adc_CDR_value, unit, ch);
    if (flag == (boolean)TRUE)
    {
        /* ADC446 */
        *(pResult) = (uint16)Adc_CDR_value;
    }
    else /* ADC448, ADC449, ADC450*/
    {
        /* at least once the group was converted */
        ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
        /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
        return;
    }
  }
  else /* (Adc_Cfg_Ptr->Channels[unit][ChIndex].ChannelLimitCheck = (boolean)FALSE) */
  {
      *(pResult) = (uint16)Adc_CDR_value;
  }
#else
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  /* @violates @ref Adc_Irq_c_REF_8 pointer arithmetic other than array indexing used */
  *(pResult) = (uint16)REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ch].ChId));
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  
  /* increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
  ADC_GroupStatus[Group].ResultIndex++;
  
  /* at least once the group was converted */
  ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;
  
  /* ADC447 */
  if(ADC_GroupStatus[Group].Conversion ==ADC_BUSY)
  {
    /* ADC224*/
    ADC_GroupStatus[Group].Conversion=ADC_COMPLETED;
  }

  if (ADC_GroupStatus[Group].ResultIndex >= GroupSamples) /* if all samples completed, wrap to 0 */
  {

  /* ADC325*/
  ADC_GroupStatus[Group].Conversion=ADC_STREAM_COMPLETED;
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if((Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR) &&
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      (Adc_Cfg_Ptr->Groups[Group].AccessMode == ADC_ACCESS_MODE_STREAMING))
  {
    /* Stop Conversion */
    /* Disable CTU in ADC MCR register is done into deinit funtion */
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CTU_ENABLED); */

    ADC_UnitStatus[unit].Status=ADC_IDLE;

    /* ADC078 */
    /* Disable Interrupt Mask*/
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_BIT_CLEAR32(ADC_IMR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV_EN);

    /* ADC429: removed for ENGR131638 */
    /*ADC_GroupsInHwQueue(unit) = (Adc_QueueIndexType)0;*/

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
    if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
    {
      /* exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
      /* ADC078 -- ADC104 -- ADC085*/
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      Adc_Cfg_Ptr->Groups[Group].Notification();
    }
    else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    {
      /* exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
    }
    /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
    return;
  }
  ADC_GroupStatus[Group].ResultIndex = 0U;
  }

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  if ((uint32)0 == Adc_NormalInterrupted)
  {
#endif
    /* if any conversion is in queue */
    if (ADC_UnitStatus[unit].QueueIndex>(Adc_QueueIndexType)0U)
    {
      ADC_UnitStatus[unit].InjConvOngoin = (boolean)FALSE;
      Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
    }
#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0015)
  }
#endif

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
  /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
  if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
    /* ADC078 -- ADC104 -- ADC085*/
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    Adc_Cfg_Ptr->Groups[Group].Notification();
  }
  else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
  }
}
#endif /*#if (STD_ON==ADC_HW_TRIGGER_API)*/

#if defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function handles the normal conversion via DMA ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion DMA ISR is called, this function takes care about
*                 the driver and the module state transitions.
*
* @param[in]      unit        the current HW unit.
* @param[in]      Group       the handled group.
*
* @return         void
*
* @api
*
* @implements     DADC04011
*
*/
STATIC INLINE void Adc_DMAEndNormalConv(Adc_HwUnitType unit, Adc_GroupType Group)
{
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  VAR(volatile uint32, AUTOMATIC) Timeout;
  /* increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
  ADC_GroupStatus[Group].ResultIndex++;
  /* at least once the group was converted */
  ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

  if(ADC_GroupStatus[Group].Conversion ==ADC_BUSY)
  {
    /* ADC224 */
    ADC_GroupStatus[Group].Conversion=ADC_COMPLETED;
  }

#if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
  /* If the current group does not contain continuous ADC data channels, that means that the DMA
  transfer copied from the first configured ADC channel till the last one, every result,
  and for the user we should give back only the configured channels results.
  DMA, transfers in this case to an internal buffer, not directly to the user defined buffer. */

  if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_OFF)
  {
    VAR(Adc_ChannelType, AUTOMATIC) ch;
    VAR(Adc_ChannelType, AUTOMATIC) firstChIndex;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
    VAR(Adc_ChannelType, AUTOMATIC) phChIndex;
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group]+(ADC_GroupStatus[Group].ResultIndex-1U);
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    firstChIndex = (Adc_ChannelType)Adc_Cfg_Ptr->Groups[Group].Assignment[0];
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    firstChIndex =  Adc_Cfg_Ptr->Channels[unit][firstChIndex].ChId;
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    for(ch=(Adc_ChannelType)0U;ch <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; ch++)
    {
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      ChIndex = (Adc_ChannelType)Adc_Cfg_Ptr->Groups[Group].Assignment[ch];
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      phChIndex = Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId;
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      *(pResult+(ch*(Adc_Cfg_Ptr->Groups[Group].NumSamples))) =
      DmaInternalResultBuffer[unit][phChIndex-firstChIndex];
    }
  }
#endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */

  /* if all samples completed, wrap to 0 */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if (ADC_GroupStatus[Group].ResultIndex >= Adc_Cfg_Ptr->Groups[Group].NumSamples)
  {
    /* ADC325*/
    ADC_GroupStatus[Group].Conversion=ADC_STREAM_COMPLETED;
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if((Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)&&
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
       (Adc_Cfg_Ptr->Groups[Group].AccessMode==ADC_ACCESS_MODE_STREAMING))
    {
      /* the following code stop the conversion and abort the current group conversion,
      is important to abort the current, othewise, another interrupt occurs after the stop */
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      REG_WRITE32(ADC_DMAR0_REG(unit),ADC_DMAR_RESET_VALUE);
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      REG_WRITE32(ADC_DMAR1_REG(unit),ADC_DMAR_RESET_VALUE);
      /* Bolero 1.5M */
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
      if(unit==(Adc_HwUnitType)ADC_UNIT_0)
      {
        /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
        /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
        REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
      }
      #else /* Bolero 256K */
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
      #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
      
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      REG_WRITE32(ADC_DMAE_REG(unit), ADC_DMAE_RESET_VALUE);

      /* load the timeout counter */
      Timeout = ADC_TIMEOUT_COUNTER;
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      while((((REG_READ32(ADC_MSR_REG(unit)))&ADC_NORMAL_CONV_STATUS)==ADC_NORMAL_CONV_ONGOING)&&
      /* @violates @ref Adc_Irq_c_REF_9 contain side effects of right-hand operand */
            (Timeout > (uint32)0U))
      {
        #if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0014)
         /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
          ADC_SWITCH_TO_ONE_SHOT_MODE(unit);
        #else
          /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
          REG_BIT_SET32(ADC_MCR_REG(unit), ADC_ABORT_CHAIN);
        #endif
        /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_NORMAL_CONV_STOP);
        Timeout--;
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
          
          /* exit critical region */
          SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
          /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
          return;
      }
      else /* ENGR00127057 */
      {
          VAR(Adc_ChannelType, AUTOMATIC) ch_temp;
          VAR(Adc_ChannelType, AUTOMATIC) ChIndex_temp;
          /* clear VALID bit from ADC result registers for all channels assigned to the group when
             conversion is aborted */
          for(ch_temp=(Adc_ChannelType)0U;
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
              ch_temp <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount;
              ch_temp++)
          {
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            ChIndex_temp = Adc_Cfg_Ptr->Groups[Group].Assignment[ch_temp];
            /* @violates @ref Adc_Irq_c_REF_6 Expected void type, assignment, increment or decrement. */
            /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
            REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex_temp].ChId));
          }
      }
      if(unit==(Adc_HwUnitType)ADC_UNIT_0)
      {
        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
        }
      }
#ifdef IPV_ADCDIG
 /* if Bolero 1.5M */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
      {
        if(unit==(Adc_HwUnitType)ADC_UNIT_1)
        {
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
        }
      }
  #endif /*#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
#endif /* #ifdef IPV_ADCDIG */
      ADC_UnitStatus[unit].Status=ADC_IDLE;

#if (ADC_ENABLE_QUEUING == STD_ON)
      ADCDig_RemoveFromQueue(unit,(uint8)0U);

      /* if any conversion is in queue */
      if (ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType)0U)
      {
        Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
      }
#else
      /* no element will be present in the queue */
      ADC_UnitStatus[unit].QueueIndex = (Adc_QueueIndexType)0;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
      /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
      if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
        /* ADC078 -- ADC104 -- ADC085*/
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        Adc_Cfg_Ptr->Groups[Group].Notification();
      }
      else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
      }
      /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
      return;
    }
    ADC_GroupStatus[Group].ResultIndex = 0U;
  }
/* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if (Adc_Cfg_Ptr->Groups[Group].mode==ADC_CONV_MODE_CONTINUOUS)
  {
      /* configure the source address in TCD of the DMA channels */
      LLM_Wr_DMA_TCD_SADDR(((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[unit]),
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      (ADC_ADDRESS(unit) + ADC_CH_DATA_REG_OFFSET + (uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)));

#if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
      if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_ON)
#endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
      {
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group] +ADC_GroupStatus[Group].ResultIndex;
          /* configure the destination result address in TCD of the DMA channels */
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
          LLM_Wr_DMA_TCD_DADDR(((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[unit]),pResult);
      }
#if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
      else
      {
          /* configure the destination result address in TCD of the DMA channels */
          LLM_Wr_DMA_TCD_DADDR(((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[unit]),
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
          DmaInternalResultBuffer[unit]);
      }
#endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
    if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
    {
      /* ADC078 -- ADC104 -- ADC085*/
      /* exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      Adc_Cfg_Ptr->Groups[Group].Notification();
    }
    else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    {
      /* exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
    }
    /* Start the DMA channel */
    if(unit==(Adc_HwUnitType)ADC_UNIT_0)
    {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
      {
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
        Dma_start_channel( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
      }
    }
  #ifdef IPV_ADCDIG
    /* if Bolero 1.5M */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
    {
      if(unit==(Adc_HwUnitType)ADC_UNIT_1)
      {
        /* Disable DMA interrupt */
        /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
        Dma_start_channel( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
      }
    }
      #endif /*#if(IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
  #endif /* #ifdef IPV_ADCDIG */
  }
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  else if (Adc_Cfg_Ptr->Groups[Group].mode==ADC_CONV_MODE_ONESHOT)
  {
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
    REG_WRITE32(ADC_DMAR0_REG(unit),ADC_DMAR_RESET_VALUE);
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
    REG_WRITE32(ADC_DMAR1_REG(unit),ADC_DMAR_RESET_VALUE);
    /* Bolero 1.5M */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
    if(unit==(Adc_HwUnitType)ADC_UNIT_0)
    {
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
    }
    #else /* Bolero 256k */
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
    REG_WRITE32(ADC_DMAR2_REG(unit),ADC_DMAR_RESET_VALUE);
    #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
    
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
    REG_WRITE32(ADC_DMAE_REG(unit), ADC_DMAE_RESET_VALUE);
    
    if(unit==(Adc_HwUnitType)ADC_UNIT_0)
    {
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
      {
        Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
      }
    }
#ifdef IPV_ADCDIG
 /* if Bolero 1.5M */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
    {
      if(unit==(Adc_HwUnitType)ADC_UNIT_1)
      {
        /* Disable DMA interrupt */
        Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
      }
    }
  #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
#endif /* #ifdef IPV_ADCDIG */

    /* ADC325*/
    ADC_GroupStatus[Group].Conversion=ADC_STREAM_COMPLETED;
    ADC_UnitStatus[unit].Status=ADC_COMPLETED;

#if (ADC_ENABLE_QUEUING == STD_ON)
    ADCDig_RemoveFromQueue(unit,(uint8)0);

    /* if any conversion is in queue */
    if (ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType)0U)
    {
      Adc_LLD_StartNormalConversion((Adc_HwUnitType)unit);
    }
#else
    /* no element will be present in the queue */
    ADC_UnitStatus[unit].QueueIndex = (Adc_QueueIndexType)0;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

    /* call notification function */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /* ADC083 -- ADC416 -- ADC080-- ADC060*/
    if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
    {
      /* exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
      /* ADC078 -- ADC104 -- ADC085*/
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      Adc_Cfg_Ptr->Groups[Group].Notification();
    }
    else
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    {
      /* exit critical region */
      SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
    }
  }
  else
  {
        /* Catastrophic Errors Recovery (CER) */
        Cer_ReportError((uint16)ADC_MODULE_ID,
                        (uint8)0U,
                        (uint8)ADC_DMAENDNORMALCONV_ID,
                        (uint8)ADC_CER_MODE_TYPE_INT);
  }
}
#endif /* defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__) */

#if defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__)
/**
 * @brief   This function handles the Injected conversion via DMA ending.
 * @details When a Injected conversion ends, and the end of
 *          conversion DMA ISR is called, this function takes care about
 *          the driver and the module state.
 *
 * @param[in]   unit        the current HW unit.
 * @param[in]   Group       the handled group.
 *
 * @return         void
 *
 * @api
 *
 * @implements     DADC04107
 */
STATIC INLINE void Adc_DMAEndInjectedConv(Adc_HwUnitType unit, Adc_GroupType Group)
{
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
  
  /* increment ResultIndex with modulo 'NumSamples' to remember another sample is completed */
  ADC_GroupStatus[Group].ResultIndex++;
  /* at least once the group was converted */
  ADC_GroupStatus[Group].AlreadyConverted = ADC_ALREADY_CONVERTED;

  if(ADC_GroupStatus[Group].Conversion ==ADC_BUSY)
  {
    /* ADC224*/
    ADC_GroupStatus[Group].Conversion=ADC_COMPLETED;
  }

#if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
  /* If the current group does not contain continuous ADC data channels, that means that
     the DMA transfer copied from the first configured ADC channel till the last one,
     every result, and for the user we should give back only the configured channels results.
     DMA, transfers in this case to an internal buffer, not directly to the user defined buffer.
  */
  if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_OFF)
  {
    VAR(Adc_ChannelType, AUTOMATIC) ch;
    VAR(Adc_ChannelType, AUTOMATIC) firstChIndex;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
    VAR(Adc_ChannelType, AUTOMATIC) phChIndex;
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group]+(ADC_GroupStatus[Group].ResultIndex-1U);
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    firstChIndex = (Adc_ChannelType)Adc_Cfg_Ptr->Groups[Group].Assignment[0];
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    firstChIndex =  Adc_Cfg_Ptr->Channels[unit][firstChIndex].ChId;
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    for(ch=(Adc_ChannelType)0U;ch <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount; ch++)
    {
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      ChIndex = (Adc_ChannelType)Adc_Cfg_Ptr->Groups[Group].Assignment[ch];
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      phChIndex = Adc_Cfg_Ptr->Channels[unit][ChIndex].ChId;
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      *(pResult+(ch*(Adc_Cfg_Ptr->Groups[Group].NumSamples)))=
      DmaInternalResultBuffer[unit][phChIndex-firstChIndex];
    }
  }
#endif

  /* if all samples completed, wrap to 0 */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
  if (ADC_GroupStatus[Group].ResultIndex >= Adc_Cfg_Ptr->Groups[Group].NumSamples)
  {
    /* ADC325*/
    ADC_GroupStatus[Group].Conversion=ADC_STREAM_COMPLETED;

    /* @violates @ref Adc_Irq_c_REF_5 expected another indexing */
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    if((Adc_Cfg_Ptr->Groups[Group].BufferMode == ADC_STREAM_BUFFER_LINEAR)&& \
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        (Adc_Cfg_Ptr->Groups[Group].AccessMode==ADC_ACCESS_MODE_STREAMING))
    {
      /* Stop Conversion [ADC316] */
      /* the following code stop the conversion and abort the current group conversion,
         is important to abort the current, othewise, another interrupt occurs after the stop */
         /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      REG_WRITE32(ADC_DMAR0_REG(unit),ADC_DMAR_RESET_VALUE);
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      REG_WRITE32(ADC_DMAE_REG(unit), ADC_DMAE_RESET_VALUE);

      {
        VAR(Adc_ChannelType, AUTOMATIC) ch_temp;
        VAR(Adc_ChannelType, AUTOMATIC) ChIndex_temp;
        /* clear VALID bit from ADC result registers for all channels
           assigned to the group when conversion is aborted*/
        for(ch_temp=(Adc_ChannelType)0U;
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            ch_temp <Adc_Cfg_Ptr->Groups[Group].AssignedChannelCount;
            ch_temp++)
        {
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          ChIndex_temp = Adc_Cfg_Ptr->Groups[Group].Assignment[ch_temp];
          /* @violates @ref Adc_Irq_c_REF_9 expected void type,assignment,increment or decrement */
          /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
          REG_READ32(ADC_CH_DATA_REG(unit, Adc_Cfg_Ptr->Channels[unit][ChIndex_temp].ChId));
        }
      }
      if(unit==(Adc_HwUnitType)ADC_UNIT_0)
      {
        if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
        {
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
        }
      }
      /* if Bolero 1.5M */
      #ifdef IPV_ADCDIG
      #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
      if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
      {
        if(unit==(Adc_HwUnitType)ADC_UNIT_1)
        {
          Dma_disable_interrupt( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
        }
      }
      #endif
      #endif
      /* @violates @ref Adc_Irq_c_REF_6 expected conversion between pointers to a functions */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_INJ_EXT_TRIGGER_EN);
      ADC_UnitStatus[unit].Status=ADC_IDLE;
      /* ADC429*/
      ADC_GroupsInHwQueue(unit) = (Adc_QueueIndexType)0;

#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
      /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
      if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
      /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
          (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
        /* ADC078 -- ADC104 -- ADC085*/
        /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
        Adc_Cfg_Ptr->Groups[Group].Notification();
      }
      else
#endif
      {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
      }
      /* @violates @ref Adc_Irq_c_REF_4 Return statement before end of function. */
      return;
    }
    ADC_GroupStatus[Group].ResultIndex = 0U;
  }
  /* circular streaming conversion or one-shot conversion */
  /* configure the source address in TCD of the DMA channels */
  LLM_Wr_DMA_TCD_SADDR(((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[unit]),
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      (ADC_ADDRESS(unit)+ADC_CH_DATA_REG_OFFSET + (uint32)(Adc_Cfg_Ptr->Groups[Group].FirstCh)));
  #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
    if (ADC_GroupStatus[Group].Adc_Dma_Continuous == (Adc_Dma_ContinuousType)STD_ON)
  #endif
    {
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      pResult = Adc_Cfg_Ptr->Groups[Group].ResultsBufferPtr[Group]+ADC_GroupStatus[Group].ResultIndex;
      /* configure the destination result address in TCD of the DMA channels */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      LLM_Wr_DMA_TCD_DADDR(((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[unit]),pResult);
    }
  #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
    else
    {
      /* configure the destination result address in TCD of the DMA channels */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      LLM_Wr_DMA_TCD_DADDR(((uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[unit]),DmaInternalResultBuffer[unit]);
    }
  #endif
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
  /* ADC083 -- ADC416 -- ADC080 -- ADC060*/
  if ((ADC_NOTIFICATION_ENABLED==ADC_GroupStatus[Group].Notification)&&
  /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
      (Adc_Cfg_Ptr->Groups[Group].Notification != NULL_PTR))
  {
    /* ADC078 -- ADC104 -- ADC085*/
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
    /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
    Adc_Cfg_Ptr->Groups[Group].Notification();
  }
  else
#endif
  {
    /* exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
  }
  /* Start the DMA channel */
  if(unit==(Adc_HwUnitType)ADC_UNIT_0)
  {
    if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[0] == (uint8)STD_ON)
    {
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      Dma_start_channel( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0]);
    }
  }
  /* if Bolero 1.5M */
  #ifdef IPV_ADCDIG
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
  if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
  {
    if(unit==(Adc_HwUnitType)ADC_UNIT_1)
    {
      /* Disable DMA interrupt */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
      Dma_start_channel( (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1]);
    }
  }
  #endif
  #endif
}
#endif

#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
 #if defined(IPV_ADCDIG) || defined(__DOXYGEN__)
  /* if Bolero 1.5M or Bolero 256k */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || defined(__DOXYGEN__)
/**
* @brief          This function handles the watchdog interrupt.
* @details        This function handles the watchdog interrupt (clears the
*                 current channel interrupt, and calls the callback function
*                 (if defined).
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04012
*
*/
STATIC void Adc_EndWDGInterrupt(Adc_HwUnitType unit)
{
    VAR(uint32, AUTOMATIC) awor_reg[3] = {(uint32)0,(uint32)0,(uint32)0};
    VAR(uint32, AUTOMATIC) awor_masks[3]={(uint32)0, (uint32)0, (uint32)0};
    VAR(uint8, AUTOMATIC) ch = 0U;

    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    awor_reg[0] = REG_READ32(ADC_AWORR0_REG(unit));
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    awor_reg[1] = REG_READ32(ADC_AWORR1_REG(unit));
    if(unit==(Adc_HwUnitType)ADC_UNIT_0)
    {
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      awor_reg[2] = REG_READ32(ADC_AWORR2_REG(unit));
    }

    for(ch=(Adc_ChannelType)0U;ch <(Adc_ChannelType)(Adc_Cfg_Ptr->Misc.ADC_CHANNELS[unit]); ch++)
    {
        uint32 mask;
        uint32 register_index;

        register_index= ADC_LLD_WdgChannelDescRegIndex[unit][ch];
        mask= ADC_LLD_WdgChannelDescMask[unit][ch];

        /* check if watchdog triggered for current channel */
        if((awor_reg[register_index] & ((uint32)mask)) == ((uint32)mask))
        {
            /* add channel mask to clear the register */
            awor_masks[register_index]|=mask;
            /* call notification (if available) */
            /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
            if(Adc_Cfg_Ptr->Channels[unit][ch].WdogNotification != NULL_PTR)
            {
                /* @violates @ref Adc_Irq_c_REF_7 Array indexing shall be only allowed form of pointer arithmetic */
                Adc_Cfg_Ptr->Channels[unit][ch].WdogNotification();
            }
        }
    }
    /* acknowledge all processed channels */
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_AWORR0_REG(unit), awor_masks[0]);
    /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_AWORR1_REG(unit), awor_masks[1]);
    if(unit==(Adc_HwUnitType)ADC_UNIT_0)
    {
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_AWORR2_REG(unit), awor_masks[2]);
    }
}
  #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
 #endif /* #ifdef IPV_ADCDIG */
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */

/**
* @brief          This function implements the ISR for the conversion.
* @details        The function implements the ISR for the given hardware unit.
*                 It's used on both ADC Hardware units.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04013
*
*/
STATIC INLINE void Adc_EndGroupConversion(Adc_HwUnitType unit)
{
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  VAR(volatile uint32, AUTOMATIC) IsrValue = REG_READ32(ADC_ISR_REG(unit));
  /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  VAR(volatile uint32, AUTOMATIC) ImrValue = REG_READ32(ADC_IMR_REG(unit));

  if (((IsrValue & ADC_ISR_END_CHAIN_INJ_CONV) == ADC_ISR_END_CHAIN_INJ_CONV) &&
      (ADC_UnitStatus[unit].SwInjQueueIndex > (Adc_QueueIndexType)0))
  {
    if ((ImrValue & ADC_ISR_END_CHAIN_INJ_CONV_MASK) == ADC_ISR_END_CHAIN_INJ_CONV_MASK)
    {
      Adc_EndSwInjectedConv(unit);
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_CLEAN);
      /* to get again the right ISR status */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      IsrValue = REG_READ32(ADC_ISR_REG(unit));
    }
  }

  if((IsrValue & ADC_ISR_END_CHAIN_NORM_CONV) == ADC_ISR_END_CHAIN_NORM_CONV)
  {
    if ((ImrValue & ADC_ISR_END_CHAIN_NORM_CONV_MASK) == (uint32)ADC_ISR_END_CHAIN_NORM_CONV_MASK)
    {
      Adc_EndNormalConv(unit);
    }
  }

#if (STD_ON==ADC_HW_TRIGGER_API)
  if (((IsrValue & ADC_ISR_END_CHAIN_INJ_CONV) == ADC_ISR_END_CHAIN_INJ_CONV) &&
      (ADC_UnitStatus[unit].HwQueueIndex > (Adc_QueueIndexType)0))
  {
    if ((ImrValue & ADC_ISR_END_CHAIN_INJ_CONV_MASK) == ADC_ISR_END_CHAIN_INJ_CONV_MASK)
    {
      Adc_EndInjectedConv(unit);
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHAIN_INJ_CONV_CLEAN);

      if ((IsrValue & ADC_ISR_END_CHANNEL_INJ_CONV) == ADC_ISR_END_CHANNEL_INJ_CONV)
      {
        /* Clear Interrupt status flag */
        /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
        /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
        REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHANNEL_INJ_CONV_CLEAN);
      }
    }
  }

  if ((IsrValue & ADC_ISR_END_CHANNEL_CTU_CONV) == ADC_ISR_END_CHANNEL_CTU_CONV)
  {
    if ((ImrValue & ADC_ISR_END_CHANNEL_CTU_CONV_EN) == ADC_ISR_END_CHANNEL_CTU_CONV_EN)
    {
    #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
      if (ADC_UnitStatus[unit].HwQueueGroupType == ADC_MHT_GROUP_TYPE)
      {
        Adc_EndMultipleCTUConv(unit);
      }
      else
    #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
      {
        Adc_EndCTUConv(unit);
      }
      /* @violates @ref Adc_Irq_c_REF_3 cast from unsigned long to pointer */
      /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
      REG_WRITE32(ADC_ISR_REG(unit), ADC_ISR_END_CHANNEL_CTU_CONV);
    }
  }
#endif /* (STD_ON==ADC_HW_TRIGGER_API) */
}

#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR processing function for the
*                 Wdg interrupts.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04014
*
*/
STATIC INLINE void Adc_WDGThresholdHandler(Adc_HwUnitType unit)
{
    VAR(uint32, AUTOMATIC) active_interrupts = (uint32)0;
    VAR(uint32, AUTOMATIC) WtimrValue = (uint32)0;
    
    /* Read Watchdog Threshold Interrupt Status Register */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    active_interrupts= REG_READ32(ADC_WTISR_REG(unit));
    /* Read Watchdog Threshold Interrupt Mask Register */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    WtimrValue = REG_READ32(ADC_WTIMR_REG(unit));
    /* acknowledge all WDG isrs */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
    REG_WRITE32(ADC_WTISR_REG(unit), active_interrupts);
#ifdef IPV_ADCDIG
    /* if Bolero 1.5M or Bolero 256k */
    #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
    if ((WtimrValue > (uint32)0) && (active_interrupts > (uint32)0))
    {
       Adc_EndWDGInterrupt(unit);
    }
    #endif /*#if(IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */
#endif /* #ifdef IPV_ADCDIG */
}
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */


#if defined( ADC_DMA_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR processing function for the
*                 DMA conversions.
*
* @param[in]      unit        the current HW unit.
*
* @return         void
*
* @api
*
* @implements     DADC04015
*
*/
STATIC INLINE void Adc_DMAEndGroupConversion(Adc_HwUnitType unit)
{
  VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;
  VAR(uint8, AUTOMATIC) dmaChannel = (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[0];
  /* @violates @ref Adc_Irq_c_REF_13 Re-use of C90 identifier pattern */
  VAR(uint32, AUTOMATIC) isrStatus = (uint32)0;

  #ifdef IPV_ADCDIG
  /* if Bolero 1.5M */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
  if (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[1] == (uint8)STD_ON)
  {
    if (unit == (Adc_HwUnitType)ADC_UNIT_1) {
      dmaChannel = (uint8)Adc_Cfg_Ptr->Misc.ADC_DMA_CH[1];
    } else {
      /* do nothing for misra */
    }
  }
  #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
#endif /* #ifdef IPV_ADCDIG */

  /* Get the interrupt request for the corresponding DMA channel */ 
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
  /* @violates @ref Adc_Irq_c_REF_11 cast from integer type to a other type or a wider integer type */
  isrStatus = REG_READ32(DMA_INTL(DMA_MOD_IDX(dmaChannel))) & (uint8)(1U << dmaChannel);
  if ((uint32)0 != isrStatus)
  {
    /* reset DMA channel interrupt flag (IRQ ACK) */
    /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
    Dma_ack_interrupt( dmaChannel );
  }

  /* Check if isr was enabled on the corresponding channel and interrupt request was set */
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
  if ((DMA_TCD_INT_HALF == (DMA_TCD_SR(dmaChannel) & DMA_TCD_INT_HALF)) && (0U != isrStatus))
  {
    /* enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();

    /* obtain the active group */
    if (ADC_UnitStatus[unit].QueueIndex > (Adc_QueueIndexType) 0)
    {
      Group=ADC_UnitStatus[unit].Queue[0];
      Adc_DMAEndNormalConv((Adc_HwUnitType)unit, Group);
    }
    else if (ADC_UnitStatus[unit].HwQueueIndex > (Adc_QueueIndexType) 0)
    {
      Group=ADC_UnitStatus[unit].HwQueue[0];
      Adc_DMAEndInjectedConv((Adc_HwUnitType)unit, Group);
    }
    /* exit critical region is done inside Adc_DMAEndNormalConv, Adc_DMAEndInjectedConv */
  /* @violates @ref Adc_Irq_c_REF_14 else-branch must have a comment or action */
  }
}
#endif /* defined( ADC_DMA_SUPPORTED) || defined(__DOXYGEN__) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware unit 0.
* @details        The function implements the ISR for the ADC Hardware unit 0.
*
* @return         void
*
* @isr
*
* @implements     DADC04016
*
*/
ISR(Adc_EndGroupConvUnit0)
{
  Adc_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_0);
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  EXIT_INTERRUPT();
}

#if defined( ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware unit 0.
* @details        The function implements the ISR for the ADC Hardware unit 0.
*
* @return         void
*
* @isr
*
* @implements     DADC04017
*
* @note           This ISR is only defined if the ADC_WDG_SUPPORTED
*                 is enabled.
*
*/
ISR(Adc_WatchDogThresholdUnit0)
{
  Adc_WDGThresholdHandler((Adc_HwUnitType)ADC_UNIT_0);
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  EXIT_INTERRUPT();
}
#endif /* defined( ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */

#if defined( ADC_DMA_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware unit 0.
* @details        The function implements the ISR for the ADC Hardware unit 0.
*
* @return         void
*
* @isr
*
* @implements     DADC04018
*
* @note           This ISR is only defined if the ADC_DMA_SUPPORTED
*                 is enabled.
*
*/
ISR(Adc_DMAEndGroupConvUnit0){
  Adc_DMAEndGroupConversion((Adc_HwUnitType)ADC_UNIT_0);
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
  EXIT_INTERRUPT();
}
#endif /* defined( ADC_DMA_SUPPORTED) || defined(__DOXYGEN__) */


/*==================================================================================================
                                          ADC HW UNIT 1
==================================================================================================*/
#if defined(IPV_ADCDIG) || defined(__DOXYGEN__)
 /* if Bolero 1.5M */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware unit 1
* @details        The function implements the ISR for the ADC Hardware unit 1.
*
* @return         void
*
* @isr
*
* @implements     DADC04019
*
*/
ISR(Adc_EndGroupConvUnit1)
{
  Adc_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_1);
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  EXIT_INTERRUPT();
}

#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware unit 1.
* @details        The function implements the ISR for the ADC Hardware unit 1.
*
* @return         void
*
* @isr
*
* @implements     DADC04020
*
* @note           This ISR is only defined if the ADC_WDG_SUPPORTED
*                 is enabled.
*
*/
ISR(Adc_WatchDogThresholdUnit1)
{
  Adc_WDGThresholdHandler((Adc_HwUnitType)ADC_UNIT_1);
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned long to pointer */
  EXIT_INTERRUPT();
}
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */

#if defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware unit 1.
* @details        The function implements the ISR for the ADC Hardware unit 1.
*
* @return         void
*
* @isr
*
* @implements     DADC04021
*
* @note           This ISR is only defined if the ADC_DMA_SUPPORTED
*                 is enabled.
*
*/
ISR(Adc_DMAEndGroupConvUnit1){
  Adc_DMAEndGroupConversion((Adc_HwUnitType)ADC_UNIT_1);
  /* @violates @ref Adc_Irq_c_REF_8 cast from unsigned int to pointer */
  EXIT_INTERRUPT();
}
#endif /* defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__) */

  #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */
#endif /* #ifdef IPV_ADCDIG */

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_Irq_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Irq_c_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
