/**
*   @file    Mcu_NonASR.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - High level part of MCU driver.
*   @details This file contains the functions not defined by AutoSAR.
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
* @section Mcu_NonASR_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section Mcu_NonASR_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_NonASR_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR
* specifications although it exceeds the max length of 31 characters
*
* @section Mcu_NonASR_C_REF_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel parameters,
* the indexing of the pointer is taken care and hence the unintended memory location will not
* be accessed
*
* @section Mcu_NonASR_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, API could not be made static.
*
* @section Mcu_NonASR_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the 
* significance of more than 31 characters.
*
* @section Mcu_NonASR_C_REF_8
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be permitted.
* This violation is due to range error check.
*
* @section Mcu_NonASR_C_REF_9
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type than an integral type.
* This is part of the test file used for checking the BASE header files. Conversions are verified to
* be ok for this file.
*
* @section Mcu_NonASR_C_REF_10
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions 
* at file scope shall have internal linkage unless external linkage is required
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "Mcu_NonASR.h"
#include "Mcu_LLD.h"
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* @implements     DMCU00004 */
#include "Det.h"
#endif

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
/**
* @file           Mcu_NonASR.c
*/
#define MCU_VENDOR_ID_C_NONASR                      43
/*
* @violates @ref Mcu_NonASR_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_MAJOR_VERSION_C_NONASR       4
/*
 * @violates @ref Mcu_NonASR_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
 * characters.
 */
#define MCU_AR_RELEASE_MINOR_VERSION_C_NONASR       0
/* @violates @ref Mcu_NonASR_C_REF_3 MISRA 2004 Required Rule 1.4, Identifier clash 
 * @violates @ref Mcu_NonASR_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
 * characters.
 */
#define MCU_AR_RELEASE_REVISION_VERSION_C_NONASR    3
#define MCU_SW_MAJOR_VERSION_C_NONASR               1
#define MCU_SW_MINOR_VERSION_C_NONASR               0
#define MCU_SW_PATCH_VERSION_C_NONASR               1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID_C_NONASR != MCU_VENDOR_ID)
#error "Mcu_NonASR.c and Mcu.h have different vendor ids"
#endif
#ifdef CHECK_AUTOSAR_VERSION
    /* Check if source file and MCU header file are of the same Autosar version */
    #if ((MCU_AR_RELEASE_MAJOR_VERSION_C_NONASR != MCU_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_AR_RELEASE_MINOR_VERSION_C_NONASR != MCU_AR_RELEASE_MINOR_VERSION) || \
         (MCU_AR_RELEASE_REVISION_VERSION_C_NONASR != MCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_NonASR.c and Mcu.h are different"
    #endif
#endif
/* Check if source file and MCU header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_C_NONASR != MCU_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_C_NONASR != MCU_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_C_NONASR != MCU_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_NonASR.c and Mcu.h are different"
#endif

/* Check if source file and Mcu_NonASR header file are of the same Autosar version */
#if (MCU_VENDOR_ID_C_NONASR != MCU_LLD_VENDOR_ID)
#error "Mcu_NonASR.c and Mcu_NonASR.h have different vendor ids"
#endif
#ifdef CHECK_AUTOSAR_VERSION
    #if ((MCU_AR_RELEASE_MAJOR_VERSION_C_NONASR != MCU_AR_RELEASE_MAJOR_VERSION_NONASR) || \
         (MCU_AR_RELEASE_MINOR_VERSION_C_NONASR != MCU_AR_RELEASE_MINOR_VERSION_NONASR) || \
         (MCU_AR_RELEASE_REVISION_VERSION_C_NONASR != MCU_AR_RELEASE_REVISION_VERSION_NONASR))
    #error "AutoSar Version Numbers of Mcu_NonASR.c and Mcu_NonASR.h are different"
    #endif
#endif
/* Check if source file and Mcu_NonASR header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_C_NONASR != MCU_SW_MAJOR_VERSION_NONASR) || \
     (MCU_SW_MINOR_VERSION_C_NONASR != MCU_SW_MINOR_VERSION_NONASR) || \
     (MCU_SW_PATCH_VERSION_C_NONASR != MCU_SW_PATCH_VERSION_NONASR))
#error "Software Version Numbers of Mcu_NonASR.c and Mcu_NonASR.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DEM header file are of the same version */
    #if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS  == STD_ON)
      #if ((MCU_AR_RELEASE_MAJOR_VERSION_C_NONASR != DEM_AR_RELEASE_MAJOR_VERSION) || \
           (MCU_AR_RELEASE_MINOR_VERSION_C_NONASR != DEM_AR_RELEASE_MINOR_VERSION))
           #error "AutoSar Version Numbers of Mcu_NonASR.c and Dem.h are different"
      #endif
    #endif

    /* Check if current file and DET header file are of the same version */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
      #if ((MCU_AR_RELEASE_MAJOR_VERSION_C_NONASR != DET_AR_RELEASE_MAJOR_VERSION) || \
           (MCU_AR_RELEASE_MINOR_VERSION_C_NONASR != DET_AR_RELEASE_MINOR_VERSION))
           #error "AutoSar Version Numbers of Mcu_NonASR.c and Det.h are different"
      #endif
    #endif
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
/*
* @violates @ref Mcu_NonASR_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_NonASR_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*
* @violates @ref Mcu_NonASR_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Mcu_NonASR_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_NonASR_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/* @violates @ref Mcu_NonASR_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_NonASR_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if defined(MCU_CONFIGURE_CLK_OUT) || defined(__DOXYGEN__)

#if (MCU_CONFIGURE_CLK_OUT == STD_OFF) || defined(__DOXYGEN__)

/*================================================================================================*/
/**
* @brief    Clock Output Enable function.
* @details This function enables the clock output. 
*          The clock output setting is provided from the configuration structure.
* @pre     Function requires an execution of @p Mcu_Init() before it can be 
*          used, otherwise it reports error to @p DET.
*
* @param[in]   ConfigPtr      Pointer to MCU configuration structure.
* 
*
* @api    
*
* @implements     DMCU06056    
*
*/

/*
* @violates @ref Mcu_NonASR_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC(void, MCU_CODE) Mcu_Enable_ClockOutput (VAR (Mcu_ClockType, AUTOMATIC) ClockSetting)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
       (uint8) MCU_ENABLECLOCKOUTPUT_ID, (uint8) MCU_E_UNINIT);
    }
    else if (ClockSetting > Mcu_Cfg_Ptr->noClockSettings)
    {
        /* Error: function parameter out of range */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_ENABLECLOCKOUTPUT_ID, (uint8) MCU_E_PARAM_CLOCK);

    }
    /** @violates @ref Mcu_NonASR_C_REF_8 Boolean operations whose results are invariant shall not be permitted.*/
    else if ((ClockSetting < 1U) || (ClockSetting > 255U))
    {
        /* Error: function parameter out of range */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_ENABLECLOCKOUTPUT_ID, (uint8) MCU_E_PARAM_CLOCK);
    }
    else if (NULL_PTR == Mcu_Cfg_Ptr->Mcu_ClockConfig)
    {
        /* Error: pointer to clock setting in config structure is NULL */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) 0, (uint8) MCU_ENABLECLOCKOUTPUT_ID, \
                          (uint8) MCU_E_PARAM_CLOCK);
    }
    else
    {
#endif
    /* @violates @ref Mcu_NonASR_C_REF_4 MISRA 2004 Advisory Rules 17.4 Array indexing
           shall be the only allowed form of pointer* arithmetic*/
        Mcu_Output_Init (&Mcu_Cfg_Ptr->Mcu_ClockConfig[ClockSetting-1U]);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/*================================================================================================*/
/**
* @brief    Clock Output Disable function.
* @details This function disables the clock output. 
*
* @api    
*
* @implements     DMCU06056     
*
*/

/*
* @violates @ref Mcu_NonASR_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC(void, MCU_CODE) Mcu_Disable_ClockOutput (void)
{
    Mcu_LLD_Disable_ClkOut ();
}

#endif /* ifdef MCU_CONFIGURE_CLK_OUT */
#endif /* if (MCU_CONFIGURE_CLK_OUT == STD_ON) */

#if (MCU_GET_DEVICE_INFO_API == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief   This function extract MCU identifier information.
* @details This function retriev MCU information from MIDR1 and MIDR2 registers of SIUL IP component.
*
* @param[out] Mcu_DeviceInfoType   Mcu Information.
*
* @return         Mcu_DeviceInfoType
*
* @retval MCU_RAMSTATE_INVALID     Ram content is not valid or unknown (default).
* @retval MCU_RAMSTATE_VALID       Ram content is valid.
*
* @api
*
* @pre
*
* @implements     DMCU06050
*
*/
/*
* @violates @ref Mcu_NonASR_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) Mcu_GetDeviceInfo (P2VAR(Mcu_DeviceInfoType, AUTOMATIC, \
    MCU_APPL_DATA) deviceinfo)
{
/* @implements DMCU06029 */
#if( MCU_DEV_ERROR_DETECT == STD_ON )
    if( deviceinfo == NULL_PTR )
    {
        /* @implements DMCU06009 */
        Det_ReportError( (uint16) MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETVERSIONINFO_ID, \
                 MCU_E_PARAM_POINTER );
    }
    else
    {
#endif /* MCU_DEV_ERROR_DETECT == STD_ON */
        Mcu_LLD_GetDeviceInfo(deviceinfo);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif   /* #if MCU_GET_DEVICE_INFO_API == STD_ON */

#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) || defined(__DOXYGEN__)  
/**
 * @brief   eMios Global Prescaler Enable.
 * @details This function enable/disable the GPREN bit of the EMIOSMCR register of an
 *          addressed eMIOS instance.
 * @pre     Function requires an execution of @p Mcu_Init() before it can be
 *          used, otherwise it reports error to @p DET.
 *
 * @param[in] eMios_module   MCU_EMIOS_MODULE_0 --> Select eMios 0
 *                           MCU_EMIOS_MODULE_1 --> Select eMios 1
 *
 * @param[in] value          MCU_EMIOS_GPREN_BIT_ENABLE   --> Global Prescaler Enabled
 *                           MCU_EMIOS_GPREN_BIT_DISABLE  --> Global Prescaler Disabled (no clock)
 *
 * @return                   void
 *
 * @implements     DMCU06051
 *
 * @api
 *
 * @violates @ref Mcu_NonASR_C_REF_5 Required Rule 8.10, API could not be made static.
 */
FUNC(void, MCU_CODE) Mcu_eMios_Configure_GPREN (VAR (uint8, AUTOMATIC) eMios_module, VAR (uint8, AUTOMATIC) value)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
        (uint8) MCU_EMIOS_CONFIGURE_GPREN_ID, (uint8) MCU_E_UNINIT);
    }
    else
    {
#endif
        /* @violates @ref Mcu_NonASR_C_REF_9 MISRA 2004 Advisory Rule 11.1, cast from unsigned long to pointer */
        MCU_EMIOS_GPREN_Conf(eMios_module,value);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* #if MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON */


#if defined(MCU_DISABLE_CMU) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief    CMU Disable function.
* @details This function disables the CMU. 
*
* @param[in] cmuIndex   0  --> Select CMU0
*                       1  --> Select CMU1
*                       2  --> Select CMU2
*                       3  --> Select CMU3
*                       4  --> Select CMU4
*                       5  --> Select CMU5
*                       6  --> Select CMU6
*                       7  --> Select CMU7
*                       8  --> Select CMU8
*                       9  --> Select CMU9
*                       10 --> Select CMU10
*                       11 --> Select CMU11
*                       12 --> Select CMU12
* @api    
*
* @implements     DMCU06052
*
*/

/*
* @violates @ref Mcu_NonASR_C_REF_5 Required Rule 8.10, API could not be made static.
*/
FUNC (void, MCU_CODE) Mcu_Disable_CMU(VAR (uint8, AUTOMATIC) cmuIndex)
{
    Mcu_Disable_Monitor(cmuIndex);
}
#endif   /* MCU_DISABLE_CMU */

#if defined(MCU_SSCM_GET_STATUS_API) || defined(__DOXYGEN__)
#if (MCU_SSCM_GET_STATUS_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          SSCM module configuration.
* @details        This function returns memory status after self-test.
*
* @param[in]
* @api 
*
* @implements     DMCU06053
* 
*/
/* @violates @ref Mcu_NonASR_C_REF_10 MISRA 2004 Required Rule 8.10, functions at file scope */
FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_SscmGetStatus(VAR( void, AUTOMATIC))
{
    return Mcu_Sscm_GetStatus();
}
#endif /* MCU_SSCM_GET_STATUS_API == STD_ON */

#if (MCU_SSCM_GET_MEMCONFIG_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          SSCM module configuration.
* @details        This function returns memory configuration.
*
* @param[in]
* @api
*
* @implements     DMCU06054
*  
*/
/* @violates @ref Mcu_NonASR_C_REF_10 MISRA 2004 Required Rule 8.10, functions at file scope */
FUNC(Mcu_SSCM_ReturnType, MCU_CODE) Mcu_SscmGetMemConfig(VAR( void, AUTOMATIC))
{
    return Mcu_Sscm_GetMemConfig();
}
#endif /* MCU_SSCM_GET_MEMCONFIG_API == STD_ON */

#if (MCU_SSCM_GET_UOPS_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          SSCM module configuration.
* @details
*
* @param[in]
* @api
*
* @implements     DMCU06055
*
*/
/* @violates @ref Mcu_NonASR_C_REF_10 MISRA 2004 Required Rule 8.10, functions at file scope */
FUNC (Mcu_SSCM_ReturnType, MCU_CODE) Mcu_SscmGetUops(VAR( void, AUTOMATIC))
{
    return Mcu_Sscm_GetUops();
}
#endif /* MCU_SSCM_GET_UOPS_API == STD_ON */

#endif

#define MCU_STOP_SEC_CODE
/* @violates @ref Mcu_NonASR_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_NonASR_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
