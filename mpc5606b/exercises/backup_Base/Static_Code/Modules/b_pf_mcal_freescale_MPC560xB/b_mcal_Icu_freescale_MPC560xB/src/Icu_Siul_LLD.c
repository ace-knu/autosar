/**
*     @file    Icu_Siul_LLD.c
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - SIUL source file support for ICU driver.
*     @details SIUL source file, containing the variables and functions that are exported by the
*              SIUL driver.
*
*     @implements     DICU04501
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Siul_LLD_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Icu_Siul_LLD_c_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*
* @section Icu_Siul_LLD_c_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Icu_Siul_LLD_c_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
* registers or other hardware specific features.
*
*@section Icu_Siul_LLD_c_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/* Implements DICU04501 */
#include "Icu_Siul_LLD.h"
#include "Icu_Siul_LLD_CfgEx.h"
/*
* @violates @ref Icu_Siul_LLD_c_2 precautions to prevent the
*       contents of a header file being included twice
*/
#include "Reg_eSys_SIUL.h"
#include "Icu_LLD.h"
#include "SchM_Icu.h"
/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/
/*
* @implements     DICU04311, DICU04312, DICU04313, DICU04314, DICU04315, DICU04316, DICU04317
*/
#define ICU_SIUL_LLD_VENDOR_ID_C                    43
/*
* @violates @ref Icu_Siul_LLD_c_3 Identifier clash
*/
/*
* @violates @ref Icu_Siul_LLD_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION_C     4
/*
* @violates @ref Icu_Siul_LLD_c_3 Identifier clash
*/
/*
* @violates @ref Icu_Siul_LLD_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION_C     0
/*
* @violates @ref Icu_Siul_LLD_c_3 Identifier clash
*/
/*
* @violates @ref Icu_Siul_LLD_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION_C  3
#define ICU_SIUL_LLD_SW_MAJOR_VERSION_C             1
#define ICU_SIUL_LLD_SW_MINOR_VERSION_C             0
#define ICU_SIUL_LLD_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Icu_Siul_LLD.h file are of the same vendor */
#if (ICU_SIUL_LLD_VENDOR_ID_C != ICU_SIUL_LLD_VENDOR_ID)
#error "Icu_Siul_LLD.c and Icu_Siul_LLD.h have different vendor IDs"
#endif
    #if ((ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION) || \
         (ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Siul_LLD.c and Icu_Siul_LLD.h are different"
    #endif
/* Check if source file and Icu_Siul_LLD.h header file are of the same Software version */
/*
*  @file Icu_Siul_LLD.c
*  @remarks Covers ICU005
*/
#if ((ICU_SIUL_LLD_SW_MAJOR_VERSION_C != ICU_SIUL_LLD_SW_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_SW_MINOR_VERSION_C != ICU_SIUL_LLD_SW_MINOR_VERSION) || \
     (ICU_SIUL_LLD_SW_PATCH_VERSION_C != ICU_SIUL_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Siul_LLD.c and Icu_Siul_LLD.h are different"
#endif


/* Check if source file and Icu_Siul_LLD.h file are of the same vendor */
#if (ICU_SIUL_LLD_VENDOR_ID_C != ICU_SIUL_LLD_CFG_EX_VENDOR_ID)
#error "Icu_Siul_LLD.c and Icu_Siul_LLD_CfgEx.h have different vendor IDs"
#endif
#if ((ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION_C != \
                                              ICU_SIUL_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Siul_LLD.c and Icu_Siul_LLD_CfgEx.h are different"
#endif
/* Check if source file and Icu_Siul_LLD.h header file are of the same Software version */
/*
*  @file Icu_Siul_LLD.c
*  @remarks Covers ICU005
*/
#if ((ICU_SIUL_LLD_SW_MAJOR_VERSION_C != ICU_SIUL_LLD_CFG_EX_SW_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_SW_MINOR_VERSION_C != ICU_SIUL_LLD_CFG_EX_SW_MINOR_VERSION) || \
     (ICU_SIUL_LLD_SW_PATCH_VERSION_C != ICU_SIUL_LLD_CFG_EX_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Siul_LLD.c and Icu_Siul_LLD_CfgEx.h are different"
#endif


/* Check if source file and Icu_LLD.h file are of the same vendor */
#if (ICU_SIUL_LLD_VENDOR_ID_C != ICU_LLD_VENDOR_ID)
    #error "Icu_Siul_LLD.c and Icu_LLD.h have different vendor IDs"
#endif
    #if ((ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_AR_RELEASE_MINOR_VERSION) || \
         (ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Siul_LLD.c and Icu_LLD.h are different"
    #endif
/* Check if source file and ICU_LLD.h header file are of the same Software version */
/*
*  @file Icu_Siul_LLD.c
*  @remarks Covers ICU005
*/
#if ((ICU_SIUL_LLD_SW_MAJOR_VERSION_C != ICU_LLD_SW_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_SW_MINOR_VERSION_C != ICU_LLD_SW_MINOR_VERSION) || \
     (ICU_SIUL_LLD_SW_PATCH_VERSION_C != ICU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Siul_LLD.c and Icu_LLD.h are different"
#endif


/* Check if source file and Reg_eSys_SIUL.h file are of the same vendor */
#if (ICU_SIUL_LLD_VENDOR_ID_C != SIUL_VENDOR_ID_REG)
#error "Icu_Siul_LLD.c and SIUL.h have different vendor IDs"
#endif
#if ((ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION_C != SIUL_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION_C != SIUL_AR_RELEASE_MINOR_VERSION_REG) || \
     (ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION_C != SIUL_AR_RELEASE_REVISION_VERSION_REG))
#error "AutoSar Version Numbers of Icu_Siul_LLD.c and SIUL.h are different"
#endif
/* Check if source file and Icu_Siul_LLD.h header file are of the same Software version */
#if ((ICU_SIUL_LLD_SW_MAJOR_VERSION_C != SIUL_SW_MAJOR_VERSION_REG) || \
     (ICU_SIUL_LLD_SW_MINOR_VERSION_C != SIUL_SW_MINOR_VERSION_REG) || \
     (ICU_SIUL_LLD_SW_PATCH_VERSION_C != SIUL_SW_PATCH_VERSION_REG))
#error "Software Version Numbers of Icu_Siul_LLD.c and Reg_eSys_SIUL.h are different"
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
static FUNC (void, ICU_CODE) Icu_Siul_LLD_DisableInterrupt(VAR(uint32, AUTOMATIC) channelMask);
static FUNC (void, ICU_CODE) Icu_Siul_LLD_EnableInterrupt(VAR(uint32, AUTOMATIC) channelMask);

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_Siul_LLD_c_2 precautions to prevent the
*        contents of a header file being included twice
*/
/*
* @violates @ref Icu_Siul_LLD_c_1 only preprocessor statements and
*        comments before "#include"
*/
#include "MemMap.h"


/*================================================================================================*/
/**
* @brief      Icu driver function that enables the interrupt of SIUL channel
* @details    This function enables SIUL Channel Interrupt
*
* @param[in]  channelMask - Channel's Bit Mask
*
* @return void
*
* @implements DICU04302
*/
/*================================================================================================*/
static FUNC (void, ICU_CODE) Icu_Siul_LLD_EnableInterrupt(VAR(uint32, AUTOMATIC) channelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17();
    {
        /* Clear pending flag */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
        REG_WRITE32(SIUL_ISR, channelMask);

        /* Enable interrupt */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
        REG_BIT_SET32(SIUL_IRER, channelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17();
}

/*================================================================================================*/
/**
* @brief      Icu driver function that disables the interrupt of SIUL channel
* @details    This function disables SIUL Channel Interrupt
*
* @param[in]  channelMask - Channel's Bit Mask
*
* @return void
*
* @implements DICU04301
*/
/*================================================================================================*/
static FUNC (void, ICU_CODE) Icu_Siul_LLD_DisableInterrupt(VAR(uint32, AUTOMATIC) channelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17();
    {
        /* Clear pending flag */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
        REG_WRITE32(SIUL_ISR, channelMask);

        /* Disable interrupt */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
        REG_BIT_CLEAR32(SIUL_IRER, channelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17();
}



/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief      Driver function that initializes SIUL hardware channel.
* @details    This function:
*              - Disables interrupt.
*              - Sets Interrupt filter enable register
*              - Sets Interrupt Filter Clock Prescaler Register
*              - Sets Activation Condition
*
* @param[in]  ParamValue IRQ Param value
* @param[in]  hwChannel IRQ HW Channel
*
* @return void
*
* @implements DICU04005
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_InitChannel(CONST(SIUL_Icu_IRQ_ParamType, AUTOMATIC) ParamValue,
                                           CONST(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(hwChannel);
     VAR(Icu_ClockPrescalerType,AUTOMATIC)Prescalar_value = 0U;
    /* Disable IRQ Interrupt */
    Icu_Siul_LLD_DisableInterrupt(channelMask);

    /* Set Interrupt Filter Enable Register */
    if (SIUL_INT_FILTER_ENABLE == ((ParamValue & ICU_SIUL_INT_FILTER_ENABLE_PARAM_MASK) >>  \
                                                            ICU_SIUL_INT_FILTER_ENABLE_PARAM_SHIFT))
    {
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
        REG_BIT_SET32(SIUL_IFER, channelMask);
         /*read the prescaler value*/

/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/                
/* @violates @ref Icu_Siul_LLD_c_4 Violates MISRA 2004 Required Rule 11.1 ,conversions bw pointer to a function and intger*/
        Prescalar_value  = (Icu_ClockPrescalerType)(REG_READ32(SIUL_IFCPR)&0x0fU);
        /* Update   interrupt Filter Clock Prescaler Register Only Once*/ 

        if((Prescalar_value == 0U) && (Icu_Cfg_Ptr->Icu_Irq_ClockPrescaler != 0U))
        {            
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/                 
/* @violates @ref Icu_Siul_LLD_c_4 Violates MISRA 2004 Required Rule 11.1 ,conversions bw pointer to a function and intger*/
            REG_WRITE32(SIUL_IFCPR,(Icu_Cfg_Ptr->Icu_Irq_ClockPrescaler));       
        }
    }
    else
    {
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
        REG_BIT_CLEAR32(SIUL_IFER, channelMask);
    }

    /* Set Interrupt Filter Clock Prescaler Register */
    REG_WRITE32(SIUL_IFMC((uint32)((uint32)hwChannel << (uint32)2U)),  \
                                    (ParamValue & ICU_SIUL_INT_FILTER_COUNTER_PARAM_MASK) >>  \
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
                                                           ICU_SIUL_INT_FILTER_COUNTER_PARAM_SHIFT);

    /* Set Activation Condition */
    Icu_Siul_LLD_SetActivationCondition(hwChannel,
                 (SIUL_ActivationType)((ParamValue & ICU_EDGE_PARAM_MASK) >> ICU_EDGE_PARAM_SHIFT));
}

/*================================================================================================*/
/**
* @brief      Driver function that de-initializes SIUL hardware channel.
* @details    This function:
*              - Disables interrupt.
*              - Clears edge event enable registers
*              - Clears Interrupt Filter Enable Register
*              - Clears Interrupt Filter Clock Prescaler Register
*
* @param[in]  hwChannel   - IRQ HW Channel
*
* @return void
*
* @implements DICU04001
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_DeInitChannel(VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(hwChannel);

    /* Disable IRQ Interrupt */
    Icu_Siul_LLD_DisableInterrupt(channelMask);

    /* Clear edge event enable registers */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    REG_BIT_CLEAR32(SIUL_IREER, channelMask);
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    REG_BIT_CLEAR32(SIUL_IFEER, channelMask);

    /* Clear Interrupt Filter Enable Register */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    REG_BIT_CLEAR32(SIUL_IFER, channelMask);

    /* Clear Interrupt Filter Clock Prescaler Register */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    REG_WRITE32(SIUL_IFMC((uint32)((uint32)hwChannel << 2U)), 0x00U);
}



#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Driver function that sets SIUL hardware channel into SLEEP mode.
* @details    This function enables the interrupt if wakeup is enabled for corresponding SIUL
*             channel
*
* @param[in]  hwChannel       - IRQ HW Channel
* @param[in]  WakeUpEnabled   - channel wakeup feature is enabled
*
* @return void
*
* @implements DICU04008
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_SetSleepMode(VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) WakeUpEnabled)
{
    CONST(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(hwChannel);
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/        
    CONST(uint32, AUTOMATIC) reg_SIUL_IRER = REG_BIT_GET32(SIUL_IRER, channelMask);                

    if (WakeUpEnabled)
    {
        if(reg_SIUL_IRER == 0U)
        {
            /* Enable IRQ Interrupt */
            Icu_Siul_LLD_EnableInterrupt(channelMask);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /* Disable IRQ Interrupt */
        Icu_Siul_LLD_DisableInterrupt(channelMask);
    }
}

/*================================================================================================*/
/**
* @brief      Driver function that sets SIUL hardware channel into NORMAL mode.
* @details    This function enables the interrupt if Notification is enabled for corresponding
*             SIUL channel
*
* @param[in]  hwChannel           - IRQ HW Channel
* @param[in]  NotificationActive  - channel notification is activated
*
* @return void
*
* @implements DICU04007
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_SetNormalMode(VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel,
                                                 VAR(boolean, AUTOMATIC) NotificationActive)
{
    CONST(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(hwChannel);
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/        
    CONST(uint32, AUTOMATIC) reg_SIUL_IRER = REG_BIT_GET32(SIUL_IRER, channelMask);        

    if (NotificationActive)
    {
        if(reg_SIUL_IRER == 0U)
        {
            /* Enable IRQ Interrupt */
            Icu_Siul_LLD_EnableInterrupt(channelMask);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /* Disable IRQ Interrupt */
        Icu_Siul_LLD_DisableInterrupt(channelMask);
    }
}
#endif  /* ICU_SET_MODE_API */

/*================================================================================================*/
/**
* @brief      Driver function that sets activation condition of SIUL channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges) for corresponding SIUL channels.
*
* @param[in]  hwChannel -  Hardware channel
* @param[in]  Activation - Activation condition
*
* @return void
*
* @implements DICU04006
*/
/*================================================================================================*/
/*
* @violates @ref Icu_Siul_LLD_c_5 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_SetActivationCondition(
                                                VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(SIUL_ActivationType, AUTOMATIC) Activation)
{
    CONST(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(hwChannel);

    switch (Activation)
    {
        case SIUL_RISING_EDGE:
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
            REG_BIT_SET32(SIUL_IREER, channelMask);
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
            REG_BIT_CLEAR32(SIUL_IFEER, channelMask);
            break;

        case SIUL_FALLING_EDGE:
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
            REG_BIT_CLEAR32(SIUL_IREER, channelMask);
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
            REG_BIT_SET32(SIUL_IFEER, channelMask);
            break;

        default:
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
            REG_BIT_SET32(SIUL_IREER, channelMask);
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
            REG_BIT_SET32(SIUL_IFEER, channelMask);
            break;
    }
}



#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Siul_LLD_EnableEdgeDetection
* @details    This function enables the interrupt corresponding to the SIUL channel.
*
* @param[in]  hwChannel - IRQ HW Channel
*
* @return void
*
* @implements DICU04032
*/
/*================================================================================================*/
/*
* @violates @ref Icu_Siul_LLD_c_5 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_EnableEdgeDetection(
                                                 VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(hwChannel);

    /* Enable IRQ Interrupt */
    Icu_Siul_LLD_EnableInterrupt(channelMask);
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Siul_LLD_DisableEdgeDetection
* @details    This function disables the interrupt corresponding to the SIUL channel.
*
* @param[in]  hwChannel - IRQ HW Channel
*
* @return void
*
* @implements DICU04031
*/
/*================================================================================================*/
/*
* @violates @ref Icu_Siul_LLD_c_5 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_Siul_LLD_DisableEdgeDetection(
                                                 VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(hwChannel);

    /* Disable IRQ Interrupt */
    Icu_Siul_LLD_DisableInterrupt(channelMask);
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that gets the input state of SIUL channel.
* @details    This function:
*             - Checks if interrupt flags for corresponding SIUL channel is set then
*             it clears the interrupt flag and returns the value as true.
*
* @param[in]  hwChannel - IRQ HW Channel
*
* @return     boolean
* @retval     true       channel is Active
* @retval     false      channel is Idle
*
* @implements DICU04004
*/
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_Siul_LLD_GetInputState(
                                                 VAR(SIUL_Icu_IRQ_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(boolean,AUTOMATIC) status = (boolean) FALSE;
    CONST(uint32, AUTOMATIC) channelMask = (uint32)(BIT0 << hwChannel);
    VAR(uint32, AUTOMATIC) reg_SIUL_ISR;
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    CONST(uint32, AUTOMATIC) reg_SIUL_IRER = REG_BIT_GET32(SIUL_IRER, channelMask);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18();
    {
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    reg_SIUL_ISR  = REG_BIT_GET32(SIUL_ISR, channelMask);
    /* Interrupt condition activated (ISR), interrupt not enabled (IRER) */
        if ((0x0U !=  reg_SIUL_ISR) && (0x0U == reg_SIUL_IRER))
        {
             /* Clear IRQ Flag */
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
            REG_WRITE32(SIUL_ISR, channelMask);

            status = (boolean)TRUE;
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18();

    return status;
}
#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_DUAL_CLOCK_MODE == STD_ON)

/*================================================================================================*/
/*================================================================================================*/
FUNC (void, ICU_CODE) SIUL_Icu_LLD_SelectPrescaler
                                          (CONST(SIUL_Icu_IRQ_ParamType, AUTOMATIC) ParamValue, 
                                          VAR(uint8, AUTOMATIC)IFCP_SIUL_Prescalar)
{
    VAR(Icu_ClockPrescalerType,AUTOMATIC) Prescalar_value = 0U;
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    /* Set Interrupt Filter Enable Register */
   if (SIUL_INT_FILTER_ENABLE == ((ParamValue & ICU_SIUL_INT_FILTER_ENABLE_PARAM_MASK) >>  \
                                                            ICU_SIUL_INT_FILTER_ENABLE_PARAM_SHIFT))
  {
 /*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/ 
        Prescalar_value  = (Icu_ClockPrescalerType)(REG_READ32(SIUL_IFCPR)&0x0fU);
                
        if(Prescalar_value != IFCP_SIUL_Prescalar )
        {
/*
* @violates @ref Icu_Siul_LLD_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/        
            REG_WRITE32(SIUL_IFCPR,IFCP_SIUL_Prescalar);    
        }
   }
}
#endif

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_Siul_LLD_c_1 only preprocessor statements and
*        comments before "#include"
*/
/*
* @violates @ref Icu_Siul_LLD_c_2 precautions to prevent the
*         contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */


