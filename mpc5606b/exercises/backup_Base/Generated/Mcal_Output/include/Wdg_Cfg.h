/**
*   @file     Wdg_Cfg.h
*   @version  1.0.1
*
*   @brief    AUTOSAR Wdg - Contains the implementation of the Watchdog API
*   @details  It contains the layer requested by autosar. The functions are independent of
*             hardware settings.
*
*   @addtogroup  Wdg  
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF12_ASR_REL_4_0_REV_0003_20161209
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef WDG_CFG_H
#define WDG_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Cfg_h_REF_2
* Full description of the violated MISRA rule and the reason why it is allowed. Ex:
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Wdg_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Wdg_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a
* constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
* do-while-zero construct.
*
* @section  Wdg_Cfg_h_REF_5
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only 
* accessed from within a single function.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Wdg_Cfg_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "WdgIf_Types.h"
#include "Gpt.h"
/*
* @violates @ref Wdg_Cfg_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "Mcal.h"



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_VENDOR_ID_CFG                    43

#define WDG_MODULE_ID_CFG                    102
/* @violates @ref Wdg_Cfg_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG     4
/* @violates @ref Wdg_Cfg_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MINOR_VERSION_CFG     0
/* @violates @ref Wdg_Cfg_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_REVISION_VERSION_CFG  3
#define WDG_SW_MAJOR_VERSION_CFG             1
#define WDG_SW_MINOR_VERSION_CFG             0
#define WDG_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/




/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */


/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
#define WDG_INSTANCE0 STD_ON



/**
* @brief  This constant specifies what value of the CR's master access protection will be used
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define SWT_MAP_ENABLE_BITS           SWT_MAP_ENABLE_8BITS

/**
* @brief  This define indicate that the watchdog is internal
*/

#define WDG_INTERNAL_MODULE         0

/**
* @brief  This define indicate that the watchdog is external connected on SPI
*/

#define WDG_EXTERNAL_MODULE_SPI     1

/**
* @brief  This define indicate that the watchdog is external connected on DIO
*/
#define WDG_EXTERNAL_MODULE_DIO     2
/**
 * @brief  This define indicate the number of HW IPs available on the Platform
 */
#define WDG_NO_OF_INSTANCES            (1)

/**
* @brief  This variable will indicate which type of driver is in use
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_TYPE           WDG_INTERNAL_MODULE

/**
* @brief  Compile switch to enable/disable development error detection for this module
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_DEV_ERROR_DETECT   STD_ON

/**
* @brief  Compile switch to allow/forbid disabling the watchdog driver during runtime
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_DISABLE_ALLOWED    STD_ON

/**
* @brief  Compile switch to enable/disable the version information
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_VERSION_INFO_API   STD_ON

/**
* @brief  This variable will indicate the index of the driver that it is in use
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WdgConf_WdgGeneral_WdgIndex (uint8)0

/**
* @brief  This variable will indicate the Wdg Initial Timeout parameter
*/

/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_INITIAL_TIMEOUT 200.0


/**
* @brief  This variable will indicate the Wdg Max Timeout parameter
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDGMAXTIMEOUT       (uint16)4200.0









/** 
* @brief  This variable will indicate RAM/ROM execution
*/
#define WDG_ROM

/**
* @brief   Switches the Production Error Detection and Notification OFF
*/

/* @violates @ref Wdg_Cfg_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_DISABLE_DEM_REPORT_ERROR_STATUS   STD_ON  /* Enable Production Error Detection */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief  This enumerated type will contain the watchdog driver's possible modes to be triggered
*/
typedef enum
{
    WDG_KEYED_SERVICE   = 0x00,  /**< @brief The watchdog driver is serviced using keyed sequence */
    WDG_FIXED_SERVICE            /**< @brief The watchdog driver is serviced using a fix sequence */
} Wdg_ServiceModeType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief  Structure containing the hardware data for the Software Watchdog Timer (SWT)
*         - the IP on which the internal Watchodg is mapped
*/

typedef struct
{
   uint32   WDG_CR;     /**< @brief The control register of SWT IP */
   uint32   WDG_TO;     /**< @brief The timeout value register of SWT IP */
   uint32   WDG_WN;     /**< @brief The window value register of SWT IP */
   uint32   WDG_TO_US;  /**< @brief The timeout value of SWT IP in usec */
   uint32   WDG_WN_US;  /**< @brief The window value of SWT IP in usec */
} SWT_HwSettingsType;

/**
* @brief  Structure containing the Watchdog Hardware Instance for the Software Watchdog Timer (SWT)
*         - the IP on which the internal Watchodg is mapped
*/
typedef enum Wdg_IPW_InstanceType
{
    WDG_IPW_INSTANCE0 = 0x0U,  /**< @brief SWT0  */
    WDG_IPW_INSTANCE1          /**< @brief SWT1  */
} Wdg_IPW_InstanceType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref Wdg_Cfg_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Wdg_Cfg_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref Wdg_Cfg_h_REF_5 MISRA 2004 Required Rule 8.7, Objects shall be defined at 
* block scope if they are only accessed from within a single function.
*/
extern CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Disable_RejectedCfg;
/*
* @violates @ref Wdg_Cfg_h_REF_5 MISRA 2004 Required Rule 8.7, Objects shall be defined at 
* block scope if they are only accessed from within a single function.
*/
extern CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Mode_FailedCfg;
/*
* @violates @ref Wdg_Cfg_h_REF_5 MISRA 2004 Required Rule 8.7, Objects shall be defined at 
* block scope if they are only accessed from within a single function.
*/
extern CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Miss_TriggerCfg;
#endif

/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_POSTBUILD_SUPPORT STD_OFF

/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_PRECOMPILE_SUPPORT STD_ON
/**
* @brief Defines the use of Pre compile (PC) support
*/
/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_CFG_EXTERN_DECLARATIONS \
    extern CONST(Wdg_ConfigType, WDG_CONST) Wdg_ConfigPC0;

/* @violates @ref Wdg_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, expand C marcos */
#define WDG_LINKTIME_SUPPORT STD_OFF

/* @violates @ref Wdg_Cfg_h_REF_3 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Wdg_Cfg_h_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"



/**
* @brief Implementation specific. This type shall be chosen in order to have the most efficient
*        implementation on a specific microcontroller platform.
*        Range: 0 ... <width of the watchdog service code>
*        Description: Width of the watchdog service code
*/
typedef uint16 Wdg_ServiceKeyWidthType;

/*
 * @brief This type shall be chosen in order to implement a callback notification in the Wdg_Isr routine.
 */
typedef P2FUNC( void, WDG_CODE, Wdg_CallbackPtrType )  ( void );

/**
* @brief   Structure to hold the watchdog driver configuration set.
* @details Used for pointers to structures holding configuration data provided
*          to the Wdg module initialization routine for configuration of the
*          module and watchdog hardware.
*
* @api
*/
typedef struct
{
#if (WDG_TYPE == WDG_INTERNAL_MODULE)
    SWT_HwSettingsType    Config_Wdg_Internal[3];  /**< @brief The configuration for watchdog
                                                                 driver on SWT */
#elif (WDG_TYPE == WDG_EXTERNAL_MODULE_SPI)
    Spi_SequenceConfig      Config_Wdg_External_Spi; /**< @brief The configuration for watchdog
                                                                 driver on SPI */
#elif(WDG_TYPE == WDG_EXTERNAL_MODULE_DIO)
    Dio_ChannelGroupType    Config_Wdg_External_Dio; /**< @brief The configuration for watchdog
                                                                 driver on DIO */
#endif
    Wdg_IPW_InstanceType    Wdg_Instance;                /**< @brief The type of Wdg Hardware Instance*/
    WdgIf_ModeType          Wdg_CfgDefaultMode;     /**< @brief The default mode for watchdog
                                                                 driver's configuration */
#if (WDG_TYPE == WDG_INTERNAL_MODULE)
    Wdg_ServiceModeType     Wdg_CfgServiceMode;     /**< @brief The type of the trigger mode for
                                                                watchdog driver on SWT */
    Wdg_ServiceKeyWidthType Wdg_KeyServiceValue;    /**< @brief Initial value of the service key */
    Wdg_CallbackPtrType     Wdg_CallBackPtr;             /**< @brief Call Back notification */

#endif                                                   
    Gpt_ChannelType         Gpt_Channel;                 /**< @brief Gpt channel used */
    uint32                  Gpt_Channel_Frequency_MHz;   /**< @brief Gpt channel frequency in MHz*/
} Wdg_ConfigType;

extern P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Ram_LLD_ConfigPtr[WDG_NO_OF_INSTANCES];


/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* WDG_CFG_H */
/** @} */

