/**
*   @file    Compiler.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - SWS Compiler abstraction
*   @details The file Compiler.h provides macros for the encapsulation of definitions and
*            declarations.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : XPC560XB
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

/**
* @file        Compiler.h
* @implements DBASE03000, DBASE03025
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Compiler_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. This is the compiler abstraction specified in AutoSar Specification of Compiler Abstraction.
*
* @section Compiler_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section Compiler_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class
* specifier, or a do-while-zero construct
*
* @section Compiler_h_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as
* the operand of # or ##.
*
* @section Compiler_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
 * significance of more than 31 characters.
*/

/**
* @file         Compiler.h
* @requirements COMPILER047
*/
#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file        Compiler.h
* @brief Include compiler memory types
* @implements DBASE00001
*/
#include "Compiler_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
* @implements DBASE03023
@{
*/
#define COMPILER_VENDOR_ID                      43
/*
* @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement, 
*/
#define COMPILER_AR_RELEASE_MAJOR_VERSION       4
/*
* @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement, 
*/
#define COMPILER_AR_RELEASE_MINOR_VERSION       0
/*
* @violates @ref Compiler_h_REF_5 This is required as per autosar Requirement, 
*/
#define COMPILER_AR_RELEASE_REVISION_VERSION    3
#define COMPILER_SW_MAJOR_VERSION               1
#define COMPILER_SW_MINOR_VERSION               0
#define COMPILER_SW_PATCH_VERSION               1
/**@}*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef __ghs__
    /**
    * @brief Symbol required to be defined when GreenHills compiler is used.
    * @implements DBASE03003
    */
  /*
    * @violates @ref Compiler_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _GREENHILLS_C_MPC560XB_
#endif
#ifdef __DCC__
    /**
    * @brief Symbol required to be defined when Diab compiler is used.
    * @implements DBASE03002
     */
  /*
    * @violates @ref Compiler_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _DIABDATA_C_MPC560XB_
#endif
#ifdef __MWERKS__
    /**
    * @brief Symbol required to be defined when Codewarrior compiler is used.
    * @implements DBASE03001
    */
  /*
    * @violates @ref Compiler_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _CODEWARRIOR_C_MPC560XB_
#endif
#ifdef __CSMC__
    /**
    * @brief Symbol required to be defined when Cosmic compiler is used.
    * @implements DBASE03024
    */
  /*
    * @violates @ref Compiler_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
  #define _COSMIC_C_MPC560XB_
#endif
#ifdef __GNUC__
    /**
    * @brief Symbol required to be defined when Codewarrior compiler is used.
    * @implements DBASE03005
    */
  /*
    * @violates @ref Compiler_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _HITECH_C_MPC560XB_
#endif

/**
* @brief The memory class AUTOMATIC shall be provided as empty definition, used for the declaration
*        of local pointers.
* @implements DBASE03004
*/
#define AUTOMATIC

/**
* @brief The memory class TYPEDEF shall be provided as empty definition. This memory class shall be
*        used within type definitions, where no memory qualifier can be specified. This can be
*        necessary for defining pointer types, with e.g. P2VAR, where the macros require two
*        parameters. First parameter can be specified in the type definition (distance to the memory
*        location referenced by the pointer), but the second one (memory allocation of the pointer
*        itself) cannot be defined at this time. Hence memory class TYPEDEF shall be applied.
* @implements DBASE03011
*/
#define TYPEDEF

/**
* @brief The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero
*        definition.
* @implements DBASE03009
*/
#define NULL_PTR ((void *)0)

/**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_MPC560XB_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    * @implements DBASE03007
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    * @implements DBASE03010
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    * @implements DBASE03008
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __interrupt
#endif /* #ifdef _GREENHILLS_C_MPC560XB_ */

/**************************************** Wind River Diab *****************************************/
#ifdef _DIABDATA_C_MPC560XB_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    * @mplements DBASE03007
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE              __inline__

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    * @implements DBASE03010
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static __inline__

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    * @implements DBASE03008
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __interrupt__
#endif /* #ifdef _DIABDATA_C_MPC560XB_ */

/*************************************** CodeWarrior **********************************************/
#ifdef _CODEWARRIOR_C_MPC560XB_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    * @implements DBASE03007
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE              inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    * @implements DBASE03010
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    * @implements DBASE03008
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC      __declspec(interrupt nowarn)
#endif /* #ifdef _CODEWARRIOR_C_MPC560XB_ */

/*************************************** Cosmic ***************************************************/
#ifdef _COSMIC_C_MPC560XB_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    * @implements DBASE03007
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INLINE @inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    * @implements DBASE03010
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define LOCAL_INLINE            static @inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    * @implements DBASE03008
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */        
    #define INTERRUPT_FUNC @interrupt
#endif /* #ifdef _COSMIC_C_MPC560XB_ */
/*************************************** HighTec **********************************************/
#ifdef _HITECH_C_MPC560XB_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    * @implements DBASE03007
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INLINE              __inline

/**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    * @implements DBASE03010
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    * @implements DBASE03008
    */
  /*
    * @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define INTERRUPT_FUNC
#endif /* #ifdef _HITECH_C_MPC560XB_ */


/**
* @brief The compiler abstraction shall define the FUNC macro for the declaration and definition of
*        functions, that ensures correct syntax of function declarations as required by a specific
*        compiler.
* @implements DBASE03015
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define FUNC(rettype, memclass) rettype

/**
* @brief The compiler abstraction shall define the P2VAR macro for the declaration and definition of
*        pointers in RAM, pointing to variables.
* @implements DBASE03019
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/**
* @brief The compiler abstraction shall define the P2CONST macro for the declaration and definition
*        of pointers in RAM pointing to constants.
* @implements DBASE03017
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

/**
* @brief The compiler abstraction shall define the CONSTP2VAR macro for the declaration and
*        definition of constant pointers accessing variables.
* @implements DBASE03014
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/**
* @brief The compiler abstraction shall define the CONSTP2CONST macro for the declaration and
*        definition of constant pointers accessing constants.
* @implements DBASE03013
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/**
* @brief The compiler abstraction shall define the P2FUNC macro for the type definition of pointers
*        to functions.
* @implements DBASE03018
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/**
* @brief The compiler abstraction shall define the CONST macro for the declaration and definition of
*        constants.
* @implements DBASE03012
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONST(consttype, memclass) const consttype

/**
* @brief The compiler abstraction shall define the VAR macro for the declaration and definition of
*        variables.
* @implements DBASE03022
*/
/*
* @violates @ref Compiler_h_REF_1 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_3 C macros shall only expand to a braced initialiser, 
*    a constant, a parenthesised expression
*/
/*
* @violates @ref Compiler_h_REF_4 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define VAR(vartype, memclass) vartype

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILER_H */

/** @} */
