/**
*   @file    Reg_eSys_ADCDig.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details Adc module registers, and macrodefinitions used to manipulate the module registers.
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

#ifndef REG_ESYS_ADCDIG_H
#define REG_ESYS_ADCDIG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_ADCDig_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section  Reg_eSys_ADCDig_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* There are different kinds of execution code sections.
*
* @section Reg_eSys_ADCDig_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
*
* @section Reg_eSys_ADCDig_h_REF_4
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section Reg_eSys_ADCDig_h_REF_5
* Violates MISRA 2004 Required Rule 8.12, Externally linked array size shall be defined
* This violation is needed to reduce code complexity because the array sizes are decided by 
* configuration but care is taken in code to respect the array bounds.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_2 Repeated include file */
#include "Reg_eSys.h"
/* @violates @ref Reg_eSys_ADCDig_h_REF_2 Repeated include file */
#include "Adc_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_ADCDig.h
*/
#define ADC_REG_VENDOR_ID                      (43)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_REG_AR_RELEASE_MAJOR_VERSION       (4)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_REG_AR_RELEASE_MINOR_VERSION       (0)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_REG_AR_RELEASE_REVISION_VERSION    (3)
#define ADC_REG_SW_MAJOR_VERSION               (1)
#define ADC_REG_SW_MINOR_VERSION               (0)
#define ADC_REG_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          These definitions are used to select the derivatives.
*/
#define IPV_ADCDIG_00_01_08_01 (0x10801UL) /**< @brief Bolero 512k cut2 - v1.8.a */
#define IPV_ADCDIG_00_02_02_02 (0x20202UL) /**< @brief Bolero 1.5M cut 1.0 - v2.2.b */
#define IPV_ADCDIG_00_03_09_01 (0x30901UL) /**< @brief Bolero 1.5M cut 2.0 - v3.9.a */
#define IPV_ADCDIG_00_02_00_01 (0x20001UL) /**< @brief Leopard - 2.0.a */
#define IPV_ADCDIG_00_01_05_01 (0x10501UL) /**< @brief Fado - 1.5.a */
#define IPV_ADCDIG_00_03_12_01 (0x31201UL) /**< @brief Bolero 3M && Bolero 256k && Bolero 128k - 3.12.a */
#define IPV_ADCDIG_00_01_06_01 (0x10601UL) /**< @brief Pictus 512k - 1.6.a, Pictus 256k - 1.6.c */
#define IPV_ADCDIG_00_03_13_01 (0x31301UL) /**< @brief Leopard cut2/cut3 && Pictus1M && Komodo2M && Leopard2M - 3.13.a */
#define IPV_ADCDIG_00_00_03_01 (0x00000301UL) /**< @brief Panther */
#define IPV_ADCDIG_00_00_04_12 (0x00000412UL) /**< @brief Rainier cut 1.0 */
#define IPV_ADCDIG_00_00_04_10 (0x00000410UL) /**< @brief Calypso cut 1.0 */

#define ADC_START_SEC_CONST_32
/* @violates @ref Reg_eSys_ADCDig_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

/**
* @brief Base address array for ADCDig
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_5 Externally linked array size shall be defined */
extern CONST(uint32, ADC_CONST) ADCDIG_BASE_ADDR[];

#define ADC_STOP_SEC_CONST_32
/* @violates @ref Reg_eSys_ADCDig_h_REF_2 Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          ADC Base address definition.
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_ADDRESS(HwUnit)         (ADCDIG_BASE_ADDR[(HwUnit)])

/**
* @brief          Main Configuration Register (MCR).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_MCR_REG(HwUnit)           ((ADC_ADDRESS((HwUnit))+(uint32)0x0000UL))

/**
* @brief          Main Status Register (MSR).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_MSR_REG(HwUnit)           ((ADC_ADDRESS((HwUnit))+0x0004UL))

/**
* @brief          Reserved From 0x0008 to 0x000F.
*/

/**
* @brief          Interrupt Status Register (ISR).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_ISR_REG(HwUnit)           ((ADC_ADDRESS((HwUnit))+0x0010UL))

/**
* @brief          Channel Pending Register (CEOCFR0-2).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_CEOCFR0_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0014UL))
#ifdef IPV_ADCDIG
/* if !Leopard and !Leopard cut2/cut3 and !Pictus 1M and !Komodo and !Panther */
#if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
  /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
  #define ADC_CEOCFR1_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0018UL))
  /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
  #define ADC_CEOCFR2_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x001CUL))
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)*/
#endif /* IPV_ADCDIG */

/**
* @brief          Interrupt Mask Register (IMR).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_IMR_REG(HwUnit)           ((ADC_ADDRESS((HwUnit))+0x0020UL))

/**
* @brief          Channel Interrupt Mask Register (CIMR0-2).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
  /* if !Pictus1M */
  #ifndef IPV_ADCDIG_31301_PICTUS1M
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CIMR0_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x0024UL))
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
  /* if !Leopard and !Leopard cut2/cut3 and !Komodo and !Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CIMR1_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x0028UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CIMR2_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x002CUL))
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
#endif /* IPV_ADCDIG */

/**
* @brief          Watchdog Threshold Interrupt Status Register (WTISR).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_WTISR_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x0030UL))

/**
* @brief          Watchdog Threshold Interrupt Mask Register (WTIMR).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_WTIMR_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x0034UL))

/**
* @brief          Reserved From 0x0038 t0 0x003C on Bolero 1.5M.
* @details        On Bolero 512K these registers do not exists. 
*/

/**
* @brief          DMAE Register (DMAE).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_DMAE_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0040UL))

/**
* @brief          DMA Channel Select Register(DMAR0-2).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_DMAR0_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x0044UL))
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo and !Panther*/
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
 /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
 #define ADC_DMAR1_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x0048UL))
 /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
 #define ADC_DMAR2_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x004CUL))
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */

/**
* @brief          Threshold Control Register (TRC0-3).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#ifdef IPV_ADCDIG
 /* if !Bolero 3M and !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo and !Panther and 
        !Rainier and !Calypso */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_TRC0_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0050UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_TRC1_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0054UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_TRC2_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0058UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_TRC3_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x005CUL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_TRCx_REG(HwUnit, Offset)  ((ADC_TRC0_REG((HwUnit)) + (uint32)(((uint32)(Offset))<<2)))
 #else /* Bolero 3M or Leopard or Leopard cut2/cut3 or Pictus1M or Komodo */
  /* if Pictus1M */
  #ifdef IPV_ADCDIG_31301_PICTUS1M
#define ADC_TRC0_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0050UL))
#define ADC_TRC1_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0054UL))
#define ADC_TRC2_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0058UL))
#define ADC_TRC3_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x005CUL))
#define ADC_TRCx_REG(HwUnit, Offset)  ((ADC_TRC0_REG((HwUnit)) + (uint32)(((uint32)(Offset))<<2)))
  #else
  /* reserved from 0x0050 - 0x005F */
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG */

/**
* @brief          Threshold Register (THRHLR0-x).
*
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_THRHLR0_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0060UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_THRHLR1_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0064UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_THRHLR2_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0068UL))
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_THRHLR3_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x006CUL))
#endif /* IPV_ADCDIG_31201_BOLERO256K */
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_THRHLRx_REG(HwUnit, Offset) ((ADC_THRHLR0_REG((HwUnit)) + (uint32)(((uint32)(Offset))<<2)))
#ifdef IPV_ADCDIG
 /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2 or Pictus 1M or Komodo or Panther */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
  #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
  #define ADC_THRHLR_4_5x_REG(HwUnit,Offset) ((ADC_THRHLR4_REG((HwUnit))+(uint32)(((uint32)(Offset))<<2)))
  #endif /* IPV_ADCDIG_31201_BOLERO256K */
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */

/**
* @brief          Threshold Register (THRALT0-3).
*
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#ifdef IPV_ADCDIG
 /* if Leopard cut1 */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01)
   #define ADC_THRALT0_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0070UL))
   #define ADC_THRALT1_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0074UL))
   #define ADC_THRALT2_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0078UL))
   #define ADC_THRALT3_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x007CUL))
 #else
 /* Reserved From 0x0070 t0 0x007F */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) */
#endif /* IPV_ADCDIG */

/**
* @brief          Presampling Control Register (PSCR).
* @details        Presampling Register (PSR0-2).
*
*/
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_PSCR_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0080UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_PSR0_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0084UL))
  /* if !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_PSR1_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0088UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_PSR2_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x008CUL))
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && 
            (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
#endif /* IPV_ADCDIG */

/**
* @brief          Reserved From 0x0090 t0 0x0093.
*/

/**
* @brief          Conversion Timing Register (CTR0-2).
*
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_CTR0_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0094UL))
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
  /* if !Pictus1M */
  #ifndef IPV_ADCDIG_31301_PICTUS1M
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_CTR1_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x0098UL))
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
  /* if !Leopard and !Leopard cut2 and !Pictus1M and !Komodo 2M and !Panther */
  #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_CTR2_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x009CUL))
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
#endif /* IPV_ADCDIG */

#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* Reserved From 0x00A0 t0 0x00A3 */
#else
  /* Reserved From 0x0098 t0 0x00A3 */
#endif /* IPV_ADCDIG_31201_BOLERO256K */

/**
* @brief          Normal Conversion Mask Register (NCMR0-2).
*
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_NCMR0_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00A4UL))
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M  and !Komodo 2M and !Panther */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_NCMR1_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00A8UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_NCMR2_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00ACUL))
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */

#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* Reserved From 0x00B0 t0 0x00B3 */
#else
  /* Reserved From 0x00A8 t0 0x00B3 */
#endif /* IPV_ADCDIG_31201_BOLERO256K */
/**
* @brief          Injected Conversion Mask Register (JCMR0-2).
*
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_JCMR0_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00B4UL))
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M  and !Komodo 2M and !Panther */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_JCMR1_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00B8UL))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_JCMR2_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00BCUL))
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)*/
#endif /* IPV_ADCDIG */

/**
* @brief          Offset Word Register (OFFWR).
*
*/
#ifdef IPV_ADCDIG
 /* if !Bolero 3M and !Leopard and !Leopard cut2/cut3 and !Pictus and !Komodo 2M and !Panther and
       !Rainier and !Calypso */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_OFFWR_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00C0UL))
 #else /* Bolero 3M or Leopard or Leopard cut2/cut3 or Pictus or Komodo 2M  */
 /* reserved from 0x00C0 - 0x00C3 */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG */

/**
* @brief          Decode Signals Delay Register (DSDR).
*
*/
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 and !Leopard and !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_DSDR_REG(HwUnit)          ((ADC_ADDRESS((HwUnit))+0x00C4UL))
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */

/**
* @brief          Power-down Exit Delay Register (PDEDR).
*
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_PDEDR_REG(HwUnit)         ((ADC_ADDRESS((HwUnit))+0x00C8UL))

/**
* @brief          Reserved From 0x00CC t0 0x00FF.
*/

/**
* @brief          Displacement of the first channel data register
*                 address relative to the ADC base address.
*
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CH_DATA_REGISTERS_START_ADDRESS_OFFSET (0x0100UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_CH_DATA_REG(HwUnit,Ch) \
 (ADC_ADDRESS((HwUnit))+ADC_CH_DATA_REGISTERS_START_ADDRESS_OFFSET+((uint32)(((uint32)(Ch))<<2)))

/**
* @brief          Maximum Precision channel range from ANP0_ANP31
*                 (range from 0 to 32).
*/
#define ADC_ST_PRICISION_CH           (0U)
#define ADC_ED_PRICISION_CH           (31U)

/**
* @brief          Maximum medium accuracy Extended channel range from 
*                 ANS0_ANS31 (range from 32 to 63).
*/
#define ADC_ST_EXTENDED_CH            (32U)
#define ADC_ED_EXTENDED_CH            (63U)

/**
* @brief          Maximum external channel range from ANX0_ANX3 
*                (range from 64 to 95).
*/
#define ADC_ST_EXTERNAL_CH            (64U)
#define ADC_ED_EXTERNAL_CH            (95U)

/**
* @brief          Additional macro used for Bolero 512K and Fado.
*/
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
#define ADC_MAX_PRICISION_COUNT       (16U)
#define ADC_MAX_EXTENDED_CH           (47U)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/**
* @brief          Additional macro used for Bolero 1.5M / Leopard / 
*                 Bolero 3M / Leopard cut2 / Komodo 2M.
*
*/
#ifdef IPV_ADCDIG
 /* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut2/cut3 or Pictus 1M or Komodo 2M or Panther 
       or Rainier or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  /* if !Pictus1M */
  #ifndef IPV_ADCDIG_31301_PICTUS1M
   /* !Bolero 256k-128k and !Rainier */
   #if (!defined(IPV_ADCDIG_31201_BOLERO256K)) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
   /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
   #define ADC_THRHLR4_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0280UL))
   /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
   #define ADC_THRHLR5_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0284UL))
   
   /* if Leopard or Leopard cut2/cut3 or Komodo 2M or Panther */
   #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR6_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0288UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR7_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x028CUL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR8_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0290UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR9_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x0294UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR10_REG(HwUnit)      ((ADC_ADDRESS((HwUnit))+0x0298UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR11_REG(HwUnit)      ((ADC_ADDRESS((HwUnit))+0x029CUL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR12_REG(HwUnit)      ((ADC_ADDRESS((HwUnit))+0x02A0UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR13_REG(HwUnit)      ((ADC_ADDRESS((HwUnit))+0x02A4UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR14_REG(HwUnit)      ((ADC_ADDRESS((HwUnit))+0x02A8UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_THRHLR15_REG(HwUnit)      ((ADC_ADDRESS((HwUnit))+0x02ACUL))
    #else
    /* Reserved From 0x0288 t0 0x02AF */
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
   #endif /* !defined(IPV_ADCDIG_31201_BOLERO256K) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) &&
             (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */

   /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
   #define ADC_CWSEL0_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02B0UL))
   /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
   #define ADC_CWSEL1_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02B4UL))

   #if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
       (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL2_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02B8UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL3_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02BCUL))
   #else
   /* Reserved From 0x02B8 t0 0x02BF */
   #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
             (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

    /* if !Leopard and !Leopard cut2/cut3 and !Komodo 2M and !Panther */
   #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
       (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL4_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02C0UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL5_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02C4UL))
    #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL6_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02C8UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL7_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02CCUL))
    #endif /* !Bolero 256k-128k */
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL8_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02D0UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL9_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02D4UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL10_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x02D8UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWSEL11_REG(HwUnit)       ((ADC_ADDRESS((HwUnit))+0x02DCUL))
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
             (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
   /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
   #define ADC_CWENR0_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02E0UL))
   /* if Leopard and !Leopard cut2/cut3 and !Komodo 2M and !Panther */
   #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
       (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWENR1_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02E4UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_CWENR2_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02E8UL))
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && 
             (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */

   /* Reserved From 0x02EC t0 0x02EF */
   /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
   #define ADC_AWORR0_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02F0UL))
   /* if Leopard and !Leopard cut2/cut3 and !Komodo 2M and !Panther */
   #if (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
       (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_AWORR1_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02F4UL))
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define ADC_AWORR2_REG(HwUnit)        ((ADC_ADDRESS((HwUnit))+0x02F8UL))
   #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) &&
             (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */

   #define ADC_CWSEL_RESET_VALUE (0x0UL)
   #define ADC_CWENR_RESET_VALUE (0x0UL)
   #define ADC_AWORR_REG_RESET_VALUE (0x0UL)
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG */

/**
* @brief          Offset to the lower part of the first Channel Data Register.
*/
#define ADC_CH_DATA_REG_OFFSET        (((uint32)ADC_CH_DATA_REGISTERS_START_ADDRESS_OFFSET+0x0002UL))

/**
* @brief          ADC Resoulution.
*/
#define ADC_BITS_RESOLUTION_10        (10U)
#define ADC_BITS_RESOLUTION_12        (12U)

/**********************************************************************************
***************                   Main Configuration Register (MCR) **************
**********************************************************************************/
/**
* @brief          OWREN: Overwrite enable.
* @details        If set to 1 the conversion data is overwritten by a 
*                 newer result otherwise it is discarded.
*/
#define ADC_OVERWRITE_EN ((uint32)0x80000000UL)
#define ADC_OVERWRITE_DIS (0x0UL)

/**
* @brief          WLSIDE: Write left /right-aligned.
* @details        0: The conversion data is written right-aligned.
*                 1: Data is left-aligned (from 15 to (15- resolution + 1)).
*/
#define ADC_WRITE_LEFT_ALIGNED ((uint32)0x40000000UL)
#define ADC_WRITE_RIGHT_ALIGNED ((uint32)0x0UL)

/**
* @brief          MODE: One_Shot/Scan.
* @details        0: One_Shot Mode - Configures the Normal conversion of one chain.
*                 1: Scan Mode - Configures continuous chain conversion mode; when the
*                 programmed chain conversion is finished it restarts immediately.
*/
#define ADC_ONE_SHOT_MODE (0x0UL)
#define ADC_CONTINUOUS_MODE (0x20000000UL)
#define ADC_CONVERSION_MODE (ADC_CONTINUOUS_MODE)

#ifdef IPV_ADCDIG
 /* if !Bolero 1.5M cut 2, !Bolero 1.5M cut 1, !Bolero 512K, !Pictus512_256, !Leopard,
       !Leopard cut2/cut3 , !Pictus1M, !Komodo 2M   */
 #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_09_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_02_02) && \
       (IPV_ADCDIG != IPV_ADCDIG_00_01_08_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
       (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01))
 #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
  /* EDGLEV: Edge or level selection for external start trigger
  Edge (EDGLEV = 0) or Level (EDGLEV = 1) configuration for external trigger usage*/
  #define ADC_EDGE_TRIGGER_MODE (0x0UL)
  #define ADC_LEVEL_TRIGGER_MODE (0x10000000UL)

/**
* @brief          TRGEN: External trigger enable.
* @details        When set enables the external trigger to start a conversion; 
*                 if the external trigger feature is needed this bit must be set.
*/
  #define ADC_EXT_TRIGGER_EN  (0x08000000UL)
  #define ADC_EXT_TRIGGER_DIS (0x0UL)

/**
* @brief          EDGE: Start trigger edge/level detection.
* @details        If TRGEN is one and EDGLEV is zero this bit selects the falling 
*                 (EDGE = 0) or rising (EDGE = 1) edge for the external trigger.
*                 If TRGEN is one and EDGLEV is one this bit selects the low 
*                 (EDGE = 0) or high (EDGE = 1) edge for the external trigger.
*/
#define ADC_EXT_TRIGGER_FALLING_EDGE (0x0UL)
#define ADC_EXT_TRIGGER_LOW_LEVEL (0x0UL)
#define ADC_EXT_TRIGGER_RISING_EDGE (0x04000000UL)
#define ADC_EXT_TRIGGER_HIGH_LEVEL (0x04000000UL)
#define ADC_EXT_TRIGGER_EDGE (ADC_EXT_TRIGGER_RISING_EDGE)
 #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
 #endif /* ((IPV_ADCDIG != IPV_ADCDIG_00_03_09_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_02_02) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_01_08_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
            (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01)) */
