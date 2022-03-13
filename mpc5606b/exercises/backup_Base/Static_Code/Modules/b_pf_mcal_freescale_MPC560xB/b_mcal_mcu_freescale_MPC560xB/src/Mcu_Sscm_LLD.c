/**
*   @file    Mcu_SSCM.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - SSCM functions implementation.
*   @details Specific functions for SSCM configuration and control.
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
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_SSCM_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a violation
* since all header files are protected against multiple inclusions
*
* @section Mcu_SSCM_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_SSCM_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_SSCM_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_SSCM_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions 
* at file scope shall have internal linkage unless external linkage is required
*
* @section Mcu_SSCM_c_REF_6
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_Sscm_LLD.h"
/* @violates @ref Mcu_SSCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED (MCU_USER_MODE_REG_PROT_ENABLED)

/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/
/**
* @file             Mcu_SSCM.c
*/
#define MCU_SSCM_LLD_VENDOR_ID_C                        43
/* @violates @ref Mcu_SSCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
/*
* @violates @ref Mcu_SSCM_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SSCM_LLD_AR_RELEASE_MAJOR_VERSION_C         4
/* @violates @ref Mcu_SSCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
/*
* @violates @ref Mcu_SSCM_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SSCM_LLD_AR_RELEASE_MINOR_VERSION_C         0
/* @violates @ref Mcu_SSCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
/*
* @violates @ref Mcu_SSCM_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SSCM_LLD_AR_RELEASE_REVISION_VERSION_C      3
#define MCU_SSCM_LLD_SW_MAJOR_VERSION_C                 1
#define MCU_SSCM_LLD_SW_MINOR_VERSION_C                 0
#define MCU_SSCM_LLD_SW_PATCH_VERSION_C                 1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_SSCM header file are of the same vendor */
#if (MCU_SSCM_LLD_VENDOR_ID_C != MCU_SSCM_LLD_VENDOR_ID)
    #error "Mcu_Sscm_LLD.c and Mcu_Sscm_LLD.h have different vendor ids"
#endif
/* Check if current file and Mcu_SSCM header file are of the same Autosar version */
#if ((MCU_SSCM_LLD_AR_RELEASE_MAJOR_VERSION_C    != MCU_SSCM_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SSCM_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_SSCM_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SSCM_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_SSCM_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_Sscm_LLD.c and Mcu_Sscm_LLD.h are different"
#endif
/* Check if current file and Mcu_SSCM header file are of the same Software version */
#if ((MCU_SSCM_LLD_SW_MAJOR_VERSION_C != MCU_SSCM_LLD_SW_MAJOR_VERSION) || \
     (MCU_SSCM_LLD_SW_MINOR_VERSION_C != MCU_SSCM_LLD_SW_MINOR_VERSION) || \
     (MCU_SSCM_LLD_SW_PATCH_VERSION_C != MCU_SSCM_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_Sscm_LLD.c and Mcu_Sscm_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    #if ((MCU_SSCM_LLD_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SSCM_LLD_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_Sscm_LLD.c and Det.h are different"
    #endif
#endif
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_SSCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SSCM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*                            statements and comments before '#include'
*/
#include "MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_SSCM_ERROR_CONFIG == STD_ON)
/**
* @brief          SSCM module configuration.
* @details
*
* @param[in]
*/
FUNC(void, MCU_CODE) Mcu_Sscm_Init(VAR(uint16, AUTOMATIC) mcu_sscm_config_val)
{
    /* Write SSCM configuration to SSCM_ERROR register */
    /* @violates @ref Mcu_SSCM_c_REF_4 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    REG_WRITE16(SSCM_ERROR_ADDR16,(uint16)mcu_sscm_config_val);
}
#endif

#if (MCU_SSCM_GET_STATUS_API == STD_ON)
/**
* @brief          SSCM module configuration.
* @details
*
* @param[in]
*
* @implements     PR-MCAL-3284
*
*/
/* @violates @ref Mcu_SSCM_c_REF_5 MISRA 2004 Required Rule 8.10, functions at file scope */
FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_Sscm_GetStatus(VAR( void, AUTOMATIC))
{
    VAR(Mcu_SSCM_ReturnType, AUTOMATIC) Status = (Mcu_SSCM_ReturnType)0U;
    /* @violates @ref Mcu_SSCM_c_REF_4 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    Status = (Mcu_SSCM_ReturnType)REG_READ16(SSCM_STATUS_ADDR16);
    return Status;
}
#endif /* MCU_SSCM_GET_STATUS_API == STD_ON */

#if (MCU_SSCM_GET_MEMCONFIG_API == STD_ON)
/**
* @brief          SSCM module configuration.
* @details
*
* @param[in]
*
* @implements     PR-MCAL-3285, PR-MCAL-3287
*
*/
/* @violates @ref Mcu_SSCM_c_REF_5 MISRA 2004 Required Rule 8.10, functions at file scope */
FUNC(Mcu_SSCM_ReturnType, MCU_CODE) Mcu_Sscm_GetMemConfig(VAR( void, AUTOMATIC))
{
    VAR(Mcu_SSCM_ReturnType, AUTOMATIC) config = (Mcu_SSCM_ReturnType)0U;
    /* @violates @ref Mcu_SSCM_c_REF_4 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    config = (Mcu_SSCM_ReturnType)REG_READ16(SSCM_MEMCONFIG_ADDR16);
    return config;
}
#endif /* MCU_SSCM_GET_MEMCONFIG_API == STD_ON */

#if (MCU_SSCM_GET_UOPS_API == STD_ON)
/**
* @brief          SSCM module configuration.
* @details
*
* @param[in]
*
* @implements     PR-MCAL-3286
*
*/
/* @violates @ref Mcu_SSCM_c_REF_5 MISRA 2004 Required Rule 8.10, functions at file scope */
FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_Sscm_GetUops(VAR( void, AUTOMATIC))
{
    VAR(Mcu_SSCM_ReturnType, AUTOMATIC) Uops = (Mcu_SSCM_ReturnType)0U;
    /* @violates @ref Mcu_SSCM_c_REF_4 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    Uops = (Mcu_SSCM_ReturnType)REG_READ32(SSCM_UOPS_ADDR32);
    return Uops;
}
#endif /* MCU_SSCM_GET_UOPS_API == STD_ON */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SSCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SSCM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*                            statements and comments before '#include'
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
