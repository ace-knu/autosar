/**
*   @file    Os_stack_config.h
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

#ifndef OS_STACK_CONFIG_H_
#define OS_STACK_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#define OSSTKADDS 2            /* additional stack space for compiler */

/* Task stacks */

#if (OSNXTSKS > 0U) || defined(OSMEMPROTECTION)
/*
OsStack structure:
+------------------------------------------------+  &OsStack[0]
|          Protection pad (in SC3..4)            |
+------------------------------------------------+  &OsStack[OSSTACKPROTECTIONPAD/4]
|       Common stack for basic tasks (in SC3..4) |
+------------------------------------------------+  &OsStack[(OSSTACKPROTECTIONPAD + OSCOMMONSTKSIZE)/4]
| Stacks for extended tasks  or for ISRs with MP |
+------------------------------------------------+  &OsStack[(OSSTACKPROTECTIONPAD + OSCOMMONSTKSIZE + OSSTKSIZE)/4]
*/

#if defined(OSMEMPROTECTION)

    #define OSSTACKPROTECTIONPAD (32UL)
                    /* stack protection layer (in bytes) */

    #if defined(OSCOMMONSTKSIZE)
        #define OSSTKBASICSIZE         (OSSTACKPROTECTIONPAD + OSCOMMONSTKSIZE)
                                        /* stack offset for extended tasks' stacks  */
    #else
        #define OSNULLSTACKSIZE         256ul   /* Stack size for null task */
        #define OSSTKBASICSIZE          (OSSTACKPROTECTIONPAD + OSNULLSTACKSIZE)        /* stack offset for extended tasks' stacks  */
    #endif /* defined(OSCOMMONSTKSIZE) */

#else /* below for SC1..2 */

    #define OSSTKBASICSIZE       (0UL)
    #define OSSTACKPROTECTIONPAD (0UL)

#endif /* defined(OSMEMPROTECTION) */


#define OSSTACK_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSSTKSIZE)          /* It is defined if OSNXTSKS > 0 or ( defined(OSMEMPROTECTION) and defined(OSISRENTRYEXIT) ) */
extern OSDWORD OsStacks[(OSSTKSIZE + OSSTKBASICSIZE) / 4U];
#else
#if (OSSTKBASICSIZE > 0U)
extern OSDWORD OsStacks[OSSTKBASICSIZE / 4U];
#endif
#endif

#define OSSTACK_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"




#endif /* (OSNXTSKS > 0U) || defined(OSMEMPROTECTION) */


  /* SysGen places stacks for extended tasks from this address */
#define OSRUNNABLESTKBEG &OsStacks[(OSSTKBASICSIZE)/4U]


#ifdef __cplusplus
}
#endif


#endif /*OS_STACK_CONFIG_H_ */

/** @} */
