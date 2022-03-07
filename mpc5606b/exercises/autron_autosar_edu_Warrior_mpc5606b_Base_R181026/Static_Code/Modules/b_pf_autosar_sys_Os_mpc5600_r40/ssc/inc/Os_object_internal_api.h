/**
*   @file    Os_object_internal_api.h
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

#ifndef OS_OBJECT_INTERNAL_API_H
#define OS_OBJECT_INTERNAL_API_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_object_api.h>      /* get the missing defines back to the original files */



#if defined(OSEXTSTATUS) || defined(OSCOMEXTSTATUS)
#define OSCALCULATEOBJIND
#define OS_GETOBJTYP(ObjId) ((ObjectTypeType)((ObjId) >> OSOBJSHIFT)) /* macro to get Object Type, assuming bits[14,15] == 0 */
#endif



#if defined(OSTIMINGPROTECTION)

/*
 * common for TPv2 and TPv3,4
 */
#define OSTP_MKOBJID(ObjTyp, ObjInd)    ((OSObjectType)((ObjTyp) << OSOBJSHIFT) | (OSObjectType)(ObjInd))       /* macro to get Object number (index) */
#define OSTP_GETOBJIND(ObjId)           ( (ObjId)  &  OSOBJMASK ) /* macro to get Object Type, assuming bits[14,15] == 0 */
#define OSTP_GETOBJTYP(ObjId)           ((ObjectTypeType)((ObjId)  >> OSOBJSHIFT))

#endif /* defined(OSTIMINGPROTECTION) */


#if defined(OSEXTSTATUS)
#define OSIDISINVALID(id, type, limit) ((OS_GETOBJTYP(id) != ((ObjectTypeType)(type))) || (id >= OS_MKOBJID((type),(limit))))
#endif


#if defined(OSEXTSTATUS)
#define OSAPPIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_APPLICATION, OSNAPPS))
#else /* defined(OSEXTSTATUS) */
#define OSAPPIDISINVALID(id)  ((id) >= OSNAPPS)
#endif /* defined(OSEXTSTATUS) */


#if defined(OSEXTSTATUS)

#define OSTASKIDISINVALID(id) (OSIDISINVALID((id), OBJECT_TASK, OSNTSKS))

#if (OSNISR > 0U)
#define OSISRIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_ISR, OSNISR))
#endif

#if defined(OSRESOURCE)
#define OSRESIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_RESOURCE, OSNALLRES_))
#endif

#define OSCTRIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_COUNTER, OSNCTRS))

#if (OSNUSERALMS > 0U)
#define OSALMIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_ALARM, OSNUSERALMS))
#endif

#if defined(OSSCHEDULETABLES)
#define OSSCTIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_SCHEDULETABLE, OSNSCTS))
#endif

#endif /* defined(OSEXTSTATUS) */


#if defined(OSUSETCB) || defined(OSINRES)
#define OSISTASKNOSUSPEND(taskId)   (OSTASKSTATUS(taskId) & OSTCBNOSUSPENDED)
#else
#define OSISTASKNOSUSPEND(taskId)   (OSCHECKTASKSTATUS(taskId))
#endif

#define OSTASKACTEXHAUSTED(taskId)  (OSISTASKNOSUSPEND(taskId))

#ifdef __cplusplus
}
#endif

#endif /*OS_OBJECT_INTERNAL_API_H */

/** @} */
