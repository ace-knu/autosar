/**
*   @file    Reg_eSys_eMIOS.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSYS_EMIOS_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include"
* MemMap.h included after each section define in order to set the current memory section
*
* @section Reg_eSYS_EMIOS_c_2
* Violates MISRA 2004 Required Rule 19.15, :  Repeated include files,  Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Reg_eSYS_EMIOS_c_3
* Violates MISRA 2004 Required Rule 20.2, This violation is not fixed since we have not used any
* Standard library macros.
*
*@section Reg_eSYS_EMIOS_c_4
* Violates MISRA 2004 Required Rule 5.1, This violation is not fixed since naming convention of 
* identifiers(internal and external) are followed as per Autosar standards, some times which may
* exceeds more than 31 characters.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "modules.h"
#include "Reg_eSys.h"
#include "Reg_eSys_eMIOS.h"


/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/**
* @brief   eMIOS Module Id, The define value is 100 for GPT, 121 for PWM and 122 for ICU
*/
/*
* @violates @ref Reg_eSYS_EMIOS_c_3 This is not a standard library macro, 
*/
#define EMIOS_COMMON_MODULE_ID                122

/**
* @brief   Source file version information
*/
#define REG_ESYS_EMIOS_C_VENDOR_ID                          43
/*
* @violates @ref Reg_eSYS_EMIOS_c_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_C_AR_RELEASE_MAJOR_VERSION           4
/*
* @violates @ref Reg_eSYS_EMIOS_c_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_C_AR_RELEASE_MINOR_VERSION           0
/*
* @violates @ref Reg_eSYS_EMIOS_c_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_C_AR_RELEASE_REVISION_VERSION        3
/*
* @violates @ref Reg_eSYS_EMIOS_c_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_C_SW_MAJOR_VERSION                   1
/*
* @violates @ref Reg_eSYS_EMIOS_c_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_C_SW_MINOR_VERSION                   0
/*
* @violates @ref Reg_eSYS_EMIOS_c_4 This is required as per autosar Requirement, 
*/
#define REG_ESYS_EMIOS_C_SW_PATCH_VERSION                   1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and header file are of the same Autosar version */
#if ((REG_ESYS_EMIOS_C_AR_RELEASE_MAJOR_VERSION != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (REG_ESYS_EMIOS_C_AR_RELEASE_MINOR_VERSION != MODULES_AR_RELEASE_MINOR_VERSION_H))
    #error "AutoSar Version Numbers of Reg_eSys_eMIOS.c and modules.h are different"
#endif
#endif

/* Check if source file and Reg_eSys_eMIOS.h are of the same vendor */
#if (REG_ESYS_EMIOS_C_VENDOR_ID != REG_ESYS_EMIOS_H_VENDOR_ID)
    #error "Reg_eSys_eMIOS.c and Reg_eSys_eMIOS.h have different vendor ids"
#endif

/* Check if source file and header file are of the same Autosar version */
#if ((REG_ESYS_EMIOS_C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_H_AR_RELEASE_MAJOR_VERSION) || \
        (REG_ESYS_EMIOS_C_AR_RELEASE_MINOR_VERSION !=  \
                                                   REG_ESYS_EMIOS_H_AR_RELEASE_MINOR_VERSION) || \
        (REG_ESYS_EMIOS_C_AR_RELEASE_REVISION_VERSION !=  \
                                                   REG_ESYS_EMIOS_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Reg_eSys_eMIOS.c and Reg_eSys_eMIOS.h are different"
#endif


/* Check if source file and header file are of the same Software version */
#if ((REG_ESYS_EMIOS_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_H_SW_MAJOR_VERSION)  || \
        (REG_ESYS_EMIOS_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_H_SW_MINOR_VERSION)  || \
        (REG_ESYS_EMIOS_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Reg_eSys_eMIOS.c and Reg_eSys_eMIOS.h are different"
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


#if ((USE_GPT_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==100))
/*
* @violates @ref Reg_eSYS_EMIOS_c_3 This is not a standard library macro, 
*/
    #define EMIOS_CONST (GPT_CONST)
    #define GPT_START_SEC_CONST_32
    #include "MemMap.h"
#endif /* (USE_GPT_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==100) */


#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==121))
/*
* @violates @ref Reg_eSYS_EMIOS_c_3 This is not a standard library macro, 
*/
    #define EMIOS_CONST (PWM_CONST)
    #define PWM_START_SEC_CONST_32
    /* 
    * @violates @ref Reg_eSYS_EMIOS_c_1 #include statements in a file should only be preceded
    *        by other preprocessor directives or comments.  
    */
    /*
    * @violates @ref Reg_eSYS_EMIOS_c_2 Precautions shall be taken in order to prevent the contents
    *        of a header file being included twice..
    */
    #include "MemMap.h"
#endif /* (USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==121) */


#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON) &&  \
                                                               (EMIOS_COMMON_MODULE_ID==122))
/*
* @violates @ref Reg_eSYS_EMIOS_c_3 This is not a standard library macro, 
*/                                                               
    #define EMIOS_CONST (ICU_CONST)
    #define ICU_START_SEC_CONST_32
    /* 
    * @violates @ref Reg_eSYS_EMIOS_c_1 #include statements in a file should only be preceded
    *        by other preprocessor directives or comments.  
    */
    /*
    * @violates @ref Reg_eSYS_EMIOS_c_2 Precautions shall be taken in order to prevent the contents
    *        of a header file being included twice..
    */
    #include "MemMap.h"
#endif /* (USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON) &&
        *                                                           (EMIOS_COMMON_MODULE_ID==122) */


#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_OFF) && \
     (USE_MCU_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==101))

/*
* @violates @ref Reg_eSYS_EMIOS_c_3 This is not a standard library macro, 
*/
     #define EMIOS_CONST (MCU_CONST)
    #define MCU_START_SEC_CONST_32
    /* 
    * @violates @ref Reg_eSYS_EMIOS_c_1 #include statements in a file should only be preceded
    *        by other preprocessor directives or comments.  
    */
    /*
    * @violates @ref Reg_eSYS_EMIOS_c_2 Precautions shall be taken in order to prevent the contents
    *        of a header file being included twice..
    */
    #include "MemMap.h"
#endif



#if ( ((USE_GPT_MODULE==STD_ON)  && (EMIOS_COMMON_MODULE_ID==100)) || \
      ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON)  && (EMIOS_COMMON_MODULE_ID==121)) || \
      ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON)  && \
       (EMIOS_COMMON_MODULE_ID==122)) || \
      ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_OFF) && \
       (USE_MCU_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==101)) )


/**
* @brief EMIOS base address array
*/
/*
* @violates @ref Reg_eSYS_EMIOS_c_3 This is not a standard library macro, 
*/
CONST(uint32, EMIOS_CONST) EMIOS_BASE_ADDR[] = {

#ifdef  EMIOSA_BASEADDR
/**
* @brief the platform includes only one emios module
*/
        EMIOSA_BASEADDR
#else
/**
* @brief on several platform there is only one emios without any index
*/
        EMIOS_BASEADDR
#endif

#ifdef  EMIOSB_BASEADDR
/**
* @brief check if second emios is available on the platform
*/
        ,EMIOSB_BASEADDR
#endif

#ifdef  EMIOSC_BASEADDR
/**
* @brief check if third emios is available on the platform
*/
        ,EMIOSC_BASEADDR
#endif
};

#endif /* module check */



#if ((USE_GPT_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==100))

#define GPT_STOP_SEC_CONST_32
/* 
* @violates @ref Reg_eSYS_EMIOS_c_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.  
*/
/*
* @violates @ref Reg_eSYS_EMIOS_c_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice..
*/
#include "MemMap.h"
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==121))
#define PWM_STOP_SEC_CONST_32
/* 
* @violates @ref Reg_eSYS_EMIOS_c_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.  
*/
/*
* @violates @ref Reg_eSYS_EMIOS_c_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice..
*/
#include "MemMap.h"
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_ON) && \
     (EMIOS_COMMON_MODULE_ID==122))

#define ICU_STOP_SEC_CONST_32
/* 
* @violates @ref Reg_eSYS_EMIOS_c_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.  
*/
/*
* @violates @ref Reg_eSYS_EMIOS_c_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice..
*/
#include "MemMap.h"
#endif

#if ((USE_GPT_MODULE==STD_OFF) && (USE_PWM_MODULE==STD_OFF) && (USE_ICU_MODULE==STD_OFF) && \
     (USE_MCU_MODULE==STD_ON) && (EMIOS_COMMON_MODULE_ID==101))

#define MCU_STOP_SEC_CONST_32
/* 
* @violates @ref Reg_eSYS_EMIOS_c_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.  
*/
/*
* @violates @ref Reg_eSYS_EMIOS_c_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice..
*/
#include "MemMap.h"
#endif






/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif
/** @} */
