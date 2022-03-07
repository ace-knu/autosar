/**
 *     @file    Icu_Wkpu_LLD_IRQ.c
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
* @file    Icu_Wkpu_LLD_IRQ.c
* @remarks Implements DICU06101
*/
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Wkpu_LLD_IRQ_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include" MemMap.h included after each section define in order to set the current memory section
*
* @section Icu_Wkpu_LLD_IRQ_c_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_Wkpu_LLD_IRQ_c_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
* of pointer arithmetic.
* The violation occurs because the variables are defined as per Autosar API specifications.
*
* @section Icu_Wkpu_LLD_IRQ_c_5
*  Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
*  a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
*  registers or other hardware specific features.
*
*@section Icu_Wkpu_LLD_IRQ_c_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
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
#include "Mcal.h"
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"

#include "Reg_eSys_WKPU.h"
#include "Icu_WKPU_LLD.h"
#include "Icu_WKPU_LLD_CfgEx.h"
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
#define WKPU_ICU_LLD_IRQ_VENDOR_ID_C         43

/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_6 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C  4
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_6 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C  0
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_6 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C  3

/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_6 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_IRQ_SW_MAJOR_VERSION_C  1
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_6 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_IRQ_SW_MINOR_VERSION_C  0
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_6 This is required as per autosar Requirement, 
*/
#define WKPU_ICU_LLD_IRQ_SW_PATCH_VERSION_C  1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and WKPU_Icu_LLD.h file are of the same vendor */
#if (WKPU_ICU_LLD_IRQ_VENDOR_ID_C != WKPU_ICU_LLD_VENDOR_ID)
    #error "Icu_Wkpu_LLD_IRQ.c and WKPU_Icu_LLD.h have different vendor IDs"
#endif

    #if ((WKPU_ICU_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_MINOR_VERSION) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_WKPU_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_LLD_IRQ.c and WKPU_Icu_LLD.h are different"
    #endif

/* Check if source file and WKPU_Icu_LLD.h header file are of the same Software version */
/**
*  @file Icu_Wkpu_LLD_IRQ.c
*  @remarks Covers ICU005
*/
#if ((WKPU_ICU_LLD_IRQ_SW_MAJOR_VERSION_C != ICU_WKPU_LLD_H_SW_MAJOR_VERSION) || \
     (WKPU_ICU_LLD_IRQ_SW_MINOR_VERSION_C != ICU_WKPU_LLD_H_SW_MINOR_VERSION) || \
     (WKPU_ICU_LLD_IRQ_SW_PATCH_VERSION_C != ICU_WKPU_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu_LLD_IRQ.c and WKPU_Icu_LLD.h are different"
#endif


/* Check if source file and WKPU_LLD_CfgEx.h file are of the same vendor */
#if (WKPU_ICU_LLD_IRQ_VENDOR_ID_C != WKPU_ICU_LLD_VENDOR_ID)
#error "Icu_Wkpu_LLD_IRQ.c and WKPU_LLD_CfgEx.h have different vendor IDs"
#endif

    #if ((WKPU_ICU_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != WKPU_AR_RELEASE_MAJOR_VERSION_EXT_H) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != WKPU_AR_RELEASE_MINOR_VERSION_EXT_H) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != WKPU_AR_RELEASE_REVISION_VERSION_EXT_H))
    #error "AutoSar Version Numbers of Icu_Wkpu_LLD_IRQ.c and WKPU_LLD_CfgEx.h are different"
    #endif

/* Check if source file and WKPU_LLD_CfgEx.h file are of the same Software version */
/**
*  @file Icu_Wkpu_LLD_IRQ.c
*  @remarks Covers ICU005
*/
#if ((WKPU_ICU_LLD_IRQ_SW_MAJOR_VERSION_C != WKPU_SW_MAJOR_VERSION_EXT_H) || \
     (WKPU_ICU_LLD_IRQ_SW_MINOR_VERSION_C != WKPU_SW_MINOR_VERSION_EXT_H) || \
     (WKPU_ICU_LLD_IRQ_SW_PATCH_VERSION_C != WKPU_SW_PATCH_VERSION_EXT_H))
    #error "Software Version Numbers of Icu_Wkpu_LLD_IRQ.c and WKPU_LLD_CfgEx.h are different"
#endif


/* Check if source file and Icu_LLD.h file are of the same vendor */
#if (WKPU_ICU_LLD_IRQ_VENDOR_ID_C != ICU_LLD_VENDOR_ID)
    #error "Icu_Wkpu_LLD_IRQ.c and Icu_LLD.h have different vendor IDs"
#endif
#ifdef CHECK_AUTOSAR_VERSION
    #if ((WKPU_ICU_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_AR_RELEASE_MINOR_VERSION) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_LLD_IRQ.c and Icu_LLD.h are different"
    #endif
#endif
/* Check if source file and ICU_LLD.h header file are of the same Software version */
/**
*  @file Icu_Wkpu_LLD_IRQ.c
*  @remarks Covers ICU005
*/
#if ((WKPU_ICU_LLD_IRQ_SW_MAJOR_VERSION_C != ICU_LLD_SW_MAJOR_VERSION) || \
     (WKPU_ICU_LLD_IRQ_SW_MINOR_VERSION_C != ICU_LLD_SW_MINOR_VERSION) || \
     (WKPU_ICU_LLD_IRQ_SW_PATCH_VERSION_C != ICU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Wkpu_LLD_IRQ.c and Icu_LLD.h are different"
#endif


/* Check if source file and Reg_eSys_WKPU.h file are of the same vendor */
#if (WKPU_ICU_LLD_IRQ_VENDOR_ID_C != REG_ESYS_WKPU_VENDOR_ID)
#error "Icu_Wkpu_LLD_IRQ.c and WKPU_Icu_LLD.h have different vendor IDs"
#endif

    #if ((WKPU_ICU_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_WKPU_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_WKPU_AR_RELEASE_MINOR_VERSION) || \
         (WKPU_ICU_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_WKPU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_LLD_IRQ.c and WKPU_Icu_LLD.h are different"

#endif
/* Check if source file and WKPU_Icu_LLD.h header file are of the same Software version */
#if ((WKPU_ICU_LLD_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_WKPU_SW_MAJOR_VERSION) || \
     (WKPU_ICU_LLD_IRQ_SW_MINOR_VERSION_C != REG_ESYS_WKPU_SW_MINOR_VERSION) || \
     (WKPU_ICU_LLD_IRQ_SW_PATCH_VERSION_C != REG_ESYS_WKPU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Wkpu_LLD_IRQ.c and Reg_eSys_WKPU.h are different"
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
#if ((defined ICU_WKUP_0_ISR_USED)  || (defined ICU_WKUP_1_ISR_USED)  ||  \
                                (defined ICU_WKUP_2_ISR_USED) || (defined ICU_WKUP_3_ISR_USED) || \
     (defined ICU_WKUP_4_ISR_USED)  || (defined ICU_WKUP_5_ISR_USED)  ||  \
                                (defined ICU_WKUP_6_ISR_USED) || (defined ICU_WKUP_7_ISR_USED))
ISR(WKPU_EXT_IRQ_0_7_ISR);
#endif

#if ((defined ICU_WKUP_8_ISR_USED)   || (defined ICU_WKUP_9_ISR_USED)   || \
                              (defined ICU_WKUP_10_ISR_USED) || (defined ICU_WKUP_11_ISR_USED) || \
     (defined ICU_WKUP_12_ISR_USED)  || (defined ICU_WKUP_13_ISR_USED)  || \
                              (defined ICU_WKUP_14_ISR_USED) || (defined ICU_WKUP_15_ISR_USED))
ISR(WKPU_EXT_IRQ_8_15_ISR);
#endif

#if ((defined ICU_WKUP_16_ISR_USED)  || (defined ICU_WKUP_17_ISR_USED)  || \
                              (defined ICU_WKUP_18_ISR_USED) || (defined ICU_WKUP_19_ISR_USED) || \
     (defined ICU_WKUP_20_ISR_USED)  || (defined ICU_WKUP_21_ISR_USED)  || \
                              (defined ICU_WKUP_22_ISR_USED) || (defined ICU_WKUP_23_ISR_USED))
ISR(WKPU_EXT_IRQ_16_23_ISR);
#endif

#if ((defined ICU_WKUP_24_ISR_USED)  || (defined ICU_WKUP_25_ISR_USED)  || \
                              (defined ICU_WKUP_26_ISR_USED) || (defined ICU_WKUP_27_ISR_USED) || \
     (defined ICU_WKUP_28_ISR_USED)  || (defined ICU_WKUP_29_ISR_USED)  || \
                              (defined ICU_WKUP_30_ISR_USED) || (defined ICU_WKUP_31_ISR_USED))
ISR(WKPU_EXT_IRQ_24_31_ISR);
#endif

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @file  Icu_Wkpu_LLD_IRQ.c
* @violates @ref  Icu_Wkpu_LLD_IRQ_c_1  MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*  and comments before "#include"
*/

/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if ((defined ICU_WKUP_0_ISR_USED)  || (defined ICU_WKUP_1_ISR_USED)  ||  \
                              (defined ICU_WKUP_2_ISR_USED)  || (defined ICU_WKUP_3_ISR_USED)  || \
     (defined ICU_WKUP_4_ISR_USED)  || (defined ICU_WKUP_5_ISR_USED)  ||  \
                              (defined ICU_WKUP_6_ISR_USED)  || (defined ICU_WKUP_7_ISR_USED)  || \
     (defined ICU_WKUP_8_ISR_USED)  || (defined ICU_WKUP_9_ISR_USED)  ||  \
                              (defined ICU_WKUP_10_ISR_USED) || (defined ICU_WKUP_11_ISR_USED) || \
     (defined ICU_WKUP_12_ISR_USED) || (defined ICU_WKUP_13_ISR_USED) ||  \
                              (defined ICU_WKUP_14_ISR_USED) || (defined ICU_WKUP_15_ISR_USED) || \
     (defined ICU_WKUP_16_ISR_USED) || (defined ICU_WKUP_17_ISR_USED) ||  \
                              (defined ICU_WKUP_18_ISR_USED) || (defined ICU_WKUP_19_ISR_USED) || \
     (defined ICU_WKUP_20_ISR_USED) || (defined ICU_WKUP_21_ISR_USED) ||  \
                              (defined ICU_WKUP_22_ISR_USED) || (defined ICU_WKUP_23_ISR_USED) || \
     (defined ICU_WKUP_24_ISR_USED) || (defined ICU_WKUP_25_ISR_USED) ||  \
                              (defined ICU_WKUP_26_ISR_USED) || (defined ICU_WKUP_27_ISR_USED) || \
     (defined ICU_WKUP_28_ISR_USED) || (defined ICU_WKUP_29_ISR_USED) ||  \
                              (defined ICU_WKUP_30_ISR_USED) || (defined ICU_WKUP_31_ISR_USED))
/*==================================================================================================*/
/**
* @brief      Icu_WKPU_LLD_ProcessInterrupt
* @details
*
* @param[in]      firstHwChannel - first IRQ HW Channel from the HW group
*
* @retval None
*
* @implements  DICU06102
*/
/*==================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_WKPU_LLD_ProcessInterrupt(
                                                             CONST(uint8, AUTOMATIC) firstHwChannel)
{
    VAR(uint8, AUTOMATIC) Wk_channel = firstHwChannel;
    VAR(uint32, AUTOMATIC) channelMask = WKPU_CHANNEL_MASK(firstHwChannel);
    VAR(uint32, AUTOMATIC) reg_wk_mask = WKPU_IRQ_CHANNEL_GROUP_MASK(firstHwChannel);
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_5 MISRA 2004 Rule 11.1: Conversions shall not be performed
*           between a pointer to a function and any type other than an integer type
*/
    CONST(uint32, AUTOMATIC) reg_WKPU_WISR = REG_READ32(WKPU_WISR);

    /* Get  WKUP0 -WKUP310 flags that has Interrupt enable bit set*/
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_5 MISRA 2004 Rule 11.1: Conversions shall not be performed
*           between a pointer to a function and any type other than an integer type
*/
    reg_wk_mask = ( reg_wk_mask & (reg_WKPU_WISR & REG_READ32(WKPU_IRER)));
    if(reg_wk_mask > (uint32)0)
    {
    /* Clear pending interrupt serviced */
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_5 MISRA 2004 Rule 11.1: Conversions shall not be performed
*           between a pointer to a function and any type other than an integer type
*/
    REG_WRITE32(WKPU_WISR, reg_wk_mask );
    while(0x0U != reg_wk_mask)
    {
        if (0x0U != (reg_wk_mask & channelMask))
        {
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_4 Array indexing shall be the only allowed form of
*                 pointer arithmetic.
*/
            Icu_LLD_ProcessCommonInterrupt(Icu_Cfg_Ptr->Icu_HWMap[WKPU_ICU_CHANNEL(Wk_channel)], \
                                                                                   reg_WKPU_WISR);
            /* clear the IRQ bit for current IRQ channel*/
            reg_wk_mask = (reg_wk_mask & (uint32)(~channelMask));
        }
        Wk_channel++;
        channelMask <<= (uint32)1U;
        }
    }
}
#endif

