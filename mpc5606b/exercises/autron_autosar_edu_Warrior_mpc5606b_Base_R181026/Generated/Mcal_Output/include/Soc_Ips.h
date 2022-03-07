/**
*   @file    Soc_Ips.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - IP module versions.
*   @details The IP modules versions used on PA hardware platform and
*            IP specific defines
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : XPC560XB
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
/**
* @file        Soc_Ips.h
* @implements DBASE11000
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Soc_Ips_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Soc_Ips_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*/

#ifndef SOC_IPS_H
#define SOC_IPS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file        Soc_Ips.h
* @brief Include platform types
*/
/*
* @violates @ref Soc_Ips_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Platform_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/**
@brief FLASH IP Version: STA1_FLH9_1568K_C90FG@v2.6.i on Bolero 1.5M
@details XPC560XB IP Versions
@remarks Implements DBASE11001
*/
#define IPV_FLASH               (0x15361669UL)
/**
@brief LINFLEX IP Version: LINFLEX2_IPS v0.18.a
@details XPC560XB IP Version
@remarks Implements DBASE11001
*/
#define IPV_LINFLEX             (0x00001200UL)
/**
* @brief ECSM IP (Platform B1.5M) Version: rpp_z0h_bolero1M5.01.00.00.09
* @details XPC560XB IP Versions
* @implements DBASE11001
*/
#define IPV_ECSM                (0x01000009UL)
/**
@brief WKUP IP Version: WKUP_01_00_10_01
@details XPC560XB IP Versions
@remarks Implements DBASE11001
*/
#define IPV_WKUP                 (0x01001001UL)
/**
@brief SIUL IP Version: siul.01.00.01.17
@details XPC560XB IP Versions
@remarks Implements DBASE11001
*/
#define IPV_SIUL                 (0x01000117UL)
/**
@brief Workaround implemented for Errata e2977
@details MC_RGM: Long Reset Sequence Occurs on 'Short Functional' Reset Event
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define ERR_IPV_MC_0019       (STD_ON)

/** 
* @brief           Defines the ADCDIG IP version for Bolero 1.5M.
*/
#define IPV_ADCDIG  (0x30901UL)  /* 3.9.a */
/** 
* @brief           Defines the CTU IP version for Bolero 1.5M.
*/
#define IPV_CTU     (0x301UL)    /* 0.3.a */

/**
* @brief Number of eMIOS modules
* @details XPC560XB Platform Defines/Configurations
*/
/*@violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, */
#define EMIOS_NB_MODULES                 (0x02U)

/**
@brief Workaround implemented for Errata e4186
@details ADCDIG: triggering an ABORT or ABORTCHAIN before the conversion starts
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define  ERR_IPV_ADCDIG_0014 (STD_ON)

/**
@brief Workaround implemented for Errata e4146
@details ADCDIG:  If CTU chain injected in CTU trigger mode, current normal chain
               aborted channel might not be restored back
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define  ERR_IPV_ADCDIG_0015 (STD_ON)
/**
@brief Number of DMA controllers available
@details XPC560XB Platform Defines/Configurations
*/
#define DMA_NB_CONTROLLERS           (0x01U)
/**
@brief Number of DMA channels available
@details XPC560XB Platform Defines/Configurations
*/
#define DMA_NB_CHANNELS              (0x10U)
/**
@brief Number of DMA_MUX channels
@details XPC560XB Platform Defines/Configurations
*/
#define DMAMUX_NB_CHANNELS           (DMA_NB_CHANNELS)
/**
* @brief Mask used to select the DMA controller for a given channel
*/
#define DMA_CTRL_MAX_CHANNELS_MASK       (0x0FU)

/**
* @brief Define to identify max number of channels per DMA controller 
*/ 
#define DMA_CTRL_MAX_CHANNELS            (0x10U)

/**
* @brief Number of STM modules
* @details XPC560XB Platform Defines/Configurations
*/
#define STM_NB_MODULES                   (0x01U)

/**
@{
@brief Defines which AutoSAR drivers use the common eDMA IP driver
*/
#define LIN_USE_DMA_LLD         (STD_OFF)
#define ADC_USE_DMA_LLD         (STD_ON)
#define SPI_USE_DMA_LLD         (STD_ON)
#define MCU_USE_DMA_LLD         (STD_ON)
#define ICU_USE_DMA_LLD         (STD_ON)
#define PWM_USE_DMA_LLD         (STD_OFF)
/**@}*/


/**
@brief EMIOS interrupts are handled by common ISRs
@details XPC560XB Platform specific Defines/Configurations for EMIOS
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define EMIOS_COMMON_ISR_HANDLER     (STD_ON)
/**
@brief EMIOS UCDIS register is available
@details XPC560XB Platform specific Defines/Configurations for EMIOS
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define EMIOS_UCDIS_AVAILABLE        (STD_ON)

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
@brief Workaround implemented for Errata e3190
@details MC_ME: Main VREG not disabled during STOP0 or HALT0 mode if RUN[0..3] mode
         selects FXOSC to be running and target mode selects FXOSC as system clock.
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define ERR_IPV_MC_0015 (STD_ON)
/**
@brief Workaround implemented for Errata e3570
@details Configures the MCU to avoid the machine check interrupt that could
             lead to a checkstop reset (if flash is powered down in low power mode)

*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define ERR_IPV_MC_0017 (STD_ON)
/**
@brief Workaround implemented for Errata e3476/e2958
@details MC_RGM: Clearing a flag at RGM_DES or RGM_FES register may
            be prevented by a reset
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define ERR_IPV_MC_0004 (STD_ON)
/**
@brief Workaround implemented for Errata e3060
@details MC_RGM: SAFE mode exit may be possible even though condition
            causing the SAFE mode
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define ERR_IPV_MC_0009  (STD_ON)

/**
@brief Workaround implemented for Errata e6976
@details MC_ME: SAFE mode not entered immediately on hardware-triggered SAFE mode request
            during STOP0 mode
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define ERR_IPV_MC_0048  (STD_ON)

/**
@brief Workaround implemented for Errata e2656/err002656
@details FlexCAN: Abort request blocks the CODE field, so
             instead of aborting the transmission, use deactivation.
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define  ERR_IPV_FLEXCAN_0002 (STD_ON)

/**
@brief Workaround implemented for Errata e7322
@details FlexCAN: FlexCAN: Bus Off Interrupt bit is erroneously asserted when soft reset is
                           performed while FlexCAN is in Bus Off state.
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define  ERR_IPV_FLEXCAN_0013 (STD_ON)

/**
@brief Workaround implemented for Errata e5569
@details ADC: The channel sequence order will be corrupted when a new normal
              conversion chain is started prior to completion of a pending normal conversion
              chain
*/
/*
* @violates @ref Soc_Ips_h_REF_2 This is not a standard library macro, 
*/
#define  ERR_IPV_ADCDIG_0016  (STD_ON)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef SOC_IPS_H*/
/** @} */

