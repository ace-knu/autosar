/**
 *     @file    Reg_eSys_WKPU.h
 *     @version 1.0.1
 * 
 *     @brief   AUTOSAR Icu - WKPU header file support for ICU driver.
 *     @details WKPU header file, containing the variables and functions that are exported by the WKPU driver.
 * 
 *     @addtogroup ICU_MODULE
 *     @{
*/
/*==================================================================================================
 *     Project             : AUTOSAR 4.0 MCAL
 *     Platform            : PA
 *     Peripheral          : eMIOS
 *     Dependencies        : none
 * 
 *     Autosar Version     : 4.0.3
 *     Autosar Revision    : ASR_REL_4_0_REV_0003
 *     Autosar ConfVariant : 
 *     SWVersion           : 1.0.1
 *     BuildVersion        : MPC560xB_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20140606
 * 
 *     (c) Copyright 2006-2014 Freescale Semiconductor Inc and STMicroelectronics
 *     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
 ==================================================================================================*/
/**
* @file    Reg_eSys_WKPU.h
* @remarks Implements DICU06401
*/

#ifndef REG_eSys_WKPU_H
#define REG_eSys_WKPU_H

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_WKPU_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*@section Reg_eSys_WKPU_h_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Reg_eSys_WKPU_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Reg_eSys.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
@{
*@brief   Header file version information
*@remarks Covers BSW00374, BSW00379, BSW00318
*/
#define REG_ESYS_WKPU_VENDOR_ID                     43

/*
* @violates @ref Reg_eSys_WKPU_h_2 This is required as per autosar Requirement, 
*/
#define REG_ESYS_WKPU_AR_RELEASE_MAJOR_VERSION      4
/*
* @violates @ref Reg_eSys_WKPU_h_2 This is required as per autosar Requirement, 
*/
#define REG_ESYS_WKPU_AR_RELEASE_MINOR_VERSION      0
/*
* @violates @ref Reg_eSys_WKPU_h_2 This is required as per autosar Requirement, 
*/
#define REG_ESYS_WKPU_AR_RELEASE_REVISION_VERSION      3

#define REG_ESYS_WKPU_SW_MAJOR_VERSION      1
#define REG_ESYS_WKPU_SW_MINOR_VERSION      0
#define REG_ESYS_WKPU_SW_PATCH_VERSION      1
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                DEFINES AND MACROS
==================================================================================================*/
/**
*@brief Wakeup Register Defintions
*@{
*/
#define WKPU_NSR            (WKPU_BASEADDR + 0x00UL)
#define WKPU_NCR            (WKPU_BASEADDR + 0x08UL)
#define WKPU_WISR           (WKPU_BASEADDR + 0x14UL)
#define WKPU_IRER           (WKPU_BASEADDR + (uint32)0x18UL)
#define WKPU_WRER           (WKPU_BASEADDR + (uint32)0x1CUL)
#define WKPU_WIREER         (WKPU_BASEADDR + (uint32)0x28UL)
#define WKPU_WIFEER         (WKPU_BASEADDR + 0x2CUL)
#define WKPU_WIFER          (WKPU_BASEADDR + 0x30UL)
#define WKPU_WIPUER         (WKPU_BASEADDR + 0x34UL)
/**@}*/

/**
*@brief IPVAULT defintion 
*@{
*/
#define IPV_WKUP_01_00_12_00   (0x01001200UL)
/**@}*/


#ifdef __cplusplus
}
#endif

#endif  /* REG_eSys_WKPU_H */
/**@}*/
