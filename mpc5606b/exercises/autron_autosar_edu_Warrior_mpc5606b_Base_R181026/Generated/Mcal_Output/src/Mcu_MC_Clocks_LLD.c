/**
*   @file    Mcu_MC_Clocks_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - File used by MCU to configure CGM parameters.
*   @details This file contains functions used for configuring parameters for the CGM modules.
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
* @section Mcu_MC_Clocks_lld_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_MC_Clocks_lld_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_MC_Clocks_lld_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers
* to other types used in macros for reading or writing data from address location of controller register.
*
* @section Mcu_MC_Clocks_lld_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, API could not be made static.
*
* @section Mcu_MC_Clocks_lld_c_REF_5
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_MC_Clocks_lld_c_REF_6
* Violates MISRA 2004 Required Rule 14.10,All if ... else if constructs shall be terminated with an else clause.
* Nothing to do in else.
*
* @section Mcu_MC_Clocks_lld_c_REF_7
* Violates MISRA 2004 Required Rule 14.7, This violation is required to avoid multiple return from function.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_LLD.h"
#include "SchM_Mcu.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Mcu_MC_Clocks_LLD.c
* @implements     DMCU05001, DMCU05002, DMCU05003, DMCU05004, DMCU05005, DMCU05006, DMCU05007
*/
#define MCU_MC_CLOCKS_LLD_VENDOR_ID_C                      43
/*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_CLOCKS_LLD_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_CLOCKS_LLD_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_CLOCKS_LLD_AR_RELEASE_REVISION_VERSION_C    3
/*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_CLOCKS_LLD_SW_MAJOR_VERSION_C               1
/*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_CLOCKS_LLD_SW_MINOR_VERSION_C               0
/*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_CLOCKS_LLD_SW_PATCH_VERSION_C               1

/*==================================================================================================
                                        FILE VERSION CHECKS
 ==================================================================================================*/

/* Check if current file and Mcu_LLD.h file are of the same vendor */
#if (MCU_MC_CLOCKS_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
    #error "Mcu_MC_Clocks_LLD.c and Mcu_LLD.h have different vendor ids"