#endif /* IPV_ADCDIG */

/* if Fado or Bolero 3M or Panther or Rainier of Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
 #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/**
* @brief          XSTRTEN: External Start enable.
* @details        This bit can be used in order to synchronize th eSTART events of two ADCs.
*/
#define ADC_EXT_START_EN (0x02000000UL)
#define ADC_EXT_START_DIS (0x0UL)
 #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || 
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

/**
* @brief          NSTART: Start conversion.
* @details        Setting this bit starts the chain or scan conversion, resetting this bit 
*                 during scan mode cause the current chain conversion to finish and stops 
*                 the operation.
*                 This bit keeps the high value until the conversion is ongoing 
*                 (or pending during injection mode).
*/
#define ADC_NORMAL_START_CONV_EN (0x01000000UL)
#define ADC_NORMAL_START_CONV_DIS (0x0UL)
#define ADC_NORMAL_CONV_STOP (0x01000000UL)

/**
* @brief          JTRGEN: Injection external trigger enable.
* @details        Setting this bit will enable the external trigger for channel injection.
*/
#define ADC_INJ_EXT_TRIGGER_EN (0x00400000UL)
#define ADC_INJ_EXT_TRIGGER_DIS (0x0UL)

/**
* @brief          JEDGE: Injection trigger edge selection.
* @details        Edge selection for external trigger; if JTRGEN is one this bit selects
*                 the falling (JEDGE = 0) or rising (JEDGE = 1) edge for the external trigger.
*/
#define ADC_INJ_TRIGGER_FALLING_EDGE (0x0UL)
#define ADC_INJ_TRIGGER_RISING_EDGE (0x00200000UL)
#define ADC_INJ_TRIGGER_EDGE (ADC_INJ_TRIGGER_RISING_EDGE)

/**
* @brief          JSTART: Injection start.
* @details        Setting this bit will start the configured injected analog channels to be
*                 converted by software; resetting this bit has no effect, as the injected chain
*                 conversion cannot be interrupted.
*/
#define ADC_INJ_START_CONV_EN (0x00100000UL)
#define ADC_INJ_START_CONV_DIS (0x0UL)

/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          Reference Range Expected.
* @details        This is a control bit that specifies the expected value of MSR[REF_RANGE].
*/
#define ADC_REF_RANGE_EXP_EN (0x00080000UL)
#define ADC_REF_RANGE_EXP_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */

/**
* @brief          CTUEN: Cross Trigger Unit Enable.
* @details        0: The cross triggering unit is disabled and the triggered injected 
*                 conversion cannot take place.
*                 1: The cross triggering unit is enabled and the triggered injected
*                 conversion can take place.
*/
#define ADC_CTU_ENABLED (0x00020000UL)
#define ADC_CTU_DISABLED (0x0UL)

/* if !Bolero 3M */
#if (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01)
/**
* @brief          ADCLKSEL: Analog clock frequency selector.
* @details        If this bit is set the AD_clk frequency is equal to ipg_clk frequency.
*                 Otherwise, it is half of ipg_clk frequency. That bit can be written
*                 in power-down only.
*/
#define ADC_CLOCK_PRESCALER_DIV1 (0x00000100UL)
#define ADC_CLOCK_PRESCALER_DIV2 ((uint32)0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) */

/* if Bolero 256k-128k */
#ifdef IPV_ADCDIG_31201_BOLERO256K /* Bolero 256k-128k */
/*ADCLKSEL: Analog clock frequency selector
If this bit is set the AD_clk frequency is equal to ipg_clk frequency. Otherwise, it is half of
ipg_clk frequency. That bit can be written in power-down only. */
  #define ADC_CLOCK_PRESCALER_DIV1 (0x00000100UL)
  #define ADC_CLOCK_PRESCALER_DIV2 ((uint32)0x0UL)
#endif /* IPV_ADCDIG_31201_BOLERO256K */

/**
* @brief          ABORT CHAIN: Abort Chain.
* @details        If this bit is set the ongoing chain conversion is aborted. This bit is reset
*                 by hardware as soon as a new conversion is requested.
*/
#define ADC_ABORT_CHAIN (0x00000080UL)

/**
* @brief          ABORT: Abort Conversion.
* @details        If this bit is set the ongoing conversion is aborted and a new conversion is
*                 invoked. This bit is reset by hardware as soon as the new conversion is invoked.
*/
#define ADC_ABORT_CHAN (0x00000040UL)

/**
* @brief          ACKO: Auto-clock-off enable.
* @details        If set enables the auto-clock-off feature.
*/
#define ADC_AUTO_CLKOFF_EN (0x00000020UL)
#define ADC_AUTO_CLKOFF_DIS ((uint32)0x0UL)

/* if Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
/**
* @brief          OFFREFRESH: Offset refresh enable.
* @details        If set, this bit enables the offset refresh feature.
*/
#define ADC_OFFSET_REFRESH_EN (0x00000010UL)
#define ADC_OFFSET_REFRESH_DIS (0x0UL)

/**
* @brief          OFFCANC: Offset Cancellation.
* @details        This bit is reset to 0 when the offset calcellation ends.
*/
#define ADC_OFFCANC_EN (0x00000008UL)
#define ADC_OFFCANC_DIS (0x0UL)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/**
* @brief          REFSEL: Reference voltage selection.
* @details        Select the reference voltage for ADC analog part.
*/
#define ADC_REFSEL_VREFH            (0x0UL)
#define ADC_REFSEL_VREFH_BAND_GAP   (0x00000002UL)
#define ADC_REFSEL_VREFH_ALTERNATE  (0x00000004UL)


/**
* @brief          PWDN: Power-down enable
* @details        When this bit is set, the analog module is requested to enter power-down mode.
*                 When ADC status is PWDN, resetting this bit will start ADC transition to IDLE mode.
*/
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
  #define ADC_POWER_DOWN_EN ((uint32)0x00000101UL)
  #define ADC_POWER_DOWN_DIS (0x100UL)
  #define ADC_POWER_DOWN ((uint32)0x00000001UL)
  #define ADC_MCR_RESET_VALUE (0x00000101UL)
