/**
*   @file    Spi_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Spi low level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
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

#ifndef SPI_LLD_H
#define SPI_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Spi_LLD_h_REF_1
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
/**
* @file           Spi_LLD.h
*/

#include "Spi_Dspi_LLD.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Spi_LLD.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define SPI_LLD_MODULE_ID                       83
#define SPI_LLD_VENDOR_ID                       43
 /*
* @violates @ref Spi_LLD_h_REF_1 This is required as per autosar Requirement, 
*/
#define SPI_LLD_AR_RELEASE_MAJOR_VERSION        4
 /*
* @violates @ref Spi_LLD_h_REF_1 This is required as per autosar Requirement, 
*/
#define SPI_LLD_AR_RELEASE_MINOR_VERSION        0
 /*
* @violates @ref Spi_LLD_h_REF_1 This is required as per autosar Requirement, 
*/
#define SPI_LLD_AR_RELEASE_REVISION_VERSION     3
#define SPI_LLD_SW_MAJOR_VERSION                1
#define SPI_LLD_SW_MINOR_VERSION                0
#define SPI_LLD_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

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


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SPI_LLD_H*/

/** @} */
