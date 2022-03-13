/**
*   @file    Os_setup_internal_api.h
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

#ifndef OS_SETUP_INTERNAL_API_H_
#define OS_SETUP_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_prop_autosar.h>
#include <Os_types_common_public.h>     /* for AppModeType */

#include <Os_setup_internal_types.h>
#include <Os_application_config.h>


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSORTIDEBUGLEVEL > 0U) || (OSNAPPMODES > 1U)
extern OSNONCACHE AppModeType OsCurAppMode;
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"


#define OSMODE     0            /* application mode */


#if(OSNAPPMODES > 1U)
        #define OSCURAPPMODE OsCurAppMode
#else
    #define OSCURAPPMODE OSDEFAULTAPPMODE
#endif /* (OSNAPPMODES > 1U) */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OSShutdownOS (StatusType error);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if defined(OSHOOKSCHEDULER)    /* not configurable by OIL */

#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

extern void IdleLoopHook (void);

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"

#endif



#ifdef __cplusplus
}
#endif


#endif /*OS_SETUP_INTERNAL_API_H_ */

/** @} */
