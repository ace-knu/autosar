/**
*   @file    Mcu_MC_Monitor_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - File used by MCU to configure CMU parameters.
*   @details This file contains functions used for configuring parameters for the CMU module.
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
* @section Mcu_MC_Monitor_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory 
* section
* 
* @section Mcu_MC_Monitor_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
* 
* @section Mcu_MC_Monitor_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers 
* to other types used in macros for reading or writing data from address location of controller register.
*
* @section Mcu_MC_Monitor_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR 
* specifications although it exceeds the max length of 31 characters
*
* @section Mcu_MC_Monitor_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, API could not be made static.
*
* @section Mcu_MC_Monitor_LLD_c_REF_6
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
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Dem.h"
#endif
/* @implements     DMCU00004*/
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_MC_Monitor_lld.c
* @implements     DMCU05046, DMCU05047, DMCU05048, DMCU05049, DMCU05050, DMCU05051, DMCU05052
*/
#define MCU_MC_MONITOR_LLD_VENDOR_ID_C                      43
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MONITOR_LLD_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MONITOR_LLD_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MONITOR_LLD_AR_RELEASE_REVISION_VERSION_C    3
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MONITOR_LLD_SW_MAJOR_VERSION_C               1
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MONITOR_LLD_SW_MINOR_VERSION_C               0
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MONITOR_LLD_SW_PATCH_VERSION_C               1

/*==================================================================================================
                                        FILE VERSION CHECKS
 ==================================================================================================*/
/* Check if current file and Mcu_LLD.h file are of the same vendor */
#if (MCU_MC_MONITOR_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
    #error "Mcu_MC_Monitor_LLD.c and Mcu_LLD.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_LLD.h header file are of the same Autosar version */
#if ((MCU_MC_MONITOR_LLD_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_MONITOR_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_MONITOR_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_MC_Monitor_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h file are of the same Software version */
#if ((MCU_MC_MONITOR_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_MC_MONITOR_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_MC_MONITOR_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_MC_Monitor_LLD.c and Mcu_LLD.h are different"
#endif
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same version */
    #if ((MCU_MC_MONITOR_LLD_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_MONITOR_LLD_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_MC_Monitor_lld.c and Dem.h are different"
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

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          This function initializes the CMU module.
* @details        The function configures the low and hi frequecy reference values.
*
*
* @return         void
*
* @implements     DMCU05144
*
*/
FUNC(void, MCU_CODE) Mcu_Monitor_Init(VAR(void, AUTOMATIC))
{
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_CGM_CMU0_LFREFR_R, MCU_CMU_LREF_VALUE); /* Set
                                                           Low
                                                           Frequency
                                                           Reference
                                                         */
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_CGM_CMU0_HFREFR_R, MCU_CMU_HREF_VALUE); /* Set High Frequency Refernece */

 }

#ifdef MCU_DISABLE_CMU
/*================================================================================================*/
/**
* @brief          This function disable the CMU module.
* @details        This function is used to write a default value in the CMU control register.
*
* @return         void
*
* @implements     PR-MCAL-3319
*
*/
FUNC (void, MCU_CODE) Mcu_Disable_Monitor(VAR (uint8, AUTOMATIC) CmuIndex)
{
    switch(CmuIndex) 
    {
        case MC_CGM_CMU0:
            /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_CLEAR32(MC_CGM_CMU0_CSR_R, (uint32) MC_CGM_CMU_CME_BIT);
            break;
        default:
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            /* This case should never occurs. */
            Det_ReportError( (uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_DISABLE_CMU_ID, (uint8)MCU_E_PARAM_CMU);
#endif
            break;
    }
}
#endif   /* MCU_DISABLE_CMU */

/*================================================================================================*/
/**
* @brief          This function deinitializes the CMU module.
* @details        This function is used to write a default value in the CMU control register.
*
* @return         void
*
* @implements     DMCU05145
*
*/
FUNC(void, MCU_CODE) Mcu_Monitor_Deinit(VAR(void, AUTOMATIC))
{
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_CGM_CMU0_CSR_R, (uint32) MCU_CMU_CR_RESET_VALUE);
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_CGM_CMU0_ISR_R, (uint32) MCU_CMU_ISR_CLEAR_VALUE);
}

/*================================================================================================*/
/**
* @brief          This function enables monitoring the external oscillator.
* @details        The function configures the parameters used in monitoring the external oscillator.
*
* @param[in]      Clk_Monitor configuration parameter
*
* @return         void
*
* @implements     DMCU05146
*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_5 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_CODE) Mcu_Monitor_Osc(VAR(uint32, AUTOMATIC) Clk_Monitor)
{
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_RMW32(MC_CGM_CMU0_CSR_R, CMU0_RCDIV_MASK, (uint32)(((Clk_Monitor) & (MCU_THREE_VALUE << MCU_SHIFT_TWENTY_FOUR)) >> MCU_SHIFT_TWENTY_THREE)); /* Set RCDIV value:
                                                                                                       Fosc <=
                                                                                                       16MHz/2^RCDIV */
}

/*================================================================================================*/
/**
* @brief          This function enables monitoring the main pll.
* @details        The function configures the parameters used in monitoring the main pll.
*
* @param[in]      ClockPtr             Pointer to clock configuration structure
*
* @return         void
*
* @implements     DMCU05053
*
*/
FUNC(void, MCU_CODE) Mcu_Monitor_Pll(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
{
      
        /* To apply Control Monitor properties */
        /* Enable/Disable Clk Monitor plus RCDIV, LFREF, HFREF: HFREF<<0 + LFREF<<12+RCDIV<<24 + EN_CMU<<26 */
        if (((ClockPtr->Clk_Monitor) & (MCU_SHIFT_ONE << MCU_SHIFT_TWENTY_SIX)) == (MCU_SHIFT_ONE << MCU_SHIFT_TWENTY_SIX))   /* Check if the Monitor is enabled */
        {
            /* This is applicable for the following lines of code */
            /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_CLEAR32(MC_CGM_CMU0_CSR_R, MCU_ONE_VALUE);
            /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_RMW32(MC_CGM_CMU0_CSR_R, CMU0_RCDIV_MASK, (((ClockPtr->Clk_Monitor) & (MCU_SHIFT_THREE << MCU_SHIFT_TWENTY_FOUR)) >> MCU_SHIFT_TWENTY_THREE)); /* Set RCDIV value:
                                                                                                           Fosc <=
                                                                                                           16MHz/2^RCDIV */
            /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_CGM_CMU0_LFREFR_R, (((ClockPtr->Clk_Monitor) & (MCU_CMU_REF_MASK << MCU_SHIFT_TWELVE)) >> MCU_SHIFT_TWELVE)); /* Set
                                                                                                                       Low
                                                                                                                       Frequency
                                                                                                                       Reference
                                                                                                                     */
            /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_CGM_CMU0_HFREFR_R, ((ClockPtr->Clk_Monitor) & (MCU_CMU_REF_MASK))); /* Set High Frequency Reference */
            /* Enable the Monitor */
            /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_SET32(MC_CGM_CMU0_CSR_R, (((ClockPtr->Clk_Monitor) & (MCU_SHIFT_ONE << MCU_SHIFT_TWENTY_SIX)) >> MCU_SHIFT_TWENTY_SIX)); 
        }
        
    }

/*================================================================================================*/
/**
* @brief          This function reports the error status to DEM.
* @details        This is a function used to report the clock failure error status to DEM.
*
* @return         void
*
* @implements     DMCU05054
*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_5 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_CODE) Mcu_Report_ClkFail(void)
{
        VAR(uint16, MCU_VAR) Timeout = (uint16)0x20;
        VAR(uint16, AUTOMATIC) Loop = (uint16)0x0;
        VAR(volatile uint16, AUTOMATIC) TempReg = (uint16) MCU_ZERO_VALUE;
    /* XTAL fail event */
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    if ((uint32) MCU_ONE_VALUE == (REG_READ32(MC_CGM_CMU0_ISR_R) & ((uint32) MCU_ONE_VALUE)) )   
    {
        if (MCU_CLOCKNOTIFICATION_ENABLE == Mcu_CpyClockNotification )
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_QuartzFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_QuartzFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
        }
        /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_CGM_CMU0_ISR_R,(uint32)MCU_ONE_VALUE);           
            
       do {
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          REG_WRITE16(MC_RGM_FES_R,(uint16)MCU_OSC_LOW_FREQ_INT);
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          TempReg = REG_READ16(MC_RGM_FES_R); /* Read FES */
          Loop++;
          }
      while (((TempReg & (uint16)MCU_OSC_LOW_FREQ_INT) != (uint16)(MCU_ZERO_VALUE)) && (Loop < Timeout));

    }
    /* Fsys < LOW fail event */
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    if ((uint32) MCU_TWO_VALUE == (REG_READ32(MC_CGM_CMU0_ISR_R) & ((uint32) MCU_TWO_VALUE)) )   
    {
        if (MCU_CLOCKNOTIFICATION_ENABLE == Mcu_CpyClockNotification )
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
        }
        /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_CGM_CMU0_ISR_R,(uint32)MCU_TWO_VALUE);        
        do {
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          REG_WRITE16(MC_RGM_FES_R,(uint16)MCU_OSC_HIGH_FREQ_INT);
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          TempReg = REG_READ16(MC_RGM_FES_R); /* Read FES */
          Loop++;
          }
      while (((TempReg & (uint16)MCU_OSC_HIGH_FREQ_INT) != (uint16)(MCU_ZERO_VALUE)) && (Loop < Timeout));
    }
    /* Fsys > HIGH fail event */
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    if ((uint32) MCU_FOUR_VALUE == (REG_READ32(MC_CGM_CMU0_ISR_R) & ((uint32) MCU_FOUR_VALUE))  )   
    {
        if (MCU_CLOCKNOTIFICATION_ENABLE == Mcu_CpyClockNotification )
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
        }
        /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_CGM_CMU0_ISR_R,(uint32)MCU_FOUR_VALUE);
         do {
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          REG_WRITE16(MC_RGM_FES_R,(uint16)MCU_OSC_HIGH_FREQ_INT);
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          TempReg = REG_READ16(MC_RGM_FES_R); /* Read FES */
          Loop++;
          }
      while (((TempReg & (uint16)MCU_OSC_HIGH_FREQ_INT) != (uint16)(MCU_ZERO_VALUE)) && (Loop < Timeout));
    }
    /* PLL loss the lock */
    /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    if ((uint16) MCU_PLL_FAIL_INT == (REG_READ16(MC_RGM_FES_R) & ((uint16) MCU_PLL_FAIL_INT)) )   
    {
        if (MCU_CLOCKNOTIFICATION_ENABLE == Mcu_CpyClockNotification )
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_LockFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_LockFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
        }
        /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_CGM_PLL0_CR_R,(uint32)PLL_CR_FAIL_FLAG);        
        do {
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          REG_WRITE16(MC_RGM_FES_R,(uint16)MCU_PLL_FAIL_INT);
          /* @violates @ref Mcu_MC_Monitor_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
          TempReg = REG_READ16(MC_RGM_FES_R); /* Read FES */
          Loop++;
          }
      while (((TempReg & (uint16)MCU_PLL_FAIL_INT) != (uint16)(MCU_ZERO_VALUE)) && (Loop < Timeout));
        
    }
 }

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements  
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Monitor_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
