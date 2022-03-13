/**
*   @file    Adc_ADCDig_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - low level driver header file.
*   @details ADCDig low level driver API.
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

#ifndef ADC_ADCDIG_LLD_H
#define ADC_ADCDIG_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_ADCDig_LLD_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include". This violation is not fixed since the inclusion of MemMap.h is as per Autosar
* requirement.
*
* @section Adc_ADCDig_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_ADCDig_LLD_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Adc_ADCDig_LLD_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_ADCDig_LLD_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
* @section Adc_ADCDig_LLD_h_REF_6
* Violates MISRA 2004 Required Rule 8.8,
* The external object has been declared only once in one file. This violation comes because global
* variable has not been initialized. Variable can not be initialized and is placed in no init section.
*
* @section Adc_ADCDig_LLD_h_REF_7
* Violates MISRA 2004 Required Rule 8.12, Externally linked array size shall be defined
* This violation is needed because the array sizes are decided by configuration but care
* is taken in code to respect the array bounds.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file */
#include "Reg_Macros.h"
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file */
#include "Reg_eSys_ADCDig.h"

#if (ADC_DUAL_CLOCK_MODE==STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API==STD_ON) || \
    (ADC_SET_MODE_API==STD_ON) || (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API==STD_ON) || \
    (ADC_GET_INJECTED_CONVERSION_STATUS_API==STD_ON) || \
    (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API==STD_ON)
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file */
#include "Adc_NonASR.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Adc_ADCDig_LLD.h
*/
#define ADC_VENDOR_ID_DIG_LLD                      (43)
/*
* @violates @ref Adc_ADCDig_LLD_h_REF_4 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD       (4)
/*
* @violates @ref Adc_ADCDig_LLD_h_REF_4 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD       (0)
/*
* @violates @ref Adc_ADCDig_LLD_h_REF_4 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
#define ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD    (3)
#define ADC_SW_MAJOR_VERSION_DIG_LLD               (1)
#define ADC_SW_MINOR_VERSION_DIG_LLD               (0)
#define ADC_SW_PATCH_VERSION_DIG_LLD               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Reg_eSys_ADCDig header file are of the same vendor */
#if (ADC_VENDOR_ID_DIG_LLD != ADC_REG_VENDOR_ID)
    #error "Adc_ADCDig_LLD.h and Reg_eSys_ADCDig.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD != ADC_REG_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD != ADC_REG_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD != ADC_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD.h and Reg_eSys_ADCDig.h are different"
#endif

/* Check if source file and ADC Reg_eSys_ADCDig header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_DIG_LLD != ADC_REG_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_DIG_LLD != ADC_REG_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_DIG_LLD != ADC_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_ADCDig_LLD.h and Reg_eSys_ADCDig.h are different"
#endif

#if (ADC_DUAL_CLOCK_MODE==STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API==STD_ON) || \
    (ADC_SET_MODE_API==STD_ON) || (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API==STD_ON) || \
    (ADC_GET_INJECTED_CONVERSION_STATUS_API==STD_ON) || \
    (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API==STD_ON)
/* Check if header file and Adc_NonASR header file are of the same vendor */
#if (ADC_VENDOR_ID_DIG_LLD != ADC_NONASR_VENDOR_ID)
#error "Adc_ADCDig_LLD.h and Adc_NonASR.h have different vendor ids"
#endif

/* Check if header file and Adc_NonASR header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_DIG_LLD != ADC_NONASR_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_DIG_LLD != ADC_NONASR_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_DIG_LLD != ADC_NONASR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_ADCDig_LLD.h and Adc_NonASR.h are different"
#endif

/* Check if header file and Adc_NonASR header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_DIG_LLD != ADC_NONASR_SW_MAJOR_VERSION)  || \
     (ADC_SW_MINOR_VERSION_DIG_LLD != ADC_NONASR_SW_MINOR_VERSION)  || \
     (ADC_SW_PATCH_VERSION_DIG_LLD != ADC_NONASR_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_ADCDig_LLD.h and Adc_NonASR.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef IPV_ADCDIG
 /* if !Bolero 3M (Bolero 256k-128k) && !Leopard && !Leopard cut2/cut3 && !Bolero 1.5M &&
       !Komodo 2M && !Panther && !Rainier && !Calypso */
#if (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_09_01) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
/**
* @brief          Clean channel pending registers macro.
* @details        Used to clean channel pending registers.
*
* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined
*/
#define ADC_CLEAN_CHANNEL_PENDING_REGS(unit) do {\
  REG_WRITE32(ADC_CEOCFR0_REG(unit),0x0000FFFFUL);\
  REG_WRITE32(ADC_CEOCFR1_REG(unit),0x0FFFFFFFUL);\
  REG_WRITE32(ADC_CEOCFR2_REG(unit),0xFFFFFFFFUL);\
} while(0)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_09_01) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) */

/* if Bolero 3M or Bolero 1.5M */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
  #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
#define ADC_CLEAN_CHANNEL_PENDING_REGS(unit) do {\
  REG_WRITE32(ADC_CEOCFR0_REG(unit),0x0000FFFFUL);\
  REG_WRITE32(ADC_CEOCFR1_REG(unit),0x0FFFFFFFUL);\
  if ((unit) == (Adc_HwUnitType)0){\
    REG_WRITE32(ADC_CEOCFR2_REG(unit),0xFFFFFFFFUL);\
  }\
} while(0)
  #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) */

/* if Bolero 256k-128k */
#ifdef IPV_ADCDIG_31201_BOLERO256K
  #define ADC_CLEAN_CHANNEL_PENDING_REGS(unit) do {\
    REG_WRITE32(ADC_CEOCFR0_REG(unit),0x0000FFFFUL);\
    REG_WRITE32(ADC_CEOCFR1_REG(unit),0x00001FFFUL);\
    REG_WRITE32(ADC_CEOCFR2_REG(unit),0xFFFFFFFFUL);\
  } while(0)
#endif /* #ifdef IPV_ADCDIG_31201_BOLERO256K */

/* if Leopard or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther or Panther */
#if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
/* if !Pictus1M */
#ifndef IPV_ADCDIG_31301_PICTUS1M
/* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
#define ADC_CLEAN_CHANNEL_PENDING_REGS(unit) do {REG_WRITE32(ADC_CEOCFR0_REG(unit),0x0000FFFFUL);} while(0)
#else /* Pictus1M */
#define ADC_CLEAN_CHANNEL_PENDING_REGS(unit) do {} while(0)
#endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
          
/* if Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
  /* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
  #define ADC_CLEAN_CHANNEL_PENDING_REGS(unit) do {\
  REG_WRITE32(ADC_CEOCFR0_REG(unit),0xFFFFFFFFUL);\
  REG_WRITE32(ADC_CEOCFR1_REG(unit),0xFFFFFFFFUL);\
  REG_WRITE32(ADC_CEOCFR2_REG(unit),0xFFFFFFFFUL);\
} while(0)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */

/* if Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  /* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
  #define ADC_CLEAN_CHANNEL_PENDING_REGS(unit) do {\
  REG_WRITE32(ADC_CEOCFR0_REG(unit),0x0000FFFFUL);\
  REG_WRITE32(ADC_CEOCFR1_REG(unit),0xFFFFFFFFUL);\
  REG_WRITE32(ADC_CEOCFR2_REG(unit),0xFFFFFFFFUL);\
} while(0)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG */

#ifdef IPV_ADCDIG
/* if Bolero 1.5M or Leopard or Bolero 3M (Bolero 256k-128k) or Leopard cut2 or
   Komodo 2M or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  /* if Bolero 1.5M or Bolero 256k-128k*/
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || defined(IPV_ADCDIG_31201_BOLERO256K)
/**
* @brief          Set channel watchdog threshold registers.
* @details        Used to set channel watchdog threshold registers.
*
* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined
*/
#ifdef IPV_ADCDIG_31201_BOLERO256K /* Bolero 256k-128k */
#define ADC_SET_THRESHOLDS(unit, Th, Ch) do {\
  if ((unit) == (Adc_HwUnitType)0){\
   if((Ch)<=(Adc_ChannelType)7U){\
    REG_BIT_SET32(ADC_CWSEL0_REG(unit), (((uint32)(Th))<<((uint32)((Ch)*((uint32)0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)8U)&&((Ch)<=(Adc_ChannelType)15U)){\
    REG_BIT_SET32(ADC_CWSEL1_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(8U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)32U)&&((Ch)<=(Adc_ChannelType)39U)){\
    REG_BIT_SET32(ADC_CWSEL4_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(32U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)40U)&&((Ch)<=(Adc_ChannelType)47U)){\
    REG_BIT_SET32(ADC_CWSEL5_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(40U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)64U)&&((Ch)<=(Adc_ChannelType)71U)){\
    REG_BIT_SET32(ADC_CWSEL8_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(64U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)72U)&&((Ch)<=(Adc_ChannelType)79U)){\
    REG_BIT_SET32(ADC_CWSEL9_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(72U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)80U)&&((Ch)<=(Adc_ChannelType)87U)){\
    REG_BIT_SET32(ADC_CWSEL10_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(80U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)88U)&&((Ch)<=(Adc_ChannelType)95U)){\
    REG_BIT_SET32(ADC_CWSEL11_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(88U))*(0x4U)))));\
   }else{\
  }\
  }\
  else\
  {\
   }\
} while(0)
#else /* !Bolero 256k-128k */
/* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
#define ADC_SET_THRESHOLDS(unit, Th, Ch) do {\
  if ((unit) == (Adc_HwUnitType)0){\
   if((Ch)<=(Adc_ChannelType)7U){\
    REG_BIT_SET32(ADC_CWSEL0_REG(unit), (((uint32)(Th))<<((uint32)((Ch)*((uint32)0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)8U)&&((Ch)<=(Adc_ChannelType)15U)){\
    REG_BIT_SET32(ADC_CWSEL1_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(8U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)32U)&&((Ch)<=(Adc_ChannelType)39U)){\
    REG_BIT_SET32(ADC_CWSEL4_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(32U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)40U)&&((Ch)<=(Adc_ChannelType)47U)){\
    REG_BIT_SET32(ADC_CWSEL5_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(40U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)48U)&&((Ch)<=(Adc_ChannelType)55U)){\
    REG_BIT_SET32(ADC_CWSEL6_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(48U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)56U)&&((Ch)<=(Adc_ChannelType)59U)){\
    REG_BIT_SET32(ADC_CWSEL7_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(56U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)64U)&&((Ch)<=(Adc_ChannelType)71U)){\
    REG_BIT_SET32(ADC_CWSEL8_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(64U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)72U)&&((Ch)<=(Adc_ChannelType)79U)){\
    REG_BIT_SET32(ADC_CWSEL9_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(72U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)80U)&&((Ch)<=(Adc_ChannelType)87U)){\
    REG_BIT_SET32(ADC_CWSEL10_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(80U))*(0x4U)))));\
   }else if (((Ch)>=(Adc_ChannelType)88U)&&((Ch)<=(Adc_ChannelType)95U)){\
    REG_BIT_SET32(ADC_CWSEL11_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(88U))*(0x4U)))));\
   }else{\
  }\
  }\
  else\
  {\
  if((Ch)<=(Adc_ChannelType)7U){\
    REG_BIT_SET32(ADC_CWSEL0_REG(unit), (((uint32)(Th))<<((uint32)((Ch)*((uint32)0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)8U)&&((Ch)<=(Adc_ChannelType)15U)){\
    REG_BIT_SET32(ADC_CWSEL1_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(8U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)32U)&&((Ch)<=(Adc_ChannelType)39U)){\
    REG_BIT_SET32(ADC_CWSEL4_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(32U))*(0x4U)))));\
  }else{\
  }\
  }\
} while(0)
#endif /* IPV_ADCDIG_31201_BOLERO256K */
#endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || defined(IPV_ADCDIG_31201_BOLERO256K) */

/* if Bolero 3M */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/**
 * @brief Used to set channel watchdog threshold registers
 */
/* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
#define ADC_SET_THRESHOLDS(unit, Th, Ch) do {\
  if((Ch)<=(Adc_ChannelType)7U){\
    REG_BIT_SET32(ADC_CWSEL0_REG(unit), (((uint32)(Th))<<((uint32)((Ch)*((uint32)0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)8U)&&((Ch)<=(Adc_ChannelType)15U)){\
    REG_BIT_SET32(ADC_CWSEL1_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(8U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)32U)&&((Ch)<=(Adc_ChannelType)39U)){\
    REG_BIT_SET32(ADC_CWSEL4_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(32U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)40U)&&((Ch)<=(Adc_ChannelType)47U)){\
    REG_BIT_SET32(ADC_CWSEL5_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(40U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)48U)&&((Ch)<=(Adc_ChannelType)55U)){\
    REG_BIT_SET32(ADC_CWSEL6_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(48U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)56U)&&((Ch)<=(Adc_ChannelType)63U)){\
    REG_BIT_SET32(ADC_CWSEL7_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(56U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)64U)&&((Ch)<=(Adc_ChannelType)71U)){\
    REG_BIT_SET32(ADC_CWSEL8_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(64U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)72U)&&((Ch)<=(Adc_ChannelType)79U)){\
    REG_BIT_SET32(ADC_CWSEL9_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(72U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)80U)&&((Ch)<=(Adc_ChannelType)87U)){\
    REG_BIT_SET32(ADC_CWSEL10_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(80U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)88U)&&((Ch)<=(Adc_ChannelType)95U)){\
    REG_BIT_SET32(ADC_CWSEL11_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(88U))*(0x4U)))));\
  }else{\
    /* do nothing */\
  }\
  } while(0)
#endif  /* #ifndef IPV_ADCDIG_31201_BOLERO256K */
#endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) */

/* if Leopard or Leopard cut2/cut3 or Pictus1M or Komodo 2M  or Panther */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
/* if !Pictus1M */
#ifndef IPV_ADCDIG_31301_PICTUS1M
/* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
#define ADC_SET_THRESHOLDS(unit, Th, Ch) do {\
  if((Ch)<=(Adc_ChannelType)7U){\
    REG_BIT_SET32(ADC_CWSEL0_REG(unit), (((uint32)(Th))<<((uint32)((Ch)*((uint32)0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)8U)&&((Ch)<=(Adc_ChannelType)15U)){\
    REG_BIT_SET32(ADC_CWSEL1_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(8U))*(0x4U)))));\
  }else{\
    /* do nothing */\
  }\
  } while(0)
#else /* Pictus1M */
#define ADC_SET_THRESHOLDS(unit, Th, Ch) do {} while(0)
#endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || 
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01 */

/* Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
/**
 * @brief Used to set channel watchdog threshold registers
 */
/* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
#define ADC_SET_THRESHOLDS(unit, Th, Ch) do {\
  if((Ch)<=(Adc_ChannelType)7U){\
    REG_BIT_SET32(ADC_CWSEL0_REG(unit), (((uint32)(Th))<<((uint32)((Ch)*((uint32)0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)8U)&&((Ch)<=(Adc_ChannelType)15U)){\
    REG_BIT_SET32(ADC_CWSEL1_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(8U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)16U)&&((Ch)<=(Adc_ChannelType)23U)){\
    REG_BIT_SET32(ADC_CWSEL2_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(16U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)24U)&&((Ch)<=(Adc_ChannelType)31U)){\
    REG_BIT_SET32(ADC_CWSEL3_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(24U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)32U)&&((Ch)<=(Adc_ChannelType)39U)){\
    REG_BIT_SET32(ADC_CWSEL4_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(32U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)40U)&&((Ch)<=(Adc_ChannelType)47U)){\
    REG_BIT_SET32(ADC_CWSEL5_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(40U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)64U)&&((Ch)<=(Adc_ChannelType)71U)){\
    REG_BIT_SET32(ADC_CWSEL8_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(64U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)72U)&&((Ch)<=(Adc_ChannelType)79U)){\
    REG_BIT_SET32(ADC_CWSEL9_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(72U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)80U)&&((Ch)<=(Adc_ChannelType)87U)){\
    REG_BIT_SET32(ADC_CWSEL10_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(80U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)88U)&&((Ch)<=(Adc_ChannelType)95U)){\
    REG_BIT_SET32(ADC_CWSEL11_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(88U))*(0x4U)))));\
  }else{\
    /* do nothing */\
  }\
  } while(0)
#endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */

/* Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
/**
 * @brief Used to set channel watchdog threshold registers
 */
/* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
#define ADC_SET_THRESHOLDS(unit, Th, Ch) do {\
  if((Ch)<=(Adc_ChannelType)7U){\
    REG_BIT_SET32(ADC_CWSEL0_REG(unit), (((uint32)(Th))<<((uint32)((Ch)*((uint32)0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)8U)&&((Ch)<=(Adc_ChannelType)15U)){\
    REG_BIT_SET32(ADC_CWSEL1_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(8U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)16U)&&((Ch)<=(Adc_ChannelType)23U)){\
    REG_BIT_SET32(ADC_CWSEL2_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(16U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)32U)&&((Ch)<=(Adc_ChannelType)39U)){\
    REG_BIT_SET32(ADC_CWSEL4_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(32U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)40U)&&((Ch)<=(Adc_ChannelType)47U)){\
    REG_BIT_SET32(ADC_CWSEL5_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(40U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)48U)&&((Ch)<=(Adc_ChannelType)55U)){\
    REG_BIT_SET32(ADC_CWSEL6_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(48U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)56U)&&((Ch)<=(Adc_ChannelType)63U)){\
    REG_BIT_SET32(ADC_CWSEL7_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(56U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)64U)&&((Ch)<=(Adc_ChannelType)71U)){\
    REG_BIT_SET32(ADC_CWSEL8_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(64U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)72U)&&((Ch)<=(Adc_ChannelType)79U)){\
    REG_BIT_SET32(ADC_CWSEL9_REG(unit), (((uint32)(Th))<<((uint32)(((Ch)-(uint32)(72U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)80U)&&((Ch)<=(Adc_ChannelType)87U)){\
    REG_BIT_SET32(ADC_CWSEL10_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(80U))*(0x4U)))));\
  }else if (((Ch)>=(Adc_ChannelType)88U)&&((Ch)<=(Adc_ChannelType)95U)){\
    REG_BIT_SET32(ADC_CWSEL11_REG(unit),(((uint32)(Th))<<((uint32)(((Ch)-(uint32)(88U))*(0x4U)))));\
  }else{\
    /* do nothing */\
  }\
  } while(0)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

#if (STD_ON == ENABLE_ERR_IPV_ADCDIG_0014)
/**
* @brief  ADC Errata Workaround - Optimized SW Abort macro.
*/

  #if (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
    /* if Pictus512_256 or Leopard or Leopard cut2 or Pictus1M or Komodo 2M or Leopard2M or Panther */
    /* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
    #define ADC_SWITCH_TO_ONE_SHOT_MODE(unit) do {\
        REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CONVERSION_MODE);\
      } while(0)

  #elif (defined(IPV_ADCDIG_31201_BOLERO256K) && (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
        (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* Bolero256k or Bolero512k */
    /* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
    #define ADC_SWITCH_TO_ONE_SHOT_MODE(unit) do {\
        REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CONVERSION_MODE);\
      } while(0)

  #elif ((!defined(IPV_ADCDIG_31201_BOLERO256K)) && (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01)
    /* Bolero 3M or Bolero1.5M */
    /* @violates @ref Adc_ADCDig_LLD_h_REF_3 Function-like macro defined */
    #define ADC_SWITCH_TO_ONE_SHOT_MODE(unit) do {\
        REG_BIT_CLEAR32(ADC_MCR_REG(unit), ADC_CONVERSION_MODE);\
      } while(0)

  #else 
    /* if Spectrum or FADO */
    #define ADC_SWITCH_TO_ONE_SHOT_MODE(unit) do { }while(0)
  #endif

#endif /* (STD_ON == ENABLE_ERR_IPV_ADCDIG_0014) */

#endif /* IPV_ADCDIG */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"
/**
* @brief          Used for group status.
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_6 object/function previously declared */
/* @violates @ref Adc_ADCDig_LLD_h_REF_7 Externally linked array size shall be defined */
extern VAR(Adc_GroupStatusType, ADC_VAR) ADC_GroupStatus[];

/**
* @brief          Used for unit status.
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_6 object/function previously declared */
/* @violates @ref Adc_ADCDig_LLD_h_REF_7 Externally linked array size shall be defined */
extern VAR(Adc_UnitStatusType , ADC_VAR) ADC_UnitStatus[];

#ifdef IPV_ADCDIG
/* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2 or Pictus1M or Komodo 2M or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
/* if !Pictus1M */
#ifndef IPV_ADCDIG_31301_PICTUS1M
/**
* @brief          Channel descriptions for the WDG interrupts.
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_6 object/function previously declared */
extern VAR(uint8, ADC_VAR) ADC_LLD_WdgChannelDescRegIndex[ADC_MAX_HW_UNITS][ADC_MAX_CHANNEL_PER_HW_UNIT];
/* @violates @ref Adc_ADCDig_LLD_h_REF_6 object/function previously declared */
extern VAR(uint32, ADC_VAR) ADC_LLD_WdgChannelDescMask[ADC_MAX_HW_UNITS][ADC_MAX_CHANNEL_PER_HW_UNIT];
#endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG */

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          This array is used to handle the MHT groups in
*                 an efficient manner through the driver code.
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_6 object/function previously declared */
extern VAR(Adc_LLD_MhtChannelGroupType, ADC_VAR) Adc_LLD_MhtChannelGroup[ADC_MAX_HW_UNITS][ADC_MAX_GROUPS_PER_HW_UNIT];
#endif

#ifdef ADC_DMA_SUPPORTED
  #if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
