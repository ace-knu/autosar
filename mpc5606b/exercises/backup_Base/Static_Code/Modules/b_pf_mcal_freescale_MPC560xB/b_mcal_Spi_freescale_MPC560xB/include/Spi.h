/**
*   @file    Spi.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Spi driver header file.
*   @details AUTOSAR specific Spi driver header file.

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

#ifndef SPI_H
#define SPI_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Spi_h_REF_1
* Violates MISRA 2004 Required Rule 1.4,
* This violation is not fixed since naming convention of Identifiers are followed as per Autosar
* standards, some times which may exceeds more than 31 characters.
*
* @section Spi_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* Forced by software arhitecture design.
*
* @section Spi_h_REF_3
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_h_REF_4
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
 *
* @section Spi_h_REF_5
* Violates MISRA 2004 Required Rule 8.8, This violation is not fixed but we have taken care while
* including the header file.
*
* @section Spi_h_REF_6
* Violates MISRA 2004 Required Rule 8.12, Array declared with unknown size.
*
* @section Spi_h_REF_7
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
* @file           Spi.h
* @implements     DSPI02492, DSPI02402.
*/

/*
* @violates @ref Spi_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
/* @implements     DSPI03053, DSPI03054. */
#include "Std_Types.h"
/*
* @violates @ref Spi_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "Mcal.h"
#include "Spi_Cfg.h"
#include "Spi_Dspi_LLD_CfgEx.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file         Spi.h
* @implements   DSPI02049
*/
#define SPI_VENDOR_ID                    43
#define SPI_MODULE_ID                    83
#define SPI_AR_RELEASE_MAJOR_VERSION     4
#define SPI_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref Spi_h_REF_1 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION  3
#define SPI_SW_MAJOR_VERSION             1
#define SPI_SW_MINOR_VERSION             0
#define SPI_SW_PATCH_VERSION             1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID != SPI_VENDOR_ID_CFG)
    #error "Spi.h and Spi_Cfg.h have different vendor ids"
#endif

/* Check if source file and SPI header file are of the same Autosar version */
  #if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION_CFG) || \
       (SPI_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION_CFG) || \
       (SPI_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION_CFG))
      #error "AutoSar Version Numbers of Spi.h and Spi_Cfg.h are different"
  #endif


/* Check if source file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION_CFG) || \
     (SPI_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION_CFG))
    #error "Software Version Numbers of Spi.h and Spi_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SPI_PHYUNIT_SYNC        ((uint32) 1u)
#define SPI_PHYUNIT_ASYNC       ((uint32) 0u)

/* Error Values */
/**
* @brief API service called with wrong parameter.
*
* @implements DSPI02435.
*/
#define SPI_E_PARAM_CHANNEL      ((uint8) 0x0Au)
/**
* @brief API service called with wrong parameter.
*
* @implements DSPI02437.
*/
#define SPI_E_PARAM_JOB          ((uint8) 0x0Bu)
/**
* @brief API service called with wrong parameter.
*
* @implements DSPI02440.
*/
#define SPI_E_PARAM_SEQ          ((uint8) 0x0Cu)
/**
* @brief API service called with wrong parameter.
*
* @implements DSPI02438.
*/
#define SPI_E_PARAM_LENGTH        ((uint8) 0x0Du)
/**
* @brief API service called with wrong parameter.
*
* @implements DSPI02441.
*/
#define SPI_E_PARAM_UNIT          ((uint8)0x0Eu)
/**
* @brief API service used without module initialization.
*
* @implements DSPI02445
*/
#define SPI_E_UNINIT              ((uint8)0x1Au)
/**
* @brief Services called in a wrong sequence.
*
* @implements DSPI02444.
*/
#define SPI_E_SEQ_PENDING         ((uint8)0x2Au)
/**
* @brief Synchronous transmission service called at wrong time.
*
* @implements DSPI02443.
*/
#define SPI_E_SEQ_IN_PROCESS      ((uint8)0x3Au)
/**
* @brief API SPI_Init service called while the SPI driver has already been intialized.
*
* @implements DSPI02432.
*/
#define SPI_E_ALREADY_INITIALIZED ((uint8)0x4Au)

/**
* @brief   The number of sequences, jobs or channels exceeds precompile time sizes.
* @details The number of sequences, jobs or channels in the configuration
*          exceeds precompile time related sizes:
*          SPI_MAX_SEQUENCE, SPI_MAX_JOB or SPI_MAX_CHANNEL.
*
* @implements DSPI02433.
*/
#define SPI_E_CONFIG_OUT_OF_RANGE ((uint8)0x5Au)

/**
* @brief   When a sequence contains uninitialized external buffers.
*
* @implements DSPI02436.
*/
#define SPI_E_PARAM_EB_UNIT       ((uint8)0x5Bu)

/**
* @brief   No job in sequence.
*
* @implements DSPI02442.
*/
#define SPI_E_SEQ_EMPTY           ((uint8)0x5Cu)

/**
* @brief   No channel in job.
*
* @implements DSPI02434.
*/
#define SPI_E_JOB_EMPTY           ((uint8)0x5Du)
/**
* @brief   If the parameter versioninfo is NULL_PTR.
*
* @implements DSPI02446.
*/
#define SPI_E_PARAM_POINTER           ((uint8)0x10u)

/**
* @brief   API service called with wrong parameter
*
* @implements DSPI02481.
*/
#define SPI_E_TSBJOB              ((uint8)0x5Eu)


#define SPI_CHANNEL_FLAG_TX_DEFAULT ((uint8) 0x01u)
#define SPI_CHANNEL_FLAG_RX_DISCARD ((uint8) 0x02u)


    /* Service IDs */
/**
* @brief API service ID for SPI Init function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02451.
*/
#define SPI_INIT_ID              ((uint8) 0x00u)
/**
* @brief API service ID for SPI DeInit function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02431.
*/
#define SPI_DEINIT_ID            ((uint8) 0x01u)
/**
* @brief API service ID for SPI write IB function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02461.
*/
#define SPI_WRITEIB_ID           ((uint8) 0x02u)
/**
* @brief API service ID for SPI async transmit function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02427.
*/
#define SPI_ASYNCTRANSMIT_ID     ((uint8) 0x03u)
/**
* @brief API service ID for SPI read IB function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02455.
*/
#define SPI_READIB_ID            ((uint8) 0x04u)
/**
* @brief API service ID for SPI setup EB function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02459.
*/
#define SPI_SETUPEB_ID           ((uint8) 0x05u)
/**
* @brief API service ID for SPI get status function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02450.
*/
#define SPI_GETSTATUS_ID         ((uint8) 0x06u)
/**
* @brief API service ID for SPI get job result function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02448.
*/
#define SPI_GETJOBRESULT_ID      ((uint8) 0x07u)
/**
* @brief API service ID for SPI get sequence result function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02449.
*/
#define SPI_GETSEQUENCERESULT_ID ((uint8) 0x08u)
/**
* @brief API service ID for SPI get version info function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02482.
*/
#define SPI_GETVERSIONINFO_ID    ((uint8) 0x09u)
/**
* @brief API service ID for SPI sync transmit function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02460.
*/
#define SPI_SYNCTRANSMIT_ID      ((uint8) 0x0Au)
/**
* @brief API service ID for SPI get hwunit status function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02447.
*/
#define SPI_GETHWUNITSTATUS_ID   ((uint8) 0x0Bu)
/**
* @brief API service ID for SPI cancel function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02428.
*/
#define SPI_CANCEL_ID            ((uint8) 0x0Cu)
/**
* @brief API service ID for SPI set async mode function.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02456.
*/
#define SPI_SETASYNCMODE_ID      ((uint8) 0x0Du)
/**
* @brief API service ID for SPI main function
* @details Parameters used when raising an error/exception
*
* @implements DSPI02491.
*/
#define SPI_MAINFUNCTION_HANDLING_ID  ((uint8)0x10u)
/**
* @brief API service ID for SPI set HW Unit async mode.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02458.
*/
#define SPI_SETHWUNITASYNCMODE_ID  ((uint8)0x80u)
/**
* @brief API service ID for SPI Set Clock Mode.
* @details Parameters used when raising an error/exception.
*
* @implements DSPI02457.
*/
#define SPI_SETCLOCKMODE_ID  ((uint8)0x81u)
/**
* @brief API service ID for Timed Serial Bus Mode.
* @details Parameters used when raising an error/exception
*
* @implements DSPI02483.
*/
#define SPI_SETTSBMODE_ID  ((uint8)0x82u)

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   The number of allowed job priority levels (0..3).
* @details The Priority has to be sint8.
*
* @implements DSPI02452.
*/
#define SPI_JOB_PRIORITY_LEVELS_COUNT    (4)
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/**
* @brief   This type defines a range of specific status for SPI Driver.
*
* @implements DSPI02426.
*/
typedef enum
{
    SPI_UNINIT = 0,          /**< @brief Not initialized or not usable. */
    SPI_IDLE,                /**< @brief Not currently transmitting any jobs. */
    SPI_BUSY                 /**< @brief Is performing a SPI Job(transmit). */
} Spi_StatusType;

/**
* @brief   This type defines a range of specific Jobs status for SPI Driver.
*
* @implements DSPI02417.
*/
typedef enum
{
    SPI_JOB_OK = 0,     /**< @brief The last transmission of the Job has been finished successfully. */
    SPI_JOB_PENDING,    /**< @brief The SPI handler/Driver is performing a SPI Job. */
    SPI_JOB_FAILED,     /**< @brief The last transmission of the Job has failed. */
    SPI_JOB_QUEUED      /**< @brief An asynchronous transmit Job has been accepted, while actual
                                     transmission for this Job has not started yet. */
} Spi_JobResultType;

/**
* @brief   This type defines a range of specific Sequences status for SPI Driver.
*
* @implements DSPI02422.
*/
typedef enum
{
    SPI_SEQ_OK = 0, /**< @brief The last transmission of the Sequence has been finished successfully. */
    SPI_SEQ_PENDING,         /**< @brief The SPI handler/Driver is performing a SPI Sequence. */
    SPI_SEQ_FAILED,          /**< @brief The last transmission of the Sequence has failed. */
    SPI_SEQ_CANCELLED   /**< @brief The last transmission of the Sequence has been cancelled by the user. */
} Spi_SeqResultType;

/**
* @brief   The enumeration containg the designated values for buffer types (internal or external).
*
* @implements DSPI02405.
*/
typedef enum
{
    IB = 0,
    EB
} Spi_BufferType;

