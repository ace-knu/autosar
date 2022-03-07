/**
*   @file    Reg_eSys_Pit.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - PIT driver header file.
*   @details PIT module register description.
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

#ifndef REG_ESYS_PIT_H
#define REG_ESYS_PIT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_PIT_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section REG_ESYS_PIT_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section REG_ESYS_PIT_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref REG_ESYS_PIT_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Reg_eSys.h"
/* @violates @ref REG_ESYS_PIT_H_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Reg_Macros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_Pit.h
* @requirements   BSW00374, BSW00379, BSW00318
* @implements     DGPT09500
*/
#define REG_ESYS_PIT_VENDOR_ID                       43
/* @violates @ref REG_ESYS_PIT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_PIT_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref REG_ESYS_PIT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_PIT_AR_RELEASE_MINOR_VERSION        0
/* @violates @ref REG_ESYS_PIT_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define REG_ESYS_PIT_AR_RELEASE_REVISION_VERSION     3
#define REG_ESYS_PIT_SW_MAJOR_VERSION                1
#define REG_ESYS_PIT_SW_MINOR_VERSION                0
#define REG_ESYS_PIT_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* PIT Registers */
/**
* @brief Timer Load Value Register (LDVAL)  Register address
*/
#define PIT_LDVAL0                                (PIT_BASEADDR + (uint32)0x0100UL)

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Timer Load Value Register (LDVAL)  Register address where as n is channel number
*/
#define PIT_LDVAL(n)                              (PIT_LDVAL0 + (uint32)((n)*0x0010UL))

/**
* @brief Current Timer Value Register (CVAL)  Register address
*/
 #define PIT_CVAL0                                (PIT_BASEADDR + (uint32)0x0104UL)

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Current Timer Value Register (CVAL)  Register address where as n is channel number
*/
#define PIT_CVAL(n)                               (PIT_CVAL0 + (uint32)((n)*0x0010UL))

/**
* @brief Timer Flag Register (TFLG)  Register address
*/
#define PIT_TFLG0                                 (PIT_BASEADDR + (uint32)0x010CUL)

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Timer Flag Register (TFLG)  Register address where as n is channel number
*/
#define PIT_TFLG(n)                               (PIT_TFLG0 + (uint32)((n)*0x0010UL))

/**
* @brief TFLG - bitfield defines.TIF bits in the Timer Flag Register (TFLG) register
*/
#define PIT_TFLG_TIF                              ((uint32)0x00000001)

/**
* @brief Timer Control Register (TCTRL)  Register address
*/
#define PIT_TCTRL0                                (PIT_BASEADDR + (uint32)0x0108UL)

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Timer Control Register (TCTRL)  Register address where as n is channel number
*/
#define PIT_TCTRL(n)                              (PIT_TCTRL0 + (uint32)((n)*0x0010UL))

/**
* @brief TCTRL - bitfield defines. TIE and TEN bits in the Timer Control Register (TCTRL)
*/
#define PIT_TCTRL_TIE                             ((uint32)0x00000002)
#define PIT_TCTRL_TEN                             ((uint32)0x00000001)

/**
* @brief PIT Module Control Registers (PITMCR)  Register address
*/
#define PIT_MCR                                   (PIT_BASEADDR + (uint32)0x00UL)

/**
* @brief PITMCR - bitfield defines.MDIS and FRZ bits in the PIT_MCR register
*/
#define PIT_MCR_MDIS                              ((uint32)0x00000002)
#define PIT_MCR_FRZ                               ((uint32)0x00000001)

/**
* @brief highest possible loading value for PIT channels
*/
#define PIT_LDVAL_MAX_VALUE                 ((uint32)0xFFFFFFFFuL)

/* Macros */
/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to Enable Clock for PIT Timers
*/
#define PIT_ENABLE_MODULE()             (REG_BIT_CLEAR32(PIT_MCR,PIT_MCR_MDIS))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to disable Clock for PIT Timers
*/
#define PIT_DISABLE_MODULE()            (REG_BIT_SET32(PIT_MCR,PIT_MCR_MDIS))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to Enable PIT timer
*/
#define PIT_TIMER_ENABLE(channel)       (REG_BIT_SET32(PIT_TCTRL(channel)  ,(uint32)PIT_TCTRL_TEN))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to Disable PIT timer
*/
#define PIT_TIMER_DISABLE(channel)      (REG_BIT_CLEAR32(PIT_TCTRL(channel) ,(uint32)PIT_TCTRL_TEN))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to read the PIT timer status
*/
#define PIT_READ_STATE(channel)         (REG_READ32(PIT_TCTRL(channel))&((uint32)PIT_TCTRL_TEN))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to Enable PIT interrupt
*/
#define PIT_INTERRUPT_ENABLE(channel)   (REG_BIT_SET32(PIT_TCTRL(channel),(uint32)PIT_TCTRL_TIE))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to Disable the PIT interrupt
*/
#define PIT_INTERRUPT_DISABLE(channel)  (REG_BIT_CLEAR32(PIT_TCTRL(channel),(uint32)PIT_TCTRL_TIE))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to clear the interrupt flag
*/
#define PIT_CLEAR_INT_FLAG(channel)     (REG_WRITE32(PIT_TFLG(channel),(uint32)PIT_TFLG_TIF))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to read the flag bit
*/
#define PIT_READ_INTERRUPT(channel)     ((REG_READ32(PIT_TFLG(channel)))&((uint32)PIT_TFLG_TIF)) 

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to read the timer value
*/
#define PIT_READTIMERVALUE(channel)     (REG_READ32(PIT_CVAL(channel)))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to write the timeout value into Timer Load Value Register (LDVAL)
*/
#define PIT_SETLOADVALUE(channel,value) (REG_WRITE32(PIT_LDVAL(channel), (value)))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to read the timeout value form Timer Load Value Register (LDVAL)
*/
#define PIT_GETLOADVALUE(channel)       (REG_READ32(PIT_LDVAL(channel)))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to Enable the Freeze
*/
#define PIT_FREEZE_ENABLE()             (REG_BIT_SET32(PIT_MCR,PIT_MCR_FRZ))

/* @violates @ref REG_ESYS_PIT_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro */
/**
* @brief Macro to disable the Freeze
*/
#define PIT_FREEZE_DISABLE()            (REG_BIT_CLEAR32(PIT_MCR,PIT_MCR_FRZ))

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

#endif /*REG_ESYS_PIT_H*/

/** @} */
