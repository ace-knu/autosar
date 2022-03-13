/**
*   @file    Os_hw_etimer.h
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

#ifndef OS_HW_ETIMER_H
#define OS_HW_ETIMER_H

#ifdef __cplusplus
extern "C"
{
#endif



    /**********************************************  eTimer generic registers         *****/
    #define OSCNTMODE     ((OSWORD)0x2000)                    /* Count Mode, count rising edges of primary source */
    #define OSPREOF       ((OSWORD)0x0018)                    /* start prescaler value */
    #define OSPSREMASK    ((OSWORD)0x0700)                    /* prescaler mask */
    #define OSCNTLEN      ((OSWORD)0x0040)                    /* Count Length = 1  - counter counts to the compare value  */
    /* and then re-initializes */
    #define OSCNTRELD     ((OSWORD)0x1800)                    /* Load CNTR with CMPLD1 upon successful compare with */
    /* the value in COMP1,CLC1 = 0x06 */
    #define OSCNTLD       ((OSWORD)0x00)                      /* CNT load value = 0 */
    #define OSNONCNTLD    ((OSWORD)0x00)                      /* non preload mode */

    /**********************************************  eTimer0 registers         *****/
    #define OSENBL        OSREG16(OSeTimerBASE0 + (OSWORD)0x10C)                  /* Channel Enable Register */
    #define OSCOMP(n)     OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)))
    #define OSCNTR(n)     OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)) + (OSWORD)0x0C)/* Counter Register  */
    #define OSCTRL(n)     OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)) + (OSWORD)0x0E)/* Control Register  */
    #define OSCTRLH(n)    OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)) + (OSWORD)0x12)/* Control Register 3 */
    #define OSSTS(n)      OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)) + (OSWORD)0x14)/* Status Register */
    #define OSINTDMA(n)   OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)) + (OSWORD)0x16)/* Interrupt and DMA Enable Register */
    #define OSCMPLD(n)    OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)) + (OSWORD)0x18)/* Comparator Load Register 1 */
    #define OSCCCTRL(n)   OSREG16(OSeTimerBASE0 + ((OSWORD)32*(n)) + (OSWORD)0x1C)/* Compare and Capture Control Register */

    /**********************************************  eTimer1 registers         *****/
        #define OSENBL1       OSREG16(OSeTimerBASE1 + (OSWORD)0x10C)                           /* Channel Enable Register */
        #define OSCOMP1(n)    OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)))                        /* Compare Register 1  */
        #define OSCNTR1(n)    OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)) + (OSWORD)0x0C)         /* Counter Register  */
        #define OSCTRL1(n)    OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)) + (OSWORD)0x0E)         /* Control Register  */
        #define OSCTRLH1(n)   OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)) + (OSWORD)0x12)         /* Control Register 3 */
        #define OSSTS1(n)     OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)) + (OSWORD)0x14)         /* Status Register */
        #define OSINTDMA1(n)  OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)) + (OSWORD)0x16)         /* Interrupt and DMA Enable Register */
        #define OSCMPLD1(n)   OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)) + (OSWORD)0x18)         /* Comparator Load Register 1 */
        #define OSCCCTRL1(n)  OSREG16(OSeTimerBASE1 + ((OSWORD)32*(n)) + (OSWORD)0x1C)         /* Compare and Capture Control Register */


    /**************************************************************************/

    #define OSETMER_STARTVAL      ((OSWORD)0x0)/* start counter value for all timers */


#if defined(OSSYSTIMER) || defined(OS2SYSTIMER)


