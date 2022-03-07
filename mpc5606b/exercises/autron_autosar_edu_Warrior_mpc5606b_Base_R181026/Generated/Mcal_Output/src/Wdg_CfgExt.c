
/**
* @file    Wdg_CfgExt.c
* @version 1.0.1
* @brief   AUTOSAR Wdg - contains the data exported by the watchodg module
* @details Contains the information that will be exported by the module, as requested by Autosar.
*
* @addtogroup  Wdg
* @{
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_CfgExt_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
*
* @section Wdg_CfgExt_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Wdg_CfgExt_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
*
* @section Wdg_CfgExt_c_REF_4
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          The functions/variables are part of external configuration
*
* @section Wdg_CfgExt_c_REF_5
*          Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Wdg_CfgExt_c_REF_6
*          Violates MISRA 2004 Required Rule 8.8,The external object has been declared only once in one file.
*          This violation comes because global variable has not been initialized. Variable can not be
*          initialized and is placed in no init section.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Wdg_CfgExt.c 
*/

#include "Wdg_Channel.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_CfgExt.c   
*/
#define WDG_VENDOR_ID_CFG_C                    43
/** @violates @ref Wdg_CfgExt_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Wdg_CfgExt_c_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG_C     4
/** @violates @ref Wdg_CfgExt_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Wdg_CfgExt_c_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MINOR_VERSION_CFG_C     0
/** @violates @ref Wdg_CfgExt_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Wdg_CfgExt_c_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_REVISION_VERSION_CFG_C  3
#define WDG_SW_MAJOR_VERSION_CFG_C             1
#define WDG_SW_MINOR_VERSION_CFG_C             0
#define WDG_SW_PATCH_VERSION_CFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg header file are of the same vendor */
#if (WDG_VENDOR_ID_CFG_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg_CfgExt.c and Wdg_Channel.h have different vendor ids"
#endif

/* Check if current file and Wdg header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG_C    != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION_CFG_C    != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION_CFG_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Wdg_CfgExt.c and Wdg_Channel.h are different"
#endif
/* Check if current file and Wdg header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_CFG_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION_CFG_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION_CFG_C != WDG_CHANNEL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_CfgExt.c and Wdg_Channel.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
/* @violates @ref Wdg_CfgExt_c_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_CfgExt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
/* @violates @ref Wdg_CfgExt_c_REF_6 MISRA 2004 Required Rule 8.8, The external object has been 
declared only once in one file. */
extern CONST(Wdg_ConfigType, WDG_CONST)Wdg_ConfigPC0;

P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_ConfigPC[WDG_NO_OF_INSTANCES]={
&Wdg_ConfigPC0
};
#endif





#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/**
* @brief The DemEventParameter parameter which shall be issued when the error "Initialization or mode
*        switch failed because it would disable the watchdog" has occurred.
*
*
*/
/*
* @violates @ref Wdg_CfgExt_c_REF_4 MISRA 2004 Required Rule 8.10, Declarations and definitions 
* of Objects or Functions at File scope
*/
CONST(Mcal_DemErrorType, WDG_CONST)  Wdg_E_Disable_RejectedCfg = { (uint32)STD_ON, (uint32)13U}; /* WDG_E_DISABLE_REJECTED parameters*/

/**
* @brief The DemEventParameter parameter which shall be issued when the error "Setting
*        a watchdog mode failed (during initialization or mode switch)" has occurred.
*
*
*/
CONST(Mcal_DemErrorType, WDG_CONST)  Wdg_E_Mode_FailedCfg = { (uint32)STD_ON, (uint32)15U}; /* WDG_E_MODE_FAILED parameters*/

/**
* @brief The DemEventParameter parameter which shall be issued when Wdg miss a trigger.
*
*
*/
/*
* @violates @ref Wdg_CfgExt_c_REF_4 MISRA 2004 Required Rule 8.10, Declarations and definitions 
* of Objects or Functions at File scope
*/
CONST(Mcal_DemErrorType, WDG_CONST)  Wdg_E_Miss_TriggerCfg = { (uint32)STD_ON, (uint32)14U}; /* WDG_E_MISS_TRIGGER parameters*/
#endif

/* @violates @ref Wdg_CfgExt_c_REF_5 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_CfgExt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_CfgExt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                     GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */
