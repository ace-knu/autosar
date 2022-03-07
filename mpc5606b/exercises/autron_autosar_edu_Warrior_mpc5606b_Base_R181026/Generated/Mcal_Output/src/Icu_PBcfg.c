/**
*     @file    Icu_PBCfg.c
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - contains the data exported by the Icu module
*     @details Contains the information that will be exported by the module, as requested by Autosar.
*
*
*     Project AUTOSAR 4.0 MCAL
*     Platform PA
*     Peripheral eMIOS
*     Dependencies none
*
*     ARVersion 4.0.3
*     ARRevision ASR_REL_4_0_REV_0003
*     ARConfVariant
*     SWVersion 1.0.1
*     BuildVersion MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*     (c) Copyright 2006-2014 Freescale Semiconductor Inc. & STMicroelectronics
*     All Rights Reserved.
*/
/*==================================================================================================
* ==================================================================================================*/
/*
 * @file    Icu_PBcfg.c
 * @remarks Implements DICU02701
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_PBcfg_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Icu_PBcfg_c_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Icu_PBcfg_c_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_PBcfg_c_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Icu_PBcfg_c_5
* Violates MISRA 2004 Required Rule 8.8, Function is declared previously
*   This is not a violation since the funciton is declared earlier during Precompile.
*
* @section Icu_PBcfg_c_6
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be
* permitted.
*
*
*@section Icu_PBcfg_c_7
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/*   @implements    DICU02701 */
#include "Icu.h"
#include "Icu_LLD.h"

#ifndef ICU_PRECOMPILE_SUPPORT

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

/**
* @{
* @brief   Configuration source file version information
* @implements DICU02301, DICU02302, DICU02303, DICU02304, DICU02305, DICU02306, DICU02307
*/
#define ICU_VENDOR_ID_PBCFG_C                        43

/*
* @violates @ref Icu_PBcfg_c_7 This is required as per autosar Requirement, 
*/
#define ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
/*
* @violates @ref Icu_PBcfg_c_7 This is required as per autosar Requirement, 
*/
#define ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C         0
/*
* @violates @ref Icu_PBcfg_c_4 external ... could be made static
*/
/*
* @violates @ref Icu_PBcfg_c_7 This is required as per autosar Requirement, 
*/
#define ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C      3

#define ICU_SW_MAJOR_VERSION_PBCFG_C                 1
#define ICU_SW_MINOR_VERSION_PBCFG_C                 0
#define ICU_SW_PATCH_VERSION_PBCFG_C                 1
/**@}*/
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check Icu_PBCfg.c against Icu.h file versions */
#if (ICU_VENDOR_ID_PBCFG_C != ICU_VENDOR_ID)
    #error "Icu_PBcfg.c and Icu.h have different vendor IDs"
#endif

    #if ((ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C != ICU_AR_RELEASE_MINOR_VERSION) || \
         (ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_PBcfg.c and Icu.h are different"
    #endif

#if ((ICU_SW_MAJOR_VERSION_PBCFG_C != ICU_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_PBCFG_C != ICU_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_PBCFG_C != ICU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_PBcfg.c and Icu.h are different"
#endif

/* Check Icu_Cfg.c against Icu_LLD.h file versions */
#if (ICU_VENDOR_ID_PBCFG_C != ICU_LLD_VENDOR_ID)
#error "Icu_PBcfg.c and Icu_LLD.h have different vendor IDs"
#endif

    #if ((ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ICU_LLD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C != ICU_LLD_AR_RELEASE_MINOR_VERSION) || \
         (ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C != ICU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_PBCfg.c and Icu_LLD.h are different"
    #endif

#if ((ICU_SW_MAJOR_VERSION_PBCFG_C != ICU_LLD_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_PBCFG_C != ICU_LLD_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_PBCFG_C != ICU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_PBCfg.c and Icu_LLD.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CODE

/*
* @violates @ref Icu_PBcfg_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
*   @violates @ref Icu_PBcfg_c_1 only preprocessor statements and comments before
*        "#include".
*/    
#include "MemMap.h"



/*
*   @brief External Notifications, for EdgeDetection and Timestamp mode channels 
*   @implements    DICU02317 
*/

/*
* @violates @ref Icu_PBcfg_c_7 This is required as per autosar Requirement, 
*/
extern FUNC (void, ICU_CODE) IcuTimestampMeasurement_0_Cbk(void);




#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_PBcfg_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Icu_PBcfg_c_1 ,  only preprocessor statements and
* comments before "#include"
*/
#include "MemMap.h"
/*
* @violates @ref Icu_PBcfg_c_7 This is required as per autosar Requirement, 
*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Icu_PBcfg_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Icu_PBcfg_c_1 ,  only preprocessor statements and
* comments before "#include"
*/
#include "MemMap.h"

/**
* @brief  This index relates the Icu Channel number with the respective global variable, depending on the measurement mode
* Each kind of measurement mode has an array(s) in the ICU driver, this index points to the corresponding variable within the ICU channel
 */
/*
* @violates @ref Icu_PBcfg_c_2 MISRA 2004 Advisory Rule 10.1, The value of an expression of integer type shall not be implicitly
*       converted to a different underlying type
* @implements DICU02312
*/

/**
* @brief  This index relates the Hardware channels with the respective ICU channel.
* When an normal interrupt is asserted this index is used to locate the corresponding ICU channel
 */
/*
* @violates @ref Icu_PBcfg_c_2  MISRA 2004 Advisory Rule 10.1, The value of an expression of integer type shall not be implicitly
*         converted to a different underlying type
* @implements DICU02313
*/
CONST(Icu_ChannelType,ICU_CONST) Icu_InitPBChannelIndex_0[3] = {
(Icu_ChannelType)0x00,
(Icu_ChannelType)0x00,
(Icu_ChannelType)0x00

};


/**
* @brief  This index relates the Hardware channels with the respective ICU channel.
* When an normal interrupt is asserted this index is used to locate the corresponding ICU channel
 */
/*
* @violates @ref Icu_PBcfg_c_2  MISRA 2004 Advisory Rule 10.1, The value of an expression of integer type shall not be implicitly
*         converted to a different underlying type
* @implements DICU02313
*/
/*
*  @violates @ref Icu_PBcfg_c_3 external ... could be made static
*/    
CONST(Icu_ChannelType,ICU_CONST) Icu_InitPBHWMap_0[ICU_MAX_HW_CHANNELS + 1U] = {
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0x00,
(Icu_ChannelType)0x01,
(Icu_ChannelType)0x02,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF
};



/**
* @brief  This index relates the Wakeup pins with the respective ICU channel
* When an wake up interrupt is asserted this index is used to locate the corresponding ICU channel
 */
/*
* @violates @ref Icu_PBcfg_c_2 MISRA 2004 Advisory Rule 10.1, The value of an expression of integer type shall not be implicitly
*         converted to a different underlying type
* @implements DICU02314
*/
/*
*  @violates @ref Icu_PBcfg_c_3 external ... could be made static
*/
CONST(Icu_ChannelType,ICU_CONST) Icu_InitPBHWWKMap_0[ICU_MAX_HW_CHANNELS + 1U] = {
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF,
(Icu_ChannelType)0xFF
};




/**@brief PostBuild Configuration */
/*
* @violates @ref Icu_PBcfg_c_2  MISRA 2004 Advisory Rule 10.1, The value of an expression of integer type shall not be implicitly
*         converted to a different underlying type
* @implements DICU02311
*/
/*
*  @violates @ref Icu_PBcfg_c_3 external ... could be made static
*/    
CONST(Icu_ChannelConfigType, ICU_CONST) Icu_InitPBChannel_0[3] =
{
    /* IcuChannel_EdgeCounter - EMIOS_0_CH_6 */
    {
    (((Icu_ParamType)ICU_FALLING_EDGE << ICU_EDGE_PARAM_SHIFT)
 /*@violates @ref Icu_PBcfg_c_6 MISRA 2004 Required Rule,Invariant results for Boolean
    *  Ops */
 | (EMIOS_PRESCALER_DIVIDE_1 << ICU_EMIOS_PRESCALER_PARAM_SHIFT) |    (EMIOS_DIGITAL_FILTER_BYPASSED << ICU_EMIOS_DIG_FILTER_PARAM_SHIFT) | (EMIOS_BUS_INTERNAL_COUNTER << ICU_EMIOS_BUS_SELECT_PARAM_SHIFT)|((Icu_ParamType)0U << ICU_SIUL_INT_FILTER_COUNTER_PARAM_SHIFT)),
    (Icu_MeasurementModeType)ICU_MODE_EDGE_COUNTER,
    (Icu_MeasurementSubModeType)ICU_FALLING_EDGE,
        NULL_PTR,
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    NULL_PTR,
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
        (boolean)FALSE,
(Icu_WakeupValue)0U,
        (boolean)FALSE,
        },
         
    /* IcuChannel_SignalMeasurement - EMIOS_0_CH_7 */
    {
    (((Icu_ParamType)ICU_RISING_EDGE << ICU_EDGE_PARAM_SHIFT)
 |((Icu_ParamType)EMIOS_UC_SAIC_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT) /*@violates @ref Icu_PBcfg_c_6 MISRA 2004 Required Rule,Invariant results for Boolean
    *  Ops */
 | (EMIOS_PRESCALER_DIVIDE_1 << ICU_EMIOS_PRESCALER_PARAM_SHIFT) |    (EMIOS_DIGITAL_FILTER_BYPASSED << ICU_EMIOS_DIG_FILTER_PARAM_SHIFT) | (EMIOS_BUS_INTERNAL_COUNTER << ICU_EMIOS_BUS_SELECT_PARAM_SHIFT)|((Icu_ParamType)0U << ICU_SIUL_INT_FILTER_COUNTER_PARAM_SHIFT)),
    (Icu_MeasurementModeType)ICU_MODE_SIGNAL_MEASUREMENT,
    (Icu_MeasurementSubModeType)ICU_DUTY_CYCLE,
        NULL_PTR,
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    NULL_PTR,
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
        (boolean)FALSE,
(Icu_WakeupValue)0U,
        (boolean)FALSE,
        },
         
    /* IcuChannel_Timestamp - EMIOS_0_CH_8 */
    {
    (((Icu_ParamType)ICU_RISING_EDGE << ICU_EDGE_PARAM_SHIFT)
 /*@violates @ref Icu_PBcfg_c_6 MISRA 2004 Required Rule,Invariant results for Boolean
    *  Ops */
 | (EMIOS_PRESCALER_DIVIDE_1 << ICU_EMIOS_PRESCALER_PARAM_SHIFT) |    (EMIOS_DIGITAL_FILTER_BYPASSED << ICU_EMIOS_DIG_FILTER_PARAM_SHIFT) | (EMIOS_BUS_INTERNAL_COUNTER << ICU_EMIOS_BUS_SELECT_PARAM_SHIFT)|((Icu_ParamType)0U << ICU_SIUL_INT_FILTER_COUNTER_PARAM_SHIFT)),
    (Icu_MeasurementModeType)ICU_MODE_TIMESTAMP,
    (Icu_MeasurementSubModeType)ICU_CIRCULAR_BUFFER,
        &IcuTimestampMeasurement_0_Cbk,
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    NULL_PTR,
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
        (boolean)FALSE,
(Icu_WakeupValue)0U,
        (boolean)FALSE,
        }
};



/**@brief PostBuild Configuration */
/*
*   @brief Configured Hardware channels
*   @implements    DICU02310
*
*/
/*
* @violates @ref Icu_PBcfg_c_2 external ... could be made static
*/
CONST(Icu_ChannelType,ICU_VAR) Icu_ChannelId_0[3]=

{
      ICU_EMIOS_0_CH_6 ,
         ICU_EMIOS_0_CH_7 ,
         ICU_EMIOS_0_CH_8 
       
 };


/**
* @brief PostBuild Configuration
* @implements    DICU02315
*/

/*
* @violates @ref Icu_PBcfg_c_2 external ... could be made static
* @violates @ref Icu_PBcfg_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
CONST(Icu_ConfigType, ICU_CONST) IcuConfigSet_0 =
{
    (Icu_ChannelType)3, /* The number of channels configured*/
    Icu_InitPBChannel_0,
    Icu_InitPBChannelIndex_0,
    Icu_ChannelId_0,
    Icu_InitPBHWMap_0,
    Icu_InitPBHWWKMap_0,
#ifdef ICU_DMA_SUPPORTED   
    NULL_PTR,
    NULL_PTR,
#endif    
    (Icu_ClockPrescalerType)0U,
    #if (ICU_DUAL_CLOCK_MODE == STD_ON)
    (Icu_ClockPrescalerType)0U,
#endif  
};


/*
* @violates @ref Icu_PBcfg_c_7 This is required as per autosar Requirement, 
*/
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
*  @file  Icu_PBcfg.c
* @violates @ref Icu_PBcfg_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
*/

/*
* @violates @ref Icu_PBcfg_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#endif /* ICU_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif


