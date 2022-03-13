/**
*   @file    Mcu_MC_Reset_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - File used by MCU to configure RGM parameters.
*   @details This file contains functions used for configuring parameters for the RGM module.
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
* @section Mcu_MC_Reset_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory 
* section
* 
* @section Mcu_MC_Reset_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
* 
* @section Mcu_MC_Reset_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers 
* to other types used in macros for reading or writing data from address location of controller register.
*
* @section Mcu_MC_Reset_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_MC_Reset_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 14.10,All if ... else if constructs shall be terminated with an else clause.
* Nothing to do in else.
*
* @section Mcu_MC_Reset_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_LLD.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON) 
#include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Mcu_MC_Reset_lld.c
* @implements     DMCU05036, DMCU05037, DMCU05038, DMCU05039, DMCU05040, DMCU05041,DMCU05042
*
*/
#define MCU_MC_RESET_LLD_VENDOR_ID_C                      43
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_RESET_LLD_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_RESET_LLD_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_RESET_LLD_AR_RELEASE_REVISION_VERSION_C    3
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_RESET_LLD_SW_MAJOR_VERSION_C               1
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_RESET_LLD_SW_MINOR_VERSION_C               0
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_4 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_RESET_LLD_SW_PATCH_VERSION_C               1

/*==================================================================================================
                                        FILE VERSION CHECKS
 ==================================================================================================*/
/* Check if current file and Mcu_LLD.h file are of the same vendor */
#if (MCU_MC_RESET_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
    #error "Mcu_MC_Reset_LLD.c and Mcu_LLD.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_LLD.h file are of the same Autosar version */
#if ((MCU_MC_RESET_LLD_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_RESET_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_RESET_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_MC_Reset_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h file are of the same Software version */
#if ((MCU_MC_RESET_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_MC_RESET_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_MC_RESET_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_MC_Reset_LLD.c and Mcu_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        #if ((MCU_MC_RESET_LLD_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (MCU_MC_RESET_LLD_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcu_MC_Reset_LLD.c and Det.h are different"
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
#define MCU_START_SEC_VAR_NO_INIT_32
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
/**
 * @brief Mcu reset status
*/
STATIC VAR(uint32, MCU_VAR) Mcu_ResetStatus;

#define MCU_STOP_SEC_VAR_NO_INIT_32
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements  
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Reset_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements  
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Reset_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          This function initializes the reset parameters.
* @details        This function configures disabling the functional event reset , disabling the 
*                 destructive event reset, the functional event alternate request, the destructive
*                 event alternate request, the functional event short sequence, the standby reset 
*                 sequence and enabling the functional bidirectional reset.
*
* @param[in]      ConfigLLDPtr Pointer to LLD configuration structure
*
* @return         void
*
* @implements     DMCU05154
*/
FUNC(void, MCU_CODE) Mcu_Reset_Init(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr)
{
    /* RESET Configurations */ 
    /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE16(MC_RGM_FERD_R, (uint16) (ConfigLLDPtr->Func_ResetOpt));


    /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE16(MC_RGM_FEAR_R, (uint16) (ConfigLLDPtr->Func_SafeIsrOpt));

    /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE16(MC_RGM_FESS_R, (uint16) (ConfigLLDPtr->Func_Phase1or3Opt));


    /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE16(MC_RGM_FBRE_R, (uint16) (ConfigLLDPtr->Ext_PinReset));
 }

/*================================================================================================*/
/**
* @brief          This function returns the reset reason.
* @details        The function reads the reset reason from hardware and returns the reason.
*
* @param[in]      Mcu_TimeOut    Mcu timeout
*
* @return         Mcu_ResetType
*
* @implements     DMCU05043
*
*/

FUNC(Mcu_ResetType, MCU_CODE) Mcu_RGM_GetResetReason(VAR(uint32, AUTOMATIC) Mcu_TimeOut)
{
        VAR(uint32, AUTOMATIC) Local_TimeOut = MCU_ZERO_VALUE;


    VAR(Mcu_RawResetType, AUTOMATIC) RawResetReg;
    VAR(Mcu_ResetType, AUTOMATIC) RawReset = MCU_RESET_UNDEFINED;
    VAR(volatile uint16, AUTOMATIC) TempReg = (uint16) MCU_ZERO_VALUE;
    VAR(uint32, AUTOMATIC) ResetBitMask = (uint32) MCU_ZERO_VALUE;
    /**********************************************************
    RawResetReg = (MC_RGM_DES) + (MC_RGM_FES<<16)
     **********************************************************/
    /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    RawResetReg = (Mcu_RawResetType) ((uint32) (REG_READ16(MC_RGM_DES_R)));
    /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    RawResetReg = (Mcu_RawResetType) ((uint32) RawResetReg + (uint32) (((uint32) REG_READ16(MC_RGM_FES_R)) << MCU_SHIFT_SIXTEEN));
    
    if ( ((uint32) MCU_ZERO_VALUE) == RawResetReg )
    {
        /* No pending reset bit - all reset reasons have been reported */
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_6 Required Rule 14.7 Return statement before end of function. */
        return MCU_RESET_UNDEFINED;
    }
    /* A reset bit is set : update the global variable */
    Mcu_ResetStatus = RawResetReg;
    if (MCU_MASK_POR_RESET == (RawResetReg & (MCU_MASK_POR_RESET)) )
    {
        RawReset = MCU_POWER_ON_RESET;
        ResetBitMask = MCU_MASK_POR_RESET;
    }

    else if (MCU_MASK_LVD27_VREG_RESET == (RawResetReg & (MCU_MASK_LVD27_VREG_RESET)) )
    {
        RawReset = MCU_2_7_LV_VREG_RESET;
        ResetBitMask = MCU_MASK_LVD27_VREG_RESET; 

    }
    else if ((RawResetReg & (MCU_MASK_LVD27_RESET)) == MCU_MASK_LVD27_RESET)
    {
        RawReset = MCU_2_7_LOW_VOLTAGE;
        ResetBitMask = MCU_MASK_LVD27_RESET; 
    }
    else if (MCU_MASK_SWT_D_RESET == (RawResetReg & (MCU_MASK_SWT_D_RESET)) )
    {
        RawReset = MCU_WATCHDOG_RESET;
        ResetBitMask = MCU_MASK_SWT_D_RESET; 
    }
    else if ((RawResetReg & (MCU_MASK_LVD12_PD1_RESET)) == MCU_MASK_LVD12_PD1_RESET)
    {
        RawReset = MCU_1_2_LV_PW_DOMAIN_1;
        ResetBitMask = MCU_MASK_LVD12_PD1_RESET; 
    }
    else if ((RawResetReg & MCU_MASK_LVD12_PD0_RESET) == MCU_MASK_LVD12_PD0_RESET)
    {
        RawReset = MCU_1_2_LV_PW_DOMAIN_0;
        ResetBitMask = MCU_MASK_LVD12_PD0_RESET;
    }
    else if ((RawResetReg & (MCU_MASK_FLASH_RESET)) == MCU_MASK_FLASH_RESET)
    {
        RawReset = MCU_FLASH_RESET;
        ResetBitMask = MCU_MASK_FLASH_RESET;
    }
    else if ((RawResetReg & (MCU_MASK_LVD45_RESET)) == MCU_MASK_LVD45_RESET)
    {
        RawReset = MCU_4_5_LOW_VOLTAGE;
        ResetBitMask = MCU_MASK_LVD45_RESET;
    }
    else if (MCU_MASK_CMU0_FHL_RESET == (RawResetReg & (MCU_MASK_CMU0_FHL_RESET)) )
    {
        RawReset = MCU_CMU_FHL_RESET;
        ResetBitMask = MCU_MASK_CMU0_FHL_RESET;
    }
    else if (MCU_MASK_CMU0_OLR_RESET == (RawResetReg & (MCU_MASK_CMU0_OLR_RESET)) )
    {
        RawReset = MCU_CMU_OLR_RESET;
        ResetBitMask = MCU_MASK_CMU0_OLR_RESET;
    }
    else if (MCU_MASK_PLL0_RESET == (RawResetReg & (MCU_MASK_PLL0_RESET)) )
    {
        RawReset = MCU_PLL0_RESET;
        ResetBitMask = MCU_MASK_PLL0_RESET;
    }
    else if ((RawResetReg & (MCU_MASK_CHECKSTOP_RESET)) == MCU_MASK_CHECKSTOP_RESET)
    {
        RawReset = MCU_CHECKSTOP_RESET;
        ResetBitMask = MCU_MASK_CHECKSTOP_RESET;
    }
    else if (MCU_MASK_SOFT_RESET == (RawResetReg & (MCU_MASK_SOFT_RESET)) )
    {
        RawReset = MCU_SW_RESET;
        ResetBitMask = MCU_MASK_SOFT_RESET;
    }
    else if (MCU_MASK_CORE_RESET == (RawResetReg & (MCU_MASK_CORE_RESET)) )
    {
        RawReset = MCU_CORE_RESET;
        ResetBitMask = MCU_MASK_CORE_RESET;
    }
    else if (MCU_MASK_JTAG_RESET == (RawResetReg & MCU_MASK_JTAG_RESET) )
    {
        RawReset = MCU_JTAG_RESET;
        ResetBitMask = MCU_MASK_JTAG_RESET;
    }
    else if (MCU_MASK_EXT_RESET == (RawResetReg & (MCU_MASK_EXT_RESET)) )
    {
        RawReset = MCU_EXR_RESET;
        ResetBitMask = MCU_MASK_EXT_RESET;
    }
    else
    {
        RawReset = MCU_RESET_UNDEFINED;
    }
    if( (ResetBitMask & MCU_RGM_DES_REG_MASK) != MCU_ZERO_VALUE )
    {
        /* dest reset */
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE16(MC_RGM_DES_R, (uint16) ResetBitMask);
#ifdef  ERR_IPV_MC_0026
    #if (ERR_IPV_MC_0026 == STD_ON)  
        TempReg = REG_READ16(MC_RGM_DES_R); 
    #endif
#endif    
    }
    else
    {
        /* func reset */
        ResetBitMask >>= MCU_SHIFT_SIXTEEN;
        /* the following loop is required according to the note in Reference Manual FES register*/
        do  
        {
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */            
            REG_WRITE16(MC_RGM_FES_R, ResetBitMask); /* Clear FES */
            /* Read FES */
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            TempReg = REG_READ16(MC_RGM_FES_R); 
            Local_TimeOut++;
        }
        while (((TempReg & ResetBitMask) != (MCU_ZERO_VALUE)) && (Local_TimeOut < Mcu_TimeOut));
    }
    return RawReset;
}

/*================================================================================================*/
/**
* @brief          This function returns the raw reset value.
* @details        This function reads the reset raw value from the hardware register.
*
* @param[in]      Mcu_TimeOut Mcu Timeout
*
*
* @return         Mcu_RawResetType
*
* @implements     DMCU05044
*
*/

FUNC(Mcu_RawResetType, MCU_CODE) Mcu_RGM_GetResetRawValue(VAR(uint32, AUTOMATIC) Mcu_TimeOut)
{
  VAR(uint32, AUTOMATIC) Local_TimeOut = MCU_ZERO_VALUE;

    VAR(Mcu_RawResetType, AUTOMATIC) RawResetReg;
    VAR(volatile uint16, AUTOMATIC) TempReg = (uint16) MCU_ZERO_VALUE;

    /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    RawResetReg = (Mcu_RawResetType) ((uint32) (REG_READ16(MC_RGM_DES_R)) & ((uint32) (MCU_RGM_DES_REG_MASK)));
   /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    RawResetReg = (Mcu_RawResetType) ((uint32) RawResetReg + (uint32) (((uint32) REG_READ16(MC_RGM_FES_R)) << MCU_SHIFT_SIXTEEN));
    if ((uint32) MCU_ZERO_VALUE == RawResetReg )
    {
        RawResetReg = Mcu_ResetStatus;
    }
    else
    {
        Mcu_ResetStatus = RawResetReg;
/* @errata ERR_IPV_MC_0026 */
#ifdef  ERR_IPV_MC_0026
     #if (ERR_IPV_MC_0026 == STD_ON)
        /* Writting one to clear all the reset bits. */
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE16(MC_RGM_DES_R, (uint16) MCU_RGM_DES_REG_MASK); 

        /* Dummy read to all the reset bits. */
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        TempReg = REG_READ16(MC_RGM_DES_R); 

        /* Writting one to clear all the reset bits. */ 
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_RGM_FES_REG_MASK); 
        
        /* Dummy read to all the reset bits. */
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        TempReg = REG_READ16(MC_RGM_FES_R); 
     #endif 
#else
        /* Normal implementation   */
        /* Writting one to clear all the reset bits. */
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE16(MC_RGM_DES_R, (uint16) MCU_RGM_DES_REG_MASK); 
    
        /* Writting one to clear all the reset bits. */
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_RGM_FES_REG_MASK); 
#endif 

        /* the following loop is required according to the note in Leopard RM Rev7*/
        do {
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_RGM_FES_REG_MASK); /* Clear FES */
            /* Read FES */
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            TempReg = REG_READ16(MC_RGM_FES_R); 
            Local_TimeOut++;
           }
        while ((TempReg != (MCU_ZERO_VALUE)) && (Local_TimeOut < Mcu_TimeOut));

    }
    return RawResetReg;
}

/*================================================================================================*/
/**
* @brief          This function performs a microcontroller reset.
* @details        This function performs a microcontroller reset by using the hardware feature of 
*                 the microcontroller.
*                 lines and contain formatting tags (both Doxygen and HTML). Optional tag.
*
* @param[in]      ResetType   Functional/Desctructive reset type
*
* @return         void
*
* @implements     DMCU05045
*
*/

#if MCU_PERFORM_RESET_API == STD_ON
    FUNC(void, MCU_CODE) Mcu_RGM_PerformReset(VAR(void, AUTOMATIC))

    {
        /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        if (MCU_ZERO_VALUE == (REG_READ32(MC_ME_GS_R) & (MCU_SHIFT_ONE << MCU_SHIFT_TWENTY_SEVEN)) )
        {
/* @errata ERR_IPV_MC_0004 */
#ifdef  ERR_IPV_MC_0004
     #if (ERR_IPV_MC_0004 == STD_ON)
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_RGM_FES_REG_MASK); 
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE16(MC_RGM_DES_R, (uint16) MCU_RGM_DES_REG_MASK); 
     #endif 
#endif 
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_MCTL_R, MCU_SOFT_CONTROL_KEY_ONE);
            /* @violates @ref Mcu_MC_Reset_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_MCTL_R, MCU_SOFT_CONTROL_KEY_TWO);
       }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        else
        {
            Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_PERFORMRESET_ID, (uint8) MCU_E_TRANSITION_IN_PROGRESS);
        }
#endif
    }
#endif /* #if MCU_PERFORM_RESET_API == STD_ON */

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_MC_Reset_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements  
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Reset_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
