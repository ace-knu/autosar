/**
*   @file    Wdg_LLD.c
*   @version 1.0.1
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) Registers
*   @details Contains information about the SWT's registers
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF12_ASR_REL_4_0_REV_0003_20161209
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
* @section Wdg_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by 
* other preprocessor directives or comments.
* This mechanism is used to properly place code and variables into their sections.
*
* @section Wdg_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
*
* @section Wdg_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* define name is required by the AUTOSAR specifications although it exceedes the max length of 31 characters.
*
* @section Wdg_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer arithmetic.
* This violation is due to use a vector pointer to access to registers memory.
*
* @section Wdg_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The pointer is used only within scope.
*
* @section Wdg_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
* @section Wdg_LLD_c_REF_7
* Violates MISRA 2004 Required Rule 14.7, A function shall have a single point of exit at the end of function
*
* @section Wdg_LLD_c_REF_8
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Wdg_LLD_c_REF_9 
* Violates MISRA 2004 Advisory Rule 12.1, dependence placed on C's operator precedence; operators: '==' and '||'
*
* @section Wdg_LLD_c_REF_10
* Violates MISRA 2004 Required Rule 12.5, non-primary expression used with logical operator

* @section Wdg_LLD_c_REF_11
* Violates MISRA 2004 Required Rule 14.10, no 'else' at end of 'if ... else if' chain
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Swt_LLD.h"
#include "Wdg_Channel.h"
#include "Wdg_LLD.h"
/*
* @violates @ref Wdg_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "Gpt.h" 
/*
* @violates @ref Wdg_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "Mcal.h"
#include "Wdg_Cbk.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @violates @ref Wdg_LLD_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/

#define WDG_LLD_VENDOR_ID_C                    43
/**
* @violates @ref Wdg_LLD_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
/* @violates @ref Wdg_LLD_c_REF_8 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_LLD_AR_RELEASE_MAJOR_VERSION_C     4
/**
* @violates @ref Wdg_LLD_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
/* @violates @ref Wdg_LLD_c_REF_8 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_LLD_AR_RELEASE_MINOR_VERSION_C     0
/**
* @violates @ref Wdg_LLD_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
/* @violates @ref Wdg_LLD_c_REF_8 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_LLD_AR_RELEASE_REVISION_VERSION_C  3
#define WDG_LLD_SW_MAJOR_VERSION_C             1
#define WDG_LLD_SW_MINOR_VERSION_C             0
#define WDG_LLD_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_LLD header file are of the same vendor */
#if (WDG_LLD_VENDOR_ID_C != WDG_LLD_VENDOR_ID)
    #error "Wdg_LLD.c and Wdg_LLD.h have different vendor ids"
#endif
/* Check if current file and Wdg_LLD header file are of the same Autosar version */
#if ((WDG_LLD_AR_RELEASE_MAJOR_VERSION_C    != WDG_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_MINOR_VERSION_C    != WDG_LLD_AR_RELEASE_MINOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_REVISION_VERSION_C != WDG_LLD_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Wdg_LLD.c and Wdg_LLD.h are different"
#endif
/* Check if current file and Wdg_LLD header file are of the same Software version */
#if ((WDG_LLD_SW_MAJOR_VERSION_C != WDG_LLD_SW_MAJOR_VERSION) || \
     (WDG_LLD_SW_MINOR_VERSION_C != WDG_LLD_SW_MINOR_VERSION) || \
     (WDG_LLD_SW_PATCH_VERSION_C != WDG_LLD_SW_PATCH_VERSION))
     #error "Software Version Numbers of Wdg_LLD.c and Wdg_LLD.h are different"
#endif
/* Check if current file and Wdg_Swt_LLD header file are of the same vendor */
#if (WDG_LLD_VENDOR_ID_C != WDG_SWT_LLD_VENDOR_ID)
    #error "Wdg_LLD.c and Wdg_Swt_LLD.h have different vendor ids"
#endif
/* Check if current file and Wdg_Swt_LLD header file are of the same Autosar version */
#if ((WDG_LLD_AR_RELEASE_MAJOR_VERSION_C    != WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_MINOR_VERSION_C    != WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_REVISION_VERSION_C != WDG_SWT_LLD_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Wdg_LLD.c and Wdg_Swt_LLD.h are different"
#endif
/* Check if current file and Wdg_Swt_LLD header file are of the same Software version */
#if ((WDG_LLD_SW_MAJOR_VERSION_C != WDG_SWT_LLD_SW_MAJOR_VERSION) || \
     (WDG_LLD_SW_MINOR_VERSION_C != WDG_SWT_LLD_SW_MINOR_VERSION) || \
     (WDG_LLD_SW_PATCH_VERSION_C != WDG_SWT_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_LLD.c and Wdg_Swt_LLD.h are different"
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
*                                       LOCAL VARIABLES
==================================================================================================*/
#define WDG_START_SEC_VAR_INIT_32
/*
* @violates @ref Wdg_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"
/**
* @brief          Global variable used for number trigger SWT
*/
STATIC VAR(uint32, WDG_VAR) Wdg_TriggerCount[WDG_NO_OF_INSTANCES] = {0UL};

#define WDG_STOP_SEC_VAR_INIT_32
/*
* @violates @ref Wdg_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
*   @brief   This function initializes the hardware of WDG module.
*   @details Calls the initialization function of the hardware that it is in use
*          (if the wdg is internal calls the SWT initialization function, else
*          the one that is for the type of the external driver)
*          
*   @param[in]      ConfigPtr      Pointer to configuration set.
*                   Wdg_Instance   Wdg Hardware Instance
* 
*   @return Std_ReturnType
*   @retval E_OK        The wdg init has been executed completely and successfully
*   @retval E_NOT_OK    The mode init has encounter errors
* 
*/
FUNC(Std_ReturnType,WDG_CODE) Wdg_LLD_Init(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                                CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR (Std_ReturnType, AUTOMATIC) ret = (uint8)E_NOT_OK;
    VAR(uint32, AUTOMATIC) Wdg_TGpt_us;
    VAR(uint32, AUTOMATIC) Wdg_TO_Swt_us;
    VAR(uint32, AUTOMATIC) Wdg_WN_Swt_us;
    VAR(uint32, AUTOMATIC) diff_us;
    CONST(SWT_HwSettingsType, WDG_CONST) Wdg_Current_Config = \
                                 Wdg_ConfigPtr[Wdg_Instance]->Config_Wdg_Internal[Wdg_Current_Mode[Wdg_Instance]];
#if (WDG_INTERNAL_MODULE == WDG_TYPE)
    ret = Wdg_SWT_Init(ConfigPtr, Wdg_Instance);
    if ((uint8)E_NOT_OK == ret)
    {
        /* @violates @ref Wdg_LLD_c_REF_7 MISRA 2004 Advisory Rule 14.7, A function shall have a single point of exit at the end of function */
        return ret;
    }
    /*
    * @violates @ref Wdg_LLD_c_REF_9 MISRA 2004 Advisory Rule 12.1, dependence placed on C's operator precedence; operators: '==' and '||'
    * @violates @ref Wdg_LLD_c_REF_10 MISRA 2004 Required Rule 12.5, non-primary expression used with logical operator
    */
    if( (Wdg_Current_Mode[Wdg_Instance] == WDGIF_SLOW_MODE) || (Wdg_Current_Mode[Wdg_Instance] == WDGIF_FAST_MODE) )
    {
        Wdg_TO_Swt_us = Wdg_Current_Config.WDG_TO_US;
        Gpt_StopTimer(Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel); 

        if (0x0U  == (Wdg_Current_Config.WDG_CR & (0x00000080U)))
        {
            /* HW window mode disabled */
            Wdg_TGpt_us =  Wdg_TO_Swt_us - (Wdg_TO_Swt_us >> 2);
            Wdg_SWT_Trigger(Wdg_Instance);
        }
        else
        {
            /* HW window mode enabled */
            Wdg_WN_Swt_us = Wdg_Current_Config.WDG_WN_US;
            diff_us = Wdg_TO_Swt_us - Wdg_WN_Swt_us;
            Wdg_TGpt_us =  (diff_us - (diff_us >> 2)) + Wdg_WN_Swt_us;
            /* Here the peripheral should be triggered, but if a trigger is performed an invalid access is raised */  
        }

        Gpt_EnableNotification(Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel);
        Gpt_StartTimer(Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel, Wdg_TGpt_us * Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel_Frequency_MHz);
    }

#ifdef WDG_INITIAL_TIMEOUT 
    /*
    * @violates @ref Wdg_LLD_c_REF_4 MISRA 2004 Required Rule 16.10, If a function returns error
    * information, then that error information shall be tested
    */
    Wdg_LLD_SetTriggerCondition((uint16)WDG_INITIAL_TIMEOUT, Wdg_Instance);
#endif
    #elif (WDG_EXTERNAL_MODULE_SPI == WDG_TYPE)
    /*Should add the function for intializing the WDG module connected on SPI*/
    /* N/A for current platform*/
    #elif (WDG_EXTERNAL_MODULE_DIO == WDG_TYPE)
    /*Should add the function for intializing the WDG module connected on DIO*/
    /* N/A for current platform*/
    #endif
    return ret;
}

/**
*   @brief   Switches the watchdog into the mode Mode
*   @details Calls the set mode function specific of the hardware that it is in use
*   @param[in]  Mode          One of the following statically configured modes:
*                               1. WDGIF_OFF_MODE
*                               2. WDGIF_SLOW_MODE
*                               3. WDGIF_FAST_MODE
*               Wdg_Instance  Wdg Hardware Instance
* 
*   @return Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
* 
*/
FUNC(Std_ReturnType,WDG_CODE) Wdg_LLD_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode,
                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(uint32, AUTOMATIC) Wdg_TGpt_us;
    VAR(uint32, AUTOMATIC) Wdg_TO_Swt_us;
    VAR(uint32, AUTOMATIC) Wdg_WN_Swt_us;
    VAR(uint32, AUTOMATIC) diff_us;
    CONST(SWT_HwSettingsType, WDG_CONST) Wdg_Current_Config = Wdg_ConfigPtr[Wdg_Instance]->Config_Wdg_Internal[Mode];

/*
* @violates @ref Wdg_LLD_c_REF_9 MISRA 2004 Advisory Rule 12.1, dependence placed on C's operator precedence; operators: '==' and '||'
* @violates @ref Wdg_LLD_c_REF_10 MISRA 2004 Required Rule 12.5, non-primary expression used with logical operator
*/
    if(Mode == WDGIF_SLOW_MODE || Mode == WDGIF_FAST_MODE)
    {
            Wdg_TO_Swt_us = Wdg_Current_Config.WDG_TO_US;
            
            Gpt_StopTimer(Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel); 
            
            
            if (0x0U  == (Wdg_Current_Config.WDG_CR & (0x00000080U)))
            {
                 /* HW window mode disabled */
                 Wdg_TGpt_us =  Wdg_TO_Swt_us - (Wdg_TO_Swt_us >> 2);
                 Wdg_SWT_Trigger(Wdg_Instance);
            }
            else
            {
                 /* HW window mode enabled */
                 Wdg_WN_Swt_us = Wdg_Current_Config.WDG_WN_US;
                 diff_us = Wdg_TO_Swt_us - Wdg_WN_Swt_us;
                 Wdg_TGpt_us =  (diff_us - (diff_us >> 2)) + Wdg_WN_Swt_us;
                 /* Here the peripheral should be triggered, but if a trigger is performed an invalid access is raised */  
            }
                
            Gpt_EnableNotification(Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel);
            Gpt_StartTimer(Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel, Wdg_TGpt_us * Wdg_ConfigPtr[Wdg_Instance]->Gpt_Channel_Frequency_MHz);
    }
    #if (WDG_INTERNAL_MODULE == WDG_TYPE)
        ret = Wdg_SWT_SetMode(Mode, Wdg_Instance);
   
    #elif (WDG_EXTERNAL_MODULE_SPI == WDG_TYPE)
        /*Should add the function for Mode setting of the WDG module connected on SPI*/
        /* N/A for current platform*/
        ret = E_NOT_OK;
    #elif (WDG_EXTERNAL_MODULE_DIO == WDG_TYPE)
        /*Should add the function for  Mode setting of the WDG module connected on DIO*/
        /* N/A for current platform*/
        ret = E_NOT_OK;
    #else
        ret = E_NOT_OK;
    #endif
    return ret;
}

/**
*   @brief   The function checks the settings for the Init parameter.
*   @details Calls the function specific of the hardware that it is in use in order
*          to verify if the given configuration set is within the allowed boundaries
*          
* 
*   @param[in]      ConfigPtr      Pointer to configuration set.
*
*   @return Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
* 
*   @pre The Wdg module's environment shall make sure that the Wdg module has
*      been initialized before the Wdg_Trigger routine is called (Req: WDG104)
*   @post None
* 
*/
/*
* @violates @ref Wdg_LLD_c_REF_6 MISRA 2004 Required Rule 8.10, Declarations and definitions 
* of Objects or Functions at File scope
*/
FUNC(Std_ReturnType,WDG_CODE) Wdg_LLD_CheckHwInitSettings(
                                         P2CONST(Wdg_ConfigType,AUTOMATIC,WDG_APPL_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) ret;

    #if (WDG_INTERNAL_MODULE == WDG_TYPE)
        ret = Wdg_SWT_CheckInitSettings(ConfigPtr);
    #elif (WDG_EXTERNAL_MODULE_SPI == WDG_TYPE)
        /*Should add the function for checking the Init settings of the WDG module connected on SPI*/
        /* N/A for current platform*/
        ret = E_NOT_OK;
    #elif (WDG_EXTERNAL_MODULE_DIO == WDG_TYPE)
        /*Should add the function for checking the Init settings of the WDG module connected on DIO*/
        /* N/A for current platform*/
        ret = E_NOT_OK;
    #else
        ret = E_NOT_OK;
    #endif
    return ret;
}

/**
*   @brief   The function checks the settings for the mode parameter.
*   @details Calls the function specific of the hardware that it is in use in order
*          to verify if the given configuration set is within the allowed boundaries
*
*   @param[in]  Mode          One of the following statically configured modes:
*                               1. WDGIF_OFF_MODE
*                               2. WDGIF_SLOW_MODE
*                               3. WDGIF_FAST_MODE
*               Wdg_Instance  Wdg Hardware Instance
* 
*   @return Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
* 
*/
/*
* @violates @ref Wdg_LLD_c_REF_6 MISRA 2004 Required Rule 8.10, Declarations and definitions 
* of Objects or Functions at File scope
*/
FUNC(Std_ReturnType,WDG_CODE) Wdg_LLD_CheckHwModeSettings(VAR(WdgIf_ModeType,AUTOMATIC) Mode,
                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) ret;

    #if (WDG_INTERNAL_MODULE == WDG_TYPE)
        ret = Wdg_SWT_CheckModeSettings(Mode, Wdg_Instance);
    #elif (WDG_EXTERNAL_MODULE_SPI == WDG_TYPE)
        /*Should add the function for checking the Mode settings of the WDG module connected on SPI*/
        /* N/A for current platform*/
        ret = E_NOT_OK;
    #elif (WDG_EXTERNAL_MODULE_DIO == WDG_TYPE)
        /*Should add the function for checking the Mode settings of the WDG module connected on DIO*/
        /* N/A for current platform*/
        ret = E_NOT_OK;
    #else
        ret = E_NOT_OK;
    #endif
    return ret;
}


/**
 * @brief   Reset the watchdog timeout counter according to the timeout value passed.
 * @details 
 *
 * @param[in] Timeout       Value (milliseconds) for setting the trigger counter.
 *            Wdg_Instance  Wdg Hardware Instance
 * 
 * @return void
 *
 */
FUNC(void,WDG_CODE) Wdg_LLD_SetTriggerCondition(VAR(uint16, AUTOMATIC) Timeout,
                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    
    VAR(uint32, AUTOMATIC) Wdg_TGpt_us;
    VAR(uint32, AUTOMATIC) Wdg_TO_Swt_us;
    VAR(uint32, AUTOMATIC) Wdg_WN_Swt_us;
    VAR(uint32, AUTOMATIC) Timeout_us;
    VAR(uint32, AUTOMATIC) diff_us;
    
    CONST(SWT_HwSettingsType, WDG_CONST) Wdg_Current_Config = \
                   Wdg_ConfigPtr[Wdg_Instance]->Config_Wdg_Internal[Wdg_Current_Mode[Wdg_Instance]];
    
    Timeout_us = (uint32)Timeout * 1000U;
    Wdg_TO_Swt_us = Wdg_Current_Config.WDG_TO_US;

    if (Timeout == 0U)  
    {
        /* When "0" is passed as timeout, stop triggering the watchdog and let the SWT counter expire. */
        Wdg_TriggerCount[Wdg_Instance] = (uint32)0;
    }
    else if(Wdg_TO_Swt_us < Timeout_us)
    {        
        if (0x0U  == (Wdg_Current_Config.WDG_CR & (0x00000080U)))
        {
            /* HW window mode disabled */
            Wdg_TGpt_us =  Wdg_TO_Swt_us - (Wdg_TO_Swt_us >> 2);
            Wdg_TriggerCount[Wdg_Instance] = (uint32)(Timeout_us / Wdg_TGpt_us);
        }
        else
        {
            /* HW window mode enabled */
            Wdg_WN_Swt_us = Wdg_Current_Config.WDG_WN_US;
            diff_us = Wdg_TO_Swt_us - Wdg_WN_Swt_us;
            Wdg_TGpt_us =  (diff_us - (diff_us >> 2)) + Wdg_WN_Swt_us;
            Wdg_TriggerCount[Wdg_Instance] = (uint32)(Timeout_us / Wdg_TGpt_us);
        }
    }
    else
    {
    /* @violates @ref Wdg_LLD_c_REF_11 All if ... else if constructs. */
    }   
}

#if (WDG_INSTANCE0 == STD_ON)
/**
*   @brief   The function implement the call back for triggering using an external counter (GPT channel).
*   @details 
*          
* 
*   @return void
* 
*/
/*
* @violates @ref Wdg_LLD_c_REF_6 MISRA 2004 Required Rule 8.10, Declarations and definitions 
* of Objects or Functions at File scope
*/
FUNC(void,WDG_CODE) Wdg_Cbk_GptNotification0(void)
{
    if (Wdg_TriggerCount[WDG_IPW_INSTANCE0] > (uint32)0)
    {    
        Wdg_SWT_Trigger(WDG_IPW_INSTANCE0);
        Wdg_TriggerCount[WDG_IPW_INSTANCE0]--;
    }    
    else
    {
        Gpt_StopTimer(Wdg_ConfigPtr[WDG_IPW_INSTANCE0]->Gpt_Channel);
        Gpt_DisableNotification(Wdg_ConfigPtr[WDG_IPW_INSTANCE0]->Gpt_Channel);
    }    
}
#endif


#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif /* WDG_LLD_C */

/** @} */
