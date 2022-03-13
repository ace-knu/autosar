/**
*   @file    Os_tp_internal_types_v3.h
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

#ifndef OS_TP_INTERNAL_TYPES_V3_H_
#define OS_TP_INTERNAL_TYPES_V3_H_

#ifdef __cplusplus
extern "C"
{
#endif


#if defined(OSTIMINGPROTECTION)

#if (OSNTPTSKRESLOCKTIME > 0U) || (OSNTPISRRESLOCKTIME > 0U)

/* TP configuration/control block of resource locking time */
struct TagOSTPResLock
{
    OSTPTICKTYPE lockTime;      /* resource locking time */
    OSWORD resId;               /* resource id */
};

typedef struct TagOSTPResLock OSTPRESLOCK;
typedef OSTPRESLOCK OSTPLOCK;

#endif

#endif /* defined(OSTIMINGPROTECTION) */


#ifdef __cplusplus
}
#endif



#endif /*OS_TP_INTERNAL_TYPES_V3_H_ */

/** @} */
