/**
*   @file    Adc_ADCDig_LLD_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - low level driver configuration header file.
*   @details ADCDig Configuration extern low level driver API.
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

#ifndef ADC_ADCDIG_LLD_CFGEX_H
#define ADC_ADCDIG_LLD_CFGEX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_ADCDig_LLD_CfgEx_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_ADCDig_LLD_CfgEx_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Adc_ADCDig_LLD_CfgEx_h_REF_3
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
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_1 Repeated include file */
#include "Mcal.h"
#include "Reg_eSys_ADCDig.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_ADCDig_LLD_CfgEx.h
*/
#define ADC_LLD_CFGEX_VENDOR_ID                        (43)
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_3 Identifier exceeds 31 characters */
#define ADC_LLD_CFGEX_AR_RELEASE_MAJOR_VERSION         (4)
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_3 Identifier exceeds 31 characters */
#define ADC_LLD_CFGEX_AR_RELEASE_MINOR_VERSION         (0)
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_3 Identifier exceeds 31 characters */
#define ADC_LLD_CFGEX_AR_RELEASE_REVISION_VERSION      (3)
#define ADC_LLD_CFGEX_SW_MAJOR_VERSION                 (1)
#define ADC_LLD_CFGEX_SW_MINOR_VERSION                 (0)
#define ADC_LLD_CFGEX_SW_PATCH_VERSION                 (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Reg_eSys_ADCDig header file are of the same vendor */
#if (ADC_LLD_CFGEX_VENDOR_ID != ADC_REG_VENDOR_ID)
    #error "Adc_ADCDig_LLD_CfgEx.h and Reg_eSys_ADCDig.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same Autosar version */
#if ((ADC_LLD_CFGEX_AR_RELEASE_MAJOR_VERSION != ADC_REG_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_LLD_CFGEX_AR_RELEASE_MINOR_VERSION != ADC_REG_AR_RELEASE_MINOR_VERSION) || \
     (ADC_LLD_CFGEX_AR_RELEASE_REVISION_VERSION != ADC_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_ADCDig_LLD_CfgEx.h and Reg_eSys_ADCDig.h are different"
#endif

/* Check if source file and ADC Reg_eSys_ADCDig header file are of the same software version */
#if ((ADC_LLD_CFGEX_SW_MAJOR_VERSION != ADC_REG_SW_MAJOR_VERSION) || \
     (ADC_LLD_CFGEX_SW_MINOR_VERSION != ADC_REG_SW_MINOR_VERSION) || \
     (ADC_LLD_CFGEX_SW_PATCH_VERSION != ADC_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_ADCDig_LLD_CfgEx.h and Reg_eSys_ADCDig.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
/**
* @brief          macros to simplify access to structures.
*/
#define ADC_CTU_START_VALUE(num) ((Adc_CtuStartValueType)(num))
/**
* @brief          External trigger start from 67.
*/
#define ADC_EXT_TRIG_PE10                   (67U)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
   Komodo 2M or Bolero 3M (Bolero 256k-128k) or Leopard2M or Panther */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01)
#ifndef IPV_ADCDIG_31201_BOLERO256K
  /**
  * @brief          Maximum CTU event configuration register across all platform.
  */
  #define ADC_MAX_CTU_EVTCFGREGS             (63U)
#else
  /**
  * @brief          Maximum CTU event configuration register across all platform.
  */
  #define ADC_MAX_CTU_EVTCFGREGS             (27U)
#endif /* IPV_ADCDIG_31201_BOLERO256K */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */

/* Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
  /**
  * @brief          Maximum BCTU event configuration register across all platform.
  */
  #define ADC_MAX_CTU_EVTCFGREGS             (31U)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */

/* Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  /**
  * @brief          Maximum BCTU event configuration register across all platform.
  */
  #define ADC_MAX_CTU_EVTCFGREGS             (95U)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

/**
* @brief          macros to simplify access to structures.
* @details        Streaming number of samples
*/
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_2 Function-like macro defined */
#define ADC_STREAMING_NUM_SAMPLES(num)      ((Adc_StreamNumSampleType)(num))

/**
* @brief          maximum hardware across all derviative, used for the array size.
*/
/* !Fado and !Panther and !Rainier */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
 /* if !Komodo */
 #ifndef IPV_ADCDIG_31301_KOMODO2M
   #ifdef IPV_ADCDIG_31201_BOLERO256K  /* Bolero 256k-128k */
     #define ADC_HW_MAX      (1U)
   #else
     #define ADC_HW_MAX      (2U)
   #endif  /* IPV_ADCDIG_31201_BOLERO256K */
 #else /* Komodo */
  #define ADC_HW_MAX                        (4U)
 #endif /* #ifndef IPV_ADCDIG_31301_KOMODO2M */
#else /* Fado or Panther or Rainier */
 /* if Panther or Rainier */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
  #define ADC_HW_MAX                        (4U)
 #else /* Fado */
   #define ADC_HW_MAX                       (1U)
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_05_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) &&
          (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) */

#if (ADC_MAX_HW_UNITS == 1U)
  /**
  * @brief          Configured hardware unit of the group.
  */
  #define ADC_GroupUnit(group)              (0U)
#else
  /**
  * @brief          Configured hardware unit of the group.
  */  
  /* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_2 Function-like macro defined */
  #define ADC_GroupUnit(group)              (Adc_Cfg_Ptr->Groups[(group)].HWUnit)
#endif /* (ADC_MAX_HW_UNITS == 1U) */

/**
* @brief          The group at position p in queue of given hardware unit.
*/
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_2 Function-like macro defined */
#define ADC_GroupInQueue(unit,p)            (ADC_UnitStatus[(unit)].Queue[(p)])

/**
* @brief          Number of hardware groups in queue for hardware unit.
*/
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_2 Function-like macro defined */
#define ADC_GroupsInHwQueue(unit)           (ADC_UnitStatus[(unit)].HwQueueIndex)

/**
* @brief          Adc group priority.
*/
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_2 Function-like macro defined */
#define ADC_GROUP_PRIORITY(Priority)        ((Adc_GroupPriorityType)(Priority))

/**
* @brief          Adc hardware trigger source configured for the group.
*/
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_2 Function-like macro defined */
#define ADC_GroupTriggerSource(group,pos)   (Adc_Cfg_Ptr->Groups[(group)].HwResource[(pos)])


#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
  /**
  * @brief          Adc priority assigned to the group.
  */
  /* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_2 Function-like macro defined */
  #define ADC_GroupPriority(group)          (Adc_Cfg_Ptr->Groups[(group)].Priority)
#endif /* ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Shift mask to align conversion results.
*/
#define ADC_SHIFT_MASK                      (0x0000FFFFUL)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
* @brief          Maximum boundary for the Adc_QueueIndexType.
*/
#define Adc_QueueIndexType_MAXIMUM          (255U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          ADC group already converted type.
* @details        Used to differentiate if group is already converted or not.
*
* @implements
*
*/
typedef enum
{
  ADC_NOT_YET_CONVERTED = 0U, /**< @brief Group not yet converted */
  ADC_ALREADY_CONVERTED       /**< @brief Group is already converted */
} Adc_GroupConversionStateType;

/**
* @brief          Adc group access Mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements
*
*/
typedef enum
{
  ADC_ACCESS_MODE_SINGLE = 0U, /**< @brief Single access mode */
  ADC_ACCESS_MODE_STREAMING    /**< @brief Streaming access mode */
} Adc_GroupAccessModeType;

/* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
   Komodo 2M or Bolero 3M (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
/**
* @brief          Adc group conversion.
* @details        Used for value received by Tressos interface configuration.
*
* @implements
*
*/
typedef enum
{
  ADC_CONV_TYPE_NORMAL = 0U, /**< @brief Normal conversion mode */
  ADC_CONV_TYPE_INJECTED     /**< @brief Injected conversion mode */
} Adc_GroupConvType;
#endif /*  (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
           (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */

/**
* @brief          Adc Group conversion mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements
*
*/
typedef enum
{
  ADC_CONV_MODE_ONESHOT = 0U, /**< @brief One shot*/
  ADC_CONV_MODE_CONTINUOUS    /**< @brief Continuous conversion mode */
} Adc_GroupConvModeType;

/**
* @brief          Adc group replacement.
* @details        Used for value received by Tressos interface configuration.
*
* @implements
*
*/
typedef enum
{
  ADC_GROUP_REPL_ABORT_RESTART, /**< @brief Abort and restart of group*/
  ADC_GROUP_REPL_SUSPEND_RESUME /**< @brief Suspend and resuming of group*/
} Adc_GroupReplacementType;

/**
* @brief          Adc group streaming buffer mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements
*
*/
typedef enum
{
  ADC_STREAM_BUFFER_LINEAR = 0U, /**< @brief Linear streaming*/
  ADC_STREAM_BUFFER_CIRCULAR     /**< @brief Circualr streaming*/
} Adc_StreamBufferModeType;

/**
* @brief          ADC group status.
* @details        ADC group enumeration type.
*
* @implements
*
*/
typedef enum
{
  ADC_IDLE = 0U,       /**< @brief Group is in IDLE state*/
  ADC_BUSY,            /**< @brief Group is in BUSY state */
  ADC_COMPLETED,       /**< @brief Group is in COMPLETED state*/
  ADC_STREAM_COMPLETED /**< @brief Group is in STREAM_COMPLETED state*/
} Adc_StatusType;

/**
* @brief          ADC group notification.
* @details        Indicates if notification is enabled for the group.
*
* @implements
*/
typedef enum
{
  ADC_NOTIFICATION_DISABLED = 0U, /**< @brief Notification is disabled */
  ADC_NOTIFICATION_ENABLED        /**< @brief Notification is enabled */
} Adc_NotificationType;

/**
* @brief          Adc hardware trigger edge.
* @details        Used for value received by Tressos interface configuration.
*
* @implements
*/
typedef enum
{
  ADC_HW_TRIG_RISING_EDGE = 0U, /**< @brief Rising edge */
  ADC_HW_TRIG_FALLING_EDGE,     /**< @brief Falling edge */
  ADC_HW_TRIG_BOTH_EDGES        /**< @brief falling and rising edge */
} Adc_HwTriggerSignalType;

/**
* @brief          Adc hardware trigger source.
* @details        Used for value received by Tressos interface configuration.
*
* @implements
*/
typedef enum
{
  ADC_TRIGG_SRC_SW = 0U /**< @brief Software triggered */
#if (ADC_HW_TRIGGER_API == STD_ON)
,
  ADC_TRIGG_SRC_HW      /**< @brief Hardware triggered */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
} Adc_TriggerSourceType;

#if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__)
/**
* @brief          Adc Hardware trigger.
* @details        Indicates if hardware trigger is enabled for group.
*
* @implements
*/
typedef enum
{
  ADC_HWTRIGGER_DISABLED = 0U, /**< @brief Hardware trigger is disabled */
  ADC_HWTRIGGER_ENABLED        /**< @brief Hardware trigger is enabled */
} Adc_HWTriggeringType;

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Adc MHT group.
* @details        Inidcates if the hardware triggered group is regular or MHT type.
*
* @implements
*/
typedef enum
{
    ADC_REGULAR_GROUP_TYPE = 0U, /**< @brief Indicate that the group is part-of a regular groups */
    ADC_MHT_GROUP_TYPE           /**< @brief Indicate that the group is part-of the MHT groups subset */
} Adc_MhtGroupType;
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__) */
#endif /* (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__) */

/* Fado */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || defined(__DOXYGEN__)
/**
* @brief          Adc ctu prescaler configuration.
* @details        Inidcates all the values of ctu prescaler.
*
* @implements
*/
typedef enum
{
  CLOCK_DIV_BY_1 = 0U, /**< @brief Clock divided by 1 */
  CLOCK_DIV_BY_2,      /**< @brief Clock divided by 2 */
  CLOCK_DIV_BY_4,      /**< @brief Clock divided by 4 */
  CLOCK_DIV_BY_8,      /**< @brief Clock divided by 5 */
  CLOCK_DIV_BY_16,     /**< @brief Clock divided by 16 */
  CLOCK_DIV_BY_32,     /**< @brief Clock divided by 32 */
  CLOCK_DIV_BY_64,     /**< @brief Clock divided by 64 */
  CLOCK_DIV_BY_128,    /**< @brief Clock divided by 128 */
  CLOCK_DIV_BY_256,    /**< @brief Clock divided by 256 */
  CLOCK_DIV_BY_512,    /**< @brief Clock divided by 512 */
  CLOCK_DIV_BY_1024    /**< @brief Clock divided by 1024 */
} Adc_CtuPrescalerConfigurationType;

/**
* @brief          Adc ctu counter group.
* @details        Inidcates all the ctu counters.
*
* @implements
*/
typedef enum
{
  COUNTER_0 = 0U, /**< @brief Counter 0 is associated with the particular event */
  COUNTER_1,      /**< @brief Counter 1 is associated with the particular event */
  COUNTER_2,      /**< @brief Counter 2 is associated with the particular event */
  COUNTER_3       /**< @brief Counter 3 is associated with the particular event */
} Adc_CtuCounterGroupType;

