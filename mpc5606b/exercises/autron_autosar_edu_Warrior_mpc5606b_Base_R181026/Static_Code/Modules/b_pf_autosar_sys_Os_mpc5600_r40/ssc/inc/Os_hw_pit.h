/**
*   @file    Os_hw_pit.h
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

#ifndef OS_HW_PIT_H
#define OS_HW_PIT_H



#ifdef __cplusplus
extern "C"
{
#endif



    #if defined(OSTIMPIT_TYPE1)
/**********************************************  PIT type1 registers    *****/
        #define OSPITFLG       OSREG32(OSPITBASE + 0x100U)                            /* PIT_RTI Interrupt Flags register */
        #define OSPITINTEN     OSREG32(OSPITBASE + 0x104U)                            /* PIT_RTI Interrupt Enable register */
        #define OSPITINTSEL    OSREG32(OSPITBASE + 0x108U)                            /* PIT Interrupt/DMA Select register */
        #define OSPITEN        OSREG32(OSPITBASE + 0x10CU)                            /* PIT_RTI Timer Enable register */
        #define OSPITCTRL      OSREG32(OSPITBASE + 0x110U)                            /* PIT Control register */
        #define OSTLVAL(n)     OSREG32(OSPITBASE + 4U*(n))                            /* PIT Timer Load Value register */
        #define OSTVAL(n)      OSREG32(OSPITBASE + 0x80U + 4U*(n))                    /* PIT Current Timer Value register */
    #endif
    
    #if defined(OSTIMPIT_TYPE2)
/**********************************************  PIT type2 registers  *****/
        #define OSPITMCR       OSREG32(OSPITBASE)                                    /* PIT Module Control Register */
        #define OSLDVAL(n)     OSREG32(OSPITBASE + 0x100U + (16U*(n)) )                /* Timer Load Value Register */
        #define OSCVAL(n)      OSREG32(OSPITBASE + 0x104U + (16U*(n)) )                /* Current Timer Value Register */
        #define OSTCTRL(n)     OSREG32(OSPITBASE + 0x108U + (16U*(n)) )                /* Timer Control Register */
        #define OSETFLG(n)     OSREG32(OSPITBASE + 0x10CU + (16U*(n)) )                /* Timer Flag Register */
    #endif
    
    #if defined(OSTIMPIT_TYPE3)
/**********************************************  PIT type3 registers,the first channel number is 1 *****/
        #define OSPITMCR       OSREG32(OSPITBASE)                                    /* PIT Module Control Register */
        #define OSLDVAL(n)     OSREG32(OSPITBASE + 0x100U + (16U*(n-1U)) )           /* Timer Load Value Register */
        #define OSCVAL(n)      OSREG32(OSPITBASE + 0x104U + (16U*(n-1U)) )           /* Current Timer Value Register */
        #define OSTCTRL(n)     OSREG32(OSPITBASE + 0x108U + (16U*(n-1U)) )           /* Timer Control Register */
        #define OSETFLG(n)     OSREG32(OSPITBASE + 0x10CU + (16U*(n-1U)) )           /* Timer Flag Register */
    #endif

#if defined(OSSYSTIMER) || defined(OS2SYSTIMER)


/*********************************************************  System timer using PIT  *****/
#if defined(OSTIMPIT) || defined(OS2TIMPIT)

    #if defined(OSTIMPIT_TYPE1)            /* PIT module type 1 */
        #define OSSTREG         OSPITFLG
        #define OSTIMTCNT       OSTVAL( OSTIMCHAN )                        /* counter value */
        #define OSTIMCHOC       OSTLVAL( OSTIMCHAN )                        /* timer load value */
        #define OSTIMCHBIT      ( 1u << OSTIMCHAN )                        /* channel bit */
        #define OSINTFLAG       OSTIMCHBIT                                /* channel interrupt flag for external usage */

        #define OSTimHWprepare()     OSPITCTRL = 0U

        #define OSSysTimRun()        OSPITEN |= OSTIMCHBIT; OSPITINTSEL |= OSTIMCHBIT   /* active timer */
        #define OSSysTimStop()       OSPITEN &= ~OSTIMCHBIT; OSPITINTSEL &= ~OSTIMCHBIT /* disable timer */
        #define OSSysTimClearFlag()  (OSPITFLG = OSTIMCHBIT)                            /* clear interrupt flag (TIFn = 1) */
        #define OSSysTimEnableInt()  (OSPITINTEN |= OSTIMCHBIT)                         /* enable timer interrupts (TIEn = 1) */
        #define OSSysTimDisableInt() (OSPITINTEN &= ~OSTIMCHBIT)                        /* disable timer interrupts (TIEn = 0) */
    #endif

    #if defined(OSTIMPIT_TYPE2) || defined(OSTIMPIT_TYPE3)                            /* PIT module type 2,3 */

        #define OSTIMMDIS      (2U)               /* PIT module clock bit */
        #define OSTIMTENBIT    (1U)               /* timer enable bit */
        #define OSTIMTIFBIT    (1U)               /* timer interrupt flag bit */
        #define OSTIMTIEBIT    (2U)               /* timer interrupt enable bit */
        
        #if defined(OSTIMPIT)
        
            #if defined(OSSYSTIMFREEZE)
                #define OSTIMFRZBIT    (1U)               /* freeze bit */
            #else
                #define OSTIMFRZBIT    (0U)
            #endif
            
            #define OSINTFLAG       OSTIMTIFBIT                    /* timer interrupt flag for external usage */
            
            #define OSTIMTCNT   OSCVAL( OSTIMCHAN )                /* counter value */
            #define OSTIMCHOC   OSLDVAL( OSTIMCHAN )                /* timer load value */
            #define OSSTREG     OSETFLG( OSTIMCHAN )
    
            #define OSTimHWprepare()    OSPITMCR |= OSTIMFRZBIT; OSPITMCR &= ~OSTIMMDIS
            
            #define OSSysTimRun()        (OSTCTRL( OSTIMCHAN ) = OSTIMTENBIT)   /* timer enable ( TENn = 1) */
            #define OSSysTimStop()       (OSTCTRL( OSTIMCHAN ) &= ~OSTIMTENBIT) /* timer disable ( TENn = 0) */
            #define OSSysTimClearFlag()  (OSETFLG( OSTIMCHAN ) = OSTIMTIFBIT)   /* clear interrupt flag (TIFn = 1) */
            #define OSSysTimEnableInt()  (OSTCTRL( OSTIMCHAN ) |= OSTIMTIEBIT)  /* enable timer interrupts (TIEn = 1) */
            #define OSSysTimDisableInt() (OSTCTRL( OSTIMCHAN ) &= ~OSTIMTIEBIT) /* disable timer interrupts (TIEn = 0) */
        
        #endif       /* defined(OSTIMPIT) */
         
         
    #endif       /* defined(OSTIMPIT_TYPE2) || defined(OSTIMPIT_TYPE3) */
#endif       /* defined(OSTIMPIT) || defined(OS2TIMPIT) */

/***************************************************************************
 * Macro:    OSSysTimSetHW
 *
 * Description: System timer's HW initialization;
 *              mode,control bits and prescaler are set here;
 *
 * Notes:
 *
 **************************************************************************/
#if defined(OSTIMPIT)
OSINLINE void
OSSysTimSetHW (void)
{
    #if defined(OSTIMMODULO)
    OSTIMCHOC = OSTIMMODULO;
    #endif
    OSSysTimRun ();        /* start system timer  */
}
#endif   /* defined(OSTIMPIT) */



#endif /*   #if defined(OSSYSTIMER) || defined(OS2SYSTIMER) */

#if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER)

/*********************************************************  Second timer using PIT  *****/
#if defined(OSTIM2PIT) || defined(OS2TIM2PIT)

    #if defined(OSTIMPIT_TYPE1)                /* PIT module type 1 */

        #define OSSTREG2      OSPITFLG

        #define OSTIM2TCNT    OSTVAL( OSTIM2CHAN )                /* counter value */
        #define OSTIM2CHOC    OSTLVAL( OSTIM2CHAN )                /* timer load value */
        #define OSTIM2CHBIT   (1U << OSTIM2CHAN)                /* channel bit */
        #define OSINTFLAG2    OSTIM2CHBIT                    /* channel interrupt flag for external usage */

        #define OSTim2HWprepare()    OSPITCTRL = 0U

        #define OSSecondRun()        OSPITEN |= OSTIM2CHBIT; OSPITINTSEL |= OSTIM2CHBIT     /* active timer */
        #define OSSecondStop()       OSPITEN &= ~OSTIM2CHBIT; OSPITINTSEL &= ~OSTIM2CHBIT   /* disable timer */
        #define OSSecondClearFlag()  (OSPITFLG = OSTIM2CHBIT)                      /* clear interrupt flag (TIFn = 1) */
        #define OSSecondEnableInt()  (OSPITINTEN |= OSTIM2CHBIT)                   /* enable timer interrupts (TIEn = 1) */
        #define OSSecondDisableInt() (OSPITINTEN &= ~OSTIM2CHBIT)                  /* disable timer interrupts (TIEn = 0) */
    #endif

    #if defined(OSTIMPIT_TYPE2) || defined(OSTIMPIT_TYPE3)    /* PIT module type 2,3 */

        #define OSTIM2MDIS      (2U)               /* PIT module clock bit */
        #define OSTIM2TENBIT    (1U)               /* timer enable bit */
        #define OSTIM2TIFBIT    (1U)               /* timer interrupt flag bit */
        #define OSTIM2TIEBIT    (2U)               /* timer interrupt enable bit */

        #if defined(OSTIM2PIT)

            #if defined(OSSECONDFREEZE)
            #define OSTIM2FRZBIT    (1U)               /* freeze bit */
            #else
            #define OSTIM2FRZBIT    (0U)
            #endif
            #define OSINTFLAG2       OSTIM2TIFBIT                    /* timer interrupt flag for external usage */

            #define OSTIM2TCNT    OSCVAL( OSTIM2CHAN )                        /* counter value */
            #define OSTIM2CHOC    OSLDVAL( OSTIM2CHAN )                        /* timer load value */
            #define OSSTREG2      OSETFLG( OSTIM2CHAN )

            #define OSTim2HWprepare()   OSPITMCR |= OSTIM2FRZBIT; OSPITMCR &= ~OSTIM2MDIS

            #define OSSecondRun()        (OSTCTRL( OSTIM2CHAN ) = OSTIM2TENBIT)      /* timer enable ( TENn = 1) */
            #define OSSecondStop()       (OSTCTRL( OSTIM2CHAN ) &= ~OSTIM2TENBIT)    /* timer disable ( TENn = 0) */
            #define OSSecondClearFlag()  (OSETFLG( OSTIM2CHAN ) = OSTIM2TIFBIT)      /* clear interrupt flag (TIFn = 1) */
            #define OSSecondEnableInt()  (OSTCTRL( OSTIM2CHAN ) |= OSTIM2TIEBIT)     /* enable timer interrupts (TIEn = 1) */
            #define OSSecondDisableInt() (OSTCTRL( OSTIM2CHAN ) &= ~OSTIM2TIEBIT)    /* disable timer interrupts (TIEn = 0) */

        #endif  /* defined(OSTIM2PIT) */

    #endif       /* defined(OSTIMPIT_TYPE2) || defined(OSTIMPIT_TYPE3) */
#endif       /* defined(OSTIM2PIT) || defined(OS2TIM2PIT) */

/***************************************************************************
* Macro:    OSSecondTimSetHW
*
* Description: Second timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
* Notes:       actions are similar to OSSystemTimSetHW
*
**************************************************************************/
#if defined(OSTIM2PIT)
OSINLINE void
OSSecondSetHW (void)
{
    #if defined(OSTIM2MODULO)
    OSTIM2CHOC = OSTIM2MODULO;
    #endif
    OSSecondRun ();        /* start second timer  */
}
#endif       /* defined(OSTIM2PIT) */


#endif /*    #if defined(OSSECONDTIMER) || defined(OS2SECONDTIMER) */


#ifdef __cplusplus
}
#endif


#endif /*OS_HW_PIT_H*/

/** @} */

