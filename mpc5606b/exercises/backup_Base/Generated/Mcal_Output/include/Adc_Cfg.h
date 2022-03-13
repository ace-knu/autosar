/**
*   @file    Adc_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Module configuration interface for Adc driver.
*   @details Contains the module configuration interface for Adc driver.
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

#ifndef ADC_CFG_H
#define ADC_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Cfg_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro. This violation is due to 
* function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Adc_Cfg_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. 
*
* @section Adc_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
*
* @section Adc_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 8.7, the scope of objects shall be restricted to function when possible
*
* @section Adc_Cfg_h_REF_5
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 characters signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
*/

/** 
* @brief The following definitions SHOULD be before the inclusion of the ADCDig_LLD_CfgEx.h header
*        file, cause in this file some conditional compilation flags are defined, and in the
*        ADCDig_LLD_CfgEx.h file some structure members are guarded by these defines.
*        According to this, these definitions should be predefined before the inclusion of the
*        mentioned header file, in order to correctly define the ADC driver internal structures.
*        Due to the fact that these structures are Low Level Driver related, they must stay in the
*        ADCDig_LLD_CfgEx.h file.
*/


/**
* @brief          MHT functionality not activated.
*/
#define ADC_MULTIPLE_HARDWARE_TRIGGERS      (STD_OFF)

/** 
* @brief           Add/Remove One time setting of Conversion time regsisters from Init() function.
* @implements      DADC04023
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_SET_ONCE_REGISTERS_SUPPORTED    (STD_OFF)

/** 
* @brief           Adds/removes ((STD_ON)/(STD_OFF)) the services Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() from the code.
* @implements      DADC04024
*/
#define ADC_HW_TRIGGER_API                  (STD_OFF)

/** 
* @brief           Set mode api enabled/disabled ((STD_ON)/(STD_OFF)).
* @implements      DADC04025
*/
#define ADC_SET_MODE_API                    (STD_ON)

/** 
* @brief           Add/Remove non autosar dual clock mode for prescaler settings.
* @implements      DADC04050
*/
#define ADC_DUAL_CLOCK_MODE                 (STD_OFF)

/** 
* @brief           Enables or disables limit checking feature in the ADC driver.
* @implements      DADC04026
*/
#define ADC_ENABLE_LIMIT_CHECK              (STD_OFF)

/** 
* @brief           Group notification mechanism is/isn't ((STD_ON)/(STD_OFF)) available at runtime.
* @implements      DADC04027
*/
#define ADC_GRP_NOTIF_CAPABILITY            (STD_ON)

/**
* @brief  Enable/Disable the DMA to transfer all channels between the start channel and end channel
*         directly to the user configured buffer.
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_DIRECT_DMA_RES_BUFFER_COPY        (STD_OFF)

/** 
* @brief           Type of prioritization mechanism ADC_PRIORITY_HW, ADC_PRIORITY_HW_SW and ADC_PRIORITY_NONE.
* @implements      DADC04028 
*/
#define ADC_PRIORITY_HW                     (0U)
#define ADC_PRIORITY_HW_SW                  (1U)
#define ADC_PRIORITY_NONE                   (2U)

/** 
* @brief           Priority implementation.
* @implements      DADC04029  
*/
#define ADC_PRIORITY_IMPLEMENTATION         (ADC_PRIORITY_NONE)

/** 
* @brief           Type of alignment mechanism ADC_ALIGN_RIGHT, ADC_ALIGN_LEFT.
* @implements      DADC04030
*/
#define ADC_ALIGN_RIGHT                     (0U)
#define ADC_ALIGN_LEFT                      (1U)

/** 
* @brief           Result Alignment.
* @implements      DADC04031 
*/
#define ADC_RESULT_ALIGNMENT                (ADC_ALIGN_RIGHT)

/** 
* @brief           Adc transfer type.
* @implements      DADC04032
*/
#define ADC_DMA                             (0U)
#define ADC_INTERRUPT                       (1U)

/** 
* @brief         This is a timeout value which is used to wait till
*                  - the conversion is not aborted.
*                  - ADC hardware is not entered in power down state.
*                  - ADC hardware is not entered in idle state.
* @implements      DADC04033
*/
#define ADC_TIMEOUT_COUNTER                 (0xffffU)

/**
 * @brief   Enable/Disable the DSDR (Mux delay) write into Adc_Init() and ADC_SetClockMode().
 *          It will be used as a compiler switch to remove code for DSDR update from
 *          Adc_Init and Adc_SetClockFrequency functions.
 */
#define ADC_MUX_DELAY_SUPPORT    (STD_OFF)

/**
 * @brief   Enable/Disable the DSDR (Mux delay) write into Adc_StartGroupConversion().
 *          It will be used as a compiler switch to remove code for DSDR update from
 *          Adc_StartGroupConversion function.
 */
#define ADC_MUX_DELAY_SUPPORT_PER_GROUP  (STD_OFF)



/** 
* @brief           Max number of hw units - are 2 on Bolero 1.5M.
* @implements      DADC04036.
*/
#define ADC_MAX_HW_UNITS (2U)

/** 
* @brief           Number of maximum channels of platform.
*/
#define ADC_MAXIMUM_HW_CHANNELS (92U)


/** 
* @brief           Add/Remove non autosar Adc_EnableChannel() and Adc_DisableChannel() api.
* @implements      DADC06016
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API      (STD_OFF)

/** 
* @brief           Get injected conversion status api enabled/disabled (STD_ON/STD_OFF).
* @implements      DADC06017
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_GET_INJECTED_CONVERSION_STATUS_API    (STD_OFF)

/**
* @brief           Enable/Disable Errata Workaround for CTU interrupted Normal groups.
* @implements
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ENABLE_ERRATA_INTERRUPTED_NORMAL_GROUP      (STD_ON)

/**
* @brief           Enable/Disable Errata Workaround for ABORTCHAIN before conversion start.
* @implements
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ENABLE_ERRATA_OPTIMIZED_SW_ABORT      (STD_ON)

/** 
* @brief          Add/Remove One time setting of Presampling regsisters from Init() function.
* @implements     DADC04045
*/
#define ADC_SET_ADC_PRESAMPLE_ONCE          (STD_OFF)

/** 
* @brief          Add/Remove One time setting of Conversion time regsisters from Init() function.
* @implements     DADC04046
*/
#define ADC_SET_ADC_CONV_TIME_ONCE          (STD_OFF)

/**
 * @brief         Add/Remove One time setting of Watchdog Enable regsisters from Init() function.
 */
#define ADC_SET_ADC_WDG_ENABLE_ONCE         (STD_OFF)

/**
* @brief   Switches the Production Error Detection and Notification OFF
* @implements
*/

/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_DISABLE_DEM_REPORT_ERROR_STATUS   (STD_ON)  /* Enable Production Error Detection */

/**
 * @brief           Add/Remove non autosar Adc_ConfigureThreshold() api.
 * @implements
 */

/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API      (STD_OFF)

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif
#include "Adc_ADCDig_LLD_CfgEx.h"
/* @violates @ref Adc_Cfg_h_REF_2 Repeated include file. */
#include "Mcal.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_Cfg.h
* @implements     DADC04038
*/
#define ADC_CFG_H_VENDOR_ID                       (43)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFG_H_AR_RELEASE_MAJOR_VERSION        (4)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFG_H_AR_RELEASE_MINOR_VERSION        (0)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFG_H_AR_RELEASE_REVISION_VERSION     (3)
#define ADC_CFG_H_SW_MAJOR_VERSION                (1)
#define ADC_CFG_H_SW_MINOR_VERSION                (0)
#define ADC_CFG_H_SW_PATCH_VERSION                (1)


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
 /* Check if source file and Dem header file are of the same version */
 #if ((ADC_CFG_H_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_CFG_H_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Adc_Cfg.h and Dem.h are different"
    #endif
 #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/** 
* @brief          Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
* @implements     DADC04040
*/
#define ADC_DEV_ERROR_DETECT                (STD_ON)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_GetVersionInfo() from the code.
* @implements     DADC04041
*/
#define ADC_VERSION_INFO_API                (STD_OFF)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_DeInit() from the code.
* @implements     DADC04042
*/
#define ADC_DEINIT_API                      (STD_OFF)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the services Adc_StartGroupConversion()and Adc_StopGroupConversion() from the code.
* @implements     DADC04043
*/
#define ADC_ENABLE_START_STOP_GROUP_API     (STD_ON)

/** 
* @brief          Add/Remove the services Adc_ReadGroup() from the code.
* @implements     DADC04044
*/
#define ADC_READ_GROUP_API                  (STD_ON)

/** 
* @brief          This switch is used to enable the hardware trigger non autosar API.
* @implements     DADC04047 
*/
#define ADC_ENABLE_CTUTRIG_NONAUTO_API       (STD_OFF)

/** 
* @brief           This switch is used to enable the queue.
* @implements      DADC04048
*/
#define ADC_ENABLE_QUEUING                  (STD_OFF)

/** 
* @brief           This switch is used to enable the non autosar ADC performance optimization feature.
* @implements      DADC04049
*/
#define ADC_BYPASS_CONSISTENCY_LOOP         (STD_OFF)



/** 
* @brief           Define the HW queue size depending on the MHT groups existence.
* @details         If there are MHT groups in the configuration the HW queue size will be the total number of MHT
*                  groups defined. If there are no MHT groups in the current configuration, then only one hardware
*                  group can be added to the HW queue, thus the queue size will be only 1.
* @implements      DADC04052
*/
#define ADC_HW_QUEUE                        (1U)

/** 
* @brief           Maximum number of channels across all hardware units.
* @implements      DADC04053
*/
#define ADC_MAX_CHANNEL_PER_HW_UNIT         (32)

/** 
* @brief           ADC Hardware units definitions.
* @implements      DADC04054
*/
#define ADC_UNIT_0                          (0)
/** 
* @brief           ADC Hardware units definitions.
* @implements      DADC04055
*/
#define ADC_UNIT_1                          (1)

/** 
* @brief           Symbolic names of ADC Hardware units.
* @implements      DADC04056
*/
#define  AdcHwUnit_0                      (ADC_UNIT_0)

/** 
* @brief           ADC Hardware unit macro for register access.
* @implements      DADC04057
* @note lint -save -e961
*
* @violates @ref Adc_Cfg_h_REF_1 Use of function like macro.
*/
#define ADC_HW_UNITS(unit)                  (Adc_Cfg_Ptr->Misc.ADC_HW_UNIT[(unit)])

/** 
* @brief           Enable/disable CTUv2 from the ADC code.
* @implements      DADC04058
*/
#define ADC_ENABLE_CTUV2                    (STD_OFF) /* CTUv2 en./dis. */

/** 
* @brief           max queue depth configured across all configset.
* @implements      DADC04059
*/
#define ADC_QUEUE_MAX_DEPTH_MAX             (1U + 0U)

/** 
* @brief           max number of groups configured across all configset.
* @implements      DADC04061 
*/
#define ADC_MAX_GROUPS                      (33U)

/**
 * @brief   Max number of groups configured per HW unit.
 */
#define ADC_MAX_GROUPS_PER_HW_UNIT          33U

/** 
* @brief           ADC Software injected configuration enabled or not.
* @implements      DADC04062 
*/
#define ADC_SW_INJ_CONFIGURED               (STD_OFF)

/** 
* @brief           AUTOSAR Symbolic names of channels on all HW units.
* @implements      DADC04063
*/
#define AdcChannel_0                       (0)
#define AdcChannel_1                       (1)
#define AdcChannel_2                       (2)
#define AdcChannel_3                       (3)
#define AdcChannel_4                       (4)
#define AdcChannel_5                       (5)
#define AdcChannel_6                       (6)
#define AdcChannel_7                       (7)
#define AdcChannel_8                       (8)
#define AdcChannel_9                       (9)
#define AdcChannel_10                       (10)
#define AdcChannel_11                       (11)
#define AdcChannel_12                       (12)
#define AdcChannel_13                       (13)
#define AdcChannel_14                       (14)
#define AdcChannel_15                       (15)
#define AdcChannel_16                       (16)
#define AdcChannel_17                       (17)
#define AdcChannel_18                       (18)
#define AdcChannel_19                       (19)
#define AdcChannel_20                       (20)
#define AdcChannel_21                       (21)
#define AdcChannel_22                       (22)
#define AdcChannel_23                       (23)
#define AdcChannel_24                       (24)
#define AdcChannel_25                       (25)
#define AdcChannel_26                       (26)
#define AdcChannel_27                       (27)
#define AdcChannel_28                       (28)
#define AdcChannel_29                       (29)
#define AdcChannel_30                       (30)
#define AdcChannel_31                       (31)



