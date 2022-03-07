/**
*   @file    Pwm_eMIOS_LLD.c
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

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_eMIOS_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                                       before "#include"
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_eMIOS_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion of integer to smaller type
*
* @section Pwm_eMIOS_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 10.1, Prohibited Implicit Conversion:
*                                        Non-constant argument to function
*
* @section Pwm_eMIOS_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
*
* @section Pwm_eMIOS_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 14.6, This violation is not fixed since it is required for our
* implementation.
*
* @section Pwm_eMIOS_LLD_C_REF_6
* Violates MISRA 2004 Required Rule 10.3, This violation is due to the use of unsigned long long
* instead of uint32 data type. This violation is not fixed since two32bit variable multiplication is
* performed to calculate PWM offset value, which will yield 64 bit value.
*
* @section Pwm_eMIOS_LLD_C_REF_7
* Violates MISRA 2004 Required Rule 11.1, This violation is due to casting unsigned long to pointer
* and access these address for updating contents in that address.
*
* @section Pwm_eMIOS_LLD_C_REF_8
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents of a
* header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section Pwm_eMIOS_LLD_C_REF_10
* Violates MISRA 2004 Advisory Rule 11.4, : cast from pointer to pointer
* To typecast the pointer from one data type to other data type
*
* @section Pwm_eMIOS_LLD_C_REF_11
* Violates MISRA 2004 Required Rule 17.4, : This violation is due to the use of pointer arithmetic,
* which is used for the speed optimization, the indexing of the pointer is taken care and hence the
* unintended memory location will not be accessed.
*
* @section Pwm_eMIOS_LLD_C_REF_12
* Violates MISRA 2004 Required Rule 8.10, external  could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Pwm_eMIOS_LLD_C_REF_13
* Violates MISRA 2004 Required Rule 12.4, The right hand operand of a logical && or || operator shall not
* contain side effects.
*
*@section Pwm_eMIOS_LLD_C_REF_14
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
* @section Pwm_eMIOS_LLD_C_REF_15
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be
* permitted.
*
* @section Pwm_eMIOS_LLD_C_REF_16
* Violates MISRA 2004 Required Rule 13.1, Assignment operators shall not be used in expressions that 
* yield a Boolean value.
*
* @section Pwm_eMIOS_LLD_C_REF_17
* Violates MISRA 2004 Required Rule 10.5, If the bitwise operators ~ and << are applied to an operand
* of underlying type unsigned char or unsigned short, the result shall be immediately cast to the
* underlying type of the operand.
*
* @section Pwm_eMIOS_LLD_C_REF_18
* Violates MISRA 2004 Required Rule 9.1, All automatic variables shall have been assigned a value
* before being used.
*
* @section Pwm_eMIOS_LLD_C_REF_19
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function.
*
* @section Pwm_eMIOS_LLD_C_REF_20
* Violates MISRA 2004 Required Rule 14.10, All if ... else if constructs shall be terminated with an
* else clause.
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Pwm.h"
#if ((PWM_SET_TRIGGER_DELAY_API == STD_ON) && (PWM_DEV_ERROR_DETECT == STD_ON))
#include "Pwm_NonASR.h"
#endif

#include "Pwm_eMIOS_LLD.h"

/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */

#include "Pwm_eMIOS_LLD_CfgEx.h"

#include "Reg_eSys_eMIOS.h"
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "Reg_eSys_eMIOS_CfgEx.h"
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "Mcal.h"

#include "SchM_Pwm.h"
#if (PWM_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "Dem.h"
#endif

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*===============================================================================================
*                                        LOCAL MACROS
===============================================================================================*/
/**
* @{
* @brief Parameters that shall be published within the Pwm driver header file and also in the
*       module's description file
*/
#define PWM_EMIOS_LLD_C_VENDOR_ID         43
/* @violates @ref Pwm_eMIOS_LLD_C_REF_9 Identifier clash */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION       4
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION       0
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION    3
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_EMIOS_LLD_C_SW_MAJOR_VERSION               1
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_EMIOS_LLD_C_SW_MINOR_VERSION               0
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_EMIOS_LLD_C_SW_PATCH_VERSION               1

/**@}*/
/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if source file and PWM header file are of the same vendor */
#if (PWM_EMIOS_LLD_C_VENDOR_ID != PWM_VENDOR_ID)
    #error "Pwm_eMIOS_LLD.c and Pwm.h have different vendor ids"
#endif


/* Check if source file and PWM header file are of the same Autosar version */
#if ((PWM_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != PWM_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != PWM_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS_LLD.c and Pwm.h are different"
#endif


/* Check if source file and PWM header file are of the same software version */
#if ((PWM_EMIOS_LLD_C_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
        (PWM_EMIOS_LLD_C_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMIOS_LLD.c and Pwm.h are different"
#endif


/* Check if source file and Pwm_eMIOS_LLD_IRQ.h are of the same vendor */
#if (PWM_EMIOS_LLD_C_VENDOR_ID != PWM_EMIOS_LLD_H_VENDOR_ID)
    #error "Pwm_eMIOS_LLD.c and Pwm_eMIOS_LLD.h have different vendor ids"
#endif


/* Check if source file and Pwm_eMIOS_LLD_IRQ.h are of the same Autosar version */
#if ((PWM_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != PWM_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS_LLD.c and Pwm_eMIOS_LLD.h are different"
#endif


/* Check if source file and Pwm_eMIOS_LLD_IRQ.h are of the same software version */
#if ((PWM_EMIOS_LLD_C_SW_MAJOR_VERSION != PWM_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_SW_MINOR_VERSION != PWM_EMIOS_LLD_H_SW_MINOR_VERSION) || \
        (PWM_EMIOS_LLD_C_SW_PATCH_VERSION != PWM_EMIOS_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMIOS_LLD.c and Pwm_eMIOS_LLD.h are different"
#endif


/* Check if source file and Pwm_eMIOS_LLD_CfgEx.h are of the same vendor */
#if (PWM_EMIOS_LLD_C_VENDOR_ID != PWM_EMIOS_LLD_CFGEX_H_VENDOR_ID)
    #error "Pwm_eMIOS_LLD.c and Pwm_eMIOS_LLD_CfgEx.h have different vendor ids"
#endif


/* Check if source file and Pwm_eMIOS_LLD_CfgEx.h are of the same Autosar version */

#if ((PWM_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != PWM_EMIOS_LLD_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS_LLD.c and Pwm_eMIOS_LLD_CfgEx.h are different"
#endif


/* Check if source file and Pwm_eMIOS_LLD_CfgEx.h are of the same software version */
#if ((PWM_EMIOS_LLD_C_SW_MAJOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_SW_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_SW_MINOR_VERSION != PWM_EMIOS_LLD_CFGEX_H_SW_MINOR_VERSION)  || \
        (PWM_EMIOS_LLD_C_SW_PATCH_VERSION != PWM_EMIOS_LLD_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMIOS_LLD.c and Pwm_eMIOS_LLD_CfgEx.h are different"
#endif


/* Check if source file and Reg_eSys_eMIOS.h are of the same vendor */
#if (PWM_EMIOS_LLD_C_VENDOR_ID != REG_ESYS_EMIOS_H_VENDOR_ID)
    #error "Pwm_eMIOS_LLD.c and Reg_eSys_eMIOS.h have different vendor ids"
#endif


/* Check if source file and Reg_ESYS_EMIOS_PWM.h are of the same Autosar version */
#if ((PWM_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS_LLD.c and Reg_eSys_eMIOS.h are different"
#endif


/* Check if source file and Reg_eSys_eMIOS.h are of the same software version */
#if ((PWM_EMIOS_LLD_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_H_SW_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_H_SW_MINOR_VERSION)  || \
        (PWM_EMIOS_LLD_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMIOS_LLD.c and Reg_eSys_eMIOS.h are different"
#endif


/* Check if source file and Reg_eSys_EMIOS_CfgEx.h are of the same vendor */
#if (PWM_EMIOS_LLD_C_VENDOR_ID != REG_ESYS_EMIOS_CFGEX_H_VENDOR_ID)
    #error "Pwm_eMIOS_LLD.c and Reg_eSys_eMIOS_CfgEx.h have different vendor ids"
#endif

/* Check if source file and header file are of the same Autosar version */
#if ((PWM_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS_LLD.c and Reg_eSys_eMIOS_CfgEx.h differe"
#endif


/* Check if source file and header file are of the same Software version */
#if ((PWM_EMIOS_LLD_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MAJOR_VERSION)  || \
        (PWM_EMIOS_LLD_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MINOR_VERSION)  || \
        (PWM_EMIOS_LLD_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMIOS_LLD.c and Reg_eSys_eMIOS_CfgEx.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

/* Check if source file and DET header file are of the same version */
#if (PWM_DEV_ERROR_DETECT == STD_ON)
    #if ((PWM_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
            (PWM_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pwm_eMIOS_LLD.c and Det.h are different"
    #endif
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL CONSTANTS
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/

#define PWM_START_SEC_VAR_NO_INIT_8
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief array used to store the notification status (enabled/disabled) and type
* @details  status and type of notification if enabled for each channel indexed using the hardware channel ID
*               \n PWM_RISING_EDGE,
*               \n PWM_FALLING_EDGE,
*               \n PWM_BOTH_EDGES,
*               \n 0xFF for disabled
* @implements DPWM04406
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static */
    VAR(uint8, PWM_VAR)  Pwm_eMIOS_LLD_Notifications[ PWM_MAX_CHANNELS ];
#endif /* PWM_NOTIFICATION_SUPPORTED */


#define PWM_STOP_SEC_VAR_NO_INIT_8
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

/**
* @brief   pointer to the top level configuration structure used by the EMIOS implementation
* @implements DPWM04404
*/
/*
* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static
*/
P2CONST(Pwm_ConfigType, PWM_VAR, PWM_APPL_CONST) Pwm_eMIOS_Cfg = NULL_PTR;

/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

/**
* @brief   array used to store the current period for each pwm channel, indexed using the hw channel id
* @implements DPWM04407
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_19 the define cannot be moved inside the block scope */
VAR(Pwm_PeriodType, PWM_VAR) Pwm_eMIOS_LLD_Period[ PWM_MAX_CHANNELS ];

#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static */
    VAR(Pwm_PeriodType, PWM_VAR) Pwm_DAOC_LLD_Duty[ PWM_MAX_CHANNELS ];
    #endif
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief    array used for reverse translation between Hw channel and Logical channel
*           used to call the logical channel notification in the hw channel ISR
* @implements DPWM04408
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static */

VAR(Pwm_ChannelType, PWM_VAR)  Pwm_eMIOS_LLD_RevHardwareTable[ PWM_EMIOS_HW_CHANNELS ];
#endif /* PWM_NOTIFICATION_SUPPORTED */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

#define PWM_START_SEC_VAR_NO_INIT_32
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief   array used to store the current dutycycle state
* details  allowable parameters are:
*           \n 1 - dutycycle != 0%, 100% - signal toggling
*           \n 0 - dutycycle == 0%, 100% - signal is stable state - no transition available
* @implements DPWM04405
*/
/*
* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static
*/
VAR(uint32, PWM_VAR)  Pwm_eMIOS_LLD_DutyState[ PWM_EMIOS_MODULES_CFG ];
#endif /* PWM_NOTIFICATION_SUPPORTED */


#define PWM_STOP_SEC_VAR_NO_INIT_32
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

#define PWM_START_SEC_VAR_NO_INIT_16
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
/**
    @brief   array used to store the current period for each pwm channel for updating the register A in DAOC mode, indexed using
             the logical channel id
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static */
    VAR(uint16, PWM_VAR) Pwm_DAOC_LLD_Period[ PWM_MAX_CHANNELS ];
    #endif
#endif

#if (PWM_GET_CHANNEL_STATE == STD_ON)
/**
* @brief Array of the duty value of the EMIOS_PWM channels used for storing  Duty Cycle 
*/
STATIC VAR(uint16, PWM_VAR) Pwm_eMIOS_Duty_Cycle_Value[PWM_MAX_CHANNELS];
#endif /*(PWM_GET_CHANNEL_STATE )*/

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)

/**
* @brief   array used to store the current Trigger delay value
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external  could be made static */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_19 the define cannot be moved inside the block scope */
VAR(uint16, PWM_VAR) Pwm_Current_TriggerDelay[PWM_MAX_CHANNELS];

   #endif
#endif  /*PWM_FEATURE_OPWMT*/

#define PWM_STOP_SEC_VAR_NO_INIT_16
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/

LOCAL_INLINE FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_UpdateChannel_AB(
                                        VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                        VAR(uint32, AUTOMATIC) valA,
                                        VAR(uint32, AUTOMATIC) valB,
                                        VAR(uint32, AUTOMATIC) ChannelAddr,
                                        VAR(uint32, AUTOMATIC) ModuleAddr
    );
/*================================================================================================*/

#ifdef PWM_FEATURE_OPWMT
  #if (PWM_FEATURE_OPWMT == STD_ON)
LOCAL_INLINE FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_UpdateChannel_B(
                                        VAR(uint32, AUTOMATIC) valB,
                                        VAR(uint32, AUTOMATIC) ChannelAddr
#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)
                                        ,VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                        VAR(uint32, AUTOMATIC) ModuleAddr
#endif
#endif
    );
  #endif
#endif /*PWM_FEATURE_OPWMT*/
/*================================================================================================*/

/**
* @brief   Function to return the channel id of master bus of current channel
* @details Function to return the channel id of master bus of current channel
* @param[in] mIdx  - the index of module
* @param[in] chIdx - the index of unified channel
* @param[in] Bus - the bus selected by this unified channel
* @param[out] - The id of master bus

*/
LOCAL_INLINE FUNC (Pwm_ChannelType, PWM_CODE) Pwm_eMIOS_LLD_GetMasterBus(
                                 VAR(Pwm_ChannelType, AUTOMATIC) mIdx,
                                 VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                 VAR(uint32, AUTOMATIC) Bus
     );
/*================================================================================================*/

LOCAL_INLINE FUNC (Pwm_PeriodType, PWM_CODE) Pwm_eMIOS_LLD_ComputeDutycycle(
        VAR(Pwm_PeriodType, AUTOMATIC) Period,
        VAR(uint16,AUTOMATIC) Duty
    );

/*================================================================================================*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
static FUNC (Pwm_PeriodType, PWM_CODE) Pwm_eMIOS_LLD_GetCounterBusPeriod(
                                           VAR(Pwm_ChannelType, AUTOMATIC) mIdx,
                                           VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                           VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) Bus
    );

/*================================================================================================*/
#ifdef PWM_EMIOS_16_BITS_VARIANT
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)
/**
@brief   Function to get the division of 64 bit unsigned integers.
@details This function returns the division value of 64 bit unsigned integers.
@param[in] j - Numerator
@param[in] k - Denominator
@return pwm_uint64 - division value of 64 bit unsigned integers.
*/

STATIC FUNC(Pwm_uint64, PWM_CODE)Pwm_div64(Pwm_uint64 j, Pwm_uint64 k);
#endif
#endif

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/
#define PWM_START_SEC_CODE
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

/**
* @brief   Function to update the A and B registers in a critical section
* @details This function disable the transfer, updates the register A
*          and register B and enables the transfer
* @param[in] chIdx - the index of unified channel
* @param[in] valA - The eMIOS Reg A value to be updated
* @param[in] valB - The eMIOS Reg B value to be updated
* @param[in] ChannelAddr - address of unified channel
* @param[in] ModuleAddr - eMIOS module address
* @api
* @implements DPWM04412
*/

/* Compiler_Warning : This warning is thrown due to chIdx and ModuleAddr variables are not used when MULTI_PWM_CHANNEL_SYNCH = STD_ON */   
LOCAL_INLINE FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_UpdateChannel_AB(
                                        VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                        VAR(uint32, AUTOMATIC) valA,
                                        VAR(uint32, AUTOMATIC) valB,
                                        VAR(uint32, AUTOMATIC) ChannelAddr,
                                        VAR(uint32, AUTOMATIC) ModuleAddr
    )
{
#ifdef MULTI_PWM_CHANNEL_SYNCH 
#if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)     
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_BIT_SET32(   (ModuleAddr+EMIOS_OUDR_OFFSET), (uint32)((uint32)1<<(chIdx)) );
#endif
#endif    
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(   (ChannelAddr + EMIOS_CADR_OFFSET), (valA) );
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(   (ChannelAddr + EMIOS_CBDR_OFFSET), (valB) );
#ifdef MULTI_PWM_CHANNEL_SYNCH 
#if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)   
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_BIT_CLEAR32( (ModuleAddr+EMIOS_OUDR_OFFSET), (uint32)((uint32)1<<(chIdx)) );
#endif
#endif    
}

#ifdef PWM_FEATURE_OPWMT
  #if (PWM_FEATURE_OPWMT == STD_ON)
/**
* @brief   Function to update the B registers in a critical section
* @details This function disable the transfer, updates  register B
* @and enables the transfer
* @param[in] chIdx - the index of unified channel
* @param[in] valB - The eMIOS Reg B value to be updated
* @param[in] ChannelAddr - address of unified channel
* @param[in] ModuleAddr - eMIOS module address
* @api
* @implements DPWM04415
*/
LOCAL_INLINE FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_UpdateChannel_B(
                                        VAR(uint32, AUTOMATIC) valB,
                                        VAR(uint32, AUTOMATIC) ChannelAddr
#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)
                                        ,VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                        VAR(uint32, AUTOMATIC) ModuleAddr
#endif
#endif                                        
    )
{
#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_BIT_SET32(   (ModuleAddr+EMIOS_OUDR_OFFSET), (uint32)((uint32)1<<(chIdx)) );
#endif
#endif
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(   (ChannelAddr + EMIOS_CBDR_OFFSET), (valB) );
#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_BIT_CLEAR32( (ModuleAddr+EMIOS_OUDR_OFFSET), (uint32)((uint32)1<<(chIdx)) );
#endif
#endif
}
  #endif
#endif /*PWM_FEATURE_OPWMT*/

/*================================================================================================*/
/**
* @brief   Function to return the channel id of master bus of current channel
* @details Function to return the channel id of master bus of current channel
* @param[in] mIdx  - the index of module
* @param[in] chIdx - the index of unified channel
* @param[in] Bus - the bus selected by this unified channel
* @param[out] - The id of master bus

*/
LOCAL_INLINE FUNC (Pwm_ChannelType, PWM_CODE) Pwm_eMIOS_LLD_GetMasterBus(
                                 VAR(Pwm_ChannelType, AUTOMATIC) mIdx,
                                 VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                 VAR(uint32, AUTOMATIC) Bus
     )
{
    VAR(Pwm_ChannelType, AUTOMATIC) mMasterBusIdx=(Pwm_ChannelType)0;
    if (PWM_BUS_DIVERSE == Bus)
    {
        if (EMIOS_CHANNEL_7 >= chIdx) /* bus B */
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_17 the bitwise operators are applied to an operand */
            mMasterBusIdx = (Pwm_ChannelType)((mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0);
        }
        else if (EMIOS_CHANNEL_15 >= chIdx) /* Bus C */
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_17 the bitwise operators are applied to an operand */
            mMasterBusIdx = (Pwm_ChannelType)((mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8);
        }
        else if (EMIOS_CHANNEL_23 >= chIdx) /* bus D */
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_17 the bitwise operators are applied to an operand */
            mMasterBusIdx = (Pwm_ChannelType)((mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16);
        }
        else /* Bus E remaining */
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_17 the bitwise operators are applied to an operand */
            mMasterBusIdx = (Pwm_ChannelType)((mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24);
        }
    }
    else if (PWM_BUS_A == Bus) /* bus A */
    {
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_17 the bitwise operators are applied to an operand */
        mMasterBusIdx = (Pwm_ChannelType)((mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23);
    } 
    else if (PWM_BUS_F == Bus) /* bus F remaining */
    {
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_17 the bitwise operators are applied to an operand */
        mMasterBusIdx = (Pwm_ChannelType)((mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22);
    }
    else
    {
        /*Empty else to fix misra*/
    }
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_18 all automatic variables shall assign a value before use */
    return mMasterBusIdx;
}

/*================================================================================================*/
/**
* @brief   Function to compute the duty cycle
* @details This function computes the dutycycle value in ticks
* @param[in] Period - period of pulse
* @param[in] Duty - duty cycle of pulse
*
* @return  Pwm_PeriodType - the computed dutycycle value in ticks
*        - uint16 - 16bit EMIOS return value
*        - uint32 - 24bit EMIOS return value
* @api
* @implements DPWM04413
*/

LOCAL_INLINE FUNC (Pwm_PeriodType, PWM_CODE) Pwm_eMIOS_LLD_ComputeDutycycle(
        VAR(Pwm_PeriodType, AUTOMATIC) Period,
        VAR(uint16,AUTOMATIC) Duty
    )
{

    VAR(Pwm_PeriodType, AUTOMATIC) dutycycle; /* 16bit or 32bit variable */

#ifdef PWM_EMIOS_16_BITS_VARIANT
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    VAR(uint32, AUTOMATIC) Calc_rounding; /* 16bit or 32bit variable */
    /* 16bit EMIOS */
     if( Duty == (uint16)0x8000)
      {
        dutycycle = Period;


      }
      else
      {
          Calc_rounding = (uint32)((uint32)Period * (uint32)Duty);
          if((Calc_rounding & (uint32)0x40000000) == (uint32)0x40000000)
          {
           dutycycle = (Pwm_PeriodType)((uint32)(Calc_rounding>>(Pwm_PeriodType)15)+(Pwm_PeriodType)1);
          }
          else
          {
           dutycycle = (Pwm_PeriodType)((uint32)Calc_rounding>>(Pwm_PeriodType)15);
          }
      }


 #else

    /* 24bit EMIOS */

    VAR(uint8, AUTOMATIC)   period_high;
    VAR(uint16, AUTOMATIC)  period_low;

    period_high = (uint8)(Period >> 16); /* get the 8bit  MS byte of 24-bit value
                                             stored on uint32 */
    period_low  = (uint16)Period;        /* get the 16bit LS word of 24-bit value
                                             stored on uint32 */


    dutycycle = (uint32)((uint32)((uint32)period_high * (uint32)Duty) << 1) +
                (uint32)((uint32)((uint32)period_low  * (uint32)Duty) >> 15);

 #endif

#else

 #error "Unknown EMIOS type, PWM_EMIOS_16_BITS_VARIANT is undefined";

#endif

    return dutycycle;

}


/*===============================================================================================*/
/**
* @brief   Function to get the period of PWM channel
* @details This function returns the channel period depending on the selected
*          counter bus - BusA / Bus Diverse
* @param[in] mIdx - eMIOS module index
* @param[in] chIdx - the index of unified channel
* @param[in] Bus - the bus selected by this unified channel
* @return Pwm_PeriodType - the period of the selected counter bus
*         - uint16 - 16bit EMIOS return value
*         - uint32 - 24bit EMIOS return value
* @api
* @implements DPWM04414
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
static FUNC (Pwm_PeriodType, PWM_CODE) Pwm_eMIOS_LLD_GetCounterBusPeriod(
                                           VAR(Pwm_ChannelType, AUTOMATIC) mIdx,
                                           VAR(Pwm_ChannelType, AUTOMATIC) chIdx,
                                           VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) Bus
    )
{

    VAR(Pwm_PeriodType,  AUTOMATIC)  Period = (Pwm_PeriodType)0;
    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;
    VAR(Pwm_ChannelType, AUTOMATIC) mMasterBusIdx;

    mMasterBusIdx = Pwm_eMIOS_LLD_GetMasterBus(mIdx, chIdx, (uint32)Bus & PWM_BUS_MASK);
    
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
    ctrlRegVal = (Pwm_EmiosCtrlParamType)REG_READ32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)));

    if((CCR_MODE_MCB_INT_CLOCK == (ctrlRegVal & CCR_MODE_MASK)) || 
       (CCR_MODE_MCB_FLAG_A_INT_CLOCK == (ctrlRegVal & CCR_MODE_MASK)))
    {
        /* bus B source : MCB reference - period in A register */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
        Period = (Pwm_PeriodType)REG_READ32(EMIOS_CADR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)));
    }
    else
    {
        /* bus B source : OPWFMB reference - period in B register */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
        Period = (Pwm_PeriodType)REG_READ32(EMIOS_CBDR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)));
    }
    return Period;
}