/*********************************************************  System eTimer timer  *****/
#if defined(OSTIMeTimer0) || defined(OSTIMeTimer1) || defined(OSTIMeTimer2)

    #define OSTIMCHBIT      ((OSWORD)1 << OSTIMCHAN)                      /* channel bit */
    #define OSTCF1          ((OSWORD)0x02)                                /* flag bit */
    #define OSTCF1I         OSTCF1                                        /* interrupt bit */

    #if defined(OSTIMeTimer0)
        #define OSTIMTCNT       OSCNTR( OSTIMCHAN )                       /* counter */
        #define OSTIMCHOC       OSCOMP( OSTIMCHAN )                       /* base of the UC */
        #define OSSTREG         OSSTS( OSTIMCHAN )                        /* status register */
        #define OSCTRLREG       OSCTRL( OSTIMCHAN )                       /* control register  */
        #define OSCCCTRLREG     OSCCCTRL( OSTIMCHAN )                     /* compare and capture control register */
        #define OSCMPLDREG      OSCMPLD( OSTIMCHAN )                      /* comparator load register 1 */
        #define OSCOMPREG       OSCOMP( OSTIMCHAN )                       /* compare register 1 */
        #define OSENBLREG       OSENBL                                    /* channel enable register */
        #define OSINTDMAREG     OSINTDMA( OSTIMCHAN )                     /* interrupt register */
        #define OSCTRLHREG      OSCTRLH( OSTIMCHAN )                      /* control register */
        #elif defined(OSTIMeTimer1)
        #define OSTIMTCNT       OSCNTR1( OSTIMCHAN )                      /* counter */
        #define OSTIMCHOC       OSCOMP1( OSTIMCHAN )                      /* base of the UC */
        #define OSSTREG         OSSTS1( OSTIMCHAN )                       /* status register */
        #define OSCTRLREG       OSCTRL1( OSTIMCHAN )                      /* control register  */
        #define OSCCCTRLREG     OSCCCTRL1( OSTIMCHAN )                    /* compare and capture control register */
        #define OSCMPLDREG      OSCMPLD1( OSTIMCHAN )                     /* comparator load register 1 */
        #define OSCOMPREG       OSCOMP1( OSTIMCHAN )                      /* compare register 1 */
        #define OSENBLREG       OSENBL1                                   /* channel enable register */
        #define OSINTDMAREG     OSINTDMA1( OSTIMCHAN )                    /* interrupt register */
        #define OSCTRLHREG      OSCTRLH1( OSTIMCHAN )                     /* control register */
        #elif defined(OSTIMeTimer2)
        #define OSTIMTCNT       OSCNTR2( OSTIMCHAN )                      /* counter */
        #define OSTIMCHOC       OSCOMP2( OSTIMCHAN )                      /* base of the UC */
        #define OSSTREG         OSSTS2( OSTIMCHAN )                       /* status register */
        #define OSCTRLREG       OSCTRL2( OSTIMCHAN )                      /* control register  */
        #define OSCCCTRLREG     OSCCCTRL2( OSTIMCHAN )                    /* compare and capture control register */
        #define OSCMPLDREG      OSCMPLD2( OSTIMCHAN )                     /* comparator load register 1 */
        #define OSCOMPREG       OSCOMP2( OSTIMCHAN )                      /* compare register 1 */
        #define OSENBLREG       OSENBL2                                   /* channel enable register */
        #define OSINTDMAREG     OSINTDMA2( OSTIMCHAN )                    /* interrupt register */
        #define OSCTRLHREG      OSCTRLH2( OSTIMCHAN )                     /* control register */
    #endif       /* defined(OSTIMeTimer0) */


    #if defined(OSSYSTIMFREEZE)
        #define OSCHFREEZE      ((OSWORD)0x01)                            /* freeze bit */
    #else
        #define OSCHFREEZE      ((OSWORD)0x0)
    #endif
    #define OSINTFLAG       OSTCF1                                        /* interrupt flag for external usage */

    #define OSTimHWprepare()                                              /* nothing to do */

    #define OSSysTimRun()        (OSENBLREG |= OSTIMCHBIT)                /* enable timer channel */
    #define OSSysTimStop()       (OSENBLREG &= ~OSTIMCHBIT)               /* disable timer channel */
    #define OSSysTimClearFlag()  (OSSTREG |= OSTCF1)                      /* clear interrupt request flag (OSTCF1 = 0) */
    #define OSSysTimEnableInt()  (OSINTDMAREG |= OSTCF1I)                 /* enable timer interrupts (TCF1I = 1) */
    #define OSSysTimDisableInt() (OSINTDMAREG &= ~OSTCF1I)                /* disable timer interrupts (TCF1I = 0) */
#endif       /* defined(OSTIMeTimer0) || defined(OSTIMeTimer1) || defined(OSTIMeTimer2) */


/***************************************************************************
* Macro:    OSSysTimSetHW
*
* Description: System timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
* Notes:
*
*          for eTimer:
*              set Count mode(CNTMODE = 1 );
*              prescaler control bits and value;
*              set re-initialize mode and load(MODULO) value for SW counters;
*              clear counter register;
*
**************************************************************************/

#if defined(OSTIMeTimer0) || defined(OSTIMeTimer1) || defined(OSTIMeTimer2)

OSINLINE void 
OSSysTimSetHW (void)
{
    #if defined(OSTIMPRESCALER)
    /* eTimer channel settings */
    OSCTRLREG = OSCNTMODE | (OSPREOF << 8) | (OSTIMPRESCALER << 8);    /* set Count mode and presc.value */
    OSTIMTCNT = OSETMER_STARTVAL;       /* clear counter register */

    OSCTRLHREG = OSCHFREEZE;            /* set "halt during debug" mode(freeze) */

    #if (OSNSYSHWCTRS > 0U)
    OSCCCTRLREG = OSNONCNTLD;        /* never preload */
    #else
    OSCTRLREG |= OSCNTLEN;           /* set Count Length */
    OSCCCTRLREG = OSCNTRELD;         /* set reload mode */
    #endif
    #endif /* defined(OSTIMPRESCALER) */

    #if defined(OSTIMMODULO)
    OSCMPLDREG = OSCNTLD;               /* CNT load value */
    OSCOMPREG = OSTIMMODULO;            /* set MODULO value */
    #endif
    #if defined(OSTIMPRESCALER)
    OSSysTimRun();                      /* start system timer  */
    #endif /* defined(OSTIMPRESCALER) */
}
#endif /* defined(OSTIMeTimer0) || defined(OSTIMeTimer1) || defined(OSTIMeTimer2) */



#endif /* #if defined(OSSYSTIMER) || defined(OS2SYSTIMER) */


#if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER)


#if defined(OSTIM2eTimer0) || defined(OSTIM2eTimer1) || defined(OSTIM2eTimer2)
/*********************************************************  System eTimer timer  *****/
    #define OSTIM2CHBIT     ((OSWORD)1 << OSTIM2CHAN)                            /* channel bit */
    #define OSTCF2          ((OSWORD)0x02)                    /* flag bit */
    #define OSTCF1I2        OSTCF2                /* interrupt bit */

    #if defined(OSTIM2eTimer0)
        #define OSTIM2TCNT      OSCNTR( OSTIM2CHAN )                      /* counter */
        #define OSTIM2CHOC      OSCOMP( OSTIM2CHAN )                      /* base of the UC */
        #define OSSTREG2        OSSTS( OSTIM2CHAN )                       /* status register */
        #define OSCTRLREG2      OSCTRL( OSTIM2CHAN )                      /* control register  */
        #define OSCCCTRLREG2    OSCCCTRL( OSTIM2CHAN )                    /* compare and capture control register */
        #define OSCMPLDREG2     OSCMPLD( OSTIM2CHAN )                     /* comparator load register 1 */
        #define OSCOMPREG2      OSCOMP( OSTIM2CHAN )                      /* compare register 1 */
        #define OSENBLREG2      OSENBL                                    /* channel enable register */
        #define OSINTDMAREG2    OSINTDMA( OSTIM2CHAN )                    /* interrupt register */
        #define OSCTRLHREG2     OSCTRLH( OSTIM2CHAN )                     /* control register */
        #elif defined(OSTIM2eTimer1)
        #define OSTIM2TCNT      OSCNTR1( OSTIM2CHAN )                     /* counter */
        #define OSTIM2CHOC      OSCOMP1( OSTIM2CHAN )                     /* base of the UC */
        #define OSSTREG2        OSSTS1( OSTIM2CHAN )                      /* status register */
        #define OSCTRLREG2      OSCTRL1( OSTIM2CHAN )                     /* control register  */
        #define OSCCCTRLREG2    OSCCCTRL1( OSTIM2CHAN )                   /* compare and capture control register */
        #define OSCMPLDREG2     OSCMPLD1( OSTIM2CHAN )                    /* comparator load register 1 */
        #define OSCOMPREG2      OSCOMP1( OSTIM2CHAN )                     /* compare register 1 */
        #define OSENBLREG2      OSENBL1                                   /* channel enable register */
        #define OSINTDMAREG2    OSINTDMA1( OSTIM2CHAN )                   /* interrupt register */
        #define OSCTRLHREG2     OSCTRLH1( OSTIM2CHAN )                    /* control register */
        #elif defined(OSTIM2eTimer2)
        #define OSTIM2TCNT      OSCNTR2( OSTIM2CHAN )                     /* counter */
        #define OSTIM2CHOC      OSCOMP2( OSTIM2CHAN )                     /* base of the UC */
        #define OSSTREG2        OSSTS2( OSTIM2CHAN )                      /* status register */
        #define OSCTRLREG2      OSCTRL2( OSTIM2CHAN )                     /* control register  */
        #define OSCCCTRLREG2    OSCCCTRL2( OSTIM2CHAN )                   /* compare and capture control register */
        #define OSCMPLDREG2     OSCMPLD2( OSTIM2CHAN )                    /* comparator load register 1 */
        #define OSCOMPREG2      OSCOMP2( OSTIM2CHAN )                     /* compare register 1 */
        #define OSENBLREG2      OSENBL2                                   /* channel enable register */
        #define OSINTDMAREG2    OSINTDMA2( OSTIM2CHAN )                   /* interrupt register */
        #define OSCTRLHREG2     OSCTRLH2( OSTIM2CHAN )                    /* control register */
    #endif /* defined(OSTIM2eTimer0) */
    

    #if defined(OSSECONDFREEZE)
        #define OSCH2FREEZE     ((OSWORD)0x01)                            /* freeze bit */
    #else
        #define OSCH2FREEZE     ((OSWORD)0x0)
    #endif

    #define OSINTFLAG2      OSTCF2                                        /* interrupt flag for external usage */

    #define OSTim2HWprepare()                                             /* nothing to do */

    #define OSSecondRun()        OSENBLREG2 |= OSTIM2CHBIT                /* enable timer channel */
    #define OSSecondStop()       OSENBLREG2 &= ~OSTIM2CHBIT               /* disable timer channel */
    #define OSSecondClearFlag()  OSSTREG2 |= OSTCF2                       /* clear interrupt request flag (OSTCF2 = 0) */
    #define OSSecondEnableInt()  OSINTDMAREG2 |= OSTCF1I2                 /* enable timer interrupts (TCF1I2 = 1) */
    #define OSSecondDisableInt() OSINTDMAREG2 &= ~OSTCF1I2                /* disable timer interrupts (TCF1I2 = 0) */
#endif       /* defined(OSTIM2eTimer0) || defined(OSTIM2eTimer1) || defined(OSTIM2eTimer2) */


/***************************************************************************
* Macro:    OSSecondTimSetHW
*
* Description: Second timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
* Notes:       actions are similar to OSSystemTimSetHW
*
**************************************************************************/

#if defined(OSTIM2eTimer0) || defined(OSTIM2eTimer1) || defined(OSTIM2eTimer2)

OSINLINE void 
OSSecondSetHW (void)
{
    #if defined(OSTIM2PRESCALER)
    /* eTimer channel settings */
    OSCTRLREG2 = OSCNTMODE | (OSPREOF << 8) | (OSTIM2PRESCALER << 8);   /* set Count mode and presc.value */
    OSTIM2TCNT = OSETMER_STARTVAL;      /* clear counter register */

    OSCTRLHREG2 = OSCH2FREEZE;          /* set "halt during debug" mode */

    #if (OSNSYSHWCTRS == 2U)
    OSCCCTRLREG2 = OSNONCNTLD;       /* never preload */
    #else
    OSCTRLREG2 |= OSCNTLEN;          /* set Count Length */
    OSCCCTRLREG2 = OSCNTRELD;        /* set reload mode */
    #endif
    #endif /* defined(OSTIM2PRESCALER) */

    #if defined(OSTIM2MODULO)
    OSCMPLDREG2 = OSCNTLD;              /* CNT load value */
    OSCOMPREG2 = OSTIM2MODULO;          /* set MODULO value */
    #endif

    #if defined(OSTIM2PRESCALER)
    OSSecondRun();                      /* start second timer  */
    #endif
}
#endif /* defined(OSTIM2eTimer0) || defined(OSTIM2eTimer1) || defined(OSTIM2eTimer2) */


#endif /* #if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER) */


#ifdef __cplusplus
}
#endif


#endif /*OS_HW_ETIMER_H*/

/** @} */

