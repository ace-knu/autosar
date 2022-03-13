/**
*   @file    Fls_Ac.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Position independent erase and write access code.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : Flash_Memory
*   Dependencies         : 
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
* @section fls_ac_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_ac_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_ac_c_REF_3
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* Caused by type signedness mismatch between the TRUE and FALSE macros which are defined as signed
* integers (PLATFORM056) and the boolean data type (PLATFORM027) which is defined as uint8.
*
* @section fls_ac_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.
*
* @section fls_ac_c_REF_5
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters. These Mcro  names are decided as per AUTOSAR guideline.
*
* @section fls_ac_c_REF_6
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is because of complex statement.
*
* @section fls_ac_c_REF_7
* Violates MISRA 2004 Advisory Rule 12.6, Booleans operands are not used for logical
* operators '&&', '||' and '!'
* This violation because of it is not effectively boolean
*
* @section fls_ac_c_REF_8
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. 
* This violation is because of complex statement
*
* @section fls_ac_c_REF_9
* Violates MISRA 2004 Required Rule 8.1, Functions shall have prototype declarations and the prototype
* shall be visible at both the function definition and call.  
* This violation is because of it is function pointer
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Fls_Ac.c
* @implements     DFLS02065
*/
#include "Fls.h"
#include "Reg_eSys_FLASHC.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Fls_Ac.c
* @implements     DFLS02068
*/
#define FLS_AC_VENDOR_ID_C                      43
/*
* @violates @ref fls_ac_c_REF_5 Identifiers more than 31 characters.
*/
#define FLS_AC_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref fls_ac_c_REF_5 Identifiers more than 31 characters.
*/
#define FLS_AC_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref fls_ac_c_REF_5 Identifiers more than 31 characters.
*/
#define FLS_AC_AR_RELEASE_REVISION_VERSION_C    3
#define FLS_AC_SW_MAJOR_VERSION_C               1
#define FLS_AC_SW_MINOR_VERSION_C               0
#define FLS_AC_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
/*
* @violates @ref fls_ac_c_REF_3 The value of an expression of
* an integer shall no be implicitly converted to a different underlying type if it is not a
* conversion to a wider integer type of the same signedness
*/
#if (FLS_AC_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Ac.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls_Ac header file are of the same Autosar version */
#if ((FLS_AC_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AC_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AC_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fls_Ac.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_AC_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_AC_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_AC_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fls_Ac.c and Fls.h are different"
#endif

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
/**
* @brief    Start of Fls section CODE AC 
*
* @violates @ref fls_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_START_SEC_CODE_AC
#else
#define FLS_START_SEC_CODE
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */
/* 
* @violates @ref fls_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "MemMap.h"

FUNC(void, FLS_CODE) Fls_LLD_AccessCode(P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) regBasePtr,
                                        P2FUNC(void, FLS_CODE, CallBack)(), P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) timerCounterAC);
/**
* @brief         This function performs flash program/erase operation
* @details
*
* @param[in]     regBasePtr     This is the register base pointer for monitoring of Flash registers
* @param[in]     CallBack       To access the call back function
* @param[in]     timerCounterAC To come out from the while loop in case of HW failure.
*
* @return        Description of the returned value
*
* @note
*/
/* 
* @violates @ref fls_ac_c_REF_4 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_LLD_AccessCode(P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) regBasePtr,
                                        P2FUNC(void, FLS_CODE, CallBack)(), P2VAR(volatile uint32, AUTOMATIC, FLS_CODE) timerCounterAC)
{
    /* start internal erase/program sequence */
    /* @violates @ref fls_ac_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
    regBasePtr[FLASHMEM_MCR] |= MCR_EHV;
    /* @violates @ref fls_ac_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
    /* @violates @ref fls_ac_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!' */
    /* @violates @ref fls_ac_c_REF_8 Side effects on right hand of logical operator: '||' or '&&' */
    while((!(regBasePtr[FLASHMEM_MCR] & MCR_DONE)) && (0U < *timerCounterAC))
    {
        (*timerCounterAC)--;
        if (NULL_PTR != CallBack)
        {
          /* @violates @ref fls_ac_c_REF_9 Functions shall have prototype declarations and the prototype
          * shall be visible at both the function definition and call
          */ 
          CallBack();
        }
    }
}
/**
* @brief    Stop of Fls section CODE AC 
*
* @violates @ref fls_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_STOP_SEC_CODE_AC
#else
#define FLS_STOP_SEC_CODE
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */
/* 
* @violates @ref fls_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
