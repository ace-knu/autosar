/**
*   @file    Mcu_PBcfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Mcu postbuild configuration parameters.
*   @details This file contains the mcu postbuild configuration parameters.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF13_ASR_REL_4_0_REV_0003_20170719
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
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
* @section Mcu_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Mcu_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Mcu_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Mcu_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_PBcfg_c_REF_5
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR
* specifications although it exceeds the max length of 31 characters.
*
* @section Mcu_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section Mcu_PBcfg_c_REF_7
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_LLD.h"

#ifndef MCU_PRECOMPILE_SUPPORT
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*
* @implements     DMCU04030, DMCU04031, DMCU04032, DMCU04033, DMCU04034, DMCU04035,
*                 DMCU04036
*/
#define MCU_VENDOR_ID_PBCFG_C                      43
/*
* @violates @ref Mcu_PBcfg_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
/*
* @violates @ref Mcu_PBcfg_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_MINOR_VERSION_PBCFG_C       0
/*
* @violates @ref Mcu_PBcfg_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
/**
* @violates @ref Mcu_PBcfg_c_REF_5 MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define MCU_AR_RELEASE_REVISION_VERSION_PBCFG_C    3
#define MCU_SW_MAJOR_VERSION_PBCFG_C               1
#define MCU_SW_MINOR_VERSION_PBCFG_C               0
#define MCU_SW_PATCH_VERSION_PBCFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu header file are of the same vendor */
#if (MCU_VENDOR_ID_PBCFG_C != MCU_LLD_VENDOR_ID)
    #error "Mcu_PBcfg.c and Mcu_LLD.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_lld.h header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_PBCFG_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION_PBCFG_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_PBcfg and Mcu_lld.h are different"
#endif
/* Check if current file and Mcu_lld.h header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_PBCFG_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_PBCFG_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_PBCFG_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_PBcfg and Mcu_lld.h are different"
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
/*
* @violates @ref Mcu_PBcfg_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Mcu_PBcfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include' 
*/

#include "MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/






STATIC CONST(Mcu_RamConfigType, MCU_CONST) Mcu_RamConfigPB_1[1]  = {    /* start of Mcu_RamConfig[0] */
    {
    /* @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    (uint32 *)0x40000000UL,             /* section base address (must be aligned to 4 bytes) */
    (uint32)0x00000400UL,        /* section size in bytes (must be multiple of 4) */
    (uint32)0xbabababaul /* value to be filled with */
    } /* end of Mcu_RamConfig[0] */

};


STATIC CONST(Mcu_ModeConfigType, MCU_CONST) Mcu_ModeConfigPB_1[3] ={

 
 /* start of Mcu_ModeConfig[1] */
 /*RUN0*/
    {
        MCU_RUN0_MODE,/* Select the Mode */
        (ME_MAIN_VOLATAGE_ON|
                    
                /* empty ELSE means PDO is set to false in DRUN or RUN0..3 or HALT */
                        
                ME_MODE_DFAON(ME_DFLASH_NORMAL)|
                ME_MODE_CFAON(ME_CFLASH_NORMAL)|
                   ME_PLL0_ON|
                ME_XOSC_ON|
            
            
                ME_RC_ON|
            
                ME_MODE_SYSCLK(ME_SYSCLK_SWITCH_PLL0)),
                
        
        
            0xFFFFFFFFU,
        

        (boolean)TRUE,
        0x1U,/*ClockConfig*/
        
            (boolean)FALSE,/*Enable system clock*/
        
        0U/* Reset Sequence for Standby mode exit */
    },
/* end of Mcu_ModeConfig[1] */

 
 /* start of Mcu_ModeConfig[2] */
 /*RUN2*/
    {
        MCU_RUN2_MODE,/* Select the Mode */
        (ME_MAIN_VOLATAGE_ON|
                    
                /* empty ELSE means PDO is set to false in DRUN or RUN0..3 or HALT */
                        
                ME_MODE_DFAON(ME_DFLASH_NORMAL)|
                ME_MODE_CFAON(ME_CFLASH_NORMAL)|
                   ME_PLL0_OFF|
                ME_XOSC_ON|
            
            
                ME_RC_ON|
            
                ME_MODE_SYSCLK(ME_SYSCLK_SWITCH_DIV_XOSC)),
                
        
        
            0xFFFFFFFFU,
        

        (boolean)TRUE,
        0x2U,/*ClockConfig*/
        
            (boolean)FALSE,/*Enable system clock*/
        
        0U/* Reset Sequence for Standby mode exit */
    },
/* end of Mcu_ModeConfig[2] */

 
 /* start of Mcu_ModeConfig[3] */
 /*HALT*/
    {
        MCU_HALT_MODE,/* Select the Mode */
        (ME_MAIN_VOLATAGE_ON|
                    
                /* empty ELSE means PDO is set to false in DRUN or RUN0..3 or HALT */
                        
                ME_MODE_DFAON(ME_DFLASH_NORMAL)|
                ME_MODE_CFAON(ME_CFLASH_NORMAL)|
                   ME_PLL0_ON|
                ME_XOSC_ON|
            
               
/* @errata ERR_IPV_MC_0005 */
#ifdef ERR_IPV_MC_0005
  #if (ERR_IPV_MC_0005== STD_ON)
                                         ME_RC_ON|
                 
   #endif
#else
                  ME_RC_ON|
#endif
            
                ME_MODE_SYSCLK(ME_SYSCLK_SWITCH_PLL0)),
                
        
        
            0xFFFFFFFFU,
        

        (boolean)FALSE,
        0x1U,/*ClockConfig*/
        
            (boolean)FALSE,/*Enable system clock*/
        
        0U/* Reset Sequence for Standby mode exit */
    }
/* end of Mcu_ModeConfig[3] */
};

