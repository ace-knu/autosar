/**
*   @file    Mcu_Flash_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - File used by MCU to configure some flash parameters.
*   @details This file contains a function used for initializing global parameters for the flash memory.
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
* @section Mcu_Flash_LLD_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_Flash_LLD_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_Flash_LLD_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Mcu_Flash_LLD_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, API could not be made static.
*
* @section Mcu_Flash_LLD_c_REF_5
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_LLD.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @implements     DMCU05097, DMCU05098, DMCU05099, DMCU05100, DMCU05101, DMCU05102,
*                 DMCU05103
*/
#define MCU_FLASH_LLD_VENDOR_ID_C                      43
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_FLASH_LLD_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_FLASH_LLD_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_FLASH_LLD_AR_RELEASE_REVISION_VERSION_C    3
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_FLASH_LLD_SW_MAJOR_VERSION_C               1
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_FLASH_LLD_SW_MINOR_VERSION_C               0
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_FLASH_LLD_SW_PATCH_VERSION_C               1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_LLD.h file are of the same vendor */
#if (MCU_FLASH_LLD_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
    #error "Mcu_Flash_lld.c and Mcu_LLD.h have different vendor ids"
#endif
/* @implements     DMCU06001 */
/* Check if current file and Mcu_LLD.h file are of the same Autosar version */
#if ((MCU_FLASH_LLD_AR_RELEASE_MAJOR_VERSION_C    != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FLASH_LLD_AR_RELEASE_MINOR_VERSION_C    != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FLASH_LLD_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_Flash_lld.c and Mcu_LLD.h are different"
#endif
/* Check if current file and Mcu_LLD.h file are of the same Software version */
#if ((MCU_FLASH_LLD_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
     (MCU_FLASH_LLD_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
     (MCU_FLASH_LLD_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_Flash_lld.c and Mcu_LLD.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_RAMCODE
/*
* @violates @ref Mcu_Flash_LLD_c_REF_1 Repeated include file
* @violates @ref Mcu_Flash_LLD_c_REF_2 Only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"
FUNC(void, MCU_RAM_CODE) Mcu_Flash_Init_Ram(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) \
        ConfigLLDPtr);
FUNC(void, MCU_RAM_CODE) Mcu_Flash_Configure_Ram(VAR(uint32, AUTOMATIC) Mcu_CFlash_Conf, \
        VAR(uint32, AUTOMATIC) Mcu_DFlash_Conf);

#define MCU_STOP_SEC_RAMCODE
/*
* @violates @ref Mcu_Flash_LLD_c_REF_1 Repeated include file
* @violates @ref Mcu_Flash_LLD_c_REF_2 Only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_Flash_LLD_c_REF_1 Repeated include file
* @violates @ref Mcu_Flash_LLD_c_REF_2 Only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"
/*
* @violates @ref Mcu_Flash_LLD_c_REF_4 Required Rule 8.10, API could not be made static.
*/
P2FUNC (void, const, Mcu_Flash_Init)(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) \
        ConfigLLDPtr) = &Mcu_Flash_Init_Ram;
/*
* @violates @ref Mcu_Flash_LLD_c_REF_4 Required Rule 8.10, API could not be made static.
*/
P2FUNC (void, const, Mcu_Flash_Configure)(VAR(uint32, AUTOMATIC) Mcu_CFlash_Conf, \
        VAR(uint32, AUTOMATIC) Mcu_DFlash_Conf) = &Mcu_Flash_Configure_Ram;
/*
* @violates @ref Mcu_Flash_LLD_c_REF_5 Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*/
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Mcu_Flash_LLD_c_REF_1 Repeated include file
* @violates @ref Mcu_Flash_LLD_c_REF_2 Only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"
#define MCU_START_SEC_RAMCODE
/*
* @violates @ref Mcu_Flash_LLD_c_REF_1 Repeated include file
* @violates @ref Mcu_Flash_LLD_c_REF_2 Only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief       This function initializes global settings for the flash memory.
*
* @details     The function initializes settings like Address Pipelining Control, Write Wait State
*              Control, Read Wait State Control, Read-While-Write Control, Page Buffer Configuration,
*              Page Buffer Configuration, Data Prefetch Enable, Instruction Prefetch Enable, Prefetch
*              Limit, Buffer Enable, Arbitration Mode, Master Prefetch Disable, Master Access Protection.
*
* @param[in]      ConfigLLDPtr      Mcu configuration pointer
*
* @return         void
*
* @implements DMCU05104
*
* @violates @ref Mcu_Flash_LLD_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_RAM_CODE) Mcu_Flash_Init_Ram(P2CONST(McuLLD_ConfigType, AUTOMATIC, MCU_APPL_CONST) \
    ConfigLLDPtr)
{
#ifdef IPV_FLASH
  #if ((IPV_FLASH == IPV_FLASH_C90FL3_1024_6_0) || \
        (IPV_FLASH == IPV_FLASH_C90FL_2048_4_0_Nh))  /* if XPC56XXL / XPC56EL70*/
    /** @violates @ref Mcu_Flash_LLD_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
    REG_RMW32(CFLASH_PFCR0, (~((uint32) (CFLASH_PFCR0_B02_APC | CFLASH_PFCR0_B02_WWSC |  CFLASH_PFCR0_B02_RWSC))),\
    /** @violates @ref Mcu_Flash_LLD_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */ \
             (uint32) (ConfigLLDPtr->flashPFCR0));
    /** @violates @ref Mcu_Flash_LLD_c_REF_3 Advisory Rule 11.1: cast from unsigned long to pointer. */
    REG_WRITE32(FLASH_PFAPR, (uint32) (ConfigLLDPtr->flashPFAPR));
  #elif ((IPV_FLASH == IPV_FLASH_C90FL_2048_4_0_238_2048_0_1_238)|| \
         (IPV_FLASH == IPV_FLASH_C90FL_2048_4_0) || \
         (IPV_FLASH == IPV_FLASH_C90FL_2048_4_0_336) || \
         (IPV_FLASH == IPV_FLASH_C90FL3_3072_4_0_3072_0_1)) /*  XPC567XR/XPC56XXA */
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */ 
    REG_RMW32(FLASH_BIUCR0,(~((uint32)(FLASH_BIUCR0_APC | FLASH_BIUCR0_WWSC | FLASH_BIUCR0_RWSC))),\
           (uint32) (ConfigLLDPtr->flashBIUCR0));

    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_WRITE32(FLASH_BIUCR1, (uint32) (ConfigLLDPtr->flashBIUCR1));

    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_WRITE32(FLASH_BIUAPR, (uint32) (ConfigLLDPtr->flashBIUAPR));
  #elif ((IPV_FLASH == IPV_FLASH_C90FG_2048_1_8) || \
         (IPV_FLASH == IPV_FLASH_C90FG_1024_2_0) || \
         (IPV_FLASH == IPV_FLASH_C90FG_512_2_9) || \
         (IPV_FLASH == IPV_FLASH_C90FG_256_1_4)) /* MPC56XXK/XPC56AXP60/XPC560XP50/XPC560XP40 */
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(CFLASH_PFCR0, (~((uint32) (CFLASH_PFCR0_B02_APC | CFLASH_PFCR0_B02_WWSC | \
                  CFLASH_PFCR0_B02_RWSC))), (uint32) (ConfigLLDPtr->flashPFCR0));
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(DFLASH_PFCR1, (~((uint32) (DFLASH_PFCR1_B1_APC | DFLASH_PFCR1_B1_WWSC | \
                  DFLASH_PFCR1_B1_RWSC))), (uint32) (ConfigLLDPtr->flashPFCR1));

    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_WRITE32(FLASH_PFAPR, (uint32) (ConfigLLDPtr->flashPFAPR));
  #elif (IPV_FLASH == IPV_FLASH_C90FG_2_1568_2_6_1) /* if XPC564XB */
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(CFLASH_PFCR0, (~((uint32) (CFLASH_PFCR0_B02_APC |  \
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */ \
              CFLASH_PFCR0_B02_RWSC))), (uint32) (ConfigLLDPtr->flashPFCR0));
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(DFLASH_PFCR1, (~((uint32) (DFLASH_PFCR1_B1_APC |  \
                  DFLASH_PFCR1_B1_RWSC))), (uint32) (ConfigLLDPtr->flashPFCR1));

    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_WRITE32(FLASH_PFAPR, (uint32) (ConfigLLDPtr->flashPFAPR));
  #else /* if XPC560XB */
   /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(CFLASH_PFCR0, (~((uint32) (CFLASH_PFCR0_B02_APC | CFLASH_PFCR0_B02_WWSC | \
              CFLASH_PFCR0_B02_RWSC))), (uint32) (ConfigLLDPtr->flashPFCR0));

     /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(DFLASH_PFCR1, (~((uint32) (DFLASH_PFCR1_B1_APC | DFLASH_PFCR1_B1_WWSC | \
                 DFLASH_PFCR1_B1_RWSC))), (uint32) (ConfigLLDPtr->flashPFCR1));

    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_WRITE32(FLASH_PFAPR, (uint32) (ConfigLLDPtr->flashPFAPR));
  #endif
#endif
}

/*================================================================================================*/
/**
* @brief       This function configures clock dependent settings for the flash memory.
*
* @details     The function configures clock dependent settings like Address Pipelining Control,
*              Write Wait State Control, Read Wait State Control.
*
* @param[in]      Mcu_CFlash_Conf      Mcu code flash configuration value
* @param[in]      Mcu_DFlash_Conf      Mcu data flash configuration value
*
* @return         void
*
* @implements DMCU05105
*
* @violates @ref Mcu_Flash_LLD_c_REF_4 Required Rule 8.10, API could not be made static.
*/
FUNC(void, MCU_RAM_CODE) Mcu_Flash_Configure_Ram(VAR(uint32, AUTOMATIC) Mcu_CFlash_Conf, \
    VAR(uint32, AUTOMATIC) Mcu_DFlash_Conf)
{
#ifdef IPV_FLASH
  #if ((IPV_FLASH == IPV_FLASH_C90FL3_1024_6_0) || \
        (IPV_FLASH == IPV_FLASH_C90FL_2048_4_0_Nh))  /* if XPC56XXL / XPC56EL70*/
    /* for MISRA */
    (void) Mcu_DFlash_Conf;
    /* update PFCR0 with values corresponding to new clock setting */
    REG_RMW32(CFLASH_PFCR0, (CFLASH_PFCR0_B02_APC | CFLASH_PFCR0_B02_WWSC | CFLASH_PFCR0_B02_RWSC), 
             /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
             (Mcu_CFlash_Conf & (CFLASH_PFCR0_B02_APC | CFLASH_PFCR0_B02_WWSC | CFLASH_PFCR0_B02_RWSC))); 
  #elif ((IPV_FLASH == IPV_FLASH_C90FL_2048_4_0_238_2048_0_1_238)|| \
         (IPV_FLASH == IPV_FLASH_C90FL_2048_4_0) || \
         (IPV_FLASH == IPV_FLASH_C90FL_2048_4_0_336) || \
         (IPV_FLASH == IPV_FLASH_C90FL3_3072_4_0_3072_0_1 )) /* XPC567XR/XPC56XXA */
    (void) Mcu_DFlash_Conf;
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 MISRA 2004 Rule 11.1, cast from unsigned long to pointer */ 
    if( (uint32)(Mcu_CFlash_Conf & FLASH_BIUCR0_APC) <  \
        (uint32)(REG_READ32(FLASH_BIUCR0) & FLASH_BIUCR0_APC ))
    {
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(FLASH_BIUCR0, FLASH_BIUCR0_RWSC, (Mcu_CFlash_Conf & FLASH_BIUCR0_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(FLASH_BIUCR0, FLASH_BIUCR0_APC, (Mcu_CFlash_Conf & FLASH_BIUCR0_APC));
    }
    else
    {
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(FLASH_BIUCR0, FLASH_BIUCR0_APC, (Mcu_CFlash_Conf & FLASH_BIUCR0_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(FLASH_BIUCR0, FLASH_BIUCR0_RWSC, (Mcu_CFlash_Conf & FLASH_BIUCR0_RWSC));
    }
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(FLASH_BIUCR0, FLASH_BIUCR0_WWSC, (Mcu_CFlash_Conf & FLASH_BIUCR0_WWSC));
  #elif ((IPV_FLASH == IPV_FLASH_C90FG_2048_1_8) || \
         (IPV_FLASH == IPV_FLASH_C90FG_1024_2_0) || \
         (IPV_FLASH == IPV_FLASH_C90FG_512_2_9) || \
         (IPV_FLASH == IPV_FLASH_C90FG_256_1_4)) /* MPC56XXK/XPC56AXP60/XPC560XP50/XPC560XP40 */
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    if( (uint32)(Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC) < \
            (uint32)(REG_READ32(CFLASH_PFCR0) & CFLASH_PFCR0_B02_APC ))
    {
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_RWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_APC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_RWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_APC, (Mcu_DFlash_Conf & DFLASH_PFCR1_B1_APC));
    }
    else
    {
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_APC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_RWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_APC, (Mcu_DFlash_Conf & DFLASH_PFCR1_B1_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_RWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_RWSC));
    }
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_WWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_WWSC));
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_WWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_WWSC));
  #elif (IPV_FLASH == IPV_FLASH_C90FG_2_1568_2_6_1) /* if XPC564XB */
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    if( (uint32)(Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC) <  \
            (uint32)(REG_READ32(CFLASH_PFCR0) & CFLASH_PFCR0_B02_APC ))
    {
        /** @remarks Covers MCU116 */
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_RWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_APC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_RWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_APC, (Mcu_DFlash_Conf & DFLASH_PFCR1_B1_APC));
    }
    else
    {
        /** @remarks Covers MCU116 */
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_APC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_RWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_APC, (Mcu_DFlash_Conf & DFLASH_PFCR1_B1_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_RWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_RWSC));
    }
  #else /* if XPC560XB */
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    if( (uint32)(Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC) < \
            (uint32)(REG_READ32(CFLASH_PFCR0) & CFLASH_PFCR0_B02_APC ))
    {
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_RWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_APC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_RWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_APC, (Mcu_DFlash_Conf & DFLASH_PFCR1_B1_APC));
    }
    else
    {
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_APC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_RWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_RWSC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_APC, (Mcu_DFlash_Conf & DFLASH_PFCR1_B1_APC));
        /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
        REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_RWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_RWSC));
    }
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(CFLASH_PFCR0, CFLASH_PFCR0_B02_WWSC, (Mcu_CFlash_Conf & CFLASH_PFCR0_B02_WWSC));
    /* @violates @ref Mcu_Flash_LLD_c_REF_3 Cast from unsigned long to pointer */
    REG_RMW32(DFLASH_PFCR1, DFLASH_PFCR1_B1_WWSC,(Mcu_DFlash_Conf & DFLASH_PFCR1_B1_WWSC));
  #endif
#endif
}

#define MCU_STOP_SEC_RAMCODE
/*
* @violates @ref Mcu_Flash_LLD_c_REF_1 Repeated include file
* @violates @ref Mcu_Flash_LLD_c_REF_2 Only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