/*===============================================================================================*/
#ifdef PWM_EMIOS_16_BITS_VARIANT
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)
/**
@brief   Function to get the division of 64 bit unsigned integers.
@details This function returns the division value of 64 bit unsigned integers.
@param[in] j - Numerator
@param[in] k - Denominator
@return pwm_uint64 - division value of 64 bit unsigned integers.
*/

STATIC FUNC(Pwm_uint64, PWM_CODE)Pwm_div64(Pwm_uint64 j, Pwm_uint64 k)
{
    Pwm_uint64 i, m;
    Pwm_uint64 n;
    uint32 c;
    
    if (k == 0ULL) 
    {
        n = ~(Pwm_uint64)0ULL;
    }
    else
    {
        if (((k-1ULL) & k) == 0ULL) {
        /* Divide by power of 2. */
        n = j;
        if((k & 0x00000000ffffffffULL) == 0ULL) {
            k >>= 32U;
            n >>= 32U;
        }
        c = (uint32)k;
        if((c & 0xffffU) == 0U) {
            c >>= 16U;
            n >>= 16U;
        }
        if((c & 0xffU) == 0U) {
            c >>= 8U;
            n >>= 8U;
        }
        while ((c >>= 1U) != 0U) {
            n >>= 1U;
        }
        } 
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_16 Assignment operators shall not be used in expressions that 
        yield a Boolean value */
        else if(((m = j | k) & 0xffffffff00000000ULL) == 0ULL) {
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer
        expression to larger type */
            n = (Pwm_uint64)((uint32)j/(uint32)k);
        } else {
            i = 0xff00000000000000ULL;
            if ((m & i) == 0ULL) {
                i >>= 8U;
                if ((m & i) == 0ULL) {
                    i >>= 8U;
                    if ((m & i) == 0ULL) {
                        i >>= 8U;
                    }
                }
            }
            c = 0U;
            while ((k & i) == 0ULL) {
                k <<= 8U;
                c += 8U;
            }
            if(j & 0x8000000000000000ULL) {
                while ((k & 0x8000000000000000ULL) == 0ULL) {
                    k <<= 1U;
                    c++;
                }
                n = 0ULL;
                if (j >= k) {
                    j -= k;
                    n |= 1ULL;
                }
            } else {
                while (k <= j) {
                    k <<= 1U;
                    c++;
                }
                n = 0ULL;
            }
            while (c > 0U) {
                c--;
                k >>= 1U;
                n <<= 1U;
                if (j >= k) {
                    j -= k;
                    n |= 1ULL;
                }
            }
            c--;
        }

    }
    return n;
}
#endif
#endif

#define PWM_STOP_SEC_CODE
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"
/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
#define PWM_START_SEC_CODE
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"

/**
* @brief   Service for initializing the hardware timer module (low level)
* @details This function initializes all the configured hardware channels as per the
*         configured mode
*         - puts the channel in GPIO mode
*         - disables the interrupt corresponding to Emios channel
*         - ulear pending interrupt flag for the channel
*         - enables/disables the Freeze Mode
*         - clears the (pending) interrupt flag corresponding to Emios channel
*         - get the Period that the current UC is using and also calculates the dutycycle
*         - update registers A and B with the dutycycle and period value for the configured mode
*         - force a match on B register for OPWFMB mode
*         - force a match on A register for OPWMB and OPWMT modes
*         - write trigger delay to alternate A register for OPWMT mode and offset to A register
*           for OPWMB and OPWMT modes
*         - FLAG assigned to DMA request and FLAG event is enabled for OPWMT mode
*         - FLAG event is disabled for OPWMB and OPWFMB modes
*         - sets the prescaler value
*         - enable prescaler which will start the internal counter, for Counter Bus
*
*
* @param[in] ConfigPtr - pointer to PWM top configuration structure
*
* @api
*
* @implements   DPWM04012
*/

FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_Init(
        P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr
    )
{
    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;

    VAR(Pwm_PeriodType, AUTOMATIC)  Period = 1U;

    VAR(uint16, AUTOMATIC)  DutyCycle;
    VAR(Pwm_PeriodType, AUTOMATIC)  tempDuty = 0U;
    VAR(uint32, AUTOMATIC)  tempDuty32;

    /* hw channel */
    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch;

    /* logical channel */
    VAR(Pwm_ChannelType, AUTOMATIC) ch = (Pwm_ChannelType )0; /* logical channel */

    /* assigned eMIOS HW module  index */
    VAR(Pwm_ChannelType, AUTOMATIC) mIdx;

    /* assigned eMIOS HW channel index */
    VAR(Pwm_ChannelType, AUTOMATIC) chIdx;

    /* eMIOS module address */
    VAR(uint32, AUTOMATIC) ModuleAddr;

    /*address of unified channel*/
    VAR(uint32, AUTOMATIC) ChannelAddr;
    VAR(uint32, AUTOMATIC) polarity_bit = 0U;  /*status of polarity bit */
    
    VAR(uint8, AUTOMATIC) mMasterBusIdx = 0xFFU;
    VAR(uint8, AUTOMATIC) mMasterBusUse[PWM_EMIOS_HW_CHANNELS];
    VAR(Pwm_PeriodType, PWM_VAR) mMasterBusPeriod[ PWM_EMIOS_HW_CHANNELS ];
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
    VAR(uint32, AUTOMATIC) prescalar;    
    #endif
#endif
    /* copy the top level configuration pointer to EMIOS implementation */
    Pwm_eMIOS_Cfg = ConfigPtr;

    for (ch=0U; ch < (Pwm_ChannelType)PWM_MAX_CHANNELS; ch++)
    {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* notifications disabled */
        Pwm_eMIOS_LLD_Notifications[ ch ] = 0xFFU;
#endif
#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
        /*trigger delay*/
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_4 Implicit conversion changes signedness */
        Pwm_Current_TriggerDelay[ch] = (Pwm_PeriodType)0x00;
#endif
#endif
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
        /*DAOC duty */
         Pwm_DAOC_LLD_Duty[ch] = (uint16)0x00;
         /* @violates @ref Pwm_eMIOS_LLD_C_REF_4 Implicit conversion changes signedness */
         Pwm_DAOC_LLD_Period[ch] = (Pwm_PeriodType)0x00;
    #endif
#endif
         /*Set 0 for array used to store the current period for each pwm channel*/
        Pwm_eMIOS_LLD_Period[ch] = (Pwm_PeriodType)0x00 ;

    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    for (ch=0U; ch < (Pwm_ChannelType)PWM_MAX_CHANNELS; ch++)
    {
        /* invalidate the reverse hardware channel 2 logical channel map */
        Pwm_eMIOS_LLD_RevHardwareTable[ ch ] = (Pwm_ChannelType)0xFFU;
    }
    for(ch=0U; ch < PWM_EMIOS_MODULES_CFG; ch++)
    {
        /*Set 0 for array used to store the current dutycycle state*/
        Pwm_eMIOS_LLD_DutyState[ch] = (uint32)0;
    }
#endif
    
    for (ch=0U; ch < (Pwm_ChannelType)PWM_EMIOS_HW_CHANNELS; ch++)
    {
        mMasterBusUse[ch] = (uint8)0xFFU;
        mMasterBusPeriod[ch] = (Pwm_PeriodType)0x00U;
    }
    /* Reset registers of the configured channels before using them */
    for (ch=0U; ch < Pwm_eMIOS_Cfg->ChannelCount; ch++)
    {
      #if (PWM_GET_CHANNEL_STATE == STD_ON)
        Pwm_eMIOS_Duty_Cycle_Value[ch] = 0U;
#endif /*PWM_GET_CHANNEL_STATE */    
        /* only handle EMIOS channels */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    if (PWM_EMIOS_CHANNEL == Pwm_eMIOS_Cfg->ChannelsPtr[ch].IpType)
        {

            /* extract from conf structure the generic channel information */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
            PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ch];
            /* extract from conf structure the EMIOS specific channel information */
            PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;

            ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;
            ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;
            /* store the associated hw channel ID */
            hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;
            mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);
            chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);

            /* save current channel control register config value in local variable */
            ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;

            /* set the channel output to the configured Idle state */
            if (PWM_HIGH == PwmChannel->Pwm_IdleState)
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );
            }
            else
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );
            }
        
            /* reset A,B regs 0 */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CADR_OFFSET ) , 0U );

            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CBDR_OFFSET ) , 0U );
        
            /* enter GPIO ouput mode - this will set the ouput pin to the EDPOL value */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_MODE_MASK, CCR_MODE_GPO );

            /* Reset Timer control register - except mode and edpol to keep channel
            *  in output idle mode 
            *  Internal Counter is also cleared when entering GPIO Mode */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), (~(CCR_EDPOL_MASK | CCR_MODE_MASK)) );

            /* disable interrupt */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

            /* clear interrupt flag */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );

            /* only write UCDIS register if it's available */
    #ifdef EMIOS_UCDIS
            /* disable unified channel */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( (ModuleAddr+EMIOS_UCDIS_OFFSET), (uint32)((uint32)1<<(chIdx)) );
    #endif /* EMIOS_UCDIS */
            
            if (PWM_BUS_INTERNAL_COUNTER != ((uint32)ctrlRegVal & PWM_BUS_MASK))
            {
                mMasterBusIdx = Pwm_eMIOS_LLD_GetMasterBus(mIdx, chIdx, ((uint32)ctrlRegVal & PWM_BUS_MASK));

                if(mMasterBusUse[mMasterBusIdx] == (uint8)0xFFU) /* This master bus is not use */
                {
                  mMasterBusUse[mMasterBusIdx] = (uint8)1U;
                  /* reset A,B regs 0 */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                  REG_WRITE32( EMIOS_CADR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), 0U );

                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                  REG_WRITE32( EMIOS_CBDR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), 0U );
                  
                  /* enter GPIO ouput mode - this will set the ouput pin to the EDPOL value */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                  REG_RMW32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_MODE_MASK, CCR_MODE_GPO );

                  /* Reset Timer control register - except mode and edpol to keep channel
                  *  in output idle mode
                  *  Internal Counter is also cleared when entering GPIO Mode */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                  REG_BIT_CLEAR32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), (~(CCR_EDPOL_MASK | CCR_MODE_MASK)));

                  /* disable interrupt */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                  REG_BIT_CLEAR32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_FEN_MASK);

                  /* clear interrupt flag */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                  REG_WRITE32(EMIOS_CSR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CSR_FLAG_BIT );

                  /* only write UCDIS register if it's available */
              #ifdef EMIOS_UCDIS
                  /* disable unified channel */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                  REG_BIT_SET32( (ModuleAddr+EMIOS_UCDIS_OFFSET), (uint32)((uint32)1<<(EMIOS_CHANNEL_INDEX(mMasterBusIdx))) );
              #endif /* EMIOS_UCDIS */
                }
            }

        } /* end if emios channel */
    } /* end for */

    /* Initialize registers of the configured channels */
    for (ch=0U; ch < (Pwm_ChannelType)PWM_EMIOS_HW_CHANNELS; ch++)
    {
        mMasterBusUse[ch] = (uint8)0xFFU;
    }
    
    for (ch=0U; ch < Pwm_eMIOS_Cfg->ChannelCount; ch++)
    {
        /* Extract from conf structure the generic channel information */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
        PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ch];

        /* extract from conf structure the EMIOS specific channel information */
        PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;
        /*eMIOS module address*/
        ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;
        /*eMIOS channel address*/
        ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;
        /*hardware channel number*/
        hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;

        mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);
        chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);
        
        /* save current channel control register config value in local variable */
        ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;
        
        if ( (EMIOS_CHANNEL_0  == chIdx) || (EMIOS_CHANNEL_8  == chIdx) || (EMIOS_CHANNEL_16 == chIdx) ||
             (EMIOS_CHANNEL_22 == chIdx) || (EMIOS_CHANNEL_23 == chIdx) || (EMIOS_CHANNEL_24 == chIdx))
        {
            if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
            {
                mMasterBusUse[hw_ch] = (uint8)5U;
                mMasterBusPeriod[hw_ch] = PwmChannel->Pwm_DefaultPeriodValue;
                Pwm_eMIOS_LLD_Period[ch] = PwmChannel->Pwm_DefaultPeriodValue;
            }
        }
    }
    
    for (ch=0U; ch < Pwm_eMIOS_Cfg->ChannelCount; ch++)  {
        /* only handle EMIOS channels */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
        if (PWM_EMIOS_CHANNEL == Pwm_eMIOS_Cfg->ChannelsPtr[ch].IpType)
        {
            /* Extract from conf structure the generic channel information */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
            PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ch];

            /* extract from conf structure the EMIOS specific channel information */
            PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;
            /*eMIOS module address*/
            ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;
            /*eMIOS channel address*/
            ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;
            /*hardware channel number*/
            hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;

            mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);
            chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /* add hw2logical translation  */
            Pwm_eMIOS_LLD_RevHardwareTable[ hw_ch ] = ch;
#endif /* PWM_NOTIFICATION_SUPPORTED */

            /* save current channel control register config value in local variable */
            ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;

            mMasterBusIdx = Pwm_eMIOS_LLD_GetMasterBus(mIdx, chIdx, 
                                                        ((uint32)ctrlRegVal & PWM_BUS_MASK));
            /* only write UCDIS register if it's available */
#ifdef EMIOS_UCDIS
            /* enable unified channel to make registers writable */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ModuleAddr+EMIOS_UCDIS_OFFSET), (uint32)((uint32)1<<(chIdx)) );
#endif /* EMIOS_UCDIS */

            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32((ChannelAddr + EMIOS_CCR_OFFSET), CCR_FREN_MASK, CCR_FREN_MASK & ctrlRegVal);

            /* before entering GPIO mode set the EDPOL bit to the configured IDLE value */
            if (PWM_HIGH == PwmChannel->Pwm_IdleState)  {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );
            }
            else {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );
            }

            /* Enter GPIO output mode */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_MODE_MASK, CCR_MODE_GPO );

            /* Disable channel interrupts  */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

            /* Clear pending interrupt flag for the channel  */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );

            /* get the Period that the current UC is using */
            if (PWM_BUS_INTERNAL_COUNTER == ((uint32)ctrlRegVal & PWM_BUS_MASK))
            {
                /* internal counter - period from configuration */
                /* increment with 1 as counter always starts at 1 */
                Pwm_eMIOS_LLD_Period[ch] = PwmChannel->Pwm_DefaultPeriodValue;

                /* This will stop the internal counterl  */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_UCPREN_MASK );

                /* Set internal counter */
                #ifdef PWM_FEATURE_DAOC
                    #if (PWM_FEATURE_DAOC == STD_ON)
                if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)){
                   /* set internal counter to 0 */
                   /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_WRITE32( ChannelAddr + EMIOS_CCNTR_OFFSET, 0);
                } else
                {
                    #endif
                #endif/*PWM_FEATURE_DAOC*/
                /* set internal counter to 1 */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( (ChannelAddr + EMIOS_CCNTR_OFFSET), 1);
                #ifdef PWM_FEATURE_DAOC
                    #if (PWM_FEATURE_DAOC == STD_ON)
                }
                    #endif
                #endif/*PWM_FEATURE_DAOC*/
                /* Select internal counter bus */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_BSL_MASK );
                #ifdef PWM_FEATURE_DAOC
                    #if (PWM_FEATURE_DAOC == STD_ON)

                    if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {

                        Pwm_DAOC_LLD_Period[ch] = PWM_DAOC_COUNTER;
                    }
                    #endif
                #endif /*PWM_FEATURE_DAOC*/
            }
            else /* Bus A or Bus Diverse */
            {
                if(mMasterBusUse[mMasterBusIdx] == (uint8)0xFFU) /* This master bus is not use */
                {
                /* only write UCDIS register if it's available */
                #ifdef EMIOS_UCDIS
                    /* enable unified channel */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_CLEAR32((ModuleAddr+EMIOS_UCDIS_OFFSET), (uint32)((uint32)1<<(EMIOS_CHANNEL_INDEX(mMasterBusIdx))) );
                #endif /* EMIOS_UCDIS */
        
            #ifdef PWM_FEATURE_OPWMCB
                #if (PWM_FEATURE_OPWMCB == STD_ON)
                    if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) ||
                      (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
                    {
                      /* Now, this master bus is use for OPWMMCB mode */
                        mMasterBusUse[mMasterBusIdx] = (uint8)1U;
                      /* internal counter - period from configuration */
                      /*divide by 2 and increment with 1 as counter always starts at 1 */
                        mMasterBusPeriod[mMasterBusIdx] = (((PwmChannel->Pwm_DefaultPeriodValue)/(Pwm_PeriodType)2U) +
                                        (Pwm_PeriodType)(1U));
                    }
                    else
                #endif
            #endif
                    if ((CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) ||
                           (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK)))
                    {
                      /* Now, this master bus is use for OPWMB or OPWMT mode */
                        mMasterBusUse[mMasterBusIdx] = (uint8)2U;
                      /* internal counter - period from configuration */
                      /*divide by 2 and increment with 1 as counter always starts at 1 */
                        mMasterBusPeriod[mMasterBusIdx] = PwmChannel->Pwm_DefaultPeriodValue;
                    }
            #ifdef PWM_FEATURE_DAOC
                #if  (PWM_FEATURE_DAOC == STD_ON)
                    else if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
                    {
                        /* Now, this master bus is use for DAOC mode, so the period is counter modulo */
                        mMasterBusUse[mMasterBusIdx] = (uint8)3U;
                        /* internal counter - period from configuration */
                        /*divide by 2 and increment with 1 as counter always starts at 1 */
                        mMasterBusPeriod[mMasterBusIdx] = PWM_DAOC_COUNTER;
                    }
                #endif
            #endif
                    else
                    {
                        /* Empty else is added to fix misra violation */
                    }
                  
                    /* enter GPIO output mode */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    REG_RMW32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_MODE_MASK, CCR_MODE_GPO);
                    /* disable prescaler - this will stop the internal counter */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    REG_BIT_CLEAR32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_UCPREN_MASK);
                    /* set internal counter to 1 */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    REG_WRITE32(EMIOS_CCNTR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), (uint32)1U);
                    /*Updated period value to EMIOSA register*/
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    REG_WRITE32(EMIOS_CADR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), mMasterBusPeriod[mMasterBusIdx]);
                    /* update prescaler values*/
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    REG_RMW32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_UCPRE_MASK,(ctrlRegVal & CCR_UCPRE_MASK));
                }

              /* Load period from master bus */
            #ifdef PWM_FEATURE_DAOC
              #if (PWM_FEATURE_DAOC == STD_ON)
              if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
              {
                Pwm_eMIOS_LLD_Period[ch] = PwmChannel->Pwm_DefaultPeriodValue;
                Pwm_DAOC_LLD_Period[ch] = mMasterBusPeriod[mMasterBusIdx];
              }
              else
              #endif
            #endif
              {
                Pwm_eMIOS_LLD_Period[ch] = mMasterBusPeriod[mMasterBusIdx];
              }

    #if (PWM_DEV_ERROR_DETECT == STD_ON)
               if (CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
               {
                  /*
                   * if the configured channel Offset is >= than the associated MCB
                   * channel period then raise PWM_E_CHANNEL_OFFSET_VALUE  error.
                   */
                  if (PwmEmiosSpecificParam->Pwm_Offset >= mMasterBusPeriod[mMasterBusIdx])
                  {
                      Det_ReportError
                      (
                          (uint16) PWM_MODULE_ID,
                          (uint8) 0,
                          (uint8) PWM_INIT_ID,
                          (uint8) PWM_E_CHANNEL_OFFSET_VALUE
                      );
                      /* @violates @ref Pwm_eMIOS_LLD_C_REF_5 more than one 'break' terminates loop */
                      break;
                  }
                }
            #ifdef PWM_FEATURE_OPWMT
              #if (PWM_FEATURE_OPWMT == STD_ON)
                else if (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
                {
                  if (PwmEmiosSpecificParam->Pwm_Offset >= mMasterBusPeriod[mMasterBusIdx])
                  {
                      Det_ReportError
                      (
                          (uint16) PWM_MODULE_ID,
                          (uint8) 0,
                          (uint8) PWM_INIT_ID,
                          (uint8) PWM_E_CHANNEL_OFFSET_VALUE
                      );
                      /* exit for loop and Pwm_Init function - we can't continue further */
                      /* @violates @ref Pwm_eMIOS_LLD_C_REF_5 more than one 'break' terminates loop */
                      break;
                  }
                }else
                {
                  /*Do nothing*/
                }
                #endif
            #endif
          #endif /* PWM_DEV_ERROR_DETECT */
         }

         /* get the dutycycle */
         DutyCycle = PwmChannel->Pwm_DefaultDutyCycleValue;
    #if (PWM_GET_CHANNEL_STATE == STD_ON)
        Pwm_eMIOS_Duty_Cycle_Value[ch] = DutyCycle;
    #endif /*PWM_GET_CHANNEL_STATE_API */

      /* get the period */
  #ifdef PWM_FEATURE_OPWMCB
      #if (PWM_FEATURE_OPWMCB == STD_ON)
      if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) ||
                 (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
      {
          /* @violates @ref Pwm_eMIOS_LLD_C_REF_4 Implicit conversion changes signedness */
          Period = (((Pwm_eMIOS_LLD_Period[ch] -1) * 2U ) + 1U);          
          tempDuty = Pwm_eMIOS_LLD_ComputeDutycycle(Period, DutyCycle);
      }
      else
      #endif
  #endif
      {
        Period = Pwm_eMIOS_LLD_Period[ch];  
      }
      tempDuty = Pwm_eMIOS_LLD_ComputeDutycycle(Period, DutyCycle);

      if (((uint16)0x0000 == DutyCycle) || (0x0U == tempDuty))
      {

          if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
              /* OPWFMB */
              Pwm_eMIOS_LLD_UpdateChannel_AB
              (
                  chIdx,
                  (uint32)0U,
                  (uint32)Period,
                  ChannelAddr,
                  ModuleAddr
              );
          } else

  #if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC) || defined(PWM_FEATURE_OPWMCB)
    #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
          if (CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
    #endif
  #endif /* PWM_FEATURE_OPWMT */
          {
              /* OPWMB */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
              Pwm_eMIOS_LLD_UpdateChannel_AB
              (
                  chIdx,
                  (uint32)0U,
                  (uint32)0U,
                  ChannelAddr,
                  ModuleAddr
              );
          }

    #ifdef PWM_FEATURE_OPWMT
      #if (PWM_FEATURE_OPWMT == STD_ON)
          else if (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
          {
              /* OPWMT */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
              Pwm_eMIOS_LLD_UpdateChannel_AB
              (
                  chIdx,
                  (uint32)1U,
                  (uint32)1U,
                  ChannelAddr,
                  ModuleAddr
              );
          }
        #endif
      #endif
      #ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
          else if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) || \
                  (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
          {
              /*OPWMCB*/
              Pwm_eMIOS_LLD_UpdateChannel_AB
              (
                  chIdx,
                  (uint32)(Pwm_eMIOS_LLD_Period[ch] + (uint32)1U),
                  (uint32)tempDuty,
                  ChannelAddr,
                  ModuleAddr
              );
          }
        #endif
      #endif
      #if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC) || defined(PWM_FEATURE_OPWMCB)
        #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
           else
            {
            /*empty else added to fix misra violation*/
            }
        #endif
      #endif

           }
           else if (PWM_DUTY_CYCLE_100 == DutyCycle)
           {
              if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
                  /* OPWFMB */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                  Pwm_eMIOS_LLD_UpdateChannel_AB
                  (
                      chIdx,
                      (uint32)Period,
                      (uint32)Period,
                      ChannelAddr,
                      ModuleAddr
                  );
              } else

#if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC) || defined(PWM_FEATURE_OPWMCB)
    #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
              if (CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
    #endif
#endif
              {
                  /* OPWMB */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                  Pwm_eMIOS_LLD_UpdateChannel_AB
                  (
                      chIdx,
                      (uint32)0U,
                      (uint32)Period,
                      ChannelAddr,
                      ModuleAddr
                  );
              }

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
              else if (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
              {
                  /* OPWMT */
                  /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                  Pwm_eMIOS_LLD_UpdateChannel_AB
                  (
                      chIdx,
                      (uint32)1U,
                      (uint32)(Period+(uint32)1U),
                      ChannelAddr,
                      ModuleAddr
                  );
              }
    #endif
#endif /* PWM_FEATURE_OPWMT */
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
                else if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) || \
                        (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
                {
                    /*OPWMCB*/
                    Pwm_eMIOS_LLD_UpdateChannel_AB
                    (
                        chIdx,
                        (uint32)1U,
                        (uint32)0,
                        ChannelAddr,
                        ModuleAddr
                    );
                }
    #endif
#endif
#if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC)
    #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON))
               else
                {
                /*empty else added to fix misra violation*/
                }
    #endif
#endif
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_20 if ... else if shall be terminated with an else clause */
            } else
            {
                /* != (0%, 100%) */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
                /*  transitions available in the signal */
                Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] |= ((uint32)1U<< EMIOS_CHANNEL_INDEX(hw_ch));
#endif /* PWM_NOTIFICATION_SUPPORTED */

                if
                (
                    CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)
                ) {
                    /* OPWFMB */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                    Pwm_eMIOS_LLD_UpdateChannel_AB
                    (
                        chIdx,
                        (uint32)tempDuty,
                        (uint32)Period,
                        ChannelAddr,
                        ModuleAddr
                    );
                } else

#if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC) || defined(PWM_FEATURE_OPWMCB)
    #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
                if (CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
    #endif
#endif

                { /* OPWMB */

                    tempDuty32 = (uint32)tempDuty + PwmEmiosSpecificParam->Pwm_Offset;

#if (PWM_DEV_ERROR_DETECT == STD_ON)

                    /* check that the configured channel Offset parameter
                     * combined with the Dutycycle will not program event B
                     * in time after the period
                     * - leading to unexpected behavior -
                     * signal will take the value of EDPOL (=signal polarity)
                     * This can happen only if Pwm_Offset != 0 because
                     * the Dutycycle formula limits event B
                     * to [0, Period];
                     * In this case (Pwm_Offset != 0) 100% dutycycle is
                     * impossible to reach
                     */
                    if (tempDuty32 >= Period)
                    {
                        Det_ReportError
                        (
                            (uint16) PWM_MODULE_ID,
                            (uint8)0,
                            (uint8)PWM_INIT_ID,
                            (uint8)PWM_E_OPWMB_CHANNEL_OFFSET_DUTYCYCLE_RANGE
                        );
                        /* exit for loop and Pwm_Init function   - we can't continue further */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_5 more than one 'break' terminates loop */
                        /* @note we need to exit the FOR loop in each case a DET Error is detected  */
                        break;
                    }
                    else
#endif /* PWM_DEV_ERROR_DETECT */

                    {
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                        Pwm_eMIOS_LLD_UpdateChannel_AB
                        (
                            chIdx,
                            (uint32)(PwmEmiosSpecificParam->Pwm_Offset + (uint32)1U),
                            (uint32)tempDuty32,
                            ChannelAddr,
                            ModuleAddr
                        );
                    }
                }

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)

                else if (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
                {  /* OPWMT */


        #if (PWM_CHANGE_REGISTER_A_SWITCH == STD_ON)
                  {
                      /* register A is updated on dutycycle change */
                      VAR(uint16, AUTOMATIC)  tempRegB;

                      /* Calculate the B-register value */
                      if ((uint16)0 != (uint16)PwmEmiosSpecificParam->Pwm_Offset)
                      {
                          tempRegB = ( (uint16)Period - (uint16)PwmEmiosSpecificParam->Pwm_Offset ) + (uint16)1U;
                      }
                      else
                      {
                          tempRegB = (uint16)1U;
                      }

                      /* Calculate the A-register value */
                      if (tempRegB > tempDuty)
                      {
                          tempDuty = tempRegB - tempDuty;
                      }
                      else
                      {
                          /* @violates @ref Pwm_eMIOS_LLD_C_REF_2 Implicit conversion of integer to smaller type */
                          tempDuty = ((uint16)Period - (uint16)tempDuty) + ((uint16)tempRegB - (uint16)1U);
                      }
                      /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                      Pwm_eMIOS_LLD_UpdateChannel_AB
                      (
                          chIdx,
                          (uint32)tempDuty,
                          (uint32)tempRegB,
                          ChannelAddr,
                          ModuleAddr
                      );
                  }
        #else /* PWM_CHANGE_REGISTER_A_SWITCH */
                    /* register B is updated on dutycycle change */
                    tempDuty32 = ( (uint32)tempDuty + PwmEmiosSpecificParam->Pwm_Offset ) % Period ;

                    /* if (tempDuty + Pwm_Offset == Period) then tempDuty32
                     * will be 0 if the reference channel is MCB/OPWFMB
                     * then we have [ 0x1, Period ] if we program regB
                     * with 0 a compare event will never be generated
                     * in this case we program the Period value instead
                     * and accept an error equal with 1 tick.
                     */
                    if ( 0x0U == tempDuty32 ) {
                        tempDuty32 = Period;
                    }

                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                    Pwm_eMIOS_LLD_UpdateChannel_AB
                    (
                        chIdx,
                        (uint32)(PwmEmiosSpecificParam->Pwm_Offset + (uint32)1U),
                        (uint32)tempDuty32,
                        ChannelAddr,
                        ModuleAddr
                    );

        #endif /* PWM_CHANGE_REGISTER_A_SWITCH */

                }
    #endif
#endif /*PWM_FEATURE_OPWMT*/

#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
               else if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) || \
                           (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
                {
                    /*OPWMCB leading/trialing edge dead time*/
                    Pwm_eMIOS_LLD_UpdateChannel_AB
                    (
                        chIdx,
                        (uint32)(Pwm_eMIOS_LLD_Period[ch] - (tempDuty/(uint32)2U)),
                        (uint32)(PwmEmiosSpecificParam->Pwm_DeadTime / (uint32)2U),
                        ChannelAddr,
                        ModuleAddr
                    );
                }
    #endif
#endif
#if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC)
    #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON))
               else
                {
                /*empty else added to fix misra violation*/
                }
    #endif
#endif
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_20 if ... else if shall be terminated with an else clause */
            }

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
            /*
            * set the trigger offset for the OPWMT channel
            */
            if (CCR_MODE_OPWMT != (ctrlRegVal & CCR_MODE_MASK))
            {
    #endif
#endif /* PWM_FEATURE_OPWMT */

                /* OPWFMB, OPWMB, DAOC, OPWMCB*/
                /* FLAG assigned to interrupt request  */
                /* enable unified channel to make registers writable */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_DMA_MASK );

                /* disable interrupt  */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)

            } else {
                    /* save configured trigger delay value for OPWMT mode*/
                    /*
                    * @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function
                    */
                Pwm_Current_TriggerDelay[ch] = (Pwm_PeriodType)(PwmEmiosSpecificParam->Pwm_TriggerDelay);

                /* OPWMT */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32
                (
                    (ChannelAddr + EMIOS_ALTA_OFFSET),
                    (uint32)(PwmEmiosSpecificParam->Pwm_TriggerDelay + (uint32)1U)
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                );

                /* FLAG assigned to DMA request */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_DMA_MASK );

                /* FLAG event enabled */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );
            }
    #endif
#endif /* PWM_FEATURE_OPWMT */

            /* Select the counter bus: internal / busA / bus diverse */

            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_BSL_MASK, ctrlRegVal & CCR_BSL_MASK );

            if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
                 /* OPWMB OPWMT OPWMCB*/
                if (PWM_HIGH == PwmChannel->Pwm_Polarity) {
                        polarity_bit = (uint32)0;
                } else {
                        polarity_bit = (uint32)0x80;
                }
            } else {
                /* OPWMB */
                if (PWM_HIGH == PwmChannel->Pwm_Polarity) {
                polarity_bit = (uint32)0x80;
                } else {
                polarity_bit = (uint32)0;
                }
            }

            /* set mode */

            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_MODE_MASK | CCR_EDPOL_MASK),
                ((ctrlRegVal & CCR_MODE_MASK) | (polarity_bit & CCR_EDPOL_MASK ))
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );

#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
            if (CCR_MODE_DAOC == ((uint32)ctrlRegVal & CCR_MODE_MASK)) {

                   if (0x0U == tempDuty)
                    {
                        Pwm_DAOC_LLD_Duty[ch] = (uint16)0U;
                         /* force match B */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );
                    }
                    else if (PWM_DUTY_CYCLE_100 == DutyCycle)
                    {
                        Pwm_DAOC_LLD_Duty[ch] = (uint16)0U;
                        /* force match A */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );
                    }
                    else
                    {   /* != (0%, 100%) */
                        Pwm_DAOC_LLD_Duty[ch] = (uint16)tempDuty;
                        if(PwmChannel->Pwm_IdleState == PwmChannel->Pwm_Polarity)
                        {
                        /* force match A */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                          REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );
                        } else
                        {
                          /* force match B */
                          /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                          REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );
                        }
                    }

                    Pwm_eMIOS_LLD_Period[ch] = PwmChannel->Pwm_DefaultPeriodValue;

                    /* FLAG event enabled */
                     /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FEN_MASK );
                    
                    if (PWM_BUS_INTERNAL_COUNTER == ((uint32)ctrlRegVal & PWM_BUS_MASK))
                    {
                      Pwm_eMIOS_LLD_UpdateChannel_AB
                      (
                          chIdx,
                          (uint32)0U,
                          (uint32)tempDuty,
                          ChannelAddr,
                          ModuleAddr
                      );
                    }
                    else
                    {
                      Pwm_eMIOS_LLD_UpdateChannel_AB
                      (
                          chIdx,
                          (uint32)1U,
                          ((uint32)tempDuty + (uint32)1U),
                          ChannelAddr,
                          ModuleAddr
                      );
                    }
                }
    #endif
#endif/*PWM_FEATURE_DAOC*/
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
         if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) || \
                   (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
        {
        /*do nothing*/
        }else
    #endif
#endif
            /* force match on the first edge - this also sets the signal level */
            if (CCR_MODE_OPWFMB_FLAG_B == ((uint32)ctrlRegVal & CCR_MODE_MASK)) {
                /* OPWFMB */
                /* force match B */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FORCMB_MASK );
            } else
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
            if ((CCR_MODE_DAOC != ((uint32)ctrlRegVal & CCR_MODE_MASK)))
    #endif
#endif/*PWM_FEATURE_DAOC*/
            {

                /* OPWMB / OPWMT */
                /* do not force event A for OPWMB/OPWMT and 0% duty */
                if (((uint16)0x0000 != DutyCycle) && (0x0U != tempDuty)) {
                    /* force match A */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FORCMA_MASK );
                } else {
                    /* force match B */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FORCMB_MASK );
                }
            }
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
            else
            {
                /*Empty else to fix misra*/
            }
    #endif
#endif/*PWM_FEATURE_DAOC*/

            if (PWM_BUS_INTERNAL_COUNTER == ((uint32)ctrlRegVal & PWM_BUS_MASK)) {
                /* set the prescaler divide value */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_RMW32((ChannelAddr + EMIOS_CCR_OFFSET), CCR_UCPRE_MASK,ctrlRegVal&CCR_UCPRE_MASK);

                /* enable prescaler - this will start the internal counter */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_UCPREN_MASK );
            }
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
            if (CCR_MODE_DAOC == ((uint32)ctrlRegVal & CCR_MODE_MASK))
            {
                if (PWM_DUTY_CYCLE_100 == DutyCycle)
                {
                    /* Write A with B value */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_WRITE32 ( EMIOS_CADR(mIdx, chIdx), REG_READ32( EMIOS_CBDR(mIdx, chIdx)));

                    /* Invert the EDGE POLARITY in control register */
                    REG_RMW32
                    (
                        ChannelAddr + EMIOS_CCR_OFFSET,
                        (CCR_EDPOL_MASK),
                        ((~polarity_bit) & CCR_EDPOL_MASK )
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    );
                }
            }
    #endif
#endif/*PWM_FEATURE_DAOC*/
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
          else if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) || \
                (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                prescalar = (REG_READ32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx))) & 
                            CCR_UCPRE_MASK);
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_RMW32((ChannelAddr + EMIOS_CCR_OFFSET), CCR_UCPRE_MASK,prescalar);
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_UCPREN_MASK );
            }
    #endif
#endif
            else
            {
            /* empty else added to fix misra violation */
            }
        } /* end if EMIOS channel */

    } /* end for */

    for (ch=0U; ch < PWM_EMIOS_HW_CHANNELS; ch++)
    {
      /* Master bus is used */
      if((uint8)0xFFU != mMasterBusUse[ch])
      {
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
        REG_BIT_CLEAR32(EMIOS_CCR(EMIOS_MODULE_INDEX(ch), EMIOS_CHANNEL_INDEX(ch)), CCR_FEN_MASK);

        switch(mMasterBusUse[ch])
        {
          case 1U:
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32(EMIOS_CCR(EMIOS_MODULE_INDEX(ch), EMIOS_CHANNEL_INDEX(ch)), \
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    CCR_MODE_MASK, (CCR_MODE_MCB_FLAG_A_INT_CLOCK & CCR_MODE_MASK));
            break;
          case 2U:
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32(EMIOS_CCR(EMIOS_MODULE_INDEX(ch), EMIOS_CHANNEL_INDEX(ch)), \
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    CCR_MODE_MASK, (CCR_MODE_MCB_INT_CLOCK & CCR_MODE_MASK));
            break;
          case 3U:
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32(EMIOS_CCR(EMIOS_MODULE_INDEX(ch), EMIOS_CHANNEL_INDEX(ch)), \
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                                CCR_MODE_MASK, (CCR_MODE_MCB_INT_CLOCK & CCR_MODE_MASK));
            break;
          default:
            break;
        }

        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
        REG_BIT_SET32(EMIOS_CCR(EMIOS_MODULE_INDEX(ch), EMIOS_CHANNEL_INDEX(ch)), CCR_UCPREN_MASK);
      }
      else
      {
        /* empty else added to fix misra violation */
      }
    }
}


/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief   This function deinitializes all eMIOS channels assigned to PWM
* @details This function
*          - sets the channel output to the configured Idle state
*          - Reset Timer control register, Internal Counter, A, B registers
*          - clears the (pending) interrupt flag corresponding to Emios channel
*
*
* @implements DPWM04008
* @api
*
*/

FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_DeInit(void)
{

    VAR(Pwm_ChannelType, AUTOMATIC) ch = (Pwm_ChannelType ) 0;

    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch; /* hw channel */

    VAR(Pwm_ChannelType, AUTOMATIC) chIdx;  /*  assigned eMIOS HW channel index */

    VAR(uint32, AUTOMATIC) ModuleAddr;  /*eMIOS module address*/
    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
    
    /* assigned eMIOS HW module  index */
    VAR(Pwm_ChannelType, AUTOMATIC) mIdx;
    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;
    VAR(uint8, AUTOMATIC) mMasterBusIdx = 0xFFU;
    VAR(uint8, AUTOMATIC) mMasterBusUse[PWM_EMIOS_HW_CHANNELS];

    for (ch = 0U; ch < Pwm_eMIOS_Cfg->ChannelCount; ch++)
    {
#if (PWM_GET_CHANNEL_STATE == STD_ON)
        Pwm_eMIOS_Duty_Cycle_Value[ch] = 0U;
#endif /*PWM_GET_CHANNEL_STATE */    
      /* only handle EMIOS channels */
      /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
      if (PWM_EMIOS_CHANNEL == Pwm_eMIOS_Cfg->ChannelsPtr[ch].IpType)
      {
        /* extract from conf structure the generic channel information */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
        PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ch];
        /* extract from conf structure the EMIOS specific channel information */
        PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;

        ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;
        ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;
        /* store the associated hw channel ID */
        hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;

        chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);

        /* set the channel output to the configured Idle state */
        if (PWM_HIGH == PwmChannel->Pwm_IdleState) {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );
        }

        else {
          /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );
        }
        
        /* reset A,B regs 0 */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_WRITE32( (ChannelAddr + EMIOS_CADR_OFFSET ) , 0U );

        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_WRITE32( (ChannelAddr + EMIOS_CBDR_OFFSET ) , 0U );
        
        /* enter GPIO ouput mode - this will set the ouput pin to the EDPOL value */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_MODE_MASK, CCR_MODE_GPO );

        /* Reset Timer control register - except mode and edpol to keep channel
        *               in output idle mode
        *         Internal Counter is also cleared when entering GPIO Mode */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_CLEAR32((ChannelAddr + EMIOS_CCR_OFFSET), (~(CCR_EDPOL_MASK | CCR_MODE_MASK)));

        /* disable interrupt */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

        /* clear interrupt flag */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );


        /* only write UCDIS register if it's available */
    #ifdef EMIOS_UCDIS
        /* disable unified channel */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_SET32( (ModuleAddr+EMIOS_UCDIS_OFFSET), (uint32)((uint32)1<<(chIdx)) );
    #endif /* EMIOS_UCDIS */

        /* reset stored period value */
        Pwm_eMIOS_LLD_Period[ ch ]=0U;
  #ifdef PWM_FEATURE_OPWMT
      #if (PWM_FEATURE_OPWMT == STD_ON)
        /* reset stored trigger delay value*/
        Pwm_Current_TriggerDelay[ch] = 0U;
      #endif
  #endif

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* invalidate the reverse hardware channel 2 logical channel map */
        Pwm_eMIOS_LLD_RevHardwareTable[ hw_ch ] = (Pwm_ChannelType)0xFFU;
        /* notifications disabled */
        Pwm_eMIOS_LLD_Notifications[ ch ] = 0xFFU;
    #endif /* PWM_NOTIFICATION_SUPPORTED */

      } /* end if emios channel */
    } /* end for */
    
    /* deinitialize master bus */
    for (ch = 0U; ch < PWM_EMIOS_HW_CHANNELS; ch++)
    {
        mMasterBusUse[ch] = 0xFFU;
    }
    for (ch = 0U; ch < Pwm_eMIOS_Cfg->ChannelCount; ch++)
    {
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
        PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ch];
        /* extract from conf structure the EMIOS specific channel information */
        PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;
        
        /* save current channel control register config value in local variable */
        ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;

        ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;

        if (PWM_BUS_INTERNAL_COUNTER != ((uint32)ctrlRegVal & PWM_BUS_MASK))
        {
            /* store the associated hw channel ID */
            hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;
            mIdx = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);
            chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);

            mMasterBusIdx = Pwm_eMIOS_LLD_GetMasterBus(mIdx, chIdx, ((uint32)ctrlRegVal & PWM_BUS_MASK));

            if(mMasterBusUse[mMasterBusIdx] == (uint8)0xFFU) /* This master bus is not use */
            {
              mMasterBusUse[mMasterBusIdx] = (uint8)1U;
              /* reset A,B regs 0 */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
              REG_WRITE32( EMIOS_CADR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), 0U );

              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
              REG_WRITE32( EMIOS_CBDR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), 0U );
              
              /* enter GPIO ouput mode - this will set the ouput pin to the EDPOL value */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
              REG_RMW32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_MODE_MASK, CCR_MODE_GPO );

              /* Reset Timer control register - except mode and edpol to keep channel
              *  in output idle mode
              *  Internal Counter is also cleared when entering GPIO Mode */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              REG_BIT_CLEAR32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), \
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                              (~(CCR_EDPOL_MASK | CCR_MODE_MASK)));

              /* disable interrupt */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
              REG_BIT_CLEAR32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_FEN_MASK);

              /* clear interrupt flag */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
              REG_WRITE32(EMIOS_CSR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CSR_FLAG_BIT );

              /* only write UCDIS register if it's available */
          #ifdef EMIOS_UCDIS
              /* disable unified channel */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
              /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
              REG_BIT_SET32( EMIOS_UCDIS(mIdx), (uint32)((uint32)1<<(EMIOS_CHANNEL_INDEX(mMasterBusIdx))) );
          #endif /* EMIOS_UCDIS */
            }
        }
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    for(ch=0U; ch < PWM_EMIOS_MODULES_CFG; ch++)
    {
      /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
      if (PWM_EMIOS_CHANNEL == Pwm_eMIOS_Cfg->ChannelsPtr[ch].IpType)
      {
          Pwm_eMIOS_LLD_DutyState[ch] = (uint32)0x00;
      }
    }
#endif

    /* invalidate EMIOS LLD top level private config pointer */
    Pwm_eMIOS_Cfg = NULL_PTR;
}
#endif /* PWM_DE_INIT_API */


/*===============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SETCOUNTERBUS_API == STD_ON))
/**
* @brief   This function sets the dutycycle for the specified eMIOS channel
* @details This function:
*          - disable the interrupt and clear the interrupt flag
*          - sets the A register with value 0 for OPWFMB mode for 0% dutycycle
*          - sets the A and B registers with value 0 for OPWMB mode for 0% dutycycle
*          - sets the A and B registers with value 1 for OPWMT mode for 0% dutycycle
*          - sets the A register with value period for OPWFMB mode for 100% dutycycle
*          - sets the A register with 0 and B register with period for OPWMB mode for
*            100% dutycycle
*          - sets the A register with 1 and B register with period+1 for OPWMT mode for
*            100% dutycycle
*          - for dutycycle not equal to 0% and 100%, FLAG event is enabled
*          - sets the A register with value dutycycle for OPWFMB mode
*          - sets the A register with value offset+1 and B register with dutycycle+offset
*            for OPWMB mode
*          - sets the A register with value offset+1 and B register with
*            (dutycycle + offset) % period for OPWMT mode
*
* @param[in]    LogicalChannelNumber - pwm channel id
* @param[in]    DutyCycle     - pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    useSection    - critical section for logical channel
*
* @note         Pwm_eMIOS_LLD_SetDutyCycle is used by EMIOS_Pwm_LLD_SetCounterBus
*               it is enabled when at least one of the APIs is enabled
*
* @api
*
* @implements DPWM04015
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external could be made static */
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetDutyCycle(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(uint16, AUTOMATIC) DutyCycle,
        VAR(uint8,  AUTOMATIC) useSection
    )
{

    VAR(Pwm_PeriodType, AUTOMATIC) Period;
    VAR(Pwm_PeriodType, AUTOMATIC) tempDuty = 0U;
    VAR(uint32, AUTOMATIC) tempDuty32;


        VAR(uint32, AUTOMATIC) polarity_bit;  /*status of polarity bit */
 

    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) mIdx; /*  assigned eMIOS HW channel index */
    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;
    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch; /* hw channel */
    VAR(Pwm_ChannelType, AUTOMATIC) chIdx; /*  assigned eMIOS HW channel index */
    VAR(uint32, AUTOMATIC) ModuleAddr;  /*eMIOS module address*/
    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
  #ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
      VAR(uint32, AUTOMATIC) dutyCorrection = 0U; /*duty correction for OPWMCB*/
    #endif
  #endif
    VAR(Pwm_PeriodType, AUTOMATIC) Offset;
    #ifdef PWM_EMIOS_16_BITS_VARIANT
        #if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)
        VAR(Pwm_uint64, AUTOMATIC)multi_result=0U;
    #endif
#endif
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
        VAR(uint32, AUTOMATIC) reg_A_value;
        VAR(uint32, AUTOMATIC) daocnotification;
        #endif
    #endif

    #ifdef PWM_FEATURE_OPWMT
        #if (PWM_FEATURE_OPWMT == STD_ON)
        VAR(uint32, AUTOMATIC) val_for_regb;    
    #endif
    #endif

    if ((uint8)STD_ON == useSection) {
        /* start critical section for logical channel */
        Pwm_Schm_ProtectResource(LogicalChannelNumber);
    }

    /* extract from conf structure the generic        channel information */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[LogicalChannelNumber];
#if (PWM_GET_CHANNEL_STATE == STD_ON)
    Pwm_eMIOS_Duty_Cycle_Value[LogicalChannelNumber] = DutyCycle;
#endif /*PWM_GET_CHANNEL_STATE_API */
    /* extract from conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;

    ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;
    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

    /* store the associated hw channel ID */
    hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;

    mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);

    chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);

    /* save current channel control register config value in local variable */
    ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;

    /* get period for current channel */

if ((CCR_MODE_DAOC != (ctrlRegVal & CCR_MODE_MASK)) &&
        (CCR_MODE_OPWFMB_FLAG_B != (ctrlRegVal & CCR_MODE_MASK))){
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            Period =  Pwm_eMIOS_LLD_GetCounterBusPeriod(mIdx, chIdx,(REG_READ32(EMIOS_CCR(mIdx, chIdx)) & CCR_BSL_MASK));
       }
    else{
             Period = Pwm_eMIOS_LLD_Period[LogicalChannelNumber];
        }
        if ((Period != Pwm_eMIOS_LLD_Period[LogicalChannelNumber])
                && ((PwmEmiosSpecificParam->Pwm_OffsetTriggerDelayAdjust) == (boolean)TRUE))
            {
            /*calculate new offset value if the frequency is modified */
#ifdef PWM_EMIOS_16_BITS_VARIANT
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)

            Offset = (Pwm_PeriodType) ((((Pwm_PeriodType)PwmEmiosSpecificParam->Pwm_Offset) * (Pwm_PeriodType)Period)/
                                                                      (Pwm_PeriodType)Pwm_eMIOS_LLD_Period[LogicalChannelNumber]);
#else            
            multi_result=(((Pwm_uint64)PwmEmiosSpecificParam->Pwm_Offset) * (Pwm_uint64)Period);
            Offset=(Pwm_PeriodType)Pwm_div64((Pwm_uint64)multi_result, (Pwm_uint64)Pwm_eMIOS_LLD_Period[LogicalChannelNumber]);
#endif
#endif
    #ifdef PWM_FEATURE_OPWMT
        #if (PWM_FEATURE_OPWMT == STD_ON)
            if(CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
            {

                /* Adjust the Trigger Delay if the frequency is modified */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                Pwm_Current_TriggerDelay[LogicalChannelNumber]  = \
                    (Pwm_PeriodType)((uint32)(Pwm_Current_TriggerDelay[LogicalChannelNumber] * (uint32)Period) / \
                    Pwm_eMIOS_LLD_Period[LogicalChannelNumber]);
            }
            #endif
        #endif
        }
        else
        {
            /*read stored offset value */
            Offset = (Pwm_PeriodType)(PwmEmiosSpecificParam->Pwm_Offset);
        }

   #ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
        if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) ||
                 (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
        {
            /* OPWMCB uses MCB up/down counter bus hence multiple (period * 2) + 1U to
               get configured period value */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_4 Implicit conversion changes signedness */
            tempDuty = Pwm_eMIOS_LLD_ComputeDutycycle((((Period - 1U)  * 2U) + 1) , DutyCycle);
        } else
        #endif
    #endif
     {tempDuty = Pwm_eMIOS_LLD_ComputeDutycycle(Period, DutyCycle);}

    if (PWM_HIGH == PwmChannel->Pwm_Polarity)
    {   /* set polarity*/
        polarity_bit = (uint32)0x80;
    }
    else
    {   /* clear polarity*/
        polarity_bit = (uint32)0;
    }

    if (((uint16)0x0000 == DutyCycle) || (0x0U == tempDuty))
    {

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* no transitions in the signal */
        Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] &= ~((uint32)1<< EMIOS_CHANNEL_INDEX(hw_ch));

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        if (CCR_MODE_OPWMT != (ctrlRegVal & CCR_MODE_MASK)) {
            #endif
        #endif /* PWM_FEATURE_OPWMT */

            /* at 0% dutycycle no edges are present in the output signal
                thus no notifications */
            /* disable interrupt */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

            /* clear interrupt flag */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        }
            #endif
        #endif /* PWM_FEATURE_OPWMT */

    #endif /* PWM_NOTIFICATION_SUPPORTED */

        if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
            /* OPWFMB */
            /* write A register */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CADR_OFFSET) , 0U );

        } else

     #if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC) || defined(PWM_FEATURE_OPWMCB)
        #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
            if (CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
        #endif
    #endif

        {
            /* OPWMB */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
            Pwm_eMIOS_LLD_UpdateChannel_AB(chIdx, (uint32)0U, (uint32)0U,ChannelAddr,ModuleAddr);
        }

    #ifdef PWM_FEATURE_OPWMT
        #if (PWM_FEATURE_OPWMT == STD_ON)
        else
         #if defined (PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
                #if (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON)
            if (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
            #endif
        #endif
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            val_for_regb = REG_READ32(EMIOS_CADR(mIdx, chIdx));
            /* OPWMT */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
            Pwm_eMIOS_LLD_UpdateChannel_B(val_for_regb,ChannelAddr
#ifdef MULTI_PWM_CHANNEL_SYNCH
    #if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)
            ,chIdx,ModuleAddr
    #endif
#endif
            );
        }
        #endif
    #endif /* PWM_FEATURE_OPWMT */
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
        else
         #ifdef PWM_FEATURE_OPWMCB
            #if (PWM_FEATURE_OPWMCB == STD_ON)
        if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
            #endif
        #endif
        {
            Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FEN_MASK );
            /* Set the polarity to configured value */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK),
                ((polarity_bit) & CCR_EDPOL_MASK )
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );

        }
        #endif
    #endif
    #ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
        else{
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            dutyCorrection = REG_READ32(EMIOS_CADR(mIdx, chIdx));
            Pwm_eMIOS_LLD_UpdateChannel_AB
                (
                    chIdx,
                    (uint32)Period + 1U,
                    (uint32)0U,
                    ChannelAddr,
                    ModuleAddr
                );
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
            /* below code added to avoid limitation of 0% dutycycle(if call idle to 0%) */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            if (CCR_MODE_GPO == (REG_READ32(ChannelAddr + EMIOS_CCR_OFFSET) & CCR_MODE_MASK))
              {
                   REG_RMW32
                    (
                        ChannelAddr + EMIOS_CCR_OFFSET,
                        (CCR_EDPOL_MASK |CCR_MODE_MASK),
                        ((polarity_bit & CCR_EDPOL_MASK ) | (ctrlRegVal & CCR_MODE_MASK))
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    );
               }
#endif
            if(dutyCorrection == 0x1U)
            {   /*this statement is required to avoid limitation of 0% duty cycle(if call 100% to 0%)*/
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ModuleAddr+EMIOS_OUDR_OFFSET), (uint32)((uint32)1<<(chIdx)) );
                if(PWM_MODE_OPWMCB_LEAD_DEADTIME == ((uint32)ctrlRegVal & CCR_MODE_MASK))
                {
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );
                }
                else
                {
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );
                }
            }
        }
        #endif
    #endif
    }
    else if (PWM_DUTY_CYCLE_100 == DutyCycle)
    {

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

        /* no transitions in the signal */
        Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] &= ~((uint32)1<< EMIOS_CHANNEL_INDEX(hw_ch));

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        if (CCR_MODE_OPWMT != (ctrlRegVal & CCR_MODE_MASK)) {
            #endif
        #endif /* PWM_FEATURE_OPWMT */
            /* at 100% dutycycle no edges are present in the output signal
               thus no notifications */
            /* disable interrupt */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

            /* clear interrupt flag */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET) , CSR_FLAG_BIT );

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        }
            #endif
        #endif /* PWM_FEATURE_OPWMT */

    #endif /* PWM_NOTIFICATION_SUPPORTED */


        if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
            /* OPWFMB */
            /* write A register */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CADR_OFFSET) , Period );
        } else

     #if defined (PWM_FEATURE_OPWMT) || defined (PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
        #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
            if (CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
        #endif
    #endif

        {
            /* OPWMB */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
            Pwm_eMIOS_LLD_UpdateChannel_AB
            (
                chIdx,
                (uint32)0U,
                (uint32)Period,
                ChannelAddr,
                ModuleAddr
            );
        }

    #ifdef PWM_FEATURE_OPWMT
        #if (PWM_FEATURE_OPWMT == STD_ON)
        else
             #if defined (PWM_FEATURE_DAOC ) || defined (PWM_FEATURE_OPWMCB)
                #if (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON)
                if (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
                #endif
            #endif
        {
            /* OPWMT */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
            Pwm_eMIOS_LLD_UpdateChannel_B
            (
                (uint32)(Period+(uint32)1U),
                 ChannelAddr
#ifdef MULTI_PWM_CHANNEL_SYNCH
    #if (MULTI_PWM_CHANNEL_SYNCH == STD_OFF)
                 ,chIdx,
                 ModuleAddr
     #endif
#endif
            );
        }
        #endif
    #endif /*PWM_FEATURE_OPWMT*/
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
        else
#ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
        if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
        #endif
#endif
        {
             /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FEN_MASK );
             /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            reg_A_value = ((Pwm_eMIOS_LLD_Period[LogicalChannelNumber] +
             /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                               REG_READ32( EMIOS_CADR(mIdx, chIdx))) % Pwm_DAOC_LLD_Period[ LogicalChannelNumber ]);            
            if (reg_A_value != (uint32)0) {
             /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CADR(mIdx, chIdx) ,  reg_A_value);
                 /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) ,  reg_A_value);
            } else
            {
             /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CADR(mIdx, chIdx) ,  Pwm_DAOC_LLD_Period[ LogicalChannelNumber ]);
                 /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) , Pwm_DAOC_LLD_Period[ LogicalChannelNumber ]);
            }
            Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
            /* Invert the edge polarity */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK),
                ((~polarity_bit) & CCR_EDPOL_MASK )
                 /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
            
         }
        #endif
    #endif
     #ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
        else{
                Pwm_eMIOS_LLD_UpdateChannel_AB
                            (
                                chIdx,
                                (uint32)1U,
                                (uint32)0U,
                                ChannelAddr,
                                ModuleAddr
                            );

        }
        #endif
    #endif/*PWM_FEATURE_DAOC*/
    } else
    {
        /* != (0%, 100%) */

    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /*  transitions available in the signal */
         Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] |= ((uint32)1U<< EMIOS_CHANNEL_INDEX(hw_ch));

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        if (CCR_MODE_OPWMT != (ctrlRegVal & CCR_MODE_MASK)) {
            #endif
        #endif /* PWM_FEATURE_OPWMT */

            /* if notifications are enabled and the dutycycle in
             * the next period is != 0%,100% (we have edges)
             * thus enable notifications - this is for the case when
             * we are coming from duty 0%,100% where
             * the notifications are disabled because we have no edges there
             */
              if (0xFFU != Pwm_eMIOS_LLD_Notifications[LogicalChannelNumber]) {
                /* FLAG event enabled */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );
            }

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        }
            #endif
        #endif /* PWM_FEATURE_OPWMT */

    #endif /* PWM_NOTIFICATION_SUPPORTED */

        if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) { /* OPWFMB */
            /* write A register */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CADR_OFFSET) , (tempDuty) );
        } else

    #if defined(PWM_FEATURE_OPWMT) || defined(PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
        #if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
                if (CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
        #endif
    #endif

        { /* OPWMB */
        /*@violates @ref Pwm_eMIOS_LLD_C_REF_15 MISRA 2004 Required Rule,This condition is added to 
        optimize the driver code*/ 
            tempDuty32 = (uint32)tempDuty + Offset;

    #if (PWM_DEV_ERROR_DETECT == STD_ON)

            /* check that the configured channel Offset parameter combined
             * with the Dutycycle will not program event B in time after
             * the period - leading to unexpected behavior -
             * signal will take the value of EDPOL ( = signal polarity )
             * This can happen only if Pwm_Offset != 0 because
             * the Dutycycle formula limits event B
             * to [0, Period];
             * In this case (Pwm_Offset != 0) 100% dutycycle is impossible
             * to reach
             */
            if (tempDuty32 >= Period) {

                Det_ReportError
                (
                    (uint16) PWM_MODULE_ID,
                    (uint8)0,
                    (uint8)PWM_SETDUTYCYCLE_ID,
                    (uint8)PWM_E_OPWMB_CHANNEL_OFFSET_DUTYCYCLE_RANGE
                );

                /*
                 * force event B equal with Period
                 */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                Pwm_eMIOS_LLD_UpdateChannel_AB
                (
                    chIdx,
                    (uint32)(Offset  + (uint32)1U),
                    (uint32)Period,
                    ChannelAddr,
                    ModuleAddr
                );
            }
            else
    #endif /* PWM_DEV_ERROR_DETECT */
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                Pwm_eMIOS_LLD_UpdateChannel_AB
                (
                    chIdx,
                    (uint32)(Offset  + (uint32)1U),
                    (uint32)tempDuty32,
                    ChannelAddr,
                    ModuleAddr
                );
            }
        }

    #ifdef PWM_FEATURE_OPWMT
        #if (PWM_FEATURE_OPWMT == STD_ON)
        else
        #if defined (PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
                #if ((PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON))
            if (CCR_MODE_OPWMT == (ctrlRegVal & CCR_MODE_MASK))
            #endif
        #endif
        {  /* OPWMT */
            #if (PWM_CHANGE_REGISTER_A_SWITCH == STD_ON)
            {
                /* register A is updated on dutycycle change */
                VAR(uint16, AUTOMATIC)  tempRegB;

                /* Calculate the B-register value */
                if ((uint16)0 != (uint16)PwmEmiosSpecificParam->Pwm_Offset)
                {
                    tempRegB = ( (uint16)Period - (uint16)PwmEmiosSpecificParam->Pwm_Offset ) + (uint16)1U;
                }
                else
                {
                    tempRegB = (uint16)1U;
                }

                /* Calculate the A-register value */
                if (tempRegB > tempDuty)
                {
                    tempDuty = tempRegB - tempDuty;
                }
                else
                {
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_2 Implicit conversion of integer to smaller type */
                    tempDuty = ((uint16)Period - (uint16)tempDuty) + ((uint16)tempRegB - (uint16)1U);
                }
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
                Pwm_eMIOS_LLD_UpdateChannel_AB
                (
                    chIdx,
                    (uint32)tempDuty,
                    (uint32)tempRegB,
                    ChannelAddr,
                    ModuleAddr
                );
            }
            #else /* PWM_CHANGE_REGISTER_A_SWITCH */
            /* register B is updated on dutycycle change */
            tempDuty32 = ( (uint32) tempDuty + Offset ) % Period ;

            /* if (tempDuty + Pwm_Offset == Period) then
            * tempDuty32 will be 0
            * if the reference channel is MCB/OPWFMB then
            * we have [ 0x1, Period ]
            * if we program regB with 0 a compare event will
            * never be generated
            * in this case we program the Period value instead
            * and accept an error equal with 1 tick.
            */
            if ( 0x0U == tempDuty32 ) {

                tempDuty32 = Period;
            }

            /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
            Pwm_eMIOS_LLD_UpdateChannel_AB
            (
                chIdx,
                (uint32)(Offset + (uint32)1U),
                (uint32)tempDuty32,
                ChannelAddr,
                ModuleAddr
            );
            #endif /* PWM_CHANGE_REGISTER_A_SWITCH */
            REG_WRITE32
            (
                (ChannelAddr + EMIOS_ALTA_OFFSET),
                (uint32)((uint32)Pwm_Current_TriggerDelay[LogicalChannelNumber] + (uint32)1U)
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
        }
        #endif
    #endif /*PWM_FEATURE_OPWMT*/
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
        else
#ifdef PWM_FEATURE_OPWMCB
        #if (PWM_FEATURE_OPWMCB == STD_ON)
        if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
        #endif
    #endif
        {
         /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FEN_MASK );
            Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)tempDuty;
            /* Set to the configured polarity */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK),
                ((polarity_bit) & CCR_EDPOL_MASK )
                 /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
        }
        #endif
    #endif
    
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
    else{
            Pwm_eMIOS_LLD_UpdateChannel_AB
                        (
                            chIdx,
                            (uint32)(Period - (tempDuty/(uint32)2U)),
                            (uint32)PwmEmiosSpecificParam->Pwm_DeadTime,
                            ChannelAddr,
                            ModuleAddr
                        );
    }
    #endif
#endif
}
    /*
     * this part is needed only if Pwm_SetOutputToIdle is available
     */
    #if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
    /* check if the channel had been put to idle state - restart the channel */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    if (CCR_MODE_GPO == (REG_READ32(ChannelAddr + EMIOS_CCR_OFFSET) & CCR_MODE_MASK)) {
        /* set EDPOL */
        if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
            /* set internal counter value to 1 -
            *  internal counter only used in OPWFMB mode for now */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CCNTR_OFFSET) , 1);
            
        }

        else {
            #ifdef PWM_FEATURE_DAOC
                #if (PWM_FEATURE_DAOC == STD_ON)
                if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                    if (PWM_BUS_INTERNAL_COUNTER == ((uint32)ctrlRegVal & PWM_BUS_MASK))
                    {
                        /* set internal counter value to 0 -
                            internal counter  used in DAOC mode */
                       /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_WRITE32( ChannelAddr + EMIOS_CCNTR_OFFSET , 0);
                    }
                }
                #endif
            #endif
        }


        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        /* in OPWMT there is no edge selection for trigger */
        if (CCR_MODE_OPWMT != (ctrlRegVal & CCR_MODE_MASK)) {
            #endif
        #endif /* PWM_FEATURE_OPWMT */

        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            {
            VAR(uint8, AUTOMATIC) Notification =  Pwm_eMIOS_LLD_Notifications[LogicalChannelNumber];


                if ( 0xFFU != (uint8)Notification ) { /* if notifications enabled */

                    /* set notification edge in ctrlRegVal */

                    if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)Notification)
                    {
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                            /* notification on both edges */
                            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                            REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_DAOC_MODE_EDGE_SELECT_MASK );
                        } else
                        {
                        #endif
                    #endif
                            /* notification on both edges */
                            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                            REG_BIT_SET32( (uint32)&ctrlRegVal, CCR_MODE_EDGE_SELECT_MASK );
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        }
                        #endif
                    #endif
                   }
                    else
                    {
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                            REG_BIT_CLEAR32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_DAOC_MODE_EDGE_SELECT_MASK );
                        } else
                        {
                        #endif
                    #endif
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_CLEAR32( (uint32)&ctrlRegVal, CCR_MODE_EDGE_SELECT_MASK );
                        #ifdef PWM_FEATURE_DAOC
                            #if (PWM_FEATURE_DAOC == STD_ON)
                            }
                            #endif
                        #endif
                    }
                }
            }
        #endif /* PWM_NOTIFICATION_SUPPORTED */

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
        }
            #endif
        #endif /* PWM_FEATURE_OPWMT */
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
    if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
    {
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8, AUTOMATIC) Notification =  Pwm_eMIOS_LLD_Notifications[LogicalChannelNumber];

        if ( 0xFFU != (uint8)Notification )
        {
            if (PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)Notification)
            {
                daocnotification = (ctrlRegVal & CCR_MODE_MASK);
                daocnotification = daocnotification | CCR_DAOC_MODE_EDGE_SELECT_MASK;
             /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, daocnotification);
            }else{
             /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, ctrlRegVal & CCR_MODE_MASK );
            }
        }else{
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, ctrlRegVal & CCR_MODE_MASK );
        }
    #else
    REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, ctrlRegVal & CCR_MODE_MASK );
    #endif
    }
else{
    #endif
#endif
        if(CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
        {
         /* Invert the edge polarity */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK |CCR_MODE_MASK),
                (((~polarity_bit) & CCR_EDPOL_MASK ) | (ctrlRegVal & CCR_MODE_MASK))
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
        }
        else
        {
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK |CCR_MODE_MASK),
                ((polarity_bit & CCR_EDPOL_MASK ) | (ctrlRegVal & CCR_MODE_MASK))
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
        }
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
        }
    #endif
#endif

#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
        if (CCR_MODE_DAOC == ((uint32)ctrlRegVal & CCR_MODE_MASK)) {

            if (0x0U == tempDuty)
            {
                Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
                /* force match B */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );

            } else if (PWM_DUTY_CYCLE_100 == DutyCycle)
            {
                Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
                /* force match A */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );
            } else
            {   /* != (0%, 100%) */
                Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)tempDuty;
                if(PwmChannel->Pwm_IdleState == PwmChannel->Pwm_Polarity)
                {
                    /* force match A */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );
                } else
                {
                    /* force match B */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );
                }
            }

            Pwm_eMIOS_LLD_Period[LogicalChannelNumber] = PwmChannel->Pwm_DefaultPeriodValue;

            /* FLAG event enabled */
           /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FEN_MASK );
            
             Pwm_eMIOS_LLD_UpdateChannel_AB
            (
                chIdx,
                (uint32)0U,
                (uint32)tempDuty,
                ChannelAddr,
                ModuleAddr
            );
        }
    #endif
#endif
        /* force match on the first edge - this also sets the signal level */
        if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
            /* force match B */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32
                    (
                        ChannelAddr + EMIOS_CCR_OFFSET,
                        ( CCR_MODE_MASK | CCR_EDPOL_MASK | CCR_FORCMB_MASK),
                        ((ctrlRegVal & CCR_MODE_MASK) | ((uint32)~polarity_bit & CCR_EDPOL_MASK ) | CCR_FORCMB_MASK )
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    );
        } else
         #if defined (PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
            #if (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON)
        if ( (CCR_MODE_DAOC != (ctrlRegVal & CCR_MODE_MASK)) &&
             ((PWM_MODE_OPWMCB_LEAD_DEADTIME != (ctrlRegVal & CCR_MODE_MASK)) ||
             (PWM_MODE_OPWMCB_TRAIL_DEADTIME != (ctrlRegVal & CCR_MODE_MASK)))
            )
            #endif
        #endif
        {
            /* force match A */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
         REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                ( CCR_MODE_MASK | CCR_EDPOL_MASK |CCR_FORCMA_MASK ),
                ((ctrlRegVal & CCR_MODE_MASK) | ((uint32)polarity_bit & CCR_EDPOL_MASK ) | CCR_FORCMA_MASK )
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
        }
        #if defined (PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
            #if (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON)
        else
        {
          /* For Misra Compliance */
        }
            #endif
        #endif
        
  }
  #endif /* PWM_SET_OUTPUT_TO_IDLE_API */

    if ((uint8)STD_ON == useSection) {
        /* exit critical section for logical channel */
        Pwm_Schm_UnprotectResource(LogicalChannelNumber);
    }
}
#endif /* (PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SETCOUNTERBUS_API == STD_ON) */


/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief   This function sets the period and the dutycycle for the specified eMIOS channel
* @details This function is applicable for mode OPWFMB
*          - disable the interrupt and clear the interrupt flag
*          - sets the A register with value 0 and B register with period for 0% dutycycle
*          - sets the A and B registers with value period for 100% dutycycle
*          - for dutycycle not equal to 0% and 100% set the A register with value dutycycle
*            and B register with value period
*
* @param[in]     LogicalChannelNumber - pwm channel id
* @param[in]     Period        - pwm signal period value
* @param[in]     DutyCycle     - pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @api
* @implements DPWM04017
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetPeriodAndDuty(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(Pwm_PeriodType,  AUTOMATIC) Period,
        VAR(uint16,          AUTOMATIC) DutyCycle
    )
{

    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;

    VAR(Pwm_PeriodType, AUTOMATIC) tempDuty;

    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch; /* hw channel */
#if defined (PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
    #if (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON)
    VAR(Pwm_ChannelType, AUTOMATIC) mIdx;  /*  assigned eMIOS HW module index */
    #endif
#endif   
    VAR(Pwm_ChannelType, AUTOMATIC) chIdx;  /*  assigned eMIOS HW channel index */

    VAR(uint32, AUTOMATIC) ModuleAddr;  /*eMIOS module address*/
    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/

    VAR(uint32, AUTOMATIC) polarity_bit = 0U;
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
    VAR(uint32, AUTOMATIC) reg_A_value;
    VAR(uint32, AUTOMATIC) daocnotification;
        #endif
    #endif
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
    /*OPWMCB variables*/
    VAR(uint32, AUTOMATIC) dutyCorrection = 0U; /*duty correction for OPWMCB*/
    VAR(uint8, AUTOMATIC) mMasterBusIdx = 0xFFU;
    #endif
#endif

    /* start critical section for logical channel */
    Pwm_Schm_ProtectResource(LogicalChannelNumber);

    /* extract from conf structure the generic        channel information */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[LogicalChannelNumber];
    /* extract from conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam = &PwmChannel->SpecificCfg.EmiosCfg;

    ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;
    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

    /* store the associated hw channel ID */
    hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;
#if defined (PWM_FEATURE_DAOC) || defined (PWM_FEATURE_OPWMCB)
    #if (PWM_FEATURE_DAOC == STD_ON) || (PWM_FEATURE_OPWMCB == STD_ON)    
    mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);
    #endif
#endif     
    chIdx = (uint8)( hw_ch &  EMIOS_CH_MASK);

    /* save current channel control register config value in local variable */
    ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;
    
#if (PWM_GET_CHANNEL_STATE == STD_ON)
    Pwm_eMIOS_Duty_Cycle_Value[LogicalChannelNumber] = DutyCycle;
#endif /*PWM_GET_CHANNEL_STATE */
    /* to cover PWM150 */
     if( (Pwm_PeriodType)0x00 == Period )
    {
        Period = Pwm_eMIOS_LLD_Period[ LogicalChannelNumber]; /*keep the old period */
        DutyCycle = (uint16)0x00;
    }

    tempDuty = Pwm_eMIOS_LLD_ComputeDutycycle(Period, DutyCycle);
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
    if ((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) ||
        (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
    {
        /*get MCB up/down counter emios channel either 0, 8, 16, 24 or channel 23*/
        mMasterBusIdx = Pwm_eMIOS_LLD_GetMasterBus(mIdx, chIdx, ((uint32)ctrlRegVal & PWM_BUS_MASK));

        /* internal counter - period from configuration */
        /*divide by 2 and increment with 1 as counter always starts at 1 */
        Period = ((Period/(Pwm_PeriodType)2U) + (Pwm_PeriodType)(1U));
        /*Updated period value to EMIOSA register*/
         /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
         /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
        REG_WRITE32(EMIOS_CADR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), (Period));
    }
    else
    {
        /* For Misra Compliance */
    }
    #endif
#endif

        if (PWM_HIGH == PwmChannel->Pwm_Polarity) {
            polarity_bit = (uint32)0x80;
        } else
        {
            polarity_bit = (uint32)0;
        }

        /* only makes sense for OPWFMB as OPWMB/OPWMT channels get their period
       from the selected UC */
    /*makes sense for OPWMCB period changes*/
    if((CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) ||
       (PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) ||
       (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)))
    {
        /* save new period value */

         Pwm_eMIOS_LLD_Period[LogicalChannelNumber] = Period;

        /* Duty Cycle and Period update */
        if (((uint16)0x0000 == DutyCycle) || (0x0U == tempDuty))
        {

            #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
                /* no transitions in the signal */
                Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] &= ~((uint32)1<< EMIOS_CHANNEL_INDEX(hw_ch));

                /* at 0% dutycycle no edges are present in
                   the output signal thus no notifications */

                /* disable interrupt */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

                /* clear interrupt flag */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );

            #endif /* PWM_NOTIFICATION_SUPPORTED */
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
            if(CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
            {
    #endif
#endif
            /* 0%, RegA = 0 */
            /*
            * @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function
            */
            Pwm_eMIOS_LLD_UpdateChannel_AB
            (
                chIdx,
                (uint32)0U,
                (uint32)Period,
                ChannelAddr,
                ModuleAddr
            );
            #ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
            }
            else
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                dutyCorrection = REG_READ32(EMIOS_CADR(mIdx, chIdx));
                Pwm_eMIOS_LLD_UpdateChannel_AB
                    (
                        chIdx,
                        (uint32)(Pwm_eMIOS_LLD_Period[LogicalChannelNumber] + (uint32)1U),
                        (uint32)0U,
                        ChannelAddr,
                        ModuleAddr
                    );
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
                /* below code added to avoid limitation of 0% dutycycle(if call idle to 0%) */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                if (CCR_MODE_GPO == (REG_READ32(ChannelAddr + EMIOS_CCR_OFFSET) & CCR_MODE_MASK))
                {
                   REG_RMW32
                    (
                        ChannelAddr + EMIOS_CCR_OFFSET,
                        (CCR_EDPOL_MASK |CCR_MODE_MASK),
                        ((polarity_bit & CCR_EDPOL_MASK ) | (ctrlRegVal & CCR_MODE_MASK))
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    );
                }
#endif
                if(dutyCorrection == 0x1U)   
                {   /*this statement is required to avoid limitation of 0% duty cycle(if call 100% to 0%)*/                 
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_CLEAR32( (ModuleAddr+EMIOS_OUDR_OFFSET), (uint32)((uint32)1<<(chIdx)) );                        
                    if(PWM_MODE_OPWMCB_LEAD_DEADTIME == ((uint32)ctrlRegVal & CCR_MODE_MASK))
                    {
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );
                    }
                    else
                    {
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );
                    }
                }
            }
    #endif
#endif
        }
        else if (PWM_DUTY_CYCLE_100 == DutyCycle)
        {
        #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /* no transitions in the signal */
             Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] &= ~((uint32)1<< EMIOS_CHANNEL_INDEX(hw_ch));

            /* at 100% dutycycle no edges are present in
            the output signal thus no notifications */
            /* disable interrupt */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );

            /* clear interrupt flag */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );

          #endif /* PWM_NOTIFICATION_SUPPORTED */
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
            if(CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
            {
    #endif
#endif

            /* 100%, A = B */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
            Pwm_eMIOS_LLD_UpdateChannel_AB
            (
                chIdx,
                (uint32)Period,
                (uint32)Period,
                ChannelAddr,
                ModuleAddr
            );
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
            }
            else{
                Pwm_eMIOS_LLD_UpdateChannel_AB
                        (
                            chIdx,
                            (uint32)1U,
                            (uint32)0U,
                            ChannelAddr,
                            ModuleAddr
                        );
            }
    #endif
#endif
        }
        else
        {   /* != 0%, 100% */

            #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /*  transitions available in the signal */
             Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] |= ((uint32)1U<< EMIOS_CHANNEL_INDEX(hw_ch));

            /* if notifications are enabled and the dutycycle
             * in the next period is != 0%,100% (we have edges)
             * thus enable notifications - this is for the case
             * when we are coming from duty 0%,100% where
             * the notifications are disabled because we have no edges there
             */
             if (Pwm_eMIOS_LLD_Notifications[LogicalChannelNumber] != 0xFFU) {
                /* FLAG event enabled */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );
            }

            #endif /* PWM_NOTIFICATION_SUPPORTED */
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
            if(CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
            {
    #endif
#endif
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
            Pwm_eMIOS_LLD_UpdateChannel_AB
            (
                chIdx,
                (uint32)tempDuty,
                (uint32)Period,
                ChannelAddr,
                ModuleAddr
            );
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
            }else{
                 Pwm_eMIOS_LLD_UpdateChannel_AB
                    (
                        chIdx,
                        (uint32)(Pwm_eMIOS_LLD_Period[LogicalChannelNumber] - (tempDuty/(uint32)2U)),
                        (uint32)(PwmEmiosSpecificParam->Pwm_DeadTime / (uint32)2U),
                        ChannelAddr,
                        ModuleAddr
                    );
            }
    #endif
#endif

        }
    }
#ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
    else if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
    {
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FEN_MASK );
        Pwm_eMIOS_LLD_Period[LogicalChannelNumber] = Period;
        
        if (PWM_BUS_INTERNAL_COUNTER != ((uint32)ctrlRegVal & PWM_BUS_MASK))
        {
            Pwm_DAOC_LLD_Period[LogicalChannelNumber] = Pwm_eMIOS_LLD_GetCounterBusPeriod(mIdx,chIdx,(ctrlRegVal & CCR_BSL_MASK));
        }

        /* Duty Cycle and Period update */
        if (0x0U == tempDuty)
        {

            #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

                 /* no transitions in the signal */
                Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] &= ~((uint32)1<< EMIOS_CHANNEL_INDEX(hw_ch));
            #endif
            Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
            /* Set the polarity to configured value */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK),
                ((polarity_bit) & CCR_EDPOL_MASK )
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
        }
        else if (PWM_DUTY_CYCLE_100 == DutyCycle)
        {
            #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /* no transitions in the signal */
            Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] &= ~((uint32)1<< EMIOS_CHANNEL_INDEX(hw_ch));            

            #endif
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            reg_A_value = ((Pwm_eMIOS_LLD_Period[LogicalChannelNumber] +
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_READ32( EMIOS_CADR(mIdx, chIdx)))% Pwm_DAOC_LLD_Period[LogicalChannelNumber]);
            if (reg_A_value != (uint32)0) {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CADR(mIdx, chIdx) ,  reg_A_value);
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) ,  reg_A_value);
            } else
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CADR(mIdx, chIdx) , Pwm_DAOC_LLD_Period[LogicalChannelNumber] );
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) , Pwm_DAOC_LLD_Period[LogicalChannelNumber] );
            }
            Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
            /* Invert the edge polarity */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK),
                ((~polarity_bit) & CCR_EDPOL_MASK )
        /*
                    * @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer
                    */
            );
        }
        else
        {   /* != 0%, 100% */
            if (PWM_BUS_INTERNAL_COUNTER != ((uint32)ctrlRegVal & PWM_BUS_MASK))
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                if (Pwm_DAOC_LLD_Period[LogicalChannelNumber] < REG_READ32( EMIOS_CBDR(mIdx, chIdx)))
                {
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) ,  Pwm_DAOC_LLD_Period[LogicalChannelNumber]);
                }
            }

            #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
            /*  transitions available in the signal */
            Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)] |= ((uint32)1U<< EMIOS_CHANNEL_INDEX(hw_ch));
            #endif
            Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)tempDuty;
            /* Set to the configured polarity */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK),
                ((polarity_bit) & CCR_EDPOL_MASK )
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );

        }
    }
    else
    {
    /*empty else added to fix misra violation*/
    }
        #endif
    #endif  /*PWM_FEATURE_DAOC*/
        /*
         * this part is needed only if Pwm_SetOutputToIdle is available
         */
        #if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)

        /* check if the channel had been put to idle state - restart the channel */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        if (CCR_MODE_GPO == (REG_READ32(ChannelAddr + EMIOS_CCR_OFFSET) & CCR_MODE_MASK)) {
        /* set EDPOL */
        if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {

            /* set internal counter value to 1 - internal counter only used in
            * OPWFMB mode for now
            * we need to set it to 1 in order to avoid the case when
            * the channel is started with
            * register value B less than the counter value -
            * in this case will have to wait until
            * the counter reaches 0xFFFF
            */
            /* set internal counter to 1 */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( (ChannelAddr + EMIOS_CCNTR_OFFSET), 1);

        }
        #ifdef PWM_FEATURE_DAOC
            #if (PWM_FEATURE_DAOC == STD_ON)
            else if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                if (PWM_BUS_INTERNAL_COUNTER == ((uint32)ctrlRegVal & PWM_BUS_MASK))
                {
                    /* set internal counter value to 0 - internal counter  used in DAOC mode */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_WRITE32( ChannelAddr + EMIOS_CCNTR_OFFSET , 0);
                }

                /* set EDPOL */
            }
            else
            {
             /* For Misra Compliance */
            }
            #endif
        #endif/*PWM_FEATURE_DAOC*/

            #ifdef PWM_FEATURE_OPWMT
                #if (PWM_FEATURE_OPWMT == STD_ON)
                    /* in OPWMT there is no edge selection for trigger */
            if (CCR_MODE_OPWMT != (ctrlRegVal & CCR_MODE_MASK)) {
                #endif
            #endif /* PWM_FEATURE_OPWMT */

            #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
                {
                     VAR(uint8, AUTOMATIC) Notification = Pwm_eMIOS_LLD_Notifications[LogicalChannelNumber];

                    if ( 0xFFU != (uint8)Notification ) { /* if notifications enabled
                         set notification edge in ctrlRegVal */

                          if (PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)Notification) {
                        #ifdef PWM_FEATURE_DAOC
                            #if (PWM_FEATURE_DAOC == STD_ON)
                            if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                            /* notification on both edges */
                                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                                REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_DAOC_MODE_EDGE_SELECT_MASK );
                            } else
                            {
                            #endif
                        #endif
                            /* notification on both edges */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( (uint32)&ctrlRegVal, CCR_MODE_EDGE_SELECT_MASK );
                        #ifdef PWM_FEATURE_DAOC
                            #if (PWM_FEATURE_DAOC == STD_ON)
                            }
                            #endif
                        #endif

                        }
                        else {
                            /* notification on period event */
                        #ifdef PWM_FEATURE_DAOC
                            #if (PWM_FEATURE_DAOC == STD_ON)
                            if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                                REG_BIT_CLEAR32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_DAOC_MODE_EDGE_SELECT_MASK );
                            } else
                            {
                            #endif
                        #endif
                              /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                              REG_BIT_CLEAR32( (uint32)&ctrlRegVal, CCR_MODE_EDGE_SELECT_MASK );
                        #ifdef PWM_FEATURE_DAOC
                            #if (PWM_FEATURE_DAOC == STD_ON)
                            }
                            #endif
                        #endif
                        }
                    }
                }
            #endif /* PWM_NOTIFICATION_SUPPORTED */

            #ifdef PWM_FEATURE_OPWMT
                #if (PWM_FEATURE_OPWMT == STD_ON)
            }
                #endif
            #endif /* PWM_FEATURE_OPWMT */
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
    if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK))
    {
    #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        VAR(uint8, AUTOMATIC) Notification = Pwm_eMIOS_LLD_Notifications[LogicalChannelNumber];
        if ( 0xFFU != (uint8)Notification )
        {
            if (PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)Notification)
            {
                daocnotification = (ctrlRegVal & CCR_MODE_MASK);
                daocnotification = daocnotification | CCR_DAOC_MODE_EDGE_SELECT_MASK;
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, daocnotification);
            }else{
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, ctrlRegVal & CCR_MODE_MASK );
            }
        }else{
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, ctrlRegVal & CCR_MODE_MASK );
        }
    #else
    REG_RMW32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_MODE_MASK, ctrlRegVal & CCR_MODE_MASK );
    #endif
    }
else{
    #endif
#endif
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
        if(CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK))
        {
    #endif
#endif

            /* set mode */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
         REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK | CCR_MODE_MASK),
                (((~polarity_bit) & CCR_EDPOL_MASK ) | (ctrlRegVal & CCR_MODE_MASK))
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */                
            );
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
        }
        else
        {
         /* Set the mode and polarity for OPWMCB mode */
            REG_RMW32
            (
                ChannelAddr + EMIOS_CCR_OFFSET,
                (CCR_EDPOL_MASK | CCR_MODE_MASK),
                ((polarity_bit & CCR_EDPOL_MASK) | (ctrlRegVal & CCR_MODE_MASK))
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            );
        }
    #endif
#endif
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
        }
    #endif
#endif


            #ifdef PWM_FEATURE_DAOC
                #if (PWM_FEATURE_DAOC == STD_ON)
            if (CCR_MODE_DAOC == ((uint32)ctrlRegVal & CCR_MODE_MASK)) {
                 Pwm_eMIOS_LLD_Period[LogicalChannelNumber] = Period;

                if (0x0U == tempDuty)
                {
                     Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
                    /* force match B */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );

                } else if (PWM_DUTY_CYCLE_100 == DutyCycle)
                {
                    Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)0;
                    /* force match A */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );

                } else
                {   /* != (0%, 100%) */
                    Pwm_DAOC_LLD_Duty[LogicalChannelNumber] = (uint16)tempDuty;
                    if(PwmChannel->Pwm_IdleState == PwmChannel->Pwm_Polarity)
                    {
                        /* force match A */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMA_MASK );
                    } else
                    {
                        /* force match B */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FORCMB_MASK );
                    }
                }

                /* FLAG event enabled */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                 REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_FEN_MASK );

                 Pwm_eMIOS_LLD_UpdateChannel_AB
                 (
                    chIdx,
                    (uint32)0U,
                    (uint32)tempDuty,
                    ChannelAddr,
                    ModuleAddr
                 );
            }
            #endif
        #endif/*PWM_FEATURE_DAOC*/
        if (CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) {
            /* force match on the first edge - this also sets the signal level */
            /* force match B */
        REG_RMW32
                    (
                        ChannelAddr + EMIOS_CCR_OFFSET,
                        ( CCR_MODE_MASK | CCR_EDPOL_MASK | CCR_FORCMB_MASK),
                        ((ctrlRegVal & CCR_MODE_MASK) | ((uint32)~polarity_bit & CCR_EDPOL_MASK ) | CCR_FORCMB_MASK )
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    );
            }

        }
      #endif /* PWM_SET_OUTPUT_TO_IDLE_API */

    /* exit critical section for logical channel */
    Pwm_Schm_UnprotectResource(LogicalChannelNumber);

}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief   This function sets the generated eMIOS channel to the idle value configured
* @details This function
*          - puts the channel in High or Low state by writing to the Control Register
*            based on the configured Idle state
*          - puts the Emios channel into GPIO mode
*
* @param[in]     LogicalChannelNumber - pwm channel id
*
* @api
*
* @implements DPWM04016
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetOutputToIdle(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
    )
{

    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
#if (PWM_GET_CHANNEL_STATE == STD_ON)
    Pwm_eMIOS_Duty_Cycle_Value[LogicalChannelNumber] = 0U;
#endif /*PWM_GET_CHANNEL_STATE */
    /* start critical section for logical channel */
    Pwm_Schm_ProtectResource(LogicalChannelNumber);

    /* extract from conf structure the generic        channel information */
    /*
    * @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used
    */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ LogicalChannelNumber ];
    /* extract from conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;

    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

    /* Put the channel in Idle state */
    if ( PWM_HIGH == PwmChannel->Pwm_IdleState ) {
      /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
      REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );

    }
    else {

        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_EDPOL_MASK );
    }
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_RMW32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_MODE_MASK, CCR_MODE_GPO );

    /* exit critical section for logical channel */
    Pwm_Schm_UnprotectResource(LogicalChannelNumber);

}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief   This function returns the pwm signal output state
* @details This function returns the PWM Channel state as High or Low
*
* @param[in]     LogicalChannelNumber - pwm channel id
*
* @return        Pwm_OutputStateType - pwm signal output logic value
* @retval        PWM_LOW - The output state of PWM channel is low
* @retval        PWM_HIGH - The output state of PWM channel is high
*
* @api
*
* @implements DPWM04011
*/

FUNC (Pwm_OutputStateType, PWM_CODE) Pwm_eMIOS_LLD_GetOutputState(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
    )
{

    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(Pwm_OutputStateType, AUTOMATIC) output_state;

    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
    /* start critical section for logical channel */
    Pwm_Schm_ProtectResource(LogicalChannelNumber);

    /* extract from conf structure the EMIOS specific channel information */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    PwmEmiosSpecificParam=&Pwm_eMIOS_Cfg->ChannelsPtr[LogicalChannelNumber].SpecificCfg.EmiosCfg;

    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    if (0U != (REG_READ32(ChannelAddr + EMIOS_CSR_OFFSET) & CSR_UCOUT_MASK)) {
        output_state = PWM_HIGH;
    } else {
        output_state = PWM_LOW;
    }

    /* exit critical section for logical channel */
    Pwm_Schm_UnprotectResource(LogicalChannelNumber);

    return output_state;

}
#endif /* PWM_GET_OUTPUT_STATE_API */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief   This function disables the user notifications
* @details This function
*          - enables the notification
*          - sets the Edge select bit in control register if notification is both edges
*          - clears the Edge select bit in control register if notification is both edges
*          - clears the interrupt flag and enables the FLAG event for OPWMB and OPWFMB modes
*          - clear interrupt flag in Status register and clear the DMA bit in
*            Control register for OPWMT mode
*
*
* @param[in]     LogicalChannelNumber - pwm channel id
* @param[in]     Notification  - notification type to be enabled
*
* @api
*
* @implements DPWM04010
*/
/*
* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement, 
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_EnableNotification(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification
    )
{

    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;

    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch;  /* hw channel */

    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
    /* start critical section for logical channel */
    Pwm_Schm_ProtectResource(LogicalChannelNumber);

    /* extract from conf structure the generic channel information */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ LogicalChannelNumber ];

    /* extract from conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;

    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

    /* save current channel control register config value in local variable */
    ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;


    #if (PWM_DEV_ERROR_DETECT == STD_ON)

    /* check for eMIOS triggering limitations */
    /* invalid flag generation modes for OPWFMB  */
    if ((CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) &&
        ((PWM_HIGH == PwmChannel->Pwm_Polarity) && (PWM_FALLING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );
    /* invalid flag generation modes for OPWFMB  */
    } else if ((CCR_MODE_OPWFMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) &&
        ((PWM_LOW == PwmChannel->Pwm_Polarity) && (PWM_RISING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );
    /* invalid flag generation modes for OPWMB  */
    } else if ((CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) &&
        ((PWM_HIGH == PwmChannel->Pwm_Polarity) && (PWM_RISING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );
    /* invalid flag generation modes for OPWMB  */
    } else if ((CCR_MODE_OPWMB_FLAG_B == (ctrlRegVal & CCR_MODE_MASK)) &&
        ((PWM_LOW == PwmChannel->Pwm_Polarity) && (PWM_FALLING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );
    }
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
    /* invalid flag generation modes for DAOC  */
    else if ((CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) &&
        ((PWM_HIGH == PwmChannel->Pwm_Polarity) && (PWM_RISING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );
    /* invalid flag generation modes for DAOC  */
    } else if ((CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) &&
        ((PWM_LOW == PwmChannel->Pwm_Polarity) && (PWM_FALLING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );
    }
    #endif
#endif
#ifdef PWM_FEATURE_OPWMCB
    #if (PWM_FEATURE_OPWMCB == STD_ON)
    /* invalid flag generation modes for OPWMCB  */
    else if (((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) ||
            (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK))) &&
        ((PWM_HIGH == PwmChannel->Pwm_Polarity) && (PWM_RISING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );

    }
    else if (((PWM_MODE_OPWMCB_LEAD_DEADTIME == (ctrlRegVal & CCR_MODE_MASK)) ||
            (PWM_MODE_OPWMCB_TRAIL_DEADTIME == (ctrlRegVal & CCR_MODE_MASK))) &&
        ((PWM_LOW == PwmChannel->Pwm_Polarity) && (PWM_FALLING_EDGE == Notification)))
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_ENABLENOTIFICATION_ID,
            (uint8) PWM_E_PARAM_NOTIFICATION
        );
    }
    #endif
#endif
    else {
    #endif /* PWM_DEV_ERROR_DETECT */

        /* store the associated hw channel ID */
        hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;


        /* note that notifications are enabled for this channel */
        Pwm_eMIOS_LLD_Notifications[ LogicalChannelNumber ] = (uint8)Notification;

        /* only enable notifications if channel is not in idle state */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        if (CCR_MODE_GPO != (REG_READ32(ChannelAddr + EMIOS_CCR_OFFSET) & CCR_MODE_MASK))
        {

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)
            /* activation edge not available in OPWMT */
            if (CCR_MODE_OPWMT != (ctrlRegVal & CCR_MODE_MASK)) {
            #endif
        #endif /* PWM_FEATURE_OPWMT */
       /*
                * transitions are present in the signal ( duty != 0%,100% )
                * dutycycle doesn't affect trigger in OPWMT mode
                */
                if (((uint32)1U<< EMIOS_CHANNEL_INDEX(hw_ch)) & Pwm_eMIOS_LLD_DutyState[ EMIOS_MODULE_INDEX(hw_ch)])
                {
                    /* Change activation edge if required */

                    if (PWM_BOTH_EDGES == Notification) {
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                            /* notification on both edges */
                            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                            REG_BIT_SET32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_DAOC_MODE_EDGE_SELECT_MASK );
                        } else
                        {
                        #endif
                    #endif
                        /* notification on both edges */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_MODE_EDGE_SELECT_MASK );
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        }
                        #endif
                    #endif
                    } else {
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        if (CCR_MODE_DAOC == (ctrlRegVal & CCR_MODE_MASK)) {
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_CLEAR32( ChannelAddr + EMIOS_CCR_OFFSET, CCR_DAOC_MODE_EDGE_SELECT_MASK);
                        } else
                        {
                        #endif
                    #endif
                        /* notification on period event */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_MODE_EDGE_SELECT_MASK);
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        }
                        #endif
                    #endif
                    }
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                        if (CCR_MODE_DAOC != (ctrlRegVal & CCR_MODE_MASK)) {
                        #endif
                    #endif
                    /* clear interrupt flag */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );
                    #ifdef PWM_FEATURE_DAOC
                        #if (PWM_FEATURE_DAOC == STD_ON)
                            }
                        #endif
                    #endif
                    /* FLAG event enabled */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );
                }

        #ifdef PWM_FEATURE_OPWMT
            #if (PWM_FEATURE_OPWMT == STD_ON)

            } else { /* OPWMT */
            /* clear interrupt flag */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );

                /* FLAG assigned to interrupt request */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_DMA_MASK );
            }

            #endif
        #endif /* PWM_FEATURE_OPWMT */

        }

    #if (PWM_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* PWM_DEV_ERROR_DETECT  */

    /* exit critical section for logical channel */
    Pwm_Schm_UnprotectResource(LogicalChannelNumber);

}
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief   This function disables the user notifications
* @details This function
*          - disables the notification
*          - disables the FEN bit in Control register for OPWMB and OPWFMB modes
*          - clear interrupt flag in Status register and Set the DMA bit in
*            Control register for OPWMT mode
*
* @param[in]     LogicalChannelNumber - pwm channel id
*
* @api
*
* @implements DPWM04009
*/
/*
* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement, 
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_DisableNotification(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
    )
{
    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam;

    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
    /* start critical section for logical channel */
    Pwm_Schm_ProtectResource(LogicalChannelNumber);

    /* extract from conf structure the generic channel information */
    /*
    * @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used
    */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ LogicalChannelNumber ];

    /* extract from conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam = &PwmChannel->SpecificCfg.EmiosCfg;

    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;


    #ifdef PWM_FEATURE_OPWMT
        #if (PWM_FEATURE_OPWMT == STD_ON)
            if (CCR_MODE_OPWMT != (PwmEmiosSpecificParam->Pwm_ParamValue & CCR_MODE_MASK)) {
        #endif
    #endif /* PWM_FEATURE_OPWMT */
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
    if (CCR_MODE_DAOC != (PwmEmiosSpecificParam->Pwm_ParamValue & CCR_MODE_MASK)) {
        #endif
    #endif
     /* disable interrupt */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FEN_MASK );
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
    }
        #endif
    #endif
    /* no need to clear the flag as it will be cleared in
     * EnableNotification before interrupts are enabled
     */

    #ifdef PWM_FEATURE_OPWMT
        #if (PWM_FEATURE_OPWMT == STD_ON)
            } else {

                /* OPWMT */
                /* clear interrupt flag */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( (ChannelAddr + EMIOS_CSR_OFFSET), CSR_FLAG_BIT );

                /* FLAG event routed to CTU */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_DMA_MASK );
            }
        #endif
    #endif /* PWM_FEATURE_OPWMT */

     /* notifications disabled */
    Pwm_eMIOS_LLD_Notifications[LogicalChannelNumber] = 0xFFU;

    /* exit critical section for logical channel */
    Pwm_Schm_UnprotectResource(LogicalChannelNumber);

}
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_SETCOUNTERBUS_API == STD_ON)
/**
* @brief   Implementation specific function to set the frequency of pwm channel
*          running on PWM_MODE_OPWMB or PWM_MODE_OPWMT mode
* @details This function
*          - changes the counter bus from Bus A to Bus Diverse or vice versa
*          - Bus selection bits will be configured in Control register
*          - update dutycycle to the configured default value
*
* @param[in] LogicalChannelNumber - pwm channel id
* @param[in] Bus           - the eMIOS bus to change to
*
* @api
*
* @implements   DPWM04018
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetCounterBus(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(uint32, AUTOMATIC)          Bus
    )
{
    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam;

    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch;  /* hw channel */

    VAR(Pwm_ChannelType, AUTOMATIC) mIdx;   /*  assigned eMIOS HW module  index */
    VAR(Pwm_ChannelType, AUTOMATIC) chIdx;  /*  assigned eMIOS HW channel index */

    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
    /* start critical section for logical channel */
    Pwm_Schm_ProtectResource(LogicalChannelNumber);

    /* extract from conf structure the generic channel information */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ LogicalChannelNumber ];

    /* extract from generic conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam = &PwmChannel->SpecificCfg.EmiosCfg;

    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;
    /* store the associated hw channel ID */
    hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;


    mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);
    chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);

    /* update the channel period with the period of the new selected counter bus */
    Pwm_eMIOS_LLD_Period[LogicalChannelNumber] = Pwm_eMIOS_LLD_GetCounterBusPeriod(mIdx, chIdx, Bus);

    /* set the new counter bus */
    if (PWM_BUS_DIVERSE == Bus)
    {
        /* select bus Diverse */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32((ChannelAddr+EMIOS_CCR_OFFSET), CCR_BSL_MASK, CCR_BSL_BUS_DIVERSE << CCR_BSL_SHIFT);
    }
    else if (PWM_BUS_A == Bus)
    {
        /* select bus A */
        /*
        * @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer
        */
        REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_BSL_MASK );
    }
    else
    {
        /* select bus F */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32((ChannelAddr+EMIOS_CCR_OFFSET), CCR_BSL_MASK, CCR_BSL_BUS_F << CCR_BSL_SHIFT);
    }
    /*
    * @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function
    */
    /* update dutycycle to the configured default value, do not enable the critical section
       as it's already on */
    Pwm_eMIOS_LLD_SetDutyCycle(
        LogicalChannelNumber, PwmChannel->Pwm_DefaultDutyCycleValue,(uint8)STD_OFF
    );

    /* exit critical section for logical channel */
    Pwm_Schm_UnprotectResource(LogicalChannelNumber);

}
#endif /* PWM_SETCOUNTERBUS_API */


/*===============================================================================================*/
#if (PWM_SETCHANNELOUTPUT_API == STD_ON)
/**
* @brief   Implementation specific function to set the state of the PWM pin as requested
*         for the current cycle
* @details This function is useful to to set the state of the PWM pin as requested
*          for the current cycle and continues
*          with normal PWM operation from the next cycle
*          - OPWFMB: if the passed state is Active, force a match on B Register otherwise
*            force a match on A Register
*          - OPWMB or OPWMT: if the passed state is Active, force a match on A Register
*            otherwise force a match on B Register
*          - the force match is done by setting the FORCMA and FORCMB bits is Control Register
*
* @param[in] LogicalChannelNumber - pwm channel id
* @param[in] State           - Active/Inactive state of the channel
*
* @@api
*
* @implements   DPWM04014
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetChannelOutput(
        VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
        VAR(Pwm_StateType, AUTOMATIC)          State
    )
{
    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;

    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/
    /* start critical section for logical channel */
    Pwm_Schm_ProtectResource(LogicalChannelNumber);

    /* extract from conf structure the generic channel information */
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ LogicalChannelNumber ];

    /* extract from generic conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam = &PwmChannel->SpecificCfg.EmiosCfg;

    ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

    /* save current channel control register config value in local variable */
    ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;

    if (CCR_MODE_OPWFMB_FLAG_B == ((uint32)ctrlRegVal & CCR_MODE_MASK)) {
        /* OPWFMB */
        if (PWM_ACTIVE == State) {
            /* force match B */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FORCMB_MASK );
        }
        else {
            /* force match A */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FORCMA_MASK );
        }
    }
    else {
        /* OPWMB / OPWMT */
        if (PWM_ACTIVE == State) {
            /* force match A */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FORCMA_MASK );
        }
        else {
            /* force match B */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_FORCMB_MASK );
        }
    }

    /* exit critical section for logical channel */
    Pwm_Schm_UnprotectResource(LogicalChannelNumber);

}
#endif /* PWM_SETCHANNELOUTPUT_API */


