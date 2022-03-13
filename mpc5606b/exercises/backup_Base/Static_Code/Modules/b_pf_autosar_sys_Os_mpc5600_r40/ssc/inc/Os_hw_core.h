/**
*   @file    Os_hw_core.h
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

#ifndef OS_HW_CORE_H_
#define OS_HW_CORE_H_

#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_hw_core_compiler.h>

#define OSREG32( address ) /*lint -save -e923 -e960 */ ( *(volatile OSDWORD*)(address) ) /*lint -restore */ /* 32-bit register */
#define OSREG16( address ) /*lint -save -e923 -e960 */ ( *(volatile OSWORD *)(address) ) /*lint -restore */ /* 16-bit register */
#define OSREG8( address )  /*lint -save -e923 -e960 */ ( *(volatile OSBYTE *)(address) ) /*lint -restore */ /*  8-bit register */


#define OSMSR_RI            ((OSDWORD)(0x00000002UL))  /* Recoverable exception bit */
#define OSMSR_ME            ((OSDWORD)(0x00001000UL))  /* Machine check enable bit */
#define OSMSR_PR            ((OSDWORD)(0x00004000UL))  /* Problem state: 0 - supervisor mode, 1 - user mode */

#define OSMSR_EE            ((OSDWORD)(0x00008000UL))  /* External interrupt enable bit */
#define OSMSR_CE            ((OSDWORD)(0x00020000UL))  /* Critical interrupt enable bit */

#define OSMSR_POW           ((OSDWORD)(0x00040000UL))  /* MSR/POW: power management enable bit (WE bit in ESYS)  */

/* Bits in MCESR register */
#define OSMCSR_BUS_ERROR    ((OSDWORD)(0x0000001CUL))  /* BUS_IERROR | BUS_DRERR | BUS_WRERR */
#define OSMCSR_EXCP_ERR     ((OSDWORD)(0x08000000UL))  /* ISI, ITLB, or Bus Error on first instruction fetch for an exception handler */

/* Bits in ESR register */
#define OSESR_ST            ((OSDWORD)(0x00800000UL))  /* bit 'Store operation' */

/* HID0 register bits description */
#define OSHID0_DOZE         ((OSDWORD)(0x00800000UL))  /* Doze mode enable */
#define OSHID0_NAP          ((OSDWORD)(0x00400000UL))  /* Nap mode enable */
#define OSHID0_SLEEP        ((OSDWORD)(0x00200000UL))  /* Sleep mode enable */
#define OSHID0_DPM          ((OSDWORD)(0x00100000UL))  /* Dynamic power management enable */

#define OSMPC_DCI()         (OSSETMSR(( OSGETMSR() ) & (OSDWORD)(~((OSMSR_EE) | (OSMSR_CE))) ))


#ifdef __cplusplus
}
#endif


#endif /*OS_HW_CORE_H_*/

/** @} */

