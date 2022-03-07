/**
*   @file    Gpt_NonASR.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - GPT Driver non AUTOSAR source file.
*   @details GPT driver source file, containing the non Autosar API specification and other variables
*            and functions that are exported by the GPT driver.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS_Stm_Pit_Rtc
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
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
* @section GPT_NonASR_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_NonASR_C_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability..
*
* @section GPT_NonASR_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_NonASR_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
* @section GPT_NonASR_C_REF_6
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability.
*
* @section GPT_NonASR_C_REF_7
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the use of pointer arithmatic, which is used for the speed optimization,
* the indexing of the pointer is taken care and hence the unintended memory location will not be
* accessed.
*
* @section GPT_NonASR_C_REF_8
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt_NonASR.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT02700, DGPT02200
*/
#include "Gpt.h"
#include "Gpt_NonASR.h"
#include "Gpt_LLD.h"
#if (GPT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_NonASR.c
* @requirements   BSW00374, BSW00318
*/
#define GPT_VENDOR_ID_NONASR_C                    43
/* @violates @ref GPT_NonASR_C_REF_2 Violates MISRA 2004 Required Rule 1.4, Identifier clash*/
/* @violates @ref GPT_NonASR_C_REF_8 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MAJOR_VERSION_NONASR_C     4
/* @violates @ref GPT_NonASR_C_REF_2 Violates MISRA 2004 Required Rule 1.4, Identifier clash*/
/* @violates @ref GPT_NonASR_C_REF_8 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_MINOR_VERSION_NONASR_C     0
/* @violates @ref GPT_NonASR_C_REF_2 Violates MISRA 2004 Required Rule 1.4, Identifier clash*/
/* @violates @ref GPT_NonASR_C_REF_8 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_REVISION_VERSION_NONASR_C  3
#define GPT_SW_MAJOR_VERSION_NONASR_C             1
#define GPT_SW_MINOR_VERSION_NONASR_C             0
#define GPT_SW_PATCH_VERSION_NONASR_C             1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_NONASR_C != GPT_VENDOR_ID)
    #error "Gpt_NonASR.c and Gpt.h have different vendor IDs"
#endif
/* @requirements GPT256 */
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_NONASR_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_NONASR_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_NONASR_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_NonASR.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_NONASR_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_NONASR_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_NONASR_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_NonASR.c and Gpt.h are different"
#endif

/* @requirements GPT256 */
/* Check if source file and DET header file are of the same Autosar version */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((GPT_AR_RELEASE_MAJOR_VERSION_NONASR_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (GPT_AR_RELEASE_MINOR_VERSION_NONASR_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Gpt_NonASR.c and Det.h are different"
        #endif
    #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* GPT_DEV_ERROR_DETECT */

/* Check if source file and GPT_LLD header file are of the same vendor */
#if (GPT_VENDOR_ID_NONASR_C != GPT_LLD_VENDOR_ID)
    #error "Gpt_NonASR.c and Gpt_LLD.h have different vendor IDs"
#endif
/* @requirements GPT256 */
/* Check if source file and Gpt_LLD header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_NONASR_C != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_NONASR_C != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_NONASR_C != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "Autosar Version Numbers of Gpt_NonASR.c and Gpt_LLD.h are different"
#endif
/* Check if source file and Gpt_LLD header file are of the same Software Version */
#if ((GPT_SW_MAJOR_VERSION_NONASR_C != GPT_LLD_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_NONASR_C != GPT_LLD_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_NONASR_C != GPT_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_NonASR.c and Gpt_LLD.h are different"
#endif

/* Check if source file and Gpt_NonASR header are of the same vendor */
#if (GPT_VENDOR_ID_NONASR_C != GPT_VENDOR_ID_NONASR_H)
    #error "Gpt_NonASR.c and Gpt_NonASR.h have different vendor ids"
#endif
/* @requirements GPT256 */
/* Check if source file and Gpt_NonASR header are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_NONASR_C != GPT_AR_RELEASE_MAJOR_VERSION_NONASR_H) || \
     (GPT_AR_RELEASE_MINOR_VERSION_NONASR_C != GPT_AR_RELEASE_MINOR_VERSION_NONASR_H) || \
     (GPT_AR_RELEASE_REVISION_VERSION_NONASR_C != GPT_AR_RELEASE_REVISION_VERSION_NONASR_H))
    #error "AutoSar Version Numbers of Gpt_NonASR.c and Gpt_NonASR.h are different"
#endif
/* Check if source file and Gpt_NonASR.h are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_NONASR_C != GPT_SW_MAJOR_VERSION_NONASR_H) || \
     (GPT_SW_MINOR_VERSION_NONASR_C != GPT_SW_MINOR_VERSION_NONASR_H) || \
     (GPT_SW_PATCH_VERSION_NONASR_C != GPT_SW_PATCH_VERSION_NONASR_H))
    #error "Software Version Numbers of Gpt_NonASR.c and Gpt_NonASR.h are different"
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
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_NonASR_C_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (GPT_DUAL_CLOCK_MODE == STD_ON)

/*================================================================================================*/
/**
* @brief     This function changes the channel prescaler.
* @details   This function sets all channels prescalers based on the input mode.
*
* @param[in] clkMode   prescaler setting ( NORMAL or ALTERNATE )
*
* @pre     Gpt_Init must be called before.
*
* @implements     DGPT02202
*
* @note Implements NonAutosar functionality
*/
/* @violates @ref GPT_NonASR_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_SetClockMode(VAR(Gpt_ClockModeType, AUTOMATIC) clkMode)
{

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID,
                                               (uint8)GPT_SET_CLOCK_MODE_ID, (uint8)GPT_E_UNINIT);
    }
    else if ((GPT_NORMAL != clkMode) && (GPT_ALTERNATE != clkMode))
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)0U, (uint8)GPT_SET_CLOCK_MODE_ID,
                                                          (uint8)GPT_E_PARAM_CLOCK_MODE);
    }
    else
#endif /* GPT_DEV_ERROR_DETECT */
    {
        Gpt_LLD_SelectPrescaler(clkMode);
    }
}
#endif /* GPT_DUAL_CLOCK_MODE */
/*================================================================================================*/

/*================================================================================================*/
#ifdef GPT_CHANGE_NEXT_TIMEOUT_VALUE
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief     This function changes the timeout period value of requested channel.
* @details   This function changes the timeout period (in number of ticks) of requested channel after a notification shall occur.
*
* @param[in]     channel        channel id
* @param[in]     value          timeout period (in number of ticks) after a notification shall occur
*
* @pre     Gpt_Init & Gpt_StartTimer must be called before.
*
* @implements     PR-MCAL-3307, DGPT02203
*
* @note Implements NonAutosar functionality
*/
/* @violates @ref GPT_NonASR_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_ChangeNextTimeoutValue(VAR(Gpt_ChannelType, AUTOMATIC) channel, VAR(Gpt_ValueType, AUTOMATIC) value)
{

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* @violates @ref GPT_NonASR_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */ 
    VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;

    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID, (uint8)GPT_E_UNINIT);
    }
    /* @violates @ref GPT_NonASR_C_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    else if ((channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count) || (GPT_CH_MODE_CONTINUOUS != Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr[channel].Gpt_ChannelMode))
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
        /* Enter critical section */
        Gpt_Schm_ProtectResource((Gpt_ChannelType)2*channel);

        returnCode = Gpt_LLD_CheckStartTimeoutValue(channel, value);

        /* Exit critical section */
        Gpt_Schm_UnprotectResource((Gpt_ChannelType)2*channel);

        if ((GPT_E_PARAM_VALUE == returnCode) || ((Gpt_ValueType)0 == value ))
        {
            /* Call Det_ReportError */
            Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID, (uint8)GPT_E_PARAM_VALUE);
        }
        else
        {
#endif
            /* Call low level function to changes the timeout period  value */
            Gpt_LLD_ChangeNextTimeoutValue(channel, value);
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}
#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */
#endif
/*================================================================================================*/
#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_NonASR_C_REF_1 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
/* @violates @ref GPT_NonASR_C_REF_3 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
