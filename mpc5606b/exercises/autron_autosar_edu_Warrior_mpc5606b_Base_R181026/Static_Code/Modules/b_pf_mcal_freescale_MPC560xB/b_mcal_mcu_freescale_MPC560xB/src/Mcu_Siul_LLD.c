/**
*   @file    Mcu_Siul_LLD.c
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - SIUL Low level driver implementation.
*   @details Implementation of the SIUL low level driver.
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

#ifndef MCU_SIUL_LLD_C
#define MCU_SIUL_LLD_C

#ifdef __cplusplus
extern "C" {
#endif

/**
*  @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_Siul_LLD_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h, 
* Precautions shall be taken in order to prevent the contents of a header file 
* being included twice This is not a violation since all header files are 
* protected against multiple inclusions
*
* @section Mcu_Siul_LLD_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set 
* the current memory section
*
* @section Mcu_Siul_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR 
* specifications although it exceeds the max length of 31 characters
*
* @section Mcu_Siul_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 11.1, Casting operation to a pointer.
* This violation is due to the Casting pointers to other types used in macros
* for Reading or writing data from address location of controller register
*
* @section Mcu_Siul_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_LLD.h"
#include "Mcu_Siul_LLD.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_Siul_LLD.c
* @implements     DMCU05055, DMCU05056, DMCU05057, DMCU05058, DMCU05059, DMCU05060,
*                 DMCU05061
*/
#define MCU_SIUL_VENDOR_ID_C                    43
/*
* @violates @ref Mcu_Siul_LLD_C_REF_3 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref Mcu_Siul_LLD_C_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SIUL_AR_RELEASE_MAJOR_VERSION_C     4
/*
* @violates @ref Mcu_Siul_LLD_C_REF_3 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref Mcu_Siul_LLD_C_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SIUL_AR_RELEASE_MINOR_VERSION_C     0
/*
* @violates @ref Mcu_Siul_LLD_C_REF_3 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref Mcu_Siul_LLD_C_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_SIUL_AR_RELEASE_REVISION_VERSION_C  3
#define MCU_SIUL_SW_MAJOR_VERSION_C             1
#define MCU_SIUL_SW_MINOR_VERSION_C             0
#define MCU_SIUL_SW_PATCH_VERSION_C             1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ecsm_LLD header file are of the same vendor */
#if (MCU_SIUL_VENDOR_ID_C != MCU_SIUL_VENDOR_ID)
    #error "Mcu_Siul_LLD.c and Mcu_SIUL_LLD.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_Siul_LLD.h header file are of the same Autosar version */

#if ((MCU_SIUL_AR_RELEASE_MAJOR_VERSION_C    != MCU_SIUL_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SIUL_AR_RELEASE_MINOR_VERSION_C    != MCU_SIUL_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SIUL_AR_RELEASE_REVISION_VERSION_C != MCU_SIUL_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_Siul_LLD.c and Mcu_Siul_LLD.h are different"
#endif
/* Check if current file and Mcu_Siul_LLD.h header file are of the same Software version */
#if ((MCU_SIUL_SW_MAJOR_VERSION_C != MCU_SIUL_SW_MAJOR_VERSION) || \
     (MCU_SIUL_SW_MINOR_VERSION_C != MCU_SIUL_SW_MINOR_VERSION) || \
     (MCU_SIUL_SW_PATCH_VERSION_C != MCU_SIUL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_Siul_LLD.c and Mcu_Siul_LLD.h are different"
#endif

/* Check if current file and Mcu_LLD.h header file are of the same Autosar version */
#if ((MCU_SIUL_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SIUL_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SIUL_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_Siul_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h header file are of the same Software version */
#if ((MCU_SIUL_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_SIUL_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_SIUL_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_Siul_LLD.c and Mcu_LLD.h are different"
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


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/* @violates @ref Mcu_Siul_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_Siul_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_GET_DEVICE_INFO_API == STD_ON)
/**
* @brief        This function returns the MCU identifier information
* @details      These information is retrieved from MIDR1 and MIDR2 registers of SIUL IP
*
*
* @param[in,out]     deviceinfo      Pointer for storing the Mcu identifier information
*
* @return none
*
* @pre    none
* @post   Preconditions as text description. Optional tag..
*
* @implements
*/
FUNC (void, MCU_CODE) Mcu_LLD_GetDeviceInfo(P2VAR (Mcu_DeviceInfoType, AUTOMATIC, \
    MCU_APPL_DATA) deviceinfo)
{
   /* MCU Device Part Number */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->partnum_device = (uint16)((REG_READ32(SIUL_MIDR1) & SIUL_MIDR1_PARTNUM) >> \
                                          MCU_SHIFT_SIXTEEN);
   /* MCU Family Part Number */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->partnum_family = (uint8)((REG_READ32(SIUL_MIDR2) & SIUL_MIDR2_PARTNUM)>> \
                                          MCU_SHIFT_EIGHT);
   /* Package Settings */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->pkg = (uint8)((REG_READ32(SIUL_MIDR1) & SIUL_MIDR1_PKG)>>MCU_SHIFT_TEN);
   /* Major Mask Revision */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->major_mask = (uint8)((REG_READ32(SIUL_MIDR1) & SIUL_MIDR1_MAJOR_MASK) >> \
                                       MCU_SHIFT_FOUR);
   /* Minor Mask Revision */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->minor_mask = (uint8)(REG_READ32(SIUL_MIDR1) & SIUL_MIDR1_MINOR_MASK);
   /* Coarse granularity for flash memory size */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->flash_size1 = (uint8)((REG_READ32(SIUL_MIDR2) & \
                                       SIUL_MIDR2_FLASH_SIZE_1 )>>MCU_SHIFT_TWENTY_SEVEN);
   /* Fine granularity for flash memory size */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->flash_size2 = (uint8)(((REG_READ32(SIUL_MIDR2) & \
                                       SIUL_MIDR2_FLASH_SIZE_2))>>MCU_SHIFT_TWENTY_THREE);
   /* Manufacturer */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   (deviceinfo)->manufacturer = (uint8)((REG_READ32(SIUL_MIDR2) & SIUL_MIDR2_SF) >> \
                                       MCU_SHIFT_THIRTY_ONE);
   /* Data flash memory present */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   if((REG_READ32(SIUL_MIDR2) & SIUL_MIDR2_EE) == SIUL_MIDR2_EE)
   {
      (deviceinfo)->data_flash = DATA_FLASH_PRESENT;
   }
   else
   {
      (deviceinfo)->data_flash = DATA_FLASH_NOT_PRESENT;
   }
   /* FlexRay present */
   /* @violates @ref Mcu_Siul_LLD_C_REF_4 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   if((REG_READ32(SIUL_MIDR2) & SIUL_MIDR2_FR) == SIUL_MIDR2_FR)
   {
      (deviceinfo)->flexray = FLEXRAY_PRESENT;
   }
   else
   {
      (deviceinfo)->flexray = FLEXRAY_NOT_PRESENT;
   }
}
#endif /* MCU_GET_DEVICE_INFO_API */

#define MCU_STOP_SEC_CODE
/* @violates @ref Mcu_Siul_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
/*
* @violates @ref Mcu_Siul_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/* Mcu_SIUL_LLD_C */
#endif
/** @} */
