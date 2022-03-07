/**
*   @file    Spi_Dspi_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - DSPI LLD header file.
*   @details DSPI peripheral LLD header file.

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

#ifndef SPI_DSPI_LLD_H
#define SPI_DSPI_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Spi_Dspi_LLD_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_Dspi_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_Dspi_LLD_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Spi_Dspi_LLD_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* This violation is not fixed since naming convention of Identifiers are followed as per Autosar
* standards, some times which may exceeds more than 31 characters.
*
* @section Spi_Dspi_LLD_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
  *
* @section Spi_Dspi_LLD_h_REF_6
* Violates MISRA 2004 Required Rule  8.8, This violation is not fixed but we have taken care while
* including the header file.
*
* @section Spi_Dspi_LLD_h_REF_7
* Violates MISRA 2004 Required Rule 19.10, Within a definition of a function-like macro, 
* the arguments shall be enclosed in parentheses.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Spi_Dspi_LLD.h
* @implements   DSPI02049
*/
/*
* @violates @ref Spi_Dspi_LLD_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Dspi_LLD_h_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_LLD     4
/*
* @violates @ref Spi_Dspi_LLD_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Dspi_LLD_h_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MINOR_VERSION_LLD     0
/*
* @violates @ref Spi_Dspi_LLD_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Dspi_LLD_h_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_REVISION_VERSION_LLD  3
#define SPI_SW_MAJOR_VERSION_LLD             1
#define SPI_SW_MINOR_VERSION_LLD             0
#define SPI_SW_PATCH_VERSION_LLD             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and SPI configuration header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_LLD    != SPI_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_MINOR_VERSION_LLD    != SPI_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_REVISION_VERSION_LLD != SPI_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Spi_Dspi_LLD.h and Spi_Cfg.h are different"
#endif

/* Check if source file and SPI configuration header file are of the same software version */
#if ((SPI_SW_MAJOR_VERSION_LLD != SPI_SW_MAJOR_VERSION_CFG) || \
     (SPI_SW_MINOR_VERSION_LLD != SPI_SW_MINOR_VERSION_CFG))
#error "Software Version Numbers of Spi_Dspi_LLD.h and Spi_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief  Map HWUnit to DSPI device structure.
*/
/*
* @violates @ref Spi_Dspi_LLD_h_REF_3 A function should be used in preference to a function-like macro.
*/

#define DSPI_HWUNIT2DSPI(HWUnit)    (&DspiDeviceState[(HWUnit)])


#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   This Macro shall set different MCU clock mode .
* @details This Macro shall set different MCU clock mode .
*
* @param[in]    ClockMode   Clock mode to be set.
*
* @pre  Pre-compile parameter SPI_DUAL_CLOCK_MODE shall be STD_ON.
*
*
* @implements DSPI02809.
*/
/*================================================================================================*/
/*
* @violates @ref Spi_Dspi_LLD_h_REF_3 A function should be used in preference to a function-like macro.
*/
#define DSPI_SET_CLOCK_MODE(ClockMode)  ((Dspi_ClockMode) = (ClockMode))

#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief   Internal structure keeping a set of cached channel attributes.
* @details Internal structure keeping a set of cached channel attributes
*          used by the optimized implementation of Spi_SyncTransmit() for
*          the sequences having only one job.
*/
typedef struct
{
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Cached value of the CTAR register. */
    VAR(uint32, SPI_VAR) CTAR[2];
#else
    VAR(uint32, SPI_VAR) CTAR;
#endif
    /**< @brief Cached pointer to the buffer descriptor. */
    P2CONST(Spi_BufferDescriptor, SPI_VAR, SPI_APPL_CONST) BufferDescriptor;
    /**< @brief Cached pointer to the channel states. */
    P2VAR(Spi_ChannelState, SPI_VAR, SPI_APPL_DATA) State;
    /**< @brief Cached default transmit value. */
    VAR(Spi_DataType, SPI_VAR) DefaultTransmitValue;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    /**< @brief Channel attributes for data width. */
    VAR(uint8, SPI_VAR) DataWidth;
#endif
} Spi_ChannelCacheAttrs;

/**
* @brief    Internal structure keeping a set of cached sequences attributes.
* @details  Internal structure keeping a set of cached sequences attributes
*           used by the optimized implementation of Spi_SyncTransmit() for
*           the sequences having only one job.
*/
typedef struct
{
    /**< @brief Number of channels in sequence. */
    VAR(Spi_ChannelType, SPI_VAR) NumChannels;
    /**< @brief Cached pointer to the sequence job state. */
    P2VAR(Spi_JobState, SPI_VAR, SPI_APPL_DATA) JobState;
    /**< @brief Cached pointer to the sequence DSPI state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) JobDspiStatus;
    /**< @brief Table of channel cached attributes. */
    P2VAR(Spi_ChannelCacheAttrs, SPI_VAR, SPI_APPL_DATA) pChannels;
    /**< @brief Cached value of the DSPI HW Unit offset. */
    VAR(uint32, SPI_VAR) JobHWOffset;
    /**< @brief Cached value of the DSPI HW Unit memory mapped registers base address. */
    VAR(uint32, SPI_VAR) DspiBaseAddress;
    /**< @brief Cached value of CMD field of the SPI dataframes. */
    VAR(uint32, SPI_VAR) JobCMD;
} Spi_SequenceCacheAttrs;
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */

/**
* @brief This structure holds runtime configuration parameters for Spi handler.
*/
typedef struct
{
    /**< @brief Reference to the corresponding HWUnit config instance. */
    P2CONST(Spi_HWUnitConfig, SPI_VAR, SPI_APPL_CONST) HWUnitConfig;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
    /**< @brief Internal buffer containing the command|data frame information for the last dataframe in job. */
    VAR(uint32, SPI_VAR) TxDmaBuffer;
    /**< @brief Internal buffer containing the command|data frame information for the last dataframe in job. */
    VAR(uint32, SPI_VAR) TxDmaBufferLast;
    /**< @brief Address of the default master TX DMA descriptor stored in memory. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) TxDmaTcdDefault;
    /**< @brief Address of the TX DMA descriptor to be used for transfering the last job dataframe. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) TxDmaTcdLast;
    /**< @brief Address of the master TX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) TxDmaTcd;
    /**< @brief Address of the master RX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) RxDmaTcd;
    /**< @brief Cache of the e_link configuration part into the iteration field. */
    VAR(uint16, SPI_VAR) MinorELink;
#endif
    /**< @brief CTAR register used to define different transfer attributes for exeternal device. */
    VAR(uint32, SPI_VAR) ExternalDeviceCTAR;
    /**< @brief Pointer to the Tx buffer of the channel currently in transmission. */
    P2VAR(Spi_DataType, SPI_VAR, SPI_APPL_DATA) CurrentTxBuffer;
    /**< @brief Pointer to the Rx buffer of the channel currently in transmission. */
    P2VAR(Spi_DataType, SPI_VAR, SPI_APPL_DATA) CurrentRxBuffer;
    /**< @brief The frame command value to be used for the channel in transmission. */
    VAR(uint32, SPI_VAR) CurrentCmd;
    /**< @brief Position in ChannelIndexList to the channel in transmission. */
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) CurrentChannelIndexPointer;
    /**< @brief Number of channels in a pending async job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) RemainingChannels;
    /**< @brief Number of frames in a pending channel, not yet transmitted. */
    VAR(Spi_NumberOfDataType, SPI_VAR) RemainingData;
    /**< @brief Number of sent frames, which must be read back in the next ISR call. */
    VAR(Spi_NumberOfDataType, SPI_VAR) SentFrames;
    /**< @brief Reference to the current job. */
    P2CONST(Spi_JobConfig, SPI_VAR, SPI_APPL_CONST) CurrentJob;
    /**< @brief Indicates if this is the last chunk of data in the job. */
    VAR(boolean, SPI_VAR) IsEndOfJob;
