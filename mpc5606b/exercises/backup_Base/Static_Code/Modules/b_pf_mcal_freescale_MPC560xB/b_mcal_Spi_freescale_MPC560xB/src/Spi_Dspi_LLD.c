/**
*   @file    Spi_Dspi_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - DSPI low-level driver implementations.
*   @details DSPI low-level driver implementations.
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
* @section Spi_Dspi_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_Dspi_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_Dspi_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to casting unsigned long to pointer
* and access these address for updating contents in that address.
*
* @section Spi_Dspi_LLD_c_REF_4
* Violates MISRA 2004 Advisory Rule 11.4,
* A cast should not be performed between a pointer to object type and a different pointer to object type.
* Casts between (uint8*) and (uint32*) are used for optimizing the memory accesses.
*
* @section Spi_Dspi_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
* Structure shall be public as it is used by Reg_eSys_DSPI.h which may be sed outside DSPI module.
*
* @section Spi_Dspi_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 17.4,
* Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*
* @section Spi_Dspi_LLD_c_REF_7
* Violates MISRA 2004 Advisory Rule 12.6,
* The operands of logical operators (&&, || and !) should be effectively Boolean.
* Expressions that are effectively Boolean should not be used as operands
* to operators other than (&&, || and !).
* Gain in generated code speed
*
* @section Spi_Dspi_LLD_c_REF_8
* Violates MISRA 2004 Required Rule 1.4,
* This violation is not fixed since naming convention of Identifiers are followed as per Autosar
* standards, some times which may exceeds more than 31 characters.
*
* @section Spi_Dspi_LLD_c_REF_9
* Violates MISRA 2004 Required Rule 10.1,
* The value of an expression of integer type shall not be implicitly
* converted to a different underlying type
*
* @section Spi_Dspi_LLD_c_REF_10
* Violates MISRA 2004 Required Rule 10.5,
* If the bitwise operators ~ and << are applied to an operand of
*underlying type unsigned char or unsigned short, the result shall
*be immediately cast to the underlying type of the operand.
*
* @section Spi_Dspi_LLD_c_REF_11
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
 *
 * @section Spi_Dspi_LLD_c_REF_12
* Violates MISRA 2004 Required Rule 10.5, Shift left of signed quantity(int)
* This rule can not be avoided because it appears when addressing memory mapped registers
* or other hardware specific feature.
*
* @section Spi_Dspi_LLD_c_REF_13
* Violates MISRA 2004 Required Rule 12.8, The right hand operand of a shift operator shall lie between zero
* and one less than the width in bits of the underlying type of the left hand operand.
*
* @section Spi_Dspi_LLD_c_REF_14
* Violates MISRA 2004 Advisory Rule 12.1, Limited dependence should be placed on C's operator precedence
* rules in expressions
*
* @section Spi_Dspi_LLD_c_REF_15
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Spi_Dspi_LLD.c
* @requirements   BSW00374, BSW00318.
*/

#include "Mcal.h"
#include "Spi.h"
#include "Spi_Dspi_LLD.h"
/*
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif

#include "Reg_eSys_DSPI.h"
#if (SPI_DMA_USED == STD_ON)
#include "Dma_LLD.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Spi_Dspi_LLD.c
* @implements     DSPI02049
*/
/*
* @violates @ref Spi_Dspi_LLD_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Dspi_LLD_c_REF_11 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_LLD_C         4
/*
* @violates @ref Spi_Dspi_LLD_c_REF_8 The compiler/linker shall be checked to ensure that 31
* character signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Dspi_LLD_c_REF_11 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MINOR_VERSION_LLD_C         0
/*
* @violates @ref Spi_Dspi_LLD_c_REF_8 The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Dspi_LLD_c_REF_11 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_REVISION_VERSION_LLD_C      3
#define SPI_SW_MAJOR_VERSION_LLD_C                 1
#define SPI_SW_MINOR_VERSION_LLD_C                 0
#define SPI_SW_PATCH_VERSION_LLD_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SPI configuration header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_LLD_C   != SPI_AR_RELEASE_MAJOR_VERSION) || \
    (SPI_AR_RELEASE_MINOR_VERSION_LLD_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
    (SPI_AR_RELEASE_REVISION_VERSION_LLD_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SPI_LLD.c and Spi.h are different"
#endif

#if ((SPI_SW_MAJOR_VERSION_LLD_C != SPI_SW_MAJOR_VERSION) || \
    (SPI_SW_MINOR_VERSION_LLD_C  != SPI_SW_MINOR_VERSION))
#error "Software Version Numbers of SPI_LLD.c and SPI_LLD.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#if ((SPI_AR_RELEASE_MAJOR_VERSION_LLD_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
    (SPI_AR_RELEASE_MINOR_VERSION_LLD_C  != DEM_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Spi_LLD.c and Dem.h are different"
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
*                                     LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
 /*
* @violates @ref Spi_Dspi_LLD_c_REF_11 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief Pool of cached information for sequences having only one job.
*/
STATIC VAR(Spi_SequenceCacheAttrs, SPI_VAR)
/* @violates @ref Spi_Dspi_LLD_c_REF_15 could define variable at block scope */
    DspiSeqsAttributes[SPI_OPTIMIZED_SEQ_BUFFER_SIZE];

/**
* @brief Pool of cached information for sequences having only one job.
*/
STATIC VAR(Spi_ChannelCacheAttrs, SPI_VAR)
/* @violates @ref Spi_Dspi_LLD_c_REF_15 could define variable at block scope */
    DspiChannelsAttributes[SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE];
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))

/**
* @brief DMA TCD descriptors for scatter / gather DMA transmissions
* @note  This buffers must be alligned at 32bytes.
* @note  lint tool detection failed due to macro usage.
*        Conform with MISRA 2004 Required Rules 8.10 (local variable must be
*        defined as static)
*/
ALIGNED_VARS_START(ex_var, 32)
/* @violates @ref Spi_Dspi_LLD_c_REF_15 could define variable at block scope */
VAR_ALIGN(STATIC VAR(DmaTcdType, SPI_VAR) Dspi_DmaTcdTxArray[SPI_MAX_HWUNIT], 32)
/* @violates @ref Spi_Dspi_LLD_c_REF_15 could define variable at block scope */
VAR_ALIGN(STATIC VAR(DmaTcdType, SPI_VAR) Dspi_DmaTcdTxLastArray[SPI_MAX_HWUNIT], 32)
ALIGNED_VARS_STOP()
#endif  /* SPI_DMA_USED == STD_ON */
 /*
* @violates @ref Spi_Dspi_LLD_c_REF_11 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_32
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief DSPI base address array.
*/
/*
* @violates @ref Spi_Dspi_LLD_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
CONST(uint32, SPI_CONST) DSPI_BASE_ADDRS[] =
{
    #ifdef  DSPI0_BASEADDR
        DSPI0_BASEADDR,
    #endif
    #ifdef  DSPI1_BASEADDR
        DSPI1_BASEADDR,
    #endif
    #ifdef  DSPI2_BASEADDR
        DSPI2_BASEADDR,
    #endif
    #ifdef  DSPI3_BASEADDR
        DSPI3_BASEADDR,
    #endif
    #ifdef  DSPI4_BASEADDR
        DSPI4_BASEADDR,
    #endif
    #ifdef  DSPI5_BASEADDR
        DSPI5_BASEADDR,
    #endif
    #ifdef  DSPI6_BASEADDR
        DSPI6_BASEADDR,
    #endif
    #ifdef  DSPI7_BASEADDR
        DSPI7_BASEADDR,
    #endif
    #ifdef  DSPI8_BASEADDR
        DSPI8_BASEADDR,
    #endif
    #ifdef  DSPI9_BASEADDR
        DSPI9_BASEADDR,
    #endif
    #ifdef  DSPI10_BASEADDR
        DSPI10_BASEADDR,
    #endif
    #ifdef  DSPI11_BASEADDR
        DSPI11_BASEADDR,
    #endif
    #ifdef  DSPI12_BASEADDR
        DSPI12_BASEADDR
    #endif

};

#define SPI_STOP_SEC_CONST_32
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/* @violates @ref Spi_Dspi_LLD_c_REF_15 could define variable at block scope */
STATIC VAR(volatile uint32, SPI_VAR) DspiReadDiscard;

#define SPI_STOP_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
 /*
* @violates @ref Spi_Dspi_LLD_c_REF_11 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief       Holds the mode of the Dual Clock.
* @details       This structure is used to store runtime internal state parameters
*              for the DSPI IP peripheral.
*
* @implements DSPI02411.
*/
/*
* @violates @ref Spi_Dspi_LLD_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_DualClockMode, SPI_VAR) Dspi_ClockMode;
#endif

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief         Pointer table to the cached information structure, for one job
*             sequences, or NULL, for unoptimized sequences.
* @details    Internal structure keeping a set of cached sequences attributes
*               used by the optimized implementation of Spi_SyncTransmit() for the
*              sequences having only one job.
*
* @implements DSPI02808.
*/
/*
* @violates @ref Spi_Dspi_LLD_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
P2VAR(Spi_SequenceCacheAttrs, SPI_VAR, SPI_APPL_DATA) DspiOneJobSeqsOptimized[SPI_MAX_SEQUENCE];
#endif

/**
* @brief Keep the HWUnit internal fields.
*
* @implements DSPI02807.
*/
/*
* @violates @ref Spi_Dspi_LLD_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_LLD_DeviceState, SPI_VAR) DspiDeviceState[SPI_MAX_HWUNIT];
 /*
* @violates @ref Spi_Dspi_LLD_c_REF_11 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_InitDma(
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_DmaIrqConfig(
        P2CONST(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_CONST) DspiDev,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_ChannelTransferFifoInit(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev,
    VAR(Spi_ChannelType, AUTOMATIC) Channel);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_JobTransferFifoDrain(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_JobTransferFifoFill(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_ChannelTransferDmaInit(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev,
    VAR(Spi_ChannelType, AUTOMATIC) Channel);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_JobTransferDmaContinue(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev);
#endif


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Initialize DMA related fields for a DSPI unit.
* @details Initialize DMA TCD descriptors static fields.
*
* @param[in]     HWUnit      Specifies which DSPI peripheral is used.
* @param[in]     DspiDev     LLD instance of the given DSPI peripheral.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_InitDma(
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev)
{
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig;

    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
    /* initialize cache values */
    DspiDev->TxDmaTcdDefault =
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))Dspi_DmaTcdTxArray[HWUnit];
    DspiDev->TxDmaTcdLast =
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))Dspi_DmaTcdTxLastArray[HWUnit];
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    HWUnitConfig = DspiDev->HWUnitConfig;
    DspiDev->TxDmaTcd =
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))DMA_TCD(HWUnitConfig->TxDmaChannel);
    DspiDev->RxDmaTcd =
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))DMA_TCD(HWUnitConfig->RxDmaChannel);

    /* store DMA Minor ELink configuration for future usage */
    DspiDev->MinorELink =
    (((uint16)((uint16)1u << 15)) |
        ((uint16)(((uint16)HWUnitConfig->TxDmaChannelAux & DMA_CTRL_MAX_CHANNELS_MASK) << 9))
    );

    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
    /* descriptors are channel dependent and will be updated if channel data width exceeds Spi_DataType */
    /* configure TX Channel 1 to write data frames (16bits) to TxDmaBuffer */
    Dma_setup_descriptor((DmaTcdPointerType)DspiDev->TxDmaTcd,
        (uint32) 0u, /* src address read => will be updated later */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            (uint8)  0x0, /* 1bytes src transfer size */
            (uint8)  0x0, /* 1bytes dest transfer size */
            (uint16) 1u, /* src offset */
            (uint16) 1u, /* bytes to transfer */
        #else
            (uint8)  DMA_DATA_TRANSFER_16_BIT, /* 2bytes src transfer size */
            (uint8)  DMA_DATA_TRANSFER_16_BIT, /* 2bytes dest transfer size */
            (uint16) 2u, /* src offset */
            (uint16) 2u, /* bytes to transfer */
        #endif
        (uint32) 0u, /* no src adjustment */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
           (uint32) (&DspiDev->TxDmaBuffer)+3u, /* dest address */
        #else
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
           (uint32) (&DspiDev->TxDmaBuffer)+2u, /* dest address */
        #endif
        (uint16) DspiDev->MinorELink, /* major iter will be updated later */
        (uint16) 0u, /* no dest offset */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (uint32) DspiDev->TxDmaTcdDefault, /* S/G to itself */
        (uint16) DspiDev->MinorELink, /* major iter will be updated later */
        (uint8)  HWUnitConfig->TxDmaChannelAux, /* major e_link */
        (uint8)  (DMA_TCD_MAJOR_E_LINK | DMA_TCD_SGA));

    /* duplicate in memory TX Channel 1 TCD, for final restore */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
    Dma_setup_descriptor((DmaTcdPointerType)DspiDev->TxDmaTcdDefault,
        (uint32) 0u, /* src address read => will be updated later */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            (uint8)  0x0, /* 1bytes src transfer size */
            (uint8)  0x0, /* 1bytes dest transfer size */
            (uint16) 1u, /* src offset */
            (uint16) 1u, /* bytes to transfer */
        #else
            (uint8)  DMA_DATA_TRANSFER_16_BIT, /* 2bytes src transfer size */
            (uint8)  DMA_DATA_TRANSFER_16_BIT, /* 2bytes dest transfer size */
            (uint16) 2u, /* src offset */
            (uint16) 2u, /* bytes to transfer */
        #endif
        (uint32) 0u, /* no src adjustment */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
           (uint32) (&DspiDev->TxDmaBuffer)+3u, /* dest address */
        #else
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
           (uint32) (&DspiDev->TxDmaBuffer)+2u, /* dest address */
        #endif
        (uint16) DspiDev->MinorELink, /* major iter will be updated later */
        (uint16) 0u, /* no dest offset */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (uint32) DspiDev->TxDmaTcdDefault, /* S/G to itself */
        (uint16) DspiDev->MinorELink, /* major iter will be updated later */
        (uint8)  HWUnitConfig->TxDmaChannelAux, /* major e_link */
        (uint8)  (DMA_TCD_MAJOR_E_LINK | DMA_TCD_SGA));

    /* configure TX Channel 2 to write TxDmaBuffer (32bits) to DSPI PUSHR */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    Dma_setup_descriptor((DmaTcdPointerType)(DMA_TCD(HWUnitConfig->TxDmaChannelAux)),
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (uint32) (&DspiDev->TxDmaBuffer), /* src address read */
        (uint8)  DMA_DATA_TRANSFER_32_BIT, /* 4bytes src transfer size */
        (uint8)  DMA_DATA_TRANSFER_32_BIT, /* 4bytes dest transfer size */
        (uint16) 0u, /* no src offset */
        (uint16) 4u, /* bytes to transfer */
        (uint32) 0u, /* no src adjustment */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (uint32) (DspiDev->pDspiPUSHRAddress), /* dest address */
        (uint16) 1, /* crt maj iter cnt */
        (uint16) 0u, /* no dest offset */
        (uint32) 0u, /* no dest adjustment */
        (uint16) 1, /* beg maj iter cnt */
        (uint8)  0u, /* no major linked channel */
        (uint8)  DMA_TCD_DISABLE_REQ);

    /* setup scatter/gather TCD */
    /* S/G to the original DMA TCD => reload the initial values */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
    Dma_setup_descriptor((DmaTcdPointerType)DspiDev->TxDmaTcdLast,
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (uint32) (&DspiDev->TxDmaBufferLast), /* src address read */
        (uint8)  DMA_DATA_TRANSFER_32_BIT, /* 4bytes src transfer size */
        (uint8)  DMA_DATA_TRANSFER_32_BIT, /* 4bytes dest transfer size */
        (uint16) 0u, /* no src offset */
        (uint16) 4u, /* bytes to transfer */
        (uint32) 0u, /* no src adjustment */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (uint32) (&DspiDev->TxDmaBuffer), /* dest address */
        (uint16) 1u, /* crt maj iter cnt */
        (uint16) 0u, /* no dest offset */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (uint32) DspiDev->TxDmaTcdDefault, /* S/G to the initial TX DMA TCD */
        (uint16) 1u, /* beg maj iter cnt */
        (uint8)  HWUnitConfig->TxDmaChannelAux, /* major e_link */
        (uint8)  (DMA_TCD_MAJOR_E_LINK | DMA_TCD_DISABLE_REQ | DMA_TCD_SGA));

    /* setup RX DMA channel */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
    Dma_setup_descriptor((DmaTcdPointerType)DspiDev->RxDmaTcd,
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
            (uint32)(DspiDev->pDspiPOPRAddress)+3u, /* data only read */
            (uint8) 0x0, /* 1bytes src transfer size */
            (uint8) 0x0, /* 1bytes dest transfer size */
        #else
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
            (uint32)(DspiDev->pDspiPOPRAddress)+2u, /* data only read */
            (uint8) DMA_DATA_TRANSFER_16_BIT, /* 2bytes src transfer size */
            (uint8) DMA_DATA_TRANSFER_16_BIT, /* 2bytes dest transfer size */
        #endif
        (uint16) 0u, /* no src offset */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            (uint16) 1u, /* bytes to transfer */
        #else
            (uint16) 2u, /* bytes to transfer */
        #endif
        (uint32) 0u, /* no src adjustment */
        (uint32) 0u, /* dest address => will be updated later */
        (uint16) 0u, /* crt maj iter cnt => will be updated later */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            (uint16) 1u, /* bytes to transfer */
        #else
            (uint16) 2u, /* dest offset */
        #endif
        (uint32) 0u, /* no dest adjustment */
        (uint16) 0u, /* beg maj iter cnt => will be updated later */
        (uint8)  0u, /* no major linked channel */
        (uint8)  DMA_TCD_DISABLE_REQ);

}
#endif /* (SPI_DMA_USED == STD_ON) */

/*================================================================================================*/
/**
* @brief   Configures DMA interrupts for the Rx channel.
* @details Activate RX channel interrupt in interrupt mode or disable then
*          in polling mode.
*
* @param[in]     DspiDev     LLD instance of the given DSPI peripheral.
* @param[in]     AsyncMode   Operation mode (SPI_INTERRUPT_MODE | SPI_POLLING_MODE).
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_DmaIrqConfig(
        P2CONST(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_CONST) DspiDev,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode)
{
    if (SPI_INTERRUPT_MODE == AsyncMode)
    {
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Set_DMA_TCDADDR_INT(DspiDev->RxDmaTcd);
    }
    else
    {
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Clear_DMA_TCDADDR_INT(DspiDev->RxDmaTcd);
    }
}
#endif /* (SPI_DMA_USED == STD_ON) */

/*================================================================================================*/
/**
* @brief   This function initializes channel related informations in DSPI HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel
*
*     Configuration caracteristics:
*     - TxDma1 fills the Data part (16bits) of a TxBuffer (32 bits), with the
*       command field set by this function
*     - TxDma1 is daisy chained with TxDma2 which transfers the TxBuffer content
*       to the DSPI PUSHR register.
*     - At the end of TxDma1 transmission, one of the following may happend:
*         -> a dedicated descriptor is loaded through scatter/gather into the
*            channel TCD, in order to transfer the last dataframe which will
*            deassert the CS signal (for end of job channels - see picture below)
*         -> the default Tx descriptor is reloaded through scatter/gather into
*            the channel TCD, in order to facilitate the next transmission
*            configuration; transmission session not started for this descriptor
*            (for not end of job channels, or for channels having the size of 1.)
*         -> the scatter/gather link is disabled, and the DMA transmission ends,
*            conserving the actual Spi Tx/Rx Buffer pointers (for long channels,
*            which need to be transfered in manny datachunck of
*            DMA_MAX_LINKED_ITER_CNT)
*
* 1) DMA configuration for the transmission of the last channel in job
*    - for this situation, the last frame will be sent using a distinct DMA
*      descriptor, as it should manage the CS deassertion into the command field.
*
*     SpiTxBuffer
*          |
*          V
*     ,---------,     DMA.E_LINK
*     | TX DMA1 |.......................
*     |         |>-------,             :
*     '---------'        |             :
*      :DMA.S_G          |16bits       :
*      :                 |             :
*      : TxDmaBufferLast |             :
*      :     |           |             :
*      V     V           |             :
*     ,---------,        |  DMA.E_LINK V
*     | TX DMA  |.......................
*     |  Last   |>--,    |             :
*     '---------'   |    |             :
*                   |    |             :
*             32bits|    V             :
*                   V /----\           :
*                /---------\           V
*   TxDmaBuffer: |Cmd |Data|      ,---------,
*                \---------/      | TX DMA2 |
*                     '---------->|         |---->DSPI.PUSHR
*                         32bits  '---------'
*                                                             ,---------,
*                                                 DSPI.POPR-->| RX DMA  |
*                                                             |         |
*                                                             '---------'
*                                                                  |
*                                                                  V
*                                                             SpiRxBuffer
*
* 2) DMA configuration for the transmission of a not final job channel, or
*    for channels having only one dataframe.
*    - all transmission is managed through the DMA TX descriptor in place;
*      reload only the default DMA descriptor
*
*     SpiTxBuffer
*          |
*          V
*     ,---------,     DMA.E_LINK
*     | TX DMA1 |.......................
*     |         |>-------,             :
*     '---------'        |             :
*          :DMA.S_G      |16bits       :
*          :             |             :
*          :             |             :
*          :             |             :
*          V             |             :
*     ,---------,        |             :
*     | TX DMA  |        |             :
*     | Default |        |             :
*     '---------'        |             :
*                        |             :
*                        |             :
*                        V             :
*                     /----\           V
*   TxDmaBuffer: |Cmd |Data|      ,---------,
*                \---------/      | TX DMA2 |
*                     '---------->|         |---->DSPI.PUSHR
*                         32bits  '---------'
*                                                             ,---------,
*                                                 DSPI.POPR-->| RX DMA  |
*                                                             |         |
*                                                             '---------'
*                                                                  |
*                                                                  V
*                                                             SpiRxBuffer
*
* 3) DMA configuration for the transmission of long jobs
*    - same picture as (2) but without any scatter/gather chaining;
*    - then the transmission is finished, the Tx channel descriptor
*      will conserve the Rx/Tx Spi buffer pointers
*
* As the Tx / Rx channel descriptors are already preset with some values, this
* function updates only:
* - Tx descriptor: - source address (Spi Tx Buffer)
*                  - DMA major iteration count (derived from channel size)
*                  - scattered/gathered DMA descriptor address
*                    (TxDmaLast or TxDmaDefault)
*                  - flags (S/G & DREQ activation)
* - Rx descriptor: - destination address (Spi Rx Buffer)
*                  - DMA major iteration count (channel size)
*
* @param[in]     DspiDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_ChannelTransferDmaInit(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev,
    VAR(Spi_ChannelType, AUTOMATIC) Channel)
{
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig;
    P2CONST(Spi_LLD_ChannelAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
        DspiChannelAttributesConfig;
    P2CONST(Spi_ChannelConfig, AUTOMATIC, SPI_APPL_CONST) pChannelConfig =
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
        &SpiConfigPtr->ChannelConfig[Channel];
    P2VAR(Spi_ChannelState, AUTOMATIC, SPI_APPL_DATA) pChannelState =
        pChannelConfig->ChannelState;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) BufferRX;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) BufferTX;
    VAR(Spi_NumberOfDataType, AUTOMATIC) FramesCount;
    VAR(sint32, AUTOMATIC) CsClearNeeded = FALSE;
    volatile P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) TxTcdAddr = DspiDev->TxDmaTcd;
    volatile P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) RxTcdAddr = DspiDev->RxDmaTcd;
    VAR(uint8, AUTOMATIC) SgaFlag = DMA_TCD_SGA;

    /* Set the CTAR parameters for this channel */
    DspiChannelAttributesConfig =
        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig;

    /* set CTAR register */
    /*
    * @remarks The call is blocking till the HWUnit exits the running state.
    */
    REG_WRITE32(DspiDev->pDspiCTARAddress,
                (DspiDev->ExternalDeviceCTAR |
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
                *       to object type and a different pointer to object type.
                */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                DspiChannelAttributesConfig[Channel].CMD));


    FramesCount = pChannelState->Length;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth)
    {
        FramesCount /= 2u;
    }
#endif

    /* identify the TX/RX buffers and update them into the DMA TCDs */
    if (0u != (pChannelState->Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT)))
    {
        /* update source address into the DMA TCD */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_SADDR(TxTcdAddr, (uint32)(&pChannelConfig->DefaultTransmitValue));
        /* overwrite the default src next offset */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_SOFF(TxTcdAddr, (uint16)0u /* no src offset */);

        DspiDev->TxDmaBufferLast = ((DspiDev->CurrentCmd & ~DSPI_CONT_MASK) |
                pChannelConfig->DefaultTransmitValue);
    }
    else
    {
        BufferTX = pChannelConfig->BufferDescriptor->BufferTX;

        /* configure TX Channel 1 to write data frames (8 or 16bits - depending on Spy_DataType) to
           TxDmaBuffer */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_SADDR(TxTcdAddr, (uint32)BufferTX);

        #if (SPI_FORCE_DATA_TYPE == STD_ON)
          /*
          * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
          *       the only allowed form of pointer arithmetic.
          */
          if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth)
          {
                /* overwrite the default src next offset */
                /* 2 bytes src transfer size, 2 bytes dest transfer size */
                /* 2 bytes src offset */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                REG_WRITE32((uint32)(TxTcdAddr) + DMA_TCD_TA_SOFF_OFFSET, (uint32)(0x01010002u));
                /* dest address */
                REG_WRITE32((uint32)(TxTcdAddr) + DMA_TCD_DADDR_OFFSET,
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed
                            * between a pointer to a function and any type other than an integral type.
                            */
                            (uint32)(&DspiDev->TxDmaBuffer)+2u);
                /* 2 bytes to transfer */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                REG_WRITE32((uint32)(TxTcdAddr) + DMA_TCD_SMLO_NBTYES_OFFSET, (uint32)(0x02u));
          }
          else
          {
                /* overwrite the default src next offset */
                /* 1 bytes src transfer size, 1 bytes dest transfer size */
                /* 1 bytes src offset */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                REG_WRITE32((uint32)(TxTcdAddr) + DMA_TCD_TA_SOFF_OFFSET, (uint32)(0x00000001u));
                /* dest address */
                REG_WRITE32((uint32)(TxTcdAddr) + DMA_TCD_DADDR_OFFSET,
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed
                            * between a pointer to a function and any type other than an integral type.
                            */
                            (uint32)(&DspiDev->TxDmaBuffer)+3u);
                /* 1 bytes to transfer */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                REG_WRITE32((uint32)(TxTcdAddr) + DMA_TCD_SMLO_NBTYES_OFFSET, (uint32)(0x01u));
          }
        #endif
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth )
        {
            DspiDev->TxDmaBufferLast = ((DspiDev->CurrentCmd & ~DSPI_CONT_MASK) |
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_10 the result shall
                        * be immediately cast to the underlying type of the operand.
                        */
                        ((uint32)(BufferTX[pChannelState->Length -2u])<<8) |
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                          BufferTX[pChannelState->Length - 1u] );
        }
        else
        {
            DspiDev->TxDmaBufferLast = ((DspiDev->CurrentCmd & ~DSPI_CONT_MASK) |
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    BufferTX[FramesCount-1u]);
        }
        #else
            DspiDev->TxDmaBufferLast = ((DspiDev->CurrentCmd & ~DSPI_CONT_MASK) |
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        BufferTX[FramesCount-1u]);
        #endif
    }

    /* prepare the command in the intermediate buffer */
    DspiDev->TxDmaBuffer = DspiDev->CurrentCmd;

    /* get the number of frames to be sent through DMA */
    if ( DMA_MAX_LINKED_ITER_CNT < FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        DspiDev->RemainingData = FramesCount - DMA_MAX_LINKED_ITER_CNT;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth)
            {
            DspiDev->RemainingData *= 2u;
            }
        #endif
        FramesCount = DMA_MAX_LINKED_ITER_CNT;

        /* S/G linking must be disabled in this case;
        The actual TCD must be in place till the last DMA chunk will
        be finished */
        SgaFlag = 0u;
        /* reset dest address adjustement */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_DLAST_SGA(TxTcdAddr, 0u);
    }
    else
    {
        DspiDev->RemainingData = 0u;

        /* identify if CS clearing will be needed at the channel end */
        if (0u == DspiDev->RemainingChannels)
        {
            if (1u == FramesCount)
            {   /* clear the CS assertion directly into the next TX frame */
                DspiDev->TxDmaBuffer &= ~DSPI_CONT_MASK;
            }
            else
            {   /* the last dataframe must be sent in a distinct TCD */
                CsClearNeeded = TRUE;
            }
        }
    }

    /* Configure RX DMA descriptor */
    /* Rx buffer will be NULL if discarding read values */
    BufferRX = pChannelConfig->BufferDescriptor->BufferRX;
    if (NULL_PTR == BufferRX)
    {
        /* dest address - discard read */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_DADDR(RxTcdAddr, (uint32) &DspiReadDiscard);
        /* update RX transfer size; no offset for destination address */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_CITER_DOFF(RxTcdAddr, ((uint32)(FramesCount)<<16) | 0u );
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_BITER(RxTcdAddr, (uint16)FramesCount);
    }
    else
    {
        /* dest address - RX buffer */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_DADDR(RxTcdAddr, (uint32) BufferRX);
        /* update RX transfer size; 2bytes offset for destination address */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
          if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth)
          {
                /* update RX transfer size; 2bytes offset for destination address */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                LLM_Wr_DMA_TCDADDR_CITER_DOFF(RxTcdAddr, ((uint32)(FramesCount)<<16) | 2u );
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                LLM_Wr_DMA_TCDADDR_SADDR(RxTcdAddr, (uint32)(DspiDev->pDspiPOPRAddress)+2u);
                /* overwrite the default src next offset */
                /* 2 bytes src transfer size, 2 bytes dest transfer size */
                /* no src offset */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                 REG_WRITE32((uint32)(RxTcdAddr) + DMA_TCD_TA_SOFF_OFFSET, (uint32)(0x01010000u));
                 /* 2 bytes to transfer */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                 REG_WRITE32((uint32)(RxTcdAddr) + DMA_TCD_SMLO_NBTYES_OFFSET, (uint32)(0x02u));
          }
          else
          {
                /* update RX transfer size; 1bytes offset for destination address */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                LLM_Wr_DMA_TCDADDR_CITER_DOFF(RxTcdAddr, ((uint32)(FramesCount)<<16) | 1u );
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                LLM_Wr_DMA_TCDADDR_SADDR(RxTcdAddr, (uint32)(DspiDev->pDspiPOPRAddress)+3u);
                /* overwrite the default src next offset */
                /* 1 bytes src transfer size, 1 bytes dest transfer size */
                /* no src offset */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                REG_WRITE32((uint32)(RxTcdAddr) + DMA_TCD_TA_SOFF_OFFSET, (uint32)(0x00000000u));
                /* 1 bytes to transfer */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                REG_WRITE32((uint32)(RxTcdAddr) + DMA_TCD_SMLO_NBTYES_OFFSET, (uint32)(0x01u));
          }
        #else
          /* update RX transfer size; 2bytes offset for destination address */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
          LLM_Wr_DMA_TCDADDR_CITER_DOFF(RxTcdAddr, ((uint32)(FramesCount)<<16) | 2u );
        #endif
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_BITER(RxTcdAddr, (uint16)FramesCount);
    }

    /* configure or not scatter/gather related informations */
    if (CsClearNeeded)
    {
        /* if Cs clearing is needed, last dataframe will be transmited using
        a distinct TCD.
        */

        /* update transfer size, preserving linked channel information */
        FramesCount = (DspiDev->MinorELink | ((uint16)(FramesCount-1u)));
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_CITER(TxTcdAddr, (uint16)FramesCount);
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_BITER(TxTcdAddr, (uint16)FramesCount);

        /* flags are set by default to DMA_TCD_MAJOR_E_LINK | DMA_TCD_SGA */
        /* update S/G address with the address of the CS clearing TCD */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_DLAST_SGA(TxTcdAddr, (uint32)DspiDev->TxDmaTcdLast);
    }
    else
    {
        /* update transfer size, preserving linked channel information */
        FramesCount = (DspiDev->MinorELink | ((uint16)FramesCount));
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_CITER(TxTcdAddr, (uint16)FramesCount);
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_BITER(TxTcdAddr, (uint16)FramesCount);

        /* S/G address set by default to reload the default TX1 TCD */
        /* setup flags */
        /* reset DONE flag (quicker than LLM_Wr_DMA_CDNE()) */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_FLAGS(TxTcdAddr, 0u);
        LLM_Wr_DMA_TCDADDR_FLAGS(TxTcdAddr,
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
            (uint8)(DMA_TCD_DONE | DMA_TCD_MAJOR_E_LINK | DMA_TCD_DISABLE_REQ | SgaFlag));
    }

    /* start RX before TX! */
    HWUnitConfig = DspiDev->HWUnitConfig;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    Dma_start_channel(HWUnitConfig->RxDmaChannel);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    Dma_start_channel(HWUnitConfig->TxDmaChannel);
}
#endif /* SPI_DMA_USED == STD_ON */

/*================================================================================================*/
/**
* @brief   Restart the DMA transmission, refreshing the size.
* @details Source and destination addresses are already set into the active TCDs.
*
* @param[in]     DspiDev      Specifies which DSPI module is used
*
* @pre The function can be called only if Spi_LLD_JobTransferDmaStart() was
*      previously called to initialize the DMA configuration.
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_JobTransferDmaContinue(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev)
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) FramesCount;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_LLD_ChannelAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
      DspiChannelAttributesConfig =
        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig;
#endif

    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig;
    volatile P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) TxTcdAddr = DspiDev->TxDmaTcd;
    volatile P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) RxTcdAddr = DspiDev->RxDmaTcd;

    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 ==
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
           DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
        {
            FramesCount = DspiDev->RemainingData / 2u;
        }
        else
        {
            FramesCount = DspiDev->RemainingData;
        }
    #else
        FramesCount = DspiDev->RemainingData;
    #endif

    /* get the number of frames to be sent through DMA */
    if ( DMA_MAX_LINKED_ITER_CNT < FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        DspiDev->RemainingData = FramesCount - DMA_MAX_LINKED_ITER_CNT;
         #if (SPI_FORCE_DATA_TYPE == STD_ON)
            if(SPI_DATA_WIDTH_16 ==
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
               DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
            {
                 DspiDev->RemainingData *= 2u;
            }
        #endif
        FramesCount = DMA_MAX_LINKED_ITER_CNT;

        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        /* update RX transfer size */
        LLM_Wr_DMA_TCDADDR_CITER(RxTcdAddr, (uint16)FramesCount);
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_BITER(RxTcdAddr, (uint16)FramesCount);
    }
    else
    {

        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        /* update RX transfer size */
        LLM_Wr_DMA_TCDADDR_CITER(RxTcdAddr, (uint16)FramesCount);
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        LLM_Wr_DMA_TCDADDR_BITER(RxTcdAddr, (uint16)FramesCount);

        DspiDev->RemainingData = 0u;

        /* identify if CS clearing will be needed at the channel end */
        if ( 0u == DspiDev->RemainingChannels )
        {
            if (1u == FramesCount)
            {   /* clear the CS assertion directly into the next TX frame */
                DspiDev->TxDmaBuffer &= ~DSPI_CONT_MASK;
                /* set S/G address to reload the default TX1 descriptor,
                at the end
                */
                LLM_Wr_DMA_TCDADDR_DLAST_SGA(TxTcdAddr,
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                        * a pointer to a function and any type other than an integral type.
                        */
                        (uint32)DspiDev->TxDmaTcdDefault);
                /* reset DONE flag (quicker than LLM_Wr_DMA_CDNE()) */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                LLM_Wr_DMA_TCDADDR_FLAGS(TxTcdAddr, 0u);
                /* enable scatter/gather link and conserve the E_LINK setting;
                - DMA REQ must be disabled at the end of the current
                transfer, in order to stop the transfer before the reload of
                the default TCD
                */
                LLM_Wr_DMA_TCDADDR_FLAGS(TxTcdAddr,
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                    * a pointer to a function and any type other than an integral type.
                    */
                    DMA_TCD_MAJOR_E_LINK | DMA_TCD_SGA | DMA_TCD_DISABLE_REQ);
            }
            else
            {   /* last dataframe will be transmited using a distinct TCD. */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                LLM_Wr_DMA_TCDADDR_DLAST_SGA(TxTcdAddr,(uint32)DspiDev->TxDmaTcdLast);
                /* reset DONE flag (quicker than LLM_Wr_DMA_CDNE()) */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                LLM_Wr_DMA_TCDADDR_FLAGS(TxTcdAddr, 0u);
                /* enable scatter/gather link and conserve the E_LINK setting;
                - DMA REQ must not be disabled at the end of the current
                transfer, in order to allow the execution of the linked SG
                */
                LLM_Wr_DMA_TCDADDR_FLAGS(TxTcdAddr,
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed
                        * between a pointer to a function and any type other than an integral type.
                        */
                        DMA_TCD_MAJOR_E_LINK | DMA_TCD_SGA);
                FramesCount--;
            }
        }
    }

    /* update transfer size, preserving linked channel information */
    FramesCount = (DspiDev->MinorELink | ((uint16)FramesCount));
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    LLM_Wr_DMA_TCDADDR_CITER(TxTcdAddr, (uint16)FramesCount);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    LLM_Wr_DMA_TCDADDR_BITER(TxTcdAddr, (uint16)FramesCount);


    /* start RX before TX! */
    HWUnitConfig = DspiDev->HWUnitConfig;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    Dma_start_channel(HWUnitConfig->RxDmaChannel);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    Dma_start_channel(HWUnitConfig->TxDmaChannel);
}
#endif

/*================================================================================================*/
/**
* @brief   This function initializes channel related informations in DSPI HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel.
*
* @param[in]     DspiDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_ChannelTransferFifoInit(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev,
    VAR(Spi_ChannelType, AUTOMATIC) Channel)
{
    P2CONST(Spi_LLD_ChannelAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
        DspiChannelAttributesConfig;
    P2CONST(Spi_ChannelConfig, AUTOMATIC, SPI_APPL_CONST) pChannelConfig;
    P2VAR(Spi_ChannelState, AUTOMATIC, SPI_APPL_DATA) pChannelState;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pChannelConfig = &SpiConfigPtr->ChannelConfig[Channel];
    pChannelState = pChannelConfig->ChannelState;
    DspiDev->RemainingData = pChannelState->Length;
    DspiDev->ReceivedData = pChannelState->Length;


    /* identify the TX/RX buffers */
    if (0u != (pChannelState->Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT)))
    {
        DspiDev->CurrentTxBuffer = NULL_PTR;

        /* integrate default transmit value in the command */
        DspiDev->CurrentCmd |= pChannelConfig->DefaultTransmitValue;
    }
    else
    {
        DspiDev->CurrentTxBuffer = pChannelConfig->BufferDescriptor->
                    BufferTX;

        /* remove default transmit value from the command, if previously set */
        DspiDev->CurrentCmd &= DSPI_TX_CMD_MASK;
    }

    /* Rx buffer will be NULL if discarding read values */
    DspiDev->CurrentRxBuffer = pChannelConfig->BufferDescriptor->BufferRX;

    /* Set the CTAR parameters for this channel */
    DspiChannelAttributesConfig =
        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig;
    /*
    * @note False detection of MISRA 2004 Rule 11.4 violation.
    *       (cast from pointer to pointer)
    */
    /* set CTAR register */
    /**
    * @note The call is blocking till the HWUnit exits the running state.
    */
    REG_WRITE32(DspiDev->pDspiCTARAddress,
                (DspiDev->ExternalDeviceCTAR |
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
                *       to object type and a different pointer to object type.
                */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                DspiChannelAttributesConfig[Channel].CMD));
#if (SPI_SLAVE_SUPPORT == STD_ON)

    if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_SLAVE)
    {
        /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
        DSPI_LLM_ENABLE_RFDF(DspiDev->HWUnitConfig->Offset);
    }
#endif
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function fills the DSPI FIFO.
* @details This function fills DSPI FIFO Transmit buffer with the
*          predefined data assigned or transmit the default
*          buffer values in case of the lack of transmit
*          data buffer.
*
* @param[in]     DspiDev     Specifies which DSPI module is used
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_JobTransferFifoFill(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev)
{
    VAR(uint32, AUTOMATIC) Cmd;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) pBufferTX;
    VAR(Spi_NumberOfDataType, AUTOMATIC) nFramesCount;
    VAR(sint32, AUTOMATIC) bEndOfJob = FALSE; /* end of job */
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_LLD_ChannelAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
        DspiChannelAttributesConfig =
        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig;
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pBufferFullTX;
#endif
    /* Get physical device handler */
    volatile P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) pDspiPUSHRAddress =
        DspiDev->pDspiPUSHRAddress;

    /* Get Channel Attributes */
    Cmd = DspiDev->CurrentCmd;

    /* calculate the number of frames to be sent and the 'end of job' state */
    nFramesCount = DspiDev->RemainingData;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 ==
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
           DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
        {
            nFramesCount/=2u;
        }
    #endif
    /* TX_FIFO_SIZE =4 */
    if (nFramesCount > SPI_FIFO_SIZE)
    {
        if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_MASTER)
        {
        nFramesCount = SPI_FIFO_SIZE;
        }
#if (SPI_SLAVE_SUPPORT == STD_ON)

        if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_SLAVE)
        {
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
            nFramesCount = (Spi_NumberOfDataType)(SPI_FIFO_SIZE - DSPI_LLM_READ_TXCTR_VAL(DspiDev->HWUnitConfig->Offset));
        }
#endif
        bEndOfJob = FALSE; /* end of job not reached */
    }
    else
    {
        /* end of job reached if this is the last channel in the job */
        if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_SLAVE)
        {
            /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
            if(nFramesCount > (SPI_FIFO_SIZE - DSPI_LLM_READ_TXCTR_VAL(DspiDev->HWUnitConfig->Offset)))
            {
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
                nFramesCount = (Spi_NumberOfDataType)(SPI_FIFO_SIZE - DSPI_LLM_READ_TXCTR_VAL(DspiDev->HWUnitConfig->Offset));
            }
        }
        else
        {
        bEndOfJob = (sint32)(0u == DspiDev->RemainingChannels);
        }
    }

    pBufferTX = DspiDev->CurrentTxBuffer;
    DspiDev->RemainingData -= nFramesCount;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 ==
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
       DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
    {
        DspiDev->RemainingData -= nFramesCount;
    }
    #endif
    DspiDev->SentFrames = nFramesCount;

    if (NULL_PTR != pBufferTX)
    {
        /* set the new TX buffer pointer */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        DspiDev->CurrentTxBuffer += nFramesCount;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 ==
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
           DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
        {
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            DspiDev->CurrentTxBuffer += nFramesCount;
        }
        #endif
        /* write the information from the buffer */
        while (nFramesCount > 0u)
        {
            nFramesCount--;

            if (0u == nFramesCount)
            {
                Cmd |= DSPI_EOQ_MASK;    /* EOQ bit in PUSHR */
                /* Force the CS disabling if last data unit
                for the last channel of the Job */
                if (bEndOfJob)
                {
                    /* signal the end of job for the current DSPI Unit */
                    DspiDev->IsEndOfJob = (boolean)TRUE;
                    Cmd = Cmd & ~DSPI_CONT_MASK; /* clear the continous CS assertion */
                }
            }

            #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if( SPI_DATA_WIDTH_16 ==
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                   DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
                {
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a
                    * pointer to object type and a different pointer to object type.
                    */
                    pBufferFullTX = (uint16 *) pBufferTX;
                    /*
                    * @note False detection of MISRA 2004 Rule 11.4 violation.
                    *       (cast from pointer to pointer)
                    */
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a
                    *  pointer to object type and a different pointer to object type.
                    */
                    REG_WRITE32(pDspiPUSHRAddress, (Cmd | *pBufferFullTX));
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferTX++;
                }
                else
                {
                    /*
                    * @note False detection of MISRA 2004 Rule 11.4 violation.
                    *       (cast from pointer to pointer)
                    */
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a
                    *   pointer to object type and a different pointer to object type.
                    */
                    REG_WRITE32(pDspiPUSHRAddress, (Cmd | *pBufferTX));
                }
            #else
                /*
                * @note False detection of MISRA 2004 Rule 11.4 violation.
                *       (cast from pointer to pointer)
                */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a
                * pointer to object type and a different pointer to object type.
                */
                REG_WRITE32(pDspiPUSHRAddress, (Cmd | *pBufferTX));
             #endif
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pBufferTX++;
        }

    }
    else
    {   /* write the default value */
        while (nFramesCount > 0u)
        {
            nFramesCount--;

            if (0u == nFramesCount)
            {
                Cmd |= DSPI_EOQ_MASK;    /* EOQ bit in PUSHR */
                /* Force the CS disabling if last data unit
                for the last channel of the Job */
                if (bEndOfJob)
                {
                    /* signal the end of job for the current DSPI Unit */
                    DspiDev->IsEndOfJob = (boolean)TRUE;
                    Cmd = Cmd & ~DSPI_CONT_MASK; /* clear the continous CS assertion */
                }
            }

            /*
            * @note False detection of MISRA 2004 Rule 11.4 violation.
            *       (cast from pointer to pointer)
            */
            /* default transmit value already integrated in DspiDev->CurrentCmd */
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
            *       to object type and a different pointer to object type.
            */
            REG_WRITE32(pDspiPUSHRAddress, Cmd);
        }
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function drains the DSPI FIFO.
* @details This function retrieves the received data from DSPI FIFO.
*
* @param[in]     DspiDev     Specifies which DSPI module is used.
*
* @implements DSPI02825.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC (void, SPI_CODE) Spi_LLD_JobTransferFifoDrain(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev)
{
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) pBufferRx;

    VAR(Spi_NumberOfDataType, AUTOMATIC) nFramesCount = 0U;
    volatile P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) pDspiPOPRAddress =
        DspiDev->pDspiPOPRAddress;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_LLD_ChannelAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
        DspiChannelAttributesConfig =
        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig;
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pBufferFullRX;
#endif
#if (SPI_SLAVE_SUPPORT == STD_ON)

if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_SLAVE)
{
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
    nFramesCount = (Spi_NumberOfDataType)(DSPI_LLM_READ_RXCTR_VAL(DspiDev->HWUnitConfig->Offset));
    DspiDev->ReceivedData -= nFramesCount;
}

#endif
if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_MASTER)
{
    nFramesCount = DspiDev->SentFrames;
}

    pBufferRx = DspiDev->CurrentRxBuffer;

    if (NULL_PTR != pBufferRx)
    {
        /* set the new RX buffer pointer */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        DspiDev->CurrentRxBuffer += nFramesCount;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            if(SPI_DATA_WIDTH_16 ==
              /*
              * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
              *       the only allowed form of pointer arithmetic.
              */
              DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
            {
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                DspiDev->CurrentRxBuffer += nFramesCount;
            }
        #endif
        /* read the deserialized information */
        do
        {

            #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if(SPI_DATA_WIDTH_16 ==
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                   DspiChannelAttributesConfig[*(DspiDev->CurrentChannelIndexPointer)].DataWidth)
                {
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a
                    * pointer to object type and a different pointer to object type.
                    */
                    pBufferFullRX = (uint16 *) pBufferRx;
                    /*
                    * @note False detection of MISRA 2004 Rule 11.4 violation.
                    *       (cast from pointer to pointer)
                    */
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a
                    * pointer to object type and a different pointer to object type.
                    */
                    *pBufferFullRX = (uint16)REG_READ32(pDspiPOPRAddress);
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferRx += 2u;
                }
                else
                {
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a
                    *  pointer to object type and a different pointer to object type.
                    */
                    *pBufferRx = (Spi_DataType)REG_READ32(pDspiPOPRAddress);
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferRx++;
                }
            #else
               /*
               * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
               *       to object type and a different pointer to object type.
               */
                *pBufferRx = (Spi_DataType)REG_READ32(pDspiPOPRAddress);
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                pBufferRx++;
            #endif
            nFramesCount--;

        } while ( 0u != nFramesCount);  /* TX_FIFO_SIZE =4 */
        /* update current RX buffer pointer */
        DspiDev->CurrentRxBuffer = pBufferRx;
#if (SPI_SLAVE_SUPPORT == STD_ON)

        if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_SLAVE)
        {
            if(DspiDev->ReceivedData == (Spi_NumberOfDataType)0)
            {
                DspiDev->IsEndOfJob = (boolean)TRUE;

            }

        }
#endif
    }
    else
    {   /* discard the information read */
        do
        {
            /*
            * @note False detection of MISRA 2004 Rule 11.4 violation.
            *       (cast from pointer to pointer)
            */
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
            *       to object type and a different pointer to object type.
            */
            DspiReadDiscard = REG_READ32(pDspiPOPRAddress);
            nFramesCount--;
        } while ( 0u != nFramesCount);
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Computes sequence / job configuration parameters like
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          This cached values will be used in sync transmissions in
*          order to optimize the time.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall not be LEVEL1.
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON.
*
* @implements DSPI02817.
*/
/*================================================================================================*/
FUNC (void, SPI_CODE) Spi_LLD_PrepareCacheInformation(void)
{
    VAR(Spi_ChannelType, AUTOMATIC) Channel, ChannelId;
    VAR(Spi_JobType, AUTOMATIC) Job;
    VAR(Spi_SequenceType, AUTOMATIC) Sequence;
    P2VAR(Spi_ChannelCacheAttrs, AUTOMATIC, SPI_APPL_DATA) pChannelAttrs;
    P2VAR(Spi_SequenceCacheAttrs, AUTOMATIC, SPI_APPL_DATA) pSeqAttrs;
    P2CONST(Spi_LLD_DeviceAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
        pDeviceAttributesConfig;
    P2CONST(Spi_ChannelConfig, AUTOMATIC, SPI_APPL_CONST) pChannelConfig;
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig;
    P2CONST(Spi_SequenceConfig, AUTOMATIC, SPI_APPL_CONST) pSequenceConfig;

    /* index to the first free entry in 'DspiSeqsAttributes' table. */
    VAR(Spi_SequenceType, AUTOMATIC) SeqsAttrCurrentIndex = 0u;

    /* index to the first free entry in 'DspiChannelsAttributes' table. */
    VAR(Spi_ChannelType, AUTOMATIC) ChannelsAttrCurrentIndex = 0u;


    /* reset all sequences as not optimized */
    for (Sequence = 0u;
        Sequence < SpiConfigPtr->Spi_Max_Sequence;
        Sequence++)
    {
        DspiOneJobSeqsOptimized[Sequence] = NULL_PTR;
    }

    for (Sequence = 0u;
        Sequence < SpiConfigPtr->Spi_Max_Sequence;
        Sequence++)
    {
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pSequenceConfig = &SpiConfigPtr->SequenceConfig[Sequence];
        /* only one job sequences can be optimized */
        if (1u == pSequenceConfig->NumJobs)
        {
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            Job = pSequenceConfig->JobIndexList[0];
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pJobConfig = &SpiConfigPtr->JobConfig[Job];
            /* check if enough place in the cached data channel pool */
            if (pJobConfig->NumChannels <=
                (SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE-ChannelsAttrCurrentIndex) )
            {
                /* get the first empty entry in the sequence pool and
                link it to the sequence */
                pSeqAttrs = &DspiSeqsAttributes[SeqsAttrCurrentIndex];
                DspiOneJobSeqsOptimized[Sequence] = pSeqAttrs;

                /* retrieve the device configuration for the sequence */
                pDeviceAttributesConfig =
                    &SpiConfigPtr->AttributesConfig->DeviceAttributesConfig
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        [SpiConfigPtr->JobConfig[Job].ExternalDevice];

                /* prepare sequence cache information */
                pSeqAttrs->NumChannels = pJobConfig->NumChannels;
                pSeqAttrs->JobState = &SpiJobState[Job];
                pSeqAttrs->DspiBaseAddress =
                    DspiDeviceState[pJobConfig->HWUnit].DspiBaseAddress;
                pSeqAttrs->JobDspiStatus =
                    DspiDeviceState[pJobConfig->HWUnit].pStatus;
                pSeqAttrs->JobCMD =
                    /* @violates @ref Spi_Dspi_LLD_c_REF_12 Violates MISRA 2004 Required Rule 10.5, Shift left of signed quantity(int) */
                    pDeviceAttributesConfig->CMD | DSPI_CMD_CTAR_SEL;

                /* set the link to the first cached channel entry */
                pSeqAttrs->pChannels =
                    &DspiChannelsAttributes[ChannelsAttrCurrentIndex];

                /* prepare channel cache information */
                for (Channel = 0u;
                    Channel < pJobConfig->NumChannels;
                    Channel++)
                {
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    ChannelId = pJobConfig->ChannelIndexList[Channel];
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pChannelConfig = &SpiConfigPtr->ChannelConfig[ChannelId];
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pChannelAttrs = &pSeqAttrs->pChannels[Channel];

                    pChannelAttrs->DefaultTransmitValue =
                        pChannelConfig->DefaultTransmitValue;
                    pChannelAttrs->State = pChannelConfig->ChannelState;
                    pChannelAttrs->BufferDescriptor =
                        pChannelConfig->BufferDescriptor;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
                    pChannelAttrs->CTAR[0] =
                        SpiConfigPtr->AttributesConfig->DeviceAttributesConfig
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                            [pJobConfig->ExternalDevice].CTAR[0]
                        |
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig[ChannelId].CMD;
                    pChannelAttrs->CTAR[1] =
                        SpiConfigPtr->AttributesConfig->DeviceAttributesConfig
                         /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                            [pJobConfig->ExternalDevice].CTAR[1]
                        |
                        /*
                        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig[ChannelId].CMD;
#else
                    pChannelAttrs->CTAR =
                        SpiConfigPtr->AttributesConfig->DeviceAttributesConfig
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            [pJobConfig->ExternalDevice].CTAR
                        |
                        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            [ChannelId].CMD;
#endif
#if (SPI_FORCE_DATA_TYPE == STD_ON)
                    pChannelAttrs->DataWidth =
                        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            [ChannelId].DataWidth;
#endif
                } /* for (channels) */

                /* set the pool indexes to the new empty entries */
                SeqsAttrCurrentIndex++;
                ChannelsAttrCurrentIndex += pJobConfig->NumChannels;

                /* end the loop if caches are full */
                if ((SeqsAttrCurrentIndex >=
                        SPI_OPTIMIZED_SEQ_BUFFER_SIZE)
                    ||
                    (ChannelsAttrCurrentIndex >=
                        SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE)
                )
                {
                    break;
                }
            }
        }
    } /* for (sequences) */
}
#endif /* (SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Initialize the specific Spi unit with all configuration
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          Also this function initializes all structure parameters
*          from the specific DSPI unit.
*
* @param[in]      HWUnit      Specifies which DSPI peripheral is used
* @param[in]      pStatus     pointer to the Autosar SPI HWUnit State
*
* @implements DSPI02811.
*/
/*================================================================================================*/
FUNC (void, SPI_CODE) Spi_LLD_Init(
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
    P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus)
{
    P2CONST(Spi_LLD_DeviceAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
        DspiDeviceAttributesConfig;
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev;
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig;
    VAR(Spi_JobType, AUTOMATIC) Job;
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) JobConfig;
    VAR(uint32, AUTOMATIC) MCR1;

    VAR(uint8, AUTOMATIC) HWoffset;

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /* Clock mode */
    Dspi_ClockMode = SPI_NORMAL;
#endif

    /* External device attributes */
    DspiDeviceAttributesConfig =
        SpiConfigPtr->AttributesConfig->DeviceAttributesConfig;

    /* Get physical device instances and link them */
    DspiDev = &DspiDeviceState[HWUnit];
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
        */
    HWUnitConfig = &SpiConfigPtr->HWUnitConfig[HWUnit];
    DspiDev->HWUnitConfig = HWUnitConfig;
    DspiDev->pStatus = pStatus;

    /* Peripheral Registers */
    HWoffset = HWUnitConfig->Offset;
    /* cache frequently used DSPI adresses in order to have a quicker access */
    DspiDev->DspiBaseAddress = DSPI_GET_BASE_ADDRESS(HWoffset);
    DspiDev->pDspiPUSHRAddress =
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))(DSPI_PUSHR(HWoffset));
    DspiDev->pDspiPOPRAddress =
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))(DSPI_POPR(HWoffset));
    DspiDev->pDspiSRAddress =
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))(DSPI_SR(HWoffset));

#if (SPI_SLAVE_SUPPORT == STD_ON)

    if (HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_SLAVE)
    {
        DspiDev->pDspiCTARAddress =
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
            (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))(DSPI_CTAR0(HWoffset));

        /* Determine chip select inactive states for each PCS */
        MCR1 = (DSPI_MCR_PCSIS_ALL);   /* high by default */
    }
    else
    {
#endif
                DspiDev->pDspiCTARAddress =
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                    * a pointer to a function and any type other than an integral type.
                    */
                    (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))(DSPI_CTAR(HWoffset));

                /* Determine chip select inactive states for each PCS */
                MCR1 = (DSPI_MCR_MSTR | DSPI_MCR_PCSIS_ALL);   /* high by default */
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif
    for (Job = (Spi_JobType) 0;
        Job < (Spi_JobType) SpiConfigPtr->Spi_Max_Job; Job++)
    {
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        JobConfig = &SpiConfigPtr->JobConfig[Job];
        if (JobConfig->HWUnit == HWUnit)
        {
            MCR1 = (uint32)(MCR1 & (
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    ~DspiDeviceAttributesConfig[JobConfig->ExternalDevice].MCR)
                );
        }
    }

    /* SPI works as a Master and CS configured with inactive
    state as appropriate */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_MCR_CONFIG(HWoffset, MCR1);

#if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) )
#if (SPI_DMA_USED == STD_ON)
    if (HWUnitConfig->UseDma)
    {
        DSPI_LLM_WRITE_RSER_REG(HWoffset,
            (DSPI_TFFF_RE_MASK | DSPI_TFFF_DIRS_MASK |
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
            DSPI_RFDF_RE_MASK | DSPI_RFDF_DIRS_MASK));

        /* initialize DMA TCDs */
        Spi_LLD_InitDma(HWUnit, DspiDev);
    }
#endif /* (SPI_DMA_USED == STD_ON) */
#endif

}

/*================================================================================================*/
/**
* @brief   IRQ configure functions.
* @details Activate/deactivate EOQ interrupts for async HWUnit according to
*          the driver operation mode (polling or interrupt).
*
* @param[in]     HWUnit      Specifies which DSPI peripheral is used
* @param[in]     AsyncMode   Specifies the operation mode
*                             (SPI_INTERRUPT_MODE | SPI_POLLING_MODE)
*
* @implements DSPI02812.
*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*================================================================================================*/
/*
* @violates @ref Spi_Dspi_LLD_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_LLD_IrqConfig(
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode)
{
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev =
        &DspiDeviceState[HWUnit];
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig =
        DspiDev->HWUnitConfig;
    VAR(uint8, AUTOMATIC) HWoffset = HWUnitConfig->Offset;

    /* set the async mode for the HWUnit */
    DspiDev-> AsyncMode = AsyncMode;

    /* activate/deactivate EOQ interrupts for Async HWUnits */
    if (SPI_PHYUNIT_ASYNC == HWUnitConfig->IsSync)
    {
#if (SPI_DMA_USED == STD_ON)
        if (HWUnitConfig->UseDma)
        {
            Spi_LLD_DmaIrqConfig(DspiDev, AsyncMode);
        }
        else
#endif /* SPI_DMA_USED == STD_ON */

        if (SPI_INTERRUPT_MODE == AsyncMode)
        {
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            DSPI_LLM_ENABLE_EOQF(HWoffset);
        }
        else
        {
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            DSPI_LLM_DISABLE_EOQF(HWoffset);
        }
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/*================================================================================================*/
/**
* @brief   IRQ polling functions.
* @details Configures DMA unit to detect received data via
*          interrupt or by polling a bit in the RSER register.
*
* @param[in]     DspiDev     Specifies which DSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
* @implements DSPI02826.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_LLD_IrqPoll(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev)
{
#if (SPI_DMA_USED == STD_ON)
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig =
        DspiDev->HWUnitConfig;
#endif

#if (SPI_DMA_USED == STD_ON)
    if (HWUnitConfig->UseDma)
    {
        /* Get status from TCD[7] register */
        /* Emulate IRQ */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        *
        */
        if (0u != (LLM_Rd_DMA_TCDADDR_FLAGS(DspiDev->RxDmaTcd) & DMA_TCD_DONE))
        {
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            */
            LLM_Wr_DMA_CDNE(HWUnitConfig->RxDmaChannel);
            Spi_LLD_IsrDmaRx(DspiDev);
        }
    }
    else
#endif /* (SPI_DMA_USED == STD_ON) */
    {
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
        *       to object type and a different pointer to object type.
        */
        if (0u != (REG_READ32(DspiDev->pDspiSRAddress) & DSPI_EOQF_STS_MASK))
        {
            /* Emulate IRQ in PIO_FIFO mode */
            Spi_LLD_IsrFifoRx(DspiDev);
        }
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function performs the de-initialization of a specific peripheral unit.
* @details This function de-initializes all configured values
*          in the MCR register and CTAR registers.
*
* @param[in]     HWUnit      Specifies which DSPI peripheral is used
*
* @implements DSPI02810.
*/
/*================================================================================================*/
FUNC (void, SPI_CODE) Spi_LLD_DeInit(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit)
{
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_CONST) HWUnitConfig;
    VAR(uint8, AUTOMATIC) HWoffset;

    /* Get physical device handler */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */    
    HWUnitConfig = &SpiConfigPtr->HWUnitConfig[HWUnit];

    /* Pointer to peripheral registers */
    HWoffset = HWUnitConfig->Offset;
    
    /* Reset the DSPI Regs and Read until the RXCTR becomes zero*/    
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    while(DSPI_LLM_READ_RXCTR_VAL(HWoffset))
    {
    /* Compiler_Warning : By Reading the DSPI_POPR register, It's draining the RX FIFO */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
        DSPI_LLM_RXDATA(HWoffset);
    }
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */   
    DSPI_LLM_RESET_STATUS_REG(HWoffset);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_MCR_RESET(HWoffset);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    DSPI_LLM_RESET_RSER_REG(HWoffset);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    DSPI_LLM_RESET_CTAR_REG(HWoffset);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    /*DSPI_LLM_RESET_FIFO_TX_REG(HWoffset);*/
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    DSPI_LLM_RESET_TCR(HWoffset);
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
}

/*================================================================================================*/
/**
* @brief   This function is called by EOQ ISRs for the DSPI units working in PIO_FIFO mode.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the DSPI
*          peripherals.
*
* @param[in]     DspiDev     Specifies which DSPI peripheral is used
*
* @implements DSPI02815
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_LLD_IsrFifoRx(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev)
{
    VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode = DspiDev->AsyncMode;
    VAR(uint32, AUTOMATIC) Status_isr;

    if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_MASTER)
    {        
    if (SPI_POLLING_MODE != AsyncMode)
    {
        /*Not in pooling mode: read status register and interrupts enabled register */
            /*
                         * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be
                         * performed between a pointer
                         *       to object type and a different pointer to object type.
                         */
            Status_isr = REG_READ32(DspiDev->pDspiSRAddress) & DSPI_EOQF_STS_MASK;
      /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
            Status_isr &= REG_READ32(DSPI_RSER(DspiDev->HWUnitConfig->Offset)) & DSPI_EOQF_RE_MASK;
        }
        else
        {
            /* Operation mode is SPI_POLLING_MODE: set Status_isr to 1*/
            Status_isr = 1u;
        }
    }
    else
    {
        if (SPI_POLLING_MODE != AsyncMode)
        {
            /*Not in pooling mode: read status register and interrupts enabled register */
            /*
                         * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be
                         * performed between a pointer
                         *       to object type and a different pointer to object type.
                         */
            Status_isr = REG_READ32(DspiDev->pDspiSRAddress) & DSPI_RFDF_STS_MASK;
      /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
            Status_isr &= REG_READ32(DSPI_RSER(DspiDev->HWUnitConfig->Offset)) & DSPI_RFDF_STS_MASK;
        }
        else
        {
            /* Operation mode is SPI_POLLING_MODE: set Status_isr to 1*/
            Status_isr = 1u;
        }
    }

    /* check if any enabled isr had been triggered */
    if (0u != Status_isr)
    {
    /* clear EOQ Flag, in order to unlock next TX transmission */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
    REG_WRITE32(DspiDev->pDspiSRAddress, DSPI_EOQF_STS_MASK);

    /* Copy data from DSPI FIFOD to channels */
    Spi_LLD_JobTransferFifoDrain(DspiDev);

#if (SPI_SLAVE_SUPPORT == STD_ON)

    if(DspiDev->HWUnitConfig->SpiPhyUnitMode == (uint8)SPI_SLAVE)
    {
        /*
    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
        REG_BIT_SET32(DspiDev->pDspiSRAddress, DSPI_RFDF_STS_MASK);
    }
#endif
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_7 The operands of logical operators
    * (&&, || and !) should be effectively Boolean.
    */
    if (!DspiDev->IsEndOfJob)
    {
        /* check for the channel switch */
        if ( 0u == DspiDev->RemainingData )
        {
            /* reached the end of channel => move to the next channel */
            /* Increase Channel indexes */
            DspiDev->RemainingChannels--;
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            DspiDev->CurrentChannelIndexPointer++;
            
            if(DspiDev->HWUnitConfig->SpiPhyUnitMode ==(uint8)SPI_MASTER)
            {
                    /* prepare next channel transmission */
                    Spi_LLD_ChannelTransferFifoInit(DspiDev,
                        *(DspiDev->CurrentChannelIndexPointer));
            }
        }

        /* perform the next chunk transmission */
        Spi_LLD_JobTransferFifoFill(DspiDev);
    }
    else
    {
        /* finish job transfer */
        Spi_JobTransferFinished(DspiDev->CurrentJob);
    }
    }

}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function is called by DMA ISR for Rx DMA channels.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the DSPI
*          peripherals
*
* @param[in]     DspiDev     Specifies which DSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*       and SPI_DMA_USED must be STD_ON
*
* @implements DSPI02814.
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC (void, SPI_CODE) Spi_LLD_IsrDmaRx(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev)
{
    VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode = DspiDev->AsyncMode;
    VAR(uint8, AUTOMATIC) dmaChannel = DspiDev->HWUnitConfig->RxDmaChannel;
    VAR(uint32, AUTOMATIC) Status_isr = 0u;
    VAR(uint32, AUTOMATIC) Enabled_isr = 0u;
    
    if (SPI_POLLING_MODE != AsyncMode)
    {
     /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */   
        Enabled_isr = (uint32)(DMA_TCD_SR(dmaChannel) & DMA_TCD_INT_MAJOR);

        /* Check that the interrupt was enabled for the corresponding DMA channel */
        if ((uint32)DMA_TCD_INT_MAJOR == Enabled_isr )
        {
            /* Get the interrupt request for the corresponding DMA channel */
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */ 
            Status_isr = LLM_Get_DMA_INTERRUPT_STATUS(dmaChannel);
        }
    }
    else
    {
        /* Operation mode is SPI_POLLING_MODE: set Status_isr to 1*/
        Status_isr = 1u;
    }

    /* Check if isr was enabled on the corresponding channel and interrupt request was set */
    if (0u != Status_isr)
    {
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /* reset DMA channel interrupt flag (IRQ ACK) */
        Dma_ack_interrupt(dmaChannel);

    if ( 0u != DspiDev->RemainingData )
    {
        /* Channel not finished => update RX/TX pointers */
        Spi_LLD_JobTransferDmaContinue(DspiDev);
    }
    else
    {
        /* reached the end of channel => move to the next channel */
        if (0u != DspiDev->RemainingChannels)
        {
            /* Increase Channel indexes */
            DspiDev->RemainingChannels--;
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            DspiDev->CurrentChannelIndexPointer++;

            /* prepare next channel transmission */
            Spi_LLD_ChannelTransferDmaInit(DspiDev,
                *(DspiDev->CurrentChannelIndexPointer));
        }
        else
        {
            /* finish job transfer */
            Spi_JobTransferFinished(DspiDev->CurrentJob);
        }
    }
    }
}
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*================================================================================================*/
/**
* @brief   This function sets the Job's attributes and send all the data through the SPI bus.
* @details This function is in charge to setup the Job attribute,
*          and to send all data though the SPI Bus.
*
* @param[in]     pJobConfig    Specifies the Job for which we will set the
*                            register values
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
* @implements DSPI02816.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_LLD_JobTransfer(
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig)
{
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) pDspiDev =
        &DspiDeviceState[pJobConfig->HWUnit];
    P2CONST(Spi_ChannelType, AUTOMATIC, SPI_APPL_CONST) pChannelList =
            pJobConfig->ChannelIndexList;

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    pDspiDev->ExternalDeviceCTAR = pJobConfig->ExternalDeviceAttrs.CTAR[Dspi_ClockMode];
#else
    pDspiDev->ExternalDeviceCTAR = pJobConfig->ExternalDeviceAttrs.CTAR;
#endif

    /* setup job specific ctar and cmd */
    /* @violates @ref Spi_Dspi_LLD_c_REF_12 Violates MISRA 2004 Required Rule 10.5, Shift left of signed quantity(int) */
    pDspiDev->CurrentCmd = (pJobConfig->ExternalDeviceAttrs.CMD | DSPI_CMD_CTAR_SEL);

    /* initialize starting channel index */
    pDspiDev->CurrentChannelIndexPointer = pChannelList;
    pDspiDev->RemainingChannels = pJobConfig->NumChannels - (Spi_ChannelType) 1u;

    /* memorize the current job */
    pDspiDev->CurrentJob = pJobConfig;

#if (SPI_DMA_USED == STD_ON)
    if (pDspiDev->HWUnitConfig->UseDma)
    {
        /* initialize the transfer parameters for the first channel */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        Spi_LLD_ChannelTransferDmaInit(pDspiDev, pChannelList[0]);
    }
    else
