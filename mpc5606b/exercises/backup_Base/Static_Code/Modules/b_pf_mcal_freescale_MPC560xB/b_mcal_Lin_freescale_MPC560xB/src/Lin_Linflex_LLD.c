/**
*   @file    Lin_Linflex_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - LINFlex.
*   @details File containing the low level driver of the LINFlex IP.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : LINFlex
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC560xB_MCAL_1_0_1_RTM_HF5_ASR_REL_4_0_REV_0003_20140822
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
* @section LINFlex_LLD_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section LINFlex_LLD_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a 
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section LINFlex_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section LINFlex_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, This violation is due to
* the structure of the types used.
*
* @section LINFlex_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section LINFlex_LLD_c_REF_6
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section LINFlex_LLD_c_REF_7
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal
* and external) shall not rely on the significance of more 
* than 31 characters.
*
* @section LINFlex_LLD_c_REF_8
* Violates MISRA 2004 Required Rule 14.10, All if ... else
*  if constructs shall be terminated with an else clause.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin.h"
#include "Lin_Linflex_LLD.h"
#include "Reg_Macros.h"
/**
* @violates @ref LINFlex_LLD_c_REF_1 Precautions shall be taken in 
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "Reg_eSys.h" /* Reg_eSys.h is included in Mcal.h also*/
#include "Reg_eSys_LINFlex.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Linflex_LLD.c
* @implements     DLIN04301
*/
#define LIN_VENDOR_ID_FLEX_C                    43
/*
* @violates @ref LINFlex_LLD_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C     4
/*
* @violates @ref LINFlex_LLD_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_MINOR_VERSION_FLEX_C     0
/*
* @violates @ref LINFlex_LLD_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
/* @violates @ref LINFlex_LLD_c_REF_7 This is required as per Autosar Requirement. */
#define LIN_AR_RELEASE_REVISION_VERSION_FLEX_C  3
#define LIN_SW_MAJOR_VERSION_FLEX_C             1
#define LIN_SW_MINOR_VERSION_FLEX_C             0
#define LIN_SW_PATCH_VERSION_FLEX_C             1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin_LLD header file are of the same vendor */
#if (LIN_VENDOR_ID_FLEX_C != LIN_VENDOR_ID_FLEX)
    #error "Lin_Linflex_LLD.c and Lin_Linflex_LLD.h have different vendor ids"
#endif

/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_FLEX_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin_Linflex_LLD.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_FLEX_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_FLEX_C != LIN_SW_MINOR_VERSION))
    #error "Software Version Numbers of Lin_Linflex_LLD.c and Lin.h are different"
#endif

/* Check if current file and Lin_Linflex_LLD.h header file are of the same Autosar version */
#if (((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MAJOR_VERSION_FLEX) || \
      (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MINOR_VERSION_FLEX)) || \
      (LIN_AR_RELEASE_REVISION_VERSION_FLEX_C != LIN_AR_RELEASE_REVISION_VERSION_FLEX))
    #error "AutoSar Version Numbers of Lin_Linflex_LLD.c and Lin_Linflex_LLD.h are different"
#endif
/* Check if current file and Lin_Linflex_LLD.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_FLEX_C != LIN_SW_MAJOR_VERSION_FLEX) || \
     (LIN_SW_MINOR_VERSION_FLEX_C != LIN_SW_MINOR_VERSION_FLEX))
    #error "Software Version Numbers of Lin_Linflex_LLD.c and Lin_Linflex_LLD.h are different"
#endif

/* Check if current file and Reg_eSys_LINFlex.h header file are of the same Autosar version */
#if (((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
      (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MINOR_VERSION_REGFLEX)) || \
      (LIN_AR_RELEASE_REVISION_VERSION_FLEX_C != LIN_AR_RELEASE_REVISION_VERSION_REGFLEX))
    #error "AutoSar Version Numbers of Lin_Linflex_LLD.c and Reg_eSys_LINFlex.h are different"
#endif
/* Check if current file and Reg_eSys_LINFlex.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_FLEX_C != LIN_SW_MAJOR_VERSION_REGFLEX) || \
     (LIN_SW_MINOR_VERSION_FLEX_C != LIN_SW_MINOR_VERSION_REGFLEX))
    #error "Software Version Numbers of Lin_Linflex_LLD.c and Reg_eSys_LINFlex.h are different"
#endif

#ifdef LIN_GLOBAL_WAKEUP_SUPPORT
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the current file and EcuM_Cbk header file are of the same Autosar version */
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C != ECUM_CBK_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lin_Linflex_LLD.c and EcuM_Cbk.h are different"
    #endif
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the current file and EcuM_Cfg header file are of the same Autosar version */
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C != ECUM_CFG_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C != ECUM_CFG_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lin_Linflex_LLD.c and EcuM_Cfg.h are different"
    #endif
#endif
#endif /* LIN_GLOBAL_WAKEUP_SUPPORT */
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
#define LIN_START_SEC_CONST_32
/** 
* @violates @ref LINFlex_LLD_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
*/
#include "MemMap.h"

/**
* @brief        LINFlex IPs base addresses.
*
* @details      Array containing the base address of all the LINFlex IPs.
*
* @implements   DLIN04302
*
* @violates @ref LINFlex_LLD_c_REF_5 All declarations and definitions
*                of objects or functions at file scope shall have
*                internal linkage unless external linkage is required.
*/
CONST(uint32, LIN_CONST) LIN_BASE_ADDRESS[] =
{
    #ifdef  LINFLEX0_BASEADDR
        LINFLEX0_BASEADDR,
    #endif /* LINFLEX0_BASEADDR */
    #ifdef  LINFLEX1_BASEADDR
        LINFLEX1_BASEADDR,
    #endif /* LINFLEX1_BASEADDR */
    #ifdef  LINFLEX2_BASEADDR
        LINFLEX2_BASEADDR,
    #endif /* LINFLEX2_BASEADDR */
    #ifdef  LINFLEX3_BASEADDR
        LINFLEX3_BASEADDR,
    #endif /* LINFLEX3_BASEADDR */
    #ifdef  LINFLEX4_BASEADDR
        LINFLEX4_BASEADDR,
    #endif /* LINFLEX4_BASEADDR */
    #ifdef  LINFLEX5_BASEADDR
        LINFLEX5_BASEADDR,
    #endif /* LINFLEX5_BASEADDR */
    #ifdef  LINFLEX6_BASEADDR
        LINFLEX6_BASEADDR,
    #endif /* LINFLEX6_BASEADDR */
    #ifdef  LINFLEX7_BASEADDR
        LINFLEX7_BASEADDR,
    #endif /* LINFLEX7_BASEADDR */
    #ifdef  LINFLEX8_BASEADDR
        LINFLEX8_BASEADDR,
    #endif /* LINFLEX8_BASEADDR */
    #ifdef  LINFLEX9_BASEADDR
        LINFLEX9_BASEADDR,
    #endif /* LINFLEX9_BASEADDR */
    #ifdef  LINFLEX10_BASEADDR
        LINFLEX10_BASEADDR,
    #endif /* LINFLEX10_BASEADDR */
    #ifdef  LINFLEX11_BASEADDR
        LINFLEX11_BASEADDR,
    #endif /* LINFLEX11_BASEADDR */
    #ifdef  LINFLEX12_BASEADDR
        LINFLEX12_BASEADDR,
    #endif /* LINFLEX12_BASEADDR */
    #ifdef  LINFLEX13_BASEADDR
        LINFLEX13_BASEADDR,
    #endif /* LINFLEX13_BASEADDR */
    #ifdef  LINFLEX14_BASEADDR
        LINFLEX14_BASEADDR,
    #endif /* LINFLEX14_BASEADDR */
    #ifdef  LINFLEX15_BASEADDR
        LINFLEX15_BASEADDR,
    #endif /* LINFLEX15_BASEADDR */
    #ifdef  LINFLEX16_BASEADDR
        LINFLEX16_BASEADDR,
    #endif /* LINFLEX16_BASEADDR */
    #ifdef  LINFLEX17_BASEADDR
        LINFLEX17_BASEADDR,
    #endif /* LINFLEX17_BASEADDR */
};

#define LIN_STOP_SEC_CONST_32
/** 
* @violates @ref LINFlex_LLD_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref LINFlex_LLD_c_REF_2 Precautions shall be taken in 
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "MemMap.h"
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define LIN_START_SEC_CODE
/** 
* @violates @ref LINFlex_LLD_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref LINFlex_LLD_c_REF_2 Precautions shall be taken in 
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @param[in] Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
* @implements   DLIN07710
*/
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_CheckWakeup(CONST(uint8, AUTOMATIC) Channel)
    {
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)FALSE;
    VAR(uint8, AUTOMATIC) Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /* check whether wake up flag has been set and wake up ISR is disabled */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    if (LINFLEX_LLM_WAKEUP_RECEIVED(Lin_LINFlex))
    {
      /**
      * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
      */
      if (LINFLEX_LLM_LIN_IRQ_WUIE_Read(Lin_LINFlex))
      {
        tempReturn = (uint8)FALSE;
      }
      else
      {
        /* LIN channel with wake up support disabled has been woken up */
        /* Clear Wake-Up flag */
        /* Note: all flags have to be cleared by writing a 1 to the flags -> writing 0 has no effect */
        /* @implements DLIN07710 */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_WAKEUP_Clear(Lin_LINFlex);
        /* Exit from Sleep mode and enters in Init mode */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_EXIT_SLEEP_MODE(Lin_LINFlex);
        /* Set the returned value to TRUE */
        tempReturn = (uint8)TRUE;      
      }
    }
    else
    {
      tempReturn = (uint8)FALSE;
    }

    return tempReturn;
    }

/**
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] Channel LIN channel to be initialized.
*
* @return            void.
*
* @implements   DLIN07410
*/
FUNC(void, LIN_CODE) LINFlex_LLD_InitChannel(CONST(uint8, AUTOMATIC) Channel)
    {
    VAR(uint8, AUTOMATIC) BreakLength;
    VAR(uint8, AUTOMATIC) Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /* Get the Break Lenght choosen for the hardware Lin channel from logical channel */
    BreakLength = Lin_Channel_Cfg_Ptr[Channel]->LinChannelBreakLength;

    /* Check whether wake up detection is enabled */
    if ((uint8)STD_ON == Lin_Channel_Cfg_Ptr[Channel]->LinChannelWakeupSupport)
        {
        /* Wake up flag set */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        if (LINFLEX_LLM_WAKEUP_RECEIVED(Lin_LINFlex))
            {
                /* @implements DLIN07291 */
#ifdef LIN_GLOBAL_WAKEUP_SUPPORT
                /* The wake-up shall directly be reported to the EcuM */
                /* via EcuM_SetWakeupEvent call-back function. */
                /* @implements DLIN07292 */
                EcuM_SetWakeupEvent(Lin_Channel_Cfg_Ptr[Channel]->LinChannelEcuMWakeupSource);
#endif
            }
        }

    /* Switch to Initialization mode */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_ENTER_INIT_MODE(Lin_LINFlex);

    /* Load default value for Reset Timeout control register */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LINTCSR_Reset(Lin_LINFlex);

    /* Reset Baudrate Registers */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_RESET_BAUDRATE(Lin_LINFlex)

    /* Load default value for LINCR1 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LINCR1_Reset(Lin_LINFlex);

    /* Exit Init mode and switch to Normal mode */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_EXIT_INIT_MODE(Lin_LINFlex);

    /* Disable Interrupts */
    /*
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_OCIE_Disable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_BEIE_Disable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_CEIE_Disable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_HEIE_Disable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_FEIE_Disable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_BOIE_Disable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_DRIE_Disable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_DTIE_Disable(Lin_LINFlex);

    /* Switch to Initialization mode */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_ENTER_INIT_MODE(Lin_LINFlex);

    /* Enable Lin Mode */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_MODE_Set(Lin_LINFlex);

    /* Clear sleep mode */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_EXIT_SLEEP_MODE(Lin_LINFlex);

    /* Enable Master mode */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_MASTER_Enable(Lin_LINFlex);

    /* Checksum calculation is done by Hardware */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_CCD_Disable(Lin_LINFlex);
    /* Checksum field is sent after the required number of data bytes is sent */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_CFD_Disable(Lin_LINFlex);

    /* Clear Bypass filter (applicable only if any filter is enabled) */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_BF_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_BF_Disable(Lin_LINFlex);

    /* Set Break Length */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    REG_BIT_CLEAR32(LINFLEX_LINCR1(Lin_LINFlex), LINFLEX_LINCR1_MBL_MASK);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_BREAK_LENGTH_Set(Lin_LINFlex, (uint32)BreakLength);

    /* Initialize Baudrate Registers */
    /* do not put semicolon after this macro it will violate MISRA 2004 14.3 rule */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_SET_BAUDRATE(Lin_LINFlex, Lin_Cfg_Ptr->Lin_Channel[Channel]->Lin_BaudRate_RegValue)

    /* Enable Lin Timeout counter */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_TIMEOUT_MODE_Set(Lin_LINFlex);

    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_RESET_STATE_MACHINE_TO_IOT_Set(Lin_LINFlex);

    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_TIMEOUT_COUNTER_Enable(Lin_LINFlex);

    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_RELEASE_MESSAGE_BUFFER(Lin_LINFlex);

    /* Enable AWUM bit if channel is configured automatic wake-up */
    if ((uint8)STD_ON == Lin_Channel_Cfg_Ptr[Channel]->LinChannelWakeupSupport)
        {
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_AWUM_Enable(Lin_LINFlex);
        }
    else
        {
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_AWUM_Disable(Lin_LINFlex);
        }

    /* Exit Init mode and switch to Normal mode */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_EXIT_INIT_MODE(Lin_LINFlex);

    /* Enable Interrupts */
    /*
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_OCIE_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_BEIE_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_CEIE_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_HEIE_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_FEIE_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_BOIE_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_DRIE_Enable(Lin_LINFlex);
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_DTIE_Enable(Lin_LINFlex);

    /* Disable wake up interrupt */
    /* It will be enabled only when needed (after sending sleep command and at the end of */
    /** the LINFlex_LLD_GoToSleepInternal()) and only for 
    *   Lin_Channel_Cfg_Ptr[Channel]->LinChannelWakeupSupport == (uint8) STD_ON
    */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_LIN_IRQ_WUIE_Disable(Lin_LINFlex);
    }

/**
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the LINFlex_LLD_SendReponse
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
* @implements   DLIN07502, DLIN07504, DLIN07505,
*               DLIN07506, DLIN07515, DLIN07517
*/
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_SendHeader(CONST(uint8, AUTOMATIC) Channel, \
                          P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr)
    {
    VAR(uint8, AUTOMATIC) Lin_LINFlex;
    VAR(uint32, AUTOMATIC) counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) tmpReturn = (uint8)E_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /** Stop any ongoing transmission */
    /* @implements DLIN07517 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_ABRQ_Set(Lin_LINFlex);

    /* wait till Cancellation of current frame */
    while(counter < LIN_TIMEOUT_LOOPS)
        {
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        if(FALSE == LINFLEX_LLM_ABRQ_Read(Lin_LINFlex))
            {
            tmpReturn = (uint8)E_OK;
            break;
            }
        counter++;
        }
    if((uint8)E_OK == tmpReturn)
        {
        /* 
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer 
        */ 
        LINFLEX_LLM_RELEASE_MESSAGE_BUFFER(Lin_LINFlex);

        /* Clear the Noise Flag of LIN Error Status Register */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_NF_Clear(Lin_LINFlex);

        /* Prepare header */
        /* First step Clear previous ID and Data Lenght */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_ID_Clear(Lin_LINFlex);
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DFL_Clear(Lin_LINFlex);

        /* Reset previous Data Bytes */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_BDRL_Write(Lin_LINFlex, 0x00000000);
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_BDRM_Write(Lin_LINFlex, 0x00000000);

        /* Set new Identifier - Low parity bits are ignored - Calculated by LinFlex controller */
        /* @implements DLIN07505 */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_ID_Set(Lin_LINFlex, (uint32)PduInfoPtr->Pid);

        /* Set Data length */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DFL_Set(Lin_LINFlex, ((uint32)PduInfoPtr->Dl - 1U));

        /* Set CheckSum type */
        /* @implements DLIN07506 */
        if (LIN_ENHANCED_CS == PduInfoPtr->Cs)
            {
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
           LINFLEX_LLM_ENHANCED_CKS_Set(Lin_LINFlex);
            }
        else
            {
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
           LINFLEX_LLM_CLASSIC_CKS_Set(Lin_LINFlex);
            }

        /* Set Data Direction */
        if (LIN_MASTER_RESPONSE == PduInfoPtr->Drc)
            {
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_TX_DIRECTION_Set(Lin_LINFlex);
            /* do not transmit header here because its a master->slave frame
            the header will be transmited together with the respose when calling SendResponse function*/
            }
        else
            {
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_RX_DIRECTION_Set(Lin_LINFlex);
            /* Transmit Header */
            /* @implements DLIN07504 */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
           LINFLEX_LLM_HTRQ_Set(Lin_LINFlex);
            }
        }
    return tmpReturn;
    }

/**
* @brief   Sends the response part of the LIN frame.
* @details Initiates the transmission of the data
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            void.
*
* @implements   DLIN07518, DLIN07519,
*               DLIN07520, DLIN07521,
*               DLIN07522
*/
FUNC (void, LIN_CODE) LINFlex_LLD_SendResponse(CONST(uint8, AUTOMATIC) Channel, \
                      P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) PduInfoPtr)
    {
    VAR(uint8, AUTOMATIC) tempDataLength;
    VAR(uint16, AUTOMATIC) Loop;
    VAR(uint32, AUTOMATIC) tempBDR;
    VAR(uint8, AUTOMATIC) Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /* Get data length */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    tempDataLength = ((uint8) (LINFLEX_LLM_DFL_Normal_Read(Lin_LINFlex) + 1UL));

    /* Fill buffer data registers: fill only BDRL or both BDRL and BDRM depending on data length */
    /* If data length < 5 fill only BDRL otherwise (data length > 4) fill both BDRL and BDRM     */
    if (tempDataLength < (uint8)5U)
        {
        tempBDR = (uint32)0x00000000;
        /* @implements DLIN07522 */
        for (Loop = (uint8)0U; Loop <  tempDataLength; Loop++)
            {
            /**
            * @violates @ref LINFlex_LLD_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            tempBDR |= (uint32)((PduInfoPtr->SduPtr[Loop] & LINFLEX_BDRL_DATA0_MASK)<<((uint8)8U * Loop));
            }

        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_BDRL_Write(Lin_LINFlex, tempBDR);
        }

    if (tempDataLength > (uint8)4U)
        {
        tempBDR = (uint32)0x00000000;
        /* @implements DLIN07521 */
        for (Loop = (uint8)0U; Loop < (uint8)4U; Loop++)
            {
            /**
            * @violates @ref LINFlex_LLD_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            tempBDR |= ((PduInfoPtr->SduPtr[Loop] & LINFLEX_BDRL_DATA0_MASK) << ( 8U * Loop));
            }
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_BDRL_Write(Lin_LINFlex, tempBDR);
        tempBDR = (uint32)0x00000000;
        /* @implements DLIN07520 */
        for (Loop =  (uint8)4U; Loop < tempDataLength; Loop++)
            {
            /**
            * @violates @ref LINFlex_LLD_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            tempBDR |= ((PduInfoPtr->SduPtr[Loop] & LINFLEX_BDRM_DATA4_MASK) << ( 8U * (Loop - 4U)));
            }

        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_BDRM_Write(Lin_LINFlex, tempBDR);
        }
    /* Transmit Header and Response */
    /* @implements DLIN07518 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_HTRQ_Set(Lin_LINFlex);
    }

/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with 
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
* @implements   DLIN07801, DLIN07810
*/
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_GoToSleep(CONST(uint8, AUTOMATIC) Channel)
    {
    VAR(uint8, AUTOMATIC) Lin_LINFlex;
    VAR(uint32, AUTOMATIC) counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) tmpReturn = (uint8)E_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /* Stop any ongoing transmission */
    /* @implements DLIN07810 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_ABRQ_Set(Lin_LINFlex);

    /* wait till Cancellation of current frame */

    /* @implements DLIN07810 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_ABRQ_Set(Lin_LINFlex);

    /* wait till Cancellation of current frame */
    while(counter < LIN_TIMEOUT_LOOPS)
        {
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        if(FALSE == LINFLEX_LLM_ABRQ_Read(Lin_LINFlex))
            {
            tmpReturn = (uint8)E_OK;
            break;
            }
        counter++;
        }
    if((uint8)E_OK == tmpReturn)
        {
        /* 
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer 
        */ 
        LINFLEX_LLM_RELEASE_MESSAGE_BUFFER(Lin_LINFlex);

        /* Prepare header */
        /* First step Clear previous ID and Data Lenght */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_ID_Clear(Lin_LINFlex);
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DFL_Clear(Lin_LINFlex);

        /* Set SLEEP Mode Identifier - Parity bits are ignored - Calculated by LinFlex controller */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_ID_Set(Lin_LINFlex, LIN_SLEEP_COMMAND_ID);

        /* Set CheckSum type */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_CLASSIC_CKS_Set(Lin_LINFlex);

        /* Set Data direction */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_TX_DIRECTION_Set(Lin_LINFlex);

        /* Set Data Length */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DFL_Set(Lin_LINFlex, LIN_DATA_LENGTH_8);

        /* Update Data bytes */
        /* do not put semicolon after these macros; it will violate MISRA 2004 14.3 rule */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA7_Set(Lin_LINFlex, LIN_DATA_255)
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA6_Set(Lin_LINFlex, LIN_DATA_255)
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA5_Set(Lin_LINFlex, LIN_DATA_255)
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA4_Set(Lin_LINFlex, LIN_DATA_255)
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA3_Set(Lin_LINFlex, LIN_DATA_255)
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA2_Set(Lin_LINFlex, LIN_DATA_255)
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA1_Set(Lin_LINFlex, LIN_DATA_255)
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_DATA0_Set(Lin_LINFlex, LIN_DATA_0)

        /* Transmit Header and Response */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_HTRQ_Set(Lin_LINFlex);
        }
    return tmpReturn;
    }

/**
* @brief   Same function as Lin_LLD_GoToSleep() but 
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the 
*          Channel in sleep mode (then LIN hardware enters a 
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
* @implements   DLIN07301, DLIN07303, DLIN07304,
*               DLIN07315, DLIN07316
*/
FUNC (Std_ReturnType, LIN_CODE) LINFlex_LLD_GoToSleepInternal(CONST(uint8, AUTOMATIC) Channel)
    {
    VAR(uint8, AUTOMATIC) Lin_LINFlex;
    VAR(uint32, AUTOMATIC) counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) tmpReturn = (uint8)E_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /* Stop any ongoing transmission */
    /* @implements DLIN07316 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_ABRQ_Set(Lin_LINFlex);

    /* wait till Cancellation of current frame */
    /* @implements DLIN07316 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_ABRQ_Set(Lin_LINFlex);

    /* wait till Cancellation of current frame */
    while(counter < LIN_TIMEOUT_LOOPS)
        {
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        if(FALSE == LINFLEX_LLM_ABRQ_Read(Lin_LINFlex))
            {
            tmpReturn = (uint8)E_OK;
            break;
            }
        counter++;
        }
    if((uint8)E_OK == tmpReturn)
        {
        /* 
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer 
        */ 
        LINFLEX_LLM_RELEASE_MESSAGE_BUFFER(Lin_LINFlex);

        /* Enter Sleep mode */
        /* @implements DLIN07304 */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        LINFLEX_LLM_ENTER_SLEEP_MODE(Lin_LINFlex);
        /* Check whether wake up detection is enabled */
        if ((uint8)STD_ON == Lin_Channel_Cfg_Ptr[Channel]->LinChannelWakeupSupport)
            {
            /* Wake up detection is enabled */
            /* Clear Wake-Up flag */
            /* @implements DLIN07301 */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_WAKEUP_Clear(Lin_LINFlex);

            /* Enable wake up interrupt */
            /* @implements DLIN07303 */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_LIN_IRQ_WUIE_Enable(Lin_LINFlex);
            }
        }
    return tmpReturn;
    }

/**
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL_STATE state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
* @implements   DLIN07609, DLIN07610
*/
FUNC (void, LIN_CODE) LINFlex_LLD_WakeUp(CONST(uint8, AUTOMATIC) Channel)
    {
    VAR(uint8, AUTOMATIC) Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /* Clear Sleep Bit */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_EXIT_SLEEP_MODE(Lin_LINFlex);

    /* Send Wake up request */
    /* @implements DLIN07610 */
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_WURQ_Set(Lin_LINFlex);
    }

/**
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status. 
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error rised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header 
 *                          transmission.
 * @retval LIN_TX_ERROR     Error occurred during response 
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 * @retval LIN_RX_NO_REPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 * @retval LIN_CH_SLEEP     Channel is in sleep mode.
 *
 * @implements   DLIN07764, DLIN07765, DLIN07766
 */
FUNC (Lin_StatusType, LIN_CODE) LINFlex_LLD_HardwareGetStatus(CONST(uint8, AUTOMATIC) Channel,
                             P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) LinSduPtr)
    {
    VAR(uint8, AUTOMATIC) Lin_LINFlex;
    VAR(uint8, AUTOMATIC) tempStatus;
    VAR(uint8, AUTOMATIC) tempOC1 = (uint8)0;
    VAR(uint8, AUTOMATIC) tempHTO = (uint8)0;
    VAR(Lin_StatusType,AUTOMATIC) TempReturn = LIN_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    tempStatus = (uint8)((LINFLEX_LLM_LIN_STATE_Read(Lin_LINFlex))>>(uint8)12U);

    switch (tempStatus & (uint8)0x0FU)
        {
        /* Master mode => return status to TX_BUSY if any of the following condition */
        case LINFLEX_LINSR_BREAK_TX_MODE :
        case LINFLEX_LINSR_BREAK_DEL_TX_MODE :
        case LINFLEX_LINSR_SYNC_FIELD_TX_MODE:
        case LINFLEX_LINSR_ID_FIELD_TX_MODE:
        case LINFLEX_LINSR_HEADER_TX_MODE:
            TempReturn = LIN_TX_BUSY;
            break;

        case LINFLEX_LINSR_DATA_RX_TX_MODE:
        case LINFLEX_LINSR_CHECKSUM_RX_TX_MODE:
            if ((LIN_TX_MASTER_RES_COMMAND == TransmitHeaderCommand[Channel]) ||
                (LIN_TX_SLEEP_COMMAND      == TransmitHeaderCommand[Channel]))
                {
                TempReturn = LIN_TX_BUSY;
                }
            else if (LIN_TX_SLAVE_RES_COMMAND == TransmitHeaderCommand[Channel])
                {
                TempReturn = LIN_RX_BUSY;
                }
            else
                {
                TempReturn = LIN_NOT_OK;
                }
            break;

        case LINFLEX_LINSR_IDLE_MODE:
        /* Check error status */
            switch(Lin_LinChFrameErrorStatus[Channel])
                {
                /* Tx header error conditions */
                case LIN_IDENTIFIER_PARITY_ERROR:
                case LIN_SYNCH_FIELD_ERROR:
                    TempReturn = LIN_TX_HEADER_ERROR;
                    break;

                /* Header or Response timeout error conditions */
                case LIN_TIMEOUT_ERROR:
                   /*
                   * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                   */
                   tempOC1 =(uint8)(LINFLEX_LLM_OC1_Read(Lin_LINFlex));
                   /*
                   * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                   */
                   tempHTO =(uint8)(LINFLEX_LLM_HTO_Read(Lin_LINFlex));

                    if ((LIN_TX_MASTER_RES_COMMAND == TransmitHeaderCommand[Channel]) ||
                        (LIN_TX_SLEEP_COMMAND      == TransmitHeaderCommand[Channel]))
                    {
                      if (tempOC1 <= tempHTO)
                      {
                          /* Timeout on Master Header Transmission */
                          TempReturn = LIN_TX_HEADER_ERROR;
                      }
                      else
                      {
                          /* Timeout on Master Response Transmission */
                          TempReturn = LIN_TX_ERROR;
                      }
                    }
                    else
                    {
                      /* Driver has received 0 or at least one data byte ? */
                      /*
                      * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                      */
                      if ((TRUE == LINFLEX_LLM_IS_BDRL_EMPTY(Lin_LINFlex)) && \
                          (TRUE == LINFLEX_LLM_IS_BDRM_EMPTY(Lin_LINFlex)))
                      {
                        /* Driver has received 0 bytes */
                        TempReturn = LIN_RX_NO_RESPONSE;
                      }
                      else
                      {
                        /* Driver has received at least 1 byte */
                        TempReturn = LIN_RX_ERROR;
                      }
                    }
                    break;

                /* Tx data error conditions */
                case LIN_BIT_ERROR:
                    if ((LIN_TX_MASTER_RES_COMMAND == TransmitHeaderCommand[Channel]) ||
                        (LIN_TX_SLEEP_COMMAND      == TransmitHeaderCommand[Channel]))
                    {
                      /*
                      * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                      */
                      tempOC1 =(uint8)(LINFLEX_LLM_OC1_Read(Lin_LINFlex));
                      /*
                      * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                      */
                      tempHTO =(uint8)(LINFLEX_LLM_HTO_Read(Lin_LINFlex));

                      if (tempOC1 <= tempHTO)
                      {
                          /* Bit Error on Master Header Transmission */
                          TempReturn = LIN_TX_HEADER_ERROR;
                      }
                      else
                      {
                          /* Bit Error on Master Response Transmission */
                          TempReturn = LIN_TX_ERROR;
                      }
                    }
                    else if (LIN_TX_SLAVE_RES_COMMAND == TransmitHeaderCommand[Channel])
                    {
                        TempReturn = LIN_TX_HEADER_ERROR;
                    }
                    else
                    {
                        TempReturn = LIN_NOT_OK;
                    }
                    break;

                /* Rx error conditions */
                case LIN_NOISE_ERROR:
                case LIN_CHECKSUM_ERROR:
                case LIN_FRAMING_ERROR:
                /*  TempReturn = LIN_RX_ERROR;
                    break; */
                /* Lin - Buffer overrun handling */
                case LIN_BUFFER_OVER_RUN_ERROR:
                    /**
                     * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                     */
                    LINFLEX_LLM_RELEASE_MESSAGE_BUFFER(Lin_LINFlex);
                    TempReturn = LIN_RX_ERROR;
                    break;

                case LIN_NO_ERROR :
                    /* Check Lin frame status variable */
                    switch(Lin_LinChFrameStatus[Channel])
                        {
                        /* Tx completed - Status Updated in ISR */
                        case LIN_TX_COMPLETE_STATE:
                            TempReturn = LIN_TX_OK;
                            break;

                        /* Rx completed - Status Updated in ISR */
                        case LIN_RX_COMPLETE_STATE:
                            /* Copy the data from hardware buffer */
                            /* @implements DLIN07765 */
                            LINFlex_LLD_CopyData(Channel, LinSduPtr);
                            TempReturn =  LIN_RX_OK;
                            break;

                        /* Tx completed - But master not received any data */
                        case LIN_CH_RECEIVE_NOTHING_STATE:
                            TempReturn = LIN_RX_NO_RESPONSE;
                            break;

                        /* Channel Initialized or wakenup or all activity completed and ready to send next header */
                        case LIN_CH_READY_STATE:
                            TempReturn = LIN_OPERATIONAL;
                            break;

                        /* Channel not ready */
                        case LIN_CH_NOT_READY_STATE:
                          TempReturn = LIN_NOT_OK;
                          break;

                        default :
                            /* @implements DLIN07766 */
                            Cer_ReportError((uint16)LIN_MODULE_ID,(uint8)0,
                            (uint8)LINFLEX_LLD_HWGETSTATUS_ID,
                            (uint8)LIN_CER_UNEXPECTED_FRAME_STATUS_INTERRUPT);
                            /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                                  Cer_ReportError() function implementation */
                            break;
                        }
                    break;
                default:
                    /* @implements DLIN07766 */
                    Cer_ReportError((uint16)LIN_MODULE_ID,
                    (uint8)0,
                    (uint8)LINFLEX_LLD_HWGETSTATUS_ID,
                    (uint8)LIN_CER_UNEXPECTED_FRAME_ERROR_STATUS_INTERRUPT);
                    /* Compiler_Warning : This warning is thrown due to the infinite loop while(1) in the
                                          Cer_ReportError() function implementation */
                    break;
                }
            break;
        default :
            TempReturn = LIN_NOT_OK;
            break;
        }
    return TempReturn;
    }

/**
* @brief   Copy the data received from the LINFlex data registers to LinSduPtr.
* @details This function shall copy the received data in the provided buffer
*          addressed by the LinSduPtr pointer parameter.
*
* @param[in]   Channel LIN channel to be addressed.
* @param[out]  LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped LIN Hardware receive buffer where the current SDU is stored
*
* @return       void.
*
* @implements   DLIN07280
*
* @note         Internal driver function.
*
* @violates @ref LINFlex_LLD_c_REF_5 All declarations and definitions
*                of objects or functions at file scope shall have
*                internal linkage unless external linkage is required.
*/
FUNC (void, LIN_CODE) LINFlex_LLD_CopyData(CONST(uint8, AUTOMATIC) Channel,
                    P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) LinSduPtr)
    {
    VAR(uint8, AUTOMATIC) tempDataLength;
    VAR(uint8, AUTOMATIC) Loop;
    VAR(uint8, AUTOMATIC) Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
    Lin_LINFlex = Lin_Channel_Cfg_Ptr[Channel]->LinChannelID;

    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    tempDataLength = ((uint8) (LINFLEX_LLM_DFL_Normal_Read(Lin_LINFlex) + 1UL));

    /* Data Length Calculation */
    if (tempDataLength < 5U)
        {
        for (Loop = (uint8) 0U; Loop < tempDataLength; Loop++)
            {
            /* Copy LSB data received in LinSduPtr[] buffer */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref LINFlex_LLD_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            LinSduPtr[Loop] = (uint8)((LINFLEX_LLM_BDRL_Read(Lin_LINFlex) >> (Loop * 8U)) & LINFLEX_BDRL_DATA0_MASK);
            }
        }

    if (tempDataLength > 4U)
        {
        for (Loop = 0U; Loop < 4U; Loop++)
            {
            /* Copy LSB data received in LinSduPtr[] buffer */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref LINFlex_LLD_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            LinSduPtr[Loop] = (uint8)((LINFLEX_LLM_BDRL_Read(Lin_LINFlex) >> (Loop * 8U)) & LINFLEX_BDRL_DATA0_MASK);
            }

        for (Loop = 4U; Loop < tempDataLength; Loop++)
            {
            /* Copy MSB data received in LinSduPtr[] buffer */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref LINFlex_LLD_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            LinSduPtr[Loop] = (uint8)((LINFLEX_LLM_BDRM_Read(Lin_LINFlex) >> ((Loop -  4U) *  8U)) & LINFLEX_BDRM_DATA4_MASK);
            }
        }
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    LINFLEX_LLM_RELEASE_MESSAGE_BUFFER(Lin_LINFlex);
    }

/**
* @brief   Interrupt handler for TX and RX on LINFlex.
* @details This function shall manage all the RX and TX ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @implements   DLIN07270, DLIN07271, DLIN07272
*               DLIN07273, DLIN07274, DLIN07275,
*               DLIN07277
*
* @note         Internal driver function.
*/
FUNC (void, LIN_CODE) LINFlex_Tx_Rx_InterruptHandler(CONST(uint8, AUTOMATIC) Channel)
    {
    VAR(sint8, AUTOMATIC) LogicalChannel;
    VAR(uint8, LIN_VAR) Lin_LINFlex;
    VAR(uint32, LIN_VAR) Lin_status;

    /* Get the logical channel index from physical channel */
    LogicalChannel = Lin_ChannelHardwareMap[Channel];

    if (Lin_ChannelHardwareMap[Channel] != -1)
        {
        /* Get base address of LINFlex module which is used by LIN channel */
        Lin_LINFlex = (uint8)Channel;

       /**
       * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
       */
        Lin_status = REG_READ32(LINFLEX_LINIER(Lin_LINFlex));
       /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        Lin_status &= REG_READ32(LINFLEX_LINSR(Lin_LINFlex));
        if (0UL != Lin_status)
        {
        /* Wake up interrupt */
        /* Wake up flag set */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
            if (0U != (Lin_status & LINFLEX_LINSR_WUF_MASK))
            {
                /* Disable wake up interrupt */
                /**
                                        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                                        */
                LINFLEX_LLM_LIN_IRQ_WUIE_Disable(Lin_LINFlex);

                /* @implements DLIN07277 */
                if (LIN_CH_SLEEP_STATE == Lin_LinChStatus[LogicalChannel])
                {
                    /* @implements DLIN07273 */
#ifdef LIN_GLOBAL_WAKEUP_SUPPORT
                    /* Indicates a valid timer wakeup event to ECU State Manager */
                    /* @implements DLIN07274 */
                    EcuM_CheckWakeup(Lin_Channel_Cfg_Ptr[LogicalChannel]->LinChannelEcuMWakeupSource);
#endif
                    /* Set Channel state Operational */
                    /* @implements DLIN07271 */
                    Lin_LinChStatus[LogicalChannel] = LIN_CH_OPERATIONAL_STATE;
                    /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
                    Lin_LinChFrameStatus[LogicalChannel] = LIN_CH_READY_STATE;
                }
            
                /* Clear Wake-Up flag */
                /**
                                        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                                        */
                 LINFLEX_LLM_WAKEUP_Clear(Lin_LINFlex);
            }
        /* Data Reception Complete interrupt */
        /* Data Reception Completed Flag set */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
            else if (0U != (Lin_status & LINFLEX_LINSR_DRF_MASK))
            {
            /* Clear interrupt flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_DATA_RX_COMPLETED_Clear(Lin_LINFlex);

            /* Update LIN channel frame operation status to LIN_RX_COMPLETE_STATE */
            Lin_LinChFrameStatus[LogicalChannel] = LIN_RX_COMPLETE_STATE;

            /* Noise Error has occurred ? */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            if (LINFLEX_LLM_NF_Read(Lin_LINFlex))
                {
                /* Set LIN channel frame error status to LIN_NOISE_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_NOISE_ERROR;

                /* Clear the Noise Flag of LIN Error Status Register */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_NF_Clear(Lin_LINFlex);
                }
            }
        /* Data Transmitted Complete interrupt */
        /* Data Transmission Completed Flag set */
        /**
        * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
            else if (0U != (Lin_status & LINFLEX_LINSR_DTF_MASK))
            {
            /* Clear interrupt flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_DATA_TX_COMPLETED_Clear(Lin_LINFlex);
            /* Check if sleep mode was transmitted */
            if (LIN_TX_SLEEP_COMMAND == TransmitHeaderCommand[LogicalChannel])
                {
                /* Check whether wake up detection is enabled */
                if ((uint8)STD_ON == Lin_Channel_Cfg_Ptr[LogicalChannel]->LinChannelWakeupSupport)
                    {
                    /* Wake up detection enabled */
                    /* Clear Wake-Up flag */
                    /**
                    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                    */
                    LINFLEX_LLM_WAKEUP_Clear(Lin_LINFlex);
                    /* Enable wake up interrupt */
                    /* @implements DLIN07275 */
                    /**
                    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                    */
                    LINFLEX_LLM_LIN_IRQ_WUIE_Enable(Lin_LINFlex);
                    }
                /* Enter Sleep mode */
                /* @implements DLIN07276 */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_ENTER_SLEEP_MODE(Lin_LINFlex);
                /* Set Channel state Sleep */
                /* @implements DLIN07272 */
                Lin_LinChStatus[LogicalChannel] = LIN_CH_SLEEP_STATE;
                /* Update TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
                TransmitHeaderCommand[LogicalChannel] = LIN_TX_NO_COMMAND;
                }
            else
                {
                /* Update LIN channel frame operation status to LIN_TX_COMPLETE_STATE */
                Lin_LinChFrameStatus[LogicalChannel] = LIN_TX_COMPLETE_STATE;
                }
            }
        else
            {
            /* Error condition - Clear all flag */
            /* Clear Wake-Up flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_WAKEUP_Clear(Lin_LINFlex);
            /* Clear Data Buffer Full flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_DATA_BUFF_FULL_Clear(Lin_LINFlex);
            /* Clear Data Buffer Empty flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_DATA_BUFF_EMPTY_Clear(Lin_LINFlex);
            /* Clear Data Reception Completed flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_DATA_RX_COMPLETED_Clear(Lin_LINFlex);
            /* Clear Data Transmission Completed flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_DATA_TX_COMPLETED_Clear(Lin_LINFlex);
            /* Clear Header Reception flag */
            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            LINFLEX_LLM_HEADER_RECEIVED_Clear(Lin_LINFlex);
            }
        }
        else
        {
          /* @violates @ref LINFlex_LLD_c_REF_8 All if ... else if constructs shall be
          *  terminated with an else clause. */
        }
    }
    return; /* exit function with no return */
    }

/**
* @brief   Interrupt handler for Error on LINFlex.
* @details This function shall manage all the Error ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @implements   DLIN07265, DLIN07266, DLIN07267,
*               DLIN07268
*
* @note         Internal driver function.
*/
FUNC (void, LIN_CODE) LINFlex_ErrorInterruptHandler(CONST(uint8, AUTOMATIC) Channel)
    {
    VAR(sint8,AUTOMATIC)LogicalChannel;
    VAR(uint8, AUTOMATIC) Lin_LINFlex;
    VAR(boolean, AUTOMATIC) IsTxErrorOnSleepCmd = (boolean)FALSE;
#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
    VAR(boolean, AUTOMATIC) IsPhysicalError = (boolean)FALSE;
#endif
    VAR(uint32, LIN_VAR) Lin_status;

    /* Get the logical channel index from physical channel */
    LogicalChannel = Lin_ChannelHardwareMap[Channel];
    /**
    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
    */
    if (Lin_ChannelHardwareMap[Channel] != -1)
        {
        /* Get base address of LINFlex module which is used by LIN channel */
         /**
          * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
         */
        Lin_LINFlex = (uint8)Channel;
         /**
          * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
         */       
       Lin_status = REG_READ32(LINFLEX_LINIER(Lin_LINFlex));
        if (0U != (Lin_status & LINFLEX_LINIER_HEIE_MASK))
        {
            Lin_status |= 0x00000600UL;
        }
        /**
          * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
        */
        Lin_status &= REG_READ32(LINFLEX_LINESR(Lin_LINFlex));
        /**
          * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
         */
        if (0UL != Lin_status)
        {
            /* Check only error flags */
            if (0U != (Lin_status & LINFLEX_LINESR_OCF_MASK))
            {
                /* Clear Output Compare flag */
                /*
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_OCF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_TIMEOUT_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_TIMEOUT_ERROR;

                /* Check if error was on sleep frame transmitting */
                if (LIN_TX_SLEEP_COMMAND == TransmitHeaderCommand[LogicalChannel])
                {
                    IsTxErrorOnSleepCmd = (boolean)TRUE;
                }
            }

            if (0U != (Lin_status & LINFLEX_LINESR_BEF_MASK))
            {
                /* Clear Bit Error flag */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_BEF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_BIT_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_BIT_ERROR;

                /* Check if error was on sleep frame transmitting */
                if (LIN_TX_SLEEP_COMMAND == TransmitHeaderCommand[LogicalChannel])
                {
                    IsTxErrorOnSleepCmd = (boolean)TRUE;
                }

#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
                IsPhysicalError = (boolean)TRUE;
#endif
            }

            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            if (0U != (Lin_status & LINFLEX_LINESR_CEF_MASK))
            {
                /* Clear Checksum Error flag */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_CEF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_CHECKSUM_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_CHECKSUM_ERROR;

#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
                IsPhysicalError = (boolean)TRUE;
#endif
            }

            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            if (0U != (Lin_status & LINFLEX_LINESR_SFEF_MASK))
            {
                /* Synch Field Error flag */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_SFEF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_SYNCH_FIELD_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_SYNCH_FIELD_ERROR;

                /* Check if error was on sleep frame transmitting */
                if (LIN_TX_SLEEP_COMMAND == TransmitHeaderCommand[LogicalChannel])
                {
                    IsTxErrorOnSleepCmd = (boolean)TRUE;
                }

#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
                IsPhysicalError = (boolean)TRUE;
#endif
            }

            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            if (0U != (Lin_status & LINFLEX_LINESR_BDEF_MASK))
            {
                /* Break Delimiter Error flag */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_BDEF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_BREAK_DELIMITER_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_BREAK_DELIMITER_ERROR;

                /* Check if error was on sleep frame transmitting */
                if (LIN_TX_SLEEP_COMMAND == TransmitHeaderCommand[LogicalChannel])
                {
                    IsTxErrorOnSleepCmd = (boolean)TRUE;
                }

#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
                IsPhysicalError = (boolean)TRUE;
#endif
            }

            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            if (0U != (Lin_status & LINFLEX_LINESR_IDPEF_MASK))
            {
                /* Identifier Parity Error flag */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_IDPEF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_IDENTIFIER_PARITY_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_IDENTIFIER_PARITY_ERROR;

                /* Check if error was on sleep frame transmitting */
                if (LIN_TX_SLEEP_COMMAND == TransmitHeaderCommand[LogicalChannel])
                {
                    IsTxErrorOnSleepCmd = (boolean)TRUE;
                }

#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
                IsPhysicalError = (boolean)TRUE;
#endif
            }

            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            if (0U != (Lin_status & LINFLEX_LINESR_FEF_MASK))
            {
                /* Framing Error flag */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_FEF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_FRAMING_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_FRAMING_ERROR;

#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
                IsPhysicalError = (boolean)TRUE;
#endif
            }

            /**
            * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
            */
            if (0U != (Lin_status & LINFLEX_LINESR_BOF_MASK))
            {
                /* Buffer Overrun flag */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_BOF_Clear(Lin_LINFlex);

                /* Set LIN channel frame error status to LIN_BUFFER_OVER_RUN_ERROR */
                Lin_LinChFrameErrorStatus[LogicalChannel] = LIN_BUFFER_OVER_RUN_ERROR;

#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
                IsPhysicalError = (boolean)TRUE;
#endif
            }

            /* Check if error was on sleep frame transmitting */
            if ((boolean)TRUE == IsTxErrorOnSleepCmd) /* Error was on sleep frame transmitting */
            {
                /* Check whether wake up detection is enabled */
                if ((uint8)STD_ON == Lin_Channel_Cfg_Ptr[LogicalChannel]->LinChannelWakeupSupport)
                {
                    /* Wake up detection enabled */
                    /* Clear Wake-Up flag */
                    /**
                    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                    */
                    LINFLEX_LLM_WAKEUP_Clear(Lin_LINFlex);
                    /* Enable wake up interrupt */
                    /* @implements DLIN07267 */
                    /**
                    * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                    */
                    LINFLEX_LLM_LIN_IRQ_WUIE_Enable(Lin_LINFlex);
                }
                /* Enter Sleep mode */
                /* @implements DLIN07268 */
                /**
                * @violates @ref LINFlex_LLD_c_REF_3 cast from unsigned int to pointer
                */
                LINFLEX_LLM_ENTER_SLEEP_MODE(Lin_LINFlex);
                /* Set Channel state Sleep */
                /* @implements DLIN07266 */
                Lin_LinChStatus[LogicalChannel] = LIN_CH_SLEEP_STATE;
                /* Update TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
                TransmitHeaderCommand[LogicalChannel] = LIN_TX_NO_COMMAND;
                /* Update LIN channel frame operation status to LIN_CH_NOT_READY_STATE */
                Lin_LinChFrameStatus[LogicalChannel] = LIN_CH_NOT_READY_STATE;
                /* Reset IsTxErrorOnSleepCmd flag */
                IsTxErrorOnSleepCmd = (boolean)FALSE;
            }
        }
        else
        {
            /* @violates @ref LINFlex_LLD_c_REF_8 All if ... else if constructs shall be
            *  terminated with an else clause. */
        }
#ifdef LIN_PHYSICAL_ERROR_NOTIFICATION_SUPPORT
        if ((boolean)FALSE != IsPhysicalError ) 
        {
            if (NULL_PTR != Lin_Cfg_Ptr->PhysicalErrorNotification )
            {
                Lin_Cfg_Ptr->PhysicalErrorNotification(LogicalChannel, Lin_status);
            }
        }
#endif
    }
    return; /* exit function with no return */
    }

#define LIN_STOP_SEC_CODE
/** 
* @violates @ref LINFlex_LLD_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref LINFlex_LLD_c_REF_2 Precautions shall be taken in 
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