#endif
    /**< @brief Memory mapped registers base address. */
    VAR(uint32, SPI_VAR) DspiBaseAddress;
    /**< @brief DSPI PUSHR register address. */
    volatile P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pDspiPUSHRAddress;
    /**< @brief DSPI POPR register address. */
    volatile P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pDspiPOPRAddress;
    /**< @brief DSPI Status register address. */
    volatile P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pDspiSRAddress;
    /**< @brief DSPI CTAR3 register address. */
    volatile P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pDspiCTARAddress;
    /**< @brief Asynchronous operating mode of the DSPI unit. */
    VAR(Spi_AsyncModeType, SPI_VAR) AsyncMode;
    /**< @brief Pointer to the Autosar HW unit SPI state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) pStatus;

    VAR(Spi_NumberOfDataType, SPI_VAR) ReceivedData;
} Spi_LLD_DeviceState;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifndef SPI_PRECOMPILE_SUPPORT
 /*
* @violates @ref Spi_Dspi_LLD_h_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Dspi_LLD_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_Dspi_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/

#include "MemMap.h"


#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief    Pointer table to the cached information structure
* @details  Pointer table to the cached information structure, for one job sequences,
*           or NULL, for unoptimized sequences.
*/
/* @violates @ref Spi_Dspi_LLD_h_REF_6 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern P2VAR(Spi_SequenceCacheAttrs, AUTOMATIC, SPI_VAR)
/* @violates @ref Spi_Dspi_LLD_h_REF_6 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
                DspiOneJobSeqsOptimized[SPI_MAX_SEQUENCE];
#endif


/**
* @brief Keep the HWUnit internal fields.
*/
/* @violates @ref Spi_Dspi_LLD_h_REF_6 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Spi_LLD_DeviceState, SPI_VAR) DspiDeviceState[SPI_MAX_HWUNIT];

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief Holds the mode of the Dual Clock.
*/
/* @violates @ref Spi_Dspi_LLD_h_REF_6 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Spi_DualClockMode, AUTOMATIC) Dspi_ClockMode;
#endif
 /*
* @violates @ref Spi_Dspi_LLD_h_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Dspi_LLD_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_Dspi_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_Dspi_LLD_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_Dspi_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

FUNC (void, SPI_CODE) Spi_LLD_Init(
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
    P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus);

FUNC (void, SPI_CODE) Spi_LLD_DeInit(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit);

#if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
FUNC (void, SPI_CODE) Spi_LLD_PrepareCacheInformation(void);
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
FUNC (Std_ReturnType, SPI_CODE) Spi_LLD_SyncTransmit(
    VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
FUNC (Std_ReturnType, SPI_CODE) Spi_LLD_SyncTransmit_Fast(
    P2CONST(Spi_SequenceCacheAttrs, AUTOMATIC, SPI_APPL_CONST) pSequence);
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_LLD_JobTransfer(
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_LLD_IrqConfig(
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_LLD_IrqPoll(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_LLD_IsrFifoRx(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC (void, SPI_CODE) Spi_LLD_IsrDmaRx(
    P2VAR(Spi_LLD_DeviceState, AUTOMATIC, SPI_APPL_DATA) DspiDev);
#endif
#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
FUNC (void, SPI_CODE) Spi_LLD_SetTSBMode(
      VAR(Spi_JobType, AUTOMATIC) TSBJob);

FUNC (void, SPI_CODE) Spi_LLD_StopTSBMode(
      VAR(Spi_JobType, AUTOMATIC) TSBJob);

FUNC (void, SPI_CODE) Spi_LLD_TSB_ASDR_DataUpdate(
      VAR(Spi_JobType, AUTOMATIC) TSBJob,
      VAR(uint32, AUTOMATIC) ASDR_Data);
#endif /*(SPI_TSB_MODE == STD_ON)*/
#endif /*TSB_MODE_SUPPORTED*/

#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_Dspi_LLD_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_Dspi_LLD_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* Spi_Dspi_LLD_H */

/** @} */

