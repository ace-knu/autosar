/**
*   @file    Dma_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - eDMA low level driver.
*   @details DeDMA low level driver functions used by MCAL drivers.
*
*   @addtogroup DMA_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section DMA_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* MemMap.h included after each section define in order to set the current memory section
*
* @section DMA_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section DMA_LLD_c_REF_4
* Violates MISRA 2004 Advisory Rule 11.4, a cast should not be performed between a pointer to object
* type and a different pointer to object type. Cast from (uint8*) to (uint32*) used for optimizing
* the memory accesses.
*
* @section DMA_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case sensitivity are
* supported for external identifiers.
* The version check defines are requested by AutoSAR standard (BSW00318) and have a standard format 
* which cannot be changed
*
* @section DMA_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type.
* There is no pointer to function conversion to any type. We suspect a wrong error reported by tool.
*
* @section DMA_LLD_c_REF_7
* Violates MISRA 2004 Required Rule 17.4,
* Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*
* @section DMA_LLD_c_REF_8
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
*@section DMA_LLD_c_REF_9
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/



/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_LLD.h"
#include "modules.h"

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

/* this define value is 101 for MCU, 123 for ADC, 82 for LIN and 83 for SPI */
#define DMA_COMMON_MODULE_ID                    122
#define DMA_AR_VENDOR_ID_LLD_C                  43
/*
* @violates @ref DMA_LLD_c_REF_9 This is required as per autosar Requirement, 
*/
#define DMA_AR_RELEASE_MAJOR_VERSION_LLD_C      4
/*
* @violates @ref DMA_LLD_c_REF_9 This is required as per autosar Requirement, 
*/
#define DMA_AR_RELEASE_MINOR_VERSION_LLD_C      0
/*
* @violates @ref DMA_LLD_c_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
/*
* @violates @ref DMA_LLD_c_REF_9 This is required as per autosar Requirement, 
*/
#define DMA_AR_RELEASE_REVISION_VERSION_LLD_C   3
#define DMA_SW_MAJOR_VERSION_LLD_C              1
#define DMA_SW_MINOR_VERSION_LLD_C              0
#define DMA_SW_PATCH_VERSION_LLD_C              1



/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and DMA header file are from the same vendor */
#if (DMA_AR_VENDOR_ID_LLD_C != DMA_VENDOR_ID)
#error "Dma_LLD.c and Dma_LLD.h have different vendor ids"
#endif

/* Check if source file and DMA header file are of the same Autosar version */
#if ((DMA_AR_RELEASE_MAJOR_VERSION_LLD_C != DMA_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_AR_RELEASE_MINOR_VERSION_LLD_C != DMA_AR_RELEASE_MINOR_VERSION) || \
     (DMA_AR_RELEASE_REVISION_VERSION_LLD_C != DMA_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dma_LLD.c and Dma_LLD.h are different"
#endif

/* Check if source file and DMA header file are of the same Software version */
#if ((DMA_SW_MAJOR_VERSION_LLD_C != DMA_SW_MAJOR_VERSION) || \
     (DMA_SW_MINOR_VERSION_LLD_C != DMA_SW_MINOR_VERSION) || \
     (DMA_SW_PATCH_VERSION_LLD_C != DMA_SW_PATCH_VERSION))
#error "Software Version Numbers of Dma_LLD.c and Dma_LLD.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if ((USE_ADC_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==123) && (ADC_USE_DMA_LLD==STD_ON))
#define DMA_CODE (ADC_CODE)
/* 
* @violates @ref DMA_LLD_C_REF_1 MISRA 2004 Advisory Rule 19.1 only preprocessor statements
* and comments before '#include'
*/
#define ADC_START_SEC_CODE
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && (USE_SPI_MODULE==STD_ON) && \
     (DMA_COMMON_MODULE_ID==83) && (SPI_USE_DMA_LLD==STD_ON))
#define DMA_CODE (SPI_CODE)
/* 
* @violates @ref DMA_LLD_C_REF_1 MISRA 2004 Advisory Rule 19.1 only preprocessor statements
* and comments before '#include'
*/
#define SPI_START_SEC_CODE
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && (USE_LIN_MODULE==STD_ON) && \
      (DMA_COMMON_MODULE_ID==82) && (LIN_USE_DMA_LLD==STD_ON))
#define DMA_CODE (LIN_CODE)
/* 
* @violates @ref DMA_LLD_C_REF_1 MISRA 2004 Advisory Rule 19.1 only preprocessor statements
* and comments before '#include'
*/
#define LIN_START_SEC_CODE
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      (USE_ICU_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==122) && (ICU_USE_DMA_LLD==STD_ON))
#define DMA_CODE (ICU_CODE)
/* 
* @violates @ref DMA_LLD_C_REF_1 MISRA 2004 Advisory Rule 19.1 only preprocessor statements
* and comments before '#include'
*/
#define ICU_START_SEC_CODE
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      ((USE_ICU_MODULE==STD_OFF) || (ICU_USE_DMA_LLD==STD_OFF)) && (USE_PWM_MODULE==STD_ON) && \
      (DMA_COMMON_MODULE_ID==121) && (PWM_USE_DMA_LLD==STD_ON))
      
#define DMA_CODE (PWM_CODE)
/* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
 * of a header file being included twice */
#define PWM_START_SEC_CODE
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      ((USE_ICU_MODULE==STD_OFF) || (ICU_USE_DMA_LLD==STD_OFF)) && ((USE_PWM_MODULE==STD_OFF) || \
      (PWM_USE_DMA_LLD==STD_OFF)) && (USE_MCU_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==101) && \
      (MCU_USE_DMA_LLD==STD_ON))
      
#define DMA_CODE (MCU_CODE)
/* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
 * of a header file being included twice */
#define MCU_START_SEC_CODE
#include "MemMap.h"
#endif

#if ( ((USE_ADC_MODULE==STD_ON)  && (DMA_COMMON_MODULE_ID==123) && (ADC_USE_DMA_LLD==STD_ON)) || \
      (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && (USE_SPI_MODULE==STD_ON) && \
      (DMA_COMMON_MODULE_ID==83) && (SPI_USE_DMA_LLD==STD_ON)) || \
      (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && (USE_LIN_MODULE==STD_ON) && \
      (DMA_COMMON_MODULE_ID==82) && (LIN_USE_DMA_LLD==STD_ON)) || \
      (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      (USE_ICU_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==122) && (ICU_USE_DMA_LLD==STD_ON)) || \
      (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      ((USE_ICU_MODULE==STD_OFF) || (ICU_USE_DMA_LLD==STD_OFF )) && \
      (USE_PWM_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==121) && (PWM_USE_DMA_LLD==STD_ON)) || \
      (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      ((USE_ICU_MODULE==STD_OFF) || (ICU_USE_DMA_LLD==STD_OFF )) && ((USE_PWM_MODULE==STD_OFF) || \
      (PWM_USE_DMA_LLD==STD_OFF )) && (USE_MCU_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==101) && \
      (MCU_USE_DMA_LLD==STD_ON)))     

/*================================================================================================*/
/**
* @brief   This function initializes the DMA module by MCU driver.
* @details This function initializes the DMA module by MCU driver.
*
* @param[in]  ConfigLLDPtr Pointer to LLD configuration structure
*/
/*================================================================================================*/
/*
* @violates @ref DMA_LLD_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, DMA_CODE) Dma_Init
    (P2CONST(Dma_ConfigType, AUTOMATIC, AUTOMATIC) ConfigLLDPtr)
{
    volatile VAR(uint8, AUTOMATIC) i=0U;
    VAR(uint8, AUTOMATIC) j=0U;

#if (DMA_NB_CONTROLLERS==2U)
    for(i=0U; i<DMA_NB_CONTROLLERS; i++)
    {
#endif
        /* Initialise the EDMA.MCR register with confgured val */
        /*
         * @violates @ref DMA_LLD_c_REF_6 Conversions shall not be performed between a pointer to a
         * function and any type other than an integral type.
         */
        REG_WRITE32(DMA_CR(i), (uint32) ConfigLLDPtr->edmaCr[i]);

        /* Init eDMA channel priority registers */
        for (j=0U; j<DMA_NB_CHANNELS; j++)
        {
            /* update the CPRs registers */
            /*
             * @violates @ref DMA_LLD_c_REF_6 Conversions shall not be performed between a pointer to a
             * function and any type other than an integral type.
            */
            REG_WRITE8(DMA_CPR(j), ConfigLLDPtr->edmaCpr[j]);
        }
#if (DMA_NB_CONTROLLERS==2U)
    }
#endif
}

