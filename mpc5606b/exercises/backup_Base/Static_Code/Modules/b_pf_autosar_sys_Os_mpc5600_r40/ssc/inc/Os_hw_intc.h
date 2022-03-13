/**
*   @file    Os_hw_intc.h
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

#ifndef OS_HW_INTC_H
#define OS_HW_INTC_H



#ifdef __cplusplus
extern "C"
{
#endif


#define OSINTC_MCR        OSREG32(OSINTC_BASE_ADDR)    /* Module Configuration Register */
#define OSINTC_TST        OSREG32(OSINTC_BASE_ADDR + 0x04U)    /* Test Register */

#define OSINTC_CPR        OSREG32(OSINTC_BASE_ADDR + 0x08U + OSINTC_OFFSET)    /* Current Priority Register */
#define OSINTC_IACKR      OSREG32(OSINTC_BASE_ADDR + 0x10U + OSINTC_OFFSET)    /* Interrupt Acknowledge Register */
#define OSINTC_EOIR       OSREG32(OSINTC_BASE_ADDR + 0x18U + OSINTC_OFFSET)    /* End of Interrupt Register */

#define OSINTC_SSCIR0_3   OSREG32(OSINTC_BASE_ADDR + 0x20U)    /* Software Set/Clear Interrupt Register 0-3 */
#define OSINTC_SSCIR4_7   OSREG32(OSINTC_BASE_ADDR + 0x24U)    /* Software Set/Clear Interrupt Register 4-7 */

#define OSINT_PSR         (OSINTC_BASE_ADDR + 0x40U)                /* Priority Select Registers Base Address */
#define OSINT_PSRX(sint)  (OSREG32(OSINT_PSR + (((sint) >> 2U)*4U)))  /* INT_PSR x address which is contained sint input */

#define OSINT_OFFSET_PSRX(sint) ((3U - ((sint) - (((sint) >> 2U)*4U)))*8U)  /* it calculates number of byte in PSRX [0..3] */


/* Set prio to sint input */
#define OSSET_INT_PSRX(sint, prio) (OSINT_PSRX(sint) |= ((OSDWORD)(prio) << OSINT_OFFSET_PSRX(sint))) /* Clear current prio for sint input */
/* Clear prio on sint input */
#define OSCLEAR_INT_PSRX(sint)     (OSINT_PSRX(sint) &= (OSDWORD)~(0xFU << OSINT_OFFSET_PSRX(sint)))

#define OSINTC_MCR_HVEN            ((OSDWORD)(0x00000001UL))                        /* Hardware vector mode */
#define OSINTC_MCR_VTES            ((OSDWORD)(0x00000020UL))                        /* Vector Table Entry Size = 8 */






#ifdef __cplusplus
}
#endif

#endif /*OS_HW_INTC_H*/

/** @} */

