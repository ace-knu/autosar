/**
*   @file    Can_PBcfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PostBuild.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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
* @section Can_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Can_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_PBcfg_c_REF_5
* Violates MISRA 2004 Required Rule 12.8, The right hand operand of a shift operator shall lie between zero
* and one less than the width in bits of the underlying type of the left hand operand.
*
* @section Can_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 10.5 , If the bitwise operators ~ and << are applied to an operand
* of underlying type unsigned char or unsigned shot, the result shall be immediately cast to the underlying type
* of the operand
* This violation is due to the operator << was used.
*
* @section Can_PBcfg_c_REF_7
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_PBcfg_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.4, a cast should not be performed between a pointer to object
* type and a different pointer to object type.
*
* @section Can_PBcfg_c_REF_9
* Violates MISRA 2004 Required Rule 16.9, a function identifier shall only be used with either a
* preceding &, or with a parenthesised parameter list, which may be empty.
*
* @section Can_PBcfg_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_PBcfg_c_REF_11
* Violates MISRA 2004 Required Rule  8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used
*/

/*
   (CAN078) The code file structure shall not be defined within this specification completely.
            At this point it shall be pointed out that the code-file structure shall include the following file named: Can_PBcfg.c.
            This file shall contain all post-build time configurable parameters.
   (CAN221) VariantPB: (Mix of precompile and Post Build multiple selectable configurable configurations.
*/
/**
* @file           Can_PBcfg.c
* @implements     DCAN02606
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_LLD.h"




/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_PBcfg.c
* @implements     DCAN02606
*/
/* @violates @ref Can_PBcfg_c_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
/* @violates @ref Can_PBcfg_c_REF_3 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C     0
/* @violates @ref Can_PBcfg_c_REF_3 This is required as per autosar Requirement. */
/* @violates @ref Can_PBcfg_c_REF_4 Identifier clash */
#define CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C  3
#define CAN_SW_MAJOR_VERSION_PBCFG_C             1
#define CAN_SW_MINOR_VERSION_PBCFG_C             0
#define CAN_SW_PATCH_VERSION_PBCFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_PBcfg.c and Can.h are different"
#endif

/* Check if current file and MODULENAME header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_PBcfg.c and Can.h are different"
#endif
/* @violates @ref Can_PBcfg_c_REF_3 This is required as per autosar Requirement. */
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#if (CAN_PRECOMPILE_SUPPORT == STD_OFF)

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
/**
@brief    Prototype of User Notifications
*/






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








/*==================================================================================================*/
/**
* @brief          Filter Masks
* @details        Filter Masks
*
* @implements     DCAN02648
*/
/*==================================================================================================*/

/* @violates @ref Can_PBcfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(Can_IdType, CAN_CONST) Can_FilterMasks0_PB[CAN_MAXFILTERCOUNT_0] =
    {   
        /* FilterMasks0[0], "DefaultFilterMask" */
        (Can_IdType)0x7ffU,
        /* FilterMasks0[1], "DefaultExtFilterMask" */
        (Can_IdType)0x1fffffffU
    };




/*==================================================================================================*/
/**
* @brief          Information about message buffers
* @details        (CAN100)Several TX hardware objects with unique HTHs may be configured. The CanIf module provides the HTH as parameter of the TX request. See Figure 7-2 for a possible configuration.
*
* @implements     DCAN02418
*/

/* @violates @ref Can_PBcfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(Can_MBConfigObjectType, CAN_CONST) MessageBufferConfigs0_PB[CAN_MAXMBCOUNT_0] =
    {
        
        
        /* IN_HwObj_ECU1_Project_0x3_ECU2_Msg_OE1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x3U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x0U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* IN_HwObj_ECU1_Project_0x103_ECU2_Msg_POE1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x103U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x1U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* IN_HwObj_ECU1_Project_0x301_ECU2_Msg_PIF1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x301U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x2U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* IN_HwObj_ECU1_Project_0x503_ECU2_Msg_P1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x503U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x3U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* IN_HwObj_ECU1_Project_0x703_GST_Msg_TP_Phys Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x703U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x4U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* IN_HwObj_ECU1_Project_0x706_GST_Msg_TP1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x706U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x5U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* IN_HwObj_ECU1_Project_0x707_GST_Msg_TP2 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x707U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x6U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* IN_HwObj_ECU1_Project_0x7df_GST_Msg_TP_Func Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)CAN_MAXMASKCOUNT,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_RECEIVE,
            /* MessageId */
            (Can_IdType)0x7dfU,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x7U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x100_ECU1_Msg_POE3 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x100U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x8U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x101_ECU1_Msg_POE1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x101U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x9U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x102_ECU1_Msg_POE2 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x102U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0xaU,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x1_ECU1_Msg_OE1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x1U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0xbU,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x200_ECU1_Msg_IF1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x200U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0xcU,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x2_ECU1_Msg_OE2 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x2U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0xdU,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x300_ECU1_Msg_PIF1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x300U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0xeU,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x501_ECU1_Msg_P1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x501U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0xfU,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x502_ECU1_Msg_P2 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x502U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x10U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x55_ECU1_Msg_GW1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x55U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x11U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x601_ECU1_Msg_P3 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x601U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x12U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x602_ECU1_Msg_P4 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x602U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x13U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x701_ECU1_Msg_TP1 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x701U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x14U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x704_ECU1_Msg_TP2 Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x704U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x15U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        },
        
        
        /* OUT_HwObj_ECU1_Project_0x705_ECU1_GST_Msg_TP Message Buffer of Can Controller ID = 0U */
        {
            /* IdMaskIndex */
            (Can_HwHandleType)0U,
            /* ControllerId  - based on the order from CanController list */
            (uint8)0U,
            /* ID type: EXTENDED, STANDARD, MIXED */
            (CanIdType)CAN_STANDARD,
            /* Receive/Transmit MB configuration */
            (Can_ObjType)CAN_TRANSMIT,
            /* MessageId */
            (Can_IdType)0x705U,
            /* Local priority bits used for arbitration */
            (uint8)0x0U,
            /* Hardware Object ID */
            (Can_HwHandleType)0x16U,
            /* Read/Write period reference used when polling mode is selected for the controller */
            (uint8)0U /* HOH configured for interrupt mode, reference not used */
        }
        
    };


