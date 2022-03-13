/**
*   @file    Reg_eSys_CTU.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details Ctu module registers, and macrodefinitions used to manipulate the module registers.
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

#ifndef REG_eSys_CTU_H
#define REG_eSys_CTU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_CTU_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Reg_eSys_CTU_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_CTU_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Reg_eSys_CTU_h_REF_1 Repeated include file */
#include "Std_Types.h"
/* @violates @ref Reg_eSys_CTU_h_REF_1 Repeated include file */
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_CTU.h
*
*/
#define CTU_REG_VENDOR_ID                       (43)
/* @violates @ref Reg_eSys_CTU_h_REF_3 Identifier exceeds 31 characters */
#define CTU_REG_AR_RELEASE_MAJOR_VERSION        (4)
/* @violates @ref Reg_eSys_CTU_h_REF_3 Identifier exceeds 31 characters */
#define CTU_REG_AR_RELEASE_MINOR_VERSION        (0)
/* @violates @ref Reg_eSys_CTU_h_REF_3 Identifier exceeds 31 characters */
#define CTU_REG_AR_RELEASE_REVISION_VERSION     (3)
#define CTU_REG_SW_MAJOR_VERSION                (1)
#define CTU_REG_SW_MINOR_VERSION                (0)
#define CTU_REG_SW_PATCH_VERSION                (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if Std_Types.h file and CTU register header file are of the same Autosar version */
 #if ((CTU_REG_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (CTU_REG_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Reg_eSys_CTU.h and Std_Types.h are different"
 #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief         These definitions are used to select the derivatives.
*/
#define IPV_CTU_00_00_08_02 (0x802UL) /**< @brief bolero 512K cut2 - v0.8.b */
#define IPV_CTU_00_00_02_02 (0x202UL) /**< @brief bolero 1.5M cut 1.0 - v0.2.b */
#define IPV_CTU_00_00_02_03 (0x203UL) /**< @brief bolero 1.5M cut 2.0 - v0.2.c */
#define IPV_CTU_00_00_07_02 (0x702UL) /**< @brief Fado - v0.7.b */
#define IPV_CTU_00_00_04_01 (0x401UL) /**< @brief bolero 3M and bolero 256k-128k - v0.4.a */
#define IPV_CTU_00_00_03_01 (0x301UL) /**< @brief bolero 1.5M cut 2.2 - v0.3.a */

#ifdef IPV_CTU
 /* if !Fado */
 #if (IPV_CTU != IPV_CTU_00_00_07_02)
/**
* @brief         Definition of PIT_3 and PIT_7 trigger source.
*/
  #define CTU_PIT_3 (23U)
  #define CTU_PIT_7 (55U)
 #else /* Fado */
/**
* @brief         Definition of PIT_3 trigger source.
*/
  #define CTU_PIT_3 (32U)
 #endif /* (IPV_CTU != IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef IPV_CTU
 /* if Bolero 3M or Bolero 256k-128k or Bolero 512K or Bolero 1.5M */
 #if(IPV_CTU==IPV_CTU_00_00_04_01)||(IPV_CTU==IPV_CTU_00_00_03_01)||(IPV_CTU== IPV_CTU_00_00_08_02)
/**
* @brief          CTU A base address.
*/
  #define CTU_A_BASEADDR (CTU_BASEADDR)
 #endif /* (IPV_CTU == IPV_CTU_00_00_04_01) || (IPV_CTU == IPV_CTU_00_00_03_01) || (IPV_CTU == IPV_CTU_00_00_08_02) */
#endif /* IPV_CTU */

/* if !Bolero 3M (Bolero 256k-128k) and !Bolero 512K and !Bolero 1.5M */
#if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                            (IPV_CTU != IPV_CTU_00_00_03_01) && \
                            (IPV_CTU != IPV_CTU_00_00_08_02))
/**
* @brief Control Status Register
*/
#define CTU_CSR ((CTU_A_BASEADDR + (uint32)0x0UL))
#endif /* if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                                     (IPV_CTU != IPV_CTU_00_00_03_01) && \
                                     (IPV_CTU != IPV_CTU_00_00_08_02)) */

/**
* @brief Control Status Register - Trigger Interrupt Request Enable
*/
#define CTU_CSR_TRGIEN ((uint32)0x00000080UL)

/**
* @brief Control Status Register - Trigger Interrupt Flag
*/
#define CTU_CSR_TRGI ((uint32)0x40UL)

