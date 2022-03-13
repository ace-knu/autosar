/**
*   @file    Can_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Interrupt routines for Can driver.
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
* @section Can_Irq_c_REF_1
* Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition.
* This violation is due to the use of multiple #/## in a macro because some interrupts can process both Tx/Rx
* in the same interrupt routine and have use twice this parameter. the parameter obtained with #/## is the same for
* all functions called in the interrupt routine.
*
* @section Can_Irq_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.13,'#/##' operator used.
* This violation is due to the use of ## used to concatenate the Controller Index (A, B, ..) in ISR function name.
*
* @section Can_Irq_c_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_Irq_c_REF_4
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* This violation is because many controllers have defined Interrupt handlers with only 1 macro.
*
* @section Can_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 1.4, Identifier clash, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section Can_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_Irq_c_REF_9
* Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
* converted to a different underlying type if: a) it is not a
* conversion to a wider integer type of the same signedness, or b)
* the expression is complex, or c) the expression is not constant
* and is a function argument, or d) the expression is not constant
* and is a return expression
*
* @section Can_Irq_c_REF_10
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*
* @section Can_Irq_c_REF_11
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
 * significance of more than 31 characters.
*
* @section Can_Irq_c_REF_12
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be
* permitted.
*
* @section Can_Irq_c_REF_13
* Violates MISRA 2004 Required Rule 12.8, The right hand operand of a shift operator shall lie between zero
* and one less than the width in bits of the underlying type of the left hand operand.
*
* @section Can_Irq_c_REF_14
* Violates MISRA 2004 Required Rule 19.10, Within a definition of a function-like macro, 
* the arguments shall be enclosed in parentheses.
*
*/

/*
(CAN035) The module Can_Irq.c contains the implementation of interrupt frames.The implementation of the interrupt service routine shall be in Can.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Can_Irq.c
* @implements     DCAN02605
*/
#include "Can.h"
#include "Can_LLD.h"
#include "CanIf_Cbk.h"
#include "Mcal.h"
#if (CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM_Cbk.h"
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* The integration of incompatible files shall be avoided. */
#define CAN_VENDOR_ID_IRQ_C                      43
/* @violates @ref Can_Irq_c_REF_11 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
/* @violates @ref Can_Irq_c_REF_11 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_MINOR_VERSION_IRQ_C       0
/*
* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/
/* @violates @ref Can_Irq_c_REF_11 This is required as per autosar Requirement. */
#define CAN_AR_RELEASE_REVISION_VERSION_IRQ_C    3
#define CAN_SW_MAJOR_VERSION_IRQ_C               1
#define CAN_SW_MINOR_VERSION_IRQ_C               0
#define CAN_SW_PATCH_VERSION_IRQ_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_IRQ_C != CAN_VENDOR_ID)
    #error "Can_Irq.c and Can.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C    != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C    != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_IRQ_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_Irq.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_IRQ_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_IRQ_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_IRQ_C != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_Irq.c and Can.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Irq.c and Det.h are different"
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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/*
   (CAN033) The Can module shall implement the interrupt service routines for all CAN Hardware Unit
   interrupts that are needed. The Can module shall disable all unused interrupts in the CAN controller.
   The Can module shall reset the interrupt flag at the end of the ISR (if not done automatically by
   hardware). The Can module shall not set the configuration (i.e. priority) of the vector table entry.
*/
/*
* @brief          CAN controller A interrupts
* @details        CAN controller A interrupts
*
* @implements     DCAN02602
*
*/
/* CAN controller A interrupts */
#ifdef CAN_FCA_INDEX
  #if (CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCA_ERR);
  #endif
    #if (CAN_A_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCA_BO);
    #endif /* (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_A_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            ISR(Can_IsrFCA_WKP);
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_A_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCA_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCA_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCA_FrameAv);
                    ISR(Can_IsrFCA_Overf);
                    ISR(Can_IsrFCA_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCA_MB_00_03);
                ISR(Can_IsrFCA_MB_04_07);
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCA_MB_08_11);
            ISR(Can_IsrFCA_MB_12_15);
            ISR(Can_IsrFCA_MB_16_31);
            ISR(Can_IsrFCA_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCA_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCA_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCA_FrameAv);
                    ISR(Can_IsrFCA_Overf);
                    ISR(Can_IsrFCA_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCA_MB_00_03);
                ISR(Can_IsrFCA_MB_04_07);
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCA_MB_08_11);
            ISR(Can_IsrFCA_MB_12_15);
            ISR(Can_IsrFCA_MB_16_31);
            ISR(Can_IsrFCA_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCA_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_OFF)
                ISR(Can_IsrFCA_MB_00_03);
                ISR(Can_IsrFCA_MB_04_07);
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCA_MB_08_11);
            ISR(Can_IsrFCA_MB_12_15);
            ISR(Can_IsrFCA_MB_16_31);
            ISR(Can_IsrFCA_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCA_INDEX */

/*
* @brief          CAN controller B interrupts
* @details        CAN controller B interrupts
*
* @implements     DCAN02602
*
*/
/* CAN controller B interrupts */
#ifdef CAN_FCB_INDEX
  #if (CAN_B_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCB_ERR);
  #endif
    #if (CAN_B_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCB_BO);
    #endif /* (CAN_B_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_B_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            ISR(Can_IsrFCB_WKP);
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_B_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCB_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCB_FrameAv);
                    ISR(Can_IsrFCB_Overf);
                    ISR(Can_IsrFCB_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCB_MB_00_03);
                ISR(Can_IsrFCB_MB_04_07);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCB_MB_08_11);
            ISR(Can_IsrFCB_MB_12_15);
            ISR(Can_IsrFCB_MB_16_31);
            ISR(Can_IsrFCB_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_OFF) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCB_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCB_FrameAv);
                    ISR(Can_IsrFCB_Overf);
                    ISR(Can_IsrFCB_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCB_MB_00_03);
                ISR(Can_IsrFCB_MB_04_07);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCB_MB_08_11);
            ISR(Can_IsrFCB_MB_12_15);
            ISR(Can_IsrFCB_MB_16_31);
            ISR(Can_IsrFCB_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_OFF)
                ISR(Can_IsrFCB_MB_00_03);
                ISR(Can_IsrFCB_MB_04_07);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCB_MB_08_11);
            ISR(Can_IsrFCB_MB_12_15);
            ISR(Can_IsrFCB_MB_16_31);
            ISR(Can_IsrFCB_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCB_INDEX */

/*
* @brief          CAN controller C interrupts
* @details        CAN controller C interrupts
**/
/* CAN controller C interrupts */
#ifdef CAN_FCC_INDEX
  #if (CAN_C_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCC_ERR);
  #endif
    #if (CAN_C_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCC_BO);
    #endif /* (CAN_C_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_C_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            ISR(Can_IsrFCC_WKP);
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_B_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCC_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCC_FrameAv);
                    ISR(Can_IsrFCC_Overf);
                    ISR(Can_IsrFCC_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCC_MB_00_03);
                ISR(Can_IsrFCC_MB_04_07);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCC_MB_08_11);
            ISR(Can_IsrFCC_MB_12_15);
            ISR(Can_IsrFCC_MB_16_31);
            ISR(Can_IsrFCC_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_OFF) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCC_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCC_FrameAv);
                    ISR(Can_IsrFCC_Overf);
                    ISR(Can_IsrFCC_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCC_MB_00_03);
                ISR(Can_IsrFCC_MB_04_07);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCC_MB_08_11);
            ISR(Can_IsrFCC_MB_12_15);
            ISR(Can_IsrFCC_MB_16_31);
            ISR(Can_IsrFCC_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_OFF)
                ISR(Can_IsrFCC_MB_00_03);
                ISR(Can_IsrFCC_MB_04_07);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCC_MB_08_11);
            ISR(Can_IsrFCC_MB_12_15);
            ISR(Can_IsrFCC_MB_16_31);
            ISR(Can_IsrFCC_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCC_INDEX */
/*
* @brief          CAN controller D interrupts
* @details        CAN controller D interrupts **/
/* CAN controller D interrupts */
#ifdef CAN_FCD_INDEX
  #if (CAN_D_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCD_ERR);
  #endif
    #if (CAN_D_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCD_BO);
    #endif /* (CAN_D_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_D_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            ISR(Can_IsrFCD_WKP);
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_D_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCD_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCD_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCD_FrameAv);
                    ISR(Can_IsrFCD_Overf);
                    ISR(Can_IsrFCD_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCD_MB_00_03);
                ISR(Can_IsrFCD_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCD_MB_08_11);
            ISR(Can_IsrFCD_MB_12_15);
            ISR(Can_IsrFCD_MB_16_31);
            ISR(Can_IsrFCD_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_OFF) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCD_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCD_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCD_FrameAv);
                    ISR(Can_IsrFCD_Overf);
                    ISR(Can_IsrFCD_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCD_MB_00_03);
                ISR(Can_IsrFCD_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCD_MB_08_11);
            ISR(Can_IsrFCD_MB_12_15);
            ISR(Can_IsrFCD_MB_16_31);
            ISR(Can_IsrFCD_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCD_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_D_FIFO_EN == STD_OFF)
                ISR(Can_IsrFCD_MB_00_03);
                ISR(Can_IsrFCD_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCD_MB_08_11);
            ISR(Can_IsrFCD_MB_12_15);
            ISR(Can_IsrFCD_MB_16_31);
            ISR(Can_IsrFCD_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCD_INDEX */
/*
* @brief          CAN controller E interrupts
* @details        CAN controller E interrupts **/
/* CAN controller E interrupts */
#ifdef CAN_FCE_INDEX
  #if (CAN_E_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCE_ERR);
  #endif
    #if (CAN_E_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCE_BO);
    #endif /* (CAN_E_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_E_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            ISR(Can_IsrFCE_WKP);
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_E_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCE_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCE_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCE_FrameAv);
                    ISR(Can_IsrFCE_Overf);
                    ISR(Can_IsrFCE_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_E_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCE_MB_00_03);
                ISR(Can_IsrFCE_MB_04_07);
            #endif /* (CAN_E_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCE_MB_08_11);
            ISR(Can_IsrFCE_MB_12_15);
            ISR(Can_IsrFCE_MB_16_31);
            ISR(Can_IsrFCE_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_OFF) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCE_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCE_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCE_FrameAv);
                    ISR(Can_IsrFCE_Overf);
                    ISR(Can_IsrFCE_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_E_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCE_MB_00_03);
                ISR(Can_IsrFCE_MB_04_07);
            #endif /* (CAN_E_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCE_MB_08_11);
            ISR(Can_IsrFCE_MB_12_15);
            ISR(Can_IsrFCE_MB_16_31);
            ISR(Can_IsrFCE_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCE_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_E_FIFO_EN == STD_OFF)
                ISR(Can_IsrFCE_MB_00_03);
                ISR(Can_IsrFCE_MB_04_07);
            #endif /* (CAN_E_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCE_MB_08_11);
            ISR(Can_IsrFCE_MB_12_15);
            ISR(Can_IsrFCE_MB_16_31);
            ISR(Can_IsrFCE_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCE_INDEX */
/*
* @brief          CAN controller F interrupts
* @details        CAN controller F interrupts
**/
/* CAN controller F interrupts */
#ifdef CAN_FCF_INDEX
  #if (CAN_F_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCF_ERR);
  #endif
    #if (CAN_F_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCF_BO);
    #endif /* (CAN_F_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_F_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            ISR(Can_IsrFCF_WKP);
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_E_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCF_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCF_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCF_FrameAv);
                    ISR(Can_IsrFCF_Overf);
                    ISR(Can_IsrFCF_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCF_MB_00_03);
                ISR(Can_IsrFCF_MB_04_07);
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCF_MB_08_11);
            ISR(Can_IsrFCF_MB_12_15);
            ISR(Can_IsrFCF_MB_16_31);
            ISR(Can_IsrFCF_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_OFF) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCF_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCF_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCF_FrameAv);
                    ISR(Can_IsrFCF_Overf);
                    ISR(Can_IsrFCF_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                ISR(Can_IsrFCF_MB_00_03);
                ISR(Can_IsrFCF_MB_04_07);
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCF_MB_08_11);
            ISR(Can_IsrFCF_MB_12_15);
            ISR(Can_IsrFCF_MB_16_31);
            ISR(Can_IsrFCF_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCF_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_F_FIFO_EN == STD_OFF)
                ISR(Can_IsrFCF_MB_00_03);
                ISR(Can_IsrFCF_MB_04_07);
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */

            ISR(Can_IsrFCF_MB_08_11);
            ISR(Can_IsrFCF_MB_12_15);
            ISR(Can_IsrFCF_MB_16_31);
            ISR(Can_IsrFCF_MB_32_63);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCF_INDEX */

/*==================================================================================================*/
/*
* @brief          Interrupt routine for Rx fifo Suppport.
* @details        Interrupt routine for Rx fifo Suppport.  Defined as macro.
*                 The controller ID is transmitted with the ## operator for the interrupt handler.
*                 FC - Can hardware channel: A, B, C, D, E, F.
*
*/

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define CAN_RXFIFO_EVENTS(FC) \
            ISR(Can_IsrFC##FC##_RxFifoEvents) { \
                    VAR(uint32, CAN_VAR)   can_status = 0U; \
                    can_status = (uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET) ; \
                    can_status &= (uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET) ; \
                    if (FLEXCAN_FIFO_AVAILABLE_INT_MASK == (can_status & FLEXCAN_FIFO_AVAILABLE_INT_MASK)) \
                    { \
                Can_LLD_RxFifoFrameAvNotif(CAN_FC##FC##_INDEX); \
                    } \
                    if (FLEXCAN_FIFO_OVERFLOW_INT_MASK == (can_status & FLEXCAN_FIFO_OVERFLOW_INT_MASK)) \
                    { \
                if (NULL_PTR != Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification) { \
                    Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification(); \
                } \
                    }\
                    if ( FLEXCAN_FIFO_WARNING_INT_MASK== (can_status & FLEXCAN_FIFO_WARNING_INT_MASK)) \
                    { \
                if (NULL_PTR != Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification) { \
                    Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification(); \
                } \
                    } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_ON) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

/*==================================================================================================*/
/*
* @brief          Interrupt routine for Rx fifo Overflow.
* @details        Interrupt routine for Rx fifo Overflow.  Defined as macro.
*                 The controller ID is transmitted with the ## operator for the interrupt handler.
*             FC - Can hardware channel: A, B, C, D, E, F.
*
*/

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
        /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
        /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define CAN_MB_RXOVER(FC) \
            ISR(Can_IsrFC##FC##_Overf) { \
                VAR(uint32, CAN_VAR)   can_status = 0U; \
                can_status = ((uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_FIFO_OVERFLOW_INT_MASK); \
                can_status &= ((uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_FIFO_OVERFLOW_INT_MASK); \
                if (FLEXCAN_FIFO_OVERFLOW_INT_MASK == can_status) \
                { \
                if (NULL_PTR != Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification) { \
                    Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoOverflowNotification(); \
                    } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


/*==================================================================================================*/
/*
* @brief          Interrupt routine for Rx fifo Warning.
* @details        Interrupt routine for Rx fifo Warning.  Defined as macro.
*                 The controller ID is transmitted with the ## operator for the interrupt handler.
*                 FC - Can hardware channel: A, B.
*
*/

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
        /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
        /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define CAN_MB_RXWARN(FC) \
            ISR(Can_IsrFC##FC##_Warn) { \
                VAR(uint32, CAN_VAR)   can_status = 0U; \
                can_status = ((uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_FIFO_WARNING_INT_MASK); \
                can_status &= ((uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_FIFO_WARNING_INT_MASK); \
                if (FLEXCAN_FIFO_WARNING_INT_MASK == can_status) \
                { \
                if (NULL_PTR != Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification) { \
                    Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_RxFifoWarningNotification(); \
                } \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */


/*==================================================================================================*/
/*
* @brief          Interrupt routine for Rx fifo Frame Available.
* @details        Interrupt routine for Rx fifo Frame Available.  Defined as macro.
*                 The controller ID is transmitted with the ## operator for the interrupt handler.
*             FC - Can hardware channel: A, B, C, D, E, F.
*
*/

#if (CAN_RXFIFO_ENABLE == STD_ON)
    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF)
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
        /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
        /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define CAN_MB_FRAV(FC) \
            ISR(Can_IsrFC##FC##_FrameAv) { \
                VAR(uint32, CAN_VAR)   can_status = 0U; \
                can_status = ((uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_FIFO_AVAILABLE_INT_MASK); \
                can_status &= ((uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_FIFO_AVAILABLE_INT_MASK); \
                if (FLEXCAN_FIFO_AVAILABLE_INT_MASK == can_status) \
                { \
                Can_LLD_RxFifoFrameAvNotif( CAN_FC##FC##_INDEX); \
                } \
                EXIT_INTERRUPT(); \
            }
    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
/*==================================================================================================*/
/**
@brief     Macro to Read status of the MB (for MBs from 0 to 63).

@remarks   The controller ID is transmitted with the ## operator for the interrupt handler.
           FC - Can hardware channel: A, B, C, D, E, F.
*/
/*==================================================================================================*/
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define MB_STATUS_READ(FC) \
            VAR(uint32, CAN_VAR) can_status1 = 0U; \
            VAR(uint32, CAN_VAR) can_status2 = 0U; \
            can_status1 = (uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET); \
            can_status1 &= (uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET); \
            can_status2 = (uint32)FLEXCAN_IFLAG2_READ(FLEXCAN_##FC##_OFFSET); \
            can_status2 &= (uint32)FLEXCAN_IMASK2_READ(FLEXCAN_##FC##_OFFSET);
#else
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define MB_STATUS_READ(FC) \
            VAR(uint32, CAN_VAR) can_status1 = 0U; \
            VAR(uint32, CAN_VAR) can_status2 = 0U; \
            can_status1 = (uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET); \
            can_status1 &= (uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET); 
#endif
/*==================================================================================================*/

/*==================================================================================================*/
/*
* @brief          Interrupt routine for all MBs  - optimization code size.
* @details        Process all MBs defined for current controller. MBs are grouped: HRHs first, the HTHs.
*                 The controller ID is transmitted with the ## operator for the interrupt handler.
*            FC - Can hardware channel: A, B, C, D, E, F.
*
*/    

#if (CAN_ISROPTCODESIZE == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    #define CAN_MB_UNIISRS(FC) \
        ISR(Can_IsrFC##FC##_UNI) { \
            MB_STATUS_READ(FC) /*can_status2 is used for controllers having MB's > 32*/\
            if ((0U != can_status1)||(0U !=can_status2)) \
            { \
            /* Rx: process from 0 to (FirstTx-1) */ \
            Can_LLD_Process_Rx( CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex - (uint8)1U) ); \
            /* Tx: process from FirstTx to (MaxMB-1) */ \
            Can_LLD_Process_Tx( CAN_FC##FC##_INDEX, (uint8)Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex, (uint8)(Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U) ); \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_ON) */


/*==================================================================================================*/
/*
* @brief          Interrupt routine for all MBs  - optimization code size, TX only.
* @details        Process all MBs that are configured for Tx.
*                 The controller ID is transmitted with the ## operator for the interrupt handler.
*           FC - Can hardware channel: A, B, C, D, E, F.
*
*/

#if (CAN_ISROPTCODESIZE == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    #define CAN_MB_UNITXISRS(FC) \
        ISR(Can_IsrFC##FC##_UNI) { \
            MB_STATUS_READ(FC) /*can_status2 is used for controllers having MB's > 32*/\
            if ((0U != can_status1)||(0U !=can_status2)) \
            { \
            /* Tx: process all Tx MBs */ \
            Can_LLD_Process_Tx( CAN_FC##FC##_INDEX, (uint8)Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex, (uint8)(Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U) ); \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_ON) */


/*==================================================================================================*/
/*
* @brief          Interrupt routine for all MBs  - optimization code size, RX only.
* @details        Process all MBs that are configured for Rx.
*                 The controller ID is transmitted with the ## operator for the interrupt handler.
*           FC - Can hardware channel: A, B, C, D, E, F.
*
*/

#if (CAN_ISROPTCODESIZE == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    #define CAN_MB_UNIRXISRS(FC) \
        ISR(Can_IsrFC##FC##_UNI) { \
            MB_STATUS_READ(FC) /*can_status2 is used for controllers having MB's > 32*/\
            if ((0U != can_status1)||(0U !=can_status2)) \
            { \
            /* Rx: process from 0 to (FirstTx-1) */ \
            Can_LLD_Process_Rx( CAN_FC##FC##_INDEX, (uint8)0U, (uint8)(Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex - (uint8)1U) ); \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_ON) */

/*==================================================================================================*/
/**
@brief     Macro to select the MB (for MBs from 0 to 63).

@remarks   The controller ID is transmitted with the ## operator for the interrupt handler.
           FC - Can hardware channel: A, B, C, D, E, F.
*/
/*==================================================================================================*/
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define MB_SIZE(FC, IdMin) \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            VAR(uint32, CAN_VAR) can_status_mask = 0U; \
            can_status_mask = 0x0000000FUL; \
            if (32U == (IdMin)) { \
            can_status_mask = 0xFFFFFFFFUL; \
            can_status = ((uint32)FLEXCAN_IFLAG2_READ(FLEXCAN_##FC##_OFFSET)) & can_status_mask ; \
            can_status &= ((uint32)FLEXCAN_IMASK2_READ(FLEXCAN_##FC##_OFFSET)) & can_status_mask; \
             } \
             else { \
             if (16U == (IdMin)) {can_status_mask = 0xFFFF0000UL ;} \
            else {can_status_mask = (can_status_mask << (((IdMin) == 32U) ? 0UL : (IdMin))); } \
            can_status = ((uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET)) & can_status_mask ; \
            can_status &= ((uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET)) & can_status_mask; \
            } 
#else
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define MB_SIZE(FC, IdMin) \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            VAR(uint32, CAN_VAR) can_status_mask = 0U; \
            can_status_mask = 0x0000000FUL; \
            if (16U == (IdMin)) {can_status_mask = 0xFFFF0000UL;} \
            else {can_status_mask = (can_status_mask << (((IdMin) == 32U) ? 0UL : (IdMin))); } \
            can_status = ((uint32)FLEXCAN_IFLAG1_READ(FLEXCAN_##FC##_OFFSET)) & can_status_mask ; \
            can_status &= ((uint32)FLEXCAN_IMASK1_READ(FLEXCAN_##FC##_OFFSET)) & can_status_mask;
#endif


/*==================================================================================================*/
/*
@brief      Interrupt routine for a range of MBs. ( for MBs from 0 to 63).
* @details        Process all MBs defined for current controller, but between a definite range.
*                 MBs are grouped: HRHs first, the HTHs.
*                 FC - Can hardware channel:A, B, C, D, E, F.
*                 Name - Suggestive name for the Int purpose.
*                 IdMin, IdMax - minimum/maximum MB id that interrupt is related for.
*
*/

#if (CAN_ISROPTCODESIZE == STD_OFF)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    /* @violates @ref Can_Irq_c_REF_14 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */    
    #define CAN_MB_ISRS(FC, Name, IdMin, IdMax) \
        ISR(Can_IsrFC##FC##_##Name) { \
            MB_SIZE(FC, (IdMin)) \
            if (0U != can_status) \
            { \
            if ( (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) <= ( (((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) < (IdMax)) ? ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) : (IdMax)) ) { \
                Can_LLD_Process_Tx( CAN_FC##FC##_INDEX, \
                                ( (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) > (IdMin)) ? (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) : (IdMin), \
                                ( ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) < (IdMax)) ? ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) : (IdMax)); \
            } \
            if ( (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) > (IdMin) ) { \
                Can_LLD_Process_Rx( CAN_FC##FC##_INDEX, \
                                (IdMin), \
                                ((Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) > ( ( ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) < (IdMax) ) ? ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) : (IdMax)) ) ? /* condition */ \
                                    ( ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U) < (IdMax)) ? ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) : (IdMax)) :  \
                                    (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex - (uint8)1U) ); /* value if condition is false */ \
            } \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_OFF) */



/*==================================================================================================*/
/*
@brief      Interrupt routine for a range of MBs - TX only ( for MBs from 0 to 63).
* @details        Process all MBs that are configured for Tx, but between a definite range.
*                 FC - Can hardware channel: A, B, C, D, E, F.
*                 Name - Suggestive name for the Int purpose.
*                 IdMin, IdMax - minimum/maximum MB id that interrupt is related for.
*
*/

#if (CAN_ISROPTCODESIZE == STD_OFF)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    /* @violates @ref Can_Irq_c_REF_14 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */
    #define CAN_MB_TXISRS(FC, Name, IdMin, IdMax) \
        ISR(Can_IsrFC##FC##_##Name) { \
            MB_SIZE(FC, (IdMin)) \
            if (0U != can_status) \
            { \
            Can_LLD_Process_Tx( CAN_FC##FC##_INDEX, \
                            ( (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) > (IdMin)) ? (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) : (IdMin), \
                            ( ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) < (IdMax) ) ? ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) : (IdMax)); \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_OFF) */


/*==================================================================================================*/
/*
* @brief          Interrupt routine for a range of MBs - RX only ( for MBs from 8 to 31).
* @details        Process all MBs that are configured for Tx, but between a definite range.
*                 FC - Can hardware channel: A, B.
*                 Name - Suggestive name for the Int purpose.
*                 IdMin, IdMax - minimum/maximum MB id that interrupt is related for.
*
*/

#if (CAN_ISROPTCODESIZE == STD_OFF)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    /* @violates @ref Can_Irq_c_REF_14 Violates MISRA 2004 Required Rule 19.10, arguments shall be enclosed in parentheses. */    
    #define CAN_MB_RXISRS(FC, Name, IdMin, IdMax) \
        ISR(Can_IsrFC##FC##_##Name) { \
            MB_SIZE(FC, (IdMin)) \
            if (0U != can_status) \
            { \
            Can_LLD_Process_Rx( CAN_FC##FC##_INDEX, \
                            (IdMin), \
                            (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex) > ( (((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) < (IdMax)) ? ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) : (IdMax)) ? /* condition */ \
                                ( (((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) < (IdMax)) ? ((Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].MaxMBCount - (uint8)1U)) : (IdMax)) : /* result if condition is true */ \
                                (Can_ControllerStatuses[CAN_FC##FC##_INDEX].FirstTxMBIndex - (uint8)1U) ); /* result if condition is false */ \
            } \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

/*==================================================================================================*/
/*
* @brief     Macro defined to store esr status when esrstatusapi is on and off
* @details   Defined as macro.
* @remarks   FC - Can hardware channel: A, B, C, D, E, F.
*/
/*==================================================================================================*/
#if (CAN_API_ERROR_STATUS == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define STATUS_ESR_BOFF(FC) \
        VAR(uint32, AUTOMATIC) can_status = 0U; \
        can_status = (uint32)FLEXCAN_CTRL_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_CTRL_BOFFMSK; \
        can_status = can_status >> (13U); \
        Can_EsrRegStatus[CAN_FC##FC##_INDEX] = (uint32)FLEXCAN_ESR_READ(FLEXCAN_##FC##_OFFSET);\
        can_status &= ((uint32)Can_EsrRegStatus[CAN_FC##FC##_INDEX] & FLEXCAN_ESR_BOFFINT); \
        if (0U != can_status) \
        { \
            /* Process BusOff condition for controller ID of FlexCAN FC */ \
            Can_LLD_Process_BusOff( CAN_FC##FC##_INDEX); \
        }
#else
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define STATUS_ESR_BOFF(FC) \
        VAR(uint32, AUTOMATIC) can_status = 0U; \
        can_status = (uint32)FLEXCAN_CTRL_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_CTRL_BOFFMSK; \
        can_status = can_status >> (13U); \
        can_status &= ((uint32)FLEXCAN_ESR_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_ESR_BOFFINT); \
        if (0U != can_status) \
        { \
            /* Process BusOff condition for controller ID of FlexCAN FC */ \
            Can_LLD_Process_BusOff( CAN_FC##FC##_INDEX); \
        }
#endif


/*==================================================================================================*/
/*
* @brief          Interrupt routine for BusOff.
* @details        Interrupt routine for BusOff.
*                 FC - Can hardware channel: A, B, C, D, E, F.
*
*/
/* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Advisory Rule 19.12, Multiple use of '#/##' operators in macro definition. */
/* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
/* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */

#define CAN_BOISR(FC) \
    ISR(Can_IsrFC##FC##_BO) { \
        STATUS_ESR_BOFF(FC) \
        EXIT_INTERRUPT(); \
    }

/*==================================================================================================*/
/*
* @brief     Macro defined to store esr status when esrstatusapi is on and off
* @details   Defined as macro.
* @remarks   FC - Can hardware channel: A, B, C, D, E, F.
*/
/*==================================================================================================*/    
#if (CAN_API_ERROR_STATUS == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define STATUS_ESR_WKP(FC) \
            VAR(uint32, AUTOMATIC) can_status = 0U; \
            can_status = (uint32)FLEXCAN_MCR_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_MCR_WAK_MSK; \
            can_status = can_status >> (26U); \
            Can_EsrRegStatus[CAN_FC##FC##_INDEX] = (uint32)FLEXCAN_ESR_READ(FLEXCAN_##FC##_OFFSET) \
            can_status &= ((uint32)Can_EsrRegStatus[CAN_FC##FC##_INDEX] & FLEXCAN_ESR_WAK_INT); \
            if (0U != can_status) \
            { \
            /* EcuM_CheckWakeup must be called by the ISR of a wakeup source to set up the PLL */ \
            /* \
             (CAN364) If the ISR for wakeup events is called, it shall call EcuM_CheckWakeup in turn. \
            */ \
            EcuM_CheckWakeup( Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].CanWakeupSourceID ); \
            /* Process Bus off condition for controller ID of FlexCAN */ \
            Can_LLD_Process_Wakeup( CAN_FC##FC##_INDEX ); \
            }
#else
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define STATUS_ESR_WKP(FC) \
            VAR(uint32, CAN_VAR) can_status = 0U; \
            can_status = (uint32)FLEXCAN_MCR_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_MCR_WAK_MSK; \
            can_status = can_status >> (26U); \
            can_status &= ((uint32)FLEXCAN_ESR_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_ESR_WAK_INT); \
            if (0U != can_status) \
            { \
            /* EcuM_CheckWakeup must be called by the ISR of a wakeup source to set up the PLL */ \
            /* \
             (CAN364) If the ISR for wakeup events is called, it shall call EcuM_CheckWakeup in turn. \
            */ \
            EcuM_CheckWakeup( Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].CanWakeupSourceID ); \
            /* Process Bus off condition for controller ID of FlexCAN */ \
            Can_LLD_Process_Wakeup( CAN_FC##FC##_INDEX ); \
            }
#endif

/*==================================================================================================*/
/*
* @brief          Interrupt routine for WakeUp.
* @details        Interrupt routine for WakeUp.
*                 FC - Can hardware channel: A, B, C, D, E, F.
*
* @implements     DCAN01126
*
*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)
   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    #define CAN_WKPISR(FC) \
        ISR(Can_IsrFC##FC##_WKP) { \
            STATUS_ESR_WKP(FC) \
            EXIT_INTERRUPT(); \
        }
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */

/*==================================================================================================*/
/*
* @brief     Macro defined to select error notification
* @details   Defined as macro.
* @remarks   FC - Can hardware channel: A, B, C, D, E, F.
*/
/*==================================================================================================*/
#if (CAN_API_ERROR_STATUS == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define STATUS_ESR(FC) \
        VAR(uint32, AUTOMATIC) can_status = 0U; \
        can_status = ((uint32)FLEXCAN_CTRL_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_CTRL_ERRMSK); \
        can_status = (can_status >> (13U)); \
        Can_EsrRegStatus[CAN_FC##FC##_INDEX] = (uint32)FLEXCAN_ESR_READ(FLEXCAN_##FC##_OFFSET); \
        can_status &= (((uint32)Can_EsrRegStatus[CAN_FC##FC##_INDEX]) & FLEXCAN_ESR_ERRINT); \
        if (0U != can_status) \
        { \
            FLEXCAN_SET_ESR_ERRINT(Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].ControllerOffset); \
            if ( NULL_PTR != Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification) { \
                Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification(Can_EsrRegStatus[CAN_FC##FC##_INDEX]); \
            } \
        } \
        Can_EsrRegStatus[CAN_FC##FC##_INDEX] = 0x00U;
#else
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define STATUS_ESR(FC) \
        VAR(uint32, CAN_VAR) can_status = 0U; \
        can_status = (uint32)FLEXCAN_CTRL_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_CTRL_ERRMSK; \
        can_status = can_status >> (13U); \
        can_status &= ((uint32)FLEXCAN_ESR_READ(FLEXCAN_##FC##_OFFSET) & FLEXCAN_ESR_ERRINT); \
        if (0U != can_status) \
        { \
            FLEXCAN_SET_ESR_ERRINT(Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].ControllerOffset); \
            if ( NULL_PTR != Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification) { \
                Can_CurrentConfigPtr->ControlerDescriptors[CAN_FC##FC##_INDEX].Can_ErrorNotification(); \
            } \
        }
#endif        

/*==================================================================================================*/
/*
* @brief          Interrupt routine for Error.
* @details        Interrupt routine for Error.
*                 FC - Can hardware channel: A, B.
*
*/
#if (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    /* @violates @ref Can_Irq_c_REF_2 Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used. */
    /* @violates @ref Can_Irq_c_REF_1 Violates MISRA 2004 Required Rule 19.12, Multiple use of '#/##' operators in macro definition. */
    /* @violates @ref Can_Irq_c_REF_10 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    #define CAN_ERRISR(FC) \
        ISR(Can_IsrFC##FC##_ERR) { /* Error Isr */ \
            STATUS_ESR(FC) \
            EXIT_INTERRUPT(); \
        }
#endif

#define CAN_START_SEC_CODE
/* @violates @ref Can_Irq_c_REF_3 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Irq_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h  */
#include "MemMap.h"


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN A
==================================================================================================*/
#ifdef CAN_FCA_INDEX
  #if (CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
/*
* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*/
    CAN_ERRISR(A)
  #endif
    #if (CAN_A_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
            /*
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
        CAN_BOISR(A)
    #endif /* (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_A_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Internal Wake-Up */
            CAN_WKPISR(A)
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_A_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
            CAN_MB_UNIISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
                    CAN_RXFIFO_EVENTS(A)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(A)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(A)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(A)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
                /*@violates @ref Can_Irq_c_REF_12 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
                CAN_MB_ISRS(A, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
                /*@violates @ref Can_Irq_c_REF_12 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
                CAN_MB_ISRS(A, MB_04_07, 4U, 7U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
           /*@violates @ref Can_Irq_c_REF_12 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
            CAN_MB_ISRS(A, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
            /*@violates @ref Can_Irq_c_REF_12 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
            CAN_MB_ISRS(A, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
           /*@violates @ref Can_Irq_c_REF_12 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
            CAN_MB_ISRS(A, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            /*
            * @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            * @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
            */
            /*@violates @ref Can_Irq_c_REF_12 MISRA 2004 Required Rule 13.7,Invariant results for Boolean Ops */
            /*@violates @ref Can_Irq_c_REF_13 MISRA 2004 Required Rule 12.8, The right hand operand of a shift operator shall lie between zero
                            and one less than the width in bits of the underlying type of the left hand operand.*/
            CAN_MB_ISRS(A, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(A)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(A)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(A)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(A)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_RXISRS(A, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_RXISRS(A, MB_04_07, 4U, 7U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_RXISRS(A, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_RXISRS(A, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_RXISRS(A, MB_16_31, 16U, 31U)
             /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            CAN_MB_RXISRS(A, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_A_FIFO_EN == STD_OFF)
                /* Message Buffer 00_03 */
                CAN_MB_TXISRS(A, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_TXISRS(A, MB_04_07, 4U, 7U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_TXISRS(A, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_TXISRS(A, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_TXISRS(A, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            CAN_MB_TXISRS(A, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCA_INDEX */


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN B
==================================================================================================*/
#ifdef CAN_FCB_INDEX
  #if (CAN_B_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
/*
* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*/
    CAN_ERRISR(B)
  #endif
    #if (CAN_B_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        CAN_BOISR(B)
    #endif /* (CAN_B_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_B_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Internal Wake-Up */
            CAN_WKPISR(B)
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_B_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(B)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(B)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(B)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(B)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_ISRS(B, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_ISRS(B, MB_04_07, 4U, 7U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_ISRS(B, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_ISRS(B, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_ISRS(B, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            CAN_MB_ISRS(B, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_OFF) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(B)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(B)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(B)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(B)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_RXISRS(B, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_RXISRS(B, MB_04_07, 4U, 7U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_RXISRS(B, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_RXISRS(B, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_RXISRS(B, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            CAN_MB_RXISRS(B, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_OFF)
                /* Message Buffer 00_03 */
                CAN_MB_TXISRS(B, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_TXISRS(B, MB_04_07, 4U, 7U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_TXISRS(B, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_TXISRS(B, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_TXISRS(B, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            CAN_MB_TXISRS(B, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCB_INDEX */
/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN C
==================================================================================================*/
#ifdef CAN_FCC_INDEX
  #if (CAN_C_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    CAN_ERRISR(C)
  #endif
    #if (CAN_C_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        CAN_BOISR(C)
    #endif /* (CAN_C_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_C_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Internal Wake-Up */
            CAN_WKPISR(C)
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_C_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(C)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(C)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(C)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(C)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_ISRS(C, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_ISRS(C, MB_04_07, 4U, 7U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_ISRS(C, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_ISRS(C, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_ISRS(C, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown due to the shifting operation */
            CAN_MB_ISRS(C, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_OFF) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(C)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(C)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(C)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(C)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_RXISRS(C, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_RXISRS(C, MB_04_07, 4U, 7U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_RXISRS(C, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_RXISRS(C, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_RXISRS(C, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            CAN_MB_RXISRS(C, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_OFF)
                /* Message Buffer 00_03 */
                CAN_MB_TXISRS(C, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_TXISRS(C, MB_04_07, 4U, 7U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_TXISRS(C, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_TXISRS(C, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_TXISRS(C, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown for the part of code which is not executed under the given condition */
            CAN_MB_TXISRS(C, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCC_INDEX */
/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN D
==================================================================================================*/
#ifdef CAN_FCD_INDEX
  #if (CAN_D_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    CAN_ERRISR(D)
  #endif
    #if (CAN_D_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        CAN_BOISR(D)
    #endif /* (CAN_D_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_D_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Internal Wake-Up */
            CAN_WKPISR(D)
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_D_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(D)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(D)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(D)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(D)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(D)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_ISRS(D, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_ISRS(D, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_ISRS(D, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_ISRS(D, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_ISRS(D, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown due to the shifting operation */
            CAN_MB_ISRS(D, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_OFF) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(D)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(D)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(D)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(D)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(D)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_RXISRS(D, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_RXISRS(D, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_RXISRS(D, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_RXISRS(D, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_RXISRS(D, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            CAN_MB_RXISRS(D, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(D)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_D_FIFO_EN == STD_OFF)
                /* Message Buffer 00_03 */
                CAN_MB_TXISRS(D, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_TXISRS(D, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_TXISRS(D, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_TXISRS(D, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_TXISRS(D, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            CAN_MB_TXISRS(D, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCD_INDEX */
/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN E
==================================================================================================*/
#ifdef CAN_FCE_INDEX
  #if (CAN_E_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    CAN_ERRISR(E)
  #endif
    #if (CAN_E_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        CAN_BOISR(E)
    #endif /* (CAN_E_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_D_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Internal Wake-Up */
            CAN_WKPISR(E)
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_E_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(E)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(E)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(E)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(E)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(E)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_E_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_ISRS(E, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_ISRS(E, MB_04_07, 4U, 7U)
            #endif /* (CAN_E_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_ISRS(E, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_ISRS(E, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_ISRS(E, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown due to the shifting operation */
            CAN_MB_ISRS(E, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_OFF) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(E)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(E)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(E)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(E)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(E)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_E_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_RXISRS(E, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_RXISRS(E, MB_04_07, 4U, 7U)
            #endif /* (CAN_E_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_RXISRS(E, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_RXISRS(E, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_RXISRS(E, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            CAN_MB_RXISRS(E, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(E)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_E_FIFO_EN == STD_OFF)
                /* Message Buffer 00_03 */
                CAN_MB_TXISRS(E, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_TXISRS(E, MB_04_07, 4U, 7U)
            #endif /* (CAN_E_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_TXISRS(E, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_TXISRS(E, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_TXISRS(E, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            CAN_MB_TXISRS(E, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCE_INDEX */
/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN F
==================================================================================================*/
#ifdef CAN_FCF_INDEX
  #if (CAN_F_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    CAN_ERRISR(F)
  #endif
    #if (CAN_F_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        CAN_BOISR(F)
    #endif /* (CAN_F_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_F_WAKEUPINT_SUPPORTED == STD_ON)
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
            /* Internal Wake-Up */
            CAN_WKPISR(F)
        #endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
    #endif /* (CAN_F_WAKEUPINT_SUPPORTED == STD_ON) */

    #if ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(F)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(F)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(F)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(F)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(F)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_ISRS(F, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_ISRS(F, MB_04_07, 4U, 7U)
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_ISRS(F, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_ISRS(F, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_ISRS(F, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            /* Compiler_Warning : This warning is thrown due to the shifting operation */
            CAN_MB_ISRS(F, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_OFF) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(F)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    CAN_RXFIFO_EVENTS(F)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV(F)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER(F)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN(F)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                CAN_MB_RXISRS(F, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_RXISRS(F, MB_04_07, 4U, 7U)
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_RXISRS(F, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_RXISRS(F, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_RXISRS(F, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            CAN_MB_RXISRS(F, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(F)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_F_FIFO_EN == STD_OFF)
                /* Message Buffer 00_03 */
                CAN_MB_TXISRS(F, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                CAN_MB_TXISRS(F, MB_04_07, 4U, 7U)
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */

            /* Message Buffer 08_11 */
            CAN_MB_TXISRS(F, MB_08_11, 8U, 11U)
            /* Message Buffer 12_15 */
            CAN_MB_TXISRS(F, MB_12_15, 12U, 15U)
            /* Message Buffer 16_31 */
            CAN_MB_TXISRS(F, MB_16_31, 16U, 31U)
            /* Message Buffer 32_63 */
            CAN_MB_TXISRS(F, MB_32_63, 32U, 63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCF_INDEX */

#define CAN_STOP_SEC_CODE
/* @violates @ref Can_Irq_c_REF_3 Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Irq_c_REF_5 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h  */

#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
