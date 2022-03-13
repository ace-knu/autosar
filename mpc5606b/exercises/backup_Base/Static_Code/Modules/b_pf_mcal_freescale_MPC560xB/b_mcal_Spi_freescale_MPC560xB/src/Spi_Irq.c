/**
*   @file    Spi_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - ISR file.
*   @details ISR description.
*
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : DSPI
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Spi_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 11.1,
* This violation is due to casting unsigned long to pointer and access these address for updating
* contents in that address.
*
* @section Spi_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* This violation is not fixed since naming convention of Identifiers are followed as per Autosar
* standards, some times which may exceeds more than 31 characters.
*
* @section Spi_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Spi_Irq.c
* @implements     DSPI02634.
*/
#include "Spi.h"
#include "Spi_LLD.h"
/*
* @violates @ref Spi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Mcal.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Spi_Irq.c
* @implements   DSPI02049
*/
/*
* @violates @ref Spi_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_MODULE_ID_IRQ_C                      83
#define SPI_VENDOR_ID_IRQ_C                      43
 /*
* @violates @ref Spi_Irq_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
 /*
* @violates @ref Spi_Irq_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MINOR_VERSION_IRQ_C       0
/*
* @violates @ref Spi_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Irq_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_REVISION_VERSION_IRQ_C    3
#define SPI_SW_MAJOR_VERSION_IRQ_C               1
#define SPI_SW_MINOR_VERSION_IRQ_C               0
#define SPI_SW_PATCH_VERSION_IRQ_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_IRQ_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_Irq.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_IRQ_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_IRQ_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_IRQ_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_Irq.c and Spi_Dspi_LLD.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

    /* Interrupt service routines */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_0_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrRxDma_DSPI_0);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_1_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrRxDma_DSPI_1);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_2_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrRxDma_DSPI_2);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_3_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrRxDma_DSPI_3);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_4_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrRxDma_DSPI_4);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_5_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrRxDma_DSPI_5);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_0_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrEOQ_DSPI_0);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_1_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrEOQ_DSPI_1);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_2_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrEOQ_DSPI_2);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_3_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrEOQ_DSPI_3);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_4_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrEOQ_DSPI_4);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_5_ENABLED == STD_ON)
    ISR(Spi_LLD_IsrEOQ_DSPI_5);
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx ISR for the DSPI 0.
* @details Non-AutoSar support function used by interrupt service
*          routine of the DMA Rx for DSPI 0
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_0_ENABLED shall be STD_ON.
*
* @implements DSPI02814.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_0_ENABLED == STD_ON)
ISR(Spi_LLD_IsrRxDma_DSPI_0)
{
#if (SPI_DMA_USED == STD_ON)
    Spi_LLD_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_0_HWUNIT));
#endif
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx ISR for the DSPI 1.
* @details Non-AutoSar support function used by interrupt service
*          routine of the DMA Rx for DSPI 1.
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_1_ENABLED shall be STD_ON.
*
* @implements DSPI02814.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_1_ENABLED == STD_ON)
ISR(Spi_LLD_IsrRxDma_DSPI_1)
{
#if (SPI_DMA_USED == STD_ON)
    Spi_LLD_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_1_HWUNIT));
#endif
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx ISR for the DSPI 2.
* @details Non-AutoSar support function used by interrupt service
*          routine of the DMA Rx for DSPI 2
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_2_ENABLED shall be STD_ON.
*
* @implements DSPI02814.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_2_ENABLED == STD_ON)
ISR(Spi_LLD_IsrRxDma_DSPI_2)
{
#if (SPI_DMA_USED == STD_ON)
    Spi_LLD_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_2_HWUNIT));
#endif
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
/**
* @brief   This function is the DMA Rx ISR for the DSPI 3.
* @details Non-AutoSar support function used by interrupt service
*          routine of the DMA Rx for DSPI 3
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_3_ENABLED shall be STD_ON.
*
* @implements DSPI02814.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_3_ENABLED == STD_ON)
ISR(Spi_LLD_IsrRxDma_DSPI_3)
{
#if (SPI_DMA_USED == STD_ON)
    Spi_LLD_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_3_HWUNIT));
#endif
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
/**
* @brief   This function is the DMA Rx ISR for the DSPI 4.
* @details Non-AutoSar support function used by interrupt service
*          routine of the DMA Rx for DSPI 4
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_4_ENABLED shall be STD_ON.
*
* @implements DSPI02814.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_4_ENABLED == STD_ON)
ISR(Spi_LLD_IsrRxDma_DSPI_4)
{
#if (SPI_DMA_USED == STD_ON)
    Spi_LLD_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_4_HWUNIT));
#endif
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
/**
* @brief   This function is the DMA Rx ISR for the DSPI 5.
* @details Non-AutoSar support function used by interrupt service
*          routine of the DMA Rx for DSPI 5
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_5_ENABLED shall be STD_ON.
*
* @implements DSPI02814.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_5_ENABLED == STD_ON)
ISR(Spi_LLD_IsrRxDma_DSPI_5)
{
#if (SPI_DMA_USED == STD_ON)
    Spi_LLD_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_5_HWUNIT));
#endif
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 0.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 0
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_0_ENABLED shall be STD_ON.
*
* @implements DSPI02815.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_0_ENABLED == STD_ON)
ISR(Spi_LLD_IsrEOQ_DSPI_0)
{
    Spi_LLD_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_0_HWUNIT));
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 1.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_1_ENABLED shall be STD_ON.
*
* @implements DSPI02815.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_1_ENABLED == STD_ON)
ISR(Spi_LLD_IsrEOQ_DSPI_1)
{
    Spi_LLD_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_1_HWUNIT));
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 2.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 2.
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_2_ENABLED shall be STD_ON.
*
* @implements DSPI02815.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_2_ENABLED == STD_ON)
ISR(Spi_LLD_IsrEOQ_DSPI_2)
{
    Spi_LLD_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_2_HWUNIT));
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 3.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 3.
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_3_ENABLED shall be STD_ON.
*
* @implements DSPI02815.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_3_ENABLED == STD_ON)
ISR(Spi_LLD_IsrEOQ_DSPI_3)
{
    Spi_LLD_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_3_HWUNIT));
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 4.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 4.
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_4_ENABLED shall be STD_ON.
*
* @implements DSPI02815.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_4_ENABLED == STD_ON)
ISR(Spi_LLD_IsrEOQ_DSPI_4)
{
    Spi_LLD_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_4_HWUNIT));
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 5.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 5.
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_5_ENABLED shall be STD_ON.
*
* @implements DSPI02815.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (DSPI_5_ENABLED == STD_ON)
ISR(Spi_LLD_IsrEOQ_DSPI_5)
{
    Spi_LLD_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_5_HWUNIT));
    /*
    * @violates @ref Spi_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif
#endif

/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*/
/* 
*@violates @ref Spi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */



