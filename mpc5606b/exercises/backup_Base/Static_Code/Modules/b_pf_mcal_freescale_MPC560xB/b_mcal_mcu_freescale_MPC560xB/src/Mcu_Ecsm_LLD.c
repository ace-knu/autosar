/**
*   @file    Mcu_Ecsm_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - ECSM.
*   @details File containing the low level driver of the ECSM IP.
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
* @section Mcu_Ecsm_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory 
* section
*
* @section Mcu_Ecsm_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_Ecsm_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to the casting pointers 
* to other types used in macros for reading or writing data from address location of controller register.
*
* @section Mcu_Ecsm_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash. Define name is required by the AUTOSAR 
* specifications although it exceeds the max length of 31 characters
*
* @section Mcu_Ecsm_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required. This variables cannot
* be made static, because they are used by applications.
*
* @section Mcu_Ecsm_LLD_C_REF_6
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
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_Ecsm_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_Ecsm_LLD.c
* @implements     DMCU05055, DMCU05056, DMCU05057, DMCU05058, DMCU05059, DMCU05060,
*                 DMCU05061
*/
#define MCU_ECSM_VENDOR_ID_C                    43
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_ECSM_AR_RELEASE_MAJOR_VERSION_C     4
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_ECSM_AR_RELEASE_MINOR_VERSION_C     0
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_4 MISRA 2004 Required Rule 1.4, Identifier clash
*/
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_6 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_ECSM_AR_RELEASE_REVISION_VERSION_C  3
#define MCU_ECSM_SW_MAJOR_VERSION_C             1
#define MCU_ECSM_SW_MINOR_VERSION_C             0
#define MCU_ECSM_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ecsm_LLD header file are of the same vendor */
#if (MCU_ECSM_VENDOR_ID_C != MCU_ECSM_VENDOR_ID)
    #error "Mcu_Ecsm_LLD.c and Mcu_ECSM_LLD.h have different vendor ids"
#endif
/*
* @implements     DMCU06001
*/
/* Check if current file and Mcu_Ecsm_LLD.h header file are of the same Autosar version */

#if ((MCU_ECSM_AR_RELEASE_MAJOR_VERSION_C    != MCU_ECSM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_ECSM_AR_RELEASE_MINOR_VERSION_C    != MCU_ECSM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_ECSM_AR_RELEASE_REVISION_VERSION_C != MCU_ECSM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_ECSM_LLD.c and Mcu_ECSM_LLD.h are different"
#endif
/* Check if current file and Mcu_Ecsm_LLD.h header file are of the same Software version */
#if ((MCU_ECSM_SW_MAJOR_VERSION_C != MCU_ECSM_SW_MAJOR_VERSION) || \
     (MCU_ECSM_SW_MINOR_VERSION_C != MCU_ECSM_SW_MINOR_VERSION) || \
     (MCU_ECSM_SW_PATCH_VERSION_C != MCU_ECSM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_Ecsm_LLD.c and Mcu_Ecsm_LLD.h are different"
#endif

/* Check if current file and Mcu_LLD.h header file are of the same Autosar version */
#if ((MCU_ECSM_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_ECSM_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_ECSM_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_Ecsm_LLD.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h header file are of the same Software version */
#if ((MCU_ECSM_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_ECSM_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_ECSM_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_Ecsm_LLD.c and Mcu_LLD.h are different"
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
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/*
* @brief          MUDCR register configuration
* @details        The function applies the user settings specified by the input 
*                 parameter mudcr_value to the miscellaneous User-Defined 
*                 Control Register (MUDCR).
*
* @param[in]      mudcr_value The value to be written into MUDCR.
*
* @implements    DMCU05150
*/
#ifdef IPV_ECSM
  #if ((IPV_ECSM == IPV_ECSM_01_00_02_00) || (IPV_ECSM == IPV_ECSM_01_00_00_04) || (IPV_ECSM == IPV_ECSM_01_00_00_08)) /*  XPC56XXL / XPC56AXP60 / MPC56XXK */
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_5 Required Rule 8.10 Object could be made static
*/
FUNC(void, MCU_CODE) Ecsm_SetMUDCR(VAR(uint32, AUTOMATIC) mudcr_value,VAR(uint32, AUTOMATIC) mudcr1_value) {
  #else
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_5 Required Rule 8.10 Object could be made static
*/
FUNC(void, MCU_CODE) Ecsm_SetMUDCR(VAR(uint32, AUTOMATIC) mudcr_value) {
  #endif
    /* @violates @ref Mcu_Ecsm_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE32(ECSM_MUDCR_R, (uint32)mudcr_value);
  #if ((IPV_ECSM == IPV_ECSM_01_00_02_00) || (IPV_ECSM == IPV_ECSM_01_00_00_04)) /* XPC56XXL / XPC56AXP60*/
    if(ECSM_MUDCR_1_ENABLE == (mudcr1_value & ECSM_MUDCR_1_ENABLE))
    {
        /* @violates @ref Mcu_Ecsm_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(ECSM_1_MUDCR_R, (((uint32)mudcr1_value) & (ECSM_SET_MUDCR_1)));
    }
}
  #elif (IPV_ECSM == IPV_ECSM_01_00_00_08) /*  MPC56XXK */
    if(mudcr1_value & (ECSM_SET_MUDCR | ECSM_SET_MUDCR_1))
    {
        /* @violates @ref Mcu_Ecsm_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
        REG_WRITE32(ECSM_1_MUDCR_R, (((uint32)mudcr1_value) & (ECSM_SET_MUDCR | ECSM_SET_MUDCR_1)));
    }
}
  #else
}
  #endif
#endif

#ifdef IPV_ECSM /*  XPC5602D/XPC5604B/XPC5607B/XPC56XXA 4M/MPC5676R/XPC56XXA 2M/XPC56AXP60/XPC560XP50/XPC560XP40*/
  #if ((IPV_ECSM == IPV_ECSM_10_10_00_12) || (IPV_ECSM == IPV_ECSM_01_00_00_09) || \
       (IPV_ECSM == IPV_ECSM_01_00_01_04) || (IPV_ECSM == IPV_ECSM_00_00_00_20) || \
       (IPV_ECSM == IPV_ECSM_01_00_02_02) || (IPV_ECSM == IPV_ECSM_01_00_00_04) || \
       (IPV_ECSM == IPV_ECSM_01_00_01_02) || (IPV_ECSM == IPV_ECSM_01_00_02_07) || \
       (IPV_ECSM == IPV_ECSM_B1_00_00_08))
#if (MCU_GET_RAM_STATE_API == STD_ON)
/*================================================================================================*/
/*
* @brief        This function initialiaze the ECSM registers
* @details      This function evaluate the SRAM 1-bit Reporting and Enable SRAM Non-Correctable Reporting
*
* @param[in]      void
*
* @return         void
*
* @implements     DMCU05160
*
*/
/*================================================================================================*/
FUNC(void, MCU_CODE) Ecsm_GetRamInit(VAR (void, MCU_VAR))
{
    /* @violates @ref Mcu_Ecsm_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
    REG_WRITE8(ECSM_ECR_R, (uint8)ECSM_MASK_ER1BR_ERNCR_ENABLE);
}

/*================================================================================================*/
/**
* @brief          This function check the ECSM registers
* @details        This function evaluate the status of SRAM
*
* @param[in]      void
*
* @return         Mcu_RamStateType
* @retval MCU_RAMSTATE_INVALID     Ram content is not valid or unknown (default).
* @retval MCU_RAMSTATE_VALID       Ram content is valid.
*
* @implements     DMCU05170
*
*/
/*================================================================================================*/

FUNC (Mcu_RamStateType, MCU_CODE) Ecsm_GetRamState(VAR (void, MCU_VAR))
{
   VAR (Mcu_RamStateType, AUTOMATIC) RamStateValue = MCU_RAMSTATE_INVALID;

    /* @violates @ref Mcu_Ecsm_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   if (ECSM_MASK_R1BC == (REG_READ8(ECSM_ESR_R) & (ECSM_MASK_R1BC))) 
   {
      RamStateValue = MCU_RAMSTATE_INVALID;
   }
    /* @violates @ref Mcu_Ecsm_LLD_C_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */
   else if (ECSM_MASK_RNCE == (REG_READ8(ECSM_ESR_R) & (ECSM_MASK_RNCE)))
   {
       RamStateValue = MCU_RAMSTATE_INVALID;
   }
   else
   {
       RamStateValue = MCU_RAMSTATE_VALID;
   }
   return (Mcu_RamStateType) RamStateValue;
}

#endif /* #if (MCU_GET_RAM_STATE_API == STD_ON) */
#endif 
#endif /* #ifdef IPV_ECSM */

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_Ecsm_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_Ecsm_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
*                            before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
