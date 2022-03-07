/**
*   @file    Mcu_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - File used by MCU that contain the ISRs.
*   @details This file contains the ISR functions used to serve the MCU interrupts.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF13_ASR_REL_4_0_REV_0003_20170719
*
*   (c) Copyright 2006-2016 Freescale Semiconductor Inc and STMicroelectronics
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_irq_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
**
* @section Mcu_irq_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory 
* section
*
* @section Mcu_irq_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
* 
* @section Mcu_irq_c_REF_4
* Violates MISRA 2004 Required Rule 8.1, Functions defined without a prototype in scope.
* 
* @section Mcu_irq_c_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Mcu_irq_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, API could not be made static.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Mcu_Irq.c
* @implements     DMCU00009
*/
#include "Mcu_LLD.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_Irq.c
* @implements     DMCU04059, DMCU04060, DMCU04061, DMCU04062, DMCU04063, DMCU04064, DMCU04065
*/
#define MCU_IRQ_VENDOR_ID_C                    43
/* @violates @ref Mcu_irq_c_REF_5 Identifier exceeds 31 characters */
#define MCU_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref Mcu_irq_c_REF_5 Identifier exceeds 31 characters */
#define MCU_IRQ_AR_RELEASE_MINOR_VERSION_C     0
/* @violates @ref Mcu_irq_c_REF_5 Identifier exceeds 31 characters */
#define MCU_IRQ_AR_RELEASE_REVISION_VERSION_C  3
#define MCU_IRQ_SW_MAJOR_VERSION_C             1
#define MCU_IRQ_SW_MINOR_VERSION_C             0
#define MCU_IRQ_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_LLD.h header file are of the same vendor */
#if (MCU_IRQ_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
#error "Mcu_Irq.c and Mcu_LLD.h have different vendor ids"
#endif
/**
* @implements     DMCU06001
*/
/* Check if current file and Mcu_LLD.h header file are of the same Autosar version */

#if ((MCU_IRQ_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IRQ_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IRQ_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_Irq.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h header file are of the same Software version */
#if ((MCU_IRQ_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_IRQ_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_IRQ_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_Irq.c and Mcu_LLD.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
/* By default interrupt callbacks are not affected. */
#if (MCU_XOSC_ISR_USED == STD_ON)
/* @violates @ref Mcu_irq_c_REF_6 API could not be made static */
P2FUNC (void, const, Mcu_XOSC_ISR_Callback)(void) = NULL_PTR;
#endif
#if (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON)
/* @violates @ref Mcu_irq_c_REF_5 Identifier exceeds 31 characters */
/* @violates @ref Mcu_irq_c_REF_6 API could not be made static */
P2FUNC (void, const, Mcu_TransitionComplete_ISR_Callback)(void) = NULL_PTR;
#endif
#if (MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON)
/* @violates @ref Mcu_irq_c_REF_6 API could not be made static */
P2FUNC (void, const, Mcu_InvalidConfig_ISR_Callback)(void) = NULL_PTR;
#endif
#if (MCU_INVALID_MODE_ISR_USED == STD_ON)
/* @violates @ref Mcu_irq_c_REF_6 API could not be made static */
P2FUNC (void, const, Mcu_InvalidMode_ISR_Callback)(void) = NULL_PTR;
#endif
#if (MCU_SAFE_MODE_ISR_USED == STD_ON)
/* @violates @ref Mcu_irq_c_REF_6 API could not be made static */
P2FUNC (void, const, Mcu_EnterSafeMode_ISR_Callback)(void) = NULL_PTR;
#endif
#if (MCU_RGM_ALTERNATEMODE_ISR_USED == STD_ON)
/* @violates @ref Mcu_irq_c_REF_6 API could not be made static */
P2FUNC (void, const, Mcu_AlternateMode_ISR_Callback)(void) = NULL_PTR; 
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_irq_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_irq_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if ((MCU_XOSC_ISR_USED == STD_ON) || defined(__DOXYGEN__))
/*================================================================================================*/
/**
* @brief          This function represents the ISR for the oscillator stability.
* @details        When the external oscillator is stabilized, if enabled, an 
*                 interrupt is triggered.
*
* @isr
*
* @implements     DMCU04081
*/
ISR(Mcu_XOSC_ISR)
{
    /* check for spurious ISR's */
    VAR(uint32, AUTOMATIC) XoscIsrMask;
    VAR(uint32, AUTOMATIC) XoscIsrFlag;

    /* read the XOSC ISR MASK */
    /* get only the requiered flag */
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    XoscIsrMask = (uint32)REG_READ32(MC_CGM_XOSC_CTL_R);
    XoscIsrMask &= (uint32)((uint32)0x01U << (uint32)MCU_FIFTEEN_VALUE);
    /* read the XOSC ISR FLAG*/
    /* get only the requiered flag */
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    XoscIsrFlag = (uint32)REG_READ32(MC_CGM_XOSC_CTL_R);
    XoscIsrFlag &= (uint32)((uint32)0x01U<<(uint32)MCU_SEVEN_VALUE);
    /* check if the ISR is enabled and pending */
    if ( ((uint32)0x00U != (uint32)XoscIsrFlag) && ((uint32)0x00U != (uint32)XoscIsrMask) )
    {
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    REG_BIT_SET32(MC_CGM_XOSC_CTL_R, MCU_CRYSTAL_OSC_INT);
        if( Mcu_XOSC_ISR_Callback != NULL_PTR )
        {
            Mcu_XOSC_ISR_Callback();
        }
    }
     /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON) || defined(__DOXYGEN__)
/*================================================================================================*/
/**
* @brief          This function represents the ISR associated to a mode transition.
* @details        When a ME transition is completed, if enabled, an interrupt is 
*                 triggered.
*
* @isr
*
* @implements     DMCU04082
*/
ISR(Mcu_TransitionComplete_ISR)
{
    VAR(uint32, AUTOMATIC) MeIsrMask ;
    VAR(uint32, AUTOMATIC) MeIsrFlag ;
 /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrMask = (uint32)REG_READ32(MC_ME_IM_R);
    MeIsrMask &= (uint32)((uint32)0x01 << (uint32)MCU_ZERO_VALUE);
 /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrFlag = (uint32)REG_READ32(MC_ME_IS_R);
    MeIsrFlag &= (uint32)((uint32)0x01 << (uint32)MCU_ZERO_VALUE);

    if( ((uint32)0x00U != (uint32)MeIsrFlag) && ((uint32)0x00U != (uint32)MeIsrMask) )
    {

    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    REG_WRITE32(MC_ME_IS_R, (uint32) MCU_ONE_VALUE);
        if( Mcu_TransitionComplete_ISR_Callback != NULL_PTR )
        {
            Mcu_TransitionComplete_ISR_Callback();
        }
    }
     /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if ((MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || defined(__DOXYGEN__))
/*================================================================================================*/
/**
* @brief          This function represents the ISR for an invalid mode configuration.
* @details        An interrupt is triggered if an attempt to apply an invalid 
*                 mode configuration is detected by the ME module.. 
*
* @isr
*
* @implements     DMCU04083
*/
ISR(Mcu_InvalidConfig_ISR)
{
 /* check for spurious ISR's */
    VAR(uint32, AUTOMATIC) MeIsrMask;
    VAR(uint32, AUTOMATIC) MeIsrFlag;
  /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrMask = (uint32)REG_READ32(MC_ME_IM_R);
    MeIsrMask &= (uint32)(((uint32)0x01U << (uint32)MCU_THREE_VALUE) | ((uint32)0x01U << (uint32)MCU_FOUR_VALUE));
  /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrFlag = (uint32)REG_READ32(MC_ME_IS_R);
    MeIsrFlag &= (uint32)(((uint32)0x01U << (uint32)MCU_THREE_VALUE) | ((uint32)0x01U << (uint32)MCU_FOUR_VALUE));

    if( ((uint32)0x00U != (uint32)MeIsrFlag) && ((uint32)0x00U != (uint32)MeIsrMask) )
     {
        /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
        if(ME_IS_CONF_SET == (REG_READ32(MC_ME_IM_R) & ME_IS_CONF_SET))
        {
            /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
            REG_WRITE32(MC_ME_IS_R, (uint32) MCU_EIGHT_VALUE);
            if( Mcu_InvalidConfig_ISR_Callback != NULL_PTR )
            {
                Mcu_InvalidConfig_ISR_Callback();
            }
        }
    }
      /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if ((MCU_INVALID_MODE_ISR_USED == STD_ON) || defined(__DOXYGEN__))
/*================================================================================================*/
/**
* @brief          This function represents the ISR for an invalid mode.
* @details        If an attempt to enter an invalid mode is detected by the ME 
*                 module, if enabled, an interrupt is triggered.
*
* @isr
*
* @implements     DMCU04084
*/
ISR(Mcu_InvalidMode_ISR)
{    
    VAR(uint32, AUTOMATIC) MeIsrMask ;
    VAR(uint32, AUTOMATIC) MeIsrFlag ;
/* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrMask = (uint32)REG_READ32(MC_ME_IM_R);
    MeIsrMask &= (uint32)((uint32)0x01U << (uint32)MCU_TWO_VALUE);
/* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrFlag = (uint32)REG_READ32(MC_ME_IS_R);
    MeIsrFlag &= (uint32)((uint32)0x01U << (uint32)MCU_TWO_VALUE);

    if( ((uint32)0x00U != (uint32)MeIsrFlag) && ((uint32)0x00U != (uint32)MeIsrMask) )
    {
/* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    REG_WRITE32(MC_ME_IS_R, (uint32) MCU_FOUR_VALUE);
/* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    if (MCU_ONE_VALUE == (REG_READ32(MC_ME_IMTS_R) & MCU_ONE_VALUE) )
    {
        /* This bit is set if the device is in SAFE mode */
        /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
        REG_WRITE32(MC_ME_IMTS_R, (uint32) MCU_ONE_VALUE); 
            if( Mcu_InvalidMode_ISR_Callback != NULL_PTR )
            {
                Mcu_InvalidMode_ISR_Callback();
            }
    }
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    if (MCU_TWO_VALUE == (REG_READ32(MC_ME_IMTS_R) & MCU_TWO_VALUE) )
    {
        /* This bit is set if the target mode request is one of those non existing determined in ME register */
        /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
        REG_WRITE32(MC_ME_IMTS_R, (uint32) MCU_TWO_VALUE); 
            if( Mcu_InvalidMode_ISR_Callback != NULL_PTR )
            {
                Mcu_InvalidMode_ISR_Callback();
            }
    }
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    if (MCU_FOUR_VALUE == (REG_READ32(MC_ME_IMTS_R) & MCU_FOUR_VALUE) )
    {
        /* This bit is set if the target mode request is one of those non enabled in ME register */
        /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
        REG_WRITE32(MC_ME_IMTS_R, (uint32) MCU_FOUR_VALUE); 
            if( Mcu_InvalidMode_ISR_Callback != NULL_PTR )
            {
                Mcu_InvalidMode_ISR_Callback();
            }                                                           
    }
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    if (MCU_EIGHT_VALUE == (REG_READ32(MC_ME_IMTS_R) & MCU_EIGHT_VALUE) )
    {
        /* This bit is set if the mode request is invalide mode */
        /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
        REG_WRITE32(MC_ME_IMTS_R, (uint32) MCU_EIGHT_VALUE); 
            if( Mcu_InvalidMode_ISR_Callback != NULL_PTR )
            {
                Mcu_InvalidMode_ISR_Callback();
            }
    }
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    if (MCU_SIXTEEN_HEX_VALUE == (REG_READ32(MC_ME_IMTS_R) & MCU_SIXTEEN_HEX_VALUE))
    {
        /* This bit is set if the new mode is request while MTRANS=1 */
        /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
        REG_WRITE32(MC_ME_IMTS_R, (uint32) MCU_SIXTEEN_HEX_VALUE); 
            if( Mcu_InvalidMode_ISR_Callback != NULL_PTR )
            {
                Mcu_InvalidMode_ISR_Callback();
            }
    }
    }
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if ((MCU_SAFE_MODE_ISR_USED == STD_ON) || defined(__DOXYGEN__))
/*================================================================================================*/
/**
* @brief          This function represents the ISR for entering safe mode.
* @details        When entering safe mode, if enabled, an interrupt is triggered.
*
* @isr
*
* @implements     DMCU04085
*/
ISR(Mcu_EnterSafeMode_ISR)
{
    /* check for spurious ISR's */
    VAR(uint32, AUTOMATIC) MeIsrMask ;
    VAR(uint32, AUTOMATIC) MeIsrFlag ;
 /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrMask = (uint32)REG_READ32(MC_ME_IM_R);
    MeIsrMask &= (uint32)((uint32)0x01U << (uint32)MCU_ONE_VALUE);
 /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    MeIsrFlag = (uint32)REG_READ32(MC_ME_IS_R);
    MeIsrFlag &= (uint32)((uint32)0x01U << (uint32)MCU_ONE_VALUE);

    if( ((uint32)0x00U != (uint32)MeIsrFlag) && ((uint32)0x00U !=(uint32) MeIsrMask) )
    {
/* @errata ERR_IPV_MC_0009 */
#ifdef ERR_IPV_MC_0009
    #if (ERR_IPV_MC_0009 == STD_ON)
        /*Errata e3060: SAFE mode exit may be possible even though
        condition causing the SAFE mode request has not been cleared.
        Workaround: the FES register is cleared before clearing Interrupt Status register.*/
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_RGM_FES_REG_MASK); 
        /*lint -restore */
    #endif
#endif
    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    REG_WRITE32(MC_ME_IS_R, (uint32) MCU_TWO_VALUE);
    if( Mcu_EnterSafeMode_ISR_Callback != NULL_PTR )
        {
            Mcu_EnterSafeMode_ISR_Callback();
        }
    }
     /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

/*================================================================================================*/
/**
* @brief          This function represents the ISR for RGM Alternate mode .
* @details        When enabled in RGM FEAR/DEAR  for alternate mode an interrupt requests to the system.
*
* @isr
*
* @implements     
*
*/
#if ((MCU_RGM_ALTERNATEMODE_ISR_USED == STD_ON) || defined(__DOXYGEN__))
ISR(RGM_AlternateMode_ISR)
{    

   /* check for spurious ISR's */
    VAR(uint16, AUTOMATIC) RgmFerdMask;
    VAR(uint16, AUTOMATIC) RgmFearMask;

    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    RgmFerdMask = (uint16)REG_READ16(MC_RGM_FERD_R);
    RgmFerdMask = (uint16)(RgmFerdMask & ((uint16)(( (uint16)MCU_FLASH_RESET_VALUE) | \
                  ( (uint16)MCU_LVD45_RESET_VALUE) | ( (uint16)MCU_CMU0_FHL_RESET_VALUE) | \
                  ( (uint16)MCU_CMU0_OLR_RESET_VALUE) | ( (uint16)MCU_PLL_RESET_VALUE) | \
                  ( (uint16)MCU_CORE_RESET_VALUE) | ( (uint16)MCU_JTAG_RESET_VALUE) )));

    /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
    RgmFearMask = (uint16)REG_READ16(MC_RGM_FEAR_R);
    RgmFearMask &= (uint16)( ( (uint16)MCU_FLASH_RESET_VALUE) | \
                   ( (uint16)MCU_LVD45_RESET_VALUE) | ( (uint16)MCU_CMU0_FHL_RESET_VALUE) | ( (uint16)MCU_CMU0_OLR_RESET_VALUE) | \
                   ( (uint16)MCU_PLL_RESET_VALUE) | ( (uint16)MCU_CORE_RESET_VALUE) | ( (uint16)MCU_JTAG_RESET_VALUE)) ;


     if( ((uint16)0x00U != (uint16)RgmFerdMask) && ((uint16)0x00U !=(uint16) RgmFearMask) )

     {

       /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
       if (MCU_JTAG_RESET_VALUE == (REG_READ16(MC_RGM_FES_R) & MCU_JTAG_RESET_VALUE) )
        {
            /* This bit is set if there is CWD interrupt */
           /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
            REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_JTAG_RESET_VALUE);
            if( Mcu_AlternateMode_ISR_Callback != NULL_PTR )
            {
                Mcu_AlternateMode_ISR_Callback();
            }
        }
        
         /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
       if (MCU_CORE_RESET_VALUE == (REG_READ16(MC_RGM_FES_R) & MCU_CORE_RESET_VALUE) )
        {
            /* This bit is set if there is CWD interrupt */
            /* @violates @ref Mcu_irq_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned int to pointer */
            REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_CORE_RESET_VALUE);
            if( Mcu_AlternateMode_ISR_Callback != NULL_PTR )
            {
                Mcu_AlternateMode_ISR_Callback();
            }
        }

        /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
      if (MCU_PLL_RESET_VALUE == (REG_READ16(MC_RGM_FES_R) & MCU_PLL_RESET_VALUE) )
      {
        Mcu_Report_ClkFail();
      }
      
      /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
     if (MCU_CMU0_OLR_RESET_VALUE == (REG_READ16(MC_RGM_FES_R) & MCU_CMU0_OLR_RESET_VALUE) )
      {
        Mcu_Report_ClkFail();
      }
      
     /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
     if (MCU_CMU0_FHL_RESET_VALUE == (REG_READ16(MC_RGM_FES_R) & MCU_CMU0_FHL_RESET_VALUE) )
      {
        Mcu_Report_ClkFail(); 
      }
     
     /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
     if (MCU_LVD45_RESET_VALUE == (REG_READ16(MC_RGM_FES_R) & MCU_LVD45_RESET_VALUE) )
      {
        /* This bit is set if there is PLL1 interrupt */
        /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
        REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_LVD45_RESET_VALUE);  
        if( Mcu_AlternateMode_ISR_Callback != NULL_PTR )
        {
            Mcu_AlternateMode_ISR_Callback();
        }
      }
      
       /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
     if (MCU_FLASH_RESET_VALUE == (REG_READ16(MC_RGM_FES_R) & MCU_FLASH_RESET_VALUE) )
      {
        /* This bit is set if there is PLL1 interrupt */
        /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
        REG_WRITE16(MC_RGM_FES_R, (uint16) MCU_FLASH_RESET_VALUE);  
        if( Mcu_AlternateMode_ISR_Callback != NULL_PTR )
        {
            Mcu_AlternateMode_ISR_Callback();
        }
      }
     
    /* @violates @ref Mcu_irq_c_REF_3 Advisory Rule 11.1: cast from unsigned int to pointer  */
    EXIT_INTERRUPT();
  }
}
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_irq_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_irq_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
