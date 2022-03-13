/**
*   @file    Mcu.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - High level part of MCU driver.
*   @details This file contains the functions defined by AutoSAR.
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
* @section Mcu_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_C_REF_3
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel parameters,
* the indexing of the pointer is taken care and hence the unintended memory location will not
* be accessed
*
* @section Mcu_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR
* specifications although it exceeds the max length of 31 characters
*
* @section Mcu_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, API could not be made static.
*
* @section Mcu_C_REF_6
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_C_REF_7
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be permitted.
* This violation is due to range error check.
*
* @section Mcu_C_REF_8 
* Violates MISRA 2004 Required Rule 14.10,All if ... else if constructs shall be terminated with an else clause.
* This violation is due to pre-compilation macro conditions.
*
* @section Mcu_C_REF_9
* Violates MISRA 2004 Required Rule 14.3,
* Before preprocessing, a null statement shall only occur on a line by itself.
* This violation is platform dependent as Mcu_LLD_DistributePllClock has null statement .
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @implements     DMCU00005, DMCU00006, DMCU00007 */
#include "Mcu.h"
#include "Mcu_LLD.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* @implements     DMCU00004 */
#include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DMCU03035, DMCU03036, DMCU03037, DMCU03038, DMCU03039, DMCU03040, DMCU03041 */
#define MCU_VENDOR_ID_C                      43
#define MCU_AR_RELEASE_MAJOR_VERSION_C       4
#define MCU_AR_RELEASE_MINOR_VERSION_C       0
/* @violates @ref Mcu_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash */
/*
* @violates @ref Mcu_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_AR_RELEASE_REVISION_VERSION_C    3
#define MCU_SW_MAJOR_VERSION_C               1
#define MCU_SW_MINOR_VERSION_C               0
#define MCU_SW_PATCH_VERSION_C               1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu header file are of the same vendor */
#if (MCU_VENDOR_ID_C != MCU_VENDOR_ID)
    #error "Mcu.c and Mcu.h have different vendor ids"
#endif
/* @implements     DMCU06001 */
/* Check if current file and Mcu header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C    != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C    != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu.c and Mcu.h are different"
#endif
/* Check if current file and Mcu header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu.c and Mcu.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        #if ((MCU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (MCU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcu.c and Det.h are different"
        #endif
    #endif
#endif
/* Check if current file and Mcu_LLD header file are of the same vendor */
#if (MCU_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
    #error "Mcu.c and Mcu_LLD.h have different vendor ids"
#endif
/* Check if current file and Mcu_LLD header file are of the same version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu.c and Mcu_LLD.h are different"
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
* @violates @ref Mcu_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/**
* @brief   Pointer to initialization structure.
*
* @implements   DMCU03053
*/
P2CONST (Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_Cfg_Ptr = NULL_PTR;
/*
* @violates @ref Mcu_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Mcu_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
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
/* @violates @ref Mcu_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief    MCU driver initialization function.
* @details  This routine initializes the MCU Driver.
*           The intention of this function is to make the configuration setting
*           for power down, clock and ram sections visible within the MCU Driver.
*
* @param[in]   ConfigPtr      Pointer to MCU configuration structure.
*
* @api
*
* @implements     DMCU03055
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) Mcu_Init (P2CONST (Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr)
{
    Mcu_Cfg_Ptr = NULL_PTR;
#ifndef MCU_PRECOMPILE_SUPPORT
/* @implements DMCU06030 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == ConfigPtr)
    {
        /* @implements DMCU06010 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
        (uint8) MCU_INIT_ID, (uint8) MCU_E_PARAM_CONFIG);
    }
    else
    {
#endif
#endif
#ifdef MCU_PRECOMPILE_SUPPORT
        if (NULL_PTR == ConfigPtr)
        {
            Mcu_Cfg_Ptr = &MCU_INIT_CONFIG_PC;
        }
        else
#endif
        {
            /* Copy pointer to config structure */
            Mcu_Cfg_Ptr = ConfigPtr;
        }
        Mcu_LLD_Init (Mcu_Cfg_Ptr->McuLLD_Config);
