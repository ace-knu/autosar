/**
*   @file    Os_internal_types.h
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

#ifndef OS_INTERNAL_TYPES_H_
#define OS_INTERNAL_TYPES_H_



#ifdef __cplusplus
extern "C"
{
#endif            /* __cplusplus */


#include <Os_prop_autosar.h> /**< for OSMC */

#include <Os_types_public.h>


#include <Os_alarm_internal_types.h>
#include <Os_counter_internal_types.h>
#include <Os_error_internal_types.h>

#include <Os_ioc_internal_types.h>

#include <Os_isr_internal_types.h>
#include <Os_memory_internal_types.h>



#include <Os_resource_internal_types.h>
#include <Os_schedule_table_internal_types.h>
#include <Os_setup_internal_types.h>
#include <Os_task_internal_types.h>

#include <Os_tp_internal_types.h>

#include <Os_types_common_alm_sct.h>


#ifdef __cplusplus
}
#endif            /* __cplusplus */



#endif /*OS_INTERNAL_TYPES_H_*/

/** @} */

