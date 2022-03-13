/**
*   @file    Dmamux_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - DMAMUX Low level driver header file.
*   @details DMAMux IP module low level driver.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF13_ASR_REL_4_0_REV_0003_20170719
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef DMAMUX_LLD_H
#define DMAMUX_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section  Mcu_DMAMUX_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_DMAMUX_LLD_h_REF_2
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Mcu_DMAMUX_LLD_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Std_Types.h"
#include "Reg_eSys_DMAMUX.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMAMUX_VENDOR_ID                      43
/*
* @violates @ref Mcu_DMAMUX_LLD_h_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref Mcu_DMAMUX_LLD_h_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Mcu_DMAMUX_LLD_h_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_AR_RELEASE_REVISION_VERSION    3
#define DMAMUX_SW_MAJOR_VERSION               1
#define DMAMUX_SW_MINOR_VERSION               0
#define DMAMUX_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys_DMAMUX header file are of the same vendor */
#if (DMAMUX_VENDOR_ID != DMAMUX_REG_VENDOR_ID)
#error "Dmamux_LLD.h and Reg_eSys_DMAMUX.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_DMAMUX header file are of the same Autosar version */
#if ((DMAMUX_AR_RELEASE_MAJOR_VERSION    != DMAMUX_REG_AR_RELEASE_MAJOR_VERSION) || \
    (DMAMUX_AR_RELEASE_MINOR_VERSION     != DMAMUX_REG_AR_RELEASE_MINOR_VERSION) || \
    (DMAMUX_AR_RELEASE_REVISION_VERSION  != DMAMUX_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dmamux_LLD.h and Reg_eSys_DMAMUX.h are different"
#endif
/* Check if current file and Reg_eSys_DMAMUX header file are of the same Software version */
#if ((DMAMUX_SW_MAJOR_VERSION != DMAMUX_REG_SW_MAJOR_VERSION) || \
     (DMAMUX_SW_MINOR_VERSION != DMAMUX_REG_SW_MINOR_VERSION) || \
     (DMAMUX_SW_PATCH_VERSION != DMAMUX_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Dmamux_LLD.h and Reg_eSys_DMAMUX.h are different"
#endif
/* Check if current file and Std_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((DMAMUX_AR_RELEASE_MAJOR_VERSION     != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DMAMUX_AR_RELEASE_MINOR_VERSION     != STD_TYPES_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Dmamux_LLD.h and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          Channels of the Dma module.
* @details        Each define refers to a different Dma channel
*/
#define DMAMUX_CHANNEL0         ((uint8) 0u)
#define DMAMUX_CHANNEL1         ((uint8) 1u)
#define DMAMUX_CHANNEL2         ((uint8) 2u)
#define DMAMUX_CHANNEL3         ((uint8) 3u)
#define DMAMUX_CHANNEL4         ((uint8) 4u)
#define DMAMUX_CHANNEL5         ((uint8) 5u)
#define DMAMUX_CHANNEL6         ((uint8) 6u)
#define DMAMUX_CHANNEL7         ((uint8) 7u)
#define DMAMUX_CHANNEL8         ((uint8) 8u)
#define DMAMUX_CHANNEL9         ((uint8) 9u)
#define DMAMUX_CHANNEL10        ((uint8) 10u)
#define DMAMUX_CHANNEL11        ((uint8) 11u)
#define DMAMUX_CHANNEL12        ((uint8) 12u)
#define DMAMUX_CHANNEL13        ((uint8) 13u)
#define DMAMUX_CHANNEL14        ((uint8) 14u)
#define DMAMUX_CHANNEL15        ((uint8) 15u)
#define DMAMUX_CHANNEL16        ((uint8) 16u)
#define DMAMUX_CHANNEL17        ((uint8) 17u)
#define DMAMUX_CHANNEL18        ((uint8) 18u)
#define DMAMUX_CHANNEL19        ((uint8) 19u)
#define DMAMUX_CHANNEL20        ((uint8) 20u)
#define DMAMUX_CHANNEL21        ((uint8) 21u)
#define DMAMUX_CHANNEL22        ((uint8) 22u)
#define DMAMUX_CHANNEL23        ((uint8) 23u)
#define DMAMUX_CHANNEL24        ((uint8) 24u)
#define DMAMUX_CHANNEL25        ((uint8) 25u)
#define DMAMUX_CHANNEL26        ((uint8) 26u)
#define DMAMUX_CHANNEL27        ((uint8) 27u)
#define DMAMUX_CHANNEL28        ((uint8) 28u)
#define DMAMUX_CHANNEL29        ((uint8) 29u)
#define DMAMUX_CHANNEL30        ((uint8) 30u)
#define DMAMUX_CHANNEL31        ((uint8) 31u)
#define DMAMUX_CHANNEL32        ((uint8) 32u)
#define DMAMUX_CHANNEL33        ((uint8) 33u)
#define DMAMUX_CHANNEL34        ((uint8) 34u)
#define DMAMUX_CHANNEL35        ((uint8) 35u)
#define DMAMUX_CHANNEL36        ((uint8) 36u)
#define DMAMUX_CHANNEL37        ((uint8) 37u)
#define DMAMUX_CHANNEL38        ((uint8) 38u)
#define DMAMUX_CHANNEL39        ((uint8) 39u)
#define DMAMUX_CHANNEL40        ((uint8) 40u)
#define DMAMUX_CHANNEL41        ((uint8) 41u)
#define DMAMUX_CHANNEL42        ((uint8) 42u)
#define DMAMUX_CHANNEL43        ((uint8) 43u)
#define DMAMUX_CHANNEL44        ((uint8) 44u)
#define DMAMUX_CHANNEL45        ((uint8) 45u)
#define DMAMUX_CHANNEL46        ((uint8) 46u)
#define DMAMUX_CHANNEL47        ((uint8) 47u)
#define DMAMUX_CHANNEL48        ((uint8) 48u)
#define DMAMUX_CHANNEL49        ((uint8) 49u)
#define DMAMUX_CHANNEL50        ((uint8) 50u)
#define DMAMUX_CHANNEL51        ((uint8) 51u)
#define DMAMUX_CHANNEL52        ((uint8) 52u)
#define DMAMUX_CHANNEL53        ((uint8) 53u)
#define DMAMUX_CHANNEL54        ((uint8) 54u)
#define DMAMUX_CHANNEL55        ((uint8) 55u)
#define DMAMUX_CHANNEL56        ((uint8) 56u)
#define DMAMUX_CHANNEL57        ((uint8) 57u)
#define DMAMUX_CHANNEL58        ((uint8) 58u)
#define DMAMUX_CHANNEL59        ((uint8) 59u)
#define DMAMUX_CHANNEL60        ((uint8) 60u)
#define DMAMUX_CHANNEL61        ((uint8) 61u)
#define DMAMUX_CHANNEL62        ((uint8) 62u)
#define DMAMUX_CHANNEL63        ((uint8) 63u)
#define DMAMUX_CHANNEL64        ((uint8) 64u)
#define DMAMUX_CHANNEL65        ((uint8) 65u)
#define DMAMUX_CHANNEL66        ((uint8) 66u)
#define DMAMUX_CHANNEL67        ((uint8) 67u)
#define DMAMUX_CHANNEL68        ((uint8) 68u)
#define DMAMUX_CHANNEL69        ((uint8) 69u)
#define DMAMUX_CHANNEL70        ((uint8) 70u)
#define DMAMUX_CHANNEL71        ((uint8) 71u)
#define DMAMUX_CHANNEL72        ((uint8) 72u)
#define DMAMUX_CHANNEL73        ((uint8) 73u)
#define DMAMUX_CHANNEL74        ((uint8) 74u)
#define DMAMUX_CHANNEL75        ((uint8) 75u)
#define DMAMUX_CHANNEL76        ((uint8) 76u)
#define DMAMUX_CHANNEL77        ((uint8) 77u)
#define DMAMUX_CHANNEL78        ((uint8) 78u)
#define DMAMUX_CHANNEL79        ((uint8) 79u)
#define DMAMUX_CHANNEL80        ((uint8) 80u)
#define DMAMUX_CHANNEL81        ((uint8) 81u)
#define DMAMUX_CHANNEL82        ((uint8) 82u)
#define DMAMUX_CHANNEL83        ((uint8) 83u)
#define DMAMUX_CHANNEL84        ((uint8) 84u)
#define DMAMUX_CHANNEL85        ((uint8) 85u)
#define DMAMUX_CHANNEL86        ((uint8) 86u)
#define DMAMUX_CHANNEL87        ((uint8) 87u)
#define DMAMUX_CHANNEL88        ((uint8) 88u)
#define DMAMUX_CHANNEL89        ((uint8) 89u)
#define DMAMUX_CHANNEL90        ((uint8) 90u)
#define DMAMUX_CHANNEL91        ((uint8) 91u)
#define DMAMUX_CHANNEL92        ((uint8) 92u)
#define DMAMUX_CHANNEL93        ((uint8) 93u)
#define DMAMUX_CHANNEL94        ((uint8) 94u)
#define DMAMUX_CHANNEL95        ((uint8) 95u)


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Dmamux configuration.
*/
typedef struct {
    VAR(uint8,  AUTOMATIC) chConfig[DMAMUX_NB_CHANNELS];
} Dmamux_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCU_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, MCU_CODE) Dmamux_Init(P2CONST(Dmamux_ConfigType, AUTOMATIC, MCU_APPL_CONST) \
    ConfigLLDPtr);

FUNC (void, MCU_CODE) DmaMux_SetChannelRouting( VAR(uint8, AUTOMATIC) output_channel,
                                                VAR(uint8, AUTOMATIC) dma_request,
                                                VAR(uint8, AUTOMATIC) channel_enable,
                                                VAR(uint8, AUTOMATIC) trigger_enable);

FUNC (void, MCU_CODE) DmaMux_SetChannelRouting2( VAR(uint8, AUTOMATIC) Dmamode,
                                                 VAR(uint8, AUTOMATIC) DmaChannel);

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_DMAMUX_LLD_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DMAMUX_LLD_H */

/** @} */
