/**
*   @file    Os_alarm_internal_api.h
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

#ifndef OS_ALARM_INTERNAL_API_H_
#define OS_ALARM_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>           /**< for OSWORD ... */
#include <Os_types_common_public.h>   /**< for AppModeType */
#include <Os_types_common_internal.h> /**< for OSAPPLICATIONTYPE */

#include <Os_alarm_internal_types.h>


#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSHWCOUNTER)
OSDECLAREVAR (extern OSNEAR OSHWTickType, OsTimVal_);
#define OsTimVal OSUSEVAR(OsTimVal_)
#endif

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if (OSNALMS > 0U)

#if (OSNUSERALMS > 0U)
#if (OSNSCTALMS == 0U)           /*  Global OS variables */
#define OSALMARRAY OsAlarms
#else
#define OSALMARRAY (OsAllAlarms.OsAlarms)
#endif
#endif /* (OSNUSERALMS > 0U) */

#if (OSNUSERALMS > 0U)
#if defined(OSAUTOALARMS)
#if (OSNAPPMODES > 1U)
extern void OSInitAutoAlarms (AppModeType mode);
#else /* (OSNAPPMODES > 1U) */
extern void OSInitAutoAlarms (void);
#endif /* (OSNAPPMODES > 1U) */
#endif /* defined(OSAUTOALARMS) */
#endif /*  (OSNUSERALMS > 0U) */

        /*  Private OS Services */
#if (OSNUSERALMS > 0U)
extern void OSInitAlarms (void);
#endif

extern void OSCheckAlarms (OSWORD ctrInd);
extern void OSCounterNotify (OSWORD ctrInd);

#if defined(OSAPPLICATION)
#if (OSNUSERALMS > 0U)
extern void OSKillAppAlarms (OSAPPLICATIONTYPE appId);
#endif
#endif

extern void OSKillAlarm (OSAlmType alarmPtr);

#if defined(OSAPPLICATION)
extern void OSNotifyAlarmAction (OSALMACTPTR action, OSAPPLICATIONTYPE appId);
#else
extern void OSNotifyAlarmAction (OSALMACTPTR action);
#endif

extern void OSInsertAlarm (OSAlmType almId);




#if (OSNUSERALMS > 0U)


#endif /* (OSNUSERALMS > 0U) */

#endif /* (OSNALMS > 0U) */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"



#ifdef __cplusplus
}
#endif



#endif /*OS_ALARM_INTERNAL_API_H_ */

/** @} */
