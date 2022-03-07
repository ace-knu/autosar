/**
*   @file    Reg_eSys.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - BIP Memory and DMA mapping.
*   @details Memory mapping of the IP modules and DMA channels present on the XPC560XB
*            hardware platform.
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
* @file        Reg_eSys.h
* @implements DBASE10000
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Reg_eSys_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*/

#ifndef REG_ESYS_H
#define REG_ESYS_H

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
* @file        Reg_eSys.h
* @brief Include platform types
*/
/*
* @violates @ref Reg_eSys_h_REF_1 Repeated include file.
*/
#include "Platform_Types.h"

/**
* @file        Reg_eSys.h
* @brief Include IP module versions
*/
#include "Soc_Ips.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief  Internal Flash
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define INTERNAL_FLASH_BASEADDR             ((uint32)0x00000000UL)
/**
* @brief  Internal RAM
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define INTERNAL_RAM_BASEADDR               ((uint32)0x40000000UL)

/**
* @brief CodeFLASH0_A
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLASHMEM0_CF0_A_BASEADDR            ((uint32)0xC3F88000UL)
/**
* @brief DataFLASH0_A
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLASHMEM0_DF0_A_BASEADDR            ((uint32)0xC3F8C000UL)
/**
* @brief System Integration Unit Lite (SIUL)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define SIUL_BASEADDR                       ((uint32)0xC3F90000UL)
/**
* @brief WakeUp Unit
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define WKPU_BASEADDR                       ((uint32)0xC3F94000UL)
/**
* @brief eMIOS 0
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
/*
* @violates @ref Reg_eSys_h_REF_2 This is not a standard library macro, 
*/
#define EMIOSA_BASEADDR                     ((uint32)0xC3FA0000UL)
/**
* @brief eMIOS 1
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
/*
* @violates @ref Reg_eSys_h_REF_2 This is not a standard library macro, 
*/
#define EMIOSB_BASEADDR                     ((uint32)0xC3FA4000UL)
/**
* @brief CodeFLASH1_B
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLASHMEM0_CF1_B_BASEADDR            ((uint32)0xC3FB0000UL)
/**
* @brief CodeFLASH2_C
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLASHMEM0_CF2_C_BASEADDR            ((uint32)0xC3FB4000UL)
/**
* @brief System Status and Configuration Module (SSCM)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define SSCM_BASEADDR                       ((uint32)0xC3FD8000UL)
/**
* @brief Mode Entry Module (MC_ME)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define MC_ME_BASEADDR                      ((uint32)0xC3FDC000UL)
/**
* @brief Clock Generation Module (MC_CGM)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define MC_CGM_BASEADDR                     ((uint32)0xC3FE0000UL)
/**
* @brief Reset Generation Module (MC_RGM)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define MC_RGM_BASEADDR                     ((uint32)0xC3FE4000UL)
/**
* @brief Power Control Unit (MC_PCU)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define MC_PCU_BASEADDR                     ((uint32)0xC3FE8000UL)
/**
* @brief Real Time Counter (RTC/API)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define RTC_BASEADDR                        ((uint32)0xC3FEC000UL)
/**
* @brief Periodic Interrupt Timer (PIT)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define PIT_BASEADDR                        ((uint32)0xC3FF0000UL)

/**
* @brief ADC 0
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define ADC0_BASEADDR                       ((uint32)0xFFE00000UL)
/**
* @brief ADC 1
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define ADC1_BASEADDR                       ((uint32)0xFFE04000UL)
/**
* @brief I2C 0
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define I2C0_BASEADDR                       ((uint32)0xFFE30000UL)
/**
* @brief LINFlex 0
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX0_BASEADDR                   ((uint32)0xFFE40000UL)
/**
* @brief LINFlex 1
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX1_BASEADDR                   ((uint32)0xFFE44000UL)
/**
* @brief LINFlex 2
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX2_BASEADDR                   ((uint32)0xFFE48000UL)
/**
* @brief LINFlex 3
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX3_BASEADDR                   ((uint32)0xFFE4C000UL)
/**
* @brief LINFlex 4
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX4_BASEADDR                   ((uint32)0xFFE50000UL)
/**
* @brief LINFlex 5
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX5_BASEADDR                   ((uint32)0xFFE54000UL)
/**
* @brief LINFlex 6
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX6_BASEADDR                   ((uint32)0xFFE58000UL)
/**
* @brief LINFlex 7
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX7_BASEADDR                   ((uint32)0xFFE5C000UL)
/**
* @brief CTU-LITE
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define CTU_BASEADDR                        ((uint32)0xFFE64000UL)
/**
* @brief CAN sampler
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define CANSP_BASEADDR                      ((uint32)0xFFE70000UL)
/**
* @brief Platform FLASH Controller
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLASHMEM0_PFC0_BASEADDR             ((uint32)0xFFE88000UL)
/**
* @brief MPU
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define MPU_BASEADDR                        ((uint32)0xFFF10000UL)
/**
* @brief SWT
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define SWT0_BASEADDR                       ((uint32)0xFFF38000UL)
/**
* @brief STM
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define STM_0_BASEADDR                      ((uint32)0xFFF3C000UL)
/**
* @brief ECSM
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
/*
* @violates @ref Reg_eSys_h_REF_2 This is not a standard library macro, 
*/
#define ECSM_BASEADDR                       ((uint32)0xFFF40000UL)
/**
* @brief DMA
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DMA_BASEADDR                        ((uint32)0xFFF44000UL)
/**
* @brief INTC
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define INTC_BASEADDR                       ((uint32)0xFFF48000UL)
/**
* @brief DSPI 0
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DSPI0_BASEADDR                      ((uint32)0xFFF90000UL)
/**
* @brief DSPI 1
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DSPI1_BASEADDR                      ((uint32)0xFFF94000UL)
/**
* @brief DSPI 2
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DSPI2_BASEADDR                      ((uint32)0xFFF98000UL)
/**
* @brief DSPI 3
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DSPI3_BASEADDR                      ((uint32)0xFFF9C000UL)
/**
* @brief DSPI 4
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DSPI4_BASEADDR                      ((uint32)0xFFFA0000UL)
/**
* @brief DSPI 5
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DSPI5_BASEADDR                      ((uint32)0xFFFA4000UL)
/**
* @brief LINFlex 8
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX8_BASEADDR                   ((uint32)0xFFFB0000UL)
/**
* @brief LINFlex 9
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define LINFLEX9_BASEADDR                   ((uint32)0xFFFB4000UL)
/**
* @brief FlexCan 0 (CAN0)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLEXCAN0_BASEADDR                   ((uint32)0xFFFC0000UL)
/**
* @brief FlexCan 1 (CAN1)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLEXCAN1_BASEADDR                   ((uint32)0xFFFC4000UL)
/**
* @brief FlexCan 2 (CAN2)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLEXCAN2_BASEADDR                   ((uint32)0xFFFC8000UL)
/**
* @brief FlexCan 3 (CAN3)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLEXCAN3_BASEADDR                   ((uint32)0xFFFCC000UL)
/**
* @brief FlexCan 4 (CAN4)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLEXCAN4_BASEADDR                   ((uint32)0xFFFD0000UL)
/**
* @brief FlexCan 5 (CAN5)
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define FLEXCAN5_BASEADDR                   ((uint32)0xFFFD4000UL)
/**
* @brief DMA Channel Multiplexer
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define DMAMUX_BASEADDR                     ((uint32)0xFFFDC000UL)
/**
* @brief BAM
* @details XPC560XB System Memory Map
* @implements DBASE10001
*/
#define BAM_BASEADDR                        ((uint32)0xFFFFC000UL)


/**************************************************************************************************/
/**
* @brief INTC OFFSET address for exit interrupt
*/
#define INTC_EOIR_OFFSET                     ((uint32)0x00000018UL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef REG_ESYS_H*/

/** @} */