#endif
/* Check if current file and Mcu_LLD.h file are of the same Autosar version */
/*
* @implements     DMCU06001
*/
#if ((MCU_MC_CLOCKS_LLD_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CLOCKS_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CLOCKS_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_MC_Clocks_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h file are of the same Software version */
#if ((MCU_MC_CLOCKS_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_MC_CLOCKS_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_MC_CLOCKS_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_MC_Clocks_LLD.c and Mcu_LLD.h are different"
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
* @violates @ref Mcu_MC_Clocks_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*================================================================================================*/
/**
* @brief          This function initializes the configurations during run and non-run modes for
*                 each peripheral.
* @details        This function selects one non-run mode configuration and one run mode
*                 configuration for each peripheral.
*
* @param[in]      number      Describes a parameter that is input to the function or macro.
*
* @param[out]     None
*
* @param[in,out]  None
*
* @return         void
*
* @implements     DMCU05008
*
*/
FUNC(void, MCU_CODE) Mcu_Configurations_Init(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr)
{
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL4_R, (uint8) (ConfigLLDPtr->SetDspi0));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL5_R, (uint8) (ConfigLLDPtr->SetDspi1));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL6_R, (uint8) (ConfigLLDPtr->SetDspi2));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL7_R, (uint8) (ConfigLLDPtr->SetDspi3));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL8_R, (uint8) (ConfigLLDPtr->SetDspi4));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL9_R, (uint8) (ConfigLLDPtr->SetDspi5));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL12_R, (uint8) (ConfigLLDPtr->SetLinFlex8));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL13_R, (uint8) (ConfigLLDPtr->SetLinFlex9));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL16_R, (uint8) (ConfigLLDPtr->SetFlexCan0));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL17_R, (uint8) (ConfigLLDPtr->SetFlexCan1));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL18_R, (uint8) (ConfigLLDPtr->SetFlexCan2));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL19_R, (uint8) (ConfigLLDPtr->SetFlexCan3));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL20_R, (uint8) (ConfigLLDPtr->SetFlexCan4));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL21_R, (uint8) (ConfigLLDPtr->SetFlexCan5));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL23_R, (uint8) (ConfigLLDPtr->SetDmaChMux));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL32_R, (uint8) (ConfigLLDPtr->SetAdc0));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL33_R, (uint8) (ConfigLLDPtr->SetAdc1));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL44_R, (uint8) (ConfigLLDPtr->SetI2C0));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL48_R, (uint8) (ConfigLLDPtr->SetLinFlex0));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL49_R, (uint8) (ConfigLLDPtr->SetLinFlex1));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL50_R, (uint8) (ConfigLLDPtr->SetLinFlex2));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL51_R, (uint8) (ConfigLLDPtr->SetLinFlex3));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL52_R, (uint8) (ConfigLLDPtr->SetLinFlex4));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL53_R, (uint8) (ConfigLLDPtr->SetLinFlex5));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL54_R, (uint8) (ConfigLLDPtr->SetLinFlex6));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL55_R, (uint8) (ConfigLLDPtr->SetLinFlex7));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL57_R, (uint8) (ConfigLLDPtr->SetCtu));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL60_R, (uint8) (ConfigLLDPtr->SetCanSc));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL68_R, (uint8) (ConfigLLDPtr->SetSiuL));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL69_R, (uint8) (ConfigLLDPtr->SetWkpu));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL72_R, (uint8) (ConfigLLDPtr->SetEmios0));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL73_R, (uint8) (ConfigLLDPtr->SetEmios1));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL91_R, (uint8) (ConfigLLDPtr->SetRtcApi));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL92_R, (uint8) (ConfigLLDPtr->SetPit));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL104_R, (uint8) (ConfigLLDPtr->SetCmu0));

}

/*================================================================================================*/
/**
* @brief          This function initializes the oscillators.
* @details        The function initializes the internal 16 MHz RC oscillator, the external 8 MHz
*                 oscillator, the 128kHz internal RC and the 32 kHz oscillator.
*
* @param[in]      ClockPtr Pointer to clock configuration structure*
* @param[in]      ModePtr Pointer to mode configuration structure
* @param[out]     CurrentReg used to store the current run mode
*
*
* @return         CurrentReg
*
*
* @implements     DMCU05009
*
*/
FUNC(uint32, MCU_CODE) Mcu_Init_Osc(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr,
                                  P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr)
{
    VAR(uint32, AUTOMATIC) CpyStartRunMode = MCU_ZERO_VALUE;
    VAR(volatile uint8, AUTOMATIC) PerClock = MCU_ZERO_BYTE_VALUE;
    VAR(volatile uint32, AUTOMATIC) PerSelClock = MCU_ZERO_VALUE;
    VAR(uint32, AUTOMATIC) CurrentReg = MCU_ZERO_VALUE;
    VAR(uint32, AUTOMATIC) TempReg = MCU_ZERO_VALUE;
    
    CpyStartRunMode = ClockPtr->Start_Run_Mode;

    /* Save system clock frequency */
    if (MCU_ZERO_VALUE == Mcu_CpySystemClockFrequency )
    {
        Mcu_CpySystemClockFrequency = ClockPtr->McuSystemClockFrequency;
    }

    if (ModePtr != NULL_PTR)
    {
        /* The following code ensure that the control of Pll, Xtal and IRC is done for each input state */
        switch (ModePtr->Mode)
        {
        case (MCU_HALT_MODE) : /* HALT */            
            /* Set sysclk first to avoid any invalid config interrupt */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            TempReg = (((~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_HALT_MC_R)) | (CpyStartRunMode & MCU_SYSTEM_CLK_MASK));
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_HALT_MC_R, TempReg);
            
            /* Set clock sources configured for LP mode */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            TempReg = ((uint32) REG_READ32(MC_ME_HALT_MC_R) & ~(MCU_PLL1_STATUS_FLAG | MCU_PLL_STATUS_FLAG | MCU_XOSC_GENERAL_FLAG | MCU_RC_GENERAL_FLAG))
                                                    | ( CpyStartRunMode & (MCU_PLL1_STATUS_FLAG | MCU_PLL_STATUS_FLAG | MCU_XOSC_GENERAL_FLAG | MCU_RC_GENERAL_FLAG));
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_HALT_MC_R, TempReg);
            
            CurrentReg = MC_ME_HALT_MC_R;
        break;
            
        case (MCU_STOP_MODE) : /* STOP */
            /* Set sysclk first to avoid any invalid config interrupt */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            TempReg = ((~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_STOP_MC_R)) | (CpyStartRunMode & MCU_SYSTEM_CLK_MASK);
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_STOP_MC_R, TempReg);

            /* Set clock sources configured for LP mode */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            TempReg = ((uint32) REG_READ32(MC_ME_STOP_MC_R) & ~(MCU_PLL1_STATUS_FLAG | MCU_PLL_STATUS_FLAG | MCU_XOSC_GENERAL_FLAG | MCU_RC_GENERAL_FLAG))
                                                    | ( CpyStartRunMode & (MCU_PLL1_STATUS_FLAG | MCU_PLL_STATUS_FLAG | MCU_XOSC_GENERAL_FLAG | MCU_RC_GENERAL_FLAG));
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_STOP_MC_R, TempReg);
            CurrentReg = MC_ME_STOP_MC_R;
        break;
            
        case (MCU_STANDBY_MODE) : /* STANDBY */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_STBY_MC_R, (uint32) ((uint32) (MCU_SYSTEM_CLK_MASK) | (uint32) REG_READ32(MC_ME_STBY_MC_R)));
            if (MCU_RC_GENERAL_FLAG == ((CpyStartRunMode) & (MCU_RC_GENERAL_FLAG)) )   /* Put RC==ON */
            {
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_BIT_SET32(MC_ME_STBY_MC_R, (MCU_RC_GENERAL_FLAG));
            }
            else
            {
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_BIT_CLEAR32(MC_ME_STBY_MC_R, (MCU_RC_GENERAL_FLAG));
            }
            CurrentReg = MC_ME_STBY_MC_R;
            break;
        default:
        {
            /* This case should never occurs. */
            Cer_ReportError( (uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INITOSC_ID, (uint8)MCU_E_WRONG_MODE);
            /* Compiler_Warning: Statement break is unreachable because of the infinite while loop found in
               the Cer_ReportError function. The CER is meant to handle those unexpected runtime situations
               that the existing DEM and DET subsystems cannot cope with.
            */
            break;
        }
        }
    }
    else
    {
        /* The following code ensure that the control of Pll, Xtal and IRC is done for each input state */
        switch (CpyStartRunMode & MCU_SYSTEM_MODE_MASK)
        {
        case (MCU_DRUN_MODE_VALUE) : /* DRUN */
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_DRUN_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_DRUN_MC_R)));
                if (MCU_XOSC_GENERAL_FLAG == ((CpyStartRunMode) & (MCU_XOSC_GENERAL_FLAG)))   /* Put XOSC==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_DRUN_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_DRUN_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                if (MCU_PLL_STATUS_FLAG == ((CpyStartRunMode) & (MCU_PLL_STATUS_FLAG)) )   /* Put PLL0ON==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_DRUN_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_DRUN_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                CurrentReg = MC_ME_DRUN_MC_R;
            break;
        case (MCU_RUN0_MODE_VALUE) : /* RUN0 */
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_RUN0_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN0_MC_R)));
                if (MCU_XOSC_GENERAL_FLAG == ((CpyStartRunMode) & (MCU_XOSC_GENERAL_FLAG)) )   /* Put XOSC==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN0_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN0_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                if (MCU_PLL_STATUS_FLAG == ((CpyStartRunMode) & (MCU_PLL_STATUS_FLAG)))   /* Put PLL0ON==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN0_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN0_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                CurrentReg = MC_ME_RUN0_MC_R;
            break;
        case (MCU_RUN1_MODE_VALUE) : /* RUN1 */
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_RUN1_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN1_MC_R)));
                if (MCU_XOSC_GENERAL_FLAG == ((CpyStartRunMode) & (MCU_XOSC_GENERAL_FLAG)) )   /* Put XOSC==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN1_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN1_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                if (MCU_PLL_STATUS_FLAG == ((CpyStartRunMode) & (MCU_PLL_STATUS_FLAG)) )   /* Put PLL0ON==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN1_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN1_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                CurrentReg = MC_ME_RUN1_MC_R;
            break;
        case (MCU_RUN2_MODE_VALUE) : /* RUN2 */
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_RUN2_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN2_MC_R)));
                if (MCU_XOSC_GENERAL_FLAG == ((CpyStartRunMode) & (MCU_XOSC_GENERAL_FLAG)) )   /* Put XOSC==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN2_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN2_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                if (MCU_PLL_STATUS_FLAG == ((CpyStartRunMode) & (MCU_PLL_STATUS_FLAG)) )   /* Put PLL0ON==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN2_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN2_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                CurrentReg = MC_ME_RUN2_MC_R;
            break;
        case (MCU_RUN3_MODE_VALUE) : /* RUN3 */
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_RUN3_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN3_MC_R)));
                if (MCU_XOSC_GENERAL_FLAG == ((CpyStartRunMode) & (MCU_XOSC_GENERAL_FLAG)) )   /* Put XOSC==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN3_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN3_MC_R, (MCU_XOSC_GENERAL_FLAG));
                }
                if (MCU_PLL_STATUS_FLAG == ((CpyStartRunMode) & (MCU_PLL_STATUS_FLAG)) )   /* Put PLL0ON==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_RUN3_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_RUN3_MC_R, (MCU_PLL_STATUS_FLAG));
                }
                CurrentReg = MC_ME_RUN3_MC_R;
            break;
            case (MCU_SAFE_MODE_VALUE) : /* SAFE */
                /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_SAFE_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_SAFE_MC_R)));
                if (ME_POWER_DOWN_OUT_ON == ((CpyStartRunMode) & (ME_POWER_DOWN_OUT_ON)) )  /* Put PDO==ON */
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_SET32(MC_ME_SAFE_MC_R, (ME_POWER_DOWN_OUT_ON));
                }
                else
                {
                    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_BIT_CLEAR32(MC_ME_SAFE_MC_R, (ME_POWER_DOWN_OUT_ON));
                }
            CurrentReg = MC_ME_SAFE_MC_R;
            break;
           default:
           {
                /* This case should never occurs. */
                Cer_ReportError( (uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INITOSC_ID, (uint8)MCU_E_WRONG_MODE);
                /* Compiler_Warning: Statement break is unreachable because of the infinite while loop found in
                   the Cer_ReportError function. The CER is meant to handle those unexpected runtime situations
                   that the existing DEM and DET subsystems cannot cope with.
                */
                break;
           }
        }
    }
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* RC_16MHz circuits Characterization */
    REG_WRITE16(MC_CGM_RC_CTL_R_L, (uint16)(ClockPtr->RC_16MHz));

    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* XOSC 4..40MHz circuits Characterization */
    REG_BIT_SET32(MC_CGM_XOSC_CTL_R, MCU_CRYSTAL_OSC_INT);
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_CGM_XOSC_CTL_R, ClockPtr->Xtal_A);
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* OSC 32kHz circuits Characterization */
    REG_WRITE32(MC_CGM_OSC_CTL_R, ClockPtr->Xtal_B_32KHz);
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* RC_128KHz circuits Characterization */
    REG_WRITE16(MC_CGM_LPRC_CTL_R_L, (uint16)(ClockPtr->RC_128KHz));


    return CurrentReg;
}

/*================================================================================================*/
/**
* @brief          This function initializes the main pll.
* @details        The main pll is started from ME module and by configuring its parameters.
*
* @param[in]      ClockPtr    Pointer to clock configuration structure
*
* @return         void
*
* @implements     DMCU05010
*
*/

FUNC(void, MCU_CODE) Mcu_Init_Pll0(VAR(uint32, AUTOMATIC) CurrentReg, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
{
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_BIT_SET32(MC_CGM_PLL0_CR_R, MCU_PLL_FAIL_MASK);
    /********************************** First PLL configurations************************/
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    if (MCU_PLL_CLOCK == (((uint32) REG_READ32(MC_ME_GS_R)) & MCU_SYSTEM_CLK_MASK))
    {
        if (ClockPtr->McuSystemClockFrequency >= Mcu_CpySystemClockFrequency)
        {
#if (MCU_FLASH_CONFIGURATION_USED == STD_ON)
            /*enter critical region*/
            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_02();
            Mcu_Flash_Configure((uint32) (CFLASH_PFCR0_B02_APC | CFLASH_PFCR0_B02_WWSC | CFLASH_PFCR0_B02_RWSC), (uint32) (DFLASH_PFCR1_B1_APC | DFLASH_PFCR1_B1_WWSC | DFLASH_PFCR1_B1_RWSC));
#endif
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_CGM_PLL0_CR_R, (uint32) ((ClockPtr->Pll_Param) & (MCU_32_BIT_MASK)));
#if (MCU_FLASH_CONFIGURATION_USED == STD_ON)
            Mcu_Flash_Configure((uint32) (ClockPtr->FLASH_PFCR0), (uint32) (ClockPtr->FLASH_PFCR1));
            /*exit critical region*/
            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_02();
#endif
        }
        else
        {
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_CGM_PLL0_CR_R, (uint32) ((ClockPtr->Pll_Param) & (MCU_32_BIT_MASK)));
        }
    }
    else
    {
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_CGM_PLL0_CR_R, (uint32) ((ClockPtr->Pll_Param) & (MCU_32_BIT_MASK)));
    }

    /* For each cases, the fail pll clock in this methods is maskered. It if configure will be actived in
       DistributePLLClock */
    if (MCU_PLL_FM_MODE == ((ClockPtr->PllMode) & (uint16) MCU_PLL_FM_MODE))
    {
        /* Put the FM parameters */
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_CGM_PLL0_MR_R, ((ClockPtr->FMPll_Param) & MCU_FMPLL_MASK));
    }
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_BIT_SET32(CurrentReg, MCU_PLL_STATUS_FLAG);
}


