/**
*   @file    Os_prop_autosar_api.h
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

#ifndef OS_PROP_AUTOSAR_API_H
#define OS_PROP_AUTOSAR_API_H


#ifdef __cplusplus
extern "C"{
#endif


/*
 * in here only #defines needed by the API layer
 */

#if !defined(OSPROPH)
    #include    "Os_prop.h"    /* OS Properties */
#else       /* !defined(OSPROPH)    */
    #include    OSPROPH        /* OS Properties */
#endif      /* !defined(OSPROPH)    */


#if defined(OSBCC1)
    #define OSBCC
#endif

#if defined(OSECC1)
    #define OSECC
#endif


/*
 * in the public area because OSTIMINGPROTECTION can determine OSISRENTRYEXIT that
 * is used in Os_services_list.h
 */

#if defined(OSSC2) || defined(OSSC4)
    #define OSTIMINGPROTECTION   /**< Timing protection */
#endif

#if defined(OSSC3) || defined(OSSC4)
    #define OSMEMPROTECTION      /**< Memory protection - needed in the API section */
#endif



#if defined(OSMEMPROTECTION)
    #if !defined(OSEXTSTATUS)
        #define OSEXTSTATUS
    #endif
    #if !defined(OSCOMEXTSTATUS)
        #define OSCOMEXTSTATUS
    #endif
#endif /* defined(OSMEMPROTECTION) */


#if (OSNAPPS > 0U)
    #define OSAPPLICATION    /* Os-Applications are configured */
#endif

#if defined(OSAPPLICATION) || (!defined(OSSC1) && defined(OSHOOKPROTECTION))
    #define OSTERMINATION    /* OS feature to terminate runnables via TerminateApplication()
                                or killing because of a protection violation */
#endif

/*
 * in the public area because OSISRENTRYEXIT is used in
 * Os_services_list.h that is needed in the public area
 */


#if (OSNIOCCALLBACKS > 0U) && !defined(OSISRENTRYEXIT)
    #define OSISRENTRYEXIT
#endif

#if (OSNIOCCALLBACKS > 0U) && defined(OSNOISR2)
    #undef OSNOISR2
#endif

#if (OSNCORES > 1U)
    #define OSMULTICORE    /* multicore configuration */
    #define OSISRENTRYEXIT
#endif /* (OSNCORES > 1U) */

#if (OSNIOCBUFFERS > 0U) || (OSNIOCGROUPBUFFERS > 0U) || (OSNIOCQUEUES > 0U) || (OSNIOCGROUPQUEUES > 0U)
    #define OSIOC
#endif

#define OSNHWCTRS  (OSNHWCTRSCORE0 + OSNHWCTRSCORE1)

    


/*
* in the public area because OSISRENTRYEXIT is used in
* Os_services_list.h that is needed in the public area
*/
#if defined(OSTIMINGPROTECTION) && !defined(OSISRENTRYEXIT)
    #define OSISRENTRYEXIT
#endif


/*
* in the public area because OSCHECKCONTEXT is used in
* Os_services_list.h that is needed in the public area
*/
#if defined(OSHOOKSTARTUP)    || defined(OSAPPHOOKSTARTUP)  || \
    defined(OSHOOKSHUTDOWN)   || defined(OSAPPHOOKSHUTDOWN) || \
    defined(OSHOOKPRETASK)    || defined(OSHOOKPOSTTASK)    || \
    defined(OSHOOKERROR)      || defined(OSAPPHOOKERROR)    || \
    defined(OSHOOKPROTECTION) || defined(OSCOMHOOKERROR)
#define OSHOOKS
#endif

#if defined(OSHOOKS) || defined(OSALMCALLBACK)
#define OSUSECONTEXT
#endif

#if defined(OSISRENTRYEXIT) || defined(OSUSECONTEXT) || defined(OSEXTSTATUS)
/* OsIsrLevel is used for context check, including hooks */
    #define OSUSEISRLEVEL
    #if defined(OSEXTSTATUS)
        #define OSCHECKCONTEXT
    #endif
#endif



/*
* in the public area because OSORTICURRENTSERVICEID is used in
* Os_services_list.h that is needed in the public area
*/
#define OSORTIDEBUGLEVELNOORTI  0U    /* no ORTI support */
#define OSORTIDEBUGLEVELSTATIC  1U    /* static ORTI support */
#define OSORTIDEBUGLEVELRUNTIME 2U    /* run time and static ORTI support */
#define OSORTIDEBUGLEVELISR     3U    /* runtime w/o service trace */

#if !defined(OSORTIDEBUGLEVEL)
#define OSORTIDEBUGLEVEL    OSORTIDEBUGLEVELNOORTI
#endif       /* !defined(OSORTIDEBUGLEVEL) */


#if (OSORTIDEBUGLEVEL == OSORTIDEBUGLEVELISR)
    /* level 3 */
    #define OSORTIRUNNINGISRID /* introducing run-time variable containing */
                               /* the identifier of currently running ISR */
#else 
    #if (OSORTIDEBUGLEVEL >= OSORTIDEBUGLEVELRUNTIME)    /* level 2 or 4 */
        #define OSORTICURRENTSERVICEID
        /* introducing run-time variable containing */
        /* the identifier of currently running OSEK OS service */
        #define OSORTIRUNNINGISRID
        /* introducing run-time variable containing */
        /* the identifier of currently running ISR */
    #endif
#endif /* (OSORTIDEBUGLEVEL == OSORTIDEBUGLEVELISR) */


/* macros for ErrorHook */
#if !defined(OSHOOKERROR)
/* no sense to have it defined w/o ErrorHook */
#undef OSGETSERVICEID
#undef OSPARAMETERACCESS
#endif


#if (defined(OSPARAMETERACCESS) || defined(OSORTICURRENTSERVICEID)) && !defined(OSGETSERVICEID)
#define OSGETSERVICEID
#endif


#ifdef __cplusplus
}
#endif


#endif /*OS_PROP_AUTOSAR_API_H*/

/** @} */

