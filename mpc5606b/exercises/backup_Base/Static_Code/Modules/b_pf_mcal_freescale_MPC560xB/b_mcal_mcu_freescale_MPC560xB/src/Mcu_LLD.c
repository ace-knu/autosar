/**
*   @file    Mcu_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Low level part of MCU driver.
*   @details This file contains the low level part of the functions defined by AutoSAR.
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
* @section MCU_LLD_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section MCU_LLD_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section MCU_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel parameters,
* the indexing of the pointer is taken care and hence the unintended memory location will not
* be accessed
*
* @section MCU_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR
* specifications although it exceeds the max length of 31 characters
*
* @section MCU_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section MCU_LLD_C_REF_6
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is to be used by LLD layer.
*
* @section MCU_LLD_C_REF_7
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability
*
* @section MCU_LLD_C_REF_8
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a 
* function and any type other than an integral type. Appears when accessing memory-mapped registers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_LLD.h"
#include "SchM_Mcu.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* @implements     DMCU00004 */
#include "Det.h"
#endif

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* @implements     DMCU00003, DMCU06057 */
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_LLD.c
* @implements     DMCU04044, DMCU04045, DMCU04046, DMCU04047, DMCU04048, DMCU04049, DMCU04050
*/
#define MCU_LLD_VENDOR_ID_C                    43
/**
* @violates @ref MCU_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters
*/
#define MCU_LLD_AR_RELEASE_MAJOR_VERSION_C     4
/**
* @violates @ref MCU_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters
*/
#define MCU_LLD_AR_RELEASE_MINOR_VERSION_C     0
/**
* @violates @ref MCU_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters
*/
#define MCU_LLD_AR_RELEASE_REVISION_VERSION_C  3
#define MCU_LLD_SW_MAJOR_VERSION_C             1
#define MCU_LLD_SW_MINOR_VERSION_C             0
#define MCU_LLD_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_LLD header file are of the same vendor */
#if (MCU_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
#error "Mcu_LLD.c and Mcu_LLD.h have different vendor ids"
#endif

/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_LLD header file are of the same Autosar version */
#if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION_C   != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
    (MCU_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
    (MCU_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD header file are of the same Software version */
#if ((MCU_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_LLD.c and Mcu_LLD.h are different"
#endif
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same version */
    #if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_LLD_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu_LLD.c and Dem.h are different"
    #endif
#endif
#endif
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
       #if ((MCU_LLD_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
            (MCU_LLD_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
       #error "AutoSar Version Numbers of Mcu_LLD.c and Det.h are different"
       #endif
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
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_NO_INIT_32
/* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "MemMap.h"
/**
* @brief Mcu Timeout
*/
STATIC VAR (uint32, MCU_VAR) Mcu_TimeOut;
#define MCU_STOP_SEC_VAR_NO_INIT_32
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"
/* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

STATIC P2CONST (Mcu_ClockConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_pClockConfig = NULL_PTR;
/* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
/* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters */
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                            before '#include' MemMap.h
*/
#include "MemMap.h"
    /** @brief Mcu clock notification */
    VAR (Mcu_ClockNotificationType, MCU_VAR) Mcu_CpyClockNotification;
/* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters */
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

/* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                            before '#include' MemMap.h
*/
#include "MemMap.h"
    /** @brief Mcu system clock frequency */
    VAR (uint32, MCU_VAR) Mcu_CpySystemClockFrequency = MCU_ZERO_VALUE;
/* @violates @ref MCU_LLD_C_REF_5 ISRA 2004 Required Rule 5.1. Identifier exceeds 31 characters */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

STATIC FUNC (void, MCU_CODE) Mcu_SetModeClockConfig (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
            VAR (Mcu_ClockNotificationType, AUTOMATIC) ClockNotification,
            P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr);

STATIC FUNC (void, MCU_CODE) Mcu_LLD_DistributeSetModePllClk (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
        P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          MCU module initialization.
* @details        The function initializes the CGM, ME, RGM, PCU modules, 
*                 specific parameters of the DMAMUX and DMA modules and global 
*                 parameters from FLASH module.
*
* @param[in]      ConfigLLDPtr Pointer to LLD configuration structure
*
* @implements     DMCU04051
*/
FUNC (void, MCU_CODE) Mcu_LLD_Init (P2CONST (McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr)
{
#if (MCU_SKIP_FUNCTION == STD_ON)
    VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType) E_OK;
#endif
#if (MCU_SSCM_ERROR_CONFIG == STD_ON)
    VAR(uint16, AUTOMATIC) Mcu_Sscm_Config = SSCM_ERROR_RAE_DISABLE|SSCM_ERROR_PAE_DISABLE;
#endif
    Mcu_pClockConfig = NULL_PTR;

    /* Store TimeOut Variables */
    Mcu_TimeOut = ConfigLLDPtr->TimeOut;

    Mcu_Modes_Init (ConfigLLDPtr);

    Mcu_Configurations_Init (ConfigLLDPtr);
/** @violates @ref MCU_LLD_C_REF_7 All macro identifiers in preprocessor directives shall*/
#if (POWER_DOMAIN == STD_ON)
    Mcu_Power_Init (ConfigLLDPtr);
#endif

#if (MCU_SKIP_FUNCTION == STD_ON)
    Status = Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
    if ((Std_ReturnType) E_NOT_OK == Status)
    {
        /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
        return;
    }
#else
    Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
#endif
    
    Mcu_Reset_Init (ConfigLLDPtr);
#if ((HAS_DMA == STD_ON) && (MCU_DMA_INIT == STD_ON))
    /* @implements DMCU06044 */
    Dma_Init (&ConfigLLDPtr->DmaConfig);
    /* @implements DMCU06045 */
    Dmamux_Init (&ConfigLLDPtr->DmamuxConfig);
#endif

#if (MCU_GET_RAM_STATE_API == STD_ON)
    Ecsm_GetRamInit();
#endif

    /*enter critical region*/
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00();

    /* @implements DMCU06046 */
    Mcu_Flash_Init (ConfigLLDPtr);

    /*exit critical region*/
    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00();
    
#if (MCU_SSCM_ERROR_CONFIG == STD_ON)
#if (MCU_SSCM_ERROR_PAE_ENABLE == STD_ON)
    Mcu_Sscm_Config|=SSCM_ERROR_PAE_ENABLE;
#endif
#if (MCU_SSCM_ERROR_RAE_ENABLE == STD_ON)
    Mcu_Sscm_Config|=SSCM_ERROR_RAE_ENABLE;
#endif
    Mcu_Sscm_Init(Mcu_Sscm_Config);
#endif

    /* Init Internal variables */
    Mcu_CpyClockNotification = MCU_CLOCKNOTIFICATION_DISABLE;

    Mcu_CpySystemClockFrequency = MCU_ZERO_VALUE;
}

/*================================================================================================*/
/**
* @brief          This function initializes the clock structure.
* @details        This function intializes the clock structure by configuring the CGM and ME modules.
*
* @param[in]      ClockPtr Pointer to clock configuration structure
* @param[in]      ClockNotification Indicates if monitoring the oscillator is enabled
* 
* @return         Std_ReturnType
* @retval         E_OK/E_NOT_OK
*
* @implements     DMCU04052
*/
#if (MCU_INIT_CLOCK == TRUE)
FUNC (Std_ReturnType, MCU_CODE) Mcu_LLD_InitClock (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
        VAR (Mcu_ClockNotificationType, AUTOMATIC) ClockNotification)
{
    VAR (uint32, AUTOMATIC) CpyStartRunMode = MCU_ZERO_VALUE;
    VAR (uint32, AUTOMATIC) CurrentReg = MCU_ZERO_VALUE;
    VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    VAR (volatile uint8, AUTOMATIC) PerClock = MCU_ZERO_BYTE_VALUE;
    VAR (volatile uint32, AUTOMATIC) PerSelClock = MCU_ZERO_VALUE;
    CpyStartRunMode = ClockPtr->Start_Run_Mode;
    Mcu_pClockConfig = ClockPtr;

    /*  
     * 1) reconfigure all CMU registers with default value (disabled)
     * 2) cut off peripherals including CMUs 
     * 3) Cut PLL off
     */
    Mcu_Monitor_Deinit();
    Mcu_Monitor_Init();
#if (MCU_INIT_CLOCK_DISABLE_PERIPHERAL == TRUE)
    Mcu_Disable_Peripheral();
#endif
    Mcu_PLL_0FF();    

    /* 
     * Apply configuration :
     * All Peripherals frozen
     * PLL OFF
     */
    #if (MCU_SKIP_FUNCTION == STD_ON)
        Status = Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
        if ((Std_ReturnType) E_NOT_OK == Status)
        {
            /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
            return (Std_ReturnType) E_NOT_OK;
        }
    #else
    Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
    #endif

    /* 
     * Reconfigure ME registers with new clock source parameters
     * RC ON/OFF, XOSC ON/OFF, PLL ON/
     * Start oscillators if requested (XTAL_A, XTAL B, 128k)
     */
    CurrentReg = Mcu_Init_Osc (ClockPtr,NULL_PTR);

    /* Store ClockNotification */
    Mcu_CpyClockNotification = ClockNotification;

    if ( MCU_PLL_STATUS_FLAG == ( (ClockPtr->Start_Run_Mode) & (MCU_PLL_STATUS_FLAG) ) ) 
    { 
        /* 
         * Reconfigure PLL registers with new parameters
         */
        Mcu_Init_Pll0 (CurrentReg, ClockPtr);
    }

    /* 
     * Apply new clock source configuration
     * Activate XOSC, PLL if requested
     * Clock CMU - CMU clock tree is not impacted by later configurations
     */
    #if (MCU_SKIP_FUNCTION == STD_ON)
        Status = Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode); 
        if ((Std_ReturnType) E_NOT_OK == Status)
        {
         /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
            return (Std_ReturnType) E_NOT_OK;
        }
#else
        Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode); 
#endif
 
    /* 
     * If the system clock is PLL :
     * Let Clock application to Distribute PLL clock API
     * Exit from this function with SysClk mapped on 16MHz RC oscillators.
     */
    if ( ( (CpyStartRunMode) & MCU_SYSTEM_CLK_MASK) != MCU_PLL_CLOCK)
    {
        /* 
         * Needed for CMU reconfiguration
         */
        Mcu_Force_CMU_Clock();
        /* 
         * Change clock source for sysclk 
         * Change running mode (no effect as peripherals are all OFF)
         * Reconfigure Flash with new clock settings
         * Reconfigure ECSM with new clock settings
         * SysClk is now on new clock setting : output clock, CMU and dividers can be configured.
         * CMU clock is forced.
         */
#if (MCU_SKIP_FUNCTION == STD_ON)
            Status = Mcu_Change_Mode (Mcu_TimeOut, ClockPtr);
            if ((Std_ReturnType) E_NOT_OK == Status)
            {
                /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
                return (Std_ReturnType) E_NOT_OK;
            }
#else
        Mcu_Change_Mode (Mcu_TimeOut, ClockPtr);
#endif
        /* 
         * Check new mode is applied
         * Check new sysclk source is applied
         */
#if (MCU_SKIP_FUNCTION == STD_ON)
            Status = Mcu_Check_Init (Mcu_TimeOut, ClockPtr);
            if ((Std_ReturnType) E_NOT_OK == Status)
            {
                /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
                return (Std_ReturnType) E_NOT_OK;
            }
#else
            Mcu_Check_Init (Mcu_TimeOut, ClockPtr);
#endif
    }
    if ((MCU_XTAL_CLOCK == ((CpyStartRunMode) & MCU_SYSTEM_CLK_MASK) ) || (MCU_XTAL_DIV_CLOCK == ((CpyStartRunMode) & MCU_SYSTEM_CLK_MASK)))
    {
        /* Configure CMU for XTAL monitoring */
        Mcu_Monitor_Osc(ClockPtr->Clk_Monitor);
    }

#if (MCU_CONFIGURE_CLK_OUT == STD_ON)
    /* Configure clkout dedicated clock tree */
        Mcu_Output_Init (ClockPtr);
    #endif

    /* 
     * Configure peripheral dividers
     */
    Mcu_Peripheral_Sets_Init (ClockPtr);

    if (MCU_PC3_ENABLED == ((ClockPtr->Periph_Clk) & MCU_PC3_ENABLED) )   /* Check if the clock for per3 is enabled */
    {
        /* 
         * Clock tree to eMIOS is now set up
         * Configure eMIOS with new clock settings 
         */
        Mcu_Force_eMIOS_Clock();
    
#if (MCU_SKIP_FUNCTION == STD_ON)
        Status = Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK); 
        if ((Std_ReturnType) E_NOT_OK == Status)
        {
            /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
            return (Std_ReturnType) E_NOT_OK;
        }
#else
        Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK); 
#endif

        Mcu_EMIOS_Init(&ClockPtr->eMIOS_Config);
    }

    /* 
     * Wait for stabilization of auxiliary oscillators 
     * 32k XTAL B osc
     * 128k osc
     */
    Status = Mcu_Check_Stability (Mcu_TimeOut, ClockPtr);

    if (Status != (Std_ReturnType) E_OK)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        /* the timeout was probably too small */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_INITCLOCK_ID, (uint8) Status);