/**
* @brief          Adc ctu delay index.
* @details        Inidcates all the ctu delay values.
*
* @implements
*/
typedef enum
{
  NO_DELAY = 0U,         /**< @brief Counter is loaded with no delay */
  DELAY_VALUE_FROM_SVR1, /**< @brief Counter is loaded with the value stored in CTU_SVR1 */
  DELAY_VALUE_FROM_SVR2, /**< @brief Counter is loaded with the value stored in CTU_SVR2 */
  DELAY_VALUE_FROM_SVR3, /**< @brief Counter is loaded with the value stored in CTU_SVR3 */
  DELAY_VALUE_FROM_SVR4, /**< @brief Counter is loaded with the value stored in CTU_SVR4 */
  DELAY_VALUE_FROM_SVR5, /**< @brief Counter is loaded with the value stored in CTU_SVR5 */
  DELAY_VALUE_FROM_SVR6, /**< @brief Counter is loaded with the value stored in CTU_SVR6 */
  DELAY_VALUE_FROM_SVR7  /**< @brief Counter is loaded with the value stored in CTU_SVR7 */
} Adc_CtuDelayIndexType;
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || defined(__DOXYGEN__) */

#if (ADC_SET_MODE_API==STD_ON)
/**
* @brief          Set mode values.
* @details        Inidcates all the values to set teh Adc mode.
*
* @implements
*/
typedef enum
{
  ADC_NORMAL_MODE = 0U, /**< @brief Normal mode */
  ADC_POWER_DOWN_MODE   /**< @brief Power down mode */
} Adc_SetModeType;
#endif /* (ADC_SET_MODE_API==STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Range select values.
* @details        Inidcates which range select is used.
*
* @implements
*/
typedef enum
{
  ADC_RANGE_ALWAYS = 0U,   /**< @brief Complete range - independent from channel limit settings */
  ADC_RANGE_BETWEEN,       /**< @brief Range between low limit and high limit - high limit value included */
  ADC_RANGE_NOT_BETWEEN,   /**< @brief Range above high limit or below low limit - low limit value included */
  ADC_RANGE_NOT_OVER_HIGH, /**< @brief Range below high limit - high limit value included */
  ADC_RANGE_NOT_UNDER_LOW, /**< @brief Range above low limit */
  ADC_RANGE_OVER_HIGH,     /**< @brief Range above high limit */
  ADC_RANGE_UNDER_LOW      /**< @briefRange below low limit - low limit value included */
} Adc_ChannelRangeSelectType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef void (*Adc_NotifyType)(void);     /**< @brief Notification function pointer definition */
typedef void (*Adc_WdgNotifyType)(void);  /**< @brief Notification function pointer definition - WDG */
typedef uint8 Adc_ChannelType;            /**< @brief Numeric ID of an ADC channel */
typedef uint16 Adc_GroupType;              /**< @brief Numeric ID of an ADC channel group. No uC dependent */
typedef uint8 Adc_ResolutionType;         /**< @brief channel resolution in number of bits */
typedef uint8 Adc_GroupPriorityType;      /**< @brief ADC Channel group priority */
typedef Adc_ChannelType Adc_GroupDefType; /**< @brief definition of channels in a group */
typedef uint8 Adc_HwUnitType;             /**< @brief Numeric ID of an ADC Hw Unit */
typedef uint16 Adc_ValueGroupType;        /**< @brief type for ADC result of one channel */
typedef uint8 Adc_ClockSourceType;        /**< @brief clock source for ADC */
typedef uint8 Adc_PrescaleType;           /**< @brief clock prescaler factor */
typedef uint16 Adc_ConversionTimeType;    /**< @brief conversion time */
typedef uint8 Adc_SamplingTimeType;       /**< @brief sampling time */
typedef uint16 Adc_VoltageSourceType;     /**< @brief reference voltage source */
typedef uint16 Adc_StreamNumSampleType;   /**< @brief Number of samples of a streaming conversion buffer */
typedef uint16 Adc_HwTriggerTimerType;    /**< @brief Type for the reload value of the ADC embedded timer */
typedef uint8 Adc_QueueIndexType;         /**< @brief Index for the queue of groups */
#if (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY)
typedef uint8 Adc_Dma_ContinuousType;     /**< @brief Indicate if DMA channels are continuous or has gaps */
#endif /* (STD_OFF == ADC_DIRECT_DMA_RES_BUFFER_COPY) */
#if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) /* Fado */
typedef uint16 Adc_CtuStartValueType;     /**< @brief Start Value to be loaded into the Counter event */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */

/**
* @brief          Structure for channel configuration.
*
* @api
*
* @implements
*/
typedef struct
{
  CONST(Adc_ChannelType, ADC_CONST) ChId; /**< @brief Channel Id */
  CONST(uint8, ADC_CONST) ThReg; /**< @brief Threshold register configured */
  CONST(uint32, ADC_CONST) ThValues; /**< @brief Threshold register value */
#if defined(IPV_ADCDIG) || defined(__DOXYGEN__)
 /* if !Bolero 3M && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther*/
 #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)) || \
      defined(__DOXYGEN__) || defined(IPV_ADCDIG_31201_BOLERO256K)
  CONST(uint32, ADC_CONST) ThCtrl; /**< @brief Threshold register control value */
 #endif /* ((IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)
            (IPV_ADCDIG != IPV_ADCDIG_00_03_12_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
            (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)) || defined(__DOXYGEN__) */
#endif /* defined(IPV_ADCDIG) || defined(__DOXYGEN__) */
#ifdef IPV_ADCDIG_31301_PICTUS1M /* if Pictus1M */
  CONST(uint32, ADC_CONST) ThCtrl; /**< @brief Threshold register control value */
#endif /* IPV_ADCDIG_31301_PICTUS1M */
  CONST(Adc_WdgNotifyType , ADC_CONST) WdogNotification; /**< @brief Wdg notification function pointer */
#if defined(IPV_ADCDIG) || defined(__DOXYGEN__)
/* if !Pictus512_256 */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__)
  CONST(uint8, ADC_CONST) EnablePresampling; /**< @brief status to indicate the presampling state */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) */
#endif /* defined(IPV_ADCDIG) || defined(__DOXYGEN__) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__)
  CONST(boolean, ADC_CONST) ChannelLimitCheck; /**< @brief Channel limit checking feature */
  CONST(Adc_ChannelRangeSelectType, ADC_CONST) ChannelRange; /**< @brief  Range conversion */
  CONST(uint32, ADC_CONST) ChannelHighLimit; /**< @brief High limit channel conversion value */
  CONST(uint32, ADC_CONST) ChannelLowLimit; /**< @brief Low limit channel conversion value */
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__) */
} Adc_LLD_ChannelConfiguration;

/**
* @brief          Structure for Adc hardware unit configuration.
*
* @api
*
* @implements
*/
typedef struct
{
  CONST(Adc_HwUnitType, ADC_CONST) AdcHardwareUnitId; /**< @brief Adc hardware unit id */
  CONST(uint32, ADC_CONST) AdcMainConfig; /**< @brief Main configuration of control registers */
  CONST(uint8, ADC_CONST) AdcPwrDownDelay; /**< @brief Power down delay for normal power system frequency */
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
  CONST(uint8, ADC_CONST) AdcAltPwrDownDelay; /**< @brief Power down delay for low power system frequency */
#endif
#if defined(IPV_ADCDIG) || defined(__DOXYGEN__)
 /* if !Pictus512_256 */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__)
  /* if !Leopard cut2 (!Pictus1M) and !Komodo 2M and !Panther*/
  #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__)
    #if (ADC_MUX_DELAY_SUPPORT == STD_ON)
      /** @brief Mux delay value */
      CONST(uint16, ADC_CONST) AdcMuxDelay;
    #if (ADC_DUAL_CLOCK_MODE  == STD_ON)
      /** @brief Alternate Mux delay value */
      CONST(uint16, ADC_CONST) AdcAltMuxDelay;
    #endif
    #endif
  #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) || defined(__DOXYGEN__)*/
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) && (!defined(IPV_ADCDIG_31301_PICTUS1M)) && \
      (!defined(IPV_ADCDIG_31301_KOMODO2M))
  CONST(uint8, ADC_CONST) PreVal0; /**< @brief presampling control register - preval0 field */
  CONST(uint8, ADC_CONST) PreVal1; /**< @brief presampling control register - preval1 field */
    /* Rainier or Calypso */
  #elif (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10)
  CONST(uint8, ADC_CONST) PreVal0; /**< @brief presampling control register - preval0 field */
  CONST(uint8, ADC_CONST) PreVal1; /**< @brief presampling control register - preval1 field */
  CONST(uint8, ADC_CONST) PreVal2; /**< @brief presampling control register - preval2 field */
  #else
  CONST(uint8, ADC_CONST) PreVal; /**< @brief presampling control register - preval field */
  #endif  /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) && (!defined IPV_ADCDIG_31301_PICTUS1M) && \
             (!defined IPV_ADCDIG_31301_KOMODO2M) */
  CONST(uint8, ADC_CONST) PreConv; /**< @brief presampling control register - preconv field */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__) */