/** 
* @brief           Symbolic names of groups.
* @implements      DADC04065
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcAllGroup0                       (32)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_0                       (0)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_1                       (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_2                       (2)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_3                       (3)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_4                       (4)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_5                       (5)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_6                       (6)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_7                       (7)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_8                       (8)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_9                       (9)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_10                       (10)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_11                       (11)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_12                       (12)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_13                       (13)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_14                       (14)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_15                       (15)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_16                       (16)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_17                       (17)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_18                       (18)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_19                       (19)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_20                       (20)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_21                       (21)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_22                       (22)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_23                       (23)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_24                       (24)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_25                       (25)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_26                       (26)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_27                       (27)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_28                       (28)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_29                       (29)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_30                       (30)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Adc_Cfg_h_REF_5 Identifier clash */
#define AdcConf_AdcGroup_AdcGroup_31                       (31)

/** 
* @brief           Number of channels in respective groups.
* @implements      DADC04066
*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_32_CHANNELS      (32)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_0_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_1_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_2_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_3_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_4_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_5_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_6_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_7_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_8_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_9_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_10_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_11_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_12_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_13_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_14_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_15_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_16_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_17_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_18_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_19_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_20_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_21_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_22_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_23_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_24_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_25_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_26_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_27_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_28_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_29_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_30_CHANNELS      (1)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_CFGSET1_GROUP_31_CHANNELS      (1)


/** 
* @brief           Adc non autosar Enable/Disable invalid group index.
* @implements      DADC06019
*/
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX   ((Adc_GroupType)0xFF)
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Structure for Configuration data.
* @details        Data structure containing the set of configuration parameters required 
*                 for initializing the ADC Driver and ADC HW Unit(s).
* @api
*
* @implements    DADC04067 
*/
typedef struct
{
  P2CONST(Adc_LLD_HWUnitConfiguration, ADC_VAR, ADC_APPL_CONST) ADC; /**< @brief Hw unit configurations */
  P2CONST(Adc_LLD_GroupConfiguration, ADC_VAR, ADC_APPL_CONST) Groups; /**< @brief Group configurations */
  P2P2CONST(Adc_LLD_ChannelConfiguration, ADC_VAR, ADC_APPL_CONST) Channels; /**< @brief Channel configurations */
  VAR(Adc_GroupType, ADC_VAR) GroupCount; /**< @brief Total number of groups */
  CONST(Adc_LLD_MultiConfig, ADC_CONST) Misc; /**< @brief Miscellaneous configuration parameters */
} Adc_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_Cfg_h_REF_2 Repeated include file. */
#include "MemMap.h"

#ifdef ADC_PRECOMPILE_SUPPORT
/**
* @brief         Declaration Configuration sets.
* @implements    DADC04068 
*/
/* @violates @ref Adc_Cfg_h_REF_4 Scope of object */
extern CONST(Adc_ConfigType, ADC_APPL_CONST) Adc_ConfigPC;
#else
/**
* @brief         Declaration Configuration sets.
* @implements    DADC04069 
*/
extern CONST(Adc_ConfigType, ADC_APPL_CONST) AdcConfigSet_0;
#endif /* ADC_PRECOMPILE_SUPPORT */

#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/**
* @brief         Declaration of Dem events.
*/
extern CONST(Mcal_DemErrorType, ADC_CONST) Adc_E_TimeoutCfg;
#endif

/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_Cfg_h_REF_2 Repeated include file. */
#include "MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_START_SEC_CODE
/* @violates @ref Adc_Cfg_h_REF_2 Repeated include file. */
#include "MemMap.h"

/* @violates @ref Adc_Cfg_h_REF_3 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_Cfg_h_REF_2 Repeated include file. */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_CFG_H */

/** @} */
