/**
*   @file    Fls.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Flash driver source code.
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
* @section fls_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long
*
* @section fls_c_REF_3
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'.
* This violation is because of complex statement
*
* @section fls_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour
* This violation is because of complex statement
*
* @section fls_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* This violation is not fixed since if hardware error is detected it should return from the function
*
* @section fls_c_REF_6
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* Return from function as soon as the read/write/erase/operation finished
*
* @section fls_c_REF_7
* Violates MISRA 2004 Advisory Rule 12.6, Booleans operands are not used for logical
* operators '&&', '||' and '!'
* This violation because of it is not effectively boolean
*
* @section fls_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating
* contents in that address.
*
* @section fls_c_REF_9
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_c_REF_10
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is because of complex statement
*
* @section fls_c_REF_11
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.
*
* @section fls_c_REF_12
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const and
* volatile qualification from the type address by a pointer
* Because of removing the const qualification from the type address by a pointer
*
* @section fls_c_REF_13
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_c_REF_14
* Violates MISRA 2004 Required Rule 17.2, Pointer subtraction shall only be applied to pointers
* that address elements of the same array
* Due to the pointers that address elements are not the same array
*
* @section fls_c_REF_15
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters. These Mcro  names are decided as per AUTOSAR guideline.
*
* @section fls_c_REF_16
* Violates MISRA 2004 Required Rule 19.4, : C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*
* @section fls_c_REF_17
* Violates MISRA 2004 Required Rule 14.10,
* All if ... else if constructs shall be terminated with an else clause.
* This violation is due to CER implementation
*
* @section fls_c_REF_18
* Violates MISRA 2004 Required Rule 13.7,
* Boolean operations whose results are invariant shall not be permitted.
* Logical expression is required for this comparision
*
* @section fls_c_REF_19
* Violates MISRA 2004 Required Rule 8.12,
* When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
* The size of the required array eliment is fixed for one compiler. But across compilers this size
* will vary. So in this array definition specific size is not mentioned.
*
* @section fls_c_REF_20
* Violates MISRA 2004 Required Rule 10.1,
* The value of an expression of integer type shall not be implicitly converted to a different underlying type if:
* a. it is not a conversion to a wider integer type of the same signedness, or
* b. the expression is complex, or
* c. the expression is not constant and is a function argument, or
* d. the expression is not constant and is a return expression.
* The expression is constant so as per above part (c) this expression is required
*
* @section fls_c_REF_21
* Violates MISRA 2004 Required Rule 20.2,
* The name of standard library macros, objects and functions shall not be reused.
* This violation is because of library macros, objects and functions are reused
*
* @section fls_c_REF_22
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within 
* a single function.
* This violation is because of Objects are defined global but used within a single function
*
* @section fls_c_REF_23 
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness
* The pointer subtraction is made inside while loop and due to its condition the subtraction 
* result is always positive and therefore it can be casted to unsigned. 
*
* @section fls_c_REF_27
* Violates MISRA 2004 Required Rule 14.6, more than one 'break' terminates loop
* Once abnormal condition is indicated, the loop is terminated by 'break'. Since 
* there are handled several abnormal conditions, the loop contains more
* than one 'break'.    
*   
* @section fls_c_REF_28
* Violates MISRA 2004 Advisory Rule 12.1, Use of mixed mode arithmetic
* This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed
* to the macro. The care is taken for the parameters sent as inputs to the macro and hence unintended truncation of values
* would not result.
*
* @section fls_c_REF_29
* Violates MISRA 2004 Required Rule 14.1,
* There shall be no unreachable code
* This violation is due to a specific testing configuration for flash timeouts (not possible in real use case) that creates not reachable code
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @implements     DFLS02064 */
#include "Fls.h"
#include "Fls_InternalTypes.h"
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
*/
#if (FLS_DEM_ERROR_DETECT == STD_ON)
/**
* @violates @ref fls_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Dem.h"
#endif

#if( FLS_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */

#include "SchM_Fls.h"
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
*/
#include "Reg_eSys_FLASHC.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @implements     DFLS02068 */
#define FLS_VENDOR_ID_C                      43U
#define FLS_AR_RELEASE_MAJOR_VERSION_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_C       0
/*
* @violates @ref fls_c_REF_13 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_AR_RELEASE_REVISION_VERSION_C    3
#define FLS_SW_MAJOR_VERSION_C               1
#define FLS_SW_MINOR_VERSION_C               0
#define FLS_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fls.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fls.c and Fls.h are different"
#endif
/* Check if current file and Dem header file are of the same version */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fls.c and Dem.h are different"
    #endif
#endif
#endif
/* Check if current file and DET header file are of the same version */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fls.c and Det.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/**
    @brief fill pattern used to clear write and erase access code in RAM
*/
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_AC_UNLOAD_PATTERN 0xffffffffU
#endif

/**
    @brief Calculate total flash size in bytes
*/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_TOTAL_SIZE (Fls_ConfigPtr->sectorEndAddr[Fls_ConfigPtr->sectorCount - 1U] + 1U)
#endif

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/
/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_START_SEC_CONST_UNSPECIFIED
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
*/
#include "MemMap.h"


#define FLS_LLD_FLASH_SECTOR_COUNT 23U

/**
* @brief    FLASH physical sectorization description
*/
static CONST(Fls_LLD_SectorInfoType, FLS_CONST) flsLLDSectorList0[FLS_LLD_FLASH_SECTOR_COUNT]=
{
    {    /* FLS_CODE_ARRAY_0_A_L00 */
        (volatile uint32*)0x00000000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_LSL0,
        LML_LLK0,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0        
    },
    {    /* FLS_CODE_ARRAY_0_A_L01 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00008000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_LSL1,
        LML_LLK1,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0        
    },
    {    /* FLS_CODE_ARRAY_0_A_L02 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x0000C000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_LSL2,
        LML_LLK2,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_0_A_L03 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00010000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_LSL3,
        LML_LLK3,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_0_A_L04 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00018000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_LSL4,
        LML_LLK4,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_0_A_L05 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00020000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_LSL5,
        LML_LLK5,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_0_A_M00 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00040000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_MSL0,
        LML_MLK0,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_0_A_M01 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00060000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        LMS_MSL1,
        LML_MLK1,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_1_B_H00 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00080000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL0,
        HBL_HLK0,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_1_B_H01 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x000A0000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL1,
        HBL_HLK1,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_1_B_H02 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x000C0000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL2,
        HBL_HLK2,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_1_B_H03 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x000E0000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL3,
        HBL_HLK3,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_2_C_H04 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00100000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL4,
        HBL_HLK4,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_2_C_H05 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00120000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL5,
        HBL_HLK5,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_2_C_H06 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00140000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL6,
        HBL_HLK6,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_2_C_H07 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00160000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        HBS_HSL7,
        HBL_HLK7,
        FLASHMEM_HBS,
        FLASHMEM_HBL,
        FLASHMEM_HBL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_0_A_SHADOW */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00200000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        0U,
        LML_TSLK,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_CODE_ARRAY_0_A_TEST */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00400000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        0U,
        LML_TSLK,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR0,
        (PFCR0_B02_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },    
    {    /* FLS_DATA_ARRAY_0_L00 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00800000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_DF0_A_BASEADDR),
        LMS_LSL0,
        LML_LLK0,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR1,
        (PFCR1_B1_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },    
    {    /* FLS_DATA_ARRAY_0_L01 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00804000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_DF0_A_BASEADDR),
        LMS_LSL1,
        LML_LLK1,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR1,
        (PFCR1_B1_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_DATA_ARRAY_0_L02 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00808000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_DF0_A_BASEADDR),
        LMS_LSL2,
        LML_LLK2,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR1,
        (PFCR1_B1_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_DATA_ARRAY_0_L03 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x0080C000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_DF0_A_BASEADDR),
        LMS_LSL3,
        LML_LLK3,
        FLASHMEM_LMS, 
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR1,
        (PFCR1_B1_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    },
    {    /* FLS_DATA_ARRAY_0_TEST */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)0x00C00000,
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_DF0_A_BASEADDR),
        0U,
        LML_TSLK,
        FLASHMEM_LMS,
        FLASHMEM_LML,
        FLASHMEM_SLL,
        FLASHMEM_PFCR1,
        (PFCR1_B1_P0_BFE),
        (boolean)FALSE,
        (volatile uint32*)0,
        0U,
        (volatile uint32*)0
    }
};

#define FLS_LLD_FLASH_ARRAY_COUNT 2U

/**
    @brief FLASH array description
*/
static CONST(Fls_LLD_ArrayInfoType, FLS_CONST) flsLLDArrayList0[FLS_LLD_FLASH_ARRAY_COUNT]=
{
    {    /* FLS_CODE_ARRAY_0_A */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_CF0_A_BASEADDR),
        (boolean)FALSE,
        (boolean)TRUE
    },
    {    /* FLS_DATA_ARRAY_0 */
        /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
        (volatile uint32*)(FLASHMEM0_DF0_A_BASEADDR),
        (boolean)FALSE,
        (boolean)TRUE
    }
};
/*
* @violates @ref fls_c_REF_16 C macros shall only expand to a braced initializer.
*/
#define FLS_LLD_DATA_BUS_WIDTH_TYPE uint32
#define FLS_LLD_DSI_EXC_SYNDROME (0x00000021UL)
#define FLS_LLD_MCI_EXC_SYNDROME (0x00000008UL)

#define FLS_LLD_INTERLEAVED_BLOCK  (STD_OFF)
#define FLS_LLD_INVALIDATE_PFCR    (STD_OFF)
#define FLS_LLD_PROGRAM_SUSPEND    (STD_OFF)


/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/**
* @brief Maximum number of bytes to read or compare in one cycle of Fls_MainFunction
* @implements DFLS02033
*/
STATIC VAR(Fls_LengthType, FLS_VAR) Fls_MaxRead = 0UL;
/**
* @brief Maximum number of bytes to write in one cycle of Fls_MainFunction
* @implements DFLS02034
*/
STATIC VAR(Fls_LengthType, FLS_VAR) Fls_MaxWrite = 0UL;
/**
* @brief Logical address of data block currently processed by Fls_MainFunction
* @implements DFLS02026
*/
STATIC VAR(Fls_AddressType, FLS_VAR) Fls_JobAddrIt = 0UL;
/**
* @brief Last logical address to be processed by a job
* @implements DFLS02025
*/
STATIC VAR(Fls_AddressType, FLS_VAR) Fls_JobAddrEnd = 0UL;
/**
* @brief Index of flash sector currently processed by a job
* @details Used by all types of job
* @implements DFLS02031
*/
STATIC VAR(Fls_SectorIndexType, FLS_VAR) Fls_JobSectorIt = 0UL;
/**
* @brief Index of last flash sector to be erase by current job
* @details Used only by erase job
* @implements DFLS02030
*/
STATIC VAR(Fls_SectorIndexType, FLS_VAR) Fls_JobSectorEnd = 0UL;
/**
* @brief Result of last flash module job
* @implements DFLS02029
*/
STATIC VAR(MemIf_JobResultType, FLS_VAR) Fls_JobResult = MEMIF_JOB_OK;
/**
* @brief Type of currently executed job (erase, write, read, or compare)
* @implements DFLS02024
*/
STATIC VAR(Fls_JobType, FLS_VAR) Fls_Job = FLS_JOB_ERASE;
/**
* @brief Pointer to current flash module configuration set
* @implements DFLS02023
*/
STATIC P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_ConfigPtr = NULL_PTR;
/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_8
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/**
* @brief Pointer to current position in source data buffer
* @details Used by both write and compare jobs
* @implements DFLS02028
*/
STATIC P2CONST( uint8, FLS_VAR, FLS_APPL_CONST ) Fls_JobDataSrcPtr = NULL_PTR;
/**
* @brief Pointer to current position in target data buffer
* @details Used only by read job
* @implements DFLS02027
*/
STATIC P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) Fls_JobDataDestPtr = NULL_PTR;
/**
* @brief Indicates that new job has been accepted
* @details Used by all types of job
* @implements DFLS02032
*/
STATIC VAR(uint8, FLS_VAR) Fls_JobStart = (uint8)0;
#define FLS_STOP_SEC_VAR_INIT_8
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/** 
    @brief Result of last flash hardware job
*/
STATIC VAR(MemIf_JobResultType, FLS_VAR) Fls_LLD_JobResult = MEMIF_JOB_OK;
/** 
    @brief Type of current flash hardware job
*/
STATIC VAR(Fls_LLD_JobType, FLS_VAR) Fls_LLD_Job = FLS_LLD_JOB_NONE;
#if( FLS_DSI_HANDLER_API == STD_ON )
/** 
    @brief Current status of the sector read operation. The Fls_DsiHandler function can terminate
        the read operation by setting this volatile variable to FLS_LLD_E_FAILED
*/
STATIC VAR( volatile Fls_LLD_ReturnType, FLS_VAR ) Fls_LLD_ReadStatus = FLS_LLD_E_OK;

/** 
    @brief Current status of the sector compare operation. The Fls_DsiHandler function can terminate
        the compare operation by setting this volatile variable to FLS_LLD_E_FAILED
*/
STATIC VAR( volatile Fls_LLD_ReturnType, FLS_VAR ) Fls_LLD_CompareStatus = FLS_LLD_E_OK;
#endif

/** 
    @brief Number of bytes of data left to write.
*/
STATIC VAR(Fls_LengthType, AUTOMATIC) Fls_LLD_RemainingData=0UL;
/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/** 
    @brief PFC configuration register offset address of current flash hardware job
*/
STATIC VAR(uint8, FLS_VAR) Fls_LLD_pfcConfRegOffset = (uint8)0;
/**
    @brief Physical address of currently read uint8, uint32 from flash
*/
STATIC P2CONST( volatile uint8, FLS_VAR, FLS_APPL_CONST ) volatile Fls_LLD_ReadAddressPtr = NULL_PTR;
/**
    @brief Physical address of currently compared uint8, uint32 from user buffer
*/
STATIC P2CONST( volatile uint8, FLS_VAR, FLS_APPL_CONST ) volatile Fls_LLD_CompareAddressPtr = NULL_PTR;
#define FLS_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/** 
    @brief Memory array control/configuration register base address of current flash hardware job
*/
STATIC P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_LLD_regBasePtr = NULL_PTR;

/** 
    @brief PFC control/configuration register base address of current flash hardware job
*/
STATIC P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_LLD_pfcRegBasePtr = NULL_PTR;
/** 
    @brief PFC configuration register invalidation value of current flash hardware job
*/
STATIC VAR(uint32, FLS_VAR) Fls_LLD_pfcConfRegInvalValue = 0UL;

/** 
    @brief PFC configuration register back-up value of current flash hardware job
*/
STATIC VAR(uint32, FLS_VAR) Fls_LLD_pfcConfRegValue = 0UL;

/** 
    @brief 'double word program operation' iterator
*/
STATIC VAR(uint32, FLS_VAR) Fls_LLD_programCycle = 0UL;

/** 
    @brief 'double word program operation' count
*/
STATIC VAR(uint32, FLS_VAR) Fls_LLD_doubleWordToCopy = 0UL;
/** 
    @brief 'number of word / double word needed for program operation'
*/
STATIC VAR(uint32, FLS_VAR) Fls_LLD_doubleWordCounter = 0UL;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
/** 
    @brief Memory array control/configuration register base address of current flash hardware job B1
*/
STATIC P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_LLD_B1regBasePtr = NULL_PTR;
/** 
    @brief To inform Mainfunction about the interlock size in case of async Write
*/
STATIC VAR(uint32, FLS_VAR) Fls_LLD_InterleavedSize = 0UL;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
/** 
    @brief 'data copy' auxiliary pointers
*/
STATIC P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_LLD_targetAddressPtr = NULL_PTR;
STATIC P2CONST(uint32, FLS_VAR, FLS_APPL_CONST) Fls_LLD_sourceAddressPtr = NULL_PTR;
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
STATIC P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_LLD_endAddressPtr = NULL_PTR;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
    STATIC VAR(Fls_LengthType, AUTOMATIC) Fls_LLD_NumberOfStepBack = 0UL;
#endif

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
/**
    @brief To inform Mainfunction that this sector is interleaved between Bank0 and Bank1
*/
STATIC VAR(boolean, FLS_VAR) Fls_LLD_asyncInterleavedBlock = (boolean)FALSE;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */

/**
    @brief Async Operation Result on Block B0
*/
STATIC VAR(boolean, FLS_VAR) Fls_LLD_gblB0OperResult = (boolean)FALSE;

/**
    @brief Async Operation Result on B1, B1 always TRUE if not Interleaved block 
*/
STATIC VAR(boolean, FLS_VAR) Fls_LLD_gblB1OperResult = (boolean)FALSE;

#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_START_SEC_CONST_32
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

/**
    @brief Position independent implementation of erase access code
*/
/* 
* @violates @ref fls_c_REF_19 When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
*/
/*
* @violates @ref fls_c_REF_22 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(uint32, FLS_CONST) Fls_ACEraseStart[];
/* 
* @violates @ref fls_c_REF_19 When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
*/
/*
* @violates @ref fls_c_REF_22 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(uint32, FLS_CONST) Fls_ACEraseEnd[];
/* 
* @violates @ref fls_c_REF_19 When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
*/
/*
* @violates @ref fls_c_REF_22 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(uint32, FLS_CONST) Fls_ACEraseSize[];


/**
    @brief Position independent implementation of write access code
*/
/* 
* @violates @ref fls_c_REF_19 When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
*/
/*
* @violates @ref fls_c_REF_22 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(uint32, FLS_CONST) Fls_ACWriteStart[];
/* 
* @violates @ref fls_c_REF_19 When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
*/
/*
* @violates @ref fls_c_REF_22 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(uint32, FLS_CONST) Fls_ACWriteEnd[];
/* 
* @violates @ref fls_c_REF_19 When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
*/
/*
* @violates @ref fls_c_REF_22 Objects shall be defined at block scope if they are only accessed from within 
* a single function.
*/
extern CONST(uint32, FLS_CONST) Fls_ACWriteSize[];


#define FLS_STOP_SEC_CONST_32
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
STATIC FUNC(Fls_SectorIndexType, FLS_CODE) Fls_GetSectorIndexByAddr(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress);
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr(
    CONST(Fls_SectorIndexType, AUTOMATIC) SectorIndex );
#if( FLS_DEV_ERROR_DETECT == STD_ON )
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrPageAligned( CONST(Fls_AddressType, AUTOMATIC) \
     TargetAddress );
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrPageStartAligned( CONST(Fls_AddressType, AUTOMATIC) \
     TargetAddress );
STATIC FUNC(boolean, FLS_CODE) Fls_IsLengthAligned(CONST(Fls_AddressType, AUTOMATIC) TargetAddress, \
                                                   CONST(Fls_LengthType, AUTOMATIC) Length);
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress );
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress );
#endif
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
STATIC FUNC( void, FLS_CODE ) Fls_LoadAc(
    CONST( Fls_JobType, AUTOMATIC) Job );
STATIC FUNC( void, FLS_CODE ) Fls_UnloadAc(
    CONST( Fls_JobType, AUTOMATIC) Job);
#endif
STATIC FUNC( MemIf_JobResultType, FLS_CODE )  Fls_DoJobErase( void );
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcMaxTransferAddrEnd(
    CONST( Fls_LengthType, AUTOMATIC) MaxTransfer );
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferOffset( void );
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferLength(
    CONST( Fls_AddressType, AUTOMATIC) MaxTransferEndAddr );
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_DoJobRead(
    CONST( Fls_AddressType, AUTOMATIC) SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) Length );
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_DoJobWrite(
    CONST( Fls_AddressType, AUTOMATIC) SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) Length );
#if( FLS_COMPARE_API == STD_ON )
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_DoJobCompare(
    CONST( Fls_AddressType, AUTOMATIC) SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) Length );
#endif
STATIC FUNC( MemIf_JobResultType, FLS_CODE ) Fls_DoJobDataTransfer(
    CONST( Fls_JobType, AUTOMATIC) Job,
    CONST( Fls_LengthType, AUTOMATIC) MaxTransfer );
#define FLS_STOP_SEC_CODE
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
#define SET_TIMEOUT_COUNTER_TO_ZERO   0x00000000U
/* 
* @violates @ref fls_c_REF_16 C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
/* @violates @ref fls_c_REF_21 The name of standard library macros, objects and functions shall not be reused */
#define ERASE_TIMEOUT_COUNTER         FLS_OPT_TIMEOUT_VALUE
/* 
* @violates @ref fls_c_REF_16 C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define WRITE_TIMEOUT_COUNTER         FLS_OPT_TIMEOUT_VALUE
/* 
* @violates @ref fls_c_REF_16 C macros shall only expand to a braced initializer, a constant, a string literal, a
* parenthesized expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define ABT_OPT_TIMEOUT_COUNTER       FLS_ABT_TIMEOUT_VALUE
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_RAMCODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
STATIC FUNC(void, FLS_CODE)     Fls_InvalidRestore_Ram (CONST(uint32, AUTOMATIC) pfcConfRegOffset, \
    CONST(uint32, AUTOMATIC) pfcConfRegInvalValue, CONST(uint32, AUTOMATIC) pfcConfRegRestoreValue);
#define FLS_STOP_SEC_RAMCODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"
STATIC P2FUNC (void, const, Fls_InvalidRestore) (CONST(uint32, AUTOMATIC) pfcConfRegOffset, \
    CONST(uint32, AUTOMATIC) pfcConfRegInvalValue, \
    CONST(uint32, AUTOMATIC) pfcConfRegRestoreValue) = &Fls_InvalidRestore_Ram;  
/*
* @violates @ref fls_c_REF_15 Identifiers more than 31 characters.
*/
#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#define FLS_START_SEC_RAMCODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"


/*================================================================================================*/
/**
* @brief          This function invalidate and restore Flash configuration register.
* @details        
*
* @param[in]     pfcConfRegOffset          FLS prefetch configuration register offset
* @param[in]     pfcConfRegInvalValue      FLS prefetch configuration register invalidation Value
* @param[in]     pfcConfRegRestoreValue    FLS prefetch configuration register velue (to be restored)
*
* @return         Description of the returned value
*
* @implements     DFLS02052
*
* @note           
*/

STATIC FUNC(void, FLS_CODE) Fls_InvalidRestore_Ram(CONST(uint32, AUTOMATIC) pfcConfRegOffset, \
    CONST(uint32, AUTOMATIC) pfcConfRegInvalValue, CONST(uint32, AUTOMATIC) pfcConfRegRestoreValue) 
{
    /* if enabled, invalidate PFC page buffers */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */    
    if (0U != (Fls_LLD_pfcRegBasePtr[pfcConfRegOffset] & pfcConfRegInvalValue))
    {
        /* invalidate PFC page buffers associated with modified memory bank */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_pfcRegBasePtr[pfcConfRegOffset] &= (~pfcConfRegInvalValue);
    
        /* restore PFCR0 or PFCR1 */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_pfcRegBasePtr[pfcConfRegOffset] = pfcConfRegRestoreValue;
    }
}

#define FLS_STOP_SEC_RAMCODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

STATIC FUNC( MemIf_JobResultType, FLS_CODE ) Fls_LLD_GetJobResult( void );
STATIC FUNC( void, FLS_CODE ) Fls_LLD_Init( void );
STATIC FUNC( void, FLS_CODE ) Fls_LLD_ClrJobResult( void );
STATIC FUNC(void, FLS_CODE) Fls_LLD_AbortSuspended(void);
#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_LLD_VerifyErase(
    P2CONST(volatile FLS_LLD_DATA_BUS_WIDTH_TYPE, AUTOMATIC, FLS_APPL_CONST ) FlashAreaPtr,
    CONST( Fls_LengthType, AUTOMATIC) DataLength );
#endif    /* FLS_ERASE_BLANK_CHECK || FLS_WRITE_BLANK_CHECK */
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_LLD_VerifyWrite(
    P2CONST( volatile FLS_LLD_DATA_BUS_WIDTH_TYPE, AUTOMATIC, FLS_APPL_CONST ) FlashAreaPtr,
    P2CONST( FLS_LLD_DATA_BUS_WIDTH_TYPE, AUTOMATIC, FLS_APPL_CONST ) UserBufferPtr,
    CONST( Fls_LengthType, AUTOMATIC) DataLength );
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */
STATIC FUNC( void, FLS_CODE ) Fls_LLD_MainFunction( void );
#if (FLS_CANCEL_API == STD_ON )
STATIC FUNC( void, FLS_CODE ) Fls_LLD_Cancel( void );
#endif   /* FLS_CANCEL_API == STD_ON */
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_VerifyHighVoltage
(    
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector
);
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorErase
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    CONST( Fls_LengthType, AUTOMATIC) physicalSectorSize,
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
    CONST( boolean, AUTOMATIC) asynch
);
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorWrite
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
    CONST(Fls_AddressType, AUTOMATIC) sectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) dataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) dataPtr,
    CONST( boolean, AUTOMATIC) asynch
);
STATIC FUNC( void, FLS_CODE ) Fls_LLD_PageWrite(
    CONST(uint32, AUTOMATIC) TotalBytes );
STATIC FUNC( uint32, FLS_CODE ) Fls_LLD_CalcInitDataLength( 
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) SourceAddrPtr,
    CONST(uint32, AUTOMATIC) TotalBytes );
STATIC FUNC( uint32, FLS_CODE ) Fls_LLD_CalcWideDataLength(
    CONST(uint32, AUTOMATIC) InitDataLength,
    CONST(uint32, AUTOMATIC) TotalBytes );
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorRead
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
    CONST(Fls_AddressType, AUTOMATIC) sectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) dataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) dataPtr
);
#if( FLS_COMPARE_API == STD_ON )
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorCompare
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
    CONST(Fls_AddressType, AUTOMATIC) sectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) dataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) dataPtr
);
#endif /* FLS_COMPARE_API == STD_ON */


/**
* @brief          Returns the LLD JobResult
* @implements     DFLS04004
*/
STATIC FUNC( MemIf_JobResultType, FLS_CODE ) Fls_LLD_GetJobResult( void )
{
    return( Fls_LLD_JobResult );
}

/**
* @brief          Initialize flash hardware.
* @implements     DFLS04005
*/    
STATIC FUNC( void, FLS_CODE ) Fls_LLD_Init( void )
{
    P2VAR(volatile uint32, AUTOMATIC, FLS_APPL_DATA) regBasePtr = NULL_PTR;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    P2VAR(volatile uint32, AUTOMATIC, FLS_APPL_DATA) regBase1Ptr = NULL_PTR;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
    VAR(uint32, AUTOMATIC) mcrValue = 0UL;
    VAR(uint32, AUTOMATIC) lmlValue = 0UL;
    VAR(uint32, AUTOMATIC) sllValue = 0UL;
    VAR(uint32, AUTOMATIC) hblValue = 0UL;
    
    /* Use diffrent iterator for configured array and physical one */
    VAR(uint32, AUTOMATIC) arrayIter = 0UL;
    VAR(uint32, AUTOMATIC) configIter=0UL;
    VAR(uint32, AUTOMATIC) timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
    Fls_LLD_JobResult = MEMIF_JOB_OK;
    
    /* process all FLASH sectors configured */
    for( configIter = 0U; configIter < Fls_ConfigPtr->sectorCount; configIter++ )    
    {
        /* This sector is configured to be unlocked? */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if (1U == Fls_ConfigPtr->sectorUnlock[configIter]) 
        {
            /* Translate physical sector in array index for Sector list */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            arrayIter = (uint32)Fls_ConfigPtr->physicalSector[configIter];
        
            /* Is it High address space or not? */
            if(flsLLDSectorList0[arrayIter].addrSpaceBloPrimLockRegOffset != \
               flsLLDSectorList0[arrayIter].addrSpaceBloSecoLockRegOffset)
            {
                /* Read LML register */
                regBasePtr = flsLLDSectorList0[arrayIter].memArrayRegBasePtr;
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                lmlValue = regBasePtr[FLASHMEM_LML];

                /* if LML reg is locked for register writes, write PSW to set LME (enable bit)*/                   
                if ( (boolean)FALSE == (lmlValue & LML_LME))
                {
                    /* write user provided password to block lock register */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBasePtr[FLASHMEM_LML] = LML_LME_PASSWORD;

                    /* check if the block lock register is enabled */
                    /* for register writes after writing password */
#if (FLS_DEV_ERROR_DETECT == STD_ON)
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    lmlValue = regBasePtr[FLASHMEM_LML];
                    if ((boolean)FALSE == (lmlValue & LML_LME))
                    {
                        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, \
                                         FLS_E_UNINIT );
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
                }
                    
                /* Directly set protection bit */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                regBasePtr[FLASHMEM_LML] &= \
                            (~flsLLDSectorList0[arrayIter].addrSpaceBloLockValue);
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
                /* Interleave Block for Low Address */        
                if ( flsLLDSectorList0[arrayIter].interleavedBlo )
                {
                    /* Read LML register */
                    regBase1Ptr = flsLLDSectorList0[arrayIter].memArrayB1RegBasePtr;
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    lmlValue = regBase1Ptr[FLASHMEM_LML];

                    /* if LML reg is locked for register writes, write PSW to set LME (enable bit)*/
                    if ( (boolean)FALSE == (lmlValue & LML_LME))
                    {
                        /* write user provided password to block lock register */
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        regBase1Ptr[FLASHMEM_LML] = LML_LME_PASSWORD;

                        /* check if the block lock register is enabled */
                        /* for register writes after writing password */
#if(FLS_DEV_ERROR_DETECT == STD_ON)
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        lmlValue = regBase1Ptr[FLASHMEM_LML];
                        if ((boolean)FALSE == (lmlValue & LML_LME))
                        {
                            Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, \
                                             FLS_E_UNINIT );
                            Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                        }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
                    }
                        
                    /* Directly set protection bit */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBase1Ptr[FLASHMEM_LML] &= \
                                    (~flsLLDSectorList0[arrayIter].addrSpaceBloLockValue);

                }
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
                /* Read SLL register */
                regBasePtr = flsLLDSectorList0[arrayIter].memArrayRegBasePtr;
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                sllValue = regBasePtr[FLASHMEM_SLL];

                /* if SLL reg is locked for register writes, write PSW to set LME (enable bit)*/
                if ( (boolean)FALSE == (sllValue & SLL_SLE))
                {
                    /* write user provided password to block lock register */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBasePtr[FLASHMEM_SLL] = SLL_SLE_PASSWORD;

                    /* check if the block lock register is enabled */
                    /* for register writes after writing password */
#if(FLS_DEV_ERROR_DETECT == STD_ON)
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    sllValue = regBasePtr[FLASHMEM_SLL];
                    if ((boolean)FALSE == (sllValue & SLL_SLE))
                    {
                        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, \
                                         FLS_E_UNINIT );
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
                }
                    
                /* Directly set protection bit */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                regBasePtr[FLASHMEM_SLL] &= (~flsLLDSectorList0[arrayIter].addrSpaceBloLockValue);
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
                if ( flsLLDSectorList0[arrayIter].interleavedBlo )
                {
                    /* Read SLL register */
                    regBase1Ptr = flsLLDSectorList0[arrayIter].memArrayB1RegBasePtr;
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    sllValue = regBase1Ptr[FLASHMEM_SLL];

                    /* if SLL reg is locked for register writes, write PSW to set LME (enable bit)*/
                    if ( (boolean)FALSE == (sllValue & SLL_SLE))
                    {
                        /* write user provided password to block lock register */
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        regBase1Ptr[FLASHMEM_SLL] = SLL_SLE_PASSWORD;

                        /* check if the block lock register is enabled */
                        /* for register writes after writing password */
#if(FLS_DEV_ERROR_DETECT == STD_ON)
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        sllValue = regBase1Ptr[FLASHMEM_SLL];
                        if ((boolean)FALSE == (sllValue & SLL_SLE))
                        {
                            Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, \
                                             FLS_E_UNINIT );
                            Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                        }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
                    }
                        
                    /* Directly set protection bit */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBase1Ptr[FLASHMEM_SLL] &= (~flsLLDSectorList0[arrayIter].addrSpaceBloLockValue);
                }
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
            }
            else
            {
                /* Read HBL register */
                regBasePtr = flsLLDSectorList0[arrayIter].memArrayRegBasePtr;
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                hblValue = regBasePtr[FLASHMEM_HBL];

                /* if HBL reg is locked for register writes, write PSW to set HBE (enable bit)*/
                if ( (boolean)FALSE == (hblValue & HBL_HBE))
                {
                    /* write user provided password to block lock register */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBasePtr[FLASHMEM_HBL] = HBL_HBE_PASSWORD;

                    /* check if the block lock register is enabled */
                    /* for register writes after writing password */
#if(FLS_DEV_ERROR_DETECT == STD_ON)
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    hblValue = regBasePtr[FLASHMEM_HBL];
                    if ((boolean)FALSE == (hblValue & HBL_HBE))
                    {
                        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, \
                        FLS_E_UNINIT );
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
                }
                    
                /* Directly set protection bit */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                regBasePtr[FLASHMEM_HBL] &= (~flsLLDSectorList0[arrayIter].addrSpaceBloLockValue);
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
                if ( flsLLDSectorList0[arrayIter].interleavedBlo )
                {
                    regBase1Ptr = flsLLDSectorList0[arrayIter].memArrayB1RegBasePtr;
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    hblValue = regBase1Ptr[FLASHMEM_HBL];
                    if ( (boolean)FALSE == (hblValue & HBL_HBE))
                    {
                        /* write user provided password to block lock register */
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        regBase1Ptr[FLASHMEM_HBL] = HBL_HBE_PASSWORD;

                        /* check if the block lock register is enabled */
                        /* for register writes after writing password */
#if(FLS_DEV_ERROR_DETECT == STD_ON)
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        hblValue = regBase1Ptr[FLASHMEM_HBL];
                        if ((boolean)FALSE == (hblValue & HBL_HBE))
                        {
                            Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, \
                                                            FLS_INIT_ID, FLS_E_UNINIT );
                            Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                        }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
                    }
                    /* Directly set protection bit */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBase1Ptr[FLASHMEM_HBL] &= \
                                (~flsLLDSectorList0[arrayIter].addrSpaceBloSelValue);
                }
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
            }
        }
    }

    /* Manage Program/Erase suspend */
    Fls_LLD_AbortSuspended();
    
    /* process all FLASH arrays */
    for( arrayIter = 0U; arrayIter < FLS_LLD_FLASH_ARRAY_COUNT; arrayIter++ )
    {
        regBasePtr = flsLLDArrayList0[arrayIter].memArrayRegBasePtr;
        /*    
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        mcrValue = regBasePtr[FLASHMEM_MCR];
        
        /* abort possible pending normal erase/program operation */
        /*
        * @violates @ref fls_c_REF_7 Booleans operands are not used
        * for logical operators '&&', '||' and '!'
        */
        if((mcrValue & MCR_ERS) || (mcrValue & MCR_PGM))
        {
           /* manage abort possible pending normal erase/program operation */  
            /* abort erase/program operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
            timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            */
            while((!(regBasePtr[FLASHMEM_MCR] & MCR_DONE)) &&
                /*
                * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                * invariant shall not be permitted.    
                * @violates @ref fls_c_REF_29 There shall be no unreachable code        
                */
                    (timerCounter < ABT_OPT_TIMEOUT_COUNTER))
            { 
                /* wait until end of resume */
                timerCounter++;
            }
            
            /*
            * @violates @ref fls_c_REF_18 Boolean operations whose results are 
            * invariant shall not be permitted. 
            */
            if (ABT_OPT_TIMEOUT_COUNTER <= timerCounter)
            {
                /* Timeout happened */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                /* Report appropriate DEM */
                if( ((mcrValue & MCR_ERS) != 0U) && ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state))
                {
                    Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                }
                if( ((mcrValue & MCR_PGM) != 0U) && ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state))
                {
                    Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                Fls_LLD_JobResult = MEMIF_JOB_FAILED;
            }
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
                     
            /* terminate program operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);            
        }

        /* clear possible EDC, EER, RWE events within array */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        regBasePtr[FLASHMEM_MCR] = regBasePtr[FLASHMEM_MCR]|(MCR_EDC|MCR_EER|MCR_RWE);

        /* clear block select registers */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        regBasePtr[FLASHMEM_LMS] = 0U;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        regBasePtr[FLASHMEM_HBS] = 0U;
    }

}


/**
* @brief          Manageing Abort Erase suspend.
* @details        An erase suspend is resumed and after immediatly aborted 
* @implements     DFLS04016
*/
STATIC FUNC(void, FLS_CODE) Fls_LLD_AbortSuspended()
{
     P2VAR(volatile uint32, AUTOMATIC, FLS_APPL_DATA) regBasePtr = NULL_PTR;
     VAR(uint32, AUTOMATIC) arrayIter = 0UL;
     VAR(uint32, AUTOMATIC) mcrValue = 0UL;
     VAR(uint32, AUTOMATIC) timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
    
    for( arrayIter = 0U; arrayIter < FLS_LLD_FLASH_ARRAY_COUNT; arrayIter++ )
    {
        regBasePtr = flsLLDArrayList0[arrayIter].memArrayRegBasePtr;
#if (FLS_LLD_PROGRAM_SUSPEND == STD_ON)          
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        mcrValue = regBasePtr[FLASHMEM_MCR];
        
        /* is program suspend operation possible within array? */      
        if(flsLLDArrayList0[arrayIter].programSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            /*
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            */
            if(mcrValue & MCR_PSUS)
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended program operation, and */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                regBasePtr[FLASHMEM_MCR] &= (~MCR_PSUS);

                /* if definitely in suspended operation state ...
                  (PSUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                * @violates @ref fls_c_REF_7 Booleans operands are not used
                * for logical operators '&&', '||' and '!'
                */
                if(!(regBasePtr[FLASHMEM_MCR] & MCR_PSUS))
                {
                    /* immediatly abort it */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
                    timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;                
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    * @violates @ref fls_c_REF_7 Booleans operands are not used
                    * for logical operators '&&', '||' and '!'
                    */
                    while((!(regBasePtr[FLASHMEM_MCR] & MCR_DONE)) &&
                        /*
                        * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                        * invariant shall not be permitted.    
                        * @violates @ref fls_c_REF_29 There shall be no unreachable code        
                        */                 
                            (timerCounter < ABT_OPT_TIMEOUT_COUNTER))
                    { 
                        /* wait until end of resume */
                        timerCounter++;
                    }
                    
                    /*
                    * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                    * invariant shall not be permitted. 
                    */
                    if (ABT_OPT_TIMEOUT_COUNTER <= timerCounter)
                    {
                        /* Timeout happened */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
                        {
                            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }
                    
                    /* terminate aborted program operation */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                }
                else
                {
                    /* Error, program was not resumed because it is not yet suspended */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                    if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
                    {
                        Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                    }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                    Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                
                }
            }
        }
#endif /* FLS_LLD_PROGRAM_SUSPEND == STD_ON */    
        
        /* update the value of MCR register */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        mcrValue = regBasePtr[FLASHMEM_MCR];
        /* is erase suspend operation possible within array? */
        if(flsLLDArrayList0[arrayIter].eraseSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            /*
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            */
            if(mcrValue & MCR_ESUS)
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended erase operation, and */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                regBasePtr[FLASHMEM_MCR] &= (~MCR_ESUS);

                /* if definitely in suspended operation state ...
                  (ESUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                * @violates @ref fls_c_REF_7 Booleans operands are not used
                * for logical operators '&&', '||' and '!'
                */
                if(!(regBasePtr[FLASHMEM_MCR] & MCR_ESUS))
                {
                    /* immediatly abort it */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
                    timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    * @violates @ref fls_c_REF_7 Booleans operands are not used
                    * for logical operators '&&', '||' and '!'
                    */
                    while((!(regBasePtr[FLASHMEM_MCR] & MCR_DONE)) &&
                        /*
                        * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                        * invariant shall not be permitted.    
                        * @violates @ref fls_c_REF_29 There shall be no unreachable code        
                        */
                            (timerCounter < ABT_OPT_TIMEOUT_COUNTER))
                    { 
                        /* wait until end of resume */
                        timerCounter++;
                    }
                    
                    /*
                    * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                    * invariant shall not be permitted. 
                    */
                    if (ABT_OPT_TIMEOUT_COUNTER <= timerCounter)
                    {
                        /* Timeout happened */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                        {
                            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }
                    /* terminate aborted erase operation */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
                }
                else
                {
                    /* Error, erase was not resumed because it is not yet suspended */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                    if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                    {
                        Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                    }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                    Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                
                }
            }
        }        
    }
}    

/**
* @brief          Clear status of erase or write hardware job result.
* @details        Set the internal status to  MEMIF_JOB_OK
* @implements     DFLS04003
*/  
STATIC FUNC( void, FLS_CODE ) Fls_LLD_ClrJobResult( void )
{
    Fls_LLD_JobResult = MEMIF_JOB_OK;
}

#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
/**
* @brief          Check that the addressed flash memory area is erased.
* @details        The function compares the contents of the addressed flash memory 
*                 area against the value of an erased flash cell to check that the block 
*                 has been completely erased
*
* @param[in]      1           FlashAreaPtr first address of the addressed flash memory area
*                             aligned to the MCU bus width
* @param[in]      2           DataLength number of bytes to check (aligned to the bus width)
*
* @return         Fls_LLD_ReturnType
* @retval         FLS_LLD_E_OK operation succeeded
* @retval         FLS_LLD_E_FAILED operation failed due to hardware error (ECC)
*                 or contents of the addressed memory area don't match with value of 
*                 an erased flash cell
*
* @implements     DFLS04011
*
* @note           Report the FLS_E_VERIFY_ERASE_FAILED Det error when the blank 
*                 check operation failed due to hardware error (ECC) or contents of 
*                 the addressed memory area didn't match with value of an erased 
*                 flash cell
*/
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_LLD_VerifyErase(
    P2CONST(volatile FLS_LLD_DATA_BUS_WIDTH_TYPE, AUTOMATIC, FLS_APPL_CONST ) FlashAreaPtr,
    CONST(Fls_LengthType, AUTOMATIC) DataLength )
{
    VAR(Fls_LLD_ReturnType, AUTOMATIC) RetVal = FLS_LLD_E_OK;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) flashAreaEndPtr = \
    /*
    * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
           ((volatile const uint8 *)FlashAreaPtr) + DataLength;
    
#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_LLD_ReadStatus = FLS_LLD_E_PENDING;
#endif

    /*
    * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( Fls_LLD_ReadAddressPtr = ((volatile const uint8 *)FlashAreaPtr); (uint32)Fls_LLD_ReadAddressPtr < \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
         (uint32)flashAreaEndPtr; Fls_LLD_ReadAddressPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) )
    {
#if( FLS_DSI_HANDLER_API == STD_ON )        
        /*
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        if((FLS_ERASED_VALUE != *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_ReadAddressPtr) ) ||
        /*
        * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
        * This violation is because of complex statement
        */
           ( FLS_LLD_E_PENDING != Fls_LLD_ReadStatus ))
        {
            break;
        }
#else
        /*
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        if( FLS_ERASED_VALUE != *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_ReadAddressPtr) )
        {
            break;
        }
#endif    
    }
    
    if( Fls_LLD_ReadAddressPtr == flashAreaEndPtr )
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_LLD_ReadStatus = FLS_LLD_E_OK;
#endif
    }
    else
    {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_ERASE_FAILED );
#endif
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_LLD_ReadStatus = FLS_LLD_E_FAILED;
#else
        RetVal = FLS_LLD_E_FAILED;
#endif
    }

#if( FLS_DSI_HANDLER_API == STD_ON )
    RetVal = Fls_LLD_ReadStatus;
#endif
    return RetVal;

}
#endif    /* FLS_ERASE_BLANK_CHECK || FLS_WRITE_BLANK_CHECK */

#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
/**
* @brief          Check that the addressed flash memory area is correctly programmed.
* @details        The function compares the contents of the reprogrammed memory area
*                 against the contents of the provided application buffer to check that 
*                 the block has been completely reprogrammed
*
* @param[in]      1           FlashAreaPtr First address of the addressed flash memory area
*                             aligned to MCU bus width boundary
* @param[in]      2           UserBufferPtr first address of the application buffer area 
*                             aligned to MCU bus width boundary
* @param[in]      3           DataLength number of bytes to compare aligned to the MCU bus
*                             width
*
* @return         Fls_LLD_ReturnType
* @retval         FLS_LLD_E_OK operation succeeded
* @retval         FLS_LLD_E_FAILED operation failed due to hardware error (ECC)
*                 or contents of the reprogrammed memory area don't match with the 
*                 contents of the provided application buffer
*
* @implements     DFLS04012
*
* @note           Report the FLS_E_VERIFY_WRITE_FAILED Det error when the verify 
*                 write operation failed due to hardware error (ECC) or contents of 
*                 the reprogrammed memory area didn't match with the contents of 
*                 the provided application buffer
*/
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_LLD_VerifyWrite(
    P2CONST( volatile FLS_LLD_DATA_BUS_WIDTH_TYPE, AUTOMATIC, FLS_APPL_CONST ) FlashAreaPtr,
    P2CONST( FLS_LLD_DATA_BUS_WIDTH_TYPE, AUTOMATIC, FLS_APPL_CONST ) UserBufferPtr,
    CONST(Fls_LengthType, AUTOMATIC) DataLength )
{
    VAR(Fls_LLD_ReturnType, AUTOMATIC) RetVal = FLS_LLD_E_OK;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) flashAreaEndPtr = \
    /*
    * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
           ((volatile const uint8 *)FlashAreaPtr) + DataLength;

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_LLD_CompareStatus = FLS_LLD_E_PENDING;
#endif
    
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    */
    Fls_LLD_CompareAddressPtr = ((const uint8 *)UserBufferPtr);
        
    /*
    * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( Fls_LLD_ReadAddressPtr = ((volatile const uint8 *)FlashAreaPtr); (uint32)Fls_LLD_ReadAddressPtr < \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
         (uint32)flashAreaEndPtr; Fls_LLD_ReadAddressPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) )
    {

#if( FLS_DSI_HANDLER_API == STD_ON )
        /*
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        if(( *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_ReadAddressPtr) != \
        /*
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
             *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_CompareAddressPtr)) || \
            /*
            * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
            * This violation is because of complex statement
            */
           ( Fls_LLD_CompareStatus != FLS_LLD_E_PENDING ))
        {
            break;
        }
#else
        /*
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        if( *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_ReadAddressPtr) != \
        /*
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
            *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_CompareAddressPtr) )
        {
            break;
        }

#endif
        
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_CompareAddressPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE);
    }
    
    if( Fls_LLD_ReadAddressPtr == flashAreaEndPtr )
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_LLD_CompareStatus = FLS_LLD_E_OK;
#endif
    }
    else
    {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_WRITE_FAILED );
#endif
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_LLD_CompareStatus = FLS_LLD_E_FAILED;
#else
        RetVal = FLS_LLD_E_FAILED;
#endif
    }

#if( FLS_DSI_HANDLER_API == STD_ON )
     RetVal = Fls_LLD_CompareStatus;
#endif
    return RetVal;

}
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */

/**
* @brief          Process ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 - Erase balnk Check
*                 .
*
* @implements     DFLS04006
*
* @note           Dem_ReportErrorStatus(Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error.
*                 Dem_ReportErrorStatus(Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
STATIC FUNC( void, FLS_CODE ) Fls_LLD_MainFunction( void )
{

    if(MEMIF_JOB_PENDING == Fls_LLD_JobResult )
    {
        /* some hardware job (asynchronous) is pending */
        if (FLS_LLD_JOB_ERASE == Fls_LLD_Job )
        {
            /* FLS_LLD_JOB_ERASE */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            if(Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_DONE)
            {
                /* erase/program high voltage sequence already finished */

                /* verify that erase operation was successful */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                if(Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_PEG)
                {
                    /* erase operation succeed */
                    Fls_LLD_gblB0OperResult = (boolean)TRUE;
                }
                else
                {
                    /* erase operation failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                    if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                    {
                        Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                    }                    
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                    Fls_LLD_Job = FLS_LLD_JOB_NONE;
                    Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                }

                /* start critical section: implementation depends on integrator */
                SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_03();
                
                /* invalidate PFC page buffers associated with modified memory bank */
                /* restore PFCR0 or PFCR1 */
                Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset,
                    (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
                
                /* end critical section: implementation depends on integrator */
                SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_03();                
                
                /* disable high voltage */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
                /* terminate erase operation */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
                /* clear block select registers */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_LMS] = 0U;
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_HBS] = 0U;

            }
            else
            {
                /* erase/program high voltage sequence didn't finished yet */
                /* wait for another call of Fls_LLD_MainFunction, do nothing */
            }
            
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
            /* FLS_LLD_JOB_ERASE for Interleaved blocks */
            if(Fls_LLD_asyncInterleavedBlock)
            {
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                if(Fls_LLD_B1regBasePtr[FLASHMEM_MCR] & MCR_DONE)
                {
                    /* erase/program high voltage sequence already finished */

                    /* verify that erase operation was successful */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    if(Fls_LLD_B1regBasePtr[FLASHMEM_MCR] & MCR_PEG)
                    {
                        /* erase operation succeed */
                        Fls_LLD_gblB1OperResult = (boolean)TRUE;
                    }
                    else
                    {
                        /* erase operation on interleaved block failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                        {
                            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                        Fls_LLD_Job = FLS_LLD_JOB_NONE;
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }

                    /* start critical section: implementation depends on integrator */
                    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_04();                    
                    
                    /* invalidate PFC page buffers associated with modified memory bank */
                    /* restore PFCR0 or PFCR1 */
                    Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset,
                        (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
                    
                    /* end critical section: implementation depends on integrator */
                    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_04();                
                        
                    /* disable high voltage */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_B1regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
                    /* terminate erase operation */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_B1regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
                    /* clear block select registers */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_B1regBasePtr[FLASHMEM_LMS] = 0U;
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_B1regBasePtr[FLASHMEM_HBS] = 0U;
                }
                else
                {
                    /* erase/program high voltage sequence didn't finished yet for interleaved blocks */
                    /* wait for another call of Fls_LLD_MainFunction, do nothing */
                }
            }
            else
            {
                /* Interleaved sector exist but is not this one */
                Fls_LLD_gblB1OperResult = (boolean)TRUE;
            }
#else
            /* Always TRUE when no interleaved block are present */
            Fls_LLD_gblB1OperResult = (boolean)TRUE;

#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
            
            /* @violates @ref fls_c_REF_7 Booleans operands are not used
               for logical operators '&&', '||' and '!' */
            if((Fls_LLD_gblB0OperResult) && (Fls_LLD_gblB1OperResult))
            {
                /* Clear the result for new LLD job */
                Fls_LLD_gblB0OperResult = (boolean)FALSE;
                Fls_LLD_gblB1OperResult = (boolean)FALSE;
                
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
                /* schedule erase blank check of flash sector */
                Fls_LLD_Job = FLS_LLD_JOB_ERASE_BLANK_CHECK;
#else
                /* erase operation succeed */
                Fls_LLD_Job = FLS_LLD_JOB_NONE;
                Fls_LLD_JobResult = MEMIF_JOB_OK;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
            }
        }
        /* Write hardware job (asynchronous) is pending */        
        else if (FLS_LLD_JOB_WRITE == Fls_LLD_Job )
        {
            /* FLS_LLD_JOB_WRITE */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            if(Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_DONE)
            {
                /* erase/program high voltage sequence already finished */

                /* start critical section: implementation depends on integrator */
                SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_05();                    
   
                /* invalidate PFC page buffers associated with modified memory bank */
                /* restore PFCR0 or PFCR1 */
                Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset, \
                (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
                
                /* end critical section: implementation depends on integrator */
                SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_05();                
                
                /* verify that program operation was successful */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                if(Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_PEG)
                {
                    /* program operation was successful */
                    
                    /* disable high voltage */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )                    
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    if( FLS_LLD_E_OK != Fls_LLD_VerifyWrite( Fls_LLD_targetAddressPtr - Fls_LLD_NumberOfStepBack, \
                        Fls_LLD_sourceAddressPtr - Fls_LLD_NumberOfStepBack, Fls_LLD_NumberOfStepBack*4U ) )
                    {
                        /* terminate program operation */
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                        Fls_LLD_Job = FLS_LLD_JOB_NONE;
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                        /*
                        * @violates @ref fls_c_REF_5 Return statement before end of function.
                        */
                        return;
                    }

#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */                    

                    /* more double word program operation to be performed? */
                    if(Fls_LLD_programCycle<Fls_LLD_doubleWordToCopy)
                    {
                        /* continue with next double word program operation */                        
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
                        if(Fls_LLD_asyncInterleavedBlock)
                        {
                            /* update Fls_LLD_regBasePtr based on targetAddress Bank */
                            /*
                            * @violates @ref fls_c_REF_8 Conversions shall not be
                            * performed between a pointer to a function and any type other than an integral type
                            */
                            if(((uint32)Fls_LLD_targetAddressPtr) & Fls_LLD_InterleavedSize)
                            {
                                /* it is Bank1 */
                                Fls_LLD_regBasePtr = \
                                    /*
                                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                                    * only allowed form of pointer arithmetic
                                    */
                                    flsLLDSectorList0[Fls_ConfigPtr->physicalSector[Fls_JobSectorIt]].memArrayB1RegBasePtr;
                            }
                            else
                            {
                                /* it is Bank0 */
                                Fls_LLD_regBasePtr = \
                                    /*
                                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                                    * only allowed form of pointer arithmetic
                                    */
                                    flsLLDSectorList0[Fls_ConfigPtr->physicalSector[Fls_JobSectorIt]].memArrayRegBasePtr;
                            }
                            /* To be sure that PGM bit is set for the interleaved block */
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_regBasePtr[FLASHMEM_MCR] |=  MCR_PGM;
                        }
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
                        /* if not page aligned execute dw programming */
                        /*
                        * @violates @ref fls_c_REF_8 Conversions shall not be
                        * performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        if( ((uint32)Fls_LLD_targetAddressPtr % Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt] )|| \
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            * @violates @ref fls_c_REF_7 Booleans operands are not used
                            * for logical operators '&&', '||' and '!'
                            */
                             (Fls_LLD_RemainingData < Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt] ) )
                        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                            if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                                                        /*
                                                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                                                        * only allowed form of pointer arithmetic
                                                        */
                                                        Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]) )
                            {
                                /* terminate program operation */
                                /*
                                * @violates @ref fls_c_REF_10 Array indexing shall be the
                                * only allowed form of pointer arithmetic
                                */
                                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                                Fls_LLD_Job = FLS_LLD_JOB_NONE;
                                Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                                /*
                                * @violates @ref fls_c_REF_6 Return statement before end of function.
                                */
                                return;
                            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                            /*It is time to do word or double word programming */
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_PageWrite(Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]);
                            Fls_LLD_programCycle++;
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_RemainingData -= Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                            /* target and source address has been incresed by Fls_LLD_PageWrite,
                               so we need a number of step back for both pointer to perform a write
                               verify check*/
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_NumberOfStepBack = Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]/4U;
#endif
                        }
                        else
                        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                            if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                                                        /*
                                                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                                                        * only allowed form of pointer arithmetic
                                                        */
                                                        Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]) )
                            {
                                /* terminate program operation */
                                /*
                                * @violates @ref fls_c_REF_10 Array indexing shall be the
                                * only allowed form of pointer arithmetic
                                */
                                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                                Fls_LLD_Job = FLS_LLD_JOB_NONE;
                                Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                                /*
                                * @violates @ref fls_c_REF_6 Return statement before end of function.
                                */
                                return;
                            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                            /* it is time to do page programming */
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_PageWrite(Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]);
                            Fls_LLD_programCycle+=Fls_LLD_doubleWordCounter;
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_RemainingData -= Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                            /* target and source address has been incresed by Fls_LLD_PageWrite,
                               so we need a number of step back for both pointer to perform a write
                               verify check*/
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_NumberOfStepBack = Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]/4U;
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                        }
                        
                        /* back-up PFCR0 or PFCR1 */
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        Fls_LLD_pfcConfRegValue = Fls_LLD_pfcRegBasePtr[Fls_LLD_pfcConfRegOffset];
                        
                        /* start internal erase/program sequence */
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        Fls_LLD_regBasePtr[FLASHMEM_MCR] |= MCR_EHV;
                        Fls_LLD_Job = FLS_LLD_JOB_WRITE;
                        Fls_LLD_JobResult = MEMIF_JOB_PENDING;
                    }
                    else
                    {
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
                        if(Fls_LLD_asyncInterleavedBlock)
                        {
                            /* all double word program operations succeed */
                            /* terminate program operation  on Bank 1 */
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_regBasePtr = flsLLDSectorList0[Fls_ConfigPtr->physicalSector[Fls_JobSectorIt]].memArrayB1RegBasePtr;
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                            
                            /* terminate program operation  on Bank 0 */
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_regBasePtr = flsLLDSectorList0[Fls_ConfigPtr->physicalSector[Fls_JobSectorIt]].memArrayRegBasePtr;
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                        }
                        else
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
                        /* all double word program operations succeed */
                        /* terminate program operation */    
                        {
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                        }
                        
                        /* For a Write Job in ASYNC mode check if Fls_JobSectorIt should be increased */
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        if( (Fls_JobAddrIt > (Fls_ConfigPtr->sectorEndAddr[Fls_JobSectorIt]) ))
                        {
                            /* Move on to the next sector */
                            Fls_JobSectorIt++;
                        }            
                        
                        /* program operation succeed */
                        Fls_LLD_Job = FLS_LLD_JOB_NONE;
                        Fls_LLD_JobResult = MEMIF_JOB_OK;
                    }
                }
                else
                {
                    /* program operation was not successful */
                    
                    /* disable high voltage */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                    /* program operation failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                    if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
                    {
                        Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                    }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                    
                    Fls_LLD_Job = FLS_LLD_JOB_NONE;
                    Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                }
            }
            else
            {
                /* erase/program high voltage sequence didn't finished yet */
                /* wait for another call of Fls_LLD_MainFunction, do nothing */
            }
        }
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
        else if ( FLS_LLD_JOB_ERASE_BLANK_CHECK == Fls_LLD_Job )
        {
            /* FLS_LLD_JOB_ERASE_BLANK_CHECK */
            /*
            * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
            * that address elements of the same array
            */
            if (Fls_LLD_targetAddressPtr < Fls_LLD_endAddressPtr)
            {
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
                * that address elements of the same array
                */
                if (((Fls_LLD_endAddressPtr - Fls_LLD_targetAddressPtr)*4) >= \
                      FLS_MAX_ERASE_BLANK_CHECK)
                {
                    /* at least one erase blank check with FLS_MAX_ERASE_BLANK_CHECK size */
                    if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                        FLS_MAX_ERASE_BLANK_CHECK) )
                    {
                        /* Erase blanck check failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                        {
                            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                  
                        Fls_LLD_Job = FLS_LLD_JOB_NONE;
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }
                    else
                    {
                        /*                           
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        */
                        Fls_LLD_targetAddressPtr += FLS_MAX_ERASE_BLANK_CHECK/(FLS_LLD_DATA_BUS_WIDTH_TYPE)4;
                    }
                }
                else
                {
                    /* at least one erase blank check with 4 bytes size */
                    if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
                    * that address elements of the same array
                    * @violates @ref fls_c_REF_20 Implicitly converted to a different underlying type.
                    */
                      (Fls_LLD_endAddressPtr - Fls_LLD_targetAddressPtr)*4) )
                    {
                        /* Erase blanck check failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                        {
                            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                    
                        Fls_LLD_Job = FLS_LLD_JOB_NONE;
                        Fls_LLD_JobResult = MEMIF_JOB_FAILED;
                    }
                    else
                    {
                        /*
                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                        * only allowed form of pointer arithmetic
                        * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
                        * that address elements of the same array
                        */
                        Fls_LLD_targetAddressPtr += Fls_LLD_endAddressPtr - Fls_LLD_targetAddressPtr;
                    }
                }
            }
            else
            {
                /* Erase blank check is finished */
                Fls_LLD_Job = FLS_LLD_JOB_NONE;
                Fls_LLD_JobResult = MEMIF_JOB_OK;
            }
        }
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */                
        /* Write interleaved hardware job (asynchronous) is pending */
        else if (FLS_LLD_JOB_NONE == Fls_LLD_Job)
        {
            /* Do nothing */
        }
        else
        {   /*
            * @violates @ref fls_c_REF_17 All if .. else if constructs shall be terminated with an else clause.
            */
            Cer_ReportError( (uint16) FLS_MODULE_ID, (uint8)FLS_INSTANCE_ID, (uint8)FLS_SID_SETCLOCKMODE, (uint8)FLS_E_DEFAULT);
        }
    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
    }
}

#if (FLS_CANCEL_API == STD_ON )
/**
* @brief          Cancel ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will abort the following jobs:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 .
*
* @implements     DFLS04002
*/
STATIC FUNC( void, FLS_CODE ) Fls_LLD_Cancel( void )
{
    VAR(uint32, AUTOMATIC) timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
    
    if(MEMIF_JOB_PENDING == Fls_LLD_JobResult )
    {
        /* some hardware job (asynchronous) is pending */
        if (FLS_LLD_JOB_ERASE == Fls_LLD_Job )
        {
            /* FLS_LLD_JOB_ERASE */
            /* hence make erase-abort operation */
            
            /* abort erase/program operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
            timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            */
            while((!(Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_DONE)) &&
                /*
                * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                * invariant shall not be permitted.    
                * @violates @ref fls_c_REF_29 There shall be no unreachable code        
                */
                    (timerCounter < ABT_OPT_TIMEOUT_COUNTER))
            { 
                /* wait until end of abort */
                timerCounter++;
            }
              
            /*
            * @violates @ref fls_c_REF_18 Boolean operations whose results are 
            * invariant shall not be permitted. 
            */
            if (ABT_OPT_TIMEOUT_COUNTER <= timerCounter)
            {
                /* Timeout happened */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                {
                    Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */ 
            }
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
            
            /* clear block select registers */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_LMS] = 0U;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_HBS] = 0U;
                
            /* start critical section: implementation depends on integrator */
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_06();                    
                
            /* invalidate PFC page buffers associated with modified memory bank */
            /* restore PFCR0 or PFCR1 */
            Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset, \
            (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
                
            /* end critical section: implementation depends on integrator */
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_06();               
                        
            /* erase operation canceled */
            Fls_LLD_Job = FLS_LLD_JOB_NONE;
            Fls_LLD_JobResult = MEMIF_JOB_CANCELED;
        }
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
        else if (FLS_LLD_JOB_ERASE_TEMP == Fls_LLD_Job )
        {   
            /* FLS_LLD_JOB_ERASE_TEMP */
            /* hence make erase-abort operation on interleaved block */
            
            /* abort erase/program operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_B1regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
            timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            */
            while((!(Fls_LLD_B1regBasePtr[FLASHMEM_MCR] & MCR_DONE)) &&
                /*
                * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                * invariant shall not be permitted.    
                * @violates @ref fls_c_REF_29 There shall be no unreachable code        
                */
                    (timerCounter < ABT_OPT_TIMEOUT_COUNTER))
            { 
                /* wait until end of abort */
                timerCounter++;
            }
            
            /*
            * @violates @ref fls_c_REF_18 Boolean operations whose results are 
            * invariant shall not be permitted. 
            */
            if (ABT_OPT_TIMEOUT_COUNTER <= timerCounter)
            {
                /* Timeout happened */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                {
                    Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */ 
            }
                
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_B1regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
            
            /* clear block select registers */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_B1regBasePtr[FLASHMEM_LMS] = 0U;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_B1regBasePtr[FLASHMEM_HBS] = 0U;
                
            /* start critical section: implementation depends on integrator */
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_07();
            
            /* invalidate PFC page buffers associated with modified memory bank */
            /* restore PFCR0 or PFCR1 */
            Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset, \
            (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
                
            /* end critical section: implementation depends on integrator */
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_07();
            
            /* erase operation canceled */
            Fls_LLD_Job = FLS_LLD_JOB_NONE;
            Fls_LLD_JobResult = MEMIF_JOB_CANCELED;
        }
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
        else
        {
            /* FLS_LLD_JOB_WRITE */
            /* hence make program-abort operation */
                
            /* abort erase/program operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
            timerCounter = SET_TIMEOUT_COUNTER_TO_ZERO;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            */
            while((!(Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_DONE)) &&
                /*
                * @violates @ref fls_c_REF_18 Boolean operations whose results are 
                * invariant shall not be permitted.    
                * @violates @ref fls_c_REF_29 There shall be no unreachable code        
                */            
                    (timerCounter < ABT_OPT_TIMEOUT_COUNTER))
            { 
                /* wait until end of abort */
                timerCounter++;
            }
            
            /*
            * @violates @ref fls_c_REF_18 Boolean operations whose results are 
            * invariant shall not be permitted. 
            */
            if (ABT_OPT_TIMEOUT_COUNTER <= timerCounter)
            {
                /* Timeout happened */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
                {
                    Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
            }
                
            /* terminate program operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
    
            /* start critical section: implementation depends on integrator */
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_08();
          
            /* invalidate PFC page buffers associated with modified memory bank */
            /* restore PFCR0 or PFCR1 */
            Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset, \
            (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
                
            /* end critical section: implementation depends on integrator */
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_08();
            
            /* program operation canceled */
            Fls_LLD_Job = FLS_LLD_JOB_NONE;
            Fls_LLD_JobResult = MEMIF_JOB_CANCELED;
        }
    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
        Fls_LLD_Job = FLS_LLD_JOB_NONE;
        Fls_LLD_JobResult = MEMIF_JOB_CANCELED;
    }
}
#endif /* FLS_CANCEL_API == STD_ON */

/**
* @brief          Verify High Voltage bit can be set (EHV).
*
* @param[in]      1           phySector Physical sector ID
*
* @return         Fls_LLD_ReturnType
* @retval         FLS_LLD_E_OK Operation succeeded
* @retval         FLS_LLD_E_FAILED Operation failed due to hardware error
*
* @pre            phySector must be in range
*
* @note           Dem_ReportErrorStatus(Fls_E_EraseFailed, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error
*/
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_VerifyHighVoltage
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector
)
{
    VAR(Fls_LLD_ReturnType, AUTOMATIC) retVal = FLS_LLD_E_OK;

    /* Variables needed to check HW registers */
    VAR(uint8, AUTOMATIC) bloPrimLockRegOffset = \
                          flsLLDSectorList0[phySector].addrSpaceBloPrimLockRegOffset;
    VAR(uint8, AUTOMATIC) bloSecoLockRegOffset = \
                          flsLLDSectorList0[phySector].addrSpaceBloSecoLockRegOffset;
    VAR(uint32, AUTOMATIC) bloLockValue = flsLLDSectorList0[phySector].addrSpaceBloLockValue;
    

    /* Base address register for Memory array */
    Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayRegBasePtr;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    Fls_LLD_B1regBasePtr = flsLLDSectorList0[phySector].memArrayB1RegBasePtr;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */

    /* verify that EHV may be set */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if( ( (Fls_LLD_regBasePtr[FLASHMEM_MCR] & (MCR_ERS|MCR_PGM|MCR_ESUS)) != 0UL ) || \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    */
         ((Fls_LLD_regBasePtr[FLASHMEM_UT0] & (UT0_AIE)) !=0UL ))
    {
        /*  EHV may not be set: modify operation already in progress */
        retVal = FLS_LLD_E_FAILED;
    }
    /* verify that sector is not protected against erase/program operations */
        /*
        * @violates @ref fls_c_REF_7 Booleans operands are not used
        * for logical operators '&&', '||' and '!'
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
    if( ( (Fls_LLD_regBasePtr[bloPrimLockRegOffset] & bloLockValue) != 0UL ) || \
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
        * This violation is because of complex statement
        */
       ((Fls_LLD_regBasePtr[bloSecoLockRegOffset] & bloLockValue) != 0UL ))
    {
        /* sector protected: erase operation failed */
        retVal = FLS_LLD_E_FAILED;
    }
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    /* verify that EHV may be set on interleaved blocks */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if (flsLLDSectorList0[phySector].interleavedBlo)
    {
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if( ( (Fls_LLD_B1regBasePtr[FLASHMEM_MCR] & (MCR_ERS|MCR_PGM|MCR_ESUS)) != 0UL ) || \
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
        * This violation is because of complex statement
        */
            ( (Fls_LLD_B1regBasePtr[FLASHMEM_UT0] & (UT0_AIE)) != 0UL ))
        {
            /*  EHV may not be set: modify operation already in progress */
            retVal = FLS_LLD_E_FAILED;
        }
        /* verify that the interleaved sector is not protected against erase/program operations */
        /*
        * @violates @ref fls_c_REF_7 Booleans operands are not used
        * for logical operators '&&', '||' and '!'
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if( ( (Fls_LLD_B1regBasePtr[bloPrimLockRegOffset] & bloLockValue) != 0UL ) ||
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
            * This violation is because of complex statement
            */
            ( ( (Fls_LLD_B1regBasePtr[bloSecoLockRegOffset] & bloLockValue)) != 0UL ) )
        {
            /* sector protected: erase operation failed */
            retVal = FLS_LLD_E_FAILED;
        }
   }
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */

    return retVal;
}
/**
* @brief          Erase one complete flash sector.
*
* @param[in]      1           phySector Physical sector ID
* @param[in]      2           physicalSectorSize size to be blank checked (only if FLS_ERASE_BLANK_CHECK == STD_ON)
* @param[in]      3           asynch Set to TRUE for asynchronous and FALSE for synchronous 
*                             function operation
*
* @return         Fls_LLD_ReturnType
* @retval         FLS_LLD_E_OK Operation succeeded
* @retval         FLS_LLD_E_FAILED Operation failed due to hardware error
* @retval         FLS_LLD_E_PENDING The operation has not yet been finished 
*                 (only for asynchronous operation )
*
* @pre            phySector must be in range
* @pre            The module must be initialized
* @post           Postconditions as text description. Optional tag.
*
* @implements     DFLS04008
*
* @note           Dem_ReportErrorStatus(Fls_E_EraseFailed, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error
*/
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorErase
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    CONST(Fls_LengthType, AUTOMATIC) physicalSectorSize,
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
    CONST( boolean, AUTOMATIC) asynch
)
{
    VAR(Fls_LLD_ReturnType, AUTOMATIC) retVal = FLS_LLD_E_OK;

    /* Variables needed to check HW registers */
    VAR(uint8, AUTOMATIC) bloSelRegOffset = flsLLDSectorList0[phySector].sectorBloSelRegOffset;
    VAR(uint32, AUTOMATIC) bloSelValue = flsLLDSectorList0[phySector].addrSpaceBloSelValue;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    VAR(boolean, AUTOMATIC) interleavedBlock = flsLLDSectorList0[phySector].interleavedBlo;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
    /* Operation Result on Block B0 and B1, B1 always TRUE if not Interleaved block */
    VAR(boolean, AUTOMATIC) B0OperResult = (boolean)FALSE;
    VAR(boolean, AUTOMATIC) B1OperResult = (boolean)FALSE;
    /* Reset timeout counter */
    VAR(volatile uint32, AUTOMATIC) timerCounterAC = SET_TIMEOUT_COUNTER_TO_ZERO;
    
    /* Start, end address for erase operation */
    Fls_LLD_targetAddressPtr = flsLLDSectorList0[phySector].sectorStartAddressPtr;
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    Fls_LLD_endAddressPtr = \
            /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
            */
    (flsLLDSectorList0[phySector].sectorStartAddressPtr + (physicalSectorSize/(FLS_LLD_DATA_BUS_WIDTH_TYPE)4));
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

    /* Base address register for Memory array */
    Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayRegBasePtr;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    Fls_LLD_B1regBasePtr = flsLLDSectorList0[phySector].memArrayB1RegBasePtr;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
    /*
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    /* Flash platform controller registers */
    Fls_LLD_pfcRegBasePtr = (volatile uint32*)(FLASHMEM0_PFC0_BASEADDR);
    Fls_LLD_pfcConfRegOffset = flsLLDSectorList0[phySector].platformFlashConfRegOffset;
    Fls_LLD_pfcConfRegInvalValue = flsLLDSectorList0[phySector].platformFlashConfInvalValue;
    Fls_LLD_pfcConfRegValue = 0U;

    /* verify that EHV may be set */
    retVal = Fls_LLD_VerifyHighVoltage(phySector);
    if( FLS_LLD_E_OK == retVal )
    {
        /*
        * @violates @ref fls_c_REF_7 Booleans operands are not used
        * for logical operators '&&', '||' and '!'
        */
        if (!asynch)
        {
            /* setup erase operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] |= MCR_ERS;
            /* load adequate block select register */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[bloSelRegOffset] = bloSelValue;
            /* make an erase interlock write, dummy data word write */
            *Fls_LLD_targetAddressPtr = 0xFFFFFFFFU;
        
            /* start critical section: implementation depends on integrator */
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
            
            /* back-up PFCR0 or PFCR1 */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_pfcConfRegValue = Fls_LLD_pfcRegBasePtr[Fls_LLD_pfcConfRegOffset];
            timerCounterAC = ERASE_TIMEOUT_COUNTER;
            /* call flash access code routine */
            /* @violates @ref fls_c_REF_4 No reliance shall be placed on undefined or unspecified behaviour */
            Fls_ConfigPtr->acErasePtr(Fls_LLD_regBasePtr, Fls_ConfigPtr->acCallBackPtr, &timerCounterAC);
            /*
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            if((Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_PEG) && \
                    /*
                    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
                    * This violation is because of complex statement
                    */
                    (0U != timerCounterAC))
            {
                /* erase operation succeed */
                B0OperResult = (boolean)TRUE;
            }

            /* invalidate PFC page buffers associated with modified memory bank */
            /* restore PFCR0 or PFCR1 */
            Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset,
                (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);

            /* end critical section: implementation depends on integrator */
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        
            /* disable high voltage */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
            /* clear adequate block select register */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[bloSelRegOffset] = 0U;

#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
            if(interleavedBlock)
            {
                /* setup erase operation: it can be done regardless of the result of above operation */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_B1regBasePtr[FLASHMEM_MCR] |= MCR_ERS;
                /* load adequate block select register */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_B1regBasePtr[bloSelRegOffset] = bloSelValue;
                /* make an erase interlock write in intrleaved block (add FLS_INTERLEAVED_BLOCK_OFFSET) */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                *(Fls_LLD_targetAddressPtr + 0x4U) = 0xFFFFFFFFU;
            
                /* start critical section: implementation depends on integrator */
                SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_01();
                
                /* back-up PFCR0 or PFCR1 */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_pfcConfRegValue = Fls_LLD_pfcRegBasePtr[Fls_LLD_pfcConfRegOffset];
                timerCounterAC = ERASE_TIMEOUT_COUNTER;
                /* call flash access code routine */
                /* @violates @ref fls_c_REF_4 No reliance shall be placed on undefined or unspecified behaviour */
                Fls_ConfigPtr->acErasePtr(Fls_LLD_B1regBasePtr, Fls_ConfigPtr->acCallBackPtr, &timerCounterAC);
                /*
                * @violates @ref fls_c_REF_7 Booleans operands are not used
                * for logical operators '&&', '||' and '!'
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                if((Fls_LLD_B1regBasePtr[FLASHMEM_MCR] & MCR_PEG) && \
                        /*
                        * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
                        * This violation is because of complex statement
                        */
                        (0U != timerCounterAC))
                {
                    /* erase operation succeed */
                    B1OperResult = (boolean)TRUE;
                }

                /* invalidate PFC page buffers associated with modified memory bank */
                /* restore PFCR0 or PFCR1 */
                Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset, \
                  (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
                
                /* end critical section: implementation depends on integrator */
                SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_01();
                
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_B1regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
                /* terminate erase operation */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_B1regBasePtr[FLASHMEM_MCR] &= (~MCR_ERS);
                /* clear adequate block select register */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_B1regBasePtr[bloSelRegOffset] = 0U;
            }
            else
            {
                B1OperResult = (boolean)TRUE;
            }        

#else
            B1OperResult = (boolean)TRUE;

#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
            /* 
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            * @violates @ref fls_c_REF_18 Boolean operations whose results are 
            * invariant shall not be permitted. 
            */
            if((B0OperResult) && (B1OperResult))
            {
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
                if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, physicalSectorSize) )
                {
                    /* erase operation failed but PEG is still OK*/
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                    if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                    {
                        Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                    }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */

                    retVal = FLS_LLD_E_FAILED;
                }
#endif /* FLS_ERASE_BLANK_CHECK == STD_ON */

                /* erase operation succeed 
                retVal = FLS_LLD_E_OK;*/
            }
            else
            {
                /* erase operation failed and PEG is NOT OK*/
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
                {
                    Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* FLS_ERASE_BLANK_CHECK == STD_ON */
                retVal = FLS_LLD_E_FAILED;
            }
        }
        else /* asynch == TRUE */
        {
            /* setup erase operation */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] |= MCR_ERS;
            /* load adequate block select register */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[bloSelRegOffset] = bloSelValue;
            /* make an erase interlock write, dummy data word write */
            *Fls_LLD_targetAddressPtr = 0xFFFFFFFFU;
            
            /* back-up PFCR0 or PFCR1 */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_pfcConfRegValue = Fls_LLD_pfcRegBasePtr[Fls_LLD_pfcConfRegOffset];
            
            /* start internal erase/program sequence */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_regBasePtr[FLASHMEM_MCR] |= MCR_EHV;
            
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
            if(interleavedBlock)
            {
                /* setup a new erase operation in parallel for interleaved block */
                /*
                 * @violates @ref fls_c_REF_10 Array indexing shall be the
                 * only allowed form of pointer arithmetic
                 */
                Fls_LLD_B1regBasePtr[FLASHMEM_MCR] |= MCR_ERS;
                /* load adequate block select register */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_B1regBasePtr[bloSelRegOffset] = bloSelValue;
                /* make an erase interlock write in intrleaved block (add FLS_INTERLEAVED_BLOCK_OFFSET) */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                *(Fls_LLD_targetAddressPtr + 0x4U) = 0xFFFFFFFFU;
                /* back-up PFCR0 or PFCR1 */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_pfcConfRegValue = Fls_LLD_pfcRegBasePtr[Fls_LLD_pfcConfRegOffset];
            
                /* start internal erase/program sequence */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_B1regBasePtr[FLASHMEM_MCR] |= MCR_EHV;
            }
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
                
            Fls_LLD_Job = FLS_LLD_JOB_ERASE;
            Fls_LLD_JobResult = MEMIF_JOB_PENDING;
            retVal = FLS_LLD_E_PENDING;
        }
    }
    else
    {

        /* Sync or Async operation can NOT be executed (ongoing or locked) */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_EraseFailedCfg.state)
        {
            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
        /*
        * @violates @ref fls_c_REF_17 All if .. else if constructs shall be terminated with an else clause.
        */
    }
    
    return retVal;
}

/**
* @brief          Write one or more complete flash pages into given flash sector.
*
* @param[in]      phySector Physical sector ID
* @param[in]      sectorOffset sector offset in bytes
* @param[in]      dataLength data length in bytes
* @param[in]      dataPtr data to be written
* @param[in]      asynch set to TRUE for asynchronous and FALSE for synchronous function operation
*
* @return         Fls_LLD_ReturnType
* @retval         FLS_LLD_E_OK Operation succeeded
* @retval         FLS_LLD_E_FAILED Operation failed due to hardware error
* @retval         FLS_LLD_E_PENDING The operation has not yet been finished 
*                 (only for asynchronous operation )
*
* @pre            sectorOffset must be double word aligned
* @pre            dataLength must be multiple double word length
* @pre            phySector must be in range
* @pre            The module must be initialized
* @post           Postconditions as text description. Optional tag.
*
* @implements     DFLS04010
*
* @note           Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
*                 when write operation failed due to hardware error
*/
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorWrite
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
    CONST(Fls_AddressType, AUTOMATIC) sectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) dataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) dataPtr,
    CONST( boolean, AUTOMATIC) asynch
)
{
    VAR(uint8, AUTOMATIC) bloPrimLockRegOffset = \
    flsLLDSectorList0[phySector].addrSpaceBloPrimLockRegOffset;
    VAR(uint8, AUTOMATIC) bloSecoLockRegOffset = \
    flsLLDSectorList0[phySector].addrSpaceBloSecoLockRegOffset;
    VAR(uint32, AUTOMATIC) bloLockValue = flsLLDSectorList0[phySector].addrSpaceBloLockValue;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    VAR(boolean, AUTOMATIC) interleavedBlock = flsLLDSectorList0[phySector].interleavedBlo;
    VAR(uint32, AUTOMATIC) interleavedSize = flsLLDSectorList0[phySector].interleavedSize;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
    VAR(volatile uint32, AUTOMATIC) timerCounterAC = WRITE_TIMEOUT_COUNTER;
    
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    */
    Fls_LLD_sourceAddressPtr = (const uint32*)(dataPtr);
    Fls_LLD_targetAddressPtr = flsLLDSectorList0[phySector].sectorStartAddressPtr + \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
                               (sectorOffset/4U);
    Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayRegBasePtr;

    Fls_LLD_RemainingData = dataLength;

    /*
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    Fls_LLD_pfcRegBasePtr = (volatile uint32*)(FLASHMEM0_PFC0_BASEADDR);
    Fls_LLD_pfcConfRegOffset = flsLLDSectorList0[phySector].platformFlashConfRegOffset;
    Fls_LLD_pfcConfRegInvalValue = flsLLDSectorList0[phySector].platformFlashConfInvalValue;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    Fls_LLD_B1regBasePtr = flsLLDSectorList0[phySector].memArrayB1RegBasePtr;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
    Fls_LLD_pfcConfRegValue = 0U;

    /* verify that EHV may be set */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if( ( (Fls_LLD_regBasePtr[FLASHMEM_MCR] & (MCR_ERS|MCR_PGM|MCR_ESUS)) != 0UL ) || \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    */
         ((Fls_LLD_regBasePtr[FLASHMEM_UT0] & (UT0_AIE)) !=0UL ))
    {
        /*  EHV may not be set: modify operation already in progress */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
        {
            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
        /*
        * @violates @ref fls_c_REF_5 Return statement before end of function.
        */
        return FLS_LLD_E_FAILED;
    }

    /* verify that sector is not protected against erase/program operations */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if( ( (Fls_LLD_regBasePtr[bloPrimLockRegOffset] & bloLockValue) != 0UL ) || \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    */
       ((Fls_LLD_regBasePtr[bloSecoLockRegOffset] & bloLockValue) != 0UL ))
    {
        /* sector protected: program operation failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
        {
            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
        /*
        * @violates @ref fls_c_REF_5 Return statement before end of function.
        */
        return FLS_LLD_E_FAILED;
    }

#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    if(interleavedBlock)
    {
        /* verify that EHV may be set */
        /*
        * @violates @ref fls_c_REF_7 Booleans operands are not used
        * for logical operators '&&', '||' and '!'
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if( ( (Fls_LLD_B1regBasePtr[FLASHMEM_MCR] & (MCR_ERS|MCR_PGM|MCR_ESUS)) != 0UL ) || \
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
                * This violation is because of complex statement
                */
                ( (Fls_LLD_B1regBasePtr[FLASHMEM_UT0] & (UT0_AIE)) != 0UL ))
        {
            /*  EHV may not be set: modify operation already in progress */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
            if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLS_LLD_E_FAILED;
        }    

        /* verify that sector is not protected against erase/program operations */
        /*
        * @violates @ref fls_c_REF_7 Booleans operands are not used
        * for logical operators '&&', '||' and '!'
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if( ( (Fls_LLD_B1regBasePtr[bloPrimLockRegOffset] & bloLockValue) != 0UL ) || \
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
        * This violation is because of complex statement
        */
                ( ( (Fls_LLD_B1regBasePtr[bloSecoLockRegOffset] & bloLockValue)) != 0UL ) )
        {
            /* sector protected: program operation failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
            if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLS_LLD_E_FAILED;
        }    
    }    
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
    /* Number of word (i.e.32bits=4bytes) double word (i.e.64bits=8bytes) to be copied  */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_LLD_doubleWordToCopy = dataLength/Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt];
    /* Number of word or dw to be copied in one propram operation */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_LLD_doubleWordCounter = Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt] / Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt];
    Fls_LLD_programCycle = 0U;
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    /* update Fls_LLD_regBasePtr based on targetAddress Bank */
    /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
    if(((uint32)Fls_LLD_targetAddressPtr) & interleavedSize)
    {
        /* it is Bank1 */
        Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayB1RegBasePtr;
    }
    else
    {
        /* it is Bank0 */
        Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayRegBasePtr;
    }
#else
        /* it is Bank0 */
        Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayRegBasePtr;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
    /* setup program operation for sync / async operation */
    /* @violates @ref fls_c_REF_10 Use only array Indexing */
    Fls_LLD_regBasePtr[FLASHMEM_MCR] |= MCR_PGM;

    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    */
    if (!asynch)
    {
        /* process all double word program operations */
        while (Fls_LLD_programCycle < Fls_LLD_doubleWordToCopy)
        {
#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
            /* update Fls_LLD_regBasePtr based on targetAddress Bank */
            /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
            if(((uint32)Fls_LLD_targetAddressPtr) & interleavedSize)
            {
                /* it is Bank1 */
                Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayB1RegBasePtr;
            }
            else
            {
                /* it is Bank0 */
                Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayRegBasePtr;
            }
#else
            /* it is Bank0 */
            Fls_LLD_regBasePtr = flsLLDSectorList0[phySector].memArrayRegBasePtr;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */
            /* if not page aligned execute dw programming */
            /*
            * @violates @ref fls_c_REF_8 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            if( ((uint32)Fls_LLD_targetAddressPtr % Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt] ) || \
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                * @violates @ref fls_c_REF_7 Booleans operands are not used
                * for logical operators '&&', '||' and '!'
                */
                (Fls_LLD_RemainingData < Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt] ) )
            {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]) )
                {
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                    /*
                    * @violates @ref fls_c_REF_6 Return statement before end of function.
                    */
                    return FLS_LLD_E_FAILED;                
                }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */                
                /*It is time to do word or double word programming */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_PageWrite(Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]);
                Fls_LLD_programCycle++;
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_RemainingData -= Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                /* target and source address has been incresed by Fls_LLD_PageWrite,
                   so we need a number of step back for both pointer to perform a write
                   verify check*/
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_NumberOfStepBack = Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]/4U;
#endif
            }
            else
            {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                                /*
                                * @violates @ref fls_c_REF_10 Array indexing shall be the
                                * only allowed form of pointer arithmetic
                                */
                                Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]) )
                {
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                    /*
                    * @violates @ref fls_c_REF_6 Return statement before end of function.
                    */
                    return FLS_LLD_E_FAILED;
                }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                /* it is time to do page programming */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_PageWrite(Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]);
                Fls_LLD_programCycle+=Fls_LLD_doubleWordCounter;
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_RemainingData -= Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                /* target and source address has been incresed by Fls_LLD_PageWrite,
                   so we need a number of step back for both pointer to perform a write
                   verify check*/
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_NumberOfStepBack = Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]/4U;
#endif
            }
            /* start critical section: implementation depends on integrator */
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_02();
            
            /* back-up PFCR0 or PFCR1 */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_pfcConfRegValue = Fls_LLD_pfcRegBasePtr[Fls_LLD_pfcConfRegOffset];
            timerCounterAC = WRITE_TIMEOUT_COUNTER;
            /* call flash access code routine */
            /* @violates @ref fls_c_REF_4 No reliance shall be placed on undefined or unspecified behaviour */
            Fls_ConfigPtr->acWritePtr(Fls_LLD_regBasePtr, Fls_ConfigPtr->acCallBackPtr, &timerCounterAC);

            /* invalidate PFC page buffers associated with modified memory bank */
            /* restore PFCR0 or PFCR1 */
            Fls_InvalidRestore((uint32) Fls_LLD_pfcConfRegOffset, \
              (uint32) Fls_LLD_pfcConfRegInvalValue, (uint32) Fls_LLD_pfcConfRegValue);
            
            /* end critical section: implementation depends on integrator */
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_02();
        
            /* verify that program operation was successful */
            /*
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            if((Fls_LLD_regBasePtr[FLASHMEM_MCR] & MCR_PEG) && \
                    /*
                    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
                    * This violation is because of complex statement
                    */
                    (0U != timerCounterAC))
            {
                /* disable high voltage */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                if( FLS_LLD_E_OK != Fls_LLD_VerifyWrite( \
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_targetAddressPtr - Fls_LLD_NumberOfStepBack, \
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_sourceAddressPtr - Fls_LLD_NumberOfStepBack, \
                    Fls_LLD_NumberOfStepBack * 4U ) )
                {
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                    /*
                    * @violates @ref fls_c_REF_5 Return statement before end of function.
                    */
                    return FLS_LLD_E_FAILED;
                }
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */

                /* program operation succeed */
                /* continue with next double word program operation */
            }
            else
            {
                /* disable high voltage */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_EHV);
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                /* program operation failed */
#if (FLS_DEM_ERROR_DETECT == STD_ON)
                if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_WriteFailedCfg.state)
                {
                    Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* FLS_DEM_ERROR_DETECT == STD_ON */
                /*
                * @violates @ref fls_c_REF_5 Return statement before end of function.
                */
                return FLS_LLD_E_FAILED;
            }
        }
            
        /* all double word program operations succeed */
        /* terminate program operation */    
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
        /* program operation succeed */
        /*
        * @violates @ref fls_c_REF_6 Return statement before end of function.
        */
        return FLS_LLD_E_OK;
    }
    else /* asynch == TRUE */
    {
        /* if not page aligned execute dw programming */
        /*
        * @violates @ref fls_c_REF_8 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if( ((uint32)Fls_LLD_targetAddressPtr % Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt] ) || \
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    * @violates @ref fls_c_REF_7 Booleans operands are not used
                    * for logical operators '&&', '||' and '!'
                    */
                    (Fls_LLD_RemainingData < Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt] ) )
        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
            if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                                        /*
                                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                                        * only allowed form of pointer arithmetic
                                        */
                                        Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]) )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                /*
                * @violates @ref fls_c_REF_6 Return statement before end of function.
                */
                return FLS_LLD_E_FAILED;
            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
            /*It is time to do word or double word programming */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_PageWrite(Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]);
            Fls_LLD_programCycle++;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_RemainingData -= Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* target and source address has been incresed by Fls_LLD_PageWrite,
               so we need a number of step back for both pointer to perform a write
               verify check*/
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_NumberOfStepBack = Fls_ConfigPtr->sectorPageSize[Fls_JobSectorIt]/4U;
#endif
        }
        else
        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
            if( FLS_LLD_E_OK != Fls_LLD_VerifyErase(Fls_LLD_targetAddressPtr, \
                                        /*
                                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                                        * only allowed form of pointer arithmetic
                                        */
                                        Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]) )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_LLD_regBasePtr[FLASHMEM_MCR] &= (~MCR_PGM);
                /*
                * @violates @ref fls_c_REF_6 Return statement before end of function.
                */
                return FLS_LLD_E_FAILED;
            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
            /* it is time to do page programming */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_PageWrite(Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]);
            Fls_LLD_programCycle+=Fls_LLD_doubleWordCounter;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_RemainingData -= Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* target and source address has been incresed by Fls_LLD_PageWrite,
               so we need a number of step back for both pointer to perform a write
               verify check*/
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_LLD_NumberOfStepBack = Fls_ConfigPtr->sectorProgSize[Fls_JobSectorIt]/4U;
#endif
        }

        /* back-up PFCR0 or PFCR1 */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_pfcConfRegValue = Fls_LLD_pfcRegBasePtr[Fls_LLD_pfcConfRegOffset];

        /* start internal erase/program sequence */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_regBasePtr[FLASHMEM_MCR] |= MCR_EHV;

        Fls_LLD_Job = FLS_LLD_JOB_WRITE;
        Fls_LLD_JobResult = MEMIF_JOB_PENDING;
        /*
        * @violates @ref fls_c_REF_6 Return statement before end of function.
        */
        return FLS_LLD_E_PENDING;
    }
}

/**
* @brief          Execute an interlock write and next program.
*
* @param[in]      1           TotalBytes Total number of bytes to program
*
* @implements     DFLS...
*/
STATIC FUNC( void, FLS_CODE ) Fls_LLD_PageWrite(
    CONST(uint32, AUTOMATIC) TotalBytes )
{
    uint32 counter;

    for (counter=0U; counter < (TotalBytes/4U); counter ++)
    {
        /* make a program data interlock write, first word data write */
        *Fls_LLD_targetAddressPtr = *Fls_LLD_sourceAddressPtr;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_targetAddressPtr += 1;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_sourceAddressPtr += 1;
    }
}

/**
* @brief          Calculate length of initial 8-bit flash read.
* @details        Calculate number of bytes to read from flash until
*                 the source pointer is aligned to the data  width and
*                 optimized wide (32-bit or 64-bit) flash reads can begin
*
* @param[in]      1           SourceAddrPtr Source pointer
* @param[in]      2           TotalBytes Total number of bytes to read
*
* @return         length of initial 8-bit flash reads in bytes
*
* @implements     DFLS04014
*/
STATIC FUNC( uint32, FLS_CODE ) Fls_LLD_CalcInitDataLength( 
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) SourceAddrPtr,
    CONST(uint32, AUTOMATIC) TotalBytes )
{
    /* Calc length of initial 8-bit transfer */
    VAR(uint32, AUTOMATIC) length = 
        /*
        * @violates @ref fls_c_REF_8 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        */
        ( (uint32)SourceAddrPtr ) & ( sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - 1UL );
    
    if ( length != 0U )
    {
        length = sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - length;
    }
    else
    {
        /* length == 0 */
    }

    if( length > TotalBytes ) 
    {
        length = TotalBytes;
    }
    else
    {
        /* length <=  TotalBytes */
    }
    
    return length;
}

/**
* @brief          Calculate length of optimized wide flash reads.
* @details        Calculate number of bytes to read from flash until
*                 the source pointer is not aligned to the data bus width
*
* @param[in]      1           InitDataLength Calculated by Fls_LLD_CalcInitDataLength
* @param[in]      2           TotalBytes Total number of bytes to read
*
* @return         length of optimized 32-bit or 64-bit flash reads in bytes
*
* @implements     DFLS04015
*/
STATIC FUNC( uint32, FLS_CODE ) Fls_LLD_CalcWideDataLength(
    CONST(uint32, AUTOMATIC) InitDataLength,
    CONST(uint32, AUTOMATIC) TotalBytes )
{
    VAR(uint32, AUTOMATIC) length =
        (( TotalBytes - InitDataLength ) & (~( sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - 1UL )));

    return length;
}

/**
* @brief          Read one or more bytes from given flash sector
*
* @param[in]      1           phySector Physical sector ID
* @param[in]      2           sectorOffset sector offset in bytes
* @param[in]      3           dataLength data length in bytes
* @param[out]     dataPtr     where read data to be written
*
* @return Fls_LLD_ReturnType
* @retval FLS_LLD_E_OK Operation succeeded
*
* @implements     DFLS04009
*/
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorRead
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
    CONST(Fls_AddressType, AUTOMATIC) sectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) dataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) dataPtr
)
{
    VAR(uint32, AUTOMATIC) initDataLength = 0UL;
    VAR(Fls_LLD_ReturnType, AUTOMATIC) RetVal = FLS_LLD_E_OK;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) readAddressEndPtr = NULL_PTR;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) readBlockAddressEndPtr = NULL_PTR;
    
    /* Physical flash address to read */
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    */
    Fls_LLD_ReadAddressPtr = (volatile const uint8 *)(flsLLDSectorList0[phySector].sectorStartAddressPtr) + \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
                              sectorOffset;

    /* End of read pointer */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    readAddressEndPtr = Fls_LLD_ReadAddressPtr + dataLength;
    
    /* Calculate end address of initial 8-bit transfer */
    initDataLength = Fls_LLD_CalcInitDataLength( Fls_LLD_ReadAddressPtr, dataLength );
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    readBlockAddressEndPtr = Fls_LLD_ReadAddressPtr + initDataLength;

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_LLD_ReadStatus = FLS_LLD_E_PENDING;
    
    /* Initial 8-bit flash read (until the data bus alignment boundary) */ 
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; ( (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr ) && \
    /*
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
       ( Fls_LLD_ReadStatus == FLS_LLD_E_PENDING ); Fls_LLD_ReadAddressPtr++)
#else
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr; Fls_LLD_ReadAddressPtr++)
#endif    
    {
        *dataPtr = *Fls_LLD_ReadAddressPtr;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        dataPtr++;
    }

    /* Calculate end address of wide 32-bit or 64-bit flash read */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    readBlockAddressEndPtr += Fls_LLD_CalcWideDataLength( initDataLength, dataLength );

    /* Data bus width transfer */    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; ( (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr ) && \
    /*
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    */
       ( Fls_LLD_ReadStatus == FLS_LLD_E_PENDING ); Fls_LLD_ReadAddressPtr += \
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
         sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE))
#else
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr; Fls_LLD_ReadAddressPtr += \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
           sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE))
#endif    
    {
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        *((FLS_LLD_DATA_BUS_WIDTH_TYPE*)dataPtr) = \
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        */ 
        *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_ReadAddressPtr);
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        dataPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE);
    }
    
    /* Final 8-bit transfer */
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; ( (uint32)Fls_LLD_ReadAddressPtr < (uint32)readAddressEndPtr ) && \
    /*
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
       ( Fls_LLD_ReadStatus == FLS_LLD_E_PENDING ); Fls_LLD_ReadAddressPtr++)
#else
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; (uint32)Fls_LLD_ReadAddressPtr < (uint32)readAddressEndPtr; Fls_LLD_ReadAddressPtr++)
#endif    
    {
        *dataPtr = *Fls_LLD_ReadAddressPtr;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        dataPtr++;
    }

#if( FLS_DSI_HANDLER_API == STD_ON )    
    if( FLS_LLD_E_PENDING == Fls_LLD_ReadStatus )
    {
        Fls_LLD_ReadStatus = FLS_LLD_E_OK;
    }
    else
    {
        /*
        * @violates @ref fls_c_REF_17 All if .. else if constructs shall be terminated with an else clause.
        */
    }
    
    RetVal = Fls_LLD_ReadStatus;
#else
    RetVal = FLS_LLD_E_OK;
#endif    
    return RetVal;
}

#if( FLS_COMPARE_API == STD_ON )
/**
* @brief          Compare data buffer with content of given flash sector.
*
* @param[in]      1           phySector Physical sector ID
* @param[in]      2           sectorOffset sector offset in bytes
* @param[in]      3           dataLength data length in bytes
* @param[in]      4           dataPtr data to be compared
*                 
* @return         Fls_LLD_ReturnType
* @retval         FLS_LLD_E_OK Operation succeeded
* @retval         FLS_LLD_E_BLOCK_INCONSISTENT Data buffer doesn't match with content of flash sector
*
* @implements     DFLS04007
*/
STATIC FUNC(Fls_LLD_ReturnType, FLS_CODE) Fls_LLD_SectorCompare
(
    CONST( Fls_LLD_PhysicalSectorType, AUTOMATIC) phySector,
    CONST(Fls_AddressType, AUTOMATIC) sectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) dataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) dataPtr
)
{
    VAR(uint32, AUTOMATIC) initDataLength = 0UL;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST ) readAddressEndPtr = NULL_PTR;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST ) readBlockAddressEndPtr = NULL_PTR;
    
    /* Physical flash address to read */
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
    * volatile qualification from the type address by a pointer
    */
    Fls_LLD_ReadAddressPtr = (volatile const uint8 *)(flsLLDSectorList0[phySector].sectorStartAddressPtr) + \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
                              sectorOffset;
    Fls_LLD_CompareAddressPtr = dataPtr;
    
    /* End of read pointer */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    readAddressEndPtr = Fls_LLD_ReadAddressPtr + dataLength;
    
    /* Calculate end address of initial 8-bit transfer */
    initDataLength = Fls_LLD_CalcInitDataLength( Fls_LLD_ReadAddressPtr, dataLength );
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    readBlockAddressEndPtr = Fls_LLD_ReadAddressPtr + initDataLength;

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_LLD_CompareStatus = FLS_LLD_E_PENDING;
    
    /* Initial 8-bit flash read (until the data bus alignment boundary) */ 
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; ( (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr ) && \
    /*
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
       ( Fls_LLD_CompareStatus == FLS_LLD_E_PENDING ); Fls_LLD_ReadAddressPtr++ )
#else
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr; Fls_LLD_ReadAddressPtr++)
#endif    
    {
        /*
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *Fls_LLD_CompareAddressPtr != *Fls_LLD_ReadAddressPtr )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLS_LLD_E_PENDING == Fls_LLD_CompareStatus )
            { 
                Fls_LLD_CompareStatus = FLS_LLD_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_LLD_CompareStatus != FLS_LLD_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLS_LLD_E_BLOCK_INCONSISTENT;
#endif            
        }
        else
        {
            /* *Fls_LLD_CompareAddressPtr == *Fls_LLD_ReadAddressPtr */
        }
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_CompareAddressPtr++;
    }

    /* Calculate end address of wide 32-bit or 64-bit flash read */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    readBlockAddressEndPtr += Fls_LLD_CalcWideDataLength( initDataLength, dataLength );

    /* Data bus width transfer */    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; ( (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr ) && \
    /*
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    */
       ( Fls_LLD_CompareStatus == FLS_LLD_E_PENDING ); Fls_LLD_ReadAddressPtr += \
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
         sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE))
#else
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; (uint32)Fls_LLD_ReadAddressPtr < (uint32)readBlockAddressEndPtr; Fls_LLD_ReadAddressPtr += \
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
         sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE))
#endif    
    {
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        */
        if( *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_CompareAddressPtr) != \
        /*
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        * @violates @ref fls_c_REF_12 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer
        */
            *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_ReadAddressPtr) )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLS_LLD_E_PENDING == Fls_LLD_CompareStatus )
            { 
                Fls_LLD_CompareStatus = FLS_LLD_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_LLD_CompareStatus != FLS_LLD_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLS_LLD_E_BLOCK_INCONSISTENT;
#endif
        }
        else
        {
            /* *((FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_CompareAddressPtr) = \
               *((FLS_LLD_DATA_BUS_WIDTH_TYPE*)Fls_LLD_ReadAddressPtr) */
        }
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_CompareAddressPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE);
    }
    
    /* Final 8-bit transfer */
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; ( (uint32)Fls_LLD_ReadAddressPtr < (uint32)readAddressEndPtr ) && \
    /*
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
           ( Fls_LLD_CompareStatus == FLS_LLD_E_PENDING ); Fls_LLD_ReadAddressPtr++)
#else
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_8 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
    for( ; (uint32)Fls_LLD_ReadAddressPtr < (uint32)readAddressEndPtr; Fls_LLD_ReadAddressPtr++)
#endif    
    {
        /*
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *Fls_LLD_CompareAddressPtr != *Fls_LLD_ReadAddressPtr )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLS_LLD_E_PENDING == Fls_LLD_CompareStatus )
            { 
                Fls_LLD_CompareStatus = FLS_LLD_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_LLD_CompareStatus != FLS_LLD_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLS_LLD_E_BLOCK_INCONSISTENT;
#endif
        }
        else
        {
            /* *Fls_LLD_CompareAddressPtr == *Fls_LLD_ReadAddressPtr */
        }
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_LLD_CompareAddressPtr++;
    }

#if( FLS_DSI_HANDLER_API == STD_ON )    
    if( FLS_LLD_E_PENDING == Fls_LLD_CompareStatus )
    {
        Fls_LLD_CompareStatus = FLS_LLD_E_OK;
    }
    else
    {
        /*
        * @violates @ref fls_c_REF_17 All if .. else if constructs shall be terminated with an else clause.
        */
    }
    /*
    * @violates @ref fls_c_REF_5 Return statement before end of function.
    */
    return Fls_LLD_CompareStatus;
#else
    /*
    * @violates @ref fls_c_REF_5 Return statement before end of function.
    */
    return FLS_LLD_E_OK;
#endif    
}
#endif /* FLS_COMPARE_API == STD_ON */

/* @implements    DFLS17001, DFLS18001 */
#if( FLS_DSI_HANDLER_API == STD_ON )
/**
* @brief          Low level data storage exception handler.
*
* @return         Exc_CompHandlerReturnType
* @retval         EXC_HANDLED_SKIP The data storage exception was 
*                 caused by currently pending flash read or compare job
* @retval         EXC_UNHANDLED The data storage exception was 
*                 NOT caused by currently pending flash read or compare job
*
* @implements     DFLS04001
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_DsiHandler(
    P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) ExceptionDetailsPtr )
{
    /* @implements    DFLS17002 */
    VAR( Fls_CompHandlerReturnType, AUTOMATIC ) RetVal = FLS_UNHANDLED;

    /* @errata ERR_IPV_FLASH_0005 */
    #ifdef ERR_IPV_FLASH_0005
      #if (ERR_IPV_FLASH_0005 == STD_ON)   
        VAR(uint8, AUTOMATIC) dataPtr;
        /*
        * @violates @ref fls_c_REF_8 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        */
        dataPtr = *((volatile uint8 *)0x00C02000U);
     #endif
    #endif
    
    /*  Check whether there is 
        [1] pending read, compare, erase or write job, 
        [2] exception syndrome register indicates DSI reason, and 
        [3] data_pt matches address currently accessed by pending flash read or flash compare job */       
    /* @implements    DFLS17010, DFLS17011 */
    if(( FLS_LLD_E_PENDING == Fls_LLD_ReadStatus ) && 
        ( FLS_LLD_DSI_EXC_SYNDROME == (ExceptionDetailsPtr->syndrome_u32 & \
          FLS_LLD_DSI_EXC_SYNDROME) ) && \
        /*
        * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
        * This violation is because of complex statement
        */
        ( ExceptionDetailsPtr->data_pt == Fls_LLD_ReadAddressPtr ))
    {
        Fls_LLD_ReadStatus = FLS_LLD_E_FAILED;
        RetVal = FLS_HANDLED_SKIP;
    }
    /* @implements    DFLS17009 */
    else if(( FLS_LLD_E_PENDING == Fls_LLD_CompareStatus ) && \
        ( FLS_LLD_DSI_EXC_SYNDROME == \
        (ExceptionDetailsPtr->syndrome_u32 & FLS_LLD_DSI_EXC_SYNDROME) ) && \
        (( ExceptionDetailsPtr->data_pt == Fls_LLD_ReadAddressPtr ) || \
        /*
        * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
        * This violation is because of complex statement
        */
        ( ExceptionDetailsPtr->data_pt == Fls_LLD_CompareAddressPtr )))
    {
        Fls_LLD_CompareStatus = FLS_LLD_E_FAILED;
        RetVal = FLS_HANDLED_SKIP;
    }
    else
    {
        /* FLS_UNHANDLED */
    }

    return RetVal;
}

#ifdef IPV_FLASH
    /* for XPC560XB, XPC560XP, XPC5602D platform */
    #if ((IPV_FLASH == IPV_FLASH_C90FG_544_2_9_65) || (IPV_FLASH == IPV_FLASH_C90FG_1568_2_6_69) || \
          (IPV_FLASH == IPV_FLASH_C90FG_1024_2_0) ||  (IPV_FLASH == IPV_FLASH_C90FG_512_2_9) || \
         (IPV_FLASH == IPV_FLASH_C90FG_256_1_4) || (IPV_FLASH == IPV_FLASH_C90FG_256_1_4_D))

    /**
    * @brief          Low level data storage exception handler.
    *
    * @return         Exc_CompHandlerReturnType
    * @retval         EXC_HANDLED_SKIP The data storage exception was 
    *                 caused by currently pending flash read or compare job
    * @retval         EXC_UNHANDLED The data storage exception was 
    *                 NOT caused by currently pending flash read or compare job
    *
    * @implements     DFLS04013
    */
    /*
    * @violates @ref fls_c_REF_11 All declarations and definitions
    * of objects or functions at file scope shall have internal linkage unless external linkage required
    */
    FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_MciHandler(
        P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) ExceptionDetailsPtr )
    {
        /* @implements    DFLS18002 */
        VAR( Fls_CompHandlerReturnType, AUTOMATIC ) RetVal = FLS_UNHANDLED;

        /* @errata ERR_IPV_FLASH_0005 */
        #ifdef ERR_IPV_FLASH_0005
          #if (ERR_IPV_FLASH_0005 == STD_ON)   
            VAR(uint8, AUTOMATIC) dataPtr;
        
        
            dataPtr = *((volatile uint8 *)0x00C02000U);
         #endif
        #endif
    
        /*  In case of IVOR1 on Z0 check whether there is:
            [1] pending read, compare, erase or write job, 
            [2] exception syndrome register indicates DSI reason, and 
            [3] data_pt matches address currently accessed by pending flash read or flash compare job 
            [-] There is NO MCAR nor DEAR special register so address currently accessed can be taken 
                from Platform Flash ECC Address Register (PFEAR) on ECSM when after 
                ECC Configuration Register (ECR) has been configured.
        */
         
        /* @implements    DFLS18004, DFLS18006 */
        if(( FLS_LLD_E_PENDING == Fls_LLD_ReadStatus ) && 
            ( FLS_LLD_MCI_EXC_SYNDROME == (ExceptionDetailsPtr->syndrome_u32 & \
              FLS_LLD_MCI_EXC_SYNDROME) ) && \
            /*
            * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
            * This violation is because of complex statement
            */
            ( ExceptionDetailsPtr->data_pt == Fls_LLD_ReadAddressPtr ))
        {
            Fls_LLD_ReadStatus = FLS_LLD_E_FAILED;
            RetVal = FLS_HANDLED_SKIP;
        }   
        /* @implements    DFLS18003, DFLS18005 */
        else if(( FLS_LLD_E_PENDING == Fls_LLD_CompareStatus ) && \
            ( FLS_LLD_MCI_EXC_SYNDROME == \
            (ExceptionDetailsPtr->syndrome_u32 & FLS_LLD_MCI_EXC_SYNDROME) ) && \
            (( ExceptionDetailsPtr->data_pt == Fls_LLD_ReadAddressPtr ) || \
            /*
            * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
            * This violation is because of complex statement
            */
            ( ExceptionDetailsPtr->data_pt == Fls_LLD_CompareAddressPtr )))
        {
            Fls_LLD_CompareStatus = FLS_LLD_E_FAILED;
            RetVal = FLS_HANDLED_SKIP;
        }
        else
        {
            /* FLS_UNHANDLED */
        }

        return RetVal;
    }
    #endif /* for XPC560XB platforms */
#endif /*ifdef IPV_FLASH */

#endif /* FLS_DSI_HANDLER_API == STD_ON */

#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"



#define FLS_START_SEC_CODE
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"



/**
* @brief        Maps TargetAddress to sector index
*
* @details      Calculate index of logical sector TargetAddress belongs to
*
* @param[in]    TargetAddress Target address in flash memory
*
* @return       Zero based index of logical sector
* @retval       0 .. (Fls_ConfigPtr->sectorCount - 1)
*
* @pre          The module must be initialized
* @pre          TargetAddress must be in configured flash boundary
*
* @implements     DFLS02047
*
*/
STATIC FUNC(Fls_SectorIndexType, FLS_CODE) Fls_GetSectorIndexByAddr(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress)
{
    VAR( Fls_SectorIndexType, AUTOMATIC ) sectorIndex = 0UL;

    for( sectorIndex = 0U; sectorIndex < Fls_ConfigPtr->sectorCount;
        sectorIndex++ )
    {
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if( TargetAddress <= Fls_ConfigPtr->sectorEndAddr[sectorIndex] )
        {
            /* TargetAddress belongs to sector with index sectorIndex */
            break;
        }
        else
        {
            /* Check next sector */
        }
    }

    return sectorIndex;
}

/**
* @brief        Return start address of given sector
*
* @details      Calculate start address (in linear space) of logical sector
*               specified by the SectorIndex parameter
*
* @param[in]    SectorIndex Index of logical sector
*
* @return       Start address of SectorIndex sector
* @retval       0 .. (FLS_TOTAL_SIZE - 1)
*
* @pre          The module must be initialized
* @pre          SectorIndex must be in range 0 .. (Fls_ConfigPtr->sectorCount - 1)
*
* @implements     DFLS02048
*
*/
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr(
    CONST(Fls_SectorIndexType, AUTOMATIC) SectorIndex )
{
    VAR( Fls_AddressType, AUTOMATIC ) TargetAddress = 0U;

    if( 0U != SectorIndex )
    {
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        TargetAddress = Fls_ConfigPtr->sectorEndAddr[SectorIndex - 1U] + 1U;
    }
    else
    {
        /* First sector starts with address 0 */
    }

    return TargetAddress;
}

/**
* @brief        Check whether TargetAddress is page aligned
*
* @details      Check whether TargetAddress is integer multiple of FLS_PAGE_SIZE
*
* @param[in]    TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE TargetAddress is page aligned
* @retval       FALSE TargetAddress is not page aligned
*
* @implements     DFLS02053
*
*/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrPageAligned(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress )
{
    VAR( boolean, AUTOMATIC ) RetVal = (boolean)FALSE;

    /* Aligned to Double Word or Word depending if CODE/DATA Flash or DFO */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if(!(TargetAddress % Fls_ConfigPtr->sectorPageSize[Fls_GetSectorIndexByAddr( TargetAddress )]))
    {
        RetVal = (boolean)TRUE;
    }
    else
    {
        /* TargetAddress is not page aligned */
    }

    return( RetVal );
}

/**
* @brief        Check whether TargetAddress is page start aligned
*
* @details      Check whether TargetAddress is in range and aligned to first
*               byte of flash page
*
* @param[in]    TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE TargetAddress is in range and aligned to start of the page
* @retval       FALSE TargetAddress is not in range or aligned to start of the page
*
* @pre          The module must be initialized
*
* @implements     DFLS02054
*
*/
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrPageStartAligned(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress )
{
    VAR( boolean, AUTOMATIC ) RetVal = (boolean)FALSE;
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if(( TargetAddress < (Fls_AddressType)FLS_TOTAL_SIZE ) &&
        /*
        * @violates @ref fls_c_REF_7 Booleans operands are not used
        * for logical operators '&&', '||' and '!'
        */
        ( Fls_IsAddrPageAligned( TargetAddress ) ))
    {
        RetVal = (boolean)TRUE;
    }
    else
    {
        /* TargetAddress is not in range or aligned to start of the page */
    }

    return( RetVal );
}

/**
* @brief        Check whether TargetAddress is page start aligned
*
* @details      Check whether Length is in range and aligned to
*               flash page
*
* @param[in]    TargetAddress Target address in flash memory
* @param[in]    Length size of current write
*
* @return       boolean
* @retval       TRUE TargetAddress is in range and aligned to end of the page
* @retval       FALSE TargetAddress is not in range or aligned to end of the page
*
* @pre          The module must be initialized
*
* @implements     DFLS02057
*
*/
STATIC FUNC(boolean, FLS_CODE) Fls_IsLengthAligned(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress,
    CONST(Fls_LengthType, AUTOMATIC) Length
    )
{
    VAR( boolean, AUTOMATIC ) RetVal = (boolean)FALSE;

    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if((((TargetAddress + Length) - 1U) < (Fls_AddressType)FLS_TOTAL_SIZE ) &&
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
       (!(Length % Fls_ConfigPtr->sectorPageSize[Fls_GetSectorIndexByAddr( TargetAddress )])))
    {
        RetVal = (boolean)TRUE;
    }
    else
    {
        /* TargetAddress is not in range or aligned to end of the page */
    }

    return( RetVal );
}


/**
* @brief        Check whether TargetAddress is sector start aligned
*
* @details      Check whether TargetAddress is in range and aligned to first
*               byte of flash sector
*
* @param[in]    TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE TargetAddress is in range and aligned to start of the sector
* @retval       FALSE TargetAddress is not in range or not aligned to
*               start of the sector
*
* @pre          The module must be initialized
*
* @implements     DFLS02056
*
*/
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress )
{
    VAR( boolean, AUTOMATIC ) RetVal = (boolean)FALSE;
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if(( TargetAddress < FLS_TOTAL_SIZE ) &&
        ( TargetAddress == Fls_GetSectorStartAddr( Fls_GetSectorIndexByAddr( TargetAddress ))))
    {
        RetVal = (boolean)TRUE;
    }
    else
    {
        /* TargetAddress is not in range or
            not aligned to start of the sector */
    }

    return RetVal;
}



/**
* @brief        Check whether TargetAddress is sector end aligned
*
* @details      Check whether TargetAddress is in range and aligned to last
*               byte of flash sector
*
* @param[in]    TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE TargetAddress is in range and aligned to end of the sector
* @retval       FALSE TargetAddress is not in range or not aligned to
*               end of the sector
*
* @pre          The module must be initialized
*
* @implements     DFLS02055
*
*/
STATIC FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned(
    CONST(Fls_AddressType, AUTOMATIC) TargetAddress )
{
    VAR( boolean, AUTOMATIC ) RetVal = (boolean)FALSE;
    VAR( Fls_SectorIndexType, AUTOMATIC ) sectorIndex = 0UL;

    sectorIndex = Fls_GetSectorIndexByAddr( TargetAddress );

    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if(( TargetAddress < FLS_TOTAL_SIZE ) &&
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        ( TargetAddress == Fls_ConfigPtr->sectorEndAddr[sectorIndex] ))
    {
        RetVal =  (boolean)TRUE;
    }
    else
    {
        /* TargetAddress is not in range or not aligned to end of the sector */
    }

    return RetVal;
}
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */


/**
* @brief        Load access code to RAM
*
* @details      Load erase or write access code to statically
*               pre-configured location in RAM
*
* @param[in]    Job Type of access code to load. Can be either
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized
*
* @implements     DFLS02058
*
*/
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
STATIC FUNC( void, FLS_CODE ) Fls_LoadAc(
    CONST( Fls_JobType, AUTOMATIC) Job )
{
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) romPtr = NULL_PTR;
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) romEndPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) ramPtr = NULL_PTR;

    switch( Job )
    {
        case FLS_JOB_ERASE:
            romPtr = Fls_ACEraseStart;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            romEndPtr = Fls_ACEraseEnd;
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            */
            /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
            ramPtr = (uint32*)(Fls_ConfigPtr->acErasePtr);
        break;

        case FLS_JOB_WRITE:
            romPtr = Fls_ACWriteStart;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            romEndPtr = Fls_ACWriteEnd;

            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            */
            /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
            ramPtr = (uint32*)(Fls_ConfigPtr->acWritePtr);
        break;

        default:
            /* Compiler_Warning: Added CER for Catastrophic events */
            Cer_ReportError( (uint16) FLS_MODULE_ID, (uint8)FLS_INSTANCE_ID, (uint8)FLS_SID_SETCLOCKMODE, (uint8)FLS_E_DEFAULT);
        break;
    }

    /* Copy erase or write access code to RAM */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    /* @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers that address elements of the same array*/
    for(; romPtr <= romEndPtr; romPtr++)
    {
        *ramPtr = *romPtr;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        ramPtr++;
    }
}


/**
* @brief        Unload access code to RAM
*
* @details      Erase write or erase access code from statically
*               pre-configured location in RAM. Fills the RAM location
*               with FLS_AC_UNLOAD_PATTERN
*
* @param[in]    Job Type of access code to unload. Can be either
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized
*
* @implements     DFLS02062
*
*/
STATIC FUNC( void, FLS_CODE ) Fls_UnloadAc(
    CONST( Fls_JobType, AUTOMATIC) Job)
{
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) ramPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) ramEndPtr = NULL_PTR;

    switch( Job )
    {
        case FLS_JOB_ERASE:

            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            */
            /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
            ramPtr = (uint32*)(Fls_ConfigPtr->acErasePtr);
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            /*
            * @violates @ref fls_c_REF_8 Conversions shall not be performed between a pointer
            * to a function and any type other than an integral type contents in that address.
            */
            ramEndPtr = ramPtr + (uint32)(Fls_ACEraseSize);
        break;

        case FLS_JOB_WRITE:

            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            */
            /* @violates @ref fls_c_REF_8 Some conversions are not allowed */
            ramPtr = (uint32*)(Fls_ConfigPtr->acWritePtr);
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            /*
            * @violates @ref fls_c_REF_8 Conversions shall not be performed between a pointer
            * to a function and any type other than an integral type contents in that address.
            */
            ramEndPtr = ramPtr + (uint32)(Fls_ACWriteSize);
        break;

        default:
            /* Compiler_Warning: Added CER for Catastrophic events */
            Cer_ReportError( (uint16) FLS_MODULE_ID, (uint8)FLS_INSTANCE_ID, (uint8)FLS_SID_SETCLOCKMODE, (uint8)FLS_E_DEFAULT);
        break;
    }

    /* Unload (erase) write or erase access code from RAM */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    /*
    * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
    * that address elements of the same array
    */
    for(; ramPtr <= ramEndPtr; ramPtr++)
    {
        *ramPtr = FLS_AC_UNLOAD_PATTERN;
    }
}
#endif /* FLS_AC_LOAD_ON_JOB_START */

/**
* @brief        Erase one complete flash sector
*
* @details      Call low level flash driver service
*               to erase one complete flash sector specified by the Fls_JobSectorIt
*               internal job variable
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK erase operation succeeded and there
*               is no more sectors to erase
* @retval       MEMIF_JOB_PENDING erase operation succeeded and there
*               is still one or more sectors to erase
* @retval       MEMIF_JOB_FAILED operation failed due to hardware error
*
* @param[in]    Job Type of access code to unload. Can be either
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized, the Fls_JobSectorIt internal
*               job variable must contain index of logical sector to be erased, and
*               Fls_JobSectorEnd must contain index of last logical sector to be erased
*
* @post         increments the Fls_JobSectorIt internal job variable
*
*
* @implements     DFLS02042
*
*/
STATIC FUNC( MemIf_JobResultType, FLS_CODE )  Fls_DoJobErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_PENDING;

     /* @implements DFLS16031, DFLS16034 */
    if( Fls_JobSectorIt > Fls_JobSectorEnd )
    {
        /* No more sectors to erase */
        RetVal = MEMIF_JOB_OK;
    }
    else
    {
        VAR( Fls_LLD_PhysicalSectorType, AUTOMATIC ) physicalSectorId;
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
        VAR( Fls_LengthType, AUTOMATIC ) physicalSectorSize = 0UL;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
        VAR( boolean, AUTOMATIC ) asynch = (boolean)0;
        VAR( Fls_LLD_ReturnType, AUTOMATIC ) lldRetVal = FLS_LLD_E_OK;

        /* Map logical sector index to physical sector ID */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        physicalSectorId = Fls_ConfigPtr->physicalSector[Fls_JobSectorIt];

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
        /* Calculate size of the physical sector */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        physicalSectorSize = (Fls_ConfigPtr->sectorEndAddr[Fls_JobSectorIt] -
            Fls_GetSectorStartAddr( Fls_JobSectorIt )) + (Fls_LengthType)1;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

        /* Get the Fls_LLD_SectorErase function operation mode */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        if( Fls_ConfigPtr->sectorFlags[Fls_JobSectorIt] &
            FLS_SECTOR_ERASE_ASYNCH )
        {
            asynch = (boolean)TRUE;
        }
        else
        {
            asynch = (boolean)FALSE;
        }

#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
        /* To inform Mainfunction how to erase an interleaved block - in async mode only */
        Fls_LLD_asyncInterleavedBlock = flsLLDSectorList0[physicalSectorId].interleavedBlo;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */

        /* Call Low-Level driver to erase one sector with
            the Fls_JobSectorIt sector index */
        /* @implements DFLS16029 */
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
        lldRetVal = Fls_LLD_SectorErase( physicalSectorId, physicalSectorSize,
            asynch );
#else
        lldRetVal = Fls_LLD_SectorErase( physicalSectorId, asynch );
#endif
        /* @implements  DFLS16030, DFLS16035 */
        if(( FLS_LLD_E_OK == lldRetVal ) && ( Fls_JobSectorIt == Fls_JobSectorEnd ))
        {
            RetVal = MEMIF_JOB_OK;
        }
        /* @implements DFLS16032, DFLS16033 */
        else if( FLS_LLD_E_FAILED == lldRetVal )
        {
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* @implements DFLS16045 */
            /* The erase operation is either pending (FLS_LLD_E_PENDING)
            in hardware in case of asynchronous operation or
            finished (FLS_LLD_E_OK) in case of synchronous operation
            and there is more sectors to erase */
            Fls_JobSectorIt++;
        }
    }

    /* @implements DFLS16036 */
    return( RetVal );
}


/**
* @brief       Calculate last logical address to read, write, or compare
*              from in current cycle of Fls_MainFunction
*
* @details      Calculate last logical address of Fls_DoJobDataTransfer
*               loop to limit number of bytes transferred to/from flash memory
*               in one cycle of Fls_MainFunction
*
* @return       Fls_AddressType
* @retval       0 .. (FLS_TOTAL_SIZE - 1)
*
* @param[in]    MaxTransfer Maximum number of bytes to read, write, or compare
*               in current cycle of Fls_MainFunction
*
* @pre          Fls_JobAddrIt must contain current, and Fls_JobAddrEnd last
*               logical address of current job
*
* @implements     DFLS02035
*
*/
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcMaxTransferAddrEnd(
    CONST( Fls_LengthType, AUTOMATIC) MaxTransfer )
{
    VAR( Fls_AddressType, AUTOMATIC ) MaxTransferEndAddr = Fls_JobAddrEnd;

    /* Adjust the MaxTransferEndAddr address to transfer only
        the MaxTransfer bytes in one Fls_MainFunction() call */
    if( MaxTransferEndAddr >= (Fls_JobAddrIt + MaxTransfer) )
    {
        MaxTransferEndAddr = (Fls_JobAddrIt + MaxTransfer) - 1U;
    }
    else
    {
        /* No adjustment is necessary. Job will finish in this cycle
            of Fls_MainFunction */
    }

    return( MaxTransferEndAddr );
}

