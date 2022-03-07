/**
*   @file    Adc_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Pre-Compile configurations for ADC driver.
*   @details Pre-Compile configuration file for ADC driver.
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
* @section Adc_Cfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Cfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_Cfg_c_REF_3
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
/* @implements     DADC00008 */
#include "Adc.h"
#include "Reg_eSys_ADCDig.h"

#ifdef ADC_PRECOMPILE_SUPPORT



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_Cfg.c
* @implements     DADC04070
*/
#define ADC_CFG_C_VENDOR_ID                    (43)
/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_CFG_C_AR_RELEASE_MAJOR_VERSION     (4)
/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_CFG_C_AR_ERLEASE_MINOR_VERSION     (0)
/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_CFG_C_AR_RELEASE_REVISION_VERSION  (3)
#define ADC_CFG_C_SW_MAJOR_VERSION             (1)
#define ADC_CFG_C_SW_MINOR_VERSION             (0)
#define ADC_CFG_C_SW_PATCH_VERSION             (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* @implements     DADC06008 */
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_CFG_C_VENDOR_ID != ADC_VENDOR_ID)
    #error "Adc_Cfg.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_CFG_C_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_CFG_C_AR_ERLEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_CFG_C_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_Cfg.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_CFG_C_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION) || \
     (ADC_CFG_C_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION) || \
     (ADC_CFG_C_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_Cfg.c and Adc.h are different"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same vendor */
#if (ADC_CFG_C_VENDOR_ID != ADC_REG_VENDOR_ID)
    #error "Adc_Cfg.c and Reg_eSys_ADCDig.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same Autosar version */
#if ((ADC_CFG_C_AR_RELEASE_MAJOR_VERSION != ADC_REG_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_CFG_C_AR_ERLEASE_MINOR_VERSION != ADC_REG_AR_RELEASE_MINOR_VERSION) || \
     (ADC_CFG_C_AR_RELEASE_REVISION_VERSION != ADC_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_Cfg.c and Reg_eSys_ADCDig.h are different"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same Software version */
#if ((ADC_CFG_C_SW_MAJOR_VERSION != ADC_REG_SW_MAJOR_VERSION) || \
     (ADC_CFG_C_SW_MINOR_VERSION != ADC_REG_SW_MINOR_VERSION) || \
     (ADC_CFG_C_SW_PATCH_VERSION != ADC_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_Cfg.c and Reg_eSys_ADCDig.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"


/**
* @brief          ADC Notification functions.
* @details        ADC Nofification functions defined inside the Plugin.
*
* @implements     DADC04071
*/
/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
extern void AdcAllGrp0Nf(void); /**< @brief for Group - 32 */

/**
* @brief          Adc Watchdog notification functions.
* @details        Adc Watchdog notification functions defined inside the Plugin.
*
* @implements     DADC04072 
*/

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
* @brief          Total number of groups in Config0.
*
* @implements     DADC04073  
*/
#define ADC_GROUPS           (33)

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"

/**
* @brief          Adc Result Buffer RAM initializations.
* @details        Array for all ADC group result ram buffers.
*
* @implements     DADC04074
*/
STATIC P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) ADC_ResultsBufferPtr[] =
{
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR,
 NULL_PTR
};

/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"

/**
* @brief          Hardware trigger sources configured for group.
*
* @implements    DADC04075
*/

/**
* @brief          Group Assignments on ADC Hardware unit 0.
*
* @implements     DADC04076
*/
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group32_Assignment_PC_0[ADC_CFGSET1_GROUP_32_CHANNELS] =
{
 0U,
 1U,
 2U,
 3U,
 4U,
 5U,
 6U,
 7U,
 8U,
 9U,
 10U,
 11U,
 12U,
 13U,
 14U,
 15U,
 16U,
 17U,
 18U,
 19U,
 20U,
 21U,
 22U,
 23U,
 24U,
 25U,
 26U,
 27U,
 28U,
 29U,
 30U,
 31U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group0_Assignment_PC_0[ADC_CFGSET1_GROUP_0_CHANNELS] =
{
 0U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group1_Assignment_PC_0[ADC_CFGSET1_GROUP_1_CHANNELS] =
{
 1U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group2_Assignment_PC_0[ADC_CFGSET1_GROUP_2_CHANNELS] =
{
 2U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group3_Assignment_PC_0[ADC_CFGSET1_GROUP_3_CHANNELS] =
{
 3U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group4_Assignment_PC_0[ADC_CFGSET1_GROUP_4_CHANNELS] =
{
 4U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group5_Assignment_PC_0[ADC_CFGSET1_GROUP_5_CHANNELS] =
{
 5U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group6_Assignment_PC_0[ADC_CFGSET1_GROUP_6_CHANNELS] =
{
 6U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group7_Assignment_PC_0[ADC_CFGSET1_GROUP_7_CHANNELS] =
{
 7U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group8_Assignment_PC_0[ADC_CFGSET1_GROUP_8_CHANNELS] =
{
 8U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group9_Assignment_PC_0[ADC_CFGSET1_GROUP_9_CHANNELS] =
{
 9U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group10_Assignment_PC_0[ADC_CFGSET1_GROUP_10_CHANNELS] =
{
 10U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group11_Assignment_PC_0[ADC_CFGSET1_GROUP_11_CHANNELS] =
{
 11U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group12_Assignment_PC_0[ADC_CFGSET1_GROUP_12_CHANNELS] =
{
 12U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group13_Assignment_PC_0[ADC_CFGSET1_GROUP_13_CHANNELS] =
{
 13U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group14_Assignment_PC_0[ADC_CFGSET1_GROUP_14_CHANNELS] =
{
 14U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group15_Assignment_PC_0[ADC_CFGSET1_GROUP_15_CHANNELS] =
{
 15U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group16_Assignment_PC_0[ADC_CFGSET1_GROUP_16_CHANNELS] =
{
 16U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group17_Assignment_PC_0[ADC_CFGSET1_GROUP_17_CHANNELS] =
{
 17U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group18_Assignment_PC_0[ADC_CFGSET1_GROUP_18_CHANNELS] =
{
 18U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group19_Assignment_PC_0[ADC_CFGSET1_GROUP_19_CHANNELS] =
{
 19U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group20_Assignment_PC_0[ADC_CFGSET1_GROUP_20_CHANNELS] =
{
 20U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group21_Assignment_PC_0[ADC_CFGSET1_GROUP_21_CHANNELS] =
{
 21U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group22_Assignment_PC_0[ADC_CFGSET1_GROUP_22_CHANNELS] =
{
 22U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group23_Assignment_PC_0[ADC_CFGSET1_GROUP_23_CHANNELS] =
{
 23U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group24_Assignment_PC_0[ADC_CFGSET1_GROUP_24_CHANNELS] =
{
 24U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group25_Assignment_PC_0[ADC_CFGSET1_GROUP_25_CHANNELS] =
{
 25U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group26_Assignment_PC_0[ADC_CFGSET1_GROUP_26_CHANNELS] =
{
 26U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group27_Assignment_PC_0[ADC_CFGSET1_GROUP_27_CHANNELS] =
{
 27U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group28_Assignment_PC_0[ADC_CFGSET1_GROUP_28_CHANNELS] =
{
 28U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group29_Assignment_PC_0[ADC_CFGSET1_GROUP_29_CHANNELS] =
{
 29U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group30_Assignment_PC_0[ADC_CFGSET1_GROUP_30_CHANNELS] =
{
 30U
};
STATIC CONST(Adc_ChannelType, ADC_CONST) ADC_Group31_Assignment_PC_0[ADC_CFGSET1_GROUP_31_CHANNELS] =
{
 31U
};

/**
* @brief          Group Assignments on ADC Hardware unit 1.
*
* @implements     DADC04077
*/



/**
* @brief          Definition of ADC Hardware units.
*
* @implements     DADC04078
*/
STATIC CONST(Adc_LLD_HWUnitConfiguration, ADC_CONST) Adc_HWUnit_CfgPC[] =
{
  /**< @brief Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit id */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Main configuration for control register */
    (ADC_CLOCK_PRESCALER_DIV2 | ADC_AUTO_CLKOFF_DIS | ADC_OVERWRITE_EN | ADC_WRITE_RIGHT_ALIGNED),
    /**< @brief Power down exit delay when ADC runs on normal system frequency */
    (ADC_POWERDOWN_EXIT_DELAY_VALUE(15)),
    /**< @brief Mux delay value */
    /**< @brief ADC_PRESAMP_VOLTAGE_V0 -> Vss=0V */
    (uint8)0x0,
    /**< @brief do not bypass the sampling phase */
    (uint8)0x0,
    (Adc_ConversionTimeType)0x0,
    (Adc_ConversionTimeType)0x0,
    /**< @brief Bit resolution */
    (Adc_ResolutionType)ADC_BITS_RESOLUTION_10
  }
};


/**
* @brief          Definition of channels on ADC Hardware unit 0.
* @details        Array of conversion command messages.
*
* @implements     DADC04079
*/
STATIC CONST(Adc_LLD_ChannelConfiguration, ADC_CONST) Adc_Channels_CfgPC_0[] =
{
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_0 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(0)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_1 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(1)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_2 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(2)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_3 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(3)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_4 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(4)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_5 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(5)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_6 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(6)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_7 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(7)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_8 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(8)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_9 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(9)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_10 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(10)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_11 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(11)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_12 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(12)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_13 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(13)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_14 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(14)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANP_15 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(15)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_0 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(32)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_1 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(33)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_2 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(34)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_3 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(35)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_4 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(36)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_5 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(37)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_6 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(38)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_7 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(39)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_8 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(40)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_9 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(41)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_10 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(42)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_11 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(43)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_12 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(44)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_13 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(45)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_14 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(46)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  },
  /**< @brief Hardware Unit ADC_UNIT_0  --  ANS_15 */
  {
    /**< @brief Adc physical channel */
      (Adc_ChannelType)(ADC_ID_CHANNEL(47)), 
        /**< @brief Threshold register configured */
    ADC_THRESHOLD_REG_0,
    /**< @brief Threshold register value */
    ADC_UNUSED_THRESHOLD,
    /**< @brief Threshold control register value */
    ADC_TH_DISABLE,
    /**< @brief No WDOG notification */
    NULL_PTR,
    /**< @brief presampling disabled */
    (uint8)0x0
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    ,
    /**< @brief limit check disabled */
    (boolean)FALSE,
    /**< @brief range for limit check */
    (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
    /**< @brief high limit value */
    (uint32)0,
    /**< @brief low limit value */
    (uint32)0
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
  }
};


/**
* @brief          Definition of channels's pointer structure.
*
* @implements     DADC04081
*/
STATIC P2CONST(Adc_LLD_ChannelConfiguration, ADC_VAR, ADC_APPL_CONST) Adc_Channels_CfgPC[] =
{
  Adc_Channels_CfgPC_0,
  NULL_PTR
};

/**
* @brief          Definition of all ADC groups.
*
* @implements     DADC04083
*/
STATIC CONST(Adc_LLD_GroupConfiguration, ADC_CONST) Adc_Groups_CfgPC[ADC_GROUPS] =
{


  /**< @brief Group0 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x1,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group0_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_0_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_ONE_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_THREE_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(0),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(0)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group1 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x2,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group1_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_1_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(1),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(1)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group2 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x4,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group2_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_2_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(2),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(2)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group3 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x8,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group3_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_3_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(3),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(3)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group4 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x10,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group4_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_4_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(4),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(4)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group5 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x20,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group5_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_5_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(5),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(5)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group6 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x40,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group6_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_6_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(6),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(6)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group7 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x80,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group7_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_7_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(7),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(7)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group8 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x100,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group8_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_8_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(8),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(8)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group9 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x200,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group9_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_9_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(9),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(9)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group10 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x400,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group10_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_10_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(10),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(10)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group11 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x800,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group11_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_11_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(11),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(11)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group12 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x1000,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group12_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_12_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(12),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(12)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group13 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x2000,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group13_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_13_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(13),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(13)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group14 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x4000,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group14_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_14_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(14),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(14)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group15 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x8000,
    /**< @brief Extended configured channels */
    (uint32)0x0,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group15_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_15_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(15),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(15)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group16 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x1,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group16_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_16_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(32),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(32)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group17 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x2,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group17_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_17_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(33),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(33)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group18 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x4,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group18_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_18_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(34),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(34)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group19 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x8,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group19_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_19_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(35),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(35)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group20 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x10,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group20_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_20_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(36),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(36)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group21 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x20,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group21_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_21_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(37),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(37)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group22 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x40,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group22_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_22_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(38),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(38)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group23 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x80,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group23_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_23_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(39),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(39)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group24 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x100,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group24_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_24_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(40),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(40)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group25 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x200,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group25_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_25_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(41),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(41)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group26 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x400,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group26_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_26_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(42),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(42)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group27 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x800,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group27_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_27_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(43),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(43)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group28 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x1000,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group28_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_28_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(44),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(44)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group29 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x2000,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group29_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_29_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(45),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(45)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group30 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x4000,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group30_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_30_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(46),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(46)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group31 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        NULL_PTR,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0x0,
    /**< @brief Extended configured channels */
    (uint32)0x8000,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group31_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_31_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(47),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(47)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_ON
  },


  /**< @brief Group32 -- Hardware Unit ADC_UNIT_0 */
  {
    /**< @brief Hardware unit configured */
    (Adc_HwUnitType)ADC_UNIT_0,
    /**< @brief Access mode */
    ADC_ACCESS_MODE_SINGLE,
    /**< @brief Conversion mode */
    ADC_CONV_MODE_ONESHOT,
    /**< @brief Conversion type */
    ADC_CONV_TYPE_NORMAL,
    #if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /**< @brief  Priority configured */
    ADC_GROUP_PRIORITY(0),
    #endif
    /**< @brief Replacement mode */
    ADC_GROUP_REPL_ABORT_RESTART,
    /**< @brief Trigger source configured */
    ADC_TRIGG_SRC_SW,
    #if (STD_ON==ADC_HW_TRIGGER_API)
    #if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
        /**< @brief This a Regular Group */
    (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
        #endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
    /**< @brief Hardware trigger signal */
    ADC_HW_TRIG_BOTH_EDGES,
    /**< @brief Number of hardware trigger sources */
    0U,
    /**< @brief Hardware resource for the group */
    0U,
    #endif /* (STD_ON==ADC_HW_TRIGGER_API) */
    #if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
    /**< @brief Notification function */
        &AdcAllGrp0Nf,
        #endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
    /**< @brief Precision configured channels */
    (uint32)0xffff,
    /**< @brief Extended configured channels */
    (uint32)0xffff,
    /**< @brief External configured channels */
    (uint32)0x0,
  
    /**< @brief Presampling for Precision channels */
    (uint32)0x0U,
    /**< @brief Presampling for Extended channels */
    (uint32)0x0U,
    /**< @brief Presampling for External channels */
    (uint32)0x0U,
    /**< @brief Wer0 for precision channels */
    (uint32)0x0U,
    /**< @brief Wer1 for extended(medi.accuracy channels) */
    (uint32)0x0U,
    /**< @brief Wer2 for external channels */
    (uint32)0x0U,
        /**< @brief ADC Group Result Buffers RAM array */
    ADC_ResultsBufferPtr,
    /**< @brief Group Streaming Buffer Mode */
    ADC_STREAM_BUFFER_LINEAR,
    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
    (Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX,
    #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    /**< @brief Number of streaming samples */
    ADC_STREAMING_NUM_SAMPLES(1),
    /**< @brief Channels assigned to the group */
    ADC_Group32_Assignment_PC_0,
    /**< @brief Number of channels in the group */
    (Adc_ChannelType)ADC_CFGSET1_GROUP_32_CHANNELS,
    /**< @brief Conversion time */
    (ADC_INPLATCH_VALUE(ADC_HALF_CLOCK_CYCLE)|ADC_INPCMP_VALUE(ADC_TWO_LATCH_CYCLE)|ADC_INPSAMP_VALUE(3)),
    /**< @brief Last Channel configured */
    (uint32)(15),
    /**< @brief First Channel Configured */
    (ADC_ID_CHANNEL(0)<<(uint32)2),
    /**< @brief Enables or Disables the ADC and DMA interrupts */
    (uint8)STD_OFF
  }
};

/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"


#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/**
* @brief         Values for production code Event Ids.
* @details       ADC production code Event Ids.
*
* @implements     DADC06021
*/
CONST(Mcal_DemErrorType,ADC_CONST)Adc_E_TimeoutCfg = { (uint32)STD_ON, (uint32)1U}; /* ADC_E_TIMEOUT parameters*/

#endif /* ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */

/**
* @brief          ADC driver Configuration structure.
*
* @implements    DADC04084
*/
CONST(Adc_ConfigType, ADC_CONST) Adc_ConfigPC =
{
    /**< @brief pointer to Hw unit configurations */
    Adc_HWUnit_CfgPC,
    /**< @brief pointer to group configurations */
    Adc_Groups_CfgPC,
    /**< @brief pointer to channel configurations */
    Adc_Channels_CfgPC,
    /**< @brief total number of groups */
    (Adc_GroupType)ADC_GROUPS,

    /**< @brief Miscellaneous configuration parameters. - Adc_LLD_MultiConfig */
    {
      /**< @brief Interrupt driven Mode */
    ADC_INTERRUPT,
  
    /**< @brief ADC is CTUV2 driven or not */
    (uint8)STD_OFF,
    /**< @brief number of the maximum groups in the current configuration */
    33U,
    /**< @brief number of the maximum hardware units in the current configuration */
    1U,
    /**< @brief depth of the queue */
    1U,
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    {
      /**< @brief number of groups of the hw unit 0 */
      (uint8)33,
      /**< @brief number of groups of the hw unit 1 */
      (uint8)0

    },
     {
      /**< @brief number of channels of the hw unit 0 */
      (uint8)32,
      (uint8)0  /* number of channels of the hw unit 1 */
    },
    {            /**< @brief the DMA channel number for both ADC Hardware units */
      (uint8)0,
            (uint8)0
                },
    {
      /**< @brief ADC_UNIT_0 - ON/OFF */
      (uint8)STD_ON,
              /**< @brief ADC_UNIT_1 - ON/OFF */
      (uint8)STD_OFF
            },
    {
           /**< @brief number of MHT groups of the ADC Hardware unit 0 */
      (uint8)0,
            /**< @brief number of MHT groups of the ADC Hardware unit 1 */
      (uint8)0  /* number of MHT groups of the hw unit 1 */
          }
    }
};

/* @violates @ref Adc_Cfg_c_REF_3 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/* @violates @ref Adc_Cfg_c_REF_2 Repeated include file */
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#endif  /* ADC_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

