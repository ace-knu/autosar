/**
*   @file    Os_orti.c
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_orti_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters. 
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character. 
* Compilers are checked for support this length of identifiers.
*
* @section Os_orti_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments. 
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*/

/****************** generic includes START ***********************/
#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>

#include <Os_internal_api.h>
#include <Os_internal_types.h>
#include <Os_internal_config.h>

#include <Os_platform.h>
/****************** generic includes END ***********************/

#include <Os_orti_internal_api.h>

/*
* @violates @ref Os_orti_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSORTICURRENTSERVICEID)
OSDECLAREVAR (OSNEAR volatile OSBYTE, OsOrtiRunningServiceId_);
OSDECLAREVAR (OSNEAR volatile OSBYTE, OsOrtiOldServiceId_);
#endif


#if (OSORTIDEBUGLEVEL > 0U)
OSDECLAREVAR (OSNEAR OSBYTE, OsOrtiRunning_);
OSDECLAREVAR (OSNEAR StatusType, OsLastError_);
#endif

#if  defined(OSORTIRUNNINGISRID) && defined(OSISRENTRYEXIT)
            /* ORTI support for tracing ISR */
OSDECLAREVAR (OSNEAR volatile OSWORD, OSISRId_);        /* the id of currently running ISR */
#endif

/*
* @violates @ref Os_orti_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_orti_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OS_START_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Os_orti_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#if (OSORTIDEBUGLEVEL > 0U)

const OSDWORD OsOrtiStart = (OSDWORD) OSSTACKTOP;
const OSDWORD OsOrtiStackStart = (OSDWORD) OSSTACKBOTTOM;

#endif /* (OSORTIDEBUGLEVEL > 0U) */

#define OS_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Os_orti_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif


/** @} */