#endif /* (SPI_DMA_USED == STD_ON) */
    {
        pDspiDev->IsEndOfJob = (boolean)FALSE;

        /* initialize the transfer parameters for the first channel */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        Spi_LLD_ChannelTransferFifoInit(pDspiDev, pChannelList[0]);
        Spi_LLD_JobTransferFifoFill(pDspiDev);
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function starts the synchronous transmission for optimized sequences having only one job.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*          Same behavior as Spi_SyncTransmit(), but the initialization time and
*          data preparation time are optimized.
*
* @param[in]     pSequence     Keep the cached information for "one job sequence"
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON
*
* @implements DSPI02819, DSPI01383.
*/
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
FUNC (Std_ReturnType, SPI_CODE) Spi_LLD_SyncTransmit_Fast(
    P2CONST(Spi_SequenceCacheAttrs, AUTOMATIC, SPI_APPL_CONST) pSequence)
{
    P2VAR(Spi_ChannelCacheAttrs, AUTOMATIC, SPI_APPL_DATA) pChannel;
    VAR(Spi_ChannelType, AUTOMATIC) ChannelsCount;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) pBufferTX;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) pBufferRX;
    P2VAR(Spi_JobState, AUTOMATIC, SPI_APPL_DATA) pJobState = pSequence->JobState;
    VAR(uint32, AUTOMATIC) Timeout = SPI_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC) tempXferData;
    VAR(Std_ReturnType, AUTOMATIC) Status;
    VAR(uint32, AUTOMATIC) DspiBaseAddress;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthTX;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthRX;
    VAR(uint32, AUTOMATIC) nEmptyPlaces;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pBufferFullTX;
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pBufferFullRX;
#endif
    /* retrieve the DSPI offset */
    DspiBaseAddress = pSequence->DspiBaseAddress;


    /* set the CMD part of the word to be transmitted */
    tempXferData = pSequence->JobCMD;

    /* Set the job status as pending and mark HW Unit as busy */
    pJobState->Result = SPI_JOB_PENDING;
    *(pSequence->JobDspiStatus) = SPI_BUSY;

    /* iterate on all channels in job */
    pChannel = pSequence->pChannels;
    ChannelsCount = pSequence->NumChannels;
    while (ChannelsCount > (Spi_ChannelType)0)
    {
        ChannelsCount--;

        /* set CTAR register */
        /**
        * @note The call is blocking till the HWUnit exits
        *       the running state.
        */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(DSPI_BASEADDR2CTAR(DspiBaseAddress), pChannel->CTAR[Dspi_ClockMode]);
#else
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        REG_WRITE32(DSPI_BASEADDR2CTAR(DspiBaseAddress), pChannel->CTAR);
#endif

        /* retrieve RX/TX buffers and the transmitted/received lengths */
        if (pChannel->State->Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT))
        {
            pBufferTX = NULL_PTR;
        }
        else
        {
            pBufferTX = pChannel->BufferDescriptor->BufferTX;
        }
        pBufferRX = pChannel->BufferDescriptor->BufferRX;

        LengthTX = pChannel->State->Length;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == pChannel->DataWidth)
        {
            LengthTX /= 2u;
        }
    #endif
        LengthRX = LengthTX;

        Timeout = SPI_TIMEOUT_COUNTER;
        nEmptyPlaces = SPI_FIFO_SIZE;

        /* while there is still something to read or to write */
        /* a kind of: while ((LengthTX > 0) || (LengthRX > 0)) */
        while ((LengthTX | LengthRX) > 0u)
        {
            VAR(uint32, AUTOMATIC) StatusReset = 0u;

            /* --------- Transmit ---------- */
            /* there is something to write and Transmit FIFO not full */
            if ((LengthTX > 0u) && (nEmptyPlaces > 0u))
            {
                LengthTX--;
                nEmptyPlaces--;

                /* reset the timeout */
                Timeout = SPI_TIMEOUT_COUNTER;

                /* prepare the data to be transmitted */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_7 The operands of logical operators
                * (&&, || and !) should be effectively Boolean.
                */
                if (!pBufferTX)
                {
                    /*
                    * @implements DSPI02476.
                    */
                    /* Get default data if TX buffer is NULL_PTR */
                    tempXferData =
                        (tempXferData & DSPI_TX_CMD_MASK) |
                        pChannel->DefaultTransmitValue;
                }
                else
                {
                    /* Read transmit data */
                    #if (SPI_FORCE_DATA_TYPE == STD_ON)
                        if (SPI_DATA_WIDTH_16 == pChannel->DataWidth)
                        {
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed between a pointer
                            *       to object type and a different pointer to object type.
                            */
                            pBufferFullTX = (uint16 *) pBufferTX;
                            tempXferData =
                            (tempXferData & DSPI_TX_CMD_MASK) | (*pBufferFullTX);
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            pBufferTX++;
                        }
                        else
                        {
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
                            *     type and an integral type.
                            */
                            tempXferData =
                                (tempXferData & DSPI_TX_CMD_MASK) | (*pBufferTX);
                        }
                    #else
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
                            *     type and an integral type.
                            */
                            tempXferData =
                            (tempXferData & DSPI_TX_CMD_MASK) | (*pBufferTX);
                    #endif
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            pBufferTX++;
                }

                /* For the last frame, clear the continous CS assertion */
                /* a kind of: if ((0u == LengthTX) && (0u == ChannelsCount) )*/
                if (0u == (LengthTX | ChannelsCount))
                {
                    tempXferData = tempXferData & ~DSPI_CONT_MASK;
                }

                /* Transmit the data */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                REG_WRITE32(DSPI_BASEADDR2PUSHR(DspiBaseAddress), tempXferData);

                /* Transmit FIFO Fill Flag must be reset */
                StatusReset |= DSPI_TFFF_STS_MASK;
            }

            /* --------- Receive ---------- */
            /* there is still something to read and Receive FIFO has data */
            if (LengthRX > 0u)
            {
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                if (0u != ((REG_READ32(DSPI_BASEADDR2SR(DspiBaseAddress))) & DSPI_RFDF_STS_MASK)
                    )
                {
                    LengthRX--;
                    nEmptyPlaces++;

                    /* reset the timeout */
                    Timeout = SPI_TIMEOUT_COUNTER;

                    /* Read Data from RX FIFO */
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_7 The operands of logical operators
                    * (&&, || and !) should be effectively Boolean.
                    */
                    if (!pBufferRX)
                    {
                        /*
                        * @implements DSPI02476
                        */
                        /* discard data if RX buffer is NULL_PTR */
                        DspiReadDiscard = REG_READ32(
                                        /*
                                        * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not
                                        * be performed between
                                        * a pointer to a function and any type other than an integral type.
                                        */
                                        DSPI_BASEADDR2POPR(DspiBaseAddress));
                    }
                    else
                    {
                        #if (SPI_FORCE_DATA_TYPE == STD_ON)
                                if (SPI_DATA_WIDTH_16 == pChannel->DataWidth)
                                {
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be
                                    * performed between a pointer
                                    *       to object type and a different pointer to object type.
                                    */
                                    pBufferFullRX = (uint16 *) pBufferRX;
                                    *pBufferFullRX = (uint16)REG_READ32(
                                            /*
                                            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall
                                            * not be performed between
                                            * a pointer to a function and any type other than an
                                            * integral type.
                                            */
                                            DSPI_BASEADDR2POPR(DspiBaseAddress));

                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                    *       the only allowed form of pointer arithmetic.
                                    */
                                    pBufferRX += 2u;
                                }
                                else
                                {
                                    *pBufferRX = (Spi_DataType)REG_READ32(
                                            /*
                                            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall
                                            * not be performed between
                                            * a pointer to a function and any type other than an
                                            * integral type.
                                            */
                                            DSPI_BASEADDR2POPR(DspiBaseAddress));
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                    *       the only allowed form of pointer arithmetic.
                                    */
                                    pBufferRX++;
                                }
                            #else
                                *pBufferRX = (Spi_DataType)REG_READ32(
                                   /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be
                                    * performed between a pointer type and an integral type.
                                    */
                                        DSPI_BASEADDR2POPR(DspiBaseAddress));
                                /*
                                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                *       the only allowed form of pointer arithmetic.
                                */
                                pBufferRX++;
                            #endif
                    }

                    /* Receive FIFO Drain Flag must be reset */
                    StatusReset |= DSPI_RFDF_STS_MASK;
                }
            }

            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            REG_WRITE32(DSPI_BASEADDR2SR(DspiBaseAddress), StatusReset);

            Timeout--;
            /* end the loop if timeout expired */
            if (0u == Timeout)
            {
                /* force the end of the outer loop too */
                ChannelsCount = 0U;
                break;
            }
        } /* while ((LengthTX > 0) || (LengthRX > 0)) */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pChannel++;
    } /* while (ChannelsCount) */

    /* release the HW Unit */
    *(pSequence->JobDspiStatus) = SPI_IDLE;

    if (Timeout > 0u)
    {
        /* Job is done set the status as OK */
        pJobState->Result = SPI_JOB_OK;
        Status = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Timeout expired => transmission failed */
        /* set the Job status as FAILED */
        pJobState->Result = SPI_JOB_FAILED;
        Status = (Std_ReturnType)E_NOT_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == SpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)SpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, \
                                                DEM_EVENT_STATUS_FAILED);
        }  
#endif
    }

    return Status;
}
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

/*================================================================================================*/
/**
* @brief   This function performs the synchronous transmission for a sequence.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Sequence      Specifies the sequence for which we will have
*                              the synchronous transmission
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
* @implements DSPI02818, DSPI01383.
*/
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
FUNC (Std_ReturnType, SPI_CODE) Spi_LLD_SyncTransmit(
    VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    P2CONST(Spi_SequenceConfig, AUTOMATIC, SPI_APPL_CONST) pSequenceConfig;
    P2CONST(Spi_ChannelConfig, AUTOMATIC, SPI_APPL_CONST) pChannelConfig;
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig;
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev;
    P2CONST(Spi_LLD_ChannelAttributesConfig, AUTOMATIC, SPI_APPL_CONST)
        DspiChannelAttributesConfig;
    VAR(Spi_JobType, AUTOMATIC) JobsCount;
    VAR(Spi_JobType, AUTOMATIC) Job;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) pJobIndexList;
    P2CONST(Spi_ChannelType, AUTOMATIC, SPI_APPL_CONST) pChannelIndexList;
    VAR(Spi_ChannelType, AUTOMATIC) ChannelsCount;
    VAR(uint32, AUTOMATIC) Timeout = SPI_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC) tempXferData;
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    P2VAR(Spi_JobState, AUTOMATIC, SPI_APPL_DATA) pJobState;
    P2VAR(Spi_ChannelState, AUTOMATIC, SPI_APPL_DATA) pChannelState;
    VAR(Spi_ChannelType, AUTOMATIC) Channel;
    VAR(uint32, AUTOMATIC) DspiBaseAddress;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthTX;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthRX;
    VAR(uint32, AUTOMATIC) Ctar;
    VAR(uint32, AUTOMATIC) nEmptyPlaces;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pBufferFullTX;
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pBufferFullRX;
#endif
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) pBufferTX;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) pBufferRX;

    /* Get sequence configuration */
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pSequenceConfig = &SpiConfigPtr->SequenceConfig[Sequence];

    /* Get Channel Attributes */
    DspiChannelAttributesConfig =
        SpiConfigPtr->AttributesConfig->ChannelAttributesConfig;

    /* Get the number of jobs in the sequence */
    JobsCount = pSequenceConfig->NumJobs;

    pJobIndexList = pSequenceConfig->JobIndexList;
    while (JobsCount > 0u)
    {
        /* Get the job id */
        Job = *pJobIndexList;

        /* Set the job status as pending */
        pJobState = &SpiJobState[Job];
        pJobState->Result = SPI_JOB_PENDING;

        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pJobConfig = &SpiConfigPtr->JobConfig[Job];
        DspiDev = &DspiDeviceState[pJobConfig->HWUnit];

        /* mark HW unit as busy */
        *(DspiDev->pStatus) = SPI_BUSY;

        /* retrieve the DSPI offset */
        DspiBaseAddress = DspiDev->DspiBaseAddress;

        /* retrieve the CTAR setting for the corresponding external device */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        Ctar = pJobConfig->ExternalDeviceAttrs.CTAR[Dspi_ClockMode];
#else
        Ctar = pJobConfig->ExternalDeviceAttrs.CTAR;
#endif

        /* set the CMD part of the word to be transmitted */
        /* @violates @ref Spi_Dspi_LLD_c_REF_12 Violates MISRA 2004 Required Rule 10.5, Shift left of signed quantity(int) */
        tempXferData = (pJobConfig->ExternalDeviceAttrs.CMD | DSPI_CMD_CTAR_SEL);

        /* iterate on all channels in job */
        ChannelsCount = pJobConfig->NumChannels;
        pChannelIndexList = pJobConfig->ChannelIndexList;
        while (ChannelsCount > (Spi_ChannelType)0)
        {
            ChannelsCount--;

            /* Get the channel ID & configuration */
            Channel = *pChannelIndexList;
            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pChannelConfig = &SpiConfigPtr->ChannelConfig[Channel];
            pChannelState = pChannelConfig->ChannelState;

            /* set CTAR register */
            /**
            * @note The call is blocking till the HWUnit exits
            *       the running state.
            */
            REG_WRITE32(DSPI_BASEADDR2CTAR(DspiBaseAddress),
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                (Ctar | DspiChannelAttributesConfig[Channel].CMD));

            /* retrieve RX/TX buffers and the transmitted/received lengths */
            if (pChannelState->Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT))
            {
                pBufferTX = NULL_PTR;
            }
            else
            {
                pBufferTX = pChannelConfig->BufferDescriptor->BufferTX;
            }
            pBufferRX = pChannelConfig->BufferDescriptor->BufferRX;

            LengthTX = pChannelState->Length;
            #if (SPI_FORCE_DATA_TYPE == STD_ON)
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                if (DspiChannelAttributesConfig[Channel].DataWidth == 1u)
                {
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth)
                    {
                        LengthTX /= 2u;
                    }
                }

            #endif
            LengthRX = LengthTX;

            Timeout = SPI_TIMEOUT_COUNTER;
            nEmptyPlaces = SPI_FIFO_SIZE;

            /* while there is still something to read or to write */
            /* a kind of: while ((LengthTX > 0) || (LengthRX > 0)) */
            while ((LengthTX | LengthRX) > 0u)
            {
                VAR(uint32, AUTOMATIC) StatusReset = 0u;

                /* --------- Transmit ---------- */
                /* there is something to write and Transmit FIFO not full */
                if ((LengthTX > 0u) && (nEmptyPlaces > 0u))
                {
                    LengthTX--;
                    nEmptyPlaces--;

                    /* reset the timeout */
                    Timeout = SPI_TIMEOUT_COUNTER;

                    /* prepare the data to be transmitted */
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_7 The operands of logical operators
                    * (&&, || and !) should be effectively Boolean.
                    */
                    if (!pBufferTX)
                    {
                        /*
                        * @implements DSPI02476.
                        */
                        /* Get default data if TX buffer is NULL_PTR */
                        tempXferData =
                            (tempXferData & DSPI_TX_CMD_MASK) |
                            pChannelConfig->DefaultTransmitValue;
                    }
                    else
                    {
                        /* Read transmit data */
                        #if (SPI_FORCE_DATA_TYPE == STD_ON)
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth)
                            {
                                /*
                                * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be performed
                                * between a pointer to object type and a different pointer to object
                                * type.
                                */
                                pBufferFullTX = (uint16 *) pBufferTX;
                                tempXferData =
                                (tempXferData & DSPI_TX_CMD_MASK) | (*pBufferFullTX);
                            }
                            else
                            {
                                /*
                                * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed
                                *  between a pointer type and an integral type.
                                */
                                tempXferData =
                                    (tempXferData & DSPI_TX_CMD_MASK) | (*pBufferTX);
                            }
                        #else
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed
                            * between a pointer type and an integral type.
                            */
                            tempXferData =
                            (tempXferData & DSPI_TX_CMD_MASK) | (*pBufferTX);
                        #endif
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            pBufferTX++;
                        #if (SPI_FORCE_DATA_TYPE == STD_ON)
                            /*
                            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            if (SPI_DATA_WIDTH_16 == DspiChannelAttributesConfig[Channel].DataWidth)
                            {
                                /*
                                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                *       the only allowed form of pointer arithmetic.
                                */
                                pBufferTX++;
                            }
                        #endif
                    }

                    /* For the last frame, clear the continous CS assertion */
                    /* a kind of: ((0u == LengthTX) && (0u == ChannelsCount))*/
                    if (0u == (LengthTX | ChannelsCount))
                    {
                        /* clear the continuous CS assertion */
                        tempXferData = tempXferData & ~DSPI_CONT_MASK;
                    }

                /* Transmit the data */
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a
                    * pointer type and an integral type.
                    */
                    REG_WRITE32(DSPI_BASEADDR2PUSHR(DspiBaseAddress), tempXferData);

                    /* Transmit FIFO Fill Flag must be reset */
                    StatusReset |= DSPI_TFFF_STS_MASK;
                }

                /* --------- Receive ---------- */
                /* there is still something to read and Receive FIFO has data */
                if (LengthRX > 0u)
                {
                    /*
                    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a
                    * pointer type and an integral type.
                    */
                    if (0u != ((REG_READ32(DSPI_BASEADDR2SR(DspiBaseAddress))) &
                            DSPI_RFDF_STS_MASK)
                    )
                    {
                        LengthRX--;
                        nEmptyPlaces++;

                        /* reset the timeout */
                        Timeout = SPI_TIMEOUT_COUNTER;

                        /* Read Data from RX FIFO */
                         /*
                         * @violates @ref Spi_Dspi_LLD_c_REF_7 The operands of logical operators
                         * (&&, || and !) should be effectively Boolean.
                         */
                        if (!pBufferRX)
                        {
                            /*
                            * @implements DSPI02476.
                            */
                            /* discard data if RX buffer is NULL_PTR */
                            DspiReadDiscard = REG_READ32(
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall not
                                    * be performed between
                                    * a pointer to a function and any type other than an integral type.
                                    */
                                    DSPI_BASEADDR2POPR(DspiBaseAddress));
                        }
                        else
                        {
                            #if (SPI_FORCE_DATA_TYPE == STD_ON)
                                if (SPI_DATA_WIDTH_16 ==
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                    *       the only allowed form of pointer arithmetic.
                                    */
                                    DspiChannelAttributesConfig[Channel].DataWidth)
                                {
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_4 A cast should not be
                                    * performed between a pointer
                                    *       to object type and a different pointer to object type.
                                    */
                                    pBufferFullRX = (uint16 *) pBufferRX;
                                    *pBufferFullRX = (uint16)REG_READ32(
                                            /*
                                            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall
                                            * not be performed between
                                            * a pointer to a function and any type other than
                                            * an integral type.
                                            */
                                            DSPI_BASEADDR2POPR(DspiBaseAddress));
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                    *       the only allowed form of pointer arithmetic.
                                    */
                                    pBufferRX += 2u;
                                }
                                else
                                {
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be
                                    *  performed between a pointer type and an integral type.
                                    */
                                    *pBufferRX = (Spi_DataType)REG_READ32(
                                            /*
                                            * @violates @ref Spi_Dspi_LLD_c_REF_3 Conversions shall
                                            * not be performed between
                                            * a pointer to a function and any type other than an
                                            * integral type.
                                            */
                                            DSPI_BASEADDR2POPR(DspiBaseAddress));
                                    /*
                                    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                    *       the only allowed form of pointer arithmetic.
                                    */
                                    pBufferRX++;
                                }
                            #else
                                *pBufferRX = (Spi_DataType)REG_READ32(
                                /*
                                * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed
                                * between a pointer
                                *     type and an integral type.
                                */
                                        DSPI_BASEADDR2POPR(DspiBaseAddress));
                                /*
                                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                                *       the only allowed form of pointer arithmetic.
                                */
                                pBufferRX++;
                            #endif
                        }

                        /* Receive FIFO Drain Flag must be reset */
                        StatusReset |= DSPI_RFDF_STS_MASK;
                    }
                }

                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                REG_WRITE32(DSPI_BASEADDR2SR(DspiBaseAddress), StatusReset);

                Timeout--;
                /* end the loop if timeout expired */
                if (0u == Timeout)
                {
                    /* force the end of the outer loop too */
                    ChannelsCount = 0U;
                    break;
                }
            } /* while ((LengthTX > 0) || (LengthRX > 0)) */

            /*
            * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pChannelIndexList++;
        } /* while (ChannelsCount) */

        /* release the HW unit */
        *(DspiDev->pStatus) = SPI_IDLE;

        if (Timeout > 0U)
        {
            /* Job is done set the status as OK */
            pJobState->Result = SPI_JOB_OK;
        }
        else
        {
            /* Timeout expired => transmission failed */
            /* set the remaining job status (including the current one) as FAILED */
            do
            {
                /* Set the job status as FAILED */
                SpiJobState[*pJobIndexList].Result = SPI_JOB_FAILED;
                /*
                * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                pJobIndexList++;
                JobsCount--;
            } while (JobsCount > 0u);
            JobsCount = 1u;  /* needed to end correctly the outer loop */
            Status = (Std_ReturnType)E_NOT_OK;
        }

        /* iterate to next job in sequence */
        /*
        * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pJobIndexList++;
        JobsCount--;
    } /* while (JobsCount > 0u) */

    if ((Std_ReturnType)E_OK != Status)
    {
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == SpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)SpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, \
                                                DEM_EVENT_STATUS_FAILED);
        }  
