/**
*   @file    DmaMux_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - DMAMux low level driver.
*   @details File containing the low level driver for DMAMux IP.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section DMAMUX_LLD_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section DMAMUX_LLD_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section DMAMUX_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers
* to other types used in macros for reading or writing data from address location of controller register.
*
* @section DMAMUX_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR
* specifications although it exceeds the max length of 31 characters
*
* @section DMAMUX_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section DMAMUX_LLD_C_REF_6
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

#include "Dmamux_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMAMUX_VENDOR_ID_C                    43
/**
* @violates @ref DMAMUX_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref DMAMUX_LLD_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_AR_RELEASE_MAJOR_VERSION_C     4
/**
* @violates @ref DMAMUX_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref DMAMUX_LLD_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_AR_RELEASE_MINOR_VERSION_C     0
/**
* @violates @ref DMAMUX_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref DMAMUX_LLD_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define DMAMUX_AR_RELEASE_REVISION_VERSION_C  3
#define DMAMUX_SW_MAJOR_VERSION_C             1
#define DMAMUX_SW_MINOR_VERSION_C             0
#define DMAMUX_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Dmamux_LLD header file are of the same vendor */
#if (DMAMUX_VENDOR_ID_C != DMAMUX_VENDOR_ID)
    #error "DmaMux_LLD.c and DmaMux_LLD.h have different vendor ids"
#endif
/* Check if current file and Dmamux_LLD header file are of the same Autosar version */
#if ((DMAMUX_AR_RELEASE_MAJOR_VERSION_C    != DMAMUX_AR_RELEASE_MAJOR_VERSION) || \
     (DMAMUX_AR_RELEASE_MINOR_VERSION_C    != DMAMUX_AR_RELEASE_MINOR_VERSION) || \
     (DMAMUX_AR_RELEASE_REVISION_VERSION_C != DMAMUX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of DmaMux_LLD.c and DmaMux_LLD.h are different"
#endif
/* Check if current file and Dmamux_LLD header file are of the same Software version */
#if ((DMAMUX_SW_MAJOR_VERSION_C != DMAMUX_SW_MAJOR_VERSION) || \
     (DMAMUX_SW_MINOR_VERSION_C != DMAMUX_SW_MINOR_VERSION) || \
     (DMAMUX_SW_PATCH_VERSION_C != DMAMUX_SW_PATCH_VERSION))
    #error "Software Version Numbers of DmaMux_LLD.c and DmaMux_LLD.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define MCU_START_SEC_CONST_32
/**
* @violates @ref DMAMUX_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"
/**
* @brief DMA_MUX base address array
*/
/*
* @violates @ref DMAMUX_LLD_C_REF_5 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
CONST(uint32, MCU_CONST) DMAMUX_BASE_ADDR[] = {
#ifdef DMAMUX_BASEADDR
    DMAMUX_BASEADDR,
#endif /* DMAMUX_BASEADDR */
#ifdef DMAMUX1_BASEADDR
    DMAMUX1_BASEADDR,
#endif /* DMAMUX1_BASEADDR */
#ifdef DMAMUX2_BASEADDR
    DMAMUX2_BASEADDR,
#endif /* DMAMUX2_BASEADDR */
#ifdef DMAMUX3_BASEADDR
    DMAMUX3_BASEADDR,
#endif /* DMAMUX3_BASEADDR */
#ifdef DMAMUX4_BASEADDR
    DMAMUX4_BASEADDR,
#endif /* DMAMUX4_BASEADDR */
#ifdef DMAMUX5_BASEADDR
    DMAMUX5_BASEADDR,
#endif /* DMAMUX5_BASEADDR */
};

#define MCU_STOP_SEC_CONST_32
/**
* @violates @ref DMAMUX_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref DMAMUX_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*           statements and comments before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref DMAMUX_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref DMAMUX_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*           statements and comments before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          DMAMUX module configuration.
* @details        The function updates the configuration register CHCONFIG of
*                 each DMA channel according to the user settings in the input
*                 parameter.
*
* @param[in]      ConfigLLDPtr describes the configuration of the DMA mux module.
*                 It determines to which source a DMA channel will be routed,
*                 specifies if each channel will be enabled and if the periodic
*                 trigger capability of each channel will be turned on.
*
* @violates @ref DMAMUX_LLD_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC(void, MCU_CODE) Dmamux_Init(P2CONST(Dmamux_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigLLDPtr)
{
    VAR(uint32, AUTOMATIC) i=0U;

    /* Init DMA_MUX channels */
    for (i=0U; i<DMAMUX_NB_CHANNELS; i++)
    {
        /* update the DMAMUX_CHCONF registers */
        /** @violates @ref DMAMUX_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE8(DMAMUX_CHCONF(i), ConfigLLDPtr->chConfig[i]);
    }
}

/*================================================================================================*/
/**
* @brief          DMAMUX module configuration.
* @details        The function updates the configuration register CHCONFIG of
*                 a single DMA channel according to the user settings in the input
*                 parameters. It determines to which source the choosen DMA channel
*                 will be routed, specifies if the channel will be enabled and if the
*                 periodic trigger capability of the channel will be turned on.
*
* @param[in]     output_channel      DMA channel that will be configured.
* @param[in]     dma_request         DMA requester module
* @param[in]     channel_enable      Specifies if the current DMA channel will be enabled
* @param[in]     trigger_enable      Specifies if the current DMA channel will be periodic triggered.
*
* @pre           DMAMux module should not be frozen and no DMA transfer should be
*                ongoing on the output_channel.
*
* @violates @ref DMAMUX_LLD_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) DmaMux_SetChannelRouting( VAR(uint8, AUTOMATIC) output_channel,
                                                VAR(uint8, AUTOMATIC) dma_request,
                                                VAR(uint8, AUTOMATIC) channel_enable,
                                                VAR(uint8, AUTOMATIC) trigger_enable)
{
    VAR(uint8, AUTOMATIC) new_routing;

    /* Before changing the trigger or source settings a DMA channel must be disabled via the
       CHCONFIG[#n].ENBL bit. */
    /** @violates @ref DMAMUX_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_BIT_CLEAR8( ((uint32)DMAMUX_CHCONF((uint32)output_channel)), (uint32)DMAMUX_ENBL_MASK);

    /* create new register configuration */
    new_routing= ((uint8)(channel_enable<<DMAMUX_ENBL_SHIFT)) & DMAMUX_ENBL_MASK;
    new_routing|= ((uint8)(trigger_enable<<DMAMUX_TRIG_SHIFT)) & DMAMUX_TRIG_MASK;
    new_routing|= dma_request & DMAMUX_SOURCE_MASK;

    /* write new register configuration */
    /** @violates @ref DMAMUX_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8( ((uint32)DMAMUX_CHCONF((uint32)output_channel)), new_routing);
}

/*================================================================================================*/
/**
* @brief          DMAMUX module configuration.
* @details        The function updates the configuration register CHCONFIG of
*                 a single DMA channel according to the user settings in the input
*                 parameters. It determines to which source the choosen DMA channel
*                 will be routed, specifies if the channel will be enabled and if the
*                 periodic trigger capability of the channel will be turned on.
*
* @param[in]     output_channel      DMA channel that will be configured.
* @param[in]     dma_request         DMA requester module
* @param[in]     channel_enable      Specifies if the current DMA channel will be enabled
* @param[in]     trigger_enable      Specifies if the current DMA channel will be periodic triggered.
*
* @pre           DMAMux module should not be frozen and no DMA transfer should be
*                ongoing on the output_channel.
*
*
* @note          This is called by the function Mcu_LLD_SetDMAv2Mode in Dma_LLD.c
*
*
* @violates @ref DMAMUX_LLD_C_REF_5 Required Rule 8.10, API could not be made static.
*
*/
FUNC (void, MCU_CODE) DmaMux_SetChannelRouting2( VAR(uint8, AUTOMATIC) Dmamode,
                                                 VAR(uint8, AUTOMATIC) DmaChannel)
{
    VAR(uint8, AUTOMATIC) value;

    /* Read DmaChannel configuration register */
    /** @violates @ref DMAMUX_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    value = REG_READ8(DMAMUX_CHCONF((uint32)DmaChannel));

    /* Mask the source bit */
    value = (uint8) (DMAMUX_SOURCE_MASK & value);
    /* Write the requested Mode to DmaChannel configuration register */
    value = ((uint8) Dmamode) | value;

    /** @violates @ref DMAMUX_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(DMAMUX_CHCONF((uint32)DmaChannel), value);

}

/**
* @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*                            statements and comments before '#include'
*/
#define MCU_STOP_SEC_CODE
/**
* @violates @ref DMAMUX_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref DMAMUX_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*           statements and comments before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
