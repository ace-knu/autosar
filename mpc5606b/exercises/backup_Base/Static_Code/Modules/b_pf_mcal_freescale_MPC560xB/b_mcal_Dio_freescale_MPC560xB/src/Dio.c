/**
*   @file    Dio.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio high level code.
*   @details This file contains the Autosar DIO driver high level code.
*
*   @addtogroup DIO_HLD
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : SIUL
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
* @section Dio_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Dio_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Dio_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 
* 31 character signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Dio_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
* functions at file scope shall have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section Dio_C_REF_5
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @implements    DDIO00002.*/
#include "Dio.h"
/* @implements    DDIO00009.*/
#if (DIO_DEV_ERROR_DETECT == STD_ON) || defined(__DOXYGEN__)
    /* @implements DDIO02001.*/
    #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*
* @implements     .
*/
#define DIO_VENDOR_ID_C                      43
#define DIO_AR_RELEASE_MAJOR_VERSION_C       4
#define DIO_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Dio_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref Dio_C_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_AR_RELEASE_REVISION_VERSION_C    3
#define DIO_SW_MAJOR_VERSION_C               1
#define DIO_SW_MINOR_VERSION_C               0
#define DIO_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* @implements    DDIO03008.*/
/* Check if current file and DIO header file are of the same vendor.*/
#if (DIO_VENDOR_ID_C != DIO_VENDOR_ID)
    #error "Dio.c and Dio.h have different vendor ids"
#endif

/* Check if current file and DIO header file are of the same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION_C    != DIO_AR_RELEASE_MAJOR_VERSION) || \
     (DIO_AR_RELEASE_MINOR_VERSION_C    != DIO_AR_RELEASE_MINOR_VERSION) || \
     (DIO_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Dio.c and Dio.h are different"
#endif

/* Check if current file and DIO header file are of the same Software version.*/
#if ((DIO_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION))
    #error "Software Version Numbers of Dio.c and Dio.h are different"
#endif

/* Check if current file and DET header file are of the same version.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (DIO_DEV_ERROR_DETECT == STD_ON)
        #if ((DIO_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (DIO_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Dio.c and Det.h are different"
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
/*
* @violates @ref Dio_C_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_START_SEC_VAR_INIT_UNSPECIFIED
/* @implements  DDIO00008.*/
/* 
* @violates @ref Dio_C_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice 
*/
#include "MemMap.h"

/**
* @brief          Current configuration pointer.
*
* @implements     DDIO03029.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
P2CONST(Dio_ConfigType, DIO_VAR, DIO_APPL_CONST) Dio_CurrentConfigPtr = NULL_PTR;

/*
* @violates @ref Dio_C_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DIO_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @implements  DDIO00008.*/
/* 
* @violates @ref Dio_C_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice 
*/
/* @violates @ref Dio_C_REF_2 only preprocessor statements and comments before '#include'. */
#include "MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define DIO_START_SEC_CODE
/* @implements DDIO00008.*/
/* 
* @violates @ref Dio_C_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice 
*/
/* @violates @ref Dio_C_REF_2 only preprocessor statements and comments before '#include'. */
#include "MemMap.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief          DIO pin check.
* @details        Verifies if the specified channel is valid.
*
* @param[in]      ChannelId   Channel id to be checked.
*
* @return                     Return a value 0 or 1 according to the received
*                             parameter.
* @retval 0                   If the pin is valid.
* @retval 1                   If the pin is invalid.
*
* @pre            This function can be used only if @p DIO_DEV_ERROR_DETECT
*                 is enabled.
*/
STATIC FUNC(uint8, DIO_CODE) invalid_pin
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(uint8, AUTOMATIC) error = (uint8)1;
    VAR(Dio_ChannelType, AUTOMATIC) i = (Dio_ChannelType)0;

    for (i = (Dio_ChannelType)0; i < DIO_PIN_INTERVALS; i += (Dio_ChannelType)2)
    {
        if ((valid_pin_ranges[i] <= ChannelId) &&
            (ChannelId <= valid_pin_ranges[i + (Dio_ChannelType)1]))
        {
            error = (uint8)0;
            break;
        }
    }
    return error;
}

