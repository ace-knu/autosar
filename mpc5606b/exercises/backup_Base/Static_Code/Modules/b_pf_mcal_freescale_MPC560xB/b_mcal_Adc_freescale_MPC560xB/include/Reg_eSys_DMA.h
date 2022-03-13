/**
*   @file    Reg_eSys_DMA.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - eDMA Registers and Macros Definitions
*   @details eDMA Registers and Macros Definitions
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
* @section Reg_eSys_DMA_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_DMA_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe 
* approach, any file must include all its dependencies. Header files are already protected against 
* double inclusions.
*
*@section Reg_eSys_DMA_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/

#ifndef REG_ESYS_DMA_H
#define REG_ESYS_DMA_H

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
* @violates @ref Reg_eSys_DMA_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "Reg_eSys.h"
/*
* @violates @ref Reg_eSys_DMA_h_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice.
*/
#include "Reg_Macros.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_DMA.h
*/
#define DMA_VENDOR_ID_REG                       43
/*
* @violates @ref Reg_eSys_DMA_h_REF_3 This is required as per autosar Requirement, 
*/
#define DMA_AR_RELEASE_MAJOR_VERSION_REG        4
/*
* @violates @ref Reg_eSys_DMA_h_REF_3 This is required as per autosar Requirement, 
*/
#define DMA_AR_RELEASE_MINOR_VERSION_REG        0
/*
* @violates @ref Reg_eSys_DMA_h_REF_3 This is required as per autosar Requirement, 
*/
#define DMA_AR_RELEASE_REVISION_VERSION_REG     3
#define DMA_SW_MAJOR_VERSION_REG                1
#define DMA_SW_MINOR_VERSION_REG                0
#define DMA_SW_PATCH_VERSION_REG                1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS                                                  
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* for backward compatibility:
      - if DMA_NB_CONTOLERS not defined by Reg_eSys.h is supposed that only one controller exist 
      - if DMA_NB_CHANNELS not defined by Reg_eSys.h is supposed that DMA support only 16 channels*/

#ifndef DMA_NB_CONTROLLERS 
    #define DMA_NB_CONTROLLERS           (0x01U)
#endif

#ifndef DMA_NB_CHANNELS 
    #define DMA_NB_CHANNELS              (0x10U)
#endif

#ifndef DMA_CTRL_MAX_CHANNELS_MASK
/**
* @brief Mask used to select the DMA controller for a given channel
*/
#define DMA_CTRL_MAX_CHANNELS_MASK       (0x3FU)

/**
* @brief Define to identify max number of channels per DMA controller 
*/ 
#define DMA_CTRL_MAX_CHANNELS            (0x40U)
#endif

#if (DMA_NB_CONTROLLERS == 2U)
     /*
     * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
     */
    #define DMA_MOD_BASE_ADDR(mIdx) \
        ((uint32)(((mIdx)>0U) ? DMAB_BASEADDR : DMAA_BASEADDR))
     /*
     * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
     */
    #define DMA_MOD_BASE_ADDR_CH(channel) \
        ((uint32)(DMA_MOD_BASE_ADDR((channel) & ((uint8)(~DMA_CTRL_MAX_CHANNELS_MASK)))))
     /*
     * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
     */
    #define DMA_MOD_IDX(channel) \
        ((uint8)(((uint8)((channel) & ((uint8)(~DMA_CTRL_MAX_CHANNELS_MASK)))>0U)? 1U : 0U))
#else
    /** 
    * @brief macro to get the DMA Module address by module index
    */
     /*
     * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
     */
    #define DMA_MOD_BASE_ADDR(mIdx)         ((uint32)(DMA_BASEADDR))
    /** 
    * @brief macro to get the DMA Module base address by channel
    */
     /*
     * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
     */
    #define DMA_MOD_BASE_ADDR_CH(channel)   ((uint32)(DMA_BASEADDR))
    /**
    * @brief macro to get the DMA Module index by channel
    */
    /*
    * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
    */
    #define DMA_MOD_IDX(channel)            ((uint8)(0U))
#endif        
    
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */

/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CR(mIdx)        ((uint32)( DMA_MOD_BASE_ADDR(mIdx)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_ES(mIdx)        ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000004UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_ERQH(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000008UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_ERQL(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000000CUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_EEIH(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000010UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_EEIL(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000014UL ))

/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_SERQ(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000018UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CERQ(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000019UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_SEEI(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000001AUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CEEI(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000001BUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CINT(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000001CUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CERR(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000001DUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_SSRT(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000001EUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CDNE(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000001FUL ))

/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_INTH(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000020UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_INTL(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000024UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_EERH(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000028UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_EERL(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000002CUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_HRSH(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000030UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_HRSL(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000034UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_GPOR(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000038UL ))

/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR0(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000100UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR1(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000101UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR2(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000102UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR3(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000103UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR4(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000104UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR5(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000105UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR6(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000106UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR7(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000107UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR8(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000108UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR9(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000109UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR10(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000010AUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR11(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000010BUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR12(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000010CUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR13(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000010DUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR14(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000010EUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR15(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000010FUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR16(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000110UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR17(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000111UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR18(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000112UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR19(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000113UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR20(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000114UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR21(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000115UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR22(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000116UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR23(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000117UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR24(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000118UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR25(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000119UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR26(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000011AUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR27(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000011BUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR28(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000011CUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR29(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000011DUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR30(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000011EUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR31(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000011FUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR32(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000120UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR33(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000121UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR34(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000122UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR35(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000123UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR36(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000124UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR37(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000125UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR38(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000126UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR39(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000127UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR40(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000128UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR41(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000129UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR42(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000012AUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR43(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000012BUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR44(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000012CUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR45(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000012DUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR46(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000012EUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR47(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000012FUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR48(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000130UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR49(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000131UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR50(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000132UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR51(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000133UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR52(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000134UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR53(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000135UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR54(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000136UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR55(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000137UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR56(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000138UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR57(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00000139UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR58(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000013AUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR59(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000013BUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR60(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000013CUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR61(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000013DUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR62(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000013EUL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR63(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x0000013FUL ))

/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD0(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001000UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD1(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001020UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD2(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001040UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD3(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001060UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD4(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001080UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD5(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000010A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD6(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000010C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD7(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000010E0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD8(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001100UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD9(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001120UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD10(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001140UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD11(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001160UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD12(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001180UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD13(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000011A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD14(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000011C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD15(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000011E0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD16(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001200UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD17(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001220UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD18(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001240UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD19(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001260UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD20(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001280UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD21(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000012A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD22(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000012C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD23(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000012E0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD24(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001300UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD25(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001320UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD26(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001340UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD27(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001360UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD28(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001380UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD29(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000013A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD30(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000013C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD31(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000013E0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD32(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001400UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD33(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001420UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD34(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001440UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD35(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001460UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD36(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001480UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD37(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000014A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD38(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000014C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD39(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000014E0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD40(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001500UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD41(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001520UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD42(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001540UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD43(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001560UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD44(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001580UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD45(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000015A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD46(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000015C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD47(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000015E0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD48(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001600UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD49(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001620UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD50(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001640UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD51(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001660UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD52(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001680UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD53(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000016A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD54(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000016C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD55(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000016E0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD56(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001700UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD57(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001720UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD58(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001740UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD59(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001760UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD60(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x00001780UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD61(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000017A0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD62(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000017C0UL ))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD63(mIdx)     ((uint32)( DMA_MOD_BASE_ADDR(mIdx) + 0x000017E0UL ))
/**@}*/

/**
* @brief Task control block address offset 
*/
#define DMA_TCD_OFFSET     ((uint32) (0x1000UL))
/**
* @brief Channel priority block address offset 
*/
#define DMA_CPT_OFFSET     ((uint32) (0x0100UL))
/**
* @brief Offset to Source address in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_SADDR_OFFSET        ((uint32) 0x00UL)
/**
* @brief Offset to smod, ssize, dmod, dsize, soff fields in TCD-Transfer Control Descriptor structure.
*/
#define DMA_TCD_TA_SOFF_OFFSET      ((uint32) 0x04UL)
/**
* @brief Offset to smloe, dmloe, mloff, nbytes fields in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_SMLO_NBTYES_OFFSET  ((uint32) 0x08UL)
/**
* @brief Offset to slast field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_SLAST_OFFSET        ((uint32) 0x0CUL)
/**
* @brief Offset to destination address field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_DADDR_OFFSET        ((uint32) 0x10UL)
/**
* @brief Offset to citer, doff fields in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_CITER_DOFF_OFFSET   ((uint32) 0x14UL)
/**
* @brief Offset to dlast_sga field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_DLAST_SGA_OFFSET    ((uint32) 0x18UL)
/**
* @brief Offset to biter, channle control/status fields in TCD - Transfer Control Descriptor structure
*/
#define DMA_TCD_BITER_CCS_OFFSET    ((uint32) 0x1CUL)

/** 
* @{
* @brief TCD Fields's address.
*/
#define DMA_TCD_DONE            (0x00000080U)
#define DMA_TCD_ACTIVE          (0x00000040U)
#define DMA_TCD_MAJOR_E_LINK    (0x00000020U)
#define DMA_TCD_SGA             (0x00000010U)
#define DMA_TCD_DISABLE_REQ     (0x00000008U)
#define DMA_TCD_INT_HALF        (0x00000004U)
#define DMA_TCD_INT_MAJOR       (0x00000002U)
#define DMA_TCD_START           (0x00000001U)
/**@}*/

/** 
* @{
* @brief TCD Fields's masks.
*/
#define DMA_TCD_MINOR_E_LINK_MASK   ((uint32) 0xFE000000U)
#define DMA_TCD_MINOR_ITER_MASK     ((uint32) 0x01FF0000U)
#define DMA_TCD_MINOR_DOFF_MASK     ((uint32) 0x0000FFFFU)
#define DMA_TCD_MINOR_SOFF_MASK     ((uint32) 0x0000FFFFU)
/**@}*/

/**
* @brief For DMA TCDs which do not use e_link field, major loop iteration count is on 15 bits.
*/
#define DMA_MAX_UNLINKED_ITER_CNT   (0x7FFFu)
/**
* @brief For DMA TCDs using e_link field, major loop iteration count is on 9 bits
*/
#define DMA_MAX_LINKED_ITER_CNT     (0x1FFu)

#define DMA_TCD_SIZE        (0x20u)
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_CPR(Channel) \
    ((uint32)(DMA_MOD_BASE_ADDR_CH(Channel) + (DMA_CPT_OFFSET) + \
    ((uint32)(Channel) & DMA_CTRL_MAX_CHANNELS_MASK)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD(Channel) \
    ((uint32)(DMA_MOD_BASE_ADDR_CH(Channel) + (DMA_TCD_OFFSET) + \
    (((uint32)(Channel) & DMA_CTRL_MAX_CHANNELS_MASK)<<5)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD_CHANNEL(Channel, Offset) ((uint32)(DMA_TCD(Channel) + (Offset)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD_SR(Channel) \
    ((*(volatile uint32*)(DMA_TCD_CHANNEL((Channel), (DMA_TCD_BITER_CCS_OFFSET)))))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_SERQ(channel) \
    (REG_WRITE8(DMA_SERQ(DMA_MOD_IDX(channel)), ((channel) & (DMA_CTRL_MAX_CHANNELS_MASK))))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_CDNE(channel) \
    (REG_WRITE8(DMA_CDNE(DMA_MOD_IDX(channel)), ((channel) & (DMA_CTRL_MAX_CHANNELS_MASK))))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_SSRT(channel) \
    (REG_WRITE8(DMA_SSRT(DMA_MOD_IDX(channel)), ((channel) & (DMA_CTRL_MAX_CHANNELS_MASK))))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_CINT(channel) \
    (REG_WRITE8(DMA_CINT(DMA_MOD_IDX(channel)), ((channel) & (DMA_CTRL_MAX_CHANNELS_MASK))))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_SERQ_IDX(mIdx,value) (REG_WRITE8(DMA_SERQ(mIdx), (value)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_CDNE_IDX(mIdx,value) (REG_WRITE8(DMA_CDNE(mIdx), (value)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_SSRT_IDX(mIdx,value) (REG_WRITE8(DMA_SSRT(mIdx), (value)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_CINT_IDX(mIdx,value) (REG_WRITE8(DMA_CINT(mIdx), (value)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCD_DADDR(Channel, dest_addr) \
   (REG_WRITE32((DMA_TCD(Channel) + (DMA_TCD_DADDR_OFFSET)), (dest_addr)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCD_SADDR(Channel, src_addr) \
   (REG_WRITE32((DMA_TCD(Channel) + (DMA_TCD_SADDR_OFFSET)), (src_addr)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Rd_DMA_INTH(mIdx)           (REG_READ32(DMA_INTH(mIdx)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Rd_DMA_INTL(mIdx)           (REG_READ32(DMA_INTL(mIdx)))
/**@}*/

/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_SADDR(TcdAddr, src_addr) \
   (REG_WRITE32((uint32)(TcdAddr) + DMA_TCD_SADDR_OFFSET, (uint32)(src_addr)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_DADDR(TcdAddr, dest_addr) \
   (REG_WRITE32((uint32)(TcdAddr) + DMA_TCD_DADDR_OFFSET, (uint32)(dest_addr)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_SOFF(TcdAddr, src_off) \
   (REG_WRITE16((uint32)(TcdAddr) + DMA_TCD_TA_SOFF_OFFSET + 2u, (uint16)(src_off)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_CITER_DOFF(TcdAddr, link_iter_doff) \
   (REG_WRITE32((uint32)(TcdAddr) + DMA_TCD_CITER_DOFF_OFFSET, (uint32)(link_iter_doff)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_CITER(TcdAddr, link_iter) \
   (REG_WRITE16((uint32)(TcdAddr) + DMA_TCD_CITER_DOFF_OFFSET, (uint16)(link_iter)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_BITER(TcdAddr, link_iter) \
   (REG_WRITE16((uint32)(TcdAddr) + DMA_TCD_BITER_CCS_OFFSET, (uint16)(link_iter)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_DLAST_SGA(TcdAddr, dlast_sg_addr) \
   (REG_WRITE32((uint32)(TcdAddr) + DMA_TCD_DLAST_SGA_OFFSET, (uint32)(dlast_sg_addr)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Wr_DMA_TCDADDR_FLAGS(TcdAddr, flags) \
   (REG_WRITE8((uint32)(TcdAddr) + DMA_TCD_BITER_CCS_OFFSET + 3u, (uint8)(flags)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Rd_DMA_TCDADDR_FLAGS(TcdAddr) \
   (REG_READ8((uint32)(TcdAddr) + DMA_TCD_BITER_CCS_OFFSET + 3u))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Set_DMA_TCDADDR_INT(TcdAddr) \
    (REG_BIT_SET32((uint32)(TcdAddr) + DMA_TCD_BITER_CCS_OFFSET, \
        (uint32)(DMA_TCD_INT_MAJOR)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Clear_DMA_TCDADDR_INT(TcdAddr) \
    (REG_BIT_CLEAR32((uint32)(TcdAddr) + DMA_TCD_BITER_CCS_OFFSET, \
        (uint32)(DMA_TCD_INT_MAJOR)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Get_DMA_Status(Channel) \
   (REG_BIT_GET32(DMA_TCD_CHANNEL((Channel), (uint32) DMA_TCD_BITER_CCS_OFFSET), BIT7))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */     
#define LLM_Get_DMA_CITER(Channel) \
   (REG_BIT_GET32(DMA_TCD_CHANNEL((Channel), (uint32) DMA_TCD_CITER_DOFF_OFFSET), BIT1))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */   
#define DMA_TCD5_CITER(Channel)    ((uint32) (DMA_TCD(Channel) + 0x0014u))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define DMA_TCD7_BITER(Channel)    ((uint32) (DMA_TCD(Channel) + 0x001Cu))   
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define CLEAR_DMA_INTC(dma_channel)     (REG_WRITE8(DMA_CINT(DMA_MOD_IDX(dma_channel)), \
                                                      (dma_channel) & (DMA_CTRL_MAX_CHANNELS_MASK)))
/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Get_DMA_INTERRUPT_STATUS(dma_channel)   \
        (((dma_channel) < (uint32)0x20UL) ? \
         (uint32)(((uint32)REG_READ32(DMA_INTL(DMA_MOD_IDX(dma_channel)))) & (uint32)((uint32)0x01UL << (uint32)(dma_channel))) : \
         (uint32)(((uint32)REG_READ32(DMA_INTH(DMA_MOD_IDX(dma_channel)))) & (uint32)((uint32)0x01UL << (uint32)((dma_channel) - (uint32)0x20UL))))

/*
 * @violates @ref Reg_eSys_DMA_h_REF_1 Function-like macro defined
 */
#define LLM_Get_DMA_INTERRUPT_ENABLE(dma_channel)   \
        ((uint32)((DMA_TCD_SR(dma_channel))& (DMA_TCD_INT_MAJOR|DMA_TCD_INT_HALF)))

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   Dma Transfer Control Descriptor related types.
*/
typedef VAR(uint8, AUTOMATIC) DmaTcdType[DMA_TCD_SIZE];
typedef P2VAR(uint8, AUTOMATIC, AUTOMATIC) DmaTcdPointerType;

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_DMA_H*/

/** @} */