#ifndef MCU_PRECOMPILE_SUPPORT
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
#endif
#endif
}
/*================================================================================================*/
/**
* @brief           MCU driver initialization of ram sections.
* @details         Function intializes the ram section selected by RamSection parameter.
 *                 The section base address, size and value to be written are provided
 *                 from the configuration structure.
*
* @param[in]       RamSection  Index of ram section from config structure to be initialized.
*
* @return          Std_ReturnType
* @retval E_OK     Command has been accepted.
* @retval E_NOT_OK Command has not been accepted.
*
* @api
*
* @pre            Should be called only after the MCU module has been initialized using the
*                 function Mcu_Init.
*
* @implements     DMCU03056
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (Std_ReturnType, MCU_CODE) Mcu_InitRamSection (VAR (Mcu_RamSectionType, AUTOMATIC) \
      RamSection)
{
    VAR (Std_ReturnType, AUTOMATIC) status = (Std_ReturnType)E_OK;
    VAR (uint32, AUTOMATIC) i;
    P2CONST (Mcu_RamConfigType, AUTOMATIC, MCU_APPL_CONST) pRam;
/* @implements DMCU06023 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06013 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
       (uint8) MCU_INITRAMSECTION_ID, (uint8) MCU_E_UNINIT);
       status = (Std_ReturnType)E_NOT_OK;
    }
    else if (RamSection >= Mcu_Cfg_Ptr->noRamSections)
    {
        /* Error: function parameter out of range */
        /* @implements DMCU06014 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_INITRAMSECTION_ID, (uint8) MCU_E_PARAM_RAMSECTION);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == Mcu_Cfg_Ptr->Mcu_RamConfig)
    {
        /* Error: pointer to ram section in config structure is NULL */
        /* @implements DMCU06015 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                  (uint8) MCU_INITRAMSECTION_ID, (uint8) MCU_E_PARAM_RAMSECTION);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
       /* @violates @ref Mcu_C_REF_3 MISRA 2004 Advisory Rules 17.4 Array indexing
           shall be the only allowed form of pointer* arithmetic*/
       pRam = &Mcu_Cfg_Ptr->Mcu_RamConfig[RamSection];

       /* init ram section, 4 bytes per one pass through the loop */
       for (i = 0UL; i < ( (uint32) (pRam->RamSize) / (uint32) 4UL); i++)
       {
           /* @violates @ref Mcu_C_REF_3 MISRA 2004 Advisory Rules 17.4 Array indexing
               shall be the only allowed form of pointer* arithmetic*/
           (pRam->RamBaseAddr) [i] = pRam->RamDefaultValue;
       }
       for (i = 0UL; i < ( (uint32) (pRam->RamSize) / (uint32) 4UL); i++)
       {
           /* @violates @ref Mcu_C_REF_3 MISRA 2004 Advisory Rules 17.4 Array indexing
               shall be the only allowed form of pointer* arithmetic*/
           if ( (pRam->RamBaseAddr) [i] != pRam->RamDefaultValue)
           {
               status = (Std_ReturnType)E_NOT_OK;
               break;
           }
       }
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    return status;
}

#if (MCU_INIT_CLOCK == TRUE) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief             MCU driver clock initialization function.
* @details           This function intializes the PLL and MCU specific clock options.
*                    The clock setting is provided from the configuration structure.
*
* @param[in]         ClockSetting  Index of clock setting from config structure to be
*
* @return            Std_ReturnType.
* @retval E_OK       Command has been accepted.
* @retval E_NOT_OK   Command has not been accepted.
*
* @api
*
* @pre     Function requires an execution of @p Mcu_Init() before it can be
*          used, otherwise it reports error to @p DET and returns @p E_NOT_OK.
*
* @implements     DMCU03057
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (Std_ReturnType, MCU_CODE) Mcu_InitClock (VAR (Mcu_ClockType, AUTOMATIC) ClockSetting)
{
    VAR (Std_ReturnType, AUTOMATIC) status = (Std_ReturnType)E_OK;
/* @implements DMCU06022 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06011 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_INITCLOCK_ID, (uint8) MCU_E_UNINIT);
       status = (Std_ReturnType)E_NOT_OK;
    }
    else if (ClockSetting > Mcu_Cfg_Ptr->noClockSettings)
    {
        /* Error: function parameter out of range */
        /* @implements DMCU06033 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_INITCLOCK_ID, (uint8) MCU_E_PARAM_CLOCK);
        status = (Std_ReturnType)E_NOT_OK;
    }
    /** @violates @ref Mcu_C_REF_7 Boolean operations whose results are invariant shall not be permitted.*/
    else if ((ClockSetting < 1U) || (ClockSetting > 255U))
    {
        /* Error: function parameter out of range */
        /* @implements DMCU06012 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_INITCLOCK_ID, (uint8) MCU_E_PARAM_CLOCK);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == Mcu_Cfg_Ptr->Mcu_ClockConfig)
    {
        /* Error: pointer to clock setting in config structure is NULL */
        /* @implements DMCU06034 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) 0, (uint8) MCU_INITCLOCK_ID, \
                          (uint8) MCU_E_PARAM_CLOCK);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
       /* @violates @ref Mcu_C_REF_3 MISRA 2004 Advisory Rules 17.4 Array indexing
           shall be the only allowed form of pointer* arithmetic*/
       status = Mcu_LLD_InitClock (&Mcu_Cfg_Ptr->Mcu_ClockConfig[ClockSetting-1U], \
                                     Mcu_Cfg_Ptr->clkNotification);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return status;
}
#endif

#if (MCU_NO_PLL == FALSE) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief   This function activates the main PLL as the system clock source.
* @details This function sets the main PLL clock as the system clock and also
*          enables monitoring of the main PLL clock. A clock failure notification
*          is generated when a mismatch with the PLL monitor occurs by
*          enabling the interrupts from the current clock setting.
*
* @api
*
* @pre     Function requires the status of the PLL has been detected as locked
*          by the function @p Mcu_GetPllStatus.
*
* @implements     DMCU03058
*
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) Mcu_DistributePllClock (void)
{
/* @implements DMCU06024 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06004 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_DISTRIBUTEPLLCLOCK_ID, (uint8) MCU_E_UNINIT);
    }
    else
    {
#endif
/* @violates @ref Mcu_C_REF_9 this function has null statement in some platform */
        Mcu_LLD_DistributePllClock ();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

/*================================================================================================*/
/**
* @brief   This function returns the lock status of the PLL.
* @details This function returns the @p MCU_PLL_STATUS_UNDEFINED if this
*          function is called prior to calling of the function Mcu_Init.
*
* @return                           Mcu_PllStatusType.
* @retval MCU_PLL_LOCKED            PLL is locked.
* @retval MCU_PLL_UNLOCKED          PLL is unlocked.
* @retval MCU_PLL_STATUS_UNDEFINED  PLL Status in unknown.
*
* @api
*
* @pre     Function requires an execution of Mcu_Init() and Mcu_InitClock()
*          before it can be used, otherwise it reports error to DET.
* @implements     DMCU03059
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus (void)
{
    /* Set status to MCU_PLL_STATUS_UNDEFINED */
    VAR (Mcu_PllStatusType, AUTOMATIC) status = MCU_PLL_STATUS_UNDEFINED;
/* @implements DMCU06025 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06005 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_GETPLLSTATUS_ID, (uint8) MCU_E_UNINIT);
    }
    else
    {
#endif
#if (MCU_NO_PLL == FALSE)
       status = Mcu_LLD_GetPllStatus();
#endif
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/*
* @violates @ref Mcu_C_REF_8 All if ... else if constructs.
*/
    }
#endif
    return status;
}

/*================================================================================================*/
/**
* @brief   This function returns the reset reason.
* @details This function returns the reset reason from the hardware and return
*          this reason if supported by the hardware.
*
* @return                           One of the possible reset reason defined in Mcu_ResetType.
*
* @see                              Mcu_ResetType
*
* @api
*
* @pre     Function requires an execution of Mcu_Init() and Mcu_InitClock()
*          before it can be used, otherwise it returns @p MCU_RESET_UNDEFINED.
*
* @implements     DMCU03060
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (Mcu_ResetType, MCU_CODE) Mcu_GetResetReason (void)
{
    /* @implements DMCU06040 */
    VAR (Mcu_ResetType, AUTOMATIC) ResetType = MCU_RESET_UNDEFINED;
/* @implements DMCU06028 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06008 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_GETRESETREASON_ID, (uint8) MCU_E_UNINIT);
    }
    else
    {
#endif
        ResetType = Mcu_LLD_GetResetReason();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return ResetType;
}

/*================================================================================================*/
/**
* @brief   This function returns the raw reset value.
* @details This function returns the raw reset value from the hardware register
*          and return this reason if supported by the hardware.
*
* @return  Mcu_RawResetType.
*
* @api
*
* @pre     Function requires an execution of @p Mcu_Init() before it can be
*          used, otherwise it returns an implementation specific vlue which
*          does not correspond to a valid value of the reset status register
*          and is not equal to 0.
*
* @implements     DMCU03061
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue (void)
{
    /* @implements DMCU06041 */
    VAR (Mcu_RawResetType, AUTOMATIC) RawResetValue = MCU_RAW_RESET_DEFAULT;
/* @implements DMCU06027 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06007 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_GETRESETRAWVALUE_ID, (uint8) MCU_E_UNINIT);
    }
    else
    {
#endif
        RawResetValue = Mcu_LLD_GetResetRawValue();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return RawResetValue;
}

/* @implements DMCU06042 */
#if (MCU_PERFORM_RESET_API == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief   This function performs a microcontroller reset.
* @details This function performs the reset type which is configured in the
*          configuration set by using feature of the microcontroller.
*
* @return  void
*
* @api
*
* @pre     Function requires an execution of @p Mcu_Init() before it can be
*          used.
*
* @implements     DMCU03062
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) Mcu_PerformReset (void)
{
/* @implements DMCU06031 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06016 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_PERFORMRESET_ID, (uint8) MCU_E_UNINIT);
    }
    else
    {
#endif
#if (MCU_RESET_CALLOUT_USED == STD_ON)
        /* @implements DMCU06047 */
        MCU_RESET_CALLOUT();
#endif
        Mcu_LLD_PerformReset();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* #if MCU_PERFORM_RESET_API == STD_ON */

/*================================================================================================*/
/**
* @brief   This function sets the MCU power mode.
* @details This function sets MCU power modes configured in the configuration set.
*
* @param[in] McuMode        The parameter represents the MCU mode settings.
*
* @return         void
*
* @api
*
* @pre     Function requires an execution of @p Mcu_Init() before it can be used.
*
* @implements     DMCU03063
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) Mcu_SetMode (VAR (Mcu_ModeType, AUTOMATIC) McuMode)
{
/* @implements DMCU06032 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06017 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_SETMODE_ID, (uint8) MCU_E_UNINIT);
    }
    else if (McuMode > Mcu_Cfg_Ptr->noModes)
    {
        /* Error: McuMode parameter is out of valid range */
        /* @implements DMCU06018 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_SETMODE_ID, (uint8) MCU_E_PARAM_MODE);
    }
    /** @violates @ref Mcu_C_REF_7 Boolean operations whose results are invariant shall not be permitted.*/
    else if ((McuMode < 1U) || (McuMode > 255U))
    {
        /* Error: McuMode parameter is out of valid range */
        /* @implements DMCU06019 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_SETMODE_ID, (uint8) MCU_E_PARAM_MODE);
    }
    else if (NULL_PTR == Mcu_Cfg_Ptr->Mcu_ModeConfig)
    {
        /* Error: pointer to mode in config structure is NULL */
        /* @implements DMCU06020 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, (uint8) MCU_SETMODE_ID, \
                          (uint8) MCU_E_PARAM_MODE);
    }
    else
    {
#endif
        Mcu_LLD_Apply_Mode(McuMode-1U);
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/* @implements DMCU06002 */
#if (MCU_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief   This function returns the version information for the MCU module.
* @details The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*
* @param[in,out] versioninfo   Pointer for storing the version information of this module.
*
*
* @api
*
* @pre            Preconditions as text description. Optional tag.
*
* @implements     DMCU03051, DMCU03064
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) Mcu_GetVersionInfo (P2VAR (Std_VersionInfoType, AUTOMATIC, \
    MCU_APPL_DATA) versioninfo)
{
/* @implements DMCU06029 */
#if( MCU_DEV_ERROR_DETECT == STD_ON )
    if( versioninfo == NULL_PTR )
    {
        /* @implements DMCU06009 */
        Det_ReportError( (uint16) MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETVERSIONINFO_ID, \
                 MCU_E_PARAM_POINTER );
    }
    else
    {
#endif /* MCU_DEV_ERROR_DETECT == STD_ON */
        /* @implements DMCU06043 */
        (versioninfo)->vendorID = (uint16) MCU_VENDOR_ID;
        (versioninfo)->moduleID = (uint8) MCU_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8) MCU_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8) MCU_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8) MCU_SW_PATCH_VERSION;
#if( MCU_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* MCU_DEV_ERROR_DETECT == STD_ON */
}
#endif /* MCU_VERSION_INFO_API == STD_ON */

/* @implements DMCU06003 */
#if (MCU_GET_RAM_STATE_API == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief   This function check the Microcontroller RAM.
* @details This function provides the actual status of the microcontroller Ram after the Reset.
*
* @param[out] Mcu_RamStateType   Ram Status.
*
* @return         Mcu_RamStateType
*
* @retval MCU_RAMSTATE_INVALID     Ram content is not valid or unknown (default).
* @retval MCU_RAMSTATE_VALID       Ram content is valid.
*
* @api
*
* @pre            Function requires an execution of @p Mcu_Init() before it can be used.
*
* @implements     DMCU03052, DMCU03065
*
*/
/*
* @violates @ref Mcu_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (Mcu_RamStateType, MCU_CODE) Mcu_GetRamState (void)
{
    VAR (Mcu_RamStateType, AUTOMATIC) RamStateValue = MCU_RAMSTATE_INVALID;
/* @implements DMCU06026 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_Cfg_Ptr)
    {
        /* Error: Mcu_Init() was not executed */
        /* @implements DMCU06006 */
        Det_ReportError ( (uint16) MCU_MODULE_ID, (uint8) MCU_INSTANCE_ID, \
                          (uint8) MCU_GETRAMSTATE_ID, (uint8) MCU_E_UNINIT);
    }
    else
    {
#endif
        RamStateValue = Mcu_LLD_GetRamState();
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (Mcu_RamStateType)RamStateValue;
}
#endif   /* #if MCU_GET_RAM_STATE_API == STD_ON */

#define MCU_STOP_SEC_CODE
/* @violates @ref Mcu_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
