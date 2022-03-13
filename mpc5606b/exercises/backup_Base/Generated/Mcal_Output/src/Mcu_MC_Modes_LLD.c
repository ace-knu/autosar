/**
*   @file    Mcu_MC_Modes_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - File used by MCU to configure ME parameters.
*   @details This file contains functions used for configuring parameters for the ME module.
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
* @section Mcu_MC_Modes_lld_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_MC_Modes_lld_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_MC_Modes_lld_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers
* to other types used in macros for reading or writing data from address location of controller register.
*
* @section Mcu_MC_Modes_lld_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, API could not be made static.
*
* @section Mcu_MC_Modes_lld_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability
*
* @section Mcu_MC_Modes_lld_c_REF_6
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_MC_Modes_lld_c_REF_7
* Violates MISRA 2004 Required Rule 14.10,All if ... else if constructs shall be terminated  with an else clause.
* Nothing to do in else.
*
* @section Mcu_MC_Modes_lld_c_REF_8
* Violates MISRA 2004 Required Rule 12.4, The right-hand operand of a logical && or || operator shall not contain side effects.
* This has been done to reduce code complexity.
*
* @section Mcu_MC_Modes_lld_c_REF_9 
* Violates MISRA 2004 Required Rule 16.10,If a function returns error information, then that error information shall be tested.
* No action required on error return of this function in this case.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcu_LLD.h"
#include "SchM_Mcu.h"
/*
* @file           Mcu_MC_Modes_LLD.c
* @implements     DMCU00004
*/
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Mcu_MC_Modes_LLD.c
* @implements     DMCU05017, DMCU05018, DMCU05019, DMCU05020, DMCU05021, DMCU05022, DMCU05023
*
*/

#define MCU_MC_MODES_LLD_VENDOR_ID_C                      43
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MODES_LLD_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MODES_LLD_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MODES_LLD_AR_RELEASE_REVISION_VERSION_C    3
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MODES_LLD_SW_MAJOR_VERSION_C               1
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MODES_LLD_SW_MINOR_VERSION_C               0
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_MC_MODES_LLD_SW_PATCH_VERSION_C               1

/*==================================================================================================
                                        FILE VERSION CHECKS
 ==================================================================================================*/
/* Check if current file and Mcu_LLD.h file are of the same vendor */
#if (MCU_MC_MODES_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
    #error "Mcu_MC_Modes_LLD.c and Mcu_LLD.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_LLD.h  file are of the same Autosar version */
#if ((MCU_MC_MODES_LLD_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_MODES_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_MODES_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_MC_Modes_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h file are of the same Software version */
#if ((MCU_MC_MODES_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_MC_MODES_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_MC_MODES_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_MC_Modes_LLD.c and Mcu_LLD.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        #if ((MCU_MC_MODES_LLD_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (MCU_MC_MODES_LLD_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcu_MC_Modes_LLD.c and Det.h are different"
        #endif
    #endif
#endif
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same version */
    #if ((MCU_MC_MODES_LLD_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_MODES_LLD_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_MC_Modes_LLD.c and Dem.h are different"
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

STATIC FUNC(void, MCU_CODE) Mcu_Apply_Run_Mode(VAR(uint32, AUTOMATIC) RUN_Param, VAR(uint32, AUTOMATIC)  StatusReg);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/* @errata ERR_IPV_MC_0017 */
#ifdef ERR_IPV_MC_0017
   #if (ERR_IPV_MC_0017 == STD_ON)
#define MCU_START_SEC_RAMCODE
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
STATIC FUNC(Std_ReturnType, MCU_CODE) Mcu_Apply_Mode_Ram (VAR(uint32, AUTOMATIC) CurrentStatusReg, P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr,
                   VAR(uint32, AUTOMATIC) StatusReg, VAR(uint32, AUTOMATIC) Mcu_TimeOut);