STATIC CONST(Mcu_ClockConfigType, MCU_CONST) Mcu_ClockConfigPB_1[2] = {/* start of Mcu_ClockConfig[1] */
    {
  /*McuPLL*/
        (ME_MCTL_TARGET_MODE(ME_TARGET_MODE_RUN0)|        
            ME_POWER_DOWN_OUT_OFF|
            ME_MODE_DFAON(ME_DFLASH_NORMAL)|
            ME_MODE_CFAON(ME_CFLASH_NORMAL)|
            ME_PLL0_ON|
            ME_XOSC_ON|
            ME_RC_ON|
            ME_MODE_SYSCLK(ME_SYSCLK_SWITCH_PLL0)),            
        (DISABLE_OSC_ISR|
            EOCV_OSC_VALUE(200)|
            OSC_BYP_OFF|
            OSC_DIV(1)),    /* XTAL_A */
        (DISABLE_OSC_ISR|
            EOCV_OSC_VALUE(100)|
            OSC_BYP_OFF|
            OSC_DIV(1)|
            DISABLE_OSC),    /* XTAL_B */
        0x00000000UL,     /* RC_16MHz */
        0x00000000UL,    /* RC_128KHz */
        (CLOCK_OUT_DIV(CLOCK_OUT_8_DIV)|
            CLOCK_OUT_SOURCE(CLOCK_OUT_SOURCE_PLL0)|
            CLOCK_OUT_ENABLE),    /* Clk_Output */
        MCU_PLL0_NORMAL_MODE,     /* Pll0_Mode */
        (FMPLL_CR_IDF_3|
          FMPLL_CR_ODF_4|
          FMPLL_CR_NDIV(96)|
          FMPLL_DISABLE_SW|
          FMPLL_FAIL_DISABLE),    /* Pll0_Param */                
        0x00000000UL,    /* Pll0_FM */
        0x80808000UL,     /* PeripheralClock */
        0x03000000UL,    /* Clock Monitor */
        {
         {0x34003f00UL,   /* EMIOS_MCR_A */
        0x34003f00UL}   /* EMIOS_MCR_B */
        },
        0x10840000UL,    /* PFCR0 system clock dependent values*/
        0x10840000UL,    /* PFCR1 system clock dependent  values*/
        64000000UL    /* System Clock Frequency */
    },
/* end of Mcu_ClockConfig[1] */
/* start of Mcu_ClockConfig[2] */
    {
  /*McuDivExtQuartzOsc*/
        (ME_MCTL_TARGET_MODE(ME_TARGET_MODE_RUN2)|        
            ME_POWER_DOWN_OUT_OFF|
            ME_MODE_DFAON(ME_DFLASH_NORMAL)|
            ME_MODE_CFAON(ME_CFLASH_NORMAL)|
            ME_PLL0_OFF|
            ME_XOSC_ON|
            ME_RC_ON|
            ME_MODE_SYSCLK(ME_SYSCLK_SWITCH_DIV_XOSC)),            
        (DISABLE_OSC_ISR|
            EOCV_OSC_VALUE(100)|
            OSC_BYP_OFF|
            OSC_DIV(1)),    /* XTAL_A */
        (DISABLE_OSC_ISR|
            EOCV_OSC_VALUE(100)|
            OSC_BYP_OFF|
            OSC_DIV(1)|
            ENABLE_OSC),    /* XTAL_B */
        0x00000000UL,     /* RC_16MHz */
        0x00000000UL,    /* RC_128KHz */
        (CLOCK_OUT_DIV(CLOCK_OUT_NO_DIV)|
            CLOCK_OUT_SOURCE(CLOCK_OUT_SOURCE_XOSC)|
            CLOCK_OUT_ENABLE),    /* Clk_Output */
        MCU_PLL0_UNUSED_MODE,     /* Pll0_Mode */
              (FMPLL_CR_IDF_2|
          FMPLL_CR_ODF_4|
          FMPLL_CR_NDIV(64)|
          FMPLL_DISABLE_SW|
          FMPLL_FAIL_DISABLE),    /* Pll0_Param */
      
        0x00000000UL,    /* Pll0_FM */
        0x80808000UL,     /* PeripheralClock */
        0x03000000UL,    /* Clock Monitor */
        {
         {0x54000000UL,   /* EMIOS_MCR_A */
        0x54000000UL}   /* EMIOS_MCR_B */
        },
        0x00000000UL,    /* PFCR0 system clock dependent values*/
        0x00000000UL,    /* PFCR1 system clock dependent  values*/
        8000000UL    /* System Clock Frequency */
    }
/* end of Mcu_ClockConfig[2] */
};
STATIC CONST(McuLLD_ConfigType, MCU_CONST) McuLLD_ConfigPB_1 =
    {
        /* Run Config Mode0  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Run Config Mode1  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Run Config Mode2  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Run Config Mode3  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Run Config Mode4  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Run Config Mode5  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Run Config Mode6  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Run Config Mode7  */
        (ME_RUN_RUN3_ACTIVE|ME_RUN_RUN2_ACTIVE|ME_RUN_RUN1_ACTIVE|ME_RUN_RUN0_ACTIVE|ME_RUN_DRUN_ACTIVE|ME_RUN_SAFE_ACTIVE),
         /* Low Power Mode  0  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_FROZEN|ME_RUN_HALT_ACTIVE),
         /* Low Power Mode  1  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_ACTIVE|ME_RUN_HALT_ACTIVE),
         /* Low Power Mode  2  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_FROZEN|ME_RUN_HALT_FROZEN),
         /* Low Power Mode  3  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_FROZEN|ME_RUN_HALT_FROZEN),
         /* Low Power Mode  4  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_FROZEN|ME_RUN_HALT_FROZEN),
         /* Low Power Mode  5  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_FROZEN|ME_RUN_HALT_FROZEN),
         /* Low Power Mode  6  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_FROZEN|ME_RUN_HALT_FROZEN),
         /* Low Power Mode  7  */
        (ME_RUN_STBY_FROZEN|ME_RUN_STOP_FROZEN|ME_RUN_HALT_FROZEN),
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* DSPI0 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* DSPI1 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* DSPI2 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* DSPI3 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* DSPI4 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* DSPI5 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX8 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX9 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* FlexCAN0 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* FlexCAN1 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* FlexCAN2 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* FlexCAN3 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* FlexCAN4 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* FlexCAN5 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* DMA_CH_MUX */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* ADC0 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* ADC1 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* I2C0 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX0 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX1 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX2 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX3 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX4 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX5 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX6 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* LIN_FLEX7 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* CTU */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* CANSampler */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC1),  /* SIUL */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC1),  /* WKPU */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* eMIOS0 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* eMIOS1 */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC1),  /* RTC_API */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* PIT_RTI */
         ME_PCTLn(ME_RUN_PC0, ME_LP_PC0),  /* CMU0 */
 
        (ME_ME_RUN3_ENABLE|
            ME_ME_STANDBY_ENABLE|
            ME_ME_STOP_ENABLE|
            ME_ME_HALT_ENABLE|
            ME_ME_RUN2_ENABLE|
            ME_ME_RUN1_ENABLE),    /*ModeEnabled                                */
 
        (FERD_JTAG_RESET|
            FERD_CORE_RESET|
            FERD_SOFT_RESET|
            FERD_CHKSTOP_RESET|
            FERD_PLL0_RESET|
            FERD_CMU0_OLR_RESET|
            FERD_CMU0_FHL_RESET|
            FERD_LVD45_RESET|
            FERD_FLASH_RESET|
            FERD_EXR_RESET),    /* Func_ResetOpt   */
       (FEAR_JTAG_SAFE|
            FEAR_CORE_SAFE|
            FEAR_PLL0_SAFE|
            FEAR_CMU0_OLR_SAFE|
            FEAR_CMU0_FHL_SAFE|
            FEAR_LVD45_SAFE|
            FEAR_FLASH_SAFE|
            FEAR_EXR_SAFE),
