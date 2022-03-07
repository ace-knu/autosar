/**
*   @file    Lin_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - File used by LIN that contain the ISRs.
*   @details This file contains the ISR functions used to serve the LIN interrupts.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : LINFlex
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF5_ASR_REL_4_0_REV_0003_20140822
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
* @section Lin_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a 
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Lin_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
* converted to a different underlying type if: a) it is not a
* conversion to a wider integer type of the same signedness, or b)
* the expression is complex, or c) the expression is not constant
* and is a function argument, or d) the expression is not constant
* and is a return expression.
*
* @section Lin_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal
* and external) shall not rely on the significance of more 
* than 31 characters.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Lin_Irq.c
* @implements     DLIN03640
*/
#include "Lin.h"
#include "Lin_Linflex_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Lin_Irq.c
* @implements     DLIN03401
*/
#define LIN_IRQ_VENDOR_ID_C                    43

/* @violates @ref Lin_Irq_c_REF_6 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C     4

/* @violates @ref Lin_Irq_c_REF_6 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MINOR_VERSION_IRQ_C     0
/*
* @violates @ref Lin_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref Lin_Irq_c_REF_6 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_IRQ_C  3
#define LIN_SW_MAJOR_VERSION_IRQ_C             1
#define LIN_SW_MINOR_VERSION_IRQ_C             0
#define LIN_SW_PATCH_VERSION_IRQ_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin.h header file are of the same Autosar version */
#if (((LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C   != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IRQ_C    != LIN_AR_RELEASE_MINOR_VERSION)) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IRQ_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin_Irq.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_IRQ_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_IRQ_C != LIN_SW_MINOR_VERSION))
    #error "Software Version Numbers of Lin_Irq.c and Lin.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief          LIN controller interrupts
* @details        LIN controller interrupts
*
*
* @implements     DLIN03100, DLIN03400
*
*
*/
#define LIN_START_SEC_CODE
/*
* @violates @ref Lin_Irq_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
/*
* @violates @ref Lin_Irq_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "MemMap.h"

#if defined(LinHWCh_0)
  ISR(Lin_LLD_IsrError_LINFlex_0);
  ISR(Lin_LLD_IsrTx_LINFlex_0);
  ISR(Lin_LLD_IsrRx_LINFlex_0);
#endif /* defined(LinHWCh_0) */

#if defined(LinHWCh_1)
  ISR(Lin_LLD_IsrError_LINFlex_1);
  ISR(Lin_LLD_IsrTx_LINFlex_1);
  ISR(Lin_LLD_IsrRx_LINFlex_1);
#endif /* defined(LinHWCh_1) */

#if defined(LinHWCh_2)
  ISR(Lin_LLD_IsrError_LINFlex_2);
  ISR(Lin_LLD_IsrTx_LINFlex_2);
  ISR(Lin_LLD_IsrRx_LINFlex_2);
#endif /* defined(LinHWCh_2) */

#if defined(LinHWCh_3)
  ISR(Lin_LLD_IsrError_LINFlex_3);
  ISR(Lin_LLD_IsrTx_LINFlex_3);
  ISR(Lin_LLD_IsrRx_LINFlex_3);
#endif /* defined(LinHWCh_3) */

#if defined(LinHWCh_4)
  ISR(Lin_LLD_IsrError_LINFlex_4);
  ISR(Lin_LLD_IsrTx_LINFlex_4);
  ISR(Lin_LLD_IsrRx_LINFlex_4);
#endif /* defined(LinHWCh_4) */

#if defined(LinHWCh_5)
  ISR(Lin_LLD_IsrError_LINFlex_5);
  ISR(Lin_LLD_IsrTx_LINFlex_5);
  ISR(Lin_LLD_IsrRx_LINFlex_5);
#endif /* defined(LinHWCh_5) */

#if defined(LinHWCh_6)
  ISR(Lin_LLD_IsrError_LINFlex_6);
  ISR(Lin_LLD_IsrTx_LINFlex_6);
  ISR(Lin_LLD_IsrRx_LINFlex_6);
#endif /* defined(LinHWCh_6) */

#if defined(LinHWCh_7)
  ISR(Lin_LLD_IsrError_LINFlex_7);
  ISR(Lin_LLD_IsrTx_LINFlex_7);
  ISR(Lin_LLD_IsrRx_LINFlex_7);
#endif /* defined(LinHWCh_7) */

#if defined(LinHWCh_8)
  ISR(Lin_LLD_IsrError_LINFlex_8);
  ISR(Lin_LLD_IsrTx_LINFlex_8);
  ISR(Lin_LLD_IsrRx_LINFlex_8);
#endif /* defined(LinHWCh_8) */

#if defined(LinHWCh_9)
  ISR(Lin_LLD_IsrError_LINFlex_9);
  ISR(Lin_LLD_IsrTx_LINFlex_9);
  ISR(Lin_LLD_IsrRx_LINFlex_9);
#endif /* defined(LinHWCh_9) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if defined(LinHWCh_0) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_0.
* @details This function implements the ISR occurring on error on
*          LinFlex_0.
* @note    This interrupt handlers is only present if Hardware 
*          Channel 0 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_0)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_0);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    /* 
    * @violates @ref Lin_Irq_c_REF_5 Violates MISRA 2004 Required Rule 10.1 ,
    * Prohibited Implicit Conversion: Non-constant argument to function,
    * Implicit conversion of integer to smaller type
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_0.
* @details This function implements the ISR occurring on reception on
*          LinFlex_0.
* @note    This interrupt handlers is only present if Hardware
*          Channel 0 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_0)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_0);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    /* 
    * @violates @ref Lin_Irq_c_REF_5 Violates MISRA 2004 Required Rule 10.1 ,
    * Prohibited Implicit Conversion: Non-constant argument to function,
    * Implicit conversion of integer to smaller type
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_0.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_0.
* @note    This interrupt handlers is only present if Hardware
*          Channel 0 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_0)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_0);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    /* 
    * @violates @ref Lin_Irq_c_REF_5 Violates MISRA 2004 Required Rule 10.1 ,
    * Prohibited Implicit Conversion: Non-constant argument to function,
    * Implicit conversion of integer to smaller type
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_0) */

#if defined(LinHWCh_1) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_1.
* @details This function implements the ISR occurring on error on
*          LinFlex_1.
* @note    This interrupt handlers is only present if Hardware
*          Channel 1 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_1)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_1);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_1.
* @details This function implements the ISR occurring on reception on
*          LinFlex_1.
* @note    This interrupt handlers is only present if Hardware
*          Channel 1 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_1)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_1);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_1.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_1.
* @note    This interrupt handlers is only present if Hardware
*          Channel 1 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_1)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_1);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_1) */

#if defined(LinHWCh_2) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_2.
* @details This function implements the ISR occurring on error on
*          LinFlex_2.
* @note    This interrupt handlers is only present if Hardware
*          Channel 2 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_2)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_2);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_2.
* @details This function implements the ISR occurring on reception on
*          LinFlex_2.
* @note    This interrupt handlers is only present if Hardware
*          Channel 2 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_2)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_2);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_2.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_2.
* @note    This interrupt handlers is only present if Hardware
*          Channel 2 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_2)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_2);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_2) */

#if defined(LinHWCh_3) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_3.
* @details This function implements the ISR occurring on error on
*          LinFlex_3.
* @note    This interrupt handlers is only present if Hardware
*          Channel 3 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_3)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_3);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_3.
* @details This function implements the ISR occurring on reception on
*          LinFlex_3.
* @note    This interrupt handlers is only present if Hardware
*          Channel 3 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_3)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_3);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_3.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_3.
* @note    This interrupt handlers is only present if Hardware
*          Channel 3 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_3)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_3);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_3) */