#else
  #define ADC_POWER_DOWN_EN ((uint32)0x00000001UL)
  #define ADC_POWER_DOWN_DIS (0x0UL)
  #define ADC_POWER_DOWN (ADC_POWER_DOWN_EN)
/* If Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  #define ADC_MCR_RESET_VALUE (0x00000101UL)
#else
  #define ADC_MCR_RESET_VALUE (0x00000001UL)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)*/
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */

/**********************************************************************************
***************               Main Status Register (MSR)             **************
**********************************************************************************/
/**
* @brief          NSTART.
* @details        This status bit is used to signal that a Normal conversion is ongoing.
*/
#define ADC_NORMAL_CONV_STATUS (0x01000000UL)
#define ADC_NORMAL_CONV_ONGOING (0x01000000UL)
#define ADC_NORMAL_CONV_FINISH (0x0UL)

/**
* @brief          JABORT.
* @details        This status bit is used to signal that an Injected conversion has been aborted.
*                 That bit is reset when a new injected conversion starts.
*/
#define ADC_INJ_ABORT_CONV_STATUS (0x00800000UL)
#define ADC_INJ_ABORT_CONV_ONGOING (0x00800000UL)
#define ADC_INJ_ABORT_CONV_FINISH (0x0UL)

/**
* @brief          JSTART.
* @details        This status bit is used to signal that an Injected conversion is ongoing.
*/
#define ADC_INJ_CONV_STATUS (0x00100000UL)
#define ADC_INJ_CONV_ONGOING (0x00100000UL)
#define ADC_INJ_CONV_FINISH (0x0UL)

/* if Leopard cut2/cut3 or Pictus 1M */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          REF_RANGE.
* @details        This bit defines the voltage range for operation of the ADC. It is provided
*                 as an output by the ADC, along with data, after every conversion.
*/
#define ADC_REF_RANGE_LESS_EQUAL_36V (0x00000000UL)
#define ADC_REF_RANGE_GREATER_45V (0x00080000UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */

/**
* @brief          CTUSTART.
* @details        This status bit is used to signal that a CTU conversion is ongoing.
*                 This bit is set when a CTU trigger pulse is received and the CTU conversion starts.
*                 When CTU trigger mode is enabled this bit is automatically reset when the conversion
*                 is completed. Otherwise, if Control Mode is enabled this bit is reset when the CTU 
*                 is disabled.
*/
#define ADC_CTU_CONV_STATUS (0x00010000UL)
#define ADC_CTU_CONV_ONGOING (0x00010000UL)
#define ADC_CTU_CONV_FINISH (0x0UL)

/**
* @brief          CHADDR:Channel address.
* @details        Channel under measure address.
*                 This status bit is used to signal which channel is under measure.
*/
#define ADC_CH_UNDER_CONVERTION (0x0000FE00UL)

/**
* @brief          ACKO: Auto-clock-off enable.
* @details        This status bit is used to signal if the Auto-clock-off feature is on.
*/
#define ADC_AUTO_CLK_OFF_STATUS (0x00000020UL)

#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
/**
* @brief          ADC_OFFREFRESH_STATUS - ADC_OFFCANC_STATUS.
* @details        Offset refresh and cancellation.
*/
#define ADC_OFFREFRESH_STATUS (0x00000010UL)
#define ADC_OFFCANC_STATUS (0x00000008UL)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/**
* @brief          ADCSTATUS
* @details        Adc Status.
*/
#define ADC_STATUS (0x00000007UL)
#define ADC_IDLE_OFFSET_STATUS (0x0UL)
#define ADC_POWERDOWN_STATUS (0x00000001UL)
#define ADC_WAIT_STATE_STATUS (0x00000002UL)
#define ADC_SAMPLE_STATUS (0x00000004UL)
#define ADC_CONVERSION_STATUS (0x00000006UL)

/**********************************************************************************
***************               Interrupt Status Register (ISR)        **************
**********************************************************************************/
/**
* @brief          ECH.
* @details        End of chain conversion.
*/
#define ADC_ISR_END_CHAIN_NORM_CONV (0x00000001UL)
#define ADC_ISR_END_CHAIN_NORM_CLEAN (0x00000001UL)

/**
* @brief          EOC.
* @details        End of channel conversion.
*/
#define ADC_ISR_END_CHANNEL_NORM_CONV (0x00000002UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_END_CHANNEL_NORM_CONV_CLEAN (0x00000002UL)

/**
* @brief          JECH.
* @details        End of injected chain conversion.
*/
#define ADC_ISR_END_CHAIN_INJ_CONV (0x00000004UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_END_CHAIN_INJ_CONV_CLEAN (0x00000004UL)

/**
* @brief          JEOC.
* @details        End of injected channel conversion.
*/
#define ADC_ISR_END_CHANNEL_INJ_CONV (0x00000008UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_END_CHANNEL_INJ_CONV_CLEAN (0x00000008UL)

/**
* @brief          EOCTU.
* @details        End of CTU conversion.
*                 It is the interrupt of the digital end of conversion for the CTU channel;
*                 active when set.
*/
#define ADC_ISR_END_CHANNEL_CTU_CONV (0x00000010UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_END_CHANNEL_CTU_CONV_CLEAN (0x00000010UL)

/* if Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
/**
* @brief          EOFFSET.
* @details        Error in offset refresh.
*                 It is the interrupt of the error in offset refresh: it's generated during the
*                 offset cancellation phase; active when set. */
#define ADC_ISR_ERROR_IN_OFFSET_REFRESH (0x00000020UL)
#define ADC_ISR_ERROR_OFFSET_REFRESH_CLEAN (0x00000020UL)

/**
* @brief          OFFCANCOVR.
* @details        Offset Cancellatin Phase Over.
*                 It is the interupt when the ADC generates the offset_ok_i to high indication
*                 then the offset cancellation phase programmed by the user is over and the offset
*                 coefficient is written into the offset register; active when set.
*/
#define ADC_ISR_OFFSET_IN_CANC_OVER (0x00000040UL)
#define ADC_ISR_OFFSET_IN_CANC_OVER_CLEAN (0x00000040UL)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M  */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          REF_RANGE.
* @details        This bit is set if REF_RANGE output from the ADC does not match with the expected
*                 value programmed in the MCR.
*/
#define ADC_ISR_REF_RANGE_NOT_MATCH_SET (0x00008000UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_REF_RANGE_NOT_MATCH_CLEAN (0x00008000UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */

#define ADC_ISR_RESET_VALUE  (0x00000000UL)

/**********************************************************************************
***************    Ch Pending Status Register (CEOCFRx)             **************
**********************************************************************************/
/* if !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
/**
* @brief          CEOCFR0 reset value.
*/
#define ADC_CEOCFR0_RESET_VALUE  (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          EOC_CHn When set, the measure of channel n is completed.
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_COMPLETED_CH_CONVERSION(Ch) ((uint32)(1<<(Ch)))

/**********************************************************************************
***************        Interrupt Mask Register (IMR)                **************
**********************************************************************************/

/**
* @brief          MSKECH.
* @details        Mask bit for ECH.
*/
#define ADC_ISR_END_CHAIN_NORM_CONV_EN (0x00000001UL)
#define ADC_ISR_END_CHAIN_NORM_CONV_DIS (0x0UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_END_CHAIN_NORM_CONV_MASK (ADC_ISR_END_CHAIN_NORM_CONV_EN)

/**
* @brief          MSKJECH.
* @details        Mask bit for JECH.
*/
#define ADC_ISR_END_CHAIN_INJ_CONV_EN (0x00000004UL)
#define ADC_ISR_END_CHAIN_INJ_CONV_DIS (0x0UL)
#define ADC_ISR_END_CHAIN_INJ_CONV_MASK (ADC_ISR_END_CHAIN_INJ_CONV_EN)

/**
* @brief          MSKJEOC.
* @details        Mask bit for JEOC.
*/
#define ADC_ISR_END_CHANNEL_INJ_CONV_EN (0x00000008UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_END_CHANNEL_INJ_CONV_DIS (0x0UL)

/**
* @brief          MSKEOCTU.
* @details        Mask bit for EOCTU.
*                 When set, the interrupt is enabled.
*/
#define ADC_ISR_END_CHANNEL_CTU_CONV_EN (0x00000010UL)
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ISR_END_CHANNEL_CTU_CONV_DIS (0x0UL)

