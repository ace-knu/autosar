/**
*   @file    Mcu_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Mcu configuration header file.
*   @details This file contains mcu configuration defines.
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
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_Cfg_h_REF_1
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_Cfg_h_REF_2
* Violates MISRA 2004 Required Rule 19.4,
* Parenthesis can't be applied for this macro to avoid code compilation error.
*
* @section Mcu_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 8.7, objects shall be defined at block scope if they are only 
* accessed from within a single function.
*
* @section Mcu_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR
* specifications although it exceeds the max length of 31 characters.
*
* @section Mcu_Cfg_h_REF_5
* Violates MISRA 2004 Advisory Rule 19.7, a function should be used in preference to a function-like macro.
*/
#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_LLD.h"
#include "Dmamux_LLD.h"
#include "Mcu_eMIOS_LLD.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @implements     DMCU04001, DMCU04002, DMCU04003, DMCU04004, DMCU04005, DMCU04006,
*                 DMCU04007, DMCU04008
*/
#define MCU_VENDOR_ID_CFG                    43
#define MCU_MODULE_ID_CFG                    101
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_MAJOR_VERSION_CFG     4
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_MINOR_VERSION_CFG     0
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_REVISION_VERSION_CFG  3
#define MCU_SW_MAJOR_VERSION_CFG             1
#define MCU_SW_MINOR_VERSION_CFG             0
#define MCU_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/**
* @implements     DMCU06001
*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /*Check if current file and Dmamux_LLD. header file are of the same version */
    #if ((MCU_AR_RELEASE_MAJOR_VERSION_CFG != DMAMUX_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_AR_RELEASE_MINOR_VERSION_CFG != DMAMUX_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_cfg.h and Dmamux_LLD.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same version */
    #if ((MCU_AR_RELEASE_MAJOR_VERSION_CFG != DMA_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_AR_RELEASE_MINOR_VERSION_CFG != DMA_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_cfg.h and Dma_LLD.h are different"
    #endif
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/**
* @brief   development error detection enabled/disabled (STD_ON/STD_OFF)
*
* @implements     DMCU04009
* 
* @api
*/
#define MCU_DEV_ERROR_DETECT                    (STD_ON)

/**
* @brief   version info API enabled/disabled (STD_ON/STD_OFF)
*
* @implements     DMCU04010
* 
* @note           BSW00411 satisfied by MCU103, MCU104
*
* @api
*/
#define MCU_VERSION_INFO_API                    (STD_OFF)

/**
* @brief   the Api function Mcu_PerformReset is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_PERFORM_RESET_API                   (STD_ON)

/**
* @brief   the Api function Mcu_GetRamState is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_GET_RAM_STATE_API                   (STD_OFF)

/**
* @brief   the Api function Mcu_GetDeviceInfo is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_GET_DEVICE_INFO_API                   (STD_OFF)

/**
 * @brief   SSCM ERROR configurations is enabled/disabled (STD_ON/STD_OFF)
 *
 * @api
 */
#define MCU_SSCM_ERROR_CONFIG                   (STD_ON)


/**
* @brief   the Api function Mcu_SscmGetStatus is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_SSCM_GET_STATUS_API                 (STD_OFF)

/**
* @brief   the Api function Mcu_SscmGetMemConfig is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_SSCM_GET_MEMCONFIG_API              (STD_OFF)

/**
* @brief   the Api function Mcu_SscmGetUops is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_SSCM_GET_UOPS_API                   (STD_OFF)

/**
* @brief   dma initialization is enabled/disabled from the MCU driver (TRUE/FALSE)
*
* @api
*/
#define MCU_DMA_INIT                            (STD_ON)

/**
* @brief   clock initialization is enabled/disabled from the MCU driver (TRUE/FALSE)
*
* @api
*/
#define MCU_INIT_CLOCK                          (TRUE)

/**
* @brief   enable/disable the fact to call Mcu_Disable_Peripheral that gate all peripherals during clock initialization done by MCU driver (TRUE/FALSE)
*
* @api
*/
/* @violates @ref Mcu_Cfg_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31 characters.*/
#define MCU_INIT_CLOCK_DISABLE_PERIPHERAL       (TRUE)  
    
/**
* @brief   MCU_DistributePllClock isn't/is available (TRUE/FALSE)
*
* @api
*/
#define MCU_NO_PLL                              (FALSE)

/**
* @brief   the Api function Mcu_Flash_Configure is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_FLASH_CONFIGURATION_USED        (STD_ON)

/**
* @brief   if low power mode transition check should be enabled (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_LP_TRANSITION_CHECK     (STD_ON)

/**
* @brief   if enter low power mode transition enabled (STD_ON/STD_OFF)
*
* @implements     DMCU06068
*
* @api
*/
#define MCU_ENTER_LOW_POWER_MODE     (STD_ON)
/**
 * @brief   The remaining settings are/aren't applied after a missed transition (STD_ON/STD_OFF)
 *
 * @api
 */
#define MCU_SKIP_FUNCTION            (STD_OFF)

/**
* @brief   The Api function Mcu_eMios_Configure_GPREN is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_EMIOS_CONFIGURE_GPREN_API ((STD_OFF))

/**
* @brief   The callout clock notification is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
/* @violates @ref Mcu_Cfg_h_REF_1 Identifier exceeds 31 characters */
#define MCU_ENABLE_DISABLE_NOTIFICATION_API     (STD_OFF)





    /**
     * @brief   Clock Out can be enabled/disabled by AUTOSAR MCU APIs
     *
     * @api
     */
#define MCU_CONFIGURE_CLK_OUT    (STD_ON)

/**
* @brief   the ISR McuXOSC is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_XOSC_ISR_USED        (STD_OFF)
/**
* @brief   the ISR McuTransition complete is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_TRANSITION_COMPLETE_ISR_USED        (STD_OFF)

/**
* @brief   the ISR McuSafeMode is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_SAFE_MODE_ISR_USED                  (STD_OFF)

/**
* @brief   the ISR McuInvalidMode is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_INVALID_MODE_ISR_USED               (STD_OFF)

/**
* @brief   the ISR McuInvalidConfiguration is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_INVALID_CONFIGURATION_ISR_USED      (STD_OFF)

/**
* @brief   the ISR RGM_AlternateMode_ISR is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_RGM_ALTERNATEMODE_ISR_USED (STD_OFF)

/**
* @brief   the callout reset is/isn't available (STD_ON/STD_OFF)
*
* @api
*/
#define MCU_RESET_CALLOUT_USED                  (STD_OFF)





/**
 * @brief   SSCM ERROR configurations is enabled/disabled (STD_ON/STD_OFF)
 *
 * @api
 */
#define MCU_SSCM_ERROR_CONFIG     (STD_ON)

/**
 * @brief   SSCM Error Peripheral Bus Abort is enabled/disabled (STD_ON/STD_OFF)
 *
 * @api
 */
#define MCU_SSCM_ERROR_PAE_ENABLE     (STD_ON)

/**
 * @brief   SSCM Error Register Bus Abort is enabled/disabled (STD_ON/STD_OFF)
 *
 * @api
 */
#define MCU_SSCM_ERROR_RAE_ENABLE     (STD_ON)

/**
* @brief   Switches the Production Error Detection and Notification OFF
*
* @implements     DMCU06059
*
* @api
*/
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_DISABLE_DEM_REPORT_ERROR_STATUS   (STD_OFF) /* Disable Production Error Detection */


/* Extern declarations */
#define MCU_CFG_EXTERNS
/*
* @violates @ref Mcu_Cfg_h_REF_2 C macros shall only expand to a braced initializer...
*/
#define MCU_CONF_PB \
 extern CONST(Mcu_ConfigType, MCU_CONST) McuModuleConfiguration_0;




/** @brief associate index to McuClockSetting ID */
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifier exceeds 31 characters
* @violates @ref Mcu_Cfg_h_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define McuConf_McuClockSettingConfig_McuClockSettingConfig_PLL   1
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifier exceeds 31 characters
* @violates @ref Mcu_Cfg_h_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define McuConf_McuClockSettingConfig_McuClockSettingConfig_QUARTZ   2


/** @brief associate index to McuMode */
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifier exceeds 31 characters
* @violates @ref Mcu_Cfg_h_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define McuConf_McuModeSettingConf_McuModeSettingConf_PLL   1
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifier exceeds 31 characters
* @violates @ref Mcu_Cfg_h_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define McuConf_McuModeSettingConf_McuModeSettingConf_QUARTZ   2
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifier exceeds 31 characters
* @violates @ref Mcu_Cfg_h_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define McuConf_McuModeSettingConf_McuModeSettingConf_HALT   3

/** @brief associate index to McuRamSectorSettingConf settings */
/*
* @violates @ref Mcu_Cfg_h_REF_1 Identifier exceeds 31 characters
* @violates @ref Mcu_Cfg_h_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define McuModuleConfiguration_0_McuRamSectorSettingConf_0   0


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief the DMA is/isn't available (STD_ON/STD_OFF) */
#define HAS_DMA                     (STD_ON)

/** @brief the Power Domain #2 Configuration is/isn't available (STD_ON/STD_OFF) */
#define POWER_DOMAIN              (STD_ON)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief   Clock failure notification.     
* @details Enable/disable clock failure interrupt generated by the MCU.
*
* @implements     DMCU04011
* 
* @api
*/
typedef enum
{
    /**
     * @brief   Disable clock notification. 
     */
        MCU_CLOCKNOTIFICATION_DISABLE = 0,
    /**
     * @brief   Enable clock notification.    
     */  
        MCU_CLOCKNOTIFICATION_ENABLE
} Mcu_ClockNotificationType;

/**
* @brief          Lock status of the PLL.
* @details        This is a status value returned by the function Mcu_GettPllStatus
*                 of the MCU module.
*
* @implements     DMCU04012
*
* @api
*/
typedef enum
{
    /**
     * @brief   PLL is locked.
     */
        MCU_PLL_LOCKED = 0,
    /**
     * @brief   PLL is unlocked.
     */
        MCU_PLL_UNLOCKED,
     /**
     * @brief   PLL Status is unknown.
     */
        MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

/**
* @brief   Ram State of the microcontroller.
* @details This is the Ram State data type returned by the function 
* Mcu_GetRamState of the Mcu module.
*
* @api
*/
typedef enum
{
    /**
     * @brief   Ram content is not valid or unknown (default).
     */
        MCU_RAMSTATE_INVALID = 0,
    /**
     * @brief   Ram content is valid.
     */
        MCU_RAMSTATE_VALID
} Mcu_RamStateType;

/**
* @brief          Contains the subset of reset sources.     
*
* @implements     DMCU04013
*
* @api  
*/
typedef enum
{
     /**
      * @brief   Power on reset event.
      */
        MCU_POWER_ON_RESET = 0,
     /**
      * @brief   Internal Watchdog Timer reset event.
      */
        MCU_WATCHDOG_RESET,
     /**
      * @brief   Software Reset event.
      */
        MCU_SW_RESET,
     /**
      * @brief   Undefined reset source.
      */ 
        MCU_RESET_UNDEFINED,
     /**
      * @brief   2.7 V low-voltage detected.
      */
        MCU_2_7_LOW_VOLTAGE,
     /**
      * @brief   2.7 V low-voltage (VREG) detected.
      */
        MCU_2_7_LV_VREG_RESET,
     /**
      * @brief   1.2 V low-voltage detected event. (power domain 0). 
      */
        MCU_1_2_LV_PW_DOMAIN_0,
     /**
      * @brief   1.2 V low-voltage detected event. (power domain 1). 
      */
        MCU_1_2_LV_PW_DOMAIN_1,
     /**
      * @brief   External reset event.
      */ 
        MCU_EXR_RESET,
     /**
      * @brief   JTAG initiated reset event.
      */
        MCU_JTAG_RESET,
     /**
      * @brief   CORE reset event.
      */
        MCU_CORE_RESET,
     /**
      * @brief   Checkstop reset event.
      */
        MCU_CHECKSTOP_RESET,
     /**
      * @brief   PLL fail event.
      */
        MCU_PLL0_RESET,
     /**
      * @brief   Oscillator frequency lower than reference event.
      */
        MCU_CMU_OLR_RESET,
     /**
      * @brief   CMU0 clock frequency higher/lower than reference event.
      */
        MCU_CMU_FHL_RESET,
     /**
      * @brief   4.5V low-voltage detected event.
      */
        MCU_4_5_LOW_VOLTAGE,
     /**
      * @brief   Code or data flash fatal error event.
      */
        MCU_FLASH_RESET
} Mcu_ResetType;

/**
* @brief   Data flash memory present. 
*/
typedef enum {
    /**
     * @brief   No data flash memory is present. 
     */
      DATA_FLASH_NOT_PRESENT = 0,
    /**
     * @brief   Data flash memory is present. 
     */
      DATA_FLASH_PRESENT
} Mcu_Dflash_PresentType;

/**
* @brief   FlexRay present. 
*/
typedef enum {
    /**
     * @brief   FlexRay is not present. 
     */
      FLEXRAY_NOT_PRESENT = 0,
    /**
     * @brief   FlexRay is present. 
     */
      FLEXRAY_PRESENT
} Mcu_Flexray_PresentType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   Identifies a RAM section in the configuration structure.  
* @details The range is dependent on the number of RAM sections provided
*          in the configuration structure.
* 
* @implements           DMCU04014
*
* @api  
*/
typedef uint32 Mcu_RamSectionType;

/**
* @brief   Identifies a MCU mode in the configuration structure.   
* @details The range is dependent on the the number of MCU modes provided
*          in the configuration structure.
* 
* @implements           DMCU04015
*
* @api
*/
typedef uint8 Mcu_ModeType;

/**
* @brief   Identifies a clock setting in the configuration structure. 
* @details The range is dependent on the the number of clock settings
*           provided in the configuration structure.
* 
* @implements           DMCU04016
*
* @api
*/
typedef uint8 Mcu_ClockType;

/**
* @brief   Identifies the reset reason in raw status register format. 
* 
* @implements           DMCU04017
*
* @api
*/
typedef uint32 Mcu_RawResetType;

/**
* @brief   Definition of a RAM section within the configuration structure.
* 
* @implements           DMCU04018
*
* @api
*/
typedef struct
{
        /**
        * @brief   RAM section base address.
        */
        P2VAR (uint32, MCU_VAR, MCU_APPL_VAR) RamBaseAddr;
        /**
        * @brief   RAM section size.
        */
        VAR (uint32, MCU_VAR) RamSize;
        /**
        * @brief   RAM default value.
        */
        VAR (uint32, MCU_VAR) RamDefaultValue;
} Mcu_RamConfigType;

/**
* @brief   Definition of a MCU mode section in the configuration structure.
* @details Specifies the system behaviour during the selected target mode. 
* 
* @implements           DMCU04019
*
* @api
*/
typedef struct
{
     /**
     * @brief   The selected magic target mode.
     */
       VAR (uint16, MCU_VAR) Mode;
     /**
     * @brief   Specifies the system behaviour in the low-power target mode. 
     * @details Contains the parameters that specifies the system behaviour if a 
     *          low-power target mode has been chosen.
     * @note    @p SysClk<<0 + @p 16RC<<4 + @p XOSC<<5 + @p PLL0<<6 + 
     *          CFlash<<16 + @p DFlash<<18 + @p MainVolReg<<20 + 
     *          @p PowDownIO<<23
     */
       VAR (uint32, MCU_VAR) LP_Param; 
     /**
     * @brief   Specifies the system behaviour in the RUN target mode. 
     * @details Contains the parameters that specifies the system behaviour if  
     *          a RUN target mode (@p RUN0 | @p RUN1 | @p RUN2 | @p RUN3) has 
     *          been chosen.
     * @note    @p SysClk<<0 + @p XOSC<<5 + @p PLL0<<6 + @p CFlash<<16 + 
     *          DFlash<<18
     */       
       VAR (uint32, MCU_VAR) RUN_Param;
       VAR (boolean, MCU_VAR) Fast_Transition;
     /**
     * @brief   Identifies a clock setting in the configuration structure. 
     * @details The range is dependent on the the number of clock settings
     *          provided in the configuration structure.
     */
       VAR (Mcu_ClockType, MCU_VAR) ClockConfig;
     /**
      * @brief   Enables/disables the system clock. 
      * @details Enables/disables the system clock only if a @p STOP0 or TEST 
      *          target mode has been chosen.
      */
        VAR (boolean, MCU_VAR) DisableSystemClock;
     /**
      * @brief   Controls booting on @p STANDBY0 mode exit.
      */
        VAR (uint16, MCU_VAR) StbyMode;
} Mcu_ModeConfigType;

/**
* @brief   Definition of a clock configuration.
* 
* @implements          DMCU04020
*
* @api
*/
typedef struct
{
      /**
       * @brief   The selected target mode to be entered.  
       * @details Specifies the target mode to be entered when the clock 
       *          structure is initialized.
       */
        VAR (uint32, MCU_VAR) Start_Run_Mode; 
      /**
       * @brief   Configuration of the fast external crystal oscillator.
       */
        VAR (uint32, MCU_VAR) Xtal_A;
      /**
       * @brief   Configuration of the slow external crystal oscillator.
       */
        VAR (uint32, MCU_VAR) Xtal_B_32KHz;
      /**
       * @brief   Configuration of the 16Mhz fast internal RC oscillator.
       */ 
        VAR (uint32, MCU_VAR) RC_16MHz;
      /**
       * @brief   Configuration of the 128Khz slow internal RC oscillator.
       */
        VAR (uint32, MCU_VAR) RC_128KHz; 
      /**
       * @brief   System clock selection. 
       * @details Clock source selection possibilities: XTAL_A, RC_16MHz, PLL 
       *          plus division factor and Enable.
       */
        VAR (uint32, MCU_VAR) Clk_Output;
      /**
       * @brief   PLL mode selection. 
       * @details PLL mode selection possibilities: Normal, 1:1, FM, CLK_SW mode.
       */ 
        VAR (uint16, MCU_VAR) PllMode;
      /**
       * @brief   PLL output clock configuration. 
       * @details PLL output clock possibilities: IDF, NDIV and ODF factors 
       *          and mode, put the 1to1 mode or Progr Clk Sw.
       */
        VAR (uint32, MCU_VAR) Pll_Param;
      /**
       * @brief   PLL modulation configuration. 
       * @details PLL modulation configuration: VCO, md, sp, fmod and incstep.
       */
        VAR (uint32, MCU_VAR) FMPll_Param;
      /**
       * @brief   Divisor for Peripheral group 1, group 2 and group 3. 
       */
        VAR (uint32, MCU_VAR) Periph_Clk;
      /**
       * @brief   Enable/Disable Clk Monitor plus @p RCDIV, @p LFREF, @p HFREF. 
       */  
        VAR (uint32, MCU_VAR) Clk_Monitor; 
      /**
       * @brief   @p EMIOS module configuration variable.
       */
        VAR (eMIOS_ConfigType, MCU_VAR) eMIOS_Config; 
      /**
       * @brief   Platform Flash Configuration Register @p PFCR0.
       * @details Configuration associated with flash memory banks 0 and 2.
       * @note    System clock dependent values.
       */
        VAR (uint32, MCU_VAR) FLASH_PFCR0;
       /**
       * @brief   Platform Flash Configuration Register @p PFCR1.
       * @details Configuration associated with flash memory bank 1.
       * @note    System clock dependent values.
       */  
        VAR (uint32, MCU_VAR) FLASH_PFCR1;
       /**
       * @brief   System Clock Frequency
       */
        VAR (uint32, MCU_VAR) McuSystemClockFrequency;
} Mcu_ClockConfigType;
/**
* @brief   Mcu driver configuration structure.
* 
* @implements          DMCU04021
*
* @api
*/    
typedef struct
{
      /**
       * @brief   Configuration for @p ME_RUN_PC0. 
       * @details The user should choose the configuration for @p ME_RUN_PC0. 
       */
        VAR (uint32, MCU_VAR) RunConfig0;
      /**
       * @brief   Configuration for @p ME_RUN_PC1. 
       * @details The user should choose the configuration for @p ME_RUN_PC1. 
       */
        VAR (uint32, MCU_VAR) RunConfig1;
      /**
       * @brief   Configuration for @p ME_RUN_PC2. 
       * @details The user should choose the configuration for @p ME_RUN_PC2. 
       */  
        VAR (uint32, MCU_VAR) RunConfig2;
      /**
       * @brief   Configuration for @p ME_RUN_PC3. 
       * @details The user should choose the configuration for @p ME_RUN_PC3. 
       */  
        VAR (uint32, MCU_VAR) RunConfig3;
      /**
       * @brief   Configuration for @p ME_RUN_PC4. 
       * @details The user should choose the configuration for @p ME_RUN_PC4. 
       */ 
        VAR (uint32, MCU_VAR) RunConfig4;
      /**
       * @brief   Configuration for @p ME_RUN_PC5. 
       * @details The user should choose the configuration for @p ME_RUN_PC5. 
       */
        VAR (uint32, MCU_VAR) RunConfig5; 
      /**
       * @brief   Configuration for @p ME_RUN_PC6. 
       * @details The user should choose the configuration for @p ME_RUN_PC6. 
       */ 
        VAR (uint32, MCU_VAR) RunConfig6;
      /**
       * @brief   Configuration for @p ME_RUN_PC7. 
       * @details The user should choose the configuration for @p ME_RUN_PC7. 
       */ 
        VAR (uint32, MCU_VAR) RunConfig7;
      /**
       * @brief   Configuration for @p ME_LP_PC0. 
       * @details The user should choose the configuration for @p ME_LP_PC0.
       */
        VAR (uint32, MCU_VAR) LowPwrConfig0;
      /**
       * @brief   Configuration for @p ME_LP_PC1. 
       * @details The user should choose the configuration for @p ME_LP_PC1.
       */  
        VAR (uint32, MCU_VAR) LowPwrConfig1; 
      /**
       * @brief   Configuration for @p ME_LP_PC2. 
       * @details The user should choose the configuration for @p ME_LP_PC2.
       */  
        VAR (uint32, MCU_VAR) LowPwrConfig2; 
      /**
       * @brief   Configuration for @p ME_LP_PC3. 
       * @details The user should choose the configuration for @p ME_LP_PC3.
       */  
        VAR (uint32, MCU_VAR) LowPwrConfig3;
      /**
       * @brief   Configuration for @p ME_LP_PC4. 
       * @details The user should choose the configuration for @p ME_LP_PC4.
       */  
        VAR (uint32, MCU_VAR) LowPwrConfig4;
      /**
       * @brief   Configuration for @p ME_LP_PC5. 
       * @details The user should choose the configuration for @p ME_LP_PC5.
       */  
        VAR (uint32, MCU_VAR) LowPwrConfig5;
      /**
       * @brief   Configuration for @p ME_LP_PC6. 
       * @details The user should choose the configuration for @p ME_LP_PC6.
       */  
        VAR (uint32, MCU_VAR) LowPwrConfig6;
      /**
       * @brief   Configuration for @p ME_LP_PC7. 
       * @details The user should choose the configuration for @p ME_LP_PC7.
       */  
        VAR (uint32, MCU_VAR) LowPwrConfig7;
      /**
       * @brief   Configuration for @p ME_PCTL4. 
       * @details The user should choose the configuration for @p ME_PCTL4.
       */  
        VAR(uint8, MCU_VAR) SetDspi0;
      /**
       * @brief   Configuration for @p ME_PCTL5. 
       * @details The user should choose the configuration for @p ME_PCTL5.
       */  
        VAR(uint8, MCU_VAR) SetDspi1;
      /**
       * @brief   Configuration for @p ME_PCTL6. 
       * @details The user should choose the configuration for @p ME_PCTL6.
       */  
        VAR(uint8, MCU_VAR) SetDspi2;
      /**
       * @brief   Configuration for @p ME_PCTL7. 
       * @details The user should choose the configuration for @p ME_PCTL7.
       */  
        VAR(uint8, MCU_VAR) SetDspi3;
      /**
       * @brief   Configuration for @p ME_PCTL8. 
       * @details The user should choose the configuration for @p ME_PCTL8.
       */  
        VAR(uint8, MCU_VAR) SetDspi4;
      /**
       * @brief   Configuration for @p ME_PCTL9. 
       * @details The user should choose the configuration for @p ME_PCTL9.
       */  
        VAR(uint8, MCU_VAR) SetDspi5;
      /**
       * @brief   Configuration for @p ME_PCTL12. 
       * @details The user should choose the configuration for @p ME_PCTL12.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex8;
      /**
       * @brief   Configuration for @p ME_PCTL13. 
       * @details The user should choose the configuration for @p ME_PCTL13.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex9;
     /**
       * @brief   Configuration for @p ME_PCTL16. 
       * @details The user should choose the configuration for @p ME_PCTL16.
       */  
        VAR(uint8, MCU_VAR) SetFlexCan0;
      /**
       * @brief   Configuration for @p ME_PCTL17. 
       * @details The user should choose the configuration for @p ME_PCTL17.
       */  
        VAR(uint8, MCU_VAR) SetFlexCan1;
      /**
       * @brief   Configuration for @p ME_PCTL18. 
       * @details The user should choose the configuration for @p ME_PCTL18.
       */  
        VAR(uint8, MCU_VAR) SetFlexCan2;
      /**
       * @brief   Configuration for @p ME_PCTL19. 
       * @details The user should choose the configuration for @p ME_PCTL19.
       */  
        VAR(uint8, MCU_VAR) SetFlexCan3;
      /**
       * @brief   Configuration for @p ME_PCTL20. 
       * @details The user should choose the configuration for @p ME_PCTL20.
       */  
        VAR(uint8, MCU_VAR) SetFlexCan4;
      /**
       * @brief   Configuration for @p ME_PCTL21. 
       * @details The user should choose the configuration for @p ME_PCTL21.
       */  
        VAR(uint8, MCU_VAR) SetFlexCan5;
      /**
       * @brief   Configuration for @p ME_PCTL23. 
       * @details The user should choose the configuration for @p ME_PCTL23.
       */  
        VAR(uint8, MCU_VAR) SetDmaChMux;
      /**
       * @brief   Configuration for @p ME_PCTL32. 
       * @details The user should choose the configuration for @p ME_PCTL32.
       */  
        VAR(uint8, MCU_VAR) SetAdc0;
      /**
       * @brief   Configuration for @p ME_PCTL33. 
       * @details The user should choose the configuration for @p ME_PCTL33.
       */  
        VAR(uint8, MCU_VAR) SetAdc1;
      /**
       * @brief   Configuration for @p ME_PCTL44. 
       * @details The user should choose the configuration for @p ME_PCTL44.
       */  
        VAR(uint8, MCU_VAR) SetI2C0;
      /**
       * @brief   Configuration for @p ME_PCTL48. 
       * @details The user should choose the configuration for @p ME_PCTL48.
       */
        VAR(uint8, MCU_VAR)   SetLinFlex0;
      /**
       * @brief   Configuration for @p ME_PCTL49. 
       * @details The user should choose the configuration for @p ME_PCTL49.
       */
        VAR(uint8, MCU_VAR)   SetLinFlex1;
      /**
       * @brief   Configuration for @p ME_PCTL50. 
       * @details The user should choose the configuration for @p ME_PCTL50.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex2;
      /**
       * @brief   Configuration for @p ME_PCTL51. 
       * @details The user should choose the configuration for @p ME_PCTL51.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex3;
      /**
       * @brief   Configuration for @p ME_PCTL52. 
       * @details The user should choose the configuration for @p ME_PCTL52.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex4;
      /**
       * @brief   Configuration for @p ME_PCTL53. 
       * @details The user should choose the configuration for @p ME_PCTL53.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex5;
      /**
       * @brief   Configuration for @p ME_PCTL54. 
       * @details The user should choose the configuration for @p ME_PCTL54.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex6;
      /**
       * @brief   Configuration for @p ME_PCTL55. 
       * @details The user should choose the configuration for @p ME_PCTL55.
       */  
        VAR(uint8, MCU_VAR) SetLinFlex7;
      /**
       * @brief   Configuration for @p ME_PCTL57. 
       * @details The user should choose the configuration for @p ME_PCTL57.
       */  
        VAR(uint8, MCU_VAR) SetCtu;
      /**
       * @brief   Configuration for @p ME_PCTL60. 
       * @details The user should choose the configuration for @p ME_PCTL60.
       */  
        VAR(uint8, MCU_VAR) SetCanSc;
      /**
       * @brief   Configuration for @p ME_PCTL68. 
       * @details The user should choose the configuration for @p ME_PCTL68.
       */  
        VAR(uint8, MCU_VAR) SetSiuL; 
      /**
       * @brief   Configuration for @p ME_PCTL69. 
       * @details The user should choose the configuration for @p ME_PCTL69.
       */  
        VAR(uint8, MCU_VAR) SetWkpu; 
      /**
       * @brief   Configuration for @p ME_PCTL72. 
       * @details The user should choose the configuration for @p ME_PCTL72.
       */  
        VAR(uint8, MCU_VAR) SetEmios0;
      /**
       * @brief   Configuration for @p ME_PCTL73. 
       * @details The user should choose the configuration for @p ME_PCTL73.
       */  
        VAR(uint8, MCU_VAR) SetEmios1;
      /**
       * @brief   Configuration for @p ME_PCTL91. 
       * @details The user should choose the configuration for @p ME_PCTL91.
       */  
        VAR(uint8, MCU_VAR) SetRtcApi;
      /**
       * @brief   Configuration for @p ME_PCTL92. 
       * @details The user should choose the configuration for @p ME_PCTL92.
       */
        VAR(uint8, MCU_VAR)   SetPit;
      /**
       * @brief   Configuration for @p ME_PCTL104. 
       * @details The user should choose the configuration for @p ME_PCTL104.
       */  
        VAR(uint8, MCU_VAR) SetCmu0;
      /**
       * @brief   Device Mode enabled
       * @details Enable/Disable the device modes
       */
        VAR (uint32, MCU_VAR) ModeEnabled;
      /** 
       * @brief   Field for the RESET Options.
       * @details Enable/Disable functional reset sources. When a functional 
       *          reset source is disabled, the associated destructive event 
       *          will trigger either SAFE mode request or an interrupt request.
       * @note    It affects RGM_FERD register.
       *
       * @implements         DMCU04074
       */
        VAR (uint16, MCU_VAR) Func_ResetOpt; /* Indicate, between the functional Reset, who could generate a Reset Sequence */
      /** 
       * @brief   Field for the RESET Options.
       * @details For each functional reset, it defines which alternate request 
       *          is performed when the reset on the functional event has been
       *          disabled. Alternate request can be either a SAFE mode request 
       *          to ME or an interrupt request to the system.
       * @note    It affects RGM_FEAR register.
       *
       * @implements         DMCU04075   
       */
        VAR (uint16, MCU_VAR) Func_SafeIsrOpt;
       /** 
       * @brief   Field for the RESET Options.
       * @details For each functional reset source, it defines which reset 
       *          sequence is performed when the functional reset is triggered. 
       *          The functional reset sequence can either start from PHASE1 or 
       *          from PHASE3.
       * @note    This could be useful for fast reset sequence, for example to 
       *          skip fhash reset. It affects the RGM_FESS register.
       *
       * @implements         DMCU04076
       */  
        VAR (uint16, MCU_VAR) Func_Phase1or3Opt;
       /** 
       * @brief   Field for the RESET Options.
       * @details Enable the generation of an external reset when a functional 
       *          reset is triggered.
       * @ note   It affects RGM_FBRE register.
       *
       * @implements         DMCU04077
       */  
        VAR (uint16, MCU_VAR) Ext_PinReset;
      /** 
       * @brief   Field for the Power domain options.
       * @details Given a power domain and a chip mode, it defines if the 
       *          peripherals located in the power domain have to be turned off/on 
       *          when the chip mode occurs.       
       */    
       /** @brief Power Domain 
       */
       VAR (uint32, MCU_VAR) PwrDom2;
       /** @brief TimeOut for internal loop 
       */
        VAR (uint32, MCU_VAR) TimeOut;
      /** 
       * @brief   Enable mode transition interrupts.
       * @details It defines if an interrupt has to be generated when:
       *          - a chip mode has been configured incorrectly.
       *          - An invalid mode trasnition has been requested.
       *          - A @p SAFE mode transition is not due to a software request. 
       *          - A mode transition has been completed.
       *          .
       */  
        VAR (uint8, MCU_VAR) IsrMode;
      /** 
       * @brief   Configure the DMA multiplexer.
       * @details The DMA mux allows to route DMA sources to DMA channels.
       */ 
        VAR (Dmamux_ConfigType, MCU_VAR) DmamuxConfig;
      /** 
       * @brief   Configure the priority for each DMA channel.
       * @details The channel priority is rappresented by numeric value:
       *          - 0 is the lowest priority.
       *          - 1,2,..15 are the next higher priority.
       *          .
       */
        VAR (Dma_ConfigType, MCU_VAR) DmaConfig;
      /** 
       * @brief   Flash memory banks 0 and 2 configuration.
       */
        VAR (uint32, MCU_VAR) flashPFCR0;
      /** 
       * @brief   Flash memory bank 1 configuration.
       */    
        VAR (uint32, MCU_VAR) flashPFCR1;
      /** 
       * @brief   Flash memory access protection.
       * @details For a given master (0..7), it controls whether read and write 
       *          accesses to the flash may be performed by the master.
       */
        VAR (uint32, MCU_VAR) flashPFAPR;
} McuLLD_ConfigType;


/**
* @brief   The structure contains the MCU identifier information.
* @details The structure contains the MCU identifier information.
* 
* @requirements
* @implements     DMCU06066
*
* @api
*/
typedef struct
{
    VAR(uint16, MCU_VAR) partnum_device;           /**< @brief MCU Part Number */
    VAR(uint8, MCU_VAR) partnum_family;            /**< @brief MCU Part Number */
    VAR(uint8, MCU_VAR) pkg;                       /**< @brief Package Settings */
    VAR(uint8, MCU_VAR) major_mask;                /**< @brief Major Mask Revision */
    VAR(uint8, MCU_VAR) minor_mask;                /**< @brief Minor Mask Revision */
    VAR(uint8, MCU_VAR) flash_size1;               /**< @brief flash memory size */
    VAR(uint8, MCU_VAR) flash_size2;               /**< @brief flash memory size */
    VAR(uint8, MCU_VAR) manufacturer;              /**< @brief Manufacturer */
    VAR(Mcu_Dflash_PresentType, MCU_VAR) data_flash;   /**< @brief Data flash memory present */
    VAR(Mcu_Flexray_PresentType, MCU_VAR) flexray;     /**< @brief FlexRay present */
} Mcu_DeviceInfoType;

/**
* @brief   The structure contains the initialization data for the MCU driver.
* @details A pointer to such a structure is provided to the MCU initialization
*          routines for configuration.
* 
* @implements                DMCU04022
*
* @api
*/
typedef struct
{
      /**
       * @brief   Clock failure notification.     
       * @details Enable/disable clock failure interrupt generated by the MCU.
       */
        VAR (Mcu_ClockNotificationType, MCU_VAR) clkNotification;
      /**
       * @brief   Identifies a RAM section in the configuration structure.  
       * @details The range is dependent on the number of RAM sections provided
       *          in the configuration structure.
       */
        VAR (Mcu_RamSectionType, MCU_VAR) noRamSections;
      /**
       * @brief   Identifies a MCU mode in the configuration structure.   
       * @details The range is dependent on the the number of MCU modes provided
       *          in the configuration structure.
       */
        VAR (Mcu_ModeType, MCU_VAR) noModes;
      /**
       * @brief   Identifies a clock setting in the configuration structure. 
       * @details The range is dependent on the the number of clock settings
       *           provided in the configuration structure.
       */
        VAR (Mcu_ClockType, MCU_VAR) noClockSettings;
      /**
       * @brief   Identifies a Ram setting in the configuration structure. 
       */
        P2CONST (Mcu_RamConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_RamConfig;
      /**
       * @brief   Identifies a mode configuration in the configuration structure. 
       */
        P2CONST (Mcu_ModeConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_ModeConfig;
      /**
       * @brief   Identifies a system clock configuration.
       */
        P2CONST (Mcu_ClockConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_ClockConfig;
      /**
       * @brief   Mcu driver configuration.
       */
        P2CONST (McuLLD_ConfigType, MCU_VAR, MCU_APPL_CONST) McuLLD_Config;
      /** 
       * @brief MCU Driver DEM Error
       */
    #if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
        /* Mcu Driver DEM Error: MCU_E_CLOCK_FAILURE */
        CONST(Mcal_DemErrorType, MCU_CONST) Mcu_E_ClockFailureCfg;
        /* Mcu Driver DEM Error: MCU_E_LOCK_FAILURE */
        CONST(Mcal_DemErrorType, MCU_CONST) Mcu_E_LockFailureCfg;
        /* Mcu Driver DEM Error: MCU_E_QUARTZ_FAILURE */
        CONST(Mcal_DemErrorType, MCU_CONST) Mcu_E_QuartzFailureCfg;
        /* Mcu Driver DEM Error: MCU_E_TIMEOUT_TRANSITION */
        CONST(Mcal_DemErrorType, MCU_CONST) Mcu_E_TimeoutTransitionCfg;
    #endif    
    } Mcu_ConfigType;
#ifndef MCU_PRECOMPILE_SUPPORT
    MCU_CONF_PB
#else
/* @violates @ref Mcu_Cfg_h_REF_3 MISRA 2004 Rule 8.7 extern object used in only one file */
    MCU_CONF_PC
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
















#ifdef __cplusplus
}
#endif

#endif /* #ifndef MCU_CFG_H */
/** @} */