#if defined(LinHWCh_4) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_4.
* @details This function implements the ISR occurring on error on
*          LinFlex_4.
* @note    This interrupt handlers is only present if Hardware
*          Channel 4 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_4)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_4);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_4.
* @details This function implements the ISR occurring on reception on
*          LinFlex_4.
* @note    This interrupt handlers is only present if Hardware
*          Channel 4 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_4)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_4);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_4.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_4.
* @note    This interrupt handlers is only present if Hardware
*          Channel 4 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_4)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_4);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_4) */

#if defined(LinHWCh_5) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_5.
* @details This function implements the ISR occurring on error on
*          LinFlex_5.
* @note    This interrupt handlers is only present if Hardware
*          Channel 5 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_5)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_5);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_5.
* @details This function implements the ISR occurring on reception on
*          LinFlex_5.
* @note    This interrupt handlers is only present if Hardware
*          Channel 5 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_5)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_5);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_5.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_5.
* @note    This interrupt handlers is only present if Hardware
*          Channel 5 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_5)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_5);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_5) */

#if defined(LinHWCh_6) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_6.
* @details This function implements the ISR occurring on error on
*          LinFlex_6.
* @note    This interrupt handlers is only present if Hardware
*          Channel 6 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_6)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_6);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_6.
* @details This function implements the ISR occurring on reception on
*          LinFlex_6.
* @note    This interrupt handlers is only present if Hardware
*          Channel 6 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_6)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_6);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_6.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_6.
* @note    This interrupt handlers is only present if Hardware
*          Channel 6 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_6)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_6);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_6) */

#if defined(LinHWCh_7) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_7.
* @details This function implements the ISR occurring on error on
*          LinFlex_7.
* @note    This interrupt handlers is only present if Hardware
*          Channel 7 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_7)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_7);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
/**
* @brief   Rx interrupt on LinFlex_7.
* @details This function implements the ISR occurring on reception on
*          LinFlex_7.
* @note    This interrupt handlers is only present if Hardware
*          Channel 7 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_7)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_7);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_7.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_7.
* @note    This interrupt handlers is only present if Hardware
*          Channel 7 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_7)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_7);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_7) */

#if defined(LinHWCh_8) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_8.
* @details This function implements the ISR occurring on error on
*          LinFlex_8.
* @note    This interrupt handlers is only present if Hardware
*          Channel 8 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_8)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_8);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_8.
* @details This function implements the ISR occurring on reception on
*          LinFlex_8.
* @note    This interrupt handlers is only present if Hardware
*          Channel 8 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_8)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_8);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_8.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_8.
* @note    This interrupt handlers is only present if Hardware
*          Channel 8 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_8)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_8);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_8) */

#if defined(LinHWCh_9) || defined(__DOXYGEN__)
/**
* @brief   Error interrupt on LinFlex_9.
* @details This function implements the ISR occurring on error on
*          LinFlex_9.
* @note    This interrupt handlers is only present if Hardware
*          Channel 9 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrError_LINFlex_9)
    {
    LINFlex_ErrorInterruptHandler(LinHWCh_9);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Rx interrupt on LinFlex_9.
* @details This function implements the ISR occurring on reception on
*          LinFlex_9.
* @note    This interrupt handlers is only present if Hardware
*          Channel 9 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrRx_LINFlex_9)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_9);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }

/**
* @brief   Tx interrupt on LinFlex_9.
* @details This function implements the ISR occurring on transmission
*          on LinFlex_9.
* @note    This interrupt handlers is only present if Hardware
*          Channel 9 is used and DMA is not used.
*
* @isr
*
* @implements     DLIN03100, DLIN03400
*
*
*/
ISR(Lin_LLD_IsrTx_LINFlex_9)
    {
    LINFlex_Tx_Rx_InterruptHandler(LinHWCh_9);
    /*
    * @violates @ref Lin_Irq_c_REF_4 cast from unsigned int to pointer
    */
    EXIT_INTERRUPT();
    }
#endif /* defined(LinHWCh_9) */

#define LIN_STOP_SEC_CODE
/** 
* @violates @ref Lin_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Lin_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/*! @} */