/**
* @brief       Calculate sector offset to read, write, or compare
*              from current sector
*
* @details      Calculate sector offset in bytes for low-level driver
*               services
*
* @return       Fls_AddressType
* @retval      0 .. (FLS_SECTOR_SIZE - 1)
*
* @pre         The module must be initialized, Fls_JobSectorIt internal job
*              variable must contain index of current logical sector,
*              Fls_JobAddrIt must contain current logical address
*
* @implements     DFLS02037
*
*/
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferOffset( void )
{
    VAR( Fls_AddressType, AUTOMATIC ) sectorAddrStart = 0UL;

    /* Get first address of Fls_JobSectorIt sector */
    sectorAddrStart = Fls_GetSectorStartAddr( Fls_JobSectorIt );

    /* Calculate the sector offset */
    return( Fls_JobAddrIt - sectorAddrStart );
}


/**
* @brief       Calculate number of bytes to read, write, or compare
*              from current sector
*
* @details      Calculate sector transfer length for low-level driver
*               services
*
* @param[in]    MaxTransferEndAddr Last address to read, write,
*               or compare data from in this cycle of Fls_MainFunction
*
* @return      Fls_AddressType
* @retval      0 .. (FLS_SECTOR_SIZE - 1)
*
* @pre        The module must be initialized, Fls_JobSectorIt internal job
*             variable must contain index of current logical sector,
*             Fls_JobAddrIt must contain current logical address, and
*             MaxTransferEndAddr must be >= Fls_JobAddrIt and lie within
*             the specified lower and upper flash address boundaries
*
* @implements     DFLS02036
*
*/
STATIC FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferLength(
    CONST( Fls_AddressType, AUTOMATIC) MaxTransferEndAddr )
{
    VAR( Fls_AddressType, AUTOMATIC ) sectorEndAddr = 0UL;

    /* Get last address of Fls_JobSectorIt sector */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    sectorEndAddr = Fls_ConfigPtr->sectorEndAddr[Fls_JobSectorIt];

    /* Adjust the sectorEndAddr according to max number of bytes to transfer
        during one cycle of Fls_MainFunction */
    if( sectorEndAddr > MaxTransferEndAddr )
    {
        sectorEndAddr = MaxTransferEndAddr;
    }
    else
    {
        /* No adjustment is necessary. There is more sectors
            to transfer */
    }

    /* Calculate number of bytes to read from the sector */
    return(( sectorEndAddr - Fls_JobAddrIt ) + 1U );
}

/**
* @brief       Read up to one physical flash sector
*
* @details      Call low level flash driver service to read given number of bytes
*               from given sector offset.
*
* @param[in]    SectorOffset Flash sector offset to read data from
* @param[in]    Length Number of bytes to read
*
* @return       Fls_LLD_ReturnType
* @retval       FLS_LLD_E_OK read operation succeeded
* @retval       FLS_LLD_E_FAILED read operation failed due to a hardware error
*
* @pre          The module must be initialized, the Fls_JobSectorIt internal job
*               variable must contain valid index of logical sector to read,
*               SectorOffset and Length must be in physical    sector boundary,
*               Fls_JobDataDestPtr internal job variable must point to data read buffer
*
* @implements     DFLS02043
*
*/
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_DoJobRead(
    CONST( Fls_AddressType, AUTOMATIC) SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) Length )
{
    /* @implements    DFLS16067 */
    VAR( Fls_LLD_ReturnType, AUTOMATIC ) RetVal = FLS_LLD_E_OK;
    VAR( Fls_LLD_PhysicalSectorType, AUTOMATIC ) physicalSector;

    /* Map logical sector index to physical sector ID */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    physicalSector = Fls_ConfigPtr->physicalSector[Fls_JobSectorIt];

    /* @implements    DFLS16007, DFLS16009 */
    /* Do physical sector read */
    if( FLS_LLD_E_OK != Fls_LLD_SectorRead( physicalSector, SectorOffset,
        Length, Fls_JobDataDestPtr ))
    {
        /* @implements    DFLS16008, DFLS16066 */
        #if (FLS_DEM_ERROR_DETECT == STD_ON)
        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_ReadFailedCfg.state)
        {
            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_ReadFailedCfg.id, DEM_EVENT_STATUS_FAILED);
        }
        #endif

        RetVal = FLS_LLD_E_FAILED;
    }
    else
    {
        /* Physical sector read succeeded */
    }

    return( RetVal );
}

/**
* @brief        Write up to one physical flash sector
*
* @details      Call low level flash driver service to write given number of bytes
*               at given sector offset
*
* @param[in]    SectorOffset Flash sector offset to write data from
* @param[in]    Length Number of bytes to read
*
* @return       Fls_LLD_ReturnType
* @retval       FLS_LLD_E_OK write operation succeeded
* @retval       FLS_LLD_E_FAILED write operation failed due to a hardware error
*
* @pre          The module must be initialized, the Fls_JobSectorIt internal job
*               variable must contain valid index of logical sector to write,
*               SectorOffset and Length must be in physical sector boundary and page
*               aligned, Fls_JobDataSrcPtr internal job variable must point to data
                write buffer
*
* @implements     DFLS02044
*
*/
 STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_DoJobWrite(
    CONST( Fls_AddressType, AUTOMATIC) SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) Length )
{
    VAR( Fls_LLD_ReturnType, AUTOMATIC ) RetVal = FLS_LLD_E_OK;
    VAR( Fls_LLD_PhysicalSectorType, AUTOMATIC ) physicalSector;
    VAR( boolean, AUTOMATIC ) asynch = (boolean)0;

    /* Map logical sector index to physical sector ID */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    physicalSector = Fls_ConfigPtr->physicalSector[Fls_JobSectorIt];

    /* Get the Fls_LLD_SectorWrite function operation mode */
    /* @implements    DFLS16068, DFLS16069, DFLS16070 */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if( Fls_ConfigPtr->sectorFlags[Fls_JobSectorIt] & FLS_PAGE_WRITE_ASYNCH )
    {
        asynch = (boolean)TRUE;
    }
    else
    {
        asynch = (boolean)FALSE;
    }

#if (FLS_LLD_INTERLEAVED_BLOCK == STD_ON)
    /* To inform Mainfunction how to write an interleaved block - in async mode only */
    Fls_LLD_asyncInterleavedBlock = flsLLDSectorList0[physicalSector].interleavedBlo;
    Fls_LLD_InterleavedSize = flsLLDSectorList0[physicalSector].interleavedSize;
#endif /* FLS_LLD_INTERLEAVED_BLOCK == STD_ON */

    /* @implements    DFLS16011 */
    RetVal = Fls_LLD_SectorWrite( physicalSector, SectorOffset, Length,
        Fls_JobDataSrcPtr, asynch );

    return( RetVal );
}

/**
    @brief Compare up to one physical flash sector with data buffer
    @details Call low level flash driver service to compare given
        number of bytes at given sector offset with data buffer

    @param[in] SectorOffset Flash sector offset to compare data with
    @param[in] Length Number of bytes to compare

    @return Fls_LLD_ReturnType
    @retval FLS_LLD_E_OK compare operation succeeded
    @retval FLS_LLD_E_FAILED compare operation failed due to a hardware error
    @retval FLS_LLD_E_BLOCK_INCONSISTENT compare operation failed
        due to data mismatch

    @pre The module must be initialized, the Fls_JobSectorIt internal job
        variable must contain valid index of logical sector to compare,
        SectorOffset and Length must be in physical sector boundary,
        Fls_JobDataSrcPtr internal job variable must point to
        compare data buffer

    @implements DFLS02040
*/
/* @implements    DFLS16014 */
#if( FLS_COMPARE_API == STD_ON )
STATIC FUNC( Fls_LLD_ReturnType, FLS_CODE ) Fls_DoJobCompare(
    CONST( Fls_AddressType, AUTOMATIC) SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) Length )
{
    VAR( Fls_LLD_ReturnType, AUTOMATIC ) RetVal = FLS_LLD_E_OK;
    VAR( Fls_LLD_PhysicalSectorType, AUTOMATIC ) physicalSector;

    /* Map logical sector index to physical sector ID */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    physicalSector = Fls_ConfigPtr->physicalSector[Fls_JobSectorIt];

    /* @implements    DFLS16015 */
    RetVal = Fls_LLD_SectorCompare( physicalSector, SectorOffset,
        Length, Fls_JobDataSrcPtr );

    /* @implements    DFLS16016, DFLS16017 */
    if( FLS_LLD_E_FAILED == RetVal )
    {
        #if (FLS_DEM_ERROR_DETECT == STD_ON)
        if ((VAR(boolean, FLS_VAR))TRUE == Fls_ConfigPtr->Fls_E_CompareFailedCfg.state)
        {
            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Fls_ConfigPtr->Fls_E_CompareFailedCfg.id, DEM_EVENT_STATUS_FAILED);
        }
        #endif

    }
    else
    {
        /* physical sector compare succeeded or
            FLS_LLD_E_BLOCK_INCONSISTENT */
    }

    return( RetVal );
}
#endif /* FLS_COMPARE_API == STD_ON */

/**
    @brief Read, write, or compare flash data
    @details Call Fls_DoJobRead, Fls_DoJobWrite, or Fls_DoJobCompare
        functions to read, write, or compare flash data. The functions
        ensures that only pre-configured maximum number of bytes is
        read, written, or compared during one cycle of
        the Fls_MainFunction call

    @return MemIf_JobResultType
    @retval MEMIF_JOB_OK read, write, or compare operation succeeded and there
        is no more data to read, write, or compare
    @retval MEMIF_JOB_PENDING read, write, or compare operation succeeded
        and there is still some data to read, write, or compare
    @retval MEMIF_JOB_FAILED read, write, or compare operation failed due
        to a hardware error
    @retval MEMIF_BLOCK_INCONSISTENT Compared data from a flash compare
        job are not equal

    @pre The module must be initialized, the Fls_JobSectorIt internal
        job variable must contain index of logical sector to read, write,
        or compare, the Fls_JobAddrIt must contain logical address to read,
        write or compare, and Fls_JobAddrEnd must contain last address to read,
        write or compare.

    @post Updates the Fls_JobSectorIt, Fls_JobDataSrcPtr, Fls_JobDataDestPtr,
        and Fls_JobAddrIt internal job variables

    @implements DFLS02041
*/
STATIC FUNC( MemIf_JobResultType, FLS_CODE ) Fls_DoJobDataTransfer(
    CONST( Fls_JobType, AUTOMATIC) Job,
    CONST( Fls_LengthType, AUTOMATIC) MaxTransfer )
{
    /* @implements    DFLS16051 */
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_PENDING;

    /* @implements    DFLS16003, DFLS16063 */
    /* No more data to write */
    if( Fls_JobAddrIt > Fls_JobAddrEnd )
    {
        RetVal = MEMIF_JOB_OK;
    }
    else
    {
        VAR( Fls_AddressType, AUTOMATIC ) maxTransferAddrEnd = 0UL;
        VAR( Fls_LLD_ReturnType, AUTOMATIC ) TransferRetVal = FLS_LLD_E_FAILED;

        /* @implements    DFLS16044 */
        /* Last address to transfer data to/from in this call of
            the Fls_MainFunction() functions */
        maxTransferAddrEnd = Fls_CalcMaxTransferAddrEnd( MaxTransfer );

        /* @implements    DFLS16005 */
        /* Transfer sector by sector until the maxTransferAddrEnd address is reached
            or error is detected */
        do
        {
            VAR( Fls_AddressType, AUTOMATIC ) sectorTransferOffset = 0UL;
            VAR( Fls_AddressType, AUTOMATIC ) sectorTransferLength = 0UL;

            /* @implements    DFLS16018, DFLS16019 */
            /* Calculate offset and length of the sector data transfer */
            sectorTransferOffset = Fls_CalcSectorTransferOffset();
            sectorTransferLength = Fls_CalcSectorTransferLength( maxTransferAddrEnd );

            /* @implements    DFLS16020 */
            /* Call Low-level driver to transfer data to/from
                physical flash device */
            switch( Job )
            {
                case FLS_JOB_WRITE:
                    /* @implements    DFLS16010, DFLS16025 */
                    TransferRetVal =  Fls_DoJobWrite(
                        sectorTransferOffset,
                        sectorTransferLength );

                    /* Update the source data pointer for next write */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_JobDataSrcPtr += sectorTransferLength;
                    break;

                case FLS_JOB_READ:
                    /* @implements    DFLS16006, DFLS16022 */
                    TransferRetVal =  Fls_DoJobRead(
                        sectorTransferOffset,
                        sectorTransferLength );

                    /* Update the destination data pointer for next read */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_JobDataDestPtr += sectorTransferLength;
                    break;

/* @implements    DFLS16012 */
#if( FLS_COMPARE_API == STD_ON )
                case FLS_JOB_COMPARE:
                    /* @implements    DFLS16013, DFLS16023 */
                    TransferRetVal =  Fls_DoJobCompare(
                        sectorTransferOffset,
                        sectorTransferLength );

                    /* Update the source data pointer for next compare */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_JobDataSrcPtr += sectorTransferLength;
                    break;
#endif /* FLS_COMPARE_API == STD_ON */

                default:
                    /* Compiler_Warning: Added CER for Catastrophic events */
                    /* @implements   DFLS16071  */
                    Cer_ReportError( (uint16) FLS_MODULE_ID, (uint8)FLS_INSTANCE_ID, (uint8)FLS_SID_SETCLOCKMODE, (uint8)FLS_E_DEFAULT);
                  break;
            }

            /* @implements    DFLS16026 */
            /* Update the Fls_JobAddressIt iterator */
            Fls_JobAddrIt += sectorTransferLength;

            /* @implements    DFLS16024 */
            /* Fls_JobSectorIt should be increased here only for SYNC mode and for read/compare job
               For a Write Job in ASYNC mode it should be set by Fls_LLD_MainFunction just before
               completing the Job */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_7 Booleans operands are not used
            * for logical operators '&&', '||' and '!'
            */
            if ( (!(Fls_ConfigPtr->sectorFlags[Fls_JobSectorIt] & FLS_PAGE_WRITE_ASYNCH))  ||    \
                   (FLS_JOB_READ == Job )                                                  ||    \
                   (FLS_JOB_COMPARE == Job )                                                     \
            )
            {
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                if( (Fls_JobAddrIt > Fls_ConfigPtr->sectorEndAddr[Fls_JobSectorIt]))
                {
                    /* @implements    DFLS16021 */
                    /* Move on to the next sector */
                    Fls_JobSectorIt++;
                }

            }
        }
        while(( Fls_JobAddrIt <= maxTransferAddrEnd ) &&
            ( TransferRetVal == FLS_LLD_E_OK ));

        /* @implements    DFLS16004, DFLS16064 */
        if( FLS_LLD_E_FAILED == TransferRetVal )
        {
            RetVal = MEMIF_JOB_FAILED;
        }
        else if( FLS_LLD_E_BLOCK_INCONSISTENT == TransferRetVal )
        {
            /* compare job only */
            /* @implements    DFLS16065 */
            RetVal = MEMIF_BLOCK_INCONSISTENT;
        }
        else if(( Fls_JobAddrIt > Fls_JobAddrEnd ) &&
            ( FLS_LLD_E_OK == TransferRetVal ))
        {
            /* All desired job data has been successfully transferred */
            /* @implements    DFLS16062 */
            RetVal = MEMIF_JOB_OK;
        }
        else
        {
            /* The write operation is either pending (FLS_LLD_E_PENDING)
            in hardware in case of asynchronous operation or
            finished (FLS_LLD_E_OK) in case of synchronous operation
            and there is more pages to write */
        }
    }

    return( RetVal );
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        The function initializes Fls module.
* @details      The function sets the internal module variables according to given
*               configuration set.
*
* @param[in]    ConfigPtr        Pointer to flash driver configuration set.
*
* @api
*
* @pre          @p ConfigPtr must not be @p NULL_PTR and the module status must not
*               be @p MEMIF_BUSY.
*
* @implements     DFLS02051
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_Init(
    P2CONST( Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST ) ConfigPtr )
{
/* @implements DFLS06001 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#if !defined(FLS_PRECOMPILE_SUPPORT)
    /* @implements DFLS06002 */
    if( NULL_PTR == ConfigPtr )
    {
        /* @implements DFLS06005 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_PARAM_CONFIG );
    }
    /* @implements DFLS06003 */
    else if( MEMIF_JOB_PENDING == Fls_JobResult )
#else     /* !defined(FLS_PRECOMPILE_SUPPORT) */
    if( MEMIF_JOB_PENDING == Fls_JobResult )
#endif    /* !defined(FLS_PRECOMPILE_SUPPORT) */
    {
        /* @implements DFLS06004 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_BUSY );
    }
    else
    {
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */

        /* @implements DFLS06006 */
#if defined(FLS_PRECOMPILE_SUPPORT)
        if (NULL_PTR == ConfigPtr)
        {
            /* @implements DFLS06007 */
            Fls_ConfigPtr = &Fls_ConfigSetPC;
        }
        else
#endif /* defined(FLS_PRECOMPILE_SUPPORT) */
        {
            /* @implements DFLS06013 */
            Fls_ConfigPtr = ConfigPtr;
        }
        /* @implements DFLS06008 */
        /* Set the max number of bytes to read/write
            during Fls_MainFunction call */
        if (MEMIF_MODE_SLOW == Fls_ConfigPtr->defaultMode)
        {
            /* @implements DFLS06009 */
            Fls_MaxRead = Fls_ConfigPtr->maxReadNormalMode;
            /* @implements DFLS06015 */
            Fls_MaxWrite = Fls_ConfigPtr->maxWriteNormalMode;
        }
        else
        {
            /* @implements DFLS06014 */
            Fls_MaxRead = Fls_ConfigPtr->maxReadFastMode;
            /* @implements DFLS06010 */
            Fls_MaxWrite = Fls_ConfigPtr->maxWriteFastMode;
        }


        /* @implements DFLS06011 */
        /* Initialize flash hardware
           NOTE: The variable 'Fls_LLD_JobResult' will be updated in the below function*/
        Fls_LLD_Init();

        if(  MEMIF_JOB_FAILED == Fls_LLD_JobResult )
        {
            Fls_JobResult = MEMIF_JOB_FAILED;
        #if( FLS_DEV_ERROR_DETECT == STD_ON )
            Fls_ConfigPtr = NULL_PTR;
        #endif
        }
        else
        {
            /* @implements DFLS06012 */
            Fls_JobResult = MEMIF_JOB_OK;
        }

    #if(FLS_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}

/**
* @brief            Erase one or more complete flash sectors.
* @details          Starts an erase job asynchronously. The actual job is performed
 *                  by the @p Fls_MainFunction.
*
* @param[in]        TargetAddress        Target address in flash memory.
* @param[in]        Length               Number of bytes to erase.
*
* @return           Std_ReturnType
* @retval           E_OK                    Erase command has been accepted.
* @retval           E_NOT_OK                Erase command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Erase changes module status and some internal variables
*                   (@p Fls_JobSectorIt, @p Fls_JobSectorEnd, @p Fls_Job,
*                   @p Fls_JobResult).
*
* @implements       DFLS02045
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Erase(
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) Length )
{
    /* @implements    DFLS07018 */
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) tmpJobSectorIt = 0UL;
    VAR( Fls_SectorIndexType, AUTOMATIC ) tmpJobSectorEnd = 0UL;

/* @implements DFLS07002 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements    DFLS07004 */
    if( NULL_PTR == Fls_ConfigPtr )
    {
        /* @implements DFLS07008 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_UNINIT );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements DFLS07009 */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    */
    else if( !(Fls_IsAddrSectorStartAligned( (Fls_AddressType)TargetAddress )) )
    {
        /* @implements DFLS07006 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_ADDRESS );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements DFLS07003 */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    */
    else if(( 0U == Length ) || ( !(Fls_IsAddrSectorEndAligned(( (Fls_AddressType)TargetAddress + Length ) - 1U ))) )
    {
        /* @implements DFLS07007 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_LENGTH );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        /* @implements DFLS07013, DFLS07014 */
        tmpJobSectorIt = Fls_GetSectorIndexByAddr( TargetAddress );
        tmpJobSectorEnd = Fls_GetSectorIndexByAddr(( TargetAddress + Length ) - 1U );

        /* @implements DFLS07005 */
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10();

        /* @implements    DFLS07011 */
        if( MEMIF_JOB_PENDING == Fls_JobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            /* @implements    DFLS07016 */
            Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Configure the erase job */
            Fls_JobSectorIt = tmpJobSectorIt;
            Fls_JobSectorEnd = tmpJobSectorEnd;
            /* @implements    DFLS07010 */
            Fls_Job = FLS_JOB_ERASE;
            /* @implements    DFLS07015 */
            Fls_JobStart = 1U;

            /* Execute the erase job */
            /* @implements    DFLS07012 */
            Fls_JobResult = MEMIF_JOB_PENDING;
        }
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
    }

    /* @implements DFLS07001, DFLS07017 */
    return( RetVal );
}


/**
* @brief            Write one or more complete flash pages to the flash device.
* @details          Starts a write job asynchronously. The actual job is performed by
*                   @p Fls_MainFunction.
*
* @param[in]        TargetAddress        Target address in flash memory.
* @param[in]        SourceAddressPtr     Pointer to source data buffer.
* @param[in]        Length               Number of bytes to write.
*
* @return           Std_ReturnType
* @retval           E_OK                 Write command has been accepted.
* @retval           E_NOT_OK             Write command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Write changes module status and some internal variables
 *                  (@p Fls_JobSectorIt, @p Fls_JobAddrIt, @p Fls_JobAddrEnd,
 *                  @p Fls_JobDataSrcPtr, @p Fls_Job, @p Fls_JobResult).
*
* @implements       DFLS02063
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Write(
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress,
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) SourceAddressPtr,
    VAR( Fls_LengthType, AUTOMATIC) Length )
{
    /* @implements DFLS08025 */
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) tmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) tmpJobAddrEnd = 0UL;

/* @implements DFLS08001 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements DFLS08003 */
    if( NULL_PTR == Fls_ConfigPtr )
    {
        /* @implements DFLS08008 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_UNINIT );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements DFLS08010 */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    */
    else if( !(Fls_IsAddrPageStartAligned( (Fls_AddressType)TargetAddress )))
    {
        /* @implements DFLS08005 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_ADDRESS );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements DFLS08020 */
    /*
    * @violates @ref fls_c_REF_7 Booleans operands are not used
    * for logical operators '&&', '||' and '!'
    */
    else if(( 0U == Length ) || ( !(Fls_IsLengthAligned( (Fls_AddressType)TargetAddress, Length ) )))
    {
        /* @implements DFLS08007 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_LENGTH );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements DFLS08009 */
    else if( NULL_PTR == SourceAddressPtr )
    {
        /* @implements DFLS08006 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_DATA );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        /* @implements DFLS08013, DFLS08017 */
        tmpJobSectorIt = Fls_GetSectorIndexByAddr(TargetAddress);
        tmpJobAddrEnd = ( TargetAddress + Length ) - 1U;

        /* @implements DFLS08011 */
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10();

        /* @implements DFLS08019 */
        if( MEMIF_JOB_PENDING == Fls_JobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            /* @implements DFLS08004 */
            Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            /* @implements DFLS08021 */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Configure the write job */
            /* @implements DFLS08024, DFLS08023, DFLS08014, DFLS08015, DFLS08012, DFLS08018 */
            Fls_JobSectorIt = tmpJobSectorIt;
            Fls_JobAddrEnd = tmpJobAddrEnd;
            Fls_JobAddrIt = TargetAddress;
            Fls_JobDataSrcPtr = SourceAddressPtr;
            Fls_Job = FLS_JOB_WRITE;
            Fls_JobStart = 1U;

            /* Execute the write job */
            /* @implements DFLS08016 */
            Fls_JobResult = MEMIF_JOB_PENDING;

        }
        /* @implements DFLS08011 */
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
    }

    /* @implements DFLS08002, DFLS08026 */
    return( RetVal );
}


/**
* @brief            Cancel an ongoing flash read, write, erase or compare job.
* @details          Abort a running job synchronously so that directly after returning
*                   from this function a new job can be started.
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Fls_Cancel changes module status and @p Fls_JobResult
 *                  internal variable.
*
* @implements       DFLS02038
*/
/* @implements DFLS09001 */
#if ( FLS_CANCEL_API == STD_ON ) || defined(__DOXYGEN__)
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_Cancel( void )
{
/* @implements DFLS09007, DFLS09008 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_ConfigPtr )
    {
        /* @implements DFLS09009 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_CANCEL_ID, FLS_E_UNINIT );
    }
    else
    {
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */

        /* @implements    DFLS09013 */
        if( MEMIF_JOB_PENDING == Fls_JobResult )
        {
            /* @implements    DFLS09012 */
            /* Cancel ongoing hardware job */
            Fls_LLD_Cancel();

/* @implements    DFLS09004 */
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
            /* @implements DFLS09006 */
            if(( FLS_JOB_ERASE == Fls_Job ) || ( FLS_JOB_WRITE == Fls_Job ))
            {
                /* @implements DFLS09005 */
                Fls_UnloadAc( Fls_Job );
            }
            else
            {
                /* The FLS_JOB_READ and FLS_JOB_COMPARE jobs don't use the access code */
            }
#endif
            /* @implements    DFLS09011 */
            Fls_JobResult = MEMIF_JOB_CANCELED;

            if( NULL_PTR != Fls_ConfigPtr->jobErrorNotificationPtr )
            {
                /* @implements    DFLS09010 */
                /* Call FlsJobErrorNotification function if configured */
                Fls_ConfigPtr->jobErrorNotificationPtr();
            }
            else
            {
                /* Callback notification configured as null pointer */
            }
        }
        else
        {
            /* Leave the job result unchanged */
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif    /* FLS_CANCEL_API == STD_ON */


/**
* @brief            Returns the FLS module status.
* @details          Returns the FLS module status synchronously.
*
* @return           MemIf_StatusType
* @retval           MEMIF_UNINIT        Module has not been initialized (yet).
* @retval           MEMIF_IDLE          Module is currently idle.
* @retval           MEMIF_BUSY          Module is currently busy.
*
* @api
*
* @implements       DFLS02049
*
*/
/* @implements    DFLS10001 */
#if(( FLS_GET_STATUS_API == STD_ON ) || defined (__DOXYGEN__))
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_StatusType, FLS_CODE ) Fls_GetStatus( void )
{
    VAR( MemIf_StatusType, AUTOMATIC ) RetVal = MEMIF_IDLE;

    if( NULL_PTR == Fls_ConfigPtr )
    {
        /* @implements    DFLS10005, DFLS10004 */
        RetVal = MEMIF_UNINIT;
    }
    else if( MEMIF_JOB_PENDING == Fls_JobResult )
    {
        /* @implements    DFLS10006, DFLS10002 */
        RetVal = MEMIF_BUSY;
    }
    else
    {
        /* @implements    DFLS10003 */
        RetVal = MEMIF_IDLE;
    }

    return( RetVal );
}
#endif    /* FLS_GET_STATUS_API == STD_ON */


/**
* @brief            Returns the result of the last job.
* @details          Returns synchronously the result of the last job.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
*
* @implements       DFLS02046
*
*/

/* @implements  DFLS11001 */
#if ( FLS_GET_JOB_RESULT_API == STD_ON )||  defined (__DOXYGEN__)
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_JobResultType, FLS_CODE ) Fls_GetJobResult( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) RetVal = MEMIF_JOB_OK;

/* @implements  DFLS11004 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements  DFLS11005 */
    if( NULL_PTR == Fls_ConfigPtr )
    {
        /* @implements  DFLS11003, DFLS11006 */
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETJOBRESULT_ID, FLS_E_UNINIT );
        RetVal = (MemIf_JobResultType)MEMIF_JOB_FAILED;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        RetVal = Fls_JobResult;
    }
    /* @implements  DFLS11002 */
    return( RetVal );
}
#endif    /* FLS_GET_JOB_RESULT_API == STD_ON */


/**
* @brief            Reads from flash memory.
* @details          Starts a read job asynchronously. The actual job is performed by
*                   @p Fls_MainFunction.
*
* @param[in]        SourceAddress        Source address in flash memory.
* @param[in]        Length               Number of bytes to read.
* @param[out]       TargetAddressPtr    Pointer to target data buffer.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_Read changes module status and some internal variables
*                 (@p Fls_JobSectorIt, @p Fls_JobAddrIt, @p Fls_JobAddrEnd,
*                 @p Fls_JobDataDestPtr, @p Fls_Job, @p Fls_JobResult).
*
* @implements       DFLS02060
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Read(
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress,
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) TargetAddressPtr,
    VAR( Fls_LengthType, AUTOMATIC) Length )
{
    /* @implements    DFLS12001 */
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) tmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) tmpJobAddrEnd = 0UL;

/* @implements    DFLS12002 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements    DFLS12004, DFLS12009 */
    if( NULL_PTR == Fls_ConfigPtr )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_UNINIT );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements    DFLS12010, DFLS12006 */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    else if( SourceAddress >= FLS_TOTAL_SIZE )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_ADDRESS );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements    DFLS12003, DFLS12008 */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    else if(( 0U == Length ) || ((SourceAddress + Length) > FLS_TOTAL_SIZE ))
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_LENGTH );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements    DFLS12011, DFLS12007 */
    else if( NULL_PTR == TargetAddressPtr )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_DATA );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        /* @implements    DFLS12014, DFLS12018 */
        tmpJobSectorIt = Fls_GetSectorIndexByAddr( SourceAddress );
        tmpJobAddrEnd = ( SourceAddress + Length ) - 1U;

        /* @implements    DFLS12012 */
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10();

        /* @implements    DFLS12021 */
        if( MEMIF_JOB_PENDING == Fls_JobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            /* @implements    DFLS12005 */
            Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Configure the read job */
            /* @implements   DFLS12023, DFLS12015, DFLS12016, DFLS12024 */
            Fls_JobSectorIt = tmpJobSectorIt;
            Fls_JobAddrIt = SourceAddress;
            Fls_JobAddrEnd = tmpJobAddrEnd;
            Fls_JobDataDestPtr = TargetAddressPtr;
            /* @implements    DFLS12013 */
            Fls_Job = FLS_JOB_READ;

            /* @implements    DFLS12020 */
            Fls_JobStart = 1U;

            /* Execute the read job */
            /* @implements    DFLS12017 */
            Fls_JobResult = MEMIF_JOB_PENDING;

        }
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
    }

    /* @implements    DFLS12022, DFLS12019 */
    return( RetVal );
}


/**
* @brief           Compares a flash memory area with an application data buffer.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  @p Fls_MainFunction.
*
* @param[in]        SourceAddress          Source address in flash memory.
* @param[in]        TargetAddressPtr       Pointer to source data buffer.
* @param[in]        Length                 Number of bytes to compare.
*
* @return           Std_ReturnType
* @retval           E_OK                      Compare command has been accepted.
* @retval           E_NOT_OK                   Compare command has not been accepted.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_Read changes module status and some internal variables
 *                (@p Fls_JobSectorIt, @p Fls_JobAddrIt, @p Fls_JobAddrEnd,
 *                @p Fls_JobDataSrcPtr, @p Fls_Job, @p Fls_JobResult).
*
* @implements       DFLS02039
*
*/
/* @implements    DFLS13001 */
#if( FLS_COMPARE_API == STD_ON ) || defined(__DOXYGEN__)
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Compare(
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress,
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) TargetAddressPtr,
    VAR( Fls_LengthType, AUTOMATIC) Length )
{
    /* @implements    DFLS13026 */
    VAR( Std_ReturnType, AUTOMATIC ) RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) tmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) tmpJobAddrEnd = 0UL;

/* @implements    DFLS13011 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements    DFLS13013, DFLS13017 */
    if( NULL_PTR == Fls_ConfigPtr )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_UNINIT );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements    DFLS13018, DFLS13014 */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    else if( SourceAddress >= FLS_TOTAL_SIZE )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_ADDRESS );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements    DFLS13012, DFLS13016 */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    else if(( 0U == Length ) || ((SourceAddress + Length) > FLS_TOTAL_SIZE ))
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_LENGTH );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* @implements    DFLS13019, DFLS13015 */
    else if( NULL_PTR == TargetAddressPtr )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_DATA );
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {


        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        /* @implements    DFLS13005, DFLS13009 */
        tmpJobSectorIt = Fls_GetSectorIndexByAddr( SourceAddress );
        tmpJobAddrEnd = ( SourceAddress + Length ) - 1U;

        /* @implements    DFLS13002 */
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10();

        /* @implements    DFLS13008, DFLS13020, DFLS13024 */
        if( MEMIF_JOB_PENDING == Fls_JobResult )
        {
/* @implements    DFLS13027 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* @implements    DFLS13006, DFLS13010, DFLS13021, DFLS13022, DFLS13023 */
            Fls_JobSectorIt = tmpJobSectorIt;
            Fls_JobAddrIt = SourceAddress;
            Fls_JobAddrEnd = tmpJobAddrEnd;
            Fls_JobDataSrcPtr = TargetAddressPtr;
            /* @implements    DFLS13004 */
            Fls_Job = FLS_JOB_COMPARE;
            Fls_JobStart = 1U;

            /* @implements    DFLS13007 */
            /* Execute the read job */
            Fls_JobResult = MEMIF_JOB_PENDING;

        }
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
    }

    /* @implements    DFLS13003, DFLS13025 */
    return( RetVal );
}
#endif /* FLS_COMPARE_API == STD_ON */



/**
* @brief           Sets the FLS module's operation mode to the given Mode.
* @details         Every given mode determinates maximum bytes for read/write
 *                 operations. Every mode has a set of pre-configured values.
*
* @param[in]        Mode        MEMIF_MODE_FAST or MEMIF_MODE_SLOW.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_SetMode changes internal variables @p Fls_MaxRead and
*                 @p Fls_MaxWrite.
*
* @implements       DFLS02061
*
*/

/* @implements    DFLS14002 */
#if( FLS_SET_MODE_API == STD_ON )|| defined (__DOXYGEN__)
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_SetMode(
    VAR( MemIf_ModeType, AUTOMATIC ) Mode )
{
/* @implements    DFLS14001 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements    DFLS14010, DFLS14011 */
    if( NULL_PTR == Fls_ConfigPtr )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_UNINIT );
    }
    /* @implements    DFLS14008, DFLS14009 */
    else if( MEMIF_JOB_PENDING == Fls_JobResult )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_BUSY );
    }
    else
    {
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
        /* Set the max number of bytes to read/write
            during Fls_MainFunction call */
        /* @implements    DFLS14007 */
        switch( Mode )
        {
            case MEMIF_MODE_FAST:
                /* @implements    DFLS14003, DFLS14005 */
                Fls_MaxRead = Fls_ConfigPtr->maxReadFastMode;
                Fls_MaxWrite = Fls_ConfigPtr->maxWriteFastMode;
                break;

            case MEMIF_MODE_SLOW:
                /* @implements    DFLS14004, DFLS14006 */
                Fls_MaxRead = Fls_ConfigPtr->maxReadNormalMode;
                Fls_MaxWrite = Fls_ConfigPtr->maxWriteNormalMode;
                break;

            default:
                /* @implements    DFLS16072 */
                /* Compiler_Warning: Added CER for Catastrophic events */
                Cer_ReportError( (uint16) FLS_MODULE_ID, (uint8)FLS_INSTANCE_ID, (uint8)FLS_SID_SETCLOCKMODE, (uint8)FLS_E_DEFAULT);
            break;
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FLS_SET_MODE_API == STD_ON */

/* @implements DFLS15001 */
#if( FLS_VERSION_INFO_API == STD_ON )|| defined(__DOXYGEN__)
/**
* @brief        Returns version information about FLS module.
* @details      Version information includes:
*               - Module Id
*               - Vendor Id
*               - Vendor specific version numbers (BSW00407).
*
* @param[in,out] VersionInfoPtr  Pointer to where to store the version information of this module.
*
* @api
*
* @implements       DFLS02050
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_GetVersionInfo(
    P2VAR( Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA ) VersionInfoPtr )
{
/* @implements DFLS15002 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements    DFLS15004, DFLS15003 */
    if( VersionInfoPtr == NULL_PTR )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETVERSIONINFO_ID, \
                 FLS_E_PARAM_POINTER );
    }
    else
    {
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        /* @implements DFLS15005 */
        VersionInfoPtr->moduleID = FLS_MODULE_ID;
        VersionInfoPtr->vendorID = FLS_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)FLS_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)FLS_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)FLS_SW_PATCH_VERSION;
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FLS_VERSION_INFO_API == STD_ON */


/**
* @brief            Performs actual flash read, write, erase and compare jobs.
* @details          Bytes number processed per cycle depends by job type (erase, write, read, compare)
*                   current FLS module's operating mode (normal, fast)
*                   and write, erase Mode of Execution (sync, async).
*
* @api
*
* @pre              The module has to be initialized.
*
*
* @implements       DFLS02059
*
* @note             This function have to be called ciclically by the Basic Software Module;
*                   it will do nothing if there aren't pending job.
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_MainFunction( void )
{
/* @implements    DFLS16043 */
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    /* @implements    DFLS16001, DFLS16002 */
    if( NULL_PTR == Fls_ConfigPtr )
    {
        Det_ReportError( FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID,
            FLS_E_UNINIT );
    }
    else
    {
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
        /* @implements    DFLS16050 */
        if( MEMIF_JOB_PENDING == Fls_JobResult )
        {
            /* @implements    DFLS16061 */
            VAR(MemIf_JobResultType, AUTOMATIC) workResult = MEMIF_JOB_OK;

            /* @implements    DFLS16053, DFLS16057 */
            if( 1U == Fls_JobStart )
            {
                Fls_JobStart = 0U;

                Fls_LLD_AbortSuspended();
/* @implements    DFLS16040  */
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
                /* Load position independent access code */
                /* @implements    DFLS16041, DFLS16042  */
                if(( FLS_JOB_ERASE == Fls_Job ) || ( FLS_JOB_WRITE == Fls_Job ))
                {
                    Fls_LoadAc( Fls_Job );
                }
                else
                {
                    /* Fls_Job != FLS_JOB_ERASE &&  Fls_Job != FLS_JOB_WRITE */
                }
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */

                /* Clear result of hardware job */
                /* @implements    DFLS16048 */
                Fls_LLD_ClrJobResult();
            }
            else
            {
                /* Fls_JobStart != 1U */
            }

            /* @implements    DFLS16059, DFLS16049, DFLS16060 */
            if(( FLS_JOB_ERASE == Fls_Job ) || ( FLS_JOB_WRITE == Fls_Job ))
            {
                /* Process ongoing erase or write asynchronous hardware job */
                Fls_LLD_MainFunction();

                /* Get status/result of ongoing erase or write asynchronous
                    hardware job */
                workResult = Fls_LLD_GetJobResult();
            }
            else
            {
                /* FLS_JOB_READ and FLS_JOB_COMPARE jobs are
                    always synchronous */
            }

            /* @implements    DFLS16047 */
            if( MEMIF_JOB_OK == workResult )
            {
                /* @implements    DFLS16052 */
                switch( Fls_Job )
                {
                    case FLS_JOB_ERASE:
                            /* @implements    DFLS16027 */
                            workResult = Fls_DoJobErase();
                        break;
                    case FLS_JOB_WRITE:
                            /* @implements    DFLS16028 */
                            workResult = Fls_DoJobDataTransfer(
                                Fls_Job, Fls_MaxWrite );
                        break;
                    case FLS_JOB_READ:
    /* For Read and Compare jobs the static function Fls_DoJobDataTransfer( )
                will be used with the same input parameters */
#if( FLS_COMPARE_API == STD_ON )
                    case FLS_JOB_COMPARE:
#endif /* FLS_COMPARE_API == STD_ON */
                            workResult = Fls_DoJobDataTransfer(
                                Fls_Job, Fls_MaxRead );
                        break;
                    default:
                        /* Compiler_Warning: Added CER for Catastrophic events */
                        /* @implements    DFLS16073 */
                        Cer_ReportError( (uint16) FLS_MODULE_ID, (uint8)FLS_INSTANCE_ID, (uint8)FLS_SID_SETCLOCKMODE, (uint8)FLS_E_DEFAULT);
                        break;
                }
            }
            else
            {
                /* workResult != MEMIF_JOB_OK */
            }

/* @implements    DFLS16037 */
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
            /* @implements    DFLS16058, DFLS16039, DFLS16038 */
            if(( MEMIF_JOB_PENDING != workResult ) &&
                (( FLS_JOB_ERASE == Fls_Job ) || ( FLS_JOB_WRITE == Fls_Job )))
            {
                Fls_UnloadAc( Fls_Job );
            }
#endif

            /* @implements    DFLS16046 */
            Fls_JobResult = workResult;

            /* @implements    DFLS16054 */
            if( MEMIF_JOB_OK == workResult )
            {
                /* @implements    DFLS16056  */
                if( NULL_PTR != Fls_ConfigPtr->jobEndNotificationPtr )
                {
                    /* Call FlsJobEndNotification function if configured */
                    Fls_ConfigPtr->jobEndNotificationPtr();
                }
                else
                {
                    /* Callback notification configured as null pointer */
                }
            }
            else if(( MEMIF_JOB_FAILED == workResult ) ||
                ( MEMIF_BLOCK_INCONSISTENT == workResult ))
            {
                /* @implements    DFLS16055 */
                if( NULL_PTR != Fls_ConfigPtr->jobErrorNotificationPtr )
                {
                    /* Call FlsJobErrorNotification function if configured */
                    Fls_ConfigPtr->jobErrorNotificationPtr();
                }
                else
                {
                    /* Callback notification configured as null pointer */
                }
            }
            else
            {
                /* Not done yet. There is more data to transfer in following
                    Fls_MainFunction call */
            }
        }
        else
        {
            /* Nothing to do since no job is pending */
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}

#define FLS_STOP_SEC_CODE
/*
* @violates @ref fls_c_REF_1 Precautions shall be taken
* in order to prevent the contents of a header being included twice.
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
