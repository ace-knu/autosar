/**
*   @file    Dma_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - eDMA Low level header.
*   @details Low level header for eDMA IP module.
*
*   @addtogroup DMA_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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
* @page misra_violations MISRA-C:2004 violations
*
* @section Dma_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* The version check defines are requested by AutoSAR standard (BSW00318) and have a standard format 
* which cannot be changed.
*
* @section Dma_LLD_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Dma_LLD_h_REF_3
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe 
* approach, any file must include all its dependencies. Header files are already protected against 
* double inclusions.
*
*/
#ifndef DMA_LLD_H
#define DMA_LLD_H

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
* @violates @ref Dma_LLD_h_REF_3 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "Std_Types.h"
#include "Reg_eSys_DMA.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_VENDOR_ID                    43
#define DMA_AR_RELEASE_MAJOR_VERSION     4
#define DMA_AR_RELEASE_MINOR_VERSION     0
/*
* @violates @ref Dma_LLD_h_REF_1 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define DMA_AR_RELEASE_REVISION_VERSION  3
#define DMA_SW_MAJOR_VERSION             1
#define DMA_SW_MINOR_VERSION             0
#define DMA_SW_PATCH_VERSION             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Std_Types.h file and DMA header file are of the same Autosar version */
#if ((DMA_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Dma_LLD.h and Std_Types.h are different"
#endif
#endif

/* Check if Std_Types.h file and DMA header file are of the same Autosar version */ 
#if ((DMA_AR_RELEASE_MAJOR_VERSION != DMA_AR_RELEASE_MAJOR_VERSION_REG) || \
     (DMA_AR_RELEASE_MINOR_VERSION != DMA_AR_RELEASE_MINOR_VERSION_REG))
#error "AutoSar Version Numbers of Dma_LLD.h and Reg_eSys_DMA.h are different"           
#endif                                                                                

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/
/* Max numbers of CPRs groups used is DMA_NB_CHANNELS/4 */
#define MAX_NB_CPR_USED         (DMA_NB_CHANNELS>>2) 

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Data transfer size 16 bits
*/
#define DMA_DATA_TRANSFER_16_BIT    ((uint8) 0x1)
/**
* @brief Data transfer size 32 bits
*/
#define DMA_DATA_TRANSFER_32_BIT    ((uint8) 0x2)
/**
* @brief Data transfer size 16 bits
*/
#define DMA_DATA_TRANSFER_64_BIT    ((uint8) 0x3)
/**
* @brief Data transfer size 16 bytes
*/
#define DMA_DATA_TRANSFER_16_BYTE   ((uint8) 0x4)
/**
* @brief Data transfer size 32 bytes
*/
#define DMA_DATA_TRANSFER_32_BYTE   ((uint8) 0x5)
/**
* @brief Mode mask bit to check the channels which is requested for the mode change
*/
#define DMA_MODE_MASK               ((uint16)0x0001U)
/**
* @brief Channel Active field bit to check whether channel is active or not
*/
#define DMA_IS_ACTIVE               ((uint32)0x00000040UL)
/**
* @brief Channel Source specifies which DMA source is routed to DMA channel
*/
#define DMASOURCEMASK               ((uint16)0x003fU)
/**
* @brief Macro used to wait for software eDMA Time out till zero
*/
#define DMA_ZERO_VALUE              ((uint32)0x0U)

/*================================================================================================*/
/** 
* @brief   Acknowledge a DMA interrupt. 
* @details Clears the interrupt request bit for a specific DMA channel
*     
* @param[in]     dma_channel      Dma channel for which to acknowledge the interrupt
* 
*/
/*================================================================================================*/
/*
 * @violates @ref Dma_LLD_h_REF_2 Function-like macro defined
 */
#define Dma_ack_interrupt(dma_channel) \
        (REG_WRITE8(DMA_CINT(DMA_MOD_IDX((uint8)(dma_channel))), \
        (((uint8)(dma_channel)) & DMA_CTRL_MAX_CHANNELS_MASK)))

/*================================================================================================*/
/** 
* @brief   Start the transfer on a specific DMA channel.
* @details Start a DMA transfer
*     
* @param[in]     dma_channel      Dma channel for which to disable the interrupt
* 
*/
/*================================================================================================*/
/*
 * @violates @ref Dma_LLD_h_REF_2 Function-like macro defined
 */
