/**
*   @file    Mcu_eMIOS_LLD.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
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
* @section Mcu_eMIOS_LLD_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                                       before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003
*
* @section Mcu_eMIOS_LLD_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, :  Repeated include files,  Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_eMIOS_LLD_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, :cast from unsigned long to pointer.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section Mcu_eMIOS_LLD_C_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section Mcu_eMIOS_LLD_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required. This variables cannot
* be made static, because they are used by applications.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_eMIOS_LLD.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/* @implements     DMCU05411, DMCU05412, DMCU05413, DMCU05414, DMCU05415,
*                 DMCU05416, DMCU05417
*/
#define MCU_EMIOS_LLD_C_VENDOR_ID           43
/* @violates @ref Mcu_eMIOS_LLD_C_REF_4 Identifier exceeds 31 characters*/
#define MCU_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION            4
/* @violates @ref Mcu_eMIOS_LLD_C_REF_4 Identifier exceeds 31 characters*/
#define MCU_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION            0
/* @violates @ref Mcu_eMIOS_LLD_C_REF_4 Identifier exceeds 31 characters*/
#define MCU_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION         3
/* @violates @ref Mcu_eMIOS_LLD_C_REF_4 Identifier exceeds 31 characters*/
#define MCU_EMIOS_LLD_SW_MAJOR_VERSION_C                    1
/* @violates @ref Mcu_eMIOS_LLD_C_REF_4 Identifier exceeds 31 characters*/
#define MCU_EMIOS_LLD_SW_MINOR_VERSION_C                    0
/* @violates @ref Mcu_eMIOS_LLD_C_REF_4 Identifier exceeds 31 characters*/
#define MCU_EMIOS_LLD_SW_PATCH_VERSION_C                    1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mcu_eMIOS_LLD header file are of the same vendor */
#if (MCU_EMIOS_LLD_C_VENDOR_ID != MCU_EMIOS_LLD_H_VENDOR_ID)
    #error "Mcu_eMIOS_LLD.c and Mcu_eMIOS_LLD.h have different vendor ids"
#endif
/* Check if current file and Mcu_eMIOS_LLD header file are of the same Autosar version */
#if ((MCU_EMIOS_LLD_C_AR_RELEASE_MAJOR_VERSION    != MCU_EMIOS_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_EMIOS_LLD_C_AR_RELEASE_MINOR_VERSION    != MCU_EMIOS_LLD_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_EMIOS_LLD_C_AR_RELEASE_REVISION_VERSION != MCU_EMIOS_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_eMIOS_LLD.c and Mcu_eMIOS_LLD.h are different"
#endif
/* Check if current file and Mcu_eMIOS_LLD header file are of the same Software version */
#if ((MCU_EMIOS_LLD_SW_MAJOR_VERSION_C != MCU_EMIOS_LLD_H_SW_MAJOR_VERSION) || \
     (MCU_EMIOS_LLD_SW_MINOR_VERSION_C != MCU_EMIOS_LLD_H_SW_MINOR_VERSION) || \
     (MCU_EMIOS_LLD_SW_PATCH_VERSION_C != MCU_EMIOS_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcu_eMIOS_LLD.c and Mcu_eMIOS_LLD.h are different"
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
* @violates @ref Mcu_eMIOS_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
/*
* @violates @ref Mcu_eMIOS_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                                 statements and comments before '#include'
*/
#include "MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief      Initializes the EMIOS MCR register for EMIOS_A and EMIOS_B
* @details function to initialize the Emios MCR register value configured
*
* @param[in]      ConfigLLDPtr
*                 
* @param[out]     None
* @param[in,out]  None
*
* @retval None
* 
* @api
* @implements     DMCU05420
*/
/*
* @violates @ref Mcu_eMIOS_LLD_C_REF_5 Required Rule 8.10 Object could be made static
*/
FUNC (void, MCU_CODE) Mcu_EMIOS_Init (P2CONST(eMIOS_ConfigType, AUTOMATIC, MCU_APPL_CONST) \
       ClockPtr)
{
    VAR(uint32, AUTOMATIC) i=0U;

    /* Configure EMIOS_MCR */
    for (i=0U; i<EMIOS_NB_MODULES; i++)
    {
        /* @violates @ref Mcu_eMIOS_LLD_C_REF_3 Cast from unsigned long to pointer */
        REG_WRITE32(EMIOS_MCR(i), ClockPtr->EmiosCr[i]);
    }

}

#define MCU_STOP_SEC_CODE
/*
* @violates @ref Mcu_eMIOS_LLD_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
/*
* @violates @ref Mcu_eMIOS_LLD_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                                 statements and comments before '#include'
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