/* @errata ERR_IPV_MC_0019 */
#ifdef ERR_IPV_MC_0019
   #if (ERR_IPV_MC_0019 == STD_ON)
       (FESS_JTAG_PH1|
         FESS_CORE_PH1|
         FESS_SOFT_PH1|
         FESS_CHKSTOP_PH1|
         FESS_PLL0_PH1|
         FESS_CMU0_OLR_PH1|
         FESS_CMU0_FHL_PH1|
         FESS_LVD45_PH1|
         FESS_FLASH_PH1|
         FESS_EXR_PH1),           /* Func_Phase1or3Opt   */
   #else
        (FESS_JTAG_PH1|
            FESS_CORE_PH1|
            FESS_SOFT_PH1|
            FESS_CHKSTOP_PH1|
            FESS_PLL0_PH1|
            FESS_CMU0_OLR_PH1|
            FESS_CMU0_FHL_PH1|
            FESS_LVD45_PH1|
            FESS_FLASH_PH1|
            FESS_EXR_PH1),           /* Func_Phase1or3Opt   */
   #endif
#else
       (FESS_JTAG_PH1|
            FESS_CORE_PH1|
            FESS_SOFT_PH1|
            FESS_CHKSTOP_PH1|
            FESS_PLL0_PH1|
            FESS_CMU0_OLR_PH1|
            FESS_CMU0_FHL_PH1|
            FESS_LVD45_PH1|
            FESS_FLASH_PH1|
            FESS_EXR_PH1),           /* Func_Phase1or3Opt   */
#endif
        (FBRE_JTAG_DIS|
            FBRE_CORE_DIS|
            FBRE_SOFT_DIS|
            FBRE_CHKSTOP_EN|
            FBRE_PLL0_DIS|
            FBRE_CMU0_OLR_DIS|
            FBRE_CMU0_FHL_DIS|
            FBRE_LVD45_DIS|
            FBRE_FLASH_DIS|
            FBRE_EXR_DIS),    /* Ext_PinReset   */


 
        (uint16)0x25fd,  /* PowerDomain */
        0xfffffffeUL,  /* Timeout */
        (uint8)0x00, /* IsrMode */ 
        {{(uint8)0x1, (uint8)0x2, (uint8)0x3, (uint8)0x4, /* DMAMUX 0, 1, 2, 3 */ 
        (uint8)0x5, (uint8)0x6, (uint8)0x7, (uint8)0x8, /* DMAMUX 4, 5, 6, 7 */
        (uint8)0x9, (uint8)0xa, (uint8)0xb, (uint8)0xc, /* DMAMUX 8, 9, 10, 11 */
        (uint8)0x11, (uint8)0x12, (uint8)0x13, (uint8)0x14}}, /* DMAMUX 12, 13, 14, 15 */ 
        {{(uint32)0x00000000UL},            /* EDMA.CR */
        {(uint8)0x00U, (uint8)0x01U, (uint8)0x02U, (uint8)0x03U, /* EDMA.CPR0,1,2,3 */    
        (uint8)0x04U, (uint8)0x05U, (uint8)0x06U, (uint8)0x07U, /* EDMA.CPR4,5,6,7 */     
        (uint8)0x08U, (uint8)0x09U, (uint8)0x0aU, (uint8)0x0bU, /* EDMA.CPR8,9,10,11 */   
        (uint8)0x0cU, (uint8)0x0dU, (uint8)0x0eU, (uint8)0x0fU}, /* EDMA.CPR12,13,14,15 */    
    },         
        (uint32)0x000180edUL,         /* PFCR0 */
        (uint32)0x00018081UL,         /* PFCR1 */
        (uint32)0x00050033UL,         /* PFAPR */
 };
/* @violates @ref Mcu_PBcfg_c_REF_6 Required Rule 8.10 Object could be made static */
CONST(Mcu_ConfigType, MCU_CONST) McuModuleConfiguration_0 =
    {
        MCU_CLOCKNOTIFICATION_DISABLE,    /* globally enable/disable SCM, loss of clock and loss of lock notification */
        1UL,                     /* number of ram sections */
        (uint8) 3U,                 /* number of low power modes */
        (uint8) 2U,                       /* number of clock settings */
        Mcu_RamConfigPB_1,             /* pointer to ram section configurations */
        Mcu_ModeConfigPB_1,            /* pointer to low power mode configurations */
        Mcu_ClockConfigPB_1,           /* pointer to clock settings configurations */
        &McuLLD_ConfigPB_1 ,            /*  pointer to low level*/
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                    {(uint32)STD_OFF, 0U},/* MCU_E_CLOCK_FAILURE parameters*/
            {(uint32)STD_OFF, 0U},/* MCU_E_LOCK_FAILURE parameters*/
            {(uint32)STD_OFF, 0U},/* MCU_E_QUARTZ_FAILURE parameters*/
            {(uint32)STD_OFF, 0U}/* MCU_E_TIMEOUT_TRANSITION parameters*/
        
#endif /* MCU_DISABLE_DEM_REPORT_ERROR_STATUS== STD_ON */  
    };
/* put McuModuleConfiguration_0 structure into specified section */
/*
* @violates @ref Mcu_PBcfg_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Mcu_PBcfg_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PBcfg_c_REF_7 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/

#include "MemMap.h"

#endif /* MCU_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */
