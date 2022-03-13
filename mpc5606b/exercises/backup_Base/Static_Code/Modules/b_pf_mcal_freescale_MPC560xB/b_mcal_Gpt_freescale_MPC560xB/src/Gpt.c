/**
*   @file    Gpt.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt  - GPT driver source file.
*   @details GPT driver source file, containing the C implementation of Autosar API specification
*            and other variables and functions that are exported by the GPT driver.
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
* @section GPT_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_C_REF_3
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The pointer is used only within scope.
*
* @section GPT_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability.
*
* @section GPT_C_REF_5
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the use of pointer arithmatic, which is used for the speed optimization,
* the indexing of the pointer is taken care and hence the unintended memory location will not be
* accessed.
*
* @section GPT_C_REF_6
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability.
*
* @section GPT_C_REF_7
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*
* @section GPT_C_REF_8
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT02500, DGPT11012, DGPT11022, DGPT02300, DGPT01025
*/
#include "Gpt.h"
#include "Gpt_LLD.h"

#include "SchM_Gpt.h"

#include "Dem.h"
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
/* @violates @ref GPT_C_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @requirements   BSW00374, BSW00318
* @{
*/
#define GPT_VENDOR_ID_C                      43
#define GPT_AR_RELEASE_MAJOR_VERSION_C       4
#define GPT_AR_RELEASE_MINOR_VERSION_C       0
/* @violates @ref GPT_C_REF_4 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_C_REF_8 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_AR_RELEASE_REVISION_VERSION_C    3
#define GPT_SW_MAJOR_VERSION_C               1
#define GPT_SW_MINOR_VERSION_C               0
#define GPT_SW_PATCH_VERSION_C               1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Gpt.c and Gpt.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt.c and Gpt.h are different"
#endif

#if (GPT_VENDOR_ID_C != GPT_LLD_VENDOR_ID)
    #error "Gpt.c and Gpt_LLD.h have different vendor ids"
#endif
/* Check if source file and GPT LLD header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt.c and Gpt_LLD.h are different"
#endif
/* Check if source file and GPT LLD header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_LLD_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_LLD_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt.c and Gpt_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Dem header file are of the same version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt.c and Dem.h are different"
    #endif

    #if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Check if source file and DET header file are of the same version */
        #if ((GPT_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (GPT_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Gpt.c and Det.h are different"
        #endif
    #endif
#endif  /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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
/* @violates @ref GPT_C_REF_8 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref GPT_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/**
* @brief          Global variable used for indicating the current GPT driver mode.
*/
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
VAR(Gpt_ModeType, GPT_VAR) Gpt_Current_Mode = GPT_MODE_NORMAL;

/**
* @brief          Global variable (pointer) used for storing the GPT driver configuration data.
*/
P2CONST(Gpt_ConfigType, GPT_VAR, GPT_APPL_CONST) Gpt_Cfg_Ptr = NULL_PTR;
/* @violates @ref GPT_C_REF_8 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref GPT_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
/* @violates @ref GPT_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

/* @violates @ref GPT_C_REF_8 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
/* @violates @ref GPT_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"
/**
* @brief          Global array used for indicating the current status of the GPT channels.
*/
VAR(Gpt_ChannelStatusType, GPT_VAR) Gpt_ChannelStatus[GPT_HW_CHANNEL_NUM];

/* @violates @ref GPT_C_REF_8 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
/* @violates @ref GPT_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   This function returns the version information of this module.
* @details This service returns the version information of this module. The version information
*          includes:
*                   Module Id
*                   Vendor Id
*                   Vendor specific version numbers (BSW00407).
*
* @param[out]     versioninfo - pointer to location to store version info
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_VERSION_INFO_API
*
* @implements     DGPT02149
*/
#if (GPT_VERSION_INFO_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) versioninfo)
{
#if (STD_ON == GPT_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_GETVERSIONINFO_ID, (uint8)GPT_E_PARAM_POINTER);
    }
    else
#endif
    {
        versioninfo->vendorID         = (uint16)GPT_VENDOR_ID;
        versioninfo->moduleID         = (uint16)GPT_MODULE_ID;
        versioninfo->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
    }
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver initialization function.
* @details Service for driver initialization. The Initialization function shall initialize all
*          relevant registers of the configured hardware with the values of the structure referenced
*          by the parameter ConfigPtr.
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          This function shall only initialize the configured resources. Resources that are
*          not configured in the configuration file shall not be touched.
*          The following rules regarding initialization of controller registers shall apply
*          to the GPT Driver implementation:
*          [1] If the hardware allows for only one usage of the register, the driver
*              module implementing that functionality is responsible for initializing the register
*          [2] If the register can affect several hardware modules and if it is an I/O register it
*              shall be initialized by the PORT driver
*          [3] If the register can affect several hardware modules and if it is not an I/O register
*              it shall be initialized by the MCU driver
*          [4] One-time writable registers that require initialization directly after reset shall be
*              initialized by the startup code
*          [5] All other registers shall be initialized by the startup code
*
* @param[in]     configPtr    Pointer to a selected configuration structure
*
* @api
*
* @implements     DGPT02139, DGPT11011, DGPT11021
*/
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/* If already initialized, error */
    if (NULL_PTR != Gpt_Cfg_Ptr)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_INIT_ID, (uint8)GPT_E_ALREADY_INITIALIZED);
    }

#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
    else if (NULL_PTR == configPtr)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_INIT_ID, (uint8)GPT_E_PARAM_POINTER);
    }
#else
    else if (NULL_PTR != configPtr)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_INIT_ID, (uint8)GPT_E_PARAM_POINTER);
    }
#endif
    else
    {
#endif

#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
        Gpt_Cfg_Ptr = &Gpt_InitConfigPC;
#else
        Gpt_Cfg_Ptr = configPtr;
#endif

        /* Reset Channel STATUS */
        for (channelIndex = GPT_LOOP_INIT; channelIndex < (Gpt_ChannelType)GPT_HW_CHANNEL_NUM; channelIndex++)
        {
            Gpt_ChannelStatus[channelIndex] = GPT_STATUS_UNINITIALIZED;
        }

        Gpt_Current_Mode = GPT_MODE_NORMAL;

        Gpt_LLD_Init();

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/*================================================================================================*/
/**
* @brief   GPT driver de-initialization function.
* @details Service for deinitializing all hardware timer channels to their power on reset
*          state.
*          The state of the peripheral after DeInit shall be the same as after power on
*          reset.
*          The service influences only the peripherals, which are allocated by static
*          configuration and the runtime configuration set passed by the previous call of Gpt_Init()
*          The driver needs to be initialized before calling Gpt_DeInit(). Otherwise, the
*          function Gpt_DeInit shall raise the development error GPT_E_UNINIT and leave the desired
*          deinitialization functionality without any action.
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_DEINIT_API
*
* @implements   DGPT02140, DGPT11010, DGPT11020, DGPT02140
*/
#if (GPT_DEINIT_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_DeInit(void)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/* @violates @ref GPT_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    VAR(StatusType, AUTOMATIC) tempExit = E_OK;
    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DEINIT_ID, (uint8)GPT_E_UNINIT);
        /* @violates @ref GPT_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
        tempExit = E_NOT_OK;
    }
    else
    {
        for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
        {
            if (GPT_STATUS_RUNNING == Gpt_ChannelStatus[channelIndex])
            {
                Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DEINIT_ID, (uint8)GPT_E_BUSY);
                /* @violates @ref GPT_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
                tempExit = E_NOT_OK;
            }
        }
    }
    /* @violates @ref GPT_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    if (E_OK == tempExit)
    {
#endif

        Gpt_LLD_DeInit();

        /* Reset Channel STATUS */
        for (channelIndex = GPT_LOOP_INIT; channelIndex < (Gpt_ChannelType)GPT_HW_CHANNEL_NUM; channelIndex++)
        {
            Gpt_ChannelStatus[channelIndex] = GPT_STATUS_UNINITIALIZED;
        }

        Gpt_Current_Mode = GPT_MODE_NORMAL;
        Gpt_Cfg_Ptr = NULL_PTR;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for fetching the elapsed timer value.
* @details Service for querying the time already elapsed.
*          In one shot mode, this is the value relative to the point in time, the channel has been
*          started with Gpt_StartTimer (calculated by the normal operation function by subtracting
*          the current minus the initial timer value and returning the absolute value).
*          In continuous mode, the function returns the timer value relative to the last timeout/the
*          start of the channel.
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator frequency, pre
*          prescalers and so on. Since these settings are made in MCU and/or in other modules it is
*          not possible to calculate such times. Hence the conversions between time and ticks shall
*          be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_GetTimeElapsed(). Otherwise, the
*          function shall raise the development error GPT_E_UNINIT and return 0.
*
* @param[in]  channel - channel id
*
* @return  Gpt_ValueType - Elapsed Time in number of ticks
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_TIME_ELAPSED_API
*
* @implements DGPT02147
*/
#if (GPT_TIME_ELAPSED_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) tempReturn = 0U;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_TIMEELAPSED_ID, (uint8)GPT_E_UNINIT);
    }
    else if (channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_TIMEELAPSED_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        if (GPT_STATUS_INITIALIZED != Gpt_ChannelStatus[channel])
        {
            /* @violates @ref GPT_C_REF_3 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
            Gpt_LLD_GetTimeElapsed(channel, &tempReturn);
        }
        else
        {
        /* @violates @ref GPT_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
            tempReturn=0;
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (tempReturn);
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for fetching the remaining timer value.
* @details This function returns the timer value remaining until the next timeout period will 
*          expire (calculated by the normal operation function by subtracting the timeout minus
*          the current timer value and returning the absolute value)
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          Usage of re-entrant capability is only allowed if the callers take care that there is no
*          simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator frequency,
*          prescalers and so on. Since these settings are made in MCU and/or in other modules it is
*          not possible to calculate such times. Hence the conversions between time and ticks shall
*          be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_GetTimeRemaining(). Otherwise, the
*          function shall raise the development error GPT_E_UNINIT and return 0.
*
* @param[in]     channel - channel id
*
* @return  Gpt_ValueType - Remaining Time in number of ticks
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_TIME_REMAINING_API
*
* @implements    DGPT02148
*/
#if (GPT_TIME_REMAINING_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_ValueType, AUTOMATIC) tempReturn = 0U;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_TIMEREMAINING_ID, (uint8)GPT_E_UNINIT);
    }
    else if (channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_TIMEREMAINING_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        if (GPT_STATUS_INITIALIZED != Gpt_ChannelStatus[channel])
        {
            /* @violates @ref GPT_C_REF_3 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable  */
            Gpt_LLD_GetTimeRemaining(channel, &tempReturn);
        }
        else
        {
        /* @violates @ref GPT_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
            tempReturn=0;
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return (tempReturn);
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for starting a timer channel.
* @details The function Gpt_StartTimer shall start the selected timer channel with a defined
*          timeout period.
*          The function Gpt_StartTimer shall invoke the configured notification for that channel
*          (see also GPT292) after the timeout period referenced via the parameter value (if
*          enabled).
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          In production mode no error is generated. The rational is that it adds no
*          additional functionality to the driver. In this case the timer will be restarted with the
*          timeout value, given as a parameter to the service.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator
*          frequency, prescalers and so on. Since these settings are made in MCU and/or in other
*          modules it is not possible to calculate such times. Hence the conversions between time and
*          ticks shall be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_StartTimer(). Otherwise, the
*          function Gpt_StartTimer shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
* @param[in]     value          timeout period (in number of ticks) after a notification shall occur
*
* @api
*
* @implements    DGPT02141
*/
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel, VAR(Gpt_ValueType, AUTOMATIC) value)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /* @violates @ref GPT_C_REF_6 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */ 
    VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;

    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STARTTIMER_ID, (uint8)GPT_E_UNINIT);
    }
    else if (channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STARTTIMER_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else if (GPT_STATUS_RUNNING == Gpt_ChannelStatus[channel])
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STARTTIMER_ID, (uint8)GPT_E_BUSY);
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
            Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STARTTIMER_ID, (uint8)GPT_E_PARAM_VALUE);
        }
        else
        {
#endif
        
        /* Enter critical section */ 
        Gpt_Schm_ProtectResource((Gpt_ChannelType)2*channel);

        /* Call low level start timer */
        Gpt_LLD_StartTimer(channel, value);

        /* Change GPT status */
        Gpt_ChannelStatus[channel] = GPT_STATUS_RUNNING;
        
        /* Exit critical section */
        Gpt_Schm_UnprotectResource((Gpt_ChannelType)2*channel);

#if (GPT_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}

/*================================================================================================*/
/**
* @brief   GPT driver function for stopping a timer channel.
* @details Service for stopping the selected timer channel
*          Stopping a timer channel, not been started before will not return a development error
*          Timer channels configured in one shot mode are stopped automatically, when the
*          timeout period has expired.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_StopTimer(). Otherwise,
*          the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @api
*
* @implements   DGPT02142, DGPT11013, DGPT11023, DGPT02142
*/
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STOPTIMER_ID, (uint8)GPT_E_UNINIT);
    }
    else if (channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count)
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STOPTIMER_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        if(GPT_STATUS_RUNNING == Gpt_ChannelStatus[channel])
        {
            Gpt_Schm_ProtectResource((Gpt_ChannelType)2*channel);

            /* Call low level stop timer */
            Gpt_LLD_StopTimer(channel);

            /* Change GPT status */
            Gpt_ChannelStatus[channel] = GPT_STATUS_STOPPED;

            Gpt_Schm_UnprotectResource((Gpt_ChannelType)2*channel);
        }
        else
        {
        /*for MISRA complaince */
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
/*================================================================================================*/
/**
* @brief   GPT driver function for enabling the notification for a timer channel.
* @details Service for enabling the notification for a channel during runtime.
*          This function can be called, while the timer is already running.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_EnableNotification(). Otherwise,
*          the function Gpt_EnableNotification shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
*
* @implements   DGPT02143
*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{

#if (GPT_DEV_ERROR_DETECT == STD_ON)

    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_ENABLENOTIFICATION_ID, (uint8)GPT_E_UNINIT);
    }
    /* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    else if ((channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count) || (NULL_PTR == (Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr)[channel].Gpt_Notification))
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_ENABLENOTIFICATION_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        Gpt_Schm_ProtectResource(((Gpt_ChannelType)2*channel)+(Gpt_ChannelType)1);

        Gpt_LLD_EnableNotification(channel);

        Gpt_Schm_UnprotectResource(((Gpt_ChannelType)2*channel)+(Gpt_ChannelType)1);

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif

}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for disabling the notification for a timer channel.
* @details Service for disabling the notification for a channel during runtime.
*          This function can be called, while the timer is already running
*          When disabled, no notification will be sent. When re-enabled again, the user
*          will not be notified of events, occurred while notifications have been disabled.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_DisableNotification().
*          Otherwise, the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
*
* @implements   DGPT02144
*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)

    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DISABLENOTIFICATION_ID, (uint8)GPT_E_UNINIT);
    }
    /* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    else if ((channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count) || (NULL_PTR == (Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr)[channel].Gpt_Notification))
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DISABLENOTIFICATION_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        Gpt_Schm_ProtectResource(((Gpt_ChannelType)2*channel)+(Gpt_ChannelType)1);

        Gpt_LLD_DisableNotification(channel);

        Gpt_Schm_UnprotectResource(((Gpt_ChannelType)2*channel)+(Gpt_ChannelType)1);

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

/*************************************************************************************************/
/**
* @brief   GPT driver function for setting the operation mode.
* @details Service for GPT mode selection. This service shall set the operation mode to the given
*          mode parameter .
*          When sleep mode is requested, the ECU State Manager calls Gpt_SetMode with mode
*          parameter "GPT_MODE_SLEEP" and prepares the GPT for sleep mode. The MCU Driver is then
*          putting the controller into SLEEP mode
*          The driver needs to be initialized before calling Gpt_SetMode(). Otherwise, the
*          function Gpt_SetMode shall raise the development error GPT_E_UNINIT.
*
* @param[in]     mode        operation mode
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*
* @implements     DGPT02150
*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_SetMode(VAR(Gpt_ModeType, AUTOMATIC) mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON)

    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_SETMODE_ID, (uint8)GPT_E_UNINIT);
    }
    else if ((GPT_MODE_NORMAL != mode) && (GPT_MODE_SLEEP != mode))
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_SETMODE_ID, (uint8)GPT_E_PARAM_MODE);
    }
    else
    {
#endif
        Gpt_Schm_ProtectResource((Gpt_ChannelType)2*GPT_MAX_EXCLUSIVE_AREA);
        if (GPT_MODE_SLEEP == mode)
        {
            Gpt_LLD_SetSleepMode();
        }
        else
        {
            Gpt_LLD_SetNormalMode();
        }
        /* Change power mode status */
        Gpt_Current_Mode = mode;
        Gpt_Schm_UnprotectResource((Gpt_ChannelType)2*GPT_MAX_EXCLUSIVE_AREA);

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
#endif
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for disabling the wakeup interrupt invocation for a timer channel.
* @details This service shall disable the wakeup interrupt invocation of a single GPT
*          channel.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_DisableWakeup(). Otherwise, the
*          function Gpt_DisableWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*
* @api
*
* @implements   DGPT02146
*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_DisableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DISABLEWAKEUP_ID, (uint8)GPT_E_UNINIT);
    }
    /* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    else if ((channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count) || ((uint8)FALSE == Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr[channel].Gpt_EnableWakeup))
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DISABLEWAKEUP_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        /* Call low level function */
        Gpt_LLD_DisableWakeup(channel);

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
#endif
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for enabling the wakeup interrupt invocation for a timer channel.
* @details This service shall re-enable the wakeup interrupt invocation of a single GPT
*          channel.
*          If supported by hardware and enabled, an internal hardware timer can serve as a
*          wakeup source
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*
* @param[in]     channel        channel id
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*
* @implements   DGPT02145
*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_EnableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)

#if (GPT_DEV_ERROR_DETECT == STD_ON)

    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_ENABLEWAKEUP_ID, (uint8)GPT_E_UNINIT);
    }
    /* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    else if ((channel >= Gpt_Cfg_Ptr->Gpt_Channel_Count) || ((uint8)FALSE == Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr[channel].Gpt_EnableWakeup))
    {
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_ENABLEWAKEUP_ID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        /* Call low level function */
        Gpt_LLD_EnableWakeup(channel);

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
#endif
}
#endif


/*================================================================================================*/
/**
* @brief   GPT driver function for checking if a wakeup capable GPT channel is the source for a
*          wakeup event.
* @details Checks if a wakeup capable GPT channel is the source for a wakeup event and calls the ECU
*          state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
*          The driver needs to be initialized before calling Gpt_Cbk_CheckWakeup(). Otherwise, the
*          function Gpt_Cbk_CheckWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]     wakeupSource        wakeup source
*
* @api
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*
* @implements   DGPT02151
*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource)
{

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_Cfg_Ptr)
    {
        /* Call Det_ReportError */
        Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_CHECKWAKEUP_ID, (uint8)GPT_E_UNINIT);
    }
    else
    {
#endif
        Gpt_LLD_Cbk_CheckWakeup(wakeupSource);

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

/*================================================================================================*/
/** 
* @brief   This function is called to enter the specific critical region. 
* @details This is a local function stub only. 
*     
* @param[in]     Gpt_ExclusiveArea     Exclusive area
* @return        void     This function does not return anything
* 
* @pre  None
* @post None
* 
*/
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_Schm_ProtectResource(VAR(uint8, AUTOMATIC) Gpt_ExclusiveArea)
{
    switch(Gpt_ExclusiveArea)
    {
    case 0:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
        break;
    case 1:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01();
        break;
    case 2:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02();
        break;
#if(1U < GPT_MAX_EXCLUSIVE_AREA)
    case 3:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03();
        break;
    case 4:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04();
        break;
#endif
#if(2U < GPT_MAX_EXCLUSIVE_AREA)
    case 5:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05();
        break;
    case 6:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06();
        break;
#endif
#if(3U < GPT_MAX_EXCLUSIVE_AREA)
    case 7:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07();
        break;
    case 8:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08();
        break;
#endif
#if(4U < GPT_MAX_EXCLUSIVE_AREA)
    case 9:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09();
        break;
    case 10:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10();
        break;
#endif
#if(5U < GPT_MAX_EXCLUSIVE_AREA)
    case 11:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11();
        break;
    case 12:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12();
        break;
#endif
#if(6U < GPT_MAX_EXCLUSIVE_AREA)
    case 13:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13();
        break;
    case 14:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14();
        break;
#endif
#if(7U < GPT_MAX_EXCLUSIVE_AREA)
    case 15:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15();
        break;
    case 16:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16();
        break;
#endif
#if(8U < GPT_MAX_EXCLUSIVE_AREA)
    case 17:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17();
        break;
    case 18:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18();
        break;
#endif
#if(9U < GPT_MAX_EXCLUSIVE_AREA)
    case 19:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19();
        break;
    case 20:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20();
        break;
#endif
#if(10U < GPT_MAX_EXCLUSIVE_AREA)
    case 21:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21();
        break;
    case 22:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22();
        break;
#endif
#if(11U < GPT_MAX_EXCLUSIVE_AREA)
    case 23:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23();
        break;
    case 24:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24();
        break;
#endif
#if(12U < GPT_MAX_EXCLUSIVE_AREA)
    case 25:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25();
        break;
    case 26:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26();
        break;
#endif
#if(13U < GPT_MAX_EXCLUSIVE_AREA)
    case 27:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27();
        break;
    case 28:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28();
        break;
#endif
#if(14U < GPT_MAX_EXCLUSIVE_AREA)
    case 29:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29();
        break;
    case 30:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30();
        break;
#endif
#if(15U < GPT_MAX_EXCLUSIVE_AREA)
    case 31:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31();
        break;
    case 32:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_32();
        break;
#endif
#if(16U < GPT_MAX_EXCLUSIVE_AREA)
    case 33:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_33();
        break;
    case 34:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_34();
        break;
#endif
#if(17U < GPT_MAX_EXCLUSIVE_AREA)
    case 35:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_35();
        break;
    case 36:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_36();
        break;
#endif
#if(18U < GPT_MAX_EXCLUSIVE_AREA)
    case 37:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_37();
        break;
    case 38:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_38();
        break;
#endif
#if(19U < GPT_MAX_EXCLUSIVE_AREA)
    case 39:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39();
        break;
    case 40:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_40();
        break;
#endif
#if(20U < GPT_MAX_EXCLUSIVE_AREA)
    case 41:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_41();
        break;
    case 42:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_42();
        break;
#endif
#if(21U < GPT_MAX_EXCLUSIVE_AREA)
    case 43:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_43();
        break;
    case 44:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_44();
        break;
#endif
#if(22U < GPT_MAX_EXCLUSIVE_AREA)
    case 45:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_45();
        break;
    case 46:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_46();
        break;
#endif
#if(23U < GPT_MAX_EXCLUSIVE_AREA)
    case 47:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_47();
        break;
    case 48:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_48();
        break;
#endif
#if(24U < GPT_MAX_EXCLUSIVE_AREA)
    case 49:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_49();
        break;
    case 50:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_50();
        break;
#endif
#if(25U < GPT_MAX_EXCLUSIVE_AREA)
    case 51:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_51();
        break;
    case 52:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_52();
        break;
#endif
#if(26U < GPT_MAX_EXCLUSIVE_AREA)
    case 53:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_53();
        break;
    case 54:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_54();
        break;
#endif
#if(27U < GPT_MAX_EXCLUSIVE_AREA)
    case 55:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_55();
        break;
    case 56:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_56();
        break;
#endif
#if(28U < GPT_MAX_EXCLUSIVE_AREA)
    case 57:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_57();
        break;
    case 58:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_58();
        break;
#endif
#if(29U < GPT_MAX_EXCLUSIVE_AREA)
    case 59:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_59();
        break;
    case 60:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_60();
        break;
#endif
#if(30U < GPT_MAX_EXCLUSIVE_AREA)
    case 61:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_61();
        break;
    case 62:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_62();
        break;
#endif
#if(31U < GPT_MAX_EXCLUSIVE_AREA)
    case 63:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_63();
        break;
    case 64:
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_64();
        break;
#endif
    default:
        Cer_ReportError((uint16)GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SCHM_PROTECTRESOURCE_ID, GPT_CER_WRONGMODULE);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
        break;
    }
}

/*================================================================================================*/
/** 
* @brief   This function is called to exit the specific critical region. 
* @details This is a local function stub only. 
*     
* @param[in]     Gpt_ExclusiveArea     Exclusive area
* @return        void     This function does not return anything
* 
* @pre  None
* @post None
* 
*/
/* @violates @ref GPT_C_REF_7 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC (void, GPT_CODE) Gpt_Schm_UnprotectResource(VAR(uint8, AUTOMATIC) Gpt_ExclusiveArea)
{
    switch(Gpt_ExclusiveArea)
    {
    case 0:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
        break;
    case 1:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01();
        break;
    case 2:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02();
        break;
#if(1U < GPT_MAX_EXCLUSIVE_AREA)
    case 3:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03();
        break;
    case 4:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04();
        break;
#endif
#if(2U < GPT_MAX_EXCLUSIVE_AREA)
    case 5:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05();
        break;
    case 6:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06();
        break;
#endif
#if(3U < GPT_MAX_EXCLUSIVE_AREA)
    case 7:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07();
        break;
    case 8:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08();
        break;
#endif
#if(4U < GPT_MAX_EXCLUSIVE_AREA)
    case 9:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09();
        break;
    case 10:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10();
        break;
#endif
#if(5U < GPT_MAX_EXCLUSIVE_AREA)
    case 11:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11();
        break;
    case 12:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12();
        break;
#endif
#if(6U < GPT_MAX_EXCLUSIVE_AREA)
    case 13:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13();
        break;
    case 14:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14();
        break;
#endif
#if(7U < GPT_MAX_EXCLUSIVE_AREA)
    case 15:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15();
        break;
    case 16:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16();
        break;
#endif
#if(8U < GPT_MAX_EXCLUSIVE_AREA)
    case 17:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17();
        break;
    case 18:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18();
        break;
#endif
#if(9U < GPT_MAX_EXCLUSIVE_AREA)
    case 19:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19();
        break;
    case 20:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20();
        break;
#endif
#if(10U < GPT_MAX_EXCLUSIVE_AREA)
    case 21:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21();
        break;
    case 22:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22();
        break;
#endif
#if(11U < GPT_MAX_EXCLUSIVE_AREA)
    case 23:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23();
        break;
    case 24:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24();
        break;
#endif
#if(12U < GPT_MAX_EXCLUSIVE_AREA)
    case 25:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25();
        break;
    case 26:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26();
        break;
#endif
#if(13U < GPT_MAX_EXCLUSIVE_AREA)
    case 27:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27();
        break;
    case 28:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28();
        break;
#endif
#if(14U < GPT_MAX_EXCLUSIVE_AREA)
    case 29:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29();
        break;
    case 30:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30();
        break;
#endif
#if(15U < GPT_MAX_EXCLUSIVE_AREA)
    case 31:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31();
        break;
    case 32:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_32();
        break;
#endif
#if(16U < GPT_MAX_EXCLUSIVE_AREA)
    case 33:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_33();
        break;
    case 34:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_34();
        break;
#endif
#if(17U < GPT_MAX_EXCLUSIVE_AREA)
    case 35:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_35();
        break;
    case 36:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_36();
        break;
#endif
#if(18U < GPT_MAX_EXCLUSIVE_AREA)
    case 37:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_37();
        break;
    case 38:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_38();
        break;
#endif
#if(19U < GPT_MAX_EXCLUSIVE_AREA)
    case 39:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39();
        break;
    case 40:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_40();
        break;
#endif
#if(20U < GPT_MAX_EXCLUSIVE_AREA)
    case 41:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_41();
        break;
    case 42:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_42();
        break;
#endif
#if(21U < GPT_MAX_EXCLUSIVE_AREA)
    case 43:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_43();
        break;
    case 44:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_44();
        break;
#endif
#if(22U < GPT_MAX_EXCLUSIVE_AREA)
    case 45:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_45();
        break;
    case 46:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_46();
        break;
#endif
#if(23U < GPT_MAX_EXCLUSIVE_AREA)
    case 47:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_47();
        break;
    case 48:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_48();
        break;
#endif
#if(24U < GPT_MAX_EXCLUSIVE_AREA)
    case 49:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_49();
        break;
    case 50:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_50();
        break;
#endif
#if(25U < GPT_MAX_EXCLUSIVE_AREA)
    case 51:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_51();
        break;
    case 52:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_52();
        break;
#endif
#if(26U < GPT_MAX_EXCLUSIVE_AREA)
    case 53:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_53();
        break;
    case 54:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_54();
        break;
#endif
#if(27U < GPT_MAX_EXCLUSIVE_AREA)
    case 55:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_55();
        break;
    case 56:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_56();
        break;
#endif
#if(28U < GPT_MAX_EXCLUSIVE_AREA)
    case 57:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_57();
        break;
    case 58:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_58();
        break;
#endif
#if(29U < GPT_MAX_EXCLUSIVE_AREA)
    case 59:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_59();
        break;
    case 60:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_60();
        break;
#endif
#if(30U < GPT_MAX_EXCLUSIVE_AREA)
    case 61:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_61();
        break;
    case 62:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_62();
        break;
#endif
#if(31U < GPT_MAX_EXCLUSIVE_AREA)
    case 63:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_63();
        break;
    case 64:
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_64();
        break;
#endif
    default:
        Cer_ReportError((uint16)GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_SCHM_UNPROTECTRESOURCE_ID, GPT_CER_WRONGMODULE);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
        break;
    }
}

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