#if ((defined ICU_WKUP_0_ISR_USED)  || (defined ICU_WKUP_1_ISR_USED)  ||  \
                                 (defined ICU_WKUP_2_ISR_USED) || (defined ICU_WKUP_3_ISR_USED) || \
     (defined ICU_WKUP_4_ISR_USED)  || (defined ICU_WKUP_5_ISR_USED)  ||  \
                                 (defined ICU_WKUP_6_ISR_USED) || (defined ICU_WKUP_7_ISR_USED))


/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 0 to 7
* @details   Process the interrupt of WKPU channels 0 to 7
*
* @remarks   This will be defined only if any of WKPU channels 0 to 7 is configured
* @implements  DICU06103
*
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_0_7_ISR)
{
    Icu_WKPU_LLD_ProcessInterrupt(WKPU_0);
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_5 MISRA 2004 Rule 11.1: Conversions shall not be performed
*           between a pointer to a function and any type other than an integer type
*/    
    EXIT_INTERRUPT();
}

#endif  /* WKPU IRQ 0 - 7 */


#if ((defined ICU_WKUP_8_ISR_USED)   || (defined ICU_WKUP_9_ISR_USED)   ||  \
                               (defined ICU_WKUP_10_ISR_USED) || (defined ICU_WKUP_11_ISR_USED) || \
     (defined ICU_WKUP_12_ISR_USED)  || (defined ICU_WKUP_13_ISR_USED)  ||  \
                               (defined ICU_WKUP_14_ISR_USED) || (defined ICU_WKUP_15_ISR_USED))

/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 8 to 15
* @details   Process the interrupt of WKPU channels 8 to 15
*
* @remarks   This will be defined only if any of WKPU channels 8 to 15 is configured
* @implements  DICU06104
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_8_15_ISR)
{
    Icu_WKPU_LLD_ProcessInterrupt(WKPU_8);
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_5 MISRA 2004 Rule 11.1: Conversions shall not be performed
*           between a pointer to a function and any type other than an integer type
*/
    EXIT_INTERRUPT();
}

#endif  /* WKPU IRQ 8 - 15 */


#if ((defined ICU_WKUP_16_ISR_USED)  || (defined ICU_WKUP_17_ISR_USED)  ||  \
                               (defined ICU_WKUP_18_ISR_USED) || (defined ICU_WKUP_19_ISR_USED) || \
(defined ICU_WKUP_20_ISR_USED)  || (defined ICU_WKUP_21_ISR_USED)  ||  \
                               (defined ICU_WKUP_22_ISR_USED) || (defined ICU_WKUP_23_ISR_USED))


/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 16 to 23
* @details   Process the interrupt of WKPU channels 16 to 23
*
* @remarks   This will be defined only if any of WKPU channels 16 to 23 is configured
* @implements  DICU06105
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_16_23_ISR)
{
    Icu_WKPU_LLD_ProcessInterrupt(WKPU_16);
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_5 MISRA 2004 Rule 11.1: Conversions shall not be performed
*           between a pointer to a function and any type other than an integer type
*/    
    EXIT_INTERRUPT();
}

#endif   /* WKPU IRQ 16 - 23 */


#if ((defined ICU_WKUP_24_ISR_USED)  || (defined ICU_WKUP_25_ISR_USED)  ||  \
                               (defined ICU_WKUP_26_ISR_USED) || (defined ICU_WKUP_27_ISR_USED) || \
     (defined ICU_WKUP_28_ISR_USED)  || (defined ICU_WKUP_29_ISR_USED)  ||  \
                                (defined ICU_WKUP_30_ISR_USED) || (defined ICU_WKUP_31_ISR_USED))


/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 24 to 31
* @details   Process the interrupt of WKPU channels 24 to 31
*
* @remarks   This will be defined only if any of WKPU channels 24 to 31 is configured
* @implements  DICU06106
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_24_31_ISR)
{
   Icu_WKPU_LLD_ProcessInterrupt(WKPU_24);
/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_5 MISRA 2004 Rule 11.1: Conversions shall not be performed
*           between a pointer to a function and any type other than an integer type
*/   
   EXIT_INTERRUPT();
}

#endif   /* WKPU IRQ 24 - 31 */


#define ICU_STOP_SEC_CODE
/**
* @file  Icu_Wkpu_LLD_IRQ.c
* @violates @ref Icu_Wkpu_LLD_IRQ_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before "#include"
*/

/*
* @violates @ref Icu_Wkpu_LLD_IRQ_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "MemMap.h"



#ifdef __cplusplus
}
#endif
/**@}*/
