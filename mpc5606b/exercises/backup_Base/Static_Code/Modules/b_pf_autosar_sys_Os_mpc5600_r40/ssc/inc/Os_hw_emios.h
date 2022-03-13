/**
*   @file    Os_hw_emios.h
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

#ifndef OS_HW_EMIOS_H
#define OS_HW_EMIOS_H

#ifdef __cplusplus
extern "C"
{
#endif



    /*********************************************  eMIOS registers and bits   *****/
    #define OSGTBE        ((OSDWORD)(0x10000000UL))/* global time base enable bit */
    #define OSGPREN       ((OSDWORD)(0x04000000UL))/* global prescaler enable bit */
    #define OSUCPREN      ((OSDWORD)(0x02000000UL))/* prescaler enable bit */
    #define OSFEN         ((OSDWORD)(0x00020000UL))/* FLAG enable bit */
    #define OSBSL         ((OSDWORD)(0x00000600UL))/* bus select bits: internal counter */
    #define OSPREMASK     ((OSDWORD)(0x0C000000UL))/* channel prescaler mask */
    #define OSGPREMASK    ((OSDWORD)(0x0000FF00UL))/* global prescaler mask */
    
    /**********************************************  eMIOS 0 registers    *****/
    #define OSMTSMCR      OSREG32(OSeMIOSBASE0)                          /* Module Configuration register     */
    #define OSMTSOUDIS    OSREG32(OSeMIOSBASE0 + 0x08U)                  /* Output Update Disable register    */
    #define OSMTSA(n)     OSREG32(OSeMIOSBASE0 + (32U*(n)) + 32U)        /* "A" */
    #define OSMTSB(n)     OSREG32(OSeMIOSBASE0 + (32U*(n)) + 36U)        /* "B" */
    #define OSMTSCNT(n)   OSREG32(OSeMIOSBASE0 + (32U*(n)) + 40U)        /* Counter */
    #define OSMTSC(n)     OSREG32(OSeMIOSBASE0 + (32U*(n)) + 44U)        /* Control */
    #define OSMTSS(n)     OSREG32(OSeMIOSBASE0 + (32U*(n)) + 48U)        /* Status  */
    
    /**********************************************  eMIOS 1 registers    *****/
        #define OSMTSMCR1     OSREG32(OSeMIOSBASE1)                      /* Module Configuration register   */
        #define OSMTSOUDIS1   OSREG32(OSeMIOSBASE1 + 0x08U)              /* Output Update Disable register  */
        #define OSMTSA1(n)    OSREG32(OSeMIOSBASE1 + (32U*(n)) + 32U)    /* "A" */
        #define OSMTSB1(n)    OSREG32(OSeMIOSBASE1 + (32U*(n)) + 36U)    /* "B" */
        #define OSMTSCNT1(n)  OSREG32(OSeMIOSBASE1 + (32U*(n)) + 40U)    /* Counter */
        #define OSMTSC1(n)    OSREG32(OSeMIOSBASE1 + (32U*(n)) + 44U)    /* Control */
        #define OSMTSS1(n)    OSREG32(OSeMIOSBASE1 + (32U*(n)) + 48U)    /* Status  */




    #define OSTIMeMIOSSAOC  (0x03U)                                      /* SAOC Mode */
    #define OSTIMeMIOSMC    (0x10U)                                      /* MC Mode */
    #define OSTIMeMIOSMCB   (0x50U)                                      /* MCB Mode(use when MC is absent) */
    #define OSeMIOSHWMODE   (OSTIMeMIOSSAOC)                             /* SAOC mode is used for all HW eMIOS system timers */



            #define OSeMIOSSWMODE   (OSTIMeMIOSMC)








#if defined(OSSYSTIMER) || defined(OS2SYSTIMER)


/*********************************************************  System eMIOS timer  *****/
#if defined(OSTIMeMIOS) || defined(OSTIMeMIOS1)

#define OSTIMCHBIT      (1U << OSTIMCHAN)                                /* channel bit */
#define OSFLAG          (1U)                                               /* interrupt flag bit */

    #if defined(OSTIMeMIOS)
        #define OSTIMTCNT       OSMTSCNT( OSTIMCHAN )                    /* counter */
        #define OSTIMCHOC       OSMTSA( OSTIMCHAN )                      /* base of the UC */
        #define OSSTREG         OSMTSS( OSTIMCHAN )                      /* status register */
        #define OSMTSCREG       OSMTSC( OSTIMCHAN )                      /* control register */
        #define OSMTSSREG       OSMTSS( OSTIMCHAN )                      /* status register */
        #define OSMTSMCRREG     OSMTSMCR                                 /* module conf.register */
        #define OSMTSOUDISREG   OSMTSOUDIS                               /* output update disable register  */
        #if defined(OSeMIOSGLOBALPRESCALER)
            #define OSeMIOSGLBL     OSeMIOSGLOBALPRESCALER               /* global prescaler value */
        #endif
    #elif defined(OSTIMeMIOS1)
        #define OSTIMTCNT       OSMTSCNT1( OSTIMCHAN )                   /* counter */
        #define OSTIMCHOC       OSMTSA1( OSTIMCHAN )                     /* base of the UC */
        #define OSSTREG         OSMTSS1( OSTIMCHAN )                     /* status register */
        #define OSMTSCREG       OSMTSC1( OSTIMCHAN )                     /* control register */
        #define OSMTSSREG       OSMTSS1( OSTIMCHAN )                     /* status register */
        #define OSMTSMCRREG     OSMTSMCR1                                /* module conf.register */
        #define OSMTSOUDISREG   OSMTSOUDIS1                              /* output update disable register  */
        #if defined(OSeMIOS1GLOBALPRESCALER)
            #define OSeMIOSGLBL     OSeMIOS1GLOBALPRESCALER              /* global prescaler value */
        #endif
    #endif       /* defined(OSTIMeMIOS) */


#if defined(OSSYSTIMFREEZE)
    #define OSCHFREEZE      ((OSDWORD)(0x80000000UL))                               /* Doze Enable bit */
    #define OSFRZ           ((OSDWORD)(0x20000000UL))                               /* Freeze bit */
#else
    #define OSCHFREEZE      (0U)
    #define OSFRZ           (0U)
#endif

#define OSINTFLAG       OSFLAG                                           /* interrupt flag for external usage */

#if defined(OSeMIOSGLOBALPRESCALER) || defined(OSeMIOS1GLOBALPRESCALER)
    #define OSTimGlobalPSR()  OSMTSMCRREG &= ~OSGPREMASK; OSMTSMCRREG |= (OSeMIOSGLBL << 8); OSMTSMCRREG |= OSGPREN
#else
    #define OSTimGlobalPSR()                                             /* nothing to do */
#endif

#if defined(OSTIMPRESCALER)                                              /* global prescaler,presettings and update enable  */
    #if defined(OSeMIOSGLOBALPRESCALER) || defined(OSeMIOS1GLOBALPRESCALER)
        #define OSTimHWprepare()  OSTimGlobalPSR(); OSMTSMCRREG |= OSFRZ | OSGTBE; OSMTSOUDISREG &= ~OSTIMCHBIT
    #else
        #define OSTimHWprepare()  OSMTSMCRREG |= OSFRZ | OSGTBE; OSMTSOUDISREG &= ~OSTIMCHBIT
    #endif
#else
    #define OSTimHWprepare() OSTimGlobalPSR()
#endif       /* defined(OSTIMPRESCALER) */

#define OSSysTimRun()        (OSMTSCREG |= OSUCPREN)                       /* set UCPREN (presc.enable) */
#define OSSysTimStop()       (OSMTSCREG &= ~OSUCPREN)                      /* disable timer channel        */
#define OSSysTimClearFlag()  (OSSTREG = OSFLAG)                            /* clear interrupt request flag */
#define OSSysTimEnableInt()  (OSMTSCREG |= OSFEN)                          /*  enable timer interrupts (FEN = 1) */
#define OSSysTimDisableInt() (OSMTSCREG &= ~OSFEN)                         /* disable timer interrupts (FEN = 0) */

#endif /* defined(OSTIMeMIOS) || defined(OSTIMeMIOS1) */




/***************************************************************************
 * Macro:    OSSysTimSetHW
 *
 * Description: System timer's HW initialization;
 *              mode,control bits and prescaler are set here;
 *
 * Notes:
          for eMIOS:
 *              set GPIO mode to get CNT = 0(optional) and mode;
 *              set output enable bit;
 *              BSL  = b11 - int.counter;
 *              MODE = 0x10(0x050) - MC(MCB) mode for SW counters,MODULO value,
 *              MODE = 0x03(0x06) - SAOC mode for HW counters;
 *              prescaler control bits and value;
 *              FREEZE bits if it needs;
 *
 **************************************************************************/
#if defined(OSTIMeMIOS) || defined(OSTIMeMIOS1)
OSINLINE void
OSSysTimSetHW (void)
{
    #if defined(OSTIMMODULO)
    /* eMIOS channel settings: */
    OSTIMCHOC = OSTIMMODULO;    /* set matching value */
    #endif

    #if defined(OSTIMPRESCALER)
    OSMTSCREG = OSCHFREEZE | OSBSL | (OSTIMPRESCALER << 26);    /* set freeze and counter source and presc.value */

    #if (OSNSYSHWCTRS > 0U)
    OSMTSCREG |= OSeMIOSHWMODE;    /* set HW timer mode */
    #else
    OSMTSCREG |= OSeMIOSSWMODE;    /* set SW timer mode */
    #endif

    OSSysTimRun ();        /* start system timer  */

    #endif /* defined(OSTIMPRESCALER) */
}
#endif       /* defined(OSTIMeMIOS) || defined(OSTIMeMIOS1) */

#endif     /* defined(OSSYSTIMER) || defined(OS2SYSTIMER) */

#if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER)

/*********************************************************  Second eMIOS timer  *****/
#if defined(OSTIM2eMIOS) || defined(OSTIM2eMIOS1)

    #define OSTIM2CHBIT     (1U << OSTIM2CHAN)                    /* channel bit */
    #define OSFLAG2         (1U)            /* interrupt flag bit */

#if defined(OSTIM2eMIOS)

    #define OSTIM2TCNT      OSMTSCNT( OSTIM2CHAN )                       /* counter */
    #define OSTIM2CHOC      OSMTSA( OSTIM2CHAN )                         /* base of the UC */
    #define OSSTREG2        OSMTSS( OSTIM2CHAN )                         /* status register */
    #define OSMTSCREG2      OSMTSC( OSTIM2CHAN )                         /* control register */
    #define OSMTSSREG2      OSMTSS( OSTIM2CHAN )                         /* status register */
    #define OSMTSMCRREG2    OSMTSMCR                                     /* module conf.register */
    #define OSMTSOUDISREG2  OSMTSOUDIS                                   /* output update disable register  */
    #if defined(OSeMIOSGLOBALPRESCALER)
        #define OSeMIOSGLBL2    OSeMIOSGLOBALPRESCALER                   /* global prescaler value */
    #endif

#elif defined(OSTIM2eMIOS1)

    #define OSTIM2TCNT      OSMTSCNT1( OSTIM2CHAN )                      /* counter */
    #define OSTIM2CHOC      OSMTSA1( OSTIM2CHAN )                        /* base of the UC */
    #define OSSTREG2        OSMTSS1( OSTIM2CHAN )                        /* status register */
    #define OSMTSCREG2      OSMTSC1( OSTIM2CHAN )                        /* control register */
    #define OSMTSSREG2      OSMTSS1( OSTIM2CHAN )                        /* status register */
    #define OSMTSMCRREG2    OSMTSMCR1                                    /* module conf.register */
    #define OSMTSOUDISREG2  OSMTSOUDIS1                                  /* output update disable register  */
    #if defined(OSeMIOS1GLOBALPRESCALER)
        #define OSeMIOSGLBL2    OSeMIOS1GLOBALPRESCALER                  /* global prescaler value */
    #endif

#endif  /* defined(OSTIM2eMIOS) */


#if defined(OSSECONDFREEZE)
    #define OSCH2FREEZE   ((OSDWORD)(0x80000000UL))                                   /* Doze Enable bit */
    #define OSFRZ2        ((OSDWORD)(0x20000000UL))                                   /* Freeze bit */
#else
    #define OSCH2FREEZE   (0U)
    #define OSFRZ2        (0U)
#endif

#define OSINTFLAG2    OSFLAG2                                            /* interrupt flag for external usage */

#if ( defined(OSTIMeMIOS1) && defined(OSTIM2eMIOS1) ) || ( defined(OSTIMeMIOS) && defined(OSTIM2eMIOS) )
/* if the 1st timer and the 2nd uses the same eMIOS HW block */

    #define OSTim2HWprepare()                                            /* nothing to do, done in System Timer         */

#else    /* need to do full initialization of eMIOS HW   */

    #if defined(OSeMIOSGLOBALPRESCALER) || defined(OSeMIOS1GLOBALPRESCALER)
        #define OSTim2GlobalPSR()  OSMTSMCRREG2 &= ~OSGPREMASK; OSMTSMCRREG2 |= (OSeMIOSGLBL2 << 8); OSMTSMCRREG2 |= OSGPREN
    #else
        #define OSTim2GlobalPSR()                                        /* nothing to do */
    #endif
    #if defined(OSTIM2PRESCALER)                                         /* global prescaler,presettings and update enable  */
    #if defined(OSeMIOSGLOBALPRESCALER) || defined(OSeMIOS1GLOBALPRESCALER)
        #define OSTim2HWprepare()  OSTim2GlobalPSR(); OSMTSMCRREG2 |= OSFRZ2 | OSGTBE; OSMTSOUDISREG2 &= ~OSTIM2CHBIT
    #else
        #define OSTim2HWprepare()  OSMTSMCRREG2 |= OSFRZ2 | OSGTBE; OSMTSOUDISREG2 &= ~OSTIM2CHBIT
    #endif
    #else/* defined(OSTIMPRESCALER) */
        #define OSTim2HWprepare() OSTim2GlobalPSR()
    #endif /* defined(OSTIM2PRESCALER) */
#endif /* ( defined(OSTIMeMIOS1) && defined(OSTIM2eMIOS1) ) || ( defined(OSTIMeMIOS) && defined(OSTIM2eMIOS) ) */

#define OSSecondRun()        (OSMTSCREG2 |= OSUCPREN)                     /* set UCPREN (presc.enable)    */
#define OSSecondStop()       (OSMTSCREG2 &= ~OSUCPREN)                    /* disable timer channel        */
#define OSSecondClearFlag()  (OSSTREG2 = OSFLAG2)                         /* clear interrupt request flag */
#define OSSecondEnableInt()  (OSMTSCREG2 |= OSFEN)                        /* enable timer interrupts      */
#define OSSecondDisableInt() (OSMTSCREG2 &= ~OSFEN)                       /* disable timer interrupts     */

#endif      /* defined(OSTIM2eMIOS) || defined(OSTIM2eMIOS1) */


/***************************************************************************
 * Macro:    OSSecondTimSetHW
 *
 * Description: Second timer's HW initialization;
 *              mode,control bits and prescaler are set here;
 *
 * Notes:       actions are similar to OSSystemTimSetHW
 *
 **************************************************************************/
#if defined(OSTIM2eMIOS) || defined(OSTIM2eMIOS1)
OSINLINE void 
OSSecondSetHW (void)
{
    #if defined(OSTIM2MODULO)
    /* eMIOS channel settings: */
    OSTIM2CHOC = OSTIM2MODULO;    /* set matching value */
    #endif

    #if defined(OSTIM2PRESCALER)
    OSMTSCREG2 = OSCH2FREEZE | OSBSL | (OSTIM2PRESCALER << 26);    /* set freeze and counter source and presc.value */

    #if (OSNSYSHWCTRS == 2U)
    OSMTSCREG2 |= OSeMIOSHWMODE;    /* set HW timer mode */
    #else
    OSMTSCREG2 |= OSeMIOSSWMODE;    /* set SW timer mode */
    #endif

    OSSecondRun ();        /* start second timer  */
    #endif /* defined(OSTIM2PRESCALER) */
}
#endif /* defined(OSSECONDTIMER) */


#endif       /* defined(OSSECONDTIMER) || defined(OS2SECONDTIMER) */


#ifdef __cplusplus
}
#endif


#endif /*OS_HW_EMIOS_H*/

/** @} */

