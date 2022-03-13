/**
*   @file    Os_memory_internal_types.h
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

#ifndef OS_MEMORY_INTERNAL_TYPES_H_
#define OS_MEMORY_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_memory_config.h> /* for OS_TRUSTED_FUNCTION ... */

#if defined(OSMEMPROTECTION)
typedef void (*OSSRV) (void);
#endif


#if defined(OSMEMPROTECTION)

/* Prepared MPU descriptor fields (except Word2) for each non-trusted application */
typedef struct
{
    OSDWORD startaddr;       /* Word0 */
    OSDWORD endaddr;         /* Word1 */
    OSDWORD valid;           /* Word3 */
    OSDWORD descaddr;        /* MPU descriptor address */

}OSMP_DSADDR_CB;

#endif            /* defined(OSMEMPROTECTION) */


#ifdef __cplusplus
}
#endif

#endif /*OS_MEMORY_INTERNAL_TYPES_H_*/

/** @} */

