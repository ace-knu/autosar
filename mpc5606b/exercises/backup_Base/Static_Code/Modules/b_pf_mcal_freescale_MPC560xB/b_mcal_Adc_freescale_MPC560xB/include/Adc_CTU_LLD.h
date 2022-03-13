/**
*   @file    Adc_CTU_LLD.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - low level driver header file.
*   @details CTU low level driver API.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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

#ifndef ADC_CTU_LLD_H
#define ADC_CTU_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_CTU_LLD_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_CTU_LLD_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Adc_CTU_LLD_h_REF_1 Repeated include file */
#include "Reg_Macros.h"
#include "Adc_CTU_ipversion.h"
#include "Reg_eSys_CTU.h"
/* @violates @ref Adc_CTU_LLD_h_REF_1 Repeated include file */
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_CTU_LLD.h
*
*/
#define CTU_VENDOR_ID                    (43)
#define CTU_MODULE_ID                    (123)
#define CTU_AR_RELEASE_MAJOR_VERSION     (4)
#define CTU_AR_RELEASE_MINOR_VERSION     (0)
#define CTU_AR_RELEASE_REVISION_VERSION  (3)
#define CTU_SW_MAJOR_VERSION             (1)
#define CTU_SW_MINOR_VERSION             (0)
#define CTU_SW_PATCH_VERSION             (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if Std_Types.h file and CTU header file are of the same Autosar version */
 #if ((CTU_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (CTU_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION))
 #error "AutoSar Version Numbers of Adc_CTU_LLD.h and Std_Types.h are different"
 #endif
#endif

#if (CTU_VENDOR_ID != CTU_REG_VENDOR_ID)
#error "Adc_CTU_LLD.h and Reg_eSys_CTU.h have different vendor ids"
#endif

#if ((CTU_AR_RELEASE_MAJOR_VERSION != CTU_REG_AR_RELEASE_MAJOR_VERSION) || \
     (CTU_AR_RELEASE_MINOR_VERSION != CTU_REG_AR_RELEASE_MINOR_VERSION) || \
     (CTU_AR_RELEASE_REVISION_VERSION != CTU_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Adc_CTU_LLD.h and Reg_eSys_CTU.h are different"
#endif

#if ((CTU_SW_MAJOR_VERSION != CTU_REG_SW_MAJOR_VERSION) || \
     (CTU_SW_MINOR_VERSION != CTU_REG_SW_MINOR_VERSION) || \
     (CTU_SW_PATCH_VERSION != CTU_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Adc_CTU_LLD.h and Reg_eSys_CTU.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Clear Flag bit position inside CTU_EVTCFGRx register.
*
*
* @implements
*/
/* if bolero 512K */
#if (IPV_CTU_00_00_08_02==IPV_CTU)
#define CLEARFLAGSHIFTVALUE ((uint32)CTU_EVTCFGR_CLR_FLAG_POS_512K)
/* if bolero 1.5M */
#elif ((IPV_CTU_00_00_02_03==IPV_CTU) || (IPV_CTU_00_00_03_01==IPV_CTU))
#define CLEARFLAGSHIFTVALUE ((uint32)CTU_EVTCFGR_CLR_FLAG_POS_1M5)
/* if fado */
#elif (IPV_CTU_00_00_07_02==IPV_CTU)
#define CLEARFLAGSHIFTVALUE ((uint32)CTU_EVTCFGR_CLR_FLAG_POS)
/* if bolero 3M */
#elif (IPV_CTU_00_00_04_01==IPV_CTU)
 /* if !bolero 256k-128k */
 #ifndef IPV_CTU_401_BOLERO256K
  #define CLEARFLAGSHIFTVALUE ((uint32)CTU_EVTCFGR_CLR_FLAG_POS_3M)
 /* Bolero 256k-128k */
 #else
  #define CLEARFLAGSHIFTVALUE ((uint32)CTU_EVTCFGR_CLR_FLAG_POS_256k)
 #endif /* IPV_CTU_401_BOLERO256K */
#endif

/* if !Bolero 3M (Bolero 256k-128k) and !Bolero 512K and !Bolero 1.5M */
#if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                            (IPV_CTU != IPV_CTU_00_00_03_01) && \
                            (IPV_CTU != IPV_CTU_00_00_08_02))
/**
* @brief          This macro initializes the CTU hardware module.
* @details        Sets TRGIEN bit, in conformance with the parameter, 
*                 from the CTU_CSR register.
*
* @implements
*/
  /* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
  #define CTU_LLD_Init_TRUE()  REG_BIT_SET32(CTU_CSR, CTU_CSR_TRGIEN);
  /* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
  #define CTU_LLD_Init_FALSE()  REG_BIT_CLEAR32(CTU_CSR, CTU_CSR_TRGIEN);

#else /* Bolero 3M (Bolero 256k-128k) or Bolero 512K or Bolero 1.5M */

  /* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
  #define CTU_LLD_Init_TRUE()  do {}while(0)
  /* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
  #define CTU_LLD_Init_FALSE()  do {}while(0)

#endif /* if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                                     (IPV_CTU != IPV_CTU_00_00_03_01) && \
                                     (IPV_CTU != IPV_CTU_00_00_08_02)) */
/**
* @brief          This macro initializes the CTU hardware module CTU_EVTCFGRx registers.
* @details        Resets all CTU_EVTCFGRx registers (write 0 for reset value).
*
*
* @implements
*/
/* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
#define CTU_LLD_ResetEvtCfgRegs() do {\
  VAR(uint8, AUTOMATIC) regIndex = (uint8)0; \
  for(regIndex=(uint8)0; regIndex < (uint8)MAXIMUM_NUMBER_OF_CTU_EVTCFGREGS; regIndex++)\
  {\
    REG_WRITE32(CTU_EVTCFGRx(regIndex), CTU_EVTCFGR_RESET_VALUE);\
  }\
} while(0)

/**
* @brief          This macro read the CTU hardware module CTU_EVTCFGRx registers.
* @details        Read the CTU_EVTCFGRx register and mask with the Trigger Mask bit.
*
*
* @implements
*/
/* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
#define CTU_LLD_ReadEvtCfgRegs(TriggSrc)  ((REG_READ32(CTU_EVTCFGRx((TriggSrc))))&(CTU_EVTCFGR_TM))

/* if Fado */
#if (IPV_CTU_00_00_07_02==IPV_CTU)
/**
* @brief          This macro initializes the CTU hardware module.
* @details        Resets PRESC_CONF bits from the CTU_CSR register (write 0 for reset value).
*
*
* @implements
*/
#define CTU_LLD_ResetPrescalerBits() {\
  REG_BIT_CLEAR32(CTU_CSR, CTU_CSR_PRESC_CONF);\
}

/**
* @brief          This macro initializes the CTU hardware module.
* @details        Sets PRESC_CONF bits, in conformance with the parameter,
*                 from the CTU_CSR register.
*
*
* @implements
*/
#define CTU_LLD_SetPrescalerValue(PrescConfig) {\
  REG_BIT_CLEAR32(CTU_CSR, CTU_CSR_PRESC_CONF);\
  REG_BIT_SET32(CTU_CSR, (uint32)PrescConfig);\
}

/**
* @brief          This macro initializes the CTU hardware module CTU_SVRx registers.
* @details        Resets all CTU_SVRx registers (write 0 for reset value).
*
*
* @implements
*/
#define CTU_LLD_ResetSvrRegs() {\
  VAR(uint8, AUTOMATIC) regIndex = (uint8)0; \
  for(regIndex=(uint8)1; regIndex <= (uint8)MAXIMUM_NUMBER_OF_CTU_SVRREGS; regIndex++) {\
    REG_WRITE32(CTU_SVRx(regIndex), CTU_SVR_RESET_VALUE);\
  }\
}

/**
* @brief          This macro initializes the CTU hardware module CTU_SVRx registers.
* @details        Sets the CTU_SVRx register, in conformance with the parameter.
*
*
* @implements
*/
#define CTU_LLD_SetCounterStartValue(Index, CounterStartValue) {\
  REG_WRITE32(CTU_SVRx(Index), CounterStartValue);\
}
#endif /* (IPV_CTU_00_00_07_02==IPV_CTU) */

/* if !Fado */
#if (IPV_CTU_00_00_07_02!=IPV_CTU)
/**
* @brief          Configures the CTU hardware module CTU_EVTCFGRx register 
*                 with the desired values.
* @details        Updates all fields in the CTU_EVTCFGRx register 
*                 (the register is specified by the TriggerSource parameter)
*                 AdcHwUnitSelector is uint8 because on some future platforms
*                 can be more than 2 ADC hw units.
*                 - N.B.: Bolero 256k-128k has 1 ADC hw unit.
*
* @param[in]      TriggerSource       Specifies the trigger source index
*                                     (ch0-eMIOS0, ch23-PIT_3,etc..)
* @param[in]      TriggerMask         The value of the Trigger Mask field:
*                                     0: Trigger masked
*                                     1: Trigger enabled
* @param[in]      ClearFlag           The value of the CLR_FLAG field:
*                                     To provide flag_ack through software
*                                     1: Flag_ack is forced to '1' for the particular event
*                                     0: Flag_ack is dependent on flag servicing
*                                     This bit implementation is generic based 
*                                     and implemented only for inputs mapped to PIT event flags.
* @param[in]      AdcHwUnitSelector   The ADC_SEL field value:
*                                     This bit selects the ADC number.
*                                     0: 10-bit ADC0 is selected
*                                     1: 12-bit ADC1 is selected
*                                     N.B.: for Bolero 256k-128k select 1
*                                     Used/present only on platforms that has more than one ADC 
*                                     hardware unit present. On platforms that has only one ADC 
*                                     hardware unit, this parameter is ignored.
* @param[in]      AdcChannelID        The ID of the ADC channel (in order to implement the ADC channel
*                                     mapping over the CTU channels)
*                                     CHANNEL_VALUE[x:0] (the precision is platform dependent)
*                                     These bits provide the ADC channel number to be converted.
*                                     Valid values are 0b0 to 0b1011111 (decimal 95).
*
*
* @implements
*/
/* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
#define CTU_LLD_SetEvtCfgReg(TriggerSource,TriggerMask,ClearFlag,AdcHwUnitSelector,AdcChannelID) do {\
  REG_WRITE32(CTU_EVTCFGRx(TriggerSource),(uint32)(((uint32)(TriggerMask) << CTU_EVTCFGR_TM_POS)|\
             ((uint32)(ClearFlag) << CLEARFLAGSHIFTVALUE) | \
             ((uint32)(AdcHwUnitSelector) << CTU_EVTCFGR_ADC_SEL_POS) | (uint32)(AdcChannelID))); } while(0)
#else /* Fado */
/**
* @brief          Configures the CTU hardware module CTU_EVTCFGRx register 
*                 with the desired values.
* @details        Updates all fields in the CTU_EVTCFGRx register 
*                 (the register is specified by the TriggerSource parameter)
*                 AdcHwUnitSelector is uint8 because on some future platforms
*                 can be more than 2 ADC hw units.
*                 - N.B.: Bolero 256k-128k has 1 ADC hw unit.
*
* @param[in]      TriggerSource       Specifies the trigger source index
*                                     (ch0-eMIOS0, ch32-PIT_3)
* @param[in]      TriggerMask         The value of the Trigger Mask field:
*                                     0: Trigger masked
*                                     1: Trigger enabled
* @param[in]      ClearFlag           The value of the CLR_FLAG field:
*                                     To provide flag_ack through software
*                                     1: Flag_ack is forced to '1' for the particular event
*                                     0: Flag_ack is dependent on flag servicing
*                                     This bit implementation is generic based 
*                                     and implemented only for inputs mapped to PIT event flags.
* @param[in]      CountGroup          The value of the COUNT_GROUP field:
*                                     00: Counter 0 is associated with the particular event
*                                     01: Counter 1 is associated with the particular event
*                                     10: Counter 2 is associated with the particular event
*                                     11: Counter 3 is associated with the particular event
* @param[in]      DelayIndex          The value of the DELAY_INDEX field:
*                                     000: No delay is provided
*                                     001: Counter is loaded with value stored in CTU_SVR1
*                                     010: Counter is loaded with value stored in CTU_SVR2
*                                     011: Counter is loaded with value stored in CTU_SVR3
*                                     100: Counter is loaded with value stored in CTU_SVR4
*                                     101: Counter is loaded with value stored in CTU_SVR5
*                                     110: Counter is loaded with value stored in CTU_SVR6
*                                     111: Counter is loaded with value stored in CTU_SVR7
* @param[in]      AdcChannelID        The ID of the ADC channel (in order to implement the ADC channel
*                                     mapping over the CTU channels)
*                                     CHANNEL_VALUE[x:0] (the precision is platform dependent)
*                                     These bits provide the ADC channel number to be converted.
*                                     Valid values are 0b0 to 0b1011111 (decimal 95).
*
*
* @implements
*/
#define CTU_LLD_SetEvtCfgReg(TriggerSource,TriggerMask,ClearFlag,CountGroup,DelayIndex, AdcChannelID) do {\
  REG_WRITE32(CTU_EVTCFGRx(TriggerSource), (uint32)( ((uint32)(TriggerMask) << CTU_EVTCFGR_TM_POS)|\
      ((uint32)(ClearFlag) << CLEARFLAGSHIFTVALUE) | \
      ((uint32)(CountGroup) << CTU_EVTCFGR_COUNT_GROUP_POS) | \
      ((uint32)(DelayIndex) << CTU_EVTCFGR_DELAY_INDEX_POS) | \
      (uint32)(AdcChannelID) ) ); } while(0)