#endif /* defined(IPV_ADCDIG) || defined(__DOXYGEN__) */
  /**
  * @brief Normal and Alternate Conversion Timings
  */
  CONST(Adc_ConversionTimeType, ADC_CONST) ConvTimeNormal;
  CONST(Adc_ConversionTimeType, ADC_CONST) ConvTimeAlternate;
  #ifdef IPV_ADCDIG
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
      #ifndef IPV_ADCDIG_31301_PICTUS1M
    /**
     * @brief   Conversion time CTR1 for Leopard or Komodo or Panther or Rainier
    */
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTimeNormal1;
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTimeAlternate1;
    #endif /* IPV_ADCDIG_31301_PICTUS1M */
  #endif /* if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
               (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
  #endif /* ifdef IPV_ADCDIG */
  CONST(Adc_ResolutionType, ADC_CONST) Res; /**< @brief Resolution of the ADC hardware */
 #if ((IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__))
 /* if !Pictus512_256  */
  #if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON)
  /**
  * @brief   Presampling for Precision channels.
  */
  CONST(uint32, ADC_CONST) Adc_PrecisionPsr;
/* if !Leopard cut2 and !Pictus and !Komodo 2M and !Leopard2M and !Panther */
 #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__)
  /**
  * @brief   Presampling for extended channels.
  */
  CONST(uint32, ADC_CONST) Adc_ExtendedPsr;
  /**
  * @brief   Presampling for External channels.
  */
  CONST(uint32, ADC_CONST) Adc_ExternalPsr;
 #endif /* #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
                (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__) */
 #endif /* (ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON) */
 #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */ 
 #if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_ON)
  /**
  * @brief   Wer0 for precision channels.
  */
  CONST(uint32, ADC_CONST) Adc_Wer0;
  #endif /* (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_ON) */
 #endif /* IPV_ADCDIG_31301_PICTUS1M */ 
 /* if !Leopard cut2 and !Pictus and !Komodo 2M and !Leopard2M and !Panther */
 #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
      (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__)
 #if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_ON)
  /**
  * @brief   Wer1 for extended(medi.accuracy channels).
  */
  CONST(uint32, ADC_CONST) Adc_Wer1;
  /**
  * @brief   Wer2 for external channels.
  */
  CONST(uint32, ADC_CONST) Adc_Wer2;
 #endif /* (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_ON) */
 #endif /* #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
                (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__) */
#endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || (defined(__DOXYGEN__) */
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON)
  /**
  * @brief   Conversion time.
  */
  CONST(Adc_ConversionTimeType , ADC_CONST) ConvTime;
/* if Leopard cut2 (Pictus1M) or Komodo 2M or Leopard2M or Panther or Rainier */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
  /**
  * @brief   Conversion time CTR1.
  */
  CONST(Adc_ConversionTimeType , ADC_CONST) ConvTime1;
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
#endif /* #if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) ||
              (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) */
#endif /* #if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON) */
} Adc_LLD_HWUnitConfiguration;

/**
* @brief          Structure for group configuration.
*
* @api
*
* @implements
*/
typedef struct
{
  CONST(Adc_HwUnitType, ADC_CONST) HWUnit; /**< @brief Hw unit to which the group belongs to */
  CONST(Adc_GroupAccessModeType , ADC_CONST) AccessMode; /**< @brief   Access mode */
  CONST(Adc_GroupConvModeType , ADC_CONST) mode; /**< @brief Conversion mode (OneShot/Continuous) */
/* if Bolero 1.5M or Bolero 512K or Leopard cut2 (Pictus 1M) or Fado or Pictus 512k_256k or
   Komodo 2M or Bolero 3M (Bolero 256k-128k) or Leopard2M or Panther or Rainier or Calypso */
#if (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) || \
    (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) || defined(__DOXYGEN__)
  CONST(Adc_GroupConvType , ADC_CONST) type; /**< @brief Conversion type (Normal/Injected) */
#endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_09_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_08_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_01_06_01) || (IPV_ADCDIG == IPV_ADCDIG_00_03_12_01) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12) ||
          (IPV_ADCDIG == IPV_ADCDIG_00_00_04_10) || defined(__DOXYGEN__) */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || defined(__DOXYGEN__)
  CONST(Adc_GroupPriorityType , ADC_CONST) Priority; /**< @brief Priority of group */
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || defined(__DOXYGEN__) */
  CONST(Adc_GroupReplacementType , ADC_CONST) ReplecementMode; /**< @brief Replacement mode */
  CONST(Adc_TriggerSourceType , ADC_CONST) TriggerSource; /**< @brief Hw/Sw trigger */
#if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__)
 #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__)
  CONST(Adc_MhtGroupType, ADC_CONST) IsMHTGroup; /**< @brief Inidicate the group type (Regular or MHT) */
 #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__) */
  CONST(Adc_HwTriggerSignalType , ADC_CONST) TriggerEdge; /**< @brief Hardware trigger edge */
 /* if !Leopard cut2 (Pictus 1M) and !Pictus 512k_256k and !Komodo 2M and !Panther and !Rainier and !Calypso */
 #if (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
  CONST(Adc_HwTriggerTimerType, ADC_CONST) AssignedTriggerCount; /**< @brief Number of trigger channels assigned to the group */
 #endif /* (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) 
           (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12)
           (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)*/
  P2CONST(Adc_HwTriggerTimerType, ADC_VAR, ADC_APPL_CONST) HwResource; /**< @brief Resource of the selected hw trigger */
 /* Fado */
 #if (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01)
  CONST(Adc_CtuPrescalerConfigurationType, ADC_CONST) PrescConfig; /**< @brief Prescaler configuration */
  CONST(Adc_CtuCounterGroupType, ADC_CONST) CounterGroup; /**< @brief Counter associated with the particular event */
  CONST(Adc_CtuDelayIndexType, ADC_CONST) DelayIndex; /**< @brief Delay index: Which CTU_SVRx register is used */
  CONST(Adc_CtuStartValueType, ADC_CONST) CounterStartValue;  /**< @brief Start Value Register for the counter chosen */
 #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_01_05_01) */
#endif /* #if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY) || defined(__DOXYGEN__)
  CONST(Adc_NotifyType , ADC_CONST) Notification; /**< @brief Pointer to notification function */
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) || defined(__DOXYGEN__) */
  CONST(uint32, ADC_CONST) Adc_PrecisionChannel; /**< @brief ANP0_31, Precision configured channels */