/*================================================================================================*/
/**
* @brief   This function disables the interrupt for a specific DMA channel.
* @details Clears the interrupt enable bit for a specific DMA channel and also
*          clears the interrupt request
*
* @param[in]    dma_channel      Dma channel for which to disable the interrupt
*/
/*================================================================================================*/
/*
* @violates @ref DMA_LLD_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, DMA_CODE) Dma_disable_interrupt( VAR(uint8, AUTOMATIC) dma_channel)
{
    /* DMA module index */
    volatile VAR(uint8, AUTOMATIC) mIdx = DMA_MOD_IDX(dma_channel);

    /* clear enable interrupt request for dma_channel */
    /*
     * @violates @ref DMA_LLD_c_REF_6 Conversions shall not be performed between a pointer to a
     * function and any type other than an integral type.
     */
    REG_WRITE8(DMA_CERQ(mIdx), dma_channel & DMA_CTRL_MAX_CHANNELS_MASK );
    /* clear interrupt request for dma_channel */
    /*
     * @violates @ref DMA_LLD_c_REF_6 Conversions shall not be performed between a pointer to a
     * function and any type other than an integral type.
     */
    REG_WRITE8(DMA_CINT(mIdx), dma_channel & DMA_CTRL_MAX_CHANNELS_MASK);
}

/*================================================================================================*/
/**
* @brief   Setup a DMA Transfer Control Descritor (TCD).
* @details Configures the DMA Tranfer Control Descriptor
*
* @param[out]    descriptor           Dma descriptor address to be configured
* @param[in]     src_addr             Source address for DMA transfer
* @param[in]     src_transfer_size    Source access transfer size
* @param[in]     dest_transfer_size   Destination access transfer size
* @param[in]     src_next_offset      Offset to be applied to compute next src addr
* @param[in]     n_bytes_to_transfer  Number of bytes to transfer
* @param[in]     src_last_adj         Adjustment to be applied to src addr at the
*                                     completion of the outer major iteration count.
* @param[in]     dest_addr            Destination address for DMA transfer
* @param[in]     crt_iter_cnt         Current major iteration count
* @param[in]     dest_next_offset     Offset to be applied to compute next
*                                     destination address.
* @param[in]     dlast_sg_addr        Adjustment to be applied to destination
*                                     address at the completion of the outer major
*                                     iteration count (if E_SG bit is 0), or
*                                     scatter/gather address (if E_SG bit is 1).
* @param[in]     begin_iter_cnt       Beginning major iteration count
* @param[in]     major_linkch         Major link channel number
* @param[in]     tcd_flags            Mask to configure E_SG(bit4)/D_REQ(bit3)/
*                                     INT_HALF(bit2)/INT_MAJ(bit1) bits of TCD
*
*
* @pre The TCD descriptor must be 32 bytes aligned
*/
/*================================================================================================*/
/*
* @violates @ref DMA_LLD_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, DMA_CODE) Dma_setup_descriptor(
    VAR(DmaTcdPointerType, AUTOMATIC) descriptor,
    VAR(uint32, AUTOMATIC) src_addr,
    VAR(uint8, AUTOMATIC) src_transfer_size,
    VAR(uint8, AUTOMATIC) dest_transfer_size,
    VAR(uint16, AUTOMATIC) src_next_offset,
    VAR(uint16, AUTOMATIC) n_bytes_to_transfer,
    VAR(uint32, AUTOMATIC) src_last_adj,
    VAR(uint32, AUTOMATIC) dest_addr,
    VAR(uint16, AUTOMATIC) crt_iter_cnt,
    VAR(uint16, AUTOMATIC) dest_next_offset,
    VAR(uint32, AUTOMATIC) dlast_sg_addr,
    VAR(uint16, AUTOMATIC) begin_iter_cnt,
    VAR(uint8, AUTOMATIC)  major_linkch,
    VAR(uint8, AUTOMATIC)  tcd_flags
    )
{
    VAR(uint32, AUTOMATIC)reg_value;
    volatile P2VAR(uint32, AUTOMATIC, AUTOMATIC) descriptor32 =
    /*
    * @violates @ref DMA_LLD_c_REF_4 A cast should not be performed between a pointer
    * to object type and a different pointer to object type.
    */
        (volatile P2VAR(uint32, AUTOMATIC, AUTOMATIC))descriptor;

      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    /* Source address */
    descriptor32[0/*DMA_TCD_SADDR_OFFSET>>2 - avoid MISRA Warn*/] = src_addr;

    /* Transfer attributes, source offset */
    reg_value= (uint32)(((uint32)(src_transfer_size)<<24) |
                        (((uint32)dest_transfer_size)<<16) |
                        ((uint32)src_next_offset)
                       );
      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    descriptor32[DMA_TCD_TA_SOFF_OFFSET>>2] = reg_value;

    /* Signed minor loop OFFSET], Number of bytes to transfer
       with each service request
     */
    reg_value=  (uint32) ( (uint32)(n_bytes_to_transfer));
      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    descriptor32[DMA_TCD_SMLO_NBTYES_OFFSET>>2] = reg_value;

      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    /* Source address last adjustment */
    descriptor32[DMA_TCD_SLAST_OFFSET>>2] = src_last_adj;

    /* Destination address */
      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    descriptor32[DMA_TCD_DADDR_OFFSET>>2] = dest_addr;

    /* Current major iteration count, destination offset */
    reg_value= (uint32)((((uint32)crt_iter_cnt)<<16) |
                        ((uint32)(dest_next_offset)) );
      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    descriptor32[DMA_TCD_CITER_DOFF_OFFSET>>2] = reg_value;

    /* Destination address last adjustment / scatter gather address */
      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    descriptor32[DMA_TCD_DLAST_SGA_OFFSET>>2] = dlast_sg_addr;

    /* Beginning iteration count, scatter/gather, interrupt flags */
    reg_value= (uint32)(
                    (((uint32)begin_iter_cnt)<<16) |
                    (((uint32)major_linkch)<<8) |
                    tcd_flags);
    /* DONE flag must be reset prior to set E_SG & E_LINK bits */
      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
    descriptor32[DMA_TCD_BITER_CCS_OFFSET>>2] = 0u;
    /* effective set of last TCD entry */
      /*
       * @violates @ref DMA_LLD_c_REF_7 Array indexing shall be
       *       the only allowed form of pointer arithmetic.
       */
       descriptor32[DMA_TCD_BITER_CCS_OFFSET>>2] = reg_value;
}
#endif /* module check */

