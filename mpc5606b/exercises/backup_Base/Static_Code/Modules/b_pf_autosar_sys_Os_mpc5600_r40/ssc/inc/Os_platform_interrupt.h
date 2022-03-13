/**
*   @file    Os_platform_interrupt.h
*   @version 4.0.69
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR OS 4.0
*   Platform             : Power Architecture
*   Peripheral           : e200z0/e200z0h
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 4.0.69
*   Build Version        : MPC5600V4_OS_4.0.69_ASR_REL_4_0_REV_0003
*
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OS_PLATFORM_INTERRUPT_H_
#define OS_PLATFORM_INTERRUPT_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h> /**< user provided platform configuration */

#include <Os_platform_config.h> /**< select IPs available on platform */
#include <Os_platform_base.h>   /**< provides base addresses for each IP */

#include <Os_hw_core.h>          /**< provides register access macros  */
#include <Os_hw_intc.h>


#if (OSNIOCCALLBACKS > 0U)

    /*
     * Software interrupt for IOC callback
     */








       /* Channel 3 is used for IOC interrupts on Z0 core */
#define OSIOCSOFTINTCORE0     3u
#define OSIOCSOFTINVOKECORE0  0x2u
#define OSIOCSOFTCLEARCORE0   0x1u

#define OSIOCCore0Invoke()    (OSINTC_SSCIR0_3 = OSIOCSOFTINVOKECORE0)
#define OSIOCCore0ClearFlag() (OSINTC_SSCIR0_3 = OSIOCSOFTCLEARCORE0)
#define OSIOCCore0GetFlag()   (OSINTC_SSCIR0_3 & OSIOCSOFTCLEARCORE0)


#endif /* OSNIOCCALLBACKS > 0U */

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"



#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"



#define OSINTC_OFFSET 0u


#ifdef __cplusplus
}
#endif


#endif /*OS_PLATFORM_INTERRUPT_H_ */

/** @} */
