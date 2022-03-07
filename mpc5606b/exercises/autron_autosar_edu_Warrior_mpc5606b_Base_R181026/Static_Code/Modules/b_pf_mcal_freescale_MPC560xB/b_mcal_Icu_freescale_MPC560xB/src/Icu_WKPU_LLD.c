/**
*     @file    Icu_Wkpu_LLD.c
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - WKPU source file support for ICU driver.
*     @details WKPU source file, containing the variables and functions that are exported by the WKPU driver.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.0 MCAL
*     Platform            : PA
*     Peripheral          : eMIOS
*     Dependencies        : none
*
*     Autosar Version     : 4.0.3
*     Autosar Revision    : ASR_REL_4_0_REV_0003
*     Autosar ConfVariant :
*     SWVersion           : 1.0.1
*     BuildVersion        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*     (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
 ==================================================================================================*/

/**
* @file    Icu_WKPU_LLD.c
* @remarks Implements DICU06001
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_WKPU_LLD_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include" MemMap.h included after each section define in order to set the current memory section
*
* @section Icu_WKPU_LLD_c_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_WKPU_LLD_c_3
*  Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
*  a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
*  registers or other hardware specific features.
*
*@section Icu_WKPU_LLD_c_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_WKPU_LLD.h"
#include "Icu_WKPU_LLD_CfgEx.h"
/*
* @violates @ref Icu_WKPU_LLD_c_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_eSys_WKPU.h"
#include "Icu_LLD.h"
#include "SchM_Icu.h"

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/
/**
* @{
* @brief   Source file version information
* @remarks Covers BSW00374, BSW00379, BSW00318
*/
#define WKPU_ICU_LLD_VENDOR_ID_C         43

/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_AR_RELEASE_MAJOR_VERSION_C  4
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_AR_RELEASE_MINOR_VERSION_C  0
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_AR_RELEASE_REVISION_VERSION_C  3

#define WKPU_ICU_LLD_SW_MAJOR_VERSION_C  1
#define WKPU_ICU_LLD_SW_MINOR_VERSION_C  0
#define WKPU_ICU_LLD_SW_PATCH_VERSION_C  1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Icu_WKPU_LLD.h file are of the same vendor */
#if (WKPU_ICU_LLD_VENDOR_ID_C != WKPU_ICU_LLD_VENDOR_ID)
#error "Icu_WKPU_LLD.c and Icu_WKPU_LLD.h have different vendor IDs"
#endif

    #if ((WKPU_ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_ICU_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_MINOR_VERSION) || \
         (WKPU_ICU_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_WKPU_LLD.c and Icu_WKPU_LLD.h are different"
    #endif

/* Check if source file and Icu_WKPU_LLD.h header file are of the same Software version */
/**
*  @file Icu_WKPU_LLD.c
*  @remarks Covers ICU005
*/
#if ((WKPU_ICU_LLD_SW_MAJOR_VERSION_C != ICU_WKPU_LLD_H_SW_MAJOR_VERSION) || \
     (WKPU_ICU_LLD_SW_MINOR_VERSION_C != ICU_WKPU_LLD_H_SW_MINOR_VERSION) || \
     (WKPU_ICU_LLD_SW_PATCH_VERSION_C != ICU_WKPU_LLD_H_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_WKPU_LLD.c and Icu_WKPU_LLD.h are different"
#endif


/* Check if source file and Icu_LLD.h file are of the same vendor */
#if (WKPU_ICU_LLD_VENDOR_ID_C != ICU_LLD_VENDOR_ID)
    #error "Icu_WKPU_LLD.c and Icu_LLD.h have different vendor IDs"
#endif

    #if ((WKPU_ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_ICU_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_AR_RELEASE_MINOR_VERSION) || \
         (WKPU_ICU_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_WKPU_LLD.c and Icu_LLD.h are different"
    #endif

/* Check if source file and ICU_LLD.h header file are of the same Software version */
/**
*  @file Icu_WKPU_LLD.c
*  @remarks Covers ICU005
*/
#if ((WKPU_ICU_LLD_SW_MAJOR_VERSION_C != ICU_LLD_SW_MAJOR_VERSION) || \
     (WKPU_ICU_LLD_SW_MINOR_VERSION_C != ICU_LLD_SW_MINOR_VERSION) || \
     (WKPU_ICU_LLD_SW_PATCH_VERSION_C != ICU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_WKPU_LLD.c and Icu_LLD.h are different"
#endif


/* Check if source file and Reg_eSys_WKPU.h file are of the same vendor */
#if (WKPU_ICU_LLD_VENDOR_ID_C != REG_ESYS_WKPU_VENDOR_ID)
#error "Icu_WKPU_LLD.c and WKPU.h have different vendor IDs"
#endif

    #if ((WKPU_ICU_LLD_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_WKPU_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_ICU_LLD_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_WKPU_AR_RELEASE_MINOR_VERSION) || \
         (WKPU_ICU_LLD_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_WKPU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_WKPU_LLD.c and WKPU.h are different"
    #endif

/* Check if source file and Icu_WKPU_LLD.h header file are of the same Software version */
#if ((WKPU_ICU_LLD_SW_MAJOR_VERSION_C != REG_ESYS_WKPU_SW_MAJOR_VERSION) || \
     (WKPU_ICU_LLD_SW_MINOR_VERSION_C != REG_ESYS_WKPU_SW_MINOR_VERSION) || \
     (WKPU_ICU_LLD_SW_PATCH_VERSION_C != REG_ESYS_WKPU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_WKPU_LLD.c and Reg_eSys_WKPU.h are different"
#endif


/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static FUNC (void, ICU_CODE) Icu_WKPU_LLD_DisableInterrupt(VAR(uint32, AUTOMATIC) channelMask);
static FUNC (void, ICU_CODE) Icu_WKPU_LLD_EnableInterrupt(VAR(uint32, AUTOMATIC) channelMask);

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE

/*
* @violates @ref Icu_WKPU_LLD_c_2 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref  Icu_WKPU_LLD_c_1 only preprocessor statements and
*  comments before "#include"
*/
#include "MemMap.h"


/*==================================================================================================*/
/**
* @brief      Icu driver function that enables the interrupt of WKPU channel.
* @details    This function enables WKPU Channel Interrupt
*
* @param[in]  channelMask - Channel's Bit Mask
* @implements DICU06002
*
*/
/*==================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
static FUNC (void, ICU_CODE) Icu_WKPU_LLD_EnableInterrupt(VAR(uint32, AUTOMATIC) channelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    {
        /* Clear ISR Flag */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_WRITE32(WKPU_WISR, channelMask);

        /* Enable IRQ Interrupt */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_SET32(WKPU_IRER, channelMask);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_SET32(WKPU_WRER, channelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
}

/*==================================================================================================*/
/**
* @brief      Icu driver function that disables the interrupt of WKPU channel.
* @details    This function disables WKPU Channel Interrupt
*
* @param[in]  channelMask - Channel's Bit Mask
* @implements DICU06003
*
*/
/*==================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
static FUNC (void, ICU_CODE) Icu_WKPU_LLD_DisableInterrupt(VAR(uint32, AUTOMATIC) channelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_20();
    {
        /* Clear ISR Flag */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_WRITE32(WKPU_WISR, channelMask);

        /* Disable IRQ Interrupt */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_CLEAR32(WKPU_IRER, channelMask);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_CLEAR32(WKPU_WRER, channelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_20();
}


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================*/
/**
* @brief      Icu driver function that initializes WKPU channel.
* @details    This function:
*              - Disables IRQ Interrupt
*              - Sets Interrupt Filter Enable Register
*              - Sets Wakeup/Interrupt Pull-up Enable Register
*              - Sets Activation Condition
*
* @param[in]  ParamValue - Wake interrupt value
* @param[in]  hwChannel - Wake channel
* @implements DICU06004
*
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_InitChannel(CONST(WKPU_Icu_ParamType, AUTOMATIC) ParamValue,
                                           CONST(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) channelMask = (uint32)0x00000001U << (uint32)(hwChannel);

    /* Disable IRQ Interrupt */
    Icu_WKPU_LLD_DisableInterrupt(channelMask);

    /* Set Interrupt Filter Enable Register */
    if (WKPU_INT_FILTER_ENABLE == ((ParamValue & ICU_WKPU_INT_FILTER_ENABLE_PARAM_MASK) >>  \
                                                            ICU_WKPU_INT_FILTER_ENABLE_PARAM_SHIFT))
    {
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_SET32(WKPU_WIFER, channelMask);
    }
    else
    {
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_CLEAR32(WKPU_WIFER, channelMask);
    }

    /* Set Wakeup/Interrupt Pull-up Enable Register */
    if (WKPU_PULLUP_ENABLE == ((ParamValue & ICU_WKPU_PULLUP_ENABLE_PARAM_MASK) >> \
                                                                ICU_WKPU_PULLUP_ENABLE_PARAM_SHIFT))
    {
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_SET32(WKPU_WIPUER, channelMask);
    }
    else
    {
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_BIT_CLEAR32(WKPU_WIPUER, channelMask);
    }

    /* Set Activation Condition */
    Icu_WKPU_LLD_SetActivationCondition(hwChannel, (WKPU_ActivationType)((ParamValue &  \
                                                     ICU_EDGE_PARAM_MASK) >> ICU_EDGE_PARAM_SHIFT));
}

/*==================================================================================================*/
/**
* @brief      Icu driver function that initializes WKPU channel.
* @details    This function:
*              - Disables IRQ Interrupt
*              - Clears Wakeup/Interrupt Filter Enable Register
*              - Clears Wakeup/Interrupt Pull-up Enable Register
*              - Clears edge event enable registers
*              - Clear Interrupt Filter Enable Register
*
* @param[in]  hwChannel   - WKUP HW Channel
* @implements DICU06005
*
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_DeInitChannel(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) channelMask = (uint32)0x00000001U << (uint32)(hwChannel);

    /* Disable IRQ Interrupt */
    Icu_WKPU_LLD_DisableInterrupt(channelMask);

    /* Clear Wakeup/Interrupt Filter Enable Register  */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    REG_BIT_CLEAR32(WKPU_WIFER, channelMask);

    /* Clear Wakeup/Interrupt Pull-up Enable Register */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    REG_BIT_CLEAR32(WKPU_WIPUER, channelMask);

    /* Clear edge event enable registers */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    REG_BIT_CLEAR32(WKPU_WIREER, channelMask);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    REG_BIT_CLEAR32(WKPU_WIFEER, channelMask);

    /* Clear Interrupt Filter Enable Register */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    REG_BIT_CLEAR32(WKPU_WIFER, channelMask);
}



#if (ICU_SET_MODE_API == STD_ON)
/*==================================================================================================*/
/**
* @brief      Icu driver function that sets WKPU channel to SLEEP mpde
* @details    This function enables the interrupt for WKUP channel if wakeup is enabled for the channel
*
* @param[in]  hwChannel       - IRQ HW Channel
* @param[in]  WakeUpEnabled   - channel wakeup feature is enabled
* @implements DICU06006
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_SetSleepMode(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) WakeUpEnabled)
{
    CONST(uint32, AUTOMATIC) channelMask = (uint32)0x00000001U << (uint32)(hwChannel);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    VAR(uint32, AUTOMATIC) reg_WKPU_IRER = REG_BIT_GET32(WKPU_IRER, channelMask);        

    if (WakeUpEnabled)
    {
        if(reg_WKPU_IRER == 0U)
        {
            /* Enable IRQ Interrupt */
         Icu_WKPU_LLD_EnableInterrupt(channelMask);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /* Disable IRQ Interrupt */
        Icu_WKPU_LLD_DisableInterrupt(channelMask);
    }
}

/*==================================================================================================*/
/**
* @brief      Icu driver function that sets WKPU channel to NORMAL mpde
* @details    This function enables the interrupt for WKUP channel if Notifcation is enabled
*             for the channel
*
* @param[in]  hwChannel IRQ HW Channel
* @param[in]  NotificationActive  - channel notification is activated
* @implements DICU06007
*
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_SetNormalMode(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel,
                                                 VAR(boolean, AUTOMATIC) NotificationActive)
{
    CONST(uint32, AUTOMATIC) channelMask = (uint32)0x00000001U << (uint32)(hwChannel);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    VAR(uint32, AUTOMATIC) reg_WKPU_IRER = REG_BIT_GET32(WKPU_IRER, channelMask);    

    if (NotificationActive)
    {
        if(reg_WKPU_IRER == 0U)
        {
            /* Enable IRQ Interrupt */
         Icu_WKPU_LLD_EnableInterrupt(channelMask);
        }
        else
        {
            /*Do nothing*/
        }    
    }
    else
    {
        /* Disable IRQ Interrupt */
        Icu_WKPU_LLD_DisableInterrupt(channelMask);
    }
}
#endif  /* ICU_SET_MODE_API */

/*==================================================================================================*/
/**
* @brief      Icu driver function that sets activation condition of WKUP channel
* @details    This function enables the requested activation condition(rising, falling or both edges)
*             for corresponding WKPU channels.
*
* @param[in]  hwChannel - Wake up hardware channel
* @param[in]  Activation - activation condition
*
* @implements DICU06008
*/
/*==================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_SetActivationCondition(
                                                     VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel,
                                                     VAR(WKPU_ActivationType, AUTOMATIC) Activation)
{
    CONST(uint32, AUTOMATIC) channelMask = (uint32)0x00000001U << (uint32)(hwChannel);

    switch (Activation)
    {
        case WKPU_RISING_EDGE:
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
            REG_BIT_SET32(WKPU_WIREER, channelMask);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
            REG_BIT_CLEAR32(WKPU_WIFEER, channelMask);
            break;

        case WKPU_FALLING_EDGE:
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
            REG_BIT_CLEAR32(WKPU_WIREER, channelMask);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
            REG_BIT_SET32(WKPU_WIFEER, channelMask);
            break;

        default:
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
            REG_BIT_SET32(WKPU_WIREER, channelMask);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
            REG_BIT_SET32(WKPU_WIFEER, channelMask);
            break;
    }
}


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu_WKPU_LLD_DisableEdgeDetection
 * @details    WKPU IP function that stops the edge detection service for an WKPU channel
 *
 * @param[in]      hwChannel   - WKPU encoded hardware channel
 *
 * @return void
 *
 * @implements  DICU06011
*/
/*================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_DisableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel)
{

    CONST(uint32, AUTOMATIC) channelMask = (uint32)0x00000001U << (uint32)(hwChannel);
    /* Enable IRQ Interrupt */
    Icu_WKPU_LLD_DisableInterrupt(channelMask);

}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu_WKPU_LLD_EnableEdgeDetection
 * @details    WKPU IP function that starts the edge detection service for an WKPU channel
 *
 * @param[in]      hwChannel   - WKPU encoded hardware channel
 *
 * @return void
 *
 * @implements  DICU06012
*/
/*================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_WKPU_LLD_EnableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel)
{

    CONST(uint32, AUTOMATIC) channelMask = (uint32)0x00000001U << (uint32)(hwChannel);
    /* Enable IRQ Interrupt */
    Icu_WKPU_LLD_EnableInterrupt(channelMask);

}
#endif /* ICU_EDGE_DETECT_API */



#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*==================================================================================================*/
/**
* @brief      Icu driver function that gets the input state of WKPU channel.
* @details    This function:
*             - Checks if interrupt flags for corresponding WKPU channel is set then
*             it clears the interrupt flag and returns the value as true.
*
* @param[in]  hwChannel - IRQ HW Channel
*
* @return     boolean
*              - true - if channel is active
*              - false - If channel is in idle
*
* @implements  DICU06013
*/
/*==================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_WKPU_LLD_GetInputState(VAR(WKPU_Icu_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(boolean, AUTOMATIC) status = (boolean) FALSE;
    CONST(uint32, AUTOMATIC) channelMask = (uint32)(BIT0 << hwChannel);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    VAR(uint32, AUTOMATIC) reg_WKPU_WISR  = REG_BIT_GET32(WKPU_WISR, channelMask);
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
    VAR(uint32, AUTOMATIC) reg_WKPU_IRER = REG_BIT_GET32(WKPU_IRER, channelMask);

    /* Interrupt condition activated (WISR), interrupt not enabled (IRER) */
    if ((0x0U != reg_WKPU_WISR) && (0x0U == reg_WKPU_IRER))
    {
        /* Clear ISR Flag */
    /*
          * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
          *           between a pointer to a function and any type other than an integer type
           */
        REG_WRITE32(WKPU_WISR, channelMask);
        status = (boolean)TRUE;
    }

    return status;
}
#endif  /* ICU_GET_INPUT_STATE_API */

/*==================================================================================================*/
/**
@brief      The function enables pull up for not configured and unavailable Wakeup pins.
@details    This function:
            The function enables pull up for not configured and unavailable Wakeup pins.

@param[in]  hwChannel - PullUpEnable

@return  
*/
/*==================================================================================================*/
/*
* @violates @ref Icu_WKPU_LLD_c_4 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) WKPU_LLD_PullUpNonBondedWakeupPin(void)
{
         VAR(uint32, AUTOMATIC) reg_WIPUER;
        /*Read current value of WIPUER register*/
        /*
        * @violates @ref Icu_WKPU_LLD_c_3 Conversions shall not be performed
        *           between a pointer to a function and any type other than an integer type
        */        
        reg_WIPUER = REG_READ32(WKPU_WIPUER);
        /*OR-ed with the current value of WIPUER register with ICU_WKUP_PULLUP_MASK*/
        reg_WIPUER |= ICU_WKUP_PULLUP_MASK;
        /* @violates @ref Icu_WKPU_LLD_c_3 cast from unsigned long to pointer*/
        REG_WRITE32(WKPU_WIPUER, reg_WIPUER);
}
#define ICU_STOP_SEC_CODE
/**
* @file  Icu_WKPU_LLD.c
* @violates @ref  Icu_WKPU_LLD_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*  comments before "#include"
*/

/*
* @violates @ref Icu_WKPU_LLD_c_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif
/**@}*/
