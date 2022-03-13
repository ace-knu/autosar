/**
*   @file    Spi_Dspi_LLD_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - DSPI Configuration LLD header file.
*   @details DSPI peripheral LLD configuration structures used by plugin generated configs.

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

#ifndef SPI_DSPI_LLD_CFGEX_H
#define SPI_DSPI_LLD_CFGEX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Spi_Dspi_LLD_CfgEx_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, This violation is not fixed since naming convention of Identifiers are followed as per Autosar
* standards, some times which may exceeds more than 31 characters.
*
* @section Spi_Dspi_LLD_CfgEx_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
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
* @implements   DSPI02049
*/
 /*
* @violates @ref Spi_Dspi_LLD_CfgEx_h_REF_2 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MAJOR_VERSION_LLD_CFGEX    4
 /*
* @violates @ref Spi_Dspi_LLD_CfgEx_h_REF_2 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_MINOR_VERSION_LLD_CFGEX    0
/*
* @violates @ref Spi_Dspi_LLD_CfgEx_h_REF_1 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
 /*
* @violates @ref Spi_Dspi_LLD_CfgEx_h_REF_2 This is required as per autosar Requirement, 
*/
#define SPI_AR_RELEASE_REVISION_VERSION_LLD_CFGEX   3
#define SPI_SW_MAJOR_VERSION_LLD_CFGEX    1
#define SPI_SW_MINOR_VERSION_LLD_CFGEX    0
#define SPI_SW_PATCH_VERSION_LLD_CFGEX    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and SPI configuration header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_LLD_CFGEX != SPI_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_MINOR_VERSION_LLD_CFGEX != SPI_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_AR_RELEASE_REVISION_VERSION_LLD_CFGEX != SPI_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Spi_Dspi_LLD_CfgEx.h and Spi_Cfg.h are different"
#endif


/* Check if source file and SPI configuration header file are of the same software version */
#if ((SPI_SW_MAJOR_VERSION_LLD_CFGEX != SPI_SW_MAJOR_VERSION_CFG) || \
     (SPI_SW_MINOR_VERSION_LLD_CFGEX != SPI_SW_MINOR_VERSION_CFG))
#error "Software Version Numbers of Spi_Dspi_LLD_CfgEx.h and Spi_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief Internal structure used to manage the channel attributes.
*
* @implements DSPI02822.
*/
typedef struct
{
    VAR(uint32, SPI_VAR) CMD; /**< @brief Channel attributes for CMD in PUSHR (selects CTAR to use). */
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    VAR(uint8, SPI_VAR)  DataWidth;       /**< @brief Channel attributes for data width. */
#endif
} Spi_LLD_ChannelAttributesConfig;

/**
* @brief Internal structure used to manage the DSPI unit attributes.
*
* @implements DSPI02823.
*/
typedef struct
{
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, SPI_VAR) CTAR[2];     /**< @brief Device attributes for CTARs. */
#else
    VAR(uint32, SPI_VAR) CTAR;        /**< @brief Device attributes for CTARs. */
#endif
    VAR(uint32, SPI_VAR) CMD;         /**< @brief Device attributes for CMD in PUSHR. */
    VAR(uint32, SPI_VAR) MCR;         /**< @brief Device CS idle setting. */
} Spi_LLD_DeviceAttributesConfig;

/**
* @brief Internal structure used to manage LLD attributes.
*
* @implements DSPI02821.
*/
typedef struct
{
    P2CONST(Spi_LLD_ChannelAttributesConfig, SPI_VAR, SPI_APPL_CONST)
                ChannelAttributesConfig;   /**< @brief Array of configuration channel attributes. */
    P2CONST(Spi_LLD_DeviceAttributesConfig, SPI_VAR, SPI_APPL_CONST)
                DeviceAttributesConfig;  /**< @brief Array of DSPI units attributes. */
} Spi_AttributesConfig;

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
/**
* @brief Internal structure used to manage the TSB attributes.
*
* @implements DSPI02484.
*/
typedef struct
{
    VAR(uint32, SPI_VAR) DSICR;    /**< @brief Device attributes for DSICR. */
    VAR(uint32, SPI_VAR) DSICR1;   /**< @brief Device attributes for DSICR1. */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, SPI_VAR) CTAR[2];
#else
    VAR(uint32, SPI_VAR) CTAR;
#endif
} Spi_LLD_TSBAttributesConfig;
#endif /*SPI_TSB_MODE == STD_ON*/
#endif /*TSB_MODE_SUPPORTED*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* Spi_Dspi_LLD_CfgEx_H */

/** @} */

