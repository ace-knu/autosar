/**
*   @file    Spi_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
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

#ifndef SPI_CFG_H
#define SPI_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Spi_Cfg_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by
* other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_Cfg_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
* @section Spi_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 19.4, This violation cannot be fixed since function and variables
* cannot be declared and defined within braces.
* For example:
* #define var  (variable)
* int var;
* In the above scenario, the var is replaced with (variable) i.e. it will become int (variable); ->This
* is not the syntax for variable declaration.
*
* @section Spi_Cfg_h_REF_5
* Violates MISRA 2004 Required Rule 1.4,
* This violation is not fixed since naming convention of Identifiers are followed as per Autosar
* standards, some times which may exceeds more than 31 characters.
*
* @section Spi_Cfg_h_REF_6
* Violates MISRA 2004 Required Rule 20.2,
* This violation is not fixed since we have not used any Standard library macros.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file           Spi_Cfg.h
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Spi_Cfg.h
* @implements   DSPI02049
*/
#define SPI_MODULE_ID_CFG                       83
#define SPI_VENDOR_ID_CFG                       43
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_CFG        4
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MINOR_VERSION_CFG        0
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_CFG     3
#define SPI_SW_MAJOR_VERSION_CFG                1
#define SPI_SW_MINOR_VERSION_CFG                0
#define SPI_SW_PATCH_VERSION_CFG                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/



/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/



/**
* @brief Switches the Development Error functionality ON or OFF.
* @details Switches the Development Error Detection and Notification ON or OFF.
* @implements DSPI02020.
*/
#define SPI_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief Switches the Version Information API functionality ON or OFF.
* @details Switches the Spi_GetVersionInfo function ON or OFF.
* @implements DSPI02024.
*/
#define SPI_VERSION_INFO_API           (STD_ON)

/**
* @brief Switches the Interruptible Sequences handling functionality ON or OFF.
* @details This parameter depends on SPI_LEVEL_DELIVERED value.
*        It is only used for SPI_LEVEL_DELIVERED configured to 1 or 2.
* @implements DSPI02022.
*/
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED  (STD_OFF)

/**
* @brief Switches the Spi_GetHWUnitStatus function ON or OFF.
* @details Switches the Spi_GetHWUnitStatus function ON or OFF.
* @implements DSPI02021
*/
#define SPI_HW_STATUS_API          (STD_ON)

/**
* @brief Switches the Spi_Cancel function ON or OFF.
* @details Switches the Spi_Cancel function ON or OFF. (see chapter 8.3.13)
* @implements DSPI02018
*/
#define SPI_CANCEL_API             (STD_ON)

/* Only Internal Buffers are allowed in Handler/Driver.*/
#define USAGE0                          0x00u

/* Only External Buffers are allowed in Handler/Driver.*/
#define USAGE1                          0x01u

/* Both Buffer types are allowd in Handler/Driver. */
#define USAGE2                          0x02u

/* Derive the CTAR used */
#define SPI_CTAR_USED                   ((uint32)3u)

/**
* @brief Selects the SPI Handler/Driver Channel Buffers usage allowed and delivered.
* @details Selects the SPI Handler/Driver Channel Buffers usage allowed and delivered.
*        (see chapter 7.2.1)
* @implements DSPI02019
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED    (USAGE2)

/* The LEVEL 0 Simple Synchronous SPI Handler/Driver functionalities are selected.*/
#define LEVEL0                          0x00u

/* The LEVEL 1 Basic Asynchronous SPI Handler/Driver functionalities are selected.*/
#define LEVEL1                          0x01u

/* The LEVEL 2 Enhanced SPI Handler/Driver functionalities are selected. */
#define LEVEL2                          0x02u

/**
* @brief Selects the SPI Handler/Driver level of scalable functionality.
* @details Selects the SPI Handler/Driver level of scalable functionality that
* is available and delivered. (see chapter 7.1)
* @implements DSPI02023.
*/
#define SPI_LEVEL_DELIVERED            (LEVEL2)

/**
* @brief Defines the maximum number of supported channels.
* @details Defines the maximum number of supported channels
*     for all the driver configurations.
* @implements DSPI02045.
*/
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiChannel_SpiChannel_L99MC6    ((Spi_ChannelType)0)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiChannel_SpiChannel_MC33972    ((Spi_ChannelType)1)
#define SPI_MAX_CHANNEL  ((Spi_ChannelType)2)

/**
* @brief Total number of Jobs configured.
* @details Defines the maximum number of supported jobs
*     for all the driver configurations.
* @implements DSPI02045
*/
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiJob_SpiJob_L99MC6_1   ((Spi_JobType)0)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiJob_SpiJob_L99MC6_2   ((Spi_JobType)1)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiJob_SpiJob_MC33972_1   ((Spi_JobType)2)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiJob_SpiJob_MC33972_2   ((Spi_JobType)3)
#define SPI_MAX_JOB     ((Spi_JobType)4)

/**
* @brief Total number of Sequences configured.
* @details Defines the maximum number of supported sequences
*     for all the driver configurations.
* @implements DSPI02045.
*/
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiSequence_SpiSequence_L99MC6_1   ((Spi_SequenceType)0)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiSequence_SpiSequence_L99MC6_2   ((Spi_SequenceType)1)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiSequence_SpiSequence_MC33972_1   ((Spi_SequenceType)2)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SpiConf_SpiSequence_SpiSequence_MC33972_2   ((Spi_SequenceType)3)
#define SPI_MAX_SEQUENCE  ((Spi_SequenceType)4)


/**
* @brief Defines the peripherals used throughout the configuration(s).
* @details Defines the peripherals used throughout the configuration(s).
* @implements DSPI02056.
*/
#define CSIB0  ((uint8)0u)
#define CSIB1  ((uint8)1u)
#define SPI_MAX_HWUNIT   2u

/**
* @brief Physical HWUnits definition - as from resource manager.
* @details Physical HWUnits definition - as from resource manager.
* @implements DSPI02080.
*/

#define DSPI_0_HWUNIT   (CSIB0)
#define DSPI_1_HWUNIT   (CSIB1)

/**
* @brief Physical HWUnits enabled/disabled
* @details Physical HWUnits enabled/disabled
*/
#define DSPI_0_ENABLED  (STD_ON)
#define DSPI_1_ENABLED  (STD_ON)
#define DSPI_2_ENABLED  (STD_OFF)
#define DSPI_3_ENABLED  (STD_OFF)
#define DSPI_4_ENABLED  (STD_OFF)
#define DSPI_5_ENABLED  (STD_OFF)
#define SPI_SLAVE_SUPPORT  (STD_OFF)

#define DSPI_0_OFFSET  0u
#define DSPI_1_OFFSET  1u

#define SPI_FIFO_SIZE   ((uint8)4u)

/**
* @brief Defines the external devices the driver will use.
* @details Reference to the external device used by this job.
* @implements DSPI02039.
*/
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_6 This is not a standard library macro, 
*/
#define SpiExternalDevice_L99MC6_1  ((Spi_ExternalDeviceType)0u)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_6 This is not a standard library macro, 
*/
#define SpiExternalDevice_L99MC6_2  ((Spi_ExternalDeviceType)1u)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_6 This is not a standard library macro, 
*/
#define SpiExternalDevice_MC33972_1  ((Spi_ExternalDeviceType)2u)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_6 This is not a standard library macro, 
*/
#define SpiExternalDevice_MC33972_2  ((Spi_ExternalDeviceType)3u)

/**
* @brief   Switches the Production Error Detection and Notification OFF
*
* @implements     DSPI02626
* 
* @api
*/

 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
#define SPI_DISABLE_DEM_REPORT_ERROR_STATUS   (STD_ON  /* Enable Production Error Detection */)

/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Define values for Autosar configuration variants.
* @details Define values for Autosar configuration variants.
*/
#define SPI_VARIANT_PRECOMPILE  (0)
#define SPI_VARIANT_POSTBUILD   (1)
#define SPI_VARIANT_LINKTIME    (2)


/**
* @brief Defines the use of Post-Build(PB) support.
* @details VARIANT-POST-BUILD: Parameters with "Pre-compile time",
*        "Link time" and "Post-build time" are allowed in this variant.
* @implements DSPI02622.
*/
#define SPI_CONFIG_VARIANT      (SPI_VARIANT_POSTBUILD)
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/* @violates @ref Spi_Cfg_h_REF_4 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define SPI_CFG_EXTERN_DECLARATIONS \
extern CONST(Spi_ConfigType, SPI_CONST) SpiDriver_0;

/**
* @brief Defines if transfers are made using DMA or FIFO.
* @details Defines if transfers are made using DMA or FIFO.
* @implements DSPI02052.
*/
#define SPI_DMA_USED    (STD_OFF)

/**
* @brief Defines if Spi driver optimization for sequences having only one job is activated or not.
* @details Defines if Spi driver optimization for sequences having only one job is activated or not.
*        If activated, additional RAM memory is required for internal data caching.
* @implements DSPI02053.
*/
#define SPI_OPTIMIZE_ONE_JOB_SEQUENCES (STD_OFF)

/**
* @brief Number of CPU clock cycles consumed by Spi_SyncTransmit() during the wait on TX/RX transmission.
* @details This value is set to the minimum measure retrieved for GHS, DIAB and CW compilers,
*       with all optimizations activated.
*/
#define SPI_WAIT_LOOP_TICKS       23u

/**
* @brief Defines the "Number of Loops" timeout.
* @details Defines the "Number of Loops" timeout used by Spi_SyncTransmit
*        function during the wait on TX/RX transmission.
*/
#define SPI_TIMEOUT_COUNTER       ((uint32)((3200000u) / SPI_WAIT_LOOP_TICKS))

/**
* @brief Allow simultaneous calls to Spi_SyncTransmit() for different threads.
* @details Two concurrent calls to Spi_SyncTransmit() will be allowed only if the related sequences
*       do not share HW units.
* @implements DSPI02065.
*/
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT             (STD_OFF)
/*==================================================================================================
 *                                           Non AUTOSAR DEFINES
==================================================================================================*/

/**
* @brief If enabled, the asyncronous operation mode (POLLING or INTERRUPT)
* @details If enabled, the asyncronous operation mode (POLLING or INTERRUPT) can
*       be defined independently for each HWUnit using Spi_SetHWUnitAsyncMode().
* @implements DSPI02064.
*/
#define SPI_HWUNIT_ASYNC_MODE (STD_OFF)

/**
* @brief If enabled, allows dual MCU clock configuration settings.
* @details If enabled, allows dual MCU clock configuration settings.
* @implements DSPI02063.
*/
#define SPI_DUAL_CLOCK_MODE (STD_OFF)

/**
* @brief   Specifies if TSB implementation is supported
*/

/**
* @brief   Specifies if TSB feature/mode is available
*/
#define SPI_TSB_MODE (STD_OFF)


/**
* @brief If enabled, allows to configure more than 256 sequences, jobs and channels.
*/
#define SPI_ALLOW_BIGSIZE_COLLECTIONS (STD_OFF)

/**
* @brief If enabled, SpiDataType is declared as uint8 instead of uint16.
*/
#define SPI_DATA_WIDTH_8  0u
#define SPI_DATA_WIDTH_16 1u
#define SPI_FORCE_DATA_TYPE (STD_OFF)


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_Cfg_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

 /*
* @violates @ref Spi_Cfg_h_REF_3 This is required as per autosar Requirement, 
*/
/*
* @violates @ref Spi_Cfg_h_REF_5 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_Cfg_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SPI_CFG_H*/

/** @} */
