/**
*   @file    Dio_Siul_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio low level SIUL code.
*   @details This file is the SIUL DIO low level driver code.
*
*   @addtogroup SIUL_DIO
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
===================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_Siul_LLD_C_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management.
*
* @section Dio_Siul_LLD_C_REF_2
*          Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
*          This violation is due to the pointer arithematic used to write or read
*          the data to or from the registers.
*
* @section Dio_Siul_LLD_C_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
*          31 character significance and case sensitivity are supported for external identifiers
*          This violation is due to the requirement that requests to have a file version check.
*
* @section Dio_Siul_LLD_C_REF_4
*          Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
*          order to prevent the contents of a header file being included twice.
*          Because of Autosar requirement MEMMAP003 of memory mapping
* 
* @section Dio_Siul_LLD_C_REF_5
*          Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
*          Many type conversions are implemented in MACROS. The code was tested successfully with 3 different compilers.
*
* @section Dio_Siul_LLD_C_REF_6
*          Violates MISRA 2004 Required Rule 10.5, Shift left of signed quantity(int),
*          FALSE: the quantity is unsigned.
*
* @section Dio_Siul_LLD_C_REF_7
*          Violates MISRA 2004 Required Rule 5.1,
*          Identifiers (internal and external) shall not rely on the significance of more than 31
*          characters.
*
* @section Dio_Siul_LLD_C_REF_8
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
*          functions at file scope shall have internal linkage unless external linkage is required.
*          State variables may be used by LLD layer.
*
* @section Dio_Siul_LLD_C_REF_9
*          Violates MISRA 2004 Required Rule 8.1 ,  Functions shall have prototype and prototype shall 
*          be visible at both the definition and call
*
*
*
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dio.h"
#include "Reg_Macros.h"
#include "Reg_eSys_SIUL.h"
#include "SchM_Dio.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SIUL_DIO_VENDOR_ID_LLD_C                    43
/*
* @violates @ref Dio_Siul_LLD_C_REF_3 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref Dio_Siul_LLD_C_REF_7 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define SIUL_DIO_AR_RELEASE_MAJOR_VERSION_LLD_C     4
/*
* @violates @ref Dio_Siul_LLD_C_REF_3 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref Dio_Siul_LLD_C_REF_7 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define SIUL_DIO_AR_RELEASE_MINOR_VERSION_LLD_C     0
/*
* @violates @ref Dio_Siul_LLD_C_REF_3 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref Dio_Siul_LLD_C_REF_7 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define SIUL_DIO_AR_RELEASE_REVISION_VERSION_LLD_C  3
#define SIUL_DIO_SW_MAJOR_VERSION_LLD_C             1
#define SIUL_DIO_SW_MINOR_VERSION_LLD_C             0
#define SIUL_DIO_SW_PATCH_VERSION_LLD_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Reg_eSys_SIUL.h version check start */
#if ((SIUL_DIO_AR_RELEASE_MAJOR_VERSION_LLD_C != SIUL_AR_RELEASE_MAJOR_VERSION_REG) || \
    (SIUL_DIO_AR_RELEASE_MINOR_VERSION_LLD_C != SIUL_AR_RELEASE_MINOR_VERSION_REG) || \
    (SIUL_DIO_AR_RELEASE_REVISION_VERSION_LLD_C != SIUL_AR_RELEASE_REVISION_VERSION_REG))
    #error "AUTOSAR Version Numbers of Siul_Dio_LLD.c and Reg_eSys_SIUL.h are different"
#endif

#if ((SIUL_DIO_SW_MAJOR_VERSION_LLD_C != SIUL_SW_MAJOR_VERSION_REG) || \
     (SIUL_DIO_SW_MINOR_VERSION_LLD_C != SIUL_SW_MINOR_VERSION_REG)) ||\
     (SIUL_DIO_SW_PATCH_VERSION_LLD_C != SIUL_SW_PATCH_VERSION_REG)
    #error "Software Version Numbers of Siul_Dio_LLD.c and Reg_eSys_SIUL.h are different"
#endif

#if ((SIUL_DIO_VENDOR_ID_LLD_C != SIUL_VENDOR_ID_REG))
    #error "VENDOR ID for Siul_Dio_LLD.c and Reg_eSys_SIUL.h is different"
#endif
/* Reg_eSys_SIUL.h version check end */

/* Dio.h version check start */
#if ((SIUL_DIO_AR_RELEASE_MAJOR_VERSION_LLD_C != DIO_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL_DIO_AR_RELEASE_MINOR_VERSION_LLD_C != DIO_AR_RELEASE_MINOR_VERSION) || \
     (SIUL_DIO_AR_RELEASE_REVISION_VERSION_LLD_C != DIO_AR_RELEASE_REVISION_VERSION) )
     #error "AUTOSAR Version Numbers of Siul_Dio_LLD.c and Dio.h are different"
#endif

#if ((SIUL_DIO_SW_MAJOR_VERSION_LLD_C != DIO_SW_MAJOR_VERSION) || \
     (SIUL_DIO_SW_PATCH_VERSION_LLD_C != DIO_SW_PATCH_VERSION) || \
     (SIUL_DIO_SW_MINOR_VERSION_LLD_C != DIO_SW_MINOR_VERSION))
    #error "Software Version Numbers of Siul_Dio_LLD.c and Dio.h are different"
#endif
#if (SIUL_DIO_VENDOR_ID_LLD_C != DIO_VENDOR_ID)
    #error "VENDOR ID for Siul_Dio_LLD.c and Dio.h is different"
#endif
/* Dio.h version check end */

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

#define DIO_START_SEC_CODE
/** @violates @ref Dio_Siul_LLD_C_REF_1
    MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
    before '#include'.*/
/**
* @violates @ref Dio_Siul_LLD_C_REF_4 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#if (DIO_REVERSEPORTBITS == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief          Reverses bits in a 16 bits word.
*
* @param[in]      Level       Bits to be reversed.
*
* @return         The reversed 16 bits word.
*
* @pre            This function can be used only if @p DIO_REVERSEPORTBITS is
*                 enabled.
*/
STATIC FUNC(Dio_PortLevelType, DIO_CODE) reverse_bits16
(
    VAR(Dio_PortLevelType, DIO_CODE) Level
)
/* 
* @violates @ref Dio_Siul_LLD_C_REF_9 MISRA 2004 Advisory Rule 1.4,Functions shall have prototype and prototype shall 
*                            be visible at both the definition and call 
*/
{
    /* r will be reversed bits of Level; first get LSB of Level */
/*
* @violates @ref Dio_Siul_LLD_C_REF_8 ,All declarations and definitions of objects or
  functions at file scope shall have internal linkage unless external linkage is required
*/
    VAR(Dio_PortLevelType, DIO_VAR) r = Level;
/* 
* @violates @ref Dio_Siul_LLD_C_REF_5 :Implicit conversion changes signedness.
*/
    VAR(uint16, DIO_VAR) s = 15; /* count shifts needed due to trailing 0s */
/* 
* @violates @ref Dio_Siul_LLD_C_REF_5 :Implicit conversion changes signedness.
*/
    Level= (uint16)(Level>>1);
/* 
* @violates @ref Dio_Siul_LLD_C_REF_5 Required Rule 10.5, Shift left of signed quantity(int),FALSE: the quantity is unsigned.
*/
    for (; Level!=0; Level >>= 1)
    {
        r = (uint16)(r<<1);
        r = (uint16)(r |((uint16)(Level & (uint16)1)));
        s--;
    }
/* 
* @violates @ref Dio_Siul_LLD_C_REF_6 :Implicit conversion changes signedness.
*/
   r = (uint16)(r<<s); /* shift when v's highest bits are zero */
    return r;
}
#endif /* DIO_REVERSEPORTBITS == STD_ON */

/*****************************************************************************
    Global functions
*****************************************************************************/

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
* @requirements   .
* @implements     DDIO05002.
*/
FUNC (Dio_LevelType, DIO_CODE) Dio_SIUL_ReadChannel
(
    CONST(Dio_ChannelType, DIO_CONST) ChannelId
)
{
    VAR(Dio_LevelType, DIO_VAR) value;
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    if ((REG_READ16(SIUL_PCR((uint32)(ChannelId)))) & SIUL_PCR_IBE_ON)
    {
        /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
        value = (Dio_LevelType)(REG_READ8(SIUL_GPDI((uint32)(ChannelId))));
    }
    else
    {
        /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
        value = (Dio_LevelType)(REG_READ8(SIUL_GPDO((uint32)(ChannelId))));
    }
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
* @requirements   .
* @implements     DDIO05005.
*/
FUNC (void, DIO_CODE) Dio_SIUL_WriteChannel
(
    CONST(Dio_ChannelType, DIO_CONST) ChannelId,
    CONST(Dio_LevelType, DIO_CONST) Level
)
{
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    REG_WRITE8(SIUL_GPDO(ChannelId), (Level));
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
* @requirements   .
* @implements     DDIO05001.
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_SIUL_FlipChannel
(
    CONST(Dio_ChannelType, DIO_CONST) ChannelId
)
{
    VAR(Dio_LevelType, DIO_VAR) value;

    SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00();
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    if ((REG_READ16(SIUL_PCR((uint32)(ChannelId)))) & SIUL_PCR_OBE_ON)
    {
        /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
        if ((Dio_LevelType)(REG_READ8(SIUL_GPDO((uint32)(ChannelId)))) == (Dio_LevelType)STD_LOW)
        {
            value = (Dio_LevelType)STD_HIGH;
        }
        else
        {
            value = (Dio_LevelType)STD_LOW;
        }
        /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
        REG_WRITE8(SIUL_GPDO(ChannelId), value);
    }
    else {
        /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
        value = (Dio_LevelType)(REG_READ8(SIUL_GPDI((uint32)(ChannelId))));
    }
    SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00();
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
* @requirements   .
* @implements     DDIO05004.
*/
FUNC (Dio_PortLevelType, DIO_CODE) Dio_SIUL_ReadPort
(
    CONST(Dio_PortType, DIO_CONST) PortId
)
{
#if DIO_READZERO_UNDEFINEDPORTS == STD_OFF
#if DIO_REVERSEPORTBITS == STD_ON
/* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    return reverse_bits16((uint16)(REG_READ16(SIUL_PGPDI(((uint32)(PortId) << 1UL)))));
#else
/* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    return (uint16)(REG_READ16(SIUL_PGPDI(((uint32)(PortId) << 1UL))));
#endif
#else
#if (DIO_REVERSEPORTBITS == STD_ON)
/* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    return reverse_bits16((uint16)(REG_READ16(SIUL_PGPDI((uint32)(PortId) << 1UL))) & undefined_portmask[PortId]);
#else
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    return (uint16)((REG_READ16(SIUL_PGPDI((uint32)(PortId) << 1UL))) & undefined_portmask[PortId]);
#endif
#endif
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
* @requirements   .
* @implements     DDIO05007.
*/
FUNC (void, DIO_CODE) Dio_SIUL_WritePort
(
    CONST(Dio_PortType, DIO_CONST) PortId,
    CONST(Dio_PortLevelType, DIO_CONST) Level
)
{
#if DIO_REVERSEPORTBITS == STD_ON
/* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    REG_WRITE16(SIUL_PGPDO(((uint32)(PortId) << 1UL)), (reverse_bits16(Level)));
#else
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    REG_WRITE16(SIUL_PGPDO(((uint32)(PortId) << 1UL)), (Level));
#endif
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
* @requirements   .
* @implements     DDIO05003.
*/
FUNC (Dio_PortLevelType, DIO_CODE) Dio_SIUL_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
)
{
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    return (Dio_PortLevelType)(((REG_READ16(SIUL_PGPDI(((uint32)(ChannelGroupIdPtr->port) << (uint32)1UL)))) &
                                (ChannelGroupIdPtr->mask)) >> (ChannelGroupIdPtr->offset));
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
* @requirements   .
* @implements     DDIO05006.
*/
FUNC (void, DIO_CODE) Dio_SIUL_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST(Dio_PortLevelType, DIO_CONST) Level
)
{
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    REG_WRITE32(SIUL_MPGPDO((uint32)((uint32)(ChannelGroupIdPtr->port) << (DIO_PORTID_SHIFT))), ((((uint32)(Level) << (ChannelGroupIdPtr->offset)) & (DIO_CHANNELGRP_OFFSET_PINS)) | (((uint32)(ChannelGroupIdPtr->mask) << (DIO_CHANNELGRP_MASK_PINS)))));
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
* @requirements   .
* @implements     DDIO05009.
*/
FUNC (void, DIO_CODE) Dio_SIUL_MaskedWritePort
(
    CONST(Dio_PortType, DIO_CONST) PortId,
    CONST(Dio_PortLevelType, DIO_CONST) Level,
    CONST(Dio_PortLevelType, DIO_CONST) Mask
)
{
    /* @violates @ref Dio_Siul_LLD_C_REF_2 MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.*/
    REG_WRITE32(SIUL_MPGPDO((uint32) ((uint32) PortId << DIO_PORTID_SHIFT)), (((uint32) Mask << DIO_CHANNELGRP_MASK_PINS) | (uint32)Level));
}
#endif /* DIO_MASKEDWRITEPORT_API == STD_ON */

#define DIO_STOP_SEC_CODE
/** @violates @ref Dio_Siul_LLD_C_REF_1
    MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
    before '#include'.*/
/**
* @violates @ref Dio_Siul_LLD_C_REF_4 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