#ifdef IPV_CTU
 /* if Fado */
  #if (IPV_CTU == IPV_CTU_00_00_07_02)
   /**
    * @brief Control Status Register - Prescaler Configuration
    */
    #define CTU_CSR_PRESC_CONF ((uint32)0x0000000FUL)
  #endif /* (IPV_CTU == IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

#ifdef IPV_CTU
 /* if Fado */
  #if (IPV_CTU == IPV_CTU_00_00_07_02)
   /**
    * @brief Start Value Registers
    */
    #define CTU_SVR1      ((CTU_A_BASEADDR +  (uint32)0x4UL))
    #define CTU_SVR2      ((CTU_A_BASEADDR +  (uint32)0x8UL))
    #define CTU_SVR3      ((CTU_A_BASEADDR +  (uint32)0xCUL))
    #define CTU_SVR4      ((CTU_A_BASEADDR +  (uint32)0x10UL))
    #define CTU_SVR5      ((CTU_A_BASEADDR +  (uint32)0x14UL))
    #define CTU_SVR6      ((CTU_A_BASEADDR +  (uint32)0x18UL))
    #define CTU_SVR7      ((CTU_A_BASEADDR +  (uint32)0x1CUL))
    #define CTU_SVRx(x)   ((CTU_SVR1 + (((uint32)((uint32)(x)-(uint32)1))<<(uint32)2)))
    #define CTU_CVR0      ((CTU_A_BASEADDR +  (uint32)0x20UL))
    #define CTU_CVR1      ((CTU_A_BASEADDR +  (uint32)0x24UL))
    #define CTU_CVR2      ((CTU_A_BASEADDR +  (uint32)0x28UL))
    #define CTU_CVR3      ((CTU_A_BASEADDR +  (uint32)0x2CUL))
    #define CTU_CVRx(x)   ((CTU_CVR0 + ((uint32)(x)<<(uint32)2)))
  #endif /* (IPV_CTU == IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

/**
* @brief Event Configuration Register Trigger Mask
*/
#define CTU_EVTCFGR_TM ((uint32)0x00008000UL)

#ifdef IPV_CTU
 /* if Fado */
 #if (IPV_CTU == IPV_CTU_00_00_07_02)
/**
* @brief Counter Group
*/
 #define CTU_EVTCFGR_COUNT_GROUP ((uint32)0x00003000UL)

/**
* @brief Counter 0 is associated with the particular event
*/
 #define CTU_EVTCFGR_COUNTER0    ((uint32)0x0UL)

/**
* @brief Counter 1 is associated with the particular event
*/
 #define CTU_EVTCFGR_COUNTER1    ((uint32)0x00001000UL)

/**
* @brief Counter 2 is associated with the particular event
*/
 #define CTU_EVTCFGR_COUNTER2    ((uint32)0x00002000UL)

/**
* @brief Counter 3 is associated with the particular event
*/
 #define CTU_EVTCFGR_COUNTER3    ((uint32)0x00003000UL)

/**
* @brief Delay Index
*/
 #define CTU_EVTCFGR_DELAY_INDEX ((uint32)0x00000700UL)

/**
* @brief No delay is provided
*/
 #define CTU_EVTCFGR_NO_DELAY    ((uint32)0x0UL)

/**
* @brief Counter is loaded with value stored in CTU_SVR1
*/
 #define CTU_EVTCFGR_CNT_SVR1    ((uint32)0x00000100UL)

/**
* @brief Counter is loaded with value stored in CTU_SVR1
*/
 #define CTU_EVTCFGR_CNT_SVR2    ((uint32)0x00000200UL)

/**
* @brief Counter is loaded with value stored in CTU_SVR3
*/
 #define CTU_EVTCFGR_CNT_SVR3    ((uint32)0x00000300UL)
/**
* @brief Counter is loaded with value stored in CTU_SVR4
*/
 #define CTU_EVTCFGR_CNT_SVR4    ((uint32)0x00000400UL)

/**
* @brief Counter is loaded with value stored in CTU_SVR5
*/
 #define CTU_EVTCFGR_CNT_SVR5    ((uint32)0x00000500UL)

/**
* @brief Counter is loaded with value stored in CTU_SVR6
*/
 #define CTU_EVTCFGR_CNT_SVR6    ((uint32)0x00000600UL)

/**
* @brief Counter is loaded with value stored in CTU_SVR7
*/
 #define CTU_EVTCFGR_CNT_SVR7    ((uint32)0x00000700UL)
 #endif /* (IPV_CTU == IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

#ifdef IPV_CTU
 /* if !Fado */
 #if (IPV_CTU != IPV_CTU_00_00_07_02)
/**
* @brief Event Configuration Register Clear Flag for Bolero 512K
*/
 #define CTU_EVTCFGR_CLR_FLAG_512K ((uint32)0x00000080UL)

/**
* @brief Event Configuration Register Clear Flag for Bolero 1.5M
*/
 #define CTU_EVTCFGR_CLR_FLAG_1M5 ((uint32)0x00004000UL)

/**
* @brief Event Configuration Register Clear Flag for Bolero 3M
*/
 #define CTU_EVTCFGR_CLR_FLAG_3M  ((uint32)0x00004000UL)

/**
* @brief Event Configuration Register Clear Flag for Bolero 256K
*/
 #define CTU_EVTCFGR_CLR_FLAG_256k  ((uint32)0x00004000UL)
 #else /* Fado */
/**
* @brief Event Configuration Register Clear Flag for Fado
*/
 #define CTU_EVTCFGR_CLR_FLAG ((uint32)0x00000080UL)
 #endif /* (IPV_CTU != IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

#ifdef IPV_CTU
 /* if !Fado */
 #if (IPV_CTU != IPV_CTU_00_00_07_02)
/**
* @brief Event Configuration Register ADC Select Bit, If 0 then 10Bit ADC, If 1 then 12Bit ADC.
*        NB.: for Bolero 256k-128k select 1.
*/
 #define CTU_EVTCFGR_ADC_SEL ((uint32)0x00000100UL)
 #endif /* (IPV_CTU != IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

/**
* @brief Event Configuration Register - field positions - (used for shifts)
*        TM position in the register word
*/
#define CTU_EVTCFGR_TM_POS (15)

#ifdef IPV_CTU
 /* if !Fado */
 /**
  * @brief CLR_FLAG position in the register word.
  */
  #if (IPV_CTU != IPV_CTU_00_00_07_02)
    #define CTU_EVTCFGR_CLR_FLAG_POS_512K (7) /**< @brief for Bolero 512K */
    #define CTU_EVTCFGR_CLR_FLAG_POS_1M5 (14) /**< @brief for Bolero 1.5M */
    #define CTU_EVTCFGR_CLR_FLAG_POS_3M  (14) /**< @brief for Bolero 3M */
    #define CTU_EVTCFGR_ADC_SEL_POS (8)       /**< @brief ADC_SEL position in the register word */
    #define CTU_EVTCFGR_CLR_FLAG_POS_256k (14) /**< @brief for Bolero 256K */
  #else
    #define CTU_EVTCFGR_CLR_FLAG_POS (7)      /**< @brief for Fado */
    #define CTU_EVTCFGR_COUNT_GROUP_POS (12)  /**< @brief COUNT_GROUP position in the register word */
    #define CTU_EVTCFGR_DELAY_INDEX_POS (8)   /**< @brief DELAY_INDEX position in the register word */
  #endif /* (IPV_CTU != IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

#ifdef IPV_CTU
 /* if !Fado */
/**
 * @brief HW resources for DMA
 */
 #if (IPV_CTU != IPV_CTU_00_00_07_02)
  #define CTU_EMIOS_A0  (0U)
  #define CTU_EMIOS_A1  (1U)
  #define CTU_EMIOS_A9  (9U)
  #define CTU_EMIOS_A18 (18U)
  #define CTU_EMIOS_A25 (25U)
  #define CTU_EMIOS_A26 (26U)
  #define CTU_EMIOS_B0  (32U)
  #define CTU_EMIOS_B9  (41U)
  #define CTU_EMIOS_B17 (49U)
  #define CTU_EMIOS_B18 (50U)
  #define CTU_EMIOS_B25 (57U)
  #define CTU_EMIOS_B26 (58U)
  #define CTU_HWRES_FOR_DMA {\
    (CTU_EMIOS_A0|CTU_EMIOS_A1|CTU_EMIOS_A9|CTU_EMIOS_A18|CTU_EMIOS_A25|CTU_EMIOS_A26|\
     CTU_EMIOS_B0|CTU_EMIOS_B9|CTU_EMIOS_B17|CTU_EMIOS_B18|CTU_EMIOS_B25|CTU_EMIOS_B26)\
                            }
  #endif /* (IPV_CTU != IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

/**
* @brief Event Configuration Registers
*/
#define CTU_EVTCFGR0      ((CTU_A_BASEADDR +  0x030UL))
#define CTU_EVTCFGR1      ((CTU_A_BASEADDR +  0x034UL))
#define CTU_EVTCFGR2      ((CTU_A_BASEADDR +  0x038UL))
#define CTU_EVTCFGR3      ((CTU_A_BASEADDR +  0x03CUL))
#define CTU_EVTCFGR4      ((CTU_A_BASEADDR +  0x040UL))
#define CTU_EVTCFGR5      ((CTU_A_BASEADDR +  0x044UL))
#define CTU_EVTCFGR6      ((CTU_A_BASEADDR +  0x048UL))
#define CTU_EVTCFGR7      ((CTU_A_BASEADDR +  0x04CUL))
#define CTU_EVTCFGR8      ((CTU_A_BASEADDR +  0x050UL))
#define CTU_EVTCFGR9      ((CTU_A_BASEADDR +  0x054UL))
#define CTU_EVTCFGR10     ((CTU_A_BASEADDR +  0x058UL))
#define CTU_EVTCFGR11     ((CTU_A_BASEADDR +  0x05CUL))
#define CTU_EVTCFGR12     ((CTU_A_BASEADDR +  0x060UL))
#define CTU_EVTCFGR13     ((CTU_A_BASEADDR +  0x064UL))
#define CTU_EVTCFGR14     ((CTU_A_BASEADDR +  0x068UL))
#define CTU_EVTCFGR15     ((CTU_A_BASEADDR +  0x06CUL))
#define CTU_EVTCFGR16     ((CTU_A_BASEADDR +  0x070UL))
#define CTU_EVTCFGR17     ((CTU_A_BASEADDR +  0x074UL))
#define CTU_EVTCFGR18     ((CTU_A_BASEADDR +  0x078UL))
#define CTU_EVTCFGR19     ((CTU_A_BASEADDR +  0x07CUL))
#define CTU_EVTCFGR20     ((CTU_A_BASEADDR +  0x080UL))
#define CTU_EVTCFGR21     ((CTU_A_BASEADDR +  0x084UL))
#define CTU_EVTCFGR22     ((CTU_A_BASEADDR +  0x088UL))
#define CTU_EVTCFGR23     ((CTU_A_BASEADDR +  0x08CUL))
#define CTU_EVTCFGR24     ((CTU_A_BASEADDR +  0x090UL))
#define CTU_EVTCFGR25     ((CTU_A_BASEADDR +  0x094UL))
#define CTU_EVTCFGR26     ((CTU_A_BASEADDR +  0x098UL))
#define CTU_EVTCFGR27     ((CTU_A_BASEADDR +  0x09CUL))
/* if !Bolero 256k-128k */
#ifndef IPV_CTU_401_BOLERO256K
 #define CTU_EVTCFGR28     ((CTU_A_BASEADDR +  0x0A0UL))
 #define CTU_EVTCFGR29     ((CTU_A_BASEADDR +  0x0A4UL))
 #define CTU_EVTCFGR30     ((CTU_A_BASEADDR +  0x0A8UL))
 #define CTU_EVTCFGR31     ((CTU_A_BASEADDR +  0x0ACUL))
 #define CTU_EVTCFGR32     ((CTU_A_BASEADDR +  0x0B0UL))