/**
* @brief   Specifies the asynchronous mechanism mode for SPI busses handled asynchronously in Level 2
* @details #if (LEVEL2 == SPI_LEVEL_DELIVERED)
*            Specifies the asynchronous mechanism mode for SPI busses handled
*            asynchronously in LEVEL 2. SPI150: This type is available or not
*           according to the pre compile time parameter:
*            SPI_LEVEL_DELIVERED. This is only relevant for LEVEL 2.
*
* @implements DSPI02403.
*/
typedef enum
{
    /* The asynchronous mechanism is ensured by polling, so interrupts
       related to SPI busses handled asynchronously are disabled. */
    SPI_POLLING_MODE = 0,
    /* The asynchronous mechanism is ensured by interrupt, so interrupts
       related to SPI busses handled asynchronously are enabled. */
    SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Specifies the Clock Modes.
*
* @implements DSPI02411, DSPI02191, DSPI02192.
*/
typedef enum
{
    SPI_NORMAL = 0u,        /**< @brief Clock reference is from SpiClockRef. */
    SPI_ALTERNATE          /**< @brief Clock reference is from SpiAlternateClockRef. */
}Spi_DualClockMode;
#endif

typedef enum
{
    SPI_MASTER = 0u,        /**< @brief SPI Hardware selected as MASTER. */
    SPI_SLAVE          /**< @brief SPI Hardware selected as SLAVE. */
}Spi_ModeType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*---------------------------------------------------------------------------
*                 SPI Driver AUTOSAR Related Type Definitions
-----------------------------------------------------------------------------*/

#if (SPI_FORCE_DATA_TYPE == STD_ON)

/**
* @brief   Type of application data buffer elements.
*
* @implements DSPI02410.
*/
    typedef uint8 Spi_DataType;
#else
    typedef uint16 Spi_DataType;
#endif

/**
* @brief   Type for defining the number of data elements of the type Spi_DataType.
* @details Type for defining the number of data elements of the type Spi_DataType
*          to send and/or receive by Channel.
*
* @implements DSPI02421.
*/
typedef uint16 Spi_NumberOfDataType;

#if (SPI_ALLOW_BIGSIZE_COLLECTIONS == STD_ON)

/**
* @brief   Specifies the identification (ID) for a Channel.
*
* @implements DSPI02408.
*/
typedef uint32 Spi_ChannelType;

/**
* @brief   Specifies the identification (ID) for a Job.
*
* @implements DSPI02419.
*/
typedef uint32 Spi_JobType;

/**
* @brief   Specifies the identification (ID) for a sequence of jobs.
*
* @implements DSPI02425.
*/
typedef uint32 Spi_SequenceType;
#else

/**
* @brief   Specifies the identification (ID) for a Channel.
*
* @implements DSPI02408.
*/
typedef uint8 Spi_ChannelType;

/**
* @brief   Specifies the identification (ID) for a Job.
*
* @implements DSPI02419.
*/
typedef uint8 Spi_JobType;

/**
* @brief   Specifies the identification (ID) for a sequence of jobs.
*
* @implements DSPI02425.
*/
typedef uint8 Spi_SequenceType;
#endif

/**
* @brief     Specifies the ID for a SPI Hardware microcontroller peripheral unit.
* @details  This type is used for specifying the identification (ID) for a SPI
*            Hardware microcontroller peripheral unit.
*
* @implements DSPI02415.
*/
typedef uint8 Spi_HWUnitType;

/**
* @brief     Contains the ID of an external device.
* @details  This contains the identification (ID) of the external device for which
*            there's a collection of particular settings
*
* @implements DSPI02412.
*/
typedef uint8 Spi_ExternalDeviceType;
/* @implements     DSPI02420 */
typedef void (Spi_NotifyType) (void);

/**
* @brief   This structure contains all the needed data to configure one SPI Sequence.
*
* @implements DSPI02423.
*/
typedef struct
{
    /**< @brief Number of jobs in the sequence. */
    VAR(Spi_JobType, SPI_VAR) NumJobs;
    /**< @brief Job index list. */
    P2CONST(Spi_JobType, SPI_VAR, SPI_APPL_CONST) JobIndexList;
    /**< @brief Job notification handler. */
    P2FUNC(Spi_NotifyType, SPI_VAR, EndNotification);
    /**< @brief Boolean indicating if the Sequence is interruptible or not. */
    VAR(uint8, SPI_VAR) Interruptible;
} Spi_SequenceConfig;

/**
* @brief   Internal structure used to manage the sequence state.
*
* @implements DSPI02424.
*/
typedef struct
{
    VAR(Spi_SeqResultType, SPI_VAR) Result;             /**< @brief Seq Result. */
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    /**< @brief Pointer to the configuration. */
    P2CONST(Spi_SequenceConfig, SPI_VAR, SPI_APPL_CONST) Sequence;
    /**< @brief Position in JobIndexList to the job in transmission of an async sequence. */
    P2CONST(Spi_JobType, SPI_VAR, SPI_APPL_CONST) CurrentJobIndexPointer;
    /**< @brief Number of jobs in a pending async sequence, not yet transmitted. */
    VAR(Spi_JobType, SPI_VAR) RemainingJobs;
#endif
} Spi_SequenceState;

/**
* @brief   Internal structure used to manage the job state.
*
* @implements DSPI02418.
*/
typedef struct
{
    VAR(Spi_JobResultType, SPI_VAR) Result;             /**< @brief Job Result. */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    /**< @brief Pointer to the state information of the async sequence. */
    P2VAR(Spi_SequenceState, SPI_VAR, SPI_APPL_DATA) AsyncCrtSequenceState;
    /**< @brief Pointer to the next async job planned for transmission. */
    VAR(Spi_JobType, SPI_VAR) AsyncNextJob;
#endif
} Spi_JobState;

/**
* @brief   This is the structure containing all the parameters needed to completely define a Job.
*
* @implements DSPI02416, DSPI02093.
*/
typedef struct
{
    /**< @brief Number of channels in the job. */
    VAR(Spi_ChannelType, SPI_VAR) NumChannels;
    /**< @brief Channel index list. */
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) ChannelIndexList;
    /**< @brief Job end notification. */
    P2FUNC(Spi_NotifyType, SPI_VAR, EndNotification);
    /**< @brief Job start notification. */
    P2FUNC(Spi_NotifyType, SPI_VAR, StartNotification);
    /**< @brief Priority. */
    VAR(sint8, SPI_VAR) Priority;
    /**< @brief Implementation specific field referencing the channel internal state. */
    P2VAR(Spi_JobState, SPI_VAR, SPI_APPL_DATA) JobState;
    /**< @brief HWUnit. */
    VAR(Spi_HWUnitType, SPI_VAR) HWUnit;
    /**< @brief HW Unit offset. */
    VAR(uint32, SPI_VAR) HWoffset;
    /**< @brief ExternalDevice. */
    VAR(Spi_ExternalDeviceType, SPI_VAR) ExternalDevice;
    /**< @brief Implementation specific field: cached LLD device attributes. */
    VAR(Spi_LLD_DeviceAttributesConfig, SPI_VAR) ExternalDeviceAttrs;
} Spi_JobConfig;

/**
* @brief   The structure contains the pointers to the Tx/Rx memory locations for the given buffer (IB or EB).
*
* @implements DSPI02404.
*/
typedef struct
{
    /**< @brief Transmit buffer pointer. */
    P2VAR(Spi_DataType, SPI_VAR, SPI_APPL_DATA) BufferTX;
    /**< @brief Receive buffer pointer. */
    P2VAR(Spi_DataType, SPI_VAR, SPI_APPL_DATA) BufferRX;
} Spi_BufferDescriptor;

/**
* @brief   Internal structure used to manage the channel state.
*
* @implements DSPI02407.
*/
typedef struct
{
    VAR(uint8, SPI_VAR) Flags;                 /**< @brief Default Transmit Enabled. */
    VAR(Spi_NumberOfDataType, SPI_VAR) Length; /**< @brief Actual Transfer size for EB. */
} Spi_ChannelState;

/**
* @brief   The structure contains the channel configuration parameters.
*
* @implements DSPI02406.
*/
typedef struct
{
    /**< @brief Buffer Type IB/EB. */
    VAR(Spi_BufferType, SPI_VAR) BufferType;
    /**< @brief Default Transmit Value. */
    VAR(Spi_DataType, SPI_VAR) DefaultTransmitValue;
    /**< @brief Data length. */
    VAR(Spi_NumberOfDataType, SPI_VAR) Length;
    /**< @brief Buffer Descriptor. */
    P2CONST(Spi_BufferDescriptor, SPI_VAR, SPI_APPL_CONST) BufferDescriptor;
    /**< @brief Implementation specific field referencing the channel internal state. */
    P2VAR(Spi_ChannelState, SPI_VAR, SPI_APPL_DATA) ChannelState;
} Spi_ChannelConfig;

/*---------------------------------------------------------------------------
*             SPI Driver Low Level Implementation Specific Type Definitions
-----------------------------------------------------------------------------*/

/**
* @brief   This structure holds the HWUnit configuration parameters.
*
* @implements DSPI02413.
*/
typedef struct
{
    /**< @brief DSPI HWunit physical offset on SOC. */
    VAR(uint8, SPI_VAR) Offset;
    /**< @brief Slave Mode - enabled  */
    VAR(uint8, SPI_VAR)SpiPhyUnitMode;
    /**< @brief Indicates if the HW unit is configured as Sync or Async. */
    VAR(uint32, SPI_VAR) IsSync;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
    /**< @brief Boolean flag indicating if DMA will be used or not for this DSPI unit. */
    VAR(uint16, SPI_VAR) UseDma;
    /**< @brief Master TX DMA channel - enabled by the DSPI TX source. */
    VAR(uint8, SPI_VAR) TxDmaChannel;
    /**< @brief Auxiliary TX DMA channel - triggered by the master TX Dma. */
    VAR(uint8, SPI_VAR) TxDmaChannelAux;
    /**< @brief RX DMA channel - enabled by the DSPI RX source. */
    VAR(uint8, SPI_VAR) RxDmaChannel;
#endif
#endif
} Spi_HWUnitConfig;

/*---------------------------------------------------------------------------
*             SPI Driver Configuration Main Structure
-----------------------------------------------------------------------------*/
/**
* @brief   This is the top level structure containing all the needed parameters for the SPI Handler/Driver.
*
* @implements DSPI02409.
*/
typedef struct
{
    /**< @brief Number of external devices defined in the configuration. */
    VAR(uint16, SPI_VAR) Spi_Max_ExternalDevice;
    /**< @brief Number of channels defined in the configuration. */
    VAR(Spi_ChannelType, SPI_VAR) Spi_Max_Channel;
    /**< @brief Number of jobs defined in the configuration. */
    VAR(Spi_JobType, SPI_VAR) Spi_Max_Job;
    /**< @brief Number of sequences defined in the configuration. */
    VAR(Spi_SequenceType, SPI_VAR) Spi_Max_Sequence;
    /**< @brief Array of channels defined in the configuration. */
    P2CONST(Spi_ChannelConfig, SPI_VAR, SPI_APPL_CONST) ChannelConfig;
    /**< @brief Array of jobs defined in the configuration. */
    P2CONST(Spi_JobConfig, SPI_VAR, SPI_APPL_CONST) JobConfig;
    /**< @brief Array of sequences defined in the configuration. */
    P2CONST(Spi_SequenceConfig, SPI_VAR, SPI_APPL_CONST) SequenceConfig;
    /**< @brief Channel & DSPI HW unit attributes. */
    P2CONST(Spi_AttributesConfig, SPI_VAR, SPI_APPL_CONST) AttributesConfig;
    /**< @brief Array of LLD DSPI device instances. */
    P2CONST(Spi_HWUnitConfig, SPI_VAR, SPI_APPL_CONST) HWUnitConfig;
    /** 
     * @brief SPI Driver DEM Error: SPI_E_HARDWARE_ERROR
     *
     */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    CONST(Mcal_DemErrorType, SPI_CONST) Spi_E_Hardware_ErrorCfg;
#endif
} Spi_ConfigType;

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)

/**
* @brief   This structure holds the TSB configuration parameters.
*
* @implements DSPI02484.
*/
typedef struct
{
    /**< @brief JobId of the configured TSB job. */
    VAR(Spi_JobType, SPI_VAR) Spi_TSB_Job;
    /**< @brief This structure holds the TSB mode selection on HWUnits. */
    VAR(Spi_LLD_TSBAttributesConfig, SPI_VAR) ExternalDeviceTSBAttrs;
} Spi_TSBConfig;
#endif
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifndef SPI_PRECOMPILE_SUPPORT
 /*
* @violates @ref Spi_h_REF_4 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"

extern P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) SpiConfigPtr;
 /*
* @violates @ref Spi_h_REF_4 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"

 /*
* @violates @ref Spi_h_REF_4 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief Spi State
*/
/* @violates @ref Spi_h_REF_5 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Spi_JobState, SPI_VAR) SpiJobState[SPI_MAX_JOB];
/* @violates @ref Spi_h_REF_5 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Spi_ChannelState, SPI_VAR) SpiChannelState[SPI_MAX_CHANNEL];
/* @violates @ref Spi_h_REF_5 Violates MISRA 2004 Required Rule 8.8, declaring an external identifier in a header file, 
* that will be included in any file where the identifier is defined or used */
extern VAR(Spi_SequenceState, SPI_VAR) SpiSequenceState[SPI_MAX_SEQUENCE];
 /*
* @violates @ref Spi_h_REF_4 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"

 /*
* @violates @ref Spi_h_REF_4 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
extern CONST(Spi_TSBConfig, SPI_CONST) SpiJobTSBConfig[SPI_MAX_TSBJOBS];
#endif
#endif

/**
* @brief Configuration structures
*/
/* @violates @ref Spi_h_REF_7 could define variable at block scope */
SPI_CFG_EXTERN_DECLARATIONS
 /*
* @violates @ref Spi_h_REF_4 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"
#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"

/**
* @brief   End Job transmission notification handler declaration.
* @details The function (global) is implemented in Spi.c (Autosar Driver Layer).
*
* @param[in]    pJobConfig   The just transmited job pointer.
*/
#if ((LEVEL2 == SPI_LEVEL_DELIVERED) || (LEVEL1 == SPI_LEVEL_DELIVERED))
extern FUNC (void, SPI_CODE) Spi_JobTransferFinished(
    P2CONST(Spi_JobConfig, AUTOMATIC, SPI_APPL_CONST) pJobConfig);
#endif

#if (SPI_VERSION_INFO_API == STD_ON)
FUNC (void, SPI_CODE) Spi_GetVersionInfo (
    P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) VersionInfo);
#endif

FUNC (void, SPI_CODE) Spi_Init(
    P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr);

FUNC (Std_ReturnType, SPI_CODE) Spi_DeInit(void);

#if ((USAGE0 == SPI_CHANNEL_BUFFERS_ALLOWED) || (USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED ))
FUNC (Std_ReturnType, SPI_CODE) Spi_WriteIB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) DataBufferPtr);

FUNC (Std_ReturnType, SPI_CODE) Spi_ReadIB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr);
#endif

#if ((LEVEL2 == SPI_LEVEL_DELIVERED) || (LEVEL1 == SPI_LEVEL_DELIVERED))
FUNC (Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(
    VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#if ( ( USAGE1 == SPI_CHANNEL_BUFFERS_ALLOWED) || \
        ( USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED)  )
FUNC (Std_ReturnType, SPI_CODE) Spi_SetupEB(
    VAR(Spi_ChannelType, AUTOMATIC) Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) SrcDataBufferPtr,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    VAR(Spi_NumberOfDataType, AUTOMATIC) Length);
#endif

FUNC (Spi_StatusType, SPI_CODE) Spi_GetStatus(void);

FUNC (Spi_JobResultType, SPI_CODE) Spi_GetJobResult(
    VAR(Spi_JobType, AUTOMATIC) Job);

FUNC (Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(
    VAR(Spi_SequenceType, AUTOMATIC) Sequence);

#if ((LEVEL2 == SPI_LEVEL_DELIVERED) || (LEVEL0 == SPI_LEVEL_DELIVERED))
FUNC (Std_ReturnType, SPI_CODE) Spi_SyncTransmit(
    VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#if (SPI_HW_STATUS_API == STD_ON)
FUNC (Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit);
#endif

#if (SPI_CANCEL_API == STD_ON)
FUNC (void, SPI_CODE) Spi_Cancel(
    VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#if (SPI_LEVEL_DELIVERED == LEVEL2)
FUNC (Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(
    VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON))
FUNC (Std_ReturnType, SPI_CODE) Spi_SetHWUnitAsyncMode(
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
    VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode);
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON) */

#if (SPI_DUAL_CLOCK_MODE == STD_ON)

FUNC (Std_ReturnType, SPI_CODE) Spi_SetClockMode(
    VAR(Spi_DualClockMode,AUTOMATIC) ClockMode);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC (void, SPI_CODE) Spi_MainFunction_Handling(void);
#endif

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)

FUNC (Std_ReturnType, SPI_CODE) Spi_TSBStart(
     VAR(Spi_JobType, AUTOMATIC) TSBJob);

FUNC (Std_ReturnType, SPI_CODE) Spi_TSBStop(
     VAR(Spi_JobType, AUTOMATIC) TSBJob);

FUNC (Std_ReturnType, SPI_CODE) Spi_TSB_ASDR_DataUpdate(
     VAR(Spi_JobType, AUTOMATIC) TSBJob,
     VAR(uint32, AUTOMATIC) ASDR_Data);

#endif /*(SPI_TSB_MODE == STD_ON)*/
#endif /*TSB_MODE_SUPPORTED*/

#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SPI_H */

/** @} */