#define Dma_start_channel(dma_channel) \
            (REG_WRITE8(DMA_SERQ(DMA_MOD_IDX((uint8)(dma_channel))), \
            ((uint8)(dma_channel)) & DMA_CTRL_MAX_CHANNELS_MASK))


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct {
       VAR(uint32, AUTOMATIC) edmaCr[DMA_NB_CONTROLLERS]; /** @brief eDMA MCR register. */
       VAR(uint8,  AUTOMATIC) edmaCpr[DMA_NB_CHANNELS]; /** @brief eDMA channel priority registers*/
} Dma_ConfigType;

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*================================================================================================*/
void Dma_Init(P2CONST(Dma_ConfigType, AUTOMATIC, AUTOMATIC) ConfigLLDPtr);
/*================================================================================================*/
void Dma_disable_interrupt( VAR(uint8, AUTOMATIC) dma_channel);
/*================================================================================================*/
void Dma_setup_descriptor(VAR(DmaTcdPointerType, AUTOMATIC) descriptor,
                                 VAR(uint32, AUTOMATIC) src_addr,
                                 VAR(uint8, AUTOMATIC) src_transfer_size,
                                 VAR(uint8, AUTOMATIC) dest_transfer_size,
                                 VAR(uint16, AUTOMATIC) src_next_offset,
                                 VAR(uint16, AUTOMATIC) n_bytes_to_transfer,
                                 VAR(uint32, AUTOMATIC) src_last_adj,
                                 VAR(uint32, AUTOMATIC) dest_addr,
                                 VAR(uint16, AUTOMATIC) crt_iter_cnt,
                                 VAR(uint16, AUTOMATIC) dest_next_offset,
                                 VAR(uint32, AUTOMATIC) dlast_sg_addr,
                                 VAR(uint16, AUTOMATIC) begin_iter_cnt,
                                 VAR(uint8, AUTOMATIC)  major_linkch,
                                 VAR(uint8, AUTOMATIC)  tcd_flags
                                );

/*================================================================================================*/
/**
* @brief   Configure a DMA transfer.
* @details Configures the DMA Tranfer Control Descriptor
* 
* @param[in]     dma_channel          Dma channel for which to disable the interrupt
* @param[in]     src_addr             Source address for DMA transfer
* @param[in]     src_transfer_size    Source access transfer size
* @param[in]     dest_transfer_size   Destination access transfer size
* @param[in]     src_next_offset      Offset to be applied to compute next src addr
* @param[in]     n_bytes_to_transfer  Number of bytes to transfer
* @param[in]     src_last_adj         Adjustment to be applied to src addr at the
*                                     completion of the outer major iteration count.
* @param[in]     dest_addr            Destination address for DMA transfer
* @param[in]     crt_iter_cnt         Current major iteration count
* @param[in]     dest_next_offset     Offset to be applied to compute next 
*                                     destination address.
* @param[in]     dlast_sg_addr        Adjustment to be applied to destination 
*                                     address at the completion of the outer major
*                                     iteration count (if E_SG bit is 0), or 
*                                     scatter/gather address (if E_SG bit is 1).
* @param[in]     begin_iter_cnt       Beginning major iteration count
* @param[in]     tcd_flags            Mask to configure E_SG(bit4)/D_REQ(bit3)/
*                                     INT_HALF(bit2)/INT_MAJ(bit1) bits of TCD
* 
*/
/*================================================================================================*/
/*
 * @violates @ref Dma_LLD_h_REF_2 Function-like macro defined
 */
#define Dma_configure_channel( dma_channel, \
                               src_addr, \
                               src_transfer_size, \
                               dest_transfer_size, \
                               src_next_offset, \
                               n_bytes_to_transfer, \
                               src_last_adj, \
                               dest_addr, \
                               crt_iter_cnt, \
                               dest_next_offset, \
                               dlast_sg_addr, \
                               begin_iter_cnt, \
                               tcd_flags ) \
        (Dma_setup_descriptor( (VAR(DmaTcdPointerType, AUTOMATIC))(DMA_TCD(dma_channel)), \
                               (src_addr), \
                               (src_transfer_size), \
                               (dest_transfer_size), \
                               (src_next_offset), \
                               (n_bytes_to_transfer), \
                               (src_last_adj), \
                               (dest_addr), \
                               (crt_iter_cnt), \
                               (dest_next_offset), \
                               (dlast_sg_addr), \
                               (begin_iter_cnt), \
                                0u, \
                               (tcd_flags) ))

#ifdef __cplusplus
}
#endif

#endif /*DMA_LLD_H*/

/** @} */
