/**
*   @file    SchM_Gpt.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Rte - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Rte.
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

#ifndef SCHM_GPT_H
#define SCHM_GPT_H

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
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
FUNC(void, RTE_CODE) SchM_Check_gpt(void);
#endif /*MCAL_TESTING_ENVIRONMENT*/

extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_32(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_33(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_34(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_35(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_36(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_37(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_38(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_39(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_40(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_41(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_42(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_43(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_44(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_45(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_46(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_47(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_48(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_49(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_50(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_51(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_52(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_53(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_54(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_55(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_56(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_57(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_58(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_59(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_60(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_61(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_62(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_63(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_64(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_65(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_66(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_67(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_68(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_69(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_70(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_71(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_72(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_73(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_74(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_75(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_76(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_77(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_78(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_79(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_80(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_81(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_82(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_83(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_84(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_85(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_86(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_87(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_88(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_89(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_90(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_91(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_92(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_93(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_94(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_95(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_96(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_97(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_98(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_99(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_100(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_101(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_102(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_103(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_104(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_105(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_106(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_107(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_108(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_109(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_110(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_111(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_112(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_113(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_114(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_115(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_116(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_117(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_118(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_119(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_120(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_121(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_122(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_123(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_124(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_125(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_126(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_127(void);
extern FUNC(void, RTE_CODE) SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_128(void);

extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_32(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_33(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_34(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_35(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_36(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_37(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_38(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_39(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_40(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_41(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_42(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_43(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_44(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_45(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_46(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_47(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_48(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_49(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_50(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_51(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_52(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_53(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_54(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_55(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_56(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_57(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_58(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_59(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_60(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_61(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_62(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_63(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_64(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_65(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_66(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_67(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_68(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_69(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_70(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_71(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_72(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_73(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_74(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_75(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_76(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_77(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_78(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_79(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_80(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_81(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_82(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_83(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_84(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_85(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_86(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_87(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_88(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_89(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_90(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_91(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_92(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_93(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_94(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_95(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_96(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_97(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_98(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_99(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_100(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_101(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_102(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_103(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_104(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_105(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_106(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_107(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_108(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_109(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_110(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_111(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_112(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_113(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_114(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_115(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_116(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_117(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_118(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_119(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_120(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_121(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_122(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_123(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_124(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_125(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_126(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_127(void);
extern FUNC(void, RTE_CODE) SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_128(void);


#ifdef __cplusplus
}
#endif

#endif /* SCHM_GPT_H */

/** @} */