/*==================================================================================================*/
/**
* @brief          Configuration of FlexCan controller
* @details        Configuration of FlexCan controller
*
* @implements     DCAN02649
*/


/* @violates @ref Can_PBcfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateCfgSet0_PB_0[CAN_CFGSET0_MAX_BAUDRATE_FC_B_0] = {
        
    /*
        =================================================

        Clock Size = 8000000.0 Hz  - Clock from external OSC.
        
        Clock Prescaler = 1 (1..256)
        
        CanBitRate = 500 Kbps (1bps..1Mbps)
        Number CANTimeQuantas per bit = 16 (8..25)
        
        CTRL Register Fields:
            PSEG1 = 7 (0..7)
            PSEG2 = 3 (1..7)
            PROPSEG = 2 (0..7)
            RJW = 3 (0..3)
        =================================================
    */
    
    /* Configuration for CanController ID0 == FlexCAN_B */
    {
      /* ===== Control Register - CTRL ===== */
        /* CTRL[PRESDIV] - Clock Prescaler */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        (uint32)((0U << FLEXCAN_CTRL_PRESDIV_SHIFT) |
        /* CTRL[RJW] - Resynchronization Jump Width */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (3U << FLEXCAN_CTRL_RJW_SHIFT) |
        /* CTRL[PSEG1] - Segment 1 */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (7U << FLEXCAN_CTRL_PSEG1_SHIFT) |
        /* CTRL[PSEG2] - Segment 2 */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (3U << FLEXCAN_CTRL_PSEG2_SHIFT) |
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (0U << FLEXCAN_CTRL_CLKSRC_SHIFT) |
        /* CTRL[LPB] - Loop-back mode */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (0U << FLEXCAN_CTRL_LPB_SHIFT) |
        /* CTRL[SMP] - Sampling mode */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (0U << FLEXCAN_CTRL_SMP_SHIFT) |
        /* CTRL[BOFF_REC] - Bus off recovery */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (1U << FLEXCAN_CTRL_BOFFREC_SHIFT) |
        /* CTRL[LBUF] - Lowest Buffer Transmitted First */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (0U << FLEXCAN_CTRL_LBUF_SHIFT) |
        /* CTRL[LOM] - Listen only mode */
        /*@violates @ref Can_PBcfg_c_REF_5 The right hand operand of a shift operator shall lie between zero
              and one less than the width in bits of the underlying type of the left hand operand.*/
        /*@violates @ref Can_PBcfg_c_REF_6 Violates MISRA 2004 Required Rule 10.5, the operator << was used. */
        (0U << FLEXCAN_CTRL_LOM_SHIFT) |
        /* CTRL[PROPSEG] - Propagation segment */
        2U) ,

#if (CAN_DUAL_CLOCK_MODE == STD_ON)
        0U,
        
#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */

        (uint16)500   /* 500kbps baud rate */
    }
    
};

/*==================================================================================================*/
/**
* @brief          Description of individual FlexCan controllers on chip
* @details        Description of individual FlexCan controllers on chip
*
* @implements     DCAN02650
*/
/* @violates @ref Can_PBcfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(Can_ControlerDescriptorType, CAN_CONST) ControlerDescriptors0_PB[CAN_MAXCONTROLLERCOUNT_0] =
    {   
        /* ControlerDescriptor of ECU1_Project */
        {
            /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. */
            (uint8)FLEXCAN_B_OFFSET,

            /* No. of Message Buffers for current controller */
            
            (uint8)23U,
            
            /* No. of BaudRate configured for current controller */
            (uint8)1U,
            
            /* Default BaudRate configured for current controller */
            (uint8)0U,

            /* ControllerBaudrateConfigsPtr */
            ControllerBaudrateCfgSet0_PB_0,

#if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* WakeUp source ID (ECU State Manager) */
            (uint32)0U, /* EcuM source not used */
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

#if (CAN_RXFIFO_ENABLE == STD_ON)
            /* TableID Controller index */
            
            (uint8)0U,

            /* Pointer to RxFifo Overflow notification function. */
            /* @violates @ref Can_PBcfg_c_REF_7 cast from unsigned long to pointer. */
            /* @violates @ref Can_PBcfg_c_REF_8 a cast should not be performed between a pointer to object */
            /* @violates @ref Can_PBcfg_c_REF_9 a function identifier shall only be used with a &, or with a parenthesised parameter list*/
            (Can_PCallBackType)NULL_PTR,

            /* Pointer to RxFifo Warning notification function. */
            /* @violates @ref Can_PBcfg_c_REF_7 cast from unsigned long to pointer. */
            /* @violates @ref Can_PBcfg_c_REF_8 a cast should not be performed between a pointer to object */
            /* @violates @ref Can_PBcfg_c_REF_9 a function identifier shall only be used with a &, or with a parenthesised parameter list*/
            (Can_PCallBackType)NULL_PTR,
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

#if (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON)
            /* Pointer to Error interrupt notification function (ESR[ERR_INT]). */
#if (CAN_API_ERROR_STATUS == STD_ON)
            /* @violates @ref Can_PBcfg_c_REF_7 cast from unsigned long to pointer. */
            /* @violates @ref Can_PBcfg_c_REF_8 a cast should not be performed between a pointer to object */
            /* @violates @ref Can_PBcfg_c_REF_9 a function identifier shall only be used with a &, or with a parenthesised parameter list*/
            (Can_PCallBackType_ret)NULL_PTR,
#else
            /* @violates @ref Can_PBcfg_c_REF_7 cast from unsigned long to pointer. */
            /* @violates @ref Can_PBcfg_c_REF_8 a cast should not be performed between a pointer to object */
            /* @violates @ref Can_PBcfg_c_REF_9 a function identifier shall only be used with a &, or with a parenthesised parameter list*/
            (Can_PCallBackType)NULL_PTR,
#endif
#endif /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
      /* ===== Controller Options ===== */
        (uint32)(
        /* Software BusOff Recovery */
        CAN_CONTROLLERCONFIG_BUSOFFSWREC | 
         /* RX Fifo Disabled */ 
        
        
         /* Error interrupt */ 

        /* Rx select by interrupt */
        /* Tx select by interrupt */
        /* BusOff select by interrupt */
        CAN_CONTROLLERCONFIG_WKPOL_EN |/* Wakeup Support Disabled */
        
        0U),
#if (CAN_MIX_MB_SUPPORT == STD_ON)
         /* Maximum MBs supported for this controller. */
         
           (uint8)32U,
         
#endif /* (CAN_MIX_MB_SUPPORT == STD_ON) */
            
#if (CAN_RXFIFO_ENABLE == STD_ON)
            /* First HRH of specified controller */
            (Can_HwHandleType)0U
#endif
        }  /* ControlerDescriptors[0] end */
        

    };



/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
* @implements     DCAN02651
*/

/* @violates @ref Can_PBcfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
CONST(Can_ConfigType, CAN_CONST) CanConfigSet =
    {
        /* Number of CAN controllers configured */
       (uint8) 1U,

        /* FilterMasksPtr */
        /* @violates @ref Can_PBcfg_c_REF_8 a cast should not be performed between a pointer to object */
       (Can_IdPtrType) Can_FilterMasks0_PB,

        /* MessageBufferConfigContainer */
        {
            /* MessageBufferConfigsPtr */
            MessageBufferConfigs0_PB,

            /* MessageBufferConfigCount */
            (Can_HwHandleType)23U,
        },

        /* FlexCAN controller description */
        ControlerDescriptors0_PB,

#if (CAN_RXFIFO_ENABLE == STD_ON)
        /* Can_RxFiFoTableIdConfigType */
        NULL_PTR, /* Rx fifo disabled */
#endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */

  

        /*Maximum Object IDs configured */
        (uint32)23U,

        /*Controller ID mapping*/
        {0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U},

        /*Can Object Type mapping*/
        {(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_RECEIVE,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT,
(Can_ObjType)CAN_TRANSMIT},
#if (CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
                     {(uint32)STD_OFF, 0U}/* CAN_E_TIMEOUT parameters*/
         
#endif /* CAN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
    };



#endif /* #if (CAN_PRECOMPILE_SUPPORT == STD_OFF) */
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

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*
@file  Can_PBcfg.c
@note  Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. - See @ref Can_PBcfg_c_REF_1
@note  Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h - See @ref Can_PBcfg_c_REF_2
*/
/* @violates @ref Can_PBcfg_c_REF_3 This is required as per autosar Requirement. */
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_1 #include preceded by non preproc directives */
/* @violates @ref Can_PBcfg_c_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
