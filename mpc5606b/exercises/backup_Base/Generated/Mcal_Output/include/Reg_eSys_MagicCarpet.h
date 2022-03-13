/**
*   @file    Reg_eSys_MagicCarpet.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Defines used to access the MC registers.
*   @details This file contains the defines used by the driver to access the MC registers.
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

#ifndef REG_ESYS_MAGICCARPET_H
#define Reg_ESYS_MAGICCARPET_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_MagicCarpet_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_MagicCarpet_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Reg_eSys_MagicCarpet_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* This is for better readablity.
*
* @section Reg_eSys_MagicCarpet_h_REF_4
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/**************************** MC_CGM Memory Map ******************************/

#define MC_CGM_XOSC_CTL_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0000UL))
#define MC_CGM_OSC_CTL_R                    ((uint32)(MC_CGM_BASEADDR+ (uint32)0x0040UL))
#define MC_CGM_RC_CTL_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x0060UL))
#define MC_CGM_RC_CTL_R_L                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0062UL))
#define MC_CGM_LPRC_CTL_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0080UL))
#define MC_CGM_LPRC_CTL_R_L                 ((uint32)(MC_CGM_BASEADDR+(uint32)0x0082UL))
#define MC_CGM_PLL0_CR_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x00A0UL))
#define MC_CGM_PLL0_MR_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x00A4UL))

#define MC_CGM_PLL1_CR_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x00C0UL))
#define MC_CGM_PLL1_MR_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x00C4UL))

#define MC_CGM_CMU0_CSR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0100UL))
#define MC_CGM_CMU0_FDR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0104UL))
#define MC_CGM_CMU0_HFREFR_R                ((uint32)(MC_CGM_BASEADDR+(uint32)0x0108UL))
#define MC_CGM_CMU0_LFREFR_R                ((uint32)(MC_CGM_BASEADDR+(uint32)0x010CUL))
#define MC_CGM_CMU0_ISR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0110UL))
#define MC_CGM_CMU0_IMR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0114UL))
#define MC_CGM_CMU0_MDR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0118UL))

#define MC_CGM_CMU1_CSR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0120UL))
#define MC_CGM_CMU1_FDR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0124UL))
#define MC_CGM_CMU1_HFREFR_R                ((uint32)(MC_CGM_BASEADDR+(uint32)0x0128UL))
#define MC_CGM_CMU1_LFREFR_R                ((uint32)(MC_CGM_BASEADDR+(uint32)0x012CUL))
#define MC_CGM_CMU1_ISR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0130UL))
#define MC_CGM_CMU1_IMR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0134UL))
#define MC_CGM_CMU1_MDR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0138UL))
#define MC_CGM_CMU2_CSR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0140UL))
#define MC_CGM_CMU2_FDR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0144UL))
#define MC_CGM_CMU2_HFREFR_R                ((uint32)(MC_CGM_BASEADDR+(uint32)0x0148UL))
#define MC_CGM_CMU2_LFREFR_R                ((uint32)(MC_CGM_BASEADDR+(uint32)0x014CUL))
#define MC_CGM_CMU2_ISR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0150UL))
#define MC_CGM_CMU2_IMR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0154UL))
#define MC_CGM_CMU2_MDR_R                   ((uint32)(MC_CGM_BASEADDR+(uint32)0x0158UL))

#define MC_CGM_OC_EN_R                      ((uint32)(MC_CGM_BASEADDR+(uint32)0x0370UL))
#define MC_CGM_OCDS_SC_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x0374UL))

#define MC_CGM_SC_SS_R                      ((uint32)(MC_CGM_BASEADDR+(uint32)0x0378UL))

#define MC_CGM_Z0_DCR_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x00C0UL))
#define MC_CGM_FEC_DCR_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x00E0UL))
#define MC_CGM_FLASH_DCR_R                  ((uint32)(MC_CGM_BASEADDR+(uint32)0x0120UL))

#define MC_CGM_SC_DC0_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x037CUL))
#define MC_CGM_SC_DC1_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x037DUL))
#define MC_CGM_SC_DC2_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x037EUL))

#define MC_CGM_AC0_SC_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x0380UL))
#define MC_CGM_AC0_DC0_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x0384UL))
#define MC_CGM_AC0_DC1_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x0385UL))

#define MC_CGM_AC1_SC_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x0388UL))
#define MC_CGM_AC1_DC0_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x038CUL))

#define MC_CGM_AC2_SC_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x0390UL))
#define MC_CGM_AC2_DC0_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x0394UL))

#define MC_CGM_AC3_SC_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x0398UL))
#define MC_CGM_AC3_DC0_R                    ((uint32)(MC_CGM_BASEADDR+(uint32)0x039CUL))

#define MC_CGM_AC4_SC_R                     ((uint32)(MC_CGM_BASEADDR+(uint32)0x03A0UL))
/**************************** MC_ME Memory Map ******************************/

#define MC_ME_GS_R                         ((uint32)(MC_ME_BASEADDR+(uint32)0x0000UL))
#define MC_ME_MCTL_R                       ((uint32)(MC_ME_BASEADDR+(uint32)0x0004UL))
#define MC_ME_ME_R                         ((uint32)(MC_ME_BASEADDR+(uint32)0x0008UL))
#define MC_ME_IS_R                         ((uint32)(MC_ME_BASEADDR+(uint32)0x000CUL))
#define MC_ME_IM_R                         ((uint32)(MC_ME_BASEADDR+(uint32)0x0010UL))
#define MC_ME_IMTS_R                       ((uint32)(MC_ME_BASEADDR+(uint32)0x0014UL))

#define MC_ME_RESET_MC_R                   ((uint32)(MC_ME_BASEADDR+(uint32)0x0020UL))
#define MC_ME_TEST_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0024UL))
#define MC_ME_SAFE_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0028UL))
#define MC_ME_DRUN_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x002CUL))
#define MC_ME_RUN0_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0030UL))
#define MC_ME_RUN1_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0034UL))
#define MC_ME_RUN2_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0038UL))
#define MC_ME_RUN3_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x003CUL))
#define MC_ME_HALT_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0040UL))
#define MC_ME_STOP_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0048UL))
#define MC_ME_STBY_MC_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0054UL))

#define MC_ME_PS0_R                        ((uint32)(MC_ME_BASEADDR+(uint32)0x0060UL))
#define MC_ME_PS1_R                        ((uint32)(MC_ME_BASEADDR+(uint32)0x0064UL))
#define MC_ME_PS2_R                        ((uint32)(MC_ME_BASEADDR+(uint32)0x0068UL))
#define MC_ME_PS3_R                        ((uint32)(MC_ME_BASEADDR+(uint32)0x006CUL))

#define MC_ME_RUN_PC0_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0080UL))
#define MC_ME_RUN_PC1_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0084UL))
#define MC_ME_RUN_PC2_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0088UL))
#define MC_ME_RUN_PC3_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x008CUL))
#define MC_ME_RUN_PC4_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0090UL))
#define MC_ME_RUN_PC5_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0094UL))
#define MC_ME_RUN_PC6_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0098UL))
#define MC_ME_RUN_PC7_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x009CUL))

#define MC_ME_LP_PC0_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00A0UL))
#define MC_ME_LP_PC1_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00A4UL))
#define MC_ME_LP_PC2_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00A8UL))
#define MC_ME_LP_PC3_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00ACUL))
#define MC_ME_LP_PC4_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00B0UL))
#define MC_ME_LP_PC5_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00B4UL))
#define MC_ME_LP_PC6_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00B8UL))
#define MC_ME_LP_PC7_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00BCUL))

#define MC_ME_PCTL4_R                      ((uint32)(MC_ME_BASEADDR+(uint32)0x00C4UL))
#define MC_ME_PCTL5_R                      ((uint32)(MC_ME_BASEADDR+(uint32)0x00C5UL))
#define MC_ME_PCTL6_R                      ((uint32)(MC_ME_BASEADDR+(uint32)0x00C6UL))
#define MC_ME_PCTL7_R                      ((uint32)(MC_ME_BASEADDR+(uint32)0x00C7UL))
#define MC_ME_PCTL8_R                      ((uint32)(MC_ME_BASEADDR+(uint32)0x00C8UL))
#define MC_ME_PCTL9_R                      ((uint32)(MC_ME_BASEADDR+(uint32)0x00C9UL))
#define MC_ME_PCTL10_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00CAUL))
#define MC_ME_PCTL11_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00CBUL))
#define MC_ME_PCTL12_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00CCUL))
#define MC_ME_PCTL13_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00CDUL))
#define MC_ME_PCTL16_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D0UL))
#define MC_ME_PCTL17_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D1UL))
#define MC_ME_PCTL18_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D2UL))
#define MC_ME_PCTL19_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D3UL))
#define MC_ME_PCTL20_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D4UL))
#define MC_ME_PCTL21_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D5UL))
#define MC_ME_PCTL23_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D7UL))
#define MC_ME_PCTL24_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00D8UL))
#define MC_ME_PCTL26_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00DAUL))
#define MC_ME_PCTL31_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00DFUL))
#define MC_ME_PCTL32_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E0UL))
#define MC_ME_PCTL33_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E1UL))
#define MC_ME_PCTL34_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E2UL))
#define MC_ME_PCTL35_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E3UL))
#define MC_ME_PCTL36_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E4UL))
#define MC_ME_PCTL37_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E5UL))
#define MC_ME_PCTL38_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E6UL))
#define MC_ME_PCTL39_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E7UL))
#define MC_ME_PCTL40_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E8UL))
#define MC_ME_PCTL41_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00E9UL))
#define MC_ME_PCTL42_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00EAUL))
#define MC_ME_PCTL43_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00EBUL))
#define MC_ME_PCTL44_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00ECUL))
#define MC_ME_PCTL45_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00EDUL))
#define MC_ME_PCTL46_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00EEUL))
#define MC_ME_PCTL47_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00EFUL))
#define MC_ME_PCTL48_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F0UL))
#define MC_ME_PCTL49_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F1UL))
#define MC_ME_PCTL50_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F2UL))
#define MC_ME_PCTL51_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F3UL))
#define MC_ME_PCTL52_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F4UL))
#define MC_ME_PCTL53_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F5UL))
#define MC_ME_PCTL54_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F6UL))
#define MC_ME_PCTL55_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F7UL))
#define MC_ME_PCTL56_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F8UL))
#define MC_ME_PCTL57_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00F9UL))
#define MC_ME_PCTL58_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00FAUL))
#define MC_ME_PCTL59_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00FBUL))
#define MC_ME_PCTL60_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00FCUL))
#define MC_ME_PCTL61_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00FDUL))
#define MC_ME_PCTL62_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00FEUL))
#define MC_ME_PCTL63_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x00FFUL))
#define MC_ME_PCTL64_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0100UL))
#define MC_ME_PCTL65_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0101UL))
#define MC_ME_PCTL66_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0102UL))
#define MC_ME_PCTL67_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0103UL))
#define MC_ME_PCTL68_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0104UL))
#define MC_ME_PCTL69_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0105UL))
#define MC_ME_PCTL70_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0106UL))
#define MC_ME_PCTL72_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0108UL))
#define MC_ME_PCTL73_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0109UL))
#define MC_ME_PCTL76_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x010CUL))
#define MC_ME_PCTL86_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0116UL))
#define MC_ME_PCTL87_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0117UL))
#define MC_ME_PCTL88_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0118UL))
#define MC_ME_PCTL89_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0119UL))
#define MC_ME_PCTL90_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x011AUL))
#define MC_ME_PCTL91_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x011BUL))
#define MC_ME_PCTL92_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x011CUL))
#define MC_ME_PCTL96_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0120UL))
#define MC_ME_PCTL98_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0122UL))
#define MC_ME_PCTL99_R                     ((uint32)(MC_ME_BASEADDR+(uint32)0x0123UL))
#define MC_ME_PCTL100_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0124UL))
#define MC_ME_PCTL101_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0125UL))
#define MC_ME_PCTL104_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x0128UL))
#define MC_ME_PCTL112_R                       (MC_ME_BASEADDR+(uint32)0x0130UL)
#define MC_ME_PCTL116_R                      (MC_ME_BASEADDR+(uint32)0x0134UL)
#define MC_ME_PCTL117_R                       (MC_ME_BASEADDR+(uint32)0x0135UL)
#define MC_ME_PCTL119_R                       (MC_ME_BASEADDR+(uint32)0x0137UL)
#define MC_ME_PCTL120_R                      (MC_ME_BASEADDR+(uint32)0x0138UL)
#define MC_ME_PCTL125_R                       (MC_ME_BASEADDR+(uint32)0x013DUL)
#define MC_ME_PCTL127_R                    ((uint32)(MC_ME_BASEADDR+(uint32)0x013FUL))

/**************************** MC_RGM Memory Map ******************************/

#define MC_RGM_FES_R                        ((uint32)(MC_RGM_BASEADDR+(uint32)0x0000UL))
#define MC_RGM_DES_R                        ((uint32)(MC_RGM_BASEADDR+(uint32)0x0002UL))
#define MC_RGM_FERD_R                       ((uint32)(MC_RGM_BASEADDR+(uint32)0x0004UL))
#define MC_RGM_DERD_R                       ((uint32)(MC_RGM_BASEADDR+(uint32)0x0006UL))
#define MC_RGM_FEAR_R                       ((uint32)(MC_RGM_BASEADDR+(uint32)0x0010UL))
#define MC_RGM_DEAR_R                       ((uint32)(MC_RGM_BASEADDR+(uint32)0x0012UL))
#define MC_RGM_FESS_R                       ((uint32)(MC_RGM_BASEADDR+(uint32)0x0018UL))
#define MC_RGM_STDBY_R                      ((uint32)(MC_RGM_BASEADDR+(uint32)0x001AUL))
#define MC_RGM_FBRE_R                       ((uint32)(MC_RGM_BASEADDR+(uint32)0x001CUL))

/**************************** MC_PCU Memory Map ******************************/

#define MC_PCU_PCONF0_R                     ((uint32)(MC_PCU_BASEADDR+(uint32)0x0000UL))
#define MC_PCU_PCONF1_R                     ((uint32)(MC_PCU_BASEADDR+(uint32)0x0004UL))
#define MC_PCU_PCONF2_R                     ((uint32)(MC_PCU_BASEADDR+(uint32)0x0008UL))
#define MC_PCU_PSTAT_R                      ((uint32)(MC_PCU_BASEADDR+(uint32)0x0040UL))



/***************************************************************************/
/* User Defines */
#define STATUS_FLAG_READ                            ((uint32)0x1)
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined  
                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define STATUS_BITS_READ(type, value, shift)        ((type)(((type)value)<<shift))
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
                   /*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define PUT_VALUE_ON_REG(type, value, shift)        ((type)(((type)value)<<shift))

/******************************************************************************/
/*                                CLOCK OUT                                   */
/******************************************************************************/
/* Output Clock Division Select Register (CGM_OCDS_SC)*/
/* SELDIV field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CLOCK_OUT_DIV(x)                   ((uint32)(((uint32)x)<<28))
#define CLOCK_OUT_DIV_MASK                 ((uint32)(((uint32)0x3U)<<28))

#define CLOCK_OUT_NO_DIV                   0
#define CLOCK_OUT_2_DIV                    1
#define CLOCK_OUT_4_DIV                    2
#define CLOCK_OUT_8_DIV                    3

/* SELCTL field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CLOCK_OUT_SOURCE(x)                ((uint32)(((uint32)x)<<24))

#define CLOCK_OUT_SOURCE_RC                (1UL)

#define CLOCK_OUT_SOURCE_XOSC              (0UL)

#define RUN_MODE_CONFIG                   ((uint32)0xFFFFFF90UL)

#define CLOCK_OUT_SOURCE_PLL0              (2UL)

#define CLOCK_OUT_SOURCE_PLL1              (3UL)

#define CLOCK_OUT_SOURCE_LPRC              (4UL)

#define CLOCK_OUT_SOURCE_LPXOSC            (5UL)

#define CLOCK_OUT_SOURCE_PLLPHI            (5UL)

#define CLOCK_OUT_SOURCE_RTCCLK            (4UL)

#define CLOCK_OUT_SOURCE_SYSCLK            (3UL)

#define CLOCK_OUT_SOURCE_MASK              ((uint32)(((uint32)0xFU)<<24))

/* Output Clock Enable Register (CGM_OC_EN) */
/* EN field */
#define CLOCK_OUT_ENABLE                   ((uint32)(((uint32)1)<<0))
#define CLOCK_OUT_DISABLE                  ((uint32)(((uint32)0)<<0))

#define CLOCK_OUT_MASK                     (CLOCK_OUT_SOURCE_MASK|CLOCK_OUT_DIV_MASK)

/******************************************************************************/
/*                  AUXILIARY CLOCK 0                                         */
/******************************************************************************/
/* Auxiliary Clock 0 Select Control Register (CGM_AC0_SC) */
/* SELCTL field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_0(x)                       ((uint32)(((uint32)x)<<24))
#define AUX_CLK_0_RC                       0
#define AUX_CLK_0_XOSC                     2
#define AUX_CLK_0_PLL0                     4
#define AUX_CLK_0_PLL1_120                 5
#define AUX_CLK_0_PLL1_80                  8
#define AUX_CLK_0_MASK                     ((uint32)(((uint32)0xF)<<24))

/* Auxiliary Clock 0 Div Configuration Register (CGM_AC1_DC0) */
/* DIV0 field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_00_DIV(x)                  ((uint8)(((uint8)((uint8)x-(uint8)1))<<0))
/* Auxiliary Clock 0 Div Configuration Register (CGM_AC1_DC1) */
/* DIV0 field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_01_DIV(x)                  ((uint8)(((uint8)((uint8)x-(uint8)1))<<0))

/* DE0 field */
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ENABLE_AUX_CLK_0                   ((uint8)(((uint8)1)<<7))
#define DISABLE_AUX_CLK_0                  ((uint8)(((uint8)0)<<7))

/* DE1 field */
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ENABLE_AUX_CLK_01                  ((uint8)(((uint8)1)<<7))
#define DISABLE_AUX_CLK_01                 ((uint8)(((uint8)0)<<7))
/******************************************************************************/
/*                                                       AUXILIARY CLOCK 1                                                                                 */
/******************************************************************************/
/* Auxiliary Clock 1 Select Control Register (CGM_AC1_SC) */
/* SELCTL field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_1(x)                       ((uint32)(((uint32)x)<<24))
#define AUX_CLK_1_PLL0                     4
#define AUX_CLK_1_PLL1_120                 5
#define AUX_CLK_1_PLL1_80                  8

#define AUX_CLK_1_MASK                     ((uint32)(((uint32)0xF)<<24))

/* Auxiliary Clock 1 Div Configuration Register (CGM_AC1_DC0) */
/* DIV0 field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_1_DIV(x)                   ((uint8)(((uint8)((uint8)x-(uint8)1))<<0))

/* DE0 field */
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ENABLE_AUX_CLK_1                   ((uint8)(((uint8)1)<<7))
#define DISABLE_AUX_CLK_1                  ((uint8)(((uint8)0)<<7))
/******************************************************************************/
/*                                                       AUXILIARY CLOCK 2                                                                                 */
/******************************************************************************/
/* Auxiliary Clock 2 Select Control Register (CGM_AC2_SC) */
/* SELCTL field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_2(x)                       ((uint32)(((uint32)x)<<24))
#define AUX_CLK_2_RC                       0
#define AUX_CLK_2_XOSC                     2
#define AUX_CLK_2_PLL0                     4
#define AUX_CLK_2_PLL1_120                 5
#define AUX_CLK_2_PLL1_80                  8
#define AUX_CLK_2_MASK                     ((uint32)(((uint32)0xF)<<24))
/* Auxiliary Clock 2 Div Configuration Register (CGM_AC2_DC0) */
/* DIV0 field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_2_DIV(x)                   ((uint8)(((uint8)((uint8)x-(uint8)1))<<0))

/* DE0 field */
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ENABLE_AUX_CLK_2                   ((uint8)(((uint8)1)<<7))
#define DISABLE_AUX_CLK_2                  ((uint8)(((uint8)0)<<7))
/******************************************************************************/
/*                                                       AUXILIARY CLOCK 3                                                                                 */
/******************************************************************************/
/* Auxiliary Clock 3 Select Control Register (CGM_AC3_SC) */
/* SELCTL field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_3(x)                       ((uint32)(((uint32)x)<<24))
#define AUX_CLK_3_XOSC                     1
#define AUX_CLK_3_RC                       0
#define AUX_CLK_3_PLL0                     4
#define AUX_CLK_3_PLL0_D1                  8
#define AUX_CLK_3_PLL1_120                 5
#define AUX_CLK_3_PLL1_80                  8
#define AUX_CLK_3_MASK                     ((uint32)(((uint32)0xF)<<24))
/* Auxiliary Clock 3 Div Configuration Register (CGM_AC3_DC0) */
/* DIV0 field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_3_DIV(x)                   ((uint8)(((uint8)((uint8)x-(uint8)1))<<0))

/* DE0 field */
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ENABLE_AUX_CLK_3                   ((uint8)(((uint8)1)<<7))
#define DISABLE_AUX_CLK_3                  ((uint8)(((uint8)0)<<7))
/******************************************************************************/
/*                                                       AUXILIARY CLOCK 4                                                                                 */
/******************************************************************************/
/* Auxiliary Clock 4 Select Control Register (CGM_AC4_SC) */
/* SELCTL field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define AUX_CLK_4(x)                       ((uint32)(((uint32)x)<<24))
#define AUX_CLK_4_XOSC                     1
#define AUX_CLK_4_RC                       0
#define AUX_CLK_4_MASK                     ((uint32)(((uint32)0xF)<<24))
/******************************************************************************/
/*                                                      RC OSCILLATOR                                                                                           */
/******************************************************************************/
/* RC Digital Interface Registers */
/* RCTRIM field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define RC_TRIM(x)                         ((uint32)(((uint32)x)<<16))
#define RC_TRIM_MASK                       ((uint32)(((uint32)0x3F)<<16))
#define RC_TRIM_MAX_VAL                    0x3FU


/******************************************************************************/
/*                                                      XOSCILLATOR                                                                                               */
/******************************************************************************/
/* Crystal Oscillator Control Register */
/* M_OSC field */
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ENABLE_OSC_ISR                     ((uint32)(((uint32)1)<<15))
#define DISABLE_OSC_ISR                    ((uint32)(((uint32)0)<<15))

/* EOCV field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define EOCV_OSC_VALUE(x)                  ((uint32)(((uint32)x)<<16))

/* OSCBYP field */
#define OSC_BYP                            ((uint32)(((uint32)1)<<31))

#define OSC_BYP_ON                         (OSC_BYP)
#define OSC_BYP_OFF                        ((uint32)(((uint32)0)<<31))


/* I_OSC field */
#define OSC_CLOCK_ISR                      ((((uint32)0x1))<<7)

/* OSCON field */
  /*
    * @violates @ref Reg_eSys_MagicCarpet_h_REF_4 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ENABLE_OSC                         ((uint32)(((uint32)1)<<0))
#define DISABLE_OSC                        ((uint32)(((uint32)0)<<0))

/* OSCDIV field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define OSC_DIV(x)                         ((uint32)(((uint32)(x - 1))<<8))
/******************************************************************************/
/*                                                      FMPLL CR                                                                                                        */
/******************************************************************************/
/* IDF field */
#define FMPLL_CR_IDF_1                     ((uint32)(((uint32)0)<<26))
#define FMPLL_CR_IDF_2                     ((uint32)(((uint32)1)<<26))
#define FMPLL_CR_IDF_3                     ((uint32)(((uint32)2)<<26))
#define FMPLL_CR_IDF_4                     ((uint32)(((uint32)3)<<26))
#define FMPLL_CR_IDF_5                     ((uint32)(((uint32)4)<<26))
#define FMPLL_CR_IDF_6                     ((uint32)(((uint32)5)<<26))
#define FMPLL_CR_IDF_7                     ((uint32)(((uint32)6)<<26))
#define FMPLL_CR_IDF_8                     ((uint32)(((uint32)7)<<26))
#define FMPLL_CR_IDF_9                     ((uint32)(((uint32)8)<<26))
#define FMPLL_CR_IDF_10                    ((uint32)(((uint32)9)<<26))
#define FMPLL_CR_IDF_11                    ((uint32)(((uint32)10)<<26))
#define FMPLL_CR_IDF_12                    ((uint32)(((uint32)11)<<26))
#define FMPLL_CR_IDF_13                    ((uint32)(((uint32)12)<<26))
#define FMPLL_CR_IDF_14                    ((uint32)(((uint32)13)<<26))
#define FMPLL_CR_IDF_15                    ((uint32)(((uint32)14)<<26))
#define FMPLL_CR_IDF_INHIBIT               ((uint32)(((uint32)15)<<26))

/* ODF field */
#define FMPLL_CR_ODF_2                     ((uint32)(((uint32)0)<<24))
#define FMPLL_CR_ODF_4                     ((uint32)(((uint32)1)<<24))
#define FMPLL_CR_ODF_8                     ((uint32)(((uint32)2)<<24))
#define FMPLL_CR_ODF_16                    ((uint32)(((uint32)3)<<24))

/* Ndiv field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define FMPLL_CR_NDIV(x)                   ((uint32)(((uint32)x)<<16))

/* en_pll_sw field */
#define FMPLL_ENABLE_SW                    ((uint32)(((uint32)1)<<8))
#define FMPLL_DISABLE_SW                   ((uint32)(((uint32)0)<<8))

/* unlock_once field */
#define FMPLL_UNLOCK_ONCE                  ((((uint32)0x1))<<6)

/* i_lock field */
#define FMPLL_ILOCK                        ((uint32)(((uint32)1)<<4))

/* s_lock field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
#define FMPLL_SLOCK                        ((((uint32)0x1))<<3)

/* pll_fail mask */
#define FMPLL_FAIL_ENABLE                  ((uint32)(((uint32)0)<<2))
#define FMPLL_FAIL_DISABLE                 ((uint32)(((uint32)1)<<2))

/*pll_fail flag */
#define PLL_CR_FAIL_FLAG                   ((uint32)(((uint32)1)<<1))

#define FMPLL0_CR_RESETVALUE               (0x05400001UL)

#define PLL1_CR_RESETVALUE                 (FMPLL0_CR_RESETVALUE)

/* Modes for PLL functionalities */
#define MCU_PLL0_NORMAL_MODE               0U
#define MCU_PLL0_FM_MODE                   1U
#define MCU_PLL0_UNUSED_MODE               2U

#define MCU_PLL1_NORMAL_MODE               0U
#define MCU_PLL1_UNUSED_MODE               2U
#define MCU_PLL1_FM_MODE                   1U
/******************************************************************************/
/*                                                      FMPLL MR                                                                                                       */
/******************************************************************************/
/* STR_BYPASS field */
#define FMPLL_STR_BYPASS_ON                ((uint32)(((uint32)1)<<31))
#define FMPLL_STR_BYPASS_OFF               ((uint32)(((uint32)0)<<31))

/* SFRD_SEL */
#define FMPLL_SPRDSEL_CENTER               ((uint32)(((uint32)0)<<29))
#define FMPLL_SPRDSEL_DOWN                 ((uint32)(((uint32)1)<<29))

/* Mod Period field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define FMPLL_MOD_PERIOD(x)                ((uint32)(((uint32)x)<<16))

/* FM Enable field */
#define FMPLL_FM_ENABLE                    ((uint32)(((uint32)1)<<15))
#define FMPLL_FM_DISABLE                   ((uint32)(((uint32)0)<<15))

/* INC_STEP field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define FMPLL_INC_STEP(x)                  ((uint32)(((uint32)x)<<0))

#define FMPLL0_MR_RESETVALUE               (0x0UL)

/******************************************************************************/
/*                                                      CMU_0_CSR                                                                                                    */
/******************************************************************************/
/* SFM field */
#define CMU0_MEASURE_START                 ((uint32)(((uint32)1)<<23))
#define CMU0_MEASURE_START_MASK            ((uint32)(((uint32)0xFFFFFUL)<<0))

/* RCDIV field*/
#define CMU0_RCDIV_1                       ((uint32)(((uint32)0)<<1))
#define CMU0_RCDIV_2                       ((uint32)(((uint32)1)<<1))
#define CMU0_RCDIV_4                       ((uint32)(((uint32)2)<<1))
#define CMU0_RCDIV_8                       ((uint32)(((uint32)3)<<1))

#define CMU0_RCDIV_MAX_VALUE               (CMU0_RCDIV_8)
#define CMU0_RCDIV_MASK                    ((uint32)(((uint32)0x3UL)<<1))
#define CMU0_CKSEL_MASK                    ((uint32)(((uint32)0x3UL)<<8))

/* CME field*/
#define CMU0_MONITOR_DISABLE               ((uint32)(((uint32)0)<<0))
#define CMU0_MONITOR_ENABLE                ((uint32)(((uint32)1)<<0))

#define CMU0_FMPLL_MONITOR_MASK            ((((uint32)0x1))<<0)

#define FMPLL0_CMU_RESETVALUE              (0x0UL)
/******************************************************************************/
/*                                                      CMU_0_HF                                                                                                     */
/******************************************************************************/
/* High Frequency register */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CMU0_HFREF(x)                      ((uint32)(((uint32)x)<<0))
#define CMU0_HFREF_MASK                    ((uint32)(((uint32)0xFFFUL)<<0))

/******************************************************************************/
/*                                                      CMU_0_LF                                                                                                     */
/******************************************************************************/
/* Low Frequency register */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CMU0_LFREF(x)                      ((uint32)(((uint32)x)<<0))
#define CMU0_LFREF_MASK                    ((uint32)(((uint32)0xFFFUL)<<0))

/******************************************************************************/
/*                                                      CMU_0_ISR                                                                                                     */
/******************************************************************************/
/* FLCI field */
#define CMU0_ISR_FLCI                      ((uint32)(((uint32)1)<<3))
/* FHHI field */
#define CMU0_ISR_FHHI                      ((uint32)(((uint32)1)<<2))
/* FLLI field */
#define CMU0_ISR_FLLI                      ((uint32)(((uint32)1)<<1))
/* OLRI field */
#define CMU0_ISR_OLRI                      ((uint32)(((uint32)1)<<0))

/******************************************************************************/
/*                                                      CMU_0_MDR                                                                                                 */
/******************************************************************************/
/* MDR field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CMU0_MDR(x)                        ((uint32)(((uint32)x)<<0))

/******************************************************************************/
/*                                                      CMU_0_FDR                                                                                                    */
/******************************************************************************/
/* FDR field */
#define CMU0_FDR                           ((uint32)(((uint32)0xFFFFF)<<0))

/******************************************************************************/
/*                                                      CMU_1_CSR                                                                                                    */
/******************************************************************************/
/* CME field */
#define CMU1_MONITOR_DISABLE               ((uint32)(((uint32)0)<<0))
#define CMU1_MONITOR_ENABLE                ((uint32)(((uint32)1)<<0))

#define CMU1_PLL_MONITOR_MASK              ((((uint32)0x1))<<0)

#define PLL1_CMU_RESETVALUE                (0x0UL)

/******************************************************************************/
/*                                                      CMU_1_HF                                                                                                     */
/******************************************************************************/
/* High Frequency register */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CMU1_HFREF(x)                      ((uint32)(((uint32)x)<<0))
#define CMU1_HFREF_MASK                    ((uint32)(((uint32)0xFFFUL)<<0))

/******************************************************************************/
/*                                                      CMU_1_LF                                                                                                     */
/******************************************************************************/
/* Low Frequency register */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CMU1_LFREF(x)                      ((uint32)(((uint32)x)<<0))
#define CMU1_LFREF_MASK                    ((uint32)(((uint32)0xFFFUL)<<0))

/******************************************************************************/
/*                                                      CMU_1_ISR                                                                                                     */
/******************************************************************************/
/* FLCI field */
#define CMU1_ISR_FLCI                      ((((uint32)0x1))<<3)
/* FHHI field */
#define CMU1_ISR_FHHI                      ((((uint32)0x1))<<2)
/* FLLI field */
#define CMU1_ISR_FLLI                      ((((uint32)0x1))<<1)

/*******************************************************************************/
/*                                                     MC_CGM_CMUx                                                                                                    */
/*******************************************************************************/
#define MC_CGM_CMU0                         (0x00U)
#define MC_CGM_CMU1                         (0x01U)
#define MC_CGM_CMU2                         (0x02U)
#define MC_CGM_CMU3                         (0x03U)
#define MC_CGM_CMU4                         (0x04U)
#define MC_CGM_CMU5                         (0x05U)
#define MC_CGM_CMU6                         (0x06U)
#define MC_CGM_CMU7                         (0x07U)
#define MC_CGM_CMU8                         (0x08U)
#define MC_CGM_CMU9                         (0x09U)
#define MC_CGM_CMU10                        (0x0AU)
#define MC_CGM_CMU11                        (0x0BU)
#define MC_CGM_CMU12                        (0x0CU)

#define MC_CGM_CMU_CME_BIT                  ((uint32)0x00000001UL)

/******************************************************************************/
/*                                                      ME_GS                                                                                                              */
/******************************************************************************/
/* Current Mode field */
#define ME_GS_CURRENT_MODE                 ((uint32)(((uint32)0xF)<<28))

#define ME_GS_CURRENT_MODE_RESET           ((uint32)(((uint32)0)<<28))
#define ME_GS_CURRENT_MODE_TEST            ((uint32)(((uint32)1)<<28))
#define ME_GS_CURRENT_MODE_SAFE            ((uint32)(((uint32)2)<<28))
#define ME_GS_CURRENT_MODE_DRUN            ((uint32)(((uint32)3)<<28))
#define ME_GS_CURRENT_MODE_RUN0            ((uint32)(((uint32)4)<<28))
#define ME_GS_CURRENT_MODE_RUN1            ((uint32)(((uint32)5)<<28))
#define ME_GS_CURRENT_MODE_RUN2            ((uint32)(((uint32)6)<<28))
#define ME_GS_CURRENT_MODE_RUN3            ((uint32)(((uint32)7)<<28))
#define ME_GS_CURRENT_MODE_HALT            ((uint32)(((uint32)8)<<28))
#define ME_GS_CURRENT_MODE_STOP            ((uint32)(((uint32)10)<<28))

/* MTRANS field */
#define ME_GS_MODE_TRANSITION              ((((uint32)0x1))<<27)

/* DC field */
#define ME_GS_DEV_CONSUMPTION              ((((uint32)0x1))<<26)

/* PDO field */
#define ME_GS_POWER_DOWN_OUT               ((((uint32)0x1))<<23)

/* MVR field */
#define ME_GS_VOLTAGE_REG                  ((((uint32)0x1))<<20)

/* DFL field*/
#define ME_GS_DATA_FLASH                   ((uint32)(((uint32)0x3)<<18))

/* CFL field*/
#define ME_GS_CODE_FLASH                   ((uint32)(((uint32)0x3)<<16))

/* PLL1 field*/
#define ME_GS_PLL1_STATUS                  ((((uint32)0x1))<<7)

/* PLL0 field*/
#define ME_GS_PLL0_STATUS                  ((((uint32)0x1))<<6)

/* XOSC field */
#define ME_GS_XOSC_STATUS                  ((((uint32)0x1))<<5)

/* RC field */
#define ME_GS_RC_STATUS                    ((((uint32)0x1))<<4)

/* SYSCLOCK field */
#define ME_GS_SYSCLK_STATUS                ((uint32)(((uint32)0xF)<<0))

/******************************************************************************/
/*                                                      ME_MCTL                                                                                                       */
/******************************************************************************/
/* Target Mode field */
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define ME_MCTL_TARGET_MODE(x)             ((uint32)(((uint32)x)<<28))
#define ME_TARGET_MODE_MASK                ((uint32)(((uint32)0xF)<<28))

#define ME_TARGET_MODE_RESET               0x0U
#define ME_TARGET_MODE_TEST                0x1U
#define ME_TARGET_MODE_SAFE                0x2U
#define ME_TARGET_MODE_DRUN                0x3U
#define ME_TARGET_MODE_RUN0                0x4U
#define ME_TARGET_MODE_RUN1                0x5U
#define ME_TARGET_MODE_RUN2                0x6U
#define ME_TARGET_MODE_RUN3                0x7U
#define ME_TARGET_MODE_HALT                0x8U
#define ME_TARGET_MODE_STOP                0xAU

/* Key field */
#define ME_MCTL_DIRECT_KEY                 ((uint32)(((uint32)0x5AF0UL)<<0))
#define ME_MCTL_INVERTED_KEY               ((uint32)(((uint32)0xA50FUL)<<0))

/*******************************************************************************/
/*                                                      ME_ME                                                                                                              */
/*******************************************************************************/
/* Standby field */
#define ME_ME_STANDBY_ENABLE               ((uint32)(((uint32)1)<<13))
#define ME_ME_STANDBY_DISABLE              ((uint32)(((uint32)0)<<13))

/* Stop field */
#define ME_ME_STOP_ENABLE                  ((uint32)(((uint32)1)<<10))
#define ME_ME_STOP_DISABLE                 ((uint32)(((uint32)0)<<10))

/* Halt field */
#define ME_ME_HALT_ENABLE                  ((uint32)(((uint32)1)<<8))
#define ME_ME_HALT_DISABLE                 ((uint32)(((uint32)0)<<8))

/* RUN3 field */
#define ME_ME_RUN3_ENABLE                  ((uint32)(((uint32)1)<<7))
#define ME_ME_RUN3_DISABLE                 ((uint32)(((uint32)0)<<7))

/* RUN2 field */
#define ME_ME_RUN2_ENABLE                  ((uint32)(((uint32)1)<<6))
#define ME_ME_RUN2_DISABLE                 ((uint32)(((uint32)0)<<6))

/* RUN1 field */
#define ME_ME_RUN1_ENABLE                  ((uint32)(((uint32)1)<<5))
#define ME_ME_RUN1_DISABLE                 ((uint32)(((uint32)0)<<5))

/* Test field */
#define ME_ME_TEST_ENABLE                  ((uint32)(((uint32)1)<<1))
#define ME_ME_TEST_DISABLE                 ((uint32)(((uint32)0)<<1))

/*******************************************************************************/
/*                                                      ME_IS                                                                                                              */
/*******************************************************************************/
/* IMTC field */
#define ME_IS_MTC_SET                      ((uint32)(((uint32)1)<<0))
#define ME_IS_MTC_CLR                      ((((uint32)0x1))<<0)

/* ISAFE field */
#define ME_IS_SAFE_SET                     ((uint32)(((uint32)1)<<1))
#define ME_IS_SAFE_CLR                     ((((uint32)0x1))<<1)

/* IMODE field */
#define ME_IS_MODE_SET                     ((uint32)(((uint32)1)<<2))
#define ME_IS_MODE_CLR                     ((((uint32)0x1))<<2)

/* ICONF field */
#define ME_IS_CONF_SET                    ((uint32)(((uint32)1)<<3))
#define ME_IS_CONF_CLR                    ((((uint32)0x1))<<3)

/* ICONF (clock) field */
#define ME_IS_CLK_CONF_SET                ((uint32)(((uint32)1)<<4))
#define ME_IS_CLK_CONF_CLR                ((((uint32)0x1))<<4)

/*******************************************************************************/
/*                                                      ME_IM                                                                                                              */
/*******************************************************************************/
/* IMTC field */
#define ME_IE_MTC_ENABLE                  ((uint8)(((uint8)1)<<0))
#define ME_IE_MTC_DISABLE                 ((uint8)(((uint8)0)<<0))

/* ISAFE field */
#define ME_IE_SAFE_ENABLE                 ((uint8)(((uint8)1)<<1))
#define ME_IE_SAFE_DISABLE                ((uint8)(((uint8)0)<<1))

/* IMODE field */
#define ME_IE_MODE_ENABLE                 ((uint8)(((uint8)1)<<2))
#define ME_IE_MODE_DISABLE                ((uint8)(((uint8)0)<<2))

/* ICONF field */
#define ME_IE_CONF_ENABLE                 ((uint8)(((uint8)1)<<3))
#define ME_IE_CONF_DISABLE                ((uint8)(((uint8)0)<<3))

/* ICONF (clock) field */
#define ME_IE_CLK_CONF_ENABLE             ((uint8)(((uint8)1)<<4))
#define ME_IE_CLK_CONF_DISABLE            ((uint8)(((uint8)0)<<4))

/*******************************************************************************/
/*                                                      ME_IMTS                                                                                                           */
/*******************************************************************************/
/* SEA field */
#define ME_IMTS_SEA_SET                   ((uint32)(((uint32)1)<<0))
#define ME_IMTS_SEA_CLR                   ((((uint32)0x1))<<0)

/* NMA field */
#define ME_IMTS_NMA_SET                   ((uint32)(((uint32)1)<<1))
#define ME_IMTS_NMA_CLR                   ((((uint32)0x1))<<1)

/* DMA field */
#define ME_IMTS_DMA_SET                   ((uint32)(((uint32)1)<<2))
#define ME_IMTS_DMA_CLR                   ((((uint32)0x1))<<2)

/* MRI field */
#define ME_IMTS_MRI_SET                   ((uint32)(((uint32)1)<<3))
#define ME_IMTS_MRI_CLR                   ((((uint32)0x1))<<3)

/* MTI field */
#define ME_IMTS_MTI_SET                   ((uint32)(((uint32)1)<<4))
#define ME_IMTS_MTI_CLR                   ((((uint32)0x1))<<4)

/*******************************************************************************/
/*                                                      ME_<MODE>_MC                                                                                                */
/*******************************************************************************/
/* PDO flag*/
#define ME_MODE_POWER_DOWN_OUT            ((uint32)(((uint32)1)<<23))
#define ME_POWER_DOWN_OUT_ON              ((uint32)(((uint32)1)<<23))
#define ME_POWER_DOWN_OUT_OFF             ((uint32)(((uint32)0)<<23))
/* MVRON flag*/
#define ME_MODE_MAIN_VOLATAGE             ((uint32)(((uint32)1)<<20))
#define ME_MAIN_VOLATAGE_ON               ((uint32)(((uint32)1)<<20))
#define ME_MAIN_VOLATAGE_OFF              ((uint32)(((uint32)0)<<20))

/* DFLAON */
#define ME_MODE_DFAON_MASK                ((uint32)(((uint32)0x3)<<18))
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define ME_MODE_DFAON(x)                  ((uint32)(((uint32)x)<<18))

#define ME_DFLASH_POWERDOWN               (0x1UL)

#define ME_DFLASH_LOWPOWER                (0x2UL)

#define ME_DFLASH_NORMAL                  (0x3UL)
/* CFLAON */
#define ME_MODE_CFAON_MASK                ((uint32)(((uint32)0x3)<<16))
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define ME_MODE_CFAON(x)                  ((uint32)(((uint32)x)<<16))

#define ME_CFLASH_POWERDOWN               (0x1UL)

#define ME_CFLASH_LOWPOWER                (0x2UL)

#define ME_CFLASH_NORMAL                  (0x3UL)

/* PLL1ON */
#define ME_MODE_PLL1                      ((uint32)(((uint32)1)<<7))
#define ME_PLL1_ON                        ((uint32)(((uint32)1)<<7))
#define ME_PLL1_OFF                       ((uint32)(((uint32)0)<<7))

/* PLL0ON */
#define ME_MODE_PLL0                      ((uint32)(((uint32)1)<<6))
#define ME_PLL0_ON                        ((uint32)(((uint32)1)<<6))
#define ME_PLL0_OFF                       ((uint32)(((uint32)0)<<6))

/* XOSC */
#define ME_MODE_XOSC                      ((uint32)(((uint32)1)<<5))
#define ME_XOSC_ON                        ((uint32)(((uint32)1)<<5))
#define ME_XOSC_OFF                       ((uint32)(((uint32)0)<<5))

/* RC */
#define ME_MODE_RC                        ((uint32)(((uint32)1)<<4))
#define ME_RC_ON                          ((uint32)(((uint32)1)<<4))
#define ME_RC_OFF                         ((uint32)(((uint32)0)<<4))

/*SYSCLK */
#define ME_MODE_SYSCLK_MASK               ((uint32)(((uint32)0xF)<<0))
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define ME_MODE_SYSCLK(x)                 ((uint32)(((uint32)x)<<0))

#define ME_SYSCLK_SWITCH_DISABLED         (0xFUL)
#define ME_SYSCLK_SWITCH_RC               (0x0UL)
#define ME_SYSCLK_SWITCH_DIV_RC           (0x1UL)
#define ME_SYSCLK_SWITCH_XOSC             (0x2UL)
#define ME_SYSCLK_SWITCH_DIV_XOSC         (0x3UL)
#define ME_SYSCLK_SWITCH_PLL0             (0x4UL)
#define ME_SYSCLK_SWITCH_PLL1             (0x5UL)
#define ME_SYSCLK_SWITCH_CLK_DISABLED     (0x0UL)

#define ME_MODE_MASK                      (ME_MODE_POWER_DOWN_OUT|\
                                                        ME_MODE_MAIN_VOLATAGE|\
                                                        ME_MODE_DFAON_MASK|\
                                                        ME_MODE_CFAON_MASK|\
                                                        ME_MODE_PLL1|\
                                                        ME_MODE_PLL0|\
                                                        ME_MODE_XOSC|\
                                                        ME_MODE_RC|\
                                                        ME_MODE_SYSCLK_MASK)

#define ME_DRUN_MODE_RESET                ((uint32)(((uint32)0x001F0010)<<0))

/*******************************************************************************/
/*                                                      ME_RUN_PCx                                                                                                    */
/*******************************************************************************/
/* Run3 Field */
#define ME_RUN_RUN3_ACTIVE                ((uint32)(((uint32)1)<<7))
#define ME_RUN_RUN3_FROZEN                ((uint32)(((uint32)0)<<7))
/* Run2 Field */
#define ME_RUN_RUN2_ACTIVE                ((uint32)(((uint32)1)<<6))
#define ME_RUN_RUN2_FROZEN                ((uint32)(((uint32)0)<<6))
/* Run1 Field */
#define ME_RUN_RUN1_ACTIVE                ((uint32)(((uint32)1)<<5))
#define ME_RUN_RUN1_FROZEN                ((uint32)(((uint32)0)<<5))
/* Run0 Field */
#define ME_RUN_RUN0_ACTIVE                ((uint32)(((uint32)1)<<4))
#define ME_RUN_RUN0_FROZEN                ((uint32)(((uint32)0)<<4))
/* DRUN Field */
#define ME_RUN_DRUN_ACTIVE                ((uint32)(((uint32)1)<<3))
#define ME_RUN_DRUN_FROZEN                ((uint32)(((uint32)0)<<3))
/* SAFE Field */
#define ME_RUN_SAFE_ACTIVE                ((uint32)(((uint32)1)<<2))
#define ME_RUN_SAFE_FROZEN                ((uint32)(((uint32)0)<<2))
/* TEST Field */
#define ME_RUN_TEST_ACTIVE                ((uint32)(((uint32)1)<<1))
#define ME_RUN_TEST_FROZEN                ((uint32)(((uint32)0)<<1))

#define ME_RUN_PC0                        0x0U
#define ME_RUN_PC1                        0x1U
#define ME_RUN_PC2                        0x2U
#define ME_RUN_PC3                        0x3U
#define ME_RUN_PC4                        0x4U
#define ME_RUN_PC5                        0x5U
#define ME_RUN_PC6                        0x6U
#define ME_RUN_PC7                        0x7U
/*******************************************************************************/
/*                                                      ME_LP_PCx                                                                                                        */
/*******************************************************************************/
/* Standby Field */
#define ME_RUN_STBY_ACTIVE                ((uint32)(((uint32)1)<<13))
#define ME_RUN_STBY_FROZEN                ((uint32)(((uint32)0)<<13))
/* Stop Field */
#define ME_RUN_STOP_ACTIVE                ((uint32)(((uint32)1)<<10))
#define ME_RUN_STOP_FROZEN                ((uint32)(((uint32)0)<<10))
/* Halt Field */
#define ME_RUN_HALT_ACTIVE                ((uint32)(((uint32)1)<<8))
#define ME_RUN_HALT_FROZEN                ((uint32)(((uint32)0)<<8))

#define ME_LP_PC0                         0x0U
#define ME_LP_PC1                         0x1U
#define ME_LP_PC2                         0x2U
#define ME_LP_PC3                         0x3U
#define ME_LP_PC4                         0x4U
#define ME_LP_PC5                         0x5U
#define ME_LP_PC6                         0x6U
#define ME_LP_PC7                         0x7U

/*******************************************************************************/
/*                                                      ME_PCTLx                                                                                                        */
/*******************************************************************************/
/* @violates @ref Reg_eSys_MagicCarpet_h_REF_1 Violates MISRA 2004 Advisory
                   Rule 19.7, Function-like macro defined                   */
/*
* @violates @ref Reg_eSys_MagicCarpet_h_REF_3 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define ME_PCTLn(run,lp)                  (((uint8)(((uint8)lp)<<3)) | ((uint8)run))


/*******************************************************************************/
/*                                                     RGM_FES                                                                                                        */
/*******************************************************************************/

/* JTAG field */
#define RGM_FES_JTAG                      ((uint16)(((uint16)1)<<0))
/* CORE field */
#define RGM_FES_CORE                      ((uint16)(((uint16)1)<<1))
/* SOFT field */
#define RGM_FES_SOFT                      ((uint16)(((uint16)1)<<2))
/* CWD field */
#define RGM_FES_CWD                       ((uint16)(((uint16)1)<<3))
/* PLL0 field */
#define RGM_FES_PLL0                      ((uint16)(((uint16)1)<<4))
/* CMU0_OLR field */
#define RGM_FES_CMU0_OLR                  ((uint16)(((uint16)1)<<5))
/* CMU0_FHL field */
#define RGM_FES_CMU0_FHL                  ((uint16)(((uint16)1)<<6))
/* FCCU_SAFE field */
#define RGM_FES_FCCU_SAFE                 ((uint16)(((uint16)1)<<7))
/* SWT field */
#define RGM_FES_SWT                       ((uint16)(((uint16)1)<<8))
/* PLL1 filed*/
#define RGM_FES_PLL1                      ((uint16)(((uint16)1)<<9))
/* FL_ECC_RCC field  */
#define RGM_FES_FL_ECC_RCC                ((uint16)(((uint16)1)<<10))
/* CMU12_FHL field */
#define RGM_FES_CMU12_FHL                 ((uint16)(((uint16)1)<<11))
/* ST_DONE field */
#define RGM_FES_ST_DONE                   ((uint16)(((uint16)1)<<12))
/* FCCU_SOFT field */
#define RGM_FES_FCCU_SOFT                 ((uint16)(((uint16)1)<<13))
/* FCCU_HARD field */
#define RGM_FES_FCCU_HARD                 ((uint16)(((uint16)1)<<14))
/* EXR field */
#define RGM_FES_EXR                       ((uint16)(((uint16)1)<<15))

#define RGM_FES_MASK                      (RGM_FES_JTAG|\
                                                                    RGM_FES_CORE|\
                                                                    RGM_FES_SOFT|\
                                                                    RGM_FES_CWD|\
                                                                    RGM_FES_PLL0|\
                                                                    RGM_FES_CMU0_OLR|\
                                                                    RGM_FES_CMU0_FHL|\
                                                                    RGM_FES_FCCU_SAFE|\
                                                                    RGM_FES_SWT|\
                                                                    RGM_FES_PLL1|\
                                                                    RGM_FES_FL_ECC_RCC|\
                                                                    RGM_FES_CMU12_FHL|\
                                                                    RGM_FES_ST_DONE|\
                                                                    RGM_FES_FCCU_SOFT|\
                                                                    RGM_FES_FCCU_HARD|\
                                                                    RGM_FES_EXR)
/*******************************************************************************/
/*                                                     RGM_DES                                                                                                          */
/*******************************************************************************/
/* LVD12 field */
#define  RGM_DES_LVD12                    ((uint16)(((uint16)1)<<0))
/* HVD12 field */
#define  RGM_DES_HVD12                    ((uint16)(((uint16)1)<<1))
/* LVD27_VREG field */
#define  RGM_DES_LVD27_VREG               ((uint16)(((uint16)1)<<2))
/* LVD27_FLASH field */
#define  RGM_DES_LVD27_FLASH              ((uint16)(((uint16)1)<<3))
/* LVD27_IO field */
#define  RGM_DES_LVD27_IO                 ((uint16)(((uint16)1)<<4))
/* COMP field */
#define  RGM_DES_COMP                     ((uint16)(((uint16)1)<<5))
/* POR field */
#define RGM_DES_POR                       ((uint16)(((uint16)1)<<15))
/* SOFT_DEST field */
#define RGM_DES_SOFT_DEST                 ((uint16)(((uint16)1)<<14))

#define RGM_DES_MASK                      (RGM_DES_LVD12|\
                                                                RGM_DES_HVD12|\
                                                                RGM_DES_LVD27_VREG|\
                                                                RGM_DES_LVD27_FLASH|\
                                                                RGM_DES_LVD27_IO|\
                                                                RGM_DES_COMP|\
                                                                RGM_DES_POR)

/*******************************************************************************/
/*                                                     RGM_FERD                                                                                                        */
/*******************************************************************************/
/* JTAG field */
#define FERD_JTAG_NORESET                 ((uint16)(((uint16)1)<<0))
#define FERD_JTAG_RESET                   ((uint16)(((uint16)0)<<0))
/* CORE field */
#define FERD_CORE_NORESET                 ((uint16)(((uint16)1)<<1))
#define FERD_CORE_RESET                   ((uint16)(((uint16)0)<<1))
/* SOFT field */
#define FERD_SOFT_NORESET                 ((uint16)(((uint16)1)<<2))
#define FERD_SOFT_RESET                   ((uint16)(((uint16)0)<<2))
/* CWD field */
#define FERD_CWD_NORESET                  ((uint16)(((uint16)1)<<3))
#define FERD_CWD_RESET                    ((uint16)(((uint16)0)<<3))
/* CHKSTOP field */
#define FERD_CHKSTOP_NORESET              ((uint16)(((uint16)0)<<3))
#define FERD_CHKSTOP_RESET                ((uint16)(((uint16)0)<<3))
/* PLL0 field */
#define FERD_PLL0_NORESET                 ((uint16)(((uint16)1)<<4))
#define FERD_PLL0_RESET                   ((uint16)(((uint16)0)<<4))
/* CMU0_OLR field */
#define FERD_CMU0_OLR_NORESET             ((uint16)(((uint16)1)<<5))
#define FERD_CMU0_OLR_RESET               ((uint16)(((uint16)0)<<5))
/* CMU0_FHL field */
#define FERD_CMU0_FHL_NORESET             ((uint16)(((uint16)1)<<6))
#define FERD_CMU0_FHL_RESET               ((uint16)(((uint16)0)<<6))
/* LVD45 field */
#define FERD_LVD45_NORESET                ((uint16)(((uint16)1)<<7))
#define FERD_LVD45_RESET                  ((uint16)(((uint16)0)<<7))
/* FCCU_SAFE field */
#define FERD_FCCU_SAFE_NORESET            ((uint16)(((uint16)1)<<7))
#define FERD_FCCU_SAFE_RESET              ((uint16)(((uint16)0)<<7))
/* SWT field */
#define FERD_SWT_NORESET                  ((uint16)(((uint16)0)<<8))
#define FERD_SWT_RESET                    ((uint16)(((uint16)0)<<8))
/* FLASH field */
#define FERD_FLASH_NORESET                ((uint16)(((uint16)1)<<8))
#define FERD_FLASH_RESET                  ((uint16)(((uint16)0)<<8))
/* PLL1 filed*/
#define FERD_PLL1_NORESET                 ((uint16)(((uint16)1)<<9))
#define FERD_PLL1_RESET                   ((uint16)(((uint16)0)<<9))
/* FL_ECC_RCC field  */
#define FERD_FL_ECC_RCC_NORESET           ((uint16)(((uint16)1)<<10))
#define FERD_FL_ECC_RCC_RESET             ((uint16)(((uint16)0)<<10))
/* Z4_CORE filed*/
#define FERD_Z4CORE_NORESET               ((uint16)(((uint16)1)<<10))
#define FERD_Z4CORE_RESET                 ((uint16)(((uint16)0)<<10))
/* CMU12_FHL field  */
#define FERD_CMU12_FHL_NORESET            ((uint16)(((uint16)1)<<11))
#define FERD_CMU12_FHL_RESET              ((uint16)(((uint16)0)<<11))
/* ST_DONE field  */
#define FERD_ST_DONE_NORESET              ((uint16)(((uint16)1)<<12))
#define FERD_ST_DONE_RESET                ((uint16)(((uint16)0)<<12))
/* FCCU_SOFT field  */
#define FERD_FCCU_SOFT_NORESET            ((uint16)(((uint16)1)<<13))
#define FERD_FCCU_SOFT_RESET              ((uint16)(((uint16)0)<<13))
/* ST_CF field  */
#define FERD_ST_CF_NORESET                ((uint16)(((uint16)1)<<13))
#define FERD_ST_CF_RESET                  ((uint16)(((uint16)1)<<13))
/* FCCU_HARD field  */
#define FERD_FCCU_HARD_NORESET            ((uint16)(((uint16)1)<<14))
#define FERD_FCCU_HARD_RESET              ((uint16)(((uint16)0)<<14))
/* ST_NCF field  */
#define FERD_ST_NCF_NORESET               ((uint16)(((uint16)1)<<14))
#define FERD_ST_NCF_RESET                 ((uint16)(((uint16)1)<<14))
/* F_EXR field */
#define FERD_EXR_NORESET                  ((uint16)(((uint16)1)<<15))
#define FERD_EXR_RESET                    ((uint16)(((uint16)0)<<15))

