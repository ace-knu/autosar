/**
*   @file    Os_prop_autosar.h
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

#ifndef OS_PROP_AUTOSAR_H
#define OS_PROP_AUTOSAR_H


#ifdef __cplusplus
extern "C"
{
#endif

/*
*  in here only defines needed in the Autosar layer, no need to export them to Autosar API layer and to the user
*
*/

#include <Os_prop_autosar_api.h>

#if !defined(OSPROPH)
#include    "Os_prop.h"    /* OS Properties */
#else      /* !defined(OSPROPH)    */
#include    OSPROPH    /* OS Properties */
#endif      /* !defined(OSPROPH)    */









#if defined(OSSC2) || ( defined(OSSC1) &&  defined(OSISRENTRYEXIT) && defined(OSECC) )
/* if there are ISR2 or systimer then common ISR stack is used in SC2 and SC1, ECC1 */
#define OSUSEISRSTACK
#endif

#if defined(OSNOISR1) && !defined(OSISRENTRYEXIT) && !defined(OSTIMINGPROTECTION) && (OSNCORES < 2U)
/* same as #if OSNISR == 0 */
#define OSNOISR
#endif

#if defined(OSEXTSTATUS)
#define OSCHECKDISABLEDINT
#endif

#if defined(OSSTKCHECK)

    #define OSSYSSTKCHECK    /* OS checks stacks (no User check functions) */
    #if defined(OSHOOKPROTECTION)
        #if !defined(SC1)
            #define OSSTKHOOKPROTECTION                /* ProtectionHook for stack monitoring violation */
        #endif
    #endif       /* defined(OSHOOKPROTECTION) */
    
#endif       /* defined(OSSTKCHECK) */

#if (OSNXTSKS > 0U) || defined(OSMEMPROTECTION)
    #define OSUSETOS        /* top of stack defined in TagOSTSKCB  */
    #if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) || defined(OSMEMPROTECTION)
        #define OSUSEBOS    /* bottom of stack defined in TagOSTSKCB  */
    #endif
#endif

#if defined(OSUSETOS) || !defined(OSSC1) || defined(OSEXTSTATUS)
    #if !defined(OSNOFASTTERMINATE)
        #define OSNOFASTTERMINATE    /* FastTerminate may be used only in SC1, BCC1, STATUS STANDARD */
    #endif
#endif

#if defined(OSNOFASTTERMINATE) || defined(OSRESOURCE)
#define OSUSETCB        /* OS uses Task Control Block */
#endif

    #if defined(OSRESOURCE)
        #define OSUSERESLINK
    #endif



#if defined(OSCOUNTER)

#define OSNSYSHWCTRS (OSNHWCTRS)

#if OSNCTRS > OSNHWCTRS
#define OSSWCOUNTER    /* there are SW counters */
#endif

#endif /* defined(OSCOUNTER) */

#if !defined(OSNSCTALMS)
#define OSNSCTALMS (OSNSCTS)
#endif

#if defined(OSNAUTOALMS)
#if (OSNAUTOALMS > 0U)
#define OSAUTOALARMS
#endif
#endif


#if defined(OSAPPLICATION)
        #if !defined(OSNOISR1) || !defined(OSNOISR2)
            #define OSKILLAPPISRS
        #endif
#endif /* defined(OSAPPLICATION) */


#ifdef __cplusplus
}
#endif


#endif /*OS_PROP_AUTOSAR_H*/

/** @} */

