/**
*   @file     Wdg_Channel.c
*
*   @version  1.0.1
*
*   @brief    AUTOSAR Wdg - Contains the implementation of the Watchdog API
*   @details  It contains the layer requested by autosar. The functions are independent of
*             hardware settings.
*
*   @addtogroup  Wdg
* @{
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
* @section Wdg_Channel_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by 
* other preprocessor directives or comments.
* This mechanism is used to properly place code and variables into their sections.
*
* @section Wdg_Channel_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
*
* @section Wdg_Channel_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* define name is required by the AUTOSAR specifications although it exceedes the max length of 31 characters.
*
* @section Wdg_Channel_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
* @section Wdg_Channel_c_REF_5
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness, and 10.3 cast
* of complex integer expression to larger type. Many type conversions are implemented in MARCOS. The code
* was tested successfully with 3 different compilers.
*
* @section Wdg_Channel_c_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Wdg_Channel_c_REF_7
* Violates MISRA 2004 Required Rule 13.7, Boolean within 'left side of && within left side of && within if' always evaluates to True
*
* @section Wdg_Channel_c_REF_8
* Violates MISRA 2004 Required Rule 16.10, If a function returns error information, then that error
* information shall be tested.
*
* @section Wdg_Channel_c_REF_9
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only 
* accessed from within a single function.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Channel.h"
#include "Wdg_LLD.h"

#if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/*
* @violates @ref Wdg_Channel_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "Dem.h"
#endif

#include "Wdg_Cbk.h"
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_CHANNEL_VENDOR_ID_C                      43
/* @violates @ref Wdg_Channel_c_REF_6  MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
/* @violates @ref Wdg_Channel_c_REF_3 Violates MISRA 2004 Required Rule 1.4 */
#define WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C       4
/* @violates @ref Wdg_Channel_c_REF_6  MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
/* @violates @ref Wdg_Channel_c_REF_3 Violates MISRA 2004 Required Rule 1.4 */
#define WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Wdg_Channel_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref Wdg_Channel_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C    3
#define WDG_CHANNEL_SW_MAJOR_VERSION_C               1
#define WDG_CHANNEL_SW_MINOR_VERSION_C               0
#define WDG_CHANNEL_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_Channel.h have different vendor ids"
#endif
/* Check if current file and WDG header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_Channel.h are different"
#endif
/* Check if current file and WDG header file are of the same Software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_CHANNEL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Channel.c and Wdg_Channel.h are different"
#endif

#if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* Check if current file and Dem header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_Channel.c and Dem.h are different"
    #endif
#endif
#endif

/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (WDG_DEV_ERROR_DETECT == STD_ON)
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg_Channel.c and Det.h are different"
        #endif
    #endif
#endif

/* Check if current file and WDG_LLD header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_LLD_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_LLD.h have different vendor ids"
#endif

/* Check if current file and WDG_LLD header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C    != WDG_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C    != WDG_LLD_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C != WDG_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_LLD.h are different"
#endif

/* Check if current file and WDG_LLD header file are of the same Software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_LLD_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_LLD_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Channel.c and Wdg_LLD.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief  This enumerated type will contain the watchdog driver's possible states
*
* @api
*/
typedef enum
{
    WDG_UNINIT         = 0x00,  /**< @brief The watchdog driver is not uninitialized */
    WDG_IDLE,                   /**< @brief = 0x01 The watchdog driver is currently idle,
                                                   i.e not beeing triggered or mode changed */
    WDG_BUSY                    /**< @brief = 0x02 The watchdog driver is currently busy,
                                                   i.e triggered or switchd between modes */
} Wdg_StatusType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
/*
* @violates @ref Wdg_Channel_c_REF_9 MISRA 2004 Required Rule 8.7, Objects shall be defined at 
* block scope if they are only accessed from within a single function.
*/
    extern P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_ConfigPC[WDG_NO_OF_INSTANCES];
#endif
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*
* @violates @ref Wdg_Channel_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Channel_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Channel_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief Global variable used for indicating the current Wdg driver mode.
*/
/* 
* @violates @ref Wdg_Channel_c_REF_4 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of
* Objects or Functions at File scope
*/
VAR(WdgIf_ModeType, WDG_VAR) Wdg_Current_Mode[WDG_NO_OF_INSTANCES] = {WDGIF_SLOW_MODE};

#if (WDG_DEV_ERROR_DETECT == STD_ON)
/**
*  @brief Variable that indicated the state of the driver if the WDG_DEV_ERROR_DETECT is on
*/
STATIC VAR(Wdg_StatusType, WDG_VAR) Wdg_Status[WDG_NO_OF_INSTANCES] = {WDG_UNINIT};
#endif

/**
*  @brief Variable that indicate the current configuration set
*/
P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_ConfigPtr[WDG_NO_OF_INSTANCES] = {NULL_PTR};
/*
* @violates @ref Wdg_Channel_c_REF_6 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Channel_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Channel_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"



/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
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
* @violates @ref Wdg_Channel_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only
* be preceded by other preprocessor directives or comments.  
*/
/*
* @violates @ref Wdg_Channel_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief   This function initializes the WDG module.
* @details The @p Wdg_Init function shall initialize the Wdg module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in] ConfigPtr     Pointer to configuration set.
* @param[in] Wdg_Instance  SWT instance.
*
* @return void
*
* @implements      DWDG03001
* 
* @api
*/
/* 
* @violates @ref Wdg_Channel_c_REF_4 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of
* Objects or Functions at File scope
*/
FUNC(void, WDG_CODE) Wdg_ChannelInit(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_ALLOWED == STD_OFF))
    VAR (WdgIf_ModeType, AUTOMATIC)   Wdg_DefaultMode;
#endif
    VAR (Std_ReturnType, AUTOMATIC) ret = (uint8)E_NOT_OK;

#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
    /* If precompile support enable, initialize the configuration pointer
     * with the default pointer */
    ConfigPtr = Wdg_ConfigPC[Wdg_Instance];
#endif    /* #ifdef WDG_PRECOMPILE_SUPPORT */

/* @implements      DWDG07002 */
#if (WDG_DEV_ERROR_DETECT == STD_ON)
#if (WDG_PRECOMPILE_SUPPORT == STD_OFF)
    if (ConfigPtr == NULL_PTR)
    {
        /* @implements      DWDG03004 */
        Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance,(uint8)WDG_INIT_ID,
                        (uint8)WDG_E_PARAM_POINTER);
    }
    else
    {
#endif /* #ifndef WDG_PRECOMPILE_SUPPORT */
#endif /* (WDG_DEV_ERROR_DETECT == STD_ON)*/
#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_ALLOWED == STD_OFF))
        Wdg_DefaultMode = ConfigPtr->Wdg_CfgDefaultMode;
#endif
        /* If the mode that will be set up in initialization is off mode and the driver
         * does not support disabling the hardware then do not execute the initialization
         * and report the error */
/* @implements      DWDG07001 */
#if (WDG_DISABLE_ALLOWED == STD_OFF)
        if (WDGIF_OFF_MODE == Wdg_DefaultMode)
        {
            #if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
            /*
            * @violates @ref Wdg_Channel_c_REF_5 Violates MISRA 2004 Required Rule 10.1
            */
            if (STD_ON == Wdg_E_Disable_RejectedCfg.state)
            {
            /*
            * @violates @ref Wdg_Channel_c_REF_5 Violates MISRA 2004 Required Rule 10.1
            */
            Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Disable_RejectedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
#endif /* (WDG_DISABLE_ALLOWED == STD_OFF) */

#if (WDG_DEV_ERROR_DETECT == STD_ON)
            if ((Wdg_DefaultMode != WDGIF_OFF_MODE) &&
                (Wdg_DefaultMode != WDGIF_SLOW_MODE)&&
/*
* @violates @ref Wdg_Channel_c_REF_7 MISRA 2004 Required Rule 13.7, Boolean within 'left side of && within left side of && within if' always evaluates to True
*/
                (Wdg_DefaultMode != WDGIF_FAST_MODE))
            {
                /* If the mode is not in the allowed boundaries of configuration
                 * do not execute initialization */
                Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance,(uint8) WDG_INIT_ID,
                                (uint8) WDG_E_PARAM_CONFIG);
            }
            else
            {
                /* If the hardware specific contents of the given configuration set
                 * is not in allowed boundaries do not execute initialization
                 */
                ret = Wdg_LLD_CheckHwInitSettings(ConfigPtr);

                /* @implements      DWDG07003 */
                if ((uint8)E_NOT_OK == ret)
                {
                    Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance, (uint8)WDG_INIT_ID,
                                    (uint8)WDG_E_PARAM_CONFIG);
                }
                else
                {
#endif /* (WDG_DEV_ERROR_DETECT == STD_ON)*/
                
                    /* Store the ConfigPtr in a global variable used in Wdg_LLD_SetMode function */
                    Wdg_ConfigPtr[Wdg_Instance] = ConfigPtr;  
                    Wdg_Current_Mode[Wdg_Instance] = ConfigPtr->Wdg_CfgDefaultMode;  
                    /* Set up the the hardware settings */
                    /* @implements      DWDG07005 */
                    ret = Wdg_LLD_Init(Wdg_ConfigPtr[Wdg_Instance], Wdg_Instance);
                    if ((uint8)E_NOT_OK == ret)
                    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)                    
                        Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance, (uint8)WDG_INIT_ID,
                                        (uint8)WDG_E_PARAM_CONFIG);
#endif

                    }
                    else
                    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
                        /* @implements      DWDG07004 */
                        Wdg_Status[Wdg_Instance] = WDG_IDLE;
#endif
                    }
#if (WDG_DEV_ERROR_DETECT == STD_ON)                    
                }
            }
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */

#if (WDG_DISABLE_ALLOWED == STD_OFF)
        }
#endif /* (WDG_DISABLE_ALLOWED == STD_OFF) */

#if (WDG_DEV_ERROR_DETECT == STD_ON)
#if (WDG_PRECOMPILE_SUPPORT == STD_OFF)
    }
#endif /*#ifndef WDG_PRECOMPILE_SUPPORT */
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */
}

/**
* @brief   Switches the watchdog into the mode Mode.
* @details By choosing one of a limited number of statically configured
*          settings (e.g. toggle or window watchdog, different timeout periods)
*          the Wdg module and the watchdog hardware can be switched between the
*          following three different watchdog modes using the @p Wdg_SetMode
*          function:<br>
*          - WDGIF_OFF_MODE,
*          - WDGIF_SLOW_MODE,
*          - WDGIF_FAST_MODE.
*          .
*
* @param[in] Mode      One of the following statically configured modes:<br>
*                      -# WDGIF_OFF_MODE,
*                      -# WDGIF_SLOW_MODE,
*                      -# WDGIF_FAST_MODE.
* @param[in] Wdg_Instance  SWT instance.
* 
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
* 
* @implements      DWDG03002
*
* @api
*/
/* 
* @violates @ref Wdg_Channel_c_REF_4 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of
* Objects or Functions at File scope
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelSetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode,
                                              CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    /* @implements      DWDG08001 */
    VAR(Std_ReturnType, AUTOMATIC) ret = (uint8)E_OK;
    /* @implements      DWDG08010 */
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) ret_hw = (uint8)E_NOT_OK;

    /* If the state of the driver is not idle, i.e that the hardware is
     * currently been trigger or the mode is changeing, do not execute the
     * switching of the mode and report the error */
    /* @implements      DWDG03005 */
    if (WDG_IDLE != Wdg_Status[Wdg_Instance])
    {
        /* @implements      DWDG08006 */
        Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance, (uint8)WDG_SETMODE_ID,
                        (uint8)WDG_E_DRIVER_STATE);
        ret = (uint8)E_NOT_OK;
    }
    else
    {
        /* Change the state indicating that the driver is currently beeing switched */
        /* @implements      DWDG08007 */
        Wdg_Status[Wdg_Instance] = WDG_BUSY;

        /* Check if <Mode> is within allowed range */
        if ((Mode != WDGIF_OFF_MODE) &&
            (Mode != WDGIF_SLOW_MODE)&&
            (Mode != WDGIF_FAST_MODE))
        {
            /* @implements      DWDG08004 */
            Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance,(uint8)WDG_SETMODE_ID,
                            (uint8) WDG_E_PARAM_MODE);
            ret = (uint8)E_NOT_OK;
        }
        /* If the hardware specific contents of the given configuration set
         * is not in allowed boundaries do not execute initialization
         */
        else
        {
            /* @implements      DWDG08009 */
            ret_hw = Wdg_LLD_CheckHwModeSettings(Mode, Wdg_Instance);
            if ((uint8)E_NOT_OK == ret_hw)
            {
                /* @implements      DWDG08005 */
                Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance, (uint8)WDG_SETMODE_ID,
                                (uint8)WDG_E_PARAM_MODE);
                ret = (uint8)E_NOT_OK;
            }
            else
            {
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */

        /* If the mode that will be set up is off mode and the driver does not support
         * disabling the hardware then do not change the mode and report the error */
/* @implements      DWDG08003 */
#if (WDG_DISABLE_ALLOWED == STD_OFF)
                if (WDGIF_OFF_MODE == Mode)
                {
                    #if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                    /*
                    * @violates @ref Wdg_Channel_c_REF_5 Violates MISRA 2004 Required Rule 10.1
                    */
                    if (STD_ON == Wdg_E_Disable_RejectedCfg.state)
                    {
                    /*
                    * @violates @ref Wdg_Channel_c_REF_5 Violates MISRA 2004 Required Rule 10.1
                    */
                    Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Disable_RejectedCfg.id, DEM_EVENT_STATUS_FAILED);
                    }
                    #endif
                    ret = (uint8)E_NOT_OK;
                }
                else
                {
#endif /* WDG_DISABLE_ALLOWED == STD_OFF */
            /* If an error occurred when trying to set up the hardware */
                    ret = Wdg_LLD_SetMode(Mode, Wdg_Instance);
                    if ((uint8)E_NOT_OK == ret)
                    {
                        #if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                        /*
                        * @violates @ref Wdg_Channel_c_REF_5 Violates MISRA 2004 Required Rule 10.1
                        */
                        if (STD_ON == Wdg_E_Mode_FailedCfg.state)
                        {
                        /* @implements      DWDG08002 */
                        /*
                        * @violates @ref Wdg_Channel_c_REF_5 Violates MISRA 2004 Required Rule 10.1
                        */
                        Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Mode_FailedCfg.id, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                    else
                    {
                        Wdg_Current_Mode[Wdg_Instance] = Mode;
                    }
#if (WDG_DISABLE_ALLOWED == STD_OFF)
                }
#endif /* WDG_DISABLE_ALLOWED == STD_OFF */

#if (WDG_DEV_ERROR_DETECT == STD_ON)
            }
        }
        /* @implements      DWDG08008 */
        Wdg_Status[Wdg_Instance] = WDG_IDLE;
    }
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */

    return (ret);
}

/**
 * @brief   Reset the watchdog timeout counter according to the timeout value passed.
 * @details 
 *
 * @param[in] Timeout       value (milliseconds) for setting the trigger counter.
 * @param[in] Wdg_Instance  SWT instance.
 * 
 * @return void
 *
 * @implements      DWDG03003
 *
 * @api
 */
/* 
* @violates @ref Wdg_Channel_c_REF_4 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of
* Objects or Functions at File scope
*/
FUNC(void, WDG_CODE) Wdg_ChannelSetTriggerCondition(VAR(uint16, AUTOMATIC) Timeout,
                                                   CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    /* If the state of the driver is not idle, i.e that the hardware is
     * currently been trigger or the mode is changeing, do not execute the
     * switching of the mode and report the error */
     
    /* @implements      DWDG09003 */
    if (WDG_IDLE != Wdg_Status[Wdg_Instance])
    {
        Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance, (uint8)WDG_SETTRIGGERCONDITION_ID,
                        (uint8)WDG_E_DRIVER_STATE);
    }
    else
    {
       if (Timeout > WDGMAXTIMEOUT)
       {
         /* @implements      DWDG09001 */
         Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance, (uint8)WDG_SETTRIGGERCONDITION_ID,
                        (uint8)WDG_E_PARAM_TIMEOUT);
       } 
      else
       {
#endif
        /* @implements      DWDG09002 */
        /* @violates @ref Wdg_Channel_c_REF_8 Violates MISRA 2004 Required Rule 16.10 */
        Wdg_LLD_SetTriggerCondition (Timeout, Wdg_Instance);
#if (WDG_DEV_ERROR_DETECT == STD_ON)
           
            
       }    
    }    
#endif
}

/* @implements DWDG06001 */
#if (WDG_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief   Returns the version information of the module.
* @details The  Wdg_GetVersionInfo function shall return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*          .
*
* @pre    This ISR is only required if the WDG_VERSION_INFO_API has to be
*         equal STD_ON.
*
* @param[in,out] versioninfo   Pointer to where to store the version
*                              information of this module.
* @param[in] Wdg_Instance  SWT instance.
*
* @return void
*
* @api
*
* @implements      DWDG03000
*
*/
/* 
* @violates @ref Wdg_Channel_c_REF_4 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of
* Objects or Functions at File scope
*/
FUNC(void, WDG_CODE) Wdg_ChannelGetVersionInfo
                    (P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) versioninfo,
                     CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    (void)(Wdg_Instance); /* added to remove warning (dcc:1516) */
    /* @implements      DWDG03007 */
#if (WDG_DEV_ERROR_DETECT == STD_ON)    
    if (NULL_PTR == versioninfo)
    {
        Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_Instance,(uint8)WDG_GETVERSION_ID,
                        (uint8)WDG_E_PARAM_POINTER);
    }
    else
    {
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */

        /* @implements DWDG06002 */
        (versioninfo)->vendorID         = (uint16)WDG_CHANNEL_VENDOR_ID;
        /* @implements DWDG06003 */
        (versioninfo)->moduleID         = (uint8)WDG_CHANNEL_MODULE_ID;    
        /* @implements DWDG06004 */
        (versioninfo)->sw_major_version = (uint8)WDG_CHANNEL_SW_MAJOR_VERSION;
        /* @implements DWDG06005 */
        (versioninfo)->sw_minor_version = (uint8)WDG_CHANNEL_SW_MINOR_VERSION;
        /* @implements DWDG06006 */
        (versioninfo)->sw_patch_version = (uint8)WDG_CHANNEL_SW_PATCH_VERSION;
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* WDG_DEV_ERROR_DETECT == STD_ON */
}
#endif /* WDG_VERSION_INFO_API == STD_ON */

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/*
* @violates @ref Wdg_Channel_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Channel_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
* prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif /* WDG_C */

/** @} */
