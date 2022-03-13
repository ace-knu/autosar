/**
*     @file    Icu_Siul_LLD_IRQ.c
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - SIUL source file support for ICU driver.
*     @details SIUL source file, containing the variables and functions that are exported by the
*              SIUL driver.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Siul_LLD_IRQ_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Icu_Siul_LLD_IRQ_c_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_Siul_LLD_IRQ_c_3
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
* of pointer arithmetic.
* The violation occurs because the variables are defined as per Autosar API specifications.
*
* @section Icu_Siul_LLD_IRQ_c_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
* registers or other hardware specific features.
*
*@section Icu_Siul_LLD_IRQ_c_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_2 precautions to prevent the
*       contents of a header file being included twice
*/
#include "Std_Types.h"

#include "Reg_eSys_SIUL.h"
/* @implements DICU04601 */
#include "Icu_Siul_LLD.h"
#include "Icu_Siul_LLD_CfgEx.h"
#include "Icu_LLD.h"
#include "SchM_Icu.h"

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

/*
* @implements     DICU04411, DICU04412, DICU04413, DICU04414, DICU04415, DICU04416, DICU04417
*/
#define ICU_SIUL_LLD_IRQ_VENDOR_ID_C         43
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C  4
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C  0
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C  3
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_IRQ_SW_MAJOR_VERSION_C  1
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_IRQ_SW_MINOR_VERSION_C  0
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_5 This is required as per autosar Requirement, 
*/
#define ICU_SIUL_LLD_IRQ_SW_PATCH_VERSION_C  1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Icu_Siul_LLD.h file are of the same vendor */
#if (ICU_SIUL_LLD_IRQ_VENDOR_ID_C != ICU_SIUL_LLD_VENDOR_ID)
    #error "Icu_Siul_LLD_IRQ.c and Icu_Siul_LLD.h have different vendor IDs"
#endif
#if ((ICU_SIUL_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_SIUL_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_SIUL_LLD_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_SIUL_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Siul_LLD_IRQ.c and Icu_Siul_LLD.h are different"
#endif
/* Check if source file and Icu_Siul_LLD.h header file are of the same Software version */
/*
*  @file Icu_SIUL_LLD_IRQ.c
*  @remarks Covers ICU005
*/
#if ((ICU_SIUL_LLD_IRQ_SW_MAJOR_VERSION_C != ICU_SIUL_LLD_SW_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_SW_MINOR_VERSION_C != ICU_SIUL_LLD_SW_MINOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_SW_PATCH_VERSION_C != ICU_SIUL_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Siul_LLD_IRQ.c and Icu_Siul_LLD.h are different"
#endif


/* Check if source file and SIUL_LLD_CfgEx.h file are of the same vendor */
#if (ICU_SIUL_LLD_IRQ_VENDOR_ID_C != ICU_SIUL_LLD_VENDOR_ID)
#error "Icu_Siul_LLD_IRQ.c and SIUL_LLD_CfgEx.h have different vendor IDs"
#endif
    #if ((ICU_SIUL_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != \
                                                  ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != \
                                                  ICU_SIUL_LLD_CFG_EX_AR_RELEASE_MINOR_VERSION) || \
         (ICU_SIUL_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != \
                                                  ICU_SIUL_LLD_CFG_EX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Siul_LLD_IRQ.c and SIUL_LLD_CfgEx.h are different"
    #endif
/* Check if source file and SIUL_LLD_CfgEx.h file are of the same Software version */
/*
*  @file Icu_Siul_LLD_IRQ.c
*  @remarks Covers ICU005
*/
#if ((ICU_SIUL_LLD_IRQ_SW_MAJOR_VERSION_C != ICU_SIUL_LLD_CFG_EX_SW_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_SW_MINOR_VERSION_C != ICU_SIUL_LLD_CFG_EX_SW_MINOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_SW_PATCH_VERSION_C != ICU_SIUL_LLD_CFG_EX_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Siul_LLD_IRQ.c and SIUL_LLD_CfgEx.h are different"
#endif


/* Check if source file and Icu_LLD.h file are of the same vendor */
#if (ICU_SIUL_LLD_IRQ_VENDOR_ID_C != ICU_LLD_VENDOR_ID)
    #error "Icu_Siul_LLD_IRQ.c and Icu_LLD.h have different vendor IDs"
#endif
    #if ((ICU_SIUL_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_AR_RELEASE_MINOR_VERSION) || \
         (ICU_SIUL_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Siul_LLD_IRQ.c and Icu_LLD.h are different"
    #endif
/* Check if source file and ICU_LLD.h header file are of the same Software version */
/*
*  @file Icu_Siul_LLD_IRQ.c
*  @remarks Covers ICU005
*/
#if ((ICU_SIUL_LLD_IRQ_SW_MAJOR_VERSION_C != ICU_LLD_SW_MAJOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_SW_MINOR_VERSION_C != ICU_LLD_SW_MINOR_VERSION) || \
     (ICU_SIUL_LLD_IRQ_SW_PATCH_VERSION_C != ICU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Siul_LLD_IRQ.c and Icu_LLD.h are different"
#endif


/* Check if source file and Reg_eSys_SIUL.h file are of the same vendor */
#if (ICU_SIUL_LLD_IRQ_VENDOR_ID_C != SIUL_VENDOR_ID_REG)
#error "Icu_Siul_LLD_IRQ.c and Icu_Siul_LLD.h have different vendor IDs"
#endif
    #if ((ICU_SIUL_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != SIUL_AR_RELEASE_MAJOR_VERSION_REG) || \
         (ICU_SIUL_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != SIUL_AR_RELEASE_MINOR_VERSION_REG) || \
         (ICU_SIUL_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != SIUL_AR_RELEASE_REVISION_VERSION_REG))
    #error "AutoSar Version Numbers of Icu_Siul_LLD_IRQ.c and Icu_Siul_LLD.h are different"
    #endif
/* Check if source file and Icu_Siul_LLD.h header file are of the same Software version */
#if ((ICU_SIUL_LLD_IRQ_SW_MAJOR_VERSION_C != SIUL_SW_MAJOR_VERSION_REG) || \
     (ICU_SIUL_LLD_IRQ_SW_MINOR_VERSION_C != SIUL_SW_MINOR_VERSION_REG) || \
     (ICU_SIUL_LLD_IRQ_SW_PATCH_VERSION_C != SIUL_SW_PATCH_VERSION_REG))
#error "Software Version Numbers of Icu_Siul_LLD_IRQ.c and Reg_eSys_SIUL.h are different"
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
#if ((defined ICU_IRQ_0_ISR_USED) || (defined ICU_IRQ_1_ISR_USED) || (defined ICU_IRQ_2_ISR_USED)||\
     (defined ICU_IRQ_3_ISR_USED) || (defined ICU_IRQ_4_ISR_USED) || (defined ICU_IRQ_5_ISR_USED)||\
     (defined ICU_IRQ_6_ISR_USED) || (defined ICU_IRQ_7_ISR_USED))
ISR(SIUL_EXT_IRQ_0_7_ISR);
#endif

#if ((defined ICU_IRQ_8_ISR_USED) || (defined ICU_IRQ_9_ISR_USED) || (defined ICU_IRQ_10_ISR_USED) \
 || (defined ICU_IRQ_11_ISR_USED) || (defined ICU_IRQ_12_ISR_USED) || (defined ICU_IRQ_13_ISR_USED)\
 || (defined ICU_IRQ_14_ISR_USED) || (defined ICU_IRQ_15_ISR_USED))
ISR(SIUL_EXT_IRQ_8_15_ISR);
#endif

#if ((defined ICU_IRQ_16_ISR_USED) || (defined ICU_IRQ_17_ISR_USED) || \
     (defined ICU_IRQ_18_ISR_USED) || (defined ICU_IRQ_19_ISR_USED) || \
     (defined ICU_IRQ_20_ISR_USED) || (defined ICU_IRQ_21_ISR_USED)|| \
     (defined ICU_IRQ_22_ISR_USED) || (defined ICU_IRQ_23_ISR_USED))
ISR(SIUL_EXT_IRQ_16_23_ISR);
#endif

#if ((defined ICU_IRQ_24_ISR_USED) || (defined ICU_IRQ_25_ISR_USED) || \
     (defined ICU_IRQ_26_ISR_USED) || (defined ICU_IRQ_27_ISR_USED) || \
     (defined ICU_IRQ_28_ISR_USED) || (defined ICU_IRQ_29_ISR_USED) || \
     (defined ICU_IRQ_30_ISR_USED) || (defined ICU_IRQ_31_ISR_USED))
