/**
*   @file    Reg_eSys_eMIOS.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS200
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
* @section REG_ESYS_EMIOS_H_1
* Violates MISRA 2004 Required Rule 19.15, :  Repeated include file MemMap.h  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation
* since all header files are protected against multiple inclusions
*
* @section REG_ESYS_EMIOS_H_2
* Violates MISRA 2004 Advisory Rule 19.7, : Use of function like macro. This
* violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section REG_ESYS_EMIOS_H_3
* Violates MISRA 2004 Required Rule 20.2, This violation is not fixed since we have not used any
* Standard library macros.
*
* @section REG_ESYS_EMIOS_H_4
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of
* Identifiers (internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*
* @section REG_ESYS_EMIOS_H_5
* Violates MISRA 2004 Required Rule 8.12, When an array is declared with external linkage, its size shall be 
* stated explicitly or defined implicitly by initialisation.
*
* @section REG_ESYS_EMIOS_H_6
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
*/

#ifndef REG_ESYS_EMIOS_H
#define REG_ESYS_EMIOS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref REG_ESYS_EMIOS_H_1 Repeated include file MemMap.h
*/
#include "modules.h"
/*
* @violates @ref REG_ESYS_EMIOS_H_1 Repeated include file MemMap.h
*/
#include "Reg_eSys.h"
/*
* @violates @ref REG_ESYS_EMIOS_H_1 Repeated include file MemMap.h
*/
#include "Reg_Macros.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief   Header file version information
*/
#define REG_ESYS_EMIOS_H_VENDOR_ID                          43
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_H_AR_RELEASE_MAJOR_VERSION           4
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_H_AR_RELEASE_MINOR_VERSION           0
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_H_AR_RELEASE_REVISION_VERSION        3
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_H_SW_MAJOR_VERSION                   1
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_H_SW_MINOR_VERSION                   0
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_H_SW_PATCH_VERSION                   1
/** @} */

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((REG_ESYS_EMIOS_H_AR_RELEASE_MAJOR_VERSION != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (REG_ESYS_EMIOS_H_AR_RELEASE_MINOR_VERSION != MODULES_AR_RELEASE_MINOR_VERSION_H))
    #error "AutoSar Version Numbers of Reg_eSys_eMIOS.h and modules.h are different"
#endif
#endif



/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


#if (USE_GPT_MODULE==STD_ON)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
    #define EMIOS_VAR (GPT_VAR)
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON))
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
    #define EMIOS_VAR (PWM_VAR)
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON))
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
    #define EMIOS_VAR (ICU_VAR)
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_OFF) &&  \
                                                                (USE_MCU_MODULE==STD_ON))
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/                                                                 
    #define EMIOS_VAR (MCU_VAR)
#endif

/**
* @brief EMIOS base address array declaration
*/
#ifdef EMIOSC_BASEADDR
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
extern CONST(uint32, EMIOS_CONST) EMIOS_BASE_ADDR[3];
#else
#ifdef EMIOSB_BASEADDR
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
* @violates @ref REG_ESYS_EMIOS_H_6 Objects shall be defined at block scope if they are only accessed from within a single function. 
*/ 
extern CONST(uint32, EMIOS_CONST) EMIOS_BASE_ADDR[2];
#else
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
extern CONST(uint32, EMIOS_CONST) EMIOS_BASE_ADDR[1];
#endif 
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* This is applicable for the following lines of code */

/**
* @{
* @brief EMIOS Module Registers - global registers, mIdx : emios module index 0 for emiosA, 1 for
*        emiosB
*/

/* MCR: module configuration register */
/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_MCR(mIdx)             (EMIOS_BASE_ADDR[(mIdx)] + (uint32)0x0000UL)

/* GFR: global flag register */
/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_GFR(mIdx)             (EMIOS_BASE_ADDR[(mIdx)] + (uint32)0x0004UL)

/* OUDR: output update disable register */
/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_OUDR(mIdx)            (EMIOS_BASE_ADDR[(mIdx)] + (uint32)0x0008UL)

#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
        /* UCDIS: enable/disable channel - not available on all EMIOS IP versions */
        /* 
        * @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
        */
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/         
        #define EMIOS_UCDIS(mIdx)           (EMIOS_BASE_ADDR[(mIdx)] + (uint32)0x000CUL)
    #endif
#endif
/**@}*/

/*
* @brief EMIOS Module Registers - offset address
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_CADR_OFFSET   (0x00UL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_CBDR_OFFSET   (0x04UL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_CCNTR_OFFSET  (0x08UL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_CCR_OFFSET    (0x0CUL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_CSR_OFFSET    (0x10UL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_ALTA_OFFSET   (0x14UL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_MCR_OFFSET             (0x0000UL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_OUDR_OFFSET            (0x0008UL)
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_UCDIS_OFFSET           (0x000CUL)


/**
* @{
* @brief EMIOS Module Registers - Unified Channel specific registers, mIdx : emios module index 0
*        for
* emiosA, 1 for emiosB, chIdx : unified channel index
*/
/* emios_base_addres[ module_ID ] + 0x20(uc block offset) + channel offset + register offset */
/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_CADR(mIdx, chIdx)    (EMIOS_BASE_ADDR[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x00UL)

/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/                                     
#define EMIOS_CBDR(mIdx, chIdx)    (EMIOS_BASE_ADDR[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x04UL)

/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/                                                                         
#define EMIOS_CCNTR(mIdx, chIdx)   (EMIOS_BASE_ADDR[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x08UL)

/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/                                    
#define EMIOS_CCR(mIdx, chIdx)     (EMIOS_BASE_ADDR[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x0CUL)

/* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/ 
#define EMIOS_CSR(mIdx, chIdx)     (EMIOS_BASE_ADDR[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x10UL)

 /* 
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
*/
/*
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro, 
*/                                   
#define EMIOS_ALTA(mIdx, chIdx)    (EMIOS_BASE_ADDR[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x14UL)
/**@}*/


/** MASK and SHIFT values for each register field */


/**
* @{
* @brief MCR - Module Configuration Register - bitfield mask and shift defines.
*/
#define MCR_DOZEEN_MASK       ((uint32)(BIT31))
#define MCR_DOZEEN_SHIFT      ((uint32)(31U))

#define MCR_MDIS_MASK         ((uint32)(BIT30))
#define MCR_MDIS_SHIFT        ((uint32)(30U))

#define MCR_FRZ_MASK          ((uint32)(BIT29))
#define MCR_FRZ_SHIFT         ((uint32)(29U))

#define MCR_GTBE_MASK         ((uint32)(BIT28))
#define MCR_GTBE_SHIFT        ((uint32)(28U))

#define MCR_ETB_MASK          ((uint32)(BIT27))
#define MCR_ETB_SHIFT         ((uint32)(27U))

#define MCR_GPREN_MASK        ((uint32)(BIT26))
#define MCR_GPREN_SHIFT       ((uint32)(26U))

#define MCR_SRV_MASK          ((uint32)(BIT19|BIT18|BIT17|BIT16))
#define MCR_SRV_SHIFT         ((uint32)(16U))

#define MCR_GPRE_MASK         ((uint32)(BIT15|BIT14|BIT13|BIT12|BIT11|BIT10|BIT9|BIT8))
#define MCR_GPRE_SHIFT        ((uint32)(8U))
/**@}*/


/**
* @{
* @brief GFR - Global Flag Register - bitfield mask and shift defines.
*/

/* mask and shift defines are not needed - read only register */

/**@}*/


/**
* @{
* @brief OUDR - Output Update Disable Register
*/
/* mask and shift defines are not needed */
/**@}*/



/**
* @{
* @brief CADR[n] - unified channel N register A
*/
/* mask and shift defines are not needed */
/**@}*/


/**
* @{
* @brief CBDR[n] - unified channel N register B
*/
/* mask and shift defines are not needed */
/**@}*/


/**
* @{
* @brief CCNTR[n] - unified channel N counter register
*/
/* mask and shift defines are not needed */
/**@}*/

/**
* @{
* @brief CCR[n] - unified channel N control register
*/
#define CCR_FREN_MASK         ((uint32)(BIT31))
#define CCR_FREN_SHIFT        ((uint32)(31U))

#define CCR_ODIS_MASK         ((uint32)(BIT30))
#define CCR_ODIS_SHIFT        ((uint32)(30U))

#define CCR_ODISL_MASK        ((uint32)(BIT29|BIT28))
#define CCR_ODISL_SHIFT       ((uint32)(28U))

#define CCR_UCPRE_MASK        ((uint32)(BIT27|BIT26))
#define CCR_UCPRE_SHIFT       ((uint32)(26U))

#define CCR_UCPREN_MASK       ((uint32)(BIT25))
#define CCR_UCPREN_SHIFT      ((uint32)(25U))

#define CCR_DMA_MASK          ((uint32)(BIT24))
#define CCR_DMA_SHIFT         ((uint32)(24U))

#define CCR_IF_MASK           ((uint32)(BIT22|BIT21|BIT20|BIT19))
#define CCR_IF_SHIFT          ((uint32)(19U))

#define CCR_FCK_MASK          ((uint32)(BIT18))
#define CCR_FCK_SHIFT         ((uint32)(18U))

#define CCR_FEN_MASK          ((uint32)(BIT17))
#define CCR_FEN_SHIFT         ((uint32)(17U))

#define CCR_FORCMA_MASK       ((uint32)(BIT13))
#define CCR_FORCMA_SHIFT      ((uint32)(13U))

#define CCR_FORCMB_MASK       ((uint32)(BIT12))
#define CCR_FORCMB_SHIFT      ((uint32)(12U))

#define CCR_BSL_MASK          ((uint32)(BIT10|BIT9))
#define CCR_BSL_SHIFT         ((uint32)(9U))

#define CCR_EDSEL_MASK        ((uint32)(BIT8))
#define CCR_EDSEL_SHIFT       ((uint32)(8U))

#define CCR_EDPOL_MASK        ((uint32)(BIT7))
#define CCR_EDPOL_SHIFT       ((uint32)(7U))

/* EDGE select mask - part of MODE field */
#define CCR_MODE_EDGE_SELECT_MASK    ((uint32)(BIT1))
#define CCR_MODE_EDGE_SELECT_SHIFT   ((uint32)(1U))
#define CCR_DAOC_MODE_EDGE_SELECT_MASK   ((uint32)(BIT0))
#define CCR_MCB_MODE              ((uint32)(BIT4|BIT6))
#define CCR_MC_MODE              ((uint32)(BIT4))

#define CCR_MODE_MASK         ((uint32)(BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))
#define CCR_MODE_SHIFT        ((uint32)(0U))
/**@}*/


/**
* @{
* @brief CSR[n] - unified channel N status register
*/

#define CSR_OVR_MASK           ((uint32)(BIT31))
#define CSR_OVR_SHIFT          ((uint32)(31U))

#define CSR_OVFL_MASK          ((uint32)(BIT15))
#define CSR_OVFL_SHIFT         ((uint32)(15U))

#define CSR_UCIN_MASK          ((uint32)(BIT2))
#define CSR_UCIN_SHIFT         ((uint32)(2U))

#define CSR_UCOUT_MASK         ((uint32)(BIT1))
#define CSR_UCOUT_SHIFT        ((uint32)(1U))

#define CSR_FLAG_MASK          ((uint32)(BIT0))
#define CSR_FLAG_SHIFT         ((uint32)(0U))

/**@}*/


/**
* @{
* @brief ALTA[n] - unified channel N alternate A register
*/
/* mask and shift defines are not needed */
/**@}*/



/** Bitfield defines. */



/**
* @{
* @brief MCR - bitfield defines.
*/
#define MCR_DOZEEN_ENABLE      ((uint32)(0U))
#define MCR_DOZEEN_DISABLE     ((uint32)(1U))

#define MCR_MDIS_CLK_ON        ((uint32)(0U))
#define MCR_MDIS_LOW_POWER     ((uint32)(1U))

#define MCR_FRZ_DISABLE        ((uint32)(0U))
#define MCR_FRZ_ENABLE         ((uint32)(1U))

#define MCR_GTBE_DISABLE       ((uint32)(0U))
#define MCR_GTBE_ENABLE        ((uint32)(1U))

#define MCR_ETB_UC             ((uint32)(0U))
#define MCR_ETB_STAC           ((uint32)(1U))

#define MCR_GPREN_DISABLE      ((uint32)(0U))
#define MCR_GPREN_ENABLE       ((uint32)(1U))

#define MCR_SRV_ETPUTA_TCR1    ((uint32)(0U))
#define MCR_SRV_ETPUTB_TCR1    ((uint32)(1U))
#define MCR_SRV_ETPUTA_TCR2    ((uint32)(2U))
#define MCR_SRV_ETPUTB_TCR2    ((uint32)(3U))
/**@}*/


/**
* @{
* @brief GFR - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief OUDR - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief CADR[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/


/**
* @{
* @brief CBDR[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/


/**
* @{
* @brief CCNTR[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief CCR[n] - bitfield defines.
*/
#define CCR_FREN_DISABLE     ((uint32)(0U))
#define CCR_FREN_ENABLE      ((uint32)(1U))

#define CCR_ODIS_DISABLE     ((uint32)(0U))
#define CCR_ODIS_ENABLE      ((uint32)(1U))

#define CCR_ODISSL_IN_0      ((uint32)(0U))
#define CCR_ODISSL_IN_1      ((uint32)(1U))
#define CCR_ODISSL_IN_2      ((uint32)(2U))
#define CCR_ODISSL_IN_3      ((uint32)(3U))

#define CCR_UCPRE_DIV_1      ((uint32)(0U))
#define CCR_UCPRE_DIV_2      ((uint32)(1U))
#define CCR_UCPRE_DIV_3      ((uint32)(2U))
#define CCR_UCPRE_DIV_4      ((uint32)(3U))

#define CCR_UCPREN_DISABLE   ((uint32)(0U))
#define CCR_UCPREN_ENABLE    ((uint32)(1U))

#define CCR_DMA_ASSIGN_INT   ((uint32)(0U))
#define CCR_DMA_ASSIGN_DMA   ((uint32)(1U))

#define CCR_IF_BYPASSED      ((uint32)(0U))
#define CCR_IF_2_PERIODS     ((uint32)(1U))
#define CCR_IF_4_PERIODS     ((uint32)(2U))
#define CCR_IF_8_PERIODS     ((uint32)(4U))
#define CCR_IF_16_PERIODS    ((uint32)(8U))

#define CCR_FCK_PRESCALED    ((uint32)(0U))
#define CCR_FCK_MAIN         ((uint32)(1U))

#define CCR_FEN_DISABLE      ((uint32)(0U))
#define CCR_FEN_ENABLE       ((uint32)(1U))

#define CCR_FORCMA_DISABLE   ((uint32)(0U))
#define CCR_FORCMA_ENABLE    ((uint32)(1U))

#define CCR_FORCMB_DISABLE   ((uint32)(0U))
#define CCR_FORCMB_ENABLE    ((uint32)(1U))

#define CCR_BSL_BUS_A        ((uint32)(0U))
#define CCR_BSL_BUS_DIVERSE  ((uint32)(1U))
#define CCR_BSL_BUS_F        ((uint32)(2U))
#define CCR_BSL_INT_COUNTER  ((uint32)(3U))

#define CCR_EDSEL_0          ((uint32)(0U))
#define CCR_EDSEL_1          ((uint32)(1U))

#define CCR_EDPOL_0          ((uint32)(0U))
#define CCR_EDPOL_1          ((uint32)(1U))


/* unified channel mode field */

#define CCR_MODE_GPI         ((uint32)(0x00))
#define CCR_MODE_GPO         ((uint32)(0x01))
#define CCR_MODE_SAIC        ((uint32)(0x02))
#define CCR_MODE_SAOC        ((uint32)(0x03))
#define CCR_MODE_IPWM        ((uint32)(0x04))
#define CCR_MODE_IPM         ((uint32)(0x05))
#define CCR_MODE_DAOC        ((uint32)(0x06))
#define CCR_MODE_DAOC_BOTH   ((uint32)(0x07))

#define CCR_MODE_PEA_CONT    ((uint32)(0x08))
#define CCR_MODE_PEA_SINGLE  ((uint32)(0x09))
#define CCR_MODE_PEC_CONT    ((uint32)(0x0A))
#define CCR_MODE_PEC_SINGLE  ((uint32)(0x0B))

#define CCR_MODE_QDEC_COUNT  ((uint32)(0x0C))
#define CCR_MODE_QDEC_PHASE  ((uint32)(0x0D))

#define CCR_MODE_WPTA        ((uint32)(0x0E))

/* CCR_MODE_ 0x0F reserved */

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MC_UP_CLEAR_START_INT_CLOCK             ((uint32)(0x10))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MC_UP_CLEAR_START_EXT_CLOCK             ((uint32)(0x11))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MC_UP_CLEAR_END_INT_CLOCK               ((uint32)(0x12))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MC_UP_CLEAR_END_EXT_CLOCK               ((uint32)(0x13))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MC_UP_DOWN_FLAG_A_INT_CLOCK             ((uint32)(0x14))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MC_UP_DOWN_FLAG_A_EXT_CLOCK             ((uint32)(0x15))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MC_CHANGE_DIR_INT_CLOCK                 ((uint32)(0x16))
#define CCR_MODE_MC_CHANGE_DIR_EXT_CLK                   ((uint32)(0x17))

#define CCR_MODE_OPWFM_FLAG_B_IMMEDIATE                  ((uint32)(0x18))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWFM_FLAG_B_NEXT_PERIOD                ((uint32)(0x19))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWFM_FLAG_A_FLAG_B_IMMEDIATE           ((uint32)(0x1A))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWFM_FLAG_A_FLAG_B_NEXT_PERIOD         ((uint32)(0x1B))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMC_FLAG_TRAILING_TRAILING_DEAD_TIME  ((uint32)(0x1C))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMC_FLAG_TRAILING_LEADING_DEAD_TIME   ((uint32)(0x1D))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMC_FLAG_BOTH_TRAILING_DEAD_TIME      ((uint32)(0x1E))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMC_FLAG_BOTH_LEADING_DEAD_TIME       ((uint32)(0x1F))

#define CCR_MODE_OPWM_FLAG_B_IMMEDIATE                   ((uint32)(0x20))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWM_FLAG_B_NEXT_PERIOD                 ((uint32)(0x21))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWM_FLAG_A_FLAG_B_IMMEDIATE            ((uint32)(0x22))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWM_FLAG_A_FLAG_B_NEXT_PERIOD          ((uint32)(0x23))

#define CCR_EDPOL_N_MODE_MASK       ((uint32)(0xFFU))
#define CCR_EDPOL_N_MODE_SET        ((uint32)(0xA6U))
#define CCR_EDPOL_N_MODE_CLEAR      ((uint32)(0x26U))   
/* CCR_MODE_ 0x24, 0x25 reserved */

/* Output Pulse Width Modulation with Trigger - not available on all EMIOS IP versions */
#define CCR_MODE_OPWMT                                   ((uint32)(0x26))

/* CCR_MODE_ 0x27 ... 0x4F reserved */



#define CCR_MODE_MCB_INT_CLOCK                           ((uint32)(0x50))
#define CCR_MODE_MCB_EXT_CLOCK                           ((uint32)(0x51))

/* CCR_MODE_ 0x52, 0x53 reserved */

#define CCR_MODE_MCB_FLAG_A_INT_CLOCK                    ((uint32)(0x54))
#define CCR_MODE_MCB_FLAG_A_EXT_CLOCK                    ((uint32)(0x55))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MCB_FLAG_A_CYCLE_INT_CLOCK              ((uint32)(0x56))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_MCB_FLAG_A_CYCLE_EXT_CLOCK              ((uint32)(0x57))

#define CCR_MODE_OPWFMB_FLAG_B                           ((uint32)(0x58))

/* CCR_MODE_ 0x59 reserved */

#define CCR_MODE_OPWFMB_FLAG_AB                          ((uint32)(0x5A))

/* CCR_MODE_ 0x5B reserved */

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMCB_FLAG_TRAILING_TRAILING_DEAD_TIME ((uint32)(0x5C))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMCB_FLAG_TRAILING_LEADING_DEAD_TIME  ((uint32)(0x5D))

/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMCB_FLAG_BOTH_TRAILING_DEAD_TIME     ((uint32)(0x5E))
/*
* @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement, 
*/
#define CCR_MODE_OPWMCB_FLAG_BOTH_LEADING_DEAD_TIME      ((uint32)(0x5F))

#define CCR_MODE_OPWMB_FLAG_B                            ((uint32)(0x60))

/* CCR_MODE_ 0x61 reserved */

#define CCR_MODE_OPWMB_FLAG_AB                           ((uint32)(0x62))

/* CCR_MODE_ 0x63 0x3F reserved */

/**@}*/


/**
* @{
* @brief CSR[n] - bitfield defines.
*/
/* only w1c bits */
#define CSR_OVR_BIT           ((uint32)(BIT31))
#define CSR_OVFL_BIT          ((uint32)(BIT15))
#define CSR_FLAG_BIT          ((uint32)(BIT0))
/**@}*/




/**
* @{
* @brief ALTA[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/






/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_EMIOS_H */
/** @} */

