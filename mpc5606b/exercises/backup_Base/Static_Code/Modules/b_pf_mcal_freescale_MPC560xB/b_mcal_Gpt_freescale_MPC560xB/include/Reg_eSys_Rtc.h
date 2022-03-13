/**
*   @file    Reg_eSys_Rtc.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Source file of the RTC driver.
*   @details RTC driver interface.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS_Stm_Pit_Rtc
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

#ifndef REG_ESYS_RTC_H
#define REG_ESYS_RTC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_RTC_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section REG_ESYS_RTC_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section REG_ESYS_RTC_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section REG_ESYS_RTC_H_REF_4
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Reg_eSys_Rtc.h
* @implements     DGPT10500
*/
/* @violates @ref REG_ESYS_RTC_H_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file */
#include "Reg_eSys.h"
/* @violates @ref REG_ESYS_RTC_H_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file */
#include "Reg_Macros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_Rtc.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define REG_ESYS_RTC_VENDOR_ID                       43
/* @violates @ref REG_ESYS_RTC_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref REG_ESYS_RTC_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref REG_ESYS_RTC_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_RTC_AR_RELEASE_REVISION_VERSION     3
#define REG_ESYS_RTC_SW_MAJOR_VERSION                1
#define REG_ESYS_RTC_SW_MINOR_VERSION                0
#define REG_ESYS_RTC_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef IPV_RTC
    /* @brief IP class RTC.00.00.03.00 */
    /* @violates @ref REG_ESYS_RTC_H_REF_4 C macros shall only expand to a braced initialiser expression */
    #define IPV_RTC_00_00_03_00     0x00000300UL
#endif



/**
* @{
* @brief Real Time Counter (RTC) Registers address
*/
#define RTC_SUPV            (RTC_BASEADDR + (uint32)0x00UL)
#define RTC_CR              (RTC_BASEADDR + (uint32)0x04UL)
#define RTC_SR              (RTC_BASEADDR + (uint32)0x08UL)
#define RTC_CNT             (RTC_BASEADDR + (uint32)0x0CUL)
#define RTC_APIVAL          (RTC_BASEADDR + (uint32)0x10UL)
#define RTC_RTCVAL          (RTC_BASEADDR + (uint32)0x14UL)
/**@}*/

/**
* @brief Number of channels in RTC
*/
#define RTC_MAX_CH          ((uint8)1U)

/**
* @brief Bit mask for RTC Supervisor Control Register
*/
#define RTC_SUPV_MASK       ((uint32)0x80000000UL)

/**
* @{
* @brief Bit mask for RTC Control Register
*/
#define RTC_CNTEN_MASK      ((uint32)0x80000000UL)
#define RTC_RTCIE_MASK      ((uint32)0x40000000UL)
#define RTC_FRZEN_MASK      ((uint32)0x20000000UL)
#define RTC_ROVREN_MASK     ((uint32)0x10000000UL)
#define RTC_RTCVAL_MASK     ((uint32)0x0FFF0000UL)
#define RTC_APIEN_MASK      ((uint32)0x00008000UL)
#define RTC_APIIE_MASK      ((uint32)0x00004000UL)
#define RTC_CLKSEL_MASK     ((uint32)0x00003000UL)
#define RTC_DIV512EN_MASK   ((uint32)0x00000800UL)
#define RTC_DIV32EN_MASK    ((uint32)0x00000400UL)
#define RTC_APIVAL_MASK     ((uint32)0x000003FFUL)
/**@}*/


/**
* @{
* @brief Bit mask for RTC Status Register
*/
#define RTC_RTCF_MASK       ((uint32)0x20000000UL)
#define RTC_APIF_MASK       ((uint32)0x00002000UL)
#define RTC_ROVRF_MASK      ((uint32)0x00000400UL)
#define RTC_ALL_INT_MASK    ((uint32)0x20002400UL)
/**@}*/

/**
* @{
* @brief Bit offset for RTC Control Register
*/
#define RTC_RTCVAL_OFFSET   16U
#define RTC_CLKSEL_OFFSET   12U
#define RTC_DIV_OFFSET      10U
/**@}*/

/**
* @brief Highest possible value for RTC API Value
*/
#define RTC_API_RTCC_APIVAL_MAX_VALUE                ((uint32)0x000003FFuL)

 /**
* @brief Macros for RTC Supervisor Control Register
*/
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_CONFIG_SUPERVISOR_MODE(value)   (REG_RMW32(RTC_CR, RTC_SUPV_MASK, (value)))