/* !Pictus512_256 && !Leopard && !Leopard cut2/cut3 && !Pictus1M && !Komodo 2M && !Panther*/
#if ((IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
    (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__)
  CONST(uint32, ADC_CONST) Adc_ExtendedChannel; /**< @brief ANS0_31 medium accuracy extended configured channels */
  CONST(uint32, ADC_CONST) Adc_ExternalChannel; /**< @brief  ANX_0_CH_64-ANX_3_CH_95 External configured channels */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && (IPV_ADCDIG != IPV_ADCDIG_00_02_00_01) && \
          (IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01) || defined(__DOXYGEN__) */
/* if !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__)
#if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF)
  CONST(uint32, ADC_CONST) Adc_PrecisionPsr; /**< @brief Presampling for Precision channels */
 /* if !Leopard cut2 and !Pictus and !Komodo 2M and !Panther */
 #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__)
  CONST(uint32, ADC_CONST) Adc_ExtendedPsr; /**< @brief Presampling for extended channels */
  CONST(uint32, ADC_CONST) Adc_ExternalPsr; /**< @brief Presampling for External channels */
 #endif /* ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__) */
#endif /* (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) */
#if (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_OFF)
 /* if !Pictus1M */
 #ifndef IPV_ADCDIG_31301_PICTUS1M
  CONST(uint32, ADC_CONST) Adc_Wer0; /**< @brief Wer0 for precision channels */
 #endif /* IPV_ADCDIG_31301_PICTUS1M */
 /* if !Leopard cut2 and !Pictus and !Komodo 2M and !Panther */
 #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) && \
     (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__) /* if !Leopard cut2 and !Pictus and !Komodo 2M */
  CONST(uint32, ADC_CONST) Adc_Wer1; /**< @brief Wer1 for extended(medi.accuracy channels) */
  CONST(uint32, ADC_CONST) Adc_Wer2; /**< @brief Wer2 for external channels */
#endif /* ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) &&
           (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || defined(__DOXYGEN__) */
  #endif /* (ADC_SET_ADC_WDG_ENABLE_ONCE == STD_OFF) */
#endif /* #if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__) */

/* if !Pictus512_256 */
#if (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__)
  /* if !Leopard cut2 (!Pictus1M) and !Komodo 2M and !Leopard2M and !Panther */
  #if ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) || \
      defined(__DOXYGEN__)

    #if ((ADC_MUX_DELAY_SUPPORT == STD_ON) && (ADC_MUX_DELAY_SUPPORT_PER_GROUP == STD_ON))
      CONST(uint8, ADC_CONST) AdcMuxDelayNeeded; /* Enables or Disables Adc Mux Delay */
    #endif

  #endif /* ((IPV_ADCDIG != IPV_ADCDIG_00_03_13_01) && (IPV_ADCDIG != IPV_ADCDIG_00_00_03_01)) ||
                defined(__DOXYGEN__) */
#endif /* (IPV_ADCDIG != IPV_ADCDIG_00_01_06_01) || defined(__DOXYGEN__) */

  P2P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) ResultsBufferPtr; /**< @brief pointer to user result buffer array */
  CONST(Adc_StreamBufferModeType , ADC_CONST) BufferMode; /**< @brief Buffer Mode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API==STD_ON) || defined(__DOXYGEN__)
  CONST(Adc_GroupType, ADC_CONST) EnableChDisableChGroupIndex; /**< @brief Group's index if it has the support to enable/disable channel */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */
  CONST(Adc_StreamNumSampleType , ADC_CONST) NumSamples; /**< @brief  Number of samples */
  P2CONST(Adc_GroupDefType , ADC_VAR, ADC_APPL_CONST) Assignment; /**< @brief Assigned channels to group */
  CONST(Adc_ChannelType , ADC_CONST) AssignedChannelCount; /**< @brief Number of channels */
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
  CONST(Adc_ConversionTimeType , ADC_CONST) ConvTime; /**< @brief Conversion time */
