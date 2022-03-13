/**
*   @file    Os_tp_config_v3.h
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

#ifndef OS_TP_CONFIG_V3_H
#define OS_TP_CONFIG_V3_H


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_tp_internal_types.h>

#if defined (OSTIMINGPROTECTION)

#if (OSNTPBGTS > 0U) ||            \
    ((OSNTPTSKINTLOCKTIME > 0U) || \
     (OSNTPISRINTLOCKTIME > 0U) || \
     (OSNTPTSKRESLOCKTIME > 0U) || \
     (OSNTPISRRESLOCKTIME > 0U))
#define OSTPBUDGET              /* there is  budget or resource/interrupt locking time */
#endif

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

    /* Prototypes of TP interrupt handlers */
extern void OSISRTPForced (void);


#if (OSNTPISRARRIV > 0U) || (OSNTPTSKARRIV > 0U)  /* there is inter-arrival time protection */

extern void OSISRTPTimerOVF (void);           /**< Interrupt handler for 'overflow' STM channel */
#endif



#if (OSNTPBGTS > 0U)
/* Interrupt handler for 'budget' STM channel */
extern void OSISRTPTimerBudget (void);
#endif

#if (OSNTPTSKINTLOCKTIME > 0U) || (OSNTPISRINTLOCKTIME > 0U)
/* Interrupt handler for 'interrupt locking time' STM channel */
extern void OSISRTPTimerIntLock (void);
#endif

#if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)
/* Interrupt handler for 'resource locking time' STM channel */
extern void OSISRTPTimerResLock (void);
#endif




#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#endif /* defined (OSTIMINGPROTECTION) */


#ifdef __cplusplus
}
#endif


#endif /*OS_TP_CONFIG_V3_H */

/** @} */
