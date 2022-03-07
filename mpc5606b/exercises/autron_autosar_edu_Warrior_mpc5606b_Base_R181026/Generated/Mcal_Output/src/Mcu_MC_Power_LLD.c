/**
*   @file    Mcu_MC_Power_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - File used by MCU to configure PCU parameters.
*   @details This file contains a function used for initializing parameters for the PCU module.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_Power_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_MC_Power_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_MC_Power_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers
* to other types used in macros for reading or writing data from address location of controller register.
*
* @section Mcu_MC_Power_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section Mcu_MC_Power_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Mcu_MC_Power_lld.c
* @implements     DMCU05029, DMCU05030, DMCU05031, DMCU05032, DMCU05033, DMCU05034, DMCU05035
*/
#define MCU_MC_POWER_LLD_VENDOR_ID_C                      43
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_POWER_LLD_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_POWER_LLD_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_POWER_LLD_AR_RELEASE_REVISION_VERSION_C    3
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_POWER_LLD_SW_MAJOR_VERSION_C               1
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_POWER_LLD_SW_MINOR_VERSION_C               0
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_POWER_LLD_SW_PATCH_VERSION_C               1

/*==================================================================================================
                                        FILE VERSION CHECKS
 ==================================================================================================*/
/* Check if current file and Mcu_LLD.h file are of the same vendor */
#if (MCU_MC_POWER_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
    #error "Mcu_MC_Power_LLD.c and Mcu_LLD.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_LLD.h file are of the same Autosar version */
#if ((MCU_MC_POWER_LLD_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_POWER_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_POWER_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_MC_Power_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h file are of the same Software version */
#if ((MCU_MC_POWER_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_MC_POWER_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_MC_POWER_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_MC_Power_LLD.c and Mcu_LLD.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          This function configures the PCU module.
* @details        The function defines whether the SRAM memory is on or off in each device mode
*                 for power domain 2.
*
* @param[in]      ConfigLLDPtr   Pointer to LLD configuration structure
*
* @return         void
*
* @implements     DMCU05153
*/
/* @violates @ref Mcu_MC_Power_LLD_c_REF_4 Required Rule 8.10, API could not be made static.*/
FUNC(void, MCU_CODE) Mcu_Power_Init(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr)
{
    /* Power Domains 2 Configurations */
    /* @violates @ref Mcu_MC_Power_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_PCU_PCONF2_R, (uint32) (ConfigLLDPtr->PwrDom2));
}

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_MC_Power_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Power_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
