/**
*   @file    Icu_eMIOS_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
*
*   (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
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
* @section Icu_eMIOS_LLD_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
*
* @section Icu_eMIOS_LLD_c_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_eMIOS_LLD_c_5
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer
*
* @section Icu_eMIOS_LLD_c_6
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form 
* of pointer arithmetic.
*The violation occurs because the variables are defined as per Autosar API specifications.
*
*@section Icu_eMIOS_LLD_c_7
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Icu_eMIOS_LLD_c_8
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not
* be permitted.
*
* @section Icu_eMIOS_LLD_c_9
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*/


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @implements DICU03701 */
/*
* @violates @ref Icu_eMIOS_LLD_c_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_eMIOS_LLD.h"
#include "Reg_eSys_eMIOS.h"
#include "Reg_eSys_eMIOS_CfgEx.h"
/*
* @violates @ref Icu_eMIOS_LLD_c_3 precautions to prevent the contents of a header file being
*             included twice 
*/
#include "Reg_Macros.h"
#include "SchM_Icu.h"
#include "Icu_LLD.h"



/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/* @implements     DICU03601, DICU03602, DICU03603, DICU03604, DICU03605, DICU03606, DICU03607 */
#define ICU_EMIOS_LLD_VENDOR_ID_C                       43

/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION        4
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION        0
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION     3
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_C_SW_MAJOR_VERSION                1
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_C_SW_MINOR_VERSION                0
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
#define ICU_EMIOS_LLD_C_SW_PATCH_VERSION                1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_EMIOS_LLD_VENDOR_ID_C != ICU_EMIOS_LLD_H_VENDOR_ID)
    #error "Icu_eMIOS_LLD.c and Icu_eMIOS_LLD.h have different vendor IDs"
#endif


/* Check if source file and Icu_eMIOS_LLD header file are of the same Autosar version */
#if ((ICU_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
       (ICU_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
       (ICU_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != ICU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMIOS_LLD.c and Icu_eMIOS_LLD.h are different"
#endif


/* Check if source file and Icu_eMIOS_LLD header file are of the same Software version */
#if ((ICU_EMIOS_LLD_C_SW_MAJOR_VERSION != ICU_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
        (ICU_EMIOS_LLD_C_SW_MINOR_VERSION != ICU_EMIOS_LLD_H_SW_MINOR_VERSION) || \
        (ICU_EMIOS_LLD_C_SW_PATCH_VERSION != ICU_EMIOS_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_eMIOS_LLD.c and Icu_eMIOS_LLD.h are different"
#endif


/* Check if Icu_eMIOS_LLD.c and Reg_eSys_EMIOS_CfgEx.h file are of the same vendor */
#if (ICU_EMIOS_LLD_VENDOR_ID_C != REG_ESYS_EMIOS_CFGEX_H_VENDOR_ID)
    #error "Icu_eMIOS_LLD.c and Reg_eSys_EMIOS_CfgEx.h have different vendor IDs"
#endif

/* Check if Icu_eMIOS_LLD.c and Reg_eSys_EMIOS_CfgEx.h file are of the same Autosar version */
#if ((ICU_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION !=  \
                                             REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION !=  \
                                             REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_MINOR_VERSION) || \
        (ICU_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION !=  \
                                             REG_ESYS_EMIOS_CFGEX_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMIOS_LLD.c and Reg_eSys_EMIOS_CfgEx.h are different"
#endif

/* Check if Icu_eMIOS_LLD.c and Reg_eSys_EMIOS_CfgEx.h file are of the same Software version */
#if ((ICU_EMIOS_LLD_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MAJOR_VERSION) || \
        (ICU_EMIOS_LLD_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_MINOR_VERSION) || \
        (ICU_EMIOS_LLD_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_CFGEX_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_eMIOS_LLD.c and Reg_eSys_EMIOS_CfgEx.h are different"
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static FUNC (void, ICU_CODE) Icu_eMIOS_LLD_EnableInterrupt(
                                                            CONST(uint8, AUTOMATIC) mIdx,
                                                            CONST(uint8, AUTOMATIC) chIdx);
                                                            
static FUNC (void, ICU_CODE) Icu_eMIOS_LLD_UCSetMode(
                                                    CONST(uint8, AUTOMATIC) mIdx,
                                                    CONST(uint8, AUTOMATIC) chIdx,
                                                    CONST(uint32, AUTOMATIC) mode);
                                                    
static FUNC (void, ICU_CODE) Icu_eMIOS_LLD_DisableInterrupt(
                                                            CONST(uint8, AUTOMATIC) mIdx,
                                                            CONST(uint8, AUTOMATIC) chIdx);                                                    

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_eMIOS_LLD_c_3 Only preprocessor statements and comments before "#include" 
*/
/*
* @violates @ref Icu_eMIOS_LLD_c_1 only preprocessor statements and comments before "#include" 
*/
#include "MemMap.h"



/*================================================================================================*/
/**
* @brief      Icu driver function that enables the eMIOS channel interrupt
* @details    This function Clears the pending interrupts of eMIOS channels and
*             enables eMIOS Channel interrupt
*
* @param[in]  mIdx  - eMIOS module index
* @param[in]  chIdx - eMIOS Channel index
* @api
* @implements   DICU03609
*/
static FUNC (void, ICU_CODE) Icu_eMIOS_LLD_EnableInterrupt(
                                                            CONST(uint8, AUTOMATIC) mIdx,
                                                            CONST(uint8, AUTOMATIC) chIdx)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13();
    {
        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        /* Clear pending flag */
        REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_MASK);

        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        /* Enable interrupt */
        REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13();
}


/*================================================================================================*/
/**
* @brief      Icu driver function that disables the eMIOS channel interrupt
* @details    This function disables eMIOS Channel interrupt
*
* @param[in]  mIdx -  eMIOS module index
* @param[in]  chIdx - eMIOS Channel index
* @api
* @implements   DICU03608
*/
static FUNC (void, ICU_CODE) Icu_eMIOS_LLD_DisableInterrupt(
                                                            CONST(uint8, AUTOMATIC) mIdx,
                                                            CONST(uint8, AUTOMATIC) chIdx)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14();
    {
        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        /* Disable interrupt */
        REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14();
}


/*================================================================================================*/
/**
* @brief      Icu driver function that sets the requested mode for eMIOS Channels.
* @details    This function sets CCR_MODE bitfield, the mode of operation of the Unified Channel
*
* @param[in]  mIdx  - eMIOS module index
* @param[in]  chIdx - eMIOS Channel index
* @param[in]  mode  - CCR_MODE bitfield value to be set
* @api
* @implements   DICU03610
*/
static FUNC (void, ICU_CODE) Icu_eMIOS_LLD_UCSetMode(
                                                    CONST(uint8, AUTOMATIC) mIdx,
                                                    CONST(uint8, AUTOMATIC) chIdx,
                                                    CONST(uint32, AUTOMATIC) mode)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    {
        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        /* Clear MODE bitfield - GPIO mode */
        REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), CCR_MODE_MASK);

        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        /* Set desired mode */
        REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), mode & CCR_MODE_MASK);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*================================================================================================*/
/**
* @brief      Icu driver initialization function for eMIOS module.
* @details    This function is called separately for each EMIOS hw channel corresponding to
*             the configured Icu channels, and:
*             - Disables the interrupt corresponding to eMIOS channel
*             - Initializes prescaler value, channel filter, freeze enable, and bus select fields
*             - Defines on which edge the period starts
*             - Clears the (pending) interrupt flag corresponding to eMIOS channel
*             - Resets the UC A register.
*             - Enables the SAIC mode for eMIOS channels.
* @param[in]  ParamValue  - contains the parameters to initialize the hardware channel
* @param[in]  channelMode - Chanel mode
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @api
* @implements   DICU03040
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_InitChannel(CONST(uint32, AUTOMATIC) ParamValue,
                                                CONST(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

   /*@violates @ref Icu_eMIOS_LLD_c_8 MISRA 2004 Required Rule,Invariant results for Boolean
         * Ops */     
    VAR(uint32, AUTOMATIC) regCCR = CCR_UCPREN_MASK | (CCR_FCK_PRESCALED << CCR_FCK_SHIFT);

#ifdef EMIOS_UCDIS_AVAILABLE
#if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Enable eMIOS Channel */
    REG_BIT_CLEAR32(EMIOS_UCDIS(mIdx), (uint32)(BIT0 << chIdx));
#endif  /* EMIOS_UCDIS_AVAILABLE */
#endif
    /* Enter GPIO Mode to Configure Channel */
    /* Reset mode for selected channel */

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_WRITE32(EMIOS_CCR(mIdx, chIdx), (uint32)0x00000000U);


    /* Initialize prescaler value, channel filter, freeze enable, and bus select and disable the
     *  prescaler The definition on which edge the period starts
     * Set Default Edge (included)
     */
    regCCR |= ((ParamValue & ICU_EMIOS_FREEZE_PARAM_MASK) >> ICU_EMIOS_FREEZE_PARAM_SHIFT) <<
            CCR_FREN_SHIFT;
    regCCR |= ((ParamValue & ICU_EMIOS_PRESCALER_PARAM_MASK) >> ICU_EMIOS_PRESCALER_PARAM_SHIFT) <<
            CCR_UCPRE_SHIFT;
    regCCR |= ((ParamValue & ICU_EMIOS_DIG_FILTER_PARAM_MASK) >> ICU_EMIOS_DIG_FILTER_PARAM_SHIFT)
            << CCR_IF_SHIFT;
    regCCR |= ((ParamValue & ICU_EMIOS_BUS_SELECT_PARAM_MASK) >> ICU_EMIOS_BUS_SELECT_PARAM_SHIFT)
            << CCR_BSL_SHIFT;
    
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_WRITE32(EMIOS_CCR(mIdx, chIdx), regCCR);

    /* Disable interrupt */
    Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupt flag (and other flags) for the channel */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), (uint32)(CSR_OVR_MASK | CSR_OVFL_MASK | CSR_FLAG_MASK));

    Icu_eMIOS_LLD_SetActivationCondition(hwChannel,
           (eMIOS_ActivationType)((ParamValue & ICU_EDGE_PARAM_MASK) >> ICU_EDGE_PARAM_SHIFT));


}


/*================================================================================================*/
/**
* @brief      Icu driver de-initialization function for eMIOS module.
* @details    This function is called separately for each EMIOS hw channel corresponding to the
*             configured Icu channels, and:
*             - Resets the eMIOS channel control register
*             - Resets the UC A register.
*             - Clears the (pending) interrupt flag corresponding to eMIOS channel
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @param[in]  reg_EMIOSCNT_available  - indicates the availability of register EMIOS UC Counter
*             - true - is available
*             - false - is not available
* @param[in]  reg_EMIOSB_available  - indicates the availability of register EMIOS UC B register
*             - true - is available
*             - false - is not available
*
* @api
* @implements   DICU03029
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_DeInitChannel(
                                                CONST(uint8, AUTOMATIC) hwChannel,
                                                VAR(boolean,AUTOMATIC) reg_EMIOSCNT_available,
                                                VAR(boolean,AUTOMATIC) reg_EMIOSB_available)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Set all channel registers as after reset */
    REG_WRITE32(EMIOS_CCR(mIdx, chIdx), EMIOS_CCR_CLEAR);
    
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_WRITE32(EMIOS_CADR(mIdx, chIdx), EMIOS_CADR_CLEAR);

    if ((boolean)TRUE == reg_EMIOSB_available)
    {
        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        REG_WRITE32(EMIOS_CBDR(mIdx, chIdx), EMIOS_CBDR_CLEAR);
    }

    if ((boolean)TRUE == reg_EMIOSCNT_available)
    {
        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        REG_WRITE32(EMIOS_CCNTR(mIdx, chIdx), EMIOS_CCNTR_CLEAR);
    }

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), EMIOS_CSR_CLEAR);

#ifdef EMIOS_UCDIS_AVAILABLE
#if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /* Disable eMIOS Channel */
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_BIT_SET32(EMIOS_UCDIS(mIdx), (uint32)(BIT0 << chIdx));
#endif
#endif  /* EMIOS_UCDIS_AVAILABLE */
}


/*================================================================================================*/
#if (ICU_SET_MODE_API == STD_ON)
/**
* @brief      Icu driver function that puts eMIOS timer channel in SLEEP mode.
* @details    This function is called separately for each EMIOS hw channel corresponding to the
*             configured Icu channels, and:
*             - Enables the interrupt for the eMIOS channel,
*                 if the wake up functionality is enabled
*             - Disables the interrupt for the eMIOS channel,
*                 if the wake up functionality is disabled
* @param[in]  hwChannel     - eMIOS encoded hardware channel
* @param[in]  WakeUpEnabled - specifies if channel is wake-up enabled
* @api
* @implements   DICU03046
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SetSleepMode(
                                            VAR(uint8, AUTOMATIC) hwChannel,
                                            VAR(boolean, AUTOMATIC) WakeUpEnabled,
                                            CONST(Icu_MeasurementModeType, AUTOMATIC) channelMode)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* value_CCR_FEN will indicate whether the interrupt is enabled or not*/
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    CONST(uint32, AUTOMATIC) value_CCR_FEN  = REG_BIT_GET32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
    VAR(uint32, AUTOMATIC) val_EMIOS_CNTR;
    if (WakeUpEnabled)
    {
    
             if (channelMode == ICU_MODE_EDGE_COUNTER)
          {
             SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_21();          
            /* @violates @ref Icu_eMIOS_LLD_c_5 cast from unsigned long to pointer */
             val_EMIOS_CNTR = REG_READ32(EMIOS_CCNTR(mIdx, chIdx));
            /* @violates @ref Icu_eMIOS_LLD_c_5 cast from unsigned long to pointer */
             Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);
            /* Set current counter value + 1 */
            /* @violates @ref Icu_eMIOS_LLD_c_5 cast from unsigned long to pointer */            
             REG_WRITE32(EMIOS_CADR(mIdx, chIdx), (val_EMIOS_CNTR+2U));
             Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_MCB_EXT_CLOCK);

            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_21(); 
          }

        /* if interrupt is not enabled*/
      if(value_CCR_FEN == 0U)
      {
        Icu_eMIOS_LLD_EnableInterrupt(mIdx, chIdx);
      }

      else
      {
          /*For Misra Compliance*/
      }

    }
    else
    {
        Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);
    }
}


/*================================================================================================*/
/**
* @brief      Icu driver function that puts the eMIOS timer channel in NORMAL mode.
* @details    This function:
*             - Enables the interrupt for the eMIOS channel, if the Notification is active
*             - Disables the interrupt for the eMIOS channel, if the Notification is not enabled
*               for the channel
* @param[in]  hwChannel          - eMIOS encoded hardware channel
* @param[in]  NotificationActive - specifies if channel has notification activated
* @api
* @implements   DICU03045
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SetNormalMode(
                                            VAR(uint8, AUTOMATIC) hwChannel,
                                            VAR(boolean, AUTOMATIC) NotificationActive,
                                            CONST(Icu_MeasurementModeType, AUTOMATIC) channelMode)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* value_CCR_FEN will indicate whether the interrupt is enabled or not*/
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    CONST(uint32, AUTOMATIC) value_CCR_FEN  = REG_BIT_GET32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);

    if (NotificationActive)
    {
        if(channelMode == ICU_MODE_EDGE_COUNTER)
        {
         SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_21(); 
        /* @violates @ref Icu_eMIOS_LLD_c_5 cast from unsigned long to pointer */
        /* Set Max. A value */
         Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);
        /* @violates @ref Icu_eMIOS_LLD_c_5 cast from unsigned long to pointer */
        /* Max. value for register A. If reached, overflow interrupt */         
         REG_WRITE32(EMIOS_CADR(mIdx, chIdx), EMIOS_INIT_CADR);
         /* @violates @ref Icu_eMIOS_LLD_c_5 cast from unsigned long to pointer */
        /* Clear pending interrupts */         
         REG_WRITE32(EMIOS_CCNTR(mIdx, chIdx), EMIOS_INIT_CCNTR);
         Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_MCB_EXT_CLOCK);    
         SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_21(); 

        }

        /* if interrupt is not enabled*/
       if(value_CCR_FEN == 0U)
       {
        Icu_eMIOS_LLD_EnableInterrupt(mIdx, chIdx);
       }

       else
       {
           /*For Misra Compliance*/
       }
    }
    else
    {
        Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);
    }
}
#endif  /* ICU_SET_MODE_API */


/*================================================================================================*/
/**
* @brief      Icu driver function that sets activation condition of eMIOS channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges) for corresponding eMIOS channels.
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @param[in]  activation  - edge activation type
* @api
* @implements   DICU03044
*/
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SetActivationCondition(
                                                VAR(uint8, AUTOMATIC) hwChannel,
                                                VAR(eMIOS_ActivationType, AUTOMATIC) activation)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    VAR(uint32, AUTOMATIC) reg_EMIOS_CCR;
#endif  /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
    switch (activation)
    {
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
        case EMIOS_OPPOSITE_EDGES:
            /*
            * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
            */
            reg_EMIOS_CCR = REG_READ32(EMIOS_CCR(mIdx, chIdx));
            /*
            * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
            */
            REG_WRITE32(EMIOS_CCR(mIdx, chIdx),(reg_EMIOS_CCR ^ CCR_EDPOL_MASK));
            break;
#endif  /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */

        case EMIOS_BOTH_EDGES:
            /*
            * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
            */
            REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_EDSEL_MASK);
            break;

        case EMIOS_RISING_EDGE:
            /*
            * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
            */
            REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), CCR_EDSEL_MASK);
            /*
            * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
            */
            REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_EDPOL_MASK);
            break;

        default:
            /* EMIOS_FALLING_EDGE */
            /*
            * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
            */
            REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), (CCR_EDSEL_MASK | CCR_EDPOL_MASK));
            break;
    }
}
/*================================================================================================*/
#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu driver function that gets the input state of eMIOS channel.
* @details    This function:
*            - Checks if interrupt flags for corresponding eMIOS channel is set then
*            it clears the interrupt flag and returns the value as true.
*
* @param[in]  hwChannel - eMIOS encoded hardware channel
*
* @return       boolean
* @retval       true - if channel is active
* @retval       false - if channel is idle
*
* @api
* @implements   DICU03038
*/

FUNC (boolean, ICU_CODE) Icu_eMIOS_LLD_GetInputState(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, IAUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    VAR(boolean, AUTOMATIC) result = (boolean)FALSE;
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    CONST(uint32, AUTOMATIC) value_CCR_FEN  = REG_BIT_GET32(EMIOS_CCR(mIdx, chIdx), CCR_FEN_MASK);
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    CONST(uint32, AUTOMATIC) value_CSR_FLAG = REG_BIT_GET32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_MASK);

    /* Interrupt not enabled, flag bit was set */
    if ( (value_CCR_FEN != CCR_FEN_MASK) &&
         (value_CSR_FLAG == CSR_FLAG_MASK) )
   {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16();
        {
            /*
            * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
            */
            /* Clear pending interrupt */
            REG_WRITE32(EMIOS_CSR(mIdx, chIdx), CSR_FLAG_MASK);
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16();


        result = (boolean)TRUE;
    }

    return result;
}
#endif  /* ICU_GET_INPUT_STATE_API */


/*================================================================================================*/
#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu driver function that starts time stamp measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Clears the pending interrupts
*             - Enables SAIC mode for the channel
*             - Enbales the interrupt for the channel
*
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @api
* @implements   DICU03048
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StartTimestamp(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
#if (ICU_DMA_SUPPORTED == STD_ON)
    CONST(boolean, AUTOMATIC)dma_enable = Icu_Cfg_Ptr->  \
                                  Icu_ChannelConfigPtr[Icu_Cfg_Ptr-> \
/* @violates @ref Icu_eMIOS_LLD_c_6 Use of pointer arithematic*/                                                          
                                        Icu_HWMap[eMIOS_ICU_CHANNEL(hwChannel)]].Icu_DMA_Enable;
#endif

    /* Make sure channel is in GPIO mode before switching modes */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupts */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), (uint32)(CSR_OVR_MASK | CSR_OVFL_MASK | CSR_FLAG_MASK));

    /* Enable SAIC mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_SAIC);

    #if(ICU_DMA_SUPPORTED == STD_ON)
     if(dma_enable == (boolean)TRUE)
     {
        /* @violates @ref Icu_eMIOS_LLD_c_5 cast from unsigned long to pointer */        
     REG_RMW32(EMIOS_CCR(mIdx, chIdx),(CCR_DMA_MASK),(CCR_DMA_MASK));
     }
    #endif
    /* Enable Interrupt */
    Icu_eMIOS_LLD_EnableInterrupt(mIdx, chIdx);
}
#endif  /* ICU_TIMESTAMP_API */


/*================================================================================================*/
#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu driver function that stops time stamp measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Disables the interrupt for the channel
*
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @api
* @implements   DICU03050
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StopTimestamp(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* Stop timestamping */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

    /* Disable interrupt */
    Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);
}


/*================================================================================================*/
/**
* @brief      Icu driver function that returns the time stamp index of eMIOS channel.
* @details    Returns the captured value in register A
*
* @param[in]  hwChannel - eMIOS encoded hardware channel
*
* @return     uint32 - The captured value in register A
* @api
* @implements   DICU03039
*/

FUNC(uint32, ICU_CODE) Icu_eMIOS_LLD_GetTimeStamp(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    return REG_READ32(EMIOS_CADR(mIdx, chIdx));
}
#endif  /* ICU_TIMESTAMP_API */


/*================================================================================================*/
#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that resets the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Puts the eMIOS channel into GPIO mode
*             - Resets the counter to initial value
*             - Loads the initial value to the RegisterA
*             - Clears the pending interrupts
*             - Restores the previous mode
*
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @api
* @implements   DICU03042
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_ResetEdgeCount(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    VAR(uint32, AUTOMATIC) prevMode;
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    prevMode = REG_BIT_GET32(EMIOS_CCR(mIdx, chIdx), CCR_MODE_MASK);

        /* Disable timer interrupts */
    Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);
    /* Enter GPIO Mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Reset counter */
    REG_WRITE32(EMIOS_CCNTR(mIdx, chIdx), EMIOS_INIT_CCNTR);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Max. value for register A. If reached, overflow interrupt */
    REG_WRITE32(EMIOS_CADR(mIdx, chIdx), EMIOS_INIT_CADR);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupts */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), (uint32)(CSR_OVR_MASK | CSR_OVFL_MASK | CSR_FLAG_MASK));

    /* Restore previous mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, prevMode);
    /* Enable timer interrupts */
    Icu_eMIOS_LLD_EnableInterrupt(mIdx, chIdx);
}
#endif  /* ICU_EDGE_COUNT_API */


/*================================================================================================*/
#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that enables the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Puts the eMIOS channel into GPIO mode
*             - Counter register is loaded with startValue
*             - Loads initial value to RegisterA
*             - Clears the pending interrupts
*             - Sets the mode to Modulus counter mode
*             - Enables the interrupt for eMIOS channel
*
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @param[in]  startValue  - starting value
* @implements   DICU03032
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_EnableEdgeCount(
                                                    VAR(uint8, AUTOMATIC) hwChannel,
                                                    VAR(uint32, AUTOMATIC) startValue)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* Make sure channel is in GPIO mode before switching modes */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

    /* Sync. eMIOS counter value. (Needed in case of stopping and re-enabling counting)
     * Note: Setting GPIO mode, the internal counter was cleared and must be restored
     */
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_WRITE32(EMIOS_CCNTR(mIdx, chIdx), startValue);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Set Max. A value */
    REG_WRITE32(EMIOS_CADR(mIdx, chIdx), EMIOS_INIT_CADR);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupts */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), (uint32)(CSR_OVR_MASK | CSR_OVFL_MASK | CSR_FLAG_MASK));

    /* Modulus counter mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_MCB_EXT_CLOCK);

    /* Enable interrupt */
    Icu_eMIOS_LLD_EnableInterrupt(mIdx, chIdx);
}
#endif  /* ICU_EDGE_COUNT_API */


/*================================================================================================*/
#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that disables the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Disables the eMIOS channel interrupt
*             - Clears the pending interrupts
*             - Save the current counter value before entering into GPIO mode
*             - Puts the channel into GPIO mode
*             - Disables MCB mode for the channel
*
* @param[in]  hwChannel    - eMIOS encoded hardware channel
* @param[out] currentValue - the current value of the channel's counter
*
* @api
* @implements DICU03030
*/

FUNC (void, ICU_CODE) Icu_eMIOS_LLD_DisableEdgeCount(
                                           VAR(uint8, AUTOMATIC) hwChannel,
                                           P2VAR(uint32, AUTOMATIC, ICU_APPL_DATA) currentValue)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* Disable interrupt */
    Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupts */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), (uint32)(CSR_OVR_MASK | CSR_OVFL_MASK | CSR_FLAG_MASK));
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Save count, before going to GPIO mode (because counter is reset to 0x0000) */
    *currentValue = REG_READ32(EMIOS_CCNTR(mIdx, chIdx));

    /* Disable MCB mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);
}
#endif  /* ICU_EDGE_COUNT_API */


/*================================================================================================*/
#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that gets edge counter measurement of eMIOS channel.
* @details    This function returns counter value (the number of counter edges) of eMIOS channel
*
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @return     uint32 - Counted edges number
*
* @api
* @implements   DICU03036
*/
/*================================================================================================*/
FUNC (uint32, ICU_CODE) Icu_eMIOS_LLD_GetEdgeNumbers(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    return REG_READ32(EMIOS_CCNTR(mIdx, chIdx));
}
#endif  /* ICU_EDGE_COUNT_API */


/*================================================================================================*/
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu driver function that starts the signal measurement of eMIOS channel.
* @details    This function:
*             - Disables the interrupt of eMIOS channel
*             - Puts the eMIOS channel into GPIO mode
*             - Sets activation condition (Rising, Falling or Both edges)
*             - Puts the eMIOS channel into requested mode (IPWM, IPM or SAIC)
*             - Clears pending interrupts
*             - Enables the interrupt for eMIOS channel
*
* @param[in]  hwChannel  - eMIOS encoded hardware channel
* @param[in]  activation - edge activation type
* @param[in]  mode       - Unified Chanel mode of operation
*
* @api
* @implements   DICU03047
*/
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StartSignalMeasurement(
                                                VAR(uint8, AUTOMATIC) hwChannel,
                                                VAR(eMIOS_ActivationType, AUTOMATIC) activation,
                                                VAR(eMIOS_OperationMode, AUTOMATIC) mode)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
   /*
         * @violates @ref Icu_eMIOS_LLD_c_6  Array indexing shall be the only allowed form of
         *                 pointer arithmetic.
         */      
    VAR(uint8, AUTOMATIC) tempChannel = Icu_Cfg_Ptr->Icu_HWMap[eMIOS_ICU_CHANNEL(hwChannel)];    

    /* Disable interrupt */
    Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);

    /* Enter GPIO Mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

    /* Set activation condition */
    Icu_eMIOS_LLD_SetActivationCondition(hwChannel, activation);

    if (EMIOS_UC_IPWM_MODE == mode)
    {
        /* Enable IPWM mode */
        Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_IPWM);

    }
    else if (EMIOS_UC_IPM_MODE == mode)
    {
        /* Enable IPM mode */
        Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_IPM);

    }
    else
    {
        /* Enable SAIC mode */
        Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_SAIC);
    }

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupt flag (and other flags) for the channel */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), (uint32)(CSR_OVR_MASK | CSR_OVFL_MASK | CSR_FLAG_MASK));

    /* Check whether measurement has to be done without interrupt or with interrupt */
   /*
         * @violates @ref Icu_eMIOS_LLD_c_6  Array indexing shall be the only allowed form of
         *                 pointer arithmetic.
         */    
    if (Icu_Cfg_Ptr->Icu_ChannelConfigPtr[tempChannel].IcuSignalMeasureWithoutInterrupt !=  \
                                                                                 (boolean)TRUE)
    {
            Icu_eMIOS_LLD_EnableInterrupt(mIdx, chIdx);
    }
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */


/*================================================================================================*/
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu driver function that stops the signal measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Disables the interrupt for requsted eMIOS channel
*             - Clears pending interrupts
*
* @param[in]  hwChannel  - eMIOS encoded hardware channel
*
* @api
* @implements   DICU03049
*/
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_StopSignalMeasurement(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* Enter GPIO Mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* EDSEL is set to 1 to discard the input in GPIO mode (not to repond the input signal
       in GPIO mode)*/
    /* Disables the flag generation as defined by EDPOL Bit */
    REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_EDSEL_MASK);


    /* Disable interrupt */
    Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupt flag (and other flags) for the channel */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), (uint32)(CSR_OVR_MASK | CSR_OVFL_MASK | CSR_FLAG_MASK));
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */


/*================================================================================================*/
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_CAPTURERGISTER_API == STD_ON)
/**
* @brief      Icu driver function that gets the RegisterA value of eMIOS channel
* @details    This function returns the register A of the given eMIOS Unified Channel
* @param[in]  hwChannel  - eMIOS encoded hardware channel
* @return     uint32 - Captured value of the register A
*
* @api
* @implements   DICU03034
*/

FUNC(uint32, ICU_CODE) Icu_eMIOS_LLD_GetCaptureRegA(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    return REG_READ32(EMIOS_CADR(mIdx, chIdx));
}

/*================================================================================================*/
/**
* @brief      Icu driver function that gets the RegisterB value of eMIOS channel
* @details    This function returns the register B of the given eMIOS Unified Channel
* @param[in]  hwChannel  - eMIOS encoded hardware channel
* @return     uint32 - Captured value of the register B
*
* @api
* @implements   DICU03035
*/

FUNC(uint32, ICU_CODE) Icu_eMIOS_LLD_GetCaptureRegB(VAR(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    return REG_READ32(EMIOS_CBDR(mIdx, chIdx));
}

#endif  /* (ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_CAPTURERGISTER_API == STD_ON) */

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_eMios_LLD_EnableEdgeDetection
* @details    eMIOS IP function that starts the edge detection service for an eMIOS channel
*
* @param[in]      hwChannel   - eMIOS encoded hardware channel
*
* @return void
*
* @implements   DICU03033
*/
/*================================================================================================*/
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMios_LLD_EnableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel){

    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* Enter GPIO Mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

    /* Enable SAIC mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_SAIC);

    /* Enable Interrupt */
    Icu_eMIOS_LLD_EnableInterrupt(mIdx, chIdx);

}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_eMios_LLD_DisableEdgeDetection
* @details    eMIOS IP function that stops the edge detection service for an eMIOS channel
*
* @param[in]      hwChannel   - eMIOS encoded hardware channel
*
* @return void
* @implements   DICU03031
*/
/*================================================================================================*/
/*
* @violates @ref Icu_eMIOS_LLD_c_7 This is required as per autosar Requirement, 
*/
FUNC (void, ICU_CODE) Icu_eMios_LLD_DisableEdgeDetection(VAR(uint8, AUTOMATIC) hwChannel){

    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);

    /* Disable interrupt */
    Icu_eMIOS_LLD_DisableInterrupt(mIdx, chIdx);

    /* Enter GPIO Mode */
    Icu_eMIOS_LLD_UCSetMode(mIdx, chIdx, CCR_MODE_GPI);

}
#endif /* ICU_EDGE_DETECT_API */


/*================================================================================================*/
/**
* @brief      Icu driver function that checks the overflow flag
* @details    This function returns true if the overflow flag is set
*
* @param[in]  flags - the flags to be checked
*
* @return        boolean
* @retval       true -  if the parameter's value contains overflow flag
* @retval       false - if the parameter's value doesnot contains overflow flag
*
* @api
* @implements   DICU03028
*/

FUNC (boolean, ICU_CODE) Icu_eMIOS_LLD_CheckOverflowFlag(CONST(uint32, AUTOMATIC) flags)
{
    return ((CSR_OVFL_BIT == (flags & CSR_OVFL_BIT)) ? (boolean)TRUE : (boolean)FALSE);
}


/*================================================================================================*/
/**
* @brief      Icu driver function that handles the interrupt of eMIOS channel.
* @details    This function:
*              - Reads the status register
*              - Clears the pending interrupt
*              - Processes interrupt for corresponding eMIOS channel
*
* @param[in]  hwChannel - eMIOS hardware channel
*
* @api
* @implements   DICU03041
*/
/*
* @violates @ref Icu_eMIOS_LLD_c_9 external ... could be made static
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_ProcessInterrupt(CONST(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    VAR(uint32, AUTOMATIC) regCSR;
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Read UC Status Register */
    regCSR = REG_READ32(EMIOS_CSR(mIdx, chIdx));

    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    /* Clear pending interrupt serviced */
    REG_WRITE32(EMIOS_CSR(mIdx, chIdx), regCSR & (CSR_OVR_BIT | CSR_OVFL_BIT | CSR_FLAG_BIT));

    /* Process interrupt for ICU logical channel */
    /*
    * @violates @ref Icu_eMIOS_LLD_c_6 Array indexing shall be the only allowed form of pointer
    *             arithmetic. 
    */
    Icu_LLD_ProcessCommonInterrupt(Icu_Cfg_Ptr->Icu_HWMap[eMIOS_ICU_CHANNEL(hwChannel)], regCSR);
}


/*================================================================================================*/
#if (ICU_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief      Icu driver function that sets the channel prescaler.
* @details    This function:
*             - Clears GPREN bit in EMIOSMCR register and UCPREN bit in EMIOSC[n] register
*             - Writes prescaling rate at UCPRE[0:1] bits in EMIOSC[n] register
*             - Enables channel prescaler by setting UCPREN bit in EMIOSC[n] register
*             - Enables global prescaler by setting GPREN bit in EMIOSMCR register
*
* @param[in]  ParamValue     - contains the parameters to initialize the hardware channel
* @param[in]  hwChannel      - eMIOS encoded hardware channel
* @api
* @implements   DICU03043
*/
FUNC (void, ICU_CODE) Icu_eMIOS_LLD_SelectPrescaler(
                                                    CONST(uint32, AUTOMATIC) ParamValue,
                                                    CONST(uint8, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    VAR(uint32, AUTOMATIC) regMCR = REG_READ32(EMIOS_MCR(mIdx));
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    VAR(uint32, AUTOMATIC) regCCR = REG_READ32(EMIOS_CCR(mIdx, chIdx));

    /* Clear GPREN bit */
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_BIT_CLEAR32(EMIOS_MCR(mIdx), MCR_GPREN_MASK);

    /* Clear GPRE bit */
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), CCR_UCPREN_MASK );

    /* Write prescaling rate at UCPRE[0:1] bits in EMIOSC[n] */
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_BIT_CLEAR32(EMIOS_CCR(mIdx, chIdx), CCR_UCPRE_MASK );
    /*Clear bit UCPRE before set up new value*/
    regCCR &= EMIOS_UCPRE_CLEAR ;
    regCCR |= ParamValue;
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_WRITE32(EMIOS_CCR(mIdx, chIdx), regCCR);

    /* Enable channel prescaler */
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    REG_BIT_SET32(EMIOS_CCR(mIdx, chIdx), CCR_UCPREN_MASK);

    /* Enable global prescaler */
    if ((regMCR & MCR_GPREN_MASK) == MCR_GPREN_MASK)
    {
        /*
        * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
        */
        REG_BIT_SET32( EMIOS_MCR(mIdx), MCR_GPREN_MASK );
    }
}

#endif  /* ICU_DUAL_CLOCK_MODE */

/*================================================================================================*/
/**
* @brief      This function returns the actual status of PIN.

* @details    This function returns the actual status o PIN
*
* @param[in]     Channel          Numeric identifier of the ICU channel
*
* @return  void
*
* @api
* @implements   DICU03037
*/
/*================================================================================================*/
/*
* @violates @ref Icu_eMIOS_LLD_c_9 external ... could be made static
*/
FUNC (boolean, ICU_CODE) Icu_eMIOS_LLD_GetInputLevel(VAR(uint8, AUTOMATIC) hwChannel){

    VAR(boolean, AUTOMATIC) result = (boolean)FALSE;
    CONST(uint8, AUTOMATIC) mIdx  = (uint8)((hwChannel & EMIOS_MOD_MASK) >> EMIOS_MOD_SHIFT);
    CONST(uint8, AUTOMATIC) chIdx = (uint8)((hwChannel & EMIOS_CH_MASK)  >> EMIOS_CH_SHIFT);
    
    /*
    * @violates @ref Icu_eMIOS_LLD_c_5 Cast from unsigned long to pointer  
    */
    result = (boolean) ((REG_READ32(EMIOS_CSR(mIdx, chIdx)) & CSR_UCIN_MASK)>> CSR_UCIN_SHIFT);

    return result;

}

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_eMIOS_LLD_c_1 only preprocessor statements and comments before "#include" 
*/
/*
* @violates @ref Icu_eMIOS_LLD_c_3 precautions to prevent the contents of a header file being
*            included twice 
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
