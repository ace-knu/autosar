/**
*   @file    Wdg_Swt_LLD.c
*
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
* @section Wdg_Swt_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by 
* other preprocessor directives or comments.
* This mechanism is used to properly place code and variables into their sections.
*
* @section Wdg_Swt_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
*
* @section Wdg_Swt_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* define name is required by the AUTOSAR specifications although it exceedes the max length of 31 characters.
*
* @section Wdg_Swt_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a function 
* and any type other than an integral type.
* This violation is due to casting source to destination and access these addresses for updating contents 
* in that address.
*
* @section Wdg_Swt_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
* @section Wdg_Swt_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 12.4, the right-hand operand of a logical "&&" or "||" operator
* shall not contain side effects. This is necessary to simplify the code structure and easier
* readability.
*
* @section Wdg_Swt_LLD_c_REF_7
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Swt_LLD.h"
#include "Reg_eSys_Swt.h"
/*
* @violates @ref Wdg_Swt_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "Mcal.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_SWT_LLD_VENDOR_ID_C                     43
/*
* @violates @ref Wdg_Swt_LLD_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
* @violates @ref Wdg_Swt_LLD_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION_C      4
/*
* @violates @ref Wdg_Swt_LLD_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
* @violates @ref Wdg_Swt_LLD_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION_C      0
/*
* @violates @ref Wdg_Swt_LLD_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to 
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
* @violates @ref Wdg_Swt_LLD_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_SWT_LLD_AR_RELEASE_REVISION_VERSION_C   3
#define WDG_SWT_LLD_SW_MAJOR_VERSION_C              1
#define WDG_SWT_LLD_SW_MINOR_VERSION_C              0
#define WDG_SWT_LLD_SW_PATCH_VERSION_C              1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Swt_LLD header file are of the same vendor */
#if (WDG_SWT_LLD_VENDOR_ID_C != WDG_SWT_LLD_VENDOR_ID)
    #error "Wdg_Swt_LLD.c and Wdg_Swt_LLD.h have different vendor ids"
#endif
/* Check if current file and Wdg_Swt_LLD header file are of the same Autosar version */
#if ((WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION_C    != WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION_C    != WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_LLD_AR_RELEASE_REVISION_VERSION_C != WDG_SWT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Swt_LLD.c and Wdg_Swt_LLD.h are different" 
#endif
/* Check if current file and SWT header file are of the same Software version */
#if ((WDG_SWT_LLD_SW_MAJOR_VERSION_C != WDG_SWT_LLD_SW_MAJOR_VERSION) || \
     (WDG_SWT_LLD_SW_MINOR_VERSION_C != WDG_SWT_LLD_SW_MINOR_VERSION) || \
     (WDG_SWT_LLD_SW_PATCH_VERSION_C != WDG_SWT_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Swt_LLD.c and Wdg_Swt_LLD.h are different"
#endif

/* Check if current file and SWT register header file are of the same vendor */
#if (WDG_SWT_LLD_VENDOR_ID_C != REG_ESYS_SWT_VENDOR_ID)
    #error "Wdg_Swt_LLD.c and Reg_eSys_Swt.h have different vendor ids"
#endif

/* Check if source file and SWT register header file are of the same Autosar version */
#if ((WDG_SWT_LLD_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_LLD_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SWT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Swt_LLD.c and Reg_eSys_Swt.h are different"
#endif

/* Check if source file and SWT register header file are of the same Software version */
#if ((WDG_SWT_LLD_SW_MAJOR_VERSION_C != REG_ESYS_SWT_SW_MAJOR_VERSION) || \
     (WDG_SWT_LLD_SW_MINOR_VERSION_C != REG_ESYS_SWT_SW_MINOR_VERSION) || \
     (WDG_SWT_LLD_SW_PATCH_VERSION_C != REG_ESYS_SWT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Swt_LLD.c and Reg_eSys_Swt.h are different"
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
#define WDG_START_SEC_CONST_32
/* @violates @ref Wdg_Swt_LLD_c_REF_1 #include should only be preceded by other preprocessor directives or comments */
/* @violates @ref Wdg_Swt_LLD_c_REF_2 prevent the contents of a header file being included twice */
#include "MemMap.h"
/* @violates @ref Wdg_Swt_LLD_c_REF_5 Declaration and definition of objects or function */
CONST(uint32, WDG_CONST) SWT_BASE_ADDRS[] = {
#ifdef SWT0_BASEADDR
    SWT0_BASEADDR
#endif
#ifdef SWT1_BASEADDR
    ,SWT1_BASEADDR
#endif
#ifdef SWT2_BASEADDR
    ,SWT2_BASEADDR
#endif
#ifdef SWT3_BASEADDR
    ,SWT3_BASEADDR
#endif
};

#define WDG_STOP_SEC_CONST_32
/* @violates @ref Wdg_Swt_LLD_c_REF_1 #include should only be preceded by other preprocessor directives or comments */
/* @violates @ref Wdg_Swt_LLD_c_REF_2 prevent the contents of a header file being included twice */
#include "MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Swt_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief Global variable (pointer) used for storing the Wdg driver configuration data.
*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_5 MISRA 2004 Required Rule 8.10, Declarations and definitions 
* of Objects or Functions at File scope
*/
P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Ram_LLD_ConfigPtr[WDG_NO_OF_INSTANCES] = {NULL_PTR};

/*
* @violates @ref Wdg_Swt_LLD_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Swt_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef WDG_KEYED_SERVICE_USED

/*
* @violates @ref Wdg_Swt_LLD_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Swt_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"
/**
*   @brief The mode used to service the watchdog; it can be used either the fixed 
*        sequence or the keyed sequence. It is set up at initialization.
*        
*/
STATIC VAR(Wdg_ServiceModeType, WDG_VAR) Wdg_ServiceMode[WDG_NO_OF_INSTANCES];

/*
* @violates @ref Wdg_Swt_LLD_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Wdg_Swt_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Swt_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
*   @brief   This function initializes the hardware of WDG module.
*   @details Sets up the values such as timeout value, window value
*
*   @param[in]      ConfigPtr      Pointer to configuration set.
* 
*   @return Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
*
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_SWT_Init(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                                CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) response = (uint8)E_OK;
    CONST(WdgIf_ModeType, WDG_CONST)Wdg_DefaultMode = ConfigPtr->Wdg_CfgDefaultMode;
    CONST(SWT_HwSettingsType, WDG_CONST) DefaultConfig = ConfigPtr->Config_Wdg_Internal[Wdg_DefaultMode];
#ifdef WDG_KEYED_SERVICE_USED
    CONST(Wdg_ServiceKeyWidthType, WDG_CONST)Wdg_KeyServiceValue = ConfigPtr->Wdg_KeyServiceValue ;
#endif

    Ram_LLD_ConfigPtr[Wdg_Instance] = ConfigPtr;

#ifdef WDG_KEYED_SERVICE_USED
    Wdg_ServiceMode[Wdg_Instance] = Ram_LLD_ConfigPtr[Wdg_Instance]->Wdg_CfgServiceMode;
#endif
   /* @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a function and any type other than an integral type. */
   /* @violates @ref Wdg_Swt_LLD_c_REF_6 Required Rule 12.4 the right-hand operand of a logical "&&" or "||" operator shall not contain side effects. */
   if( (SWT_WDG_HARD_LOCK) == (REG_READ32(SWT_CR(Wdg_Instance)) & SWT_WDG_HARD_LOCK) )
    {
        response =  (uint8)E_NOT_OK;
    }
    else
    {
        /* Unlock the possible lock condition   */
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_SR(Wdg_Instance), SWT_UNLOCK_SEQ1);

        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_SR(Wdg_Instance), SWT_UNLOCK_SEQ2);

        /* Disable watchdog */
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_BIT_CLEAR32(SWT_CR(Wdg_Instance), SWT_WDG_ENABLED);

        /* Set Timer-out register */
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_TO(Wdg_Instance), DefaultConfig.WDG_TO);

        /* Set window register */
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_WN(Wdg_Instance), DefaultConfig.WDG_WN);

        /* Activate the default configuration  */
#ifdef WDG_KEYED_SERVICE_USED
        if (WDG_KEYED_SERVICE == Wdg_ServiceMode[Wdg_Instance])
        {
            /*
            * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
            * between a pointer to a function and any type other than an integral type.
            */
            REG_WRITE32(SWT_SK(Wdg_Instance), Wdg_KeyServiceValue);
        }
#endif
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_CR(Wdg_Instance),(SWT_MAP_ENABLE_BITS |DefaultConfig.WDG_CR));
    }
    return response; 
}

/**
*   @brief   Switches the watchdog into the mode Mode
*   @details Sets up the specific parameters on the hardware for mode requested
*   @param[in]  Mode      One of the following statically configured modes:
*                       -# WDGIF_OFF_MODE
*                       -# WDGIF_SLOW_MODE
*                       -# WDGIF_FAST_MODE
*                       .
* 
*   @return Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
* 
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_SWT_SetMode(CONST(WdgIf_ModeType, AUTOMATIC) Mode,
                                                CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) response = (uint8)E_OK;
    CONST(SWT_HwSettingsType, WDG_CONST) CrtConfig = Ram_LLD_ConfigPtr[Wdg_Instance]->Config_Wdg_Internal[Mode];

    /*
    * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
    * between a pointer to a function and any type other than an integral type.
    */
    /*
     * @violates @ref Wdg_Swt_LLD_c_REF_6 the right-hand operand of a logical "&&" or "||" operator
     * shall not contain side effects.
     */
    if( ((SWT_WDG_SOFT_LOCK) == ( REG_READ32(SWT_CR(Wdg_Instance)) & SWT_WDG_SOFT_LOCK ) )|| \
                  ((SWT_WDG_HARD_LOCK) == ( REG_READ32(SWT_CR(Wdg_Instance)) & SWT_WDG_HARD_LOCK )))
    {
        response =  (uint8)E_NOT_OK;
    }
    else
    {
        /* Disable watchdog */
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_BIT_CLEAR32(SWT_CR(Wdg_Instance), SWT_WDG_ENABLED);

        /* Set Timer-out register */
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_TO(Wdg_Instance), CrtConfig.WDG_TO);

        /* Set window register */
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_WN(Wdg_Instance), CrtConfig.WDG_WN);

        /* Set the Control Register*/
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_CR(Wdg_Instance),(SWT_MAP_ENABLE_BITS | CrtConfig.WDG_CR));
    }
    return response;
}

/**
*   @brief   This function triggers the watchdog hardware.
*   @details Writes the trigger sequence on the hardware
* 
* 
*   @return Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
*  
*   @pre The Wdg module's environment shall make sure that the Wdg module has
*      been initialized before the Wdg_Trigger routine is called (Req: WDG104)
* 
*/
FUNC(void, WDG_CODE) Wdg_SWT_Trigger(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
#ifdef WDG_KEYED_SERVICE_USED
    if (WDG_KEYED_SERVICE == Wdg_ServiceMode[Wdg_Instance])
    {
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        VAR(uint32, WDG_VAR) keyed_value = SWT_GET_KEYED_SERVICE_SEQ1(Wdg_Instance);

        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_SR(Wdg_Instance), keyed_value);
        keyed_value = ((17UL * keyed_value) + 3UL) & 0x0000FFFFUL;
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_SR(Wdg_Instance), keyed_value);
    }
    else
    {
#endif
        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_SR(Wdg_Instance), SWT_FIXED_SERVICE_SEQ1);

        /*
        * @violates @ref Wdg_Swt_LLD_c_REF_4 MISRA 2004 Required Rule 11.1, Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(SWT_SR(Wdg_Instance), SWT_FIXED_SERVICE_SEQ2);
#ifdef WDG_KEYED_SERVICE_USED
    }
#endif
}

/**
*   @brief   The function check the settings for the Init parameter.
*   @details Verifies if the given configuration set is within the allowed boundaries
* 
*   @pre The Wdg module's environment shall make sure that the Wdg module has
*      been initialized before the Wdg_Trigger routine is called (Req: WDG104)
*     
*
*   @return Std_ReturnType
*   @return @retval E_OK        The mode switch has been executed completely and successfully
* 
*   @retval E_NOT_OK    The mode switch has encounter errors
*
*/
FUNC(Std_ReturnType, WDG_CODE)
     Wdg_SWT_CheckInitSettings(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) response = (uint8)E_OK;
    CONST(SWT_HwSettingsType, WDG_CONST)
          DefaultConfig = ConfigPtr->Config_Wdg_Internal[ConfigPtr->Wdg_CfgDefaultMode];

    if ( SWT_TRIGGER_MODE_WINDOW == (DefaultConfig.WDG_CR & SWT_TRIGGER_MODE_WINDOW))
    {
        if (DefaultConfig.WDG_TO < DefaultConfig.WDG_WN)
        {
            response = (uint8)E_NOT_OK;
        }
    }
    return response;
}

/**
*   @brief   The function check the settings for the Init parameter.
*   @details Verifies if the given configuration set is within the allowed boundaries
*   @pre     The Wdg module's environment shall make sure that the Wdg module has
*          been initialized before the Wdg_Trigger routine is called (Req: WDG104)
* 
*   @return Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
* 
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_SWT_CheckModeSettings(CONST(WdgIf_ModeType, AUTOMATIC) Mode,
                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) response = (uint8)E_OK;
    CONST(SWT_HwSettingsType, WDG_CONST) CrtConfig = Ram_LLD_ConfigPtr[Wdg_Instance]->Config_Wdg_Internal[Mode];

    if ( SWT_TRIGGER_MODE_WINDOW == (CrtConfig.WDG_CR & SWT_TRIGGER_MODE_WINDOW))
    {
        if (CrtConfig.WDG_TO < CrtConfig.WDG_WN)
        {
            response = (uint8)E_NOT_OK;
        }
    }
    return response;
}

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif

/*
* @violates @ref Wdg_Swt_LLD_c_REF_1 MISRA 2004 Advisory Rule 19.1, #include statements in a file should only 
* be preceded by other preprocessor directives or comments. 
*/
/*
* @violates @ref Wdg_Swt_LLD_c_REF_2 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif /* WDG_SWT_LLD_H */

/** @} */
