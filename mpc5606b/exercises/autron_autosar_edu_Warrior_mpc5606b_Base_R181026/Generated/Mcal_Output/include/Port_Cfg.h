/**
* @file    Port_Cfg.h
*
* @version 1.0.1
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup Port
* @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIUL
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF11_ASR_REL_4_0_REV_0003_20161011
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* This is an Autosar requirement about the memory management.
*
* @section PORT_CFG_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section PORT_CFG_REF_3
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section PORT_CFG_REF_4
* Violates MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct. 
*
* @section PORT_CFG_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are
* only accessed from within a single function.
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file    Port_Cfg.h
* @implements DPORT00010
*/
#include "Port_Siul_LLD_CfgEx.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
* @implements   DPORT04001
*/
#define PORT_VENDOR_ID_CFG_H                       43
/*
* @violates @ref PORT_CFG_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_H        4
/*
* @violates @ref PORT_CFG_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_H        0
/*
* @violates @ref PORT_CFG_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_H     3
#define PORT_SW_MAJOR_VERSION_CFG_H                1
#define PORT_SW_MINOR_VERSION_CFG_H                0
#define PORT_SW_PATCH_VERSION_CFG_H                1

/*==================================================================================================
*                               FILE VERSION CHECKS
==================================================================================================*/
/**
* @file    Port_Cfg.h
* @implements   DPORT06001
*/
/* Check if Port_Cfg.h and Port_Siul_LLD_CfgEx.h file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != SIUL_VENDOR_ID_EXT_H)
    #error "Port_Cfg.h and Port_Siul_LLD_CfgEx.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Port_Siul_LLD_CfgEx.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != SIUL_AR_RELEASE_MAJOR_VERSION_EXT_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != SIUL_AR_RELEASE_MINOR_VERSION_EXT_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != SIUL_AR_RELEASE_REVISION_VERSION_EXT_H))
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_Siul_LLD_CfgEx.h are different"
#endif
/* Check if Port_Cfg.h and Port_Siul_LLD_CfgEx.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != SIUL_SW_MAJOR_VERSION_EXT_H) || \
     (PORT_SW_MINOR_VERSION_CFG_H != SIUL_SW_MINOR_VERSION_EXT_H) || \
     (PORT_SW_PATCH_VERSION_CFG_H != SIUL_SW_PATCH_VERSION_EXT_H))
  #error "Software Version Numbers of Port_Cfg.h and Port_Siul_LLD_CfgEx.h are different"
#endif

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements       DPORT04002, DPORT04019, DPORT04020, DPORT04021,
*
* @api
*/
typedef struct
{
    VAR(uint8,PORT_VAR) numPins;                                                           /**< @brief Number of pins Configured */
    VAR(uint16,PORT_VAR) NoUnUsedPins;                                                     /**< @brief Number of pins Unused */
    P2CONST(uint16,AUTOMATIC,PORT_APPL_CONST)Port_NoUnUsedPadsArray;                       /**< @brief Unused pins array */
    P2CONST(Port_LLD_UnUsedPinConfigType,AUTOMATIC,PORT_APPL_CONST) Port_LLD_UnUsedPinPtr;  /**< @brief Default pad configuration */
    P2CONST(Port_LLD_PinConfigType,AUTOMATIC,PORT_APPL_CONST) Port_LLD_PinConfPtr;         /**< @brief pin default configuration */
    P2CONST(Port_LLD_PadSelConfigType,AUTOMATIC,PORT_APPL_CONST) Port_LLD_PadSelConfPtr;   /**< @brief pad selection default configuration */
} Port_ConfigType;

/**
* @brief Settings for a PSMI register
* @details The structure @p Pad_PSMI_Setting manages ExtraFunctions PinMode.
* 
* @implements DPORT04003
* @api
*/
typedef struct
{
    VAR(uint8,PORT_VAR) PSMI_id;   /**< @brief The number of the PSMI register to be configured */
    VAR(uint8,PORT_VAR) PSMI_code; /**< @brief The value written in the reg for signal allocation */
} Pad_PSMI_Setting;

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Show the IPV used.
* @note This define can be used by test phase.
* @implements
*/
#define IPV_SIUL_USED

/*
* @brief Enable/Disable Development Error Detection
* @implements   DPORT04012
*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)
/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
* @implements   DPORT04013
*/
#define PORT_SET_PIN_DIRECTION_API      (STD_ON)
/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
* @implements   DPORT04014
*/
#define PORT_SET_PIN_MODE_API           (STD_OFF)
/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
* @implements   DPORT04015
*/
#define PORT_VERSION_INFO_API           (STD_OFF)

/**
@brief Enable/Disable Port Pin Abstraction Mode 
*/
#define PORT_PIN_ABSTRACTION_MODE_API           (STD_OFF)




/**
* @file    Port_Cfg.h
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
* @implements DPORT04016
*/
#define PortConf_PortPin_PortContainer_A_PortPin_0  0
#define PortConf_PortPin_PortContainer_A_PortPin_1  1
#define PortConf_PortPin_PortContainer_A_PortPin_2  2
#define PortConf_PortPin_PortContainer_A_PortPin_3  3
#define PortConf_PortPin_PortContainer_A_PortPin_4  4
#define PortConf_PortPin_PortContainer_A_PortPin_5  5
#define PortConf_PortPin_PortContainer_A_PortPin_6  6
#define PortConf_PortPin_PortContainer_A_PortPin_7  7
#define PortConf_PortPin_PortContainer_A_PortPin_8  8
#define PortConf_PortPin_PortContainer_A_PortPin_9  9
#define PortConf_PortPin_PortContainer_A_PortPin_10  10
#define PortConf_PortPin_PortContainer_A_PortPin_11  11
#define PortConf_PortPin_PortContainer_A_PortPin_12  12
#define PortConf_PortPin_PortContainer_A_PortPin_13  13
#define PortConf_PortPin_PortContainer_A_PortPin_14  14
#define PortConf_PortPin_PortContainer_A_PortPin_15  15
#define PortConf_PortPin_PortContainer_B_PortPin_0  16
#define PortConf_PortPin_PortContainer_B_PortPin_1  17
#define PortConf_PortPin_PortContainer_B_PortPin_2  18
#define PortConf_PortPin_PortContainer_B_PortPin_3  19
#define PortConf_PortPin_PortContainer_B_PortPin_4  20
#define PortConf_PortPin_PortContainer_B_PortPin_5  21
#define PortConf_PortPin_PortContainer_B_PortPin_6  22
#define PortConf_PortPin_PortContainer_B_PortPin_7  23
#define PortConf_PortPin_PortContainer_B_PortPin_8  24
#define PortConf_PortPin_PortContainer_B_PortPin_9  25
#define PortConf_PortPin_PortContainer_B_PortPin_10  26
#define PortConf_PortPin_PortContainer_B_PortPin_11  27
#define PortConf_PortPin_PortContainer_B_PortPin_12  28
#define PortConf_PortPin_PortContainer_B_PortPin_13  29
#define PortConf_PortPin_PortContainer_B_PortPin_14  30
#define PortConf_PortPin_PortContainer_B_PortPin_15  31
#define PortConf_PortPin_PortContainer_C_PortPin_0  32
#define PortConf_PortPin_PortContainer_C_PortPin_1  33
#define PortConf_PortPin_PortContainer_C_PortPin_2  34
#define PortConf_PortPin_PortContainer_C_PortPin_3  35
#define PortConf_PortPin_PortContainer_C_PortPin_4  36
#define PortConf_PortPin_PortContainer_C_PortPin_5  37
#define PortConf_PortPin_PortContainer_C_PortPin_6  38
#define PortConf_PortPin_PortContainer_C_PortPin_7  39
#define PortConf_PortPin_PortContainer_C_PortPin_8  40
#define PortConf_PortPin_PortContainer_C_PortPin_9  41
#define PortConf_PortPin_PortContainer_C_PortPin_10  42
#define PortConf_PortPin_PortContainer_C_PortPin_11  43
#define PortConf_PortPin_PortContainer_C_PortPin_12  44
#define PortConf_PortPin_PortContainer_C_PortPin_13  45
#define PortConf_PortPin_PortContainer_C_PortPin_14  46
#define PortConf_PortPin_PortContainer_C_PortPin_15  47
#define PortConf_PortPin_PortContainer_D_PortPin_0  48
#define PortConf_PortPin_PortContainer_D_PortPin_1  49
#define PortConf_PortPin_PortContainer_D_PortPin_2  50
#define PortConf_PortPin_PortContainer_D_PortPin_3  51
#define PortConf_PortPin_PortContainer_D_PortPin_4  52
#define PortConf_PortPin_PortContainer_D_PortPin_5  53
#define PortConf_PortPin_PortContainer_D_PortPin_6  54
#define PortConf_PortPin_PortContainer_D_PortPin_7  55
#define PortConf_PortPin_PortContainer_D_PortPin_8  56
#define PortConf_PortPin_PortContainer_D_PortPin_9  57
#define PortConf_PortPin_PortContainer_D_PortPin_10  58
#define PortConf_PortPin_PortContainer_D_PortPin_11  59
#define PortConf_PortPin_PortContainer_D_PortPin_12  60
#define PortConf_PortPin_PortContainer_D_PortPin_13  61
#define PortConf_PortPin_PortContainer_D_PortPin_14  62
#define PortConf_PortPin_PortContainer_D_PortPin_15  63
#define PortConf_PortPin_PortContainer_E_PortPin_0  64
#define PortConf_PortPin_PortContainer_E_PortPin_1  65
#define PortConf_PortPin_PortContainer_E_PortPin_2  66
#define PortConf_PortPin_PortContainer_E_PortPin_3  67
#define PortConf_PortPin_PortContainer_E_PortPin_4  68
#define PortConf_PortPin_PortContainer_E_PortPin_5  69
#define PortConf_PortPin_PortContainer_E_PortPin_6  70
#define PortConf_PortPin_PortContainer_E_PortPin_7  71
#define PortConf_PortPin_PortContainer_E_PortPin_8  72
#define PortConf_PortPin_PortContainer_E_PortPin_9  73
#define PortConf_PortPin_PortContainer_E_PortPin_10  74
#define PortConf_PortPin_PortContainer_E_PortPin_11  75
#define PortConf_PortPin_PortContainer_E_PortPin_12  76
#define PortConf_PortPin_PortContainer_E_PortPin_13  77
#define PortConf_PortPin_PortContainer_E_PortPin_14  78
#define PortConf_PortPin_PortContainer_E_PortPin_15  79
#define PortConf_PortPin_PortContainer_F_PortPin_0  80
#define PortConf_PortPin_PortContainer_F_PortPin_1  81
#define PortConf_PortPin_PortContainer_F_PortPin_2  82
#define PortConf_PortPin_PortContainer_F_PortPin_3  83
#define PortConf_PortPin_PortContainer_F_PortPin_4  84
#define PortConf_PortPin_PortContainer_F_PortPin_5  85
#define PortConf_PortPin_PortContainer_F_PortPin_6  86
#define PortConf_PortPin_PortContainer_F_PortPin_7  87
#define PortConf_PortPin_PortContainer_F_PortPin_8  88
#define PortConf_PortPin_PortContainer_F_PortPin_9  89
#define PortConf_PortPin_PortContainer_F_PortPin_10  90
#define PortConf_PortPin_PortContainer_F_PortPin_11  91
#define PortConf_PortPin_PortContainer_F_PortPin_12  92
#define PortConf_PortPin_PortContainer_F_PortPin_13  93
#define PortConf_PortPin_PortContainer_F_PortPin_14  94
#define PortConf_PortPin_PortContainer_F_PortPin_15  95
#define PortConf_PortPin_PortContainer_G_PortPin_0  96
#define PortConf_PortPin_PortContainer_G_PortPin_1  97
#define PortConf_PortPin_PortContainer_G_PortPin_2  98
#define PortConf_PortPin_PortContainer_G_PortPin_3  99
#define PortConf_PortPin_PortContainer_G_PortPin_4  100
#define PortConf_PortPin_PortContainer_G_PortPin_5  101
#define PortConf_PortPin_PortContainer_G_PortPin_6  102
#define PortConf_PortPin_PortContainer_G_PortPin_7  103
#define PortConf_PortPin_PortContainer_G_PortPin_8  104
#define PortConf_PortPin_PortContainer_G_PortPin_9  105
#define PortConf_PortPin_PortContainer_G_PortPin_10  106
#define PortConf_PortPin_PortContainer_G_PortPin_11  107
#define PortConf_PortPin_PortContainer_G_PortPin_12  108
#define PortConf_PortPin_PortContainer_G_PortPin_13  109
#define PortConf_PortPin_PortContainer_G_PortPin_14  110
#define PortConf_PortPin_PortContainer_G_PortPin_15  111
#define PortConf_PortPin_PortContainer_H_PortPin_0  112
#define PortConf_PortPin_PortContainer_H_PortPin_1  113
#define PortConf_PortPin_PortContainer_H_PortPin_2  114
#define PortConf_PortPin_PortContainer_H_PortPin_3  115
#define PortConf_PortPin_PortContainer_H_PortPin_4  116
#define PortConf_PortPin_PortContainer_H_PortPin_5  117
#define PortConf_PortPin_PortContainer_H_PortPin_6  118
#define PortConf_PortPin_PortContainer_H_PortPin_7  119
#define PortConf_PortPin_PortContainer_H_PortPin_8  120
#define PortConf_PortPin_PortContainer_H_PortPin_9  121
#define PortConf_PortPin_PortContainer_H_PortPin_10  122

/**
* @brief The last supported pin number
*/
#define PORT_MAX_PIN_PACKAGE     ((uint8)(148))

/**
* @brief Number of PSMI registers
* @details Platform constant
*/
#define PORT_NMBR_PSMI_REGS     ((uint8)(16))
/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS        ((Port_PinModeType)(9))
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_16BLOCK_NO          ((uint8)(10))


#ifndef PORT_PRECOMPILE_SUPPORT
/**
* @brief Declaration of config sets for PostBuild configuration
*/
#define PORT_CONFIG_PB
/**
 * @brief Number of unused pin intervals
*/
#define Port_NoUnUsedPins_0    26U

/**
* @brief The maximum number of configured pins
*/

#define PORT_MAX_PIN_SETTINGS_0   ((uint8)(123))
/*
* @violates @ref PORT_CFG_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_CFG_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"



/**
* @brief External declaration of the Port configuration structures for post-build mode
* @implements DPORT04017
*/
extern CONST(Port_ConfigType, PORT_CONST) PortConfigSet_0;

/**
* @brief External declaration of the Port pad functionality extra settings array
* @implements DPORT04018
*/
/*
* @violates @ref PORT_CFG_REF_6 Objects shall be defined at block scope if they are
* only accessed from within a single function.
*/
extern CONST(Pad_PSMI_Setting,PORT_CONST) Pad_funct_extrasettings[149][7];
/*
* @violates @ref PORT_CFG_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_CFG_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"

#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*
* @violates @ref PORT_CFG_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_CFG_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"

#if (PORT_SET_PIN_MODE_API == STD_ON)
/**
* @brief External declaration of the Port pin description array
* @implements DPORT04021
*/
/*
* @violates @ref PORT_CFG_REF_6 Objects shall be defined at block scope if they are
* only accessed from within a single function.
*/
extern CONST(uint16, PORT_CONST) Port_PinDescription[9][10];
#endif

/*
* @violates @ref PORT_CFG_REF_3 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_CFG_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/* @implements DPORT00004 */
#define PORT_START_SEC_CODE
/*
* @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_CFG_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"

#define PORT_STOP_SEC_CODE
/*
* @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_CFG_REF_2 Repeated include file MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */
