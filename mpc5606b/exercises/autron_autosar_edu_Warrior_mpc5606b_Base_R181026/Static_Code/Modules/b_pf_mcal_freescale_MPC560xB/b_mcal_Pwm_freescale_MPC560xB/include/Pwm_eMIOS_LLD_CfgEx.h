/**
*   @file    Pwm_eMIOS_LLD_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS200
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

#ifndef PWM_EMIOS_LLD_CfgEx_H
#define PWM_EMIOS_LLD_CfgEx_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_eMIOS_LLD_CfgEx_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents of a
* header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section Pwm_eMIOS_LLD_CfgEx_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section Pwm_eMIOS_LLD_CfgEx_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
*/
/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included twice
*/
#include "Std_Types.h"


/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

#define PWM_EMIOS_LLD_CFGEX_H_VENDOR_ID                         43
#define PWM_EMIOS_LLD_CFGEX_H_MODULE_ID                         121
/*
* @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION          4
/*  @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_2 Identifier clash. */
/*
* @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION          0
/*  @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_2 Identifier clash. */
/*
* @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_REVISION_VERSION       3
/*
* @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_CFGEX_H_SW_MAJOR_VERSION                  1
/*
* @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_CFGEX_H_SW_MINOR_VERSION                  0
/*
* @violates @ref Pwm_eMIOS_LLD_CfgEx_h_REF_3 This is required as per autosar Requirement, 
*/
#define PWM_EMIOS_LLD_CFGEX_H_SW_PATCH_VERSION                  1


/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h are of the same Autosar version */
#if ((PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS_LLD_CfgEx.h and Std_Types.h are different"
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/



/*
* This should be based on defines from Reg_eSys_EMIOS_Pwm.h but this file
* inclusion must be avoided in order to avoid exporting all the EMIOS
* internals to the user
*/

/**
* @brief   Modulus Up Counter with internal source
*/
#define PWM_MODE_MC                (0x00000010UL)
 /**
* @brief   Bus Select: Modulus Up/Down Counter
*/
#define PWM_MODE_MCB_UD                (0x00000054UL)
/**
* @brief   Modulus Up Counter Buffered with internal source
*/
#define PWM_MODE_MCB               (0x00000050UL)
/**
* @brief   OPWFMB Buffered with Flag on B Match (period)
*/
#define PWM_MODE_OPWFMB            (0x00000058UL)
/**
* @brief   Buffered with Flag on B Match (period)
*/
#define PWM_MODE_OPWMB             (0x00000060UL)
/**
* @brief   Output Pulse Width Modulation with Trigger
*/
#define PWM_MODE_OPWMT             (0x00000026UL)
/**
* @brief Center Aligned Output Pulse Width Modulation Buffered Lead Edge
*/
#define PWM_MODE_OPWMCB              (0x0000005DUL)
/**
* @brief Center Aligned Output Pulse Width Modulation Buffered with lead edge dead time
*/
#define PWM_MODE_OPWMCB_LEAD_DEADTIME              (0x0000005DUL)
/**
* @brief Center Aligned Output Pulse Width Modulation Buffered with trial edge dead time
*/
#define PWM_MODE_OPWMCB_TRAIL_DEADTIME              (0x0000005CUL)
 /**
     @brief   Double Action Output Compare
  */
#define PWM_MODE_DAOC             (0x00000006UL)
 /**
* @brief   Bus select: counter bus[A]
*/
#define PWM_BUS_A                  (0x00000000UL)
/**
* @brief   Bus select: channels [0,7]: counter busB, channels [8,15]: counter busC, channels [16,23]: counter busD
*/
#define PWM_BUS_DIVERSE            (0x00000200UL)

/**
* @brief   Bus select: counter bus[F]
*/
#define PWM_BUS_F                  (0x00000400UL)

/**
* @brief   Bus select: internal counter
*/
#define PWM_BUS_INTERNAL_COUNTER   (0x00000600UL)
/**
* @brief   Bus select mask
*/
#define PWM_BUS_MASK               (0x00000600UL)
/**
* @brief   Initialization option to set the channel prescaler value to 1
*/
#define PWM_PRES_1                 (0x00000000UL)
/**
* @brief   Initialization option to set the channel prescaler value to 2
*/
#define PWM_PRES_2                 (0x04000000UL)
/**
* @brief   Initialization option to set the channel prescaler value to 3
*/
#define PWM_PRES_3                 (0x08000000UL)
/**
* @brief   Initialization option to set the channel prescaler value to 4
*/
#define PWM_PRES_4                 (0x0C000000UL)
/**
* @brief   Initialization option to enable freeze mode for the channel
*/
#define PWM_FREEZE_ENABLE          (0x80000000UL)
/**
* @brief   Channel 24 index
*/
#define PWM_EMIOS_CH_24            (24UL)


/*===============================================================================================
                                             ENUMS
===============================================================================================*/


/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/**
* @brief   EMIOS HW channel id type, make sure it is the same type as Pwm_ChannelType
* @implements DPWM04103
*/
typedef uint8 Pwm_HwChannelType;


/**
* @brief   eMIOS unified channel control register value
* @implements DPWM04102
*/
typedef uint32 Pwm_EmiosCtrlParamType;


#ifdef PWM_EMIOS_16_BITS_VARIANT
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)
/**
* @brief Unsigned long long integer at least 64 bit long.
* (0x00000000..0xFFFFFFFFFFFFFFFF) - 64 bit
*/
typedef unsigned long long Pwm_uint64;

/**
* @brief long long integer at least 64 bit long.
* (0x00000000..0xFFFFFFFFFFFFFFFF) - 64 bit
*/
typedef long long Pwm_sint64;
#endif
#endif


/**
* @brief EMIOS IP specific channel configuration structure for the PWM functionality
* @implements DPWM04101
*/
typedef struct
{
    CONST(Pwm_HwChannelType, PWM_CONST) Pwm_HwChannelID;/**< @brief eMIOS HW channel id */
    CONST(uint32,      PWM_CONST)               Pwm_Emios_ModuleAddr; /**< @brief Emios module address value*/
    CONST(uint32,      PWM_CONST)               Pwm_Emios_ChannelAddr; /**< @brief Emios channel address value*/
    CONST(Pwm_EmiosCtrlParamType, PWM_CONST) Pwm_ParamValue;/**< @brief EMIOSC[n] control */
#if (PWM_DUAL_CLOCK_MODE == STD_ON)
    CONST(uint32, PWM_CONST) Pwm_Prescaler_Alternate;/**< @brief prescaler value */
#endif
    CONST(Pwm_PeriodType, PWM_CONST) Pwm_Offset;/**< @brief leading edge of the output pulse */

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
    CONST(Pwm_PeriodType, PWM_CONST) Pwm_TriggerDelay;/**< @brief delay of trigger generation */
    #endif
#endif
    CONST(boolean, PWM_CONST) Pwm_OffsetTriggerDelayAdjust;/**< @brief delay of trigger delay adjust */
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)    
    CONST(uint16, PWM_CONST) Pwm_DeadTime;/**< @brief deadtime value */
    #endif
#endif 
} Pwm_EMIOS_ChannelConfigType;



/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* PWM_EMIOS_LLD_CfgEx_H */

/** @} */