/**
* @{
* @brief Macros for RTC Control Register
*/
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_COUNTER_ENABLE()                (REG_BIT_SET32(RTC_CR, RTC_CNTEN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_COUNTER_DISABLE()               (REG_BIT_CLEAR32(RTC_CR, RTC_CNTEN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_API_READ_STATE()                (REG_READ32(RTC_CR) & RTC_APIEN_MASK)
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_RTC_INT_ENABLE()                (REG_BIT_SET32(RTC_CR, RTC_RTCIE_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_RTC_INT_DISABLE()               (REG_BIT_CLEAR32(RTC_CR, RTC_RTCIE_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_FREEZE_ENABLE()                 (REG_BIT_SET32(RTC_CR, RTC_FRZEN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_FREEZE_DISABLE()                (REG_BIT_CLEAR32(RTC_CR, RTC_FRZEN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_ROLL_OVER_INT_ENABLE()          (REG_BIT_SET32(RTC_CR, RTC_ROVREN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_ROLL_OVER_INT_DISABLE()         (REG_BIT_CLEAR32(RTC_CR, RTC_ROVREN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_API_ENABLE()                    (REG_BIT_SET32(RTC_CR, RTC_APIEN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_API_DISABLE()                   (REG_BIT_CLEAR32(RTC_CR, RTC_APIEN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_API_INT_ENABLE()                (REG_BIT_SET32(RTC_CR, RTC_APIIE_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_API_INT_DISABLE()               (REG_BIT_CLEAR32(RTC_CR, RTC_APIIE_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_READ_API_INT_ENABLE()           (REG_BIT_GET32(RTC_CR, RTC_APIIE_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_DIV512_ENABLE()                 (REG_BIT_SET32(RTC_CR, RTC_DIV512EN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_DIV512_DISABLE()                (REG_BIT_CLEAR32(RTC_CR, RTC_DIV512EN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_DIV32_ENABLE()                  (REG_BIT_SET32(RTC_CR, RTC_DIV32EN_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_DIV32_DISABLE()                 (REG_BIT_CLEAR32(RTC_CR, RTC_DIV32EN_MASK))

/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_CLOCK_SELECT(value)             (REG_RMW32(RTC_CR, RTC_CLKSEL_MASK, (uint32)(((uint32)(value))<<RTC_CLKSEL_OFFSET)))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_CONFIGURE_PRESCALER(value)      (REG_RMW32(RTC_CR, (RTC_DIV32EN_MASK | RTC_DIV512EN_MASK), (uint32)(((uint32)(value))<<RTC_DIV_OFFSET)))

#ifdef IPV_RTC
    #if (IPV_RTC >= IPV_RTC_00_00_03_00)
        /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
        #define RTC_API_SET_COMPARE(value)          (REG_WRITE32(RTC_APIVAL, (value)))
        /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
        #define RTC_API_GET_COMPARE()               (REG_READ32(RTC_APIVAL))
        /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
        #define RTC_RTC_SET_COMPARE(value)          (REG_WRITE32(RTC_RTCVAL, (value)))
    #else
        /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
        #define RTC_API_SET_COMPARE(value)          (REG_RMW32(RTC_CR, RTC_APIVAL_MASK, ((value) & RTC_APIVAL_MASK)))
        /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
        #define RTC_API_GET_COMPARE()               (RTC_APIVAL_MASK & REG_READ32(RTC_CR))
        /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
        #define RTC_RTC_SET_COMPARE(value)          (REG_RMW32(RTC_CR, RTC_RTCVAL_MASK, (uint32)(((uint32)(value))<<RTC_RTCVAL_OFFSET)))
    #endif
#else
    /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
    #define RTC_API_SET_COMPARE(value)          (REG_RMW32(RTC_CR, RTC_APIVAL_MASK, ((value) & RTC_APIVAL_MASK)))
    /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
    #define RTC_API_GET_COMPARE()               (RTC_APIVAL_MASK & REG_READ32(RTC_CR))
    /* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
    #define RTC_RTC_SET_COMPARE(value)          (REG_RMW32(RTC_CR, RTC_RTCVAL_MASK, (uint32)(((uint32)(value))<<RTC_RTCVAL_OFFSET)))
#endif

/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_RESET_CNTRL_REG()               (REG_RMW32(RTC_CR, (uint32)0xDFFFFFFFUL, (uint32)0x0UL))
/**@}*/

/**
* @{
* @brief Macros for RTC Status Register
*/
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_CLEAR_RTC_INTERRUPT()           (REG_WRITE32(RTC_SR, RTC_RTCF_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_READ_API_INTERRUPT()            (REG_BIT_GET32(RTC_SR, RTC_APIF_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_CLEAR_API_INTERRUPT()           (REG_WRITE32(RTC_SR, RTC_APIF_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_CLEAR_ROVR_INTERRUPT()          (REG_WRITE32(RTC_SR, RTC_ROVRF_MASK))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_CLEAR_ALL_INTERRUPT()           (REG_WRITE32(RTC_SR, RTC_ALL_INT_MASK))
/**@}*/

/**
* @{
* @brief Macros for RTC Counter Register
*/
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_GET_COUNTER()                   (REG_READ32(RTC_CNT))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_RESET_COUNTER()                 (REG_WRITE32(RTC_CNT, (uint32)0x0UL))
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7, Use of function like macro */
#define RTC_API_GET_COUNTER()               (REG_READ32(RTC_CNT) & RTC_APIVAL_MASK)
/**@}*/

/*==================================================================================================
*                                             ENUMS
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

#define GPT_START_SEC_CODE
/* @violates @ref REG_ESYS_RTC_H_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#define GPT_STOP_SEC_CODE
/* @violates @ref REG_ESYS_RTC_H_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_RTC_H*/

/**@}*/
