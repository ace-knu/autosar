/**
*   @file    Wdg_Irq.c
*   @version 1.0.1
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) Registers
*   @details Contains information about the SWT's registers
*
*   @addtogroup  Wdg
 * @{
 */
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF12_ASR_REL_4_0_REV_0003_20161209
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
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
* @section Wdg_Irq_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Wdg_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* define name is required by the AUTOSAR specifications although it exceedes the max length of 31 characters.
*
* @section Wdg_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer
* This macro compute the address of any register by using the hardware offset of the controller. The address 
* calculated as an unsigned int is passed to a macro for initializing the pointer with that address.
* (ex:see REG_WRITE32 macro).
*
* @section Wdg_Irq_c_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include". 
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Wdg_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 8.1, Functions shall has prototype delarations and the prototype
* shall be visible at both the function definetion and the call
* requirement MEMMAP003.
*
* @section Wdg_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness, and 10.3,
* Cast of complex integer expression to larger type.
* Many type conversions are implemented in MACROS. The code was tested successfully with 3
* different compilers.

* @section Wdg_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters

* @section Wdg_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator: '&&'
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Channel.h"
/*
* @violates @ref Wdg_Irq_c_REF_1 MISRA 2004 Required Rule 19.15, Precautions shall be taken in order 
* to prevent the contents of a header file being included twice.
*/

#if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif
#include "Reg_eSys_Swt.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/



#define WDG_VENDOR_ID_IRQ                      43
/* @violates @ref Wdg_Irq_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MAJOR_VERSION_IRQ       4
/* @violates @ref Wdg_Irq_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define WDG_AR_RELEASE_MINOR_VERSION_IRQ       0
/* @violates @ref Wdg_Irq_c_REF_7 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
/* @violates @ref Wdg_Irq_c_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define WDG_AR_RELEASE_REVISION_VERSION_IRQ    3
#define WDG_SW_MAJOR_VERSION_IRQ               1
#define WDG_SW_MINOR_VERSION_IRQ               0
#define WDG_SW_PATCH_VERSION_IRQ               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg header file are of the same vendor */
#if (WDG_VENDOR_ID_IRQ != WDG_CHANNEL_VENDOR_ID)
    #error " Wdg_Irq.c and Wdg_Channel.h have different vendor ids"
#endif
/* Check if current file and Wdg header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_IRQ    != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION_IRQ    != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION_IRQ != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Irq.c and Wdg.h are different"
#endif
/* Check if current file and Wdg header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_IRQ != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION_IRQ != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION_IRQ != WDG_CHANNEL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Irq.c and Wdg_Channel.h are different"
#endif
#if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* Check if current file and Dem header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_AR_RELEASE_MAJOR_VERSION_IRQ != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_AR_RELEASE_REVISION_VERSION_IRQ != DEM_AR_RELEASE_REVISION_VERSION) || \
         (WDG_AR_RELEASE_MINOR_VERSION_IRQ != DEM_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Irq.c and Dem.h are different"
    #endif
#endif
#endif
/* Check if current file and Reg_eSys_Swt header file are of the same vendor */
#if (WDG_VENDOR_ID_IRQ != REG_ESYS_SWT_VENDOR_ID)
    #error " Wdg_Irq.c and Reg_eSys_Swt.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_Swt header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_IRQ    != REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION_IRQ    != REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION_IRQ != REG_ESYS_SWT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Irq.c and Reg_eSys_Swt.h are different"
#endif
/* Check if current file and Reg_eSys_Swt header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_IRQ != REG_ESYS_SWT_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION_IRQ != REG_ESYS_SWT_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION_IRQ != REG_ESYS_SWT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Irq.c and Reg_eSys_Swt.h are different"
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
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif

/* @violates @ref Wdg_Irq_c_REF_1 Precaution shall be taken in order to prevent  the contents of a header file being included twice. */
/* @violates @ref Wdg_Irq_c_REF_4 Only preprocessor statements and comments before 'include' */
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/**
*   @brief   This function treats the SWT interrupt.
*   @details This function process the SWT interrupt
*   @pre     This ISR is only required if the WDG_ISR_USED option is
*            enabled.
*   @param[in]          Wdg_Instance        Harwdware SWT instance.
*
*   @isr
*
*/
#if ((defined WDG_ISR0_USED) ||  defined(__DOXYGEN__))
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_Swt_ProcessInterrupt(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    /* Service interrupt flag */
    /* Check that the time-out interrupt flag is set. If not, call a CER event*/
/* @violates @ref Wdg_Irq_c_REF_3 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
    volatile VAR(uint32, AUTOMATIC) Interrupt_Enable_Flag = REG_READ32(SWT_CR(Wdg_Instance)) & SWT_INTERRUPT_TOGGLE;
/* @violates @ref Wdg_Irq_c_REF_3 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */    
    volatile VAR(uint32, AUTOMATIC) Interrupt_status_Flag = REG_READ32(SWT_IR(Wdg_Instance)) & SWT_IR_CLEAR;
/* @violates @ref Wdg_Irq_c_REF_3 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
/* @violates @ref Wdg_Irq_c_REF_8 MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator: '&&'*/
    if((SWT_IR_CLEAR == Interrupt_status_Flag)&&(SWT_INTERRUPT_TOGGLE==Interrupt_Enable_Flag))
    {
        /* Service interrupt flag */
       /** @violates @ref Wdg_Irq_c_REF_3 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer */
        REG_BIT_SET32(SWT_IR(Wdg_Instance),SWT_IR_CLEAR);

    }

    if (NULL_PTR !=Ram_LLD_ConfigPtr[Wdg_Instance]->Wdg_CallBackPtr)
    {
        Ram_LLD_ConfigPtr[Wdg_Instance]->Wdg_CallBackPtr();
    }
    
#if(WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    if ((uint32)STD_ON == (uint32)Wdg_E_Miss_TriggerCfg.state)
    {
    /* Report to DEM module WDG missed a trigger*/
       Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Miss_TriggerCfg.id , DEM_EVENT_STATUS_FAILED);
    }
#endif
    
    /*
    * @violates @ref Wdg_Irq_c_REF_3 MISRA 2004 Required Rule 11.1, Conversions shall not be
    * performed between a pointer to a function and any type than an integral type.
    */
    EXIT_INTERRUPT();
}
#endif

#ifdef WDG_ISR0_USED
/**
*   @brief   This function process the interrupt SWT0.
*   @details This function process the SWT0 interrupt
 *  @pre    This ISR is only required if the WDG_ISR_USED option is
 *          enabled.
 *
 *  @isr
 *
 *  @remarks Implements DWDG04000   
*/
ISR(Wdg_Isr0)
/* @violates @ref Wdg_Irq_c_REF_5 Function 'Wdg_Isr0' defined without a prototype in scope */
{
    Wdg_Swt_ProcessInterrupt(WDG_IPW_INSTANCE0);
    /* @violates @ref Wdg_Irq_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    EXIT_INTERRUPT();
}

#endif /* WDG_ISR_USED */


#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif

/* @violates @ref Wdg_Irq_c_REF_1 Precaution shall be taken in order to prevent  the contents of a header file being included twice. */
/* @violates @ref Wdg_Irq_c_REF_4 Only preprocessor statements and comments before 'include' */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