/**
* @brief          Internal buffer used by DMA to transfer blocks with gaps.
*/
/* @violates @ref Adc_ADCDig_LLD_h_REF_6 object/function previously declared */
extern VAR(Adc_ValueGroupType,ADC_VAR) DmaInternalResultBuffer[ADC_MAX_HW_UNITS][ADC_MAXIMUM_HW_CHANNELS];
  #endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
#endif /* #ifdef ADC_DMA_SUPPORTED */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/* @violates @ref Adc_ADCDig_LLD_h_REF_6 object/function previously declared */
extern VAR(Adc_NCMR_Type, ADC_VAR) Adc_NCMRx_Mask[ADC_NO_OF_ENABLE_CH_DISABLE_CH_GROUPS];
#endif

/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

/**
* @brief          Used to point the configuration structure.
*/
extern P2CONST(Adc_ConfigType , ADC_VAR, ADC_APPL_CONST) Adc_Cfg_Ptr;
/* for bolero 3M only */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
#if (ADC_DUAL_CLOCK_MODE == STD_ON )
  extern VAR(Adc_NonASR_DualClockModeType, ADC_VAR) Adc_ClockMode;
#endif
#endif

/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
FUNC(void, ADC_CODE) ADCDig_LLD_StartNormalConversion(VAR(Adc_HwUnitType, AUTOMATIC) unit);

/* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus_512k_256k or 
      Komodo 2M or Bolero 3M (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
FUNC(void, ADC_CODE) ADCDig_LLD_StartInjectedConversion(VAR(Adc_HwUnitType, AUTOMATIC) unit);
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

FUNC(void, ADC_CODE) ADCDig_LLD_Init(P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) CfgPtr);

#if (ADC_DEINIT_API == STD_ON)
FUNC(void, ADC_CODE) ADCDig_LLD_DeInit(void);
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
FUNC(void, ADC_CODE) ADCDig_LLD_StartGroupConversion(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
);
FUNC(void, ADC_CODE) ADCDig_LLD_StopGroupConversion
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
FUNC(void, ADC_CODE) ADCDig_LLD_EnableHardwareTrigger
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
);
FUNC(void, ADC_CODE) ADCDig_LLD_DisableHardwareTrigger
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  VAR(Adc_HwUnitType, AUTOMATIC) unit
);

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
FUNC(void, ADC_CODE) ADCDig_LLD_EnableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);
FUNC(void, ADC_CODE) ADCDig_LLD_DisableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_HwResultReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
);
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

FUNC(Adc_StreamNumSampleType, ADC_CODE) ADCDig_LLD_GetStreamLastPointer
(
  VAR(Adc_GroupType, AUTOMATIC) Group,
  P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr
);

#if (ADC_READ_GROUP_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_ReadGroup
(
  CONST(Adc_GroupType, AUTOMATIC) Group,
  P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
);
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#ifdef ADC_DMA_SUPPORTED
FUNC(void, ADC_CODE) ADCDig_StartDMAOperation(VAR(Adc_HwUnitType, AUTOMATIC) Unit);
#endif /* ADC_DMA_SUPPORTED */

FUNC(void, ADC_CODE) ADCDig_RemoveFromQueue
(
  CONST(Adc_HwUnitType, AUTOMATIC) unit,
  CONST(Adc_QueueIndexType, AUTOMATIC) cur_queue_index
);

#if (ADC_SET_MODE_API == STD_ON)
FUNC (Std_ReturnType, ADC_CODE) ADCDig_LLD_SetMode(VAR(Adc_SetModeType, AUTOMATIC) SetMode);
#endif /* (ADC_SET_MODE_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_SetClockMode
(
   VAR(Adc_NonASR_DualClockModeType, AUTOMATIC) ClockMode
);
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
FUNC(boolean, ADC_CODE) ADCDig_LLD_CheckConversionValuesInRange
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
(
  VAR(uint16, AUTOMATIC) value,
  VAR(Adc_HwUnitType, AUTOMATIC) unit,
  VAR(Adc_ChannelType, AUTOMATIC) index
);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
#if (ADC_HW_TRIGGER_API == STD_ON)
FUNC(Adc_StatusType, ADC_CODE) ADCDig_LLD_GetInjectedConversionStatus
/* @violates @ref Adc_ADCDig_LLD_h_REF_5 Identifier exceeds 31 characters */
(
  VAR(Adc_HwUnitType, AUTOMATIC) unit
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON) */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) ADCDig_LLD_ConfigureThreshold
(
  VAR(Adc_GroupType, AUTOMATIC) GroupId,
  VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
  VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
);
#endif

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_ADCDig_LLD_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_ADCDIG_LLD_H */

/** @} */
