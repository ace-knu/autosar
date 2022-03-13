/**
*   @file   Wdg.c
*  
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - contains the data exported by the Watchdog module
*   @details Contains the information that will be exported by the module, as requested by Autosar.
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
* @section Wdg_C_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section Wdg_C_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
* @section Wdg_C_REF_3
*          Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of
*          more than 31 characters.This can not be avoided due to naming convention.
* @section Wdg_C_REF_4
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before #include. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* @section Wdg_C_REF_5
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          The functions/variables are part of Wdg API
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdg.h"
#include "Wdg_Channel.h"

#if (WDG_INSTANCE0 == STD_ON)
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg.c    
*/
#define WDG_43_INSTANCE0_VENDOR_ID_C                    43
#define WDG_43_INSTANCE0_MODULE_ID_C                    102
/** @violates @ref Wdg_C_REF_2 MISRA 2004 Rule 1.4 */
/** @violates @ref Wdg_C_REF_3 MISRA 2004 Rule 5.1 */
#define WDG_43_INSTANCE0_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref Wdg_C_REF_2 MISRA 2004 Rule 1.4 */
/** @violates @ref Wdg_C_REF_3 MISRA 2004 Rule 5.1 */
#define WDG_43_INSTANCE0_AR_RELEASE_MINOR_VERSION_C     0
/** @violates @ref Wdg_C_REF_2 MISRA 2004 Rule 1.4 */
/** @violates @ref Wdg_C_REF_3 MISRA 2004 Rule 5.1 */
#define WDG_43_INSTANCE0_AR_RELEASE_REVISION_VERSION_C  3
#define WDG_43_INSTANCE0_SW_MAJOR_VERSION_C             1
#define WDG_43_INSTANCE0_SW_MINOR_VERSION_C             0
#define WDG_43_INSTANCE0_SW_PATCH_VERSION_C             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG channel header file are of the same vendor */
#if (WDG_43_INSTANCE0_VENDOR_ID_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg.c and Wdg_Channel.h have different vendor ids"
#endif

/* Check if current file and WDG channel header file are of the same Autosar version */
#if ((WDG_43_INSTANCE0_AR_RELEASE_MAJOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_INSTANCE0_AR_RELEASE_MINOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_INSTANCE0_AR_RELEASE_REVISION_VERSION_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg.c and Wdg_Channel.h are different"
#endif

/* Check if current file and WDG channel header file are of the same software version */
#if ((WDG_43_INSTANCE0_SW_MAJOR_VERSION_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_43_INSTANCE0_SW_MINOR_VERSION_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_43_INSTANCE0_SW_PATCH_VERSION_C != WDG_CHANNEL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg.c and Wdg_Channel.h are different"
#endif


/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_43_INSTANCE0_VENDOR_ID_C != \
     WDG_43_INSTANCE0_VENDOR_ID)
    #error "Wdg.c and Wdg.h have different vendor ids"
#endif

/* Check if current file and WDG channel header file are of the same Autosar version */
#if ((WDG_43_INSTANCE0_AR_RELEASE_MAJOR_VERSION_C    != \
      WDG_43_INSTANCE0_AR_RELEASE_MAJOR_VERSION) || \
      (WDG_43_INSTANCE0_AR_RELEASE_MINOR_VERSION_C  != \
      WDG_43_INSTANCE0_AR_RELEASE_MINOR_VERSION) || \
      (WDG_43_INSTANCE0_AR_RELEASE_REVISION_VERSION_C != \
      WDG_43_INSTANCE0_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg.c and Wdg.h are different"
#endif

/* Check if current file and WDG configuration header file are of the same software version */
#if ((WDG_43_INSTANCE0_SW_MAJOR_VERSION_C != \
      WDG_43_INSTANCE0_SW_MAJOR_VERSION) || \
      (WDG_43_INSTANCE0_SW_MINOR_VERSION_C != \
      WDG_43_INSTANCE0_SW_MINOR_VERSION) || \
      (WDG_43_INSTANCE0_SW_PATCH_VERSION_C != \
      WDG_43_INSTANCE0_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg.c and Wdg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_C_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "MemMap.h"


/**
* @brief   This function initializes the WDG module.
* @details The @p Wdg_Init function shall initialize the Wdg module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in] ConfigPtr     Pointer to configuration set.
*
* @implements      Wdg_InstanceNo_Init_Activity
*
* @api
* @violates @ref Wdg_C_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(void, WDG_CODE) Wdg_Init(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) pConfigPtr)
{
    Wdg_ChannelInit(pConfigPtr, WDG_IPW_INSTANCE0);
}

/**
* @brief   Switches the watchdog into the mode Mode.
* @details By choosing one of a limited number of statically configured
*          settings (e.g. toggle or window watchdog, different timeout periods)
*          the Wdg module and the watchdog hardware can be switched between the
*          following three different watchdog modes using the @p  Wdg_SetMode
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
*                      .
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
* @implements      Wdg_InstanceNo_SetMode_Activity
*
* @api
* @violates @ref Wdg_C_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode(CONST(WdgIf_ModeType, AUTOMATIC) Mode)
{
    return Wdg_ChannelSetMode(Mode, WDG_IPW_INSTANCE0);
}


/**
 * @brief   Reset the watchdog timeout counter according to the timeout value passed.
 * @details 
 *
 * @param[in] Timeout value (milliseconds) for setting the trigger counter.
 * 
 * @implements      Wdg_InstanceNo_SetTriggerCondition_Activity
 *
 * @api
 * @violates @ref Wdg_C_REF_3 MISRA 2004 Rule 5.1 
 * @violates @ref Wdg_C_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 * functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition(CONST(uint16, WDG_CONST) u16Timeout)
{
    Wdg_ChannelSetTriggerCondition(u16Timeout, WDG_IPW_INSTANCE0);
}

        
#if (WDG_VERSION_INFO_API == STD_ON)

/**
* @brief   Returns the version information of the module.
* @details The Wdg_ChannelGetVersionInfo function shall return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*          .
*
* @pre    This function is only required if the WDG_VERSION_INFO_API has to be
*         equal STD_ON.
*
* @param[in,out] pVersioninfo   Pointer to where to store the version
*                              information of this module.
*
* @api
*
* @implements     Wdg_InstanceNo_GetVersionInfo_Activity
* @violates @ref Wdg_C_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(void, WDG_CODE) Wdg_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) pVersioninfo)
{
    Wdg_ChannelGetVersionInfo(pVersioninfo, WDG_IPW_INSTANCE0);
}
#endif /* WDG_VERSION_INFO_API == STD_ON */

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_C_REF_1 MISRA 2004 Required Rule 19.15
* @violates @ref Wdg_C_REF_4 MISRA 2004 Rule 19.1
*/
#include "MemMap.h"

#endif /*#if (WDG_INSTANCE0 == STD_ON)*/
#ifdef __cplusplus
}
#endif

/** @} */