#endif
    }
    return Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief   Low-level timed serial bus mode setting function.
* @details Initialize all the Spi units with CSI configuration.
*          Also configure the master configuration register for
*          parameters like DSPI configuration, continuos clock enable,
*          master mode selection etc.
*
* @param[in]  Spi_JobType  Job to be configured in TSB mode.
*
* @implements DSPI01391.
*/
/*================================================================================================*/
FUNC (void, SPI_CODE) Spi_LLD_SetTSBMode(
    VAR(Spi_JobType, AUTOMATIC) TSBJob)
{

    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    VAR(uint8, AUTOMATIC) HWoffset;
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig;
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig;
    P2CONST(Spi_TSBConfig, AUTOMATIC, SPI_APPL_CONST) pJobTSBConfig;
    VAR(uint32, AUTOMATIC) SpiNormalJob;
    VAR(uint32, AUTOMATIC) MCR;
    VAR(uint32, AUTOMATIC) DSICR;
    VAR(uint32, AUTOMATIC) DSICR1;
    VAR(uint32, AUTOMATIC) CTAR;

    pJobTSBConfig = &SpiJobTSBConfig[TSBJob];
    SpiNormalJob = pJobTSBConfig->Spi_TSB_Job;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pJobConfig = &SpiConfigPtr->JobConfig[SpiNormalJob];


    /* Logical Spi HWUnit */
    HWUnit = pJobConfig->HWUnit;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    HWUnitConfig = &SpiConfigPtr->HWUnitConfig[HWUnit];
    /* Peripheral Registers */
    HWoffset = HWUnitConfig->Offset;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    MCR = REG_READ32(DSPI_MCR(HWoffset));
    /*2) configuration of DSPI_MCR*/
    /* Master mode selection*/
    /* Determine chip select inactive states for each PCS */  /* high by default */
    /* CSI configuration of the DSPI*/
    /* Enable Transmit FIFO*/
    /* Disable Transmit FIFO.*/
    /* Continuous SCK Enable*/
    /* HALT = 1; stop transfers*/
    MCR = ((MCR & DSPI_MCR_PCSIS_ALL) | DSPI_MCR_MSTR | DSPI_MCR_DCONF_CSI
            | DSPI_MCR_RX_FIFO | DSPI_MCR_CONT_SCKE | DSPI_MCR_HALT);

    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_MCR_CONFIG(HWoffset, MCR);

    /*2) configuration of DSPI_DSICR*/
    /*Timed Serial Bus Configuration enabled*/
    /*ctar3 selection*/

    /*3)Set DSPI_DSICR attributes Transmit Data Source(TXSS), Change in data transfer(CID),
        DSI peripheral Chip Select(DPCSx)*/
    DSICR = pJobTSBConfig->ExternalDeviceTSBAttrs.DSICR;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_DSICR_CONFIG(HWoffset, (DSICR|DSPI_DSICR_TSBC|DSPI_DSICR_DSICTAS_CTAR3));

    /*4)Set DSPI_DSICR1 attributes Timed Serial Bus Operation Count(TSBCNT),
        Peripheral chip select for the seocnd part of the frame with dual receiver */
    DSICR1 = pJobTSBConfig->ExternalDeviceTSBAttrs.DSICR1;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_DSICR1_CONFIG(HWoffset, DSICR1);

    /*5)Set ctar3 attributes*/

    /*Update the ctar3 based on clock mode selected*/
    #if (SPI_DUAL_CLOCK_MODE == STD_ON)
    CTAR = pJobTSBConfig->ExternalDeviceTSBAttrs.CTAR[Dspi_ClockMode];
    #else
    CTAR = pJobTSBConfig->ExternalDeviceTSBAttrs.CTAR;
    #endif
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_WR_CTAR3_CONFIG(HWoffset, CTAR);
    /*LSB first, when operating in TSB configuration, this bit
    should be set to be compliant to MSC specification*/
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_CTAR3_WR_LSBFE(HWoffset);

    /*6) Start transfer*/
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_MCR_HALT_CLEAR(HWoffset);
}
/*================================================================================================*/
/**
* @brief   Low-level timed serial bus mode deinitialisation function.
* @details DSPI hardware is deinitialised to master and SPI mode
*
* @param[in]     Spi_JobType Job configured in TSB mode
*
* @implements DSPI01392.
*/
/*================================================================================================*/
FUNC (void, SPI_CODE) Spi_LLD_StopTSBMode(
    VAR(Spi_JobType, AUTOMATIC) TSBJob)
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig;
    P2CONST(Spi_TSBConfig, AUTOMATIC, SPI_APPL_CONST) pJobTSBConfig;
    VAR(uint32, AUTOMATIC) SpiNormalJob;

    pJobTSBConfig = &SpiJobTSBConfig[TSBJob];
    SpiNormalJob = pJobTSBConfig->Spi_TSB_Job;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pJobConfig = &SpiConfigPtr->JobConfig[SpiNormalJob];

    /* Logical Spi HWUnit */
    HWUnit = pJobConfig->HWUnit;

    /* De- initialize the DSPI driver */
    Spi_LLD_DeInit(HWUnit);

    /* Reset configuration pointer */
    SpiConfigPtr = NULL_PTR;
}
/*================================================================================================*/
/**
* @brief   Low-level ASDR write register while in  timed serial bus mode
* @details Low-level ASDR write register while in  timed serial bus mode
*
* @param[in]     Spi_JobType Job configured in TSB mode
*
* @implements DSPI01393.
*/
/*================================================================================================*/
FUNC (void, SPI_CODE) Spi_LLD_TSB_ASDR_DataUpdate(
    VAR(Spi_JobType, AUTOMATIC) TSBJob,
    VAR(uint32, AUTOMATIC) ASDR_Data)
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    VAR(uint8, AUTOMATIC) HWoffset;
    P2CONST(Spi_HWUnitConfig, AUTOMATIC, SPI_APPL_CONST) HWUnitConfig;
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig;
    P2CONST(Spi_TSBConfig, AUTOMATIC, SPI_APPL_CONST) pJobTSBConfig;
    VAR(uint32, AUTOMATIC) SpiNormalJob;

    pJobTSBConfig = &SpiJobTSBConfig[TSBJob];
    SpiNormalJob = pJobTSBConfig->Spi_TSB_Job;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pJobConfig = &SpiConfigPtr->JobConfig[SpiNormalJob];

    /* Logical Spi HWUnit */
    HWUnit = pJobConfig->HWUnit;
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    HWUnitConfig = &SpiConfigPtr->HWUnitConfig[HWUnit];
    /* Peripheral Registers */
    HWoffset = HWUnitConfig->Offset;

    /*Update data on ASDR register*/
    /*
    * @violates @ref Spi_Dspi_LLD_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    DSPI_LLM_ASDR_CONFIG(HWoffset, ASDR_Data);

}
#endif /*(SPI_TSB_MODE == STD_ON)*/
#endif /*TSB_MODE_SUPPORTED*/
/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_Dspi_LLD_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_LLD_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif



/** @} */


