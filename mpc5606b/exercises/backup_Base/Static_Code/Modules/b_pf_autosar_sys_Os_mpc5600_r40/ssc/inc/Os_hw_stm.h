/**
*   @file    Os_hw_stm.h
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

#ifndef OS_HW_STM_H
#define OS_HW_STM_H


#ifdef __cplusplus
extern "C"
{
#endif


    /************************************************  STM registers  *****/
    #define OSSTMTENBIT     (1U)/* STM timer enable bit */
    #define OSSTMFLBIT      (1U)/* STM channel interrupt flag */
    #define OSSTMCENBIT     (1U)/* STM channel enable bit */
    #define OSSTMFREEZEBIT  (2U)/* STM freeze bit */
    #define OSSTM_CR        OSREG32(OSSTMBASE)                                /* STM Control Register */
    #define OSSTM_CNT       OSREG32(OSSTMBASE + 0x04U)                        /* STM Counter Value */
    #define OSSTM_CCR(n)    OSREG32(OSSTMBASE + 0x10U + (16U*(n)))            /* STM Channel n Control Register */
    #define OSSTM_CIR(n)    OSREG32(OSSTMBASE + 0x14U + (16U*(n)))            /* STM Channel n Interrupt Register */
    #define OSSTM_CMP(n)    OSREG32(OSSTMBASE + 0x18U + (16U*(n)))            /* STM Channel n Compare Register */



    /**************************************************************************/

    #define OSSTM_STARTVAL  ((OSDWORD)0x0)   /**< start value for STM counter */


#if defined(OSSYSTIMER) || defined(OS2SYSTIMER)


/*********************************************************  System STM timer  *****/
#if defined(OSTIMSTM)

    #define OSINTFLAG       OSSTMFLBIT                    /* channel interrupt flag for external usage */

    #define OSTIMTCNT       OSSTM_CNT                    /* counter value */
    #define OSTIMCHOC       OSSTM_CMP(OSTIMCHAN)        /* timer compare value */
    #define OSSTREG         OSSTM_CIR(OSTIMCHAN)        /* status register */

    #if defined(OSSYSTIMFREEZE)
        #define OSTIMFRZBIT     OSSTMFREEZEBIT
    #else
        #define OSTIMFRZBIT     (0U)
    #endif

    #if defined(OSTIMPRESCALER)                 /* set counter,prescaler and timer enable bit */
        #define OSTimHWprepare()     (OSSTM_CR = (OSTIMPRESCALER << 8) | OSTIMFRZBIT | OSSTMTENBIT)
    #else
        #define OSTimHWprepare()                /* nothing to do */
    #endif
    #define OSSysTimRun()                /* running by OSSysTimEnableInt() */
    #define OSSysTimStop()       (OSSTM_CCR(OSTIMCHAN) = 0U)                          /* disable timer channel (CENn = 0) */
    #define OSSysTimClearFlag()  (OSSTM_CIR(OSTIMCHAN) = OSSTMFLBIT)                  /* clear interrupt flag (CIFn = 1) */
    #define OSSysTimEnableInt()  (OSSTM_CCR(OSTIMCHAN) = OSSTMCENBIT)                 /* enable timer interrupts (CENn = 1) */
    #define OSSysTimDisableInt() OSSysTimStop()                        /* disable timer interrupts (CENn = 0) */

#endif       /* defined(OSTIMSTM) */



/***************************************************************************
* Macro:    OSSysTimSetHW
*
* Description: System timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
*          for STM:
*              MODULO value;
*              FREEZE bits if it needs;
*              clear counter register;
*
**************************************************************************/
#if defined(OSTIMSTM)
OSINLINE void 
OSSysTimSetHW (void)
{
    #if defined(OSTIMPRESCALER)
    OSTIMTCNT = OSSTM_STARTVAL;
    #endif

    #if defined(OSTIMMODULO)
    OSTIMCHOC = OSTIMTCNT + OSTIMMODULO;
    #endif

    OSSysTimRun ();        /* start system timer  */
}

#endif     /* OSTIMSTM */


#endif /* #if defined(OSSYSTIMER) || defined(OS2SYSTIMER) */


#if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER)


/*********************************************************  System STM timer  *****/
#if defined(OSTIM2STM)

    #define OSINTFLAG2      OSSTMFLBIT                /* channel interrupt flag for external usage */
    #define OSTIM2TCNT      OSSTM_CNT                    /* counter value */
    #define OSTIM2CHOC      OSSTM_CMP(OSTIM2CHAN)        /* timer compare value */
    #define OSSTREG2        OSSTM_CIR(OSTIM2CHAN)        /* status register */


    #if defined(OSSECONDFREEZE)
        #define OSTIM2FRZBIT    (2U)
    #else
        #define OSTIM2FRZBIT    (0U)
    #endif

    #if defined(OSTIM2PRESCALER)
    /* set counter,prescaler and timer enable bit */
        #define OSTim2HWprepare()    (OSSTM_CR = (OSTIM2PRESCALER << 8) | OSTIM2FRZBIT | OSSTMTENBIT)
    #else
        #define OSTim2HWprepare()            /* nothing to do */
    #endif

    #define OSSecondRun()            /* running by OSSecondEnableInt() */
    #define OSSecondStop()       (OSSTM_CCR(OSTIM2CHAN) = 0U)             /* disable timer channel (CENn = 0) */
    #define OSSecondClearFlag()  (OSSTM_CIR(OSTIM2CHAN) = OSSTMFLBIT)     /* clear interrupt flag (CIFn = 1) */
    #define OSSecondEnableInt()  (OSSTM_CCR(OSTIM2CHAN) = OSSTMCENBIT)    /* the channel is enabled (CENn = 1) */
    #define OSSecondDisableInt() OSSecondStop()                           /* the channel is disabled (CENn = 0) */

#endif /* defined(OSTIM2STM) */


/***************************************************************************
* Macro:    OSSecondTimSetHW
*
* Description: Second timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
* Notes:       actions are similar to OSSystemTimSetHW
*
**************************************************************************/

#if defined(OSTIM2STM)
OSINLINE void 
OSSecondSetHW (void)
{
    #if defined(OSTIM2PRESCALER)
    OSTIM2TCNT = OSSTM_STARTVAL;
    #endif

    #if defined(OSTIM2MODULO)
    OSTIM2CHOC = OSTIM2TCNT + OSTIM2MODULO;
    #endif

    OSSecondRun ();        /* start second timer  */
}
#endif /* defined(OSTIM2STM) */



#endif /* #if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER) */


#ifdef __cplusplus
}
#endif



#endif /*OS_HW_STM_H*/

/** @} */

