/**
*   @file    Compiler_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Module specific memory and pointer classes
*   @details The file Compiler_Cfg.h contains the module specific parameters (ptrclass and 
*            memclass) that are passed to the macros defined in Compiler.h
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : XPC560XB
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

/**
@file        Compiler_Cfg.h
@implements  DBASE04002
*/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Compiler_Cfg_REF_1
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
@{
* @brief ADC memory and pointer classes.
* @implements DBASE04001
*/
#define ADC_CODE
#define ADC_CONST
#define ADC_APPL_DATA
#define ADC_APPL_CONST
#define ADC_APPL_CODE
#define ADC_CALLOUT_CODE
#define ADC_VAR_NOINIT
#define ADC_VAR_POWER_ON_INIT
#define ADC_VAR_FAST
#define ADC_VAR
#define ADC_REGSPACE
/**@}*/

/** 
@{
* @brief CAN memory and pointer classes.
* @implements DBASE04001
*/
#define CAN_CODE
#define CAN_CONST
#define CAN_APPL_DATA
#define CAN_APPL_CONST
#define CAN_APPL_CODE
#define CAN_CALLOUT_CODE
#define CAN_VAR_NOINIT
#define CAN_VAR_POWER_ON_INIT
#define CAN_VAR_FAST
#define CAN_VAR
#define CAN_REGSPACE
/**@}*/

/** 
@{
* @brief CANIF memory and pointer classes.
* @implements DBASE04001
*/
#define CANIF_CODE
#define CANIF_CONST
#define CANIF_APPL_DATA
#define CANIF_APPL_CONST
#define CANIF_APPL_CODE
#define CANIF_CALLOUT_CODE
#define CANIF_VAR_NOINIT
#define CANIF_VAR_POWER_ON_INIT
#define CANIF_VAR_FAST
#define CANIF_VAR
#define CANIF_REGSPACE
/**@}*/

/** 
@{
* @brief DEM memory and pointer classes.
* @implements DBASE04001
*/
#define DEM_CODE
#define DEM_CONST
#define DEM_APPL_DATA
#define DEM_APPL_CONST
#define DEM_APPL_CODE
#define DEM_CALLOUT_CODE
#define DEM_VAR_NOINIT
#define DEM_VAR_POWER_ON_INIT
#define DEM_VAR_FAST
#define DEM_VAR
#define DEM_REGSPACE
/**@}*/

/** 
@{
* @brief DET memory and pointer classes.
* @implements DBASE04001
*/
#define DET_CODE
#define DET_CONST
#define DET_APPL_DATA
#define DET_APPL_CONST
#define DET_APPL_CODE
#define DET_CALLOUT_CODE
#define DET_VAR_NOINIT
#define DET_VAR_POWER_ON_INIT
#define DET_VAR_FAST
#define DET_VAR
#define DET_REGSPACE
/**@}*/

/** 
@{
* @brief DIO memory and pointer classes.
* @implements DBASE04001
*/
#define DIO_CODE
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR
#define DIO_REGSPACE
/**@}*/

/** 
@{
* @brief ETH memory and pointer classes.
* @implements DBASE04001
*/
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_CODE
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_CONST
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_APPL_DATA
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_APPL_CONST
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_APPL_CODE
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_CALLOUT_CODE
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_VAR_NOINIT
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_VAR_POWER_ON_INIT
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/ 
#define ETH_VAR_FAST
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/  
#define ETH_VAR
/*
* @violates @ref Compiler_Cfg_REF_1 This is not a standard library macro, 
*/  
#define ETH_REGSPACE
/**@}*/



/** 
@{
* @brief FEE memory and pointer classes.
* @implements DBASE04001
*/
#define FEE_CODE
#define FEE_CONST
#define FEE_APPL_DATA
#define FEE_APPL_CONST
#define FEE_APPL_CODE
#define FEE_CALLOUT_CODE
#define FEE_VAR_NOINIT
#define FEE_VAR_POWER_ON_INIT
#define FEE_VAR_FAST
#define FEE_VAR
#define FEE_REGSPACE
/**@}*/

/** 
@{
* @brief FLS memory and pointer classes.
* @implements DBASE04001
*/
#define FLS_CODE
#define FLS_CONST
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_APPL_CODE
#define FLS_CALLOUT_CODE
#define FLS_VAR_NOINIT
#define FLS_VAR_POWER_ON_INIT
#define FLS_VAR_FAST
#define FLS_VAR
#define FLS_REGSPACE
/**@}*/

/** 
@{
* @brief FlexRay memory and pointer classes.
* @implements DBASE04001
*/
#define FR_CODE
#define FR_CONST
#define FR_APPL_DATA
#define FR_APPL_CONST
#define FR_APPL_CODE
#define FR_CALLOUT_CODE
#define FR_VAR_NOINIT
#define FR_VAR_POWER_ON_INIT
#define FR_VAR_FAST
#define FR_VAR
#define FR_REGSPACE
/**@}*/

/** 
@{
* @brief GPT memory and pointer classes.
* @implements DBASE04001
*/
#define GPT_CODE
#define GPT_CONST
#define GPT_APPL_DATA
#define GPT_APPL_CONST
#define GPT_APPL_CODE
#define GPT_CALLOUT_CODE
#define GPT_VAR_NOINIT
#define GPT_VAR_POWER_ON_INIT
#define GPT_VAR_FAST
#define GPT_VAR
#define GPT_REGSPACE
/**@}*/

/** 
@{
* @brief ICU memory and pointer classes.
* @implements DBASE04001
*/
#define ICU_CODE
#define ICU_CONST
#define ICU_APPL_DATA
#define ICU_APPL_CONST
#define ICU_APPL_CODE
#define ICU_CALLOUT_CODE
#define ICU_VAR_NOINIT
#define ICU_VAR_POWER_ON_INIT
#define ICU_VAR_FAST
#define ICU_VAR
#define ICU_REGSPACE
/**@}*/

/** 
@{
* @brief LIN memory and pointer classes.
* @implements DBASE04001
*/
#define LIN_CODE
#define LIN_CONST
#define LIN_APPL_DATA
#define LIN_APPL_CONST
#define LIN_APPL_CODE
#define LIN_CALLOUT_CODE
#define LIN_VAR_NOINIT
#define LIN_VAR_POWER_ON_INIT
#define LIN_VAR_FAST
#define LIN_VAR
#define LIN_REGSPACE
/**@}*/

/** 
@{
* @brief MCU memory and pointer classes.
* @implements DBASE04001
*/
#define MCU_CODE
#define MCU_CONST
#define MCU_APPL_DATA
#define MCU_APPL_CONST
#define MCU_APPL_CODE
#define MCU_CALLOUT_CODE
#define MCU_VAR_NOINIT
#define MCU_VAR_POWER_ON_INIT
#define MCU_VAR_FAST
#define MCU_VAR
#define MCU_REGSPACE
/**@}*/

/** 
@{
* @brief PORT memory and pointer classes.
* @implements DBASE04001
*/
#define PORT_CODE
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_CALLOUT_CODE
#define PORT_VAR_NOINIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR
#define PORT_REGSPACE
/**@}*/

/** 
@{
* @brief PWM memory and pointer classes.
* @implements DBASE04001
*/
#define PWM_CODE
#define PWM_CONST
#define PWM_APPL_DATA
#define PWM_APPL_CONST
#define PWM_APPL_CODE
#define PWM_CALLOUT_CODE
#define PWM_VAR_NOINIT
#define PWM_VAR_POWER_ON_INIT
#define PWM_VAR_FAST
#define PWM_VAR
#define PWM_REGSPACE
/**@}*/


/** 
@{
* @brief RamTST memory and pointer classes.
* @implements DBASE04001
*/
#define RAMTST_CODE
#define RAMTST_CONST
#define RAMTST_APPL_DATA
#define RAMTST_APPL_CONST
#define RAMTST_APPL_CODE
#define RAMTST_CALLOUT_CODE
#define RAMTST_VAR_NOINIT
#define RAMTST_VAR_POWER_ON_INIT
#define RAMTST_VAR_FAST
#define RAMTST_VAR
#define RAMTST_REGSPACE
/**@}*/

/** 
@{
* @brief SchM memory and pointer classes.
* @implements DBASE04001
*/
#define SCHM_CODE
#define SCHM_CONST
#define SCHM_APPL_DATA
#define SCHM_APPL_CONST
#define SCHM_APPL_CODE
#define SCHM_CALLOUT_CODE
#define SCHM_VAR_NOINIT
#define SCHM_VAR_POWER_ON_INIT
#define SCHM_VAR_FAST
#define SCHM_VAR
#define SCHM_REGSPACE
/**@}*/

/** 
@{
* @brief SPI memory and pointer classes.
* @implements DBASE04001
*/
#define SPI_CODE
#define SPI_CONST
#define SPI_APPL_DATA
#define SPI_APPL_CONST
#define SPI_APPL_CODE
#define SPI_CALLOUT_CODE
#define SPI_VAR_NOINIT
#define SPI_VAR_POWER_ON_INIT
#define SPI_VAR_FAST
#define SPI_VAR
#define SPI_REGSPACE
/**@}*/

/** 
@{
* @brief WDG memory and pointer classes.
* @implements DBASE04001
*/
#define WDG_CODE
#define WDG_CONST
#define WDG_APPL_DATA
#define WDG_APPL_CONST
#define WDG_APPL_CODE
#define WDG_CALLOUT_CODE
#define WDG_VAR_NOINIT
#define WDG_VAR_POWER_ON_INIT
#define WDG_VAR_FAST
#define WDG_VAR
#define WDG_REGSPACE
/**@}*/

/** 
@{
* @brief WDGIF memory and pointer classes.
* @implements DBASE04001
*/
#define WDGIF_CODE
#define WDGIF_CONST
#define WDGIF_APPL_DATA
#define WDGIF_APPL_CONST
#define WDGIF_APPL_CODE
#define WDGIF_CALLOUT_CODE
#define WDGIF_VAR_NOINIT
#define WDGIF_VAR_POWER_ON_INIT
#define WDGIF_VAR_FAST
#define WDGIF_VAR
#define WDGIF_REGSPACE
/**@}*/

/** 
* @brief Define for ComStack Data.
* @implements DBASE04001
*/
#define AUTOSAR_COMSTACKDATA

/* --------------------------------------------------------------------------*/
/*                   RTE                                                     */
/* --------------------------------------------------------------------------*/

/* <INIT_POLICY> is the initialization policy of variables.
   Possible values are:
   
   NO_INIT: Used for variables that are never cleared and never initialized.
   CLEARED: Used for variables that are cleared to zero after every reset.
   POWER_ON_CLEARED: Used for variables that are cleared to zero only after
   power on reset.
   INIT: Used for variables that are initialized with values after every reset.
   POWER_ON_INIT: Used for variables that are initialized with values only
   after power on reset */

/* To be used for code. */
#define RTE_CODE

/* To be used for references on application functions.
   (e.g. callout function pointers). */
#define RTE_CALLOUT_CODE

/* To be used for code that shall go into fast code memory segments. */
#define RTE_CODE_FAST

/* To be used for code that shall go into slow code memory segments. */
#define RTE_CODE_SLOW

/* To be used for global or static constants. */
#define RTE_CONST

/* To be used for calibration constants. */
#define RTE_CALIB

/* To be used for module configuration constants. */
#define RTE_CONFIG_DATA

/* <PREFIX>_CONST_SAVED_RECOVERY_ZONE_<INIT_POLICY> To be used for all global
   or static variables. */
#define RTE_CONST_SAVED_RECOVERY_ZONE_NO_INIT
#define RTE_CONST_SAVED_RECOVERY_ZONE_CLEARED
#define RTE_CONST_SAVED_RECOVERY_ZONE_POWER_ON_CLEARED
#define RTE_CONST_SAVED_RECOVERY_ZONE_INIT
#define RTE_CONST_SAVED_RECOVERY_ZONE_POWER_ON_INIT

/* To be used for references on application data (expected to be in RAM or ROM)
   passed via API. */
#define RTE_APPL_DATA

/* To be used for references on application constants (expected to be certainly
   in ROM, for instance pointer of Init-function) passed via API. */
#define RTE_APPL_CONST

/* <PREFIX>_VAR_<INIT_POLICY> To be used for all global or static variables. */
#define RTE_VAR_NO_INIT
#define RTE_VAR_CLEARED
#define RTE_VAR_POWER_ON_CLEARED
#define RTE_VAR_INIT
#define RTE_VAR_POWER_ON_INIT

/* <PREFIX>_VAR_FAST_<INIT_POLICY> To be used for all global or static
   variables that have at least one of the following properties:
   A. accessed bitwise
   B. frequently used
   C. high number of accesses in source code */
#define RTE_VAR_FAST_NO_INIT
#define RTE_VAR_FAST_CLEARED
#define RTE_VAR_FAST_POWER_ON_CLEARED
#define RTE_VAR_FAST_INIT
#define RTE_VAR_FAST_POWER_ON_INIT

/* <PREFIX>_VAR_SLOW_<INIT_POLICY> To be used for all infrequently accessed
   global or static variables. */
#define RTE_VAR_SLOW_NO_INIT
#define RTE_VAR_SLOW_CLEARED
#define RTE_VAR_SLOW_POWER_ON_CLEARED
#define RTE_VAR_SLOW_INIT
#define RTE_VAR_SLOW_POWER_ON_INIT

/* <PREFIX>_INTERNAL_VAR_<INIT_POLICY> To be used for global or static
   variables which are accessible from a calibration tool. */
#define RTE_INTERNAL_VAR_NO_INIT
#define RTE_INTERNAL_VAR_CLEARED
#define RTE_INTERNAL_VAR_POWER_ON_CLEARED
#define RTE_INTERNAL_VAR_INIT
#define RTE_INTERNAL_VAR_POWER_ON_INIT

/* <PREFIX>_VAR_SAVED_ZONE_<INIT_POLICY> To be used for RAM buffers of
   variables saved oin non-volatile memory. */
#define RTE_VAR_SAVED_ZONE_NO_INIT
#define RTE_VAR_SAVED_ZONE_CLEARED
#define RTE_VAR_SAVED_ZONE_POWER_ON_CLEARED
#define RTE_VAR_SAVED_ZONE_INIT
#define RTE_VAR_SAVED_ZONE_POWER_ON_INIT


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILER_CFG_H */

/** @} */
