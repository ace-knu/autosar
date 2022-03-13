/**
*   @file    Mcu_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Low level header file for MCU driver.
*   @details This file contains declarations of the low level functions defined for MCU driver.
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

#ifndef MCU_LLD_H
#define MCU_LLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_LLD_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is not a violation since
* all header files are protected against multiple inclusions.
*
* @section Mcu_LLD_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory 
* section.
*
* @section Mcu_LLD_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Mcu_LLD_H_REF_4
* Violates MISRA 2004 Required Rule 8.8, The external object has been declared only once in one
* file. This violation comes because global variable has not been initialized. Variable can not
* be initialized and is placed in no init section.
*
* @section Mcu_LLD_H_REF_5
* Violates MISRA 2004 Required Rule 8.7, objects shall be defined at block scope if they are only 
* accessed from within a single function.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Mcu_LLD.h
* @implements     DMCU00008
*/
#include "Reg_eSys_MagicCarpet.h"
#include "Reg_eSys_FLASHC.h"
#include "Mcu.h"
#include "Mcu_Ecsm_LLD.h"
#include "Mcu_Sscm_LLD.h"
#include "Mcu_eMIOS_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_LLD.h
* @implements     DMCU04037, DMCU04038, DMCU04039, DMCU04040, DMCU04041, DMCU04042, DMCU04043
*/
#define MCU_LLD_VENDOR_ID                      43
/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_LLD_AR_RELEASE_MAJOR_VERSION       4
/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_LLD_AR_RELEASE_MINOR_VERSION       0
/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_LLD_AR_RELEASE_REVISION_VERSION    3
#define MCU_LLD_SW_MAJOR_VERSION               1
#define MCU_LLD_SW_MINOR_VERSION               0
#define MCU_LLD_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu configuration header file are of the same vendor */
#if (MCU_LLD_VENDOR_ID != MCU_VENDOR_ID_CFG)
    #error "Mcu_LLD.h and Mcu_Cfg.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu configuration header file are of the same Autosar version */
#if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION    != MCU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCU_LLD_AR_RELEASE_MINOR_VERSION    != MCU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCU_LLD_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcu_LLD.h and Mcu_Cfg.h are different"
#endif
/* Check if current file and Mcu configuration header file are of the same software version */
#if ((MCU_LLD_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION_CFG) || \
     (MCU_LLD_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION_CFG) || \
     (MCU_LLD_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcu_LLD.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and mcu header file are of the same vendor */
#if (MCU_LLD_VENDOR_ID != MCU_VENDOR_ID)
    #error "Mcu_LLD.h and Mcu.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu header file are of the same Autosar version */
#if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION    != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LLD_AR_RELEASE_MINOR_VERSION    != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_LLD_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_LLD.h and Mcu.h are different"
#endif
/* Check if current file and Mcu header file are of the same software version */
#if ((MCU_LLD_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION) || \
     (MCU_LLD_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION) || \
     (MCU_LLD_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_LLD.h and Mcu.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the current file and Ecsm header file are of the same Autosar version */
    #if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION != MCU_ECSM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LLD_AR_RELEASE_MINOR_VERSION != MCU_ECSM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu_LLD.h and Mcu_Ecsm_LLD.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the current file and SSCM header file are of the same Autosar version */
    #if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION != MCU_SSCM_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LLD_AR_RELEASE_MINOR_VERSION != MCU_SSCM_LLD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu_LLD.h and Mcu_Sscm_LLD.h are different"
    #endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          Masks relating to the uC reset module
*/
#define MCU_ZERO_BYTE_VALUE                      ((uint8)0x0U)
#define MCU_ONE_BYTE_VALUE                       ((uint8)0x1U)
#define MCU_ZERO_VALUE                           ((uint32)0x0UL)
#define MCU_ONE_VALUE                            ((uint32)0x1UL)
#define MCU_TWO_VALUE                            ((uint32)0x2UL)
#define MCU_THREE_VALUE                          ((uint32)0x3UL)
#define MCU_FOUR_VALUE                           ((uint32)0x4UL)
#define MCU_SEVEN_VALUE                          ((uint32)0x7UL)
#define MCU_EIGHT_VALUE                          ((uint32)0x8UL)
#define MCU_NINE_VALUE                           ((uint32)0x9UL)
#define MCU_FIFTEEN_VALUE                        ((uint32)0xFUL)
#define MCU_SIXTEEN_HEX_VALUE                    ((uint32)0x10UL)
#define MCU_16_BIT_MASK                          ((uint16)0xFFFFUL)
#define MCU_32_BIT_MASK                          ((uint32)0xFFFFFFFFUL)
#define MCU_SHIFT_ONE                            ((uint32)1UL)
#define MCU_SHIFT_THREE                          ((uint32)3UL)
#define MCU_SHIFT_FOUR                           ((uint32)4UL)
#define MCU_SHIFT_EIGHT                          ((uint32)8UL)
#define MCU_SHIFT_TEN                            ((uint32)10UL)
#define MCU_SHIFT_TWELVE                         ((uint32)12UL)
#define MCU_SHIFT_SIXTEEN                        ((uint32)16UL)
#define MCU_SHIFT_NINETEEN                       ((uint32)19UL)
#define MCU_SHIFT_TWENTY                         ((uint32)20UL)
#define MCU_SHIFT_TWENTY_THREE                   ((uint32)23UL)
#define MCU_SHIFT_TWENTY_FOUR                    ((uint32)24UL)
#define MCU_SHIFT_TWENTY_SIX                     ((uint32)26UL)
#define MCU_SHIFT_TWENTY_SEVEN                   ((uint32)27UL)
#define MCU_SHIFT_TWENTY_EIGHT                   ((uint32)28UL)
#define MCU_SHIFT_THIRTY                         ((uint32)30UL)
#define MCU_SHIFT_THIRTY_ONE                     ((uint32)31UL)

/**
* @brief          PLL functional modes
*/
#define MCU_PLL_NORMAL_MODE                      ((uint8)0U)
#define MCU_PLL_FM_MODE                          ((uint8)1U)
#define MCU_PLL_UNUSED_MODE                      ((uint8)2U)


/**
* @brief          RGM choices
*/

#define MCU_FLASH_RESET_VALUE                   ((uint16)0x0100U)
#define MCU_LVD45_RESET_VALUE                   ((uint16)0x0080U)
#define MCU_CMU0_FHL_RESET_VALUE                ((uint16)0x0040U)
#define MCU_CMU0_OLR_RESET_VALUE                ((uint16)0x0020U)
#define MCU_PLL_RESET_VALUE                     ((uint16)0x0010U)
#define MCU_CORE_RESET_VALUE                    ((uint16)0x0002U)
#define MCU_JTAG_RESET_VALUE                    ((uint16)0x0001U)



/**
* @brief          System clock choices
*/
#define MCU_RC16MHz_CLOCK                        ((uint32)0UL)
#define MCU_RC16MHz_DIV_CLOCK                    ((uint32)1UL)
#define MCU_XTAL_CLOCK                           ((uint32)2UL)
#define MCU_XTAL_DIV_CLOCK                       ((uint32)3UL)
#define MCU_PLL_CLOCK                            ((uint32)4UL)
#define MCU_SYSCLK_SWITCH_DISABLED               ((uint32)0xFUL)

/**
* @brief          Microcontroller RC internal oscillator frequency
*/
#define MCU_RC16MHz_CLOCK_FREQUENCY              ((uint32)16000000UL)

/**
* @brief          Defines relating to the Microcontroller Modes
*/
#define MCU_RESET_MODE                           ((uint16)0UL)
#define MCU_TEST_MODE                            ((uint16)1UL)
#define MCU_SAFE_MODE                            ((uint16)2UL)
#define MCU_DRUN_MODE                            ((uint16)3UL)
#define MCU_RUN0_MODE                            ((uint16)4UL)
#define MCU_RUN1_MODE                            ((uint16)5UL)
#define MCU_RUN2_MODE                            ((uint16)6UL)
#define MCU_RUN3_MODE                            ((uint16)7UL)
#define MCU_HALT_MODE                            ((uint16)8UL)
#define MCU_STOP_MODE                            ((uint16)10UL)
#define MCU_STANDBY_MODE                         ((uint16)13UL)
#define MCU_DEST_RESET_MODE                      ((uint16)15UL)
#define MCU_DRUN_MODE_VALUE                      ((uint32)0x30000000UL)
#define MCU_RUN0_MODE_VALUE                      ((uint32)0x40000000UL)
#define MCU_RUN1_MODE_VALUE                      ((uint32)0x50000000UL)
#define MCU_RUN2_MODE_VALUE                      ((uint32)0x60000000UL)
#define MCU_RUN3_MODE_VALUE                      ((uint32)0x70000000UL)
#define MCU_TEST_MODE_VALUE                      ((uint32)0x10000000UL)
#define MCU_SAFE_MODE_VALUE                      ((uint32)0x20000000UL)
#define MCU_SYSTEM_MODE_MASK                     ((uint32)0xF0000000UL)

/**
* @brief          Internal Error IDs for reporting to DET
*
* @implements     DMCU04066, DMCU04067, DMCU04068, DMCU04069, DMCU04070, DMCU04071, DMCU04072, DMCU04073
*/
#define MCU_E_HALT_INVALID_TRANSITIONS           ((uint8)0x12U)
#define MCU_E_STOP_INVALID_TRANSITIONS           ((uint8)0x13U)
/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_E_STANDBY_INVALID_TRANSITIONS        ((uint8)0x14U)
#define MCU_E_TRANSITION_IN_PROGRESS             ((uint8)0x15U)
#define MCU_E_INVALIDE_MODE                      ((uint8)0x16U)
#define MCU_E_32k_OSC_NOT_STABLE                 ((uint8)0x17U)
#define MCU_E_128k_OSC_NOT_STABLE                ((uint8)0x18U)
#define MCU_E_XOSC_NOT_STABLE                    ((uint8)0x19U)
#define MCU_E_RUN0_INVALID_TRANSITIONS           ((uint8)0x20U)
#define MCU_E_RUN1_INVALID_TRANSITIONS           ((uint8)0x21U)
#define MCU_E_RUN2_INVALID_TRANSITIONS           ((uint8)0x22U)
#define MCU_E_RUN3_INVALID_TRANSITIONS           ((uint8)0x23U)

/**
* @brief          Defines relating to the clock monitor unit
*/
#define MCU_CMU_CR_RESET_VALUE                   ((uint32)0x6UL)
#define MCU_CMU_HREF_VALUE                       ((uint32)0x00000FFFUL)
#define MCU_CMU_LREF_VALUE                       ((uint32)0x0000000UL)
#define MCU_OSC_LOW_FREQ_INT                     ((uint16)0x0020U)
#define MCU_OSC_HIGH_FREQ_INT                    ((uint16)0x0040U)
#define MCU_OSC_CMU12_HIGH_FREQ_INT              ((uint16)0x0800U)
#define MCU_PLL_FAIL_INT                         ((uint16)0x0010U)
#define MCU_CMU_REF_MASK                         ((uint32)0x00000FFFUL)
#define MCU_CMU_ISR_CLEAR_VALUE                  ((uint32)0x7UL)

/**
* @brief          Defines relating to the clock
*/
#define MCU_SYSTEM_CLK_MASK                      ((uint32)0x0000000FUL)
#define MCU_CRYSTAL_OSC_INT                      ((uint32)0x00000080UL)
#define MCU_PLL_FAIL_MASK                        ((uint32)0x00000004UL)
#define MCU_FMPLL_MASK                           ((uint32)0xFFFF7FFFUL)
#define MCU_ENABLE_FMPLL                         ((uint32)0x00008000UL)
#define MCU_RC_GENERAL_FLAG                      ((uint32)0x00000010UL)
#define MCU_XOSC_GENERAL_FLAG                    ((uint32)0x00000020UL)
#define MCU_PLL_STATUS_FLAG                      ((uint32)0x00000040UL)
#define MCU_PLL1_STATUS_FLAG                     ((uint32)0x00000080UL)
#define MCU_CHECK_PLLLOCK_FLAG                   ((uint32)0x00000008UL)
#define MCU_CLK_OUT_MASK                         ((uint32)0x1UL)
#define MCU_CLK_STABLE                           ((uint32)0x80000000UL)
#define MCU_32KHZ_CLK_STABLE                     ((uint32)0x00000002UL)
#define MCU_128KHZ_CLK_STABLE                    ((uint32)0x00000010UL)

/**
* @brief          Defines relating to the peripheral set
*/
#define MCU_PC1_ENABLED                          ((uint32)0x80000000UL)
#define MCU_PC2_ENABLED                          ((uint32)0x00800000UL)
#define MCU_PC3_ENABLED                          ((uint32)0x00008000UL)
#define MCU_PC4_ENABLED                          ((uint32)0x00000080UL)
#define MCU_DE_ENABLED                           ((uint8)0x80U)
#define MCU_PERIPH_CLOCK_DIV_MASK                ((uint32)0x8FUL)
#define MCU_PERIPH_CLOCK_SEL_MASK                ((uint32)0x70UL)
#define MCU_PERIPH_RESET                         ((uint32)0x04000000UL)
    

/**
* @brief          Keys relating to the mode transition
*/
#define MCU_SOFT_CONTROL_KEY_ONE                 ((uint32)0x00005AF0UL)
#define MCU_SOFT_CONTROL_KEY_TWO                 ((uint32)0x0000A50FUL)
#define MCU_TRANSITION_STATUS                    ((uint32)0x08000000UL)


/** @brief Clock divider configuration (Z0, FEC, FLASH) related defines */
#define MCU_Z0_DIV_ENABLED                       ((uint32)0x00000001UL)
#define MCU_FEC_DIV_ENABLED                      ((uint32)0x00000010UL)
#define MCU_FLASH_DIV_ENABLED                    ((uint32)0x00000100UL)
#define MCU_Z0_DIV_DISABLED                      ((uint32)0x00000000UL)
#define MCU_FEC_DIV_DISABLED                     ((uint32)0x00000000UL)
#define MCU_FLASH_DIV_DISABLED                   ((uint32)0x00000000UL)
#define MCU_CLOCK_DIV_ENABLED                    ((uint32)0x00000001UL)

/** @brief Auxiliary Clock related defines */
#define AUX_CLK_0_FIRC                          ((uint32)0x00000000UL)
#define AUX_CLK_0_FXOSC                         ((uint32)0x01000000UL)
#define AUX_CLK_1_SYSCLK                        ((uint32)0x00000000UL)
#define AUX_CLK_1_FMPLL_PHI1                    ((uint32)0x01000000UL)


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Mcu_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "MemMap.h"

/**
 * @brief Mcu clock notification 
*/
/* @violates @ref Mcu_LLD_H_REF_4 object function previously declared */
extern VAR (Mcu_ClockNotificationType, MCU_VAR) Mcu_CpyClockNotification;

/**
 * @brief Mcu Callback mechanism
*/
#if (MCU_XOSC_ISR_USED == STD_ON)
/* @violates @ref Mcu_LLD_H_REF_5 MISRA 2004 Required Rule 8.7, extern object used in only one file */
extern P2FUNC (void, const, Mcu_XOSC_ISR_Callback)(void);
#endif
#if (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON)
/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
/* @violates @ref Mcu_LLD_H_REF_5 MISRA 2004 Required Rule 8.7, extern object used in only one file */
extern P2FUNC (void, const, Mcu_TransitionComplete_ISR_Callback)(void);
#endif
#if (MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON)
/* @violates @ref Mcu_LLD_H_REF_5 MISRA 2004 Required Rule 8.7, extern object used in only one file */
extern P2FUNC (void, const, Mcu_InvalidConfig_ISR_Callback)(void);
#endif
#if (MCU_INVALID_MODE_ISR_USED == STD_ON)
/* @violates @ref Mcu_LLD_H_REF_5 MISRA 2004 Required Rule 8.7, extern object used in only one file */
extern P2FUNC (void, const, Mcu_InvalidMode_ISR_Callback)(void);
#endif
#if (MCU_SAFE_MODE_ISR_USED == STD_ON)
/* @violates @ref Mcu_LLD_H_REF_5 MISRA 2004 Required Rule 8.7, extern object used in only one file */
extern P2FUNC (void, const, Mcu_EnterSafeMode_ISR_Callback)(void);
#endif
#if (MCU_RGM_ALTERNATEMODE_ISR_USED == STD_ON)
/* @violates @ref Mcu_LLD_H_REF_5 MISRA 2004 Required Rule 8.7, extern object used in only one file */
extern P2FUNC (void, const, Mcu_AlternateMode_ISR_Callback)(void);
#endif

/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_LLD_H_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*                            statements and comments before '#include'
*/
#include "MemMap.h"

/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
/**
 * @brief Mcu System clock frequency
*/
extern VAR (uint32, MCU_VAR) Mcu_CpySystemClockFrequency;
extern P2CONST (Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_Cfg_Ptr;

/* @violates @ref Mcu_LLD_H_REF_3 Identifier exceeds 31 characters */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_LLD_H_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*                            statements and comments before '#include'
*/
#include "MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_LLD_H_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                                before '#include' MemMap.h
*/
#include "MemMap.h"

FUNC (void, MCU_CODE) Mcu_Configurations_Init (P2CONST (McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr);

FUNC(uint32, MCU_CODE) Mcu_Init_Osc(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
                           P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr);

FUNC(void, MCU_CODE) Mcu_Init_Pll0(VAR(uint32, AUTOMATIC) CurrentReg, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);

FUNC(void, MCU_CODE) Mcu_Configure_FMPLL_ClkFail(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);

FUNC (void, MCU_CODE) Mcu_Output_Init (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);

#ifdef MCU_CONFIGURE_CLK_OUT
#if (MCU_CONFIGURE_CLK_OUT == STD_OFF)
    extern FUNC(void, MCU_CODE) Mcu_LLD_Disable_ClkOut (void);
#endif
#endif

#if (MCU_GET_DEVICE_INFO_API == STD_ON)
FUNC (void, MCU_CODE) Mcu_LLD_GetDeviceInfo(P2VAR (Mcu_DeviceInfoType, AUTOMATIC, \
    MCU_APPL_DATA) deviceinfo);    
#endif


FUNC (void, MCU_CODE) Mcu_Peripheral_Sets_Init (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);

FUNC (Mcu_PllStatusType, MCU_CODE) Mcu_FMPLL_GetPllStatus (void);

FUNC(void, MCU_CODE) Mcu_PLL_0FF(void);
FUNC(void, MCU_CODE) Mcu_Disable_Peripheral(void);
FUNC (void, MCU_CODE) Mcu_LLD_Init (P2CONST (McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr);

FUNC(Std_ReturnType, MCU_CODE) Mcu_Check_Stability(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);

FUNC(void, MCU_CODE) Mcu_Monitor_Osc(VAR(uint32, AUTOMATIC) Clk_Monitor);

#if MCU_INIT_CLOCK == TRUE
FUNC (Std_ReturnType, MCU_CODE) Mcu_LLD_InitClock (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
                VAR (Mcu_ClockNotificationType, AUTOMATIC) ClockNotification);
#endif

#if (MCU_NO_PLL == FALSE)
FUNC (void, MCU_CODE) Mcu_LLD_DistributePllClock (void);
#endif

FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_LLD_GetPllStatus(void);

FUNC(void, AUTOMATIC) Mcu_LLD_Apply_Mode(VAR (Mcu_ModeType, AUTOMATIC) McuMode);

FUNC (void, MCU_CODE) Mcu_Modes_Init (P2CONST (McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr);
#if (MCU_SKIP_FUNCTION == STD_ON)
    FUNC(Std_ReturnType, AUTOMATIC) Mcu_Apply_Mode(VAR(uint32, AUTOMATIC) Mcu_TimeOut, VAR(uint32, AUTOMATIC) Mode);
#else
FUNC (void, AUTOMATIC) Mcu_Apply_Mode (VAR (uint32, AUTOMATIC) Mcu_TimeOut, VAR (uint32, AUTOMATIC) Mode);
#endif
#if (MCU_SKIP_FUNCTION == STD_ON)
    FUNC(Std_ReturnType, AUTOMATIC) Mcu_Change_Mode(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);
#else
FUNC (void, AUTOMATIC) Mcu_Change_Mode (VAR (uint32, AUTOMATIC) Mcu_TimeOut, P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);
#endif
#if (MCU_SKIP_FUNCTION == STD_ON)
    FUNC(Std_ReturnType, AUTOMATIC) Mcu_Check_Init(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);
#else
FUNC (void, AUTOMATIC) Mcu_Check_Init (VAR (uint32, AUTOMATIC) Mcu_TimeOut, P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);
#endif
FUNC (void, AUTOMATIC) Mcu_Change_LowPower_Mode (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr, P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr);

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
FUNC (void, MCU_CODE) Mcu_Apply_LowPower_Mode (VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr);
#else
FUNC (void, MCU_CODE) Mcu_Apply_LowPower_Mode (P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr);
#endif

FUNC (void, MCU_CODE) Mcu_Monitor_Init (VAR (void, AUTOMATIC) );

FUNC (void, MCU_CODE) Mcu_Monitor_Deinit (VAR (void, AUTOMATIC) );

#ifdef MCU_DISABLE_CMU
extern FUNC (void, MCU_CODE) Mcu_Disable_Monitor(VAR (uint8, AUTOMATIC) CmuIndex);
#endif

FUNC (void, MCU_CODE) Mcu_Monitor_Pll (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr);

FUNC (void, MCU_CODE) Mcu_Power_Init (P2CONST (McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr);

FUNC (void, MCU_CODE) Mcu_Reset_Init (P2CONST (McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr);

FUNC (Mcu_ResetType, MCU_CODE) Mcu_RGM_GetResetReason (VAR(uint32, AUTOMATIC) Mcu_TimeOut);

FUNC (Mcu_RawResetType, MCU_CODE) Mcu_RGM_GetResetRawValue (VAR(uint32, AUTOMATIC) Mcu_TimeOut);

FUNC(void, MCU_CODE) Mcu_RGM_PerformReset(void);

#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_LLD_GetRamState (void);
#endif

FUNC(void, MCU_CODE) Mcu_ClkFail_ISR(void);

FUNC(void, MCU_CODE) Mcu_Report_ClkFail(void);

/* @violates @ref Mcu_LLD_H_REF_5 extern object used in only one file */
extern P2FUNC (void, const, Mcu_Flash_Init)(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr);

extern P2FUNC (void, const, Mcu_Flash_Configure)(VAR(uint32, AUTOMATIC) Mcu_CFlash_Conf, VAR(uint32, AUTOMATIC) Mcu_DFlash_Conf);

FUNC(Mcu_ResetType, MCU_CODE) Mcu_LLD_GetResetReason (VAR (void, AUTOMATIC));

FUNC(Mcu_RawResetType, MCU_CODE) Mcu_LLD_GetResetRawValue (VAR (void, AUTOMATIC));

#if MCU_PERFORM_RESET_API == STD_ON
    FUNC(void, MCU_CODE) Mcu_LLD_PerformReset(VAR (void, AUTOMATIC));
#endif  /* #if MCU_PERFORM_RESET_API == STD_ON */

FUNC(void, MCU_CODE) Mcu_Force_CMU_Clock(void);

FUNC(void, MCU_CODE) Mcu_Force_eMIOS_Clock(void);

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_LLD_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_LLD_H_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                                before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_LLD_H */

/** @} */