ISR(SIUL_EXT_IRQ_24_31_ISR);
#endif
/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_1 only preprocessor statements
*       and comments before "#include"
*/

/*
* @violates @ref Icu_Siul_LLD_IRQ_c_2 precautions to prevent the
*        contents of a header file being included twice
*/
#include "MemMap.h"

#if ((defined ICU_IRQ_0_ISR_USED)  || (defined ICU_IRQ_1_ISR_USED)  || (defined ICU_IRQ_2_ISR_USED)\
  || (defined ICU_IRQ_3_ISR_USED)  || (defined ICU_IRQ_4_ISR_USED)  || (defined ICU_IRQ_5_ISR_USED)\
  || (defined ICU_IRQ_6_ISR_USED)  || (defined ICU_IRQ_7_ISR_USED)  || (defined ICU_IRQ_8_ISR_USED)\
  || (defined ICU_IRQ_9_ISR_USED)  || (defined ICU_IRQ_10_ISR_USED) \
  || (defined ICU_IRQ_11_ISR_USED) || (defined ICU_IRQ_12_ISR_USED) \
  || (defined ICU_IRQ_13_ISR_USED) || (defined ICU_IRQ_14_ISR_USED) \
  || (defined ICU_IRQ_15_ISR_USED) || (defined ICU_IRQ_16_ISR_USED) \
  || (defined ICU_IRQ_17_ISR_USED) || (defined ICU_IRQ_18_ISR_USED) \
  || (defined ICU_IRQ_19_ISR_USED) || (defined ICU_IRQ_20_ISR_USED) \
  || (defined ICU_IRQ_21_ISR_USED) || (defined ICU_IRQ_22_ISR_USED) \
  || (defined ICU_IRQ_23_ISR_USED) || (defined ICU_IRQ_24_ISR_USED) \
  || (defined ICU_IRQ_25_ISR_USED) || (defined ICU_IRQ_26_ISR_USED) \
  || (defined ICU_IRQ_27_ISR_USED) || (defined ICU_IRQ_28_ISR_USED) \
  || (defined ICU_IRQ_29_ISR_USED) || (defined ICU_IRQ_30_ISR_USED) \
  || (defined ICU_IRQ_31_ISR_USED))


/**
* @brief      Icu_Siul_LLD_ProcessInterrupt
* @details
*
* @param[in]      firstHwChannel - first IRQ HW Channel from the HW group
*
* @return void
*
* @implements DICU04405
*/
INLINE FUNC (void, ICU_CODE) Icu_Siul_LLD_ProcessInterrupt(CONST(uint8, AUTOMATIC) firstHwChannel)
{
    VAR(uint8, AUTOMATIC) irq_channel = firstHwChannel;
    VAR(uint32, AUTOMATIC) channelMask = SIUL_CHANNEL_MASK(firstHwChannel);
    VAR(uint32, AUTOMATIC) reg_irq_mask = SIUL_IRQ_CHANNEL_GROUP_MASK(firstHwChannel);
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    CONST(uint32, AUTOMATIC) reg_SIUL_ISR = REG_READ32(SIUL_ISR);
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    CONST(uint32, AUTOMATIC) reg_SIUL_IRER = REG_READ32(SIUL_IRER);

    /* Get only IRQ4 .. IRQ15 flags that has Interrupt enable bit set*/
    reg_irq_mask = reg_irq_mask & reg_SIUL_ISR & reg_SIUL_IRER;
    if(reg_irq_mask > (uint32)0)
     {
    /* Clear pending interrupt serviced */
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    REG_WRITE32(SIUL_ISR, reg_irq_mask );

    while(0x0U != reg_irq_mask)
    {
        if (0x0U != (reg_irq_mask & channelMask))
        {
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_3 Array indexing shall be the only allowed
*           form of pointer arithmetic.
*/
            Icu_LLD_ProcessCommonInterrupt(Icu_Cfg_Ptr->Icu_HWMap[IRQ_ICU_CHANNEL(irq_channel)],  \
                                                                                      reg_SIUL_ISR);
            /* clear the IRQ bit for current IRQ channel*/
            reg_irq_mask = reg_irq_mask & (uint32)(~channelMask);
        }
        irq_channel++;
        channelMask <<= (uint32)1;
    }
     }
}
#endif
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if ((defined ICU_IRQ_0_ISR_USED)  || (defined ICU_IRQ_1_ISR_USED)  || \
     (defined ICU_IRQ_2_ISR_USED)  || (defined ICU_IRQ_3_ISR_USED)  || \
     (defined ICU_IRQ_4_ISR_USED)  || (defined ICU_IRQ_5_ISR_USED)  || \
     (defined ICU_IRQ_6_ISR_USED)  || (defined ICU_IRQ_7_ISR_USED))
