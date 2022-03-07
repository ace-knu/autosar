/**
*   @file    Spi_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Pre-Compile (PC) configuration data code template.
*   @details Code template for Pre-Compile(PC) configuration file generation.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Spi_Cfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_Cfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_Cfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* This violation is not fixed since naming convention of Identifiers are followed as per Autosar
* standards, some times which may exceeds more than 31 characters.
*
* @section Spi_Cfg_c_REF_4
* Violates MISRA 2004 Required Rule 10.1,
* The value of an expression of integer type shall not be implicitly
* converted to a different underlying type
*
* @section Spi_Cfg_c_REF_5
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
/*
* @file           Spi_Cfg.c
* @implements     DSPI02635.
*/
#include "Spi.h"
#include "Reg_eSys_DSPI.h"


#if (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE)

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/
/**
* @file         Spi_Cfg.c
* @implements   DSPI02049
*/
/*
* @violates @ref Spi_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/

#define SPI_MODULE_ID_CFG_C                        83
#define SPI_VENDOR_ID_CFG_C                        43
/*
* @violates @ref Spi_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_CFG_C         4
/*
* @violates @ref Spi_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MINOR_VERSION_CFG_C         0
/*
* @violates @ref Spi_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_REVISION_VERSION_CFG_C      3
#define SPI_SW_MAJOR_VERSION_CFG_C                 1
#define SPI_SW_MINOR_VERSION_CFG_C                 0
#define SPI_SW_PATCH_VERSION_CFG_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID_CFG_C != SPI_VENDOR_ID_CFG)
    #error "Spi_Cfg.c and Spi_Cfg.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_CFG_C    != SPI_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_MINOR_VERSION_CFG_C    != SPI_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_REVISION_VERSION_CFG_C != SPI_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Spi_Cfg.c and Spi_Cfg.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_CFG_C != SPI_SW_MAJOR_VERSION_CFG) || \
     (SPI_SW_MINOR_VERSION_CFG_C != SPI_SW_MINOR_VERSION_CFG) || \
     (SPI_SW_PATCH_VERSION_CFG_C != SPI_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Spi_Cfg.c and Spi_Cfg.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_Cfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* Job start Notifications */

/* Job End Notifications */

/* Sequence End Notifications */

#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_Cfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Cfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*  Buffers Descriptors for EB Channels (if any) */
static VAR(Spi_BufferDescriptor, SPI_VAR) Buffer_PCSpiChannel_L99MC6;
static VAR(Spi_BufferDescriptor, SPI_VAR) Buffer_PCSpiChannel_MC33972;

/* Allocate Buffers for IB Channels (if any) */


 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_Cfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_Cfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"

/*  Buffers Descriptors for IB Channels (if any) */

/* Channel Configuration */
static CONST(Spi_ChannelConfig, SPI_CONST) SpiChannelConfig_PC[2] =
{
    {
        /* SpiChannel_L99MC6*/
        EB,
        255U,
        2U,
        &Buffer_PCSpiChannel_L99MC6,
        &SpiChannelState[0]
    },
    {
        /* SpiChannel_MC33972*/
        EB,
        1U,
        3U,
        &Buffer_PCSpiChannel_MC33972,
        &SpiChannelState[1]
    }

};

/* Channel to Job Assignment */

 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_L99MC6_1_ChannelAssignment_PC[1] = {SpiConf_SpiChannel_SpiChannel_L99MC6};
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_L99MC6_2_ChannelAssignment_PC[1] = {SpiConf_SpiChannel_SpiChannel_L99MC6};
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_MC33972_1_ChannelAssignment_PC[1] = {SpiConf_SpiChannel_SpiChannel_MC33972};
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_MC33972_2_ChannelAssignment_PC[1] = {SpiConf_SpiChannel_SpiChannel_MC33972};

/* Job Configuration */
static CONST(Spi_JobConfig, SPI_CONST) SpiJobConfig_PC[4] =
{
    {
        /* SpiJob_L99MC6_1 */
        (Spi_ChannelType)1u,
        SpiJob_L99MC6_1_ChannelAssignment_PC, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &SpiJobState[0], /* JobState instance */
        CSIB0, /* HWUnit index */
        DSPI_0_OFFSET, /* DSPI device HW unit offset */
        /* External Device Settings */
        SpiExternalDevice_L99MC6_1, /* External Device */
        {
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_2 | DSPI_CTAR_SBR_64 | DSPI_CTAR_DBR_0), /* Baudrate: Should=500000.0, Is=500000, Error=0.0% */
            (uint32)(DSPI_CMD_PCS0 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
                }
    },
    {
        /* SpiJob_L99MC6_2 */
        (Spi_ChannelType)1u,
        SpiJob_L99MC6_2_ChannelAssignment_PC, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &SpiJobState[1], /* JobState instance */
        CSIB0, /* HWUnit index */
        DSPI_0_OFFSET, /* DSPI device HW unit offset */
        /* External Device Settings */
        SpiExternalDevice_L99MC6_2, /* External Device */
        {
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_2 | DSPI_CTAR_SBR_64 | DSPI_CTAR_DBR_0), /* Baudrate: Should=500000.0, Is=500000, Error=0.0% */
            (uint32)(DSPI_CMD_PCS1 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
                }
    },
    {
        /* SpiJob_MC33972_1 */
        (Spi_ChannelType)1u,
        SpiJob_MC33972_1_ChannelAssignment_PC, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &SpiJobState[2], /* JobState instance */
        CSIB1, /* HWUnit index */
        DSPI_1_OFFSET, /* DSPI device HW unit offset */
        /* External Device Settings */
        SpiExternalDevice_MC33972_1, /* External Device */
        {
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_5 | DSPI_CTAR_SBR_2 | DSPI_CTAR_DBR_0), /* Baudrate: Should=6000000.0, Is=6400000, Error=6.67% */
            (uint32)(DSPI_CMD_PCS0 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
                }
    },
    {
        /* SpiJob_MC33972_2 */
        (Spi_ChannelType)1u,
        SpiJob_MC33972_2_ChannelAssignment_PC, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        &SpiJobState[3], /* JobState instance */
        CSIB1, /* HWUnit index */
        DSPI_1_OFFSET, /* DSPI device HW unit offset */
        /* External Device Settings */
        SpiExternalDevice_MC33972_2, /* External Device */
        {
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_5 | DSPI_CTAR_SBR_2 | DSPI_CTAR_DBR_0), /* Baudrate: Should=6000000.0, Is=6400000, Error=6.67% */
            (uint32)(DSPI_CMD_PCS1 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
                }
    }

};

/* Job to Sequence Assignment */
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_JobType, SPI_CONST) SpiSequence_L99MC6_1_JobAssignment_PC[1] = {SpiConf_SpiJob_SpiJob_L99MC6_1};
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_JobType, SPI_CONST) SpiSequence_L99MC6_2_JobAssignment_PC[1] = {SpiConf_SpiJob_SpiJob_L99MC6_2};
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_JobType, SPI_CONST) SpiSequence_MC33972_1_JobAssignment_PC[1] = {SpiConf_SpiJob_SpiJob_MC33972_1};
 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
static CONST(Spi_JobType, SPI_CONST) SpiSequence_MC33972_2_JobAssignment_PC[1] = {SpiConf_SpiJob_SpiJob_MC33972_2};

/* Sequence Configuration */
static CONST(Spi_SequenceConfig, SPI_CONST) SpiSequenceConfig_PC[4] =
{
    {  /* SpiSequence_L99MC6_1 */
        (Spi_JobType)1u,
        SpiSequence_L99MC6_1_JobAssignment_PC, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE/* Interruptible */
    },
    {  /* SpiSequence_L99MC6_2 */
        (Spi_JobType)1u,
        SpiSequence_L99MC6_2_JobAssignment_PC, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE/* Interruptible */
    },
    {  /* SpiSequence_MC33972_1 */
        (Spi_JobType)1u,
        SpiSequence_MC33972_1_JobAssignment_PC, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE/* Interruptible */
    },
    {  /* SpiSequence_MC33972_2 */
        (Spi_JobType)1u,
        SpiSequence_MC33972_2_JobAssignment_PC, /* List of Jobs */
        NULL_PTR, /* End Notification */
        (uint8)FALSE/* Interruptible */
    }

};

/*---------------------------------------------------------------------------
*            SPI Driver Implementation Specific Configuration
-----------------------------------------------------------------------------*/

/* DspiChannelAttributesConfig_PC0 Channel Attribute Configuration of Spi*/
static CONST(Spi_LLD_ChannelAttributesConfig, SPI_CONST) DspiChannelAttributesConfig_PC[2] =
{
    {(uint32)(DSPI_CMD_MSB | DSPI_CMD_WIDTH_8)},
    {(uint32)(DSPI_CMD_MSB | DSPI_CMD_WIDTH_8)}

};

/* DspiDeviceAttributesConfig_PC0 Device Attribute Configuration of Spi*/
static CONST(Spi_LLD_DeviceAttributesConfig, SPI_CONST) DspiDeviceAttributesConfig_PC[4] =
{
    {  /* SpiExternalDevice_L99MC6_1 */
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_2 | DSPI_CTAR_SBR_64 | DSPI_CTAR_DBR_0), /* Baudrate: Should=500000.0, Is=500000, Error=0.0% */
            (uint32)(DSPI_CMD_PCS0 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
    },
    {  /* SpiExternalDevice_L99MC6_2 */
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_2 | DSPI_CTAR_SBR_64 | DSPI_CTAR_DBR_0), /* Baudrate: Should=500000.0, Is=500000, Error=0.0% */
            (uint32)(DSPI_CMD_PCS1 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
    },
    {  /* SpiExternalDevice_MC33972_1 */
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_5 | DSPI_CTAR_SBR_2 | DSPI_CTAR_DBR_0), /* Baudrate: Should=6000000.0, Is=6400000, Error=6.67% */
            (uint32)(DSPI_CMD_PCS0 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
    },
    {  /* SpiExternalDevice_MC33972_2 */
            (uint32)(DSPI_CTAR_CPOL_LOW| /* Clock Polarity (Idle State) */
            DSPI_CTAR_CPHA_TRAILING| /* Clock Phase */
            DSPI_CTAR_PCSCLK_1 | DSPI_CTAR_SCSCLK_64 | /* TimeCs2Clk: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PASC_1 | DSPI_CTAR_SASC_64 | /* TimeClk2Cs: Should=1000, Is=1000, Error=0.0% */
            DSPI_CTAR_PDT_3 | DSPI_CTAR_SDT_128 | /* TimeCs2Cs: Should=6400, Is=6000, Error=-6.25% */
            DSPI_CTAR_PBR_5 | DSPI_CTAR_SBR_2 | DSPI_CTAR_DBR_0), /* Baudrate: Should=6000000.0, Is=6400000, Error=6.67% */
            (uint32)(DSPI_CMD_PCS1 | /* Chip Select Pin */
            DSPI_CMD_CONTINOUS_TRUE), /* Continous chip select */
        (uint32)0u  /* Chip select polarity */
    }
};

static CONST(Spi_AttributesConfig, SPI_CONST) SpiAttributesConfig_PC = {
     DspiChannelAttributesConfig_PC,
     DspiDeviceAttributesConfig_PC
};

/* Array of DSPI Unit configurations */
static CONST(Spi_HWUnitConfig, SPI_CONST) HWUnitConfig_PC[SPI_MAX_HWUNIT] =
{
    { DSPI_0_OFFSET, (uint8)SPI_MASTER, SPI_PHYUNIT_SYNC },
    { DSPI_1_OFFSET, (uint8)SPI_MASTER, SPI_PHYUNIT_SYNC }
};

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
/* Driver Configuration */
CONST(Spi_ConfigType, SPI_CONST) SpiDriverConfig_PC =
{
    4u,
    2u,
    4u,
    4u,
    SpiChannelConfig_PC,
    SpiJobConfig_PC,
    SpiSequenceConfig_PC,
    &SpiAttributesConfig_PC,
    HWUnitConfig_PC,
    /**
    * @brief   DEM error parameters
    */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    { (uint32)STD_ON, 12U} /* SPI_E_HARDWARE_ERROR parameters*/ 
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */  
};

 /*
* @violates @ref Spi_Cfg_c_REF_5 This is required as per autosar Requirement, 
*/
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Spi_Cfg_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Cfg_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "MemMap.h"


#endif  /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */

#ifdef __cplusplus
}
#endif

/** @} */
