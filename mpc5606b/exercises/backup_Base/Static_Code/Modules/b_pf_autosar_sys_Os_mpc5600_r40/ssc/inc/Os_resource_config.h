/**
*   @file    Os_resource_config.h
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

#ifndef OS_RESOURCE_CONFIG_H_
#define OS_RESOURCE_CONFIG_H_



#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_basic.h>     /* for OSDWORD ... */
#include <Os_types_common_internal.h>   /* for OSPRIOTYPE, OSAPPLICATIONTYPE ... */


#if defined(OSRESOURCE)

#if defined(OSAPPLICATION)

struct TagOSRESCFG
{
    OSAPPLICATIONMASKTYPE appMask;     /* Application identification mask value */
    OSPRIOTYPE resPrio;                /* Resource priority for task resources  */
};

typedef struct TagOSRESCFG OSRESCFG;

#endif

#endif /* defined(OSRESOURCE) */



#if defined(OSRESOURCE)

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

/* Configuration Data declaration  */
#if defined(OSAPPLICATION)
extern const OSRESCFG OsResCfg[OSNRESS + OSNISRRESS];                 /**< used in Os_mem.c and Os_resource.c */
#else
extern const OSPRIOTYPE OsResPrioTbl[OSNRESS + OSNISRRESS];           /**< used in Os_resource.c */
#endif

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* defined(OSRESOURCE) */






#ifdef __cplusplus
}
#endif


#endif /*OS_RESOURCE_CONFIG_H_ */

/** @} */
