/**
*   @file    Os_memory_config.h
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

#ifndef OS_MEMORY_CONFIG_H_
#define OS_MEMORY_CONFIG_H_



#ifdef __cplusplus
extern "C"
{
#endif

typedef void (*OS_TRUSTED_FUNCTION) (TrustedFunctionIndexType, TrustedFunctionParameterRefType);

#if defined(OSMEMPROTECTION)

#if !defined(OSEXCEPTIONSTACKSIZE)
#define OSEXCEPTIONSTACKSIZE 128        /* 128 * 4 bytes */
#endif

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

extern OSDWORD OsExceptionStack[OSEXCEPTIONSTACKSIZE];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#endif

#if defined(OSMEMPROTECTION)
          /* Start and end address of non-trusted application data section */
typedef struct
{
    OSDWORD startaddr;          /* Word0 */
    OSDWORD endaddr;            /* Word1 */

} OSMP_DSADDR;

#endif /* defined(OSMEMPROTECTION) */

#if defined(OSMEMPROTECTION)

#if (OSNNOTTRUSTEDAPPS > 0U)

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

          /* Arrays of application data section addresses (in ROM) */
#if (OSNMEMDATA0 > 0U)
extern const OSMP_DSADDR OsMPData[OSNNOTTRUSTEDAPPS];
#endif

#if (OSNMEMDATA1 > 0U)
extern const OSMP_DSADDR OsMPData_1[OSNNOTTRUSTEDAPPS];
#endif

#if (OSNMEMDATA2 > 0U)
extern const OSMP_DSADDR OsMPData_2[OSNNOTTRUSTEDAPPS];
#endif

          /* Arrays of application peripheral section addresses (in ROM) */
#if defined(OSPERIPHERALS0)
extern const OSMP_DSADDR OsMPPeripheral[OSNNOTTRUSTEDAPPS];
#endif
#if defined(OSPERIPHERALS1)
extern const OSMP_DSADDR OsMPPeripheral_1[OSNNOTTRUSTEDAPPS];
#endif
#if defined(OSPERIPHERALS2)
extern const OSMP_DSADDR OsMPPeripheral_2[OSNNOTTRUSTEDAPPS];
#endif

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif /* (OSNNOTTRUSTEDAPPS > 0U) */

#endif /* defined(OSMEMPROTECTION) */

#ifdef __cplusplus
}
#endif


#endif /*OS_MEMORY_CONFIG_H_ */

/** @} */
