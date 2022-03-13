/**
*   @file    SchM_Gpt.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Rte - module implementation
*   @details his module implements stubs for the AUTOSAR Rte
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : 
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

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"
#include "SchM_Gpt.h"
#ifdef MCAL_TESTING_ENVIRONMENT
#include "EUnit.h" /* EUnit Test Suite */
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ISR_ON(msr)                    (uint32)((uint32)(msr) & (uint32)(ISR_STATE_MASK)) 

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define ISR_STATE_MASK     ((uint32)0x00008000UL)   /**< @brief EE bit of MSR */

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
static uint32 msr_00;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_01;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_02;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_03;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_04;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_05;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_06;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_07;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_08;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_09;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_10;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_11;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_12;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_13;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_14;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_15;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_16;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_17;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_18;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_19;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_20;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_21;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_22;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_23;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_24;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_25;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_26;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_27;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_28;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_29;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_30;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_31;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_32;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_33;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_34;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_35;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_36;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_37;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_38;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_39;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_40;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_41;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_42;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_43;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_44;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_45;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_46;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_47;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_48;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_49;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_50;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_51;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_52;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_53;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_54;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_55;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_56;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_57;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_58;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_59;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_60;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_61;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_62;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_63;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_64;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_65;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_66;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_67;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_68;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_69;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_70;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_71;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_72;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_73;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_74;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_75;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_76;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_77;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_78;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_79;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_80;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_81;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_82;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_83;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_84;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_85;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_86;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_87;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_88;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_89;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_90;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_91;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_92;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_93;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_94;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_95;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_96;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_97;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_98;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_99;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_100;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_101;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_102;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_103;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_104;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_105;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_106;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_107;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_108;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_109;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_110;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_111;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_112;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_113;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_114;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_115;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_116;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_117;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_118;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_119;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_120;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_121;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_122;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_123;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_124;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_125;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_126;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_127;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_128;    /**< @brief exclusive area MSR state upon entering*/

static volatile uint32 reentry_guard_00 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_01 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_02 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_03 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_04 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_05 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_06 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_07 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_08 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_09 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_10 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_11 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_12 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_13 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_14 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_15 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_16 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_17 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_18 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_19 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_20 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_21 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_22 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_23 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_24 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_25 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_26 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_27 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_28 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_29 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_30 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_31 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_32 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_33 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_34 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_35 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_36 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_37 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_38 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_39 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_40 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_41 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_42 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_43 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_44 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_45 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_46 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_47 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_48 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_49 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_50 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_51 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_52 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_53 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_54 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_55 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_56 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_57 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_58 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_59 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_60 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_61 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_62 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_63 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_64 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_65 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_66 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_67 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_68 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_69 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_70 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_71 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_72 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_73 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_74 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_75 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_76 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_77 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_78 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_79 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_80 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_81 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_82 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_83 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_84 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_85 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_86 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_87 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_88 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_89 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_90 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_91 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_92 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_93 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_94 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_95 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_96 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_97 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_98 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_99 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_100 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_101 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_102 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_103 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_104 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_105 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_106 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_107 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_108 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_109 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_110 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_111 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_112 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_113 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_114 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_115 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_116 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_117 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_118 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_119 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_120 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_121 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_122 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_123 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_124 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_125 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_126 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_127 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_128 = 0; /**< @brief guard for the msr variable against overwrite*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#ifndef _COSMIC_C_MPC560XB_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
FUNC(uint32, RTE_CODE) Gpt_schm_read_msr(void); 
#endif /*ifndef _COSMIC_C_MPC560XB_*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "MemMap.h"

#if (defined(_GREENHILLS_C_MPC560XB_) || defined(_DIABDATA_C_MPC560XB_) || defined(_CODEWARRIOR_C_MPC560XB_))
/*================================================================================================*/
/** 
* @brief   This macro returns the MSR register value (32 bits). 
* @details This macro function implementation returns the MSR register value in r3 (32 bits). 
*     
* @pre  None
* @post None
* 
*/
ASM_KEYWORD FUNC(uint32, RTE_CODE) Gpt_schm_read_msr(void)
{
    mfmsr r3
}
#endif /*#ifdef GHS||DIAB||CW*/

#ifdef _COSMIC_C_MPC560XB_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
#define Gpt_schm_read_msr() ASM_KEYWORD("mfmsr r3") 

#endif  /*Cosmic compiler only*/

#ifdef _HITECH_C_MPC560XB_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
FUNC(uint32, RTE_CODE) Gpt_schm_read_msr(void)
{
    uint32 result;
    __asm volatile("mfmsr %0" : "=r" (result) :);
    return result;
}

#endif  /*HighTec compiler only*/


/*================================================================================================*/
/** 
* @brief   This function is called to allow GPT to enter the specific critical region. 
* @details This is a local function stub only. 
*     
* @param[in]     void     No input parameters
* @return        void     This function does not return anything
* 
* @pre  None
* @post None
* 
*/
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00(void)
{
        reentry_guard_00++;
        if(1UL == reentry_guard_00)
        {
           msr_00 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_00)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01(void)
{
        reentry_guard_01++;
        if(1UL == reentry_guard_01)
        {
           msr_01 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_01)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02(void)
{
        reentry_guard_02++;
        if(1UL == reentry_guard_02)
        {
           msr_02 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_02)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03(void)
{
        reentry_guard_03++;
        if(1UL == reentry_guard_03)
        {
           msr_03 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_03)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04(void)
{
        reentry_guard_04++;
        if(1UL == reentry_guard_04)
        {
           msr_04 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_04)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05(void)
{
        reentry_guard_05++;
        if(1UL == reentry_guard_05)
        {
           msr_05 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_05)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06(void)
{
        reentry_guard_06++;
        if(1UL == reentry_guard_06)
        {
           msr_06 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_06)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07(void)
{
        reentry_guard_07++;
        if(1UL == reentry_guard_07)
        {
           msr_07 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_07)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08(void)
{
        reentry_guard_08++;
        if(1UL == reentry_guard_08)
        {
           msr_08 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_08)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09(void)
{
        reentry_guard_09++;
        if(1UL == reentry_guard_09)
        {
           msr_09 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_09)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10(void)
{
        reentry_guard_10++;
        if(1UL == reentry_guard_10)
        {
           msr_10 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_10)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11(void)
{
        reentry_guard_11++;
        if(1UL == reentry_guard_11)
        {
           msr_11 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_11)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12(void)
{
        reentry_guard_12++;
        if(1UL == reentry_guard_12)
        {
           msr_12 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_12)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13(void)
{
        reentry_guard_13++;
        if(1UL == reentry_guard_13)
        {
           msr_13 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_13)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14(void)
{
        reentry_guard_14++;
        if(1UL == reentry_guard_14)
        {
           msr_14 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_14)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15(void)
{
        reentry_guard_15++;
        if(1UL == reentry_guard_15)
        {
           msr_15 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_15)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16(void)
{
        reentry_guard_16++;
        if(1UL == reentry_guard_16)
        {
           msr_16 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_16)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17(void)
{
        reentry_guard_17++;
        if(1UL == reentry_guard_17)
        {
           msr_17 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_17)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18(void)
{
        reentry_guard_18++;
        if(1UL == reentry_guard_18)
        {
           msr_18 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_18)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19(void)
{
        reentry_guard_19++;
        if(1UL == reentry_guard_19)
        {
           msr_19 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_19)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20(void)
{
        reentry_guard_20++;
        if(1UL == reentry_guard_20)
        {
           msr_20 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_20)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21(void)
{
        reentry_guard_21++;
        if(1UL == reentry_guard_21)
        {
           msr_21 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_21)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22(void)
{
        reentry_guard_22++;
        if(1UL == reentry_guard_22)
        {
           msr_22 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_22)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23(void)
{
        reentry_guard_23++;
        if(1UL == reentry_guard_23)
        {
           msr_23 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_23)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24(void)
{
        reentry_guard_24++;
        if(1UL == reentry_guard_24)
        {
           msr_24 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_24)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25(void)
{
        reentry_guard_25++;
        if(1UL == reentry_guard_25)
        {
           msr_25 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_25)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26(void)
{
        reentry_guard_26++;
        if(1UL == reentry_guard_26)
        {
           msr_26 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_26)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27(void)
{
        reentry_guard_27++;
        if(1UL == reentry_guard_27)
        {
           msr_27 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_27)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28(void)
{
        reentry_guard_28++;
        if(1UL == reentry_guard_28)
        {
           msr_28 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_28)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29(void)
{
        reentry_guard_29++;
        if(1UL == reentry_guard_29)
        {
           msr_29 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_29)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30(void)
{
        reentry_guard_30++;
        if(1UL == reentry_guard_30)
        {
           msr_30 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_30)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31(void)
{
        reentry_guard_31++;
        if(1UL == reentry_guard_31)
        {
           msr_31 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_31)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_32(void)
{
        reentry_guard_32++;
        if(1UL == reentry_guard_32)
        {
           msr_32 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_32)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_33(void)
{
        reentry_guard_33++;
        if(1UL == reentry_guard_33)
        {
           msr_33 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_33)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_34(void)
{
        reentry_guard_34++;
        if(1UL == reentry_guard_34)
        {
           msr_34 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_34)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_35(void)
{
        reentry_guard_35++;
        if(1UL == reentry_guard_35)
        {
           msr_35 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_35)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_36(void)
{
        reentry_guard_36++;
        if(1UL == reentry_guard_36)
        {
           msr_36 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_36)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_37(void)
{
        reentry_guard_37++;
        if(1UL == reentry_guard_37)
        {
           msr_37 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_37)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_38(void)
{
        reentry_guard_38++;
        if(1UL == reentry_guard_38)
        {
           msr_38 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_38)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39(void)
{
        reentry_guard_39++;
        if(1UL == reentry_guard_39)
        {
           msr_39 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_39)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_40(void)
{
        reentry_guard_40++;
        if(1UL == reentry_guard_40)
        {
           msr_40 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_40)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_41(void)
{
        reentry_guard_41++;
        if(1UL == reentry_guard_41)
        {
           msr_41 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_41)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_42(void)
{
        reentry_guard_42++;
        if(1UL == reentry_guard_42)
        {
           msr_42 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_42)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_43(void)
{
        reentry_guard_43++;
        if(1UL == reentry_guard_43)
        {
           msr_43 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_43)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_44(void)
{
        reentry_guard_44++;
        if(1UL == reentry_guard_44)
        {
           msr_44 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_44)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_45(void)
{
        reentry_guard_45++;
        if(1UL == reentry_guard_45)
        {
           msr_45 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_45)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_46(void)
{
        reentry_guard_46++;
        if(1UL == reentry_guard_46)
        {
           msr_46 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_46)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_47(void)
{
        reentry_guard_47++;
        if(1UL == reentry_guard_47)
        {
           msr_47 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_47)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_48(void)
{
        reentry_guard_48++;
        if(1UL == reentry_guard_48)
        {
           msr_48 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_48)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_49(void)
{
        reentry_guard_49++;
        if(1UL == reentry_guard_49)
        {
           msr_49 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_49)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_50(void)
{
        reentry_guard_50++;
        if(1UL == reentry_guard_50)
        {
           msr_50 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_50)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_51(void)
{
        reentry_guard_51++;
        if(1UL == reentry_guard_51)
        {
           msr_51 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_51)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_52(void)
{
        reentry_guard_52++;
        if(1UL == reentry_guard_52)
        {
           msr_52 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_52)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_53(void)
{
        reentry_guard_53++;
        if(1UL == reentry_guard_53)
        {
           msr_53 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_53)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_54(void)
{
        reentry_guard_54++;
        if(1UL == reentry_guard_54)
        {
           msr_54 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_54)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_55(void)
{
        reentry_guard_55++;
        if(1UL == reentry_guard_55)
        {
           msr_55 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_55)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_56(void)
{
        reentry_guard_56++;
        if(1UL == reentry_guard_56)
        {
           msr_56 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_56)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_57(void)
{
        reentry_guard_57++;
        if(1UL == reentry_guard_57)
        {
           msr_57 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_57)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_58(void)
{
        reentry_guard_58++;
        if(1UL == reentry_guard_58)
        {
           msr_58 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_58)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_59(void)
{
        reentry_guard_59++;
        if(1UL == reentry_guard_59)
        {
           msr_59 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_59)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_60(void)
{
        reentry_guard_60++;
        if(1UL == reentry_guard_60)
        {
           msr_60 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_60)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_61(void)
{
        reentry_guard_61++;
        if(1UL == reentry_guard_61)
        {
           msr_61 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_61)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_62(void)
{
        reentry_guard_62++;
        if(1UL == reentry_guard_62)
        {
           msr_62 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_62)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_63(void)
{
        reentry_guard_63++;
        if(1UL == reentry_guard_63)
        {
           msr_63 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_63)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_64(void)
{
        reentry_guard_64++;
        if(1UL == reentry_guard_64)
        {
           msr_64 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_64)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_65(void)
{
        reentry_guard_65++;
        if(1UL == reentry_guard_65)
        {
           msr_65 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_65)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_66(void)
{
        reentry_guard_66++;
        if(1UL == reentry_guard_66)
        {
           msr_66 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_66)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_67(void)
{
        reentry_guard_67++;
        if(1UL == reentry_guard_67)
        {
           msr_67 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_67)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_68(void)
{
        reentry_guard_68++;
        if(1UL == reentry_guard_68)
        {
           msr_68 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_68)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_69(void)
{
        reentry_guard_69++;
        if(1UL == reentry_guard_69)
        {
           msr_69 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_69)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_70(void)
{
        reentry_guard_70++;
        if(1UL == reentry_guard_70)
        {
           msr_70 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_70)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_71(void)
{
        reentry_guard_71++;
        if(1UL == reentry_guard_71)
        {
           msr_71 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_71)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_72(void)
{
        reentry_guard_72++;
        if(1UL == reentry_guard_72)
        {
           msr_72 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_72)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_73(void)
{
        reentry_guard_73++;
        if(1UL == reentry_guard_73)
        {
           msr_73 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_73)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_74(void)
{
        reentry_guard_74++;
        if(1UL == reentry_guard_74)
        {
           msr_74 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_74)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_75(void)
{
        reentry_guard_75++;
        if(1UL == reentry_guard_75)
        {
           msr_75 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_75)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_76(void)
{
        reentry_guard_76++;
        if(1UL == reentry_guard_76)
        {
           msr_76 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_76)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_77(void)
{
        reentry_guard_77++;
        if(1UL == reentry_guard_77)
        {
           msr_77 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_77)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_78(void)
{
        reentry_guard_78++;
        if(1UL == reentry_guard_78)
        {
           msr_78 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_78)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_79(void)
{
        reentry_guard_79++;
        if(1UL == reentry_guard_79)
        {
           msr_79 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_79)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_80(void)
{
        reentry_guard_80++;
        if(1UL == reentry_guard_80)
        {
           msr_80 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_80)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_81(void)
{
        reentry_guard_81++;
        if(1UL == reentry_guard_81)
        {
           msr_81 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_81)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_82(void)
{
        reentry_guard_82++;
        if(1UL == reentry_guard_82)
        {
           msr_82 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_82)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_83(void)
{
        reentry_guard_83++;
        if(1UL == reentry_guard_83)
        {
           msr_83 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_83)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_84(void)
{
        reentry_guard_84++;
        if(1UL == reentry_guard_84)
        {
           msr_84 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_84)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_85(void)
{
        reentry_guard_85++;
        if(1UL == reentry_guard_85)
        {
           msr_85 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_85)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_86(void)
{
        reentry_guard_86++;
        if(1UL == reentry_guard_86)
        {
           msr_86 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_86)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_87(void)
{
        reentry_guard_87++;
        if(1UL == reentry_guard_87)
        {
           msr_87 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_87)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_88(void)
{
        reentry_guard_88++;
        if(1UL == reentry_guard_88)
        {
           msr_88 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_88)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_89(void)
{
        reentry_guard_89++;
        if(1UL == reentry_guard_89)
        {
           msr_89 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_89)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_90(void)
{
        reentry_guard_90++;
        if(1UL == reentry_guard_90)
        {
           msr_90 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_90)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_91(void)
{
        reentry_guard_91++;
        if(1UL == reentry_guard_91)
        {
           msr_91 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_91)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_92(void)
{
        reentry_guard_92++;
        if(1UL == reentry_guard_92)
        {
           msr_92 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_92)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_93(void)
{
        reentry_guard_93++;
        if(1UL == reentry_guard_93)
        {
           msr_93 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_93)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_94(void)
{
        reentry_guard_94++;
        if(1UL == reentry_guard_94)
        {
           msr_94 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_94)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_95(void)
{
        reentry_guard_95++;
        if(1UL == reentry_guard_95)
        {
           msr_95 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_95)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_96(void)
{
        reentry_guard_96++;
        if(1UL == reentry_guard_96)
        {
           msr_96 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_96)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_97(void)
{
        reentry_guard_97++;
        if(1UL == reentry_guard_97)
        {
           msr_97 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_97)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_98(void)
{
        reentry_guard_98++;
        if(1UL == reentry_guard_98)
        {
           msr_98 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_98)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_99(void)
{
        reentry_guard_99++;
        if(1UL == reentry_guard_99)
        {
           msr_99 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_99)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_100(void)
{
        reentry_guard_100++;
        if(1UL == reentry_guard_100)
        {
           msr_100 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_100)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_101(void)
{
        reentry_guard_101++;
        if(1UL == reentry_guard_101)
        {
           msr_101 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_101)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_102(void)
{
        reentry_guard_102++;
        if(1UL == reentry_guard_102)
        {
           msr_102 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_102)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_103(void)
{
        reentry_guard_103++;
        if(1UL == reentry_guard_103)
        {
           msr_103 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_103)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_104(void)
{
        reentry_guard_104++;
        if(1UL == reentry_guard_104)
        {
           msr_104 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_104)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_105(void)
{
        reentry_guard_105++;
        if(1UL == reentry_guard_105)
        {
           msr_105 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_105)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_106(void)
{
        reentry_guard_106++;
        if(1UL == reentry_guard_106)
        {
           msr_106 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_106)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_107(void)
{
        reentry_guard_107++;
        if(1UL == reentry_guard_107)
        {
           msr_107 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_107)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_108(void)
{
        reentry_guard_108++;
        if(1UL == reentry_guard_108)
        {
           msr_108 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_108)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_109(void)
{
        reentry_guard_109++;
        if(1UL == reentry_guard_109)
        {
           msr_109 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_109)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_110(void)
{
        reentry_guard_110++;
        if(1UL == reentry_guard_110)
        {
           msr_110 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_110)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_111(void)
{
        reentry_guard_111++;
        if(1UL == reentry_guard_111)
        {
           msr_111 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_111)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_112(void)
{
        reentry_guard_112++;
        if(1UL == reentry_guard_112)
        {
           msr_112 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_112)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_113(void)
{
        reentry_guard_113++;
        if(1UL == reentry_guard_113)
        {
           msr_113 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_113)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_114(void)
{
        reentry_guard_114++;
        if(1UL == reentry_guard_114)
        {
           msr_114 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_114)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_115(void)
{
        reentry_guard_115++;
        if(1UL == reentry_guard_115)
        {
           msr_115 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_115)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_116(void)
{
        reentry_guard_116++;
        if(1UL == reentry_guard_116)
        {
           msr_116 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_116)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_117(void)
{
        reentry_guard_117++;
        if(1UL == reentry_guard_117)
        {
           msr_117 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_117)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_118(void)
{
        reentry_guard_118++;
        if(1UL == reentry_guard_118)
        {
           msr_118 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_118)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_119(void)
{
        reentry_guard_119++;
        if(1UL == reentry_guard_119)
        {
           msr_119 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_119)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_120(void)
{
        reentry_guard_120++;
        if(1UL == reentry_guard_120)
        {
           msr_120 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_120)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_121(void)
{
        reentry_guard_121++;
        if(1UL == reentry_guard_121)
        {
           msr_121 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_121)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_122(void)
{
        reentry_guard_122++;
        if(1UL == reentry_guard_122)
        {
           msr_122 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_122)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_123(void)
{
        reentry_guard_123++;
        if(1UL == reentry_guard_123)
        {
           msr_123 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_123)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_124(void)
{
        reentry_guard_124++;
        if(1UL == reentry_guard_124)
        {
           msr_124 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_124)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_125(void)
{
        reentry_guard_125++;
        if(1UL == reentry_guard_125)
        {
           msr_125 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_125)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_126(void)
{
        reentry_guard_126++;
        if(1UL == reentry_guard_126)
        {
           msr_126 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_126)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_127(void)
{
        reentry_guard_127++;
        if(1UL == reentry_guard_127)
        {
           msr_127 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_127)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
FUNC (void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_128(void)
{
        reentry_guard_128++;
        if(1UL == reentry_guard_128)
        {
           msr_128 = Gpt_schm_read_msr();  /*read MSR (to store interrupts state)*/
           if (ISR_ON(msr_128)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
           {
             SuspendAllInterrupts();
           }
        }
}
                          
/*================================================================================================*/
/** 
* @brief   This function is called to allow GPT to exit the specific critical region. 
* @details This is a local function stub only. It will resume interrupts if no other 
*          critical area is still executing.
*     
* @param[in]     void     No input parameters
* @return        void     This function does not return anything
* 
* @pre  None
* @post None
* 
*/
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00(void)
{
    reentry_guard_00--;
    if ((ISR_ON(msr_00))&&(0UL == reentry_guard_00))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01(void)
{
    reentry_guard_01--;
    if ((ISR_ON(msr_01))&&(0UL == reentry_guard_01))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02(void)
{
    reentry_guard_02--;
    if ((ISR_ON(msr_02))&&(0UL == reentry_guard_02))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03(void)
{
    reentry_guard_03--;
    if ((ISR_ON(msr_03))&&(0UL == reentry_guard_03))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04(void)
{
    reentry_guard_04--;
    if ((ISR_ON(msr_04))&&(0UL == reentry_guard_04))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05(void)
{
    reentry_guard_05--;
    if ((ISR_ON(msr_05))&&(0UL == reentry_guard_05))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06(void)
{
    reentry_guard_06--;
    if ((ISR_ON(msr_06))&&(0UL == reentry_guard_06))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07(void)
{
    reentry_guard_07--;
    if ((ISR_ON(msr_07))&&(0UL == reentry_guard_07))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08(void)
{
    reentry_guard_08--;
    if ((ISR_ON(msr_08))&&(0UL == reentry_guard_08))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09(void)
{
    reentry_guard_09--;
    if ((ISR_ON(msr_09))&&(0UL == reentry_guard_09))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10(void)
{
    reentry_guard_10--;
    if ((ISR_ON(msr_10))&&(0UL == reentry_guard_10))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11(void)
{
    reentry_guard_11--;
    if ((ISR_ON(msr_11))&&(0UL == reentry_guard_11))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12(void)
{
    reentry_guard_12--;
    if ((ISR_ON(msr_12))&&(0UL == reentry_guard_12))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13(void)
{
    reentry_guard_13--;
    if ((ISR_ON(msr_13))&&(0UL == reentry_guard_13))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14(void)
{
    reentry_guard_14--;
    if ((ISR_ON(msr_14))&&(0UL == reentry_guard_14))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15(void)
{
    reentry_guard_15--;
    if ((ISR_ON(msr_15))&&(0UL == reentry_guard_15))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16(void)
{
    reentry_guard_16--;
    if ((ISR_ON(msr_16))&&(0UL == reentry_guard_16))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17(void)
{
    reentry_guard_17--;
    if ((ISR_ON(msr_17))&&(0UL == reentry_guard_17))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18(void)
{
    reentry_guard_18--;
    if ((ISR_ON(msr_18))&&(0UL == reentry_guard_18))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19(void)
{
    reentry_guard_19--;
    if ((ISR_ON(msr_19))&&(0UL == reentry_guard_19))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20(void)
{
    reentry_guard_20--;
    if ((ISR_ON(msr_20))&&(0UL == reentry_guard_20))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21(void)
{
    reentry_guard_21--;
    if ((ISR_ON(msr_21))&&(0UL == reentry_guard_21))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22(void)
{
    reentry_guard_22--;
    if ((ISR_ON(msr_22))&&(0UL == reentry_guard_22))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23(void)
{
    reentry_guard_23--;
    if ((ISR_ON(msr_23))&&(0UL == reentry_guard_23))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24(void)
{
    reentry_guard_24--;
    if ((ISR_ON(msr_24))&&(0UL == reentry_guard_24))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25(void)
{
    reentry_guard_25--;
    if ((ISR_ON(msr_25))&&(0UL == reentry_guard_25))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26(void)
{
    reentry_guard_26--;
    if ((ISR_ON(msr_26))&&(0UL == reentry_guard_26))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27(void)
{
    reentry_guard_27--;
    if ((ISR_ON(msr_27))&&(0UL == reentry_guard_27))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28(void)
{
    reentry_guard_28--;
    if ((ISR_ON(msr_28))&&(0UL == reentry_guard_28))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29(void)
{
    reentry_guard_29--;
    if ((ISR_ON(msr_29))&&(0UL == reentry_guard_29))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30(void)
{
    reentry_guard_30--;
    if ((ISR_ON(msr_30))&&(0UL == reentry_guard_30))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31(void)
{
    reentry_guard_31--;
    if ((ISR_ON(msr_31))&&(0UL == reentry_guard_31))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_32(void)
{
    reentry_guard_32--;
    if ((ISR_ON(msr_32))&&(0UL == reentry_guard_32))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_33(void)
{
    reentry_guard_33--;
    if ((ISR_ON(msr_33))&&(0UL == reentry_guard_33))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_34(void)
{
    reentry_guard_34--;
    if ((ISR_ON(msr_34))&&(0UL == reentry_guard_34))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_35(void)
{
    reentry_guard_35--;
    if ((ISR_ON(msr_35))&&(0UL == reentry_guard_35))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_36(void)
{
    reentry_guard_36--;
    if ((ISR_ON(msr_36))&&(0UL == reentry_guard_36))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_37(void)
{
    reentry_guard_37--;
    if ((ISR_ON(msr_37))&&(0UL == reentry_guard_37))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_38(void)
{
    reentry_guard_38--;
    if ((ISR_ON(msr_38))&&(0UL == reentry_guard_38))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39(void)
{
    reentry_guard_39--;
    if ((ISR_ON(msr_39))&&(0UL == reentry_guard_39))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_40(void)
{
    reentry_guard_40--;
    if ((ISR_ON(msr_40))&&(0UL == reentry_guard_40))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_41(void)
{
    reentry_guard_41--;
    if ((ISR_ON(msr_41))&&(0UL == reentry_guard_41))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_42(void)
{
    reentry_guard_42--;
    if ((ISR_ON(msr_42))&&(0UL == reentry_guard_42))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_43(void)
{
    reentry_guard_43--;
    if ((ISR_ON(msr_43))&&(0UL == reentry_guard_43))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_44(void)
{
    reentry_guard_44--;
    if ((ISR_ON(msr_44))&&(0UL == reentry_guard_44))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_45(void)
{
    reentry_guard_45--;
    if ((ISR_ON(msr_45))&&(0UL == reentry_guard_45))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_46(void)
{
    reentry_guard_46--;
    if ((ISR_ON(msr_46))&&(0UL == reentry_guard_46))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_47(void)
{
    reentry_guard_47--;
    if ((ISR_ON(msr_47))&&(0UL == reentry_guard_47))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_48(void)
{
    reentry_guard_48--;
    if ((ISR_ON(msr_48))&&(0UL == reentry_guard_48))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_49(void)
{
    reentry_guard_49--;
    if ((ISR_ON(msr_49))&&(0UL == reentry_guard_49))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_50(void)
{
    reentry_guard_50--;
    if ((ISR_ON(msr_50))&&(0UL == reentry_guard_50))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_51(void)
{
    reentry_guard_51--;
    if ((ISR_ON(msr_51))&&(0UL == reentry_guard_51))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_52(void)
{
    reentry_guard_52--;
    if ((ISR_ON(msr_52))&&(0UL == reentry_guard_52))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_53(void)
{
    reentry_guard_53--;
    if ((ISR_ON(msr_53))&&(0UL == reentry_guard_53))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_54(void)
{
    reentry_guard_54--;
    if ((ISR_ON(msr_54))&&(0UL == reentry_guard_54))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_55(void)
{
    reentry_guard_55--;
    if ((ISR_ON(msr_55))&&(0UL == reentry_guard_55))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_56(void)
{
    reentry_guard_56--;
    if ((ISR_ON(msr_56))&&(0UL == reentry_guard_56))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_57(void)
{
    reentry_guard_57--;
    if ((ISR_ON(msr_57))&&(0UL == reentry_guard_57))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_58(void)
{
    reentry_guard_58--;
    if ((ISR_ON(msr_58))&&(0UL == reentry_guard_58))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_59(void)
{
    reentry_guard_59--;
    if ((ISR_ON(msr_59))&&(0UL == reentry_guard_59))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_60(void)
{
    reentry_guard_60--;
    if ((ISR_ON(msr_60))&&(0UL == reentry_guard_60))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_61(void)
{
    reentry_guard_61--;
    if ((ISR_ON(msr_61))&&(0UL == reentry_guard_61))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_62(void)
{
    reentry_guard_62--;
    if ((ISR_ON(msr_62))&&(0UL == reentry_guard_62))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_63(void)
{
    reentry_guard_63--;
    if ((ISR_ON(msr_63))&&(0UL == reentry_guard_63))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_64(void)
{
    reentry_guard_64--;
    if ((ISR_ON(msr_64))&&(0UL == reentry_guard_64))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_65(void)
{
        reentry_guard_65--;
        if ((ISR_ON(msr_65))&&(0UL == reentry_guard_65))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_66(void)
{
        reentry_guard_66--;
        if ((ISR_ON(msr_66))&&(0UL == reentry_guard_66))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_67(void)
{
        reentry_guard_67--;
        if ((ISR_ON(msr_67))&&(0UL == reentry_guard_67))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_68(void)
{
        reentry_guard_68--;
        if ((ISR_ON(msr_68))&&(0UL == reentry_guard_68))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_69(void)
{
        reentry_guard_69--;
        if ((ISR_ON(msr_69))&&(0UL == reentry_guard_69))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_70(void)
{
        reentry_guard_70--;
        if ((ISR_ON(msr_70))&&(0UL == reentry_guard_70))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_71(void)
{
        reentry_guard_71--;
        if ((ISR_ON(msr_71))&&(0UL == reentry_guard_71))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_72(void)
{
        reentry_guard_72--;
        if ((ISR_ON(msr_72))&&(0UL == reentry_guard_72))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_73(void)
{
        reentry_guard_73--;
        if ((ISR_ON(msr_73))&&(0UL == reentry_guard_73))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_74(void)
{
        reentry_guard_74--;
        if ((ISR_ON(msr_74))&&(0UL == reentry_guard_74))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_75(void)
{
        reentry_guard_75--;
        if ((ISR_ON(msr_75))&&(0UL == reentry_guard_75))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_76(void)
{
        reentry_guard_76--;
        if ((ISR_ON(msr_76))&&(0UL == reentry_guard_76))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_77(void)
{
        reentry_guard_77--;
        if ((ISR_ON(msr_77))&&(0UL == reentry_guard_77))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_78(void)
{
        reentry_guard_78--;
        if ((ISR_ON(msr_78))&&(0UL == reentry_guard_78))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_79(void)
{
        reentry_guard_79--;
        if ((ISR_ON(msr_79))&&(0UL == reentry_guard_79))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_80(void)
{
        reentry_guard_80--;
        if ((ISR_ON(msr_80))&&(0UL == reentry_guard_80))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_81(void)
{
        reentry_guard_81--;
        if ((ISR_ON(msr_81))&&(0UL == reentry_guard_81))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_82(void)
{
        reentry_guard_82--;
        if ((ISR_ON(msr_82))&&(0UL == reentry_guard_82))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_83(void)
{
        reentry_guard_83--;
        if ((ISR_ON(msr_83))&&(0UL == reentry_guard_83))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_84(void)
{
        reentry_guard_84--;
        if ((ISR_ON(msr_84))&&(0UL == reentry_guard_84))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_85(void)
{
        reentry_guard_85--;
        if ((ISR_ON(msr_85))&&(0UL == reentry_guard_85))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_86(void)
{
        reentry_guard_86--;
        if ((ISR_ON(msr_86))&&(0UL == reentry_guard_86))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_87(void)
{
        reentry_guard_87--;
        if ((ISR_ON(msr_87))&&(0UL == reentry_guard_87))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_88(void)
{
        reentry_guard_88--;
        if ((ISR_ON(msr_88))&&(0UL == reentry_guard_88))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_89(void)
{
        reentry_guard_89--;
        if ((ISR_ON(msr_89))&&(0UL == reentry_guard_89))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_90(void)
{
        reentry_guard_90--;
        if ((ISR_ON(msr_90))&&(0UL == reentry_guard_90))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_91(void)
{
        reentry_guard_91--;
        if ((ISR_ON(msr_91))&&(0UL == reentry_guard_91))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_92(void)
{
        reentry_guard_92--;
        if ((ISR_ON(msr_92))&&(0UL == reentry_guard_92))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_93(void)
{
        reentry_guard_93--;
        if ((ISR_ON(msr_93))&&(0UL == reentry_guard_93))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_94(void)
{
        reentry_guard_94--;
        if ((ISR_ON(msr_94))&&(0UL == reentry_guard_94))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_95(void)
{
        reentry_guard_95--;
        if ((ISR_ON(msr_95))&&(0UL == reentry_guard_95))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_96(void)
{
        reentry_guard_96--;
        if ((ISR_ON(msr_96))&&(0UL == reentry_guard_96))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_97(void)
{
        reentry_guard_97--;
        if ((ISR_ON(msr_97))&&(0UL == reentry_guard_97))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_98(void)
{
        reentry_guard_98--;
        if ((ISR_ON(msr_98))&&(0UL == reentry_guard_98))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_99(void)
{
        reentry_guard_99--;
        if ((ISR_ON(msr_99))&&(0UL == reentry_guard_99))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_100(void)
{
        reentry_guard_100--;
        if ((ISR_ON(msr_100))&&(0UL == reentry_guard_100))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_101(void)
{
        reentry_guard_101--;
        if ((ISR_ON(msr_101))&&(0UL == reentry_guard_101))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_102(void)
{
        reentry_guard_102--;
        if ((ISR_ON(msr_102))&&(0UL == reentry_guard_102))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_103(void)
{
        reentry_guard_103--;
        if ((ISR_ON(msr_103))&&(0UL == reentry_guard_103))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_104(void)
{
        reentry_guard_104--;
        if ((ISR_ON(msr_104))&&(0UL == reentry_guard_104))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_105(void)
{
        reentry_guard_105--;
        if ((ISR_ON(msr_105))&&(0UL == reentry_guard_105))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_106(void)
{
        reentry_guard_106--;
        if ((ISR_ON(msr_106))&&(0UL == reentry_guard_106))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_107(void)
{
        reentry_guard_107--;
        if ((ISR_ON(msr_107))&&(0UL == reentry_guard_107))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_108(void)
{
        reentry_guard_108--;
        if ((ISR_ON(msr_108))&&(0UL == reentry_guard_108))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_109(void)
{
        reentry_guard_109--;
        if ((ISR_ON(msr_109))&&(0UL == reentry_guard_109))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_110(void)
{
        reentry_guard_110--;
        if ((ISR_ON(msr_110))&&(0UL == reentry_guard_110))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_111(void)
{
        reentry_guard_111--;
        if ((ISR_ON(msr_111))&&(0UL == reentry_guard_111))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_112(void)
{
        reentry_guard_112--;
        if ((ISR_ON(msr_112))&&(0UL == reentry_guard_112))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_113(void)
{
        reentry_guard_113--;
        if ((ISR_ON(msr_113))&&(0UL == reentry_guard_113))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_114(void)
{
        reentry_guard_114--;
        if ((ISR_ON(msr_114))&&(0UL == reentry_guard_114))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_115(void)
{
        reentry_guard_115--;
        if ((ISR_ON(msr_115))&&(0UL == reentry_guard_115))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_116(void)
{
        reentry_guard_116--;
        if ((ISR_ON(msr_116))&&(0UL == reentry_guard_116))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_117(void)
{
        reentry_guard_117--;
        if ((ISR_ON(msr_117))&&(0UL == reentry_guard_117))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_118(void)
{
        reentry_guard_118--;
        if ((ISR_ON(msr_118))&&(0UL == reentry_guard_118))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_119(void)
{
        reentry_guard_119--;
        if ((ISR_ON(msr_119))&&(0UL == reentry_guard_119))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_120(void)
{
        reentry_guard_120--;
        if ((ISR_ON(msr_120))&&(0UL == reentry_guard_120))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_121(void)
{
        reentry_guard_121--;
        if ((ISR_ON(msr_121))&&(0UL == reentry_guard_121))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_122(void)
{
        reentry_guard_122--;
        if ((ISR_ON(msr_122))&&(0UL == reentry_guard_122))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_123(void)
{
        reentry_guard_123--;
        if ((ISR_ON(msr_123))&&(0UL == reentry_guard_123))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_124(void)
{
        reentry_guard_124--;
        if ((ISR_ON(msr_124))&&(0UL == reentry_guard_124))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_125(void)
{
        reentry_guard_125--;
        if ((ISR_ON(msr_125))&&(0UL == reentry_guard_125))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_126(void)
{
        reentry_guard_126--;
        if ((ISR_ON(msr_126))&&(0UL == reentry_guard_126))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_127(void)
{
        reentry_guard_127--;
        if ((ISR_ON(msr_127))&&(0UL == reentry_guard_127))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}
FUNC (void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_128(void)
{
        reentry_guard_128--;
        if ((ISR_ON(msr_128))&&(0UL == reentry_guard_128))         /*if interrupts were enabled*/
        {
            ResumeAllInterrupts();
        }
}

#ifdef MCAL_TESTING_ENVIRONMENT
/** 
@brief   This function checks that all entered exclusive areas were also exited. 
@details This function checks that all entered exclusive areas were also exited. The check
         is done by verifying that all reentry_guard_* static variables are back to the
         zero value.
    
@param[in]     void       No input parameters
@return        void       This function does not return a value. Test asserts are used instead. 

@pre  None
@post None

@remarks Covers 
@remarks Implements 
*/
FUNC(void, RTE_CODE) SchM_Check_gpt(void)
{
    EU_ASSERT(0UL == reentry_guard_00);
    EU_ASSERT(0UL == reentry_guard_01);
    EU_ASSERT(0UL == reentry_guard_02);
    EU_ASSERT(0UL == reentry_guard_03);
    EU_ASSERT(0UL == reentry_guard_04);
    EU_ASSERT(0UL == reentry_guard_05);
    EU_ASSERT(0UL == reentry_guard_06);
    EU_ASSERT(0UL == reentry_guard_07);
    EU_ASSERT(0UL == reentry_guard_08);
    EU_ASSERT(0UL == reentry_guard_09);
    EU_ASSERT(0UL == reentry_guard_10);
    EU_ASSERT(0UL == reentry_guard_11);
    EU_ASSERT(0UL == reentry_guard_12);
    EU_ASSERT(0UL == reentry_guard_13);
    EU_ASSERT(0UL == reentry_guard_14);
    EU_ASSERT(0UL == reentry_guard_15);
    EU_ASSERT(0UL == reentry_guard_16);
    EU_ASSERT(0UL == reentry_guard_17);
    EU_ASSERT(0UL == reentry_guard_18);
    EU_ASSERT(0UL == reentry_guard_19);
    EU_ASSERT(0UL == reentry_guard_20);
    EU_ASSERT(0UL == reentry_guard_21);
    EU_ASSERT(0UL == reentry_guard_22);
    EU_ASSERT(0UL == reentry_guard_23);
    EU_ASSERT(0UL == reentry_guard_24);
    EU_ASSERT(0UL == reentry_guard_25);
    EU_ASSERT(0UL == reentry_guard_26);
    EU_ASSERT(0UL == reentry_guard_27);
    EU_ASSERT(0UL == reentry_guard_28);
    EU_ASSERT(0UL == reentry_guard_29);
    EU_ASSERT(0UL == reentry_guard_30);
    EU_ASSERT(0UL == reentry_guard_31);
    EU_ASSERT(0UL == reentry_guard_32);
    EU_ASSERT(0UL == reentry_guard_33);
    EU_ASSERT(0UL == reentry_guard_34);
    EU_ASSERT(0UL == reentry_guard_35);
    EU_ASSERT(0UL == reentry_guard_36);
    EU_ASSERT(0UL == reentry_guard_37);
    EU_ASSERT(0UL == reentry_guard_38);
    EU_ASSERT(0UL == reentry_guard_39);
    EU_ASSERT(0UL == reentry_guard_40);
    EU_ASSERT(0UL == reentry_guard_41);
    EU_ASSERT(0UL == reentry_guard_42);
    EU_ASSERT(0UL == reentry_guard_43);
    EU_ASSERT(0UL == reentry_guard_44);
    EU_ASSERT(0UL == reentry_guard_45);
    EU_ASSERT(0UL == reentry_guard_46);
    EU_ASSERT(0UL == reentry_guard_47);
    EU_ASSERT(0UL == reentry_guard_48);
    EU_ASSERT(0UL == reentry_guard_49);
    EU_ASSERT(0UL == reentry_guard_50);
    EU_ASSERT(0UL == reentry_guard_51);
    EU_ASSERT(0UL == reentry_guard_52);
    EU_ASSERT(0UL == reentry_guard_53);
    EU_ASSERT(0UL == reentry_guard_54);
    EU_ASSERT(0UL == reentry_guard_55);
    EU_ASSERT(0UL == reentry_guard_56);
    EU_ASSERT(0UL == reentry_guard_57);
    EU_ASSERT(0UL == reentry_guard_58);
    EU_ASSERT(0UL == reentry_guard_59);
    EU_ASSERT(0UL == reentry_guard_60);
    EU_ASSERT(0UL == reentry_guard_61);
    EU_ASSERT(0UL == reentry_guard_62);
    EU_ASSERT(0UL == reentry_guard_63);
    EU_ASSERT(0UL == reentry_guard_64);
    EU_ASSERT(0UL == reentry_guard_65)
    EU_ASSERT(0UL == reentry_guard_66)
    EU_ASSERT(0UL == reentry_guard_67)
    EU_ASSERT(0UL == reentry_guard_68)
    EU_ASSERT(0UL == reentry_guard_69)
    EU_ASSERT(0UL == reentry_guard_70)
    EU_ASSERT(0UL == reentry_guard_71)
    EU_ASSERT(0UL == reentry_guard_72)
    EU_ASSERT(0UL == reentry_guard_73)
    EU_ASSERT(0UL == reentry_guard_74)
    EU_ASSERT(0UL == reentry_guard_75)
    EU_ASSERT(0UL == reentry_guard_76)
    EU_ASSERT(0UL == reentry_guard_77)
    EU_ASSERT(0UL == reentry_guard_78)
    EU_ASSERT(0UL == reentry_guard_79)
    EU_ASSERT(0UL == reentry_guard_80)
    EU_ASSERT(0UL == reentry_guard_81)
    EU_ASSERT(0UL == reentry_guard_82)
    EU_ASSERT(0UL == reentry_guard_83)
    EU_ASSERT(0UL == reentry_guard_84)
    EU_ASSERT(0UL == reentry_guard_85)
    EU_ASSERT(0UL == reentry_guard_86)
    EU_ASSERT(0UL == reentry_guard_87)
    EU_ASSERT(0UL == reentry_guard_88)
    EU_ASSERT(0UL == reentry_guard_89)
    EU_ASSERT(0UL == reentry_guard_90)
    EU_ASSERT(0UL == reentry_guard_91)
    EU_ASSERT(0UL == reentry_guard_92)
    EU_ASSERT(0UL == reentry_guard_93)
    EU_ASSERT(0UL == reentry_guard_94)
    EU_ASSERT(0UL == reentry_guard_95)
    EU_ASSERT(0UL == reentry_guard_96)
    EU_ASSERT(0UL == reentry_guard_97)
    EU_ASSERT(0UL == reentry_guard_98)
    EU_ASSERT(0UL == reentry_guard_99)
    EU_ASSERT(0UL == reentry_guard_100)
    EU_ASSERT(0UL == reentry_guard_101)
    EU_ASSERT(0UL == reentry_guard_102)
    EU_ASSERT(0UL == reentry_guard_103)
    EU_ASSERT(0UL == reentry_guard_104)
    EU_ASSERT(0UL == reentry_guard_105)
    EU_ASSERT(0UL == reentry_guard_106)
    EU_ASSERT(0UL == reentry_guard_107)
    EU_ASSERT(0UL == reentry_guard_108)
    EU_ASSERT(0UL == reentry_guard_109)
    EU_ASSERT(0UL == reentry_guard_110)
    EU_ASSERT(0UL == reentry_guard_111)
    EU_ASSERT(0UL == reentry_guard_112)
    EU_ASSERT(0UL == reentry_guard_113)
    EU_ASSERT(0UL == reentry_guard_114)
    EU_ASSERT(0UL == reentry_guard_115)
    EU_ASSERT(0UL == reentry_guard_116)
    EU_ASSERT(0UL == reentry_guard_117)
    EU_ASSERT(0UL == reentry_guard_118)
    EU_ASSERT(0UL == reentry_guard_119)
    EU_ASSERT(0UL == reentry_guard_120)
    EU_ASSERT(0UL == reentry_guard_121)
    EU_ASSERT(0UL == reentry_guard_122)
    EU_ASSERT(0UL == reentry_guard_123)
    EU_ASSERT(0UL == reentry_guard_124)
    EU_ASSERT(0UL == reentry_guard_125)
    EU_ASSERT(0UL == reentry_guard_126)
    EU_ASSERT(0UL == reentry_guard_127)
    EU_ASSERT(0UL == reentry_guard_128)

    reentry_guard_00 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_01 = 0UL; /*reset reentry_guard_01 for the next test in the suite*/
    reentry_guard_02 = 0UL; /*reset reentry_guard_02 for the next test in the suite*/
    reentry_guard_03 = 0UL; /*reset reentry_guard_03 for the next test in the suite*/
    reentry_guard_04 = 0UL; /*reset reentry_guard_04 for the next test in the suite*/
    reentry_guard_05 = 0UL; /*reset reentry_guard_05 for the next test in the suite*/
    reentry_guard_06 = 0UL; /*reset reentry_guard_06 for the next test in the suite*/
    reentry_guard_07 = 0UL; /*reset reentry_guard_07 for the next test in the suite*/
    reentry_guard_08 = 0UL; /*reset reentry_guard_08 for the next test in the suite*/
    reentry_guard_09 = 0UL; /*reset reentry_guard_09 for the next test in the suite*/
    reentry_guard_10 = 0UL; /*reset reentry_guard_10 for the next test in the suite*/
    reentry_guard_11 = 0UL; /*reset reentry_guard_11 for the next test in the suite*/
    reentry_guard_12 = 0UL; /*reset reentry_guard_12 for the next test in the suite*/
    reentry_guard_13 = 0UL; /*reset reentry_guard_13 for the next test in the suite*/
    reentry_guard_14 = 0UL; /*reset reentry_guard_14 for the next test in the suite*/
    reentry_guard_15 = 0UL; /*reset reentry_guard_15 for the next test in the suite*/
    reentry_guard_16 = 0UL; /*reset reentry_guard_16 for the next test in the suite*/
    reentry_guard_17 = 0UL; /*reset reentry_guard_17 for the next test in the suite*/
    reentry_guard_18 = 0UL; /*reset reentry_guard_18 for the next test in the suite*/
    reentry_guard_19 = 0UL; /*reset reentry_guard_19 for the next test in the suite*/
    reentry_guard_20 = 0UL; /*reset reentry_guard_20 for the next test in the suite*/
    reentry_guard_21 = 0UL; /*reset reentry_guard_21 for the next test in the suite*/
    reentry_guard_22 = 0UL; /*reset reentry_guard_22 for the next test in the suite*/
    reentry_guard_23 = 0UL; /*reset reentry_guard_23 for the next test in the suite*/
    reentry_guard_24 = 0UL; /*reset reentry_guard_24 for the next test in the suite*/
    reentry_guard_25 = 0UL; /*reset reentry_guard_25 for the next test in the suite*/
    reentry_guard_26 = 0UL; /*reset reentry_guard_26 for the next test in the suite*/
    reentry_guard_27 = 0UL; /*reset reentry_guard_27 for the next test in the suite*/
    reentry_guard_28 = 0UL; /*reset reentry_guard_28 for the next test in the suite*/
    reentry_guard_29 = 0UL; /*reset reentry_guard_29 for the next test in the suite*/
    reentry_guard_30 = 0UL; /*reset reentry_guard_30 for the next test in the suite*/
    reentry_guard_31 = 0UL; /*reset reentry_guard_31 for the next test in the suite*/
    reentry_guard_32 = 0UL; /*reset reentry_guard_32 for the next test in the suite*/
    reentry_guard_33 = 0UL; /*reset reentry_guard_33 for the next test in the suite*/
    reentry_guard_34 = 0UL; /*reset reentry_guard_34 for the next test in the suite*/
    reentry_guard_35 = 0UL; /*reset reentry_guard_35 for the next test in the suite*/
    reentry_guard_36 = 0UL; /*reset reentry_guard_36 for the next test in the suite*/
    reentry_guard_37 = 0UL; /*reset reentry_guard_37 for the next test in the suite*/
    reentry_guard_38 = 0UL; /*reset reentry_guard_38 for the next test in the suite*/
    reentry_guard_39 = 0UL; /*reset reentry_guard_39 for the next test in the suite*/
    reentry_guard_40 = 0UL; /*reset reentry_guard_40 for the next test in the suite*/
    reentry_guard_41 = 0UL; /*reset reentry_guard_41 for the next test in the suite*/
    reentry_guard_42 = 0UL; /*reset reentry_guard_42 for the next test in the suite*/
    reentry_guard_43 = 0UL; /*reset reentry_guard_43 for the next test in the suite*/
    reentry_guard_44 = 0UL; /*reset reentry_guard_44 for the next test in the suite*/
    reentry_guard_45 = 0UL; /*reset reentry_guard_45 for the next test in the suite*/
    reentry_guard_46 = 0UL; /*reset reentry_guard_46 for the next test in the suite*/
    reentry_guard_47 = 0UL; /*reset reentry_guard_47 for the next test in the suite*/
    reentry_guard_48 = 0UL; /*reset reentry_guard_48 for the next test in the suite*/
    reentry_guard_49 = 0UL; /*reset reentry_guard_49 for the next test in the suite*/
    reentry_guard_50 = 0UL; /*reset reentry_guard_50 for the next test in the suite*/
    reentry_guard_51 = 0UL; /*reset reentry_guard_51 for the next test in the suite*/
    reentry_guard_52 = 0UL; /*reset reentry_guard_52 for the next test in the suite*/
    reentry_guard_53 = 0UL; /*reset reentry_guard_53 for the next test in the suite*/
    reentry_guard_54 = 0UL; /*reset reentry_guard_54 for the next test in the suite*/
    reentry_guard_55 = 0UL; /*reset reentry_guard_55 for the next test in the suite*/
    reentry_guard_56 = 0UL; /*reset reentry_guard_56 for the next test in the suite*/
    reentry_guard_57 = 0UL; /*reset reentry_guard_57 for the next test in the suite*/
    reentry_guard_58 = 0UL; /*reset reentry_guard_58 for the next test in the suite*/
    reentry_guard_59 = 0UL; /*reset reentry_guard_59 for the next test in the suite*/
    reentry_guard_60 = 0UL; /*reset reentry_guard_60 for the next test in the suite*/
    reentry_guard_61 = 0UL; /*reset reentry_guard_61 for the next test in the suite*/
    reentry_guard_62 = 0UL; /*reset reentry_guard_62 for the next test in the suite*/
    reentry_guard_63 = 0UL; /*reset reentry_guard_63 for the next test in the suite*/
    reentry_guard_64 = 0UL; /*reset reentry_guard_64 for the next test in the suite*/
    reentry_guard_65 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_66 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_67 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_68 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_69 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_70 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_71 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_72 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_73 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_74 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_75 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_76 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_77 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_78 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_79 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_80 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_81 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_82 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_83 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_84 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_85 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_86 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_87 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_88 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_89 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_90 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_91 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_92 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_93 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_94 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_95 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_96 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_97 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_98 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_99 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_100 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_101 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_102 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_103 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_104 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_105 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_106 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_107 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_108 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_109 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_110 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_111 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_112 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_113 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_114 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_115 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_116 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_117 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_118 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_119 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_120 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_121 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_122 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_123 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_124 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_125 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_126 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_127 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
    reentry_guard_128 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/

}
#endif /*MCAL_TESTING_ENVIRONMENT*/

#define RTE_STOP_SEC_CODE
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