/*===============================================================================================*/
#if (PWM_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief Implementation specific function to set the channel prescaler.
* @details This function is useful to set the value of the channel prescaler.
*          For this purpose, the following actions are taken for each configured channel
*          running on internal counter bus:
*          - write 0 at both GPREN bit in EMIOSMCR register and UCPREN bit in EMIOSC[n] register,
*            thus disabling prescalers;
*          - write the desired value for prescaling rate at UCPRE[0:1] bits in EMIOSC[n] register;
*          - enable channel prescaler by writing 1 at UCPREN bit in EMIOSC[n] register;
*          - enable global prescaler by writing 1 at GPREN bit in EMIOSMCR register.
*
* @param[in] Prescaler - prescaler type
*
* @api
*
* @implements   DPWM04013
*/
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SelectPrescaler(
        VAR(Pwm_SelectPrescalerType, AUTOMATIC) Prescaler
    )
{
    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;

    VAR(Pwm_EmiosCtrlParamType, AUTOMATIC) ctrlRegVal;

    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch; /* hw channel */
    VAR(Pwm_ChannelType, AUTOMATIC) ch = (Pwm_ChannelType )0; /* logical channel */
    VAR(Pwm_ChannelType, AUTOMATIC) chIdx;  /* assigned eMIOS HW channel index */

    VAR(uint32, AUTOMATIC) mcrRegVal;

    VAR(uint32, AUTOMATIC) ModuleAddr;  /*eMIOS module address*/
    VAR(uint32, AUTOMATIC) ChannelAddr; /*address of unified channel*/

    VAR(Pwm_ChannelType, AUTOMATIC) mIdx;
    VAR(uint8, AUTOMATIC) mMasterBusIdx;
    VAR(uint8, AUTOMATIC) mMasterBusUse[PWM_EMIOS_HW_CHANNELS];

    for (ch=0U; ch < (Pwm_ChannelType)PWM_EMIOS_HW_CHANNELS; ch++)
    {
      mMasterBusUse[ch] = (uint8)0xFFU;
    }

    for (ch=0U; ch < Pwm_eMIOS_Cfg->ChannelCount; ch++)  {
        /* only handle EMIOS channels */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
        if (PWM_EMIOS_CHANNEL == Pwm_eMIOS_Cfg->ChannelsPtr[ch].IpType)
        {

            /* extract from conf structure the generic channel information */
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
            PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[ch];

            /* extract from conf structure the EMIOS specific channel information */
            PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;
            ModuleAddr = PwmEmiosSpecificParam->Pwm_Emios_ModuleAddr;
            ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

            hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;
            chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);
            mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);

            /* save current channel control register config value in local variable */
            ctrlRegVal = PwmEmiosSpecificParam->Pwm_ParamValue;

            if (PWM_BUS_INTERNAL_COUNTER == ((uint32)ctrlRegVal & PWM_BUS_MASK))
            {
                /* only write UCDIS register if it's available */
                #ifdef EMIOS_UCDIS
                    /* enable unified channel to make registers writable */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_CLEAR32( (ModuleAddr+EMIOS_UCDIS_OFFSET), (uint32)((uint32)1<<(chIdx)));
                #endif /* EMIOS_UCDIS */

                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                mcrRegVal = REG_READ32(ModuleAddr+EMIOS_MCR_OFFSET);

                /* disable global prescaler - this will stop the EMIOS clock */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ModuleAddr+EMIOS_MCR_OFFSET), MCR_GPREN_MASK );

                /* disable prescaler - this will stop the internal counter */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_UCPREN_MASK );

                /* set internal counter to 1 */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( (ChannelAddr + EMIOS_CCNTR_OFFSET), 1);

                /* select internal counter bus */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_BSL_MASK );

                if (PWM_NORMAL == Prescaler)
                {
                    /* set the prescaler divide value */
                    REG_RMW32
                    (
                        (ChannelAddr + EMIOS_CCR_OFFSET),
                        CCR_UCPRE_MASK,
                        ctrlRegVal & CCR_UCPRE_MASK
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    );
                }
                else if (PWM_ALTERNATE == Prescaler)
                {
                    /* set the alternate prescaler divide value */
                    REG_RMW32
                    (
                        (ChannelAddr + EMIOS_CCR_OFFSET),
                        CCR_UCPRE_MASK,
                        PwmEmiosSpecificParam->Pwm_Prescaler_Alternate & CCR_UCPRE_MASK
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    );
                }
                else
                {
                    /* Do nothing. Empty else added to fix MISRA Violation*/
                }

                /* enable prescaler - this will start the internal counter */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_SET32( (ChannelAddr + EMIOS_CCR_OFFSET), CCR_UCPREN_MASK );

                if ((mcrRegVal & MCR_GPREN_MASK) == MCR_GPREN_MASK)
                {
                    /* enable global prescaler */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( (ModuleAddr+EMIOS_MCR_OFFSET), MCR_GPREN_MASK );
                }

            }
            else
            {
              mMasterBusIdx = Pwm_eMIOS_LLD_GetMasterBus(mIdx, chIdx, ((uint32)ctrlRegVal & PWM_BUS_MASK));
              if(mMasterBusUse[mMasterBusIdx] == (uint8)0xFFU) /* This master bus is not use */
              {
                /* Now, this master bus is use for OPWMMCB mode */
                mMasterBusUse[mMasterBusIdx] = (uint8)1U;

                /* only write UCDIS register if it's available */
                #ifdef EMIOS_UCDIS
                /* enable unified channel to make registers writable */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32((ModuleAddr+EMIOS_UCDIS_OFFSET), \
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                                (uint32)((uint32)1<<(EMIOS_CHANNEL_INDEX(mMasterBusIdx))));
                #endif
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                mcrRegVal = REG_READ32(ModuleAddr+EMIOS_MCR_OFFSET);

                /* disable global prescaler - this will stop the EMIOS clock */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_BIT_CLEAR32((ModuleAddr+EMIOS_MCR_OFFSET), MCR_GPREN_MASK );

                /* disable prescaler - this will stop the internal counter */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                REG_BIT_CLEAR32(EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_UCPREN_MASK );
                /* set internal counter to 1 */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                REG_WRITE32( EMIOS_CCNTR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), 1);

                /* select internal counter bus */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                REG_BIT_SET32( EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_BSL_MASK );

                if (PWM_NORMAL == Prescaler)
                {
                    /* set the prescaler divide value */
                    REG_RMW32
                    (
                        EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)),
                        CCR_UCPRE_MASK,
                        ctrlRegVal & CCR_UCPRE_MASK
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    );
                }
                else if (PWM_ALTERNATE == Prescaler)
                {
                    /* set the alternate prescaler divide value */
                    REG_RMW32
                    (
                        EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)),
                        CCR_UCPRE_MASK,
                        PwmEmiosSpecificParam->Pwm_Prescaler_Alternate & CCR_UCPRE_MASK
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                        /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                    );
                }
                else
                {
                    /* Do nothing. Empty else added to fix MISRA Violation*/
                }

                /* enable prescaler - this will start the internal counter */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_6 Cast of complex integer expression to larger type */
                REG_BIT_SET32( EMIOS_CCR(mIdx, EMIOS_CHANNEL_INDEX(mMasterBusIdx)), CCR_UCPREN_MASK );

                if ((mcrRegVal & MCR_GPREN_MASK) == MCR_GPREN_MASK)
                {
                    /* enable global prescaler */
                    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                    REG_BIT_SET32( (ModuleAddr+EMIOS_MCR_OFFSET), MCR_GPREN_MASK );
                }
              }
              else
              {
              /* Do nothing. Empty else added to fix MISRA Violation*/
              }
            }
        } /* end if EMIOS channel */
    } /* end for */
}

#endif /* PWM_DUAL_CLOCK_MODE */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief   Interrupt service routine to process the eMIOS interrupt
* @details This function
*         - clears the unified channel interrupt flag bit in Control register
*         - calls the LLD layer handler
*
* @param[in]     hw_ch_id      EMIOS channel ID that triggered the interrupt
* @implements DPWM04501
* @api
*/
/* @violates @ref Pwm_eMIOS_LLD_C_REF_12 external could be made static */
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_ProcessInterrupt( VAR(Pwm_ChannelType, AUTOMATIC) hw_ch_id )
{
    VAR(Pwm_ChannelType, AUTOMATIC) ch_id;  /*  logical channel */

    VAR(Pwm_ChannelType, AUTOMATIC) mIdx;   /*  assigned eMIOS HW module  index */
    VAR(Pwm_ChannelType, AUTOMATIC) chIdx;  /*  assigned eMIOS HW channel index */
    VAR(Pwm_EdgeNotificationType, AUTOMATIC) Notification;

    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
    VAR(uint32, AUTOMATIC) ch_mode;   /* channel mode */
    VAR(uint32, AUTOMATIC) edpol_value;   /* edge polarity value */
    VAR(uint32, AUTOMATIC) ucout_value;   /* ucout bit value */
    VAR(uint32, AUTOMATIC) reg_A_value;   /* store the calculated register A value */
    VAR(uint32, AUTOMATIC) reg_B_value;   /* store the calculated register B value */
        #endif
    #endif
    /* store the associated hw channel ID */

    mIdx  = (uint8)((uint8)hw_ch_id >> EMIOS_MOD_SHIFT);
    chIdx = (uint8)((uint8)hw_ch_id &  EMIOS_CH_MASK);
    /* get logical channel ID */
    ch_id = Pwm_eMIOS_LLD_RevHardwareTable[hw_ch_id];    
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    ch_mode = ( REG_READ32(EMIOS_CCR(mIdx, chIdx)) & CCR_MODE_MASK );
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    edpol_value = ( REG_READ32(EMIOS_CCR(mIdx, chIdx)) & CCR_EDPOL_MASK );
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    ucout_value = ( REG_READ32(EMIOS_CSR(mIdx, chIdx)) & CSR_UCOUT_MASK );
        #endif
    #endif
    /* clear unified channel interrupt flag */
    /*
    * @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer
    */
    REG_WRITE32( EMIOS_CSR(mIdx, chIdx), CSR_FLAG_BIT );
    #ifdef PWM_FEATURE_DAOC
        #if (PWM_FEATURE_DAOC == STD_ON)

    if ( CCR_MODE_DAOC == ch_mode )
    {
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        reg_A_value = (((Pwm_eMIOS_LLD_Period[ch_id] - Pwm_DAOC_LLD_Duty[ch_id]) + 
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_2 Implicit conversion of integer to smaller type */
                         REG_READ32(EMIOS_CBDR(mIdx,chIdx)))%Pwm_DAOC_LLD_Period[ch_id]);
        if (reg_A_value != (uint32)0U) {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( EMIOS_CADR(mIdx, chIdx) ,  reg_A_value);

        } else
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( EMIOS_CADR(mIdx, chIdx) ,  Pwm_DAOC_LLD_Period[ ch_id ]);
        }
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
        reg_B_value = ((Pwm_eMIOS_LLD_Period[ch_id]+REG_READ32(EMIOS_CBDR(mIdx,chIdx)))%
                      Pwm_DAOC_LLD_Period[ch_id]);

        if (reg_B_value != (uint32)0U) {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) ,  reg_B_value);
        } else
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer  */
            REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) ,  Pwm_DAOC_LLD_Period[ ch_id ]);
        }
    } else
    if(CCR_MODE_DAOC_BOTH == ch_mode )
    {
        if( edpol_value != (ucout_value<<6) ) {
          /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
          reg_A_value = (((Pwm_eMIOS_LLD_Period[ch_id] - Pwm_DAOC_LLD_Duty[ch_id]) + 
          /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
          /* @violates @ref Pwm_eMIOS_LLD_C_REF_2 Implicit conversion of integer to smaller type */
                         REG_READ32(EMIOS_CBDR(mIdx,chIdx)))%Pwm_DAOC_LLD_Period[ch_id]);
            if (reg_A_value != (uint32)0U) {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CADR(mIdx, chIdx) ,  reg_A_value);
            } else
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CADR(mIdx, chIdx) ,  Pwm_DAOC_LLD_Period[ ch_id ]);
            }
        } else
        {
            /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
            reg_B_value = ((Pwm_eMIOS_LLD_Period[ch_id]+REG_READ32(EMIOS_CBDR(mIdx,chIdx)))%
                      Pwm_DAOC_LLD_Period[ch_id]);
            if (reg_B_value != (uint32)0U) {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) ,  reg_B_value);
            } else
            {
                /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                REG_WRITE32( EMIOS_CBDR(mIdx, chIdx) ,  Pwm_DAOC_LLD_Period[ ch_id ]);
            }
        }
    }
    else
    {
     /* For Misra Compliance */
    }
        #endif
    #endif
    /* get logical channel ID */
    
    Notification = (Pwm_EdgeNotificationType)Pwm_eMIOS_LLD_Notifications[ ch_id ];

    /* Call Common Interrupt Routine */
    if ( 0xffU != ch_id ) {
        if (Pwm_eMIOS_Cfg != NULL_PTR){
#ifdef PWM_FEATURE_DAOC
    #if (PWM_FEATURE_DAOC == STD_ON)
        if ( (CCR_MODE_DAOC == ch_mode) || (CCR_MODE_DAOC_BOTH == ch_mode) )
        {
            if( Pwm_DAOC_LLD_Duty[ch_id] != 0x0U )
            {
                if ( 0xFFU != (uint8)Notification )
                {
        /*  @violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used  */
                    Pwm_eMIOS_Cfg->ChannelsPtr[ ch_id ].Pwm_Channel_Notification();
                }
            }
        }
        else
    #endif
#endif
        {
                if ( 0xFFU != (uint8)Notification )
                {
     /* Note: For PWM, interrupts are not enabled if the notification function is
            * a NULL_PTR. Therefore the code does not check for NULL_PTR before calling
            * the notification function
            */
         /*@violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
            Pwm_eMIOS_Cfg->ChannelsPtr[ ch_id ].Pwm_Channel_Notification();
                }
        }

        } else { /* Pwm_eMIOS_Cfg == NULL_PTR */
            /* if IRQs are received even if the driver is not initialized then report the error to DEM */
                #if (PWM_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                if((uint32)STD_ON == Pwm_E_UnexpectedIrqCfg.state)
                {
                    Dem_ReportErrorStatus((Dem_EventIdType)Pwm_E_UnexpectedIrqCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                #endif
        /* @violates @ref Pwm_eMIOS_LLD_C_REF_20 if ... else if shall be terminated with an else clause */
        }
    } else {
        /* IRQ received for HW channel but corresponding logical channel is not known -
           channel not configured by pwm driver */
                #if (PWM_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                if((uint32)STD_ON == Pwm_E_UnexpectedIrqCfg.state)
                {
                    Dem_ReportErrorStatus((Dem_EventIdType)Pwm_E_UnexpectedIrqCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                #endif
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_20 if ... else if shall be terminated with an else clause */
    }

}
#endif /* PWM_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
#ifdef PWM_FEATURE_OPWMT
    #if (PWM_FEATURE_OPWMT == STD_ON)
/**
@brief   Implementation specific function to set the trigger delay  for  pwm channel
         running on PWM_MODE_OPWMT mode
         - write trigger delay to alternate A register for OPWMT mode

@param[in] LogicalChannelNumber - pwm channel id
@param[in] TriggerDelay         - triggerdelay

@implements DPWM04502
*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_SetTriggerDelay
                      (
                          VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber,
                          VAR(Pwm_PeriodType, AUTOMATIC)  TriggerDelay
                      )
{


    /* Pwm channel generic parameters from config structure */
    P2CONST(Pwm_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmChannel = NULL_PTR;
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_EMIOS_ChannelConfigType, AUTOMATIC, PWM_APPL_CONST) PwmEmiosSpecificParam= NULL_PTR;
    VAR(uint32, AUTOMATIC) ChannelAddr;

#if (PWM_DEV_ERROR_DETECT == STD_ON)   
    VAR(Pwm_ChannelType, AUTOMATIC) hw_ch; /* hw channel */
    VAR(Pwm_ChannelType, AUTOMATIC) mIdx; /*  assigned eMIOS HW channel index */
    VAR(Pwm_ChannelType, AUTOMATIC) chIdx; /* assigned eMIOS HW channel index */
    VAR(Pwm_PeriodType, AUTOMATIC) Period;
#endif

    /* extract from conf structure the generic        channel information */
    /*@violates @ref Pwm_eMIOS_LLD_C_REF_11 pointer arithmetic other than array indexing used */
    PwmChannel = &Pwm_eMIOS_Cfg->ChannelsPtr[LogicalChannelNumber];

    /* extract from conf structure the EMIOS specific channel information */
    PwmEmiosSpecificParam =  &PwmChannel->SpecificCfg.EmiosCfg;

#if (PWM_DEV_ERROR_DETECT == STD_ON)
    /* store the associated hw channel ID */
    hw_ch = PwmEmiosSpecificParam->Pwm_HwChannelID;
    mIdx  = (uint8)(hw_ch >> EMIOS_MOD_SHIFT);
    chIdx = (uint8)(hw_ch &  EMIOS_CH_MASK);

    Period =  Pwm_eMIOS_LLD_GetCounterBusPeriod(mIdx, chIdx, \
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
                                               (REG_READ32(EMIOS_CCR(mIdx, chIdx)) & CCR_BSL_MASK));
    if(TriggerDelay > Period)
    {
        Det_ReportError
        (
            (uint16) PWM_MODULE_ID,
            (uint8) 0,
            (uint8) PWM_SETTRIGGERDELAY_ID,
            (uint8) PWM_E_OPWMT_CHANNEL_TRIGGER_RANGE
        );
    }
    else
#endif /* PWM_DEV_ERROR_DETECT == STD_ON */
    {
      ChannelAddr = PwmEmiosSpecificParam->Pwm_Emios_ChannelAddr;

      /*Save current Trigger Delay in local variable*/
      /* @violates @ref Pwm_eMIOS_LLD_C_REF_3 Non-constant argument to function */
      Pwm_Current_TriggerDelay[LogicalChannelNumber] = (Pwm_PeriodType)TriggerDelay;

      /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
      REG_WRITE32((ChannelAddr + EMIOS_ALTA_OFFSET),(uint32)( (uint32)TriggerDelay + (uint32) 1));
    }
}
#endif
#endif
#endif
/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE == STD_ON)
/**
* @brief   Implementation specific function to get the Duty cycle of the given PWM channel
* @param[in] LogicalChannelNumber - pwm channel id
* @implements DPWM04020
*/
FUNC(uint16, PWM_CODE)  Pwm_eMIOS_LLD_GetChannelState    (
                                                                VAR(Pwm_ChannelType, AUTOMATIC) LogicalChannelNumber
                                                            )
{


    return Pwm_eMIOS_Duty_Cycle_Value[LogicalChannelNumber];


}

#endif /*PWM_GET_CHANNEL_STATE_API*/

#ifdef MULTI_PWM_CHANNEL_SYNCH
#if (MULTI_PWM_CHANNEL_SYNCH == STD_ON)
/**
@brief   Implementation specific function to enable/disble the buffer transfer.

@details This function is useful to enable/disble the buffer transfer to synchronize
         multiple PWM channels.

@param[in] ModuleIndex - eMIOS module
           ChannelMask - channel mask set

@remarks PR-MCAL-3299
@implements DPWM04019
*/

FUNC (void, PWM_CODE) Pwm_eMIOS_LLD_BufferTransferEnableDisable
/* @violates @ref Pwm_eMIOS_LLD_C_REF_14 This is required as per autosar Requirement */
                             (
                                 VAR(uint8, AUTOMATIC) ModuleIndex,
                                 VAR(uint32, AUTOMATIC) ChannelMask
                             )
{
    /* @violates @ref Pwm_eMIOS_LLD_C_REF_7 Cast from unsigned long to pointer */
    REG_RMW32(EMIOS_OUDR(ModuleIndex),(uint32)(0xFFFFFFF),(uint32)(ChannelMask & (uint32)0xFFFFFFF));
}
#endif
#endif
#define PWM_STOP_SEC_CODE
/* @violates @ref Pwm_eMIOS_LLD_C_REF_1 Only preprocessor statements and comments before "#include" */
/* @violates @ref Pwm_eMIOS_LLD_C_REF_8 a header file being included twice */
#include "MemMap.h"


#ifdef __cplusplus
}
#endif
/* @} */
