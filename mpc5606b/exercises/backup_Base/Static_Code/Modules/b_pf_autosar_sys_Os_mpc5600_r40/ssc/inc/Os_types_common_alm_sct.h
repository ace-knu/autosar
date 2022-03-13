/**
*   @file    Os_types_common_alm_sct.h
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

#ifndef OS_TYPES_COMMON_ALM_SCT_H_
#define OS_TYPES_COMMON_ALM_SCT_H_

#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

#include <Os_alarm_internal_types.h>
#include <Os_schedule_table_internal_types.h>


/*
 * Alarms and Sct common control block
 * placed here as it is used in configuration too
 */

#if (OSNUSERALMS > 0U) && (OSNSCTALMS > 0U)

/* OSALLALARMS structure is intended to ensure that both OsAlarms and OsSCTAlarms arrays
   were located in the memory directly one after another.
   NB! The order of items is important because alarm processing code depends on this. */
typedef struct
{
    OSALMCB OsAlarms[OSNUSERALMS];
    OSSCTALMCB OsSCTAlarms[OSNSCTALMS];

} OSALLALARMS;

#endif


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSNALMS > 0U)
#if (OSNUSERALMS > 0U) && (OSNSCTALMS > 0U)
extern OSALLALARMS OsAllAlarms;                   /**< common CB for alarms and sct */
#endif
#endif /* (OSNALMS > 0U) */

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif



#endif /*OS_TYPES_COMMON_ALM_SCT_H_ */

/** @} */