/* if Leopard cut2/cut3 or Pictus1M or Komodo 2M or Panther or Rainier cut 1.0 */
  #if (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) || \
      (IPV_ADCDIG == IPV_ADCDIG_00_00_04_12)
   #ifndef IPV_ADCDIG_31301_PICTUS1M /* if !Pictus1M */
  CONST(Adc_ConversionTimeType , ADC_CONST) ConvTime1; /**< @brief Conversion time CTR1 */
   #endif /* IPV_ADCDIG_31301_PICTUS1M */
  #endif /* (IPV_ADCDIG == IPV_ADCDIG_00_03_13_01) || (IPV_ADCDIG == IPV_ADCDIG_00_00_03_01) */
#endif /* #if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF) */
  CONST(uint32 , ADC_CONST) LastCh; /**< @brief Last channel configured */
  CONST(uint32 , ADC_CONST) FirstCh; /**< @brief First channel configured */
  CONST(uint8 , ADC_CONST) AdcWithoutInterrupt; /**< @brief Enables or Disables the ADC and DMA interrupts */
} Adc_LLD_GroupConfiguration;

/**
* @brief          Miscellaneous configuration structure.
*
* @api
*
* @implements
*/
typedef struct
{
  CONST(uint8 , ADC_CONST) ADC_DMA_INTERRUPT_SOFTWARE; /**< @brief DMA or Interrupt driven */
#if (IPV_ADCDIG != IPV_ADCDIG_00_00_04_12) && (IPV_ADCDIG != IPV_ADCDIG_00_00_04_10)
  CONST(uint8 , ADC_CONST) ADC_ACTIVE_CTUV2; /**< @brief Indicate if CTU controls the ADC */
#else
  CONST(uint8 , ADC_CONST) ADC_ACTIVE_BCTU; /**< @brief Indicate if BCTU controls the ADC */
#endif
  CONST(uint8 , ADC_CONST) ADC_MAX_GROUPS; /**< @brief Number of the maximum groups */
  CONST(uint8 , ADC_CONST) ADC_MAX_HWCFG; /**< @brief Number of the maximum hw units */
  CONST(uint16 , ADC_CONST) ADC_QUEUE_MAX_DEPTH; /**< @brief Depth of the queue */
  CONST(Adc_GroupType , ADC_CONST) ADC_GROUPS[ADC_HW_MAX]; /** <@brief   number of groups of the hw unit x*/ 
  CONST(uint8 , ADC_CONST) ADC_CHANNELS[ADC_HW_MAX]; /**< @brief Number of channels of the hw unit x */
  CONST(uint8 , ADC_CONST) ADC_DMA_CH[ADC_HW_MAX]; /**< @brief If dma driven then indicates the dma channel number for HW UNITS */
  CONST(uint8 , ADC_CONST) ADC_HW_UNIT[ADC_HW_MAX]; /**< @brief If unit x is active STD_ON/STD_OFF */
  CONST(uint8 , ADC_CONST) ADC_HW_QUEUE_MAX_DEPTH[ADC_HW_MAX]; /**< @brief Maximum depth of the hw queue for each unit */
} Adc_LLD_MultiConfig;


/**
* @brief          This structure is used to manipulate the MHT Multiple Hardware
*                 Triggered groups
* @api
*
* @implements
*/
typedef struct
{
  VAR(Adc_ChannelType, ADC_VAR) chId; /**< @brief The ID of a physical ADC channel */
  VAR(Adc_GroupType, ADC_VAR) grId; /**< @brief The ID of a MHT group */
  VAR(uint32, ADC_VAR) mask; /**< @brief Mask value */
  VAR(uint8, ADC_VAR) register_index; /**< @brief register index value */
} Adc_LLD_MhtChannelGroupType ;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifndef ADC_PRECOMPILE_SUPPORT
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_3 Identifier exceeds 31 characters */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_1 Repeated include file */
#include "MemMap.h"

/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_3 Identifier exceeds 31 characters */
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_ADCDig_LLD_CfgEx_h_REF_1 Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_ADCDIG_LLD_CFGEX_H */

/** @} */
