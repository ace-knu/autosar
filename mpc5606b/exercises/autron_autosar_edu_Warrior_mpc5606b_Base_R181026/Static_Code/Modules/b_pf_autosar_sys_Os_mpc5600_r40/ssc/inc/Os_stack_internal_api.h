/**
*   @file    Os_stack_internal_api.h
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

#ifndef OS_STACK_INTERNAL_API_H_
#define OS_STACK_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_prop_autosar.h>


#if defined(OSMEMPROTECTION)

        #define OSSTACKTOP     &OsStacks[(OSSTKBASICSIZE/4U) - (OSDWORD)OSSTKADDS]  /* top of common stack */
        #define OSSTACKBOTTOM  &OsStacks[OSSTACKPROTECTIONPAD/4U]        /* bottom of common stack */
#endif /* defined(OSMEMPROTECTION) */




#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) || defined(OSMEMPROTECTION)
#define OSSTKNOASSIGNED     0xFFFFU
#endif


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSSYSSTKCHECK)
extern void OSCheckStack (void);
#endif

#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)
extern void OSFillStacks (void);
#else
#define OSFillStacks( )
#endif

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern OSWORD OSGetUsedBytes (const OSDWORD * start, OSWORD num);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#if !defined(OSSTKCHECKPATTERN)
#define OSSTKCHECKPATTERN  0x55555555U  /* Pattern to used to fill the stack area */
#endif

#if !defined(OSORTISTACKPATTERN)
#define OSORTISTACKPATTERN  OSSTKCHECKPATTERN
#endif /* !defined(OSORTISTACKPATTERN) */


/***************************************************************************
* Macro:       OSSTKSETGUARD, OSSTKINVALID
*
* Description: initialize, check stack patterns
*
* Notes:       pattern size may be 1 or 2 or 4 long words
*
**************************************************************************/
#if OSSTKCHECKPATTERNSIZE == 1U
#define OSSTKINVALID(ptr)   (*(ptr) != OSSTKCHECKPATTERN)
#define OSSTKSETGUARD(ptr)   *(ptr) = OSSTKCHECKPATTERN

#elif OSSTKCHECKPATTERNSIZE == 2U
#define OSSTKINVALID(ptr)   (((ptr)[0] != OSSTKCHECKPATTERN) || ((ptr)[1] != OSSTKCHECKPATTERN))
#define OSSTKSETGUARD(ptr)   (ptr)[0] = OSSTKCHECKPATTERN; (ptr)[1] = OSSTKCHECKPATTERN

#elif OSSTKCHECKPATTERNSIZE == 4U

#define OSSTKINVALID(ptr)                                               \
    ((((ptr)[0] != OSSTKCHECKPATTERN) || ((ptr)[1] != OSSTKCHECKPATTERN)) || \
     (((ptr)[2] != OSSTKCHECKPATTERN) || ((ptr)[3] != OSSTKCHECKPATTERN)))

#define OSSTKSETGUARD(ptr)                                      \
    (ptr)[0] = OSSTKCHECKPATTERN; (ptr)[1] = OSSTKCHECKPATTERN; \
    (ptr)[2] = OSSTKCHECKPATTERN; (ptr)[3] = OSSTKCHECKPATTERN
#endif


#endif /* defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) */


#ifdef __cplusplus
}
#endif


#endif /*OS_STACK_INTERNAL_API_H_ */

/** @} */