/*================================================================================================*/
/**
* @brief          This function activates FM modulation when PLL0 and PLL1 are in locked state
* @details        This function enable FMPLL0 and FMPLL1. Enable/Disable PLL clock fail for
*                 PLL0 and PLL1.
*
* @param[in]      ClockPtr Pointer to clock configuration structure
*
* @return         void
*
* @implements     DMCU05143
*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_CODE) Mcu_Configure_FMPLL_ClkFail(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
{
    /* Enable FM modulation when FMPLL is in lock state */
    if (MCU_PLL_FM_MODE == ((ClockPtr->PllMode) & (uint16) MCU_PLL_FM_MODE))
    {
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_BIT_SET32(MC_CGM_PLL0_MR_R, MCU_ENABLE_FMPLL);
    }
    /* Enable/Disable PLL cloak fail */
    if (MCU_ZERO_VALUE == ((ClockPtr->Pll_Param) & (MCU_PLL_FAIL_MASK)) )
    {
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_BIT_CLEAR32(MC_CGM_PLL0_CR_R, MCU_PLL_FAIL_MASK);
    }
    else
    {
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_BIT_SET32(MC_CGM_PLL0_CR_R, MCU_PLL_FAIL_MASK);
    }
}

/*================================================================================================*/
/**
* @brief          This function configures the output clock.
* @details        The output clock is selected from CGM module.
*
* @param[in]      ClockPtr    Pointer to clock configuration structure
*
* @return         void
*
* @implements     DMCU05012
*
*/
FUNC(void, MCU_CODE) Mcu_Output_Init(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
{
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* Enable Disable output clock */
    REG_WRITE32(MC_CGM_OC_EN_R, (uint32) ((ClockPtr->Clk_Output) & (MCU_CLK_OUT_MASK)));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* Select Source clock plus divisor factors */
    REG_WRITE8(MC_CGM_OCDS_SC_R, (uint8) (((ClockPtr->Clk_Output) & (~MCU_CLK_OUT_MASK))>>MCU_SHIFT_TWENTY_FOUR));
}

/*================================================================================================*/
/**
* @brief          This function disables the output clock.
* @details        This function disables the output clock.
*
* @implements
*
*/
#ifdef MCU_CONFIGURE_CLK_OUT
#if (MCU_CONFIGURE_CLK_OUT == STD_OFF)
 FUNC(void, MCU_CODE) Mcu_LLD_Disable_ClkOut (void)
 {
     /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
     REG_WRITE32(MC_CGM_OC_EN_R, ~MCU_CLK_OUT_MASK); /* Disable output clock */
 }
#endif
#endif

/*================================================================================================*/
/**
* @brief          This function initializes the clock to the peripheral sets.
* @details        Each peripheral set clock is initialized by writing to the CGM module.
*
* @param[in]      ClockPtr      Pointer to clock configuration structure
*
* @return         void
*
* @implements     DMCU05013
*
*/
FUNC(void, MCU_CODE) Mcu_Peripheral_Sets_Init(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
{
    VAR(volatile uint8, AUTOMATIC) PerClock = MCU_ZERO_BYTE_VALUE;
    if (MCU_PC1_ENABLED == ((ClockPtr->Periph_Clk) & MCU_PC1_ENABLED))   /* Check if the clock for per1 is enabled */
    {
        PerClock = (uint8) (((ClockPtr->Periph_Clk) & (MCU_PERIPH_CLOCK_DIV_MASK << MCU_SHIFT_TWENTY_FOUR)) >> (MCU_SHIFT_TWENTY_FOUR));
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_BIT_SET8(MC_CGM_SC_DC0_R, MCU_DE_ENABLED);
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE8(MC_CGM_SC_DC0_R, (uint8) (PerClock));
    }
    else
    {
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE8(MC_CGM_SC_DC0_R, (uint8) MCU_ZERO_BYTE_VALUE);
    }
    if (((ClockPtr->Periph_Clk) & MCU_PC2_ENABLED) == MCU_PC2_ENABLED)   /* Check if the clock for per2 is enabled */
    {
        PerClock = ((uint8) (((ClockPtr->Periph_Clk) & (MCU_PERIPH_CLOCK_DIV_MASK << MCU_SHIFT_SIXTEEN)) >> MCU_SHIFT_SIXTEEN));
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_BIT_SET8(MC_CGM_SC_DC1_R, MCU_DE_ENABLED);
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE8(MC_CGM_SC_DC1_R, (uint8) (PerClock));
    }
    else
    {
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE8(MC_CGM_SC_DC1_R, (uint8) MCU_ZERO_BYTE_VALUE);
    }
    if (MCU_PC3_ENABLED == ((ClockPtr->Periph_Clk) & MCU_PC3_ENABLED) )   /* Check if the clock for per3 is enabled */
    {
        PerClock = ((uint8) (((ClockPtr->Periph_Clk) & (MCU_PERIPH_CLOCK_DIV_MASK << MCU_SHIFT_EIGHT)) >> MCU_SHIFT_EIGHT));
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_BIT_SET8(MC_CGM_SC_DC2_R, MCU_DE_ENABLED);
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE8(MC_CGM_SC_DC2_R, (uint8) (PerClock));
    }
    else
    {
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE8(MC_CGM_SC_DC2_R, (uint8) MCU_ZERO_BYTE_VALUE);
    }
}

/*================================================================================================*/
/**
* @brief          This function waits for the low power oscillators to be stable.
* @details        This function waits for the low power oscillators to be stable.
*
* @param[in]      ClockPtr    Pointer to clock configuration structure
*
* @return         Std_ReturnType
* @retval E_OK    Oscillator stable
*
* @retval MCU_E_32k_OSC_NOT_STABLE   32KHz oscillator not stable
*
* @retval MCU_E_128k_OSC_NOT_STABLE  128KHz osccillator not stable
*
*
* @implements     DMCU05014
*
*/

FUNC(Std_ReturnType, MCU_CODE) Mcu_Check_Stability(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr) {
    VAR (Std_ReturnType, AUTOMATIC) status = (Std_ReturnType) E_OK;
    VAR(uint32, AUTOMATIC) Local_TimeOut = MCU_ZERO_VALUE;
    if (ENABLE_OSC == ((ClockPtr->Xtal_B_32KHz) & ENABLE_OSC))
    {
        /* 32kHz Oscillator */
        if (MCU_ZERO_VALUE == ((ClockPtr->Xtal_B_32KHz) & MCU_CLK_STABLE))
        {
            Local_TimeOut = MCU_ZERO_VALUE;
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            while (((MCU_ZERO_VALUE) == (REG_READ32(MC_CGM_OSC_CTL_R) & MCU_32KHZ_CLK_STABLE) ) && (Local_TimeOut < Mcu_TimeOut))
            {
                Local_TimeOut++;
            }
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            if ((MCU_ZERO_VALUE) == (REG_READ32(MC_CGM_OSC_CTL_R) & MCU_32KHZ_CLK_STABLE) )
            {
                status = (Std_ReturnType) MCU_E_32k_OSC_NOT_STABLE;
            }
        }
    }
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_7 MISRA 2004 Rule 14.7, variable always return true */
    if ((Std_ReturnType) E_OK == status )
    {
        /* 128kHz Oscillator */
        Local_TimeOut = MCU_ZERO_VALUE;
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        while (((MCU_ZERO_VALUE) == (REG_READ32(MC_CGM_LPRC_CTL_R) & MCU_128KHZ_CLK_STABLE) ) && (Local_TimeOut < Mcu_TimeOut))
        {
            Local_TimeOut++;
        }
        /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        if ((MCU_ZERO_VALUE) == (REG_READ32(MC_CGM_LPRC_CTL_R) & (MCU_128KHZ_CLK_STABLE)) )
        {
            status = (Std_ReturnType) MCU_E_128k_OSC_NOT_STABLE;
        }
    }
    return status;
}

/*================================================================================================*/
/**
* @brief          This function disable Auxiliary clock selectors
* @details        This function disable Auxiliary clock selectors.
*
*
* @param[in]      none
*
* @return         void
*
* @implements     DMCU05156
*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_CODE) Mcu_Disable_Peripheral(void)
{
    /* Override RUN_PCx configuration in order to gate all peripherals clock via LP and RUN config 0 */
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC0_R, (uint32) (MCU_ZERO_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC0_R, (uint32) (MCU_ZERO_VALUE));

    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL4_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL5_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL6_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL7_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL8_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL9_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL12_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL13_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL16_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL17_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL18_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL19_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL20_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL21_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL23_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL32_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL33_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL44_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL48_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL49_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL50_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL51_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL52_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL53_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL54_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL55_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL57_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL60_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL68_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL69_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL72_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL73_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL91_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL92_R, (uint8) (MCU_ZERO_BYTE_VALUE));
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL104_R, (uint8) (MCU_ZERO_BYTE_VALUE));

}

/*================================================================================================*/
/**
* @brief          This function put FMPLL OFF
* @details        The function turns off the FMPLL before changing the settings of
*                 the FMPLL
*
* @param[in]      none
*
* @return         void
*
* @implements     DMCU05155
*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_CODE) Mcu_PLL_0FF(void)
{
    VAR(uint32, AUTOMATIC) CpyMode = MCU_ZERO_VALUE;

    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    CpyMode = REG_READ32(MC_ME_GS_R);
    
    /* Disable frequency modulation before switching PLL off */
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_BIT_CLEAR32(MC_CGM_PLL0_MR_R, MCU_ENABLE_FMPLL);
    
    switch (CpyMode & MCU_SYSTEM_MODE_MASK)
    {
    case (MCU_DRUN_MODE_VALUE) : /* DRUN */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_DRUN_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_DRUN_MC_R)));
            /* Put PLL0ON==OFF */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_CLEAR32(MC_ME_DRUN_MC_R, (MCU_PLL_STATUS_FLAG));
        break;
    case (MCU_RUN0_MODE_VALUE) : /* RUN0 */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN0_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN0_MC_R)));
            /* Put PLL0ON==OFF */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_CLEAR32(MC_ME_RUN0_MC_R, (MCU_PLL_STATUS_FLAG));
        break;
    case (MCU_RUN1_MODE_VALUE) : /* RUN1 */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN1_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN1_MC_R)));
            /* Put PLL0ON==OFF */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_CLEAR32(MC_ME_RUN1_MC_R, (MCU_PLL_STATUS_FLAG));
        break;
    case (MCU_RUN2_MODE_VALUE) : /* RUN2 */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN2_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN2_MC_R)));
            /* Put PLL0ON==OFF */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_CLEAR32(MC_ME_RUN2_MC_R, (MCU_PLL_STATUS_FLAG));
        break;
    case (MCU_RUN3_MODE_VALUE) : /* RUN3 */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN3_MC_R, (uint32) ((uint32) (~MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN3_MC_R)));
            /* Put PLL0ON==OFF */
            /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_BIT_CLEAR32(MC_ME_RUN3_MC_R, (MCU_PLL_STATUS_FLAG));
        break;
    default:
    {
        break;
    }
    }
}

/*================================================================================================*/
/**
* @brief          This function returns the status of the pll.
* @details        This reads the main pll status and returns if the pll locked or not.
*
* @param[in]      none
*
* @return         void
*
* @implements     DMCU05015
*
*/
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_FMPLL_GetPllStatus(void)
{
    VAR(Mcu_PllStatusType, AUTOMATIC) Status = MCU_PLL_UNLOCKED;
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    if (MCU_CHECK_PLLLOCK_FLAG == (REG_READ32(MC_CGM_PLL0_CR_R) & (MCU_CHECK_PLLLOCK_FLAG))  )
    {
        Status = MCU_PLL_LOCKED;
    }
    return Status;
}


/*================================================================================================*/
/**
* @brief          This function forces clocking of CMU0 IP.
* @details        Should be called after Mcu_Disable_Peripherals to avoid any conflict with other peripherals.
*
* @param[in]      none
*
* @return         void
*
* @implements     DMCU05016
*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_CODE) Mcu_Force_CMU_Clock(void)
{
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC1_R, MCU_32_BIT_MASK);
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL104_R, (uint8) (MCU_ONE_BYTE_VALUE));
}

/*================================================================================================*/
/**
* @brief          This function forces clocking of eMIOS IPs.
* @details        Should be called after Mcu_Disable_Peripherals to avoid any conflict with other peripherals.
*
* @param[in]      none
*
* @return         void
*
* @implements     DMCU05016
*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_CODE) Mcu_Force_eMIOS_Clock(void)
{
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC1_R, MCU_32_BIT_MASK);
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL72_R, MCU_ONE_BYTE_VALUE);
    /* @violates @ref Mcu_MC_Clocks_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(MC_ME_PCTL73_R, MCU_ONE_BYTE_VALUE);
}

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_MC_Clocks_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Clocks_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
