/**
*   @file    Gpt_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - GPT driver source file.
*   @details GPT driver source file, containing the C implementation of functions prototypes that:
*            - are Autosar specific and are not exported by the GPT driver.
*            - are not related to the GPT driver related IPs.    
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
* @section GPT_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* This violation is due to large macro name. This is maintained for better readability.
*
* @section GPT_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the use of pointer arithmatic, which is used for the speed optimization,
* the indexing of the pointer is taken care and hence the unintended memory location will not be
* accessed.
*
* @section GPT_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability.
*
* @section GPT_LLD_C_REF_6
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The pointer is used only within scope.
*
* @section GPT_LLD_C_REF_7
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the Casting pointers to other types used in macros
* for Reading or writing data from address location of controller register.
*
* @section GPT_LLD_C_REF_8
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section GPT_LLD_C_REF_9
* Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope
* If a variable to be used within a Function in the same file use Static.Similarly if a function is called 
* from elsewhere within the same file use Static.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt_LLD.c
* @requirements   BSW00374, BSW00318
* @implements     DGPT03901
*/
#include "Gpt.h"
#include "Gpt_LLD.h"
#include "Gpt_eMIOS_LLD.h"
#include "Reg_eSys_eMIOS.h"
#include "Gpt_Stm_LLD.h"
#include "Reg_eSys_Stm.h"
#include "Gpt_Pit_LLD.h"
#include "Reg_eSys_Pit.h"
#include "Gpt_Rtc_LLD.h"
#include "Reg_eSys_Rtc.h"

#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief   Source file version information
* @requirements BSW00374, BSW00379, BSW00318
* @{
*/
#define GPT_LLD_VENDOR_ID                      43
/* @violates @ref GPT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_LLD_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref GPT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_LLD_AR_RELEASE_MINOR_VERSION_C     0
/* @violates @ref GPT_LLD_C_REF_3 Violates MISRA 2004 Required Rule 1.4, Identifier clash */
/* @violates @ref GPT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1,
* The long identifiers are maintained for better readability. */
#define GPT_LLD_AR_RELEASE_REVISION_VERSION_C  3
#define GPT_LLD_SW_MAJOR_VERSION_C             1
#define GPT_LLD_SW_MINOR_VERSION_C             0
#define GPT_LLD_SW_PATCH_VERSION_C             1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (GPT_LLD_VENDOR_ID != GPT_VENDOR_ID)
    #error "Gpt_LLD.c and Gpt.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Gpt.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_LLD.c and Gpt.h are different"
#endif

#if (GPT_LLD_VENDOR_ID != GPT_LLD_VENDOR_ID)
    #error "Gpt_LLD.c and Gpt_LLD.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Gpt_LLD.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != GPT_LLD_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != GPT_LLD_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != GPT_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_LLD.c and Gpt_LLD.h are different"
#endif

#if (GPT_LLD_VENDOR_ID != GPT_EMIOS_LLD_H_VENDOR_ID)
    #error "Gpt_LLD.c and Gpt_eMIOS_LLD.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Gpt_eMIOS_LLD.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != GPT_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != GPT_EMIOS_LLD_H_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != GPT_EMIOS_LLD_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_LLD.c and Gpt_eMIOS_LLD.h are different"
#endif

#if (GPT_LLD_VENDOR_ID != GPT_STM_LLD_VENDOR_ID)
    #error "Gpt_LLD.c and Gpt_Stm_LLD.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_STM_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_STM_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_STM_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Gpt_Stm_LLD.hare different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != GPT_STM_LLD_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != GPT_STM_LLD_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != GPT_STM_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_LLD.c and Gpt_Stm_LLD.hare different"
#endif

#if (GPT_LLD_VENDOR_ID != GPT_PIT_LLD_VENDOR_ID)
    #error "Gpt_LLD.c and Gpt_Pit_LLD.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_PIT_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_PIT_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_PIT_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Gpt_Pit_LLD.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != GPT_PIT_LLD_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != GPT_PIT_LLD_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != GPT_PIT_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_LLD.c and Gpt_Pit_LLD.h are different"
#endif

#if (GPT_LLD_VENDOR_ID != GPT_RTC_LLD_VENDOR_ID)
    #error "Gpt_LLD.c and Gpt_Rtc_LLD.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != GPT_RTC_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != GPT_RTC_LLD_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != GPT_RTC_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Gpt_Rtc_LLD.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != GPT_RTC_LLD_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != GPT_RTC_LLD_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != GPT_RTC_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_LLD.c and Gpt_Rtc_LLD.h are different"
#endif

#if (GPT_LLD_VENDOR_ID != REG_ESYS_STM_VENDOR_ID)
    #error "Gpt_LLD.c and Reg_eSys_Stm.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_STM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Reg_eSys_Stm.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != REG_ESYS_STM_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != REG_ESYS_STM_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != REG_ESYS_STM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_LLD.c and Reg_eSys_Stm.h are different"
#endif

#if (GPT_LLD_VENDOR_ID != REG_ESYS_PIT_VENDOR_ID)
    #error "Gpt_LLD.c and Reg_eSys_Pit.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_PIT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Reg_eSys_Pit.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != REG_ESYS_PIT_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != REG_ESYS_PIT_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != REG_ESYS_PIT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_LLD.c and Reg_eSys_Pit.h are different"
#endif

#if (GPT_LLD_VENDOR_ID != REG_ESYS_RTC_VENDOR_ID)
    #error "Gpt_LLD.c and Reg_eSys_Rtc.h have different vendor ids"
#endif
#if ((GPT_LLD_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RTC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_LLD.c and Reg_eSys_Rtc.h are different"
#endif
#if ((GPT_LLD_SW_MAJOR_VERSION_C != REG_ESYS_RTC_SW_MAJOR_VERSION) || \
     (GPT_LLD_SW_MINOR_VERSION_C != REG_ESYS_RTC_SW_MINOR_VERSION) || \
     (GPT_LLD_SW_PATCH_VERSION_C != REG_ESYS_RTC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_LLD.c and Reg_eSys_Rtc.h are different"
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
#define GPT_START_SEC_VAR_NO_INIT_32
/* @violates @ref GPT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
/** 
* @brief Array of data structure elements storing timeout, channel mode, wakeup and notification 
*        information.
*
* @implements DGPT03303
*/
VAR(Gpt_LLD_ChannelInfoType, GPT_VAR) Gpt_LLD_ChannelInfo[GPT_HW_CHANNEL_NUM];
/** 
* @brief Array of data structure elements storing channel mode, wakeup and notification 
*        information.
*
* @implements
*/
VAR(uint8, GPT_VAR) Gpt_LLD_ChannelBitInfo[GPT_HW_CHANNEL_NUM];
#define GPT_STOP_SEC_VAR_NO_INIT_32
/* @violates @ref GPT_LLD_C_REF_2 Repeated include file MemMap.h */
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

/* @violates @ref GPT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_LLD_C_REF_2 Repeated include file MemMap.h */
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"
/**
* @brief Pointer to a data structure containing channel configuration information (set in tresos)
*
* @implements DGPT03302
*
* @note       Possible values:
*             0xffu                   : channel not configured
*             "logical channel" index : channel configured and logical channel index (channel index 
*                                       configured in tresos) is corresponding to HW channel
*             This is mainly used for determining the GPT interrupt source
*/
P2CONST(Gpt_LLD_ChannelConfigType, GPT_VAR, GPT_APPL_CONST) Gpt_LLD_ChannelConfigPtr = NULL_PTR;
/* @violates @ref GPT_LLD_C_REF_8 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref GPT_LLD_C_REF_2 Repeated include file MemMap.h */
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"

#define GPT_START_SEC_VAR_NO_INIT_8
/* @violates @ref GPT_LLD_C_REF_2 Repeated include file MemMap.h */
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "MemMap.h"
/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for EMIOS:
*
* @implements DGPT03306
*/
VAR(uint8, GPT_VAR) GPT_LLD_EMIOS_HardwareMap[GPT_EMIOS_CHAN_NUM];

/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for PIT:
*
* @implements DGPT03304
*/
VAR(uint8, GPT_VAR) GPT_LLD_PIT_HardwareMap[GPT_PIT_CHAN_NUM];

/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for STM:
*
* @implements DGPT03305
*/
VAR(uint8, GPT_VAR) GPT_LLD_STM_HardwareMap[GPT_STM_CHAN_NUM];

/** 
* @brief  Array containing "HW channel" vs "logical channel correspondence" for RTC:
*
* @implements DGPT03319
*/
VAR(uint8, GPT_VAR) GPT_LLD_RTC_HardwareMap[GPT_RTC_CHAN_NUM];

#define GPT_STOP_SEC_VAR_NO_INIT_8
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#if (GPT_PRECOMPILE_SUPPORT == STD_ON)

#define GPT_START_SEC_CONST_UNSPECIFIED
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

    
#define GPT_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent initialization function. 
* @details This function is called only once and sets up all the channels in the used configuration. 
*          It initializes the internal GPT driver variables and arrays and calls the IP-specific 
*          initialization function.
*
* @implements DGPT03301
*/
FUNC (void, GPT_CODE) Gpt_LLD_Init(void)
{
    VAR(Gpt_ChannelType, AUTOMATIC) hwChannel;
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;

    /* Clear hardware channel map and set global initialization */
    
    for (channelIndex = GPT_LOOP_INIT; channelIndex < (Gpt_ChannelType)GPT_EMIOS_CHAN_NUM; channelIndex++)
    {
        GPT_LLD_EMIOS_HardwareMap[channelIndex] = 0xffu;
    }

    for (channelIndex = GPT_LOOP_INIT; channelIndex < (Gpt_ChannelType)GPT_PIT_CHAN_NUM; channelIndex++)
    {
        GPT_LLD_PIT_HardwareMap[channelIndex] = 0xffu;
    }

    for (channelIndex = GPT_LOOP_INIT; channelIndex < (Gpt_ChannelType)GPT_STM_CHAN_NUM; channelIndex++)
    {
        GPT_LLD_STM_HardwareMap[channelIndex] = 0xffu;
    }
    for (channelIndex = GPT_LOOP_INIT; channelIndex < (Gpt_ChannelType)GPT_RTC_CHAN_NUM; channelIndex++)
    {
        GPT_LLD_RTC_HardwareMap[channelIndex] = 0xffu;
    }
    
    for (channelIndex = GPT_LOOP_INIT; channelIndex < (Gpt_ChannelType)GPT_HW_CHANNEL_NUM; channelIndex++)
    {
        /* Clear Notification, GPT MODE  */
        Gpt_LLD_ChannelBitInfo[channelIndex] = GPT_INDEX_ZERO;

        /* Reset Load value */
        Gpt_LLD_ChannelInfo[channelIndex].Gpt_ReloadValue = GPT_INDEX_ZERO;

        /* Reset Stop value */
        Gpt_LLD_ChannelInfo[channelIndex].Gpt_StopValue = GPT_INDEX_ZERO;
    }

    Gpt_LLD_ChannelConfigPtr = Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr;

    
    /* De-initialze the used channels before. The new requirement PR-MCAL-3337:
    Rationale: Peripherals (e.g. CAN, SPI) may be used by customer (e.g. by boot loader) in advance. 
    While passing execution to AUTOSAR application, the initialization routine must be able to cope 
    with this situation and properly initialize the peripheral, even if the peripheral might already 
    be initialized (not in reset state) */
    for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
    {
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        module_type = Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Module;
        switch(module_type)
        {
        case GPT_EMIOS_MODULE:
#if (GPT_DEINIT_API == STD_ON)
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_DeInit(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
#endif            
            break;
        case GPT_PIT_MODULE:
#if (GPT_DEINIT_API == STD_ON)        
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_DeInit(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
#endif            
            break;
        case GPT_STM_MODULE:
#if (GPT_DEINIT_API == STD_ON)        
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Stm_LLD_DeInit(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
#endif            
            break;
        case GPT_RTC_MODULE:
#if (GPT_DEINIT_API == STD_ON)        
            Rtc_LLD_DeInit();
#endif            
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DEINIT_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
        }
    }

    /* Save copy of current hardware channel number in local variable */
    for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
    {
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        hwChannel = Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel;
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        module_type = Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Module;

        /* Store Channel Mode (ONE_SHOT / CONTINUOUS) this macro does not set any registers*/
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        GPT_SET_CHANNEL_MODE(channelIndex, (uint8) Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelMode);
        
        /* call the LLD level function for this module */
        switch(module_type)
        {
        case GPT_EMIOS_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_InitChannel(hwChannel, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_FreezeEnable);
            GPT_LLD_EMIOS_HardwareMap[hwChannel] = channelIndex;
            break;
        case GPT_PIT_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_InitChannel(hwChannel, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_FreezeEnable);
            GPT_LLD_PIT_HardwareMap[hwChannel] = channelIndex;
            break;
        case GPT_STM_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Stm_LLD_InitChannel(hwChannel, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_FreezeEnable);
            GPT_LLD_STM_HardwareMap[hwChannel] = channelIndex;
            break;
        case GPT_RTC_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Rtc_LLD_InitChannel((Rtc_Gpt_LLD_ChannelClkSrcType)Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelClkSrc, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_FreezeEnable);
            GPT_LLD_RTC_HardwareMap[hwChannel] = channelIndex;
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_INIT_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
        }


        Gpt_ChannelStatus[channelIndex] = GPT_STATUS_INITIALIZED;
    }
}

#if (GPT_DEINIT_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent de-initialization function. 
* @details This function is called only once and sets up all the channels from the current configuration. 
*          It de-initializes the internal GPT driver variables and calls the IP-specific de-initialization function.
*
* @pre     On/Off by the configuration parameter: GPT_DEINIT_API
*
* @implements DGPT03302
*/
FUNC (void, GPT_CODE) Gpt_LLD_DeInit(void)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;

    for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
    {
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        module_type = Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Module;
        switch(module_type)
        {
        case GPT_EMIOS_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_DeInit(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            break;
        case GPT_PIT_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_DeInit(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            break;
        case GPT_STM_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Stm_LLD_DeInit(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            break;
        case GPT_RTC_MODULE:
            Rtc_LLD_DeInit();
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DEINIT_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
        }
    }
    
    /* Reset ChannelConfig pointer */
    Gpt_LLD_ChannelConfigPtr = NULL_PTR;
}
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for fetching the elapsed timer value. 
* @details It determines the type of the HW channel (e.g. eMIOS, STM,etc...) and calls the
*         appropriate IP function for reading the HW timer and then it calculates the 
*         elapsed timer value.
*
* @param[in]     channel         Numeric identifier of the GPT channel
* @param[out]    returnValuePtr  Pointer to elapsed timer value
*
* @pre     On/Off by the configuration parameter: GPT_TIME_ELAPSED_API
*
* @implements DGPT03206
*/
FUNC (void, GPT_CODE) Gpt_LLD_GetTimeElapsed(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                             P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;
    if(GPT_STATUS_RUNNING == Gpt_ChannelStatus[channel])
    {
        switch(module_type)
        {
            case GPT_EMIOS_MODULE:
            /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Emios_LLD_GetTime(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, returnValuePtr);
                break;
            case GPT_PIT_MODULE:
            /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Pit_LLD_GetTime(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, returnValuePtr);
                break;
            case GPT_STM_MODULE:
            /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Stm_LLD_GetTime(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, returnValuePtr);
                break;
            case GPT_RTC_MODULE:
                Rtc_LLD_GetTime(Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue, returnValuePtr);
                break;
            default:
                Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_TIMEELAPSED_ID, (uint8)GPT_CER_WRONGMODULE);
                /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
                break;    
        }
    }
    else  if(GPT_STATUS_EXPIRED == Gpt_ChannelStatus[channel])
    {
        *returnValuePtr = Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue;
    }
    else if(GPT_STATUS_STOPPED == Gpt_ChannelStatus[channel])
    {
        *returnValuePtr = Gpt_LLD_ChannelInfo[channel].Gpt_StopValue;
    }
    else
    {
        /* Do nothing. Empty else added to fix MISRA Violation*/
    }
}
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for fetching the remaining timer value. 
* @details It determines the type of the HW channel (e.g. eMIOS, STM,etc...) and calls the
*          appropriate IP function for reading the HW timer and then it calculates the 
*          remaining timer value.
*
* @param[in]     channel         Numeric identifier of the GPT channel
* @param[out]    returnValuePtr  Pointer to elapsed timer value
*
* @pre     On/Off by the configuration parameter: GPT_TIME_REMAINING_API
*
* @implements DGPT03205
*/
FUNC (void, GPT_CODE) Gpt_LLD_GetTimeRemaining(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                                         P2VAR(Gpt_ValueType, AUTOMATIC, GPT_APPL_DATA) returnValuePtr)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    VAR(Gpt_ChannelType, AUTOMATIC) channel_type;
    VAR(uint32, GPT_VAR) u32Temp;
    VAR(Gpt_ChannelType, AUTOMATIC) mIdx;   /* assigned eMIOS HW module  index */
    VAR(Gpt_ChannelType, AUTOMATIC) chIdx;  /* assigned eMIOS HW channel index */
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;
    if(GPT_STATUS_RUNNING == Gpt_ChannelStatus[channel])
    {
        switch(module_type)
        {
        case GPT_EMIOS_MODULE:
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_GetTime(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, returnValuePtr);
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            if(GPT_CH_MODE_ONESHOT == (uint8)Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode)
            {
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            channel_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel;
            mIdx  = (uint8)((uint8)channel_type >> (uint8)5U);
            chIdx = (uint8)((uint8)channel_type &  (uint8)0x1FU);
            /* @violates @ref GPT_LLD_C_REF_7 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            u32Temp = REG_READ32(EMIOS_CSR(mIdx, chIdx));
            u32Temp &= CSR_FLAG_MASK;
                if(CSR_FLAG_MASK == u32Temp)
                {
                    *returnValuePtr = (Gpt_ValueType)0;
                }
            }
                break;
            case GPT_PIT_MODULE:
            /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_GetTime(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, returnValuePtr);
            /* @violates @ref GPT_LLD_C_REF_7 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            u32Temp = REG_READ32(PIT_TFLG(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel));
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            if((GPT_CH_MODE_ONESHOT  == (uint8)Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode) && (PIT_TFLG_TIF == u32Temp))
            {
                *returnValuePtr = (Gpt_ValueType)0;
            }
            break;
        case GPT_STM_MODULE:
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            Stm_LLD_GetTime(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, returnValuePtr);
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            /* @violates @ref GPT_LLD_C_REF_7 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            u32Temp = STM_CH_READ_ISR_REQ(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            if((GPT_CH_MODE_ONESHOT == (uint8)Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode) && (STM_CIR_CLEAR == u32Temp))
            {
                *returnValuePtr = (Gpt_ValueType)0;
            }
            break;
        case GPT_RTC_MODULE:
            Rtc_LLD_GetTime(Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue, returnValuePtr);
            /* @violates @ref GPT_LLD_C_REF_7 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
            u32Temp = RTC_READ_API_INTERRUPT();
            /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            if((GPT_CH_MODE_ONESHOT == (uint8)Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode) && (RTC_APIF_MASK == u32Temp))
            {
                *returnValuePtr = (Gpt_ValueType)0;
            }
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_TIMEREMAINING_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
        break;
        }
        *returnValuePtr = Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue - *returnValuePtr;
    }
    else if(GPT_STATUS_STOPPED == Gpt_ChannelStatus[channel])
    {
        *returnValuePtr = Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue - Gpt_LLD_ChannelInfo[channel].Gpt_StopValue;
    }
    else if(GPT_STATUS_EXPIRED == Gpt_ChannelStatus[channel])
    {
        /* @violates @ref GPT_LLD_C_REF_5 MISRA 2004 Rule 10.1, Implicit conversion changes signedness */
        *returnValuePtr = 0;
    }
    else
    {
        /* Do nothing. Empty else added to fix MISRA Violation*/
    }
}
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for checking the timeout value of
*          a channel. 
* @details It determines the type of the HW channel (e.g. eMIOS, STM,etc...) and checks the
*          provided value against the maximum supported HW value.
*
* @param[in]     channel       Numeric identifier of the GPT channel
* @param[in]     value         Timeout period (in ticks) after which a notification shall occur (if 
*                              enabled).
*
* @pre     On/Off by the configuration parameter: GPT_DEV_ERROR_DETECT
*
* @implements DGPT03214
*/
FUNC (Std_ReturnType, GPT_CODE) Gpt_LLD_CheckStartTimeoutValue(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                                               VAR(Gpt_ValueType, AUTOMATIC) value)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;    
        /* @violates @ref GPT_LLD_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    VAR(Std_ReturnType, AUTOMATIC) returnCode = E_OK;
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;
    switch(module_type)
    {
    case GPT_EMIOS_MODULE:
        if(EMIOS_LLD_INVALID_TIMEOUT_VALUE(value))
        {
            returnCode = GPT_E_PARAM_VALUE;
        }
        break;
    case GPT_RTC_MODULE:
        if(RTC_LLD_INVALID_TIMEOUT_VALUE(value))
        {
            returnCode = GPT_E_PARAM_VALUE;
        }
        break;
    case GPT_PIT_MODULE:
        /* @violates @ref GPT_LLD_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
        returnCode = E_OK;
        break;
    case GPT_STM_MODULE:
        /* @violates @ref GPT_LLD_C_REF_5 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
        returnCode = E_OK;
        break;
    default:
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_CHECKTIMEOUTVALUE_ID, (uint8)GPT_CER_WRONGMODULE);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
        break;
    }
    
    return returnCode;
}
#endif

/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for starting the timer channel.
* @details It determines the type of the HW channel (e.g. eMios, STM,etc...), calculates
*          its ID and calls the appropriate IP function for starting the timer channel.
*
* @param[in]     channel       Numeric identifier of the GPT channel
* @param[in]     value         Timeout period (in ticks) after which a notification shall occur (if 
*                              enabled).
*
* @implements DGPT03203
*/
FUNC (void, GPT_CODE) Gpt_LLD_StartTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel,
                                         VAR(Gpt_ValueType, AUTOMATIC) value)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;
    switch(module_type)
    {
    case GPT_EMIOS_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        Emios_LLD_StartTimer(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, value , Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode);
        break;
    case GPT_PIT_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        Pit_LLD_StartTimer(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, value, Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode);
        break;
    case GPT_STM_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        Stm_LLD_StartTimer(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, value);
        break;
    case GPT_RTC_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        Rtc_LLD_StartTimer(value, Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode, &Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue);
        break;
    default:
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STARTTIMER_ID, (uint8)GPT_CER_WRONGMODULE);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
        break;
    }
    /* Save desired value in ReloadValue */
    Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue = value;
}

/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for stopping the timer channel. 
* @details It determines the type of the HW channel (e.g. eMios, STM,etc...), calculates 
*          its ID and calls the appropriate IP function for stopping the timer channel.
*
* @param[in]     channel       Numeric identifier of the GPT channel
*
* @implements DGPT03204
*/
FUNC (void, GPT_CODE) Gpt_LLD_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    VAR(Gpt_ValueType, AUTOMATIC) curTime = GPT_INDEX_ZERO;
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;
    switch(module_type)
    {
    case GPT_EMIOS_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
        Emios_LLD_StopTimer(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, &curTime);
        break;
    case GPT_PIT_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
        Pit_LLD_StopTimer(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, &curTime);
        break;
    case GPT_STM_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
        Stm_LLD_StopTimer(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel, &curTime);
        break;
    case GPT_RTC_MODULE:
        /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
        Rtc_LLD_StopTimer(&curTime);
        break;
    default:
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_STOPTIMER_ID, (uint8)GPT_CER_WRONGMODULE);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
        break;
    }

    if(GPT_STATUS_EXPIRED == Gpt_ChannelStatus[channel])
    {
        Gpt_LLD_ChannelInfo[channel].Gpt_StopValue = Gpt_LLD_ChannelInfo[channel].Gpt_ReloadValue;
    }
    else if(GPT_STATUS_RUNNING == Gpt_ChannelStatus[channel])
    {
        Gpt_LLD_ChannelInfo[channel].Gpt_StopValue = curTime;
    }
    else
    {
        /* Do nothing. Empty else added to fix MISRA Violation*/
    }
}

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for setting the SLEEP mode. 
* @details For each of the configured channels, it determines the type of the HW channel 
*          (e.g. eMIOS, STM,etc...) and stops the non-wake-up capable channel. The wake-up capable 
*          channels are not stopped. 
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*
* @implements DGPT03210
*/
/* @violates @ref GPT_LLD_C_REF_9 Violates MISRA 2004 Required Rule 8.10, This function was used in
* other file but misra tool can not find it when GPT_REPORT_WAKEUP_SOURCE == STD_OFF
*/
FUNC (void, GPT_CODE) Gpt_LLD_SetSleepMode(void)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    VAR(Gpt_ValueType, AUTOMATIC) curTime = GPT_INDEX_ZERO;
    
    for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
    {
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        module_type = Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Module;
        switch(module_type)
        {
        case GPT_EMIOS_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_SetSleepMode(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel,
        /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
                                    (boolean)(GPT_GET_WAKE_UP(channelIndex)), &curTime);
            if (GPT_WAKE_UP_DISABLED == GPT_GET_WAKE_UP(channelIndex))
            {
                if(GPT_NOTIFICATION_ENABLED == GPT_GET_NOTIFICATION(channelIndex))
                {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    Emios_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
                }
            }
            else
            {
            /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Emios_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            }
            break;
        case GPT_PIT_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_SetSleepMode(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel,
        /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
                                    (boolean)(GPT_GET_WAKE_UP(channelIndex)), &curTime);
            if (GPT_WAKE_UP_DISABLED == GPT_GET_WAKE_UP(channelIndex))
            {
                if(GPT_NOTIFICATION_ENABLED == GPT_GET_NOTIFICATION(channelIndex))
                {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    Pit_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
                }
            }
            else
            {
            /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Pit_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            }
            break;
        case GPT_STM_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
            Stm_LLD_StopTimer(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel, &curTime);
            break;
        case GPT_RTC_MODULE:
            /* @violates @ref GPT_LLD_C_REF_6 Violates MISRA 2004 Required Rule 1.2, taking address of near auto variable */
            Rtc_LLD_SetSleepMode((boolean)(GPT_GET_WAKE_UP(channelIndex)), &curTime);
            if (GPT_WAKE_UP_DISABLED == GPT_GET_WAKE_UP(channelIndex))
            {
                if(GPT_NOTIFICATION_ENABLED == GPT_GET_NOTIFICATION(channelIndex))
                {
                    Rtc_LLD_DisableNotification();
                }
            }
            else
            {
                Rtc_LLD_EnableNotification();
            }
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_SETMODE_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
        }
        if(GPT_STATUS_EXPIRED == Gpt_ChannelStatus[channelIndex])
        {
            Gpt_LLD_ChannelInfo[channelIndex].Gpt_StopValue = Gpt_LLD_ChannelInfo[channelIndex].Gpt_ReloadValue;
        }
        else if(GPT_STATUS_RUNNING == Gpt_ChannelStatus[channelIndex])
        {
            Gpt_LLD_ChannelInfo[channelIndex].Gpt_StopValue = curTime;
        }
        else
        {
            /* Do nothing. Empty else added to fix MISRA Violation*/
        }
        
        if ((boolean)FALSE == (GPT_GET_WAKE_UP(channelIndex)))
        {
            Gpt_ChannelStatus[channelIndex] = GPT_STATUS_STOPPED;
        }
    }
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for setting the Normal mode. 
* @details For each of the configured channels, it determines the type of the HW channel 
*          (e.g. STM, PIT, eTimeretc...) and enables the ocunter for STM channels. 
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*
* @implements DGPT03209
*/
/* @violates @ref GPT_LLD_C_REF_9 Violates MISRA 2004 Required Rule 8.10, This function was used in
* other file but misra tool can not find it when GPT_REPORT_WAKEUP_SOURCE == STD_OFF
*/
FUNC (void, GPT_CODE) Gpt_LLD_SetNormalMode(void)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;
    VAR(Gpt_ChannelType, AUTOMATIC) StmModuleIdx;
    VAR(boolean, AUTOMATIC) atLeastOneStmChannelConfigured[STM_NB_MODULES];
    VAR(boolean, AUTOMATIC) atLeastOneRtcChannelConfigured = (boolean)FALSE;
    /* @violates @ref GPT_LLD_C_REF_5 MISRA 2004 Rule 10.1, Implicit conversion changes signedness */
    for(channelIndex = 0;channelIndex < STM_NB_MODULES; channelIndex++)
    {
        atLeastOneStmChannelConfigured[channelIndex] = (boolean)FALSE;
    }
    
    for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
    {
        
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        switch (Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Module)
        {
        case GPT_STM_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
            StmModuleIdx = ((uint8)Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel & (uint8)STM_MOD_MASK) >> STM_MOD_SHIFT;
            atLeastOneStmChannelConfigured[StmModuleIdx] = (boolean)TRUE;
            break;
        case GPT_RTC_MODULE:
            if (GPT_NOTIFICATION_ENABLED == GPT_GET_NOTIFICATION(channelIndex))
            {
                Rtc_LLD_EnableNotification();
            }
            else
            {
                Rtc_LLD_DisableNotification();
            }
            atLeastOneRtcChannelConfigured = (boolean)TRUE;
            break;
        case GPT_EMIOS_MODULE:
            if (GPT_NOTIFICATION_ENABLED == GPT_GET_NOTIFICATION(channelIndex))
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Emios_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            }
            else
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Emios_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            }
            break;
        case GPT_PIT_MODULE:
            if (GPT_NOTIFICATION_ENABLED == GPT_GET_NOTIFICATION(channelIndex))
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Pit_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            }
            else
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Pit_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel);
            }
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_SETMODE_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
        }
    }
    /* @violates @ref GPT_LLD_C_REF_4 MISRA 2004 Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref GPT_LLD_C_REF_5 MISRA 2004 Rule 10.1, Implicit conversion changes signedness */
    for(channelIndex = 0;channelIndex < STM_NB_MODULES; channelIndex++)
    {
        if((boolean)TRUE == atLeastOneStmChannelConfigured[channelIndex])
        {
        /* @violates @ref GPT_LLD_C_REF_5 MISRA 2004 Rule 10.1, Implicit conversion changes signedness */
            Stm_LLD_SetNormalMode(channelIndex*STM_NUMBER_CHANNEL);
        }
    }
    if((boolean)TRUE == atLeastOneRtcChannelConfigured)
    {
        Rtc_LLD_SetNormalMode();
    }
}
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for enabling the timer channel
*          notification. 
* @details It resets the notification bit-field of Gpt_LLD_ChannelInfo[channel] and determines the 
*          type of the HW channel (e.g. eMIOS, STM,etc...), and enables the corresponding IRQ, for 
*          all the channels except for the STM channels.
*
* @param[in]     channel       Numeric identifier of the GPT channel
*
* @pre     On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
*
* @implements DGPT03207
*/
FUNC (void, GPT_CODE) Gpt_LLD_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;

    GPT_SET_NOTIFICATION(channel, GPT_NOTIFICATION_ENABLED);
    switch(module_type)
    {
    case GPT_EMIOS_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        Emios_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
        break;
    case GPT_PIT_MODULE:
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        Pit_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
        break;
    case GPT_STM_MODULE:        
        break;
    case GPT_RTC_MODULE:
        Rtc_LLD_EnableNotification();
        break;
    default:
        Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_ENABLENOTIFICATION_ID, (uint8)GPT_CER_WRONGMODULE);
        /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
        break;
    }
}
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for disabling the timer channel notification.
* @details It resets the notification bit-field of Gpt_LLD_ChannelInfo[channel] and determines the
*          type of the HW channel (e.g. eMios, STM,etc...), and disables the corresponding IRQ, for
*          all the channels except for the STM channels.
*
* @param[in]     channel       Numeric identifier of the GPT channel
*
* @pre     On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
*
* @implements DGPT03208
*/
FUNC (void, GPT_CODE) Gpt_LLD_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    GPT_SET_NOTIFICATION(channel, GPT_NOTIFICATION_DISABLED);
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if (GPT_CH_MODE_CONTINUOUS == (Gpt_LLD_ChannelConfigPtr[channel].Gpt_ChannelMode))
    {
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;

        switch(module_type)
        {
        case GPT_EMIOS_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
            break;
        case GPT_PIT_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
            break;
        case GPT_STM_MODULE:
            break;
        case GPT_RTC_MODULE:
            Rtc_LLD_DisableNotification();
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DISABLENOTIFICATION_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
        }
    }
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for disabling the wakeup interrupt invocation 
*          of a timer channel. 
* @details It resets the wakeup bit-field of Gpt_LLD_ChannelInfo[channel].
*
* @param[in]     channel       Numeric identifier of the GPT channel
*
* @pre     On/Off by the configuration parameter: GPT_WAKEUP_FUNCTIONALITY_API
*
* @implements DGPT03212
*/
/* @violates @ref GPT_LLD_C_REF_9 Violates MISRA 2004 Required Rule 8.10, This function was used in
* other file but misra tool can not find it when GPT_REPORT_WAKEUP_SOURCE == STD_OFF
*/
FUNC (void, GPT_CODE) Gpt_LLD_DisableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;

    /* Change Wakeup status in the channel info */
    GPT_SET_WAKE_UP(channel, GPT_WAKE_UP_DISABLED);

    switch(module_type)
    {
        case GPT_EMIOS_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
            break;
        case GPT_PIT_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_DisableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
            break;
        case GPT_STM_MODULE:
            break;
        case GPT_RTC_MODULE:
            Rtc_LLD_DisableNotification();
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_DISABLEWAKEUP_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
    }
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for enabling the wakeup interrupt invocation 
*          of a timer channel. 
* @details It sets the wakeup bit-field of Gpt_LLD_ChannelInfo[channel].
*
* @param[in]     channel       Numeric identifier of the GPT channel
*
* @pre  requires GPT_WAKEUP_FUNCTIONALITY_API = STD_ON
*
* @implements DGPT03211
*/
/* @violates @ref GPT_LLD_C_REF_9 Violates MISRA 2004 Required Rule 8.10, This function was used in
* other file but misra tool can not find it when GPT_REPORT_WAKEUP_SOURCE == STD_OFF
*/
FUNC (void, GPT_CODE) Gpt_LLD_EnableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    module_type = Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Module;

    /* Change Wakeup status in the channel info */
    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    if ((boolean)TRUE == Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr[channel].Gpt_EnableWakeup)
    {
        GPT_SET_WAKE_UP(channel, GPT_WAKE_UP_ENABLED);
        switch(module_type)
        {
        case GPT_EMIOS_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Emios_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
            break;
        case GPT_PIT_MODULE:
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            Pit_LLD_EnableNotification(Gpt_LLD_ChannelConfigPtr[channel].Gpt_HW_Channel);
            break;
        case GPT_STM_MODULE:        
            break;
        case GPT_RTC_MODULE:
            Rtc_LLD_EnableNotification();
            break;
        default:
            Cer_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, (uint8)GPT_ENABLEWAKEUP_ID, (uint8)GPT_CER_WRONGMODULE);
            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                            Cer_ReportError() function implementation */
            break;
        }
    }
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/** 
* @brief   Gpt driver Autosar independent and IP dependent function for checking if a GPT channel is the source for
*          wakeup event .
* @details It checks if a GPT channel is the source for wakeup event and calls the ECU state manager
*          service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
*          channel wakeup event. 
*
* @param[in]     wakeupSource        Information on wakeup source to be checked.
*
* @pre  requires GPT_WAKEUP_FUNCTIONALITY_API == STD_ON
*
* @implements DGPT03213
*/
/* @violates @ref GPT_LLD_C_REF_9 Violates MISRA 2004 Required Rule 8.10, This function was used in
* other file but misra tool can not find it when GPT_REPORT_WAKEUP_SOURCE == STD_OFF
*/
FUNC (void, GPT_CODE) Gpt_LLD_Cbk_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;
    for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
    {
        if ((GPT_GET_WAKE_UP(channelIndex) == GPT_WAKE_UP_ENABLED)
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            && (Gpt_Cfg_Ptr->Gpt_ChannelConfigPtr[channelIndex].Gpt_ChannelWakeUpInfo == wakeupSource))
        {
            if (GPT_WAKEUP_YES == GPT_GET_WAKEUP_GEN(channelIndex))
            {
                /* Calling EcuM_SetWakeupEvent */
                EcuM_SetWakeupEvent(wakeupSource);
                GPT_SET_WAKEUP_GEN(channelIndex, GPT_WAKEUP_NO);
                break;
            }
        }
    }
}
#endif

#if (GPT_DUAL_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/** 
* @brief      This function changes the channel prescaler.
* @details    This function sets all channels prescalers based on the input mode.
*
* @param[in]  ClkMode - prescaler setting ( NORMAL or ALTERNATE )
*
* @implements   DGPT03501
*/
FUNC (void, GPT_CODE) Gpt_LLD_SelectPrescaler(VAR(Gpt_ClockModeType, AUTOMATIC) ClkMode)
{
    VAR(Gpt_ChannelType, AUTOMATIC) hwChannel;
    VAR(Gpt_ChannelType, AUTOMATIC) channelIndex;
    VAR(Gpt_ChannelType, AUTOMATIC) module_type;
    VAR(boolean, AUTOMATIC) enableStmCounter = (boolean)FALSE;

    /* Save copy of current hardware channel number in local variable */
    for (channelIndex = GPT_LOOP_INIT; channelIndex < Gpt_Cfg_Ptr->Gpt_Channel_Count; channelIndex++)
    {
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        hwChannel = Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Channel;
        /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        module_type = Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_HW_Module;

        /* call the LLD level function for this module */
        if(GPT_EMIOS_MODULE == module_type)
        {
            if(GPT_NORMAL == ClkMode)
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Emios_LLD_SelectPrescaler(hwChannel, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale);
            }
            else
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                if((uint8)0 != (uint8)Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale_Alternate)
                {
                    /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    Emios_LLD_SelectPrescaler(hwChannel, (uint32)Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale_Alternate);
                }
            }
        }
        else if((GPT_STM_MODULE == module_type) && ((boolean)FALSE == enableStmCounter))
        {
            if (GPT_NORMAL == ClkMode)
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Stm_LLD_SelectPrescaler(hwChannel, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale);
                enableStmCounter = (boolean)TRUE;
            }
            else
            {
                /* @violates @ref GPT_LLD_C_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                Stm_LLD_SelectPrescaler(hwChannel, Gpt_LLD_ChannelConfigPtr[channelIndex].Gpt_ChannelPrescale_Alternate);
                enableStmCounter = (boolean)TRUE;
            }
        }
        else
        {
            /* For Misra Complaince */
        }
    }
}
#endif /* GPT_DUAL_CLOCK_MODE == STD_ON */

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_LLD_C_REF_1 Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_LLD_C_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