#define MCU_STOP_SEC_RAMCODE
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
STATIC P2FUNC (Std_ReturnType, const, Mcu_Apply_Mode_from_Ram)(VAR(uint32, AUTOMATIC) CurrentStatusReg, P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr,
                   VAR(uint32, AUTOMATIC) StatusReg,VAR(uint32, AUTOMATIC) Mcu_TimeOut) = &Mcu_Apply_Mode_Ram;
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#define MCU_START_SEC_RAMCODE
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
STATIC FUNC(Std_ReturnType, MCU_RAM_CODE) Mcu_Apply_Mode_Ram (VAR(uint32, AUTOMATIC) CurrentStatusReg,
             P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr,
             VAR(uint32, AUTOMATIC) StatusReg, VAR(uint32, AUTOMATIC) Mcu_TimeOut)
{
    VAR(uint32, AUTOMATIC) ModeTemp = ModePtr->Mode;
    VAR (Std_ReturnType, AUTOMATIC) status = (Std_ReturnType) E_OK;
    VAR(uint32, AUTOMATIC) Loop = 0UL;
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_RMW32(CurrentStatusReg, ((ME_MODE_CFAON_MASK) | (ME_MODE_DFAON_MASK)), (uint32)((ModePtr->LP_Param)&(ME_MODE_CFAON_MASK | ME_MODE_DFAON_MASK)));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_MCTL_R, (((ModeTemp) << (uint32)MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_MCTL_R, (((ModeTemp) << (uint32)MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
    do
    {
        if (Loop > Mcu_TimeOut)
        {
            status = (Std_ReturnType)E_NOT_OK;
            break;
        }
        Loop++;
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    }  while (MCU_TRANSITION_STATUS == (REG_READ32(MC_ME_GS_R) & (MCU_TRANSITION_STATUS)) );
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_RMW32 (CurrentStatusReg, (ME_MODE_CFAON_MASK | ME_MODE_DFAON_MASK), (ME_MODE_CFAON(ME_CFLASH_NORMAL) | ME_MODE_DFAON(ME_DFLASH_NORMAL)));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_MCTL_R, ((((uint32)(StatusReg)) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_MCTL_R, ((((uint32)(StatusReg)) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
    Loop = 0UL;
    do
    {
        if (Loop > Mcu_TimeOut)
        {
            status = (Std_ReturnType)E_NOT_OK;
            break;
        }
        Loop++;
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    }  while (MCU_TRANSITION_STATUS == (REG_READ32(MC_ME_GS_R) & (MCU_TRANSITION_STATUS)));

    return (Std_ReturnType)status;
}
#define MCU_STOP_SEC_RAMCODE
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
   #endif
#endif

#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          This function initializes the ME configuration registers.
* @details        This function initializes the ME running and non-running configuration registers
*                 and ME interrupt masks.
*
* @param[in]      ConfigLLDPtr  Pointer to LLD configuration structure
*
* @return         void
*
* @implements     DMCU05024
*
*/
FUNC(void, MCU_CODE) Mcu_Modes_Init(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr)
{
/* @errata ERR_IPV_MC_0014 */
#ifdef  ERR_IPV_MC_0014
     #if (ERR_IPV_MC_0014  == STD_ON)
        #if (MCU_SKIP_FUNCTION == STD_ON)
            VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType) E_OK;
        #endif
     #endif
#endif
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_ME_R, (ConfigLLDPtr->ModeEnabled));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC0_R, (uint32) (ConfigLLDPtr->RunConfig0));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC1_R, (uint32) (ConfigLLDPtr->RunConfig1));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC2_R, (uint32) (ConfigLLDPtr->RunConfig2));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC3_R, (uint32) (ConfigLLDPtr->RunConfig3));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC4_R, (uint32) (ConfigLLDPtr->RunConfig4));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC5_R, (uint32) (ConfigLLDPtr->RunConfig5));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC6_R, (uint32) (ConfigLLDPtr->RunConfig6));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_RUN_PC7_R, (uint32) (ConfigLLDPtr->RunConfig7));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC0_R, (((uint32) (ConfigLLDPtr->LowPwrConfig0))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC1_R, (((uint32) (ConfigLLDPtr->LowPwrConfig1))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC2_R, (((uint32) (ConfigLLDPtr->LowPwrConfig2))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC3_R, (((uint32) (ConfigLLDPtr->LowPwrConfig3))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC4_R, (((uint32) (ConfigLLDPtr->LowPwrConfig4))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC5_R, (((uint32) (ConfigLLDPtr->LowPwrConfig5))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC6_R, (((uint32) (ConfigLLDPtr->LowPwrConfig6))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_LP_PC7_R, (((uint32) (ConfigLLDPtr->LowPwrConfig7))));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* Eanble/Disable Isr for transition */
    REG_WRITE32(MC_ME_IM_R, (uint32) (ConfigLLDPtr->IsrMode));
/* @errata ERR_IPV_MC_0014 */
#ifdef  ERR_IPV_MC_0014
     #if (ERR_IPV_MC_0014  == STD_ON)
        /* Peripheral clocks may  get incorrectly disabled or enabled after entering debug mode */
     #if (MCU_SKIP_FUNCTION == STD_ON)
         Status = Mcu_Apply_Mode (ConfigLLDPtr->TimeOut, MCU_32_BIT_MASK);
         if ((Std_ReturnType) E_NOT_OK == Status)
         {
             /* @violates @ref Mcu_MC_Modes_lld_c_REF_5 Required Rule 14.7 Return statement before end of function. */
             return;
         }
     #else
         Mcu_Apply_Mode (ConfigLLDPtr->TimeOut, MCU_32_BIT_MASK);
     #endif
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_IS_R, ME_IS_MTC_SET);
     #endif
#endif
}

/*================================================================================================*/
/**
* @brief          This function performs an ME transition.
* @details        The function initializes a ME transition and waits for it to finish. In case the
*                 transition takes too long, it returns and reports MCU_TIMEOUT_TRANSITION to DEM.
*
* @param[in]      Mcu_TimeOut      Timeout for the transition
*
* @param[in]      Mode             The required mode
*
* @return         void
*
* @implements     DMCU05025
*/
#if (MCU_SKIP_FUNCTION == STD_ON)
FUNC(Std_ReturnType, AUTOMATIC) Mcu_Apply_Mode(VAR(uint32, AUTOMATIC) Mcu_TimeOut, VAR(uint32, AUTOMATIC) Mode)
#else
FUNC(void, AUTOMATIC) Mcu_Apply_Mode(VAR(uint32, AUTOMATIC) Mcu_TimeOut, VAR(uint32, AUTOMATIC) Mode)
#endif
{
#if (MCU_SKIP_FUNCTION == STD_ON)
        VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
#endif
    VAR(uint32, AUTOMATIC) Loop = 0UL;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    VAR(uint32, AUTOMATIC) ModeEnStatus = 0UL;
#endif

    if (MCU_32_BIT_MASK == Mode)
    {
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        Mode = REG_READ32(MC_ME_GS_R);
    }

    Mode = Mode & (uint32) MCU_SYSTEM_MODE_MASK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    ModeEnStatus = (uint32) REG_READ32(MC_ME_ME_R);
        if (((Mode == ME_MCTL_TARGET_MODE(ME_TARGET_MODE_RUN1)) && ((ModeEnStatus & ME_ME_RUN1_ENABLE) != ME_ME_RUN1_ENABLE))||\
            ((Mode == ME_MCTL_TARGET_MODE(ME_TARGET_MODE_RUN2)) && ((ModeEnStatus & ME_ME_RUN2_ENABLE) != ME_ME_RUN2_ENABLE))||\
            ((Mode == ME_MCTL_TARGET_MODE(ME_TARGET_MODE_RUN3)) && ((ModeEnStatus & ME_ME_RUN3_ENABLE) != ME_ME_RUN3_ENABLE)))
        {
         Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
        (uint8) MCU_APPLY_MODE_ID, (uint8) MCU_E_MODE_NOT_ENABLED);
#if (MCU_SKIP_FUNCTION == STD_ON)
        Status = (Std_ReturnType) E_NOT_OK;
#endif
        }
        else
        {
#endif
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* Apply the configuration */
    REG_WRITE32(MC_ME_MCTL_R, (Mode | MCU_SOFT_CONTROL_KEY_ONE));
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(MC_ME_MCTL_R, (Mode | MCU_SOFT_CONTROL_KEY_TWO));
    do
    {
        if (Loop > Mcu_TimeOut)
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_TimeoutTransitionCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_TimeoutTransitionCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
#if (MCU_SKIP_FUNCTION == STD_ON)
            Status = (Std_ReturnType) E_NOT_OK;
#endif
            break;
        }
        Loop++;
    }
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    while (MCU_TRANSITION_STATUS == (REG_READ32(MC_ME_GS_R) & (MCU_TRANSITION_STATUS)) );
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
#if (MCU_SKIP_FUNCTION == STD_ON)
    return Status;
#endif
}

/*================================================================================================*/
/**
* @brief          This function changes the running ME mode.
* @details        The mode is changed and configures clock dependent flash parameters.
*
* @param[in]      ClockPtr    Pointer to clock configuration structure
*
* @param[in]      Mcu_TimeOut Mcu timeout
*
* @return         void
*
* @implements    DMCU05151
*/
#if (MCU_SKIP_FUNCTION == STD_ON)
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(Std_ReturnType, AUTOMATIC) Mcu_Change_Mode(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
#else
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, AUTOMATIC) Mcu_Change_Mode(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
#endif
{
#if (MCU_SKIP_FUNCTION == STD_ON)
    VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
#endif
    switch ((ClockPtr->Start_Run_Mode) & MCU_SYSTEM_MODE_MASK)
    {
    case (MCU_DRUN_MODE_VALUE) : /* DRUN */
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_DRUN_MC_R, (uint32) ((ClockPtr->Start_Run_Mode) & (~MCU_SYSTEM_MODE_MASK)));
        break;
    case (MCU_RUN0_MODE_VALUE) : /* RUN0 */
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_RUN0_MC_R, (uint32) ((ClockPtr->Start_Run_Mode) & (~MCU_SYSTEM_MODE_MASK)));
        break;
    case (MCU_RUN1_MODE_VALUE) : /* RUN1 */
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_RUN1_MC_R, (uint32) ((ClockPtr->Start_Run_Mode) & (~MCU_SYSTEM_MODE_MASK)));
        break;
    case (MCU_RUN2_MODE_VALUE) : /* RUN2 */
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_RUN2_MC_R, (uint32) ((ClockPtr->Start_Run_Mode) & (~MCU_SYSTEM_MODE_MASK)));
        break;
    case (MCU_RUN3_MODE_VALUE) : /* RUN3 */
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_RUN3_MC_R, (uint32) ((ClockPtr->Start_Run_Mode) & (~MCU_SYSTEM_MODE_MASK)));
        break;
    case (MCU_SAFE_MODE_VALUE) : /* SAFE */
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_SAFE_MC_R, (uint32) ((ClockPtr->Start_Run_Mode) & (~MCU_SYSTEM_MODE_MASK)));
        break;
    default:
    {
        /* This case should never occurs. */
        Cer_ReportError( (uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_CHANGE_MODE_ID, (uint8)MCU_E_WRONG_MODE);
        /* Compiler_Warning: Statement break is unreachable because of the infinite while loop found in
           the Cer_ReportError function. The CER is meant to handle those unexpected runtime situations
           that the existing DEM and DET subsystems cannot cope with.
        */
        break;
    }
    }

    if (ClockPtr->McuSystemClockFrequency < Mcu_CpySystemClockFrequency)
    {
#if (MCU_SKIP_FUNCTION == STD_ON)
        Status = Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode);
        if ((Std_ReturnType) E_NOT_OK == Status)
        {
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_5 Required Rule 14.7 Return statement before end of function. */
            return (Std_ReturnType) E_NOT_OK;
        }
#else
        Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode);
#endif
    }
#if (MCU_FLASH_CONFIGURATION_USED == STD_ON)
    /*enter critical region*/
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01();
    Mcu_Flash_Configure((uint32) (ClockPtr->FLASH_PFCR0), (uint32) (ClockPtr->FLASH_PFCR1));
    /*exit critical region*/
    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01();
#endif
    if (ClockPtr->McuSystemClockFrequency >= Mcu_CpySystemClockFrequency)
    {
#if (MCU_SKIP_FUNCTION == STD_ON)
        Status = Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode);
        if ((Std_ReturnType) E_NOT_OK == Status)
        {
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_5 Required Rule 14.7 Return statement before end of function. */
            return (Std_ReturnType) E_NOT_OK;
        }
#else
        Mcu_Apply_Mode (Mcu_TimeOut, ClockPtr->Start_Run_Mode);
#endif
    }

    /* Save system clock frequency */
    Mcu_CpySystemClockFrequency = ClockPtr->McuSystemClockFrequency;
#if (MCU_SKIP_FUNCTION == STD_ON)
    return (Std_ReturnType) Status;
#endif
}

/*================================================================================================*/
/**
* @brief          This function checks if the mode and system clock are configured accordingly.
* @details        The mode and system clock are checked against the ME status. In case it takes
*                 too long to obtain the desired configuration, it returns and reports
*                 MCU_TIMEOUT_TRANSITION to DEM.
*
* @param[in]      Mcu_TimeOut Mcu timeout
*
* @param[in]      ClockPtr    Pointer to clock configuration structure
*
* @return         void
*
* @implements     DMCU05026
*/
#if (MCU_SKIP_FUNCTION == STD_ON)
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(Std_ReturnType, AUTOMATIC) Mcu_Check_Init(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
#else
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, AUTOMATIC) Mcu_Check_Init(VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr)
#endif
{
    VAR(uint32, AUTOMATIC) Loop = 0UL;
#if (MCU_SKIP_FUNCTION == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
#endif
    do
    {
        if (Loop > Mcu_TimeOut)
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_TimeoutTransitionCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_TimeoutTransitionCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
#if (MCU_SKIP_FUNCTION == STD_ON)
            Status = (Std_ReturnType)E_NOT_OK;
#endif
            break;
        }
        Loop++;
    }
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* To confirm the Mode */
    while ((REG_READ32(MC_ME_GS_R) & (MCU_SYSTEM_MODE_MASK)) != ((ClockPtr->Start_Run_Mode) & MCU_SYSTEM_MODE_MASK));
    if (Loop <= Mcu_TimeOut)
    {
        Loop = 0UL;

        do
        {
            if (Loop > Mcu_TimeOut)
            {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                if ((uint32)STD_ON == Mcu_Cfg_Ptr->Mcu_E_TimeoutTransitionCfg.state)
                {
                    Dem_ReportErrorStatus((Dem_EventIdType) Mcu_Cfg_Ptr->Mcu_E_TimeoutTransitionCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif
#if (MCU_SKIP_FUNCTION == STD_ON)
            Status = (Std_ReturnType)E_NOT_OK;
#endif
                break;
            }
            Loop++;
        }
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        /* To confirm the Clock */
        while ((REG_READ32(MC_ME_GS_R) & (MCU_SYSTEM_CLK_MASK)) != ((ClockPtr->Start_Run_Mode) & MCU_SYSTEM_CLK_MASK));
    }
#if (MCU_SKIP_FUNCTION == STD_ON)
    return (Std_ReturnType) Status;
#endif
}

/*================================================================================================*/
/**
* @brief          This function changes the low power ME mode.
* @details        The low power mode is changed.
*
* @param[in]      ClockPtr       Pointer to clock configuration structure
* @param[in]      ModePtr        Pointer to mode configuration structure
* @param[out]     pMcuModeVal    The selected mode.
*
* @return         void
*
* @implements    DMCU05152
*/
FUNC(void, AUTOMATIC) Mcu_Change_LowPower_Mode(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) ClockPtr, P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr)
{
    VAR(uint32, AUTOMATIC) CpyStartRunMode = ClockPtr->Start_Run_Mode;

    switch (ModePtr->Mode)
    {

    case (MCU_HALT_MODE) : /* HALT */
    {
        {
            if( (ModePtr->LP_Param & MCU_RC_GENERAL_FLAG) != MCU_RC_GENERAL_FLAG )
            {
                /* Move sysclk before switching off RC to avoid an invalid config interrupt */
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_HALT_MC_R, (uint32) ((((CpyStartRunMode) & (~MCU_SYSTEM_MODE_MASK)) | ModePtr->LP_Param) | MCU_RC_GENERAL_FLAG));
            }
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_HALT_MC_R, (uint32) ((((CpyStartRunMode) & (~MCU_SYSTEM_MODE_MASK)) | ModePtr->LP_Param)));
        }
    }
    break;

    case (MCU_STOP_MODE) : /* STOP */
    {
        {
            if( (ModePtr->LP_Param & MCU_RC_GENERAL_FLAG) != MCU_RC_GENERAL_FLAG )
            {
                /* Move sysclk before switching off RC to avoid an invalid config interrupt */
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_STOP_MC_R, (uint32) ((((CpyStartRunMode) & (MCU_SYSTEM_MODE_MASK)) | ModePtr->LP_Param)));
            }
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_STOP_MC_R, (uint32) ((((CpyStartRunMode) & (MCU_SYSTEM_MODE_MASK)) | ModePtr->LP_Param)));
        }
    }
    break;
    case (MCU_STANDBY_MODE) : /* STBY */
    {
        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(MC_ME_STBY_MC_R, (uint32) ((CpyStartRunMode) & (MCU_SYSTEM_CLK_MASK)));
    }
    break;
    default:
    {
        /* This case should never occurs. */
        Cer_ReportError( (uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_CHANGE_LOWPOWER_ID, (uint8)MCU_E_WRONG_MODE);
        /* Compiler_Warning: Statement break is unreachable because of the infinite while loop found in
           the Cer_ReportError function. The CER is meant to handle those unexpected runtime situations
           that the existing DEM and DET subsystems cannot cope with.
        */
        break;
    }
    }
}

/*================================================================================================*/
/**
* @brief          This function performs a transition to a low power mode.
* @details        This function is used for entering a low power mode (HALT, STOP or STANDBY).
*                 If configured, the wait instruction is called and after waking up, the
*                 microcontroller resumes execution after the wait instruction.
*
* @param[in]      Mcu_TimeOut Mcu timeout
* @param[in]      ModePtr     Pointer to mode configuration structure
*
* @return         void
*
* @implements     DMCU05027
*/
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
FUNC (void, MCU_CODE) Mcu_Apply_LowPower_Mode (VAR(uint32, AUTOMATIC) Mcu_TimeOut, P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr)
#else
FUNC (void, MCU_CODE) Mcu_Apply_LowPower_Mode (P2CONST (Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) ModePtr)
#endif
{
    VAR(uint32, AUTOMATIC) StatusReg = MCU_ZERO_VALUE;
/* @errata ERR_IPV_MC_0015 */
#ifdef  ERR_IPV_MC_0015
    #if (ERR_IPV_MC_0015 == STD_ON)
     /* Main VREG not disabled during STOP0 or HALT0 mode if RUN[0..3] mode  selects FXOSC to be
        running and target mode selects FXOSC as system clock */
    VAR(uint32, AUTOMATIC) ModeConfigRegTmp= MCU_ZERO_VALUE;
         #endif
#endif
/* @errata ERR_IPV_MC_0017 */
#ifdef ERR_IPV_MC_0017
   #if (ERR_IPV_MC_0017 == STD_ON)
       VAR (Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType) E_OK;
   #endif
#endif
#if (MCU_LP_TRANSITION_CHECK == STD_ON)
    VAR(uint32, AUTOMATIC) Loop = 0UL;
#endif
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    /* Clear mode transition complete status */
    REG_WRITE32(MC_ME_IS_R, ME_IS_MTC_SET);
    /* Current status */
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    StatusReg = ((REG_READ32(MC_ME_GS_R) & MCU_SYSTEM_MODE_MASK) >> MCU_SHIFT_TWENTY_EIGHT);
    switch (ModePtr->Mode)
    {
    case (MCU_HALT_MODE) : /* HALT */
            /* Check for Invalid Transitions */
            if ((((uint16)StatusReg) >= MCU_RUN0_MODE) && (((uint16)StatusReg) <= MCU_RUN3_MODE))
            {
                VAR (uint32, AUTOMATIC) temp_reg = (uint32) ModePtr->LP_Param;
            
#ifdef ERR_IPV_MC_0046
#if (ERR_IPV_MC_0046 == STD_ON)
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)StatusReg) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)StatusReg) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
#if ((MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON))
    do
    {
        if (Loop > Mcu_TimeOut)
        {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            /* if this is the case, an interrupt arrived just before entering low power mode */
            Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_INVALIDE_MODE);
#endif
            break;
        }
        Loop++;
    }
    /* Check mode transition complete status */
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    while ((REG_READ32(MC_ME_GS_R) & ME_GS_MODE_TRANSITION) == ME_GS_MODE_TRANSITION);
#endif /* (MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
#endif /* ERR_IPV_MC_0046 == STD_ON */
#endif /* ERR_IPV_MC_0046 */

                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_HALT_MC_R, temp_reg);
/* @errata ERR_IPV_MC_0015 */
#ifdef  ERR_IPV_MC_0015
         #if (ERR_IPV_MC_0015 == STD_ON)
                 /* Main VREG not disabled during STOP0 or HALT0 mode if RUN[0..3] mode
                  selects FXOSC to be running and target mode selects FXOSC
                  as system clock */
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                if (((temp_reg & ME_MAIN_VOLATAGE_ON) != ME_MAIN_VOLATAGE_ON) &&
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                /*
                 * @violates @ref Mcu_MC_Modes_lld_c_REF_8 The right-hand operand
                 */
                (ME_GS_XOSC_STATUS == (REG_READ32(MC_ME_GS_R) & ME_GS_XOSC_STATUS) ) &&
                ((((uint32)ME_SYSCLK_SWITCH_XOSC) == (temp_reg & ((uint32)ME_SYSCLK_SWITCH_XOSC))) ||
                ((((uint32)ME_SYSCLK_SWITCH_DIV_XOSC) == (temp_reg & ((uint32)ME_SYSCLK_SWITCH_DIV_XOSC))))))
                {
                    if (MCU_RUN0_MODE == ((uint16)StatusReg) )
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN0_MC_R);
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN0_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    else if (MCU_RUN1_MODE == ((uint16)StatusReg) )
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN1_MC_R);
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN1_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    else if (MCU_RUN2_MODE == ((uint16)StatusReg) )
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN2_MC_R);
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN2_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    else
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN3_MC_R);
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN3_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    /*
                     * @violates @ref Mcu_MC_Modes_lld_c_REF_9 If a function returns error information.
                     */
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
                    /* @violates @ref Mcu_MC_Modes_lld_c_REF_9 MISRA 2004 Required Rule 16.10, Treat if function returns error information.*/         
                    Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
#endif
                    /* Clear mode transition complete status */
                    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_WRITE32(MC_ME_IS_R, ME_IS_MTC_SET);
                    Mcu_Apply_Run_Mode(ModeConfigRegTmp, StatusReg);
                }
         #endif
#endif
                Mcu_Apply_Run_Mode(ModePtr->RUN_Param, StatusReg);
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                if (MCU_ZERO_VALUE == (REG_READ32(MC_ME_GS_R) & (MCU_ONE_VALUE << MCU_SHIFT_TWENTY_SEVEN)) )
                {
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
                   #if (MCU_DEV_ERROR_DETECT == STD_ON)
                    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    if (((uint32) REG_READ32(MC_ME_ME_R) & ME_ME_HALT_ENABLE) != ME_ME_HALT_ENABLE)
                    {
                       Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                       (uint8) MCU_APPLY_MODE_ID, (uint8) MCU_E_MODE_NOT_ENABLED);
                    }
                    else
                    {
                   #endif
/* @errata ERR_IPV_MC_0017 */
#ifdef ERR_IPV_MC_0017
    #if (ERR_IPV_MC_0017 == STD_ON)
                        if ((ME_MODE_CFAON_MASK != ((ModePtr->LP_Param) & ME_MODE_CFAON_MASK)))
                        {
                            /* enter critical region*/
                            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_03();
                            if (MCU_RUN0_MODE == ((uint16)StatusReg) )
                            {
                                Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN0_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN1_MODE == ((uint16)StatusReg))
                            {
                               Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN1_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN2_MODE == ((uint16)StatusReg))
                            {
                                Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN2_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN3_MODE == ((uint16)StatusReg))
                            {
                               Status =  Mcu_Apply_Mode_from_Ram (MC_ME_RUN3_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else
                            {
                            /*
                             * @violates @ref Mcu_MC_Modes_lld_c_REF_7 All if ... else if constructs.
                            */
                            }
                            /* exit critical region*/
                            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_03();
                        }
                        else
                        {
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_HALT_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_HALT_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
                        }
                        if (Status != (Std_ReturnType) E_OK)
                        {
        #if (MCU_DEV_ERROR_DETECT == STD_ON)
                        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_HALT_INVALID_TRANSITIONS);
        #endif
                        }
    #endif /* end of #if (ERR_IPV_MC_0017 == STD_ON) */
#else

                       /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                       REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_HALT_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                       /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                       REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_HALT_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
#endif /* end of #ifdef ERR_IPV_MC_0017 */
                    #if (MCU_DEV_ERROR_DETECT == STD_ON)
                    } /* end of if (((uint32) REG_READ32(MC_ME_ME_R) & ME_ME_HALT_ENABLE) != ME_ME_HALT_ENABLE) */
                    #endif
#endif /* end of #if (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
                }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
                else
                {
                    Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_HALT_INVALID_TRANSITIONS);
                }
#endif
            }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_HALT_INVALID_TRANSITIONS);
            }
#endif
        break;
    case (MCU_STOP_MODE) : /* STOP */
                /* Check for Invalid Transitions */
            if ((((uint16)StatusReg) >= MCU_RUN0_MODE) && (((uint16)StatusReg) <= MCU_RUN3_MODE))
            {
                VAR (uint32, AUTOMATIC) temp_reg = (uint32) ModePtr->LP_Param;

#ifdef ERR_IPV_MC_0046
#if (ERR_IPV_MC_0046 == STD_ON)
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)StatusReg) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)StatusReg) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
#if ((MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON))
    do
    {
        if (Loop > Mcu_TimeOut)
        {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            /* if this is the case, an interrupt arrived just before entering low power mode */
            Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_INVALIDE_MODE);
#endif
            break;
        }
        Loop++;
    }
    /* Check mode transition complete status */
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    while ((REG_READ32(MC_ME_GS_R) & ME_GS_MODE_TRANSITION) == ME_GS_MODE_TRANSITION);
#endif /* (MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
#endif /* ERR_IPV_MC_0046 == STD_ON */
#endif /* ERR_IPV_MC_0046 */

                /* Check if we have to disable the sysclk*/
                if (ModePtr->DisableSystemClock)
                {
                    temp_reg |= MCU_SYSTEM_CLK_MASK;
                }

                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_STOP_MC_R, temp_reg);
/* @errata ERR_IPV_MC_0015 */
#ifdef  ERR_IPV_MC_0015
         #if (ERR_IPV_MC_0015 == STD_ON)
                 /* Main VREG not disabled during STOP0 or HALT0 mode if RUN[0..3] mode
                  selects FXOSC to be running and target mode selects FXOSC
                  as system clock */
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                if (((temp_reg & ME_MAIN_VOLATAGE_ON) != ME_MAIN_VOLATAGE_ON) &&
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                /*
                 * @violates @ref Mcu_MC_Modes_lld_c_REF_8 The right-hand operand
                 */
                (ME_GS_XOSC_STATUS == (REG_READ32(MC_ME_GS_R) & ME_GS_XOSC_STATUS)) &&
                ((((uint32)ME_SYSCLK_SWITCH_XOSC) == (temp_reg & ((uint32)ME_SYSCLK_SWITCH_XOSC))) ||
                ((((uint32)ME_SYSCLK_SWITCH_DIV_XOSC) == (temp_reg & ((uint32)ME_SYSCLK_SWITCH_DIV_XOSC))))))
                {
                    if (MCU_RUN0_MODE == ((uint16)StatusReg))
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN0_MC_R);
                       /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN0_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    else if (MCU_RUN1_MODE == ((uint16)StatusReg))
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN1_MC_R);
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN1_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    else if (MCU_RUN2_MODE == ((uint16)StatusReg))
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN2_MC_R);
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN2_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    else
                    {
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        ModeConfigRegTmp = REG_READ32(MC_ME_RUN3_MC_R);
                        /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                        REG_WRITE32(MC_ME_RUN3_MC_R, (uint32)(ModeConfigRegTmp&RUN_MODE_CONFIG));
                    }
                    /*
                     * @violates @ref Mcu_MC_Modes_lld_c_REF_9 If a function returns error information.
                     */
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
                    /* @violates @ref Mcu_MC_Modes_lld_c_REF_9 MISRA 2004 Required Rule 16.10, Treat if function returns error information.*/                              
                    Mcu_Apply_Mode (Mcu_TimeOut, MCU_32_BIT_MASK);
#endif
                    /* Clear mode transition complete status */
                    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    REG_WRITE32(MC_ME_IS_R, ME_IS_MTC_SET);
                    Mcu_Apply_Run_Mode(ModeConfigRegTmp, StatusReg);
                }
         #endif
#endif
                Mcu_Apply_Run_Mode(ModePtr->RUN_Param, StatusReg);
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                if (MCU_ZERO_VALUE == (REG_READ32(MC_ME_GS_R) & (MCU_ONE_VALUE << MCU_SHIFT_TWENTY_SEVEN)) )
                {
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
                    #if (MCU_DEV_ERROR_DETECT == STD_ON)
                    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    if (((uint32) REG_READ32(MC_ME_ME_R) & ME_ME_STOP_ENABLE) != ME_ME_STOP_ENABLE)
                    {
                       Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                       (uint8) MCU_APPLY_MODE_ID, (uint8) MCU_E_MODE_NOT_ENABLED);
                    }
                    else
                    {
                    #endif
/* @errata ERR_IPV_MC_0017 */
#ifdef ERR_IPV_MC_0017
    #if (ERR_IPV_MC_0017 == STD_ON)
                        if ((ME_MODE_CFAON_MASK != ((ModePtr->LP_Param) & ME_MODE_CFAON_MASK)))
                        {
                            /* enter critical region*/
                            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_03();
                            if (MCU_RUN0_MODE == ((uint16)StatusReg) )
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN0_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN1_MODE == ((uint16)StatusReg))
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN1_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN2_MODE == ((uint16)StatusReg))
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN2_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN3_MODE == ((uint16)StatusReg))
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN3_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else
                            {
                            /*
                             * @violates @ref Mcu_MC_Modes_lld_c_REF_7 All if ... else if constructs.
                             */
                            }
                            /* exit critical region*/
                            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_03();
                        }
                        else
                        {
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STOP_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STOP_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
                        }
                        if (Status != (Std_ReturnType) E_OK)
                        {
        #if (MCU_DEV_ERROR_DETECT == STD_ON)
                        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_STOP_INVALID_TRANSITIONS);
        #endif
                        }
    #endif /* end of #if (ERR_IPV_MC_0017 == STD_ON) */
#else
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STOP_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STOP_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
#endif /* end of #ifdef ERR_IPV_MC_0017 */
                    #if (MCU_DEV_ERROR_DETECT == STD_ON)
                    } /* end of if (((uint32) REG_READ32(MC_ME_ME_R) & ME_ME_STOP_ENABLE) != ME_ME_STOP_ENABLE) */
                    #endif
#endif /* end of #if (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
                }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
                else
                {
                    Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_STOP_INVALID_TRANSITIONS);
                }
#endif
            }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_STOP_INVALID_TRANSITIONS);
            }
#endif
        break;
    case (MCU_STANDBY_MODE) : /* STBY */
                /* Check for Invalid Transitions */
            if ((((uint16)StatusReg) >= MCU_DRUN_MODE) && (((uint16)StatusReg) <= MCU_RUN3_MODE))
            {
#ifdef ERR_IPV_MC_0046
#if (ERR_IPV_MC_0046 == STD_ON)
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)StatusReg) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)StatusReg) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
#if ((MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON))
    do
    {
        if (Loop > Mcu_TimeOut)
        {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            /* if this is the case, an interrupt arrived just before entering low power mode */
            Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_INVALIDE_MODE);
#endif
            break;
        }
        Loop++;
    }
    /* Check mode transition complete status */
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    while ((REG_READ32(MC_ME_GS_R) & ME_GS_MODE_TRANSITION) == ME_GS_MODE_TRANSITION);
#endif /* (MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
#endif /* ERR_IPV_MC_0046 == STD_ON */
#endif /* ERR_IPV_MC_0046 */
                
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE16(MC_RGM_STDBY_R, (ModePtr->StbyMode));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_STBY_MC_R, (uint32) (ModePtr->LP_Param));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                if (MCU_ZERO_VALUE == (REG_READ32(MC_ME_GS_R) & (MCU_ONE_VALUE << MCU_SHIFT_TWENTY_SEVEN)) )
                {
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
                    #if (MCU_DEV_ERROR_DETECT == STD_ON)
                    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                    if (((uint32) REG_READ32(MC_ME_ME_R) & ME_ME_STANDBY_ENABLE) != ME_ME_STANDBY_ENABLE)
                    {
                       Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                       (uint8) MCU_APPLY_MODE_ID, (uint8) MCU_E_MODE_NOT_ENABLED);
                    }
                    else
                    {
                   #endif
/* @errata ERR_IPV_MC_0017 */
#ifdef ERR_IPV_MC_0017
    #if (ERR_IPV_MC_0017 == STD_ON)
                        if ((ME_MODE_CFAON_MASK != ((ModePtr->LP_Param) & ME_MODE_CFAON_MASK)))
                        {
                            /* enter critical region*/
                            SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_03();
                            if (MCU_RUN0_MODE == ((uint16)StatusReg) )
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN0_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN1_MODE == ((uint16)StatusReg))
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN1_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN2_MODE == ((uint16)StatusReg))
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN2_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else if (MCU_RUN3_MODE == ((uint16)StatusReg))
                            {
                                 Status = Mcu_Apply_Mode_from_Ram (MC_ME_RUN3_MC_R, ModePtr, StatusReg, Mcu_TimeOut);
                            }
                            else
                            {
                            /*
                             * @violates @ref Mcu_MC_Modes_lld_c_REF_7 All if ... else if constructs.
                             */
                            }
                            /* exit critical region*/
                            SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_03();
                        }
                        else
                        {
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STANDBY_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STANDBY_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
                        }
                        if (Status != (Std_ReturnType) E_OK)
                        {
        #if (MCU_DEV_ERROR_DETECT == STD_ON)
                        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_STANDBY_INVALID_TRANSITIONS);
        #endif
                        }
    #endif /* end of #if (ERR_IPV_MC_0017 == STD_ON) */
#else
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STANDBY_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_STANDBY_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
#endif /* end of #ifdef ERR_IPV_MC_0017 */
                    #if (MCU_DEV_ERROR_DETECT == STD_ON)
                    } /* end of if (((uint32) REG_READ32(MC_ME_ME_R) & ME_ME_STANDBY_ENABLE) != ME_ME_STANDBY_ENABLE) */
                    #endif
#endif /* end of #if (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
                }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
                else
                {
                    Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_STANDBY_INVALID_TRANSITIONS);
                }
#endif
            }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_STANDBY_INVALID_TRANSITIONS);
            }
#endif
        break;
    case (MCU_DRUN_MODE) : /* DRUN */
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_DRUN_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_DRUN_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
        break;
    case (MCU_RUN0_MODE) : /* RUN0 */
            if( ((uint16)StatusReg) != MCU_SAFE_MODE )
            {
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN0_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN0_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
            }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_RUN0_INVALID_TRANSITIONS);
            }
#endif
        break;
    case (MCU_RUN1_MODE) : /* RUN1 */
            if( ((uint16)StatusReg) != MCU_SAFE_MODE )
            {
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN1_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN1_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
            }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            else
            {

                Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_RUN1_INVALID_TRANSITIONS);
            }
#endif
        break;
    case (MCU_RUN2_MODE) : /* RUN2 */
            if( ((uint16)StatusReg) != MCU_SAFE_MODE )
            {
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN2_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN2_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
            }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_RUN2_INVALID_TRANSITIONS);
            }
#endif
        break;
    case (MCU_RUN3_MODE) : /* RUN3 */
            if( ((uint16)StatusReg) != MCU_SAFE_MODE )
            {
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN3_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
                /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
                REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_RUN3_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
            }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_RUN3_INVALID_TRANSITIONS);
            }
#endif
        break;
    case (MCU_SAFE_MODE) : /* SAFE */
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_SAFE_MC_R, ((uint32)ModePtr->LP_Param));
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_SAFE_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_ONE));
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_MCTL_R, ((((uint32)MCU_SAFE_MODE) << MCU_SHIFT_TWENTY_EIGHT) | MCU_SOFT_CONTROL_KEY_TWO));
        break;

    default:
    {
        /* This case should never occurs. */
        Cer_ReportError( (uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_APPLY_LOWPOWER_ID, (uint8)MCU_E_WRONG_MODE);
        /* Compiler_Warning: Statement break is unreachable because of the infinite while loop found in
           the Cer_ReportError function. The CER is meant to handle those unexpected runtime situations
           that the existing DEM and DET subsystems cannot cope with.
        */
        break;
    }
    }

#if ((MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON))
    do
    {
        if (Loop > Mcu_TimeOut)
        {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            /* if this is the case, an interrupt arrived just before entering low power mode */
            Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_INVALIDE_MODE);
#endif
            break;
        }
        Loop++;
    }
    /* Check mode transition complete status */
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    while ((REG_READ32(MC_ME_GS_R) & ME_GS_MODE_TRANSITION) == ME_GS_MODE_TRANSITION);
#endif
/*Perform a loop to ensure that Modem Voltage Regulator is stable and ready to be used in case that MVR can be switch off during halt/stop mode*/
#if ((MCU_LP_TRANSITION_CHECK == STD_ON) && (MCU_ENTER_LOW_POWER_MODE == STD_ON))
    do
    {
        if (Loop > Mcu_TimeOut)
        {
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            /* if this is the case, an interrupt arrived just before entering low power mode */
            Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, (uint8) MCU_E_INVALIDE_MODE);
#endif
            break;
        }
        Loop++;
    }
     /* Check MVR is ready to be used after transition */
    /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    while ((REG_READ32(MC_ME_GS_R) & ((uint32) (ME_GS_VOLTAGE_REG))) != ((uint32) (ME_GS_VOLTAGE_REG)));
#endif

}

/*================================================================================================*/
/**
* @brief          This function modifies clock settings corresponding to the run mode before that
*                 was running before low power entry.
* @details        This function modifies clock settings for a run mode but does not apply them by
*                 executing a transition, they will be automatically applied by hardware at low
*                 power exit. This is useful in scenarios where the clocks settings that were in
*                 the run mode running before low power entry are not convenient when exiting low power state.
*
* @param[in]      RUN_Param   Represents the clock settings that will be applied
*
* @param[out]     StatusReg   Represents the current mode status
*
* @return         void
*
* @implements     DMCU05028
*/
STATIC FUNC(void, MCU_CODE) Mcu_Apply_Run_Mode(VAR(uint32, AUTOMATIC) RUN_Param, VAR(uint32, AUTOMATIC)  StatusReg)
{
if (RUN_Param != MCU_32_BIT_MASK)
{
    switch (StatusReg)
    {
        case (MCU_RUN0_MODE) : /* RUN0 */
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN0_MC_R, (uint32) RUN_Param | ((uint32) ((uint32) (MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN0_MC_R))));
            break;
        case (MCU_RUN1_MODE) : /* RUN1 */
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN1_MC_R, (uint32) RUN_Param | ((uint32) ((uint32) (MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN1_MC_R))));
            break;
        case (MCU_RUN2_MODE) : /* RUN2 */
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN2_MC_R, (uint32) RUN_Param | ((uint32) ((uint32) (MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN2_MC_R))));
            break;
        case (MCU_RUN3_MODE) : /* RUN3 */
            /* @violates @ref Mcu_MC_Modes_lld_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
            REG_WRITE32(MC_ME_RUN3_MC_R, (uint32) RUN_Param | ((uint32) ((uint32) (MCU_SYSTEM_CLK_MASK) & (uint32) REG_READ32(MC_ME_RUN3_MC_R))));
            break;
        default:
        {
            /* This case should never occurs. */
            Cer_ReportError( (uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_APPLY_RUNMODE_ID, (uint8)MCU_E_WRONG_MODE);
            /* Compiler_Warning: Statement break is unreachable because of the infinite while loop found in
               the Cer_ReportError function. The CER is meant to handle those unexpected runtime situations
               that the existing DEM and DET subsystems cannot cope with.
            */
            break;
        }
    }
}
}

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_MC_Modes_lld_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*                and comments before '#include' MemMap.h
* @violates @ref Mcu_MC_Modes_lld_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