#endif /* (IPV_CTU_00_00_07_02!=IPV_CTU) */

/* if !Bolero 3M (Bolero 256k-128k) and !Bolero 512K and !Bolero 1.5M */
#if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                            (IPV_CTU != IPV_CTU_00_00_03_01) && \
                            (IPV_CTU != IPV_CTU_00_00_08_02))
/**
* @brief          This macro clears the TRGIE bit in the CTU_CSR register.
* @details        Clears the TRGIE field in the CTU_CSR register in order to ack the interrupt.
*
*
* @implements
*/
  /* @violates @ref Adc_CTU_LLD_h_REF_2 Function-like macro defined */
  #define CTU_LLD_ClearTRGI() REG_BIT_SET32(CTU_CSR, CTU_CSR_TRGI)

#else /* (Bolero 3M (Bolero 256k-128k) or Bolero 512K or Bolero 1.5M) */
  /* @violates @ref Adc_CTU_LLD_h_REF_2 this violation is due to function like macros defined for register operations */
  #define CTU_LLD_ClearTRGI() do{}while(0)
#endif /* if (!defined(IPV_CTU)) || ((IPV_CTU != IPV_CTU_00_00_04_01) && \
                                     (IPV_CTU != IPV_CTU_00_00_03_01) && \
                                     (IPV_CTU != IPV_CTU_00_00_08_02)) */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/* @violates @ref Adc_CTU_LLD_h_REF_1 Repeated include file */
#include "MemMap.h"

#define ADC_STOP_SEC_CODE
/* @violates @ref Adc_CTU_LLD_h_REF_1 Repeated include file */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_CTU_LLD_H */

/** @} */