#endif

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
        /* if the timeout was configured right but the clock is still unstable, there is probably a hardware error*/
           if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.state)
           {
              Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.id, DEM_EVENT_STATUS_FAILED);
           }    
        #endif

        Status = (Std_ReturnType) E_NOT_OK;
    }

   /* 
    * Release forced clock for eMIOS and CMU
    * Re-initialize all peripheral clocks with the user settings
    */
    Mcu_Modes_Init (Mcu_Cfg_Ptr->McuLLD_Config);
    Mcu_Configurations_Init (Mcu_Cfg_Ptr->McuLLD_Config);
    
#if (MCU_SKIP_FUNCTION == STD_ON)
    Status = Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode); 
    if ((Std_ReturnType) E_NOT_OK == Status)
    {
        /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
        return (Std_ReturnType) E_NOT_OK;
    }
#else
    Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode); 
#endif

    return Status;
}
#endif

/*================================================================================================*/
/**
* @brief          This function activates the main PLL as the system clock source.
* @details        This function sets the PLL as the system clock and also enables monitoring.
*
* @param[in]      ClockPtr Pointer to clock configuration structure
*
* @implements     DMCU04053
 */
#if (MCU_NO_PLL == FALSE)
FUNC (void, MCU_CODE) Mcu_LLD_DistributePllClock (void)
    {
    #if (MCU_SKIP_FUNCTION == STD_ON)
    VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    #endif

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_pClockConfig)
    {
        /* Error: Mcu_InitClock() was not executed */
        /* @implements DMCU06021 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_DISTRIBUTEPLLCLOCK_ID, (uint8) MCU_E_CLOCK_UNINIT);
    }
    /* @implements DMCU06038 */
    else if ( MCU_PLL_UNLOCKED == Mcu_FMPLL_GetPllStatus()) 
    {
        /* @implements DMCU06037 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_DISTRIBUTEPLLCLOCK_ID, (uint8) MCU_E_PLL_NOT_LOCKED);
    }
    else
    {
#endif
        VAR (uint32, AUTOMATIC) CpyStartRunMode;

        CpyStartRunMode = Mcu_pClockConfig->Start_Run_Mode;

        
        if ( MCU_PLL_CLOCK == ( (CpyStartRunMode) & MCU_SYSTEM_CLK_MASK))
        {
            Mcu_Configure_FMPLL_ClkFail(Mcu_pClockConfig);
            /* @implements DMCU06036 */
            #if (MCU_SKIP_FUNCTION == STD_ON)
            Status = Mcu_Change_Mode (Mcu_TimeOut, Mcu_pClockConfig);
            if ((Std_ReturnType) E_NOT_OK == Status)
            {
                /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
                return;
            }
            #else
            Mcu_Change_Mode (Mcu_TimeOut, Mcu_pClockConfig);
            #endif

            #if (MCU_SKIP_FUNCTION == STD_ON)
            Status = Mcu_Check_Init (Mcu_TimeOut, Mcu_pClockConfig);
            if ((Std_ReturnType) E_NOT_OK == Status)
            {
                /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
                return;
            }
           #else
            Mcu_Check_Init (Mcu_TimeOut, Mcu_pClockConfig);
           #endif

            Mcu_Monitor_Pll (Mcu_pClockConfig);
        }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    }
#endif

/*================================================================================================*/
/**
* @brief          This function returns the status of the PLL.
* @details        This function uses low level driver functionality to provide the pll status.
*
* @return         Status  describes the status of the PLL
* @retval         MCU_PLL_LOCKED/MCU_PLL_UNLOCKED
*
* @implements     DMCU04054
*
*/
/* @violates @ref MCU_LLD_C_REF_6 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_LLD_GetPllStatus(void)
{
    /* @implements DMCU06039 */
    Mcu_PllStatusType status = MCU_PLL_STATUS_UNDEFINED;    

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_pClockConfig)
    {
        /* Error: Mcu_InitClock() was not executed */
        /* @implements DMCU06061 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_GETPLLSTATUS_ID, (uint8) MCU_E_CLOCK_UNINIT);
    }
    else
    {
#endif
          status = Mcu_FMPLL_GetPllStatus();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return status;
}

/*================================================================================================*/
/**
* @brief          The function is used to enter into a low power mode.
* @details        The function performs clock specific initializations and then 
*                 a low power mode is entered.
*
* @param[in]      ClockPtr Pointer to clock configuration structure
* @param[in]      ClockNotification Indicates if monitoring the oscillator is enabled
* @param[in]      ModePtr Pointer to mode configuration structure
*
* @implements     DMCU04078
*/
STATIC FUNC (void, MCU_CODE) Mcu_SetModeClockConfig (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
            VAR (Mcu_ClockNotificationType, AUTOMATIC) ClockNotification,
            P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr)
{
    VAR (uint32, AUTOMATIC) CurrentReg = MCU_ZERO_VALUE;
    VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType) E_OK;

    CurrentReg = Mcu_Init_Osc (ClockPtr, ModePtr);

    #if (MCU_SKIP_FUNCTION == STD_ON)
        Status = Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
        if ((Std_ReturnType) E_NOT_OK == Status)
        {
            /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
            return;
        }
    #else
        Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
    #endif


    /* Store ClockNotification */
    Mcu_CpyClockNotification = ClockNotification;
    Mcu_Monitor_Deinit();


    if ( MCU_PLL_STATUS_FLAG == ( (ClockPtr->Start_Run_Mode) & (MCU_PLL_STATUS_FLAG) ) ) { /* The circuits can be characterize only if for the new modality, the system clock used is PLL.
                             */
        
            Mcu_Monitor_Init();
        
        Mcu_Init_Pll0 (CurrentReg, ClockPtr);
    }


#if (MCU_CONFIGURE_CLK_OUT == STD_ON)
        Mcu_Output_Init (ClockPtr);
    #endif


    Mcu_Peripheral_Sets_Init (ClockPtr);

    Status = Mcu_Check_Stability (Mcu_TimeOut, ClockPtr);

    if (Status != (Std_ReturnType) E_OK)
    {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        /* the timeout was probably too small */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) Status);
#endif

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
        /* if the timeout was configured right but the clock is still unstable, there is probably a hardware error*/
           if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.state)
           {
              Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_ClockFailureCfg.id, DEM_EVENT_STATUS_FAILED);
           }    
        #endif
    }

    #if (MCU_SKIP_FUNCTION == STD_ON)
        Status = Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
        if ((Std_ReturnType) E_NOT_OK == Status)
        {
            /* @violates @ref MCU_LLD_C_REF_7 Required Rule 14.7 Return statement before end of function. */
            return;
        }
    #else
        Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
    #endif

#ifdef MCU_EMIOS_INIT
    Mcu_EMIOS_Init(ClockPtr);
#endif

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    Mcu_Apply_LowPower_Mode (Mcu_TimeOut, ModePtr);
#else
    Mcu_Apply_LowPower_Mode (ModePtr);
#endif
}

/*================================================================================================*/
/**
* @brief          The function sets the PLL as the system clock when the uC is in a low power mode.
* @details        The function sets the PLL as the system clock and also enables 
*                 monitoring when the system is in a low power mode.
*
* @param[in]      ClockPtr Pointer to clock configuration structure
* @param[in]      ClockNotification Indicates if monitoring the oscillator is enabled
* @param[in]      ModePtr Pointer to mode configuration structure
*
* @implements     DMCU04079
*/
STATIC FUNC (void, MCU_CODE) Mcu_LLD_DistributeSetModePllClk (P2CONST (Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
        P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr)
{
    Mcu_Change_LowPower_Mode (ClockPtr, ModePtr);

    if ( MCU_PLL_CLOCK == ( (ClockPtr->Start_Run_Mode) & MCU_SYSTEM_CLK_MASK))
    {
        Mcu_Monitor_Pll (ClockPtr);
    }
}

/*================================================================================================*/
/**
* @brief          This function applies the low power mode requested.
* @details        This function calls ip low level diver function with the requested mode.
*
* @param[in]      McuMode describes the low power mode configuration.
*
* @implements     DMCU04080
*/
FUNC(void, AUTOMATIC) Mcu_LLD_Apply_Mode(VAR (Mcu_ModeType, AUTOMATIC) McuMode)
{
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr;

    /* @violates @ref MCU_LLD_C_REF_3 MISRA 2004 Required Rules 17.4 Array indexing  
        shall be the only allowed form of pointer* arithmetic */
    ModePtr = &(Mcu_Cfg_Ptr->Mcu_ModeConfig[McuMode]);


#ifdef ERR_IPV_MC_0048
   {
        /* check following preconditions of errata: stop mode required with system clock disabled, and internal clock enabled */
        if ( (ModePtr->Mode == MCU_STOP_MODE) && ((ModePtr->LP_Param & MCU_SYSTEM_CLK_MASK) == MCU_SYSCLK_SWITCH_DISABLED) && ((ModePtr->LP_Param & MCU_RC_GENERAL_FLAG) == MCU_RC_GENERAL_FLAG) )
        {
            /* prevent any safe mode entrance from RGM */ 
            /* configure all hardware-triggered SAFE mode requests that need to cause an immediate transition from STOP0 to SAFE mode to be interrupt requests. 
              This is done in the MC_RGM’s ‘Functional' Event Alternate Request register (RGM_FEAR).*/
           /* @violates @ref MCU_LLD_C_REF_8 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE16(MC_RGM_FEAR_R, MCU_16_BIT_MASK);
         }
    }
#endif

    if (ModePtr->Fast_Transition)
    {
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
        Mcu_Apply_LowPower_Mode (Mcu_TimeOut, ModePtr);
#else
        Mcu_Apply_LowPower_Mode (ModePtr);
#endif
    }
    else
    {
        VAR (Mcu_ClockType, AUTOMATIC) ClockSetting;

        ClockSetting = ModePtr->ClockConfig;

        /* @violates @ref MCU_LLD_C_REF_3 MISRA 2004 Required Rules 17.4 Array indexing  
        shall be the only allowed form of pointer* arithmetic */
        Mcu_pClockConfig = &Mcu_Cfg_Ptr->Mcu_ClockConfig[ClockSetting-(uint8)1];

        Mcu_LLD_DistributeSetModePllClk (Mcu_pClockConfig,ModePtr);

        Mcu_SetModeClockConfig (Mcu_pClockConfig, Mcu_Cfg_Ptr->clkNotification, ModePtr);
    }
}

/*================================================================================================*/
/**
* @brief          This function returns the reset reason.
* @details        The function returns the status of the last asserted reset source.
*                 If a reset event has occured the status of the corresponding 
*                 reset source is asserted.
*
* @return         The reset reason
*
* @see            Mcu_ResetType
*
* @implements     DMCU04055
*
*/
FUNC(Mcu_ResetType, MCU_CODE) Mcu_LLD_GetResetReason (VAR (void, AUTOMATIC))
{
       return Mcu_RGM_GetResetReason(Mcu_TimeOut);
}

/*================================================================================================*/
/**
* @brief          This function returns the raw reset reason.
* @details        The function returns the status of the reset sources.
*                 If a reset event has occured the status of the corresponding 
*                 reset source is asserted.
*
* @return         The raw reset reason.
*
* @implements     DMCU04056
*/
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_LLD_GetResetRawValue (VAR (void, AUTOMATIC))
{
        return Mcu_RGM_GetResetRawValue(Mcu_TimeOut);
}

/*================================================================================================*/
/**
* @brief          This function performs a microcontroller functional or destructive 
*                 reset by using the hardware feature of the microcontroller.
*
* @pre            The MCU module's environment shall only call the function after 
*                 the MCU has been initialized by the function Mcu_Init. 
*
* @implements     DMCU04057
*/
#if MCU_PERFORM_RESET_API == STD_ON
FUNC(void, MCU_CODE) Mcu_LLD_PerformReset(VAR (void, AUTOMATIC))
{
      Mcu_RGM_PerformReset();
}
#endif


/*================================================================================================*/
/**
* @brief          This function check the Microcontroller RAM.
* @details        This function provides the actual status of the microcontroller Ram after the Reset.
*
* @return         Mcu_RamStateType
* @retval MCU_RAMSTATE_INVALID     Ram content is not valid or unknown (default).
* @retval MCU_RAMSTATE_VALID       Ram content is valid.
*
* @implements     DMCU04058
*/
#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_LLD_GetRamState (void)
{
    return (Mcu_RamStateType)Ecsm_GetRamState();

}
#endif

#define MCU_STOP_SEC_CODE
/*
* @violates @ref MCU_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