#endif /* ifndef IPV_CTU_401_BOLERO256K */
#ifdef IPV_CTU
 /* if !Fado */
  #if (IPV_CTU != IPV_CTU_00_00_07_02)
   /* if !Bolero 256k-128k */
   #ifndef IPV_CTU_401_BOLERO256K
     #define CTU_EVTCFGR33     ((CTU_A_BASEADDR +  0x0B4UL))
     #define CTU_EVTCFGR34     ((CTU_A_BASEADDR +  0x0B8UL))
     #define CTU_EVTCFGR35     ((CTU_A_BASEADDR +  0x0BCUL))
     #define CTU_EVTCFGR36     ((CTU_A_BASEADDR +  0x0C0UL))
     #define CTU_EVTCFGR37     ((CTU_A_BASEADDR +  0x0C4UL))
     #define CTU_EVTCFGR38     ((CTU_A_BASEADDR +  0x0C8UL))
     #define CTU_EVTCFGR39     ((CTU_A_BASEADDR +  0x0CCUL))
     #define CTU_EVTCFGR40     ((CTU_A_BASEADDR +  0x0D0UL))
     #define CTU_EVTCFGR41     ((CTU_A_BASEADDR +  0x0D4UL))
     #define CTU_EVTCFGR42     ((CTU_A_BASEADDR +  0x0D8UL))
     #define CTU_EVTCFGR43     ((CTU_A_BASEADDR +  0x0DCUL))
     #define CTU_EVTCFGR44     ((CTU_A_BASEADDR +  0x0E0UL))
     #define CTU_EVTCFGR45     ((CTU_A_BASEADDR +  0x0E4UL))
     #define CTU_EVTCFGR46     ((CTU_A_BASEADDR +  0x0E8UL))
     #define CTU_EVTCFGR47     ((CTU_A_BASEADDR +  0x0ECUL))
     #define CTU_EVTCFGR48     ((CTU_A_BASEADDR +  0x0F0UL))
     #define CTU_EVTCFGR49     ((CTU_A_BASEADDR +  0x0F4UL))
     #define CTU_EVTCFGR50     ((CTU_A_BASEADDR +  0x0F8UL))
     #define CTU_EVTCFGR51     ((CTU_A_BASEADDR +  0x0FCUL))
     #define CTU_EVTCFGR52     ((CTU_A_BASEADDR +  0x100UL))
     #define CTU_EVTCFGR53     ((CTU_A_BASEADDR +  0x104UL))
     #define CTU_EVTCFGR54     ((CTU_A_BASEADDR +  0x108UL))
     #define CTU_EVTCFGR55     ((CTU_A_BASEADDR +  0x10CUL))
     #define CTU_EVTCFGR56     ((CTU_A_BASEADDR +  0x110UL))
     /* if !Bolero 512K */
     #if (IPV_CTU != IPV_CTU_00_00_08_02)
       #define CTU_EVTCFGR57     ((CTU_A_BASEADDR +  0x114UL))
       #define CTU_EVTCFGR58     ((CTU_A_BASEADDR +  0x118UL))
       #define CTU_EVTCFGR59     ((CTU_A_BASEADDR +  0x11CUL))
       #define CTU_EVTCFGR60     ((CTU_A_BASEADDR +  0x120UL))
       #define CTU_EVTCFGR61     ((CTU_A_BASEADDR +  0x124UL))
       #define CTU_EVTCFGR62     ((CTU_A_BASEADDR +  0x128UL))
       #define CTU_EVTCFGR63     ((CTU_A_BASEADDR +  0x12CUL))
     #endif /* (IPV_CTU != IPV_CTU_00_00_08_02) */
   #endif /* IPV_CTU_401_BOLERO256K */
  #endif /* (IPV_CTU != IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

#ifdef IPV_CTU
 /* if !Fado */
/**
 * @brief Total number of CTU_EVTCFGR/CTU_EVTCFGR registers
 */
 #if (IPV_CTU != IPV_CTU_00_00_07_02)
  /* if Bolero 256k-128k */
  #ifdef IPV_CTU_401_BOLERO256K
    #define MAXIMUM_NUMBER_OF_CTU_EVTCFGREGS (28)
  #endif /* IPV_CTU_401_BOLERO256K */
  /* if Bolero 512K */
  #if (IPV_CTU == IPV_CTU_00_00_08_02)
   #define MAXIMUM_NUMBER_OF_CTU_EVTCFGREGS (57)
  #endif /* (IPV_CTU == IPV_CTU_00_00_08_02) */
  /* if Bolero 1.5M or Bolero 3M */
  #if (IPV_CTU == IPV_CTU_00_00_03_01) || (IPV_CTU == IPV_CTU_00_00_04_01)
   /* If !Bolero 256k */
   #ifndef IPV_CTU_401_BOLERO256K
   /* @violates @ref Reg_eSys_CTU_h_REF_3 Identifier exceeds 31 characters */
   #define MAXIMUM_NUMBER_OF_CTU_EVTCFGREGS (64)
   #endif /* ifndef IPV_CTU_401_BOLERO256K */
  #endif /* (IPV_CTU == IPV_CTU_00_00_03_01) */
 #else /* Fado */
  #define MAXIMUM_NUMBER_OF_CTU_EVTCFGREGS (33)
  #define MAXIMUM_NUMBER_OF_CTU_SVRREGS (7)
  #define CTU_SVR_RESET_VALUE (0x0)
 #endif /* (IPV_CTU != IPV_CTU_00_00_07_02) */
#endif /* IPV_CTU */

/**
* @brief Event Configuration Register Reset value
*/
#define CTU_EVTCFGR_RESET_VALUE ((uint32)0x00000000)

/**
* @brief Event Configuration Register x macro accessReset value
*/
/* @violates @ref Reg_eSys_CTU_h_REF_2 Use of function like macro */
#define CTU_EVTCFGRx(x)   ((CTU_EVTCFGR0 + ((uint32)(x)<<(uint32)2)))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/* @violates @ref Reg_eSys_CTU_h_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

#define ADC_STOP_SEC_CODE
/* @violates @ref Reg_eSys_CTU_h_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* REG_eSys_CTU_H */

/** @} */
