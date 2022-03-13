/**
*   @file    Reg_eSys_ECSM.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - eCSM Registers and Macros Definitions.
*   @details eCSM Registers and Macros Definitions.
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

#ifndef REG_ESYS_ECSM_H
#define REG_ESYS_ECSM_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_ESCM_H_REF_1
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section REG_ESYS_ESCM_H_REF_2
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_ECSM.h
* @implements     DMCU05090, DMCU05091, DMCU05092, DMCU05093, DMCU05094, DMCU05095,
*                 DMCU05096
*/
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_REG_VENDOR_ID                      43
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    /*
* @violates @ref REG_ESYS_ESCM_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define ECSM_REG_AR_RELEASE_MAJOR_VERSION       4
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    /*
* @violates @ref REG_ESYS_ESCM_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define ECSM_REG_AR_RELEASE_MINOR_VERSION       0
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    /*
* @violates @ref REG_ESYS_ESCM_H_REF_2 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define ECSM_REG_AR_RELEASE_REVISION_VERSION    3
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_REG_SW_MAJOR_VERSION               1
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_REG_SW_MINOR_VERSION               0
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_REG_SW_PATCH_VERSION               1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/**
* @brief  XPC564XB platform
*/
#define IPV_ECSM_14_2                   (0x00000014UL)

/**
* @brief  XPC56XXL platform
*/
#define IPV_ECSM_01_00_02_00            (0x01000200UL)

/**
* @brief  MPC56XXK platform
*/
#define IPV_ECSM_01_00_00_08            (0x01000008UL)

/**
* @brief  XPC560XB 512K platform 
*/ 
#define IPV_ECSM_10_10_00_12            (0x10100012UL)

/**
* @brief  XPC560XB 1.5M platform
*/
#define IPV_ECSM_01_00_00_09            (0x01000009UL)

/**
* @brief  XPC560XB 256K platform
*/
#define IPV_ECSM_B1_00_00_08           (0xB1000008UL)

/**
* @brief  XPC56XXA 4M platform
*/
#define IPV_ECSM_01_00_01_04            (0x01000104UL)

/**
* @brief  XPC56XXA 2M platform
*/
#define IPV_ECSM_01_00_02_02            (0x01000202UL)

/**
* @brief  MPC5676R platform
*/
#define IPV_ECSM_00_00_00_20            (0x00000020UL)

/**
* @brief  XPC56AXP60 platform
*/
#define IPV_ECSM_01_00_00_04   (0x01000004UL)

/**
* @brief  XPC560XP50 platform
*/
#define IPV_ECSM_01_00_01_02  (0x01000102UL)

/**
* @brief  XPC560XP40 platform
*/
#define IPV_ECSM_01_00_02_07  (0x01000207UL)
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PCT_R                       ((uint32)(ECSM_BASEADDR+(uint32)0x0000UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PLREV_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0002UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PLAMC_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0004UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PLASC_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0006UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_IOPMC_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0008UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_MRSR_R                      ((uint32)(ECSM_BASEADDR+(uint32)0x000FUL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_MWCR_R                      ((uint32)(ECSM_BASEADDR+(uint32)0x0013UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_MUDCR_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0024UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_ECR_R                       ((uint32)(ECSM_BASEADDR+(uint32)0x0043UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_ESR_R                       ((uint32)(ECSM_BASEADDR+(uint32)0x0047UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_EEGR_R                      ((uint32)(ECSM_BASEADDR+(uint32)0x004AUL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PFEAR_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0050UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PFEMR_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0056UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PFEAT_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0057UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PFEDRH_R                    ((uint32)(ECSM_BASEADDR+(uint32)0x0058UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PFEDRL_R                    ((uint32)(ECSM_BASEADDR+(uint32)0x005CUL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PREAR_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0060UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PRESR_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0065UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PREMR_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0066UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PREAT_R                     ((uint32)(ECSM_BASEADDR+(uint32)0x0067UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PREDRH_R                    ((uint32)(ECSM_BASEADDR+(uint32)0x0068UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_PREDRL_R                    ((uint32)(ECSM_BASEADDR+(uint32)0x006CUL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */

#define ECSM_1_PCT_R                     ((uint32)(ECSM_1_BASEADDR+(uint32)0x0000UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PLREV_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0002UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PLAMC_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0004UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PLASC_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0006UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_IOPMC_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0008UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_MRSR_R                    ((uint32)(ECSM_1_BASEADDR+(uint32)0x000FUL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_MUDCR_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0024UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_ECR_R                     ((uint32)(ECSM_1_BASEADDR+(uint32)0x0043UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_ESR_R                     ((uint32)(ECSM_1_BASEADDR+(uint32)0x0047UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_EEGR_R                    ((uint32)(ECSM_1_BASEADDR+(uint32)0x004AUL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PFEAR_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0050UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PFEMR_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0056UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PFEAT_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0057UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PFEDRH_R                  ((uint32)(ECSM_1_BASEADDR+(uint32)0x0058UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PFEDRL_R                  ((uint32)(ECSM_1_BASEADDR+(uint32)0x005CUL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PREAR_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0060UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PRESR_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0065UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PREMR_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0066UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PREAT_R                   ((uint32)(ECSM_1_BASEADDR+(uint32)0x0067UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PREDRH_R                  ((uint32)(ECSM_1_BASEADDR+(uint32)0x0068UL))
  /*
    * @violates @ref REG_ESYS_ESCM_H_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
#define ECSM_1_PREDRL_R                  ((uint32)(ECSM_1_BASEADDR+(uint32)0x006CUL))

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_ECSM_H */

/** @} */