#if ((USE_ADC_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==123) && (ADC_USE_DMA_LLD==STD_ON))

#define ADC_STOP_SEC_CODE
/*
* @violates @ref DMA_LLD_C_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && (USE_SPI_MODULE==STD_ON) && \
     (DMA_COMMON_MODULE_ID==83) && (SPI_USE_DMA_LLD==STD_ON))
#define SPI_STOP_SEC_CODE
/*
* @violates @ref DMA_LLD_C_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && (USE_LIN_MODULE==STD_ON) && \
      (DMA_COMMON_MODULE_ID==82) && (LIN_USE_DMA_LLD==STD_ON))
#define LIN_STOP_SEC_CODE
/*
* @violates @ref DMA_LLD_C_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) ||(LIN_USE_DMA_LLD==STD_OFF )) && \
      (USE_ICU_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==122) && (ICU_USE_DMA_LLD==STD_ON))
#define ICU_STOP_SEC_CODE
/*
* @violates @ref DMA_LLD_C_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
#endif


#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      ((USE_ICU_MODULE==STD_OFF) || (ICU_USE_DMA_LLD==STD_OFF)) && (USE_PWM_MODULE==STD_ON) && \
      (DMA_COMMON_MODULE_ID==121) && (PWM_USE_DMA_LLD==STD_ON))
      
#define PWM_STOP_SEC_CODE
/*
* @violates @ref DMA_LLD_C_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
#endif

#if (((USE_ADC_MODULE==STD_OFF) || (ADC_USE_DMA_LLD==STD_OFF)) && ((USE_SPI_MODULE==STD_OFF) || \
      (SPI_USE_DMA_LLD==STD_OFF)) && ((USE_LIN_MODULE==STD_OFF) || (LIN_USE_DMA_LLD==STD_OFF )) && \
      ((USE_ICU_MODULE==STD_OFF) || (ICU_USE_DMA_LLD==STD_OFF)) && ((USE_PWM_MODULE==STD_OFF) || \
      (PWM_USE_DMA_LLD==STD_OFF)) && (USE_MCU_MODULE==STD_ON) && (DMA_COMMON_MODULE_ID==101) && \
      (MCU_USE_DMA_LLD==STD_ON))
      
#define MCU_STOP_SEC_CODE
/*
* @violates @ref DMA_LLD_C_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref DMA_LLD_C_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
#endif

 
#ifdef __cplusplus
}
#endif

/** @} */