/* if Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
/**
* @brief          MSKEOFFSET.
* @details        Mask bit for EOFFSET.
*/
#define ADC_ISR_ERROR_OFFSET_REFRESH_EN (0x00000020UL)
#define ADC_ISR_ERROR_OFFSET_REFRESH_DIS (0x0UL)

/**
* @brief          MSKJEOC.
* @details        Mask bit for JEOC.
*/
#define ADC_ISR_OFFSET_CANC_OVER_EN (0x00000040UL)
#define ADC_ISR_OFFSET_CANC_OVER_DIS (0x0UL)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M  */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          MSK_REF_RANGE.
* @details        Mask bit for REF_RANGE.
*/
#define ADC_ISR_REF_RANGE_EN (0x00008000UL)
#define ADC_ISR_REF_RANGE_DIS (0x0UL)
#define ADC_ISR_REF_RANGE_MASK (ADC_ISR_REF_RANGE_EN)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */

#define ADC_IMR_RESET_VALUE  (0x0UL)

/**********************************************************************************
***************      Ch Interrupt Mask Register (CIMRx)              **************
**********************************************************************************/
/**
* @brief          When set (CIMn = 1), interrupt for channel n is enabled.
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ENABLE_END_ISR_CH_CONVERSION(Ch) ((uint32)(1<<(Ch)))

#define ADC_CIMR_RESET_VALUE  (0x0UL)

/**********************************************************************************
****************   WatchDog Threshold Interrupt Status Register (WTISR) ***********
**********************************************************************************/
/**
* @brief          WDG0L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 0.
*/
/* !Fado and !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH0_LOW_ISR_STATUS (0x00000001UL)
 #else /* Pictus1M */
#define ADC_WTH0_LOW_ISR_STATUS (0x00000001UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH0_LOW_ISR_STATUS (0x00000001UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          WDG1L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 1.
*/
/* !Fado and !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH1_LOW_ISR_STATUS (0x00000004UL)
 #else /* Pictus1M */
#define ADC_WTH1_LOW_ISR_STATUS (0x00000002UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH1_LOW_ISR_STATUS (0x00000002UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          WDG2L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 2.
*/
/* !Fado and !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH2_LOW_ISR_STATUS (0x00000010UL)
 #else /* Pictus1M */
#define ADC_WTH2_LOW_ISR_STATUS (0x00000004UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH2_LOW_ISR_STATUS (0x00000004UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/**
* @brief          WDG3L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 3.
*/
/* !Fado and !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
#define ADC_WTH3_LOW_ISR_STATUS (0x00000040UL)
 #else /* Pictus1M */
#define ADC_WTH3_LOW_ISR_STATUS (0x00000008UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH3_LOW_ISR_STATUS (0x00000008UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
/**
* @brief          WDG4L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 4.
*/
#define ADC_WTH4_LOW_ISR_STATUS (0x00000100UL)
/**
* @brief          WDG5L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 5.
*/
#define ADC_WTH5_LOW_ISR_STATUS (0x00000400UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther or Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
/**
* @brief          WDG6L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 6.
*/
#define ADC_WTH6_LOW_ISR_STATUS (0x00001000UL)

/**
* @brief          WDG7L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 7.
*/
#define ADC_WTH7_LOW_ISR_STATUS (0x00004000UL)

/**
* @brief          WDG8L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 8.
*/
#define ADC_WTH8_LOW_ISR_STATUS (0x00010000UL)

/**
* @brief          WDG9L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 9.
*/
#define ADC_WTH9_LOW_ISR_STATUS (0x00040000UL)

/**
* @brief          WDG10L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 10.
*/
#define ADC_WTH10_LOW_ISR_STATUS (0x00100000UL)

/**
* @brief          WDG11L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 11.
*/
#define ADC_WTH11_LOW_ISR_STATUS (0x00400000UL)

/**
* @brief          WDG12L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 12.
*/
#define ADC_WTH12_LOW_ISR_STATUS (0x01000000UL)

/**
* @brief          WDG13L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 13.
*/
#define ADC_WTH13_LOW_ISR_STATUS (0x04000000UL)

/**
* @brief          WDG14L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 14.
*/
#define ADC_WTH14_LOW_ISR_STATUS (0x10000000UL)

/**
* @brief          WDG15L.
* @details        This corresponds to the interrupt generated on the converted value being
*                 lower than the programmed lower threshold 15.
*/
#define ADC_WTH15_LOW_ISR_STATUS (0x40000000UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) 
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */

/**
* @brief          WDG0H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 0.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH0_HIGH_ISR_STATUS (0x00000002UL)
 #else /* Pictus1M */
#define ADC_WTH0_HIGH_ISR_STATUS (0x00000010UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH0_HIGH_ISR_STATUS (0x00000010UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          WDG1H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 1.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH1_HIGH_ISR_STATUS (0x00000008UL)
 #else /* Pictus1M */
#define ADC_WTH1_HIGH_ISR_STATUS (0x00000020UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH1_HIGH_ISR_STATUS (0x00000020UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          WDG2H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 2.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
/* if !Pictus1M */
#ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH2_HIGH_ISR_STATUS (0x00000020UL)
 #else /* Pictus1M */
#define ADC_WTH2_HIGH_ISR_STATUS (0x00000040UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH2_HIGH_ISR_STATUS (0x00000040UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/**
* @brief          WDG3H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 3.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH3_HIGH_ISR_STATUS (0x00000080UL)
 #else /* Pictus1M */
#define ADC_WTH3_HIGH_ISR_STATUS (0x00000080UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH3_HIGH_ISR_STATUS (0x00000080UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          WDG4H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 4.
*/
#define ADC_WTH4_HIGH_ISR_STATUS (0x00000200UL)

/**
* @brief          WDG5H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 5.
*/
#define ADC_WTH5_HIGH_ISR_STATUS (0x00000800UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther or Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
/**
* @brief          WDG6H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 6.
*/
#define ADC_WTH6_HIGH_ISR_STATUS (0x00002000UL)

/**
* @brief          WDG7H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 7.
*/
#define ADC_WTH7_HIGH_ISR_STATUS (0x00008000UL)

/**
* @brief          WDG8H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 8.
*/
#define ADC_WTH8_HIGH_ISR_STATUS (0x00020000UL)

/**
* @brief          WDG9H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 9.
*/
#define ADC_WTH9_HIGH_ISR_STATUS (0x00080000UL)

/**
* @brief          WDG10H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 10.
*/
#define ADC_WTH10_HIGH_ISR_STATUS (0x00200000UL)

/**
* @brief          WDG11H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 11.
*/
#define ADC_WTH11_HIGH_ISR_STATUS (0x00800000UL)

/**
* @brief          WDG12H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 12.
*/
#define ADC_WTH12_HIGH_ISR_STATUS (0x02000000UL)

/**
* @brief          WDG13H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 13.
*/
#define ADC_WTH13_HIGH_ISR_STATUS (0x08000000UL)

/**
* @brief          WDG14H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 14.
*/
#define ADC_WTH14_HIGH_ISR_STATUS (0x20000000UL)

/**
* @brief          WDG15H.
* @details        This corresponds to the interrupt generated on the converted value being 
*                 greater than the programmed higher threshold 15.
*/
#define ADC_WTH15_HIGH_ISR_STATUS (0x80000000UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */

#define ADC_WTISR_RESET_VALUE  (0x0UL)

/**********************************************************************************
**************   WatchDog Threshold Interrupt Mask Register (WTIMR)  **************
**********************************************************************************/
/**
* @brief          MSKWDG0L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 0.
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
/* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M 
#define ADC_WTH0_LOW_ISR_EN (0x00000001UL)
#define ADC_WTH0_LOW_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH0_LOW_ISR_EN (0x00000001UL)
#define ADC_WTH0_LOW_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH0_LOW_ISR_EN (0x00000001UL)
#define ADC_WTH0_LOW_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          MSKWDG1L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 1.
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH1_LOW_ISR_EN (0x00000004UL)
#define ADC_WTH1_LOW_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH1_LOW_ISR_EN (0x00000002UL)
#define ADC_WTH1_LOW_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH1_LOW_ISR_EN (0x00000002UL)
#define ADC_WTH1_LOW_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          MSKWDG2L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 2.
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH2_LOW_ISR_EN (0x00000010UL)
#define ADC_WTH2_LOW_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH2_LOW_ISR_EN (0x00000004UL)
#define ADC_WTH2_LOW_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH2_LOW_ISR_EN (0x00000004UL)
#define ADC_WTH2_LOW_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/**
* @brief          MSKWDG3L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 3.
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH3_LOW_ISR_EN (0x00000040UL)
#define ADC_WTH3_LOW_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH3_LOW_ISR_EN (0x00000008UL)
#define ADC_WTH3_LOW_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH3_LOW_ISR_EN (0x00000008UL)
#define ADC_WTH3_LOW_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          MSKWDG4L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 4.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH4_LOW_ISR_EN (0x00000100UL)
#define ADC_WTH4_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG5L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 5.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH5_LOW_ISR_EN (0x00000400UL)
#define ADC_WTH5_LOW_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M or Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          MSKWDG6L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 6.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH6_LOW_ISR_EN (0x00001000UL)
#define ADC_WTH6_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG7L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 7.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH7_LOW_ISR_EN (0x00004000UL)
#define ADC_WTH7_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG8L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 8.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH8_LOW_ISR_EN (0x00010000UL)
#define ADC_WTH8_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG9L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 9.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH9_LOW_ISR_EN (0x00040000UL)
#define ADC_WTH9_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG10L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 10.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH10_LOW_ISR_EN (0x00100000UL)
#define ADC_WTH10_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG11L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 11.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH11_LOW_ISR_EN (0x00400000UL)
#define ADC_WTH11_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG12L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 12.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH12_LOW_ISR_EN (0x01000000UL)
#define ADC_WTH12_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG13L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 13.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH13_LOW_ISR_EN (0x04000000UL)
#define ADC_WTH13_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG14L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 14.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH14_LOW_ISR_EN (0x10000000UL)
#define ADC_WTH14_LOW_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG15L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 15.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH15_LOW_ISR_EN (0x40000000UL)
#define ADC_WTH15_LOW_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || 
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */

/**
* @brief          MSKWDG0H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 0. 
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH0_HIGH_ISR_EN (0x00000002UL)
#define ADC_WTH0_HIGH_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH0_HIGH_ISR_EN (0x00000010UL)
#define ADC_WTH0_HIGH_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH0_HIGH_ISR_EN (0x00000010UL)
#define ADC_WTH0_HIGH_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          MSKWDG1H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 1.
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH1_HIGH_ISR_EN (0x00000008UL)
#define ADC_WTH1_HIGH_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH1_HIGH_ISR_EN (0x00000020UL)
#define ADC_WTH1_HIGH_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH1_HIGH_ISR_EN (0x00000020UL)
#define ADC_WTH1_HIGH_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**
* @brief          MSKWDG2H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 2.
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH2_HIGH_ISR_EN (0x00000020UL)
#define ADC_WTH2_HIGH_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH2_HIGH_ISR_EN (0x00000040UL)
#define ADC_WTH2_HIGH_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH2_HIGH_ISR_EN (0x00000040UL)
#define ADC_WTH2_HIGH_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/**
* @brief          MSKWDG3H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 3.
*                 When set the interrupt is enabled.
*/
/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_WTH3_HIGH_ISR_EN (0x00000080UL)
#define ADC_WTH3_HIGH_ISR_DIS (0x0UL)
 #else /* Pictus1M */
#define ADC_WTH3_HIGH_ISR_EN (0x00000080UL)
#define ADC_WTH3_HIGH_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#else /* Fado or Pictus512_256 */
#define ADC_WTH3_HIGH_ISR_EN (0x00000080UL)
#define ADC_WTH3_HIGH_ISR_DIS (0x0UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if !Fado && !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
/**
* @brief          MSKWDG4H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 4.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH4_HIGH_ISR_EN (0x00000200UL)
#define ADC_WTH4_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG5H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 5.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH5_HIGH_ISR_EN (0x00000800UL)
#define ADC_WTH5_HIGH_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M or Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
/**
* @brief          MSKWDG6H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 6.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH6_HIGH_ISR_EN (0x00002000UL)
#define ADC_WTH6_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG7H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 7.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH7_HIGH_ISR_EN (0x00008000UL)
#define ADC_WTH7_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG8H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 8.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH8_HIGH_ISR_EN (0x00020000UL)
#define ADC_WTH8_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG9H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 9.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH9_HIGH_ISR_EN (0x00080000UL)
#define ADC_WTH9_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG10H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 10.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH10_HIGH_ISR_EN (0x00200000UL)
#define ADC_WTH10_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG11H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 11.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH11_HIGH_ISR_EN (0x00800000UL)
#define ADC_WTH11_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG12H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 12.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH12_HIGH_ISR_EN (0x02000000UL)
#define ADC_WTH12_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG13H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 13.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH13_HIGH_ISR_EN (0x08000000UL)
#define ADC_WTH13_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG14H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 14.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH14_HIGH_ISR_EN (0x20000000UL)
#define ADC_WTH14_HIGH_ISR_DIS (0x0UL)

/**
* @brief          MSKWDG15H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 15.
*                 When set the interrupt is enabled.
*/
#define ADC_WTH15_HIGH_ISR_EN (0x80000000UL)
#define ADC_WTH15_HIGH_ISR_DIS (0x0UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */

#define ADC_WTIMR_RESET_VALUE  (0x0UL)

/**********************************************************************************
***************             DMAE Register (DMAE)                    **************
**********************************************************************************/
/**
* @brief          DMAEN.
* @details        DMA global enable.
*                 When this bit is set, the DMA feature is enabled.
*/
#define ADC_DMA_GLOBAL_EN (0x00000001UL)
#define ADC_DMA_GLOBAL_DIS (0x0UL)

/**
* @brief          DCLR.
* @details        DMA clear sequence enable.
*                 0: DMA request cleared by Acknowledge from DMA controller
*                 1: DMA request cleared on read of data registers.
*/
#define ADC_DMA_REQ_CLEAR_ON_READ (0x00000002UL)
#define ADC_DMA_REQ_CLEAR_ON_ACK (0x0UL)

#define ADC_DMAE_RESET_VALUE  (0x0UL)

/**********************************************************************************
***************                  DMA Register (DMAR)                **************
**********************************************************************************/
/**
* @brief          When set (DMAn = 1), channel n is enabled to transfer data in DMA mode.
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_ENABLE_DMA_TRANSFER(Ch) ((uint32)(1<<(Ch)))

#define ADC_DMAR_RESET_VALUE  (0x0UL)


/**********************************************************************************
***************    Threshold Control Register (TRCx)                **************
**********************************************************************************/
/**
* @brief          THRCH.
* @details        Choose the channel for threshold comparison.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_CH_THRESHOLD_COMP(x) ((uint32)(x))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_TH_OUTPUT_PIN_INVERT(x)     ((uint32)(((uint32)(x))<<14))
#define INVERT_OUTPUT_PIN               (0x1U)
#define NO_INVERT_OUTPUT_PIN            (0x1U)

/**
* @brief          THREN.
* @details        Threshold enable
*                 When set, this bit enables the threshold detection feature for the selected channel.
*/
#define ADC_TH_ENABLE (0x8000U)
#define ADC_TH_DISABLE (0x0000U)

/**
* @brief          TRCx reset values.
*/
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
#define ADC_TRC0_RESET_VALUE          (0x0UL)
#define ADC_TRC1_RESET_VALUE          (0x0UL)
#define ADC_TRC2_RESET_VALUE          (0x0UL)
#define ADC_TRC3_RESET_VALUE          (0x0UL)
#define ADC_TRCx_RESET_VALUE          (0x0UL)
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */

/**
* @brief          Threshold register values
*/
#define ADC_THRESHOLD_REG_0           ((uint8)0x0)
#define ADC_THRESHOLD_REG_1           ((uint8)0x1)
#define ADC_THRESHOLD_REG_2           ((uint8)0x2)
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
#define ADC_THRESHOLD_REG_3           ((uint8)0x3)
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
#ifdef IPV_ADCDIG
/* if Bolero 1.5M or Leopard or Bolero 3M or Leopard cut 2 or Pictus1M or Komodo 2M or Panther or Calypso */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  /* if !Pictus1M */
  #ifndef IPV_ADCDIG_31301_PICTUS1M
   #ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
   #define ADC_THRESHOLD_REG_4           ((uint8)0x4)
   #define ADC_THRESHOLD_REG_5           ((uint8)0x5)
   #endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
  #endif /* IPV_ADCDIG_31301_PICTUS1M */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
#endif /* IPV_ADCDIG */
/* if Leopard or Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther */
#if (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
   #define ADC_THRESHOLD_REG_6           ((uint8)0x6)
   #define ADC_THRESHOLD_REG_7           ((uint8)0x7)
   #define ADC_THRESHOLD_REG_8           ((uint8)0x8)
   #define ADC_THRESHOLD_REG_9           ((uint8)0x9)
   #define ADC_THRESHOLD_REG_10          ((uint8)0xA)
   #define ADC_THRESHOLD_REG_11          ((uint8)0xB)
   #define ADC_THRESHOLD_REG_12          ((uint8)0xC)
   #define ADC_THRESHOLD_REG_13          ((uint8)0xD)
   #define ADC_THRESHOLD_REG_14          ((uint8)0xE)
   #define ADC_THRESHOLD_REG_15          ((uint8)0xF)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */

/**********************************************************************************
***************   Threshold  Register (THRHLRx)                      **************
**********************************************************************************/
/**
* @brief          THRH.
* @details        High threshold value for channel x
* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined
*/
#define ADC_HIGH_TH_VALUE(Th) ((uint32)((uint32)(Th)<<16))

/**
* @brief          THRL.
* @details        Low threshold value for channel x
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH_VALUE(Th) ((uint32)(Th))

/**
* @brief          Low and High threshold values.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH0_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH1_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH2_VALUE(Th) ((uint32)(Th))
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH3_VALUE(Th) ((uint32)(Th))
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH0_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH1_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH2_VALUE(Th) ((uint32)((uint32)(Th)<<16))
#ifndef IPV_ADCDIG_31201_BOLERO256K /* !Bolero 256k-128k */
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH3_VALUE(Th) ((uint32)((uint32)(Th)<<16))
#endif /* ifndef IPV_ADCDIG_31201_BOLERO256K */
/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH4_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH5_VALUE(Th) ((uint32)(Th))

 /* !Calypso */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH6_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH7_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH8_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH9_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH10_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH11_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH12_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH13_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH14_VALUE(Th) ((uint32)(Th))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_LOW_TH15_VALUE(Th) ((uint32)(Th))
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
 
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH4_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH5_VALUE(Th) ((uint32)((uint32)(Th)<<16))

 /* !Calypso */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH6_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH7_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH8_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH9_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH10_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH11_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH12_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH13_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH14_VALUE(Th) ((uint32)((uint32)(Th)<<16))
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_HIGH_TH15_VALUE(Th) ((uint32)((uint32)(Th)<<16))
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */

/**
* @brief          Threshold reset values.
*/
/* If !Calypso */
#if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
/* !Bolero 256k-128k and !Rainier and !Calypso */
#if (!defined(IPV_ADCDIG_31201_BOLERO256K)) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
/* if !Leopard cut2/cut3 and !Pictus1M and !Komodo 2M and !Panther */
#if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
#define ADC_UNUSED_THRESHOLD          (0x0UL)
#define ADC_THRHLR0_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR1_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR2_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR3_RESET_VALUE       (0x03FF0000UL)
#define ADC_THRHLRx_RESET_VALUE       (0x03FF0000UL)
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
#define ADC_THRHLR4_RESET_VALUE       (0x03FF0000UL)
#define ADC_THRHLR5_RESET_VALUE       (0x03FF0000UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
#else /* Leopard cut2/cut3 or Pictus1M or Komodo 2M */
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
#define ADC_UNUSED_THRESHOLD          (0x0UL)
#define ADC_THRHLR0_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR1_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR2_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR3_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR4_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR5_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR6_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR7_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR8_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR9_RESET_VALUE       (0x0FFF0000UL)
#define ADC_THRHLR10_RESET_VALUE      (0x0FFF0000UL)
#define ADC_THRHLR11_RESET_VALUE      (0x0FFF0000UL)
#define ADC_THRHLR12_RESET_VALUE      (0x0FFF0000UL)
#define ADC_THRHLR13_RESET_VALUE      (0x0FFF0000UL)
#define ADC_THRHLR14_RESET_VALUE      (0x0FFF0000UL)
#define ADC_THRHLR15_RESET_VALUE      (0x0FFF0000UL)
#define ADC_THRHLRx_RESET_VALUE       (0x0FFF0000UL)
 #else /* Pictus1M */
#define ADC_UNUSED_THRESHOLD          (0x0UL)
#define ADC_THRHLR0_RESET_VALUE       (0x03FF0000UL)
#define ADC_THRHLR1_RESET_VALUE       (0x03FF0000UL)
#define ADC_THRHLR2_RESET_VALUE       (0x03FF0000UL)
#define ADC_THRHLR3_RESET_VALUE       (0x03FF0000UL)
#define ADC_THRHLRx_RESET_VALUE       (0x03FF0000UL)
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */
#else /* Bolero 256k-128k or Rainier */
  #define ADC_UNUSED_THRESHOLD          (0x0UL)
  #define ADC_THRHLR0_RESET_VALUE       (0x0FFF0000UL)
  #define ADC_THRHLR1_RESET_VALUE       (0x0FFF0000UL)
  #define ADC_THRHLR2_RESET_VALUE       (0x0FFF0000UL)
  /* Rainier */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
    #define ADC_THRHLR3_RESET_VALUE     (0x0FFF0000UL)
  #endif
  #define ADC_THRHLRx_RESET_VALUE       (0x0FFF0000UL)
#endif /* IPV_ADCDIG_31201_BOLERO256K or Rainier */
#else /* Calypso */
  #define ADC_UNUSED_THRESHOLD          (0x0UL)
  /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
  #define ADC_THRHLR_RESET_VALUE(unit)  (((unit) == (uint8)0) ? (0x03FF0000UL) : (0x0FFF0000UL))
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
/**********************************************************************************
***************        Presampling Control Register (PSCR)         **************
**********************************************************************************/

/* if !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
/**
* @brief          PRECONV.
* @details        Convert presampled value.
*                 If bit PRECONV is set, presampling is followed by the conversion.
*                 Sampling will be bypassed and conversion of presampled data will be done.
*/
#define ADC_PSCR_PRECONV_EN (0x00000001UL)
#define ADC_PSCR_PRECONV_DIS (0x0UL)

/**
* @brief          PREVAL0[0:1].
* @details        Internal voltage selection for presampling.
*                 Selects analog input voltage for presampling from the available internal 
*                 voltages (internal precision channels).
*/
/* if !Panther and !Rainier and !Calypso */
#if (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
    #define ADC_PSCR_PREVAL0_VSS_ZERO_VOLT (0x0UL)
    #define ADC_PSCR_PREVAL0_VSS_FIVE_VOLT (0x00000002UL)
#else
    /* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
    #define ADC_PSCR_PREVAL0_AGND_THREE_VOLT (0x0UL)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
    #define ADC_PSCR_PREVAL0_AVDD_THREE_VOLT (0x00000002UL)
    #define ADC_PSCR_PREVAL0_VREFL (0x00000004UL)
    #define ADC_PSCR_PREVAL0_VREFH (0x00000006UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */

/**
* @brief          PREVAL1[0:1].
* @details        Internal voltage selection for presampling.
*                 Selects analog input voltage for presampling from the available two internal
*                 voltages (internal extended channels).
*/
/* if !Panther and !Rainier and !Calypso */
#if (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
    #define ADC_PSCR_PREVAL1_VSS_ZERO_VOLT (0x0UL)
    #define ADC_PSCR_PREVAL1_VSS_FIVE_VOLT (0x00000008UL)
#else
    /* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
    #define ADC_PSCR_PREVAL1_AGND_THREE_VOLT (0x0UL)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
    #define ADC_PSCR_PREVAL1_AVDD_THREE_VOLT (0x00000008UL)
    #define ADC_PSCR_PREVAL1_VREFL (0x00000010UL)
    #define ADC_PSCR_PREVAL1_VREFH (0x00000018UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */

/**
* @brief          PREVAL2[0:1].
* @details        Internal voltage selection for presampling.
*                 Selects analog input voltage for presampling from the available two internal
*                 voltages (external channels).
*/
/* if !Panther and !Rainier and !Calypso */
#if (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
    #define ADC_PSCR_PREVAL2_VSS_ZERO_VOLT (0x0UL)
    #define ADC_PSCR_PREVAL2_VSS_FIVE_VOLT (0x00000020UL)
    /* Rainier or Calypso */
#elif (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
    #define ADC_PSCR_PREVAL2_AGND_THREE_VOLT (0x0UL)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_3 Identifier exceeds 31 characters */
    #define ADC_PSCR_PREVAL2_AVDD_THREE_VOLT (0x00000020UL)
    #define ADC_PSCR_PREVAL2_VREFL (0x00000040UL)
    #define ADC_PSCR_PREVAL2_VREFH (0x00000060UL)
#else /* Panther */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) */

#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */


/**********************************************************************************
***************        Presampling Register (PSR[0..2])         **************
**********************************************************************************/
/* if !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
/**
* @brief          ADC_PSR_CH_EN.
* @details        Presampling register channel.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_PSR_CH_EN(Ch) ((uint32)(1<<(Ch)))
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */

/**********************************************************************************
***************        Conversion Timing Register (CTRx)         **************
**********************************************************************************/
#ifdef IPV_ADCDIG
/* !Panther and !Rainier and !Calypso */
#if (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
/**
* @brief          INPLATCH.
* @details        Configuration bit for Latching phase duration.
*                 - 0b means half clock cycle;
*                 - 1b means 1 clock cycle.
*                 The 1b condition is possible only if INPCMP is bigger than 01b otherwise it is
*                 automatically set to 0b inside the ADC.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_INPLATCH_VALUE(x) ((uint16)((uint16)(x)<<15))

/**
* @brief          Half ot onne clock.
*/
#define ADC_HALF_CLOCK_CYCLE          (0x0U)
#define ADC_ONE_CLOCK_CYCLE           (0x1U)

#ifdef IPV_ADCDIG
 /* if Pictus512_256 or Leopard or Leopard cut2/cut3 or Pictus1M or Komodo 2M */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
     (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01)  || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)
/**
* @brief          ADC_NO_SHIFT, ADC_AVIN_1_2_LSB, ADC_AVIN_0
*/
#define ADC_NO_SHIFT                  (0x0U)
#define ADC_AVIN_1_2_LSB              (0x1U)
#define ADC_AVIN_0                    (0x2U)
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_OFFSETSHIFT_VALUE(x) ((uint16)((uint16)(x)<<12))
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01)*/
#endif /* IPV_ADCDIG */

/**
* @brief          INPCMP.
* @details        Configuration bits for the comparison duration.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_INPCMP_VALUE(x) ((uint16)((uint16)(x)<<9))

/**
* @brief          Zero, one, two or three latch cycle values.
*/
#define ADC_ZERO_LATCH_CYCLE          (0x0U)
#define ADC_ONE_LATCH_CYCLE           (0x1U)
#define ADC_TWO_LATCH_CYCLE           (0x2U)
#define ADC_THREE_LATCH_CYCLE         (0x3U)
#define ADC_FOUR_LATCH_CYCLE          (0x0U)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */

/**
* @brief          INPSAMP.
* @details        Configuration of sampling phase duration.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_INPSAMP_VALUE(x) ((uint16)(x))

/* if Leopard cut2/cut3 or Pictus1M or Panther or Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
/**
* @brief          INPSAMP.
* @details        Configuration of sampling phase duration.
*/
 /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
 #define ADC_INPSAMP1_VALUE(x) ((uint16)((uint16)(x)<<1))
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */

/**
* @brief          CTRx reset values.
*/
/* !Panther and !Rainier and !Calypso */
#if (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
#define ADC_CTR0_RESET_VALUE          (0x203UL)
#define ADC_CTR1_RESET_VALUE          (0x203UL)
#define ADC_CTR2_RESET_VALUE          (0x203UL)
#else
#define ADC_CTR0_RESET_VALUE          (0x16UL)
#define ADC_CTR1_RESET_VALUE          (0x16UL)
#define ADC_CTR2_RESET_VALUE          (0x16UL)
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10) */
#endif /* IPV_ADCDIG */
/**********************************************************************************
***************   Normal Conversion Mask Register (NCMRx)            **************
**********************************************************************************/
/**
* @brief          When set, sampling is enabled for channel n.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_NORMAL_CONV_CH_EN(Ch) ((uint32)((uint32)1<<(uint32)(Ch)))

/**
* @brief          NCMR register reset value.
*/
#define ADC_NCMR_RESET_VALUE          (0x0UL)

/**
* @brief          Adc channel id.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_ID_CHANNEL(id)            ((uint32)(id))

/**********************************************************************************
***************  Injected Conversion Mask Register (JCMRx)           **************
**********************************************************************************/
/**
* @brief          When set, inj sampling is enabled for channel n.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_INJ_CONV_CH_EN(Ch) ((uint32)(1<<(Ch)))

/**
* @brief          JCMR register reset value.
*/
#define ADC_JCMR_RESET_VALUE          (0x0UL)

/*********************************************************************************
*************** Decode Signals Delay Register (DSDR)               ***************
**********************************************************************************/
/**
* @brief          DSDR.
* @details        The delay between the external decode signals and the start of the sampling
*                 phase. It is used to take into account the settling time of the external mux.
*/
#ifdef IPV_ADCDIG
 /* if !Pictus512_256 */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01)
 /* if Bolero 1.5M or Leopard or Bolero 3M or Rainier or Calypso */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define MUX_DELAY_VALUE(x) ((uint16)(x))
  #else
    /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
    #define MUX_DELAY_VALUE(x) ((uint8)(x))
  #endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_02_00_01) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
                (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
 #endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
#else
  /* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
  #define MUX_DELAY_VALUE(x) ((uint8)(x))
#endif /* #ifdef IPV_ADCDIG */

/**********************************************************************************
*************** Power-Down Exit Delay Registers (PDEDR)              **************
**********************************************************************************/
/**
* @brief          PDED.
* @details        The delay between the power-down bit reset and the starting of conversion.
*/
/* @violates @ref Reg_eSys_ADCDig_h_REF_1 Function-like macro defined */
#define ADC_POWERDOWN_EXIT_DELAY_VALUE(x) ((uint8)(x))

/**
* @brief          PDEDR register reset value.
*/
#define ADC_PDEDR_RESET_VALUE (0x0UL)


/**********************************************************************************
*************** Data Registers                                       **************
**********************************************************************************/

/**
* @brief          Mask used to verify the DATA registers content (VALID flag).
*/
#define ADC_VALID_DATA_MASK (0x00080000UL)


/**********************************************************************************
******    ADCDig ERRATA switches
**********************************************************************************/

#ifdef IPV_ADCDIG
  /* If Bolero 3M (or Bolero 256k-128k) OR Bolero 512K OR Bolero 1.5M */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01)

    /* If Errata workaround is enabled */
    #if defined(ADC_ENABLE_ERRATA_INTERRUPTED_NORMAL_GROUP) && \
      (STD_ON == ADC_ENABLE_ERRATA_INTERRUPTED_NORMAL_GROUP) && \
      (defined(ERR_IPV_ADCDIG_0015)) && (STD_ON == ERR_IPV_ADCDIG_0015)

      /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
      #define ENABLE_ERR_IPV_ADCDIG_0015  (STD_ON)

    #else

      /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
      #define ENABLE_ERR_IPV_ADCDIG_0015  (STD_OFF)

    #endif

    /* If Errata workaround is enabled */
    #if defined(ADC_ENABLE_ERRATA_OPTIMIZED_SW_ABORT) && \
      (STD_ON == ADC_ENABLE_ERRATA_OPTIMIZED_SW_ABORT) && \
      (defined(ERR_IPV_ADCDIG_0014)) && (STD_ON == ERR_IPV_ADCDIG_0014)

      /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
      #define ENABLE_ERR_IPV_ADCDIG_0014  (STD_ON)

    #else

      /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
      #define ENABLE_ERR_IPV_ADCDIG_0014  (STD_OFF)

    #endif
    
    #if defined(ERR_IPV_ADCDIG_0016) && (STD_ON == ERR_IPV_ADCDIG_0016)
      /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
      #define ENABLE_ERR_IPV_ADCDIG_0016  (STD_ON)
    #endif

  #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) */
#endif /* ifdef IPV_ADCDIG */

#ifndef ENABLE_ERR_IPV_ADCDIG_0015
  /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
  #define ENABLE_ERR_IPV_ADCDIG_0015  (STD_OFF)
#endif

#ifndef ENABLE_ERR_IPV_ADCDIG_0014
  /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
  #define ENABLE_ERR_IPV_ADCDIG_0014  (STD_OFF)
#endif

#ifndef ENABLE_ERR_IPV_ADCDIG_0016
  /* @violates @ref Reg_eSys_ADCDig_h_REF_4 Re-use of C90 identifier pattern */
  #define ENABLE_ERR_IPV_ADCDIG_0016  (STD_OFF)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_ADCDIG_H */

/** @} */
