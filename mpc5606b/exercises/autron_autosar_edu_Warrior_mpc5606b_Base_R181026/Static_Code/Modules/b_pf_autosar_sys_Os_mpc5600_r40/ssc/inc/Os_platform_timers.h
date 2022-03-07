/**
*   @file    Os_platform_timers.h
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

#ifndef OS_PLATFORM_TIMERS_H_
#define OS_PLATFORM_TIMERS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h> /**< user provided platform configuration */

#include <Os_platform_config.h> /**< select IPs available on platform */
#include <Os_platform_base.h>   /**< provides base addresses for each IP */

#include <Os_hw_core.h>          /**< provides register access macros  */



#include <Os_hw_emios.h>

#include <Os_hw_etimer.h>


#include <Os_hw_pit.h>


#include <Os_hw_stm.h>


/*********************** platform specific definitions for timers ***********************/

#if defined(OSHWCOUNTER)




#if defined(OSTIMSTM) || defined(OSTIM2STM)
typedef OSDWORD OSHWTickType;
#else
typedef OSWORD OSHWTickType;    /* eMIOS/eTimer 16bits */
#endif












#endif /* defined(OSHWCOUNTER) */






#if defined(OSMPC5602D) || defined(OSMPC5604B) || defined(OSMPC5606B) || defined(OSMPC5607B)

    #if (OSNHWCTRS == 2U)
        #if defined(OSTIMSTM) && defined(OSTIM2STM)
            #define OSCTRBITS(num) (num)    /* 32 bit STM counter */
        #else
            #if defined(OSTIMSTM)
                #define OSCTRBITS(num) ((ctrInd != 0U) ? (OSWORD)(num) : (num))  /* 16 bit eMIOS counter or */
            #elif defined(OSTIM2STM)        /* 32 bit STM counter */
                #define OSCTRBITS(num) ((ctrInd == 0U) ? (OSWORD)(num) : (num))
            #else
                #define OSCTRBITS(num) ((OSWORD)(num))  /* 32 bit STM counter */
            #endif /* defined(OSTIMSTM) */
        #endif /* defined(OSTIMSTM) && defined(OSTIM2STM) */

    #elif (OSNHWCTRS == 1U)
        #if defined(OSTIMeMIOS) || defined(OSTIMeMIOS1)
            #define OSCTRBITS(num) ((OSWORD)(num))  /* 16 bit eMIOS counter */
        #else
            #define OSCTRBITS(num) (num)    /* 32 bit STM counter */
        #endif /* defined(OSTIMeMIOS) || defined(OSTIM2eMIOS) */

    #endif /* (OSNHWCTRS == 2U) */

#endif /* defined(OSMPC5602D) || defined(OSMPC5604B) || defined(OSMPC5606B) || defined(OSMPC5607B) */


#if defined(OSMPC5602P) || defined(OSMPC5604P)

    #if (OSNHWCTRS == 2U)
        #if defined(OSTIMSTM) && defined(OSTIM2STM)
            #define OSCTRBITS(num) (num)    /* 32 bit STM counter */
        #else
            #if defined(OSTIMSTM)
                #define OSCTRBITS(num) ((ctrInd != 0U) ? (OSWORD)(num) : (num))  /* 16 bit eTimer counter or */
            #elif defined(OSTIM2STM)        /* 32 bit STM counter */
                #define OSCTRBITS(num) ((ctrInd == 0U) ? (OSWORD)(num) : (num))
            #else
                #define OSCTRBITS(num) ((OSWORD)(num))
            #endif /* defined(OSTIMSTM) */
        #endif /* defined(OSTIMSTM) && defined(OSTIM2STM) */

    #elif (OSNHWCTRS == 1U)
        #if defined(OSTIMeTimer0) || defined(OSTIMeTimer1) || defined(OSTIMeTimer2)
            #define OSCTRBITS(num) ((OSWORD)(num))  /* 16 bit eTimer counter */
        #else
            #define OSCTRBITS(num) (num)    /* 32 bit STM counter */
        #endif /* defined(OSTIMeTimer1) || defined(OSTIM2eTimer1) || defined(OSTIMeTimer2) */
    #endif /* (OSNHWCTRS == 2U) */

#endif /* defined(OSMPC5602P) || defined(OSMPC5604P) */


























#if defined(OSSYSTIMER)

#if defined(OSTIMDEC) || defined(OSTIMFIT)
#define OSSTREG             (OSINTC_SSCIR4_7)
#define OSSysTimClearFlag() (OSSTREG = OSSYSSOFTCLEAR)
#define OSSysTimFlagIsSet() (OSSTREG & OSSYSSOFTCLEAR)


#else /* below for other timers */

#define OSSysTimFlagIsSet() (OSSTREG & OSINTFLAG)

#if defined(OSHWCOUNTER)
#if defined(OSTIMeMIOS)
#define OSTIMSetCNTVal( value ) \
                    OSMTSCREG &= ~OSeMIOSHWMODE;   /* enter to GPIO mode for CNT change */ \
                    OSTIMTCNT = value; \
                    OSMTSCREG |= OSeMIOSHWMODE;    /* restore SAOC mode */ \
                    OSSysTimClearFlag()
#else
#define OSTIMSetCNTVal( value ) \
                        OSTIMTCNT = value; \
                        OSSysTimClearFlag()
#endif
#endif /* defined(OSHWCOUNTER) */

#endif /* defined(OSTIMDEC) || defined(OSTIMFIT) */
#endif /* defined(OSSYSTIMER) */


#if defined(OSSECONDTIMER)
#if defined(OSTIM2DEC) || defined(OSTIM2FIT)
#define OSSTREG2            (OSINTC_SSCIR4_7)
#define OSSecondClearFlag() (OSSTREG2 = OSSECSOFTCLEAR)
#define OSSecondFlagIsSet() (OSSTREG2 & OSSECSOFTCLEAR)


#else  /* below for other timers */

#define OSSecondFlagIsSet() (OSSTREG2 & OSINTFLAG2)

#if defined(OSHWCOUNTER)
#if defined(OSTIM2eMIOS)
#define OSTIM2SetCNTVal( value )                                        \
    OSMTSCREG2 &= ~OSeMIOSHWMODE;   /* enter to GPIO mode for CNT change */ \
    OSTIM2TCNT = value;                                                 \
    OSMTSCREG2 |= OSeMIOSHWMODE;    /* restore SAOC mode */             \
    OSSecondClearFlag()
#else
#define OSTIM2SetCNTVal( value )                \
    OSTIM2TCNT = value;                         \
    OSSecondClearFlag()
#endif
#endif /* defined(OSHWCOUNTER) */
#endif /* defined(OSTIM2DEC) || defined(OSTIM2FIT) */
#endif /* defined(OSSECONDTIMER) */





#if defined(OSHWCOUNTER)


/* Single core implementation */
#if (OSNHWCTRS == 1U)

#define OSHWCtrInterruptRaised( ctrId )  OSSysTimFlagIsSet()
#define OSHWCtrValue( ctrId )            (OSTIMTCNT)
#define OSHWCtrGetOC( ctrId )            (OSTIMCHOC)
#define OSHWCtrInit( ctrId, value )      OSTIMSetCNTVal( value )

#else /* OSNHWCTRS == 1U */

#define OSHWCtrInterruptRaised( ctrId )  ( ( (ctrId) != 0U ) ? OSSecondFlagIsSet() : OSSysTimFlagIsSet() )
#define OSHWCtrValue( ctrId )            ( ( (ctrId) != 0U ) ? (OSTIM2TCNT) : (OSTIMTCNT) )
#define OSHWCtrGetOC( ctrId )            ( ( (ctrId) != 0U ) ? (OSTIM2CHOC) : (OSTIMCHOC) )
#define OSHWCtrInit( ctrId, value )             \
    if( ctrId == 1U)                            \
    {                                           \
        OSTIM2SetCNTVal( value );               \
    }                                           \
    else                                        \
    {                                           \
        OSTIMSetCNTVal( value );                \
    }
#endif /* OSNHWCTRS == 1U */


#endif /* defined(OSHWCOUNTER) */




#ifdef __cplusplus
}
#endif


#endif /* OS_PLATFORM_TIMERS_H_ */

/** @} */
