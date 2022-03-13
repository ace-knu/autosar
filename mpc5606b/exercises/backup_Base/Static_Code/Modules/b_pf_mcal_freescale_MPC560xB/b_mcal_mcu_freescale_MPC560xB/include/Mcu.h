/**
*   @file    Mcu.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - High level header of MCU driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
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

#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR 
* specifications although it exceeds the max length of 31 characters
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @implements     DMCU00001, DMCU00002 */
/* @violates @ref Mcu_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Std_Types.h"
#include "Mcu_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*
* @implements     DMCU03001, DMCU03002, DMCU03054, DMCU03030, DMCU03031, DMCU03032, DMCU03033, DMCU03034
*/
#define MCU_VENDOR_ID                      43
#define MCU_MODULE_ID                      101
#define MCU_AR_RELEASE_MAJOR_VERSION       4
#define MCU_AR_RELEASE_MINOR_VERSION       0
/* @violates @ref Mcu_H_REF_2 MISRA 2004 Required Rule 1.4, Identifier clash */
#define MCU_AR_RELEASE_REVISION_VERSION    3
#define MCU_SW_MAJOR_VERSION               1
#define MCU_SW_MINOR_VERSION               0
#define MCU_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_VENDOR_ID_CFG)
#error "Mcu.h and Mcu_Cfg.h have different vendor ids"
#endif
/* @implements     DMCU06001 */
/* Check if current file and MCU configuration header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION    != MCU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCU_AR_RELEASE_MINOR_VERSION    != MCU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCU_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif
/* Check if current file and MCU configuration header file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION_CFG) || \
     (MCU_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION_CFG) || \
     (MCU_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same Autosar version */
    #if ((MCU_AR_RELEASE_MAJOR_VERSION     != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_AR_RELEASE_MINOR_VERSION     != STD_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief            API service ID of Mcu_Init function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03003
* 
* @api
*/
#define MCU_INIT_ID               ((uint8)0x00U)
/**
* @brief            API service ID of Mcu_InitRamSection function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03004
* 
* @api
*/
#define MCU_INITRAMSECTION_ID     ((uint8)0x01U)
/**
* @brief            API service ID of Mcu_InitClock function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03005
* 
* @api
*/
#define MCU_INITCLOCK_ID          ((uint8)0x02U)
/**
* @brief            API service ID of Mcu_DistributePllClock function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03006
* 
* @api
*/
#define MCU_DISTRIBUTEPLLCLOCK_ID ((uint8)0x03U)
/**
* @brief            API service ID of Mcu_GetPllStatus function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03007
* 
* @api
*/
#define MCU_GETPLLSTATUS_ID       ((uint8)0x04U)
/**
* @brief            API service ID of Mcu_GetResetReason function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03008
* 
* @api
*/
#define MCU_GETRESETREASON_ID     ((uint8)0x05U)
/**
* @brief            API service ID of Mcu_GetResetRawValue function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03009
* 
* @api
*/
#define MCU_GETRESETRAWVALUE_ID   ((uint8)0x06U)
/**
* @brief            API service ID of Mcu_PerformReset function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03010
* 
* @api
*/
#define MCU_PERFORMRESET_ID       ((uint8)0x07U)
/**
* @brief            API service ID of Mcu_SetMode function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03011
* 
* @api
*/
#define MCU_SETMODE_ID            ((uint8)0x08U)
/**
* @brief            API service ID of Mcu_GetVersionInfo function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03012
* 
* @api
*/
#define MCU_GETVERSIONINFO_ID     ((uint8)0x09U)


/**
* @brief            API service ID of Mcu_GetVersionInfo function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03013
*
* @api
*/
#define MCU_GETRAMSTATE_ID       ((uint8)0x10U)

/**
* @brief            MCU Instance ID
* @implements       DMCU03014
* 
* @api
*/
#define MCU_INSTANCE_ID           ((uint8)0x0U)

/**
* @brief            API service ID ofMcu_Init_Osc function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03015
* 
* @api
*/
#define MCU_INITOSC_ID            ((uint8)0x20U)

/**
* @brief            API service ID of Mcu_Change_Mode function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03016
* 
* @api
*/
#define MCU_CHANGE_MODE_ID        ((uint8)0x21U)

/**
* @brief            API service ID of Mcu_Change_LowPower_Mode function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03017
* 
* @api
*/
#define MCU_CHANGE_LOWPOWER_ID    ((uint8)0x22U)

/**
* @brief            API service ID of Mcu_Apply_LowPower_Mode function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03018
* 
* @api
*/
#define MCU_APPLY_LOWPOWER_ID     ((uint8)0x23U)

/**
* @brief            API service ID of Mcu_Apply_LowPower_Mode function
* @details          Parameters used when raising an error/exception
* @implements       DMCU03019
* 
* @api
*/
#define MCU_APPLY_RUNMODE_ID      ((uint8)0x24U)

/**
* @brief            Service ID of Mcu_Apply_Mode function
* @details          Parameter used when raising an error/exception
* @implements
* 
* @api
*/
#define MCU_APPLY_MODE_ID         ((uint8)0x25U)

/**
* @brief            API service ID of Mcu_Disable_CMU function
* @details          Parameters used when raising an error/exception
* @implements       PR-MCAL-3319
* 
* @api
*/
#define MCU_DISABLE_CMU_ID        ((uint8)0x26U)

/**
* @brief            API service called with wrong parameter
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03020
* 
* @api
*/
#define MCU_E_PARAM_CONFIG        ((uint8)0x0AU)

/**
* @brief            ClockSetting shall be within the settings defined in the configuration
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03021
* 
* @api
*/
#define MCU_E_PARAM_CLOCK         ((uint8)0x0BU)

/**
* @brief            McuMode shall be within the modes defined in the configuration data
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03022
* 
* @api
*/
#define MCU_E_PARAM_MODE          ((uint8)0x0CU)

/**
* @brief            RamSection shall be within the sections defined in the configuration data
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03023
* 
* @api
*/
#define MCU_E_PARAM_RAMSECTION    ((uint8)0x0DU)

/**
* @brief            A error shall be reported if the status of the PLL is detected as not locked
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03024
* 
* @api
*/
#define MCU_E_PLL_NOT_LOCKED      ((uint8)0x0EU)

/**
* @brief            API service used without module initialization
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03025
* 
* @api
*/
#define MCU_E_UNINIT              ((uint8)0x0FU)
/**
* @brief            The error MCU_E_PARAM_POINTER shall be reported 
*                   in case the value is a NULL pointer in 
*                   Mcu_GetVersionInfo() API
* @details          If development error detection is enabled, the parameter versioninfo shall 
*                   be checked for being NULL. 
* @implements       DMCU03026
* 
* @api
*/
#define MCU_E_PARAM_POINTER        ((uint8)0x10U)
/**
* @brief            Error: Mcu_InitClock() was not executed before Mcu_GetPllStatus() or 
*                   Mcu_DistributePllClock()
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03027
* 
* @api
*/
#define MCU_E_CLOCK_UNINIT        ((uint8)0x11U)
/**
* @brief            Raw Reset Value returned in a case when Mcu_GetResetRawValue() is called before
*                   Mcu_Init() is called
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       DMCU03028
* 
* @api
*/
#define MCU_RAW_RESET_DEFAULT      ((uint32)0xFFFFFFFFUL)

/**
* @brief            CER Error
* @details          Wrong mode transition
* @implements       DMCU03029
* 
* @api
*/
#define MCU_E_WRONG_MODE         ((uint8)0x20U)

/**
* @brief            Disabled mode transition error
* @details          Mcu_Apply_Mode() tries to apply a disabled mode
* @implements
* 
* @api
*/
#define MCU_E_MODE_NOT_ENABLED    ((uint8)0x11U)

/**
* @brief            CMU shall be within the sections defined in the configuration data
* @details          Errors and exceptions that will be detected by the MCU driver
* @implements       PR-MCAL-3319
* 
* @api
*/
#define MCU_E_PARAM_CMU            ((uint8)0x12U)

/**
* @brief            API service ID of Mcu_Enable_ClockOutput function
* @details          Parameters used when raising an error/exception
* @implements       
* 
* @api
*/
#define MCU_ENABLECLOCKOUTPUT_ID     ((uint8)0x20U)

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

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/* @violates @ref Mcu_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "MemMap.h"

/* @implements DMCU03042 */
extern FUNC (void, MCU_CODE) Mcu_Init (P2CONST (Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) \
    ConfigPtr);

/* @implements DMCU03043 */
extern FUNC (Std_ReturnType, MCU_CODE) Mcu_InitRamSection (VAR (Mcu_RamSectionType, AUTOMATIC) \
    RamSection);

#if MCU_INIT_CLOCK == TRUE
/* @implements DMCU03044 */
extern FUNC (Std_ReturnType, MCU_CODE) Mcu_InitClock (VAR (Mcu_ClockType, AUTOMATIC) \
    ClockSetting);
#endif

#if (MCU_NO_PLL == FALSE)
/* @implements DMCU03045 */
extern FUNC (void, MCU_CODE) Mcu_DistributePllClock (void);
#endif

/* @implements DMCU03046 */
extern FUNC (Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus (void);

/* @implements DMCU03047 */
extern FUNC (Mcu_ResetType, MCU_CODE) Mcu_GetResetReason (void);

/* @implements DMCU03048 */
extern FUNC (Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue (void);

#if MCU_PERFORM_RESET_API == STD_ON
/* @implements DMCU03049 */
extern FUNC (void, MCU_CODE) Mcu_PerformReset (void);
#endif /* #if MCU_PERFORM_RESET_API == STD_ON */

/* @implements DMCU03050 */
extern FUNC (void, MCU_CODE) Mcu_SetMode (VAR (Mcu_ModeType, AUTOMATIC) McuMode);

#if MCU_VERSION_INFO_API == STD_ON
extern FUNC (void, MCU_CODE) Mcu_GetVersionInfo (P2VAR (Std_VersionInfoType, AUTOMATIC, \
          MCU_APPL_DATA) versioninfo);
#endif  /* #if MCU_VERSION_INFO_API == STD_ON */

#if (MCU_GET_RAM_STATE_API == STD_ON)
extern FUNC (Mcu_RamStateType, MCU_CODE) Mcu_GetRamState (void);
#endif  /* #if MCU_GET_RAM_STATE_API == STD_ON */

#define MCU_STOP_SEC_CODE
/* @violates @ref Mcu_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_H */

/** @} */