/*================================================================================================*/
/*
* @brief          DIO port check.
* @details        Verifies if the specified port is valid.
*
* @param[in]      PortId      Port id to be checked.
*
* @return                     Return a value 0 or 1 according to the received
*                             parameter.
* @retval 0                   If the pin is valid.
* @retval 1                   If the pin is invalid.
*
* @pre            This function can be used only if @p DIO_DEV_ERROR_DETECT
*                 is enabled.
*/
STATIC FUNC(uint8, DIO_CODE) invalid_port
(
    CONST(Dio_PortType, AUTOMATIC) PortId
)
{
    VAR(uint8, AUTOMATIC) error = (uint8)1;
    VAR(uint8, AUTOMATIC) i = (uint8)0;

    for (i = (uint8)0; i < DIO_PORT_INTERVALS; i += (uint8)2)
    {
        if ((valid_port_ranges[i] <= PortId) &&
            (PortId <= valid_port_ranges[i + (uint8)1]))
        {
            error = (uint8)0;
            break;
         }
    }
    return error;
}
#endif /* DIO_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          Driver initialization.
* @details        This function must be invoked before the driver can be used.
*
* @param[in]      ConfigPtr   Pointer to the configuration data.
*
* @implements     DDIO03012.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, DIO_CODE) Dio_Init
(
    P2CONST(Dio_ConfigType, AUTOMATIC, DIO_APPL_CONST) ConfigPtr
)
{
        /* @implements DDIO06042.*/
#if defined(DIO_PRECOMPILE_SUPPORT)
        Dio_CurrentConfigPtr = &Dio_ConfigPC;
#else
    /* @implements DDIO06029, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* @implements DDIO06005.*/
    if (NULL_PTR == ConfigPtr)
    {
        /* @implements DDIO06006.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_INIT_ID, DIO_E_PARAM_CONFIG);
    }
    else /* @implements DDIO06007.*/
#endif /* DIO_DEV_ERROR_DETECT == STD_ON */
    {
        Dio_CurrentConfigPtr = ConfigPtr;
    }
#endif
}

/* @implements DDIO06039.*/
#if (DIO_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief          Service to get the version information of this module.
* @details        The @p Dio_GetVersionInfo() function shall return the version
*                 information of this module. The version information includes:
*                 - Module Id.
*                 - Vendor Id.
*                 - Vendor specific version numbers.
*                 .
*
* @param[in,out]  versioninfo Pointer to where to store the version
*                             information of this module.
*
* @pre            This function can be used only if @p DIO_VERSION_INFO_API
*                 has been enabled.
*
* @implements     DDIO03030.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, DIO_CODE) Dio_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) versioninfo
)
{
    /* @implements DDIO06030, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* @implements DDIO06040.*/
    if (NULL_PTR == versioninfo)
    {
        /* @implements DDIO06014.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_GETVERSIONINFO_ID,
                        DIO_E_PARAM_POINTER);
    }
    else /* @implements DDIO06041.*/
#endif /* DIO_DEV_ERROR_DETECT == STD_ON */
    {
        /* @implements DDIO06054.*/
        versioninfo->vendorID = (uint16)DIO_VENDOR_ID;
        versioninfo->moduleID = (uint16)DIO_MODULE_ID;
        versioninfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
    }
}
#endif /* DIO_VERSION_INFO_API == STD_ON */

/*================================================================================================*/
/**
* @brief          Returns the value of the specified DIO channel.
* @details        This function returns the value of the specified DIO channel.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*
* @implements     DDIO03002.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    /* @implements DDIO06031.*/
    VAR(Dio_LevelType, AUTOMATIC) value = (Dio_LevelType) STD_LOW;
    
    /* @implements DDIO06015, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* @implements DDIO06016.*/
    if (invalid_pin(ChannelId))
    {
        /* @implements DDIO06002.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_READCHANNEL_ID,DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif /* DIO_DEV_ERROR_DETECT */
    {
        /* @implements DDIO06047.*/
        value = Dio_LLD_ReadChannel(ChannelId);
    }
    /* @implements DDIO06032.*/
    return value;
}

/*================================================================================================*/
/**
* @brief          Sets the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall set the specified level on the
*                 specified channel. If the specified channel is configured
*                 as an input channel, this function shall have no influence
*                 on the physical output and on the result of the next read
*                 service.
*
* @param[in]      ChannelId   Specifies the required channel id.
* @param[in]      Level       Specifies the channel desired level.
*
* @implements     DDIO03005.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType, AUTOMATIC) Level
)
{
    /* @implements DDIO06017, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* @implements DDIO06018.*/
    if (invalid_pin(ChannelId))
    {
        /* @implements DDIO06004.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_WRITECHANNEL_ID,DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else /* @implements DDIO06036.*/
#endif /* DIO_DEV_ERROR_DETECT */
    {
        /* @implements DDIO06050.*/
        Dio_LLD_WriteChannel(ChannelId, Level);
    }
}

#if (DIO_FLIP_CHANNEL_API == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief          Inverts the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall invert the level of the specified
*                 channel. If the specified channel is configured as an
*                 input channel, this function shall have no influence
*                 on the physical output and on the result of the next
*                 read service.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*
* @pre            This function can be used only if @p DIO_FLIP_CHANNEL_API
*                 has been enabled.
*
* @implements     DDIO03001.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    /* @implements DDIO06033.*/
    VAR(Dio_LevelType, AUTOMATIC) value = (Dio_LevelType) STD_LOW;
    
    /* @implements DDIO06019, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* @implements DDIO06020.*/
    if (invalid_pin(ChannelId))
    {
        /* @implements DDIO06001.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_FLIPCHANNEL_ID,DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif /* DIO_DEV_ERROR_DETECT */
    {
        /* @implements DDIO06048.*/
        value = Dio_LLD_FlipChannel(ChannelId);
    }
    /* @implements DDIO06043.*/
    return value;
}
#endif /* DIO_FLIP_CHANNEL_API == STD_ON */

/*================================================================================================*/
/**
* @brief          Returns the level of all channels of specified port.
* @details        This function will return the level of all channels
*                 belonging to the specified port.
*
* @param[in]      PortId      Specifies the required port id.
*
* @return                     Levels of all channels of specified port.
*
* @implements     DDIO03004.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
)
{
    /* @implements DDIO06035.*/
    VAR(Dio_PortLevelType, AUTOMATIC) value = (Dio_PortLevelType) STD_LOW;
    
    /* @implements DDIO06021, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* @implements DDIO06022.*/
    if (invalid_port(PortId))
    {
        /* @implements DDIO06008.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_READPORT_ID,DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif
    {
        /* @implements DDIO06049.*/
        value = Dio_LLD_ReadPort(PortId);
    }
    /* @implements DDIO06056.*/
    return value;
}

/*================================================================================================*/
/**
* @brief          Sets the value of a port.
* @details        This function will set the specified value on the specified
*                 port.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
*
* @implements     DDIO03007.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, DIO_CODE) Dio_WritePort
(
    CONST(Dio_PortType, AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
)
{
    /* @implements DDIO06023, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* @implements DDIO06024.*/
    if (invalid_port(PortId))
    {
        /* @implements DDIO06009.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_WRITEPORT_ID, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else /* @implements DDIO06038.*/
#endif
    {
        /* @implements DDIO06053.*/
        Dio_LLD_WritePort(PortId, Level);
    }
}

/*================================================================================================*/
/**
* @brief          This service reads a subset of the adjoining bits of a port.
* @details        This function will read a subset of adjoining bits of a
*                 port (channel group).
*
* @param[in]      ChannelGroupIdPtr Pointer to the channel group.
* @return                     The channel group levels.
*
* @implements     DDIO03003.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
)
{
    /* @implements DDIO06034.*/
    VAR(Dio_PortLevelType, AUTOMATIC) value = (Dio_PortLevelType) STD_LOW;

    /* @implements DDIO06025, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* Check Channel Group Ptr ID */
    /* @implements DDIO06026.*/
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        /* @implements DDIO06013.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_READCHANNELGROUP_ID,
                        DIO_E_PARAM_INVALID_GROUP_ID);
    }
    /* Check Port ID */
    else
    {
        /* @implements DDIO06045.*/
        if (invalid_port((ChannelGroupIdPtr)->port))
        {
            /* @implements DDIO06010.*/
            Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                            DIO_READCHANNELGROUP_ID,
                            DIO_E_PARAM_INVALID_PORT_ID);
        }
        else
#endif
        {
            /* @implements DDIO06046.*/
            value = Dio_LLD_ReadChannelGroup(ChannelGroupIdPtr);
        }
#if DIO_DEV_ERROR_DETECT == STD_ON
    }
#endif
    /* @implements DDIO06044.*/
    return value;
}

/*================================================================================================*/
/**
* @brief          Sets a subset of the adjoining bits of a port to the
*                 specified levels.
* @details        This function will set a subset of adjoining bits of a port
*                 (channel group) to the specified levels without changing
*                 the remaining channels of the port and channels that
*                 are configured as input.
*                 This function will do the masking of the channels and will
*                 do the shifting so that the values written by the function
*                 are aligned to the LSB.
*
* @param[in]      ChannelGroupIdPtr Pointer to the channel group.
* @param[in]      Level       Desired levels for the channel group.
*
* @implements     DDIO03006.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, DIO_CODE) Dio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST(Dio_PortLevelType,AUTOMATIC) Level
)
{
    /* @implements DDIO06027, DDIO07001.*/
#if DIO_DEV_ERROR_DETECT == STD_ON
    /* Check Channel Group Ptr ID */
    /* @implements DDIO06028.*/
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        /* @implements DDIO06012.*/
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_WRITECHANNELGROUP_ID,
                        DIO_E_PARAM_INVALID_GROUP_ID);
    }
    else
    {
        /* Check Port ID */
        /* @implements DDIO06052.*/
        if (invalid_port((ChannelGroupIdPtr)->port))
        {
            /* @implements DDIO06011.*/
            Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                            DIO_WRITECHANNELGROUP_ID,
                            DIO_E_PARAM_INVALID_PORT_ID);
        }
        else /* @implements DDIO06037.*/
#endif
        {
            /* @implements DDIO06051.*/
            Dio_LLD_WriteChannelGroup(ChannelGroupIdPtr, Level);
        }
#if DIO_DEV_ERROR_DETECT == STD_ON
    }
#endif
}

#if (DIO_MASKEDWRITEPORT_API == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief          DIO Mask write port using mask.
* @details        Writes a DIO port with masked value.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
* @param[in]      Mask        Specifies the Mask value of the port.
*
* @pre            This function can be used only if @p DIO_MASKEDWRITEPORT_API
*                 has been enabled.
*
* @implements     DDIO03031.
*
* @api
*/
/*
* @violates @ref Dio_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, DIO_CODE) Dio_MaskedWritePort
(
    CONST(Dio_PortType, AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
)
{
#if DIO_DEV_ERROR_DETECT == STD_ON
    if (invalid_port(PortId))
    {
        Det_ReportError((uint16) DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_MASKEDWRITEPORT_ID, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif
    {
        Dio_LLD_MaskedWritePort(PortId, Level, Mask);
    }
}
#endif /* DIO_MASKEDWRITEPORT_API */

#define DIO_STOP_SEC_CODE
/* @implements DDIO00008.*/
/* 
* @violates @ref Dio_C_REF_1 Precautions shall be taken in order to prevent
* the contents of a header file being included twice 
*/
/* @violates @ref Dio_C_REF_2 only preprocessor statements and comments before '#include'. */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