/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 0 to 7
* @details   Process the interrupt of SIUL channels 0 to 7
*
* @isr
*
* @implements DICU04401
*
* @note   This will be defined only if any of SIUL channels 0 to 7 is configured
*/
/*================================================================================================*/
ISR(SIUL_EXT_IRQ_0_7_ISR)
{

    Icu_Siul_LLD_ProcessInterrupt(SIUL_IRQ_0);
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    EXIT_INTERRUPT();
}
#endif  /* IRQ 0 - 7 */


#if ((defined ICU_IRQ_8_ISR_USED)   || (defined ICU_IRQ_9_ISR_USED)   || \
     (defined ICU_IRQ_10_ISR_USED)  || (defined ICU_IRQ_11_ISR_USED)  || \
     (defined ICU_IRQ_12_ISR_USED)  || (defined ICU_IRQ_13_ISR_USED)  || \
     (defined ICU_IRQ_14_ISR_USED)  || (defined ICU_IRQ_15_ISR_USED))

/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 8 to 15
* @details   Process the interrupt of SIUL channels 8 to 15
*
* @isr
*
* @implements DICU04402
*
* @note  This will be defined only if any of SIUL channels 8 to 15 is configured
*/
/*================================================================================================*/
ISR(SIUL_EXT_IRQ_8_15_ISR)
{
    Icu_Siul_LLD_ProcessInterrupt(SIUL_IRQ_8);
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    EXIT_INTERRUPT();
}
#endif  /* IRQ 8 - 15 */


#if ((defined ICU_IRQ_16_ISR_USED)  || (defined ICU_IRQ_17_ISR_USED)  || \
     (defined ICU_IRQ_18_ISR_USED)  || (defined ICU_IRQ_19_ISR_USED)  || \
     (defined ICU_IRQ_20_ISR_USED)  || (defined ICU_IRQ_21_ISR_USED)  || \
     (defined ICU_IRQ_22_ISR_USED)  || (defined ICU_IRQ_23_ISR_USED))

/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 16 to 23
* @details   Process the interrupt of SIUL channels 16 to 23
*
* @isr
*
* @implements DICU04403
*
* @note   This will be defined only if any of SIUL channels 16 to 23 is configured
*/
/*================================================================================================*/
ISR(SIUL_EXT_IRQ_16_23_ISR)
{
    Icu_Siul_LLD_ProcessInterrupt(SIUL_IRQ_16);
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    EXIT_INTERRUPT();
}
#endif


#if ((defined ICU_IRQ_24_ISR_USED)  || (defined ICU_IRQ_25_ISR_USED)  || \
     (defined ICU_IRQ_26_ISR_USED)  || (defined ICU_IRQ_27_ISR_USED)  || \
     (defined ICU_IRQ_28_ISR_USED)  || (defined ICU_IRQ_29_ISR_USED)  || \
     (defined ICU_IRQ_30_ISR_USED)  || (defined ICU_IRQ_31_ISR_USED))
/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 24 to 31
* @details   Process the interrupt of SIUL channels 24 to 31
*
* @isr
*
* @implements DICU04404
*
* @note   This will be defined only if any of SIUL channels 16 to 23 is configured
*/
/*================================================================================================*/
ISR(SIUL_EXT_IRQ_24_31_ISR)
{
    Icu_Siul_LLD_ProcessInterrupt(SIUL_IRQ_24);
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_4 Conversions shall not be performed
*  between a pointer to a function and any type other than an integer type
*/
    EXIT_INTERRUPT();
}

#endif

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_1 only preprocessor statements
*        and comments before "#include"
*/
/*
* @violates @ref Icu_Siul_LLD_IRQ_c_2 precautions to prevent the
*        contents of a header file being included twice
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