/*******************************************************************************/
/*                                                     RGM_DERD                                                                                                          */
/*******************************************************************************/
/* LVD12 field */
#define  DERD_LVD12_NORESET               ((uint16)(((uint16)1)<<0))
#define  DERD_LVD12_RESET                 ((uint16)(((uint16)0)<<0))
/* HVD12 field */
#define  DERD_HVD12_NORESET               ((uint16)(((uint16)1)<<1))
#define  DERD_HVD12_RESET                 ((uint16)(((uint16)0)<<1))
/* LVD27_VREG field */
#define DERD_LVD27_VREG_NORESET           ((uint16)(((uint16)1)<<4))
#define DERD_LVD27_VREG_RESET             ((uint16)(((uint16)0)<<4))
/* LVD27_FLASH field */
#define DERD_LVD27_FLASH_NORESET          ((uint16)(((uint16)1)<<5))
#define DERD_LVD27_FLASH_RESET            ((uint16)(((uint16)0)<<5))
/* LVD27_IO field */
#define DERD_LVD27_IO_NORESET             ((uint16)(((uint16)1)<<6))
#define DERD_LVD27_IO_RESET               ((uint16)(((uint16)0)<<6))
/* COMP field */
#define DERD_COMP_NORESET                 ((uint16)(((uint16)1)<<7))
#define DERD_COMP_RESET                   ((uint16)(((uint16)0)<<7))

/* COMP field */
#define DERD_SOFT_DEST_NORESET            ((uint16)(((uint16)1)<<14))
#define DERD_SOFT_DEST_RESET              ((uint16)(((uint16)0)<<14))

/* POR field */
#define DERD_POR_NORESET                  ((uint16)(((uint16)1)<<15))
#define DERD_POR_RESET                    ((uint16)(((uint16)0)<<15))
/*******************************************************************************/
/*                                                     RGM_FEAR                                                                                                        */
/*******************************************************************************/
/* JTAG field */
#define FEAR_JTAG_ISR                     ((uint16)(((uint16)1)<<0))
#define FEAR_JTAG_SAFE                    ((uint16)(((uint16)0)<<0))
/* CORE field */
#define FEAR_CORE_ISR                     ((uint16)(((uint16)1)<<1))
#define FEAR_CORE_SAFE                    ((uint16)(((uint16)0)<<1))
/* SOFT field */
#define FEAR_SOFT_ISR                     ((uint16)(((uint16)1)<<2))
#define FEAR_SOFT_SAFE                    ((uint16)(((uint16)0)<<2))
/* CWD field */
#define FEAR_CWD_ISR                      ((uint16)(((uint16)1)<<3))
#define FEAR_CWD_SAFE                     ((uint16)(((uint16)0)<<3))
/* CHKSTOP field */
#define FEAR_CHKSTOP_ISR                  ((uint16)(((uint16)1)<<3))
#define FEAR_CHKSTOP_SAFE                 ((uint16)(((uint16)0)<<3))
/* PLL0 field */
#define FEAR_PLL0_ISR                     ((uint16)(((uint16)1)<<4))
#define FEAR_PLL0_SAFE                    ((uint16)(((uint16)0)<<4))
/* CMU0_OLR field */
#define FEAR_CMU0_OLR_ISR                 ((uint16)(((uint16)1)<<5))
#define FEAR_CMU0_OLR_SAFE                ((uint16)(((uint16)0)<<5))
/* CMU0_FHL field */
#define FEAR_CMU0_FHL_ISR                 ((uint16)(((uint16)1)<<6))
#define FEAR_CMU0_FHL_SAFE                ((uint16)(((uint16)0)<<6))
/* LVD45 field */
#define FEAR_LVD45_ISR                    ((uint16)(((uint16)1)<<7))
#define FEAR_LVD45_SAFE                   ((uint16)(((uint16)0)<<7))
/* FCCU_SAFE field */
#define FEAR_FCCU_SAFE_ISR                ((uint16)(((uint16)1)<<7))
#define FEAR_FCCU_SAFE_SAFE               ((uint16)(((uint16)0)<<7))
/* FLASH field */
#define FEAR_FLASH_ISR                    ((uint16)(((uint16)1)<<8))
#define FEAR_FLASH_SAFE                   ((uint16)(((uint16)0)<<8))
/* SWT field */
#define FEAR_SWT_ISR                      ((uint16)(((uint16)1)<<8))
#define FEAR_SWT_SAFE                     ((uint16)(((uint16)0)<<8))
/* PLL1 field */
#define FEAR_PLL1_ISR                     ((uint16)(((uint16)1)<<9))
#define FEAR_PLL1_SAFE                    ((uint16)(((uint16)0)<<9))
/* Z4_CORE field */
#define FEAR_Z4CORE_ISR                   ((uint16)(((uint16)1)<<10))
#define FEAR_Z4CORE_SAFE                  ((uint16)(((uint16)0)<<10))
/* FL_ECC_RCC field */
#define FEAR_FL_ECC_RCC_ISR               ((uint16)(((uint16)1)<<10))
#define FEAR_FL_ECC_RCC_SAFE              ((uint16)(((uint16)0)<<10))
/* CMU12_FHL field */
#define FEAR_CMU12_FHL_ISR                ((uint16)(((uint16)1)<<11))
#define FEAR_CMU12_FHL_SAFE               ((uint16)(((uint16)0)<<11))
/* ST_DONE field */
#define FEAR_ST_DONE_ISR                  ((uint16)(((uint16)1)<<12))
#define FEAR_ST_DONE_SAFE                 ((uint16)(((uint16)0)<<12))
/* FCCU_SOFT field */
#define FEAR_FCCU_SOFT_ISR                ((uint16)(((uint16)1)<<13))
#define FEAR_FCCU_SOFT_SAFE               ((uint16)(((uint16)0)<<13))
/* FCCU_HARD field */
#define FEAR_FCCU_HARD_ISR                ((uint16)(((uint16)1)<<14))
#define FEAR_FCCU_HARD_SAFE               ((uint16)(((uint16)0)<<14))
/* EXR field */
#define FEAR_EXR_ISR                      ((uint16)(((uint16)1)<<15))
#define FEAR_EXR_SAFE                     ((uint16)(((uint16)0)<<15))

/*******************************************************************************/
/*                                                     RGM_FESS                                                                                                        */
/*******************************************************************************/
/* JTAG field */
#define FESS_JTAG_PH3                     ((uint16)(((uint16)1)<<0))
#define FESS_JTAG_PH1                     ((uint16)(((uint16)0)<<0))
/* CORE field */
#define FESS_CORE_PH3                     ((uint16)(((uint16)1)<<1))
#define FESS_CORE_PH1                     ((uint16)(((uint16)0)<<1))
/* SOFT field */
#define FESS_SOFT_PH3                     ((uint16)(((uint16)1)<<2))
#define FESS_SOFT_PH1                     ((uint16)(((uint16)0)<<2))
/* CWD field */
#define FESS_CWD_PH3                      ((uint16)(((uint16)1)<<3))
#define FESS_CWD_PH1                      ((uint16)(((uint16)0)<<3))
/* CHKSTOP field */
#define FESS_CHKSTOP_PH3                  ((uint16)(((uint16)1)<<3))
#define FESS_CHKSTOP_PH1                  ((uint16)(((uint16)0)<<3))
/* PLL0 field */
#define FESS_PLL0_PH3                     ((uint16)(((uint16)1)<<4))
#define FESS_PLL0_PH1                     ((uint16)(((uint16)0)<<4))
/* CMU0_OLR field */
#define FESS_CMU0_OLR_PH3                 ((uint16)(((uint16)1)<<5))
#define FESS_CMU0_OLR_PH1                 ((uint16)(((uint16)0)<<5))
/* CMU0_FHL field */
#define FESS_CMU0_FHL_PH3                 ((uint16)(((uint16)1)<<6))
#define FESS_CMU0_FHL_PH1                 ((uint16)(((uint16)0)<<6))
/* FCCU_SAFE field */
#define FESS_FCCU_SAFE_PH3                ((uint16)(((uint16)1)<<7))
#define FESS_FCCU_SAFE_PH1                ((uint16)(((uint16)0)<<7))
/* LVD45 field */
#define FESS_LVD45_PH3                    ((uint16)(((uint16)1)<<7))
#define FESS_LVD45_PH1                    ((uint16)(((uint16)0)<<7))
/* FLASH field */
#define FESS_FLASH_PH3                    ((uint16)(((uint16)1)<<8))
#define FESS_FLASH_PH1                    ((uint16)(((uint16)0)<<8))
/* SWT field */
#define FESS_SWT_PH3                      ((uint16)(((uint16)1)<<8))
#define FESS_SWT_PH1                      ((uint16)(((uint16)0)<<8))
/* PLL1 field */
#define FESS_PLL1_PH3                     ((uint16)(((uint16)1)<<9))
#define FESS_PLL1_PH1                     ((uint16)(((uint16)0)<<9))
/* FL_ECC_RCC field */
#define FESS_FL_ECC_RCC_PH3               ((uint16)(((uint16)1)<<10))
#define FESS_FL_ECC_RCC_PH1               ((uint16)(((uint16)0)<<10))
/* Z4_CORE field */
#define FESS_Z4CORE_PH3                   ((uint16)(((uint16)1)<<10))
#define FESS_Z4CORE_PH1                   ((uint16)(((uint16)0)<<10))
/* CMU12_FHL field */
#define FESS_CMU12_FHL_PH3                ((uint16)(((uint16)1)<<11))
#define FESS_CMU12_FHL_PH1                ((uint16)(((uint16)0)<<11))
/* ST_DONE field */
#define FESS_ST_DONE_PH3                  ((uint16)(((uint16)1)<<12))
#define FESS_ST_DONE_PH1                  ((uint16)(((uint16)0)<<12))
/* FCCU_SOFT field */
#define FESS_FCCU_SOFT_PH3                ((uint16)(((uint16)1)<<13))
#define FESS_FCCU_SOFT_PH1                ((uint16)(((uint16)0)<<13))
/* FCCU_HARD field */
#define FESS_FCCU_HARD_PH3                ((uint16)(((uint16)1)<<14))
#define FESS_FCCU_HARD_PH1                ((uint16)(((uint16)0)<<14))
/* EXR field */
#define FESS_EXR_PH3                      ((uint16)(((uint16)1)<<15))
#define FESS_EXR_PH1                      ((uint16)(((uint16)0)<<15))
/*******************************************************************************/
/*                                                     RGM_FBRE                                                                                                        */
/*******************************************************************************/
/* JTAG field */
#define FBRE_JTAG_DIS                     ((uint16)(((uint16)1)<<0))
#define FBRE_JTAG_EN                      ((uint16)(((uint16)0)<<0))
/* CORE field */
#define FBRE_CORE_DIS                     ((uint16)(((uint16)1)<<1))
#define FBRE_CORE_EN                      ((uint16)(((uint16)0)<<1))
/* SOFT field */
#define FBRE_SOFT_DIS                     ((uint16)(((uint16)1)<<2))
#define FBRE_SOFT_EN                      ((uint16)(((uint16)0)<<2))
/* CWD field */
#define FBRE_CWD_DIS                      ((uint16)(((uint16)1)<<3))
#define FBRE_CWD_EN                       ((uint16)(((uint16)0)<<3))
/* CHKSTOP field */
#define FBRE_CHKSTOP_DIS                  ((uint16)(((uint16)1)<<3))
#define FBRE_CHKSTOP_EN                   ((uint16)(((uint16)0)<<3))
/* PLL0 field */
#define FBRE_PLL0_DIS                     ((uint16)(((uint16)1)<<4))
#define FBRE_PLL0_EN                      ((uint16)(((uint16)0)<<4))
/* CMU0_OLR field */
#define FBRE_CMU0_OLR_DIS                 ((uint16)(((uint16)1)<<5))
#define FBRE_CMU0_OLR_EN                  ((uint16)(((uint16)0)<<5))
/* CMU0_FHL field */
#define FBRE_CMU0_FHL_DIS                 ((uint16)(((uint16)1)<<6))
#define FBRE_CMU0_FHL_EN                  ((uint16)(((uint16)0)<<6))
/* FCCU_SAFE field */
#define FBRE_FCCU_SAFE_DIS                ((uint16)(((uint16)1)<<7))
#define FBRE_FCCU_SAFE_EN                 ((uint16)(((uint16)0)<<7))
/* LVD45 field */
#define FBRE_LVD45_DIS                    ((uint16)(((uint16)1)<<7))
#define FBRE_LVD45_EN                     ((uint16)(((uint16)0)<<7))
/* SWT field */
#define FBRE_SWT_DIS                      ((uint16)(((uint16)1)<<8))
#define FBRE_SWT_EN                       ((uint16)(((uint16)0)<<8))
/* FLASH field */
#define FBRE_FLASH_DIS                    ((uint16)(((uint16)1)<<8))
#define FBRE_FLASH_EN                     ((uint16)(((uint16)0)<<8))
/* PLL1 field */
#define FBRE_PLL1_DIS                     ((uint16)(((uint16)1)<<9))
#define FBRE_PLL1_EN                      ((uint16)(((uint16)0)<<9))
/* FL_ECC_RCC field */
#define FBRE_FL_ECC_RCC_DIS               ((uint16)(((uint16)1)<<10))
#define FBRE_FL_ECC_RCC_EN                ((uint16)(((uint16)0)<<10))
/* Z4CORE field */
#define FBRE_Z4CORE_DIS                   ((uint16)(((uint16)1)<<10))
#define FBRE_Z4CORE_EN                    ((uint16)(((uint16)0)<<10))
/* CMU12_FHL field */
#define FBRE_CMU12_FHL_DIS                ((uint16)(((uint16)1)<<11))
#define FBRE_CMU12_FHL_EN                 ((uint16)(((uint16)0)<<11))
/* ST_DONE field */
#define FBRE_ST_DONE_DIS                  ((uint16)(((uint16)1)<<12))
#define FBRE_ST_DONE_EN                   ((uint16)(((uint16)0)<<12))
/* FCCU_SOFT field */
#define FBRE_FCCU_SOFT_DIS                ((uint16)(((uint16)1)<<13))
#define FBRE_FCCU_SOFT_EN                 ((uint16)(((uint16)0)<<13))
/* FCCU_HARD field */
#define FBRE_FCCU_HARD_DIS                ((uint16)(((uint16)1)<<14))
#define FBRE_FCCU_HARD_EN                 ((uint16)(((uint16)0)<<14))
/* EXR field */
#define FBRE_EXR_DIS                      ((uint16)(((uint16)1)<<15))
#define FBRE_EXR_EN                       ((uint16)(((uint16)0)<<15))

#define FBRE_POR_VALUE                    (0x0UL)    /*Power On Reset Value */


/*******************************************************************************/
/*                                                     RGM_DEAR                                                                                                          */
/*******************************************************************************/
/* LVD12_PD0 field */
#define  DEAR_LVD12_PD0_ISR               ((uint16)(((uint16)1)<<0))
#define  DEAR_LVD12_PD0_SAFE              ((uint16)(((uint16)0)<<0))
/* LVD12_PD1 field */
#define  DEAR_LVD12_PD1_ISR               ((uint16)(((uint16)1)<<1))
#define  DEAR_LVD12_PD1_SAFE              ((uint16)(((uint16)0)<<1))
/* SWT field */
#define DEAR_SWT_ISR                      ((uint16)(((uint16)1)<<2))
#define DEAR_SWT_SAFE                     ((uint16)(((uint16)0)<<2))
/* LVD27 field */
#define DEAR_LVD27_ISR                    ((uint16)(((uint16)1)<<3))
#define DEAR_LVD27_SAFE                   ((uint16)(((uint16)0)<<3))

#define MCU_RGM_DES_REG_MASK              ((uint16)0xFFFFU)
#define MCU_RGM_FES_REG_MASK              ((uint16)0xFFFFU)
#define MCU_MASK_EXT_RESET                ((uint32)0x80000000UL)
#define MCU_MASK_FLASH_RESET              ((uint32)0x01000000UL)
#define MCU_MASK_LVD45_RESET              ((uint32)0x00800000UL)
#define MCU_MASK_CMU0_FHL_RESET           ((uint32)0x00400000UL)
#define MCU_MASK_CMU0_OLR_RESET           ((uint32)0x00200000UL)
#define MCU_MASK_PLL0_RESET               ((uint32)0x00100000UL)
#define MCU_MASK_CHECKSTOP_RESET          ((uint32)0x00080000UL)
#define MCU_MASK_SOFT_RESET               ((uint32)0x00040000UL)
#define MCU_MASK_CORE_RESET               ((uint32)0x00020000UL)
#define MCU_MASK_JTAG_RESET               ((uint32)0x00010000UL)
#define MCU_MASK_POR_RESET                ((uint32)0x00008000UL)
#define MCU_MASK_LVD27_VREG_RESET         ((uint32)0x00000010UL)  /* Flag for 2.7 V low-voltage det. (VREG) */
#define MCU_MASK_LVD27_RESET              ((uint32)0x00000008UL)
#define MCU_MASK_SWT_D_RESET              ((uint32)0x00000004UL)
#define MCU_MASK_LVD12_PD1_RESET          ((uint32)0x00000002UL)
#define MCU_MASK_LVD12_PD0_RESET          ((uint32)0x00000001UL)
#define MCU_MASK_COMP_RESET               ((uint32)0x00000080UL)


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_MAGICCARPET_H */

/** @} */
