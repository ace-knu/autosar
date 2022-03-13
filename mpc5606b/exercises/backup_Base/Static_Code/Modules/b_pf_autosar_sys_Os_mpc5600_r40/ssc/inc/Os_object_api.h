/**
*   @file    Os_object_api.h
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

#ifndef OS_OBJECT_API_H
#define OS_OBJECT_API_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar_api.h>

/*
 * the defines belonged to Os_object_internal_api.h, they were
 * moved here because they are used in configuration files
 */

/*
 * Standard Constants of ObjectTypeType
 */
#define     OBJECT_TASK               ((ObjectTypeType)0x1)
#define     OBJECT_ISR                ((ObjectTypeType)0x2)
#define     OBJECT_ALARM              ((ObjectTypeType)0x3)
#define     OBJECT_RESOURCE           ((ObjectTypeType)0x4)
#define     OBJECT_COUNTER            ((ObjectTypeType)0x5)
#define     OBJECT_SCHEDULETABLE      ((ObjectTypeType)0x6)
#define     OBJECT_MESSAGE            ((ObjectTypeType)0x7)
#define     OBJECT_SPINLOCK           ((ObjectTypeType)0x8)
#define     OBJECT_CORE               ((ObjectTypeType)0x9)
#define     OBJECT_APPLICATION        ((ObjectTypeType)0xA)


#define OSOBJMASK   (OSWORD)0x07FF
#define OSTYPMASK   (OSWORD)0x7800
#define OSOBJSHIFT          (0x0BU)        /* shift to Type Mask */



#if defined(OSEXTSTATUS) || defined(OSCOMEXTSTATUS)

#define OS_MKOBJID(ObjTyp, ObjInd) /*lint -save -e960 */ ((OSObjectType)(((OSObjectType)(ObjTyp))<<OSOBJSHIFT) | (OSObjectType)(ObjInd))  /*lint -restore */ /* macro for SysGen, used in cfg files */
#define OS_GETOBJIND(ObjId)        /*lint -save -e960 */ ((ObjId) & OSOBJMASK)     /*lint -restore */          /* macro to get Object number (index), used in cfg.c */

#else
#define OS_MKOBJID(ObjTyp, ObjInd)  ObjInd
#define OS_GETOBJIND(ObjId) ObjId
#endif



#ifdef __cplusplus
}
#endif


#endif /*OS_OBJECT_API_H */

/** @} */
